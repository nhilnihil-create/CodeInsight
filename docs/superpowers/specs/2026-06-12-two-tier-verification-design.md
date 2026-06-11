# Two-Tier Verification Architecture Design

**Date**: 2026-06-12
**Author**: Claude Code (with user brainstorming)
**Status**: Approved by user

---

## Overview

CodeInsight V2 needs a comprehensive two-tier verification system to stress-test backend analytics engines, validate CDS calculation correctness, and ensure React UI/UX handles real user interactions. This design creates both a backend simulation layer (Tier A) and a browser-based E2E test suite (Tier B), each independently runnable and chainable together.

## Scope

- **Tier A**: `/simulation/` — API-driven semester simulation with 50 student personas
- **Tier B**: `/e2e/` + root `playwright.config.js` — Playwright browser automation for key UI flows
- **Integration**: Root `package.json` scripts, `/api/health` endpoint
- **Out of scope**: Modifying existing frontend mobile-triage Playwright tests; modifying production backend logic beyond the health endpoint

---

## Section 1: Project Structure

```
codeinsight/
├── package.json              ← adds 3 scripts (test:simulation, test:e2e, test:full)
├── playwright.config.js      ← NEW root E2E config
├── backend/
│   ├── server.js             ← ADD: GET /api/health route
│   └── .env                  ← shared DB config (read by simulation)
├── simulation/               ← NEW Tier A
│   ├── package.json          ← deps: axios, pg, tree-sitter, tree-sitter-cpp
│   ├── personas.js           ← 50 personas across 4 tiers + 1 instructor
│   ├── studentGenerator.js   ← C++ AST normalizer + CodeNet 7-concept matching
│   ├── automationRunner.js   ← multi-cycle runner
│   └── validator.js          ← queries DB → SYSTEM_HEALTH_REPORT.md
├── e2e/                      ← NEW Tier B
│   └── classroomWorkflow.spec.js ← auth → join → submit → instructor dashboard
└── frontend/
    └── playwright.config.js  ← UNTOUCHED (mobile-triage only)
```

---

## Section 2: Tier A — Backend Simulation

### 2.1 Personas (`simulation/personas.js`)

Exports:
- `PERSONAS` — array of 50 student objects
- `INSTRUCTOR` — single instructor object

Each student:
```javascript
{
  id: 'sim_tier1_01',          // deterministic, prefix-based cleanup
  name: 'Alice Chen',
  email: 'sim.alice.chen@test.codeinsight',
  password: 'SimPass123!',
  tier: 'high_performer',      // one of 4 tiers
  accuracy: 0.95,              // expected correctness rate
  avgTimeSec: 120,             // average time per submission
  errorProfile: ['none'],      // types of bugs they make
  retryBehavior: 'none',       // 'none' | 'moderate' | 'heavy' | 'spam'
}
```

**Tier distribution:**
| Tier | Count | Accuracy | avgTimeSec | Error Profile | Retry Behavior |
|------|-------|----------|------------|---------------|----------------|
| 1: High Performers | 10 | 90-100% | 60-180s | none | none |
| 2: Medium Learners | 20 | 50-80% | 180-600s | syntax, off-by-one | moderate |
| 3: Struggling Learners | 15 | 10-50% | 600-1800s | infinite loops, logic errors | heavy |
| 4: Adversarial | 5 | N/A | 0-10s | spam, copy-paste, massive payloads | spam |

### 2.2 Student Generator (`simulation/studentGenerator.js`)

**AST Normalizer:**
- Uses `tree-sitter-cpp` to parse C++ source
- Strips all identifiers (variable names, function names) and literals
- Replaces with anonymous tokens (`IDENT`, `NUMBER`, `STRING`)
- Produces a structural hash (SHA-256 of the anonymized AST)

**CodeNet Template Matcher:**
- Pre-computed structural hashes for 7 core concepts:
  - Datatypes, Variables, Conditionals, Loops, Functions, Arrays, OOP
- Maps student's structural hash against template library
- Returns `{ conceptMatch: string, similarity: number, templateId: string }`

**Payload Generator:**
Based on persona tier + exercise type, emits C++ code for:
- `STATE_CORRECT` — correct solution
- `BUG_OFF_BY_ONE` — `< N` vs `<= N`
- `BUG_INFINITE_LOOP` — missing increment, flawed condition
- `BUG_SYNTAX_ERROR` — missing semicolons, undeclared variables
- `FLAG_COPY_PASTE` — correct code, but zero intermediate telemetry markers

**Includes:** `🔥 AI Student Generator Prompt` as a commented block documenting the external LLM configuration pattern.

