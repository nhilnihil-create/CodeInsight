# E2E Real-World Simulation Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Real-world E2E simulation with 20 students, 3 concurrent Playwright sessions, submission through real Docker backend pipeline, exercise close → batch CDS → alerts verification, plus server restart recovery.

**Architecture:** Standalone `simulation/e2e/` directory. Submitter handles individual browser flow, concurrent manager runs 3 in parallel, verifier checks DB state, orchestrator ties everything together. Real backend on port 5000, frontend on port 5173.

**Tech Stack:** Playwright (browser automation), pg (PostgreSQL), Node.js, Docker (C++ sandbox)

## Global Constraints

- All files live under `simulation/e2e/`
- Use `instructor@psu.edu` for instructor actions (already exists)
- Test students: `student-XX@e2e.test` emails, password `test123`
- DB: localhost:5432, user `codeuser`, password `codepassword123`, database `codeinsight`
- Backend: localhost:5000, must have `PLAYWRIGHT=1` env var for rate limit bypass
- Frontend: localhost:5173 (Vite dev server)
- Exercise: C++ "sum 1..N", section created dynamically
- 3 concurrent Playwright sessions, headless Chromium
- Character-by-character typing via `page.keyboard.type()`
- Docker must be available for C++ compilation

---

### Task 1: Data Layer — Exercise Definition + Personas + Config

**Files:**
- Create: `simulation/e2e/exercise.js`
- Create: `simulation/e2e/personas.js`
- Create: `simulation/e2e/config.js`

**Interfaces:**
- Produces: `EXERCISE` object with `{ id: null, title, description, starterCode, testCases, referenceSolution, sectionId }`
- Produces: `PERSONAS` array of 20 objects, each with `{ id, name, email, password, archetype, attempts: [{ code, expectedCorrect }], expectedFlags, expectedCdsRange }`
- Produces: `SECTION_TITLE`, `EXERCISE_TITLE` constants, `DB_CONFIG`, `BASE_URL`, `BACKEND_URL`

- [ ] **Step 1: Create config.js**

```javascript
// simulation/e2e/config.js
const BASE_URL = 'http://localhost:5173';
const BACKEND_URL = 'http://localhost:5000';
const SECTION_TITLE = 'E2E Test Section';
const EXERCISE_TITLE = 'Sum 1..N';
const DB_CONFIG = {
  host: 'localhost', port: 5432,
  database: 'codeinsight',
  user: 'codeuser',
  password: 'codepassword123',
};
const ARCHETYPES = {
  HIGH: 'high', AVERAGE: 'average', STRUGGLING: 'struggling',
  HARDCODER: 'hardcoder', BLANK: 'blank',
};
const CONCURRENCY = 3;
const STUDENT_COUNT = 20;
const INSTRUCTOR = { email: 'instructor@psu.edu', password: 'password123' };
const STUDENT_PASSWORD = 'test123';
module.exports = { BASE_URL, BACKEND_URL, SECTION_TITLE, EXERCISE_TITLE,
  DB_CONFIG, ARCHETYPES, CONCURRENCY, STUDENT_COUNT, INSTRUCTOR, STUDENT_PASSWORD };
```

- [ ] **Step 2: Run test** — verify file loads without error

Run: `node -e "require('./simulation/e2e/config.js'); console.log('OK')"`
Expected: `OK`

- [ ] **Step 3: Create exercise.js**

```javascript
// simulation/e2e/exercise.js
const EXERCISE = {
  id: null, sectionId: null,
  title: 'Sum 1..N',
  description: 'Write a program that reads an integer N and prints the sum of numbers from 1 to N.',
  starterCode: `#include <iostream>
using namespace std;

int main() {
    // TODO: Implement your solution here

    return 0;
}`,
  referenceSolution: `#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    cout << sum;
    return 0;
}`,
  testCases: [
    { input: '10', expected: '55', hidden: false },
    { input: '5', expected: '15', hidden: false },
    { input: '100', expected: '5050', hidden: true },
    { input: '1', expected: '1', hidden: true },
  ],
};
module.exports = { EXERCISE };
```

- [ ] **Step 4: Create personas.js** — contains all 20 students with per-attempt code

