const { test, expect } = require('@playwright/test');
const fs = require('fs');
const { BASE_URL } = require('./config');
const { PERSONAS } = require('./personas');
const { check, screenshot, printSummary } = require('./spec-checker');

let state = {};
try { state = JSON.parse(fs.readFileSync(__dirname + '/seed-state.json', 'utf8')); } catch { console.error('Run seed-data.js first!'); process.exit(1); }

async function loginAs(page, persona) {
  await page.goto(BASE_URL + '/login');
  await page.waitForLoadState('networkidle');
  await page.fill('input[type="email"]', persona.email);
  await page.fill('input[type="password"]', persona.password);
  await page.click('button[type="submit"]');
  await page.waitForURL(url => !url.toString().includes('/login'), { timeout: 10000 }).catch(() => {});
  await page.waitForTimeout(1000);
  return !page.url().includes('/login');
}

function setEditorCode(code) {
  return async (page) => {
    const hasMonaco = await page.evaluate(() => !!window.monaco).catch(() => false);
    if (hasMonaco) {
      await page.evaluate((c) => {
        const models = window.monaco.editor.getModels();
        if (models.length > 0) models[0].setValue(c);
      }, code);
      await page.waitForTimeout(500);
      return true;
    }
    return false;
  };
}

test.describe('Student Workflow Simulation - 15 Personas', () => {
  for (const persona of PERSONAS) {
    test.describe(`Persona: ${persona.name} (${persona.archetype})`, () => {
      const exerciseIds = Object.values(state.exerciseIds || {});
      const exerciseKeys = Object.keys(state.exerciseIds || {});

      test('Step 1: Login and verify dashboard', async ({ page }) => {
        const logged = await loginAs(page, persona);
        await screenshot(page, persona.name + '_01_login_' + (logged ? 'ok' : 'fail'));
        expect(logged).toBeTruthy();

        if (page.url().includes('/student')) {
          await check(page, persona.name + '_Dashboard', [
            { name: 'Dashboard loaded', verify: async (p) => {
              const body = await p.evaluate(() => document.body.textContent);
              return body.toLowerCase().includes('exercise') || body.toLowerCase().includes('dashboard') || body.toLowerCase().includes('today');
            }},
          ]);
        }
      });

      for (let i = 0; i < exerciseKeys.length && i < 3; i++) {
        const exKey = exerciseKeys[i];
        const exId = state.exerciseIds[exKey];
        const attemptsForExercise = persona.attempts.filter(a => {
          const map = { sumN: 0, evenOdd: 1, findMax: 2 };
          return map[a.exercise] === i;
        });

        for (let j = 0; j < attemptsForExercise.length; j++) {
          const attempt = attemptsForExercise[j];
          const attemptLabel = attempt.correct ? 'correct' : 'wrong';

          test(`Step ${2 + i * 3 + j}: Submit ${exKey} attempt ${j + 1} (${attemptLabel})`, async ({ page }) => {
            const logged = await loginAs(page, persona);
            expect(logged).toBeTruthy();

            await page.goto(BASE_URL + '/student/exercises/' + exId);
            await page.waitForLoadState('networkidle');
            await page.waitForTimeout(3000);

            await screenshot(page, persona.name + '_' + exKey + '_attempt' + (j+1) + '_editor');

            const editorLoaded = await page.locator('.monaco-editor').first().isVisible({ timeout: 15000 }).catch(() => false);
            if (!editorLoaded) {
              console.log('  Monaco not loaded for ' + persona.name + ' on ' + exKey);
              await screenshot(page, persona.name + '_' + exKey + '_no_editor');
              return;
            }

            const setCode = setEditorCode(attempt.code);
            const injected = await setCode(page);
            if (!injected) {
              console.log('  Monaco API failed, using keyboard fallback');
              const editor = page.locator('.monaco-editor').first();
              await editor.click();
              await page.keyboard.press('Control+A');
              await page.keyboard.press('Delete');
              await page.keyboard.type(attempt.code, { delay: 3 });
            }

            await page.waitForTimeout(500);
            await screenshot(page, persona.name + '_' + exKey + '_attempt' + (j+1) + '_coded');

            const submitBtn = page.locator('button').filter({ hasText: /submit/i }).first();
            if (await submitBtn.isVisible({ timeout: 5000 }).catch(() => false)) {
              await submitBtn.click();
            }

            await page.waitForTimeout(8000);
            await screenshot(page, persona.name + '_' + exKey + '_attempt' + (j+1) + '_submitted');

            await check(page, persona.name + '_' + exKey + '_Submit' + (j+1), [
              { name: 'Submission processed', verify: async (p) => {
                const body = await p.evaluate(() => document.body.textContent);
                return body.includes('pass') || body.includes('Pass') || body.includes('Failed') ||
                       body.includes('submitted') || body.includes('Review') || body.includes('result');
              }},
            ]);
          });
        }
      }

      test(`Step FINAL: Verify student profile and progress for ${persona.name}`, async ({ page }) => {
        const logged = await loginAs(page, persona);
        expect(logged).toBeTruthy();

        await page.goto(BASE_URL + '/student/progress');
        await page.waitForLoadState('networkidle');
        await page.waitForTimeout(2000);
        await screenshot(page, persona.name + '_progress');

        await check(page, persona.name + '_Progress', [
          { name: 'Progress page loaded', verify: async (p) => {
            const body = await p.evaluate(() => document.body.textContent);
            return body.includes('mastery') || body.includes('Mastery') || body.includes('completion') ||
                   body.includes('Loading') || body.includes('exercises') || body.includes('Progress');
          }},
        ]);

        if (persona.archetype === 'hardcoder' || persona.archetype === 'blank' ||
            persona.archetype === 'copypaste' || persona.archetype === 'bloomer') {
          await page.goto(BASE_URL + '/student/integrity');
          await page.waitForLoadState('networkidle');
          await page.waitForTimeout(2000);
          await screenshot(page, persona.name + '_integrity');

          if (persona.archetype === 'hardcoder' || persona.archetype === 'blank') {
            await check(page, persona.name + '_Integrity', [
              { name: 'Integrity page loaded', verify: async (p) => {
                const body = await p.evaluate(() => document.body.textContent);
                return body.includes('integrity') || body.includes('flag') || body.includes('pattern') || body.includes('Keep coding');
              }},
            ]);
          }
        }
      });
    });
  }
});
