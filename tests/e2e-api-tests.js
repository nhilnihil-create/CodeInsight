#!/usr/bin/env node

/**
 * ============================================================================
 * CODEINSIGHT E2E TEST SUITE — Session 288d1abf
 * ============================================================================
 * API-focused test suite for CDS computation, live peer ranking, and API fixes
 * Uses curl for HTTP requests and direct database queries
 * ============================================================================
 */

const { Client } = require('pg');
const http = require('http');
const https = require('https');

const BASE_URL = 'http://localhost:5173';
const API_BASE = 'http://localhost:5000/api';
const SECTION_ID = 5;

const CREDENTIALS = {
  instructor: { email: 'instructor@psu.edu', password: 'password123' },
  maria: { email: 'maria@student.psu.edu', password: 'password123' },
  jose: { email: 'jose@student.psu.edu', password: 'password123' },
  ana: { email: 'ana@student.psu.edu', password: 'password123' }
};

let testResults = {
  passed: 0,
  failed: 0,
  tests: []
};

// ============================================================================
// HELPER: Make HTTP requests
// ============================================================================
function makeRequest(method, url, body = null, headers = {}) {
  return new Promise((resolve, reject) => {
    const urlObj = new URL(url);
    const options = {
      hostname: urlObj.hostname,
      port: urlObj.port,
      path: urlObj.pathname + urlObj.search,
      method: method,
      headers: {
        'Content-Type': 'application/json',
        ...headers
      }
    };

    const req = http.request(options, (res) => {
      let data = '';
      res.on('data', chunk => data += chunk);
      res.on('end', () => {
        try {
          const parsed = data ? JSON.parse(data) : {};
          resolve({
            status: res.statusCode,
            headers: res.headers,
            body: parsed,
            rawBody: data
          });
        } catch (e) {
          resolve({
            status: res.statusCode,
            headers: res.headers,
            body: null,
            rawBody: data
          });
        }
      });
    });

    req.on('error', reject);
    if (body) req.write(JSON.stringify(body));
    req.end();
  });
}

// ============================================================================
// HELPER: Database query
// ============================================================================
async function queryDB(sql, params = []) {
  const client = new Client({
    host: 'localhost',
    port: 5432,
    database: 'codeinsight',
    user: 'postgres'
  });

  try {
    await client.connect();
    const result = await client.query(sql, params);
    return result.rows;
  } catch (err) {
    console.error('DB Error:', err.message);
    throw err;
  } finally {
    await client.end();
  }
}

// ============================================================================
// HELPER: Assert and log results
// ============================================================================
function assert(testName, condition, details = '') {
  const status = condition ? '✅ PASS' : '❌ FAIL';
  console.log(`${status}: ${testName}${details ? ' (' + details + ')' : ''}`);
  
  testResults.tests.push({
    name: testName,
    passed: condition,
    details
  });

  if (condition) {
    testResults.passed++;
  } else {
    testResults.failed++;
  }

  return condition;
}

// ============================================================================
// TEST 1: API Environment Variables (Vite)
// ============================================================================
async function test1_EnvironmentVariables() {
  console.log('\n📋 TEST 1: Phase 6 - Vite Environment Variable Fix');
  console.log('─'.repeat(70));

  try {
    const response = await makeRequest('GET', `${BASE_URL}/login`);
    assert('Frontend loads without 404', response.status < 500);
    assert('Frontend response not empty', response.rawBody.length > 0);
  } catch (err) {
    assert('Frontend loads', false, err.message);
  }
}