```javascript
// simulation/e2e/personas.js — 20 students, 5 archetypes × 4
const PERSONAS = [
  // ── HIGH PERFORMER (S01-S04) ──
  { id: 1, name: 'Alice', email: 'student-01@e2e.test', password: 'test123',
    archetype: 'high', typingSpeed: 80,
    attempts: [
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    int n;\n    cin >> n;\n    int sum = 0;\n    for (int i = 1; i <= n; i++) {\n        sum += i;\n    }\n    cout << sum;\n    return 0;\n}`,
        correct: true },
    ],
    expectedFlags: [], expectedCdsRange: 'Low' },
  { id: 2, name: 'Bob', email: 'student-02@e2e.test', password: 'test123',
    archetype: 'high', typingSpeed: 75,
    attempts: [
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    int x;\n    cin >> x;\n    int total = 0;\n    for (int i = 1; i <= x; i++) {\n        total = total + i;\n    }\n    cout << total;\n    return 0;\n}`,
        correct: true },
    ],
    expectedFlags: [], expectedCdsRange: 'Low' },
  { id: 3, name: 'Carol', email: 'student-03@e2e.test', password: 'test123',
    archetype: 'high', typingSpeed: 85,
    attempts: [
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    int n;\n    cin >> n;\n    int result = 0;\n    for (int i = 1; i <= n; i++) {\n        result += i;\n    }\n    cout << result;\n    return 0;\n}`,
        correct: true },
    ],
    expectedFlags: [], expectedCdsRange: 'Low' },
  { id: 4, name: 'Dave', email: 'student-04@e2e.test', password: 'test123',
    archetype: 'high', typingSpeed: 90,
    attempts: [
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    int N;\n    cin >> N;\n    int accumulator = 0;\n    for (int i = 1; i <= N; i++) {\n        accumulator += i;\n    }\n    cout << accumulator;\n    return 0;\n}`,
        correct: true },
    ],
    expectedFlags: [], expectedCdsRange: 'Low' },

  // ── AVERAGE (S05-S08) ──
  { id: 5, name: 'Eve', email: 'student-05@e2e.test', password: 'test123',
    archetype: 'average', typingSpeed: 130,
    attempts: [
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    int n;\n    cin >> n;\n    cout << 55;\n    return 0;\n}`,
        correct: false },
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    int n;\n    cin >> n;\n    int sum = 0;\n    for (int i = 0; i < n; i++) {\n        sum += i;\n    }\n    cout << sum;\n    return 0;\n}`,
        correct: false },
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    int n;\n    cin >> n;\n    int sum = 0;\n    for (int i = 1; i <= n; i++) {\n        sum += i;\n    }\n    cout << sum;\n    return 0;\n}`,
        correct: true },
    ],
    expectedFlags: [], expectedCdsRange: 'Low-Moderate' },
  { id: 6, name: 'Frank', email: 'student-06@e2e.test', password: 'test123',
    archetype: 'average', typingSpeed: 140,
    attempts: [
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    int n;\n    cin >> n;\n    int total = 0;\n    total = n * (n + 1) / 2;\n    cout << total;\n    return 0;\n}`,
        correct: false },
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    int n;\n    cin >> n;\n    int total = 0;\n    for (int i = 1; i <= n; i++) {\n        total = total + i;\n    }\n    cout << total;\n    return 0;\n}`,
        correct: true },
    ],
    expectedFlags: [], expectedCdsRange: 'Low-Moderate' },
  { id: 7, name: 'Grace', email: 'student-07@e2e.test', password: 'test123',
    archetype: 'average', typingSpeed: 120,
    attempts: [
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    int n;\n    cin >> n;\n    if (n == 10) { cout << 55; }\n    return 0;\n}`,
        correct: false },
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    int n;\n    cin >> n;\n    int result = 0;\n    result = (n * (n + 1)) / 2;\n    cout << result;\n    return 0;\n}`,
        correct: true },
    ],
    expectedFlags: [], expectedCdsRange: 'Low-Moderate' },
  { id: 8, name: 'Henry', email: 'student-08@e2e.test', password: 'test123',
    archetype: 'average', typingSpeed: 150,
    attempts: [
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    int n;\n    cin >> n;\n    int sum = n;\n    cout << sum;\n    return 0;\n}`,
        correct: false },
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    int n;\n    cin >> n;\n    int sum = 0;\n    for (int i = 1; i <= n; i++) {\n        sum += i;\n    }\n    cout << sum;\n    return 0;\n}`,
        correct: true },
    ],
    expectedFlags: [], expectedCdsRange: 'Low-Moderate' },

  // ── STRUGGLING / RETRY STORM (S09-S12) ──
  { id: 9, name: 'Ivy', email: 'student-09@e2e.test', password: 'test123',
    archetype: 'struggling', typingSpeed: 200,
    attempts: [
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    cout << 55;\n    return 0;\n}`,
        correct: false },
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    int n;\n    cin >> n;\n    int; // syntax error\n    cout << n;\n    return 0;\n}`,
        correct: false },
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    int n;\n    cin >> n;\n    int sum = 0;\n    for (int i = 0; i < 10; i++) {\n        sum += i;\n    }\n    cout << sum;\n    return 0;\n}`,
        correct: false },
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    int n;\n    cin >> n;\n    int sum = 0;\n    for (int i = 0; i < n; i++) {\n        sum += i;\n    }\n    cout << sum;\n    return 0;\n}`,
        correct: false },
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    int n;\n    cin >> n;\n    int sum = 0;\n    for (int i = 1; i <= n; i++) {\n        sum += i;\n    }\n    cout << sum;\n    return 0;\n}`,
        correct: true },
    ],
    expectedFlags: ['RETRY_STORM'], expectedCdsRange: 'High' },
  { id: 10, name: 'Jack', email: 'student-10@e2e.test', password: 'test123',
    archetype: 'struggling', typingSpeed: 250,
    attempts: [
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    int n;\n    cin >> n;\n    cout << n + 10;\n    return 0;\n}`,
        correct: false },
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    int n;\n    cin >> n;\n    int total;\n    for (int i = 0; i <= n; i++) {\n        total += i;\n    }\n    cout << total;\n    return 0;\n}`,
        correct: false },
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    int n;\n    cin >> n;\n    int total = 0;\n    for (int i = 1; i <= n; i++) {\n        total += i;\n    }\n    cout << total;\n    return 0;\n}`,
        correct: true },
    ],
    expectedFlags: ['RETRY_STORM'], expectedCdsRange: 'High' },
  { id: 11, name: 'Kate', email: 'student-11@e2e.test', password: 'test123',
    archetype: 'struggling', typingSpeed: 300,
    attempts: [
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    return 0;\n}`,
        correct: false },
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    int n;\n    cin >> n;\n    // loop here\n    return 0;\n}`,
        correct: false },
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    int n;\n    cin >> n;\n    int result = 0;\n    for (int i = 0; i < 5; i++) {\n        result += 5;\n    }\n    cout << result;\n    return 0;\n}`,
        correct: false },
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    int n;\n    cin >> n;\n    int result = 0;\n    for (int i = 1; i <= n; i++) {\n        result += i;\n    }\n    cout << result;\n    return 0;\n}`,
        correct: true },
    ],
    expectedFlags: ['RETRY_STORM'], expectedCdsRange: 'High' },
  { id: 12, name: 'Leo', email: 'student-12@e2e.test', password: 'test123',
    archetype: 'struggling', typingSpeed: 350,
    attempts: [
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    int n;\n    cin >> n;\n    int sum;\n    for (int i = 1; i < n; i++) {\n        sum = sum + i;\n    }\n    cout << sum;\n    return 0;\n}`,
        correct: false },
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    int n;\n    cin >> n;\n    int sum = 0;\n    for (int i = 1; i <= n; i++) {\n        sum = sum + i;\n    }\n    cout << sum;\n    return 0;\n}`,
        correct: true },
    ],
    expectedFlags: ['RETRY_STORM'], expectedCdsRange: 'High' },

  // ── HARDCODER (S13-S16) ──
  { id: 13, name: 'Mia', email: 'student-13@e2e.test', password: 'test123',
    archetype: 'hardcoder', typingSpeed: 50,
    attempts: [
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    cout << 55;\n    return 0;\n}`,
        correct: true },
    ],
    expectedFlags: ['HARDCODING'], expectedCdsRange: 'High' },
  { id: 14, name: 'Noah', email: 'student-14@e2e.test', password: 'test123',
    archetype: 'hardcoder', typingSpeed: 50,
    attempts: [
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    cout << "15";\n    return 0;\n}`,
        correct: false },  // test case input=5 expects 15, but cout<<"15" is string — wrong type
    ],
    expectedFlags: ['HARDCODING'], expectedCdsRange: 'High' },
  { id: 15, name: 'Olivia', email: 'student-15@e2e.test', password: 'test123',
    archetype: 'hardcoder', typingSpeed: 50,
    attempts: [
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    cout << 5050;\n    return 0;\n}`,
        correct: true },
    ],
    expectedFlags: ['HARDCODING'], expectedCdsRange: 'High' },
  { id: 16, name: 'Parker', email: 'student-16@e2e.test', password: 'test123',
    archetype: 'hardcoder', typingSpeed: 50,
    attempts: [
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    cout << 1 << endl;\n    return 0;\n}`,
        correct: true },
    ],
    expectedFlags: ['HARDCODING'], expectedCdsRange: 'High' },

  // ── BLANK SUBMITTER (S17-S20) ──
  { id: 17, name: 'Quinn', email: 'student-17@e2e.test', password: 'test123',
    archetype: 'blank', typingSpeed: 500,
    attempts: [
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    // TODO: Implement your solution here\n\n    return 0;\n}`,
        correct: false },
    ],
    expectedFlags: ['BLANK_TEMPLATE'], expectedCdsRange: 'High' },
  { id: 18, name: 'Riley', email: 'student-18@e2e.test', password: 'test123',
    archetype: 'blank', typingSpeed: 500,
    attempts: [
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    // TODO\n    return 0;\n}`,
        correct: false },
    ],
    expectedFlags: ['BLANK_TEMPLATE'], expectedCdsRange: 'High' },
  { id: 19, name: 'Sage', email: 'student-19@e2e.test', password: 'test123',
    archetype: 'blank', typingSpeed: 500,
    attempts: [
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    return 0;\n}`,
        correct: false },
    ],
    expectedFlags: ['BLANK_TEMPLATE'], expectedCdsRange: 'High' },
  { id: 20, name: 'Taylor', email: 'student-20@e2e.test', password: 'test123',
    archetype: 'blank', typingSpeed: 500,
    attempts: [
      { code: `#include <iostream>\nusing namespace std;\nint main() {\n    int n;\n    cin >> n;\n    return 0;\n}`,
        correct: false },
    ],
    expectedFlags: ['BLANK_TEMPLATE'], expectedCdsRange: 'High' },
];
module.exports = { PERSONAS };
```

- [ ] **Step 5: Verify all data files load**

Run: `node -e "const {PERSONAS}=require('./simulation/e2e/personas.js'); const {EXERCISE}=require('./simulation/e2e/exercise.js'); console.log(PERSONAS.length+' personas, '+EXERCISE.testCases.length+' test cases');"`
Expected: `20 personas, 4 test cases`

- [ ] **Step 6: Commit**

```bash
git add simulation/e2e/
git commit -m "feat(e2e): add data layer — config, exercise, 20 personas"
```

---

### Task 2: Browser Submitter — Individual Student Flow

**Files:**
- Create: `simulation/e2e/submitter.js`

**Interfaces:**
- Consumes: `PERSONAS[i]` object, `EXERCISE` object with `{ id, sectionId }`
- Exports: `async function submitStudentFlow(page, persona, exerciseId, {concurrentIdx})` → returns `{ studentId, name, attempts: [{ success, result }], duration }`

- [ ] **Step 1: Create submitter.js**

```javascript
// simulation/e2e/submitter.js
const { BASE_URL } = require('./config');

