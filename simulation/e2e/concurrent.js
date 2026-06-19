const { chromium } = require('playwright');
const { submitStudentFlow } = require('./submitter');

function splitIntoQueues(personas, n) {
  const queues = Array.from({ length: n }, () => []);
  personas.forEach((p, i) => queues[i % n].push(p));
  return queues;
}

async function runSession(students, exerciseId, sessionIdx) {
  const browser = await chromium.launch({ headless: true });
  const results = [];
  try {
    const context = await browser.newContext({ viewport: { width: 1280, height: 720 } });
    for (let i = 0; i < students.length; i++) {
      const student = students[i];
      console.log(`  [Session ${sessionIdx + 1}] ${student.name} (${student.email}) — ${student.attempts.length} attempt(s)...`);
      const page = await context.newPage();
      const r = await submitStudentFlow(page, student, exerciseId, { concurrentIdx: sessionIdx });
      await page.close();
      results.push(r);
      const status = r.attempts.some(a => a.success) ? '\u2713' : '\u2717';
      const passed = r.attempts.filter(a => a.success).length;
      console.log(`  [Session ${sessionIdx + 1}] ${status} ${student.name}: ${passed}/${r.attempts.length} passed (${(r.duration / 1000).toFixed(1)}s)`);
    }
  } catch (e) {
    console.error(`  [Session ${sessionIdx + 1}] Error: ${e.message}`);
  } finally {
    await browser.close();
  }
  return results;
}

async function runConcurrent(personas, exerciseId, concurrency = 3) {
  const queues = splitIntoQueues(personas, concurrency);
  console.log(`\n  Splitting ${personas.length} students into ${concurrency} sessions (${queues.map(q => q.length).join('+')})`);

  const startTime = Date.now();
  const sessions = queues.map((queue, i) => runSession(queue, exerciseId, i));
  const sessionResults = await Promise.allSettled(sessions);

  const allResults = [];
  for (const sr of sessionResults) {
    if (sr.status === 'fulfilled') allResults.push(...sr.value);
    else console.error('Session rejected:', sr.reason);
  }

  console.log(`\n  All sessions complete in ${((Date.now() - startTime) / 1000).toFixed(1)}s`);
  return allResults;
}

module.exports = { runConcurrent };
