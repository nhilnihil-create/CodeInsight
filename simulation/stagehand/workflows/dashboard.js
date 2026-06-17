/**
 * simulation/stagehand/workflows/dashboard.js
 *
 * Dashboard navigation tests using Playwright.
 */

const { createBrowser, login, navigateTo, hasPageContent, PERSONAS } = require('../config');

const INSTRUCTOR_ROUTES = [
  { path: '/instructor/dashboard', name: 'Dashboard' },
  { path: '/instructor/heatmap', name: 'Heatmap' },
  { path: '/instructor/students', name: 'Students' },
  { path: '/instructor/exercises', name: 'Exercises' },
  { path: '/instructor/reports', name: 'Reports' },
  { path: '/instructor/integrity', name: 'Integrity' },
];

const STUDENT_ROUTES = [
  { path: '/student/dashboard', name: 'My Exercises' },
  { path: '/student/progress', name: 'My Progress' },
  { path: '/student/profile', name: 'My Profile' },
];

async function testInstructorNavigation() {
  const { browser, page } = await createBrowser();
  const results = [];

  try {
    await login(page, PERSONAS.instructor.email, PERSONAS.instructor.password);

    for (const route of INSTRUCTOR_ROUTES) {
      try {
        await navigateTo(page, route.path);
        const visible = await hasPageContent(page);
        results.push({ page: route.name, passed: visible });
      } catch (error) {
        results.push({ page: route.name, passed: false, error: error.message });
      }
    }

    return { passed: results.every(r => r.passed), results };
  } catch (error) {
    return { passed: false, results, error: error.message };
  } finally {
    await browser.close();
  }
}

async function testStudentNavigation() {
  const { browser, page } = await createBrowser();
  const results = [];
  const student = PERSONAS.students[0];

  try {
    await login(page, student.email, student.password);

    for (const route of STUDENT_ROUTES) {
      try {
        await navigateTo(page, route.path);
        const visible = await hasPageContent(page);
        results.push({ page: route.name, passed: visible });
      } catch (error) {
        results.push({ page: route.name, passed: false, error: error.message });
      }
    }

    return { passed: results.every(r => r.passed), results };
  } catch (error) {
    return { passed: false, results, error: error.message };
  } finally {
    await browser.close();
  }
}

module.exports = { testInstructorNavigation, testStudentNavigation };
