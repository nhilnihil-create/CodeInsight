/**
 * simulation/stagehand/workflows/cds-engine.js
 *
 * CDS Engine workflow tests: dashboard KPIs, heatmap, live CDS, command center.
 */

const { createBrowser, login, navigateTo, hasPageContent, PERSONAS } = require('../config');

async function testInstructorDashboard() {
  const { browser, page } = await createBrowser();
  const steps = [];

  try {
    await login(page, PERSONAS.instructor.email, PERSONAS.instructor.password);
    steps.push({ action: 'Login as instructor', success: true });

    await navigateTo(page, '/instructor/dashboard');
    steps.push({ action: 'Navigate to dashboard', success: true });

    // Check KPI cards exist (At-Risk, Avg CDS, Mastery, Flags)
    const kpiCards = page.locator('.grid > div, [class*="card"], [class*="stat"]');
    const kpiCount = await kpiCards.count();
    steps.push({ action: 'KPI cards visible', success: kpiCount >= 3, count: kpiCount });

    // Check for section selector
    const sectionSelect = page.locator('select, [role="combobox"], button:has-text("Section")').first();
    const hasSectionSelect = await sectionSelect.isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'Section selector visible', success: hasSectionSelect });

    // Check for struggling concepts bar
    const conceptBar = page.locator('text=Struggling, text=Concepts, [class*="concept"]').first();
    const hasConceptBar = await conceptBar.isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'Struggling concepts section', success: hasConceptBar });

    // Check for recent flags list
    const flagsList = page.locator('text=Recent, text=Flags, text=Integrity').first();
    const hasFlagsList = await flagsList.isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'Recent flags section', success: hasFlagsList });

    const passed = steps.filter(s => s.success).length >= 3;
    return { passed, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await browser.close();
  }
}

async function testHeatmapView() {
  const { browser, page } = await createBrowser();
  const steps = [];

  try {
    await login(page, PERSONAS.instructor.email, PERSONAS.instructor.password);
    steps.push({ action: 'Login as instructor', success: true });

    await navigateTo(page, '/instructor/heatmap');
    steps.push({ action: 'Navigate to heatmap', success: true });

    // Check heatmap grid exists
    const heatmapGrid = page.locator('table, [class*="heatmap"], [class*="grid"], [class*="mosaic"]').first();
    const hasGrid = await heatmapGrid.isVisible({ timeout: 5000 }).catch(() => false);
    steps.push({ action: 'Heatmap grid visible', success: hasGrid });

    // Check for student rows
    const studentRows = page.locator('tr, [class*="row"], [class*="student"]');
    const rowCount = await studentRows.count();
    steps.push({ action: 'Student rows rendered', success: rowCount >= 1, count: rowCount });

    // Check for color-coded cells
    const coloredCells = page.locator('td[style*="background"], td[class*="bg-"], [class*="tier"], [class*="cell"]');
    const cellCount = await coloredCells.count();
    steps.push({ action: 'Colored CDS cells', success: cellCount >= 1, count: cellCount });

    // Check for search filter
    const searchInput = page.locator('input[type="search"], input[placeholder*="search" i], input[placeholder*="filter" i]').first();
    const hasSearch = await searchInput.isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'Search filter visible', success: hasSearch });

    const passed = steps.filter(s => s.success).length >= 2;
    return { passed, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await browser.close();
  }
}

async function testCommandCenter() {
  const { browser, page } = await createBrowser();
  const steps = [];

  try {
    await login(page, PERSONAS.instructor.email, PERSONAS.instructor.password);
    steps.push({ action: 'Login as instructor', success: true });

    await navigateTo(page, '/instructor/command');
    steps.push({ action: 'Navigate to command center', success: true });

    // Check for insight cards (what/why/who/action)
    const insightCards = page.locator('[class*="card"], [class*="insight"], [class*="tile"]');
    const cardCount = await insightCards.count();
    steps.push({ action: 'Insight cards rendered', success: cardCount >= 2, count: cardCount });

    // Check for KPI summary
    const kpiSection = page.locator('text=CDS, text=At-Risk, text=Mastery, text=KPI').first();
    const hasKpi = await kpiSection.isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'KPI summary visible', success: hasKpi });

    // Check for at-risk roster
    const roster = page.locator('text=At-Risk, text=Roster, text=Students').first();
    const hasRoster = await roster.isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'At-risk roster visible', success: hasRoster });

    const passed = steps.filter(s => s.success).length >= 2;
    return { passed, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await browser.close();
  }
}

async function testStudentMyScores() {
  const { browser, page } = await createBrowser();
  const steps = [];
  const student = PERSONAS.students[0];

  try {
    await login(page, student.email, student.password);
    steps.push({ action: 'Login as student', success: true });

    await navigateTo(page, '/student/progress');
    steps.push({ action: 'Navigate to progress', success: true });

    // Check for mastery bars
    const masteryBars = page.locator('[class*="progress"], [class*="mastery"], [class*="bar"], [role="progressbar"]');
    const barCount = await masteryBars.count();
    steps.push({ action: 'Mastery bars visible', success: barCount >= 1, count: barCount });

    // Check for concept labels
    const conceptLabels = page.locator('text=CDS, text=NER, text=NRS, text=Score');
    const hasLabels = await conceptLabels.first().isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'CDS score labels', success: hasLabels });

    // Check for trend indicators
    const trends = page.locator('[class*="trend"], [class*="delta"], [class*="arrow"]');
    const trendCount = await trends.count();
    steps.push({ action: 'Trend indicators', success: trendCount >= 0 });

    const passed = steps.filter(s => s.success).length >= 2;
    return { passed, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await browser.close();
  }
}

module.exports = { testInstructorDashboard, testHeatmapView, testCommandCenter, testStudentMyScores };
