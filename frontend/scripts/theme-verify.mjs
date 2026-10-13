/**
 * Theme verification: screenshots + computed-style assertions for both
 * themes, plus dark-regression check (local dark vs production dark,
 * which still serves the pre-theme build).
 *
 * Run: node scripts/theme-verify.mjs
 * Needs: vite dev on 127.0.0.1:5173 (see repo docs), network for prod.
 * Output: frontend/theme-shots/*.png + console report. Exit 1 on failure.
 */
import fs from 'node:fs';
import path from 'node:path';
import { chromium } from '@playwright/test';

const EXE = 'C:\\Users\\Rokhai\\AppData\\Local\\ms-playwright\\chromium-1228\\chrome-win64\\chrome.exe';
const OUT = path.join(process.cwd(), 'theme-shots');
fs.mkdirSync(OUT, { recursive: true });

const TARGETS = [
  { name: 'local', base: 'http://127.0.0.1:5173' },
  { name: 'prod', base: 'https://codeinsight-bsit-4h.vercel.app' },
];
const PAGES = [
  { name: 'landing', path: '/' },
  { name: 'login', path: '/login' },
];
const THEMES = ['dark', 'light'];

let failures = 0;
const check = (ok, label, detail = '') => {
  console.log(`${ok ? 'PASS' : 'FAIL'}  ${label}${detail ? '  [' + detail + ']' : ''}`);
  if (!ok) failures++;
};

const EXPECTED = {
  dark: { bg: 'rgb(9, 14, 26)', fg: 'rgb(208, 217, 231)' },
  light: { bg: 'rgb(248, 250, 252)', fg: 'rgb(15, 23, 41)' },
};

const browser = await chromium.launch({ executablePath: EXE });
const results = {};

for (const t of TARGETS) {
  results[t.name] = {};
  for (const theme of THEMES) {
    results[t.name][theme] = {};
    const ctx = await browser.newContext({
      viewport: { width: 1440, height: 900 },
      colorScheme: theme,
    });
    const page = await ctx.newPage();
    for (const p of PAGES) {
      await page.goto(t.base + p.path, { waitUntil: 'networkidle', timeout: 45000 }).catch(() => null);
      await page.waitForTimeout(1200);
      const shot = path.join(OUT, `${t.name}-${theme}-${p.name}.png`);
      await page.screenshot({ path: shot, fullPage: false });
      const info = await page.evaluate(() => {
        const cs = getComputedStyle(document.body);
        return {
          dataTheme: document.documentElement.getAttribute('data-theme'),
          colorScheme: document.documentElement.style.colorScheme,
          bodyBg: cs.backgroundColor,
          bodyFg: cs.color,
          themeColor: document.querySelector('meta[name="theme-color"]')?.content,
        };
      });
      results[t.name][theme][p.name] = info;
      console.log(`shot ${t.name}-${theme}-${p.name}.png  data-theme=${info.dataTheme} bg=${info.bodyBg}`);
    }
    await ctx.close();
  }
}

// Token-level assertions on the local build.
for (const theme of THEMES) {
  for (const p of PAGES) {
    const info = results.local[theme][p.name];
    check(info.dataTheme === theme, `local ${theme}/${p.name} resolves data-theme`);
    check(info.bodyBg === EXPECTED[theme].bg, `local ${theme}/${p.name} body bg`, info.bodyBg);
    check(info.bodyFg === EXPECTED[theme].fg, `local ${theme}/${p.name} body fg`, info.bodyFg);
    check(info.colorScheme === theme, `local ${theme}/${p.name} color-scheme`);
    check(
      info.themeColor === (theme === 'dark' ? '#0B0F19' : '#F8FAFC'),
      `local ${theme}/${p.name} theme-color meta`, info.themeColor
    );
  }
}

// Stored-choice override: stored light wins over dark OS and vice versa.
{
  const ctx = await browser.newContext({
    viewport: { width: 1280, height: 800 }, colorScheme: 'dark',
  });
  const page = await ctx.newPage();
  await page.goto('http://127.0.0.1:5173/login', { waitUntil: 'domcontentloaded', timeout: 45000 }).catch(() => null);
  await page.evaluate(() => localStorage.setItem('codeinsight-theme', 'light'));
  await page.reload({ waitUntil: 'domcontentloaded' }).catch(() => null);
  const dt1 = await page.evaluate(() => document.documentElement.getAttribute('data-theme'));
  check(dt1 === 'light', 'stored light overrides dark OS', dt1);
  await page.evaluate(() => localStorage.setItem('codeinsight-theme', 'dark'));
  await page.reload({ waitUntil: 'domcontentloaded' }).catch(() => null);
  const dt2 = await page.evaluate(() => document.documentElement.getAttribute('data-theme'));
  check(dt2 === 'dark', 'stored dark applies', dt2);
  await ctx.close();
}

// Dark regression: local dark (new build) vs prod dark (pre-theme build).
for (const p of PAGES) {
  const a = results.local.dark[p.name];
  const b = results.prod.dark[p.name];
  check(a.bodyBg === b.bodyBg && a.bodyFg === b.bodyFg, `dark regression ${p.name} tokens`, `${a.bodyBg}/${a.bodyFg}`);
}

await browser.close();
console.log(failures ? `\n${failures} FAILURE(S)` : '\nALL THEME CHECKS PASS');
process.exit(failures ? 1 : 0);
