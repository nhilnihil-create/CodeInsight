const { test, expect } = require('@playwright/test');
const BASE = 'http://localhost:5173';

test('quick smoke test - student login + submit + instructor verify', async ({ page }) => {
  test.setTimeout(120000);

  // Login as student 01
  await page.goto(`${BASE}/login`, { waitUntil: 'networkidle' });
  await page.waitForSelector('input[placeholder="your@email.com"]', { timeout: 10000 });
  await page.fill('input[placeholder="your@email.com"]', 'student01@test.edu');
  await page.fill('input[type="password"]', 'password123');
  await page.getByRole('button', { name: 'Sign In' }).click();
  await page.waitForURL(/dashboard/, { timeout: 15000 });
  console.log('Login OK - URL:', page.url());

  // Go to exercise
  await page.goto(`${BASE}/student/exercises/245`, { waitUntil: 'networkidle' });
  const editorVisible = await page.waitForSelector('.monaco-editor', { timeout: 15000 }).then(() => true).catch(() => false);
  console.log(`Editor visible: ${editorVisible}`);

  // Check page title and key content
  const bodyText = await page.locator('body').innerText();
  console.log('Page body (first 2000):', bodyText.substring(0, 2000));

  // Type code with missing semicolon via Monaco's hidden textarea
  const monacoTextarea = page.locator('.monaco-editor textarea').first();
  const taFound = await monacoTextarea.isVisible().catch(() => false);
  console.log(`Monaco textarea visible: ${taFound}`);

  if (taFound) {
    await monacoTextarea.focus();
    await page.waitForTimeout(500);
    await page.keyboard.press('Control+a');
    await page.waitForTimeout(200);
    await page.keyboard.press('Delete');
    await page.waitForTimeout(200);
    await page.keyboard.type('#include <iostream>\nusing namespace std;\nint main() {\n  int x = 5\n  cout << x;\n  return 0;\n}', { delay: 20 });
    await page.waitForTimeout(500);
    console.log('Code typed');
  } else {
    // Fallback: use evaluate to set Monaco content directly
    console.log('Trying evaluate fallback');
    await page.evaluate(() => {
      const editor = document.querySelector('.monaco-editor');
      if (editor) {
        // Try to access Monaco model
        const textarea = editor.querySelector('textarea');
        if (textarea) {
          const nativeInputValueSetter = Object.getOwnPropertyDescriptor(window.HTMLTextAreaElement.prototype, 'value').set;
          nativeInputValueSetter.call(textarea, '#include <iostream>\nusing namespace std;\nint main() {\n  int x = 5\n  cout << x;\n  return 0;\n}');
          textarea.dispatchEvent(new Event('input', { bubbles: true }));
        }
      }
    });
    await page.waitForTimeout(500);
    console.log('Evaluate fallback done');
  }

  // Check Submit button
  const submitBtn = page.getByRole('button', { name: 'Submit' });
  const submitFound = await submitBtn.isVisible().catch(() => false);
  console.log(`Submit button visible: ${submitFound}`);

  if (submitFound) {
    await submitBtn.click();
    console.log('Clicked Submit, waiting...');
    await page.waitForTimeout(8000);
    console.log('Wait complete');

    // Check for toast or submission panel update
    const afterText = await page.locator('body').innerText();
    console.log('After submission (first 3000):', afterText.substring(0, 3000));
  }

  // Clear session for instructor login
  await page.context().clearCookies();
  await page.evaluate(() => localStorage.clear());
  await page.goto(`${BASE}/login`, { waitUntil: 'networkidle' });
  await page.waitForSelector('input[placeholder="your@email.com"]', { timeout: 10000 });
  await page.fill('input[placeholder="your@email.com"]', 'instructor@psu.edu');
  await page.fill('input[type="password"]', 'password123');
  await page.getByRole('button', { name: 'Sign In' }).click();
  await page.waitForURL(/instructor/, { timeout: 15000 });
  console.log('Instructor login OK - URL:', page.url());

  await page.goto(`${BASE}/instructor/exercises`, { waitUntil: 'networkidle' });
  await page.waitForTimeout(3000);

  const instructorText = await page.locator('body').innerText();
  console.log('=== INSTRUCTOR EXERCISES PAGE ===');
  console.log(instructorText.substring(0, 5000));
});
