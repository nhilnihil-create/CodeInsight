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
const { Client } = require('pg');
const { PERSONAS, INSTRUCTOR } = require('./personas');
const { generatePayload, matchCodeNet, PAYLOADS } = require('./studentGenerator');

// ── Configuration ────────────────────────────────────────────────────────────

const API_BASE = process.env.SIM_API_BASE || 'http://127.0.0.1:5000/api';
const SLEEP_MS = (ms) => new Promise((r) => setTimeout(r, ms));

// Cookie jar for authenticated sessions
function createClient() {
  const jar = {};
  const client = axios.create({
    baseURL: API_BASE,
    withCredentials: true,
    headers: { 'Content-Type': 'application/json' },
    maxRedirects: 0,
    validateStatus: (status) => true,
    timeout: 30000,
  });

  client.interceptors.response.use((res) => {
    const setCookie = res.headers['set-cookie'];
    if (setCookie) {
      const authCookie = setCookie.find((c) => c.includes('ci_token'));
      if (authCookie) {
        jar.token = authCookie.split(';')[0];
      }
    }
    if (jar.token) {
      client.defaults.headers.Cookie = jar.token;
    }
    return res;
  });

  return { client, jar };
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
  } catch (err) {
    console.error('   ⚠️  Cleanup failed (non-fatal):', err.message);
    try { await db.end(); } catch (_) {}
  }
}

// ── Setup Phase ──────────────────────────────────────────────────────────────

