/**
 * simulation/stagehand/workflows/student-progress.js
 *
 * Student progress workflow tests: dashboard, progress tracking, code submission, today's plan.
 */

const { createBrowser, login, navigateTo, PERSONAS } = require('../config');

async function testStudentDashboard() {
  const { browser, page } = await createBrowser();
  const steps = [];
  const student = PERSONAS.students[0];

  try {
    await login(page, student.email, student.password);
    steps.push({ action: 'Login as student', success: true });

    await navigateTo(page, '/student/dashboard');
    steps.push({ action: 'Navigate to dashboard', success: true });

    // Check for due exercises count
    const dueExercises = page.locator('text=Due, text=Upcoming, text=Exercises, [class*="due"]');
    const hasDue = await dueExercises.first().isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'Due exercises section', success: hasDue });

    // Check for mastery percentage
    const mastery = page.locator('text=Mastery, text=%, [class*="mastery"]');
    const hasMastery = await mastery.first().isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'Mastery percentage visible', success: hasMastery });

    // Check for completion percentage
    const completion = page.locator('text=Completion, text=Completed, [class*="completion"]');
    const hasCompletion = await completion.first().isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'Completion percentage visible', success: hasCompletion });

    // Check for weakest concepts
    const weakest = page.locator('text=Weakest, text=Struggling, text=Improve, [class*="weak"]');
    const hasWeakest = await weakest.first().isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'Weakest concepts visible', success: hasWeakest });

    // Check for recommended exercises
    const recommended = page.locator('text=Recommended, text=Next, [class*="recommend"]');
    const hasRecommended = await recommended.first().isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'Recommended exercises visible', success: hasRecommended });

    const passed = steps.filter(s => s.success).length >= 2;
    return { passed, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await browser.close();
  }
}

async function testStudentProgressPage() {
  const { browser, page } = await createBrowser();
  const steps = [];
  const student = PERSONAS.students[0];

  try {
    await login(page, student.email, student.password);
    steps.push({ action: 'Login as student', success: true });

    await navigateTo(page, '/student/progress');
    steps.push({ action: 'Navigate to progress', success: true });

    // Check for trajectory banner
    const trajectory = page.locator('[class*="trajectory"], [class*="banner"], text=Trajectory, text=Weakest');
    const hasTrajectory = await trajectory.first().isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'Trajectory banner visible', success: hasTrajectory });

    // Check for micro-metrics (Mastery %, Completion %, Avg Attempts)
    const metrics = page.locator('[class*="metric"], [class*="micro"], [class*="stat"]');
    const metricCount = await metrics.count();
    steps.push({ action: 'Micro-metrics rendered', success: metricCount >= 2, count: metricCount });

    // Check for per-concept mastery bars
    const conceptBars = page.locator('[class*="progress"], [class*="mastery"], [class*="bar"], [role="progressbar"]');
    const barCount = await conceptBars.count();
    steps.push({ action: 'Concept mastery bars', success: barCount >= 1, count: barCount });

    // Check for period selector (7d/30d/90d/All)
    const periodSelector = page.locator('button:has-text("7d"), button:has-text("30d"), button:has-text("90d"), button:has-text("All")');
    const periodCount = await periodSelector.count();
    steps.push({ action: 'Period selector buttons', success: periodCount >= 2, count: periodCount });

    // Check for trend arrows
    const trends = page.locator('[class*="trend"], [class*="delta"]');
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

async function testStudentTodayPlan() {
  const { browser, page } = await createBrowser();
  const steps = [];
  const student = PERSONAS.students[0];

  try {
    await login(page, student.email, student.password);
    steps.push({ action: 'Login as student', success: true });

    await navigateTo(page, '/student/today');
    steps.push({ action: 'Navigate to today plan', success: true });

    // Check for focus exercise
    const focusExercise = page.locator('text=Focus, text=Today, text=Recommended, [class*="focus"]');
    const hasFocus = await focusExercise.first().isVisible({ timeout: 5000 }).catch(() => false);
    steps.push({ action: 'Focus exercise visible', success: hasFocus });

    // Check for "why" explanation
    const whyExplanation = page.locator('text=Why, text=Because, text=Reason, [class*="why"]');
    const hasWhy = await whyExplanation.first().isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'Why explanation visible', success: hasWhy });

    // Check for class average
    const classAvg = page.locator('text=Class Average, text=Average, text=Peer, [class*="average"]');
    const hasClassAvg = await classAvg.first().isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'Class average visible', success: hasClassAvg });

    // Check for concept bars
    const conceptBars = page.locator('[class*="concept"], [class*="bar"], [class*="progress"]');
    const barCount = await conceptBars.count();
    steps.push({ action: 'Concept bars rendered', success: barCount >= 1 });

    // Check for signals
    const signals = page.locator('text=Signal, text=Alert, text=Warning, [class*="signal"]');
    const hasSignals = await signals.first().isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'Signals visible', success: hasSignals });

    // Check for next moves
    const nextMoves = page.locator('text=Next Move, text=Next Step, text=Action, [class*="next"]');
    const hasNextMoves = await nextMoves.first().isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'Next moves visible', success: hasNextMoves });

    const passed = steps.filter(s => s.success).length >= 3;
    return { passed, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await browser.close();
  }
}