### 2.3 Automation Runner (`simulation/automationRunner.js`)

**Environment config:**
```javascript
require('dotenv').config({ path: '../backend/.env' });
```

**Setup phase:**
1. Create instructor account via `POST /api/auth/register`
2. Login via `POST /api/auth/login` (capture cookie)
3. Create section via `POST /api/sections` (extract `inviteCode`)
4. Register all 50 students via `POST /api/auth/register`
5. Enroll all via `POST /api/sections/join` with invite code
6. Create exercises (baseline + stress + adversarial) via `POST /api/exercises`

**Cycle 1 — Baseline Run:**
- Exercise: "Hello World" or simple variable math
- All tiers submit correct solutions
- Pass rate: ~80%, minimal retries (1-2 attempts)
- Purpose: verify happy-path data flows through submissions → CDS → alerts

**Cycle 2 — Stress Run:**
- Exercise: "Print numbers 1 to N" (Loops concept)
- Tier 1-2: submit correct solutions after 1-3 attempts
- Tier 3: flood with `BUG_INFINITE_LOOP` payloads, test:
  - Docker sandbox catches infinite loops without crashing
  - PostgreSQL handles concurrent submission writes
  - `SELECT ... FOR UPDATE` on join resolves race conditions
- Tier 4: submits massive binary strings, compiler-breaking code

**Cycle 3 — Adversarial Run:**
- Tier 4 executes:
  - Rapid script spamming (10+ submissions in <1 second)
  - Perfect answers with zero typing telemetry (copy-paste detection)
  - Massive payload injections (boundary testing)
- Verify `integrity_flags` table populated correctly

**CDS Trigger:**
- Programmatically close exercises via `POST /api/exercises/:id/close`
- Or call batch CDS computation directly
- Verify `cds_scores` and `cds_snapshots` populated

### 2.4 Validator (`simulation/validator.js`)

**Environment config:**
```javascript
require('dotenv').config({ path: '../backend/.env' });
```

Connects directly to PostgreSQL, queries:
- `submissions` — count by student, by exercise, by correctness
- `cds_scores` — per-student CDS values, classification distribution
- `cds_snapshots` — audit trail completeness
- `integrity_flags` — flag counts by type
- `behavioral_events` — event completeness

**Generates `simulation/SYSTEM_HEALTH_REPORT.md`:**

```markdown
# System Health Report — Generated YYYY-MM-DD

## CDS Consistency: [PASS/FAIL]
- Baseline exercise avg CDS: X.XX (expected: < 0.30)
- Stress exercise avg CDS: X.XX (expected: > 0.50)
- Margin: X.XX ✓

## Data Parity: [PASS/FAIL]
- Expected submissions: 150 (50 students × 3 cycles avg)
- Actual submissions: N
- Missing: N

## Resilience Score: XX%
- Infinite loops caught: N/N
- Backend crashes: 0
- Sandbox timeouts: N

## Integrity Flags
- Copy-paste flags: N
- Growth velocity flags: N
- Blank submission flags: N

## CDS Snapshot Audit Trail
- Snapshots recorded: N
- Students with snapshots: N/50
```

---

## Section 3: Tier B — Playwright E2E

### 3.1 Root `playwright.config.js`

```javascript
const { defineConfig, devices } = require('@playwright/test');

module.exports = defineConfig({
  testDir: './e2e',
  fullyParallel: false,
  workers: 1,
  reporter: 'html',

  use: {
    baseURL: 'http://127.0.0.1:5173',
    trace: 'on-first-retry',
  },

  webServer: [
    {
      command: 'NODE_OPTIONS="--max-old-space-size=1024" cd frontend && npm run dev -- --host 127.0.0.1 --port 5173',
      url: 'http://127.0.0.1:5173',
      reuseExistingServer: false,
      timeout: 60000,
    },
    {
      command: 'cd backend && npm run start',
      url: 'http://127.0.0.1:5000/api/health',
      reuseExistingServer: false,
      timeout: 60000,
    },
  ],

  projects: [
    {
      name: 'chromium',
      use: { ...devices['Desktop Chrome'] },
    },
  ],
});
```

**Key decisions:**
- `testDir: './e2e'` — hardcoded to root e2e folder, won't leak into frontend/tests
- `workers: 1` + `fullyParallel: false` — strict sequential execution, prevents OOM
- `reuseExistingServer: false` — always starts fresh, self-contained
- `127.0.0.1` everywhere — avoids WSL2 IPv6 localhost trap
- Vite RAM cap: `NODE_OPTIONS="--max-old-space-size=1024"` (1GB heap)

### 3.2 `e2e/classroomWorkflow.spec.js`

