# E2E Real-World Simulation — Design Spec

**Date**: 2026-06-17  
**Status**: Approved for implementation  
**Total students**: 20 (5 archetypes × 4)  
**Concurrency**: 3 simultaneous Playwright sessions  
**Backend**: Real `instructor@psu.edu` account, Docker compilation, real engines  

---

## 1. Architecture Overview

A standalone Playwright-based E2E orchestration that simulates 20 students solving a C++ "sum 1..N" exercise through the real browser interface. All submissions go through the full backend pipeline: Docker compilation, integrity engine, live CDS, and (after exercise close) batch CDS + alerts.

**Key design decisions:**
- Full browser via Playwright (not API-only)
- Character-by-character typing for realism
- 3 concurrent sessions to stress-test race conditions
- Real backend `academicIntegrityEngine.js`, `cdsEngine.js`, etc.
- Uses existing `instructor@psu.edu` account for instructor actions
- Test data left in-place for user inspection (cleanup script provided)

---

## 2. File Layout

```
simulation/e2e/
├── orchestrator.js          # Main entry: setup → submit → close → verify → restart
├── config.js                # Environment, credentials, paths
├── personas.js              # 20 students with code/behavior/expectation data
├── exercise.js              # Exercise definition (test cases, starter code, etc.)
├── submitter.js             # Per-student browser flow (login → type → submit)
├── concurrent.js            # 3-way concurrent session pool
├── verifier.js              # DB/API verification (submissions, flags, CDS, alerts)
├── restart.js               # Server restart mid-flow test
└── cleanup.js               # Remove all test data
```

---

## 3. Exercise: "Sum 1..N"

A simple C++ loop exercise appropriate for testing all integrity engines.

### Problem
Write a program that reads an integer N and prints the sum of numbers from 1 to N.

### Test Cases
| Input | Expected | Hidden |
|-------|----------|--------|
| 10 | 55 | No |
| 5 | 15 | No |
| 100 | 5050 | Yes |
| 1 | 1 | Yes |

### Starter Code
```cpp
#include <iostream>
using namespace std;

int main() {
    // TODO: Implement your solution here
    
    return 0;
}
```

### Reference Solution
```cpp
#include <iostream>
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
}
```

### Concept Tags
- loops, variables, input-output

---

## 4. Student Personas (20 total)

### Group 1: High Performer (S01–S04)
- **Behavior**: Fast typing (60-100ms/char), no tab switches, no paste, no idle
- **Attempts**: 1 correct submission
- **Code**: Proper loop, clean style, each with slightly different variable naming
- **Expected flags**: None
- **Expected CDS**: Low

### Group 2: Average (S05–S08)
- **Behavior**: Moderate typing (100-180ms/char), 2-3 tab switches, 1-2s idle
- **Attempts**: 2-3 attempts (1-2 wrong, learn from errors)
  - Attempt 1: Wrong code (off-by-one, wrong variable, etc.)
  - Attempt 2 (or 3): Correct solution
- **Expected flags**: None
- **Expected CDS**: Low–Moderate

### Group 3: Struggling / Retry Storm (S09–S12)
- **Behavior**: Slow typing (180-350ms/char), 5+ tab switches, 10-30s idle, occasional paste
- **Attempts**: 4-5 attempts (mostly wrong, final maybe correct)
  - Attempt 1: Completely wrong (prints constant)
  - Attempt 2: Syntax error
  - Attempt 3: Partial logic but wrong
  - Attempt 4: Almost correct
  - Attempt 5: Correct (maybe)
- **Expected flags**: RETRY_STORM, possibly INSTANT_SUCCESS
- **Expected CDS**: High

### Group 4: Hardcoder (S13–S16)
- **Behavior**: Fast paste via Shift+Insert (simulated Ctrl+V), no loop code
- **Attempts**: 1 attempt (paste pre-computed answer)
- **Code**: `cout << 55;` — direct numeric output, no loop, no variables
- **Expected flags**: HARDCODING
- **Expected CDS**: High (blank/hardcoder special case → CDS=1.0)

### Group 5: Blank Submitter (S17–S20)
- **Behavior**: Type a few characters or nothing
- **Attempts**: 1-2 attempts (submit empty or starter code)
- **Code**: Empty or identical to starter code
- **Expected flags**: BLANK_TEMPLATE
- **Expected CDS**: High (blank special case → CDS=1.0)

---

## 5. Concurrent Execution Flow

### Orchestrator Sequence

