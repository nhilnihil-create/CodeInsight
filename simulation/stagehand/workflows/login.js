/**
 * simulation/stagehand/workflows/login.js
 *
 * Login flow tests using Playwright.
 */

const { createBrowser, login, PERSONAS } = require('../config');

async function testInstructorLogin() {
  const { browser, page } = await createBrowser();
  const steps = [];

  try {
    await login(page, PERSONAS.instructor.email, PERSONAS.instructor.password);
    steps.push({ action: 'Login', success: true });

    const url = page.url();
    const passed = url.includes('/instructor');
    steps.push({ action: 'Verify redirect', success: passed, url });

    return { passed, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await browser.close();
  }
}

async function testStudentLogin() {
  const { browser, page } = await createBrowser();
  const steps = [];
  const student = PERSONAS.students[0];

  try {
    await login(page, student.email, student.password);
    steps.push({ action: 'Login', success: true });

    const url = page.url();
    const passed = url.includes('/student');
    steps.push({ action: 'Verify redirect', success: passed, url });

    return { passed, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await browser.close();
  }
}

async function testInvalidLogin() {
  const { browser, page } = await createBrowser();
  const steps = [];

  try {
    await login(page, 'invalid@test.com', 'wrongpassword');
    steps.push({ action: 'Submit invalid credentials', success: true });

    await page.waitForTimeout(2000);
    const url = page.url();
    const stayedOnLogin = url.includes('/login') || !url.includes('/dashboard');
    steps.push({ action: 'Stayed on login page', success: stayedOnLogin, url });

    return { passed: stayedOnLogin, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await browser.close();
  }
}

module.exports = { testInstructorLogin, testStudentLogin, testInvalidLogin };
