/**
 * Follow-up normalizer: puts the `light:` variant outermost
 * (hover:light:x -> light:hover:x) to match Tailwind stacking convention.
 * Run once: node scripts/theme-normalize.mjs
 */
import fs from 'node:fs';
import path from 'node:path';

function walk(dir, out = []) {
  for (const e of fs.readdirSync(dir, { withFileTypes: true })) {
    const p = path.join(dir, e.name);
    if (e.isDirectory()) walk(p, out);
    else if (/\.(jsx|js)$/.test(e.name) && !/\.test\.(jsx|js)$/.test(e.name)) out.push(p);
  }
  return out;
}

const SRC = path.join(process.cwd(), 'src');
let files = 0;
for (const file of walk(SRC)) {
  let text = fs.readFileSync(file, 'utf8');
  const next = text.replace(
    /\b(hover|focus|focus-visible|focus-within|active|disabled|sm|md|lg|xl|placeholder|first|last|odd|even):light:/g,
    'light:$1:'
  );
  if (next !== text) {
    fs.writeFileSync(file, next);
    files++;
    console.log('normalized ' + path.relative(SRC, file));
  }
}
console.log(`done, ${files} file(s) touched`);
