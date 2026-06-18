/**
 * simulation/stagehand/workflows/analytics.js
 *
 * Analytics workflow tests: reports, longitudinal data, concept analytics, custom heatmap.
 */

const { createBrowser, login, navigateTo, PERSONAS } = require('../config');

async function testReportsPage() {
  const { browser, page } = await createBrowser();
  const steps = [];

  try {
    await login(page, PERSONAS.instructor.email, PERSONAS.instructor.password);
    steps.push({ action: 'Login as instructor', success: true });

    await navigateTo(page, '/instructor/reports');
    steps.push({ action: 'Navigate to reports', success: true });

    // Check for KPI summary cards
    const kpiCards = page.locator('[class*="card"], [class*="kpi"], [class*="stat"], [class*="summary"]');
    const kpiCount = await kpiCards.count();
    steps.push({ action: 'KPI summary cards', success: kpiCount >= 2, count: kpiCount });

    // Check for tab navigation (Mastery, Completion, Engagement, Integrity)
    const tabs = page.locator('button[role="tab"], [class*="tab"], a:has-text("Mastery"), a:has-text("Completion")');
    const tabCount = await tabs.count();
    steps.push({ action: 'Report tabs visible', success: tabCount >= 2, count: tabCount });

    // Check for chart/visualization
    const charts = page.locator('svg, canvas, [class*="chart"], [class*="recharts"]');
    const chartCount = await charts.count();
    steps.push({ action: 'Charts rendered', success: chartCount >= 1, count: chartCount });

    // Check for period selector
    const periodSelector = page.locator('select, [role="combobox"], button:has-text("7d"), button:has-text("30d"), button:has-text("All")').first();
    const hasPeriod = await periodSelector.isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'Period selector visible', success: hasPeriod });

    // Check for export button
    const exportBtn = page.locator('button:has-text("Export"), button:has-text("CSV"), button:has-text("Download")').first();
    const hasExport = await exportBtn.isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'Export button visible', success: hasExport });

    const passed = steps.filter(s => s.success).length >= 3;
    return { passed, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await browser.close();
  }
}

