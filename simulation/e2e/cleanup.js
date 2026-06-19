const { Pool } = require('pg');
const { DB_CONFIG } = require('./config');

const pool = new Pool(DB_CONFIG);

async function cleanupTestData(exerciseId, sectionId) {
  console.log('\nCleaning up test data...');
  const client = await pool.connect();
  try {
    await client.query('BEGIN');

    const f1 = await client.query('DELETE FROM integrity_flags WHERE exercise_id = $1', [exerciseId]);
    console.log(`  \u2713 ${f1.rowCount} integrity_flags deleted`);

    const f2 = await client.query("DELETE FROM analytics_alerts WHERE exercise_id = $1 AND alert_type = 'CDS_HIGH'", [exerciseId]);
    console.log(`  \u2713 ${f2.rowCount} analytics_alerts deleted`);

    const f3 = await client.query('DELETE FROM cds_snapshots WHERE exercise_id = $1', [exerciseId]);
    console.log(`  \u2713 ${f3.rowCount} cds_snapshots deleted`);

    const f4 = await client.query('DELETE FROM cds_scores WHERE exercise_id = $1', [exerciseId]);
    console.log(`  \u2713 ${f4.rowCount} cds_scores deleted`);

    const f5 = await client.query('DELETE FROM submissions WHERE exercise_id = $1', [exerciseId]);
    console.log(`  \u2713 ${f5.rowCount} submissions deleted`);

    const f6 = await client.query('DELETE FROM exercises WHERE id = $1', [exerciseId]);
    console.log(`  \u2713 Exercise ${exerciseId} deleted`);

    const f7 = await client.query(
      "DELETE FROM enrollments WHERE student_id IN (SELECT id FROM users WHERE email LIKE $1) AND section_id = $2",
      ['student-%@e2e.test', sectionId]);
    console.log(`  \u2713 ${f7.rowCount} enrollments deleted`);

    if (sectionId) {
      const f8 = await client.query('DELETE FROM sections WHERE id = $1', [sectionId]);
      console.log(`  \u2713 Section ${sectionId} deleted`);
    }

    const f9 = await client.query(
      "DELETE FROM users WHERE email LIKE $1", ['student-%@e2e.test']);
    console.log(`  \u2713 ${f9.rowCount} test users deleted`);

    await client.query('COMMIT');
    console.log('  \u2713 All test data cleaned up');
  } catch (error) {
    await client.query('ROLLBACK');
    console.error(`  \u2717 Cleanup error: ${error.message}`);
    throw error;
  } finally {
    client.release();
    await pool.end();
  }
}

async function main() {
  const exerciseId = process.argv[2] ? parseInt(process.argv[2]) : null;
  const sectionId = process.argv[3] ? parseInt(process.argv[3]) : null;
  if (!exerciseId) { console.error('Usage: node cleanup.js <exerciseId> [sectionId]'); process.exit(1); }
  await cleanupTestData(exerciseId, sectionId || 0);
  console.log('Done.');
}

if (require.main === module) main();

module.exports = { cleanupTestData };
