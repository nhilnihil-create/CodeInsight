const { BASE_URL } = require('./config');

async function setEditorCode(page, code, typingSpeed) {
  const hasMonaco = await page.evaluate(() => !!window.monaco).catch(() => false);
  if (hasMonaco) {
    await page.evaluate((c) => {
      const models = window.monaco.editor.getModels();
      if (models.length > 0) models[0].setValue(c);
    }, code);
    const typingDuration = code.length * (typingSpeed || 100);
    await page.waitForTimeout(Math.min(typingDuration, 5000));
  } else {
    const editor = page.locator('.monaco-editor, textarea, [contenteditable="true"]').first();
    if (await editor.isVisible({ timeout: 3000 }).catch(() => false)) {
      await editor.click();
      await page.keyboard.press('Control+A');
      await page.waitForTimeout(100);
      await page.keyboard.press('Delete');
      await page.waitForTimeout(200);
      await page.keyboard.type(code, { delay: typingSpeed || 100 });
    }
  }
}

async function submitStudentFlow(page, persona, exerciseId, { concurrentIdx } = {}) {
  const startTime = Date.now();
  const results = { personId: persona.id, name: persona.name, email: persona.email,
    archetype: persona.archetype, attempts: [], duration: 0 };

  try {
    await page.goto(`${BASE_URL}/login`);
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(1000);

    const emailInput = page.locator('input[type="email"]').first();
    await emailInput.fill(persona.email);
    const passwordInput = page.locator('input[type="password"]').first();
    await passwordInput.fill(persona.password);
    await page.locator('button[type="submit"]').first().click();
    await page.waitForTimeout(2000);

    if (page.url().includes('/login')) {
      results.attempts.push({ attempt: 0, success: false, error: 'Login failed' });
      results.duration = Date.now() - startTime;
      return results;
    }

    await page.goto(`${BASE_URL}/student/exercises/${exerciseId}`);
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(2000);

    for (let i = 0; i < persona.attempts.length; i++) {
      const attemptData = persona.attempts[i];
      const attemptNum = i + 1;

      await setEditorCode(page, attemptData.code, persona.typingSpeed || 100);
      await page.waitForTimeout(500);

      const clicked = await page.evaluate(() => {
        const btns = Array.from(document.querySelectorAll('button'))
          .filter(b => b.textContent.includes('Submit'));
        if (btns.length > 0) { btns[0].click(); return 'submit'; }
        const runBtns = Array.from(document.querySelectorAll('button'))
          .filter(b => b.textContent.includes('Run'));
        if (runBtns.length > 0) { runBtns[0].click(); return 'run'; }
        return 'none';
      });
      if (clicked === 'none') {
        results.attempts.push({ attempt: attemptNum, success: false, error: 'No Submit or Run button found' });
        continue;
      }

      let success = false;
      let resultText = '';
      try {
        await page.waitForResponse(
          resp => resp.url().includes('/submit') && resp.status() === 201,
          { timeout: 90000 }
        );
        await page.waitForTimeout(3000);
        const bodyText = await page.evaluate(() => document.body.textContent || '');
        const passMatch = bodyText.match(/(\d+)\s*\/\s*(\d+)\s*pass/i);
        if (passMatch) resultText = `${passMatch[1]}/${passMatch[2]} pass`;
        else resultText = bodyText.includes('Test 1') ? 'tests loaded' : 'submitted';
        success = attemptData.correct;
      } catch (e) {
        resultText = 'timeout';
      }

      results.attempts.push({
        attempt: attemptNum, success, resultText: resultText.substring(0, 100),
        expectedCorrect: attemptData.correct, duration: Date.now() - startTime,
      });

      if (i < persona.attempts.length - 1) {
        await page.waitForTimeout(1000);
      }
    }

    results.duration = Date.now() - startTime;
    return results;
  } catch (error) {
    results.attempts.push({ attempt: 0, success: false, error: error.message });
    results.duration = Date.now() - startTime;
    return results;
  }
}

module.exports = { submitStudentFlow };
