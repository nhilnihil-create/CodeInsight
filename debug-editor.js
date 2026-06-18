const { chromium } = require('playwright');
(async () => {
  const browser = await chromium.launch({ headless: false });
  const page = await browser.newPage();
  
  // Login
  await page.goto('http://localhost:5173/login');
  await page.waitForLoadState('networkidle');
  await page.fill('input[type="email"]', 'perfect-maria@workflow.test');
  await page.fill('input[type="password"]', 'test1234');
  await page.click('button[type="submit"]');
  await page.waitForTimeout(3000);
  console.log('Logged in, URL:', page.url());
  
  // Go to exercise
  await page.goto('http://localhost:5173/student/exercises/220');
  await page.waitForLoadState('networkidle');
  
  // Check immediately
  console.log('--- Immediate check ---');
  let hasMonaco = await page.evaluate(() => !!window.monaco).catch(() => false);
  let editorVis = await page.locator('.monaco-editor').isVisible({ timeout: 2000 }).catch(() => false);
  console.log(`window.monaco: ${hasMonaco}, .monaco-editor visible: ${editorVis}`);
  
  // Wait and recheck
  await page.waitForTimeout(3000);
  console.log('--- After 3s wait ---');
  hasMonaco = await page.evaluate(() => !!window.monaco).catch(() => false);
  editorVis = await page.locator('.monaco-editor').isVisible({ timeout: 2000 }).catch(() => false);
  console.log(`window.monaco: ${hasMonaco}, .monaco-editor visible: ${editorVis}`);
  
  // Check page URL
  console.log('URL:', page.url());
  
  // Check if we're on the right page
  const bodyText = await page.evaluate(() => document.body.innerText.substring(0, 200));
  console.log('Body text:', bodyText);
  
  // Screenshot
  await page.screenshot({ path: '/tmp/debug-editor.png', fullPage: true });
  
  await browser.close();
})();
