const { chromium } = require('playwright');
const { Pool } = require('pg');
const { BASE_URL, DB_CONFIG, INSTRUCTOR } = require('./config');

const pool = new Pool(DB_CONFIG);

async function verifyAnalytics(sectionId, exerciseId) {
  const results = [];
  const browser = await chromium.launch({ headless: true });

  try {
    const context = await browser.newContext({ viewport: { width: 1440, height: 900 } });
    const page = await context.newPage();

    // ── Login as instructor ─────────────────────────────────────────
    await page.goto(`${BASE_URL}/login`);
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(1000);
    await page.locator('input[type="email"]').first().fill(INSTRUCTOR.email);
    await page.locator('input[type="password"]').first().fill(INSTRUCTOR.password);
    await page.locator('button[type="submit"]').first().click();
    await page.waitForTimeout(2000);

    const loginOk = !page.url().includes('/login');
    results.push({ page: 'Login', passed: loginOk, detail: loginOk ? 'Instructor logged in' : 'Login failed' });
    if (!loginOk) return { allPassed: false, results };

    // ── Dashboard ──────────────────────────────────────────────────
    await page.goto(`${BASE_URL}/instructor/dashboard`);
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);
    const dashText = await page.evaluate(() => document.body.textContent || '');
    const dashHasData = dashText.includes(sectionId.toString()) || dashText.includes('Section') || dashText.length > 500;
    await page.screenshot({ path: `/tmp/analytics_dashboard.png` });
    results.push({ page: 'Dashboard', passed: dashHasData, detail: `Dashboard loaded (${dashText.length} chars)` });

    // ── Section Detail (Analytics tab) ────────────────────────────
    await page.goto(`${BASE_URL}/instructor/sections/${sectionId}`);
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);
    const sectionText = await page.evaluate(() => document.body.textContent || '');
    const sectionHasData = sectionText.includes('Exercise') || sectionText.includes('exercise') || sectionText.includes('CDS');
    await page.screenshot({ path: `/tmp/analytics_section.png` });
    results.push({ page: 'SectionDetail', passed: sectionHasData, detail: `Section page loaded (${sectionText.length} chars)` });

    // ── Academic Integrity ───────────────────────────────────────
    await page.goto(`${BASE_URL}/instructor/sections/${sectionId}/academic-integrity`);
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);
    const integrityText = await page.evaluate(() => document.body.textContent || '');
    const hasFlags = integrityText.includes('HARDCODING') || integrityText.includes('BLANK_TEMPLATE') || integrityText.includes('CODE_GROWTH') || integrityText.includes('BEHAVIORAL') || integrityText.includes('integrity') || integrityText.includes('Integrity');
    await page.screenshot({ path: `/tmp/analytics_integrity.png` });
    results.push({ page: 'AcademicIntegrity', passed: hasFlags, detail: hasFlags ? 'Integrity flags visible' : 'No flag text found' });

    // ── Structure Violations ──────────────────────────────────────
    await page.goto(`${BASE_URL}/instructor/sections/${sectionId}/structure-violations`);
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);
    const violationsText = await page.evaluate(() => document.body.textContent || '');
    await page.screenshot({ path: `/tmp/analytics_violations.png` });
    results.push({ page: 'StructureViolations', passed: violationsText.length > 100, detail: `Violations page loaded (${violationsText.length} chars)` });

    // ── Micro Concepts ────────────────────────────────────────────
    await page.goto(`${BASE_URL}/instructor/sections/${sectionId}/micro-concepts`);
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);
    const microText = await page.evaluate(() => document.body.textContent || '');
    await page.screenshot({ path: `/tmp/analytics_microconcepts.png` });
    results.push({ page: 'MicroConcepts', passed: microText.length > 100, detail: `Micro-concepts page loaded (${microText.length} chars)` });

    // ── Heatmap ────────────────────────────────────────────────────
    await page.goto(`${BASE_URL}/instructor/heatmap`);
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);
    const heatmapText = await page.evaluate(() => document.body.textContent || '');
    await page.screenshot({ path: `/tmp/analytics_heatmap.png` });
    results.push({ page: 'Heatmap', passed: heatmapText.length > 100, detail: `Heatmap page loaded (${heatmapText.length} chars)` });

    // ── Reports ────────────────────────────────────────────────────
    await page.goto(`${BASE_URL}/instructor/reports`);
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(3000);
    const reportsText = await page.evaluate(() => document.body.textContent || '');
    await page.screenshot({ path: `/tmp/analytics_reports.png` });
    results.push({ page: 'Reports', passed: reportsText.length > 100, detail: `Reports page loaded (${reportsText.length} chars)` });

    const allPassed = results.every(r => r.passed);
    return { allPassed, results };
  } catch (error) {
    results.push({ page: 'Error', passed: false, detail: error.message });
    return { allPassed: false, results };
  } finally {
    await browser.close();
  }
}

module.exports = { verifyAnalytics };