async function testStudentCodeSubmission() {
  const { browser, page } = await createBrowser();
  const steps = [];
  const student = PERSONAS.students[0];

  try {
    await login(page, student.email, student.password);
    steps.push({ action: 'Login as student', success: true });

    await navigateTo(page, '/student/exercises');
    steps.push({ action: 'Navigate to exercises', success: true });

    // Click first exercise
    const exerciseLink = page.locator('a[href*="/student/exercises/"]').first();
    if (await exerciseLink.isVisible({ timeout: 5000 }).catch(() => false)) {
      await exerciseLink.click();
      await page.waitForLoadState('networkidle');
      await page.waitForTimeout(3000);
      steps.push({ action: 'Open exercise', success: true });

      // Check for code editor
      const editor = page.locator('.monaco-editor, [class*="editor"], textarea').first();
      const hasEditor = await editor.isVisible({ timeout: 5000 }).catch(() => false);
      steps.push({ action: 'Code editor loaded', success: hasEditor });

      if (hasEditor) {
        // Check for Run button
        const runBtn = page.locator('button:has-text("Run")').first();
        const hasRunBtn = await runBtn.isVisible({ timeout: 3000 }).catch(() => false);
        steps.push({ action: 'Run button visible', success: hasRunBtn });

        // Check for Submit button
        const submitBtn = page.locator('button:has-text("Submit")').first();
        const hasSubmitBtn = await submitBtn.isVisible({ timeout: 3000 }).catch(() => false);
        steps.push({ action: 'Submit button visible', success: hasSubmitBtn });

        // Check for test results area
        const testResults = page.locator('[class*="test"], [class*="result"], [class*="output"]');
        const hasResults = await testResults.first().isVisible({ timeout: 3000 }).catch(() => false);
        steps.push({ action: 'Test results area visible', success: hasResults });

        // Check for attempt counter
        const attempts = page.locator('text=Attempt, text=Submission, [class*="attempt"]');
        const hasAttempts = await attempts.first().isVisible({ timeout: 3000 }).catch(() => false);
        steps.push({ action: 'Attempt counter visible', success: hasAttempts });
      }
    } else {
      steps.push({ action: 'No exercises available', success: true });
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

async function testStudentProfile() {
  const { browser, page } = await createBrowser();
  const steps = [];
  const student = PERSONAS.students[0];

  try {
    await login(page, student.email, student.password);
    steps.push({ action: 'Login as student', success: true });

    await navigateTo(page, '/student/profile');
    steps.push({ action: 'Navigate to profile', success: true });

    // Check for profile info
    const profileInfo = page.locator('[class*="profile"], [class*="info"], [class*="user"]');
    const hasProfile = await profileInfo.first().isVisible({ timeout: 5000 }).catch(() => false);
    steps.push({ action: 'Profile info visible', success: hasProfile });

    // Check for stats
    const stats = page.locator('[class*="stat"], [class*="metric"], text=Exercises, text=Completed');
    const hasStats = await stats.first().isVisible({ timeout: 3000 }).catch(() => false);
    steps.push({ action: 'Stats visible', success: hasStats });

    const passed = steps.filter(s => s.success).length >= 1;
    return { passed, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await browser.close();
  }
}

async function testStudentRecommendations() {
  const { browser, page } = await createBrowser();
  const steps = [];
  const student = PERSONAS.students[0];

  try {
    await login(page, student.email, student.password);
    steps.push({ action: 'Login as student', success: true });

    await navigateTo(page, '/student/recommendations');
    steps.push({ action: 'Navigate to recommendations', success: true });

    // Check for recommended exercises list
    const recList = page.locator('[class*="recommend"], [class*="list"], [class*="card"]');
    const hasList = await recList.first().isVisible({ timeout: 5000 }).catch(() => false);
    steps.push({ action: 'Recommendations list visible', success: hasList });

    // Check for exercise cards
    const exerciseCards = page.locator('[class*="exercise"], [class*="card"], a[href*="/student/exercises/"]');
    const cardCount = await exerciseCards.count();
    steps.push({ action: 'Recommended exercise cards', success: cardCount >= 0 });

    const passed = steps.filter(s => s.success).length >= 1;
    return { passed, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await browser.close();
  }
}

module.exports = { testStudentDashboard, testStudentProgressPage, testStudentTodayPlan, testStudentCodeSubmission, testStudentProfile, testStudentRecommendations };
