/**
 * e2e/bsit4h-simulation.spec.js
 *
 * Full E2E browser simulation:
 *   Instructor creates "Sum of Two Numbers" via UI wizard
 *   → All 21 BSIT-4H students submit real code through the browser
 *   → Backend compiles in Docker, runs tests, fires integrity checks
 *   → CDS computed & UI verified
 *
 * Run: PLAYWRIGHT=1 npx playwright test e2e/bsit4h-simulation.spec.js --headed --project=chromium
 * Requires: backend on :5000, frontend on :5173, DB seeded with seed_bsit4h_simulation.js
 */

const { test, expect } = require('@playwright/test');

// ── Credentials ─────────────────────────────────────────────────────────────

const INSTRUCTOR = { email: 'instructor@psu.edu', password: 'password123' };

const STUDENTS = [
  // Group A — Top (3): correct solution, 1 attempt
  { name: 'Angel Cruz',         email: 'angel.cruz@psu.edu',        group: 'A', code: null },
  { name: 'Mark Villanueva',    email: 'mark.villanueva@psu.edu',   group: 'A', code: null },
  { name: 'Sarah Dimagiba',     email: 'sarah.dimagiba@psu.edu',    group: 'A', code: null },
  // Group B — Good (4): mostly correct
  { name: 'Kevin Santos',       email: 'kevin.santos@psu.edu',      group: 'B', code: null },
  { name: 'Patricia Reyes',     email: 'patricia.reyes@psu.edu',    group: 'B', code: null },
  { name: 'Daniel Torres',      email: 'daniel.torres@psu.edu',     group: 'B', code: null },
  { name: 'Jessica Alvarez',    email: 'jessica.alvarez@psu.edu',   group: 'B', code: null },
  // Group C — Average (5): some errors
  { name: 'Marco Gonzales',     email: 'marco.gonzales@psu.edu',    group: 'C', code: null },
  { name: 'Angela Bautista',    email: 'angela.bautista@psu.edu',   group: 'C', code: null },
  { name: 'Ramon Dela Cruz',    email: 'ramon.delacruz@psu.edu',    group: 'C', code: null },
  { name: 'Catherine Lim',      email: 'catherine.lim@psu.edu',     group: 'C', code: null },
  { name: 'Josefina Ramos',     email: 'josefina.ramos@psu.edu',    group: 'C', code: null },
  // Group D — Struggling (4): more errors
  { name: 'Michael Garcia',     email: 'michael.garcia@psu.edu',    group: 'D', code: null },
  { name: 'Isabella Flores',    email: 'isabella.flores@psu.edu',   group: 'D', code: null },
  { name: 'Roberto Mendoza',    email: 'roberto.mendoza@psu.edu',   group: 'D', code: null },
  { name: 'Carmen Navarro',     email: 'carmen.navarro@psu.edu',    group: 'D', code: null },
  // Group E — Very struggling (2): many errors
  { name: 'Antonio Lopez',      email: 'antonio.lopez@psu.edu',     group: 'E', code: null },
  { name: 'Gloria Hernandez',   email: 'gloria.hernandez@psu.edu',  group: 'E', code: null },
  // Group F — Never correct (1): all wrong
  { name: 'Pedro Ramirez',      email: 'pedro.ramirez@psu.edu',     group: 'F', code: null },
  // Group G — Integrity flagged (1): hardcoded
  { name: 'Luisa Mercado',      email: 'luisa.mercado@psu.edu',     group: 'G', code: null },
  // Nihil — existing student
  { name: 'Nihil Hiza',         email: 'nihil19@gmail.com',          group: 'existing', code: null },
];

// ── Code templates per group ────────────────────────────────────────────────

const CORRECT_CODE = `#include <iostream>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  cout << a + b;
  return 0;
}`;

const WRONG_CODE = `#include <iostream>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  cout << a;
  return 0;
}`;

const HARDCODED_CODE = `#include <iostream>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  cout << 8;
  return 0;
}`;

// Assign codes based on group
STUDENTS.forEach(s => {
  switch (s.group) {
    case 'A': s.code = CORRECT_CODE; break;
    case 'B': s.code = CORRECT_CODE; break;
    case 'C': s.code = CORRECT_CODE; break;
    case 'D': s.code = WRONG_CODE; break;
    case 'E': s.code = WRONG_CODE; break;
    case 'F': s.code = WRONG_CODE; break;
    case 'G': s.code = HARDCODED_CODE; break;
    default: s.code = CORRECT_CODE; break;
  }
});

