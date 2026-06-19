const http = require('http');
const { BACKEND_URL, INSTRUCTOR, STUDENT_PASSWORD, SECTION_TITLE, EXERCISE_TITLE } = require('./config');
const { PERSONAS } = require('./personas');
const { EXERCISE } = require('./exercise');

const HOST = { hostname: 'localhost', port: 5000 };

function apiCall(method, path, body, token) {
  return new Promise((resolve, reject) => {
    const url = new URL(path, BACKEND_URL);
    const data = body ? JSON.stringify(body) : null;
    const headers = { 'Content-Type': 'application/json' };
    if (data) headers['Content-Length'] = Buffer.byteLength(data);
    if (token) headers['Cookie'] = `ci_token=${token}`;
    const opts = { hostname: url.hostname, port: url.port, path: url.pathname, method, headers };
    const req = http.request(opts, (res) => {
      let d = '';
      res.on('data', c => d += c);
      res.on('end', () => { try { resolve({ status: res.statusCode, data: JSON.parse(d) }); } catch { resolve({ status: res.statusCode, data: d }); } });
    });
    req.on('error', reject);
    if (data) req.write(data);
    req.end();
  });
}

async function loginToken() {
  return new Promise((resolve, reject) => {
    const data = JSON.stringify(INSTRUCTOR);
    const req = http.request({ ...HOST, path: '/api/auth/login', method: 'POST',
      headers: { 'Content-Type': 'application/json', 'Content-Length': Buffer.byteLength(data) }
    }, (res) => {
      let d = '';
      res.on('data', c => d += c);
      res.on('end', () => {
        const cookies = res.headers['set-cookie'] || [];
        const t = cookies.find(c => c.startsWith('ci_token='));
        resolve(t ? t.split(';')[0].replace('ci_token=', '') : null);
      });
    });
    req.write(data); req.end();
  });
}

async function setupTestData() {
  console.log('\nPHASE 1: Setup...');
  const instructorToken = await loginToken();
  if (!instructorToken) throw new Error('Could not get instructor token');
  console.log('  \u2713 Instructor logged in');

  const sectionRes = await apiCall('POST', '/api/sections/', { name: SECTION_TITLE, course_code: 'E2E-TEST', school_year: '2025-2026', semester: 'Sem 2', description: 'E2E test section' }, instructorToken);
  if (!sectionRes || sectionRes.status >= 400) throw new Error(`Section creation failed: ${JSON.stringify(sectionRes?.data)}`);
  const sectionId = sectionRes.data?.id || sectionRes.data?.section?.id;
  console.log(`  \u2713 Section created (id=${sectionId})`);

  for (const p of PERSONAS) {
    const regRes = await apiCall('POST', '/api/auth/register',
      { name: p.name, email: p.email, password: STUDENT_PASSWORD, role: 'student' }, instructorToken);
    if (regRes.status >= 400 && !regRes.data?.code?.includes('EXISTS')) {
      console.log(`  \u26A0 Register ${p.email}: ${regRes.data?.message || regRes.status}`);
    }
  }
  console.log(`  \u2713 ${PERSONAS.length} students registered`);

  const testEmails = PERSONAS.map(p => p.email);
  await apiCall('POST', `/api/sections/${sectionId}/enroll`, { emails: testEmails }, instructorToken);
  console.log(`  \u2713 ${testEmails.length} students enrolled in section ${sectionId}`);

  const exercisePayload = {
    title: EXERCISE_TITLE,
    description: EXERCISE.description,
    concept_name: 'Loops',
    section_id: sectionId,
    starter_code: EXERCISE.starterCode,
    reference_solution: EXERCISE.referenceSolution,
    test_cases: EXERCISE.testCases.map(tc => ({
      input: tc.input, expectedOutput: tc.expectedOutput, isVisible: tc.isVisible,
      validationType: 'exact',
    })),
    time_limit_minutes: 60,
    auto_alert: true,
  };
  const exerciseRes = await apiCall('POST', '/api/exercises/', exercisePayload, instructorToken);
  if (!exerciseRes || exerciseRes.status >= 400) throw new Error(`Exercise creation failed: ${JSON.stringify(exerciseRes?.data)}`);
  const exerciseId = exerciseRes.data?.id || exerciseRes.data?.exercise?.id;
  console.log(`  \u2713 Exercise created (id=${exerciseId})`);

  return { sectionId, exerciseId, instructorToken };
}

module.exports = { setupTestData, loginToken, apiCall };
