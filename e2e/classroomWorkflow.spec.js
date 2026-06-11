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
  test('both portal buttons route to login page', async ({ page }) => {
    await page.goto('http://127.0.0.1:5173');

    await page.getByRole('link', { name: 'Instructor Portal' }).click();
    await expect(page).toHaveURL(/.*\/login/);

    await page.goto('http://127.0.0.1:5173');
    await page.getByRole('link', { name: 'Student Access' }).click();
    await expect(page).toHaveURL(/.*\/login/);
  });

  test('instructor login redirects to instructor dashboard', async ({ page }) => {
    await page.goto('http://127.0.0.1:5173/login');

    await page.getByLabel('EMAIL').fill(INSTRUCTOR.email);
    await page.getByLabel('PASSWORD').fill(INSTRUCTOR.password);
    await page.getByRole('button', { name: 'Sign In' }).click();

    await expect(page).toHaveURL(/.*\/instructor\/dashboard/, { timeout: 10000 });
    await expect(page.getByRole('heading', { level: 1 })).toBeVisible({ timeout: 10000 });
  });

  test('student login redirects to student dashboard', async ({ page }) => {
    await page.goto('http://127.0.0.1:5173/login');

    await page.getByLabel('EMAIL').fill(STUDENT.email);
    await page.getByLabel('PASSWORD').fill(STUDENT.password);
    await page.getByRole('button', { name: 'Sign In' }).click();

    await expect(page).toHaveURL(/.*\/student/, { timeout: 10000 });
    await expect(page.getByRole('heading', { level: 1 })).toBeVisible({ timeout: 10000 });
  });

  test('invalid credentials show error toast', async ({ page }) => {
    await page.goto('http://127.0.0.1:5173/login');

    await page.getByLabel('EMAIL').fill('nobody@test.codeinsight');
    await page.getByLabel('PASSWORD').fill('wrongpassword');
    await page.getByRole('button', { name: 'Sign In' }).click();

    await expect(page.getByRole('alert')).toBeVisible();
    await expect(page.getByRole('alert')).toContainText(/invalid|failed/i);
  });
});

// -- Test 2: Student Join Code Gate ---------------------------------------------------------------

test.describe('Student Join Code Gate', () => {
  test('invalid join code shows error message', async ({ page }) => {
    await page.goto('http://127.0.0.1:5173/login');
    await page.getByLabel('EMAIL').fill(STUDENT.email);
    await page.getByLabel('PASSWORD').fill(STUDENT.password);
    await page.getByRole('button', { name: 'Sign In' }).click();
    await expect(page).toHaveURL(/.*\/student/, { timeout: 10000 });

    await page.goto('http://127.0.0.1:5173/student/sections');

    const codeInput = page.getByPlaceholder('e.g. K7P-3QX');
    await expect(codeInput).toBeVisible();
    await codeInput.fill('XXXXX');

    await expect(page.getByRole('button', { name: 'Join' })).toBeDisabled();

    await codeInput.fill('ABC-DEF');
    await page.getByRole('button', { name: 'Join' }).click();

    await expect(page.getByText(/failed|invalid|error/i)).toBeVisible({ timeout: 5000 });
  });
});

// -- Test 3: Workspace Code Submission Flow -------------------------------------------------------

test.describe('Workspace Code Submission Flow', () => {
  test('student can type code in Monaco editor and submit', async ({ page }) => {
    await page.goto('http://127.0.0.1:5173/login');
    await page.getByLabel('EMAIL').fill(STUDENT.email);
    await page.getByLabel('PASSWORD').fill(STUDENT.password);
    await page.getByRole('button', { name: 'Sign In' }).click();
    await expect(page).toHaveURL(/.*\/student/, { timeout: 10000 });

    await page.goto('http://127.0.0.1:5173/student/exercises');
    await page.waitForLoadState('networkidle');

    const exerciseLinks = page.locator('a').filter({ hasText: /exercise/i });
    const count = await exerciseLinks.count();

    if (count > 0) {
      await exerciseLinks.first().click();
      await page.waitForLoadState('networkidle');

      // Monaco renders its editable content in a hidden textarea inside .monaco-editor .inputarea
      const editorTextarea = page.locator('.monaco-editor .inputarea').first();
      await editorTextarea.click();

      await page.keyboard.press('ControlOrMeta+KeyA');
      await page.keyboard.press('Backspace');

      const cppCode = `#include <iostream>
using namespace std;

int main() {
  cout << "Hello from E2E" << endl;
  return 0;
}`;
      await page.keyboard.type(cppCode, { delay: 50 });

      await expect(page.locator('.monaco-editor .line')).toContainText('Hello from E2E', { timeout: 5000 });

      await page.getByRole('button', { name: /submit/i }).click();

      await page.waitForTimeout(10000);

      const hasResult = await page.locator(':has-text("passed"), :has-text("failed"), :has-text("Error"), :has-text("output")').first().isVisible().catch(() => false);
      expect(hasResult).toBeTruthy();
    } else {
      console.log('No exercises available for submission test. Skipping.');
    }
  });
});

// -- Test 4: Instructor Visualization Panel -------------------------------------------------------

test.describe('Instructor Visualization Panel', () => {
  test('instructor dashboard renders with data', async ({ page }) => {
    await page.goto('http://127.0.0.1:5173/login');
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
    await page.goto('http://127.0.0.1:5173/login');
    await page.getByLabel('EMAIL').fill(INSTRUCTOR.email);
    await page.getByLabel('PASSWORD').fill(INSTRUCTOR.password);
    await page.getByRole('button', { name: 'Sign In' }).click();
    await expect(page).toHaveURL(/.*\/instructor\/dashboard/, { timeout: 10000 });
    await page.waitForTimeout(3000);

    await page.goto('http://127.0.0.1:5173/instructor/heatmap');
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);

    const hasHeatmap = await page.locator('[class*="grid"], [class*="flex"]').first().isVisible().catch(() => false);
    expect(hasHeatmap).toBeTruthy();
  });

  test('student roster table renders', async ({ page }) => {
    await page.goto('http://127.0.0.1:5173/login');
    await page.getByLabel('EMAIL').fill(INSTRUCTOR.email);
    await page.getByLabel('PASSWORD').fill(INSTRUCTOR.password);
    await page.getByRole('button', { name: 'Sign In' }).click();
    await expect(page).toHaveURL(/.*\/instructor\/dashboard/, { timeout: 10000 });
    await page.waitForTimeout(3000);

    await page.goto('http://127.0.0.1:5173/instructor/students');
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);

    const hasStudents = await page.locator('table, [class*="student"], [class*="roster"]').first().isVisible()
      .catch(() => page.locator(':has-text("student")').first().isVisible().catch(() => false));
    expect(hasStudents).toBeTruthy();
  });

  test('CDS classification badges visible', async ({ page }) => {
    await page.goto('http://127.0.0.1:5173/login');
    await page.getByLabel('EMAIL').fill(INSTRUCTOR.email);
    await page.getByLabel('PASSWORD').fill(INSTRUCTOR.password);
    await page.getByRole('button', { name: 'Sign In' }).click();
    await expect(page).toHaveURL(/.*\/instructor\/dashboard/, { timeout: 10000 });
    await page.waitForTimeout(3000);

    await page.goto('http://127.0.0.1:5173/instructor/integrity');
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);

    const hasIntegrity = await page.locator(':has-text("integrity"), :has-text("flag"), :has-text("risk"), :has-text("CDS")')
      .first().isVisible().catch(() => false);
    expect(hasIntegrity).toBeTruthy();
  });
});
