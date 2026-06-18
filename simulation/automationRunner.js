/**
 * simulation/automationRunner.js
 *
 * Multi-cycle semester simulation runner.
 * Creates instructor → section → 50 students → runs 3 operational cycles.
 *
 * Environment: reads backend/.env for DB config and server URL.
 */

require('dotenv').config({ path: '../backend/.env' });

const axios = require('axios');
const jwt = require('jsonwebtoken');
const { Client } = require('pg');
const { PERSONAS, INSTRUCTOR } = require('./personas');
const { generatePayload, matchCodeNet, PAYLOADS } = require('./studentGenerator');

// ── Configuration ────────────────────────────────────────────────────────────

const API_BASE = process.env.SIM_API_BASE || 'http://127.0.0.1:5000/api';
const JWT_SECRET = process.env.JWT_SECRET || 'your_super_secret_key_change_this_in_production';
const SLEEP_MS = (ms) => new Promise((r) => setTimeout(r, ms));

// ── Concurrency Throttle ─────────────────────────────────────────────────────
// Process submissions in small batches to prevent CPU/RAM spikes.
// Instead of all 50 personas hitting the server at once, only BATCH_SIZE run
// concurrently at any time.

const BATCH_SIZE = parseInt(process.env.SIM_BATCH_SIZE || '3');

/**
 * Run async tasks in batches. Only `batchSize` tasks execute concurrently.
 * @param {Array<() => Promise>} tasks - Thunk array
 * @param {number} batchSize - Max concurrent tasks
 * @returns {Promise<Array>} Results in order
 */
async function runInBatches(tasks, batchSize) {
  const results = [];
  for (let i = 0; i < tasks.length; i += batchSize) {
    const batch = tasks.slice(i, i + batchSize).map(t => t());
    const batchResults = await Promise.all(batch);
    results.push(...batchResults);
  }
  return results;
}

// ── Memory Guard ─────────────────────────────────────────────────────────────
// Prevents RAM exhaustion during long simulation runs (infinite loop timeouts).

const MAX_MEM_MB = process.env.SIM_MAX_MEM_MB ? parseInt(process.env.SIM_MAX_MEM_MB) : 512;

function memCheck(label) {
  const usage = process.memoryUsage();
  const heapUsedMB = Math.round(usage.heapUsed / 1024 / 1024);
  const rssMB = Math.round(usage.rss / 1024 / 1024);
  if (heapUsedMB > MAX_MEM_MB) {
    console.error(`\n⚠️  Memory guard: heap ${heapUsedMB}MB exceeds limit ${MAX_MEM_MB}MB — forcing GC and pausing`);
    if (global.gc) global.gc();
    // If still over limit after GC, throw to halt the simulation
    const afterGC = Math.round(process.memoryUsage().heapUsed / 1024 / 1024);
    if (afterGC > MAX_MEM_MB) {
      throw new Error(`Memory limit exceeded even after GC: ${afterGC}MB > ${MAX_MEM_MB}MB`);
    }
  }
  // Log every 100 submissions to avoid log spam
  if (label && label.submissionCount && label.submissionCount % 100 === 0) {
    console.log(`   📊 Memory: heap=${heapUsedMB}MB, rss=${rssMB}MB`);
  }
}

/**
 * Generate a JWT token directly for a user.
 * Bypasses rate-limited login endpoint — uses same JWT secret as backend.
 */
function generateToken(user) {
  return jwt.sign(
    { id: user.id, name: user.name, email: user.email, role: user.role },
    JWT_SECRET,
    { expiresIn: '7d' }
  );
}

// Authenticated axios client with direct JWT cookie injection
function createClient(user) {
  const client = axios.create({
    baseURL: API_BASE,
    headers: { 'Content-Type': 'application/json', 'Connection': 'close' },
    maxRedirects: 0,
    validateStatus: (status) => true,
    timeout: 120000,
  });

  if (user && user.id) {
    const token = generateToken(user);
    client.defaults.headers.Cookie = `ci_token=${token}`;
  }

  return client;
}

// ── Cleanup-at-Start ─────────────────────────────────────────────────────────

