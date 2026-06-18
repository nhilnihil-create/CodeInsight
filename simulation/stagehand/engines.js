/**
 * simulation/stagehand/engines.js
 *
 * Core engine simulators that mirror the backend logic.
 * Used for pre-validation and expected results calculation.
 */

// ── CDS Engine Simulator ─────────────────────────────────────────────────
const CDS_THRESHOLDS = { LOW: 0.31, MODERATE: 0.50 };

function computeClassStats(rawValues) {
  const safeValues = (rawValues || []).map(v => Number(v)).filter(v => !isNaN(v));
  if (safeValues.length === 0) return { min: 0, p95: 0, denominator: 0, hasVariance: false };
  const sorted = [...safeValues].sort((a, b) => a - b);
  const p95Index = Math.ceil(sorted.length * 0.95) - 1;
  const p95 = sorted[Math.max(0, Math.min(p95Index, sorted.length - 1))];
  const min = Math.min(...safeValues);
  const denominator = p95 - min;
  return { min, p95, denominator, hasVariance: denominator !== 0 };
}

function normalizeWithStats(value, stats) {
  if (!stats.hasVariance) return 0.00;
  const cappedValue = Math.min(Number(value), stats.p95);
  const raw = Math.max(0, Math.min((cappedValue - stats.min) / stats.denominator, 1.0));
  return Number(parseFloat(raw).toFixed(2));
}

function classify(cds) {
  if (cds === null || cds === undefined) return 'Unscored';
  if (cds <= CDS_THRESHOLDS.LOW) return 'Low';
  if (cds <= CDS_THRESHOLDS.MODERATE) return 'Moderate';
  return 'High';
}

function computeBatchCDS(submissions) {
  // submissions: Array of { studentId, attempts: [{ isCorrect, timeSpent, code }] }
  const perStudent = {};
  for (const sub of submissions) {
    const attempts = sub.attempts;
    const failedAttempts = attempts.filter(a => !a.isCorrect).length;
    const totalAttempts = attempts.length;
    const maxTime = Math.max(...attempts.map(a => a.timeSpent));
    perStudent[sub.studentId] = { failedAttempts, totalAttempts, maxTime };
  }

  const failedValues = Object.values(perStudent).map(s => s.failedAttempts);
  const totalValues = Object.values(perStudent).map(s => s.totalAttempts);
  const timeValues = Object.values(perStudent).map(s => s.maxTime);

  const failedStats = computeClassStats(failedValues);
  const totalStats = computeClassStats(totalValues);
  const timeStats = computeClassStats(timeValues);

  const results = {};
  for (const [studentId, data] of Object.entries(perStudent)) {
    const ner = normalizeWithStats(data.failedAttempts, failedStats);
    const nrs = normalizeWithStats(data.totalAttempts, totalStats);
    const nts = normalizeWithStats(data.maxTime, timeStats);
    const cds = Math.min(1, (0.40 * ner) + (0.35 * nrs) + (0.25 * nts));
    const cdsRounded = Number(parseFloat(cds).toFixed(2));

    results[studentId] = {
      ner, nrs, nts,
      cds: cdsRounded,
      classification: classify(cdsRounded),
    };
  }

  return results;
}

// ── Integrity Engine Simulator ────────────────────────────────────────────