```
orchestrator.js
  │
  ├── PHASE 1: SETUP (API calls)
  │     ├─ 1a. Login as instructor@psu.edu → get token
  │     ├─ 1b. Create section "E2E Test Section"
  │     ├─ 1c. Register 20 students (student-XX@e2e.test)
  │     ├─ 1d. Enroll all 20 in the section
  │     └─ 1e. Create exercise "Sum 1..N" under the section
  │
  ├── PHASE 2: SUBMISSIONS (Playwright, 3 concurrent)
  │     ├─ Split 20 students into 3 session queues (7+7+6)
  │     ├─ Promise.allSettled([session1, session2, session3])
  │     │     └─ Each session per student:
  │     │           ├─ Launch headless Chromium
  │     │           ├─ Login via browser UI (email/password fields)
  │     │           ├─ Navigate to /student/exercises
  │     │           ├─ Open the exercise by URL
  │     │           ├─ For each attempt:
  │     │           │     ├─ Focus editor
  │     │           │     ├─ Typing simulation (character by character)
  │     │           │     ├─ Click Submit button
  │     │           │     ├─ Wait for test results (poll for result DOM)
  │     │           │     └─ Log attempt result
  │     │           └─ Close browser
  │
  ├── PHASE 3: CLOSE EXERCISE (API)
  │     ├─ POST /api/exercises/:id/close → triggers batch CDS
  │     └─ Wait for CDS computation to complete
  │
  ├── PHASE 4: VERIFICATION (DB + API)
  │     ├─ 4a. Submissions: count, correctness, per-student
  │     ├─ 4b. Integrity flags: types, severities, per-student
  │     ├─ 4c. CDS scores: all students scored, classifications match
  │     ├─ 4d. Alerts: high-CDS alerts generated
  │     └─ 4e. Snapshots: cds_snapshots audit trail written
  │
  ├── PHASE 5: SERVER RESTART TEST
  │     ├─ 5a. Note server PID
  │     ├─ 5b. Kill backend (SIGTERM)
  │     ├─ 5c. Wait 5s
  │     ├─ 5d. Restart backend
  │     ├─ 5e. Wait for server to be healthy
  │     ├─ 5f. Submit one final attempt via API
  │     └─ 5g. Verify submission persisted in DB
  │
  └── PHASE 6: REPORT
        ├─ Print summary table
        ├─ Save JSON report to simulation/e2e/results/
        └─ Exit with code 0 if all pass, 1 on critical failure
```

---

## 6. Typing Simulation Details

Each keystroke simulation uses Playwright's `page.keyboard.type()` with character-by-character delays.

### Per-archetype timing
| Archetype | Keystroke delay | Pause pattern |
|-----------|----------------|---------------|
| High Performer | 60-100ms random | None |
| Average | 100-180ms random | 1-2s pause mid-code |
| Struggling | 180-350ms random | 3-5s pauses, backspace typos |
| Hardcoder | N/A (paste) | Paste via Ctrl+V |
| Blank Submitter | Minimal typing | Submit almost immediately |

### Code per student
Each of the 4 students per archetype gets a unique version of their archetype's code pattern:
- Different variable names (sum → total → result → accumulator)
- Different spacing/indentation
- Different comments (or none)

This avoids exact-duplicate detection issues while preserving the archetype's core pattern.

---

## 7. Verification Thresholds

### Phase 4 Pass/Fail Criteria

| Check | Method | Pass Criteria |
|-------|--------|---------------|
| Submissions exist | DB query | `count >= 20` |
| Each student submitted | DB query | All 20 have ≥1 submission |
| Test results stored | DB query | All submissions have non-null `test_results` |
| HARDCODING flags | DB query | ≥3 of 4 hardcoders flagged |
| BLANK_TEMPLATE flags | DB query | ≥3 of 4 blank submitters flagged |
| RETRY_STORM flags | DB query | ≥2 of 4 struggling students flagged |
| All have CDS scores | DB query | 20/20 have `cds_scores` row |
| CDS distribution | DB query | At least 1 High and 1 Low |
| Alerts for High CDS | DB query | ≥1 alert in `analytics_alerts` table |
| Snapshots written | DB query | ≥1 entry in `cds_snapshots` |
| Server restart recovery | API + DB | Submission persists after restart |

### Student expectations per archetype
| Archetype | Min flags | Expected CDS range |
|-----------|-----------|-------------------|
| High Performer | 0 | Low (<0.31) |
| Average | 0 | Low–Moderate (<0.51) |
| Struggling | ≥1 (RETRY_STORM) | Moderate–High (>0.31) |
| Hardcoder | ≥1 (HARDCODING) | High (>0.50, flagged special case) |
| Blank Submitter | ≥1 (BLANK_TEMPLATE) | High (>0.50, flagged special case) |

---

## 8. Database Connection

Direct PostgreSQL connection via `pg` module for verification queries.

### Connection
```
host: localhost
port: 5432
database: codeinsight
user: codeuser
password: codepassword123
```

### Key queries for verification
```sql
-- Submissions count
SELECT COUNT(*) FROM submissions WHERE exercise_id = $1;

-- Integrity flags by type
SELECT flag_type, COUNT(*) FROM integrity_flags WHERE exercise_id = $1 GROUP BY flag_type;

-- CDS scores
SELECT student_id, cds, classification FROM cds_scores WHERE exercise_id = $1;

-- Alerts
SELECT * FROM analytics_alerts WHERE exercise_id = $1;

-- Snapshots
SELECT COUNT(*) FROM cds_snapshots WHERE exercise_id = $1;
```

