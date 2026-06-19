# Deterministic Rule Hardening Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task.

**Goal:** Systematically harden all 4 deterministic analysis engines against edge cases, evasion tactics, and silent failure modes, replacing AI intuition with exhaustive rule coverage.

**Architecture:** Run 3 iterative analysis phases (Rule Extraction Matrix → Edge-Case Fuzzing → CDS State Transition Mapping) using AI as an adversarial compiler engineer, then codify all findings as deterministic rules, tree-sitter queries, and regression tests.

**Tech Stack:** Node.js, tree-sitter (C++ grammar), PostgreSQL, Jest, deterministic detectors only

## Global Constraints

- Zero AI/ML in codified output — all final rules are deterministic (regex, tree-sitter queries, AST traversal, heuristic formulas)
- All 793 existing tests must continue to pass
- Follow existing patterns in the target modules (detector objects, rule arrays, evidence extractors)
- Every edge case must map to an actionable deterministic check
- Silent failure analysis must include how a student could trick each rule

---

## Task 1: Iteration 1 — Code-to-Rule Extraction Matrix (Academic Integrity + AST)

**Files:**
- Analyze: `backend/services/academicIntegrityEngine.js`
- Analyze: `backend/services/astVerifier.js`
- Create: `backend/services/rules/hardcodingRuleMatrix.md` (documentation)
- Modify: `backend/services/academicIntegrityEngine.js` (additions from matrix)
- Modify: `backend/services/astVerifier.js` (additions from matrix)
- Test: `backend/test/academicIntegrityEdgeCases.test.js`

**Interfaces:**
- Consumes: `checkHardcoding(code, exercise, submission)`, `checkBlankTemplate(code, starterCode)`, `verify(code, requirements, options)`, `checkBadPatterns(tree, conceptName, code)`, `checkVariableUsage(tree, conceptName)`, `checkOutputDependency(tree, requiredNodes)`
- Produces: Complete rule matrix with trigger conditions, behavioral expectations, and silent failure modes per check

- [ ] **Step 1: Extract rule matrix from checkHardcoding**
  - Document every trigger pattern (cout regex, computation scoring, loop/variable detection)
  - Identify silent failures: renamed cout (printf/puts bypass), computed literals (constexpr, macro-based), obfuscated computation (bit manipulation instead of arithmetic), test case manipulation
  - Hardcode detection gaps: print via putchar() in loop, string-based output (std::ostringstream), return-value cheating (program returns expected value as exit code)

- [ ] **Step 2: Extract rule matrix from checkBlankTemplate**
  - Document exact match logic and whitespace-only bypass
  - Identify silent failures: whitespace + single character change, comment-only changes, reshuffled includes

- [ ] **Step 3: Extract rule matrix from astVerifier checks**
  - Required nodes check: alternative node sets (for/while/do) — can student use a computed goto instead?
  - Empty bodies check: does `;` alone constitute empty body? Ternary operators?
  - Variable usage: what if student uses pointers/references instead of identifiers? Macros?
  - Output dependency: what about output via fprintf to stderr instead of stdout? What about volatile side effects?

- [ ] **Step 4: Codify identified gaps as new deterministic rules**
  - Add `checkHardcodingExtended()` to academicIntegrityEngine.js covering printf, putchar, ostringstream, return-value evasion
  - Add `checkBlankTemplateExtended()` covering comment-only changes, include reshuffles
  - Add empty body edge cases to astVerifier.js (semicolon-only, ternary expressions, comma operator)
  - Add extended output dependency checks (stderr, exit code, file output)

- [ ] **Step 5: Write edge-case regression tests**
  - 5+ edge cases for hardcoding evasion techniques
  - 3+ edge cases for blank template bypasses
  - 5+ edge cases for AST verification silent failures
  - Test file: `backend/test/academicIntegrityEdgeCases.test.js`

- [ ] **Step 6: Run tests and verify all pass**

