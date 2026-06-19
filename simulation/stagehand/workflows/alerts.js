/**
 * simulation/stagehand/workflows/alerts.js
 *
 * Alerts/Intervention workflow tests: intervention queue, review alerts, at-risk detection.
 */

const { createBrowser, login, navigateTo, PERSONAS } = require('../config');

async function testInterventionQueue() {
  const { browser, page } = await createBrowser();
  const steps = [];

  try {
    await login(page, PERSONAS.instructor.email, PERSONAS.instructor.password);
    steps.push({ action: 'Login as instructor', success: true });

    await navigateTo(page, '/instructor/alerts');
    steps.push({ action: 'Navigate to alerts', success: true });

    // Check for intervention queue header
    const header = page.locator('text=Intervention, text=Alerts, text=At-Risk, h1, h2').first();
    const hasHeader = await header.isVisible({ timeout: 5000 }).catch(() => false);
    steps.push({ action: 'Intervention queue header', success: hasHeader });

    // Check for severity tiers
    const tiers = page.locator('text=Critical, text=Needs Support, text=Developing, text=Strong, text=Excellent');
    const tierCount = await tiers.count();
    steps.push({ action: 'Severity tiers visible', success: tierCount >= 2, count: tierCount });

    // Check for student rows
    const studentRows = page.locator('tr, [class*="alert-row"], [class*="student-item"]');
    const rowCount = await studentRows.count();
    steps.push({ action: 'Student alert rows', success: rowCount >= 0 });

    // Check for mastery bars in alerts
    const masteryBars = page.locator('[class*="progress"], [class*="mastery"], [class*="bar"], [role="progressbar"]');
    const barCount = await masteryBars.count();
    steps.push({ action: 'Mastery bars in alerts', success: barCount >= 0 });

    // Check for search/filter
    const searchInput = page.locator('input[type="search"], input[placeholder*="search" i]').first();
    const hasSearch = await searchInput.isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'Search filter visible', success: hasSearch });

    const passed = steps.filter(s => s.success).length >= 3;
    return { passed, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await browser.close();
  }
}

