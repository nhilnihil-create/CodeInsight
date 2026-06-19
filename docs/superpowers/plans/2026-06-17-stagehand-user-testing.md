# Stagehand User Testing Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Add browser-level user testing simulation using Stagehand to test real user workflows (clicks, navigation, form filling) across all three roles (Instructor, Student, Admin).

**Architecture:** Stagehand wraps Playwright with LLM-powered natural language commands. We'll create persona-driven test scripts that simulate real users interacting with the UI. Tests run against the existing Playwright config (Chromium, Firefox, WebKit, Mobile).

**Tech Stack:** Stagehand (npm package), Playwright (existing), Node.js

## Global Constraints

- Backend must be running on port 5000 before tests execute
- Frontend must be running on port 5173 before tests execute
- Use existing test credentials from `simulation/personas.js`
- All test data uses `sim.*@test.codeinsight` email prefix for cleanup
- Tests must not modify production data
- Follow existing code patterns in `simulation/` directory

---

## File Structure

```
simulation/
├── stagehand/
│   ├── config.js              # Stagehand configuration and browser setup
│   ├── personas/
│   │   ├── instructor.js      # Instructor persona workflows
│   │   ├── student.js         # Student persona workflows
│   │   └── admin.js           # Admin persona workflows
│   ├── workflows/
│   │   ├── login.js           # Login flow tests
│   │   ├── dashboard.js       # Dashboard navigation tests
│   │   ├── exercises.js       # Exercise creation/submission tests
│   │   ├── analytics.js       # Analytics/reporting tests
│   │   └── integrity.js       # Integrity flag tests
│   ├── runner.js              # Main test runner with reporting
│   └── results/               # Test result output directory
package.json                   # Add stagehand dependency
```

---

### Task 1: Install Stagehand and Create Config

**Files:**
- Modify: `package.json` (root)
- Create: `simulation/stagehand/config.js`

**Interfaces:**
- Consumes: Existing Playwright config, `simulation/personas.js`
- Produces: `createStagehandInstance()` function

- [ ] **Step 1: Add stagehand dependency**

```bash
cd /home/nihil/projects/codeinsight
npm install stagehand --save-dev
```

- [ ] **Step 2: Create config.js**

```javascript
/**
 * simulation/stagehand/config.js
 *
 * Stagehand configuration for CodeInsight user testing.
 * Wraps Playwright with LLM-powered natural language commands.
 */

const { Stagehand } = require('stagehand');
const { INSTRUCTOR, PERSONAS } = require('../personas');

const BASE_URL = process.env.BASE_URL || 'http://localhost:5173';

/**
 * Create a Stagehand instance with configured browser.
 * @param {Object} options - Configuration options
 * @param {string} options.persona - Persona identifier (instructor email or student index)
 * @param {string} options.browser - Browser type: 'chromium' | 'firefox' | 'webkit'
 * @param {boolean} options.headless - Run headless (default: true)
 * @returns {Promise<{stagehand: Stagehand, page: any}>}
 */
async function createStagehandInstance({
  persona = INSTRUCTOR.email,
  browser = 'chromium',
  headless = true,
} = {}) {
  const stagehand = new Stagehand({
    browser,
    headless,
    verbose: process.env.STAGEHAND_VERBOSE === 'true',
  });

  const page = await stagehand.init();
  await page.goto(BASE_URL);

  return { stagehand, page };
}

/**
 * Get persona by email or index.
 * @param {string|number} identifier - Email string or index number
 * @returns {Object} Persona object
 */
function getPersona(identifier) {
  if (typeof identifier === 'string') {
    if (identifier === INSTRUCTOR.email) return INSTRUCTOR;
    const found = PERSONAS.find(p => p.email === identifier);
    if (found) return found;
    throw new Error(`Persona not found: ${identifier}`);
  }
  if (typeof identifier === 'number') {
    return PERSONAS[identifier] || INSTRUCTOR;
  }
  return INSTRUCTOR;
}

module.exports = { createStagehandInstance, getPersona, BASE_URL, INSTRUCTOR, PERSONAS };
```

- [ ] **Step 3: Verify installation**

```bash
cd /home/nihil/projects/codeinsight
node -e "const s = require('stagehand'); console.log('Stagehand loaded:', typeof s.Stagehand)"
```

Expected: `Stagehand loaded: function`

- [ ] **Step 4: Commit**

