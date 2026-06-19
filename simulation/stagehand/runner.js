/**
 * simulation/stagehand/runner.js
 *
 * Lightweight Stagehand test runner.
 * Runs all workflows sequentially, generates JSON report.
 * Includes comprehensive engine simulation.
 */

const fs = require('fs');
const path = require('path');
const { testInstructorLogin, testStudentLogin, testInvalidLogin } = require('./workflows/login');
const { testInstructorNavigation, testStudentNavigation } = require('./workflows/dashboard');
const { testExerciseSubmission } = require('./workflows/exercises');
const { testInstructorDashboard, testHeatmapView, testCommandCenter, testStudentMyScores } = require('./workflows/cds-engine');
const { testIntegrityQueue, testIntegrityFlagDetail, testBulkDismiss, testStudentIntegrityView } = require('./workflows/integrity');
const { testReportsPage, testReportTabs, testLongitudinalProgress, testConceptAnalytics, testCustomHeatmap } = require('./workflows/analytics');
const { testExerciseList, testExerciseWizard, testExerciseDatabank, testCloseExercise, testEditExercise } = require('./workflows/exercise-workspace');
const { testStudentDashboard, testStudentProgressPage, testStudentTodayPlan, testStudentCodeSubmission, testStudentProfile, testStudentRecommendations } = require('./workflows/student-progress');
const { testInterventionQueue, testAlertDetailDrawer, testReviewAlert, testDashboardAtRiskSection, testMicroConceptAlerts } = require('./workflows/alerts');
const { runComprehensiveSimulation } = require('./workflows/comprehensive');

const RESULTS_DIR = path.join(__dirname, 'results');

