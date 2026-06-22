const { chromium } = require('playwright');
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
  // 10: Correct
  { id: '10', code: null },
];

const EXERCISE_ID = 245;

async function sleep(ms) {
  return new Promise(r => setTimeout(r, ms));
}

async function setMonacoContent(page, code) {
  // Set Monaco model content programmatically
  const result = await page.evaluate((newCode) => {
    const models = window.monaco?.editor?.getModels();
    if (models && models.length > 0) {
      models[0].setValue(newCode);
      return true;
    }
    return false;
  }, code);
  return result;
}

async function run() {
  const browser = await chromium.launch({ headless: false });
  const context = await browser.newContext({ ignoreHTTPSErrors: true });

  // === PHASE 1: Submit for all 10 students ===
  for (const s of STUDENTS) {
    const page = await context.newPage();
    const email = `student${s.id}@test.edu`;
    console.log(`[${new Date().toISOString()}] === Student ${s.id} (${email}) ===`);

    // Login
    await page.goto(`${BASE}/login`, { waitUntil: 'networkidle' });
    await page.waitForSelector('input[placeholder="your@email.com"]', { timeout: 10000 });
    await page.fill('input[placeholder="your@email.com"]', email);
    await page.fill('input[type="password"]', 'password123');
    await page.getByRole('button', { name: 'Sign In' }).click();
    await page.waitForURL(/dashboard/, { timeout: 15000 });
    console.log(`  Logged in`);

    // Navigate to exercise
    await page.goto(`${BASE}/student/exercises/${EXERCISE_ID}`, { waitUntil: 'networkidle' });
    await page.waitForSelector('.monaco-editor', { timeout: 15000 });
    await page.waitForTimeout(2000);

    if (s.code !== null) {
      console.log(`  Setting code (${s.code.length} chars)`);
      const ok = await setMonacoContent(page, s.code);
      console.log(`  Monaco setValue returned: ${ok}`);
      
      // Verify the code was actually updated
      const currentValue = await page.evaluate(() => {
        const models = window.monaco?.editor?.getModels();
        return models ? models[0].getValue() : null;
      });
      console.log(`  Editor content preview: ${(currentValue || '').substring(0, 60).replace(/\n/g, '\\n')}`);
      
      await page.waitForTimeout(1000);
    } else {
      console.log(`  Keeping default code`);
    }

    // Check Submit button
    const submitBtn = page.getByRole('button', { name: 'Submit' });
    const exists = await submitBtn.isVisible().catch(() => false);
    if (!exists) {
      // Might be in "Review Mode" - try to find Reset or just snapshot page
      const ptext = await page.locator('body').innerText();
      console.log(`  Submit not found! Page contains "Review Mode": ${ptext.includes('Review Mode')}`);
      // Check if already submitted
      const subCount = await page.locator('.submissions-panel, [class*="submission"]').innerText().catch(() => '');
      console.log(`  Submissions panel: ${subCount.substring(0, 200)}`);
      await page.close();
      continue;
    }
    console.log(`  Submitting...`);
    await submitBtn.click();
    await sleep(8000);
    console.log(`  Done`);

    await page.close();
  }

  // === PHASE 2: Instructor check ===
  console.log(`[${new Date().toISOString()}] === Instructor check ===`);
  const page = await context.newPage();
  
  // Clear session
  await context.clearCookies();
  await page.goto(`${BASE}/login`, { waitUntil: 'networkidle' });
  await page.evaluate(() => localStorage.clear());
  await page.goto(`${BASE}/login`, { waitUntil: 'networkidle' });
  
  await page.waitForSelector('input[placeholder="your@email.com"]', { timeout: 10000 });
  await page.fill('input[placeholder="your@email.com"]', 'instructor@psu.edu');
  await page.fill('input[type="password"]', 'password123');
  await page.getByRole('button', { name: 'Sign In' }).click();
  await page.waitForURL(/instructor/, { timeout: 15000 });
  console.log(`  Instructor URL: ${page.url()}`);

  await page.goto(`${BASE}/instructor/exercises`, { waitUntil: 'networkidle' });
  await sleep(3000);
  
  // Select section
  const select = page.locator('select').first();
  if (await select.isVisible().catch(() => false)) {
    await select.selectOption({ label: 'E2E 10 Student Test' });
    await sleep(3000);
  }

  // Click the row to expand the accordion
  console.log('  Clicking row to expand accordion...');
  const exerciseRow = page.locator('table tr').filter({ hasText: 'E2E Variables Test' }).first();
  const rowBox = await exerciseRow.boundingBox();
  if (rowBox) {
    // Click in the middle of the row, offset to the left side (away from action buttons)
    await page.mouse.click(rowBox.x + 50, rowBox.y + rowBox.height / 2);
    console.log('  Clicked row');
  } else {
    console.log('  Row not found, trying text click');
    await page.getByText('E2E Variables Test').first().click();
  }
  await sleep(5000);
  
  const bodyText = await page.locator('body').innerText();
  console.log('=== INSTRUCTOR PAGE AFTER CLICK ===');
  console.log(bodyText);

  // Save full HTML for debugging
  const html = await page.content();
  const fs = require('fs');
  fs.writeFileSync('/tmp/e2e_result.html', html);
  console.log('HTML saved to /tmp/e2e_result.html');
  
  await browser.close();
}

run().catch(err => { console.error('FATAL:', err); process.exit(1); });
