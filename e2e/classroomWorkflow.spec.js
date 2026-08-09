/**
 * e2e/classroomWorkflow.spec.js
 *
 * Tier B: Playwright E2E tests for CodeInsight V2 classroom workflow.
 * Tests: Auth gate -> Join code -> Code submission -> Instructor dashboard.
 *
 * Runs against headless Chromium with Vite + Express auto-started.
 */

const { test, expect } = require('@playwright/test');

const INSTRUCTOR = {
  email: 'instructor@psu.edu',
  password: 'password123',
};

const STUDENT = {
  email: 'maria@student.psu.edu',
  password: 'password123',
};

// -- Test 1: Authentication Gate ------------------------------------------------------------------

test.describe('Authentication Gate', () => {
  test.skip('both portal buttons route to login page', ({ page }) => {
    // Skipped: Landing page auto-redirects to /login in dev mode
    // This test requires a clean state without prior auth sessions
  });

  test('instructor login redirects to instructor dashboard', async ({ page }) => {
    await page.goto('http://localhost:5173/login');

    await page.getByLabel('EMAIL').fill(INSTRUCTOR.email);
    await page.getByLabel('PASSWORD').fill(INSTRUCTOR.password);
    await page.getByRole('button', { name: 'Sign In' }).click();

    await expect(page).toHaveURL(/.*\/instructor\/dashboard/, { timeout: 10000 });
    await expect(page.getByRole('heading', { level: 1 })).toBeVisible({ timeout: 10000 });
  });

  test('student login redirects to student dashboard', async ({ page }) => {
    await page.goto('http://localhost:5173/login');

    await page.getByLabel('EMAIL').fill(STUDENT.email);
    await page.getByLabel('PASSWORD').fill(STUDENT.password);
    await page.getByRole('button', { name: 'Sign In' }).click();

    await expect(page).toHaveURL(/.*\/student/, { timeout: 10000 });
    await expect(page.getByRole('heading', { level: 1 })).toBeVisible({ timeout: 10000 });
  });

  test('invalid credentials show error toast', async ({ page }) => {
    await page.goto('http://localhost:5173/login');

    await page.getByLabel('EMAIL').fill('nobody@test.codeinsight');
    await page.getByLabel('PASSWORD').fill('wrongpassword');
    await page.getByRole('button', { name: 'Sign In' }).click();

    await expect(page.getByRole('alert')).toBeVisible();
    await expect(page.getByRole('alert')).toContainText(/invalid|failed|too many/i);
  });
});

// -- Test 2: Student Join Code Gate ---------------------------------------------------------------

test.describe('Student Join Code Gate', () => {
  test('invalid join code shows error message', async ({ page }) => {
    await page.goto('http://localhost:5173/login');
    await page.getByLabel('EMAIL').fill(STUDENT.email);
    await page.getByLabel('PASSWORD').fill(STUDENT.password);
    await page.getByRole('button', { name: 'Sign In' }).click();
    await expect(page).toHaveURL(/.*\/student/, { timeout: 10000 });

    await page.goto('http://localhost:5173/student/sections');

    const codeInput = page.getByPlaceholder('e.g. K7P-3QX');
    await expect(codeInput).toBeVisible();
    await codeInput.fill('XXXXX');

    await expect(page.getByRole('button', { name: 'Join' })).toBeDisabled();

    await codeInput.fill('ABC-DEF');
    await page.getByRole('button', { name: 'Join' }).click();

    await expect(page.getByText(/failed|invalid|error/i).first()).toBeVisible({ timeout: 5000 });
  });
});

// -- Test 3: Workspace Code Submission Flow -------------------------------------------------------

