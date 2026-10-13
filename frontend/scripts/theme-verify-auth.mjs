/**
 * Authenticated theme verification: logs in as seeded instructor + student,
 * screenshots key pages in both themes (via the real Sidebar toggle),
 * and asserts theme resolution + tokens throughout.
 *
 * Run: node scripts/theme-verify-auth.mjs
 * Needs: vite dev :5173, backend :5000 with seeded demo accounts.
 * Output: frontend/theme-shots-auth/*.png + console report.
 */
import fs from 'node:fs';
import path from 'node:path';
import { chromium } from '@playwright/test';

const EXE = 'C:\\Users\\Rokhai\\AppData\\Local\\ms-playwright\\chromium-1228\\chrome-win64\\chrome.exe';
const BASE = 'http://127.0.0.1:5173';
const OUT = path.join(process.cwd(), 'theme-shots-auth');
fs.mkdirSync(OUT, { recursive: true });

let failures = 0;
const check = (ok, label, detail = '') => {
  console.log(`${ok ? 'PASS' : 'FAIL'}  ${label}${detail ? '  [' + detail + ']' : ''}`);
  if (!ok) failures++;
};

const browser = await chromium.launch({ executablePath: EXE });

async function loginAs(email, password) {
  const ctx = await browser.newContext({ viewport: { width: 1440, height: 900 }, colorScheme: 'dark' });
  const page = await ctx.newPage();
  await page.goto(BASE + '/login', { waitUntil: 'networkidle', timeout: 45000 }).catch(() => null);
  await page.getByLabel(/email/i).fill(email);
  await page.getByLabel(/password/i).fill(password);
  await page.getByRole('button', { name: /sign in/i }).click();
  await page.waitForTimeout(2500);
  return { ctx, page };
}

async function setMode(page, mode) {
  // Use the real Sidebar toggle when present; fall back to direct set.
  const group = page.getByRole('group', { name: 'Color theme' });
  if ((await group.count()) > 0) {
    const btn = group.getByRole('button', { name: new RegExp(mode, 'i') });
    if ((await btn.count()) > 0) {
      await btn.click();
      await page.waitForTimeout(600);
      return 'toggle-ui';
    }
  }
  await page.evaluate((m) => {
    localStorage.setItem('codeinsight-theme', m);
    location.reload();
  }, mode);
  await page.waitForTimeout(1500);
  return 'localStorage-fallback';
}

async function snap(page, file, extra = {}) {
  await page.waitForTimeout(1200);
  await page.screenshot({ path: path.join(OUT, file) });
  const info = await page.evaluate(() => ({
    dataTheme: document.documentElement.getAttribute('data-theme'),
    bg: getComputedStyle(document.body).backgroundColor,
    fg: getComputedStyle(document.body).color,
    url: location.pathname + location.search,
  }));
  console.log(`shot ${file}  theme=${info.dataTheme} url=${info.url} ${extra.note || ''}`);
  return info;
}

// ── Instructor ──────────────────────────────────────────────
{
  const { ctx, page } = await loginAs('instructor@psu.edu', 'password123');
  const url = new URL(page.url());
  check(url.pathname.startsWith('/instructor'), 'instructor login lands on instructor area', url.pathname);

  const togglePresent = (await page.getByRole('group', { name: 'Color theme' }).count()) > 0;
  check(togglePresent, 'Sidebar theme toggle present (instructor)');

  for (const [path, name] of [
    ['/instructor/dashboard', 'instructor-dashboard'],
    ['/instructor/heatmap', 'instructor-heatmap'],
    ['/instructor/students', 'instructor-students'],
    ['/admin', 'admin-overview-redirect-check'],
  ]) {
    await page.goto(BASE + path, { waitUntil: 'networkidle', timeout: 45000 }).catch(() => null);
    const howDark = await setMode(page, 'dark');
    const d = await snap(page, `dark-${name}.png`, { note: howDark });
    check(d.dataTheme === 'dark', `dark ${name} resolves`, d.dataTheme);
    const howLight = await setMode(page, 'light');
    const l = await snap(page, `light-${name}.png`, { note: howLight });
    check(l.dataTheme === 'light', `light ${name} resolves`, l.dataTheme);
    check(l.bg === 'rgb(248, 250, 252)', `light ${name} page bg`, l.bg);
  }
  await ctx.close();
}

// ── Student ─────────────────────────────────────────────────
{
  const { ctx, page } = await loginAs('maria@student.psu.edu', 'password123');
  const url = new URL(page.url());
  check(url.pathname.startsWith('/student'), 'student login lands on student area', url.pathname);
  for (const [path, name] of [
    ['/student/exercises', 'student-exercises'],
    ['/student/dashboard', 'student-dashboard'],
  ]) {
    await page.goto(BASE + path, { waitUntil: 'networkidle', timeout: 45000 }).catch(() => null);
    await setMode(page, 'dark');
    const d = await snap(page, `dark-${name}.png`);
    check(d.dataTheme === 'dark', `dark ${name} resolves`, d.dataTheme);
    await setMode(page, 'light');
    const l = await snap(page, `light-${name}.png`);
    check(l.dataTheme === 'light' && l.bg === 'rgb(248, 250, 252)', `light ${name} resolves+bg`, `${l.dataTheme}/${l.bg}`);
  }
  await ctx.close();
}

await browser.close();
console.log(failures ? `\n${failures} FAILURE(S)` : '\nALL AUTH THEME CHECKS PASS');
process.exit(failures ? 1 : 0);