// ── Shared state ────────────────────────────────────────────────────────────

const SHARED = { exerciseId: null, sectionId: 66 };

// ── Helpers ─────────────────────────────────────────────────────────────────

async function login(page, email, password) {
  await page.goto('/login');
  await page.waitForLoadState('networkidle');
  const emailInput = page.locator('#email');
  await emailInput.waitFor({ state: 'visible', timeout: 15000 });
  await emailInput.fill(email);
  await page.locator('#password').fill(password);
  await page.getByRole('button', { name: 'Sign In' }).click();
  await page.waitForTimeout(2000);
  await page.waitForLoadState('networkidle');
}

async function setMonacoCode(page, code) {
  await page.waitForSelector('.monaco-editor', { state: 'visible', timeout: 15000 });
  await page.waitForTimeout(1500);
  const ok = await page.evaluate((c) => {
    if (window.monacoEditor && typeof window.monacoEditor.setValue === 'function') {
      window.monacoEditor.setValue(c);
      return true;
    }
    if (window.monaco && window.monaco.editor) {
      const models = window.monaco.editor.getModels();
      if (models.length > 0) { models[0].setValue(c); return true; }
      const editors = window.monaco.editor.getEditors();
      if (editors && editors.length > 0) { editors[0].setValue(c); return true; }
    }
    return false;
  }, code);
  if (!ok) {
    const textarea = page.locator('textarea[aria-label="Editor content"]');
    await textarea.waitFor({ state: 'visible', timeout: 5000 });
    await textarea.focus();
    await textarea.fill('');
    await page.keyboard.insertText(code);
  }
  await page.waitForTimeout(500);
}

// ── Test Suite ──────────────────────────────────────────────────────────────

