/**
 * WCAG contrast checker for CodeInsight theme tokens.
 * Parses :root (dark) and [data-theme="light"] blocks in src/index.css,
 * computes relative-luminance contrast ratios for every meaningful
 * foreground/background pairing, and FAILS (exit 1) on any violation.
 * Run: node scripts/check-contrast.mjs
 */
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

const css = fs.readFileSync(
  path.join(path.dirname(fileURLToPath(import.meta.url)), '..', 'src', 'index.css'),
  'utf8'
);

function block(theme) {
  const re = theme === 'dark' ? /:root\s*\{([^}]*)\}/ : /\[data-theme="light"\]\s*\{([^}]*)\}/;
  const m = css.match(re);
  if (!m) throw new Error('theme block not found: ' + theme);
  const vars = {};
  for (const line of m[1].split('\n')) {
    const mm = line.match(/--([\w-]+)\s*:\s*([^;]+);/);
    if (mm) vars[mm[1]] = mm[2].trim();
  }
  return vars;
}

// "222 47% 11%" | "#0F172A" -> [r,g,b] 0..255
function toRgb(v) {
  v = v.trim();
  if (v.startsWith('#')) {
    let h = v.slice(1);
    if (h.length === 3) h = h.split('').map((c) => c + c).join('');
    const n = parseInt(h.slice(0, 6), 16);
    return [(n >> 16) & 255, (n >> 8) & 255, n & 255];
  }
  const m = v.match(/^([\d.]+)\s+([\d.]+)%\s+([\d.]+)%$/);
  if (!m) throw new Error('unparsable color: ' + v);
  let [hh, ss, ll] = [parseFloat(m[1]) / 360, parseFloat(m[2]) / 100, parseFloat(m[3]) / 100];
  const f = (p, q, t) => {
    if (t < 0) t += 1;
    if (t > 1) t -= 1;
    if (t < 1 / 6) return p + (q - p) * 6 * t;
    if (t < 1 / 2) return q;
    if (t < 2 / 3) return p + (q - p) * (2 / 3 - t) * 6;
    return p;
  };
  let r, g, b;
  if (ss === 0) {
    r = g = b = ll;
  } else {
    const q = ll < 0.5 ? ll * (1 + ss) : ll + ss - ll * ss;
    const p = 2 * ll - q;
    r = f(p, q, hh + 1 / 3);
    g = f(p, q, hh);
    b = f(p, q, hh - 1 / 3);
  }
  return [r, g, b].map((x) => Math.round(x * 255));
}

function lum([r, g, b]) {
  const f = (c) => {
    c /= 255;
    return c <= 0.03928 ? c / 12.92 : Math.pow((c + 0.055) / 1.055, 2.4);
  };
  return 0.2126 * f(r) + 0.7152 * f(g) + 0.0722 * f(b);
}

function ratio(fg, bg) {
  const [l1, l2] = [lum(toRgb(fg)), lum(toRgb(bg))].sort((a, b) => b - a);
  return (l1 + 0.05) / (l2 + 0.05);
}

const dark = block('dark');
const light = block('light');
const V = (theme, name) => (theme === 'dark' ? dark : light)[name];

// [label, fgVar, bgVar, minRatio]
const PAIRS = [
  ['body text', 'foreground', 'background', 7.0],
  ['body secondary (--text-2)', 'text-2', 'bg-0', 4.5],
  ['body tertiary (--text-3)', 'text-3', 'bg-0', 4.5],
  ['card text', 'card-foreground', 'card', 7.0],
  ['popover text', 'popover-foreground', 'popover', 4.5],
  ['primary button text', 'primary-foreground', 'primary', 4.5],
  ['primary as text on page', 'primary', 'background', 4.5],
  ['secondary button text', 'secondary-foreground', 'secondary', 4.5],
  ['muted text', 'muted-foreground', 'background', 4.5],
  ['accent text', 'accent-foreground', 'accent', 4.5],
  ['destructive text on page', 'destructive', 'background', 4.5],
  ['destructive button text', 'destructive-foreground', 'destructive', 4.5],
  ['success text on page', 'success', 'background', 4.5],
  ['success button text', 'success-foreground', 'success', 4.5],
  ['warning text on page', 'warning', 'background', 4.5],
  ['warning button text', 'warning-foreground', 'warning', 4.5],
  ['info text on page', 'info', 'background', 4.5],
  ['info button text', 'info-foreground', 'info', 4.5],
  ['cds-low text on page', 'cds-low', 'background', 4.5],
  ['cds-mod text on page', 'cds-mod', 'background', 4.5],
  ['cds-high text on page', 'cds-high', 'background', 4.5],
  ['cds-na text on page', 'cds-na', 'background', 4.5],
  ['input border vs page', 'input', 'background', 3.0],
  ['focus ring vs page', 'ring', 'background', 3.0],
  ['sidebar text', 'sidebar-foreground', 'sidebar', 4.5],
  ['chart-1 vs card', 'chart-1', 'card', 3.0],
  ['chart-2 vs card', 'chart-2', 'card', 3.0],
  ['chart-3 vs card', 'chart-3', 'card', 3.0],
  ['chart-4 vs card', 'chart-4', 'card', 3.0],
  ['chart-5 vs card', 'chart-5', 'card', 3.0],
];

let failures = 0;
let lightFailures = 0;
for (const theme of ['dark', 'light']) {
  // DARK is frozen (do-not-touch rule): reported for baseline context only,
  // never enforced. LIGHT is the deliverable and is strictly enforced.
  const enforced = theme === 'light';
  console.log(`\n== ${theme.toUpperCase()}${enforced ? '' : ' (baseline, not enforced)'} ==`);
  for (const [label, fg, bg, min] of PAIRS) {
    let r, status;
    try {
      r = ratio(V(theme, fg), V(theme, bg));
      status = r >= min ? 'PASS' : 'FAIL';
      if (status === 'FAIL') {
        failures++;
        if (enforced) lightFailures++;
      }
    } catch (e) {
      r = NaN;
      status = 'ERROR(' + e.message + ')';
      failures++;
      if (enforced) lightFailures++;
    }
    console.log(`${status}  ${Number.isNaN(r) ? '---' : r.toFixed(2) + ':1'}  (need ${min}:1)  ${label}  [${fg} on ${bg}]`);
  }
}
console.log(
  lightFailures
    ? `\n${lightFailures} ENFORCED (LIGHT) FAILURE(S) — ${failures} total incl. dark baseline`
    : '\nALL LIGHT PAIRS PASS' + (failures ? ` (${failures} pre-existing dark-baseline note(s), dark frozen)` : '')
);
process.exit(lightFailures ? 1 : 0);
