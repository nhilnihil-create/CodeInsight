const { execSync, spawn } = require('child_process');
const http = require('http');
const { BACKEND_URL } = require('./config');

function sleep(ms) { return new Promise(r => setTimeout(r, ms)); }

async function getBackendPid() {
  try {
    const out = execSync('pgrep -f "node.*server\\.js"', { encoding: 'utf8', timeout: 5000 });
    const pids = out.trim().split('\n').filter(Boolean).map(Number);
    const ourPid = process.pid;
    return pids.find(p => p !== ourPid) || null;
  } catch { return null; }
}

async function waitForHealthy(timeoutMs = 30000) {
  const start = Date.now();
  while (Date.now() - start < timeoutMs) {
    try {
      await new Promise((resolve, reject) => {
        http.get(`${BACKEND_URL}/api/auth/me`, (res) => {
          resolve(res.statusCode);
        }).on('error', reject);
      });
      return true;
    } catch {}
    await sleep(1000);
  }
  return false;
}

async function testServerRestart(exerciseId) {
  const steps = [];

  try {
    const token = await new Promise((resolve, reject) => {
      const data = JSON.stringify({ email: 'student-01@e2e.test', password: 'test1234' });
      const url = new URL('/api/auth/login', BACKEND_URL);
      const req = http.request({ hostname: url.hostname, port: url.port, path: url.pathname,
        method: 'POST', headers: { 'Content-Type': 'application/json', 'Content-Length': Buffer.byteLength(data) }
      }, (res) => {
        const cookies = res.headers['set-cookie'] || [];
        const t = cookies.find(c => c.startsWith('ci_token='));
        resolve(t ? t.split(';')[0].replace('ci_token=', '') : null);
      });
      req.on('error', reject);
      req.write(data); req.end();
    });
    if (!token) {
      return { passed: false, steps: [{ action: 'Login', success: false, detail: 'Could not get student token' }] };
    }
    steps.push({ action: 'Login as student-01', success: true });

    const pid = await getBackendPid();
    if (!pid) {
      return { passed: false, steps: [...steps, { action: 'Find PID', success: false, detail: 'Could not find backend process' }] };
    }
    steps.push({ action: 'Found backend PID', success: true, detail: `PID ${pid}` });

    process.kill(pid, 'SIGTERM');
    await sleep(2000);

    const stillRunning = await getBackendPid();
    steps.push({ action: 'Kill backend', success: !stillRunning || stillRunning !== pid,
      detail: `PID ${pid} killed` });

    await sleep(3000);

    const backendDir = '/home/nihil/projects/codeinsight/backend';
    const server = spawn('node', ['server.js'], {
      cwd: backendDir, stdio: 'pipe',
      env: { ...process.env, PORT: '5000', PLAYWRIGHT: '1' },
    });
    server.stdout.on('data', d => process.stdout.write(`[backend] ${d}`));
    server.stderr.on('data', d => process.stderr.write(`[backend-err] ${d}`));

    steps.push({ action: 'Spawn backend', success: true, detail: `PID ${server.pid}` });

    const healthy = await waitForHealthy(60000);
    steps.push({ action: 'Wait for healthy', success: healthy, detail: healthy ? 'Backend ready' : 'Timeout' });

    if (!healthy) {
      return { passed: false, steps };
    }

    const submitRes = await new Promise((resolve, reject) => {
      const data = JSON.stringify({ exerciseId: Number(exerciseId), code: '#include <iostream>\nusing namespace std;\nint main() { cout << "recovery"; return 0; }',
        timeSpentSeconds: 5 });
      const url = new URL('/api/submissions/submit', BACKEND_URL);
      const req = http.request({ hostname: url.hostname, port: url.port, path: url.pathname,
        method: 'POST', headers: { 'Content-Type': 'application/json', 'Content-Length': Buffer.byteLength(data),
          'Cookie': `ci_token=${token}` }
      }, (res) => {
        let d = '';
        res.on('data', c => d += c);
        res.on('end', () => { try { resolve(JSON.parse(d)); } catch { resolve({ raw: d }); } });
      });
      req.on('error', reject);
      req.write(data); req.end();
    });
    steps.push({ action: 'Submit recovery attempt', success: !!submitRes,
      detail: submitRes ? `Submitted (id=${submitRes.id || '?'})` : 'Failed' });

    const { Pool } = require('pg');
    const { DB_CONFIG } = require('./config');
    const pool = new Pool(DB_CONFIG);
    const dbResult = await pool.query(
      "SELECT COUNT(*) as count FROM submissions WHERE exercise_id = $1 AND code LIKE '%recovery%'",
      [exerciseId]);
    const found = parseInt(dbResult.rows[0].count);
    await pool.end();

    steps.push({ action: 'Verify recovery in DB', success: found >= 1,
      detail: `${found} recovery submission(s) found` });

    const allPassed = steps.filter(s => s.success === false).length === 0;
    return { passed: allPassed, steps };
  } catch (error) {
    return { passed: false, steps: [...steps, { action: 'Error', success: false, detail: error.message }] };
  }
}

module.exports = { testServerRestart };