**Test 1: Authentication Gate**
- Navigate to `http://127.0.0.1:5173`
- Click "Instructor Portal" → assert role state configured, routing to instructor view
- Click "Student Access" → assert different state
- Cross-role login attempt → assert error toast visible

**Test 2: Student Join Code Gate**
- Register fresh student via UI forms
- Assert dashboard shows ONLY "Enter code to join" panel (empty state)
- Type invalid code → assert error message renders
- Type valid instructor code → assert UI transitions to workspace WITHOUT hard page reload (check no full navigation event)

**Test 3: Workspace Code Submission Flow**
- Navigate to workspace
- Target Monaco Editor: `page.getByRole('code').nth(0)`
- Click to focus → `ControlOrMeta+KeyA` → `Backspace` (clear starter code)
- `page.keyboard.type(cppCode, { delay: 50 })` — simulated human typing
- Click submit → assert loading spinner visible
- Assert telemetry elements render (attempt counter, time tracking)
- Assert success/failure feedback visible

**Test 4: Instructor Visualization Panel**
- Login as instructor
- Navigate to section dashboard
- Assert concept difficulty heatmap renders (visual DOM element present)
- Assert student roster table populated
- Assert CDS classification badges visible with correct color coding

---

## Section 4: Integration & Data Lifecycle

### 4.1 Root `package.json` scripts

```json
{
  "scripts": {
    "test:simulation": "npm test --prefix simulation",
    "test:e2e": "npx playwright test --config=playwright.config.js",
    "test:full": "npm run test:simulation -- --no-cleanup && npm run test:e2e"
  }
}
```

### 4.2 Cleanup-at-Start Strategy

Both tiers perform cleanup **before** running, not after:
- Identify all users matching `sim_tier*` prefix
- Delete their: `behavioral_events`, `audit_log`, `submissions`, `cds_scores`, `cds_snapshots`, `integrity_flags`, `enrollments`, `users` entries
- This ensures clean slate for current run AND leaves data available for post-run inspection

**Standalone mode** (`test:simulation` or `test:e2e`):
1. Clean old `sim_tier*` data
2. Run tests
3. Data persists for manual inspection

**Chained mode** (`test:full`):
1. Simulation cleans old data → runs → leaves data
2. E2E sees populated dashboard from simulation data
3. E2E runs its own verification against live data
4. Final cleanup optional (user can inspect)

### 4.3 Backend Health Check

Add to `backend/server.js`:
```javascript
app.get('/api/health', (req, res) => {
  res.status(200).json({
    status: 'up',
    db: !!process.env.DATABASE_URL,
    time: new Date().toISOString()
  });
});
```

This ensures Playwright's `webServer` waits for full backend readiness before launching tests.

---

## Section 5: Error Handling & Resilience

### 5.1 Simulation Error Handling
- HTTP errors logged with full response body
- DB connection failures retry up to 3 times with exponential backoff
- Individual student failures don't crash the entire cycle
- Partial results still generate validator report

### 5.2 Playwright Error Handling
- `trace: 'on-first-retry'` — captures trace on retry for debugging
- Screenshots on failure in `e2e/test-results/`
- Health check ensures both servers are up before tests begin
- Sequential execution prevents resource contention

### 5.3 Non-Disruption Guarantees
- All simulation data uses `sim_tier*` prefix — never touches production data
- Cleanup is prefix-scoped, not table-wide
- E2E creates ephemeral test accounts that are cleaned up
- No modifications to production tables, only reads and prefix-scoped writes

---

## Section 6: Dependencies

### `simulation/package.json`
```json
{
  "name": "codeinsight-simulation",
  "version": "1.0.0",
  "scripts": {
    "test": "node automationRunner.js && node validator.js"
  },
  "dependencies": {
    "axios": "^1.6.0",
    "pg": "^8.11.0",
    "tree-sitter": "^0.22.0",
    "tree-sitter-cpp": "^0.23.4"
  }
}
```

### Root `package.json` additions
```json
{
  "devDependencies": {
    "@playwright/test": "^1.60.0"
  }
}
```

`@playwright/test` already exists at root level — no new root dependency needed.

---

## Acceptance Criteria

1. `npm run test:simulation` completes all 3 cycles, generates `SYSTEM_HEALTH_REPORT.md`
2. `npm run test:e2e` runs 4 test blocks, all passing
3. `npm run test:full` runs simulation then E2E, E2E sees simulation data on instructor dashboard
4. Report shows CDS consistency PASS, data parity PASS, resilience score > 95%
5. No production data affected (prefix-scoped only)
6. RAM usage stays under 2GB during full run
