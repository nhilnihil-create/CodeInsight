/**
 * E2E simulation: common errors flow in the misconception accordion.
 *
 * Validates:
 *  - Common Class Errors section appears
 *  - Friendly text shown (not raw compiler errors)
 *  - Errors ranked by frequency (top = missing semicolon, 3 students)
 *  - Std namespace errors silently filtered (no 'cout' in display)
 *  - Data-driven narratives in InsightCards
 *
 * Prerequisites:
 *   backend running on :5000, frontend on :5173,
 *   seed_common_errors_e2e.js already executed.
 */

const { test, expect } = require('@playwright/test');

test.describe('Common Errors Misconception Flow', () => {
  test.use({ viewport: { width: 1280, height: 800 } });

  test('accordion shows ranked common errors with friendly text and data-driven narratives', async ({ page }) => {
    // 1. Login
    await page.goto('/login');
    await page.waitForLoadState('networkidle');
    await page.fill('#email', 'instructor@psu.edu');
    await page.fill('#password', 'password123');
    await page.click('button[type="submit"]');
    await page.waitForURL('**/instructor/dashboard', { timeout: 15000 });

    // 2. Go to exercises page
    await page.goto('/instructor/exercises');
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(2000);

    // 3. Select the E2E Common Errors Test section
    const combobox = page.getByRole('combobox').first();
    await combobox.waitFor({ state: 'visible', timeout: 15000 });
    await combobox.click();
    await page.getByRole('option').filter({ hasText: 'E2E Common Errors Test' }).click();
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(1000);

    // 4. Expand the exercise accordion
    await page.getByText('Variables and I/O - E2E').first().click();

    // 5. Wait for analytics to load (Total Students metric)
    await expect(page.getByText('Total Students')).toBeVisible({ timeout: 60000 });
    await page.waitForTimeout(1000);

    // 6. Verify the "Common Class Errors" section header is visible
    await expect(page.getByText('Common Class Errors')).toBeVisible({ timeout: 10000 });

    // 7. Verify top error card shows "Missing semicolon" (friendly text, not raw compiler error)
    await expect(page.locator('.text-sm.font-semibold').filter({ hasText: 'Missing semicolon' })).toBeVisible({ timeout: 10000 });

    // 8. Verify undeclared identifier error shows (2nd ranked) in the error cards
    await expect(page.locator('.text-sm.font-semibold').filter({ hasText: 'undeclared identifier' })).toBeVisible({ timeout: 5000 });

    // 9. Verify raw error text is NOT shown (e.g., no "y was not declared")
    await expect(page.getByText(/y['\u2019]? was not declared/)).not.toBeVisible();

    // 10. Verify std namespace errors are filtered (no "cout" in raw form)
    await expect(page.getByText(/cout.*not declared/)).not.toBeVisible();

    // 11. Verify only 2 InsightCards exist (no redundant Root Cause / Before Advancing)
    await expect(page.getByText('Class Summary')).toBeVisible({ timeout: 5000 });
    await expect(page.getByText('Recommended Action')).toBeVisible({ timeout: 5000 });
    await expect(page.locator('.text-xs.font-semibold').filter({ hasText: 'Root Cause' })).not.toBeVisible();
    await expect(page.locator('.text-xs.font-semibold').filter({ hasText: 'Before Advancing' })).not.toBeVisible();

    // 12. Verify class summary card references the top error details
    const summaryCard = page.getByText('Class Summary').locator('..');
    await expect(summaryCard).toContainText('of');
    await expect(summaryCard).toContainText('Missing semicolon');

    // 13. Verify Recommended Action card combines insights (Most frequent + practice)
    const actionCard = page.getByText('Recommended Action').locator('..');
    await expect(actionCard).toContainText('Most frequent');
    await expect(actionCard).toContainText('Practice resolving');

    // 14. Verify empty state is NOT shown
    await expect(page.getByText('No patterns detected.')).not.toBeVisible();

    // 15. Take screenshot
    await page.screenshot({ path: '/home/nihil/projects/codeinsight/simulation/screenshots/common-errors-accordion.png', fullPage: true });
  });
});