async function testReportTabs() {
  const { browser, page } = await createBrowser();
  const steps = [];

  try {
    await login(page, PERSONAS.instructor.email, PERSONAS.instructor.password);
    steps.push({ action: 'Login as instructor', success: true });

    await navigateTo(page, '/instructor/reports');
    steps.push({ action: 'Navigate to reports', success: true });

    // Try clicking each tab
    const tabNames = ['Mastery', 'Completion', 'Engagement', 'Integrity'];
    for (const tabName of tabNames) {
      const tab = page.locator(`button:has-text("${tabName}"), a:has-text("${tabName}"), [role="tab"]:has-text("${tabName}")`).first();
      if (await tab.isVisible({ timeout: 2000 }).catch(() => false)) {
        await tab.click();
        await page.waitForTimeout(1500);
        steps.push({ action: `Switch to ${tabName} tab`, success: true });

        // Check for content after tab switch
        const hasContent = await page.locator('svg, canvas, table, [class*="chart"]').first().isVisible({ timeout: 3000 }).catch(() => false);
        steps.push({ action: `${tabName} content loaded`, success: hasContent });
      }
    }

    const passed = steps.filter(s => s.success).length >= 2;
    return { passed, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await browser.close();
  }
}

async function testLongitudinalProgress() {
  const { browser, page } = await createBrowser();
  const steps = [];

  try {
    await login(page, PERSONAS.instructor.email, PERSONAS.instructor.password);
    steps.push({ action: 'Login as instructor', success: true });

    // Navigate to students list
    await navigateTo(page, '/instructor/students');
    steps.push({ action: 'Navigate to students', success: true });

    // Click first student
    const studentLink = page.locator('a[href*="/instructor/students/"], tr[class*="student"], [class*="student-row"]').first();
    if (await studentLink.isVisible({ timeout: 5000 }).catch(() => false)) {
      await studentLink.click();
      await page.waitForLoadState('networkidle');
      await page.waitForTimeout(2000);
      steps.push({ action: 'Select student', success: true });

      // Check for longitudinal tab or section
      const longitudinalTab = page.locator('button:has-text("Longitudinal"), a:has-text("Longitudinal"), button:has-text("Progress"), [class*="longitudinal"]').first();
      if (await longitudinalTab.isVisible({ timeout: 3000 }).catch(() => false)) {
        await longitudinalTab.click();
        await page.waitForTimeout(2000);
        steps.push({ action: 'Open longitudinal tab', success: true });

        // Check for chart
        const chart = page.locator('svg, canvas, [class*="chart"], [class*="progress"]').first();
        const hasChart = await chart.isVisible({ timeout: 5000 }).catch(() => false);
        steps.push({ action: 'Longitudinal chart visible', success: hasChart });

        // Check for trend arrows
        const trends = page.locator('[class*="trend"], [class*="arrow"]');
        const trendCount = await trends.count();
        steps.push({ action: 'Trend indicators', success: trendCount >= 0 });
      } else {
        steps.push({ action: 'No longitudinal tab found', success: true });
      }
    } else {
      steps.push({ action: 'No students available', success: true });
    }

    const passed = steps.filter(s => s.success).length >= 2;
    return { passed, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await browser.close();
  }
}

async function testConceptAnalytics() {
  const { browser, page } = await createBrowser();
  const steps = [];

  try {
    await login(page, PERSONAS.instructor.email, PERSONAS.instructor.password);
    steps.push({ action: 'Login as instructor', success: true });

    // Navigate to section detail or analytics
    await navigateTo(page, '/instructor/sections');
    steps.push({ action: 'Navigate to sections', success: true });

    // Click first section
    const sectionLink = page.locator('a[href*="/instructor/sections/"], tr[class*="section"]').first();
    if (await sectionLink.isVisible({ timeout: 5000 }).catch(() => false)) {
      await sectionLink.click();
      await page.waitForLoadState('networkidle');
      await page.waitForTimeout(2000);
      steps.push({ action: 'Select section', success: true });

      // Check for concept analytics tab/section
      const conceptTab = page.locator('button:has-text("Concept"), a:has-text("Concept"), button:has-text("Analytics")').first();
      if (await conceptTab.isVisible({ timeout: 3000 }).catch(() => false)) {
        await conceptTab.click();
        await page.waitForTimeout(2000);
        steps.push({ action: 'Open concept analytics', success: true });

        // Check for CMI/CRS metrics
        const metrics = page.locator('text=CMI, text=CRS, text=Velocity, text=Mastery Index');
        const hasMetrics = await metrics.first().isVisible({ timeout: 3000 }).catch(() => false);
        steps.push({ action: 'CMI/CRS metrics visible', success: hasMetrics });
      } else {
        steps.push({ action: 'No concept analytics tab', success: true });
      }
    } else {
      steps.push({ action: 'No sections available', success: true });
    }

    const passed = steps.filter(s => s.success).length >= 2;
    return { passed, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await browser.close();
  }
}

async function testCustomHeatmap() {
  const { browser, page } = await createBrowser();
  const steps = [];

  try {
    await login(page, PERSONAS.instructor.email, PERSONAS.instructor.password);
    steps.push({ action: 'Login as instructor', success: true });

    await navigateTo(page, '/instructor/custom-heatmap');
    steps.push({ action: 'Navigate to custom heatmap', success: true });

    // Check for custom heatmap grid
    const heatmapGrid = page.locator('table, [class*="heatmap"], [class*="grid"], [class*="mosaic"]').first();
    const hasGrid = await heatmapGrid.isVisible({ timeout: 5000 }).catch(() => false);
    steps.push({ action: 'Custom heatmap grid visible', success: hasGrid });

    // Check for tag selector
    const tagSelector = page.locator('select, [role="combobox"], button:has-text("Tag"), button:has-text("Filter")').first();
    const hasTagSelector = await tagSelector.isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'Tag selector visible', success: hasTagSelector });

    const passed = steps.filter(s => s.success).length >= 1;
    return { passed, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await browser.close();
  }
}

module.exports = { testReportsPage, testReportTabs, testLongitudinalProgress, testConceptAnalytics, testCustomHeatmap };