```bash
git add package.json package-lock.json simulation/stagehand/config.js
git commit -m "feat: install Stagehand and add config for user testing"
```

---

### Task 2: Create Login Workflow Tests

**Files:**
- Create: `simulation/stagehand/workflows/login.js`

**Interfaces:**
- Consumes: `createStagehandInstance()`, `getPersona()` from config.js
- Produces: `testInstructorLogin()`, `testStudentLogin()`, `testInvalidLogin()`

- [ ] **Step 1: Create login.js workflow**

```javascript
/**
 * simulation/stagehand/workflows/login.js
 *
 * Login flow tests using natural language commands.
 * Tests: valid login, invalid login, redirect behavior.
 */

const { createStagehandInstance, getPersona, INSTRUCTOR, PERSONAS } = require('../config');

/**
 * Test instructor login flow.
 * @returns {Promise<{passed: boolean, steps: Array}>}
 */
async function testInstructorLogin() {
  const { stagehand, page } = await createStagehandInstance();
  const steps = [];

  try {
    // Step 1: Navigate to login
    await page.act('Navigate to the login page');
    steps.push({ action: 'Navigate to login', success: true });

    // Step 2: Fill email
    await page.act(`Type "${INSTRUCTOR.email}" in the email field`);
    steps.push({ action: 'Fill email', success: true });

    // Step 3: Fill password
    await page.act(`Type "${INSTRUCTOR.password}" in the password field`);
    steps.push({ action: 'Fill password', success: true });

    // Step 4: Click sign in
    await page.act('Click the Sign In button');
    steps.push({ action: 'Click Sign In', success: true });

    // Step 5: Verify redirect to dashboard
    await page.wait(3000);
    const url = page.url();
    const redirected = url.includes('/instructor/dashboard') || url.includes('/instructor');
    steps.push({ action: 'Verify redirect', success: redirected, url });

    return { passed: redirected, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await stagehand.close();
  }
}

/**
 * Test student login flow.
 * @returns {Promise<{passed: boolean, steps: Array}>}
 */
async function testStudentLogin() {
  const { stagehand, page } = await createStagehandInstance();
  const student = PERSONAS[0]; // First student persona
  const steps = [];

  try {
    await page.act('Navigate to the login page');
    steps.push({ action: 'Navigate to login', success: true });

    await page.act(`Type "${student.email}" in the email field`);
    steps.push({ action: 'Fill email', success: true });

    await page.act(`Type "${student.password}" in the password field`);
    steps.push({ action: 'Fill password', success: true });

    await page.act('Click the Sign In button');
    steps.push({ action: 'Click Sign In', success: true });

    await page.wait(3000);
    const url = page.url();
    const redirected = url.includes('/student');
    steps.push({ action: 'Verify redirect', success: redirected, url });

    return { passed: redirected, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await stagehand.close();
  }
}

/**
 * Test invalid login shows error.
 * @returns {Promise<{passed: boolean, steps: Array}>}
 */
async function testInvalidLogin() {
  const { stagehand, page } = await createStagehandInstance();
  const steps = [];

  try {
    await page.act('Navigate to the login page');
    steps.push({ action: 'Navigate to login', success: true });

    await page.act('Type "invalid@test.com" in the email field');
    steps.push({ action: 'Fill invalid email', success: true });

    await page.act('Type "wrongpassword" in the password field');
    steps.push({ action: 'Fill wrong password', success: true });

    await page.act('Click the Sign In button');
    steps.push({ action: 'Click Sign In', success: true });

    await page.wait(2000);
    const hasError = await page.observe('Check if an error message is visible');
    const passed = hasError && hasError.length > 0;
    steps.push({ action: 'Verify error shown', success: passed });

    return { passed, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await stagehand.close();
  }
}

module.exports = { testInstructorLogin, testStudentLogin, testInvalidLogin };
```

- [ ] **Step 2: Test the login workflow**

```bash
cd /home/nihil/projects/codeinsight
node -e "
const { testInstructorLogin } = require('./simulation/stagehand/workflows/login');
testInstructorLogin().then(r => console.log(JSON.stringify(r, null, 2)));
"
```

Expected: `{ passed: true, steps: [...] }`

- [ ] **Step 3: Commit**

```bash
git add simulation/stagehand/workflows/login.js
git commit -m "feat: add Stagehand login workflow tests"
```

---

### Task 3: Create Dashboard Navigation Tests

