# Instructions

- Following Playwright test failed.
- Explain why, be concise, respect Playwright best practices.
- Provide a snippet of code with the fix, if possible.

# Test info

- Name: mobile-triage.spec.js >> admin can complete ISO/IEC 25010 evaluation (acceptance §13.12)
- Location: tests/e2e/mobile-triage.spec.js:28:1

# Error details

```
Test timeout of 30000ms exceeded.
```

```
Error: locator.click: Test timeout of 30000ms exceeded.
Call log:
  - waiting for getByRole('button', { name: /^1 — / })

```

# Page snapshot

```yaml
- generic [ref=e2]:
  - generic [ref=e4]:
    - link "Back to home" [ref=e6]:
      - /url: /
      - img [ref=e7]
      - text: Back to home
    - generic [ref=e9]:
      - generic [ref=e10]:
        - generic [ref=e11]: CodeInsight
        - heading "Welcome back" [level=3] [ref=e12]
        - paragraph [ref=e13]: Sign in to continue to CodeInsight · Pampanga State University · CCS
      - generic [ref=e15]:
        - generic [ref=e16]:
          - text: EMAIL
          - textbox "EMAIL" [ref=e17]:
            - /placeholder: your@email.com
        - generic [ref=e18]:
          - text: PASSWORD
          - textbox "PASSWORD" [ref=e19]:
            - /placeholder: ••••••••
        - button "Sign In" [ref=e20]:
          - img [ref=e21]
          - text: Sign In
      - generic [ref=e25]:
        - generic [ref=e26]:
          - img [ref=e27]
          - text: "Demo accounts (password: password123)"
        - generic [ref=e29]: "Instructor: instructor@psu.edu"
        - generic [ref=e30]: "Student: maria@student.psu.edu"
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
  20 |   await expect(page.getByText("TODAY'S FOCUS")).toBeVisible({ timeout: 2500 });
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
> 32 |     await page.getByRole('button', { name: /^1 — / }).click();
     |                                                       ^ Error: locator.click: Test timeout of 30000ms exceeded.
  33 |   }
  34 |   await expect(page.getByText('Submit evaluation')).toBeVisible({ timeout: 240_000 });
  35 | });
  36 | 
```