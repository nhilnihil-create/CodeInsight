# CLAUDE.md Documentation Update Design

## Overview
This design document outlines the necessary updates to the CLAUDE.md file to accurately reflect the current implementation state of the CodeInsight project. Based on investigation of the codebase, several sections contain outdated information about the implementation status of critical components.

## Areas Requiring Updates

### 1. Known Issues & Remaining Work (2%) Section
**Current State (Lines 160-170):**
```markdown
### Known Issues & Remaining Work (2%)

| Issue | Priority | Component | Status | Effort |
|-------|----------|-----------|--------|--------|
| Academic Integrity Engine (3 placeholder functions) | 🔴 HIGH | backend/services/academicIntegrityEngine.js | 🟡 Needs implementation | 4-6 hrs |
| Code Paste Detection (queries non-existent column) | 🔴 HIGH | backend/services/integrityFlagEngine.js:28 | ⚠️ Will crash | 1-2 hrs |
| Notification Queue (only logs to console) | 🔴 CRITICAL | backend/services/cdsJobQueue.js | ⚠️ Not working | 2-3 hrs |
| Hidden test case separation verification | 🟡 MEDIUM | backend/services/executor.js | 🔄 Needs verification | 1 hr |
| Duplicate section controllers | 🔵 LOW | backend/controllers/ | 🟡 Code quality | 1-2 hrs |
| Deployment to Oracle Cloud | 🔴 HIGH | DevOps | ⏳ Not started | 2-4 hrs |
```

**Proposed Updates:**

1. **Academic Integrity Engine**: Update to reflect that functions are implemented with minor documentation issues:
   - `checkHardcoding()` is actually implemented (lines 16-56) despite placeholder comments
   - `checkBehavioralAnomaly()` and `checkCodeGrowthAnomaly()` are implemented but depend on historical data availability
   - Primary issue is outdated comments/documentation, not missing functionality

2. **Code Paste Detection**: Remove or update this issue as it's not accurate:
   - The `reference_solution` column EXISTS in the exercises table (schema.sql line 46)
   - The `detectCodePaste()` function properly handles missing reference_solution (returns false to avoid false positives)
   - No crash will occur in production

3. **Notification Queue**: Clarify the actual state:
   - Email notification implementation EXISTS and is functional
   - Currently gated by `EMAIL_ENABLED` environment variable and credential availability
   - Would work when properly configured (credentials exist in .env but may be placeholder values)

### 2. Current Implementation Status Section
Several subsections need updating to remove inaccurate "placeholder" or "stubbed" descriptions:

#### Academic Integrity Engine Documentation (Lines 620-626)
**Current:**
```markdown
#### ⚠️ **academicIntegrityEngine.js** — Partially Complete (⚠️ Placeholder Functions)
- `checkBlankTemplate()` — ✅ Working (compares to starter_code)
- `checkHardcoding()` — ❌ Placeholder (returns null)
- `checkBehavioralAnomaly()` — ❌ Placeholder (returns null)
- `checkCodeGrowthPattern()` — ❌ Placeholder (returns null)
- **Note:** Non-functional detectors prevent features from working; see Known Issues #1
- **Implementation:** [backend/services/academicIntegrityEngine.js](backend/services/academicIntegrity
```

**Proposed:**
```markdown
#### ✅ **academicIntegrityEngine.js** — Fully Functional
- `checkBlankTemplate()` — ✅ Working (compares to starter_code)
- `checkHardcoding()` — ✅ Working (detects direct numeric output with minimal computation)
- `checkBehavioralAnomaly()` — ✅ Working (requires historical CDS data for z-score calculation)
- `checkCodeGrowthAnomaly()` — ✅ Working (requires historical submission data for baseline)
- `logPassiveBehavior()` — ✅ Working (merges behavioral data with submission)
- `evaluateIntegrity()` — ✅ Working (orchestrates all checks)
- **Note:** All functions are implemented. Behavioral and growth anomaly checks require historical data to be meaningful but return gracefully when data insufficient.
- **Implementation:** [backend/services/academicIntegrityEngine.js](backend/services/academicIntegrityEngine.js)
```

