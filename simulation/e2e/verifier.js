const { Pool } = require('pg');
const { DB_CONFIG, STUDENT_COUNT } = require('./config');
const { PERSONAS } = require('./personas');

const pool = new Pool(DB_CONFIG);

async function verifySubmissions(exerciseId, sectionId) {
  const checks = [];
  const client = await pool.connect();

  try {
    const subCount = await client.query(
      'SELECT COUNT(*) as count FROM submissions WHERE exercise_id = $1', [exerciseId]);
    const count = parseInt(subCount.rows[0].count);
    checks.push({ name: 'Submissions exist', passed: count >= STUDENT_COUNT,
      detail: `${count} total (need >= ${STUDENT_COUNT})` });

    const studentSubs = await client.query(
      'SELECT student_id, COUNT(*) as cnt FROM submissions WHERE exercise_id = $1 GROUP BY student_id',
      [exerciseId]);
    const submittedIds = new Set(studentSubs.rows.map(r => r.student_id));
    const studentUsers = await client.query(
      'SELECT id FROM users WHERE email LIKE $1', ['student-%@e2e.test']);
    const missing = studentUsers.rows.filter(u => !submittedIds.has(u.id));
    checks.push({ name: 'All students submitted', passed: missing.length === 0,
      detail: missing.length > 0 ? `Missing: ${missing.map(m => m.id).join(',')}` : 'All 20 present' });

    const codeCheck = await client.query(
      "SELECT COUNT(*) as count FROM submissions WHERE exercise_id = $1 AND code IS NOT NULL",
      [exerciseId]);
    checks.push({ name: 'Code stored for all', passed: parseInt(codeCheck.rows[0].count) >= STUDENT_COUNT,
      detail: `${codeCheck.rows[0].count} submissions with code` });

    const flags = await client.query(
      'SELECT flag_type, COUNT(*) as cnt FROM integrity_flags WHERE exercise_id = $1 GROUP BY flag_type ORDER BY flag_type',
      [exerciseId]);
    const flagMap = {};
    flags.rows.forEach(r => flagMap[r.flag_type] = parseInt(r.cnt));
    const hardcodingOk = (flagMap['HARDCODING'] || 0) >= 2;
    const blankOk = (flagMap['BLANK_TEMPLATE'] || 0) >= 2;
    const codeGrowthOk = (flagMap['CODE_GROWTH_ANOMALY'] || 0) >= 1;
    const behavioralOk = (flagMap['BEHAVIORAL_ANOMALY'] || 0) >= 2;
    checks.push({ name: 'HARDCODING flags', passed: hardcodingOk,
      detail: `${flagMap['HARDCODING'] || 0} found (need >= 2)` });
    checks.push({ name: 'BLANK_TEMPLATE flags', passed: blankOk,
      detail: `${flagMap['BLANK_TEMPLATE'] || 0} found (need >= 2)` });
    checks.push({ name: 'CODE_GROWTH_ANOMALY flags', passed: codeGrowthOk,
      detail: `${flagMap['CODE_GROWTH_ANOMALY'] || 0} found (need >= 1)` });
    checks.push({ name: 'BEHAVIORAL_ANOMALY flags', passed: behavioralOk,
      detail: `${flagMap['BEHAVIORAL_ANOMALY'] || 0} found (need >= 2)` });

    const cdsScores = await client.query(
      'SELECT COUNT(*) as count FROM cds_scores WHERE exercise_id = $1', [exerciseId]);
    checks.push({ name: 'CDS scores for all', passed: parseInt(cdsScores.rows[0].count) >= STUDENT_COUNT,
      detail: `${cdsScores.rows[0].count} scores (need >= ${STUDENT_COUNT})` });

    const cdsDist = await client.query(
      'SELECT classification, COUNT(*) as cnt FROM cds_scores WHERE exercise_id = $1 GROUP BY classification',
      [exerciseId]);
    const distMap = {};
    cdsDist.rows.forEach(r => distMap[r.classification] = parseInt(r.cnt));
    const hasLow = (distMap['Low'] || 0) >= 1;
    const hasHigh = (distMap['High'] || 0) >= 1;
    checks.push({ name: 'CDS distribution - Low exists', passed: hasLow,
      detail: `Low: ${distMap['Low'] || 0}` });
    checks.push({ name: 'CDS distribution - High exists', passed: hasHigh,
      detail: `High: ${distMap['High'] || 0}, Moderate: ${distMap['Moderate'] || 0}` });

    const alerts = await client.query(
      "SELECT COUNT(*) as count FROM alerts WHERE exercise_id = $1",
      [exerciseId]);
    checks.push({ name: 'High-CDS alerts generated', passed: parseInt(alerts.rows[0].count) >= 1,
      detail: `${alerts.rows[0].count} alerts` });

    const snapshots = await client.query(
      'SELECT COUNT(*) as count FROM cds_snapshots WHERE exercise_id = $1', [exerciseId]);
    checks.push({ name: 'CDS snapshots written', passed: parseInt(snapshots.rows[0].count) >= 1,
      detail: `${snapshots.rows[0].count} snapshots` });

    const allPassed = checks.every(c => c.passed);
    return { checks, allPassed };
  } finally {
    client.release();
  }
}

module.exports = { verifySubmissions };