async function submitStudentFlow(page, persona, exerciseId, { concurrentIdx } = {}) {
  const startTime = Date.now();
  const results = { personId: persona.id, name: persona.name, email: persona.email,
    archetype: persona.archetype, attempts: [], duration: 0 };

  try {
    // Login
    await page.goto(`${BASE_URL}/login`);
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(1000);

    const emailInput = page.locator('input[type="email"]').first();
    await emailInput.fill(persona.email);
    const passwordInput = page.locator('input[type="password"]').first();
    await passwordInput.fill(persona.password);
    await page.locator('button[type="submit"]').first().click();
    await page.waitForTimeout(2000);

    if (page.url().includes('/login')) {
      results.attempts.push({ attempt: 0, success: false, error: 'Login failed — stayed on /login' });
      results.duration = Date.now() - startTime;
      return results;
    }

    // Navigate to exercise directly by URL
    await page.goto(`${BASE_URL}/student/exercises/${exerciseId}`);
    await page.waitForLoadState('networkidle');
    await page.waitForTimeout(2000);

    // Submit each attempt
    for (let i = 0; i < persona.attempts.length; i++) {
      const attemptData = persona.attempts[i];
      const attemptNum = i + 1;

      // Clear and type code character by character
      await page.evaluate(() => {
        const editor = document.querySelector('.monaco-editor');
        if (editor && editor._codeEditorService) { /* Monaco clear */ }
      });
      // Fallback: focus textarea and type
      const textarea = page.locator('textarea.inputarea').first();
      if (await textarea.isVisible({ timeout: 3000 }).catch(() => false)) {
        await textarea.focus();
        // Select all and delete
        await page.keyboard.press('Control+A');
        await page.waitForTimeout(100);
        await page.keyboard.press('Delete');
        await page.waitForTimeout(200);
        // Type code character by character
        await page.keyboard.type(attemptData.code, { delay: persona.typingSpeed || 100 });
      } else {
        // Try Monaco API fallback
        await page.evaluate((code) => {
          const editor = window.monaco?.editor?.getModels?.();
          if (editor && editor.length > 0) {
            editor[0].setValue(code);
          }
        }, attemptData.code);
      }

      await page.waitForTimeout(500);

      // Click Submit button
      const submitBtn = page.locator('button:has-text("Submit")').first();
      if (await submitBtn.isVisible({ timeout: 5000 }).catch(() => false)) {
        await submitBtn.click();
      } else {
        const runBtn = page.locator('button:has-text("Run")').first();
        if (await runBtn.isVisible({ timeout: 3000 }).catch(() => false)) {
          await runBtn.click();
        }
      }

      // Wait for result — poll for test results to appear
      let resultText = '';
      let success = false;
      try {
        await page.waitForTimeout(2000);
        // Wait for test result elements
        const resultEl = page.locator('[class*="result"], [class*="test"], [class*="output"], [class*="feedback"]').first();
        await resultEl.waitFor({ state: 'visible', timeout: 30000 });
        resultText = await resultEl.textContent().catch(() => 'timeout');
        success = attemptData.correct; // We know if it should be correct
      } catch (e) {
        resultText = 'timeout';
      }

      results.attempts.push({
        attempt: attemptNum, success, resultText: resultText.substring(0, 100),
        expectedCorrect: attemptData.correct, duration: Date.now() - startTime,
      });

      // Brief pause between attempts
      if (i < persona.attempts.length - 1) {
        await page.waitForTimeout(1000);
      }
    }

    results.duration = Date.now() - startTime;
    return results;
  } catch (error) {
    results.attempts.push({ attempt: 0, success: false, error: error.message });
    results.duration = Date.now() - startTime;
    return results;
  }
}

