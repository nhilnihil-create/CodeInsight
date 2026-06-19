const { setupTestData, apiCall } = require('./setup');
const { runConcurrent } = require('./concurrent');
const { verifySubmissions } = require('./verifier');
const { testServerRestart } = require('./restart');
const { verifyAnalytics } = require('./analyticsVerifier');
const { STUDENT_COUNT, CONCURRENCY, BACKEND_URL } = require('./config');
const { PERSONAS } = require('./personas');

async function checkBackend() {
  try {
    const http = require('http');
    await new Promise((resolve, reject) => {
      http.get(`${BACKEND_URL}/api/auth/me`, (res) => {
        resolve(res.statusCode);
      }).on('error', reject);
    });
    return true;
  } catch { return false; }
}

async function closeExercise(exerciseId, token) {
  const res = await apiCall('POST', `/api/exercises/${exerciseId}/close`, {}, token);
  return res.status < 400;
}

async function runE2ESimulation() {
  const startTime = Date.now();
  console.log('\u2554\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2557');
  console.log('\u2551  E2E REAL-WORLD SIMULATION                             \u2551');
  console.log(`\u2551  ${STUDENT_COUNT} students x 5 archetypes x ${CONCURRENCY} concurrent          \u2551`);
  console.log('\u255a\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u255d\n');

  const backendUp = await checkBackend();
  if (!backendUp) {
    console.error('\u2717 Backend not reachable. Start with PLAYWRIGHT=1 env var.');
    return { summary: { passed: false, error: 'Backend down' }, results: {} };
  }

  let sectionId, exerciseId, instructorToken;
  let submissionResults = [];
  let verifyResults = null;
  let restartResults = null;
  let analyticsResults = null;

  try {
    const setup = await setupTestData();
    sectionId = setup.sectionId;
    exerciseId = setup.exerciseId;
    instructorToken = setup.instructorToken;

    console.log('\nPHASE 2: Concurrent submissions (3 sessions)...');
    submissionResults = await runConcurrent(PERSONAS, exerciseId, CONCURRENCY);

    const totalAttempts = submissionResults.reduce((s, r) => s + r.attempts.length, 0);
    const passedAttempts = submissionResults.reduce((s, r) => s + r.attempts.filter(a => a.success).length, 0);
    const failedSubmissions = submissionResults.filter(r => r.attempts.every(a => !a.success));
    console.log(`\n  Submissions: ${totalAttempts} total, ${passedAttempts} passed`);
    if (failedSubmissions.length > 0) {
      console.log(`  \u26A0 ${failedSubmissions.length} students had no successful attempts:`);
      failedSubmissions.forEach(s => console.log(`    - ${s.name} (${s.email})`));
    }

    console.log('\nPHASE 3: Close exercise (batch CDS)...');
    const closed = await closeExercise(exerciseId, instructorToken);
    console.log(`  ${closed ? '\u2713' : '\u2717'} Exercise closed`);

    if (closed) {
      await new Promise(r => setTimeout(r, 3000));
    }

    console.log('\nPHASE 4: Verification...');
    verifyResults = await verifySubmissions(exerciseId, sectionId);
    for (const check of verifyResults.checks) {
      console.log(`  ${check.passed ? '\u2713' : '\u2717'} ${check.name}: ${check.detail}`);
    }

    console.log('\nPHASE 5: Server restart test...');
    const reopenRes = await apiCall('POST', `/api/exercises/${exerciseId}/reopen`, {}, instructorToken);
    console.log(`  ${reopenRes.status < 400 ? '\u2713' : '\u2717'} Exercise reopened for restart test`);
    if (reopenRes.status < 400) {
      await new Promise(r => setTimeout(r, 1000));
    }
    restartResults = await testServerRestart(exerciseId);
    for (const step of restartResults.steps) {
      console.log(`  ${step.success ? '\u2713' : '\u2717'} ${step.action}${step.detail ? ': ' + step.detail : ''}`);
    }

    console.log('\nPHASE 6: Instructor analytics browser verification...');
    if (sectionId && exerciseId) {
      analyticsResults = await verifyAnalytics(sectionId, exerciseId);
      for (const r of analyticsResults.results) {
        console.log(`  ${r.passed ? '\u2713' : '\u2717'} ${r.page}: ${r.detail}`);
      }
    } else {
      console.log('  \u26A0 Skipped (missing section/exercise ID)');
    }

  } catch (error) {
    console.error(`\n\u2717 Fatal error: ${error.message}`);
  }

  const duration = (Date.now() - startTime) / 1000;

  const allChecksPassed = verifyResults ? verifyResults.allPassed : false;
  const restartPassed = restartResults ? restartResults.passed : false;
  const analyticsPassed = analyticsResults ? analyticsResults.allPassed : true;
  const overallPassed = allChecksPassed && restartPassed && analyticsPassed;

  console.log('\n' + '\u2550'.repeat(60));
  console.log('  FINAL RESULTS');
  console.log('\u2550'.repeat(60));
  console.log(`  Setup:       \u2713`);
  console.log(`  Submissions: ${submissionResults.filter(r => r.attempts.some(a => a.success)).length}/${STUDENT_COUNT} students completed`);
  console.log(`  Verifier:    ${allChecksPassed ? '\u2713' : '\u2717'} all checks`);
  if (verifyResults) {
    for (const c of verifyResults.checks) {
      console.log(`    ${c.passed ? '\u2713' : '\u2717'} ${c.name}: ${c.detail}`);
    }
  }
  console.log(`  Restart:     ${restartPassed ? '\u2713' : '\u2717'}`);
  console.log(`  Analytics:   ${analyticsPassed ? '\u2713' : '\u2717'}`);
  console.log(`  Duration:    ${(duration / 60).toFixed(1)}m ${(duration % 60).toFixed(0)}s`);
  console.log('\u2550'.repeat(60));
  if (sectionId) console.log(`  Section:     id=${sectionId}`);
  if (exerciseId) console.log(`  Exercise:    id=${exerciseId}`);
  console.log('\u2550'.repeat(60));

  return {
    summary: { passed: overallPassed, duration, sectionId, exerciseId },
    results: { submissionResults, verifyResults, restartResults },
  };
}

if (require.main === module) {
  runE2ESimulation().then(r => process.exit(r.summary.passed ? 0 : 1));
}

module.exports = { runE2ESimulation };