function checkHardcoding(code, testCases) {
  const coutPattern = /cout\s*<<\s*(\d+)\s*[;>]/g;
  const matches = Array.from(code.matchAll(coutPattern));
  if (matches.length === 0) return null;

  const literalValues = matches.map(m => m[1]);
  const expectedOutputs = (testCases || []).map(tc => tc.expected.toString().trim());
  const matchesExpected = expectedOutputs.some(exp => literalValues.some(val => exp.includes(val)));

  const hasOperations = /[\+\-\*\/\%\(\)]/g.test(code);
  const hasVariables = /\b(int|float|double)\s+\w+\s*=/g.test(code);
  const hasLoops = /(for|while|do)\s*[\({]/g.test(code);

  const computationScore = (hasOperations ? 1 : 0) + (hasVariables ? 1 : 0) + (hasLoops ? 1 : 0);

  if (computationScore < 2 && !hasLoops) {
    return {
      type: 'HARDCODED_SOLUTION',
      severity: 'HIGH',
      evidence: `Found ${matches.length} direct numeric output(s) matching expected answer with minimal computation`,
      matchesExpected,
    };
  }

  return null;
}

function checkBlankTemplate(code, starterCode) {
  const normalizedCode = code.trim();
  const normalizedStarter = starterCode.trim();

  if (normalizedCode === '') {
    return { type: 'BLANK_TEMPLATE', severity: 'HIGH', evidence: 'Submission is empty' };
  }
  if (normalizedCode === normalizedStarter) {
    return { type: 'BLANK_TEMPLATE', severity: 'HIGH', evidence: 'Submission is identical to starter code' };
  }
  return null;
}

function checkCodeGrowthAnomaly(previousCode, currentCode) {
  if (!previousCode) return null;
  const prevTokens = previousCode.split(/\s+/).length;
  const currTokens = currentCode.split(/\s+/).length;
  const growth = prevTokens > 0 ? ((currTokens - prevTokens) / prevTokens) * 100 : 0;

  if (growth > 30) {
    return {
      type: 'CODE_GROWTH_ANOMALY',
      severity: 'MEDIUM',
      evidence: `Code grew ${growth.toFixed(1)}% between submissions (${prevTokens} → ${currTokens} tokens)`,
      growth,
    };
  }
  return null;
}

// ── Behavioral Anomaly Detector ──────────────────────────────────────────

const TAB_SWITCH_THRESHOLD = 10;
const PASTE_EVENT_THRESHOLD = 5;
const IDLE_TIME_THRESHOLD = 60; // seconds

function detectBehavioralAnomalies(behavior) {
  const flags = [];

  if (behavior.tabSwitches > TAB_SWITCH_THRESHOLD) {
    flags.push({
      type: 'PASSIVE_BEHAVIOR_LOG',
      severity: 'MEDIUM',
      evidence: `${behavior.tabSwitches} tab switches detected (threshold: ${TAB_SWITCH_THRESHOLD})`,
    });
  }

  if (behavior.pasteEvents > PASTE_EVENT_THRESHOLD) {
    flags.push({
      type: 'PASSIVE_BEHAVIOR_LOG',
      severity: 'MEDIUM',
      evidence: `${behavior.pasteEvents} paste events detected (threshold: ${PASTE_EVENT_THRESHOLD})`,
    });
  }

  if (behavior.idleTime > IDLE_TIME_THRESHOLD) {
    flags.push({
      type: 'PASSIVE_BEHAVIOR_LOG',
      severity: 'LOW',
      evidence: `${behavior.idleTime}s idle time detected (threshold: ${IDLE_TIME_THRESHOLD}s)`,
    });
  }

  return flags;
}

// ── Retry Storm Detector ─────────────────────────────────────────────────

const RETRY_STORM_THRESHOLD = 10;
const RETRY_STORM_WINDOW_MIN = 30;

function detectRetryStorm(submissions) {
  const failedSubs = submissions.filter(s => !s.isCorrect);
  if (failedSubs.length >= RETRY_STORM_THRESHOLD) {
    return {
      triggered: true,
      type: 'RETRY_STORM',
      consecutiveFailures: failedSubs.length,
      threshold: RETRY_STORM_THRESHOLD,
    };
  }
  return { triggered: false };
}

// ── Micro-Concept Analyzer ───────────────────────────────────────────────

function analyzeMicroConcepts(code) {
  const results = [];

  // Check loop initialization
  const hasLoopInit = /int\s+\w+\s*=\s*\d+/g.test(code);
  results.push({
    concept: 'loop-initialization',
    passed: hasLoopInit,
    feedback: hasLoopInit ? 'Loop variable correctly initialized' : 'Missing loop variable initialization',
  });

  // Check loop condition
  const hasLoopCondition = /(i\s*<=|i\s*<|i\s*>=|i\s*>)/g.test(code);
  results.push({
    concept: 'loop-condition',
    passed: hasLoopCondition,
    feedback: hasLoopCondition ? 'Loop condition correctly defined' : 'Missing or incorrect loop condition',
  });

  // Check accumulator pattern
  const hasAccumulator = /(sum\s*\+=|sum\s*=\s*sum|total\s*\+=)/g.test(code);
  results.push({
    concept: 'accumulator-pattern',
    passed: hasAccumulator,
    feedback: hasAccumulator ? 'Accumulator pattern correctly used' : 'Missing accumulator pattern',
  });

  return results;
}

// ── AST Verifier Simulator ───────────────────────────────────────────────

function verifyAST(code) {
  const issues = [];

  // Check for required constructs
  const hasLoop = /(for|while|do)\s*\(/.test(code);
  const hasVariable = /\b(int|float|double|long|short)\s+\w+/.test(code);
  const hasOutput = /cout\s*<</.test(code);

  if (!hasLoop) issues.push('Missing loop construct');
  if (!hasVariable) issues.push('Missing variable declaration');
  if (!hasOutput) issues.push('Missing output statement');

  return {
    verified: issues.length === 0,
    issues,
    score: issues.length === 0 ? 1.0 : Math.max(0, 1 - (issues.length * 0.33)),
  };
}

module.exports = {
  computeBatchCDS,
  classify,
  CDS_THRESHOLDS,
  checkHardcoding,
  checkBlankTemplate,
  checkCodeGrowthAnomaly,
  detectBehavioralAnomalies,
  detectRetryStorm,
  analyzeMicroConcepts,
  verifyAST,
};