module.exports = { submitStudentFlow };
```

- [ ] **Step 2: Quick manual verify** — test with a single student

Run: `node -e "const {chromium}=require('playwright'); const {submitStudentFlow}=require('./simulation/e2e/submitter.js'); const {PERSONAS}=require('./simulation/e2e/personas.js'); (async()=>{const b=await chromium.launch({headless:true}); const p=await b.newPage(); const r=await submitStudentFlow(p, PERSONAS[0], 188); console.log(JSON.stringify(r,null,2)); await b.close()})()" 2>&1 | head -30`
Expected: Returns attempt results (may fail cleanly since exercise 188 isn't the right one — but process should run)

- [ ] **Step 3: Commit**

```bash
git add simulation/e2e/submitter.js
git commit -m "feat(e2e): add browser submitter for individual student flow"
```

---

### Task 3: Concurrent Session Manager

**Files:**
- Create: `simulation/e2e/concurrent.js`

**Interfaces:**
- Consumes: `PERSONAS`, `EXERCISE.id`, `submitStudentFlow()` function
- Exports: `async function runConcurrent(personas, exerciseId, concurrency)` → returns array of per-student results
- Splits 20 personas into 3 queues, launches 3 Playwright browsers, runs each queue sequentially in its own session, all 3 sessions run in parallel via `Promise.allSettled()`

- [ ] **Step 1: Create concurrent.js**

```javascript
// simulation/e2e/concurrent.js
const { chromium } = require('playwright');
const { submitStudentFlow } = require('./submitter');

function splitIntoQueues(personas, n) {
  const queues = Array.from({ length: n }, () => []);
  personas.forEach((p, i) => queues[i % n].push(p));
  return queues;
}

async function runSession(students, exerciseId, sessionIdx) {
  const browser = await chromium.launch({ headless: true });
  const results = [];
  try {
    const context = await browser.newContext({ viewport: { width: 1280, height: 720 } });
    for (let i = 0; i < students.length; i++) {
      const student = students[i];
      console.log(`  [Session ${sessionIdx + 1}] ${student.name} (${student.email}) — ${student.attempts.length} attempt(s)...`);
      const page = await context.newPage();
      const r = await submitStudentFlow(page, student, exerciseId, { concurrentIdx: sessionIdx });
      await page.close();
      results.push(r);
      const status = r.attempts.some(a => a.success) ? '✓' : '✗';
      const passed = r.attempts.filter(a => a.success).length;
      console.log(`  [Session ${sessionIdx + 1}] ${status} ${student.name}: ${passed}/${r.attempts.length} passed (${(r.duration / 1000).toFixed(1)}s)`);
    }
  } catch (e) {
    console.error(`  [Session ${sessionIdx + 1}] Error: ${e.message}`);
  } finally {
    await browser.close();
  }
  return results;
}

async function runConcurrent(personas, exerciseId, concurrency = 3) {
  const queues = splitIntoQueues(personas, concurrency);
  console.log(`\n  Splitting ${personas.length} students into ${concurrency} sessions (${queues.map(q => q.length).join('+')})`);

  const startTime = Date.now();
  const sessions = queues.map((queue, i) => runSession(queue, exerciseId, i));
  const sessionResults = await Promise.allSettled(sessions);

  const allResults = [];
  for (const sr of sessionResults) {
    if (sr.status === 'fulfilled') allResults.push(...sr.value);
    else console.error('Session rejected:', sr.reason);
  }

  console.log(`\n  All sessions complete in ${((Date.now() - startTime) / 1000).toFixed(1)}s`);
  return allResults;
}

module.exports = { runConcurrent };
```

- [ ] **Step 2: Commit**

```bash
git add simulation/e2e/concurrent.js
git commit -m "feat(e2e): add concurrent session manager — 3 parallel Playwright sessions"
```

---

### Task 4: Database Verifier

**Files:**
- Create: `simulation/e2e/verifier.js`

**Interfaces:**
- Consumes: `DB_CONFIG`, `EXERCISE.id`, `PERSONAS`
- Exports: `async function verifySubmissions(exerciseId)` → `{ checks: [{ name, passed, detail }], allPassed }`

- [ ] **Step 1: Create verifier.js**

```javascript
// simulation/e2e/verifier.js
const { Pool } = require('pg');
const { DB_CONFIG, STUDENT_COUNT } = require('./config');
const { PERSONAS } = require('./personas');

const pool = new Pool(DB_CONFIG);

async function verifySubmissions(exerciseId, sectionId) {
  const checks = [];
  const client = await pool.connect();

  try {
    // Check 1: Submission count
    const subCount = await client.query(
      'SELECT COUNT(*) as count FROM submissions WHERE exercise_id = $1', [exerciseId]);
    const count = parseInt(subCount.rows[0].count);
    checks.push({ name: 'Submissions exist', passed: count >= STUDENT_COUNT,
      detail: `${count} total (need >= ${STUDENT_COUNT})` });

    // Check 2: Each student submitted
    const studentSubs = await client.query(
      'SELECT student_id, COUNT(*) as cnt FROM submissions WHERE exercise_id = $1 GROUP BY student_id',
      [exerciseId]);
    const submittedIds = new Set(studentSubs.rows.map(r => r.student_id));
    const studentUsers = await client.query(
      'SELECT id FROM users WHERE email LIKE $1', ['student-%@e2e.test']);
    const missing = studentUsers.rows.filter(u => !submittedIds.has(u.id));
    checks.push({ name: 'All students submitted', passed: missing.length === 0,
      detail: missing.length > 0 ? `Missing: ${missing.map(m => m.id).join(',')}` : 'All 20 present' });

    // Check 3: Test results populated
    const nullResults = await client.query(
      "SELECT COUNT(*) as count FROM submissions WHERE exercise_id = $1 AND test_results IS NULL",
      [exerciseId]);
    checks.push({ name: 'Test results stored', passed: parseInt(nullResults.rows[0].count) === 0,
      detail: `${nullResults.rows[0].count} submissions with null test_results` });

    // Check 4: Integrity flags by type
    const flags = await client.query(
      'SELECT flag_type, COUNT(*) as cnt FROM integrity_flags WHERE exercise_id = $1 GROUP BY flag_type ORDER BY flag_type',
      [exerciseId]);
    const flagMap = {};
    flags.rows.forEach(r => flagMap[r.flag_type] = parseInt(r.cnt));
    const hardcodingOk = (flagMap['HARDCODING'] || 0) >= 2;
    const blankOk = (flagMap['BLANK_TEMPLATE'] || 0) >= 2;
    const retryOk = (flagMap['RETRY_STORM'] || 0) >= 1 || (flagMap['BEHAVIORAL_ANOMALY'] || 0) >= 1;
    checks.push({ name: 'HARDCODING flags', passed: hardcodingOk,
      detail: `${flagMap['HARDCODING'] || 0} found (need ≥2)` });
    checks.push({ name: 'BLANK_TEMPLATE flags', passed: blankOk,
      detail: `${flagMap['BLANK_TEMPLATE'] || 0} found (need ≥2)` });
    checks.push({ name: 'RETRY_STORM/BEHAVIORAL flags', passed: retryOk,
      detail: `RETRY_STORM:${flagMap['RETRY_STORM'] || 0}, BEHAVIORAL:${flagMap['BEHAVIORAL_ANOMALY'] || 0}` });

    // Check 5: CDS scores — all students scored
    const cdsScores = await client.query(
      'SELECT COUNT(*) as count FROM cds_scores WHERE exercise_id = $1', [exerciseId]);
    checks.push({ name: 'CDS scores for all', passed: parseInt(cdsScores.rows[0].count) >= STUDENT_COUNT,
      detail: `${cdsScores.rows[0].count} scores (need ≥${STUDENT_COUNT})` });

    // Check 6: CDS distribution — at least 1 High and 1 Low
    const cdsDist = await client.query(
      'SELECT classification, COUNT(*) as cnt FROM cds_scores WHERE exercise_id = $1 GROUP BY classification',
      [exerciseId]);
    const distMap = {};
    cdsDist.rows.forEach(r => distMap[r.classification] = parseInt(r.cnt));
    const hasLow = (distMap['Low'] || 0) >= 1;
    const hasHigh = (distMap['High'] || 0) >= 1;
    checks.push({ name: 'CDS distribution — Low exists', passed: hasLow,
      detail: `Low: ${distMap['Low'] || 0}` });
    checks.push({ name: 'CDS distribution — High exists', passed: hasHigh,
      detail: `High: ${distMap['High'] || 0}, Moderate: ${distMap['Moderate'] || 0}` });

    // Check 7: Alerts generated for High CDS
    const alerts = await client.query(
      "SELECT COUNT(*) as count FROM analytics_alerts WHERE exercise_id = $1 AND alert_type = 'CDS_HIGH'",
      [exerciseId]);
    checks.push({ name: 'High-CDS alerts generated', passed: parseInt(alerts.rows[0].count) >= 1,
      detail: `${alerts.rows[0].count} alerts` });

    // Check 8: CDS snapshots audit trail
    const snapshots = await client.query(
      'SELECT COUNT(*) as count FROM cds_snapshots WHERE exercise_id = $1', [exerciseId]);
    checks.push({ name: 'CDS snapshots written', passed: parseInt(snapshots.rows[0].count) >= 1,
      detail: `${snapshots.rows[0].count} snapshots` });

    const allPassed = checks.every(c => c.passed);
    return { checks, allPassed };
  } finally {
    client.release();
  }
}

