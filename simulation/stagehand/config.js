/**
 * simulation/stagehand/config.js
 *
 * Playwright-based user testing with natural language-style helpers.
 * Lightweight: 3 students + 1 instructor, headless Chromium.
 */

const { chromium } = require('playwright');

const BASE_URL = process.env.BASE_URL || 'http://localhost:5173';

// Test personas (matching existing test credentials)
const PERSONAS = {
  instructor: {
    name: 'Test Instructor',
    email: 'instructor@psu.edu',
    password: 'password123',
    role: 'instructor',
  },
  students: [
    { name: 'Maria', email: 'maria@student.psu.edu', password: 'password123', tier: 'high' },
    { name: 'Alex', email: 'alex@student.psu.edu', password: 'password123', tier: 'medium' },
    { name: 'Jordan', email: 'jordan@student.psu.edu', password: 'password123', tier: 'struggling' },
  ],
};

/**
 * Launch browser and create a new page.
 * @param {Object} options
 * @returns {Promise<{browser: any, page: any}>}
 */
async function createBrowser({ headless = true } = {}) {
  const browser = await chromium.launch({ headless });
  const context = await browser.newContext({
    viewport: { width: 1280, height: 720 },
  });
  const page = await context.newPage();
  return { browser, page };
}

/**
 * Login helper - navigates and fills credentials.
 * @param {any} page - Playwright page
 * @param {string} email
 * @param {string} password
 */
async function login(page, email, password) {
  await page.goto(`${BASE_URL}/login`);
  await page.waitForLoadState('networkidle');

  // Fill email - try multiple selectors
  const emailInput = page.locator('input[type="email"], input[name="email"], input[placeholder*="email" i]').first();
  await emailInput.fill(email);

  // Fill password
  const passwordInput = page.locator('input[type="password"], input[name="password"]').first();
  await passwordInput.fill(password);

  // Click sign in
  const submitBtn = page.locator('button[type="submit"], button:has-text("Sign In"), button:has-text("Login")').first();
  await submitBtn.click();

  // Wait for navigation
  await page.waitForTimeout(3000);
}

/**
 * Navigate to a page by clicking a nav link or going to URL.
 * @param {any} page - Playwright page
 * @param {string} path - URL path
 */
async function navigateTo(page, path) {
  await page.goto(`${BASE_URL}${path}`);
  await page.waitForLoadState('networkidle');
  await page.waitForTimeout(1000);
}

/**
 * Check if page has visible content.
 * @param {any} page - Playwright page
 * @returns {Promise<boolean>}
 */
async function hasPageContent(page) {
  try {
    // Check for common content indicators
    const hasMain = await page.locator('main, [role="main"], .content, #root > div').first().isVisible({ timeout: 3000 });
    const hasText = await page.locator('h1, h2, h3, p, span').first().isVisible({ timeout: 3000 });
    return hasMain || hasText;
  } catch {
    return false;
  }
}

module.exports = { createBrowser, login, navigateTo, hasPageContent, PERSONAS, BASE_URL };