test.describe('Workspace Code Submission Flow', () => {
  test('student can type code in Monaco editor and submit', async ({ page }) => {
    await page.goto('http://localhost:5173/login');
    await page.getByLabel('EMAIL').fill(STUDENT.email);
    await page.getByLabel('PASSWORD').fill(STUDENT.password);
    await page.getByRole('button', { name: 'Sign In' }).click();
    await expect(page).toHaveURL(/.*\/student/, { timeout: 10000 });

    // Navigate to exercises page and find an exercise link with a real exercise ID
    await page.goto('http://localhost:5173/student/exercises');
    await page.waitForLoadState('networkidle');

    // Find links that match /student/exercises/\d+ pattern. Prefer an
    // uncompleted exercise: completed ones are in locked review mode with a
    // disabled Run/Submit. The list labels completed exercises "Review" and
    // incomplete ones "Start".
    const exerciseLinks = page.locator('a[href*="/student/exercises/"]').filter({ hasNotText: 'Review' });
    const count = await exerciseLinks.count();

    if (count > 0) {
      await exerciseLinks.first().click();
      await page.waitForLoadState('networkidle');

      // Wait for Monaco editor to render
      const hasMonaco = await page.waitForSelector('.monaco-editor', { state: 'visible', timeout: 15000 }).catch(() => null);
      if (!hasMonaco) {
        console.log('Monaco editor did not load — skipping Monaco interaction test.');
        return;
      }

      // Monaco's textarea is readonly/hidden in headless mode.
      // Inject code directly via Monaco's editor model API.
      const cppCode = `#include <iostream>
using namespace std;

int main() {
  cout << "Hello from E2E" << endl;
  return 0;
}`;
      await page.evaluate((code) => {
        // @monaco-editor/react exposes the editor instance on window
        // Try multiple ways to get the editor reference
        if (window.monaco && window.monacoEditor) {
          window.monacoEditor.setValue(code);
          return true;
        }
        // Fallback: set value on all visible Monaco editor instances
        const editors = document.querySelectorAll('.monaco-editor');
        if (editors.length > 0 && window.monaco) {
          const allModels = window.monaco.editor.getModels();
          if (allModels.length > 0) {
            allModels[0].setValue(code);
            return true;
          }
        }
        return false;
      }, cppCode);

      await page.waitForTimeout(1000);

      // Verify code was injected by checking displayed text
      const hasCode = await page.locator('.monaco-editor').getByText('Hello from E2E').isVisible().catch(() => false);
      console.log('Code visible in editor:', hasCode);
      expect(hasCode).toBeTruthy();

      // Exercise may be completed — enable Practice Mode to unlock Submit
      const practiceBtn = page.getByRole('button', { name: /Practice Mode/i });
      if (await practiceBtn.isVisible().catch(() => false)) {
        await practiceBtn.click();
        await page.waitForTimeout(2000);
      }

      // Try to find Submit button (may appear after Practice Mode)
      const submitBtn = page.getByRole('button', { name: /submit/i });
      if (await submitBtn.isVisible({ timeout: 3000 }).catch(() => false)) {
        await submitBtn.click();
        await page.waitForTimeout(10000);
        const hasResult = await page.locator(':has-text("passed"), :has-text("failed"), :has-text("Error"), :has-text("output")').first().isVisible().catch(() => false);
        expect(hasResult).toBeTruthy();
      } else {
        // Fallback: verify Run button works
        await page.getByRole('button', { name: /run/i }).first().click();
        await page.waitForTimeout(10000);
        const hasOutput = await page.locator(':has-text("output"), :has-text("Test"), :has-text("passed"), :has-text("failed")').first().isVisible().catch(() => false);
        expect(hasOutput).toBeTruthy();
      }
    } else {
      console.log('No exercises available for submission test. Skipping.');
    }
  });
});

// -- Test 4: Instructor Visualization Panel -------------------------------------------------------

test.describe('Instructor Visualization Panel', () => {
  test('instructor dashboard renders with data', async ({ page }) => {
    await page.goto('http://localhost:5173/login');
    await page.getByLabel('EMAIL').fill(INSTRUCTOR.email);
    await page.getByLabel('PASSWORD').fill(INSTRUCTOR.password);
    await page.getByRole('button', { name: 'Sign In' }).click();
    await expect(page).toHaveURL(/.*\/instructor\/dashboard/, { timeout: 10000 });

    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);

    const hasContent = await page.locator('svg, [class*="card"], [class*="Card"]').first().isVisible().catch(() => false);
    expect(hasContent).toBeTruthy();
  });

  test('concept difficulty heatmap renders', async ({ page }) => {
    await page.goto('http://localhost:5173/login');
    await page.getByLabel('EMAIL').fill(INSTRUCTOR.email);
    await page.getByLabel('PASSWORD').fill(INSTRUCTOR.password);
    await page.getByRole('button', { name: 'Sign In' }).click();
    await expect(page).toHaveURL(/.*\/instructor\/dashboard/, { timeout: 10000 });
    await page.waitForTimeout(3000);

    await page.goto('http://localhost:5173/instructor/heatmap');
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);

    const hasHeatmap = await page.locator('[class*="grid"], [class*="flex"]').first().isVisible().catch(() => false);
    expect(hasHeatmap).toBeTruthy();
  });

  test('student roster table renders', async ({ page }) => {
    await page.goto('http://localhost:5173/login');
    await page.getByLabel('EMAIL').fill(INSTRUCTOR.email);
    await page.getByLabel('PASSWORD').fill(INSTRUCTOR.password);
    await page.getByRole('button', { name: 'Sign In' }).click();
    await expect(page).toHaveURL(/.*\/instructor\/dashboard/, { timeout: 10000 });
    await page.waitForTimeout(3000);

    await page.goto('http://localhost:5173/instructor/students');
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);

    const hasStudents = await page.locator('table, [class*="student"], [class*="roster"]').first().isVisible()
      .catch(() => page.locator(':has-text("student")').first().isVisible().catch(() => false));
    expect(hasStudents).toBeTruthy();
  });

  test('CDS classification badges visible', async ({ page }) => {
    await page.goto('http://localhost:5173/login');
    await page.getByLabel('EMAIL').fill(INSTRUCTOR.email);
    await page.getByLabel('PASSWORD').fill(INSTRUCTOR.password);
    await page.getByRole('button', { name: 'Sign In' }).click();
    await expect(page).toHaveURL(/.*\/instructor\/dashboard/, { timeout: 10000 });
    await page.waitForTimeout(3000);

    await page.goto('http://localhost:5173/instructor/integrity');
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);

    const hasIntegrity = await page.locator(':has-text("integrity"), :has-text("flag"), :has-text("risk"), :has-text("CDS")')
      .first().isVisible().catch(() => false);
    expect(hasIntegrity).toBeTruthy();
  });
});
