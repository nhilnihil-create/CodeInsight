#!/usr/bin/env node
/**
 * simulation/liveDemo.js
 *
 * REALISTIC 50-Student Live Demo — real API calls, human delays, varied code.
 * Uses direct JWT generation for auth (avoids login rate limiter).
 *
 * USAGE:
 *   node simulation/liveDemo.js
 *
 * PREREQUISITES:
 *   - Backend running on http://127.0.0.1:5000
 *   - Frontend dev server on http://127.0.0.1:5173
 *   - Docker + gcc:14-bookworm image
 *
 * KEY FEATURES:
 *   - Real HTTP API for data ops (exercises, submissions, close)
 *   - Human-like thinking/typing delays (300-2500ms)
 *   - Per-student unique code with 12+ realistic error patterns
 *   - Conditional retry on 5xx errors
 *   - ETA tracking + live analytics polling every 10 students
 *   - 50 varied personas (10 high, 20 medium, 15 struggling, 5 adversarial)
 */

const axios = require('axios');
const jwt = require('jsonwebtoken');
const { Client } = require('pg');
const { PERSONAS } = require('./personas');

// ── Config ────────────────────────────────────────────────────────────────────

const API_BASE = 'http://127.0.0.1:5000/api';

const DB_CONFIG = {
  host: process.env.DB_HOST || 'localhost',
  port: parseInt(process.env.DB_PORT || '5432'),
  database: process.env.DB_NAME || 'codeinsight',
  user: process.env.DB_USER || 'codeuser',
  password: process.env.DB_PASSWORD || 'codepassword123',
};

const JWT_SECRET = process.env.JWT_SECRET || 'your_super_secret_key_change_this_in_production';

const DELAY_MS = {
  THINKING:  [500, 2500],
  TYPING:    [300, 1200],
  NAV:       [200, 600],
  RETRY_GAP: [800, 1500],
  STUDENT:   [100, 300],
};

const MAX_RETRIES = 2;

// ── Helpers ────────────────────────────────────────────────────────────────────

const sleep = ms => new Promise(r => setTimeout(r, ms));
const rand = (min, max) => Math.floor(Math.random() * (max - min + 1)) + min;
const randDelay = r => rand(r[0], r[1]);

const C = {
  bold:   s => `\x1b[1m${s}\x1b[0m`,
  dim:    s => `\x1b[2m${s}\x1b[0m`,
  green:  s => `\x1b[32m${s}\x1b[0m`,
  yellow: s => `\x1b[33m${s}\x1b[0m`,
  cyan:   s => `\x1b[36m${s}\x1b[0m`,
  red:    s => `\x1b[31m${s}\x1b[0m`,
};

function makeClient(token) {
  const headers = { 'Content-Type': 'application/json' };
  if (token) headers.Cookie = `ci_token=${token}`;
  return axios.create({
    baseURL: API_BASE, headers,
    validateStatus: () => true, timeout: 30000,
  });
}

function genToken(user) {
  return jwt.sign(
    { id: user.id, name: user.name, email: user.email, role: user.role },
    JWT_SECRET, { expiresIn: '7d' }
  );
}

// ── ETA Tracker ────────────────────────────────────────────────────────────────

let etaStart, etaTotal, etaDone;
function etaInit(total) { etaStart = Date.now(); etaTotal = total; etaDone = 0; }
function etaTick(n = 1) {
  etaDone += n;
  if (etaDone === 0) return '--:--';
  const per = (Date.now() - etaStart) / 1000 / etaDone;
  const rem = per * (etaTotal - etaDone);
  const m = Math.floor(rem / 60), s = Math.floor(rem % 60);
  return `${m}:${String(s).padStart(2, '0')}`;
}

// ── Code Generators ─────────────────────────────────────────────────────────────

function genHello(idx, attempt, correct) {
  const inc = ['#include <iostream>', '#include <iostream>\nusing namespace std;'][idx % 2];
  const ns = inc.includes('using namespace') ? '' : '\nusing namespace std;';
  if (correct) {
    const b = ['cout << "Hello World" << endl;', 'cout << "Hello World\\n";',
               'printf("Hello World\\n");', 'puts("Hello World");'][idx % 4];
    return `${inc}${ns}\n\nint main() {\n  ${b}\n  return 0;\n}\n`;
  }
  const e = (idx + attempt) % 6;
  const base = `${inc}${ns}\n\nint main() {\n`;
  switch (e) {
    case 0: return `${base}  cout << "Hello World" << endl\n  return 0;\n}\n`;
    case 1: return `${base}  c0ut << "Hello World" << endl;\n  return 0;\n}\n`;
    case 2: return `${base}  cout << "hello world" << endl;\n  return 0;\n}\n`;
    case 3: return `${base}  Cout << "Hello World" << endl;\n  return 0;\n}\n`;
    case 4: return `${base}  cout << "Hello World" << endl;\n  return 0;\n`;
    case 5: return `${base}  cout << "Hello World" << endl;\n  return 0;\n}\n`;
  }
}

