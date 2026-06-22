const { test, expect } = require('@playwright/test');

const BASE = 'http://localhost:5173';

const STUDENTS = [
  // 01-04: Missing semicolon
  { id: '01', code: '#include <iostream>\nusing namespace std;\nint main() {\n  int x = 5\n  cout << x;\n  return 0;\n}' },
  { id: '02', code: '#include <iostream>\nusing namespace std;\nint main() {\n  int x = 5\n  cout << x;\n  return 0;\n}' },
  { id: '03', code: '#include <iostream>\nusing namespace std;\nint main() {\n  int x = 5\n  cout << x;\n  return 0;\n}' },
  { id: '04', code: '#include <iostream>\nusing namespace std;\nint main() {\n  int x = 5\n  cout << x;\n  return 0;\n}' },
  // 05-07: Undeclared variable y
  { id: '05', code: '#include <iostream>\nusing namespace std;\nint main() {\n  int x = 5;\n  y = x + 10;\n  cout << y;\n  return 0;\n}' },
  { id: '06', code: '#include <iostream>\nusing namespace std;\nint main() {\n  int x = 5;\n  y = x + 10;\n  cout << y;\n  return 0;\n}' },
  { id: '07', code: '#include <iostream>\nusing namespace std;\nint main() {\n  int x = 5;\n  y = x + 10;\n  cout << y;\n  return 0;\n}' },
  // 08-09: Missing closing brace
  { id: '08', code: '#include <iostream>\nusing namespace std;\nint main() {\n  int x = 5;\n  cout << x;\n  return 0;' },
  { id: '09', code: '#include <iostream>\nusing namespace std;\nint main() {\n  int x = 5;\n  cout << x;\n  return 0;' },
  // 10: Correct (no change)
  { id: '10', code: null },
];

const EXERCISE_ID = 244;

test.describe('10-Student Full Pipeline E2E', () => {
  test('students submit code with compiler errors, instructor verifies accordion', async ({ context }) => {
    test.setTimeout(600000); // 10 minutes

    for (const s of STUDENTS) {
      const page = await context.newPage();
      const email = `student${s.id}@test.edu`;
      console.log(`[${new Date().toISOString()}] === Student ${s.id} (${email}) ===`);

      // Clear session for clean login
      await page.context().clearCookies();
      await page.evaluate(() => localStorage.clear());
      await page.goto(`${BASE}/login`, { waitUntil: 'networkidle' });
      await page.waitForSelector('input[placeholder="your@email.com"]', { timeout: 15000 });
      await page.fill('input[placeholder="your@email.com"]', email);
      await page.fill('input[type="password"]', 'password123');
      await page.getByRole('button', { name: 'Sign In' }).click();
      await page.waitForURL(/dashboard/, { timeout: 15000 });
      console.log(`[${new Date().toISOString()}] Logged in as ${email}`);

      // Navigate to exercise
      await page.goto(`${BASE}/student/exercises/${EXERCISE_ID}`, { waitUntil: 'networkidle' });
      await page.waitForSelector('.monaco-editor', { timeout: 15000 });
      await page.waitForTimeout(2000); // Let Monaco fully boot

      if (s.code !== null) {
        console.log(`[${new Date().toISOString()}] Typing code (${s.code.length} chars)`);
        const monacoTA = page.locator('.monaco-editor textarea').first();
        await monacoTA.focus();
        await page.waitForTimeout(500);
        await page.keyboard.press('Control+a');
        await page.waitForTimeout(300);
        await page.keyboard.press('Delete');
        await page.waitForTimeout(300);
        await page.keyboard.type(s.code, { delay: 20 });
        await page.waitForTimeout(500);
        console.log(`[${new Date().toISOString()}] Code typed`);
      } else {
        console.log(`[${new Date().toISOString()}] Keeping default code`);
        await page.waitForTimeout(1000);
      }

      // Submit
      console.log(`[${new Date().toISOString()}] Clicking Submit`);
      await page.getByRole('button', { name: 'Submit' }).click();
      await page.waitForTimeout(8000); // Wait for compilation + toast
      console.log(`[${new Date().toISOString()}] Submitted`);

      await page.close();
    }

    // ===== PHASE 2: Instructor check =====
    console.log(`[${new Date().toISOString()}] === Instructor check ===`);
    const page = await context.newPage();
    await page.goto(`${BASE}/login`, { waitUntil: 'networkidle' });
    await page.waitForSelector('input[placeholder="your@email.com"]', { timeout: 15000 });
    await page.fill('input[placeholder="your@email.com"]', 'instructor@psu.edu');
    await page.fill('input[type="password"]', 'password123');
    await page.getByRole('button', { name: 'Sign In' }).click();
    await page.waitForURL(/\/instructor/, { timeout: 15000 });

    // Navigate to exercises page
    await page.goto(`${BASE}/instructor/exercises`, { waitUntil: 'networkidle' });
    await page.waitForTimeout(3000);

    // Select the E2E section from dropdown
    const sectionSelect = page.locator('select').first();
    if (await sectionSelect.isVisible({ timeout: 5000 }).catch(() => false)) {
      await sectionSelect.selectOption({ label: 'E2E 10 Student Test' });
      await page.waitForTimeout(3000);
    }

    // Get all text from the page for inspection
    const bodyText = await page.locator('body').innerText();
    console.log('=== PAGE TEXT (first 8000 chars) ===');
    console.log(bodyText.substring(0, 8000));
    console.log('=== END PAGE TEXT ===');

    // Verify common errors in the accordion
    // Expected: "Missing semicolon" ranked #1 with highest count
    const hasMissingSemicolon = bodyText.includes('Missing semicolon');
    const hasUndeclaredIdent = bodyText.includes('Undeclared identifier');
    const hasMissingBrace = bodyText.includes('Missing closing');

    console.log(`Missing semicolon visible: ${hasMissingSemicolon}`);
    console.log(`Undeclared identifier visible: ${hasMissingUndeclared}`);
    console.log(`Missing brace visible: ${hasMissingBrace}`);

    // If the accordion exists, try to expand it
    const exerciseHeading = page.getByText('E2E Variables Test').first();
    if (await exerciseHeading.isVisible({ timeout: 5000 }).catch(() => false)) {
      await exerciseHeading.click();
      await page.waitForTimeout(2000);
      const expandedText = await page.locator('body').innerText();
      console.log('=== EXPANDED TEXT ===');
      console.log(expandedText);
    } else {
      console.log('Exercise heading not found — accordion may not be rendered');
      // Try refreshing with refresh=true
      await page.goto(`${BASE}/instructor/exercises?refresh=true`, { waitUntil: 'networkidle' });
      await page.waitForTimeout(3000);
      const refreshText = await page.locator('body').innerText();
      console.log('=== AFTER REFRESH ===');
      console.log(refreshText.substring(0, 5000));
    }

    await page.close();
  });
});