---

## Task 2: Iteration 2 — Automated Edge-Case Fuzzing (Micro-Concept + Class Misconception)

**Files:**
- Analyze: `backend/services/microConceptEngine.js`
- Analyze: `backend/services/classMisconceptionReport.js`
- Analyze: `backend/services/microConceptTaxonomy.js`
- Analyze: `backend/services/badPatterns.js`
- Modify: `backend/services/microConceptEngine.js` (add cross-cutting detectors)
- Modify: `backend/services/classMisconceptionReport.js` (add root cause patterns)
- Test: `backend/test/microConceptEdgeCases.test.js`

**Interfaces:**
- Consumes: `detectMicroConcepts(context, conceptName)`, `formatFeedback(detectionResults)`, `generateClassMisconceptionReport(exerciseId)`, `MICRO_CONCEPT_RULES`, `BAD_PATTERNS`
- Produces: 15 edge-case code snippets with expected AST breakdown and misconception tags

- [ ] **Step 1: Generate 5 edge-case snippets for malformed-but-compilable syntax**
  - Snippet examples: comma operator abuse, ternary nesting, short-circuit logic, typeof hacks, placement new
  - For each: write expected AST node breakdown + expected misconception tag

- [ ] **Step 2: Generate 5 edge-case snippets for obfuscated structural flows**
  - Deeply nested loops (10+ levels with goto), setjmp/longjmp control flow, computed goto (label as values), Duff's device, signal handler-based flow

- [ ] **Step 3: Generate 5 edge-case snippets for academic integrity evasion**
  - Variable renaming + semantic shifting + control flow inversion, macro-based logic that compiles to same semantics, template metaprogrammed loops, recursive descent instead of iteration, lambda-based recursion

- [ ] **Step 4: Add cross-cutting detectors for discovered edge-case patterns**
  - New detectors in microConceptEngine.js crossCuttingRules for: comma operator abuse, empty loop bodies, suspiciously over-nested structures, implicit fallthrough in switch
  - Add macro obfuscation heuristic to crossCuttingRules

- [ ] **Step 5: Extend classMisconceptionReport.js root cause patterns**
  - Add root cause inference for all 25 concepts (currently only handles ~7)
  - Add recommended action patterns for all 25 misconception types

- [ ] **Step 6: Write micro-concept edge-case tests**
  - 15 tests (one per edge case snippet) verifying engine produces correct output without crashing
  - Test file: `backend/test/microConceptEdgeCases.test.js`

- [ ] **Step 7: Run tests and verify all pass**

---

## Task 3: Iteration 3 — CDS Engine State-Transition Boundary Mapping

**Files:**
- Analyze: `backend/services/cdsEngine.js`
- Analyze: `backend/services/alertEngine.js`
- Modify: `backend/services/cdsEngine.js` (add guard validation)
- Test: `backend/test/cdsStateTransition.test.js`

**Interfaces:**
- Consumes: `computeBatchCDS(exerciseId, db)`, `calculateLiveCDS(studentId, exerciseId, db)`, `computeClassStats(rawValues)`, `normalizeWithStats(value, stats)`, `classify(cds, isPreliminary)`, `getLivePeerRanking(exerciseId, db)`
- Produces: Actionable engineering spec for state-machine boundary conditions

- [ ] **Step 1: Map normalization boundary conditions**
  - Zero-variance classes (all students identical): denominator = 0 → returns 0.00. Is this correct? What happens with single-student class?
  - Single outlier student (one student with 100 failures vs others with 0): does p95 capping correctly handle this?
  - All students have integrity flags (excluded set equals class): filteredSubMap is empty — what happens to normalization stats?
  - Mixed flag types: blank vs hardcoding vs behavioral — all treated same for exclusion. Should they be?