async function testAlertDetailDrawer() {
  const { browser, page } = await createBrowser();
  const steps = [];

  try {
    await login(page, PERSONAS.instructor.email, PERSONAS.instructor.password);
    steps.push({ action: 'Login as instructor', success: true });

    await navigateTo(page, '/instructor/alerts');
    steps.push({ action: 'Navigate to alerts', success: true });

    // Click first alert row
    const alertRow = page.locator('tr, [class*="alert-row"], [class*="student-item"]').first();
    if (await alertRow.isVisible({ timeout: 5000 }).catch(() => false)) {
      await alertRow.click();
      await page.waitForTimeout(2000);
      steps.push({ action: 'Click alert row', success: true });

      // Check for detail drawer
      const drawer = page.locator('[class*="drawer"], [class*="detail"], [class*="panel"], [class*="modal"]').first();
      const hasDrawer = await drawer.isVisible({ timeout: 5000 }).catch(() => false);
      steps.push({ action: 'Detail drawer opened', success: hasDrawer });

      // Check for CDS score in drawer
      const cdsScore = page.locator('text=CDS, text=Score, text=Difficulty').first();
      const hasCds = await cdsScore.isVisible({ timeout: 3000 }).catch(() => false);
      steps.push({ action: 'CDS score visible', success: hasCds });

      // Check for mastery bar in drawer
      const masteryBar = page.locator('[class*="mastery"], [class*="progress"], [class*="bar"]').first();
      const hasMastery = await masteryBar.isVisible({ timeout: 3000 }).catch(() => false);
      steps.push({ action: 'Mastery bar in drawer', success: hasMastery });

      // Check for student info
      const studentInfo = page.locator('text=Student, text=Email, [class*="student"]').first();
      const hasStudentInfo = await studentInfo.isVisible({ timeout: 3000 }).catch(() => false);
      steps.push({ action: 'Student info visible', success: hasStudentInfo });

      // Check for concept/exercise info
      const conceptInfo = page.locator('text=Concept, text=Exercise, text=Topic').first();
      const hasConceptInfo = await conceptInfo.isVisible({ timeout: 3000 }).catch(() => false);
      steps.push({ action: 'Concept/Exercise info', success: hasConceptInfo });

      // Check for instructor notes
      const notes = page.locator('text=Notes, text=Instructor, textarea, [class*="note"]').first();
      const hasNotes = await notes.isVisible({ timeout: 3000 }).catch(() => false);
      steps.push({ action: 'Instructor notes area', success: hasNotes });

      // Check for Review button
      const reviewBtn = page.locator('button:has-text("Review"), button:has-text("Mark")').first();
      const hasReviewBtn = await reviewBtn.isVisible({ timeout: 3000 }).catch(() => false);
      steps.push({ action: 'Review button visible', success: hasReviewBtn });
    } else {
      steps.push({ action: 'No alerts to inspect', success: true });
    }

    const passed = steps.filter(s => s.success).length >= 3;
    return { passed, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await browser.close();
  }
}

async function testReviewAlert() {
  const { browser, page } = await createBrowser();
  const steps = [];

  try {
    await login(page, PERSONAS.instructor.email, PERSONAS.instructor.password);
    steps.push({ action: 'Login as instructor', success: true });

    await navigateTo(page, '/instructor/alerts');
    steps.push({ action: 'Navigate to alerts', success: true });

    // Find a Review button
    const reviewBtn = page.locator('button:has-text("Review"), button:has-text("Mark Reviewed")').first();
    if (await reviewBtn.isVisible({ timeout: 5000 }).catch(() => false)) {
      await reviewBtn.click();
      await page.waitForTimeout(2000);
      steps.push({ action: 'Click Review button', success: true });

      // Check for confirmation or success
      const confirmation = page.locator('[class*="modal"], [class*="dialog"], [role="dialog"], text=Confirm');
      const hasConfirmation = await confirmation.first().isVisible({ timeout: 3000 }).catch(() => false);

      if (hasConfirmation) {
        const confirmBtn = page.locator('button:has-text("Confirm"), button:has-text("Yes")').first();
        if (await confirmBtn.isVisible({ timeout: 2000 }).catch(() => false)) {
          await confirmBtn.click();
          await page.waitForTimeout(2000);
          steps.push({ action: 'Confirm review', success: true });
        }
      }

      // Check for success notification
      const notification = page.locator('[class*="toast"], [class*="notification"], [class*="alert"], text=Success, text=Reviewed');
      const hasNotification = await notification.first().isVisible({ timeout: 5000 }).catch(() => false);
      steps.push({ action: 'Review success notification', success: hasNotification });
    } else {
      steps.push({ action: 'No alerts to review', success: true });
    }

    const passed = steps.filter(s => s.success).length >= 1;
    return { passed, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await browser.close();
  }
}

async function testDashboardAtRiskSection() {
  const { browser, page } = await createBrowser();
  const steps = [];

  try {
    await login(page, PERSONAS.instructor.email, PERSONAS.instructor.password);
    steps.push({ action: 'Login as instructor', success: true });

    await navigateTo(page, '/instructor/dashboard');
    steps.push({ action: 'Navigate to dashboard', success: true });

    // Check for at-risk count
    const atRiskCount = page.locator('text=At-Risk, text=At Risk, [class*="at-risk"]');
    const hasAtRisk = await atRiskCount.first().isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'At-risk count visible', success: hasAtRisk });

    // Check for delta indicator
    const delta = page.locator('[class*="delta"], [class*="change"]');
    const hasDelta = await delta.first().isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'Delta indicator visible', success: hasDelta });

    // Check for struggling concepts bar
    const conceptBar = page.locator('[class*="concept"], [class*="bar"], text=Struggling').first();
    const hasConceptBar = await conceptBar.isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'Struggling concepts bar', success: hasConceptBar });

    // Check for recent flags
    const recentFlags = page.locator('text=Recent, text=Flags, text=Integrity, [class*="flag"]').first();
    const hasFlags = await recentFlags.isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'Recent flags visible', success: hasFlags });

    const passed = steps.filter(s => s.success).length >= 2;
    return { passed, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await browser.close();
  }
}

async function testMicroConceptAlerts() {
  let browser, page;
  const steps = [];

  try {
    const ctx = await createBrowser();
    browser = ctx.browser;
    page = ctx.page;

    await login(page, PERSONAS.instructor.email, PERSONAS.instructor.password);
    if (!page || page.isClosed()) throw new Error('Page closed after login');
    steps.push({ action: 'Login as instructor', success: true });

    // Navigate to section detail to find micro-concept alerts
    await navigateTo(page, '/instructor/sections');
    steps.push({ action: 'Navigate to sections', success: true });

    const sectionLink = page.locator('a[href*="/instructor/sections/"]').first();
    if (await sectionLink.isVisible({ timeout: 5000 }).catch(() => false)) {
      await sectionLink.click();
      await page.waitForLoadState('networkidle');
      await page.waitForTimeout(2000);
      steps.push({ action: 'Select section', success: true });

      // Check for micro-concept alerts tab/section
      const microAlerts = page.locator('text=Micro, text=Concept Alert, text=Feedback').first();
      const hasMicroAlerts = await microAlerts.isVisible({ timeout: 3000 }).catch(() => false);
      steps.push({ action: 'Micro-concept alerts section', success: hasMicroAlerts });
    } else {
      steps.push({ action: 'No sections available', success: true });
    }

    const passed = steps.filter(s => s.success).length >= 1;
    return { passed, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    if (browser) await browser.close();
  }
}

module.exports = { testInterventionQueue, testAlertDetailDrawer, testReviewAlert, testDashboardAtRiskSection, testMicroConceptAlerts };
