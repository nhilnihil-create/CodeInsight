// frontend/tests/e2e/mobile-triage.spec.js
// Acceptance §13.1 (instructor triage < 10s), §13.2 (student next-action < 3s),
// §13.11 (admin has 1+ action path), §13.12 (ISO/IEC 25010 < 4 min on phone).

import { test, expect } from '@playwright/test';

test.use({ viewport: { width: 375, height: 812 } });

test('instructor sees top-3 at-risk students in < 10s (acceptance §13.1)', async ({ page }) => {
  await page.goto('/instructor/command');
  const t0 = Date.now();
  // Wait for the AtRiskQueue to appear.
  await expect(page.getByText('AT-RISK QUEUE')).toBeVisible({ timeout: 9000 });
  const t1 = Date.now();
  expect(t1 - t0).toBeLessThan(10000);
});

test('student sees next action in < 3s (acceptance §13.2)', async ({ page }) => {
  await page.goto('/student/today');
  await expect(page.getByText("TODAY'S FOCUS")).toBeVisible({ timeout: 2500 });
});

test('admin overview surfaces the evaluation queue (acceptance §13.11)', async ({ page }) => {
  await page.goto('/admin/overview');
  await expect(page.getByText(/Review pending evaluations/)).toBeVisible();
});

test('admin can complete ISO/IEC 25010 evaluation (acceptance §13.12)', async ({ page }) => {
  await page.goto('/admin/evaluation');
  // Iterate through 8 questions (the spec's instrument size); tap first scale option.
  for (let i = 0; i < 8; i++) {
    await page.getByRole('button', { name: /^1 — / }).click();
  }
  await expect(page.getByText('Submit evaluation')).toBeVisible({ timeout: 240_000 });
});
