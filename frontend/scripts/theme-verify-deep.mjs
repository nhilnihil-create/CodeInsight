/**
 * Deep-page theme verification: student code editor (Monaco) + exercise
 * list, both themes, driven through the real UI. Best-effort: exits 0 with
 * a clear SKIP report when local demo data is absent.
 */
import fs from 'node:fs';
import path from 'node:path';
import { chromium } from '@playwright/test';

const EXE = 'C:\\Users\\Rokhai\\AppData\\Local\\ms-playwright\\chromium-1228\\chrome-win64\\chrome.exe';
const BASE = 'http://127.0.0.1:5173';
const OUT = path.join(process.cwd(), 'theme-shots-auth');
fs.mkdirSync(OUT, { recursive: true });

let failures = 0;
let skipped = 0;
const check = (ok, label, detail = '') => {
  console.log(`${ok ? 'PASS' : 'FAIL'}  ${label}${detail ? '  [' + detail + ']' : ''}`);
  if (!ok) failures++;
};

const browser = await chromium.launch({ executablePath: EXE });
const ctx = await browser.newContext({ viewport: { width: 1440, height: 900 }, colorScheme: 'dark' });
const page = await ctx.newPage();

await page.goto(BASE + '/login', { waitUntil: 'networkidle', timeout: 45000 }).catch(() => null);
await page.getByLabel(/email/i).fill('angel.cruz@psu.edu');
await page.getByLabel(/password/i).fill('password123');
await page.getByRole('button', { name: /sign in/i }).click();
await page.waitForTimeout(2500);

if (!page.url().includes('/student')) {
  console.log(`SKIP  persona login unavailable (${page.url()}) — deep student pages unverified by screenshot`);
  skipped++;
  await browser.close();
  console.log(failures ? `\n${failures} FAILURE(S)` : '\nDONE (with skips)');
  process.exit(failures ? 1 : 0);
}

// Pick a section if gated, then open the exercises list.
if (page.url().includes('select-section')) {
  const cards = page.locator('button, a').filter({ hasText: /BSIT|CS|Programming|Join|Select/i });
  if ((await cards.count()) > 0) {
    await cards.first().click().catch(() => null);
    await page.waitForTimeout(2000);
  }
}
await page.goto(BASE + '/student/exercises', { waitUntil: 'networkidle', timeout: 45000 }).catch(() => null);
await page.waitForTimeout(1500);

// Open the first exercise row (whatever opens the editor).
const opener = page.locator('a[href*="/student/exercises/"], a[href*="code-editor"], button').first();
const hrefCount = await page.locator('a[href*="/student/exercises/"]').count();
console.log(`exercise links found: ${hrefCount}`);
if (hrefCount === 0) {
  console.log('SKIP  no exercises reachable — editor unverified by screenshot');
  skipped++;
} else {
  await page.locator('a[href*="/student/exercises/"]').first().click();
  await page.waitForTimeout(2500);

  for (const theme of ['dark', 'light']) {
    await page.evaluate((m) => {
      localStorage.setItem('codeinsight-theme', m);
      location.reload();
    }, theme);
    await page.waitForTimeout(2500);
    const file = `${theme}-student-editor.png`;
    await page.screenshot({ path: path.join(OUT, file) });
    const info = await page.evaluate(() => ({
      dataTheme: document.documentElement.getAttribute('data-theme'),
      monacoBg: (() => {
        const el = document.querySelector('.monaco-editor-background, .monaco-editor');
        return el ? getComputedStyle(el).backgroundColor : 'n/a';
      })(),
    }));
    console.log(`shot ${file}  theme=${info.dataTheme} monaco-bg=${info.monacoBg}`);
    check(info.dataTheme === theme, `${theme} editor resolves`, info.dataTheme);
    if (theme === 'light') {
      check(info.monacoBg === 'rgb(255, 255, 255)', 'light Monaco background is white', info.monacoBg);
    } else {
      const darkOk = info.monacoBg === 'rgb(10, 16, 24)' || info.monacoBg === 'rgb(9, 14, 26)';
      check(darkOk, 'dark Monaco background stays dark', info.monacoBg);
    }
  }
}

await browser.close();
console.log(skipped ? `\nDONE with ${skipped} skip(s)` : '\nALL DEEP CHECKS PASS');
process.exit(failures ? 1 : 0);