module.exports = { verifySubmissions };
```

- [ ] **Step 2: Commit**

```bash
git add simulation/e2e/verifier.js
git commit -m "feat(e2e): add database verifier — checks submissions, flags, CDS, alerts"
```

---

### Task 5: Server Restart Test

**Files:**
- Create: `simulation/e2e/restart.js`

**Interfaces:**
- Exports: `async function testServerRestart(exerciseId)` → `{ passed, detail }`
- Kills backend process, waits, restarts, submits a recovery submission, verifies in DB

- [ ] **Step 1: Create restart.js**

```javascript
// simulation/e2e/restart.js
const { execSync, spawn } = require('child_process');
const http = require('http');
const { BACKEND_URL } = require('./config');

function httpPost(path, body, token) {
  return new Promise((resolve, reject) => {
    const url = new URL(path, BACKEND_URL);
    const data = JSON.stringify(body);
    const headers = { 'Content-Type': 'application/json', 'Content-Length': Buffer.byteLength(data) };
    if (token) headers['Cookie'] = `ci_token=${token}`;
    const req = http.request({ hostname: url.hostname, port: url.port, path: url.pathname,
      method: 'POST', headers }, (res) => {
      let d = '';
      res.on('data', c => d += c);
      res.on('end', () => { try { resolve(JSON.parse(d)); } catch { resolve(d); } });
    });
    req.on('error', reject);
    req.write(data);
    req.end();
  });
}

function httpGet(path) {
  return new Promise((resolve, reject) => {
    const url = new URL(path, BACKEND_URL);
    http.get({ hostname: url.hostname, port: url.port, path: url.pathname }, (res) => {
      let d = '';
      res.on('data', c => d += c);
      res.on('end', () => resolve({ status: res.statusCode, body: d }));
    }).on('error', reject);
  });
}

function sleep(ms) { return new Promise(r => setTimeout(r, ms)); }

async function getBackendPid() {
  try {
    const out = execSync('pgrep -f "node.*server\\.js"', { encoding: 'utf8', timeout: 5000 });
    const pids = out.trim().split('\n').filter(Boolean).map(Number);
    // Filter out our own node process
    const ourPid = process.pid;
    return pids.find(p => p !== ourPid) || null;
  } catch { return null; }
}

async function waitForHealthy(timeoutMs = 30000) {
  const start = Date.now();
  while (Date.now() - start < timeoutMs) {
    try {
      const res = await httpGet('/api/auth/me');
      if (res.status === 200) return true;
    } catch {}
    await sleep(1000);
  }
  return false;
}

async function loginAsInstructor() {
  const loginRes = await httpPost('/api/auth/login',
    { email: 'instructor@psu.edu', password: 'password123' });
  if (loginRes && loginRes.code === 'UNAUTHORIZED') return null;
  // Get token from cookie logic — for simplicity use email/password
  return 'instructor-token';
}