async function setup() {
  console.log('🚀 SETUP PHASE');
  console.log('='.repeat(60));

  const { client, jar } = createClient();

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

  // 2. Login as instructor
  console.log('\n🔑 Logging in as instructor...');
  res = await client.post('/auth/login', {
    email: INSTRUCTOR.email,
    password: INSTRUCTOR.password,
  });
  if (res.status !== 200) {
    throw new Error(`Instructor login failed: ${res.status} ${JSON.stringify(res.data)}`);
  }
  const instructor = res.data.user;
  console.log(`   Logged in: ${instructor.name} (ID: ${instructor.id})`);

  // 3. Create section
  console.log('\n🏫 Creating section...');
  res = await client.post('/sections', {
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

  // 5. Enroll all students via join code
  console.log('\n📋 Enrolling students via join code...');
  let enrolled = 0;
  for (const student of students) {
    const loginRes = await client.post('/auth/login', {
      email: student.email,
      password: student.password,
    });
    if (loginRes.status !== 200) continue;

    const joinRes = await client.post('/sections/join', { code: inviteCode });
    if (joinRes.status === 200 || joinRes.status === 409) {
      enrolled++;
    } else {
      console.error(`   ⚠️  ${student.email} join failed: ${joinRes.status}`);
    }
  }
  console.log(`   Enrolled: ${enrolled}/${students.length}`);

  // 6. Create exercises for each cycle
  console.log('\n📚 Creating exercises...');

  // Baseline exercise
  res = await client.post('/exercises', {
    title: 'Sim Baseline - Hello World',
    description: 'Print "Hello World" to the console.',
    concept_name: 'Variables',
    section_id: section.id,
    time_limit_minutes: 15,
    test_cases: [
      { input: '', expected_output: 'Hello World', hidden: false },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Write your code here\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\nusing namespace std;\n\nint main() {\n  cout << "Hello World" << endl;\n  return 0;\n}\n',
    mode: 'learning',
  });
  const baselineExercise = res.status === 201 ? res.data : null;
  console.log(`   Baseline exercise: ${baselineExercise ? baselineExercise.id : 'FAILED'}`);

  // Stress exercise
  res = await client.post('/exercises', {
    title: 'Sim Stress - Print 1 to N',
    description: 'Print numbers from 1 to N using a loop.',
    concept_name: 'Loops',
    section_id: section.id,
    time_limit_minutes: 30,
    test_cases: [
      { input: '5', expected_output: '1\n2\n3\n4\n5\n', hidden: false },
      { input: '3', expected_output: '1\n2\n3\n', hidden: false },
      { input: '10', expected_output: '1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n', hidden: true },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  int n;\n  cin >> n;\n  // Write your loop here\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\nusing namespace std;\n\nint main() {\n  int n;\n  cin >> n;\n  for (int i = 1; i <= n; i++) {\n    cout << i << endl;\n  }\n  return 0;\n}\n',
    mode: 'learning',
  });
  const stressExercise = res.status === 201 ? res.data : null;
  console.log(`   Stress exercise: ${stressExercise ? stressExercise.id : 'FAILED'}`);

  // Adversarial exercise
  res = await client.post('/exercises', {
    title: 'Sim Adversarial - Copy Detection',
    description: 'Print numbers from 1 to N. This exercise monitors for copy-paste behavior.',
    concept_name: 'Loops',
    section_id: section.id,
    time_limit_minutes: 30,
    test_cases: [
      { input: '5', expected_output: '1\n2\n3\n4\n5\n', hidden: false },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  int n;\n  cin >> n;\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\nusing namespace std;\n\nint main() {\n  int n;\n  cin >> n;\n  for (int i = 1; i <= n; i++) {\n    cout << i << endl;\n  }\n  return 0;\n}\n',
    mode: 'learning',
  });
  const adversarialExercise = res.status === 201 ? res.data : null;
  console.log(`   Adversarial exercise: ${adversarialExercise ? adversarialExercise.id : 'FAILED'}`);

  console.log('\n✅ SETUP COMPLETE\n');

  return {
    client,
    jar,
    instructor,
    section,
    inviteCode,
    students,
    exercises: {
      baseline: baselineExercise,
      stress: stressExercise,
      adversarial: adversarialExercise,
    },
  };
}

// ── Submission Helper ────────────────────────────────────────────────────────

async function submitCode(studentClient, exerciseId, code, timeSpentSeconds = 60) {
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
    return { status: res.status, data: res.data };
  } catch (err) {
    return { status: err.response?.status || 500, data: { message: err.message } };
  }
}

// ── Cycle 1: Baseline Run ────────────────────────────────────────────────────

async function runBaseline({ client, students, exercises }) {
  console.log('\n📊 CYCLE 1: BASELINE RUN');
  console.log('-'.repeat(60));

  const exerciseId = exercises.baseline.id;
  let totalSubmissions = 0;
  let totalPasses = 0;
  let totalFails = 0;

  for (const student of students) {
    const maxAttempts = student.tier === 'high_performer' ? 1 : 2;

    for (let attempt = 1; attempt <= maxAttempts; attempt++) {
      const { client: studentClient } = createClient();
      await studentClient.post('/auth/login', {
        email: student.email,
        password: student.password,
      });

      let code;
      if (attempt === maxAttempts || student.tier === 'high_performer') {
        code = `#include <iostream>\nusing namespace std;\nint main() {\n  cout << "Hello World" << endl;\n  return 0;\n}\n`;
      } else {
        code = `#include <iostream>\nusing namespace std;\nint main() {\n  cout << "Hello World" << endl\n  return 0;\n}\n`;
      }

      const result = await submitCode(
        studentClient, exerciseId, code,
        Math.round(student.avgTimeSec / maxAttempts)
      );

      totalSubmissions++;
      if (result.data.allPassed) totalPasses++;
      else totalFails++;

      await SLEEP_MS(50);
    }
  }

  console.log(`   Submissions: ${totalSubmissions}, Passes: ${totalPasses}, Fails: ${totalFails}`);
  console.log('   ✅ Baseline complete\n');
  return { totalSubmissions, totalPasses, totalFails };
}

// ── Cycle 2: Stress Run ─────────────────────────────────────────────────────

async function runStress({ client, students, exercises }) {
  console.log('\n💪 CYCLE 2: STRESS RUN');
  console.log('-'.repeat(60));

  const exerciseId = exercises.stress.id;
  let totalSubmissions = 0;
  let totalPasses = 0;
  let totalFails = 0;
  let infiniteLoopsCaught = 0;

  for (const student of students) {
    const { client: studentClient } = createClient();
    await studentClient.post('/auth/login', {
      email: student.email,
      password: student.password,
    });

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

      const result = await submitCode(studentClient, exerciseId, code, timeSpent);
      totalSubmissions++;

      if (result.data.allPassed) totalPasses++;
      else totalFails++;

      if (result.data.status === 'Time Limit Exceeded' || result.data.status === 'Killed') {
        infiniteLoopsCaught++;
      }

      await SLEEP_MS(student.retryBehavior === 'heavy' ? 100 : 200);
    }
  }

  console.log(`   Submissions: ${totalSubmissions}, Passes: ${totalPasses}, Fails: ${totalFails}`);
  console.log(`   Infinite loops caught by sandbox: ${infiniteLoopsCaught}`);
  console.log('   ✅ Stress complete\n');
  return { totalSubmissions, totalPasses, totalFails, infiniteLoopsCaught };
}

// ── Cycle 3: Adversarial Run ─────────────────────────────────────────────────

async function runAdversarial({ client, students, exercises }) {
  console.log('\n⚔️  CYCLE 3: ADVERSARIAL RUN');
  console.log('-'.repeat(60));

  const exerciseId = exercises.adversarial.id;
  let totalSubmissions = 0;
  let totalPasses = 0;
  let totalFails = 0;

  const adversarialStudents = students.filter((s) => s.tier === 'adversarial');
  const normalStudents = students.filter((s) => s.tier !== 'adversarial');

  for (const student of normalStudents) {
    const { client: studentClient } = createClient();
    await studentClient.post('/auth/login', {
      email: student.email,
      password: student.password,
    });

    const code = generatePayload('STATE_CORRECT', student);
    const result = await submitCode(studentClient, exerciseId, code, student.avgTimeSec);
    totalSubmissions++;
    if (result.data.allPassed) totalPasses++;
    else totalFails++;
    await SLEEP_MS(100);
  }

  for (const student of adversarialStudents) {
    const { client: studentClient } = createClient();
    await studentClient.post('/auth/login', {
      email: student.email,
      password: student.password,
    });

    const copyPasteCode = generatePayload('FLAG_COPY_PASTE', student);
    const cpResult = await submitCode(studentClient, exerciseId, copyPasteCode, 0);
    totalSubmissions++;
    if (cpResult.data.allPassed) totalPasses++;
    else totalFails++;

    for (let i = 0; i < 10; i++) {
      const spamCode = i % 2 === 0
        ? generatePayload('STATE_CORRECT', student)
        : generatePayload('BUG_SYNTAX_ERROR', student);
      const spamResult = await submitCode(studentClient, exerciseId, spamCode, 1);
      totalSubmissions++;
      if (spamResult.data.allPassed) totalPasses++;
      else totalFails++;
      await SLEEP_MS(50);
    }

    const massiveResult = await submitCode(
      studentClient, exerciseId,
      generatePayload('MASSIVE_PAYLOAD', student),
      5
    );
    totalSubmissions++;
    if (massiveResult.data.allPassed) totalPasses++;
    else totalFails++;

    console.log(`   ${student.name}: copy-paste (${cpResult.status}), spam (10), massive (${massiveResult.status})`);
  }

  console.log(`\n   Submissions: ${totalSubmissions}, Passes: ${totalPasses}, Fails: ${totalFails}`);
  console.log('   ✅ Adversarial complete\n');
  return { totalSubmissions, totalPasses, totalFails };
}

// ── Trigger CDS Calculation ──────────────────────────────────────────────────

async function triggerCDS(client, exerciseId) {
  console.log(`\n📈 Triggering batch CDS for exercise ${exerciseId}...`);
  try {
    const res = await client.post(`/exercises/${exerciseId}/close`);
    console.log(`   Exercise closed: ${res.status} ${res.data.message || ''}`);

    await client.post(`/exercises/${exerciseId}/reopen`);
    console.log('   Exercise reopened');
  } catch (err) {
    console.error(`   ⚠️  CDS trigger failed: ${err.message}`);
  }
}

module.exports = { createClient, cleanup, setup, runBaseline, runStress, runAdversarial, triggerCDS };
