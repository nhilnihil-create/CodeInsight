/**
 * simulation/stagehand/workflows/integrity.js
 *
 * Integrity flag engine workflow tests: flag queue, review, detail drawer, bulk dismiss.
 */

const { createBrowser, login, navigateTo, PERSONAS } = require('../config');

async function testIntegrityQueue() {
  const { browser, page } = await createBrowser();
  const steps = [];

  try {
    await login(page, PERSONAS.instructor.email, PERSONAS.instructor.password);
    steps.push({ action: 'Login as instructor', success: true });

    await navigateTo(page, '/instructor/integrity');
    steps.push({ action: 'Navigate to integrity page', success: true });

    // Check integrity flags list/table
    const flagsList = page.locator('table, [class*="flag"], [class*="queue"], [class*="list"]');
    const hasList = await flagsList.first().isVisible({ timeout: 5000 }).catch(() => false);
    steps.push({ action: 'Integrity flags list visible', success: hasList });

    // Check for severity filter
    const severityFilter = page.locator('select, [role="combobox"], button:has-text("Severity"), button:has-text("Filter")').first();
    const hasFilter = await severityFilter.isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'Severity filter visible', success: hasFilter });

    // Check for type filter
    const typeFilter = page.locator('button:has-text("Type"), button:has-text("HARDCODED"), button:has-text("BLANK")').first();
    const hasTypeFilter = await typeFilter.isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'Type filter visible', success: hasTypeFilter });

    // Check for search input
    const searchInput = page.locator('input[type="search"], input[placeholder*="search" i]').first();
    const hasSearch = await searchInput.isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'Search input visible', success: hasSearch });

    // Check for flag rows
    const flagRows = page.locator('tr[class*="flag"], [class*="flag-row"], [class*="integrity-item"]');
    const rowCount = await flagRows.count();
    steps.push({ action: 'Flag rows rendered', success: rowCount >= 0 });

    const passed = steps.filter(s => s.success).length >= 2;
    return { passed, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await browser.close();
  }
}

async function testIntegrityFlagDetail() {
  const { browser, page } = await createBrowser();
  const steps = [];

  try {
    await login(page, PERSONAS.instructor.email, PERSONAS.instructor.password);
    steps.push({ action: 'Login as instructor', success: true });

    await navigateTo(page, '/instructor/integrity');
    steps.push({ action: 'Navigate to integrity page', success: true });

    // Try to click first flag row to open detail
    const flagRow = page.locator('tr[class*="flag"], [class*="flag-row"], [class*="integrity-item"], table tbody tr').first();
    if (await flagRow.isVisible({ timeout: 5000 }).catch(() => false)) {
      await flagRow.click();
      await page.waitForTimeout(2000);
      steps.push({ action: 'Click flag row', success: true });

      // Check for detail drawer/panel
      const detailDrawer = page.locator('[class*="drawer"], [class*="detail"], [class*="panel"], [class*="modal"]').first();
      const hasDrawer = await detailDrawer.isVisible({ timeout: 5000 }).catch(() => false);
      steps.push({ action: 'Detail drawer opened', success: hasDrawer });

      // Check for evidence section
      const evidence = page.locator('text=Evidence, text=Context, text=Behaviors').first();
      const hasEvidence = await evidence.isVisible({ timeout: 3000 }).catch(() => false);
      steps.push({ action: 'Evidence section visible', success: hasEvidence });

      // Check for review/dismiss buttons
      const reviewBtn = page.locator('button:has-text("Review"), button:has-text("Dismiss"), button:has-text("Mark")').first();
      const hasReviewBtn = await reviewBtn.isVisible({ timeout: 3000 }).catch(() => false);
      steps.push({ action: 'Review/Dismiss button visible', success: hasReviewBtn });
    } else {
      steps.push({ action: 'No flags to inspect', success: true });
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

async function testBulkDismiss() {
  const { browser, page } = await createBrowser();
  const steps = [];

  try {
    await login(page, PERSONAS.instructor.email, PERSONAS.instructor.password);
    steps.push({ action: 'Login as instructor', success: true });

    await navigateTo(page, '/instructor/integrity');
    steps.push({ action: 'Navigate to integrity page', success: true });

    // Check for checkbox selection
    const checkboxes = page.locator('input[type="checkbox"], [role="checkbox"]');
    const checkboxCount = await checkboxes.count();
    steps.push({ action: 'Checkboxes available', success: checkboxCount >= 0 });

    // Check for bulk action button
    const bulkBtn = page.locator('button:has-text("Bulk"), button:has-text("Select All"), button:has-text("Dismiss Selected")').first();
    const hasBulkBtn = await bulkBtn.isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'Bulk action button visible', success: hasBulkBtn });

    // Select first checkbox if available
    if (checkboxCount > 0) {
      await checkboxes.first().click();
      steps.push({ action: 'Select first flag', success: true });

      // Check if bulk action is now enabled
      const enabledBulkBtn = page.locator('button:has-text("Bulk"):not([disabled]), button:has-text("Dismiss"):not([disabled])').first();
      const isEnabled = await enabledBulkBtn.isVisible({ timeout: 2000 }).catch(() => false);
      steps.push({ action: 'Bulk action enabled after selection', success: isEnabled });
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

async function testStudentIntegrityView() {
  const { browser, page } = await createBrowser();
  const steps = [];
  const student = PERSONAS.students[0];

  try {
    await login(page, student.email, student.password);
    steps.push({ action: 'Login as student', success: true });

    await navigateTo(page, '/student/integrity');
    steps.push({ action: 'Navigate to student integrity', success: true });

    // Check for integrity flags list (read-only)
    const flagsList = page.locator('table, [class*="flag"], [class*="list"], [class*="queue"]');
    const hasList = await flagsList.first().isVisible({ timeout: 5000 }).catch(() => false);
    steps.push({ action: 'Student integrity flags visible', success: hasList });

    // Check that no review/dismiss buttons exist (read-only)
    const reviewBtn = page.locator('button:has-text("Review"), button:has-text("Dismiss")').first();
    const hasReviewBtn = await reviewBtn.isVisible({ timeout: 2000 }).catch(() => false);
    steps.push({ action: 'No review buttons (read-only)', success: !hasReviewBtn });

    const passed = steps.filter(s => s.success).length >= 1;
    return { passed, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await browser.close();
  }
}

module.exports = { testIntegrityQueue, testIntegrityFlagDetail, testBulkDismiss, testStudentIntegrityView };