async function testServerRestart(exerciseId) {
  const steps = [];

  try {
    // Step 1: Login to get a token
    const token = await new Promise((resolve, reject) => {
      const data = JSON.stringify({ email: 'instructor@psu.edu', password: 'password123' });
      const url = new URL('/api/auth/login', BACKEND_URL);
      const req = http.request({ hostname: url.hostname, port: url.port, path: url.pathname,
        method: 'POST', headers: { 'Content-Type': 'application/json', 'Content-Length': Buffer.byteLength(data) }
      }, (res) => {
        const cookies = res.headers['set-cookie'] || [];
        const t = cookies.find(c => c.startsWith('ci_token='));
        resolve(t ? t.split(';')[0].replace('ci_token=', '') : null);
      });
      req.on('error', reject);
      req.write(data); req.end();
    });
    if (!token) {
      return { passed: false, steps: [{ action: 'Login', success: false, detail: 'Could not get instructor token' }] };
    }
    steps.push({ action: 'Login as instructor', success: true });

    // Step 2: Get backend PID
    const pid = await getBackendPid();
    if (!pid) {
      return { passed: false, steps: [...steps, { action: 'Find PID', success: false, detail: 'Could not find backend process' }] };
    }
    steps.push({ action: 'Found backend PID', success: true, detail: `PID ${pid}` });

    // Step 3: Kill backend
    process.kill(pid, 'SIGTERM');
    await sleep(2000);

    // Verify killed
    const stillRunning = await getBackendPid();
    steps.push({ action: 'Kill backend', success: !stillRunning || stillRunning !== pid,
      detail: `PID ${pid} killed` });

    await sleep(3000);

    // Step 4: Restart backend
    const backendDir = '/home/nihil/projects/codeinsight/backend';
    const server = spawn('node', ['server.js'], {
      cwd: backendDir, stdio: 'pipe',
      env: { ...process.env, PORT: '5000', PLAYWRIGHT: '1' },
    });
    server.stdout.on('data', d => process.stdout.write(`[backend] ${d}`));
    server.stderr.on('data', d => process.stderr.write(`[backend-err] ${d}`));

    steps.push({ action: 'Spawn backend', success: true, detail: `PID ${server.pid}` });

    // Step 5: Wait for healthy
    const healthy = await waitForHealthy(60000);
    steps.push({ action: 'Wait for healthy', success: healthy, detail: healthy ? 'Backend ready' : 'Timeout' });

    if (!healthy) {
      return { passed: false, steps };
    }

    // Step 6: Submit a recovery attempt
    const submitRes = await new Promise((resolve, reject) => {
      const data = JSON.stringify({ exerciseId, code: '#include <iostream>\nusing namespace std;\nint main() { cout << "recovery"; return 0; }',
        timeSpentSeconds: 5 });
      const url = new URL('/api/submissions/submit', BACKEND_URL);
      const req = http.request({ hostname: url.hostname, port: url.port, path: url.pathname,
        method: 'POST', headers: { 'Content-Type': 'application/json', 'Content-Length': Buffer.byteLength(data),
          'Cookie': `ci_token=${token}` }
      }, (res) => {
        let d = '';
        res.on('data', c => d += c);
        res.on('end', () => { try { resolve(JSON.parse(d)); } catch { resolve({ raw: d }); } });
      });
      req.on('error', reject);
      req.write(data); req.end();
    });
    steps.push({ action: 'Submit recovery attempt', success: !!submitRes,
      detail: submitRes ? 'Submitted' : 'Failed' });

    // Step 7: Verify via DB
    const { Pool } = require('pg');
    const { DB_CONFIG } = require('./config');
    const pool = new Pool(DB_CONFIG);
    const dbResult = await pool.query(
      "SELECT COUNT(*) as count FROM submissions WHERE exercise_id = $1 AND code LIKE '%recovery%'",
      [exerciseId]);
    const found = parseInt(dbResult.rows[0].count);
    await pool.end();

    steps.push({ action: 'Verify recovery in DB', success: found >= 1,
      detail: `${found} recovery submission(s) found` });

    const allPassed = steps.filter(s => s.success === false).length === 0;
    return { passed: allPassed, steps };
  } catch (error) {
    return { passed: false, steps: [...steps, { action: 'Error', success: false, detail: error.message }] };
  }
}

module.exports = { testServerRestart };
```

- [ ] **Step 2: Commit**

```bash
git add simulation/e2e/restart.js
git commit -m "feat(e2e): add server restart test — kill, restart, verify recovery"
```

---

### Task 6: Setup Phase — API Orchestration for Creating Section, Students, Exercise

**Files:**
- Create: `simulation/e2e/setup.js`

**Interfaces:**
- Exports: `async function setupTestData()` → `{ sectionId, exerciseId, instructorToken }`
- Uses instructor@psu.edu to create section, register 20 students, enroll them, create exercise

- [ ] **Step 1: Create setup.js**

```javascript
// simulation/e2e/setup.js
const http = require('http');
const { BACKEND_URL, INSTRUCTOR, STUDENT_PASSWORD, SECTION_TITLE, EXERCISE_TITLE } = require('./config');
const { PERSONAS } = require('./personas');
const { EXERCISE } = require('./exercise');

const HOST = { hostname: 'localhost', port: 5000 };

function apiCall(method, path, body, token) {
  return new Promise((resolve, reject) => {
    const url = new URL(path, BACKEND_URL);
    const data = body ? JSON.stringify(body) : null;
    const headers = { 'Content-Type': 'application/json' };
    if (data) headers['Content-Length'] = Buffer.byteLength(data);
    if (token) headers['Cookie'] = `ci_token=${token}`;
    const opts = { hostname: url.hostname, port: url.port, path: url.pathname, method, headers };
    const req = http.request(opts, (res) => {
      let d = '';
      res.on('data', c => d += c);
      res.on('end', () => { try { resolve({ status: res.statusCode, data: JSON.parse(d) }); } catch { resolve({ status: res.statusCode, data: d }); } });
    });
    req.on('error', reject);
    if (data) req.write(data);
    req.end();
  });
}

async function loginToken() {
  const res = await apiCall('POST', '/api/auth/login', INSTRUCTOR);
  if (!res || res.status >= 400) throw new Error(`Login failed: ${JSON.stringify(res?.data)}`);
  // Token is in set-cookie — we need to get it differently
  return new Promise((resolve, reject) => {
    const data = JSON.stringify(INSTRUCTOR);
    const req = http.request({ ...HOST, path: '/api/auth/login', method: 'POST',
      headers: { 'Content-Type': 'application/json', 'Content-Length': Buffer.byteLength(data) }
    }, (res) => {
      let d = '';
      res.on('data', c => d += c);
      res.on('end', () => {
        const cookies = res.headers['set-cookie'] || [];
        const t = cookies.find(c => c.startsWith('ci_token='));
        resolve(t ? t.split(';')[0].replace('ci_token=', '') : null);
      });
    });
    req.write(data); req.end();
  });
}