async function runAllTests() {
  const startTime = Date.now();
  const results = {
    timestamp: new Date().toISOString(),
    duration: 0,
    summary: { total: 0, passed: 0, failed: 0 },
    tests: [],
    comprehensiveSimulation: null,
  };

  // ── Phase 1: Basic Workflow Tests ────────────────────────────────────────
  console.log('\n═══════════════════════════════════════════════════════════');
  console.log('  PHASE 1: BASIC WORKFLOW TESTS');
  console.log('═══════════════════════════════════════════════════════════\n');

  const basicTests = [
    { name: 'Instructor Login', fn: testInstructorLogin },
    { name: 'Student Login', fn: testStudentLogin },
    { name: 'Invalid Login', fn: testInvalidLogin },
    { name: 'Instructor Navigation', fn: testInstructorNavigation },
    { name: 'Student Navigation', fn: testStudentNavigation },
    { name: 'Exercise Submission', fn: testExerciseSubmission },
  ];

  for (const test of basicTests) {
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

  // ── Phase 2: CDS Engine Tests ───────────────────────────────────────────
  console.log('\n═══════════════════════════════════════════════════════════');
  console.log('  PHASE 2: CDS ENGINE TESTS');
  console.log('═══════════════════════════════════════════════════════════\n');

  const cdsTests = [
    { name: 'Instructor Dashboard', fn: testInstructorDashboard },
    { name: 'Heatmap View', fn: testHeatmapView },
    { name: 'Command Center', fn: testCommandCenter },
    { name: 'Student My Scores', fn: testStudentMyScores },
  ];

  for (const test of cdsTests) {
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

  // ── Phase 3: Integrity Flag Engine Tests ────────────────────────────────
  console.log('\n═══════════════════════════════════════════════════════════');
  console.log('  PHASE 3: INTEGRITY FLAG ENGINE TESTS');
  console.log('═══════════════════════════════════════════════════════════\n');

  const integrityTests = [
    { name: 'Integrity Queue', fn: testIntegrityQueue },
    { name: 'Integrity Flag Detail', fn: testIntegrityFlagDetail },
    { name: 'Bulk Dismiss', fn: testBulkDismiss },
    { name: 'Student Integrity View', fn: testStudentIntegrityView },
  ];

  for (const test of integrityTests) {
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

  // ── Phase 4: Analytics Tests ────────────────────────────────────────────
  console.log('\n═══════════════════════════════════════════════════════════');
  console.log('  PHASE 4: ANALYTICS TESTS');
  console.log('═══════════════════════════════════════════════════════════\n');

  const analyticsTests = [
    { name: 'Reports Page', fn: testReportsPage },
    { name: 'Report Tabs', fn: testReportTabs },
    { name: 'Longitudinal Progress', fn: testLongitudinalProgress },
    { name: 'Concept Analytics', fn: testConceptAnalytics },
    { name: 'Custom Heatmap', fn: testCustomHeatmap },
  ];

  for (const test of analyticsTests) {
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

  // ── Phase 5: Exercise Workspace Tests ───────────────────────────────────
  console.log('\n═══════════════════════════════════════════════════════════');
  console.log('  PHASE 5: EXERCISE WORKSPACE TESTS');
  console.log('═══════════════════════════════════════════════════════════\n');

  const exerciseTests = [
    { name: 'Exercise List', fn: testExerciseList },
    { name: 'Exercise Wizard', fn: testExerciseWizard },
    { name: 'Exercise Databank', fn: testExerciseDatabank },
    { name: 'Close Exercise', fn: testCloseExercise },
    { name: 'Edit Exercise', fn: testEditExercise },
  ];

  for (const test of exerciseTests) {
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

  // ── Phase 6: Student Progress Tests ─────────────────────────────────────
  console.log('\n═══════════════════════════════════════════════════════════');
  console.log('  PHASE 6: STUDENT PROGRESS TESTS');
  console.log('═══════════════════════════════════════════════════════════\n');

  const studentTests = [
    { name: 'Student Dashboard', fn: testStudentDashboard },
    { name: 'Student Progress Page', fn: testStudentProgressPage },
    { name: 'Student Today Plan', fn: testStudentTodayPlan },
    { name: 'Student Code Submission', fn: testStudentCodeSubmission },
    { name: 'Student Profile', fn: testStudentProfile },
    { name: 'Student Recommendations', fn: testStudentRecommendations },
  ];

  for (const test of studentTests) {
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

  // ── Phase 7: Alerts/Intervention Tests ──────────────────────────────────
  console.log('\n═══════════════════════════════════════════════════════════');
  console.log('  PHASE 7: ALERTS/INTERVENTION TESTS');
  console.log('═══════════════════════════════════════════════════════════\n');

  const alertTests = [
    { name: 'Intervention Queue', fn: testInterventionQueue },
    { name: 'Alert Detail Drawer', fn: testAlertDetailDrawer },
    { name: 'Review Alert', fn: testReviewAlert },
    { name: 'Dashboard At-Risk Section', fn: testDashboardAtRiskSection },
    { name: 'Micro-Concept Alerts', fn: testMicroConceptAlerts },
  ];

  for (const test of alertTests) {
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

  // ── Phase 8: Comprehensive Engine Simulation ────────────────────────────
  console.log('\n═══════════════════════════════════════════════════════════');
  console.log('  PHASE 8: COMPREHENSIVE ENGINE SIMULATION');
  console.log('  (All 10 personas, all core engines)');
  console.log('═══════════════════════════════════════════════════════════\n');

  results.summary.total++;
  console.log('▶ Running: Comprehensive Simulation (10 personas)...');

  try {
    const simResults = await runComprehensiveSimulation();
    results.comprehensiveSimulation = simResults;

    const simPassed = simResults.summary.browserPassed === simResults.summary.browserTotal && simResults.summary.personasTested >= 10; // At least 70% of personas
    results.tests.push({
      name: 'Comprehensive Engine Simulation',
      passed: simPassed,
      details: simResults.summary,
    });

    if (simPassed) {
      results.summary.passed++;
      console.log(`  ✓ PASSED (${simResults.summary.personasTested} personas, ${simResults.summary.browserPassed}/${simResults.summary.browserTotal} browser)`);
    } else {
      results.summary.failed++;
      console.log(`  ✗ FAILED (${simResults.summary.personasTested} personas, ${simResults.summary.browserPassed}/${simResults.summary.browserTotal} browser)`);
    }
  } catch (error) {
    results.summary.failed++;
    results.tests.push({ name: 'Comprehensive Engine Simulation', passed: false, error: error.message });
    console.log(`  ✗ ERROR: ${error.message}`);
  }

  results.duration = Date.now() - startTime;

  // Save report
  if (!fs.existsSync(RESULTS_DIR)) {
    fs.mkdirSync(RESULTS_DIR, { recursive: true });
  }
  const reportPath = path.join(RESULTS_DIR, `report-${Date.now()}.json`);
  fs.writeFileSync(reportPath, JSON.stringify(results, null, 2));

  console.log(`\n${'='.repeat(60)}`);
  console.log(`FINAL RESULTS: ${results.summary.passed}/${results.summary.total} passed`);
  console.log(`Duration: ${(results.duration / 1000).toFixed(1)}s`);
  console.log(`Report: ${reportPath}`);

  if (results.comprehensiveSimulation) {
    const cs = results.comprehensiveSimulation;
    console.log(`\nComprehensive Simulation:`);
    console.log(`  Browser: ${cs.summary.browserPassed}/${cs.summary.browserTotal} passed`);
    console.log(`  Personas: ${cs.summary.personasTested}`);
    console.log(`  CDS Distribution: Low=${cs.summary.cdsDistribution.Low} Moderate=${cs.summary.cdsDistribution.Moderate} High=${cs.summary.cdsDistribution.High}`);
    console.log(`  Engine Coverage:`);
    const engines = Object.entries(cs.summary.enginesCovered);
    for (const [name, covered] of engines) {
      console.log(`    ${covered ? '✓' : '✗'} ${name}`);
    }
  }

  console.log(`${'='.repeat(60)}`);

  return results;
}

module.exports = { runAllTests };

if (require.main === module) {
  runAllTests().then(r => process.exit(r.summary.failed > 0 ? 1 : 0));
}
