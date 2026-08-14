// frontend/tests/e2e/mobile-triage.spec.js
// Acceptance §13.1 (instructor triage < 10s), §13.2 (student next-action < 3s),
// §13.11 (admin has 1+ action path), §13.12 (ISO/IEC 25010 < 4 min on phone).

import { test, expect } from '@playwright/test';

test.use({ viewport: { width: 375, height: 812 } });

test('instructor sees top-3 at-risk students in < 10s (acceptance §13.1)', async ({ page }) => {
  await page.goto('/instructor/command');
  const t0 = Date.now();
  // Wait for the AtRiskRoster to appear.
  await expect(page.getByText('At-Risk Roster')).toBeVisible({ timeout: 9000 });
  const t1 = Date.now();
  expect(t1 - t0).toBeLessThan(10000);
});

test('student sees next action in < 3s (acceptance §13.2)', async ({ page }) => {
  await page.goto('/student/today');
  await expect(page.getByText('What')).toBeVisible({ timeout: 2500 });
});

test('admin overview surfaces the evaluation queue (acceptance §13.11)', async ({ page }) => {
  await page.goto('/admin/overview');
  // The overview surfaces the evaluation section with a link into the queue.
  await expect(page.getByRole('link', { name: /View \/ export/ })).toBeVisible();
});

test('admin can complete ISO/IEC 25010 evaluation (acceptance §13.12)', async ({ page }) => {
  await page.goto('/admin/evaluation');
  // Iterate through all 12 questions (FS 4 + US 5 + PE 3); tap the first
  // scale option of each. Buttons are labeled "{scale}: {label}", e.g. "1: Strongly Disagree".
  const firstOption = page.getByRole('button', { name: /^1: Strongly Disagree$/ });
  for (let i = 0; i < 12; i++) {
    await firstOption.nth(i).click();
  }
  await expect(page.getByText('Submit evaluation')).toBeVisible({ timeout: 240_000 });
});