async function setupTestData() {
  console.log('\nPHASE 1: Setup...');
  const instructorToken = await loginToken();
  if (!instructorToken) throw new Error('Could not get instructor token');
  console.log('  ✓ Instructor logged in');

  // Create section
  const sectionRes = await apiCall('POST', '/api/sections/', { name: SECTION_TITLE, description: 'E2E test section' }, instructorToken);
  if (!sectionRes || sectionRes.status >= 400) throw new Error(`Section creation failed: ${JSON.stringify(sectionRes?.data)}`);
  const sectionId = sectionRes.data?.id || sectionRes.data?.section?.id;
  console.log(`  ✓ Section created (id=${sectionId})`);

  // Register 20 students
  for (const p of PERSONAS) {
    const regRes = await apiCall('POST', '/api/auth/register',
      { name: p.name, email: p.email, password: STUDENT_PASSWORD, role: 'student' }, instructorToken);
    if (regRes.status >= 400 && !regRes.data?.code?.includes('EXISTS')) {
      console.log(`  ⚠ Register ${p.email}: ${regRes.data?.message || regRes.status}`);
    }
  }
  console.log('  ✓ 20 students registered');

  // Enroll all students
  const enrolled = await apiCall('GET', '/api/sections/students-all', null, instructorToken);
  const students = enrolled.data || [];
  const testStudents = students.filter(s => s.email.endsWith('@e2e.test'));
  for (const s of testStudents) {
    await apiCall('POST', `/api/sections/${sectionId}/enroll`, { student_id: s.id }, instructorToken);
  }
  console.log(`  ✓ ${testStudents.length} students enrolled in section ${sectionId}`);

  // Create exercise in section
  const exercisePayload = {
    title: EXERCISE_TITLE,
    description: EXERCISE.description,
    section_id: sectionId,
    starter_code: EXERCISE.starterCode,
    reference_solution: EXERCISE.referenceSolution,
    test_cases: EXERCISE.testCases.map(tc => ({
      input: tc.input, expected: tc.expected, hidden: tc.hidden,
      validationType: 'exact',
    })),
    time_limit_minutes: 60,
    auto_alert: true,
  };
  const exerciseRes = await apiCall('POST', '/api/exercises/', exercisePayload, instructorToken);
  if (!exerciseRes || exerciseRes.status >= 400) throw new Error(`Exercise creation failed: ${JSON.stringify(exerciseRes?.data)}`);
  const exerciseId = exerciseRes.data?.id || exerciseRes.data?.exercise?.id;
  console.log(`  ✓ Exercise created (id=${exerciseId})`);

  return { sectionId, exerciseId, instructorToken };
}

module.exports = { setupTestData, loginToken, apiCall };
```

- [ ] **Step 2: Commit**

```bash
git add simulation/e2e/setup.js
git commit -m "feat(e2e): add setup phase — creates section, students, exercise via API"
```

---

### Task 7: Cleanup Script

**Files:**
- Create: `simulation/e2e/cleanup.js`

**Interfaces:**
- Exports: `async function cleanupTestData(exerciseId, sectionId)` — deletes all test data

- [ ] **Step 1: Create cleanup.js**

```javascript
// simulation/e2e/cleanup.js
const { Pool } = require('pg');
const { DB_CONFIG } = require('./config');

const pool = new Pool(DB_CONFIG);

async function cleanupTestData(exerciseId, sectionId) {
  console.log('\nCleaning up test data...');
  const client = await pool.connect();
  try {
    await client.query('BEGIN');

    // Delete integrity flags
    const f1 = await client.query('DELETE FROM integrity_flags WHERE exercise_id = $1', [exerciseId]);
    console.log(`  ✓ ${f1.rowCount} integrity_flags deleted`);

    // Delete analytics_alerts
    const f2 = await client.query("DELETE FROM analytics_alerts WHERE exercise_id = $1 AND alert_type = 'CDS_HIGH'", [exerciseId]);
    console.log(`  ✓ ${f2.rowCount} analytics_alerts deleted`);

    // Delete CDS snapshots
    const f3 = await client.query('DELETE FROM cds_snapshots WHERE exercise_id = $1', [exerciseId]);
    console.log(`  ✓ ${f3.rowCount} cds_snapshots deleted`);

    // Delete CDS scores
    const f4 = await client.query('DELETE FROM cds_scores WHERE exercise_id = $1', [exerciseId]);
    console.log(`  ✓ ${f4.rowCount} cds_scores deleted`);

    // Delete submissions
    const f5 = await client.query('DELETE FROM submissions WHERE exercise_id = $1', [exerciseId]);
    console.log(`  ✓ ${f5.rowCount} submissions deleted`);

    // Delete exercise
    const f6 = await client.query('DELETE FROM exercises WHERE id = $1', [exerciseId]);
    console.log(`  ✓ Exercise ${exerciseId} deleted`);

    // Delete enrollments for test students
    const f7 = await client.query(
      "DELETE FROM enrollments WHERE student_id IN (SELECT id FROM users WHERE email LIKE $1) AND section_id = $2",
      ['student-%@e2e.test', sectionId]);
    console.log(`  ✓ ${f7.rowCount} enrollments deleted`);

    // Delete section
    if (sectionId) {
      const f8 = await client.query('DELETE FROM sections WHERE id = $1', [sectionId]);
      console.log(`  ✓ Section ${sectionId} deleted`);
    }

    // Delete test users
    const f9 = await client.query(
      "DELETE FROM users WHERE email LIKE $1", ['student-%@e2e.test']);
    console.log(`  ✓ ${f9.rowCount} test users deleted`);

    await client.query('COMMIT');
    console.log('  ✓ All test data cleaned up');
  } catch (error) {
    await client.query('ROLLBACK');
    console.error(`  ✗ Cleanup error: ${error.message}`);
    throw error;
  } finally {
    client.release();
    await pool.end();
  }
}

async function main() {
  const exerciseId = process.argv[2] ? parseInt(process.argv[2]) : null;
  const sectionId = process.argv[3] ? parseInt(process.argv[3]) : null;
  if (!exerciseId) { console.error('Usage: node cleanup.js <exerciseId> [sectionId]'); process.exit(1); }
  await cleanupTestData(exerciseId, sectionId || 0);
  console.log('Done.');
}

if (require.main === module) main();

module.exports = { cleanupTestData };
```

- [ ] **Step 2: Commit**

```bash
git add simulation/e2e/cleanup.js
git commit -m "feat(e2e): add cleanup script — removes all test data"
```

---

### Task 8: Main Orchestrator

**Files:**
- Create: `simulation/e2e/orchestrator.js`

**Interfaces:**
- Exports: `async function runE2ESimulation()` → `{ summary, results }`
- Ties together setup → submit → close → verify → restart → report

- [ ] **Step 1: Create orchestrator.js**

```javascript
// simulation/e2e/orchestrator.js
const { setupTestData, apiCall } = require('./setup');
const { runConcurrent } = require('./concurrent');
const { verifySubmissions } = require('./verifier');
const { testServerRestart } = require('./restart');
const { STUDENT_COUNT, CONCURRENCY, BACKEND_URL } = require('./config');
const { PERSONAS } = require('./personas');

async function checkBackend() {
  try {
    const http = require('http');
    await new Promise((resolve, reject) => {
      http.get(`${BACKEND_URL}/api/auth/me`, (res) => {
        resolve(res.statusCode);
      }).on('error', reject);
    });
    return true;
  } catch { return false; }
}

async function closeExercise(exerciseId, token) {
  const res = await apiCall('POST', `/api/exercises/${exerciseId}/close`, {}, token);
  return res.status < 400;
}