async function cleanup() {
  console.log('\n🧹 Cleanup: Removing old simulation data...');

  const db = new Client({
    host: process.env.DB_HOST || 'localhost',
    port: parseInt(process.env.DB_PORT || '5432'),
    database: process.env.DB_NAME || 'codeinsight',
    user: process.env.DB_USER || 'codeuser',
    password: process.env.DB_PASSWORD || 'codepassword123',
  });

  try {
    await db.connect();

    // Kill only connections stuck on enrollment INSERT (from previous failed simulation runs)
    await db.query(`
      SELECT pg_terminate_backend(pid)
      FROM pg_stat_activity
      WHERE datname = 'codeinsight'
        AND pid != pg_backend_pid()
        AND state = 'idle in transaction'
        AND query LIKE '%INSERT INTO enrollments%'
        AND NOW() - state_change > interval '10 seconds'
    `);
    console.log('   ⚡ Cleared stale database locks');

    const secRes = await db.query(
      "DELETE FROM sections WHERE name LIKE 'Sim Section%' OR name LIKE 'Sim Stress%' OR name LIKE 'Sim Adversarial%'"
    );
    console.log(`   Deleted ${secRes.rowCount} old simulation sections`);

    const userRes = await db.query(
      "DELETE FROM users WHERE name LIKE 'Sim %' AND email LIKE '%@test.codeinsight'"
    );
    console.log(`   Deleted ${userRes.rowCount} old simulation users (cascaded to all child tables)`);

    await db.end();
    console.log('   ✅ Cleanup complete\n');
    memCheck();
  } catch (err) {
    console.error('   ⚠️  Cleanup failed (non-fatal):', err.message);
    try { await db.end(); } catch (_) {}
  }
}

// ── Setup Phase ──────────────────────────────────────────────────────────────

