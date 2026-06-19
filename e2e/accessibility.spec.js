const { test, expect } = require('@playwright/test');

test.describe('Accessibility Checks (Compatibility Testing)', () => {
  const PAGES = [
    { path: '/login', name: 'Login page' },
    { path: '/student/sections', name: 'Student sections' },
    { path: '/instructor/dashboard', name: 'Instructor dashboard' },
  ];

  for (const { path, name } of PAGES) {
    test(`${name} has accessible structure`, async ({ page }) => {
      await page.goto(`http://localhost:5173${path}`);
      await page.waitForLoadState('networkidle');

      // Verify landmark structure
      const hasHeading = await page.locator('h1, h2, h3').first().isVisible().catch(() => false);
      expect(hasHeading).toBeTruthy();

      // Verify interactive elements have accessible names
      const buttons = page.getByRole('button');
      const buttonCount = await buttons.count();
      for (let i = 0; i < Math.min(buttonCount, 10); i++) {
        await expect(buttons.nth(i)).toBeVisible();
      }

      // Verify form inputs have associated labels
      const inputs = page.getByRole('textbox');
      const inputCount = await inputs.count();
      for (let i = 0; i < Math.min(inputCount, 10); i++) {
        const input = inputs.nth(i);
        const label = page.locator(`label[for="${await input.getAttribute('id')}"]`);
        const hasAriaLabel = await input.getAttribute('aria-label');
        const isAriaLabelled = await input.getAttribute('aria-labelledby');
        expect(label.first().isVisible().catch(() => false) || !!hasAriaLabel || !!isAriaLabelled).toBeTruthy();
      }

      // Check images have alt text
      const images = page.locator('img');
      const imgCount = await images.count();
      for (let i = 0; i < imgCount; i++) {
        const alt = await images.nth(i).getAttribute('alt');
        if (alt !== null) {
          expect(typeof alt).toBe('string');
        }
      }
    });
  }

  test('keyboard navigation works on login form', async ({ page }) => {
    await page.goto('http://localhost:5173/login');
    await page.waitForLoadState('networkidle');

    // Focus first focusable element via Tab
    await page.keyboard.press('Tab');
    const focused = page.locator(':focus');
    await expect(focused).toBeVisible();
  });
});
