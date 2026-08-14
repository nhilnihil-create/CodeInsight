// frontend/tests/e2e/mobile-widths.spec.js
// Phase 4: Mobile no-overflow walkthrough at 360×740 and 768×1024.
// Asserts document.documentElement.scrollWidth <= window.innerWidth after each
// page load — catches any element that pushes past the right edge.

import { test, expect } from '@playwright/test';

// ── Login helper ──────────────────────────────────────────────────────
async function login(page, email, password) {
  await page.goto('/login');
  await page.fill('#email', email);
  await page.fill('#password', password);
  await page.keyboard.press('Enter');
  await page.waitForURL((url) => !url.pathname.startsWith('/login'), { timeout: 15000 });
}

// ── Section gate helper (student) ────────────────────────────────────
async function dismissSectionGate(page) {
  const gate = page.getByRole('button', { name: /Open class/ }).first();
  const gateShown = await gate.waitFor({ state: 'visible', timeout: 10000 })
    .then(() => true)
    .catch(() => false);
  if (gateShown) {
    await gate.click();
    await page.waitForURL((url) => !url.pathname.includes('select-section'), { timeout: 15000 });
  }
}

// ── Overflow assertion ────────────────────────────────────────────────
async function assertNoHorizontalOverflow(page, route) {
  // Wait for network idle so lazy content has rendered.
  await page.waitForLoadState('networkidle', { timeout: 15000 }).catch(() => {});
  const overflow = await page.evaluate(() => {
    return document.documentElement.scrollWidth > window.innerWidth;
  });
  expect(overflow, `Horizontal overflow detected on ${route}`).toBe(false);
}

// ── Route tables ──────────────────────────────────────────────────────
const INSTRUCTOR_ROUTES = [
  '/instructor/dashboard',
  '/instructor/command',
  '/instructor/reports',
  '/instructor/sections',
  '/instructor/students',
  '/instructor/exercises',
  '/instructor/exercise-explorer',
  '/instructor/alerts',
  '/instructor/integrity',
  '/instructor/heatmap',
];

const STUDENT_ROUTES = [
  '/student/dashboard',
  '/student/today',
  '/student/progress',
  '/student/profile',
  '/student/recommendations',
  '/student/sections',
];

// ── Test matrix ───────────────────────────────────────────────────────
const VIEWPORTS = [
  { name: 'phone', width: 360, height: 740 },
  { name: 'tablet', width: 768, height: 1024 },
];

for (const vp of VIEWPORTS) {
  test.describe(`No horizontal overflow at ${vp.width}×${vp.height}`, () => {
    test.use({ viewport: { width: vp.width, height: vp.height } });

    test('instructor routes — no overflow', async ({ page }) => {
      await login(page, 'instructor@psu.edu', 'password123');

      for (const route of INSTRUCTOR_ROUTES) {
        await page.goto(route, { waitUntil: 'domcontentloaded' });
        await assertNoHorizontalOverflow(page, route);
      }
    });

    test('student routes — no overflow', async ({ page }) => {
      await login(page, 'maria@student.psu.edu', 'password123');
      await dismissSectionGate(page);

      for (const route of STUDENT_ROUTES) {
        await page.goto(route, { waitUntil: 'domcontentloaded' });
        await assertNoHorizontalOverflow(page, route);
      }
    });

    test('hamburger drawer opens and closes without overflow', async ({ page }) => {
      await login(page, 'maria@student.psu.edu', 'password123');
      await dismissSectionGate(page);
      await page.goto('/student/today', { waitUntil: 'domcontentloaded' });

      // Only relevant below 1024px — the hamburger is hidden on desktop.
      if (vp.width < 1024) {
        const hamburger = page.getByRole('button', { name: /menu|toggle sidebar/i }).first();
        const exists = await hamburger.isVisible({ timeout: 3000 }).catch(() => false);
        if (exists) {
          await hamburger.click();
          await page.waitForTimeout(300);
          await assertNoHorizontalOverflow(page, '/student/today (drawer open)');

          // Close via backdrop
          const backdrop = page.locator('[data-testid="sidebar-scrim"], .fixed.inset-0').first();
          if (await backdrop.isVisible({ timeout: 2000 }).catch(() => false)) {
            await backdrop.click();
            await page.waitForTimeout(300);
          }
          await assertNoHorizontalOverflow(page, '/student/today (drawer closed)');
        }
      }
    });
  });
}