async function setup() {
  console.log('🚀 SETUP PHASE');
  console.log('='.repeat(60));

  // Instructor client (unauthenticated initially — register doesn't need auth)
  const client = createClient();

  // 1. Create instructor
  console.log('\n📝 Creating instructor...');
  let res = await client.post('/auth/register', {
    name: INSTRUCTOR.name,
    email: INSTRUCTOR.email,
    password: INSTRUCTOR.password,
    role: INSTRUCTOR.role,
  });
  if (res.status !== 201 && res.status !== 409) {
    throw new Error(`Failed to create instructor: ${res.status} ${JSON.stringify(res.data)}`);
  }
  console.log(`   Instructor: ${INSTRUCTOR.email} (status: ${res.status})`);

  // Look up instructor ID from DB to generate JWT
  const instructorDb = new Client({
    host: process.env.DB_HOST || 'localhost',
    port: parseInt(process.env.DB_PORT || '5432'),
    database: process.env.DB_NAME || 'codeinsight',
    user: process.env.DB_USER || 'codeuser',
    password: process.env.DB_PASSWORD || 'codepassword123',
  });
  await instructorDb.connect();
  const instrRes = await instructorDb.query(
    'SELECT id, name, email, role FROM users WHERE email = $1', [INSTRUCTOR.email]
  );
  const instructor = instrRes.rows[0];
  await instructorDb.end();
  console.log(`   Instructor ID: ${instructor.id}`);

  // Create authenticated instructor client
  const instrClient = createClient(instructor);

  // 3. Create section (using authenticated client)
  console.log('\n🏫 Creating section...');
  res = await instrClient.post('/sections', {
    name: 'Sim Section Baseline',
    course_code: 'CS101',
    school_year: '2026-2027',
    semester: 'Sem 1',
  });
  if (res.status !== 201) {
    throw new Error(`Failed to create section: ${res.status} ${JSON.stringify(res.data)}`);
  }
  const section = res.data;
  const inviteCode = section.code;
  console.log(`   Section: "${section.name}" (ID: ${section.id}, Code: ${inviteCode})`);

  // 4. Register all 50 students
  console.log(`\n👥 Registering ${PERSONAS.length} students...`);
  const students = [];
  for (const persona of PERSONAS) {
    res = await client.post('/auth/register', {
      name: persona.name,
      email: persona.email,
      password: persona.password,
      role: 'student',
    });
    if (res.status === 201 || res.status === 409) {
      students.push({ ...persona, userId: res.data.user?.id });
      if (res.status === 201) {
        process.stdout.write('.');
      } else {
        process.stdout.write('R');
      }
    } else {
      console.error(`\n   ❌ Failed to register ${persona.email}: ${res.status}`);
    }
  }
  console.log(`\n   Registered ${students.length}/${PERSONAS.length} students`);

  // 5. Enroll all students via direct SQL (bypasses FOR UPDATE lock issue in /sections/join)
  console.log('\n📋 Enrolling students via direct SQL...');
  const enrollDb = new Client({
    host: process.env.DB_HOST || 'localhost',
    port: parseInt(process.env.DB_PORT || '5432'),
    database: process.env.DB_NAME || 'codeinsight',
    user: process.env.DB_USER || 'codeuser',
    password: process.env.DB_PASSWORD || 'codepassword123',
  });
  await enrollDb.connect();
  let enrolled = 0;
  let alreadyEnrolled = 0;
  for (const student of students) {
    // Fetch student ID from database
    const idRes = await enrollDb.query(
      'SELECT id FROM users WHERE email = $1', [student.email]
    );
    if (!idRes.rows.length) continue;
    const studentId = idRes.rows[0].id;
    student.userId = studentId;

    try {
      await enrollDb.query(
        'INSERT INTO enrollments(student_id, section_id) VALUES($1, $2)',
        [studentId, section.id]
      );
      enrolled++;
    } catch (err) {
      if (err.code === '23505') {
        alreadyEnrolled++; // UNIQUE constraint violation
      } else {
        console.error(`\n   ⚠️  ${student.email} enrollment failed: ${err.message}`);
      }
    }
    process.stdout.write('.');
  }
  await enrollDb.end();
  console.log(`\n   Enrolled: ${enrolled} new, ${alreadyEnrolled} already enrolled`);

  // 6. Create exercises for each cycle (using authenticated instructor client)
  console.log('\n📚 Creating exercises...');

  // Baseline exercise
  res = await instrClient.post('/exercises', {
    title: 'Sim Baseline - Hello World',
    description: 'Print "Hello World" to the console.',
    concept_name: 'Variables',
    section_id: section.id,
    time_limit_minutes: 15,
    test_cases: [
      { input: '', expectedOutput: 'Hello World', hidden: false },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Write your code here\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\nusing namespace std;\n\nint main() {\n  cout << "Hello World" << endl;\n  return 0;\n}\n',
  });
  const baselineExercise = res.status === 201 ? res.data : null;
  console.log(`   Baseline exercise: ${baselineExercise ? baselineExercise.id : 'FAILED'}`);

  // Stress exercise
  res = await instrClient.post('/exercises', {
    title: 'Sim Stress - Print 1 to N',
    description: 'Print numbers from 1 to N using a loop.',
    concept_name: 'Loops',
    section_id: section.id,
    time_limit_minutes: 30,
    test_cases: [
      { input: '5', expectedOutput: '1\n2\n3\n4\n5\n', hidden: false },
      { input: '3', expectedOutput: '1\n2\n3\n', hidden: false },
      { input: '10', expectedOutput: '1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n', hidden: true },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  int n;\n  cin >> n;\n  // Write your loop here\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\nusing namespace std;\n\nint main() {\n  int n;\n  cin >> n;\n  for (int i = 1; i <= n; i++) {\n    cout << i << endl;\n  }\n  return 0;\n}\n',
  });
  const stressExercise = res.status === 201 ? res.data : null;
  console.log(`   Stress exercise: ${stressExercise ? stressExercise.id : 'FAILED'}`);

  // Adversarial exercise
  res = await instrClient.post('/exercises', {
    title: 'Sim Adversarial - Copy Detection',
    description: 'Print numbers from 1 to N. This exercise monitors for copy-paste behavior.',
    concept_name: 'Loops',
    section_id: section.id,
    time_limit_minutes: 30,
    test_cases: [
      { input: '5', expectedOutput: '1\n2\n3\n4\n5\n', hidden: false },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  int n;\n  cin >> n;\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\nusing namespace std;\n\nint main() {\n  int n;\n  cin >> n;\n  for (int i = 1; i <= n; i++) {\n    cout << i << endl;\n  }\n  return 0;\n}\n',
  });
  const adversarialExercise = res.status === 201 ? res.data : null;
  console.log(`   Adversarial exercise: ${adversarialExercise ? adversarialExercise.id : 'FAILED'}`);

  console.log('\n✅ SETUP COMPLETE\n');

  return {
    client: instrClient,
    instructor,
    section,
    students,
    exercises: {
      baseline: baselineExercise,
      stress: stressExercise,
      adversarial: adversarialExercise,
    },
  };
}

// ── Submission Helper ────────────────────────────────────────────────────────

async function submitCode(studentClient, exerciseId, code, timeSpentSeconds = 60, submissionCount = 0) {
  try {
    const res = await studentClient.post('/submissions/submit', {
      exerciseId,
      code,
      timeSpentSeconds,
      behavioralData: {
        tabSwitchCount: 0,
        pasteCount: 0,
        idleTimeSeconds: 0,
      },
    });
    memCheck({ submissionCount });
    return { status: res.status, data: res.data };
  } catch (err) {
    memCheck({ submissionCount });
    return { status: err.response?.status || 500, data: { message: err.message } };
  }
}

/**
 * Submit code with explicit behavioral telemetry.
 * Used for adversarial simulations where anomalous behavior should be recorded.
 */
async function submitCodeWithTelemetry(studentClient, exerciseId, code, timeSpentSeconds,
  telemetry, submissionCount = 0) {
  try {
    const res = await studentClient.post('/submissions/submit', {
      exerciseId,
      code,
      timeSpentSeconds,
      behavioralData: {
        tabSwitchCount: telemetry.tabSwitchCount || 0,
        pasteCount: telemetry.pasteCount || 0,
        idleTimeSeconds: telemetry.idleTimeSeconds || 0,
      },
    });
    memCheck({ submissionCount });
    return { status: res.status, data: res.data };
  } catch (err) {
    memCheck({ submissionCount });
    return { status: err.response?.status || 500, data: { message: err.message } };
  }
}

// ── Cycle 1: Baseline Run ────────────────────────────────────────────────────

async function runBaseline({ students, exercises }) {
  console.log('\n📊 CYCLE 1: BASELINE RUN');
  console.log('-'.repeat(60));

  const exerciseId = exercises.baseline.id;
  let totalSubmissions = 0;
  let totalPasses = 0;
  let totalFails = 0;

  // Build all submission tasks
  const tasks = [];
  for (const student of students) {
    const maxAttempts = student.tier === 'high_performer' ? 1 : 2;
    for (let attempt = 1; attempt <= maxAttempts; attempt++) {
      let code;
      if (attempt === maxAttempts || student.tier === 'high_performer') {
        code = `#include <iostream>\nusing namespace std;\nint main() {\n  cout << "Hello World" << endl;\n  return 0;\n}\n`;
      } else {
        code = `#include <iostream>\nusing namespace std;\nint main() {\n  cout << "Hello World" << endl\n  return 0;\n}\n`;
      }
      const timeSpent = Math.round(student.avgTimeSec / maxAttempts);
      const studentClient = createClient({
        id: student.userId, name: student.name, email: student.email, role: 'student'
      });
      tasks.push(async () => {
        const result = await submitCode(studentClient, exerciseId, code, timeSpent);
        return result;
      });
    }
  }

  // Execute in batches of BATCH_SIZE
  const results = await runInBatches(tasks, BATCH_SIZE);
  for (const result of results) {
    totalSubmissions++;
    if (result.data.allPassed) totalPasses++;
    else totalFails++;
  }

  console.log(`   Submissions: ${totalSubmissions}, Passes: ${totalPasses}, Fails: ${totalFails}`);
  console.log('   ✅ Baseline complete\n');
  return { totalSubmissions, totalPasses, totalFails };
}

// ── Cycle 2: Stress Run ─────────────────────────────────────────────────────

async function runStress({ students, exercises }) {
  console.log('\n💪 CYCLE 2: STRESS RUN');
  console.log('-'.repeat(60));

  const exerciseId = exercises.stress.id;
  let totalSubmissions = 0;
  let totalPasses = 0;
  let totalFails = 0;
  let infiniteLoopsCaught = 0;

  // Build all submission tasks
  const tasks = [];
  for (const student of students) {
    const maxAttempts = student.retryBehavior === 'heavy' ? 5
      : student.retryBehavior === 'moderate' ? 3 : 2;

    for (let attempt = 1; attempt <= maxAttempts; attempt++) {
      let code;
      if (student.tier === 'high_performer') {
        code = generatePayload('STATE_CORRECT', student);
      } else if (student.tier === 'medium_learner') {
        code = Math.random() > 0.3
          ? generatePayload('STATE_CORRECT', student)
          : generatePayload('BUG_OFF_BY_ONE', student);
      } else if (student.tier === 'struggling_learner') {
        const rand = Math.random();
        if (rand < 0.6) {
          code = generatePayload('BUG_INFINITE_LOOP', student);
        } else if (rand < 0.9) {
          code = generatePayload('BUG_OFF_BY_ONE', student);
        } else {
          code = generatePayload('STATE_CORRECT', student);
        }
      } else {
        code = attempt % 2 === 0
          ? generatePayload('BUG_SYNTAX_ERROR', student)
          : generatePayload('BUG_INFINITE_LOOP', student);
      }

      const timeSpent = student.tier === 'struggling_learner'
        ? student.avgTimeSec + Math.floor(Math.random() * 300)
        : student.avgTimeSec;

      const studentClient = createClient({
        id: student.userId, name: student.name, email: student.email, role: 'student'
      });

      tasks.push(async () => {
        const result = await submitCode(studentClient, exerciseId, code, timeSpent);
        return result;
      });
    }
  }

  // Execute in batches
  const results = await runInBatches(tasks, BATCH_SIZE);
  for (const result of results) {
    totalSubmissions++;
    if (result.data.allPassed) totalPasses++;
    else totalFails++;
    if (result.data.status === 'Time Limit Exceeded' || result.data.status === 'Killed') {
      infiniteLoopsCaught++;
    }
  }

  console.log(`   Submissions: ${totalSubmissions}, Passes: ${totalPasses}, Fails: ${totalFails}`);
  console.log(`   Infinite loops caught by sandbox: ${infiniteLoopsCaught}`);
  console.log('   ✅ Stress complete\n');
  return { totalSubmissions, totalPasses, totalFails, infiniteLoopsCaught };
}

// ── Cycle 3: Adversarial Run ─────────────────────────────────────────────────

async function runAdversarial({ students, exercises }) {
  console.log('\n⚔️  CYCLE 3: ADVERSARIAL RUN');
  console.log('-'.repeat(60));

  const exerciseId = exercises.adversarial.id;
  let totalSubmissions = 0;
  let totalPasses = 0;
  let totalFails = 0;

  const adversarialStudents = students.filter((s) => s.tier === 'adversarial');
  const normalStudents = students.filter((s) => s.tier !== 'adversarial');

  // Build all submission tasks
  const tasks = [];

  // Normal students — single correct submission each
  for (const student of normalStudents) {
    const studentClient = createClient({
      id: student.userId, name: student.name, email: student.email, role: 'student'
    });
    tasks.push(async () => {
      const code = generatePayload('STATE_CORRECT', student);
      return await submitCode(studentClient, exerciseId, code, student.avgTimeSec);
    });
  }

  // Adversarial students — copy-paste + spam + massive payload
  for (const student of adversarialStudents) {
    const studentClient = createClient({
      id: student.userId, name: student.name, email: student.email, role: 'student'
    });

    // Copy-paste submission: 0 typing, 1 paste, instant submission
    tasks.push(async () => {
      return await submitCodeWithTelemetry(studentClient, exerciseId,
        generatePayload('FLAG_COPY_PASTE', student), 0,
        { tabSwitchCount: 0, pasteCount: 1, idleTimeSeconds: 0 }
      );
    });

    // Spam submissions: rapid-fire with anomalous telemetry
    for (let i = 0; i < 10; i++) {
      const spamCode = i % 2 === 0
        ? generatePayload('STATE_CORRECT', student)
        : generatePayload('BUG_SYNTAX_ERROR', student);
      tasks.push(async () => {
        return await submitCodeWithTelemetry(studentClient, exerciseId, spamCode, 1,
          { tabSwitchCount: 3, pasteCount: 0, idleTimeSeconds: 0 }
        );
      });
    }
    tasks.push(async () => {
      return await submitCodeWithTelemetry(studentClient, exerciseId,
        generatePayload('MASSIVE_PAYLOAD', student), 5,
        { tabSwitchCount: 5, pasteCount: 2, idleTimeSeconds: 0 }
      );
    });
  }

  // Execute in batches
  const results = await runInBatches(tasks, BATCH_SIZE);
  for (const result of results) {
    totalSubmissions++;
    if (result.data.allPassed) totalPasses++;
    else totalFails++;
  }

  console.log(`   Submissions: ${totalSubmissions}, Passes: ${totalPasses}, Fails: ${totalFails}`);
  console.log('   ✅ Adversarial complete\n');
  return { totalSubmissions, totalPasses, totalFails };
}

// ── Trigger CDS Calculation ──────────────────────────────────────────────────

async function triggerCDS(client, exerciseId) {
  console.log(`\n📈 Triggering batch CDS for exercise ${exerciseId}...`);
  try {
    // Use a longer timeout for batch CDS computation
    client.defaults.timeout = 300000; // 5 minutes for large datasets
    const res = await client.post(`/exercises/${exerciseId}/close`);
    console.log(`   Exercise closed: ${res.status} ${res.data.message || ''}`);

    await client.post(`/exercises/${exerciseId}/reopen`);
    console.log('   Exercise reopened');
    client.defaults.timeout = 120000; // reset timeout
  } catch (err) {
    console.error(`   ⚠️  CDS trigger failed: ${err.message}`);
  }
}

module.exports = { createClient, cleanup, setup, runBaseline, runStress, runAdversarial, triggerCDS };