**Files:**
- Create: `simulation/stagehand/workflows/dashboard.js`

**Interfaces:**
- Consumes: `createStagehandInstance()`, `INSTRUCTOR` from config.js
- Produces: `testInstructorDashboardNavigation()`, `testStudentDashboardNavigation()`

- [ ] **Step 1: Create dashboard.js workflow**

```javascript
/**
 * simulation/stagehand/workflows/dashboard.js
 *
 * Dashboard navigation and interaction tests.
 * Tests: page loads, navigation, data display.
 */

const { createStagehandInstance, INSTRUCTOR, PERSONAS } = require('../config');

const INSTRUCTOR_PAGES = [
  { path: '/instructor/dashboard', name: 'Dashboard', check: 'KPI cards or insight banner' },
  { path: '/instructor/heatmap', name: 'Heatmap', check: 'grid or heatmap visualization' },
  { path: '/instructor/students', name: 'Students', check: 'student list or roster' },
  { path: '/instructor/exercises', name: 'Exercises', check: 'exercise list or table' },
  { path: '/instructor/reports', name: 'Reports', check: 'report tabs or charts' },
  { path: '/instructor/integrity', name: 'Integrity', check: 'integrity flags or queue' },
];

const STUDENT_PAGES = [
  { path: '/student/dashboard', name: 'My Exercises', check: 'exercise list or cards' },
  { path: '/student/progress', name: 'My Progress', check: 'progress chart or mastery' },
  { path: '/student/profile', name: 'My Profile', check: 'profile information' },
];

/**
 * Test instructor dashboard navigation across all pages.
 * @returns {Promise<{passed: boolean, results: Array}>}
 */
async function testInstructorDashboardNavigation() {
  const { stagehand, page } = await createStagehandInstance();
  const results = [];

  try {
    // Login as instructor
    await page.act('Navigate to the login page');
    await page.act(`Type "${INSTRUCTOR.email}" in the email field`);
    await page.act(`Type "${INSTRUCTOR.password}" in the password field`);
    await page.act('Click the Sign In button');
    await page.wait(3000);

    // Test each page
    for (const pageConfig of INSTRUCTOR_PAGES) {
      try {
        await page.act(`Navigate to ${pageConfig.name}`);
        await page.wait(2000);

        const observations = await page.observe(`Check if ${pageConfig.check} is visible`);
        const passed = observations && observations.length > 0;
        results.push({ page: pageConfig.name, passed, observations });
      } catch (error) {
        results.push({ page: pageConfig.name, passed: false, error: error.message });
      }
    }

    const allPassed = results.every(r => r.passed);
    return { passed: allPassed, results };
  } catch (error) {
    return { passed: false, results, error: error.message };
  } finally {
    await stagehand.close();
  }
}

/**
 * Test student dashboard navigation across all pages.
 * @returns {Promise<{passed: boolean, results: Array}>}
 */
async function testStudentDashboardNavigation() {
  const { stagehand, page } = await createStagehandInstance();
  const student = PERSONAS[0];
  const results = [];

  try {
    // Login as student
    await page.act('Navigate to the login page');
    await page.act(`Type "${student.email}" in the email field`);
    await page.act(`Type "${student.password}" in the password field`);
    await page.act('Click the Sign In button');
    await page.wait(3000);

    // Test each page
    for (const pageConfig of STUDENT_PAGES) {
      try {
        await page.act(`Navigate to ${pageConfig.name}`);
        await page.wait(2000);

        const observations = await page.observe(`Check if ${pageConfig.check} is visible`);
        const passed = observations && observations.length > 0;
        results.push({ page: pageConfig.name, passed, observations });
      } catch (error) {
        results.push({ page: pageConfig.name, passed: false, error: error.message });
      }
    }

    const allPassed = results.every(r => r.passed);
    return { passed: allPassed, results };
  } catch (error) {
    return { passed: false, results, error: error.message };
  } finally {
    await stagehand.close();
  }
}

module.exports = { testInstructorDashboardNavigation, testStudentDashboardNavigation };
```

- [ ] **Step 2: Test the dashboard workflow**

```bash
cd /home/nihil/projects/codeinsight
node -e "
const { testInstructorDashboardNavigation } = require('./simulation/stagehand/workflows/dashboard');
testInstructorDashboardNavigation().then(r => console.log(JSON.stringify(r, null, 2)));
"
```

Expected: `{ passed: true, results: [...] }`

