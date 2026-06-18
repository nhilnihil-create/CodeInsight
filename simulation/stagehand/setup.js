/**
 * simulation/stagehand/setup.js
 *
 * Setup script: creates a dedicated test exercise and enrolls test students.
 * Must be run BEFORE the comprehensive simulation.
 */

const http = require('http');
const { BASE_URL } = require('./config');

// Define the exercise that matches our personas
const EXERCISE_DEF = {
  title: 'Comprehensive Simulation Exercise',
  description: 'Automated test exercise for comprehensive engine simulation',
  concept_id: 2, // Loops concept
  concept_name: 'Loops',
  section_id: 67, // Existing test section
  starter_code: `#include <iostream>
using namespace std;
int main() {
    // TODO: Implement your solution here
    
    return 0;
}`,
  test_cases: [
    { input: '', expected: '55', hidden: false, isVisible: true },
    { input: '', expected: '15', hidden: true, isVisible: false },
    { input: '', expected: '5050', hidden: true, isVisible: false },
  ],
  time_limit_minutes: 30,
  is_draft: false,
};

/**
 * Login and get JWT cookie.
 */
function login() {
  return new Promise((resolve, reject) => {
    const data = JSON.stringify({ email: 'instructor@psu.edu', password: 'password123' });
    const req = http.request({
      hostname: 'localhost', port: 5000, path: '/api/auth/login',
      method: 'POST',
      headers: { 'Content-Type': 'application/json', 'Content-Length': data.length },
    }, (res) => {
      let body = '';
      res.on('data', c => body += c);
      res.on('end', () => {
        const cookies = res.headers['set-cookie'] || [];
        const ciToken = cookies.find(c => c.startsWith('ci_token='));
        if (ciToken) resolve(ciToken.split(';')[0].replace('ci_token=', ''));
        else reject(new Error('No ci_token cookie in response: ' + body));
      });
    });
    req.on('error', reject);
    req.write(data);
    req.end();
  });
}

/**
 * Make an API request with cookie auth.
 */
function apiRequest(method, path, body = null, token = '') {
  return new Promise((resolve, reject) => {
    const opts = {
      hostname: 'localhost', port: 5000, path, method,
      headers: { 'Cookie': `ci_token=${token}` },
    };
    let bodyStr = null;
    if (body) {
      bodyStr = JSON.stringify(body);
      opts.headers['Content-Type'] = 'application/json';
      opts.headers['Content-Length'] = Buffer.byteLength(bodyStr);
    }
    const req = http.request(opts, (res) => {
      let data = '';
      res.on('data', c => data += c);
      res.on('end', () => {
        try { resolve(JSON.parse(data)); }
        catch { resolve(data); }
      });
    });
    req.on('error', reject);
    if (bodyStr) req.write(bodyStr);
    req.end();
  });
}

/**
 * Create the test exercise and enroll test students.
 */
async function setupSimulation() {
  console.log('▶ Setting up simulation environment...');

  // Login as instructor
  const token = await login();
  console.log('  ✓ Logged in as instructor (token obtained)');

  // Enroll test students (chloe, derek, emma, fiona, george, hannah, ian)
  const testStudents = [
    { email: 'chloe@student.psu.edu', name: 'Chloe', id: null },
    { email: 'derek@student.psu.edu', name: 'Derek', id: null },
    { email: 'emma@student.psu.edu', name: 'Emma', id: null },
    { email: 'fiona@student.psu.edu', name: 'Fiona', id: null },
    { email: 'george@student.psu.edu', name: 'George', id: null },
    { email: 'hannah@student.psu.edu', name: 'Hannah', id: null },
    { email: 'ian@student.psu.edu', name: 'Ian', id: null },
  ];

  for (const student of testStudents) {
    try {
      // Check if user exists
      let users = await apiRequest('GET', `/api/users?email=${student.email}`, null, token);
      // Try to find or create user
      const userRes = await apiRequest('POST', '/api/auth/register', {
        name: student.name, email: student.email, password: 'password123', role: 'student',
      }, token).catch(() => null);
      if (userRes && userRes.user) {
        student.id = userRes.user.id;
      }
    } catch (e) {
      // User might already exist
    }

    // Enroll in section 67
    if (student.id) {
      await apiRequest('POST', '/api/enrollments', {
        student_id: student.id, section_id: 67,
      }, token).catch(() => {});
    }
  }
  console.log('  ✓ Test students enrolled');

  // Create the exercise
  let exercise;
  try {
    exercise = await apiRequest('POST', '/api/exercises', EXERCISE_DEF, token);
    console.log(`  ✓ Created exercise: "${exercise.title}" (ID: ${exercise.id})`);

    // Update exercise definition with created ID
    EXERCISE_DEF.id = exercise.id;
  } catch (e) {
    console.log('  ⚠ Could not create exercise, using existing:', e.message);
    // Try to find an existing exercise
    const exercises = await apiRequest('GET', '/api/exercises', null, token);
    if (exercises && exercises.length > 0) {
      exercise = exercises[0];
      EXERCISE_DEF.id = exercise.id;
      console.log(`  ✓ Using existing exercise: "${exercise.title}" (ID: ${exercise.id})`);
    }
  }

  return { exerciseId: exercise?.id, token };
}

module.exports = { setupSimulation, EXERCISE_DEF };