- [ ] **Step 2: Map post-solution cutoff edge cases**
  - Student solves correctly on first attempt (cutoff = 1, counted = [attempt 1]) — correct
  - Student never solves correctly (cutoff = null, counted = all attempts) — but what if they never solve and have integrity flag?
  - Student solves correctly but gets flag on same attempt (firstAccepted is null because flag_id is null check) — is this correct? Should flagged-accepted not count as accepted?
  - Multiple accepted attempts: firstAccepted finds earliest, but what about earlier correct attempts that were flagged?

- [ ] **Step 3: Map live CDS divergence from batch CDS**
  - Batch CDS uses pre-computed global stats; live CDS recomputes per-call — can these diverge? Under what conditions?
  - Race condition: student submits between batch compute and live query — live shows different CDS for same data
  - Preliminary class logic (< 3 students) only applies to batch — live CDS doesn't use isPreliminary. Is this a bug?

- [ ] **Step 4: Add deterministic validation guards**
  - Guard `computeClassStats` against empty filtered values returning NaN
  - Guard `normalizeWithStats` against capping with p95 = 0 (if all values are 0)
  - Add `filteredSubMap` empty-set handling in computeBatchCDS (skip normalization, assign unscored)
  - Document preliminary class handling gap for live CDS
  - Add `computeClassStats` edge-case tests for single-student class, all-identical students, all-excluded students

- [ ] **Step 5: Write CDS state transition tests**
  - Zero-variance normalization test
  - Single student class test
  - All-excluded students test (all flagged)
  - Mixed flag exclusion test
  - Live vs. batch CDS divergence test
  - Edge case: student with null/undefined time_spent_seconds
  - Test file: `backend/test/cdsStateTransition.test.js`

- [ ] **Step 6: Run tests and verify all pass**

---

## Task 4: Codify All Findings — Close the Loop

**Files:**
- Modify: `backend/services/microConceptTaxonomy.js` (add edge case detectors)
- Modify: `backend/services/badPatterns.js` (add new patterns from edge-case analysis)
- Modify: `backend/services/academicIntegrityEngine.js` (add extended checks)
- Modify: `backend/services/microConceptEngine.js` (enhance detectors)
- Modify: `backend/services/cdsEngine.js` (add guard validations)
- Test: All test files

**Interfaces:**
- Consumes: ALL findings from Tasks 1-3
- Produces: Updated deterministic engines with 100% reliable edge-case coverage

- [ ] **Step 1: Merge all new rules into microConceptTaxonomy.js**
  - Add ~10 new rule blocks covering edge cases from Task 2 fuzzing
  - Include: comma operator abuse, goto-induced control flow, macro obfuscation, setjmp/longjmp, Duff's device pattern, lambda recursion

- [ ] **Step 2: Merge all new bad patterns into badPatterns.js**
  - From Task 2 AST analysis: empty loop bodies, ternary-as-control-flow, short-circuit-gate, fallthrough-without-comment

- [ ] **Step 3: Merge extended integrity checks**
  - From Task 1: printf/putchar hardcoding, ostringstream bypass, return-value cheating, exit-code evasion

- [ ] **Step 4: Merge CDS guards**
  - From Task 3: empty-filtered-set guard, zero-stats guard, preliminary-class parity for live CDS

- [ ] **Step 5: Run full test suite (all 43 suites)**
  - Verify all 793+ existing tests pass
  - Verify all new tests (from Tasks 1-3) pass
  - Fix any regressions

- [ ] **Step 6: Run lint and verify no warnings**

---

## Task 5: Verification Gate — Feed Edge Cases Back Through Engine

**Files:**
- Execute: `npm test` (full suite)
- Verify: no regressions, all new edge cases correctly flagged

- [ ] **Step 1: Run full test suite one final time**
- [ ] **Step 2: Verify every edge case snippet triggers expected flag**
- [ ] **Step 3: Verify edge cases that should NOT trigger flags are clean**
- [ ] **Step 4: Document final rule coverage metrics**
