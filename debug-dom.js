const { chromium } = require('playwright');
(async () => {
  const browser = await chromium.launch({ headless: false });
  const page = await browser.newPage();
  
  await page.goto('http://localhost:5173/login');
  await page.waitForLoadState('networkidle');
  await page.fill('input[type="email"]', 'perfect-maria@workflow.test');
  await page.fill('input[type="password"]', 'test1234');
  await page.click('button[type="submit"]');
  await page.waitForTimeout(3000);
  
  await page.goto('http://localhost:5173/student/exercises/220');
  await page.waitForLoadState('networkidle');
  await page.waitForTimeout(3000);
  
  // Check all elements with class containing 'monaco'
  const monacoEls = await page.evaluate(() => {
    const all = document.querySelectorAll('*');
    const results = [];
    for (const el of all) {
      if (el.className && typeof el.className === 'string' && el.className.toLowerCase().includes('monaco')) {
        const rect = el.getBoundingClientRect();
        results.push({
          tag: el.tagName,
          class: el.className.substring(0, 100),
          visible: rect.width > 0 && rect.height > 0,
          rect: { x: Math.round(rect.x), y: Math.round(rect.y), w: Math.round(rect.width), h: Math.round(rect.height) }
        });
      }
    }
    return results;
  });
  console.log('Monaco elements:', JSON.stringify(monacoEls, null, 2));
  
  // Try the actual Monaco API to set value
  const result = await page.evaluate(() => {
    try {
      const models = window.monaco.editor.getModels();
      if (models.length === 0) return 'No models';
      models[0].setValue('test code here');
      return 'Set value OK: ' + models[0].getValue();
    } catch(e) { return 'Error: ' + e.message; }
  });
  console.log('Monaco setValue:', result);
  
  // Now check if the submit button works
  const submitBtn = page.locator('button').filter({ hasText: /submit/i }).first();
  const submitVis = await submitBtn.isVisible().catch(() => false);
  console.log('Submit button visible:', submitVis);
  
  // Check for terminal/console output
  const terminal = await page.evaluate(() => {
    const term = document.querySelector('[class*="terminal"], [class*="Terminal"], [class*="output"], [class*="Output"]');
    return term ? term.innerText.substring(0, 200) : 'no terminal found';
  });
  console.log('Terminal:', terminal);
  
  await browser.close();
})();