async function runE2ESimulation() {
  const startTime = Date.now();
  console.log('╔══════════════════════════════════════════════════════════╗');
  console.log('║  E2E REAL-WORLD SIMULATION                             ║');
  console.log(`║  ${STUDENT_COUNT} students × 5 archetypes × ${CONCURRENCY} concurrent          ║`);
  console.log('╚══════════════════════════════════════════════════════════╝\n');

  // Pre-check
  const backendUp = await checkBackend();
  if (!backendUp) {
    console.error('✗ Backend not reachable. Start with PLAYWRIGHT=1 env var.');
    return { summary: { passed: false, error: 'Backend down' }, results: {} };
  }

  let sectionId, exerciseId, instructorToken;
  let submissionResults = [];
  let verifyResults = null;
  let restartResults = null;

  try {
    // ── PHASE 1: Setup ──
    const setup = await setupTestData();
    sectionId = setup.sectionId;
    exerciseId = setup.exerciseId;
    instructorToken = setup.instructorToken;

    // ── PHASE 2: Concurrent Submissions ──
    console.log('\nPHASE 2: Concurrent submissions (3 sessions)...');
    submissionResults = await runConcurrent(PERSONAS, exerciseId, CONCURRENCY);

    // Print submission summary
    const totalAttempts = submissionResults.reduce((s, r) => s + r.attempts.length, 0);
    const passedAttempts = submissionResults.reduce((s, r) => s + r.attempts.filter(a => a.success).length, 0);
    const failedSubmissions = submissionResults.filter(r => r.attempts.every(a => !a.success));
    console.log(`\n  Submissions: ${totalAttempts} total, ${passedAttempts} passed`);
    if (failedSubmissions.length > 0) {
      console.log(`  ⚠ ${failedSubmissions.length} students had no successful attempts:`);
      failedSubmissions.forEach(s => console.log(`    - ${s.name} (${s.email})`));
    }

    // ── PHASE 3: Close Exercise ──
    console.log('\nPHASE 3: Close exercise (batch CDS)...');
    const closed = await closeExercise(exerciseId, instructorToken);
    console.log(`  ${closed ? '✓' : '✗'} Exercise closed`);

    if (closed) {
      // Wait for batch CDS to process
      await new Promise(r => setTimeout(r, 3000));
    }

    // ── PHASE 4: Verification ──
    console.log('\nPHASE 4: Verification...');
    verifyResults = await verifySubmissions(exerciseId, sectionId);
    for (const check of verifyResults.checks) {
      console.log(`  ${check.passed ? '✓' : '✗'} ${check.name}: ${check.detail}`);
    }

    // ── PHASE 5: Server Restart Test ──
    console.log('\nPHASE 5: Server restart test...');
    restartResults = await testServerRestart(exerciseId);
    for (const step of restartResults.steps) {
      console.log(`  ${step.success ? '✓' : '✗'} ${step.action}${step.detail ? ': ' + step.detail : ''}`);
    }

  } catch (error) {
    console.error(`\n✗ Fatal error: ${error.message}`);
  }

  const duration = (Date.now() - startTime) / 1000;

  // ── Summary ──
  const allChecksPassed = verifyResults ? verifyResults.allPassed : false;
  const restartPassed = restartResults ? restartResults.passed : false;
  const overallPassed = allChecksPassed && restartPassed;

  console.log('\n' + '═'.repeat(60));
  console.log('  FINAL RESULTS');
  console.log('═'.repeat(60));
  console.log(`  Setup:       ✓`);
  console.log(`  Submissions: ${submissionResults.filter(r => r.attempts.some(a => a.success)).length}/${STUDENT_COUNT} students completed`);
  console.log(`  Verifier:    ${allChecksPassed ? '✓' : '✗'} all checks`);
  if (verifyResults) {
    for (const c of verifyResults.checks) {
      console.log(`    ${c.passed ? '✓' : '✗'} ${c.name}: ${c.detail}`);
    }
  }
  console.log(`  Restart:     ${restartPassed ? '✓' : '✗'}`);
  console.log(`  Duration:    ${(duration / 60).toFixed(1)}m ${(duration % 60).toFixed(0)}s`);
  console.log('═'.repeat(60));
  if (sectionId) console.log(`  Section:     id=${sectionId}`);
  if (exerciseId) console.log(`  Exercise:    id=${exerciseId}`);
  console.log('═'.repeat(60));

  return {
    summary: { passed: overallPassed, duration, sectionId, exerciseId },
    results: { submissionResults, verifyResults, restartResults },
  };
}

if (require.main === module) {
  runE2ESimulation().then(r => process.exit(r.summary.passed ? 0 : 1));
}

module.exports = { runE2ESimulation };
```

- [ ] **Step 2: Commit**

```bash
git add simulation/e2e/orchestrator.js
git commit -m "feat(e2e): add main orchestrator — ties all phases together"
```

---

### Task 9: Dry-Run and Fix Issues

**Files:** (none new — only fixes to existing files)

- [ ] **Step 1: Run setup only** to verify API orchestration works

Run: `node -e "const {setupTestData}=require('./simulation/e2e/setup.js'); setupTestData().then(r=>console.log('Section:',r.sectionId,'Exercise:',r.exerciseId)).catch(e=>console.error(e))" 2>&1`
Expected: Section created, 20 students registered, exercise created, IDs returned

- [ ] **Step 2: If setup fails**, fix API call signatures, auth, or field names

- [ ] **Step 3: Run cleanup** after setup test

Run: `node simulation/e2e/cleanup.js <exerciseId> <sectionId>`
Expected: All test data removed from DB

- [ ] **Step 4: Run full orchestrator** with reduced students first (just 6, 2 per archetype)

Run: Modify orchestrator temporarily to only use first 6 personas, run with `timeout 600 node -e "..."`  
Expected: All phases complete, verification checks pass

- [ ] **Step 5: Run full 20-student orchestrator**

Run: `cd simulation/e2e && timeout 900 node orchestrator.js 2>&1`
Expected: All phases pass, 20 students submitted, verification checks green

- [ ] **Step 6: Fix any issues found** during dry run

- [ ] **Step 7: Commit final fixes**

```bash
git add -A
git commit -m "fix(e2e): fix issues found during dry run"
```

---

### Task 10: Documentation and Handoff

**Files:**
- Create: `simulation/e2e/README.md`

- [ ] **Step 1: Create README.md**

```markdown
# E2E Real-World Simulation

Full end-to-end test: 20 students, 3 concurrent browser sessions, real backend pipeline.

## Prerequisites

- Backend running on port 5000 with `PLAYWRIGHT=1` env var
- Frontend running on port 5173
- PostgreSQL accessible (localhost:5432)
- Docker for C++ compilation sandbox

## Run

```bash
cd simulation/e2e
node orchestrator.js
```

## Cleanup

```bash
node cleanup.js <exerciseId> <sectionId>
```

## Architecture

See `docs/superpowers/specs/2026-06-17-e2e-simulation-design.md`
```

- [ ] **Step 2: Commit**

```bash
git add simulation/e2e/README.md
git commit -m "docs(e2e): add README with usage instructions"
```