function genLoop(idx, attempt, correct) {
  if (correct) {
    const s = idx % 3;
    if (s === 1) return '#include <iostream>\nusing namespace std;\n\nint main() {\n  int n;\n  cin >> n;\n  int i = 1;\n  while (i <= n) { cout << i << endl; i++; }\n  return 0;\n}\n';
    if (s === 2) return '#include <iostream>\nusing namespace std;\n\nint main() {\n  int n;\n  cin >> n;\n  int i = 1;\n  do { cout << i << endl; i++; } while (i <= n);\n  return 0;\n}\n';
    return '#include <iostream>\nusing namespace std;\n\nint main() {\n  int n;\n  cin >> n;\n  for (int i = 1; i <= n; i++) cout << i << endl;\n  return 0;\n}\n';
  }
  const e = (idx + attempt * 7) % 8;
  switch (e) {
    case 0: // off-by-one (< vs <=)
      return '#include <iostream>\nusing namespace std;\n\nint main() {\n  int n;\n  cin >> n;\n  for (int i = 1; i < n; i++) cout << i << endl;\n  return 0;\n}\n';
    case 1: // starts at 0
      return '#include <iostream>\nusing namespace std;\n\nint main() {\n  int n;\n  cin >> n;\n  for (int i = 0; i <= n; i++) cout << i << endl;\n  return 0;\n}\n';
    case 2: // missing semicolon
      return '#include <iostream>\nusing namespace std;\n\nint main() {\n  int n;\n  cin >> n\n  for (int i = 1; i <= n; i++) cout << i << endl;\n  return 0;\n}\n';
    case 3: // n-1 bound
      return '#include <iostream>\nusing namespace std;\n\nint main() {\n  int n;\n  cin >> n;\n  for (int i = 1; i < n; i++) cout << i << endl;\n  return 0;\n}\n';
    case 4: // reverse
      return '#include <iostream>\nusing namespace std;\n\nint main() {\n  int n;\n  cin >> n;\n  for (int i = n; i >= 1; i--) cout << i << endl;\n  return 0;\n}\n';
    case 5: // float n
      return '#include <iostream>\nusing namespace std;\n\nint main() {\n  float n;\n  cin >> n;\n  for (int i = 1; i <= n; i++) cout << i << endl;\n  return 0;\n}\n';
    case 6: // while no increment
      return '#include <iostream>\nusing namespace std;\n\nint main() {\n  int n;\n  cin >> n;\n  int i = 1;\n  while (i <= n) { cout << i << endl; }\n  return 0;\n}\n';
    case 7: // wrong variable
      return '#include <iostream>\nusing namespace std;\n\nint main() {\n  int n;\n  cin >> n;\n  for (int j = 1; j <= n; i++) cout << j << endl;\n  return 0;\n}\n';
  }
}

// ── Submission ──────────────────────────────────────────────────────────────────

async function submitWithRetry(sc, exerciseId, code, timeSpent) {
  for (let r = 0; r <= MAX_RETRIES; r++) {
    const res = await sc.post('/submissions/submit', { exerciseId, code, timeSpentSeconds: timeSpent });
    if (res.status < 500) return res;
    if (r < MAX_RETRIES) await sleep(randDelay(DELAY_MS.RETRY_GAP));
  }
  return null;
}

