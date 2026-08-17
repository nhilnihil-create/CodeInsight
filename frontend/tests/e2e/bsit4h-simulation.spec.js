/**
 * e2e/bsit4h-simulation.spec.js
 *
 * Fast simulation spec — verifies the months-long seeded analytics end to end.
 *
 * The old spec drove 21 real student submissions through the compile pipeline
 * (15-minute timeout). That path is now covered by backend integration tests
 * (cdsIntegration, hiddenTestFlow). This spec instead runs against the
 * deterministic months-long seed (backend/scripts/seed_bsit4h_months.js) and
 * asserts every analytics surface shows coherent, related data — as if the
 * system had been running for ~3 months:
 *
 *   1. Dashboard  → at-risk roster, class trend, KPIs
 *   2. Heatmap    → students × concepts + class averages
 *   3. Reports    → concept mastery (W-4..Now), completion, integrity trends
 *   4. Students   → roster + per-student CDS history
 *   5. Student    → learner's own progress
 *
 * Prereq (once, or after a DB reset):
 *   cd backend && node scripts/seed_bsit4h_months.js
 *
 * Run (backend on :5000 with PLAYWRIGHT=1 to bypass the login rate limiter,
 * Vite dev on :5173):
 *   cd frontend && npx playwright test tests/e2e/bsit4h-simulation.spec.js --project=desktop-chromium
 *
 * The suite runs on the desktop project only (charts assume a wide layout).
 */

import { test, expect } from '@playwright/test';

const INSTRUCTOR = { email: 'instructor@psu.edu', password: 'password123' };
const STUDENT = { email: 'maria@student.psu.edu', password: 'password123' };

// Desktop-only: skip under the mobile emulation project.
test.beforeEach(async ({ page }) => {
  const vp = page.viewportSize();
  if (vp && vp.width < 800) test.skip();
});

// ── Helpers ─────────────────────────────────────────────────────────────────

async function login(page, email, password) {
  await page.goto('/login');
  await page.fill('#email', email);
  await page.fill('#password', password);
  await page.keyboard.press('Enter');
  await page.waitForURL((url) => !url.pathname.startsWith('/login'), { timeout: 20000 });
}

/** Find the BSIT-4H section id via the API (login + list sections). */
async function getBSITSectionId(request) {
  const login = await request.post('/api/auth/login', {
    data: { email: INSTRUCTOR.email, password: INSTRUCTOR.password },
  });
  expect(login.ok()).toBeTruthy();
  const res = await request.get('/api/sections');
  const list = await res.json();
  const sections = Array.isArray(list) ? list : [];
  const hit = sections.find((s) => (s.name || '').includes('BSIT'));
  expect(hit, 'BSIT-4H section must exist — run backend/scripts/seed_bsit4h_months.js').toBeTruthy();
  return hit.id;
}

/** Persist the chosen section so useLastSection picks it on next mount. */
async function selectSection(page, sectionId) {
  await page.evaluate((sid) => localStorage.setItem('codeinsight:lastSection', String(sid)), sectionId);
  await page.reload();
  await page.waitForLoadState('networkidle');
}

// ── Tests ───────────────────────────────────────────────────────────────────

test('01 — seeded data is coherent across every analytics surface (API)', async ({ request }) => {
  const sid = await getBSITSectionId(request);

  // Dashboard: at-risk banner, KPIs, populated 7-day trend
  const dash = await (await request.get(`/api/analytics/instructor/dashboard/${sid}?period=7d`)).json();
  expect(dash.insight?.atRiskCount).toBeGreaterThanOrEqual(5);
  const studentsKpi = (dash.kpis || []).find((k) => k.label === 'Students');
  expect(studentsKpi?.value).toBe(24);
  const nonzeroTrendDays = (dash.trend || []).filter((t) => t.cds > 0).length;
  expect(nonzeroTrendDays).toBeGreaterThanOrEqual(2);

  // Heatmap: full roster × concept grid with class averages
  const hm = await (await request.get(`/api/analytics/heatmap/${sid}`)).json();
  expect(hm.students?.length).toBeGreaterThanOrEqual(20);
  expect(hm.concepts?.length).toBeGreaterThanOrEqual(10);
  const populatedAvgs = Object.values(hm.classAverages || {}).filter((a) => a.avgCDS > 0).length;
  expect(populatedAvgs).toBeGreaterThanOrEqual(5);

  // Concept mastery: every visible week slot has a real point
  const cm = await (await request.get(`/api/analytics/reports/${sid}/concept-mastery?weeks=5`)).json();
  expect(cm.weeks).toEqual(['W-4', 'W-3', 'W-2', 'W-1', 'Now']);
  for (let i = 0; i < 5; i++) {
    expect(cm.concepts.some((c) => c.series[i] > 0), `week ${cm.weeks[i]} has a measurement`).toBeTruthy();
  }
  // Procedural Fundamentals concepts present (the default mastery tab)
  const procedural = cm.concepts.filter((c) =>
    ['datatypes', 'variables', 'strings', 'input-output', 'enums', 'type-casting'].includes(c.id)
  );
  expect(procedural.length).toBeGreaterThanOrEqual(4);

  // Completion: every exercise's buckets close to 100 (rounding allowed)
  const comp = await (await request.get(`/api/analytics/reports/${sid}/completion`)).json();
  expect(comp.length).toBeGreaterThanOrEqual(10);
  for (const row of comp) {
    const sum = row.on_time + row.late + row.missing;
    expect(sum, `${row.exercise} buckets sum to ~100`).toBeGreaterThanOrEqual(99);
    expect(sum).toBeLessThanOrEqual(101);
  }

  // Integrity: flag breakdown + a current-week flag on the timeline
  const it = await (await request.get(`/api/analytics/reports/${sid}/integrity-trends?weeks=5`)).json();
  expect(it.breakdown.length).toBeGreaterThanOrEqual(3);
  expect(it.timeline[4][it.timeline[4].moderate > 0 ? 'moderate' : 'high']).toBeGreaterThanOrEqual(1);

  // At-risk roster / intervention queue
  const queue = await (await request.get(`/api/analytics/alerts/${sid}`)).json();
  expect(queue.atRisk?.length).toBeGreaterThanOrEqual(5);
  expect(queue.totalStudents).toBe(24);

  // Per-student CDS history (multi-month progression)
  const profile = await (await request.get(`/api/analytics/student/${queue.atRisk[0].studentId}/profile`)).json();
  expect(profile.length).toBeGreaterThanOrEqual(10);
  expect(profile.some((p) => p.cds != null)).toBeTruthy();

  // Student side: the learner sees their own concept scores
  const sl = await request.post('/api/auth/login', {
    data: { email: STUDENT.email, password: STUDENT.password },
  });
  expect(sl.ok()).toBeTruthy();
  const ms = await (await request.get(`/api/analytics/my-scores?sectionId=${sid}`)).json();
  expect(Array.isArray(ms) ? ms.length : 0).toBeGreaterThanOrEqual(3);
});

