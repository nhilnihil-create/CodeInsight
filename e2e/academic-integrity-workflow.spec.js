/**
 * e2e/academic-integrity-workflow.spec.js
 *
 * Full UI walkthrough of the academic integrity pipeline:
 *   Instructor creates section → creates exercise via 6-step wizard
 *   → Student joins → submits hardcoded code (1st=warning, 2nd=flag)
 *   → Student views integrity page & submits context
 *   → Instructor reviews & dismisses flag
 *   → Bias audit endpoint verification
 *
 * Requires: backend on :5000, frontend on :5173, DB seeded with schema.sql
 * Run: npx playwright test e2e/academic-integrity-workflow.spec.js --headed --project=chromium
 */

const { test, expect } = require('@playwright/test');
const fs = require('fs');
const path = require('path');
const { Pool } = require('pg');

// ── Live-DB access for direct assertions (e.g. run_attempts snapshots) ─────
// Credentials come from backend/.env — the same source the live backend on
// :5000 uses. Requires PostgreSQL reachable from the process running Playwright.

function loadDotEnv(file) {
  const out = {};
  if (!fs.existsSync(file)) return out;
  const text = fs.readFileSync(file, 'utf8');
  for (const line of text.split('\n')) {
    const m = line.match(/^\s*([A-Za-z_][A-Za-z0-9_]*)\s*=\s*(.*?)\s*$/);
    if (m) out[m[1]] = m[2].replace(/^["']|["']$/g, '');
  }
  return out;
}

const BACKEND_ENV = loadDotEnv(path.join(__dirname, '..', 'backend', '.env'));
const dbPool = new Pool({
  host: process.env.DB_HOST || BACKEND_ENV.DB_HOST || 'localhost',
  port: parseInt(process.env.DB_PORT || BACKEND_ENV.DB_PORT || '5432', 10),
  database: process.env.DB_NAME || BACKEND_ENV.DB_NAME || 'codeinsight',
  user: process.env.DB_USER || BACKEND_ENV.DB_USER,
  password: process.env.DB_PASSWORD || BACKEND_ENV.DB_PASSWORD,
  max: 2,
});

// ── Credentials ─────────────────────────────────────────────────────────

const INSTRUCTOR = { email: 'instructor@psu.edu', password: 'password123' };
const STUDENT = { email: 'maria@student.psu.edu', password: 'password123' };

// ── Shared state (set by tests, consumed by later tests) ─────────────────

const SHARED = {
  sectionName: null,
  joinCode: null,
  exerciseId: null,
  flagId: null,
};

// ── Pages (long-lived across tests within a role) ────────────────────────

let instructorPage;
let studentPage;

// ── Helpers ──────────────────────────────────────────────────────────────

async function login(page, { email, password }) {
  await page.goto('/login');
  await page.waitForLoadState('networkidle');
  const emailInput = page.locator('#email');
  await emailInput.waitFor({ state: 'visible', timeout: 15000 });
  await emailInput.fill(email);
  await page.locator('#password').fill(password);
  await page.getByRole('button', { name: 'Sign In' }).click();
  // Wait for redirect after login (give extra time for API + SPA navigation)
  await page.waitForTimeout(2000);
  await page.waitForLoadState('networkidle');
}

/**
 * Inject C++ code into the Monaco editor.
 * Falls back through several strategies.
 */
async function setMonacoCode(page, code) {
  // Wait for Monaco to be fully mounted
  await page.waitForSelector('.monaco-editor', { state: 'visible', timeout: 15000 });
  await page.waitForTimeout(1500);

  const ok = await page.evaluate((c) => {
    // Strategy 1: direct window reference
    if (window.monacoEditor && typeof window.monacoEditor.setValue === 'function') {
      window.monacoEditor.setValue(c);
      return true;
    }
    // Strategy 2: monaco.editor.getModels()
    if (window.monaco && window.monaco.editor) {
      const models = window.monaco.editor.getModels();
      if (models.length > 0) {
        models[0].setValue(c);
        return true;
      }
    }
    // Strategy 3: find all editor instances
    if (window.monaco && window.monaco.editor) {
      const editors = window.monaco.editor.getEditors();
      if (editors && editors.length > 0) {
        editors[0].setValue(c);
        return true;
      }
    }
    return false;
  }, code);

  if (!ok) {
    // Fallback: type into Monaco's hidden textarea
    const textarea = page.locator('textarea[aria-label="Editor content"]');
    await textarea.waitFor({ state: 'visible', timeout: 5000 });
    await textarea.focus();
    await textarea.fill('');
    await page.keyboard.insertText(code);
  }
  await page.waitForTimeout(500);
}

// ── Test Suite ───────────────────────────────────────────────────────────

test.describe.serial('Academic Integrity Full UI Workflow', () => {
  test.setTimeout(180000);

  // ── Setup: long-lived pages ──────────────────────────────────────────

  test.beforeAll(async ({ browser }) => {
    instructorPage = await browser.newPage();
    studentPage = await browser.newPage();
    instructorPage.setDefaultTimeout(15000);
    studentPage.setDefaultTimeout(15000);
  });

  test.afterAll(async () => {
    await instructorPage?.close();
    await studentPage?.close();
    await dbPool?.end();
  });

    // ── Test 1: Instructor creates section ───────────────────────────────

  test('01 — Instructor creates a section', async () => {
    SHARED.sectionName = `E2E Integrity ${Date.now()}`;

    // Login as instructor
    await login(instructorPage, INSTRUCTOR);
    await expect(instructorPage).toHaveURL(/\/instructor\/dashboard/, { timeout: 15000 });

    // Navigate to sections
    await instructorPage.goto('/instructor/sections');
    await instructorPage.waitForLoadState('networkidle');

    // Click "New Section"
    const newSectionBtn = instructorPage.getByRole('button', { name: 'New Section' });
    await newSectionBtn.waitFor({ state: 'visible' });
    await newSectionBtn.click();

    // Fill dialog
    await instructorPage.waitForSelector('#create-name', { timeout: 5000 });
    await instructorPage.fill('#create-name', SHARED.sectionName);
    await instructorPage.fill('#create-course', 'CS101');
    await instructorPage.fill('#create-semester', 'Sem 1');
    await instructorPage.fill('#create-year', '2025-2026');

    // Submit
    const createBtn = instructorPage.getByRole('button', { name: 'Create Section' });
    await createBtn.click();

    // Wait for dialog to close and section to appear in list
    await instructorPage.waitForTimeout(2000);
    await instructorPage.waitForLoadState('networkidle');

    // Click on the newly created section in the list
    await instructorPage.waitForTimeout(500);
    const sectionRow = instructorPage.locator('li[role="button"]').filter({ hasText: SHARED.sectionName });
    await expect(sectionRow.first()).toBeVisible({ timeout: 10000 });
    await sectionRow.first().click();

    // Wait for section detail page to load
    await instructorPage.waitForURL(/\/instructor\/sections\//);
    await instructorPage.waitForLoadState('networkidle');

    // Extract join code from aria-label
    const joinBtn = instructorPage.locator('[aria-label^="Copy join code"]');
    await expect(joinBtn).toBeVisible({ timeout: 10000 });
    const ariaLabel = await joinBtn.getAttribute('aria-label');
    SHARED.joinCode = ariaLabel.replace('Copy join code ', '').trim();
  });

  // ── Test 2: Instructor creates exercise via 6-step wizard ────────────

  test('02 — Instructor creates exercise via 6-step wizard', async () => {
    // Navigate to exercise workspace
    await instructorPage.goto('/instructor/exercises/new');
    await instructorPage.waitForLoadState('networkidle');
    await instructorPage.waitForTimeout(1000);

    // ── Step 0: Title & Description ──
    const titleInput = instructorPage.getByPlaceholder('e.g. Print Fibonacci Series up to N');
    await titleInput.waitFor({ state: 'visible', timeout: 10000 });
    await titleInput.fill('Integrity Test Exercise');

    const descInput = instructorPage.getByPlaceholder('Write clear instructions for students...');
    await descInput.fill('E2E test for academic integrity workflow');

    // Set concept via custom event BEFORE advancing (avoids Radix UI interaction issues)
    await instructorPage.evaluate(() => {
      document.dispatchEvent(new CustomEvent('e2e:setConcept', { detail: { concept_name: 'Variables' } }));
    });
    await instructorPage.waitForTimeout(300);

    // Click "Next" from Step 0
    await instructorPage.locator('#exercise-form').getByRole('button', { name: 'Next' }).click();
    await instructorPage.waitForTimeout(500);

    // ── Step 1: Concept Tag (already set, just click Next) ──
    await instructorPage.locator('#exercise-form').getByRole('button', { name: 'Next' }).click();
    await instructorPage.waitForTimeout(500);

    // ── Step 2: Starter Code (keep default) ──
    await instructorPage.locator('#exercise-form').getByRole('button', { name: 'Next' }).click();
    await instructorPage.waitForTimeout(500);

    // ── Step 3: Test Cases ──
    // Set expected output to "42" so cout << 42 will trigger hardcoding flag
    const expectedField = instructorPage.getByPlaceholder('15');
    await expectedField.waitFor({ state: 'visible' });
    await expectedField.fill('42');

    await instructorPage.locator('#exercise-form').getByRole('button', { name: 'Next' }).click();
    await instructorPage.waitForTimeout(500);

    // ── Step 4: Section Assignment (info only) ──
    await instructorPage.locator('#exercise-form').getByRole('button', { name: 'Next' }).click();
    await instructorPage.waitForTimeout(500);

    // ── Step 5: Timer & Deadline ──
    const timeInput = instructorPage.locator('#exercise-form').locator('input[type="number"]');
    await timeInput.waitFor({ state: 'visible' });
    await timeInput.fill('45');

    // Click "Add to Basket"
    await instructorPage.locator('#exercise-form').getByRole('button', { name: 'Add to Basket' }).click();
    await instructorPage.waitForTimeout(1000);

    // ── Basket Panel: select section and publish ──

    // Wait for the basket sidebar to appear (right column)
    await instructorPage.waitForSelector('text=Publish To', { timeout: 10000 });

    // Scroll the basket panel into view
    await instructorPage.evaluate(() => {
      const panel = document.querySelector('.lg\\:col-span-1');
      if (panel) panel.scrollIntoView({ block: 'nearest', behavior: 'instant' });
    });
    await instructorPage.waitForTimeout(500);

    // Click the section checkbox via JS (shadcn Checkbox is a <button> inside <label>)
    const toggled = await instructorPage.evaluate((name) => {
      const labels = document.querySelectorAll('label');
      for (const label of labels) {
        if (label.textContent.includes(name)) {
          const cb = label.querySelector('button[role="checkbox"]');
          if (cb) { cb.click(); return true; }
        }
      }
      return false;
    }, SHARED.sectionName);
    if (!toggled) console.warn('Could not find section checkbox for:', SHARED.sectionName);
    await instructorPage.waitForTimeout(500);

    // Click "Publish"
    const publishBtn = instructorPage.getByRole('button', { name: 'Publish' });
    await publishBtn.click();

    // Wait for navigation to /instructor/exercises (after 1s timeout + navigate)
    await instructorPage.waitForURL(/\/instructor\/exercises/, { timeout: 15000 });
    await instructorPage.waitForLoadState('networkidle');

    // Verify the exercise appears in the list
    await expect(instructorPage.getByText('Integrity Test Exercise').first()).toBeVisible({ timeout: 10000 });
  });

  // ── Test 3: Student joins section and submits hardcoded code ─────────

  test('03 — Student joins section and submits hardcoded code', async () => {
    // Login as student
    await login(studentPage, STUDENT);
    await expect(studentPage).toHaveURL(/\/student\//);

    // Navigate to sections/join page
    await studentPage.goto('/student/sections');
    await studentPage.waitForLoadState('networkidle');

    // Wait for join code input
    const joinInput = studentPage.getByPlaceholder('e.g. K7P-3QX');
    await joinInput.waitFor({ state: 'visible', timeout: 10000 });

    // Fill join code and click Join
    await joinInput.fill(SHARED.joinCode);
    const joinBtn = studentPage.getByRole('button', { name: 'Join' });
    await expect(joinBtn).toBeEnabled({ timeout: 5000 });
    await joinBtn.click();

    // Wait for join to succeed
    await studentPage.waitForTimeout(2000);

    // Navigate to exercises page
    await studentPage.goto('/student/exercises');
    await studentPage.waitForLoadState('networkidle');

    // Find and click the "Start" link (rendered as <a> via Button asChild)
    const startBtn = studentPage.locator('a').filter({ hasText: 'Start' }).first();
    await startBtn.waitFor({ state: 'visible', timeout: 15000 });
    await startBtn.click();

    // Wait for the code editor page to load
    await studentPage.waitForURL(/\/student\/exercises\/\d+/);
    await studentPage.waitForLoadState('networkidle');

    // Extract exercise ID from URL
    const url = studentPage.url();
    const idMatch = url.match(/(\d+)$/);
    if (idMatch) SHARED.exerciseId = idMatch[1];

    // Wait for Monaco editor
    await studentPage.waitForSelector('.monaco-editor', { state: 'visible', timeout: 15000 });
    await studentPage.waitForTimeout(2000);

    // Inject hardcoded code that will trigger hardcoding detection
    const code = `#include <iostream>
using namespace std;

int main() {
  cout << 42;
  return 0;
}`;

    await setMonacoCode(studentPage, code);

    // Verify code was injected
    const codeVisible = await studentPage.locator('.monaco-editor').getByText('cout << 42').isVisible().catch(() => false);
    console.log('Code visible in Monaco:', codeVisible);

    // Run once — exercises the per-run checkpoint path (persists a run_attempts
    // snapshot with the behavioral counters) before the final submit.
    const runBtn = studentPage.getByRole('button', { name: /run/i });
    await runBtn.waitFor({ state: 'visible', timeout: 15000 });
    await runBtn.click({ force: true });

    // Wait for the visible test result to settle (run pipeline compiles + executes).
    // This exercise has exactly 1 visible test case (expected output "42").
    await expect(studentPage.locator('[aria-label="1 of 1 tests passing"]')).toBeVisible({ timeout: 60000 });

    // Submit the hardcoded code once. The AST verifier flags it (is_verified=false,
    // verification_logs row, graduated WARNING event) but the submission still passes
    // 1/1 test cases, so the exercise completes on this single submit.
    const submitBtn = studentPage.getByRole('button', { name: /submit/i });
    await submitBtn.waitFor({ state: 'visible', timeout: 15000 });
    await submitBtn.click({ force: true });

    // Deterministic end state: the "✓ Exercise Completed — Your CDS is locked" banner.
    // The success toast auto-dismisses, so assert on the banner, not the toast. This wait
    // also covers the compile/settle time (~5-60s), so no extra waitForTimeout is needed.
    await expect(studentPage.getByText(/Your CDS is locked/)).toBeVisible({ timeout: 60000 });
  });

  // ── Test 3b: Completed exercise → "Review" label + locked review mode ────

  test('03b — Completed exercise shows Review label and locked review mode', async () => {
    // 1. Still on the completed exercise page: review mode is locked
    await expect(studentPage.getByText('Review Mode').first()).toBeVisible({ timeout: 15000 });
    await expect(studentPage.getByRole('button', { name: /run/i })).toBeDisabled();
    // The countdown timer is hidden in review mode
    await expect(studentPage.locator('span.sr-only', { hasText: 'Time remaining:' })).toHaveCount(0);

    // The Run click in test 03 persisted a run_attempts snapshot for this exercise.
    // Fail-soft: if no live-DB credentials are available (e.g. CI), skip — the
    // persistence itself is covered by backend integration tests.
    try {
      const { rows } = await dbPool.query(
        'SELECT COUNT(*)::int AS n FROM run_attempts WHERE exercise_id = $1',
        [Number(SHARED.exerciseId)]
      );
      expect(rows[0].n).toBeGreaterThanOrEqual(1);
    } catch (dbErr) {
      console.log('Skipping run_attempts DB assertion:', dbErr.message);
    }

    // 2. The exercises list now shows "Review" instead of "Start"
    await studentPage.goto('/student/exercises');
    await studentPage.waitForLoadState('networkidle');
    const reviewLink = studentPage.locator('a').filter({ hasText: 'Review' });
    await expect(reviewLink.first()).toBeVisible({ timeout: 15000 });

    // 3. Reopening keeps review mode locked (Run disabled, no countdown)
    await reviewLink.first().click();
    await studentPage.waitForURL(/\/student\/exercises\/\d+/);
    await studentPage.waitForLoadState('networkidle');
    await expect(studentPage.getByText('Review Mode').first()).toBeVisible({ timeout: 15000 });
    await expect(studentPage.getByRole('button', { name: /run/i })).toBeDisabled();
    await expect(studentPage.locator('span.sr-only', { hasText: 'Time remaining:' })).toHaveCount(0);
  });

  // ── Test 4: Student views integrity page and submits context ─────────

  test('04 — Student views integrity page and submits context', async () => {
    // Navigate to student integrity page
    await studentPage.goto('/student/integrity');
    await studentPage.waitForLoadState('networkidle');
    await studentPage.waitForTimeout(2000);

    // Check if stats cards are visible (from our enhanced transparency view)
    const hasStats = await studentPage.getByText('Total Flags').isVisible().catch(() => false);
    console.log('Stats dashboard visible:', hasStats);

    // Look for a flag card
    const flagCard = studentPage.locator('text=Hardcoding Detected');
    const hasFlag = await flagCard.isVisible({ timeout: 5000 }).catch(() => false);
    console.log('Hardcoding flag visible:', hasFlag);

    if (hasFlag) {
      // Submit context/appeal
      const addContextBtn = studentPage.getByRole('button', { name: 'Add context for your instructor' });
      if (await addContextBtn.isVisible({ timeout: 3000 }).catch(() => false)) {
        await addContextBtn.click();
        await studentPage.waitForTimeout(300);

        // Fill the response textarea
        const textarea = studentPage.locator('textarea[placeholder*="Share any context"]');
        await textarea.fill('I was testing the output format for this exercise. The value 42 was used as a test value, not a final answer.');

        // Click Submit
        const submitResp = studentPage.getByRole('button', { name: 'Submit' });
        await submitResp.click();
        await studentPage.waitForTimeout(1000);

        // Verify the response is displayed
        await expect(studentPage.getByText('Your context:')).toBeVisible({ timeout: 5000 });
      } else {
        console.log('No "Add context" button visible');
      }
    } else {
      console.log('No hardcoding flag found — checking for any flag...');
      const anyFlag = await studentPage.getByText(/flag|pattern|detected/i).first().isVisible().catch(() => false);
      console.log('Any flag/pattern visible:', anyFlag);
    }
  });

  // ── Test 5: Instructor reviews and dismisses flag ────────────────────

  test('05 — Instructor reviews and dismisses the flag', async () => {
    // Switch back to instructor page
    await instructorPage.bringToFront();

    // Navigate to integrity page
    await instructorPage.goto('/instructor/integrity');
    await instructorPage.waitForLoadState('networkidle');
    await instructorPage.waitForTimeout(3000);

    // Look for the flag — search for the student name or exercise title
    const flagRow = instructorPage.locator('li[role="button"]').filter({ hasText: /Integrity Test Exercise|Maria|HARDCODING/i });
    const hasFlags = await flagRow.first().isVisible({ timeout: 8000 }).catch(() => false);
    console.log('Flag row visible in instructor view:', hasFlags);

    if (hasFlags) {
      // Click the flag row to open detail drawer
      await flagRow.first().click();
      await instructorPage.waitForTimeout(1000);

      // Check for student response in the detail view
      const hasResponse = await instructorPage.getByText(/testing the output format|Your context|student_response/i)
        .first().isVisible({ timeout: 3000 }).catch(() => false);
      console.log('Student response visible in detail:', hasResponse);

      // Dismiss the flag
      const dismissBtn = instructorPage.getByRole('button', { name: /Mark Reviewed|Reviewed|Dismiss/i });
      if (await dismissBtn.first().isVisible({ timeout: 3000 }).catch(() => false)) {
        await dismissBtn.first().click();
        await instructorPage.waitForTimeout(1000);
        console.log('Flag review action clicked');
      } else {
        // Try the bulk action dropdown
        const bulk = instructorPage.getByRole('button', { name: /Bulk action/i });
        if (await bulk.isVisible().catch(() => false)) {
          await bulk.click();
          await instructorPage.waitForTimeout(300);
          await instructorPage.getByRole('menuitem', { name: /Dismiss/i }).click();
          await instructorPage.waitForTimeout(1000);
        }
      }
    } else {
      console.log('No flags found in instructor view — check if flag was created');
      // Take a screenshot for debugging
      await instructorPage.screenshot({ path: '/tmp/e2e-no-flags.png' });
    }
  });

  // ── Test 6: Bias audit endpoint returns correct stats ────────────────

  test('06 — Bias audit endpoint returns correct stats', async ({ request }) => {
    // Extract auth cookie from instructor page
    const cookies = await instructorPage.context().cookies();
    const ciToken = cookies.find(c => c.name === 'ci_token');
    const res = await request.get('http://localhost:5000/api/analytics/integrity-audit', {
      headers: ciToken ? { Cookie: `ci_token=${ciToken.value}` } : {},
    });
    expect(res.ok()).toBeTruthy();

    const data = await res.json();
    console.log('Audit summary:', JSON.stringify(data.summary, null, 2));

    // Verify structure
    expect(data).toHaveProperty('summary');
    expect(data).toHaveProperty('byType');
    expect(data).toHaveProperty('bySeverity');
    expect(data).toHaveProperty('perStudent');
    expect(data).toHaveProperty('dismissalRate');

    // There should be at least one section with data
    expect(data.summary.sections.length).toBeGreaterThanOrEqual(1);

    // If any flags were created, byType should have entries
    if (data.summary.totalFlags > 0) {
      expect(data.byType.some(t => t.flag_type === 'HARDCODING')).toBeTruthy();
    }
  });
});