---

## 9. Server Restart Test

### Procedure
1. Get backend PID: `pgrep -f "node.*server.js"` or similar
2. Send SIGTERM: `kill <PID>`
3. Poll for process exit (max 5s)
4. Restart: same command or find and run start script
5. Poll health endpoint `GET /api/health` until 200 (max 30s)
6. Submit one attempt via API: `POST /api/submissions/submit`
7. Query DB: verify submission exists with `submitted_at` after restart timestamp

### Rollback
If backend restart fails or takes too long, mark test as skipped (not failed), since this tests infrastructure behavior, not application logic.

---

## 10. Cleanup

Provided as a separate script (`cleanup.js`) to run manually. Does NOT run automatically so test data remains for inspection.

### Cleanup order (respect FK constraints)
1. Delete `integrity_flags` for the exercise
2. Delete `analytics_alerts` for the exercise
3. Delete `cds_snapshots` for the exercise
4. Delete `cds_scores` for the exercise
5. Delete `submissions` for the exercise
6. Delete `behavioral_events` for test students
7. Delete exercise from section (soft: just close it)
8. Delete enrollments for test students
9. Delete test users (student accounts)
10. Optionally: delete the section itself

---

## 11. Error Handling

| Scenario | Behavior |
|----------|----------|
| Student login fails | Retry once, then skip student, log failure |
| Exercise not found | Skip student session, fail phase |
| Submission fails | Log error, continue to next student |
| Docker not available | Skip Docker tests, mark as warning |
| Server restart fails | Mark restart test as skipped, continue |
| DB connection fails | Abort with clear error message |
| Timeout (per submission) | 60s max, mark as failed if exceeded |

---

## 12. Output / Report

### Console output
```
═══════════════════════════════════════════════
  E2E REAL-WORLD SIMULATION
  20 students × 5 archetypes × 3 concurrent
═══════════════════════════════════════════════

PHASE 1: Setup...
  ✓ Section created (id=88)
  ✓ 20 students registered
  ✓ All enrolled in section 88
  ✓ Exercise created (id=200)

PHASE 2: Submissions (3 concurrent)...
  ┌─ Session A (7 students) ─────────────────┐
  │ S01 (High)   ✓ attempt 1/1 (correct)     │
  │ S04 (High)   ✓ attempt 1/1 (correct)     │
  │ S07 (Avg)    ✗ attempt 1, ✓ attempt 2    │
  │ S10 (Strug)  ✗✗✗✗✓ attempt 5            │
  │ S13 (Hard)   ✓ attempt 1 (HARDCODING)    │
  │ S16 (Hard)   ✓ attempt 1 (HARDCODING)    │
  │ S19 (Blank)  ✓ attempt 1 (BLANK_TEMPLATE)│
  └──────────────────────────────────────────┘
  ┌─ Session B (7 students) ─────────────────┐
  ...                                         │
  └──────────────────────────────────────────┘
  ┌─ Session C (6 students) ─────────────────┐
  ...                                         │
  └──────────────────────────────────────────┘

PHASE 3: Exercise Close...
  ✓ Batch CDS computed

PHASE 4: Verification...
  ✓ Submissions: 47 total (all have test_results)
  ✓ Integrity flags: 8 total (4 HARDCODING, 4 BLANK_TEMPLATE, 2 RETRY_STORM)
  ✓ CDS scores: 20/20 students scored
  ✓ Distribution: Low=8, Moderate=5, High=7
  ✓ Alerts: 5 generated for High CDS
  ✓ Snapshots: 1 audit entry

PHASE 5: Server Restart...
  ✓ Backend killed (PID 12345)
  ✓ Backend restarted
  ✓ Recovery submission persisted

═══════════════════════════════════════════════
  RESULT: 21/21 checks PASSED
  Duration: 14m 32s
═══════════════════════════════════════════════
  Data preserved for inspection:
  Section: "E2E Test Section" (id=88)
  Exercise: "Sum 1..N" (id=200)
  Students: student-01@e2e.test ... student-20@e2e.test
  Run cleanup.js to remove test data
═══════════════════════════════════════════════
```

### JSON report
Saved to `simulation/e2e/results/report-<timestamp>.json` with all check results, timestamps, and error details.

---

## 13. Dependencies

All already present in the project:
- Playwright (`simulation/stagehand` uses it)
- `pg` (PostgreSQL client) — verify available in `package.json`
- Backend running on port 5000 with `PLAYWRIGHT=1` env var
- Frontend running on port 5173
- Docker for C++ compilation sandbox

### State prerequisites
- Backend running (port 5000)
- Frontend running (port 5173)
- PostgreSQL accessible (localhost:5432)
- Docker available for code execution
- `instructor@psu.edu` user exists
