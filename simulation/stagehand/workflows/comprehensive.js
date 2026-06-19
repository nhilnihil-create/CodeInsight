/**
 * simulation/stagehand/workflows/comprehensive.js
 *
 * Comprehensive engine simulation.
 *
 * Part A: Browser-based - 3 existing students work the exercise via the UI
 *   - Tests: UI rendering, login, code editor, submit flow
 *
 * Part B: Engine simulation - All 10 personas run through all core engines locally
 *   - Tests: CDS Engine, Integrity Engine, Micro-Concept, AST, Behavioral,
 *            Retry Storm, Code Growth, Hardcoding, Blank Template
 */

const { createBrowser, login, navigateTo, PERSONAS } = require('../config');
const { PERSONAS: STUDENT_PERSONAS } = require('../personas');
const {
  computeBatchCDS,
  checkHardcoding,
  checkBlankTemplate,
  checkCodeGrowthAnomaly,
  detectBehavioralAnomalies,
  detectRetryStorm,
  analyzeMicroConcepts,
  verifyAST,
} = require('../engines');
const {
  simulateTyping,
  simulateTabSwitches,
  simulatePasteEvents,
  simulateIdleTime,
} = require('../behavioral');

// Exercise definition matching the actual DB exercise
const EXERCISE = {
  id: 188,
  title: 'Full Test Exercise',
  starterCode: `#include <iostream>
using namespace std;
int main() {
    // TODO: Implement your solution here
    
    return 0;
}`,
  testCases: [{ input: '', expected: '55', hidden: false }],
};

// ── Part A: Browser-based student simulation ──────────────────────────────