- [ ] **Step 3: Commit**

```bash
git add simulation/stagehand/workflows/dashboard.js
git commit -m "feat: add Stagehand dashboard navigation tests"
```

---

### Task 4: Create Exercise Workflow Tests

**Files:**
- Create: `simulation/stagehand/workflows/exercises.js`

**Interfaces:**
- Consumes: `createStagehandInstance()`, `INSTRUCTOR`, `PERSONAS` from config.js
- Produces: `testExerciseCreation()`, `testExerciseSubmission()`

- [ ] **Step 1: Create exercises.js workflow**

```javascript
/**
 * simulation/stagehand/workflows/exercises.js
 *
 * Exercise creation and submission workflow tests.
 * Tests: instructor creates exercise, student submits code.
 */

const { createStagehandInstance, INSTRUCTOR, PERSONAS } = require('../config');

/**
 * Test instructor exercise creation flow.
 * @returns {Promise<{passed: boolean, steps: Array}>}
 */
async function testExerciseCreation() {
  const { stagehand, page } = await createStagehandInstance();
  const steps = [];

  try {
    // Login as instructor
    await page.act('Navigate to the login page');
    await page.act(`Type "${INSTRUCTOR.email}" in the email field`);
    await page.act(`Type "${INSTRUCTOR.password}" in the password field`);
    await page.act('Click the Sign In button');
    await page.wait(3000);
    steps.push({ action: 'Login', success: true });

    // Navigate to exercises
    await page.act('Navigate to Exercises');
    await page.wait(2000);
    steps.push({ action: 'Navigate to Exercises', success: true });

    // Click Create Exercise button
    await page.act('Click the Create Exercise button');
    await page.wait(2000);
    steps.push({ action: 'Click Create Exercise', success: true });

    // Fill exercise title
    await page.act('Type "Stagehand Test Exercise" in the title field');
    steps.push({ action: 'Fill title', success: true });

    // Fill description
    await page.act('Type "A test exercise created by Stagehand" in the description field');
    steps.push({ action: 'Fill description', success: true });

    // Select concept (if dropdown exists)
    try {
      await page.act('Select "Datatypes" from the concept dropdown');
      steps.push({ action: 'Select concept', success: true });
    } catch {
      steps.push({ action: 'Select concept', success: false, note: 'No concept dropdown' });
    }

    // Save exercise
    await page.act('Click the Save or Create button');
    await page.wait(2000);
    steps.push({ action: 'Save exercise', success: true });

    // Verify creation
    const observations = await page.observe('Check if success message or exercise list is visible');
    const passed = observations && observations.length > 0;
    steps.push({ action: 'Verify creation', success: passed });

    return { passed, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await stagehand.close();
  }
}

/**
 * Test student exercise submission flow.
 * @returns {Promise<{passed: boolean, steps: Array}>}
 */
async function testExerciseSubmission() {
  const { stagehand, page } = await createStagehandInstance();
  const student = PERSONAS[0];
  const steps = [];

  try {
    // Login as student
    await page.act('Navigate to the login page');
    await page.act(`Type "${student.email}" in the email field`);
    await page.act(`Type "${student.password}" in the password field`);
    await page.act('Click the Sign In button');
    await page.wait(3000);
    steps.push({ action: 'Login', success: true });

    // Navigate to exercises
    await page.act('Navigate to My Exercises');
    await page.wait(2000);
    steps.push({ action: 'Navigate to Exercises', success: true });

    // Click on first exercise
    await page.act('Click on the first exercise in the list');
    await page.wait(3000);
    steps.push({ action: 'Select exercise', success: true });

    // Wait for code editor
    const hasEditor = await page.observe('Check if a code editor is visible');
    if (hasEditor && hasEditor.length > 0) {
      steps.push({ action: 'Code editor loaded', success: true });

      // Type code
      await page.act('Type "#include <iostream>\nusing namespace std;\nint main() { cout << 42; return 0; }" in the code editor');
      steps.push({ action: 'Type code', success: true });

      // Click Run
      await page.act('Click the Run button');
      await page.wait(5000);
      steps.push({ action: 'Click Run', success: true });

      // Check output
      const output = await page.observe('Check if output or test results are visible');
      const passed = output && output.length > 0;
      steps.push({ action: 'Verify output', success: passed });

      return { passed, steps };
    } else {
      steps.push({ action: 'Code editor not found', success: false });
      return { passed: false, steps };
    }
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await stagehand.close();
  }
}

module.exports = { testExerciseCreation, testExerciseSubmission };
```

