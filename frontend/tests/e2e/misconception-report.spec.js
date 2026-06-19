import { test, expect } from '@playwright/test';

test.describe('Misconception Report', () => {
  test.use({ viewport: { width: 1280, height: 800 } });

  test('instructor sees detected misconception in exercise accordion', async ({ page }) => {
    await page.goto('/login');
    await page.fill('#email', 'instructor@psu.edu');
    await page.fill('#password', 'password123');
    await page.click('button[type="submit"]');
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

    // Verify a specific misconception is detected (exact match avoids multi-element)
    await expect(page.getByText('Undeclared Variable', { exact: true })).toBeVisible({ timeout: 5000 });

    // Verify empty state is NOT shown
    await expect(page.getByText('No misconception patterns detected.')).not.toBeVisible();
  });
});