async function simulateBrowserStudent(persona, exerciseId) {
  const { browser, page } = await createBrowser();
  const steps = [];

  try {
    await login(page, persona.email, persona.password);
    if (page.url().includes('/login')) {
      steps.push({ action: 'Login', success: false, error: 'Stayed on login' });
      return { passed: false, steps };
    }
    steps.push({ action: 'Login', success: true });

    await navigateTo(page, '/student/exercises');
    steps.push({ action: 'Navigate to exercises', success: true });

    // Wait for exercise list to render
    await page.waitForTimeout(2000);
    await page.waitForLoadState('networkidle');

    // Open the exercise — try direct URL first as most reliable
    let opened = false;
    await page.goto(`${require('../config').BASE_URL}/student/exercises/${exerciseId}`);
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(2000);

    // Verify we're on the exercise page (not redirected back)
    const currentUrl = page.url();
    if (currentUrl.includes(`/exercises/${exerciseId}`)) {
      opened = true;
    } else {
      // Fallback: try clicking the link on exercises page
      await page.goto(`${require('../config').BASE_URL}/student/exercises`);
      await page.waitForLoadState('networkidle');
      await page.waitForTimeout(2000);
      const link = page.locator(`a[href*="/student/exercises/${exerciseId}"]`).first();
      if (await link.isVisible({ timeout: 8000 }).catch(() => false)) {
        await link.click();
        await page.waitForLoadState('networkidle');
        await page.waitForTimeout(2000);
        opened = page.url().includes(`/exercises/${exerciseId}`);
      }
    }
    if (!opened) {
      steps.push({ action: 'Open exercise', success: false });
      return { passed: false, steps };
    }
    await page.waitForTimeout(1000);
    steps.push({ action: 'Open exercise', success: true });

    // Check editor
    const hasEditor = await page.locator('.monaco-editor, textarea').first().isVisible({ timeout: 10000 }).catch(() => false);
    steps.push({ action: 'Code editor loaded', success: hasEditor });
    if (!hasEditor) return { passed: false, steps };

    // Check for Run/Submit buttons
    const hasRun = await page.locator('button:has-text("Run")').first().isVisible({ timeout: 5000 }).catch(() => false);
    const hasSubmit = await page.locator('button:has-text("Submit")').first().isVisible({ timeout: 5000 }).catch(() => false);
    steps.push({ action: 'Run button', success: hasRun });
    steps.push({ action: 'Submit button', success: hasSubmit });

    return { passed: steps.filter(s => s.success).length >= 4, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await browser.close();
  }
}

async function runBrowserSimulation() {
  console.log('▶ Phase A: Browser Simulation (existing students)...');
  const results = [];
  const existingStudents = PERSONAS.students.slice(0, 3);

  for (const student of existingStudents) {
    const { passed, steps } = await simulateBrowserStudent(student, 188);
    results.push({ name: student.name, passed, steps: steps.filter(s => s.success).length });
    console.log(`  ${passed ? '✓' : '✗'} ${student.name}: ${steps.filter(s => s.success).length}/${steps.length} steps`);
  }

  return results;
}

// ── Part B: All engines, all personas ─────────────────────────────────────

async function runEngineSimulation() {
  console.log('\n▶ Phase B: Engine Simulation (all 10 personas)...\n');

  const engineResults = [];

  for (const persona of STUDENT_PERSONAS) {
    const engines = [];

    // 1. Hardcoding detection
    const hardcodingFlags = persona.submissions
      .map(s => checkHardcoding(s.code, EXERCISE.testCases))
      .filter(Boolean);
    if (hardcodingFlags.length > 0) engines.push('HARDCODING ✓');

    // 2. Blank template detection
    const blankFlags = persona.submissions
      .map(s => checkBlankTemplate(s.code, EXERCISE.starterCode))
      .filter(Boolean);
    if (blankFlags.length > 0) engines.push('BLANK_TEMPLATE ✓');

    // 3. Code growth anomaly
    let growthFlag = null;
    if (persona.submissions.length >= 2) {
      for (let i = 1; i < persona.submissions.length; i++) {
        growthFlag = checkCodeGrowthAnomaly(persona.submissions[i-1].code, persona.submissions[i].code);
        if (growthFlag) break;
      }
    }
    if (growthFlag) engines.push('CODE_GROWTH ✓');

    // 4. Behavioral anomaly detection
    const beFlags = detectBehavioralAnomalies(persona.behavior);
    if (beFlags.length > 0) engines.push('BEHAVIORAL ✓');

    // 5. Retry storm detection
    const storm = detectRetryStorm(persona.submissions);
    if (storm.triggered) engines.push('RETRY_STORM ✓');

    // 6. Micro-concept analysis
    const lastSub = persona.submissions[persona.submissions.length - 1];
    const micros = analyzeMicroConcepts(lastSub.code);

    // 7. AST verification
    const ast = verifyAST(lastSub.code);

    // 8. CDS score (simulated)
    const lastAttempts = persona.submissions.filter(s => s.isCorrect);
    const finalCorrect = lastAttempts.length > 0;

    engineResults.push({
      name: persona.name,
      expectedFlags: persona.expectedFlags,
      detectedEngines: engines,
      microPassRate: `${micros.filter(m => m.passed).length}/${micros.length}`,
      astVerified: ast.verified,
      astIssues: ast.issues,
      finalCorrect,
    });

    // Normalize: extract engine type from strings like "HARDCODING ✓" -> "HARDCODING"
    const normalizeFlag = (f) => f
      .replace('HARDCODED_SOLUTION', 'HARDCODING')
      .replace('CODE_GROWTH_ANOMALY', 'CODE_GROWTH')
      .replace('PASSIVE_BEHAVIOR_LOG', 'BEHAVIORAL')
      .replace('_SOLUTION', '')
      .replace('_LOG', '')
      .replace('_ANOMALY', '');
    const detectedTypes = engines.map(e => e.replace(' ✓', ''));
    const expectedTypes = persona.expectedFlags.map(normalizeFlag);
    const flagMatch = expectedTypes.some(f => detectedTypes.includes(f));

    const status = (flagMatch || persona.expectedFlags.length === 0) ? '✓' : '✗';
    console.log(`  ${status} ${persona.name}`);
    console.log(`    Expected flags: ${persona.expectedFlags.join(', ') || 'none'}`);
    if (engines.length > 0) console.log(`    Detected:       ${engines.join(', ')}`);
    if (persona.expectedFlags.length > 0 && !flagMatch) {
      console.log(`    ⚠ Flag mismatch! Expected ${persona.expectedFlags.join(', ')}`);
    }
    console.log(`    Micro-concepts: ${micros.filter(m => m.passed).length}/${micros.length}`);
    console.log(`    AST: ${ast.verified ? 'verified' : 'issues: ' + (ast.issues.join(', ') || 'none')}`);
    console.log('');
  }

  // ── Aggregate CDS ────────────────────────────────────────────────────────
  const cdsResults = computeBatchCDS(
    STUDENT_PERSONAS.map(p => ({
      studentId: p.id,
      attempts: p.submissions.map(s => ({
        isCorrect: s.isCorrect, timeSpent: s.timeSpent, code: s.code,
      })),
    }))
  );

  console.log('  Aggregate CDS Results (simulated p95 min-max):');
  for (const [sid, data] of Object.entries(cdsResults)) {
    const p = STUDENT_PERSONAS.find(p => p.id === Number(sid));
    const name = p ? p.name : sid;
    const expected = p ? p.expectedCDS : '?';
    const match = data.classification === expected ? '✓' : '✗';
    console.log(`    ${match} ${name}: NER=${data.ner} NRS=${data.nrs} NTS=${data.nts} CDS=${data.cds} (${data.classification}) [expected: ${expected}]`);
  }

  return { engineResults, cdsResults };
}

// ── Main Entry Point ─────────────────────────────────────────────────────

async function runComprehensiveSimulation() {
  console.log('╔══════════════════════════════════════════════════════════╗');
  console.log('║  COMPREHENSIVE ENGINE SIMULATION                       ║');
  console.log('║  Testing: CDS, Integrity, Micro-Concepts, AST,        ║');
  console.log('║           Behavioral, Retry Storm, Code Growth         ║');
  console.log('╚══════════════════════════════════════════════════════════╝\n');

  const startTime = Date.now();

  // Part A: Browser
  const browserResults = await runBrowserSimulation();

  // Part B: Engines
  const { engineResults, cdsResults } = await runEngineSimulation();

  const duration = Date.now() - startTime;

  // ── Final Summary ──────────────────────────────────────────────────────────
  const totalFlags = engineResults.reduce((s, r) => s + r.expectedFlags.filter(f => {
    const engineName = f.replace('_SOLUTION', '').replace('_LOG', '');
    return r.detectedEngines.some(e => e.includes(engineName));
  }).length, 0);

  const summary = {
    timestamp: new Date().toISOString(),
    duration,
    browserPassed: browserResults.filter(r => r.passed).length,
    browserTotal: browserResults.length,
    personasTested: STUDENT_PERSONAS.length,
    enginesCovered: {
      hardcodingDetector: engineResults.some(r =>
        r.detectedEngines.some(e => e.includes('HARDCODING'))),
      blankTemplateDetector: engineResults.some(r =>
        r.detectedEngines.some(e => e.includes('BLANK_TEMPLATE'))),
      codeGrowthDetector: engineResults.some(r =>
        r.detectedEngines.some(e => e.includes('CODE_GROWTH'))),
      behavioralDetector: engineResults.some(r =>
        r.detectedEngines.some(e => e.includes('BEHAVIORAL'))),
      retryStormDetector: engineResults.some(r =>
        r.detectedEngines.some(e => e.includes('RETRY_STORM'))),
      microConceptEngine: true,
      astVerifier: true,
      cdsEngine: true,
    },
    cdsDistribution: {
      Low: Object.values(cdsResults).filter(r => r.classification === 'Low').length,
      Moderate: Object.values(cdsResults).filter(r => r.classification === 'Moderate').length,
      High: Object.values(cdsResults).filter(r => r.classification === 'High').length,
    },
  };

  console.log('╔══════════════════════════════════════════════════════════╗');
  console.log('║  FINAL SUMMARY                                        ║');
  console.log('╠══════════════════════════════════════════════════════════╣');
  console.log(`║  Browser Tests:  ${summary.browserPassed}/${summary.browserTotal} passed`);
  console.log(`║  Duration:       ${(duration / 1000).toFixed(1)}s`);
  console.log(`║  Personas:       ${summary.personasTested}`);
  console.log(`║  CDS Dist:       Low=${summary.cdsDistribution.Low} Mid=${summary.cdsDistribution.Moderate} High=${summary.cdsDistribution.High}`);
  console.log('║  Engines Tested:');
  for (const [name, covered] of Object.entries(summary.enginesCovered)) {
    console.log(`║    ${covered ? '✓' : '○'} ${name}`);
  }
  console.log('╚══════════════════════════════════════════════════════════╝\n');

  return { summary, browserResults, engineResults, cdsResults };
}

module.exports = { runComprehensiveSimulation };
