// frontend/scripts/check-mobile-bundle.mjs
// Acceptance §13.4, §13.5.
// Fails the build if any phone-route bundle exceeds 200 KB gzipped,
// or if D3 is present in a phone summary-mode bundle.
//
// NOTE: This check currently scans every chunk in dist/assets/, not just
// per-route phone splits. The single main JS chunk will likely be flagged
// for an un-lazy-loaded app. Per-route splitting is a follow-up (Task 18+).

import { readFileSync, readdirSync } from 'fs';
import { join } from 'path';
import { gzipSync } from 'zlib';
import { execSync } from 'child_process';

const BUDGET_KB = 200;
const PHONE_ROUTES = [
  '/instructor/command', '/instructor/students', '/instructor/concepts', '/instructor/integrity',
  '/student/today', '/student/exercises', '/student/progress',
  '/admin/overview',
];

console.log('Building...');
execSync('npm run build', { stdio: 'inherit' });

const distDir = 'dist/assets';
const chunks = readdirSync(distDir).filter(f => f.endsWith('.js'));
let bad = [];

for (const chunk of chunks) {
  const gz = gzipSync(readFileSync(join(distDir, chunk))).length;
  const kb = gz / 1024;
  const src = readFileSync(join(distDir, chunk), 'utf8');
  const containsD3 = /d3-|from "d3"|from 'd3'/.test(src) || /d3\.(select|scale|line|axis)/.test(src);
  if (kb > BUDGET_KB) bad.push(`${chunk}: ${kb.toFixed(1)} KB > ${BUDGET_KB} KB`);
  if (containsD3 && chunk.includes('mobile')) bad.push(`${chunk}: contains D3 (forbidden in summary-mode phone bundle)`);
}

if (bad.length) {
  console.error('Bundle budget FAILED:');
  for (const b of bad) console.error('  -', b);
  process.exit(1);
}
console.log(`OK — all phone chunks <= ${BUDGET_KB} KB gzipped, no D3 in mobile summary bundles.`);