- [ ] **Step 2: Test the exercise workflow**

```bash
cd /home/nihil/projects/codeinsight
node -e "
const { testExerciseCreation } = require('./simulation/stagehand/workflows/exercises');
testExerciseCreation().then(r => console.log(JSON.stringify(r, null, 2)));
"
```

Expected: `{ passed: true, steps: [...] }`

- [ ] **Step 3: Commit**

```bash
git add simulation/stagehand/workflows/exercises.js
git commit -m "feat: add Stagehand exercise workflow tests"
```

---

### Task 5: Create Analytics and Integrity Tests

**Files:**
- Create: `simulation/stagehand/workflows/analytics.js`
- Create: `simulation/stagehand/workflows/integrity.js`

**Interfaces:**
- Consumes: `createStagehandInstance()`, `INSTRUCTOR` from config.js
- Produces: `testAnalyticsView()`, `testIntegrityFlags()`

- [ ] **Step 1: Create analytics.js workflow**

```javascript
/**
 * simulation/stagehand/workflows/analytics.js
 *
 * Analytics and reporting tests.
 * Tests: reports page, concept mastery, longitudinal data.
 */

const { createStagehandInstance, INSTRUCTOR } = require('../config');

/**
 * Test analytics and reporting views.
 * @returns {Promise<{passed: boolean, steps: Array}>}
 */
async function testAnalyticsView() {
  const { stagehand, page } = await createStagehandInstance();
  const steps = [];

  try {
    // Login as instructor
    await page.act('Navigate to the login page');
    await page.act(`Type "${INSTRUCTOR.email}" in the email field`);
    await page.act(`Type "${INSTRUCTOR.password}" in the password field`);
    await page.act('Click the Sign In button');
    await page.wait(3000);
    steps.push({ action: 'Login', success: true });

    // Navigate to reports
    await page.act('Navigate to Reports');
    await page.wait(3000);
    steps.push({ action: 'Navigate to Reports', success: true });

    // Check for report tabs
    const tabs = await page.observe('Check if report tabs (Mastery, Completion, Integrity) are visible');
    steps.push({ action: 'Report tabs visible', success: tabs && tabs.length > 0 });

    // Click on different tabs
    try {
      await page.act('Click on the Mastery tab');
      await page.wait(2000);
      const masteryData = await page.observe('Check if mastery data or charts are visible');
      steps.push({ action: 'Mastery tab data', success: masteryData && masteryData.length > 0 });
    } catch (error) {
      steps.push({ action: 'Mastery tab', success: false, error: error.message });
    }

    // Check heatmap
    await page.act('Navigate to Heatmap');
    await page.wait(3000);
    const heatmap = await page.observe('Check if heatmap grid or cells are visible');
    steps.push({ action: 'Heatmap visible', success: heatmap && heatmap.length > 0 });

    const passed = steps.filter(s => s.success).length > steps.length * 0.5;
    return { passed, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await stagehand.close();
  }
}

module.exports = { testAnalyticsView };
```

- [ ] **Step 2: Create integrity.js workflow**

```javascript
/**
 * simulation/stagehand/workflows/integrity.js
 *
 * Integrity flag tests.
 * Tests: integrity queue, flag review, at-risk roster.
 */

const { createStagehandInstance, INSTRUCTOR } = require('../config');

/**
 * Test integrity flag views and actions.
 * @returns {Promise<{passed: boolean, steps: Array}>}
 */
async function testIntegrityFlags() {
  const { stagehand, page } = await createStagehandInstance();
  const steps = [];

  try {
    // Login as instructor
    await page.act('Navigate to the login page');
    await page.act(`Type "${INSTRUCTOR.email}" in the email field`);
    await page.act(`Type "${INSTRUCTOR.password}" in the password field`);
    await page.act('Click the Sign In button');
    await page.wait(3000);
    steps.push({ action: 'Login', success: true });

    // Navigate to integrity
    await page.act('Navigate to Integrity');
    await page.wait(3000);
    steps.push({ action: 'Navigate to Integrity', success: true });

    // Check for integrity flags or empty state
    const flags = await page.observe('Check if integrity flags or empty state message is visible');
    steps.push({ action: 'Integrity page loaded', success: flags && flags.length > 0 });

    // Check intervention queue link on dashboard
    await page.act('Navigate to Dashboard');
    await page.wait(2000);
    const interventionLink = await page.observe('Check if intervention queue link or button is visible');
    steps.push({ action: 'Intervention queue link', success: interventionLink && interventionLink.length > 0 });

    // Check at-risk roster
    const atRisk = await page.observe('Check if at-risk students or roster section is visible');
    steps.push({ action: 'At-risk roster', success: atRisk && atRisk.length > 0 });

    const passed = steps.filter(s => s.success).length > steps.length * 0.5;
    return { passed, steps };
  } catch (error) {
    steps.push({ action: 'Error', success: false, error: error.message });
    return { passed: false, steps };
  } finally {
    await stagehand.close();
  }
}

module.exports = { testIntegrityFlags };
```