async function submitRound(students, exerciseId, codeGen, attMap, label, ic) {
  console.log(C.bold(`\n📌 ${label}`));
  console.log('─'.repeat(50));
  const total = students.reduce((a, s) => a + (attMap[s.tier] || 1), 0);
  etaInit(total);
  let subs = 0, pass = 0, fail = 0;

  for (let i = 0; i < students.length; i++) {
    const s = students[i];
    if (!s.token) continue;
    const max = attMap[s.tier] || 1;
    const sc = makeClient(s.token);

    for (let a = 1; a <= max; a++) {
      const correct = a === max;
      const code = codeGen(i, a, correct);
      const ts = correct ? rand(30, 180) : rand(60, 600);
      await sleep(randDelay(DELAY_MS.THINKING));
      const eta = etaTick();
      process.stdout.write(`   [${String(i + 1).padStart(2, '0')}/50] ${s.name.padEnd(20)} a${a}/${max} `);

      const res = await submitWithRetry(sc, exerciseId, code, ts);
      if (res && res.status === 200) {
        const ok = res.data.allPassed;
        subs++; ok ? pass++ : fail++;
        process.stdout.write(ok ? C.green('✓\n') : C.red('✗\n'));
        if (a === max && res.data.liveCDS) {
          const c = res.data.liveCDS;
          process.stdout.write(C.dim(`          CDS:${c.cds?.toFixed(3)||'---'} ETA:${eta}\n`));
        } else process.stdout.write(C.dim(`          ETA: ${eta}\n`));
      } else {
        fail++; subs++;
        process.stdout.write(C.red(`✗ (${res?.status||'timeout'}) ETA:${eta}\n`));
      }
      if (a < max) await sleep(randDelay(DELAY_MS.TYPING));
    }
    await sleep(randDelay(DELAY_MS.STUDENT));
    if ((i + 1) % 10 === 0) await showLiveStats(ic, exerciseId);
  }
  console.log(C.dim(`   ─────────────────────────────────────`));
  console.log(`   ${C.bold('Result:')} ${subs} subs · ${C.green(`${pass} passed`)} · ${C.red(`${fail} failed`)}`);
  return { subs, pass, fail };
}

// ── Analytics ───────────────────────────────────────────────────────────────────

async function showLiveStats(ic, exerciseId) {
  try {
    const r = await ic.get(`/analytics/live-cds/${exerciseId}`);
    if (r.status === 200 && Array.isArray(r.data)) {
      const s = r.data.filter(x => x.cds != null);
      if (s.length) console.log(C.dim(`   📊 Live CDS: ${s.length} scored, avg ${(s.reduce((a,b)=>a+b.cds,0)/s.length).toFixed(4)}`));
    }
  } catch (_) {}
}

async function showFinalAnalytics(ic, sectionId) {
  const r1 = await ic.get(`/analytics/reports/${sectionId}/summary`);
  if (r1.status === 200) {
    console.log(`\n  ${C.bold('Section Summary')}`);
    console.log(`    Enrolled: ${r1.data.totalStudents || '?'}  Avg CDS: ${r1.data.avgCds?.toFixed(4) || 'N/A'}`);
    console.log(`    CDS range: ${r1.data.minCds?.toFixed(4)||'?'} – ${r1.data.maxCds?.toFixed(4)||'?'}`);
    console.log(`    At-Risk: ${r1.data.atRiskCount || 0}  Flags: ${r1.data.flagCount || 0}`);
  }
  const r2 = await ic.get(`/analytics/activity/${sectionId}`);
  if (r2.status === 200) console.log(`    Recent activity: ${Array.isArray(r2.data) ? r2.data.length : '?'} events`);

  // Concept mastery
  const r3 = await ic.get(`/analytics/reports/${sectionId}/concept-mastery?weeks=5`);
  if (r3.status === 200 && r3.data.concepts?.length) {
    const withData = r3.data.concepts.filter(c => c.current > 0);
    console.log(`\n  ${C.bold('Concept Mastery')} (concepts with data: ${withData.length}/${r3.data.concepts.length})`);
    for (const c of withData.slice(0, 6)) {
      console.log(`    ${c.name.padEnd(16)} ${c.current}% mastery`);
    }
  } else {
    console.log(C.yellow(`\n  ⚠ Concept mastery: no data yet (CDS may need batch computation)`));
  }
}

// ── MAIN ────────────────────────────────────────────────────────────────────────