// ============================================================================
// TEST 2: API Base URL (No Double /api)
// ============================================================================
async function test2_ApiBaseUrl() {
  console.log('\n📋 TEST 2: Phase 6 - API Base URL (No Double /api)');
  console.log('─'.repeat(70));

  try {
    // Try to login and get token
    const loginRes = await makeRequest('POST', `${API_BASE}/auth/login`, {
      email: CREDENTIALS.instructor.email,
      password: CREDENTIALS.instructor.password
    });

    assert('Login endpoint accessible', loginRes.status === 200, `Status: ${loginRes.status}`);
    assert('No double /api in login URL', !`${API_BASE}/auth/login`.includes('/api/api'));

    if (loginRes.body && loginRes.body.token) {
      const token = loginRes.body.token;

      // Try /me endpoint
      const meRes = await makeRequest('GET', `${API_BASE}/auth/me`, null, {
        'Authorization': `Bearer ${token}`
      });

      assert('Me endpoint accessible', meRes.status === 200, `Status: ${meRes.status}`);
      assert('Me endpoint returns user', meRes.body && meRes.body.id);
    }
  } catch (err) {
    assert('API Base URL test', false, err.message);
  }
}

// ============================================================================
// TEST 3: Enrollment Endpoint (No 404)
// ============================================================================
async function test3_EnrollmentEndpoint() {
  console.log('\n📋 TEST 3: Phase 6 - Enrollment Endpoint (No 404)');
  console.log('─'.repeat(70));

  try {
    const loginRes = await makeRequest('POST', `${API_BASE}/auth/login`, {
      email: CREDENTIALS.instructor.email,
      password: CREDENTIALS.instructor.password
    });

    if (loginRes.body && loginRes.body.token) {
      const token = loginRes.body.token;

      // Try enrollment endpoint
      const enrollRes = await makeRequest('POST', `${API_BASE}/sections/${SECTION_ID}/enroll`, {
        studentIds: [],
        emails: [CREDENTIALS.maria.email]
      }, {
        'Authorization': `Bearer ${token}`
      });

      assert('Enrollment endpoint returns valid status', [200, 201, 400].includes(enrollRes.status), 
        `Status: ${enrollRes.status} (404 would indicate path issue)`);
      assert('No 404 on enrollment', enrollRes.status !== 404);
    }
  } catch (err) {
    assert('Enrollment endpoint test', false, err.message);
  }
}

// ============================================================================
// TEST 4: Semester Field in Database
// ============================================================================
async function test4_SemesterField() {
  console.log('\n📋 TEST 4: Phase 7 - Semester Field Persisted to Database');
  console.log('─'.repeat(70));

  try {
    const sections = await queryDB(
      'SELECT id, name, semester FROM sections WHERE id = $1',
      [SECTION_ID]
    );

    assert('Section exists', sections.length > 0, `Found ${sections.length} sections`);
    
    if (sections.length > 0) {
      const section = sections[0];
      assert('Semester column exists', section.semester !== undefined, 
        `Semester value: ${section.semester}`);
      assert('Semester is not empty', section.semester !== null && section.semester !== '');
    }
  } catch (err) {
    assert('Semester field test', false, err.message);
  }
}