- [ ] **Step 3: Commit**

```bash
git add simulation/stagehand/workflows/analytics.js simulation/stagehand/workflows/integrity.js
git commit -m "feat: add Stagehand analytics and integrity workflow tests"
```

---

### Task 6: Create Main Test Runner

**Files:**
- Create: `simulation/stagehand/runner.js`

**Interfaces:**
- Consumes: All workflow modules from `workflows/`
- Produces: `runAllTests()`, JSON report output

- [ ] **Step 1: Create runner.js**

```javascript
/**
 * simulation/stagehand/runner.js
 *
 * Main test runner for Stagehand user testing.
 * Runs all workflows and generates JSON report.
 */

const fs = require('fs');
const path = require('path');
const { testInstructorLogin, testStudentLogin, testInvalidLogin } = require('./workflows/login');
const { testInstructorDashboardNavigation, testStudentDashboardNavigation } = require('./workflows/dashboard');
const { testExerciseCreation, testExerciseSubmission } = require('./workflows/exercises');
const { testAnalyticsView } = require('./workflows/analytics');
const { testIntegrityFlags } = require('./workflows/integrity');

const RESULTS_DIR = path.join(__dirname, 'results');

/**
 * Run all Stagehand user tests and generate report.
 * @param {Object} options - Run options
 * @param {boolean} options.verbose - Print detailed results
 * @returns {Promise<Object>} Test report
 */
async function runAllTests({ verbose = true } = {}) {
  const startTime = Date.now();
  const results = {
    timestamp: new Date().toISOString(),
    duration: 0,
    summary: { total: 0, passed: 0, failed: 0 },
    tests: [],
  };

  const tests = [
    { name: 'Instructor Login', fn: testInstructorLogin, role: 'instructor' },
    { name: 'Student Login', fn: testStudentLogin, role: 'student' },
    { name: 'Invalid Login', fn: testInvalidLogin, role: 'system' },
    { name: 'Instructor Dashboard Navigation', fn: testInstructorDashboardNavigation, role: 'instructor' },
    { name: 'Student Dashboard Navigation', fn: testStudentDashboardNavigation, role: 'student' },
    { name: 'Exercise Creation', fn: testExerciseCreation, role: 'instructor' },
    { name: 'Exercise Submission', fn: testExerciseSubmission, role: 'student' },
    { name: 'Analytics View', fn: testAnalyticsView, role: 'instructor' },
    { name: 'Integrity Flags', fn: testIntegrityFlags, role: 'instructor' },
  ];

  for (const test of tests) {
    results.summary.total++;
    if (verbose) console.log(`\n▶ Running: ${test.name}...`);

    try {
      const testResult = await test.fn();
      results.tests.push({
        name: test.name,
        role: test.role,
        passed: testResult.passed,
        details: testResult.steps || testResult.results || [],
      });

      if (testResult.passed) {
        results.summary.passed++;
        if (verbose) console.log(`  ✓ PASSED`);
      } else {
        results.summary.failed++;
        if (verbose) console.log(`  ✗ FAILED`);
      }
    } catch (error) {
      results.summary.failed++;
      results.tests.push({
        name: test.name,
        role: test.role,
        passed: false,
        error: error.message,
      });
      if (verbose) console.log(`  ✗ ERROR: ${error.message}`);
    }
  }

  results.duration = Date.now() - startTime;

  // Save report
  if (!fs.existsSync(RESULTS_DIR)) {
    fs.mkdirSync(RESULTS_DIR, { recursive: true });
  }
  const reportPath = path.join(RESULTS_DIR, `report-${Date.now()}.json`);
  fs.writeFileSync(reportPath, JSON.stringify(results, null, 2));

  if (verbose) {
    console.log(`\n${'='.repeat(60)}`);
    console.log(`TEST RESULTS: ${results.summary.passed}/${results.summary.total} passed`);
    console.log(`Duration: ${(results.duration / 1000).toFixed(1)}s`);
    console.log(`Report: ${reportPath}`);
    console.log(`${'='.repeat(60)}`);
  }

  return results;
}

module.exports = { runAllTests };

// Run directly
if (require.main === module) {
  runAllTests()
    .then(results => {
      process.exit(results.summary.failed > 0 ? 1 : 0);
    })
    .catch(error => {
      console.error('Fatal error:', error);
      process.exit(1);
    });
}
```