test('02 — instructor dashboard renders the months of analytics (UI)', async ({ page, request }) => {
  const sid = await getBSITSectionId(request);
  await login(page, INSTRUCTOR.email, INSTRUCTOR.password);
  await selectSection(page, sid);

  await page.goto('/instructor/dashboard');
  await expect(page.getByText(/at high risk of failing/i).first()).toBeVisible({ timeout: 15000 });
  // Class trend chart renders a curve
  await expect(page.locator('.recharts-line-curve').first()).toBeVisible({ timeout: 15000 });
  // KPIs reflect the seed
  await expect(page.getByText('At risk').first()).toBeVisible();
});

test('03 — reports mastery/completion/integrity tabs render seeded data (UI)', async ({ page, request }) => {
  const sid = await getBSITSectionId(request);
  await login(page, INSTRUCTOR.email, INSTRUCTOR.password);
  await selectSection(page, sid);

  await page.goto('/instructor/reports');
  // Mastery: trend chart lines + Procedural legend chips
  await expect(page.locator('.recharts-line-curve').first()).toBeVisible({ timeout: 20000 });
  await expect(page.getByText(/Concept mastery/).first()).toBeVisible();
  await expect(page.getByText('Datatypes').first()).toBeVisible({ timeout: 15000 });

  // Completion tab: stacked bars + per-exercise table
  await page.getByRole('tab', { name: 'Completion' }).click();
  await expect(page.getByText(/Submission status/).first()).toBeVisible({ timeout: 15000 });
  await expect(page.getByText('Lab 01 — Even or Odd').first()).toBeVisible({ timeout: 15000 });

  // Integrity tab: flag timeline + breakdown
  await page.getByRole('tab', { name: 'Integrity' }).click();
  await expect(page.getByText(/Integrity flags/).first()).toBeVisible({ timeout: 15000 });
  await expect(page.getByText('HARDCODING').first()).toBeVisible({ timeout: 15000 });
});

test('04 — instructor students page lists the seeded roster (UI)', async ({ page, request }) => {
  const sid = await getBSITSectionId(request);
  await login(page, INSTRUCTOR.email, INSTRUCTOR.password);
  await selectSection(page, sid);

  await page.goto('/instructor/students');
  // A top performer and a struggling student from the seed are both listed
  await expect(page.getByText('Angel Cruz').first()).toBeVisible({ timeout: 15000 });
  await expect(page.getByText('Pedro Ramirez').first()).toBeVisible({ timeout: 15000 });
});

test('05 — student side shows their own months of progress (UI)', async ({ page }) => {
  await login(page, STUDENT.email, STUDENT.password);

  // Section gate: pick the BSIT-4H class card if the picker appears
  const gate = page.getByRole('heading', { name: 'My Classes' });
  const gateShown = await gate.waitFor({ state: 'visible', timeout: 15000 })
    .then(() => true)
    .catch(() => false);
  if (gateShown) {
    const bsitCard = page.locator('div.grid button', { hasText: 'BSIT' }).first();
    if (await bsitCard.count()) {
      await bsitCard.click();
      await page.waitForURL((url) => !url.pathname.includes('select-section'), { timeout: 15000 });
    } else {
      await page.locator('div.grid button').first().click();
      await page.waitForURL((url) => !url.pathname.includes('select-section'), { timeout: 15000 });
    }
  }

  // The learner's Today view surfaces their next action from real CDS data
  await page.goto('/student/today');
  await expect(page.getByText('What').first()).toBeVisible({ timeout: 30000 });
});