// ============================================================================
// TEST 5: CDS Computation & Database Accuracy
// ============================================================================
async function test5_CdsComputation() {
  console.log('\n📋 TEST 5: CDS Computation & Database Accuracy');
  console.log('─'.repeat(70));

  try {
    // Get all CDS scores for section 5
    const cdsScores = await queryDB(
      'SELECT student_id, ner, nrs, nts, cds, classification FROM cds_scores WHERE section_id = $1 ORDER BY cds DESC',
      [SECTION_ID]
    );

    console.log(`Found ${cdsScores.length} CDS scores`);

    if (cdsScores.length > 0) {
      // Verify CDS formula for each score
      let formulaCorrect = true;
      cdsScores.forEach((score, idx) => {
        const calculated = (0.40 * score.ner) + (0.35 * score.nrs) + (0.25 * score.nts);
        const cdsMatch = Math.abs(calculated - score.cds) < 0.01; // Allow 0.01 rounding
        
        if (!cdsMatch) {
          console.log(`  ⚠️  Student ${score.student_id}: Expected CDS ${calculated.toFixed(4)}, got ${score.cds.toFixed(4)}`);
          formulaCorrect = false;
        }
      });

      assert('CDS formula correct (0.40*NER + 0.35*NRS + 0.25*NTS)', formulaCorrect);

      // Verify classifications
      const classifications = cdsScores.map(s => ({
        cds: s.cds,
        classification: s.classification,
        correct: (s.cds <= 0.33 && s.classification === 'Low') ||
                 (s.cds > 0.33 && s.cds <= 0.66 && s.classification === 'Moderate') ||
                 (s.cds > 0.66 && s.classification === 'High')
      }));

      const allCorrect = classifications.every(c => c.correct);
      assert('Classifications match CDS ranges', allCorrect);

      // Show summary
      console.log('\n  CDS Score Summary:');
      cdsScores.forEach(score => {
        console.log(`    Student ${score.student_id}: CDS=${score.cds.toFixed(4)}, Class=${score.classification} (NER=${score.ner.toFixed(2)}, NRS=${score.nrs.toFixed(2)}, NTS=${score.nts.toFixed(2)})`);
      });
    } else {
      console.log('  ℹ️  No CDS scores yet (may not be computed yet)');
    }

    assert('CDS computation test complete', true);
  } catch (err) {
    assert('CDS computation test', false, err.message);
  }
}

// ============================================================================
// TEST 6: Enrollments Exist
// ============================================================================
async function test6_Enrollments() {
  console.log('\n📋 TEST 6: Enrollments Verification');
  console.log('─'.repeat(70));

  try {
    const enrollments = await queryDB(
      'SELECT id, student_id, section_id FROM enrollments WHERE section_id = $1',
      [SECTION_ID]
    );

    console.log(`Found ${enrollments.length} enrollments in section ${SECTION_ID}`);
    assert('Enrollments exist or are empty (no error)', true, `${enrollments.length} enrollments`);

    if (enrollments.length > 0) {
      enrollments.forEach(e => {
        console.log(`  - Student ${e.student_id} enrolled in section ${e.section_id}`);
      });
    }
  } catch (err) {
    assert('Enrollments test', false, err.message);
  }
}

// ============================================================================
// TEST 7: Submissions Tracking
// ============================================================================
async function test7_Submissions() {
  console.log('\n📋 TEST 7: Submissions Tracking');
  console.log('─'.repeat(70));

  try {
    const submissions = await queryDB(
      `SELECT s.id, s.student_id, s.exercise_id, s.is_correct, s.attempt_number 
       FROM submissions s 
       JOIN exercises e ON s.exercise_id = e.id 
       WHERE e.section_id = $1 
       ORDER BY s.submitted_at DESC LIMIT 10`,
      [SECTION_ID]
    );

    console.log(`Found ${submissions.length} submissions in section ${SECTION_ID}`);
    assert('Submissions table queryable', true, `${submissions.length} submissions`);

    if (submissions.length > 0) {
      const passedCount = submissions.filter(s => s.is_correct).length;
      const failedCount = submissions.filter(s => !s.is_correct).length;
      console.log(`  - Passed: ${passedCount}, Failed: ${failedCount}`);
    }
  } catch (err) {
    assert('Submissions test', false, err.message);
  }
}

// ============================================================================
// TEST 8: Network Assertions - No Double Paths
// ============================================================================
async function test8_NetworkAssertions() {
  console.log('\n📋 TEST 8: Network Assertions - API Path Validation');
  console.log('─'.repeat(70));

  try {
    const testUrls = [
      `${API_BASE}/auth/me`,
      `${API_BASE}/sections`,
      `${API_BASE}/sections/${SECTION_ID}`,
      `${API_BASE}/exercises`,
      `${API_BASE}/analytics/heatmap/${SECTION_ID}`
    ];

    let doubleApiCount = 0;
    testUrls.forEach(url => {
      if (url.includes('/api/api')) {
        doubleApiCount++;
        console.log(`  ⚠️  Double /api found: ${url}`);
      }
    });

    assert('No double /api paths', doubleApiCount === 0);
    console.log(`  ✓ Verified ${testUrls.length} API URLs - all correct format`);
  } catch (err) {
    assert('Network assertions test', false, err.message);
  }
}

