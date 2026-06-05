// frontend/tests/mobile/layout-config-driven.test.js
// Spec §2.3, acceptance §13.7. 100% of phone screens render from the config object;
// zero `if (role === ...)` branches in src/pages/mobile/.

import { describe, it, expect } from 'vitest';
import { readFileSync, readdirSync, statSync } from 'fs';
import { join } from 'path';

function walkJsx(dir) {
  const out = [];
  for (const e of readdirSync(dir)) {
    const p = join(dir, e);
    if (statSync(p).isDirectory()) out.push(...walkJsx(p));
    else if (p.endsWith('.jsx')) out.push(p);
  }
  return out;
}

describe('mobile pages are layout-config-driven (acceptance §13.7)', () => {
  it('no mobile page checks user.role directly', () => {
    const files = walkJsx('src/pages/mobile');
    const offenders = [];
    for (const f of files) {
      const src = readFileSync(f, 'utf8');
      if (/role\s*===\s*['"]/.test(src) || /role\s*!==\s*['"]/.test(src)) {
        offenders.push(f);
      }
    }
    expect(offenders).toEqual([]);
  });
});
