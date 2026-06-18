const path = require('path');
const SCREENSHOT_DIR = path.join(__dirname, 'screenshots');
let screenshotIdx = 0;
const mismatches = [];
async function screenshot(page, label) {
  screenshotIdx++;
  const fp = path.join(SCREENSHOT_DIR, String(screenshotIdx).padStart(3, '0') + '_' + label.replace(/[^a-zA-Z0-9_-]/g, '_') + '.png');
  try { await page.screenshot({ path: fp, fullPage: false }); } catch(e) {}
  return fp;
}
async function check(page, stepName, checks) {
  const results = [];
  for (const c of checks) {
    try {
      let passed = false, detail = '';
      if (typeof c.verify === 'function') { passed = await c.verify(page); detail = c.description || ''; }
      else if (c.selector) { const v = await page.locator(c.selector).first().isVisible({ timeout: c.timeout || 5000 }).catch(() => false); passed = v; detail = c.selector + (v ? ' visible' : ' not visible'); }
      else if (c.text) { const f = await page.getByText(c.text, { exact: false }).first().isVisible({ timeout: c.timeout || 5000 }).catch(() => false); passed = f; detail = c.text + (f ? ' found' : ' not found'); }
      results.push({ name: c.name || 'unnamed', passed, detail });
      if (!passed) mismatches.push({ step: stepName, check: c.name || 'unnamed', detail });
    } catch (e) { results.push({ name: c.name || 'unnamed', passed: false, detail: e.message }); mismatches.push({ step: stepName, check: c.name || 'unnamed', detail: e.message }); }
  }
  return results;
}
function printSummary() {
  console.log('\n' + '='.repeat(60));
  console.log('SPEC CHECKER: ' + mismatches.length + ' mismatches');
  console.log('='.repeat(60));
  if (mismatches.length === 0) console.log('All checks passed!');
  else { const bs = {}; mismatches.forEach(m => { if (!bs[m.step]) bs[m.step] = []; bs[m.step].push(m); }); Object.entries(bs).forEach(([s, items]) => { console.log('[' + s + ']'); items.forEach(m => console.log('  - ' + m.check + ': ' + m.detail)); }); }
  console.log('='.repeat(60));
}
module.exports = { check, screenshot, getMismatches: () => mismatches, printSummary };
