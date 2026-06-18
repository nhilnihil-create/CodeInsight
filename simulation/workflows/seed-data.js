const http = require('http');
const { INSTRUCTOR, SECTION_NAME, SECTION_CODE, EXERCISES } = require('./config');
const { PERSONAS } = require('./personas');

let COOKIE = '';

function api(method, path, data) {
  return new Promise((resolve, reject) => {
    const body = data ? JSON.stringify(data) : null;
    const headers = { 'Content-Type': 'application/json' };
    if (COOKIE) headers['Cookie'] = COOKIE;
    const opts = { method, hostname: 'localhost', port: 5000, path, headers };
    const req = http.request(opts, res => {
      const setCookie = res.headers['set-cookie'];
      if (setCookie) {
        const match = setCookie.find(c => c.startsWith('ci_token='));
        if (match) COOKIE = 'ci_token=' + match.split(';')[0].split('=')[1];
      }
      let chunks = [];
      res.on('data', c => chunks.push(c));
      res.on('end', () => {
        const text = Buffer.concat(chunks).toString();
        try { resolve({ status: res.statusCode, body: JSON.parse(text) }); }
        catch { resolve({ status: res.statusCode, body: text }); }
      });
    });
    req.on('error', reject);
    if (body) req.write(body);
    req.end();
  });
}

async function registerStudent(p) {
  const res = await api('POST', '/api/auth/register', { name: p.name, email: p.email, password: p.password, role: 'student' });
  if (res.status === 201 || res.status === 200) { console.log('  OK: ' + p.name); return true; }
  if (res.status === 409) { console.log('  Exists: ' + p.name); return true; }
  console.log('  FAIL: ' + p.name + ' (' + res.status + ')');
  return false;
}

async function createSection() {
  const res = await api('POST', '/api/sections', { name: SECTION_NAME, course_code: SECTION_CODE, semester: 'Summer', school_year: '2026' });
  if (res.status === 201 || res.status === 200) {
    console.log('  Section created: id=' + res.body.id);
    return res.body.id;
  }
  console.log('  Section create result:', res.status, JSON.stringify(res.body).substring(0, 200));
  return null;
}

async function createExercise(sectionId, ex) {
  const res = await api('POST', '/api/exercises', {
    title: ex.title, description: ex.description,
    concept_name: ex.conceptName, section_id: sectionId,
    time_limit_minutes: ex.timeLimitMinutes,
    starter_code: ex.starterCode, reference_solution: ex.referenceSolution,
    test_cases: ex.testCases,
  });
  if (res.status === 201 || res.status === 200) {
    console.log('  Exercise: ' + ex.title + ' (id=' + res.body.id + ')');
    return res.body.id;
  }
  console.log('  Exercise FAIL: ' + ex.title + ':', res.status, JSON.stringify(res.body).substring(0, 150));
  return null;
}

async function enrollStudent(sectionId, email) {
  const res = await api('POST', '/api/sections/' + sectionId + '/enroll',  { emails: [email] });
  return res.status === 201 || res.status === 200 || res.status === 409;
}

async function seed() {
  console.log('=== SEEDING TEST DATA ===');
  console.log('\n1. Registering 15 students...');
  for (const p of PERSONAS) await registerStudent(p);

  console.log('\n2. Logging in as instructor...');
  await api('POST', '/api/auth/login', { email: INSTRUCTOR.email, password: INSTRUCTOR.password });
  console.log('  Logged in');

  console.log('\n3. Creating section...');
  const sectionId = await createSection();
  if (!sectionId) { console.log('FATAL: no section'); process.exit(1); }

  console.log('\n4. Creating exercises...');
  const exerciseIds = {};
  for (let i = 0; i < EXERCISES.length; i++) {
    const id = await createExercise(sectionId, EXERCISES[i]);
    exerciseIds[EXERCISES[i].title] = id;
    EXERCISES[i].id = id;
  }

  console.log('\n5. Enrolling students...');
  let ok = 0;
  for (const p of PERSONAS) { if (await enrollStudent(sectionId, p.email)) ok++; }
  console.log('  Enrolled: ' + ok + '/' + PERSONAS.length);

  console.log('\n=== SEED COMPLETE ===');
  console.log('Section ID: ' + sectionId);
  console.log('Exercise IDs:', JSON.stringify(exerciseIds));
  return { sectionId, exerciseIds };
}

if (require.main === module) {
  seed().then(r => {
    require('fs').writeFileSync(__dirname + '/seed-state.json', JSON.stringify(r, null, 2));
    console.log('\nState saved to seed-state.json');
    process.exit(0);
  }).catch(e => { console.error('Seed failed:', e); process.exit(1); });
}

module.exports = { seed };
