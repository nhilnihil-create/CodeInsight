/**
 * simulation/stagehand/workflows/exercises.js
 *
 * Exercise submission workflow test using Playwright.
 */

const { createBrowser, login, navigateTo, PERSONAS } = require('../config');

async function testExerciseSubmission() {
  const { browser, page } = await createBrowser();
  const steps = [];
  const student = PERSONAS.students[0];

  try {
    // Login as student
    await login(page, student.email, student.password);
    steps.push({ action: 'Login', success: true });

    // Navigate to exercises
    await navigateTo(page, '/student/exercises');
    steps.push({ action: 'Navigate to exercises', success: true });

    // Click first exercise link
    const exerciseLink = page.locator('a[href*="/student/exercises/"]').first();
    if (await exerciseLink.isVisible({ timeout: 5000 })) {
      await exerciseLink.click();
      await page.waitForLoadState('networkidle');
      await page.waitForTimeout(3000);
      steps.push({ action: 'Select exercise', success: true });

      // Check for code editor (Monaco)
      const hasEditor = await page.locator('.monaco-editor').isVisible({ timeout: 5000 }).catch(() => false);
      if (hasEditor) {
        steps.push({ action: 'Code editor loaded', success: true });

        // Inject code via Monaco API
        await page.evaluate(() => {
          if (window.monaco) {
            const models = window.monaco.editor.getModels();
            if (models.length > 0) {
              models[0].setValue('#include <iostream>\nusing namespace std;\nint main() { cout << 42; return 0; }');
            }
          }
        });
        steps.push({ action: 'Inject code', success: true });

        // Click Run button
        const runBtn = page.locator('button:has-text("Run"), button:has-text("Submit")').first();
        if (await runBtn.isVisible({ timeout: 3000 })) {
          await runBtn.click();
          await page.waitForTimeout(5000);
          steps.push({ action: 'Run code', success: true });
        } else {
          steps.push({ action: 'Run button not found', success: false });
        }

        return { passed: true, steps };
      } else {
        steps.push({ action: 'No code editor found', success: false });
        return { passed: false, steps };
      }
    } else {
      steps.push({ action: 'No exercises available', success: false });
      return { passed: false, steps };
    }
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await browser.close();
  }
}

module.exports = { testExerciseSubmission };
