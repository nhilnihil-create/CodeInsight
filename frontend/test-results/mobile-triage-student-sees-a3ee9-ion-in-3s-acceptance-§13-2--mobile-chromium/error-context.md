# Instructions

- Following Playwright test failed.
- Explain why, be concise, respect Playwright best practices.
- Provide a snippet of code with the fix, if possible.

# Test info

- Name: mobile-triage.spec.js >> student sees next action in < 3s (acceptance §13.2)
- Location: tests/e2e/mobile-triage.spec.js:18:1

# Error details

```
Error: expect(locator).toBeVisible() failed

Locator: getByText('TODAY\'S FOCUS')
Expected: visible
Timeout: 2500ms
Error: element(s) not found

Call log:
  - Expect "toBeVisible" with timeout 2500ms
  - waiting for getByText('TODAY\'S FOCUS')

```

```yaml
- heading "Page not found" [level=3]
- paragraph: The page you were looking for doesn't exist or has been moved.
- button "Back to Login"
- region "Notifications alt+T"
```

# Test source

```ts
  1  | // frontend/tests/e2e/mobile-triage.spec.js
  2  | // Acceptance §13.1 (instructor triage < 10s), §13.2 (student next-action < 3s),
  3  | // §13.11 (admin has 1+ action path), §13.12 (ISO/IEC 25010 < 4 min on phone).
  4  | 
  5  | import { test, expect } from '@playwright/test';
  6  | 
  7  | test.use({ viewport: { width: 375, height: 812 } });
  8  | 
  9  | test('instructor sees top-3 at-risk students in < 10s (acceptance §13.1)', async ({ page }) => {
  10 |   await page.goto('/instructor/command');
  11 |   const t0 = Date.now();
  12 |   // Wait for the AtRiskQueue to appear.
  13 |   await expect(page.getByText('AT-RISK QUEUE')).toBeVisible({ timeout: 9000 });
  14 |   const t1 = Date.now();
  15 |   expect(t1 - t0).toBeLessThan(10000);
  16 | });
  17 | 
  18 | test('student sees next action in < 3s (acceptance §13.2)', async ({ page }) => {
  19 |   await page.goto('/student/today');
> 20 |   await expect(page.getByText("TODAY'S FOCUS")).toBeVisible({ timeout: 2500 });
     |                                                 ^ Error: expect(locator).toBeVisible() failed
  21 | });
  22 | 
  23 | test('admin overview surfaces the evaluation queue (acceptance §13.11)', async ({ page }) => {
  24 |   await page.goto('/admin/overview');
  25 |   await expect(page.getByText(/Review pending evaluations/)).toBeVisible();
  26 | });
  27 | 
  28 | test('admin can complete ISO/IEC 25010 evaluation (acceptance §13.12)', async ({ page }) => {
  29 |   await page.goto('/admin/evaluation');
  30 |   // Iterate through 8 questions (the spec's instrument size); tap first scale option.
  31 |   for (let i = 0; i < 8; i++) {
  32 |     await page.getByRole('button', { name: /^1 — / }).click();
  33 |   }
  34 |   await expect(page.getByText('Submit evaluation')).toBeVisible({ timeout: 240_000 });
  35 | });
  36 | 
```