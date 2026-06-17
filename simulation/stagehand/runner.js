/**
 * simulation/stagehand/runner.js
 *
 * Lightweight Stagehand test runner.
 * Runs all workflows sequentially, generates JSON report.
 */

const fs = require('fs');
const path = require('path');
const { testInstructorLogin, testStudentLogin, testInvalidLogin } = require('./workflows/login');
const { testInstructorNavigation, testStudentNavigation } = require('./workflows/dashboard');
const { testExerciseSubmission } = require('./workflows/exercises');

const RESULTS_DIR = path.join(__dirname, 'results');

async function runAllTests() {
  const startTime = Date.now();
  const results = {
    timestamp: new Date().toISOString(),
    duration: 0,
    summary: { total: 0, passed: 0, failed: 0 },
    tests: [],
  };

  const tests = [
    { name: 'Instructor Login', fn: testInstructorLogin },
    { name: 'Student Login', fn: testStudentLogin },
    { name: 'Invalid Login', fn: testInvalidLogin },
    { name: 'Instructor Navigation', fn: testInstructorNavigation },
    { name: 'Student Navigation', fn: testStudentNavigation },
    { name: 'Exercise Submission', fn: testExerciseSubmission },
  ];

  for (const test of tests) {
    results.summary.total++;
    console.log(`▶ Running: ${test.name}...`);

    try {
      const testResult = await test.fn();
      results.tests.push({
        name: test.name,
        passed: testResult.passed,
        details: testResult.steps || testResult.results || [],
      });

      if (testResult.passed) {
        results.summary.passed++;
        console.log(`  ✓ PASSED`);
      } else {
        results.summary.failed++;
        console.log(`  ✗ FAILED`);
      }
    } catch (error) {
      results.summary.failed++;
      results.tests.push({ name: test.name, passed: false, error: error.message });
      console.log(`  ✗ ERROR: ${error.message}`);
    }
  }

  results.duration = Date.now() - startTime;

  // Save report
  if (!fs.existsSync(RESULTS_DIR)) {
    fs.mkdirSync(RESULTS_DIR, { recursive: true });
  }
  const reportPath = path.join(RESULTS_DIR, `report-${Date.now()}.json`);
  fs.writeFileSync(reportPath, JSON.stringify(results, null, 2));

  console.log(`\n${'='.repeat(50)}`);
  console.log(`RESULTS: ${results.summary.passed}/${results.summary.total} passed`);
  console.log(`Duration: ${(results.duration / 1000).toFixed(1)}s`);
  console.log(`Report: ${reportPath}`);
  console.log(`${'='.repeat(50)}`);

  return results;
}

module.exports = { runAllTests };

if (require.main === module) {
  runAllTests().then(r => process.exit(r.summary.failed > 0 ? 1 : 0));
}
