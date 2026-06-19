const { Pool } = require('pg');
const pool = new Pool({ host:'localhost', port:5432, database:'codeinsight', user:'codeuser', password:'codepassword123', max:5 });
async function q(sql, p) { const { rows } = await pool.query(sql, p||[]); return rows; }
async function runFullVerification(sectionId, ec) {
  console.log('\n--- Database Verification ---');
  const all = [];
  const s = await q('SELECT COUNT(*) as c FROM submissions s JOIN exercises e ON s.exercise_id=e.id WHERE e.section_id=$1', [sectionId]);
  all.push({ name:'Submissions', passed: parseInt(s[0].c)>=1, detail: s[0].c+' found' });
  const c = await q('SELECT COUNT(*) as c FROM cds_scores cs JOIN exercises e ON cs.exercise_id=e.id WHERE e.section_id=$1', [sectionId]);
  all.push({ name:'CDS scores', passed: parseInt(c[0].c)>=1, detail: c[0].c+' found' });
  const fl = await q('SELECT flag_type, COUNT(*) as c FROM integrity_flags WHERE section_id=$1 GROUP BY flag_type', [sectionId]);
  const fm = {}; fl.forEach(r => fm[r.flag_type] = parseInt(r.c));
  ['HARDCODING','BLANK_TEMPLATE','CODE_GROWTH_ANOMALY','BEHAVIORAL_ANOMALY','PASSIVE_BEHAVIOR_LOG'].forEach(t => all.push({ name:t+' flags', passed:(fm[t]||0)>=1, detail:(fm[t]||0)+' found' }));
  const al = await q('SELECT COUNT(*) as c FROM alerts WHERE section_id=$1', [sectionId]);
  all.push({ name:'Alerts', passed: parseInt(al[0].c)>=1, detail: al[0].c+' found' });
  const p = all.filter(r => r.passed).length;
  all.forEach(r => console.log('  '+(r.passed?'[PASS]':'[FAIL]')+' '+r.name+': '+r.detail));
  console.log('\nDB verification: '+p+'/'+all.length+' checks passed');
  return { results: all, allPassed: p===all.length };
}
async function close() { await pool.end(); }
module.exports = { q, runFullVerification, close };