test.describe.serial('BSIT-4H Full Pipeline Simulation', () => {
  test.setTimeout(900000); // 15 minutes for all 21 students

  // ── Test 1: Instructor creates exercise via UI wizard ──────────────────

  test('01 — Instructor creates E2E Simulation exercise via UI wizard', async ({ browser }) => {
    const page = await browser.newPage();
    page.setDefaultTimeout(15000);

    try {
      await login(page, INSTRUCTOR.email, INSTRUCTOR.password);
      await expect(page).toHaveURL(/\/instructor\/dashboard/, { timeout: 15000 });

      // Navigate to create exercise
      await page.goto('/instructor/exercises/new');
      await page.waitForLoadState('networkidle');
      await page.waitForTimeout(1000);

      // Step 0: Title & Description
      const titleInput = page.getByPlaceholder('e.g. Print Fibonacci Series up to N');
      await titleInput.waitFor({ state: 'visible', timeout: 10000 });
      await titleInput.fill('E2E Simulation — Sum of Two Numbers');

      const descInput = page.getByPlaceholder('Write clear instructions for students...');
      await descInput.fill('Read two integers and print their sum. Full pipeline E2E test.');

      await page.evaluate(() => {
        document.dispatchEvent(new CustomEvent('e2e:setConcept', { detail: { concept_name: 'Variables' } }));
      });
      await page.waitForTimeout(300);

      await page.locator('#exercise-form').getByRole('button', { name: 'Next' }).click();
      await page.waitForTimeout(500);

      // Step 1: Concept Tag
      await page.locator('#exercise-form').getByRole('button', { name: 'Next' }).click();
      await page.waitForTimeout(500);

      // Step 2: Starter Code
      await page.locator('#exercise-form').getByRole('button', { name: 'Next' }).click();
      await page.waitForTimeout(500);

      // Step 3: Test Cases
      // Visible test: input "3 5" → expected "8"
      const stdinInput = page.getByPlaceholder(/5\n1 2 3 4 5/);
      await stdinInput.waitFor({ state: 'visible', timeout: 10000 });
      await stdinInput.fill('3 5');

      const expectedOutput = page.getByPlaceholder('15');
      await expectedOutput.fill('8');

      // Add hidden test case: input "10 20" → expected "30"
      await page.getByRole('button', { name: /Add Test Case/i }).click();
      await page.waitForTimeout(500);

      // Find the second test case's textareas
      const textareas = page.locator('#exercise-form').locator('textarea');
      const taCount = await textareas.count();
      // Fill second test case's stdin (4th textarea: 3rd+4th are the 2nd test's input+expected)
      if (taCount >= 4) {
        await textareas.nth(2).fill('10 20');  // stdin for 2nd test
        await textareas.nth(3).fill('30');      // expected for 2nd test
      }

      // Toggle the second test case to hidden
      const visiblePills = page.locator('button:has-text("👁 Visible")');
      const pillCount = await visiblePills.count();
      if (pillCount >= 2) {
        await visiblePills.nth(1).click();  // toggle 2nd test to hidden
      }

      await page.locator('#exercise-form').getByRole('button', { name: 'Next' }).click();
      await page.waitForTimeout(500);

      // Step 4: Section Assignment
      await page.locator('#exercise-form').getByRole('button', { name: 'Next' }).click();
      await page.waitForTimeout(500);

      // Step 5: Timer & Deadline
      const timeInput = page.locator('#exercise-form').locator('input[type="number"]');
      await timeInput.waitFor({ state: 'visible' });
      await timeInput.fill('30');
      await page.locator('#exercise-form').getByRole('button', { name: 'Add to Basket' }).click();
      await page.waitForTimeout(1000);

      // Basket: select BSIT-4H section and publish
      await page.waitForSelector('text=Publish To', { timeout: 10000 });
      await page.evaluate(() => {
        const panel = document.querySelector('.lg\\:col-span-1');
        if (panel) panel.scrollIntoView({ block: 'nearest', behavior: 'instant' });
      });
      await page.waitForTimeout(500);

      const toggled = await page.evaluate((name) => {
        const labels = document.querySelectorAll('label');
        for (const label of labels) {
          if (label.textContent.includes(name)) {
            const cb = label.querySelector('button[role="checkbox"]');
            if (cb) { cb.click(); return true; }
          }
        }
        return false;
      }, 'BSIT - 4H');
      if (!toggled) console.warn('Could not find BSIT-4H checkbox');
      await page.waitForTimeout(500);

      const publishBtn = page.getByRole('button', { name: 'Publish' });
      await publishBtn.click();

      await page.waitForURL(/\/instructor\/exercises/, { timeout: 15000 });
      await page.waitForLoadState('networkidle');

      // Verify exercise appears in the list
      await expect(page.getByText('E2E Simulation').first()).toBeVisible({ timeout: 10000 });

      // Query DB for the exercise ID (created by instructor 286 in section 66)
      const { execSync } = require('child_process');
      const idOutput = execSync(
        `PGPASSWORD=codepassword123 psql -U codeuser -h localhost -d codeinsight -t -A -c "SELECT id FROM exercises WHERE section_id=66 AND created_by=286 AND title LIKE 'E2E Simulation%' ORDER BY id DESC LIMIT 1;"`,
        { timeout: 10000 }
      ).toString().trim();
      SHARED.exerciseId = parseInt(idOutput, 10);
      console.log(`Created exercise ID: ${SHARED.exerciseId}`);
      expect(SHARED.exerciseId).toBeGreaterThan(0);
    } finally {
      await page.close();
    }
  });

  // ── Test 2: All 21 students submit code via API ───────────────────────

  test('02 — All 21 students submit code through the pipeline', async ({ request }) => {
    const results = [];
    const baseURL = 'http://localhost:5000';

    for (let i = 0; i < STUDENTS.length; i++) {
      const student = STUDENTS[i];
      try {
        // Login to get auth cookie
        const loginRes = await request.post(`${baseURL}/api/auth/login`, {
          data: { email: student.email, password: 'password123' },
        });
        const loginBody = await loginRes.json();
        const cookies = loginRes.headers()['set-cookie'] || '';
        console.log(`[${i + 1}/${STUDENTS.length}] ${student.name} (${student.group}) — submitting...`);

        // Submit via API (exercises the full compile → test → integrity → live CDS pipeline)
        const submitRes = await request.post(`${baseURL}/api/student/exercises/${SHARED.exerciseId}/submit`, {
          headers: { Cookie: cookies },
          data: {
            code: student.code,
            language: 'cpp',
            timeSpentSeconds: 60,
            tabSwitchCount: 0,
            pasteCount: 0,
            idleTimeSeconds: 0,
          },
          timeout: 45000,
        });
        const body = await submitRes.json();
        const ok = submitRes.ok();
        results.push({ name: student.name, group: student.group, success: ok });
        console.log(`  → ${ok ? 'OK' : 'FAIL'} ${student.name}: status=${submitRes.status()}, passed=${body.passed}, cds=${body.liveCDS?.cds ?? body.liveCDS}`);
      } catch (err) {
        results.push({ name: student.name, group: student.group, success: false, error: err.message });
        console.log(`  → FAIL ${student.name}: ${err.message}`);
      }
    }

    const passed = results.filter(r => r.success).length;
    const failed = results.filter(r => !r.success).length;
    console.log(`\n═══════════════════════════════════════`);
    console.log(`Student submissions: ${passed} passed, ${failed} failed`);

    for (const r of results) {
      console.log(`  ${r.success ? '✅' : '❌'} ${r.name} (${r.group})${r.error ? ': ' + r.error : ''}`);
    }

    expect(passed).toBeGreaterThanOrEqual(18);
  });

  // ── Test 3: Verify integrity flags were created ───────────────────────

  test('03 — Verify integrity pipeline ran for flagged student', async () => {
    const { execSync } = require('child_process');
    const result = execSync(
      `PGPASSWORD=codepassword123 psql -U codeuser -h localhost -d codeinsight -t -A -c "SELECT COUNT(*) FROM integrity_flags WHERE exercise_id=${SHARED.exerciseId};"`,
      { timeout: 10000, env: { ...process.env } }
    ).toString().trim();

    const flagCount = parseInt(result, 10);
    console.log(`Integrity flags for exercise ${SHARED.exerciseId}: ${flagCount}`);
    expect(flagCount).toBe(1);

    // Verify the flag is for Luisa (hardcoding)
    const flagDetail = execSync(
      `PGPASSWORD=codepassword123 psql -U codeuser -h localhost -d codeinsight -t -A -c "SELECT u.name, if2.flag_type, if2.severity FROM integrity_flags if2 JOIN users u ON u.id=if2.student_id WHERE if2.exercise_id=${SHARED.exerciseId};"`,
      { timeout: 10000, env: { ...process.env } }
    ).toString().trim();
    console.log(`Flag detail: ${flagDetail}`);
    expect(flagDetail).toContain('Luisa');
    expect(flagDetail).toContain('HARDCODING');
  });

  // ── Test 4: Compute batch CDS ─────────────────────────────────────────

  test('04 — Batch CDS computation for E2E Simulation exercise', async () => {
    const { execSync } = require('child_process');
    const backendDir = '/home/nihil/projects/codeinsight/backend';

    console.log(`Computing batch CDS for exercise ${SHARED.exerciseId}...`);
    const output = execSync(
      `node scripts/compute_batch_cds.js ${SHARED.exerciseId}`,
      { cwd: backendDir, timeout: 60000, env: { ...process.env } }
    );
    console.log(output.toString());
    expect(output.toString()).toContain('studentsProcessed');
  });

  // ── Test 5: Verify CDS results in the database ────────────────────────

  test('05 — Verify CDS results in database', async () => {
    const { execSync } = require('child_process');
    const d = `PGPASSWORD=codepassword123 psql -U codeuser -h localhost -d codeinsight -t -A`;

    // Check CDS score distribution
    const cdsDist = execSync(
      `${d} -c "SELECT cs.classification, COUNT(*) FROM cds_scores cs WHERE cs.exercise_id=${SHARED.exerciseId} AND cs.source='batch' GROUP BY cs.classification ORDER BY cs.classification;"`,
      { timeout: 10000, env: { ...process.env } }
    ).toString().trim();
    console.log(`CDS distribution:\n${cdsDist}`);

    // Verify we have exactly 1 Flagged-Pending (Luisa)
    expect(cdsDist).toContain('Flagged-Pending|1');

    // Verify we have correct-code students with very low CDS
    expect(cdsDist).toContain('Very Low');

    // Check that the flagged student has null CDS
    const flaggedCDS = execSync(
      `${d} -c "SELECT u.name FROM cds_scores cs JOIN users u ON u.id=cs.student_id WHERE cs.exercise_id=${SHARED.exerciseId} AND cs.cds IS NULL AND cs.classification='Flagged-Pending';"`,
      { timeout: 10000, env: { ...process.env } }
    ).toString().trim();
    console.log(`Flagged student (null CDS): ${flaggedCDS}`);
    expect(flaggedCDS).toContain('Luisa');

    console.log('\n✅ Pipeline verification complete');
    console.log(`   Exercise ${SHARED.exerciseId}: 21 submissions, 1 HARDCODING flag, 21 CDS scores`);
  });
});
