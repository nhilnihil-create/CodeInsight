import { test, expect } from '@playwright/test';

test.describe('Misconception Report', () => {
  test.use({ viewport: { width: 1280, height: 800 } });

  test('instructor sees detected misconception in exercise accordion', async ({ page }) => {
    await page.goto('/login');
    await page.fill('#email', 'instructor@psu.edu');
    await page.fill('#password', 'password123');
    // Submit via Enter (native form submit) — WebKit mobile taps on the
    // submit button never stabilize under Playwright's iPhone emulation.
    await page.keyboard.press('Enter');
    await page.waitForURL('**/instructor/dashboard', { timeout: 10000 });

    await page.goto('/instructor/exercises');
    await page.waitForLoadState('networkidle');

    // Open section filter and select E2E section
    const combobox = page.getByRole('combobox').first();
    await combobox.waitFor({ state: 'visible', timeout: 10000 });
    await combobox.click();
    await page.getByRole('option').filter({ hasText: 'E2E Misconception Test' }).click();
    await page.waitForLoadState('networkidle');

    // Expand the exercise accordion
    await page.getByText('Variables Practice - E2E').first().click();

    // Wait for analytics to load and verify report shows data
    await expect(page.getByText('Total Students')).toBeVisible({ timeout: 30000 });

    // Verify the undeclared-identifier error is detected. The report renders the
    // friendly copy under "Common Class Errors" (not the taxonomy name). The
    // phrase appears in the card and the recommended-action summary, so scope
    // to the first match.
    await expect(page.getByText('Using an undeclared identifier', { exact: false }).first()).toBeVisible({ timeout: 5000 });

    // Verify empty state is NOT shown
    await expect(page.getByText('No misconception patterns detected.')).not.toBeVisible();
  });
});
