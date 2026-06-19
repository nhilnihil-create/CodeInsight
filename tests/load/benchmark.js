#!/usr/bin/env node

/**
 * Lightweight load/benchmark testing (article: "Load testing tools").
 * Measures API response times and throughput under concurrent requests.
 *
 * Usage: node tests/load/benchmark.js [--concurrency=N] [--requests=N]
 *
 * Requires: Backend running on localhost:5000
 */

const http = require('http');

const CONCURRENCY = parseInt(process.argv.find(a => a.startsWith('--concurrency='))?.split('=')[1] || 10);
const TOTAL_REQUESTS = parseInt(process.argv.find(a => a.startsWith('--requests='))?.split('=')[1] || 100);
const BASE_URL = 'http://localhost:5000';

const endpoints = [
  '/api/health',
  '/api/concepts',
];

function fetch(path) {
  return new Promise((resolve) => {
    const start = Date.now();
    http.get(`${BASE_URL}${path}`, (res) => {
      let data = '';
      res.on('data', (chunk) => { data += chunk; });
      res.on('end', () => {
        resolve({
          path,
          status: res.statusCode,
          duration: Date.now() - start,
          size: data.length,
        });
      });
    }).on('error', (err) => {
      resolve({ path, status: 0, duration: Date.now() - start, error: err.message });
    });
  });
}

async function worker(id, endpoint) {
  const results = [];
  for (let i = 0; i < TOTAL_REQUESTS / CONCURRENCY; i++) {
    results.push(await fetch(endpoint));
  }
  return results;
}

async function run() {
  console.log(`\n📊 Load Test: ${TOTAL_REQUESTS} requests, concurrency=${CONCURRENCY}`);
  console.log('='.repeat(60));

  for (const endpoint of endpoints) {
    console.log(`\n  Testing: ${endpoint}`);
    const workers = [];
    for (let i = 0; i < CONCURRENCY; i++) {
      workers.push(worker(i, endpoint));
    }
    const allResults = (await Promise.all(workers)).flat();

    const durations = allResults.map(r => r.duration);
    const successes = allResults.filter(r => r.status === 200).length;
    const failures = allResults.filter(r => r.status !== 200).length;
    durations.sort((a, b) => a - b);

    const avg = durations.reduce((a, b) => a + b, 0) / durations.length;
    const p50 = durations[Math.floor(durations.length * 0.5)];
    const p95 = durations[Math.floor(durations.length * 0.95)];
    const p99 = durations[Math.floor(durations.length * 0.99)];

    console.log(`    Success: ${successes}/${TOTAL_REQUESTS}`);
    console.log(`    Avg:     ${avg.toFixed(0)}ms`);
    console.log(`    P50:     ${p50}ms`);
    console.log(`    P95:     ${p95}ms`);
    console.log(`    P99:     ${p99}ms`);
    console.log(`    Fail:    ${failures}`);
  }

  console.log('\n✅ Benchmark complete\n');
}

run().catch(console.error);
