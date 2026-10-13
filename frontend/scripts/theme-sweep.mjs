/**
 * One-shot theme sweep: appends `light:` counterparts to dark-only Tailwind
 * utilities across src. The BASE (dark) class is never modified in place,
 * so dark rendering is unchanged; the `light:` variant only matches under
 * [data-theme="light"] (see @custom-variant in index.css).
 *
 * Run once: node scripts/theme-sweep.mjs
 * Review with: git diff --stat
 */
import fs from 'node:fs';
import path from 'node:path';

const SRC = path.join(process.cwd(), 'src');

// [dark-only utility, light-mode counterpart core]
const ACCENTS_700 = [
  'emerald', 'teal', 'amber', 'rose', 'red', 'sky', 'blue',
  'orange', 'yellow', 'lime', 'cyan', 'purple', 'violet',
  'fuchsia', 'pink', 'indigo',
];
const GRAYS_600 = ['slate', 'zinc', 'gray', 'neutral', 'stone'];

const PAIRS = [];
for (const c of ACCENTS_700) {
  for (const s of ['300', '400', '500']) {
    PAIRS.push([`text-${c}-${s}`, `text-${c}-700`]);
  }
}
for (const c of GRAYS_600) {
  for (const s of ['300', '400', '500']) {
    PAIRS.push([`text-${c}-${s}`, `text-${c}-600`]);
  }
}
PAIRS.push(
  ['text-white/90', 'text-slate-900/90'],
  ['text-white/80', 'text-slate-900/80'],
  ['text-white/70', 'text-slate-700'],
  ['text-white/60', 'text-slate-600'],
  ['text-white/50', 'text-slate-600'],
  ['text-white/40', 'text-slate-500'],
  ['text-white/35', 'text-slate-500'],
  ['text-white/30', 'text-slate-500'],
  ['text-white/25', 'text-slate-500'],
  ['text-white', 'text-slate-900'],
  ['bg-white/[0.02]', 'bg-slate-950/[0.02]'],
  ['bg-white/[0.03]', 'bg-slate-950/[0.03]'],
  ['bg-white/[0.04]', 'bg-slate-950/[0.04]'],
  ['bg-white/[0.06]', 'bg-slate-950/[0.06]'],
  ['bg-white/[0.08]', 'bg-slate-950/[0.08]'],
  ['bg-white/[0.1]', 'bg-slate-950/[0.1]'],
  ['bg-white/[0.12]', 'bg-slate-950/[0.12]'],
  ['bg-white/10', 'bg-slate-950/10'],
  ['bg-white/5', 'bg-slate-950/5'],
  ['border-white/[0.04]', 'border-slate-950/[0.04]'],
  ['border-white/[0.05]', 'border-slate-950/[0.05]'],
  ['border-white/[0.06]', 'border-slate-950/[0.06]'],
  ['border-white/[0.08]', 'border-slate-950/[0.08]'],
  ['border-white/[0.1]', 'border-slate-950/[0.1]'],
  ['border-white/[0.12]', 'border-slate-950/[0.12]'],
  ['border-white/10', 'border-slate-950/10'],
  ['border-white/5', 'border-slate-950/5'],
  ['ring-white/[0.08]', 'ring-slate-950/20'],
  ['bg-[#0B0F19]', 'bg-[#F8FAFC]'],
  ['bg-[#0E1322]/80', 'bg-white/80'],
  ['from-[#0E1322]/90', 'from-white/90'],
  ['via-[#0E1322]/40', 'via-slate-300/50'],
  ['bg-[#080C15]', 'bg-white'],
  ['bg-[#0D1126]/40', 'bg-slate-200/50'],
  ['bg-[#0D1126]', 'bg-slate-100'],
  ['bg-[#131B2E]/60', 'bg-white/70'],
  ['bg-[#131B2E]/40', 'bg-white/60'],
  ['bg-[#131B2E]/30', 'bg-white/60'],
  ['bg-slate-900/40', 'bg-slate-200/70'],
);

// Longest-first so 'text-white/80' wins over 'text-white'.
PAIRS.sort((a, b) => b[0].length - a[0].length);

const esc = (s) => s.replace(/[.*+?^${}()|[\]\\]/g, '\\$&');

function walk(dir, out = []) {
  for (const e of fs.readdirSync(dir, { withFileTypes: true })) {
    const p = path.join(dir, e.name);
    if (e.isDirectory()) walk(p, out);
    else if (/\.(jsx|js)$/.test(e.name) && !/\.test\.(jsx|js)$/.test(e.name)) out.push(p);
  }
  return out;
}

const SKIP_FILES = new Set([
  'lib/theme.jsx',
  'lib/monacoThemes.js',
  'components/ThemeToggle.jsx',
  'components/ThemedToaster.jsx',
]);

let filesChanged = 0;
const pairCounts = {};
const changedFiles = [];

for (const file of walk(SRC)) {
  const rel = path.relative(SRC, file).replace(/\\/g, '/');
  if (SKIP_FILES.has(rel)) continue;
  let text = fs.readFileSync(file, 'utf8');
  let n = 0;
  for (const [from, lightCore] of PAIRS) {
    const re = new RegExp(`((?:[A-Za-z-]+:)*)${esc(from)}(?![\\w/-])`, 'g');
    text = text.replace(re, (m, prefix) => {
      if (prefix.includes('dark:') || prefix.includes('light:')) return m;
      n++;
      pairCounts[from] = (pairCounts[from] || 0) + 1;
      return `${m} ${prefix}light:${lightCore}`;
    });
  }
  if (n > 0) {
    fs.writeFileSync(file, text);
    filesChanged++;
    changedFiles.push(`${rel} (+${n})`);
  }
}

console.log(`files changed: ${filesChanged}`);
for (const f of changedFiles) console.log('  ' + f);
console.log('\nreplacements by token (top 30):');
for (const [k, v] of Object.entries(pairCounts).sort((a, b) => b[1] - a[1]).slice(0, 30)) {
  console.log(`  ${v}x  ${k}`);
}