#### Integrity Flag Engine Documentation (Lines 567-568)
**Current:**
```markdown
│   ├── integrityFlagEngine.js        # Flag generation (⚠️ has bug)
```

**Proposed:**
```markdown
│   ├── integrityFlagEngine.js        # Flag generation ✅
```

#### CDS Job Queue Documentation (Lines 568-569)
**Current:**
```markdown
│   ├── cdsJobQueue.js                # Async CDS queue (⚠️ notifications stubbed)
```

**Proposed:**
```markdown
│   ├── cdsJobQueue.js                # Async CDS queue ✅ (email notifications work when EMAIL_ENABLED=true and credentials configured)
```

#### Submission Controller Documentation (Lines 741-746)
**Current:**
```markdown
   - Call academicIntegrityEngine checks (mostly stubbed):
     → checkBlankTemplate() ✅
     → checkHardcoding() ❌ null
     → checkBehavioralAnomaly() ❌ null
     → checkCodeGrowthPattern() ❌ null
```

**Proposed:**
```markdown
   - Call academicIntegrityEngine checks:
     → checkBlankTemplate() ✅
     → checkHardcoding() ✅
     → checkBehavioralAnomaly() ✅ (returns null if insufficient historical data)
     → checkCodeGrowthAnomaly() ✅ (returns null if insufficient historical data)
```

#### Tech Stack Section (Lines 344-345)
**Current:**
```markdown
| Micro-concept analytics | Deterministic rule engine (40+ rules) | ✅ Implemented |
```

**Proposed:** (No change needed - this is accurate)

### 3. Deployment Readiness Checklist
**Current (Lines 175):**
```markdown
| **Code Quality** | ✅ 98% Ready | 3 critical issues remaining, see Known Issues |
```

**Proposed:**
```markdown
| **Code Quality** | ✅ 98% Ready | See Known Issues section for remaining work items |
```

### 4. Quick Status Snapshot
**Current (Lines 17-18):**
```markdown
| **Overall Completion** | ✅ 98% | Title defense PASSED; 3 critical issues remain |
| **Last Update** | June 2, 2026 | Comprehensive audit complete |
```

**Proposed:**
```markdown
| **Overall Completion** | ✅ 98% | Title defense PASSED; documentation audit complete |
| **Last Update** | June 4, 2026 | Documentation updated to reflect actual implementation state |
```

## Implementation Approach

### Design Decisions
1. **Accuracy over optimism**: Only claim features as implemented when verified in code
2. **Clarity about dependencies**: Clearly state when features depend on External factors (historical data, configuration)
3. **Remove false alarms**: Eliminate issues that don't actually exist (like the non-existent column problem)
4. **Preserve useful information**: Keep legitimate TODO items and actual work remaining

### Specific File Changes
1. Update the Known Issues & Remaining Work table (lines 160-170)
2. Update Academic Integrity Engine documentation (lines 620-626)
3. Update Integrity Flag Engine reference (line 567)
4. Update CDS Job Queue reference (line 568)
5. Update Submission Controller integrity check description (lines 741-746)
6. Update Tech Stack section if needed (line 344-345)
7. Update Deployment Readiness Checklist (line 175)
8. Update Quick Status Snapshot (lines 17-18)

## Rationale
These updates are necessary because:
1. The CLAUDE.md file claims to be "the AUTHORITATIVE reference for the current implementation state" (line 972)
2. Current documentation misleads about what is actually working vs what needs work
3. Accurate documentation is essential for effective AI-assisted development
4. The investigation revealed that many "critical issues" were either resolved or mischaracterized

## Testing & Verification
After implementing these changes:
1. Verify that all claims in CLAUDE.md can be substantiated by examining the referenced code
2. Confirm that no functionality is overstated or understated
3. Ensure the document maintains its role as a reliable reference for understanding the codebase

## Open Questions
None - the updates are based on direct code investigation and verification.

---
*Design submitted for approval. Once approved, changes will be implemented directly to CLAUDE.md.*