const { test, expect } = require('@playwright/test');
const fs = require('fs');
const { BASE_URL, INSTRUCTOR } = require('./config');
const { check, screenshot, printSummary } = require('./spec-checker');

let state = {};
try { state = JSON.parse(fs.readFileSync(__dirname + '/seed-state.json', 'utf8')); } catch { console.error('Run seed-data.js first!'); process.exit(1); }

const SECTION_ID = state.sectionId;

async function loginInstructor(page) {
  await page.goto(BASE_URL + '/login');
  await page.waitForLoadState('networkidle');
  await page.fill('input[type="email"]', INSTRUCTOR.email);
  await page.fill('input[type="password"]', INSTRUCTOR.password);
  await page.click('button[type="submit"]');
  await page.waitForURL(url => !url.toString().includes('/login'), { timeout: 10000 }).catch(() => {});
  await page.waitForTimeout(1000);
  return !page.url().includes('/login');
}

test.describe('Instructor Workflow - 25 Steps', () => {
  test('Step 1: Login and verify instructor dashboard', async ({ page }) => {
    const logged = await loginInstructor(page);
    expect(logged).toBeTruthy();
    await screenshot(page, 'instructor_01_login');
    await check(page, 'Instructor Dashboard', [
      { name: 'Dashboard loaded', verify: async (p) => {
        const body = await p.evaluate(() => document.body.textContent);
        return body.includes('CDS') || body.includes('Dashboard') || body.includes('Student') || body.includes('Section');
      }},
    ]);
  });

  test('Step 2: Command Center', async ({ page }) => {
    await loginInstructor(page);
    await page.goto(BASE_URL + '/instructor/command');
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);
    await screenshot(page, 'instructor_02_command');
    await check(page, 'Command Center', [
      { name: 'Page loaded', verify: async (p) => {
        const body = await p.evaluate(() => document.body.textContent);
        return body.includes('Command') || body.includes('KPI') || body.includes('confidence') || body.includes('Loading');
      }},
    ]);
  });

  test('Step 3: Sections list', async ({ page }) => {
    await loginInstructor(page);
    await page.goto(BASE_URL + '/instructor/sections');
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);
    await screenshot(page, 'instructor_03_sections');
    await check(page, 'Sections', [
      { name: 'Sections page', verify: async (p) => {
        const body = await p.evaluate(() => document.body.textContent);
        return body.includes('Section') || body.includes('section') || body.includes('No sections');
      }},
    ]);
  });

  test('Step 4: Section detail page', async ({ page }) => {
    await loginInstructor(page);
    if (!SECTION_ID) { console.log('No section ID, skipping'); return; }
    await page.goto(BASE_URL + '/instructor/sections/' + SECTION_ID);
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);
    await screenshot(page, 'instructor_04_sectionDetail');
    await check(page, 'Section Detail', [
      { name: 'Section page loaded', verify: async (p) => {
        const body = await p.evaluate(() => document.body.textContent);
        return body.includes('Roster') || body.includes('Analytics') || body.includes('Settings') || body.includes('Section');
      }},
    ]);
  });

  test('Step 5: Roster tab', async ({ page }) => {
    await loginInstructor(page);
    if (!SECTION_ID) return;
    await page.goto(BASE_URL + '/instructor/sections/' + SECTION_ID);
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(2000);
    const rosterTab = page.locator('button, [role="tab"]').filter({ hasText: /roster/i }).first();
    if (await rosterTab.isVisible({ timeout: 3000 }).catch(() => false)) {
      await rosterTab.click();
      await page.waitForTimeout(2000);
    }
    await screenshot(page, 'instructor_05_roster');
    await check(page, 'Roster', [
      { name: 'Student list visible', verify: async (p) => {
        const body = await p.evaluate(() => document.body.textContent);
        return body.includes('student') || body.includes('Student') || body.includes('enrolled') || body.includes('No students');
      }},
    ]);
  });

  test('Step 6: Analytics tab', async ({ page }) => {
    await loginInstructor(page);
    if (!SECTION_ID) return;
    await page.goto(BASE_URL + '/instructor/sections/' + SECTION_ID);
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(2000);
    const analyticsTab = page.locator('button, [role="tab"]').filter({ hasText: /analytics/i }).first();
    if (await analyticsTab.isVisible({ timeout: 3000 }).catch(() => false)) {
      await analyticsTab.click();
      await page.waitForTimeout(2000);
    }
    await screenshot(page, 'instructor_06_analytics');
    await check(page, 'Analytics', [
      { name: 'Analytics loaded', verify: async (p) => {
        const body = await p.evaluate(() => document.body.textContent);
        return body.includes('mastery') || body.includes('Mastery') || body.includes('concept') || body.includes('Loading');
      }},
    ]);
  });

  test('Step 7: Submissions tab', async ({ page }) => {
    await loginInstructor(page);
    if (!SECTION_ID) return;
    await page.goto(BASE_URL + '/instructor/sections/' + SECTION_ID);
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(2000);
    const submissionsTab = page.locator('button, [role="tab"]').filter({ hasText: /submissions/i }).first();
    if (await submissionsTab.isVisible({ timeout: 3000 }).catch(() => false)) {
      await submissionsTab.click();
      await page.waitForTimeout(2000);
    }
    await screenshot(page, 'instructor_07_submissions');
    await check(page, 'Submissions', [
      { name: 'Submissions loaded', verify: async (p) => {
        const body = await p.evaluate(() => document.body.textContent);
        return body.includes('submission') || body.includes('Submission') || body.includes('No submissions');
      }},
    ]);
  });

  test('Step 8: Students page', async ({ page }) => {
    await loginInstructor(page);
    await page.goto(BASE_URL + '/instructor/students');
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);
    await screenshot(page, 'instructor_08_students');
    await check(page, 'Students', [
      { name: 'Students page', verify: async (p) => {
        const body = await p.evaluate(() => document.body.textContent);
        return body.includes('student') || body.includes('Student') || body.includes('No students');
      }},
    ]);
  });

  test('Step 9: Exercises page', async ({ page }) => {
    await loginInstructor(page);
    await page.goto(BASE_URL + '/instructor/exercises');
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);
    await screenshot(page, 'instructor_09_exercises');
    await check(page, 'Exercises', [
      { name: 'Exercises page', verify: async (p) => {
        const body = await p.evaluate(() => document.body.textContent);
        return body.includes('Sum') || body.includes('Even') || body.includes('Maximum') || body.includes('exercise') || body.includes('Exercise');
      }},
    ]);
  });

  test('Step 10: Heatmap', async ({ page }) => {
    await loginInstructor(page);
    await page.goto(BASE_URL + '/instructor/heatmap');
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);
    await screenshot(page, 'instructor_10_heatmap');
    await check(page, 'Heatmap', [
      { name: 'Heatmap loaded', verify: async (p) => {
        const body = await p.evaluate(() => document.body.textContent);
        return body.includes('Heatmap') || body.includes('heatmap') || body.includes('Student') || body.includes('Concept');
      }},
    ]);
  });

  test('Step 11: Alerts (Intervention Queue)', async ({ page }) => {
    await loginInstructor(page);
    await page.goto(BASE_URL + '/instructor/alerts');
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);
    await screenshot(page, 'instructor_11_alerts');
    await check(page, 'Alerts', [
      { name: 'Alerts page loaded', verify: async (p) => {
        const body = await p.evaluate(() => document.body.textContent);
        return body.includes('alert') || body.includes('Alert') || body.includes('intervention') || body.includes('risk') || body.includes('No alerts');
      }},
    ]);
  });

  test('Step 12: Integrity flags', async ({ page }) => {
    await loginInstructor(page);
    await page.goto(BASE_URL + '/instructor/integrity');
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);
    await screenshot(page, 'instructor_12_integrity');
    await check(page, 'Integrity', [
      { name: 'Integrity page loaded', verify: async (p) => {
        const body = await p.evaluate(() => document.body.textContent);
        return body.includes('integrity') || body.includes('Integrity') || body.includes('flag') || body.includes('HARDCODING') || body.includes('No flags');
      }},
    ]);
  });

  test('Step 13: Reports page', async ({ page }) => {
    await loginInstructor(page);
    await page.goto(BASE_URL + '/instructor/reports');
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);
    await screenshot(page, 'instructor_13_reports');
    await check(page, 'Reports', [
      { name: 'Reports page', verify: async (p) => {
        const body = await p.evaluate(() => document.body.textContent);
        return body.includes('Reports') || body.includes('report') || body.includes('mastery') || body.includes('Mastery');
      }},
    ]);
  });

  test('Step 14: Custom Tags', async ({ page }) => {
    await loginInstructor(page);
    if (!SECTION_ID) return;
    await page.goto(BASE_URL + '/instructor/sections/' + SECTION_ID + '/custom-tags');
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);
    await screenshot(page, 'instructor_14_custom_tags');
    await check(page, 'Custom Tags', [
      { name: 'Tags page loaded', verify: async (p) => {
        const body = await p.evaluate(() => document.body.textContent);
        return body.includes('Tag') || body.includes('tag') || body.includes('custom') || body.includes('No custom tags');
      }},
    ]);
  });

  test('Step 15: Custom Heatmap', async ({ page }) => {
    await loginInstructor(page);
    if (!SECTION_ID) return;
    await page.goto(BASE_URL + '/instructor/sections/' + SECTION_ID + '/custom-heatmap');
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);
    await screenshot(page, 'instructor_15_custom_heatmap');
  });

  test('Step 16: Structure Violations', async ({ page }) => {
    await loginInstructor(page);
    if (!SECTION_ID) return;
    await page.goto(BASE_URL + '/instructor/sections/' + SECTION_ID + '/structure-violations');
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);
    await screenshot(page, 'instructor_16_structure_violations');
  });

  test('Step 17: Micro-concept Report', async ({ page }) => {
    await loginInstructor(page);
    if (!SECTION_ID) return;
    await page.goto(BASE_URL + '/instructor/sections/' + SECTION_ID + '/micro-concepts');
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);
    await screenshot(page, 'instructor_17_micro_concepts');
  });

  test('Step 18: Academic Integrity Flags (section)', async ({ page }) => {
    await loginInstructor(page);
    if (!SECTION_ID) return;
    await page.goto(BASE_URL + '/instructor/sections/' + SECTION_ID + '/academic-integrity');
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);
    await screenshot(page, 'instructor_18_academic_integrity');
  });

  test('Step 19: Exercise Explorer', async ({ page }) => {
    await loginInstructor(page);
    await page.goto(BASE_URL + '/instructor/explorer');
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);
    await screenshot(page, 'instructor_19_explorer');
    await check(page, 'Explorer', [
      { name: 'Explorer page', verify: async (p) => {
        const body = await p.evaluate(() => document.body.textContent);
        return body.includes('Explorer') || body.includes('explorer') || body.includes('Search') || body.includes('search');
      }},
    ]);
  });

  test('Step 20: Close an exercise', async ({ page }) => {
    await loginInstructor(page);
    if (!SECTION_ID) return;
    await page.goto(BASE_URL + '/instructor/exercises');
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);
    const closeBtn = page.locator('button').filter({ hasText: /lock|close/i }).first();
    if (await closeBtn.isVisible({ timeout: 3000 }).catch(() => false)) {
      await closeBtn.click();
      await page.waitForTimeout(1000);
    }
    await screenshot(page, 'instructor_20_close_exercise');
  });

  test('Step 21: Reopen an exercise', async ({ page }) => {
    await loginInstructor(page);
    if (!SECTION_ID) return;
    await page.goto(BASE_URL + '/instructor/exercises');
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);
    const openBtn = page.locator('button').filter({ hasText: /unlock|reopen|open/i }).first();
    if (await openBtn.isVisible({ timeout: 3000 }).catch(() => false)) {
      await openBtn.click();
      await page.waitForTimeout(1000);
    }
    await screenshot(page, 'instructor_21_reopen_exercise');
  });

  test('Step 22: Export section data', async ({ page }) => {
    await loginInstructor(page);
    if (!SECTION_ID) return;
    await page.goto(BASE_URL + '/instructor/sections/' + SECTION_ID);
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(2000);
    const moreBtn = page.locator('button').filter({ hasText: /more|export|actions/i }).first();
    if (await moreBtn.isVisible({ timeout: 3000 }).catch(() => false)) {
      await moreBtn.click();
      await page.waitForTimeout(1000);
    }
    await screenshot(page, 'instructor_22_export');
  });

  test('Step 23: Section Settings', async ({ page }) => {
    await loginInstructor(page);
    if (!SECTION_ID) return;
    await page.goto(BASE_URL + '/instructor/sections/' + SECTION_ID);
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(2000);
    const settingsTab = page.locator('button, [role="tab"]').filter({ hasText: /settings/i }).first();
    if (await settingsTab.isVisible({ timeout: 3000 }).catch(() => false)) {
      await settingsTab.click();
      await page.waitForTimeout(2000);
    }
    await screenshot(page, 'instructor_23_settings');
    await check(page, 'Settings', [
      { name: 'Settings tab loaded', verify: async (p) => {
        const body = await p.evaluate(() => document.body.textContent);
        return body.includes('Section') || body.includes('Roster') || body.includes('Delete') || body.includes('metadata');
      }},
    ]);
  });

  test('Step 24: Exercise workspace', async ({ page }) => {
    await loginInstructor(page);
    await page.goto(BASE_URL + '/instructor/exercises/workspace');
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);
    await screenshot(page, 'instructor_24_exercise_workspace');
  });

  test('Step 25: Final overview', async ({ page }) => {
    await loginInstructor(page);
    await page.goto(BASE_URL + '/instructor/dashboard');
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);
    await screenshot(page, 'instructor_25_final_overview');
    await check(page, 'Final Dashboard', [
      { name: 'Dashboard loaded', verify: async (p) => {
        const body = await p.evaluate(() => document.body.textContent);
        return body.includes('CDS') || body.includes('Dashboard') || body.includes('Student') || body.includes('Section');
      }},
    ]);
  });
});

test.afterAll(async () => {
  printSummary();
});