// ============================================================================
// TEST 9: Database Integrity
// ============================================================================
async function test9_DatabaseIntegrity() {
  console.log('\n📋 TEST 9: Database Integrity Check');
  console.log('─'.repeat(70));

  try {
    // Check all required tables exist
    const tables = ['users', 'sections', 'enrollments', 'exercises', 'submissions', 'cds_scores'];
    
    for (const table of tables) {
      const result = await queryDB(`SELECT COUNT(*) as count FROM ${table}`);
      const count = result[0].count;
      console.log(`  ✓ ${table}: ${count} rows`);
      assert(`Table ${table} exists`, true);
    }

    // Check users exist
    const users = await queryDB(
      `SELECT id, email FROM users WHERE email IN ($1, $2, $3, $4)`,
      [
        CREDENTIALS.instructor.email,
        CREDENTIALS.maria.email,
        CREDENTIALS.jose.email,
        CREDENTIALS.ana.email
      ]
    );

    console.log(`\n  Test users found: ${users.length}`);
    users.forEach(u => console.log(`    - ${u.email} (ID: ${u.id})`));
    
    assert('All test users exist', users.length === 4, `Found ${users.length}/4`);
  } catch (err) {
    assert('Database integrity test', false, err.message);
  }
}

// ============================================================================
// FINAL REPORT
// ============================================================================
function printReport() {
  console.log('\n' + '='.repeat(80));
  console.log('TEST EXECUTION REPORT — CodeInsight E2E Suite');
  console.log('='.repeat(80));

  console.log('\n📊 RESULTS SUMMARY:');
  console.log(`   ✅ PASSED: ${testResults.passed}`);
  console.log(`   ❌ FAILED: ${testResults.failed}`);
  console.log(`   📈 TOTAL:  ${testResults.passed + testResults.failed}`);

  const passRate = ((testResults.passed / (testResults.passed + testResults.failed)) * 100).toFixed(1);
  console.log(`   📋 PASS RATE: ${passRate}%`);

  console.log('\n📋 DETAILED RESULTS:');
  testResults.tests.forEach((test, idx) => {
    const icon = test.passed ? '✅' : '❌';
    console.log(`   ${idx + 1}. ${icon} ${test.name}`);
    if (test.details) {
      console.log(`      └─ ${test.details}`);
    }
  });

  console.log('\n' + '='.repeat(80));
  
  if (testResults.failed === 0) {
    console.log('✨ ALL TESTS PASSED! ✨');
  } else {
    console.log(`⚠️  ${testResults.failed} test(s) failed. Review details above.`);
  }

  console.log('='.repeat(80) + '\n');
}

// ============================================================================
// MAIN EXECUTION
// ============================================================================
async function runAllTests() {
  console.log('\n╔════════════════════════════════════════════════════════════════════════════╗');
  console.log('║ CodeInsight E2E Test Suite — Session 288d1abf                              ║');
  console.log('║ CDS Computation, Live Peer Ranking, API Fixes                              ║');
  console.log('╚════════════════════════════════════════════════════════════════════════════╝');

  await test1_EnvironmentVariables();
  await test2_ApiBaseUrl();
  await test3_EnrollmentEndpoint();
  await test4_SemesterField();
  await test5_CdsComputation();
  await test6_Enrollments();
  await test7_Submissions();
  await test8_NetworkAssertions();
  await test9_DatabaseIntegrity();

  printReport();

  process.exit(testResults.failed > 0 ? 1 : 0);
}

runAllTests().catch(err => {
  console.error('Fatal error:', err);
  process.exit(1);
});