async function main() {
  console.clear();
  const startedAt = Date.now();
  const db = new Client(DB_CONFIG);
  await db.connect();

  console.log(C.bold('\n╔══════════════════════════════════════════════════════╗'));
  console.log(C.bold('║     CodeInsight · Live 50-Student Demo             ║'));
  console.log(C.bold('╚══════════════════════════════════════════════════════╝'));
  console.log(C.dim(`   ${new Date().toLocaleTimeString()}\n`));

  // ── 1. Instructor JWT ──────────────────────────────────────────────────────────
  console.log(C.bold('1/6  Generate Instructor Token'));
  let iRes = await db.query("SELECT id, name, email, role FROM users WHERE email='instructor@psu.edu'");
  if (!iRes.rows.length) {
    console.log(C.yellow('   Instructor not found, registering via API...'));
    const c = makeClient();
    const rr = await c.post('/auth/register', { name: 'Juan Dela Cruz', email: 'instructor@psu.edu', password: 'password123', role: 'instructor' });
    if (rr.status !== 201) throw new Error(`Instructor register: ${rr.status}`);
    iRes = await db.query("SELECT id, name, email, role FROM users WHERE email='instructor@psu.edu'");
  }
  const instructor = iRes.rows[0];
  const instrToken = genToken(instructor);
  const ic = makeClient(instrToken);
  console.log(C.green(`   ✓ ${instructor.name} (ID:${instructor.id})`));

  // ── 2. Create Section ──────────────────────────────────────────────────────────
  console.log(C.bold('\n2/6  Create Demo Section'));
  const secName = `Live Demo ${new Date().toISOString().slice(0, 16).replace('T', ' ')}`;
  const sr = await ic.post('/sections', { name: secName, course_code: 'CS101', school_year: '2026-2027', semester: 'Demo' });
  if (sr.status !== 201) throw new Error(`Section create: ${sr.status} ${JSON.stringify(sr.data)}`);
  const section = sr.data;
  console.log(C.green(`   ✓ "${section.name}" (ID:${section.id}, Code:${C.yellow(section.code)})`));

  // ── 3. Create Exercises ────────────────────────────────────────────────────────
  console.log(C.bold('\n3/6  Create Exercises'));

  const e1 = await ic.post('/exercises', {
    title: 'HW — Hello World', description: 'Print "Hello World" to the console.',
    concept_name: 'Variables', section_id: section.id, time_limit_minutes: 15,
    test_cases: [{ input: '', expectedOutput: 'Hello World', hidden: false }],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\nusing namespace std;\n\nint main() {\n  cout << "Hello World" << endl;\n  return 0;\n}\n',
  });
  if (e1.status !== 201) throw new Error(`Ex1: ${e1.status}`);
  console.log(C.green(`   ✓ Hello World (ID:${e1.data.id})`));

  const e2 = await ic.post('/exercises', {
    title: 'LP — Print 1 to N', description: 'Print numbers 1..N using a loop.',
    concept_name: 'Loops', section_id: section.id, time_limit_minutes: 30,
    test_cases: [
      { input: '5', expectedOutput: '1\n2\n3\n4\n5\n', hidden: false },
      { input: '3', expectedOutput: '1\n2\n3\n', hidden: false },
      { input: '10', expectedOutput: '1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n', hidden: true },
    ],
    starter_code: '#include <iostream>\nusing namespace std;\n\nint main() {\n  int n;\n  cin >> n;\n  return 0;\n}\n',
    reference_solution: '#include <iostream>\nusing namespace std;\n\nint main() {\n  int n;\n  cin >> n;\n  for (int i = 1; i <= n; i++) cout << i << endl;\n  return 0;\n}\n',
  });
  if (e2.status !== 201) throw new Error(`Ex2: ${e2.status}`);
  console.log(C.green(`   ✓ Print 1 to N (ID:${e2.data.id})`));

  const exercises = [{ ...e1.data, tag: 'hello' }, { ...e2.data, tag: 'loop' }];

  // ── 4. Register 50 Students ────────────────────────────────────────────────────
  console.log(C.bold('\n4/6  Register 50 Students'));
  const students = [];

  for (let i = 0; i < PERSONAS.length; i++) {
    const p = PERSONAS[i];
    process.stdout.write(`   [${String(i + 1).padStart(2, '0')}/50] ${p.name.padEnd(20)} `);

    // Try register via API first
    const c = makeClient(); // no auth needed for register
    const rr = await c.post('/auth/register', { name: p.name, email: p.email, password: p.password, role: 'student' });

    if (rr.status === 201) {
      const uid = rr.data.user?.id;
      const tok = genToken({ id: uid, name: p.name, email: p.email, role: 'student' });
      students.push({ ...p, userId: uid, token: tok });
      console.log(C.green('✓'));
    } else if (rr.status === 409) {
      // Already exists — query DB for ID then generate JWT
      const ux = await db.query('SELECT id FROM users WHERE email = $1', [p.email]);
      if (ux.rows.length) {
        const uid = ux.rows[0].id;
        const tok = genToken({ id: uid, name: p.name, email: p.email, role: 'student' });
        students.push({ ...p, userId: uid, token: tok });
        console.log(C.yellow('↻'));
      } else {
        console.log(C.red(`✗ no user`));
      }
    } else {
      console.log(C.red(`✗ ${rr.status}`));
    }
    await sleep(randDelay(DELAY_MS.NAV));
  }
  console.log(C.green(`\n   ✓ ${students.length} students ready`));

  // ── 5. Enroll ──────────────────────────────────────────────────────────────────
  console.log(C.bold('\n5/6  Enroll Students'));
  const ids = students.filter(s => s.userId).map(s => s.userId);
  const er = await ic.post(`/sections/${section.id}/enroll`, { student_ids: ids });
  if (er.status === 200) {
    console.log(C.green(`   ✓ ${er.data.message}`));
  } else {
    console.log(C.yellow(`   Bulk: ${er.status}, trying individual...`));
    let n = 0;
    for (const s of students) {
      if (!s.token) continue;
      const sc = makeClient(s.token);
      const jr = await sc.post('/sections/join', { code: section.code });
      if (jr.status === 200 || jr.status === 409) n++;
      await sleep(15);
    }
    console.log(C.green(`   ✓ ${n} enrolled individually`));
  }

  // ── 6a. R1: Hello World ────────────────────────────────────────────────────────
  const r1 = await submitRound(students, exercises[0].id, genHello,
    { high_performer: 1, medium_learner: 2, struggling_learner: 3, adversarial: 1 },
    '6a/6  R1: Hello World', ic);

  // ── 6b. R2: Print 1 to N ───────────────────────────────────────────────────────
  const r2 = await submitRound(students, exercises[1].id, genLoop,
    { high_performer: 1, medium_learner: 3, struggling_learner: 5, adversarial: 1 },
    '6b/6  R2: Print 1 to N', ic);

  // ── 7. Batch CDS ───────────────────────────────────────────────────────────────
  console.log(C.bold('\n7/8  Batch CDS Computation'));
  ic.defaults.timeout = 300000;
  for (const ex of exercises) {
    console.log(`   Closing "${ex.title}"...`);
    const cr = await ic.post(`/exercises/${ex.id}/close`);
    const msg = cr.data?.message || '';
    console.log(`      Close: ${cr.status} ${msg}`);
    if (cr.status === 200) {
      await sleep(1000);
      const rr = await ic.post(`/exercises/${ex.id}/reopen`);
      console.log(`      Reopen: ${rr.status}`);
    }
  }
  ic.defaults.timeout = 30000;

  // ── 8. Final Analytics ─────────────────────────────────────────────────────────
  console.log(C.bold('\n8/8  Final Analytics'));
  await showFinalAnalytics(ic, section.id);

  await db.end();

  // ── Summary + URLs ─────────────────────────────────────────────────────────────
  const total = r1.subs + r2.subs;
  const elapsed = ((Date.now() - startedAt) / 1000).toFixed(1);

  console.log(C.bold('\n══════════════════════════════════════════════════════'));
  console.log(C.green('  ✅ Demo complete! Open in your browser:'));
  console.log('');
  console.log(`  ${C.cyan('Dashboard')}        → http://127.0.0.1:5173/instructor/dashboard`);
  console.log(`  ${C.cyan('Command Center')}    → http://127.0.0.1:5173/instructor/command`);
  console.log(`  ${C.cyan('Reports')}           → http://127.0.0.1:5173/instructor/reports`);
  console.log(`  ${C.cyan('Section Detail')}    → http://127.0.0.1:5173/instructor/sections/${section.id}`);
  console.log(`  ${C.cyan('Student Roster')}    → http://127.0.0.1:5173/instructor/students`);
  console.log(`  ${C.cyan('Heatmap')}           → http://127.0.0.1:5173/instructor/heatmap`);
  console.log(`  ${C.cyan('Integrity')}         → http://127.0.0.1:5173/instructor/integrity`);
  console.log(C.dim(`\n  Login: instructor@psu.edu / password123`));
  console.log(C.yellow(`  💡 Keep dashboard open to see live updates!`));

  console.log(C.bold('\n──────────────────────────────────────────────────────'));
  console.log(`  ${C.bold('Summary')}`);
  console.log(`  Time:        ${elapsed}s  Section ID: ${section.id}`);
  console.log(`  Students:    ${students.length}`);
  console.log(`  Submissions: ${total} total`);
  console.log(`    R1 HW:     ${r1.subs} (${C.green(r1.pass)}/${C.red(r1.fail)} pass/fail)`);
  console.log(`    R2 Loop:   ${r2.subs} (${C.green(r2.pass)}/${C.red(r2.fail)} pass/fail)`);
  console.log('──────────────────────────────────────────────────────\n');
}

main().catch(err => {
  console.error(C.red(`\n❌ ${err.message}`));
  console.error(err.stack);
  process.exit(1);
});