- [ ] **Step 2: Add npm script to package.json**

```bash
cd /home/nihil/projects/codeinsight
```

Edit `package.json` to add:
```json
{
  "scripts": {
    "test:stagehand": "node simulation/stagehand/runner.js",
    "test:stagehand:verbose": "STAGEHAND_VERBOSE=true node simulation/stagehand/runner.js"
  }
}
```

- [ ] **Step 3: Test the runner**

```bash
cd /home/nihil/projects/codeinsight
npm run test:stagehand
```

Expected: All tests run, JSON report saved to `simulation/stagehand/results/`

- [ ] **Step 4: Commit**

```bash
git add simulation/stagehand/runner.js package.json
git commit -m "feat: add Stagehand test runner with JSON reporting"
```

---

### Task 7: Create Results Viewer (Optional)

**Files:**
- Create: `simulation/stagehand/viewResults.js`

**Interfaces:**
- Consumes: JSON reports from `results/` directory
- Produces: Formatted console output

- [ ] **Step 1: Create viewResults.js**

```javascript
/**
 * simulation/stagehand/viewResults.js
 *
 * View and analyze Stagehand test results.
 */

const fs = require('fs');
const path = require('path');

const RESULTS_DIR = path.join(__dirname, 'results');

function viewLatestResults() {
  if (!fs.existsSync(RESULTS_DIR)) {
    console.log('No results found. Run: npm run test:stagehand');
    return;
  }

  const files = fs.readdirSync(RESULTS_DIR)
    .filter(f => f.startsWith('report-') && f.endsWith('.json'))
    .sort()
    .reverse();

  if (files.length === 0) {
    console.log('No report files found.');
    return;
  }

  const latest = JSON.parse(fs.readFileSync(path.join(RESULTS_DIR, files[0]), 'utf-8'));

  console.log('\n' + '='.repeat(60));
  console.log('STAGEHAND TEST RESULTS');
  console.log('='.repeat(60));
  console.log(`Timestamp: ${latest.timestamp}`);
  console.log(`Duration: ${(latest.duration / 1000).toFixed(1)}s`);
  console.log(`Summary: ${latest.summary.passed}/${latest.summary.total} passed`);
  console.log('='.repeat(60));

  for (const test of latest.tests) {
    const icon = test.passed ? '✓' : '✗';
    console.log(`\n${icon} ${test.name} (${test.role})`);
    if (test.error) {
      console.log(`  Error: ${test.error}`);
    }
    if (test.details && test.details.length > 0) {
      for (const detail of test.details.slice(0, 5)) {
        const detailIcon = detail.success ? '  ✓' : '  ✗';
        console.log(`${detailIcon} ${detail.action}`);
      }
    }
  }

  console.log('\n' + '='.repeat(60));
}

viewLatestResults();
```

- [ ] **Step 2: Commit**

```bash
git add simulation/stagehand/viewResults.js
git commit -m "feat: add Stagehand results viewer"
```

---

## Summary

After completing all tasks:

1. **Install**: `npm install stagehand --save-dev`
2. **Run tests**: `npm run test:stagehand`
3. **View results**: `node simulation/stagehand/viewResults.js`
4. **Check reports**: `simulation/stagehand/results/report-*.json`

**Test Coverage:**
- Login flows (instructor, student, invalid)
- Dashboard navigation (all instructor pages, all student pages)
- Exercise workflows (creation, submission)
- Analytics views (reports, heatmap)
- Integrity flags (queue, at-risk roster)

**Next Steps:**
- Add more persona-specific workflows (struggling student, adversarial user)
- Add performance timing metrics
- Integrate with CI/CD pipeline
- Add A/B testing capabilities for UI variants
