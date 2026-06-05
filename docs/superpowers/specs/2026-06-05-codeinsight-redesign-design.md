# CodeInsight Redesign — Design Specification

**Date:** 2026-06-05
**Status:** Approved (Section 1 routes · Section 2 v2 tokens & components · Section 3 v3 instructor command center · Section 4 v1 student journey & integrity dashboard · Section 5 v2 section management)
**Project:** CodeInsight — Pampanga State University capstone
**Thesis:** *Behavioral Analytics-Driven Web System for Concept-Level Difficulty Detection and Early Intervention in Introductory Programming Courses*

---

## 0. North star

> **The thesis is the source of truth.** CodeInsight exists to operationalize the thesis's research contribution: detecting concept-level difficulty and triggering early intervention in introductory programming courses. Every design decision below must trace to a thesis requirement, an ISO/IEC 25010 evaluation attribute, or the seven C++ concepts (DT, VR, CD, LP, FN, AR, OP).

> **The final system should feel like a modern educational intelligence platform built around learning analytics, not merely an online coding platform.** The analytics experience is the centerpiece of the application. The code editor is necessary infrastructure, not the product.

---

## 1. Design principles (the three banners)

### 1.1 DESIGN PRINCIPLE 01 — Insight-first analytics
**Every chart answers four questions: What is happening? Why is it happening? Who needs help? What action should be taken?**

The reading order is fixed (What → Why → Who → Action). A chart that displays numbers without naming the action is a code-review rejection. Every analytics endpoint returns a `summary` field. Every chart component takes a required `insight` prop. The system never shows a CDS value without context.

### 1.2 DESIGN PRINCIPLE 02 — Learning insights language (hard rule)
**Never display CDS values without context. Every CDS visualization must explain what the score means, why it matters, and what action should be taken.**

A bare `CDS = 0.62` is not a deliverable. The canonical form is:
> `CDS: 0.62 (High Difficulty) — Students are struggling with nested loops. Average completion time increased 18%.`

The trailing clause (what + why + action) is non-optional. `InterventionCard` / insight captions are the canonical surfaces for it.

### 1.3 DESIGN PRINCIPLE 03 — Provenance & attribution
**Section management is the only place in the system that is operational rather than analytical.**

Every analytics claim — "Functions is the hardest concept this week," "7 students are at risk," "3 integrity flags are open" — implicitly depends on knowing *which roster, in which section, under which instructor, in which term*. Without a defensible answer to "who is in this section and why did they get there," every other insight in the system becomes ungrounded.

**The audit log is not a feature — it is the system's evidence that it is fair.** The `section_audit_log` table is append-only at the DB level (no `UPDATE` or `DELETE` granted to the application role).

---

## 2. The thesis-backed core

### 2.1 CDS formula
```
CDS = (0.40 × NER) + (0.35 × NRS) + (0.25 × NTS)
```
- **NER** — Normalized Error Rate
- **NRS** — Normalized Repetition Rate (re-attempts on the same exercise / concept)
- **NTS** — Normalized Time Spent

### 2.2 CDS classification
| Class | Range | Color |
|---|---|---|
| Low | 0.00 – 0.31 | `--cds-low: #22C55E` |
| Moderate | 0.31 – 0.50 | `--cds-mod: #FACC15` |
| High | 0.50 – 0.66 | `--cds-high: #EF4444` |
| No data | insufficient history | `--cds-na: #7C3AED` |

### 2.3 The seven C++ concepts
DT (Datatypes) · VR (Variables) · CD (Conditionals) · LP (Loops) · FN (Functions) · AR (Arrays) · OP (OOP)

Every exercise, submission, flag, intervention, and report is tagged with one or more of these seven concepts. The radar has seven axes — one per concept.

### 2.4 ISO/IEC 25010:2011 evaluation
Three attributes, 4-point Likert scale, target sample n=85:
1. Functional Suitability
2. Usability
3. Performance Efficiency

The instrument is built in-app. A new `evaluation_responses` table stores responses for export.

---

## 3. Tech stack (frozen)

| Layer | Choice | Notes |
|---|---|---|
| Backend | Node.js + Express | |
| DB | PostgreSQL (12 tables) | add 1 new table: `evaluation_responses` |
| Frontend | React + Vite | |
| Editor | Monaco | |
| Charts | D3.js + Chart.js | **NOT Recharts** — need SVG-level control for the heatmap & radar |
| Compilation | GCC | C++ only, v1 |
| AST | tree-sitter | C++ grammar |
| Code corpus | Project CodeNet | baseline similarity |
| Deployment | Oracle Cloud ARM VM.Standard.A1.Flex (4 cores, 24 GB RAM, 100 GB) | Ubuntu 22.04 + Nginx + PM2 + Let's Encrypt |

---

## 4. Architecture: Hub + Drill (Approach B)

CDS is the connective tissue. The headline screen is the Instructor Command Center. Every other surface is reached by drilling from it.

**Three roles, equal weight:**
- **Student** — learning journey, code editor, integrity reflection
- **Instructor** — command center, intervention, integrity queue
- **Admin** — department-level oversight, user management, sections, ISO eval

**Three epistemic modes:**
- **Insight (green / purple)** — actionable analytics, the primary mode
- **Integrity (dashed border, muted)** — separate epistemic mode, hypothesis-not-verdict framing, never the headline
- **Operational (purple chip)** — section management, roster changes, audit log

---

## 5. Route map (Section 1)

React Router v6:

```
/student
  /today
  /exercises
  /exercises/:id
  /exercises/:id/result
  /progress
  /integrity
  /sections

/instructor
  /command              ← headline (Section 3)
  /sections             ← index (Section 5A)
  /sections/:id         ← section hub, purple chip (Section 5B)
  /sections/:id/roster
  /sections/:id/join-requests
  /sections/:id/policy
  /sections/:id/tas
  /sections/:id/audit
  /heatmap
  /concepts
  /concepts/:id
  /students
  /students/:id
  /integrity            ← instructor queue (Section 4B)
  /integrity/:id
  /reports

/admin
  /
  /users
  /sections             ← department overview + CSV import (Section 5G)
  /concepts
  /exercises
  /evaluation           ← ISO/IEC 25010 instrument & export
```

**One new backend endpoint:** `GET /api/analytics/section/:id/hub` — aggregates the instructor command-center payload in a single round trip. Reduces N+1 fan-out on the headline screen.

**One new table:** `evaluation_responses` (ISO/IEC 25010 instrument storage).

**Insight-first enforcement:**
- Every analytics endpoint returns a `summary` field.
- Every chart component takes a required `insight` prop.
- CI lint rule (frontend): no `<CDSPill>` without an adjacent `<InsightText>`.

---

## 6. Design tokens (Section 2 v2)

### 6.1 Surface — Dark (default)
```
--bg-0: #0B1120   /* app canvas */
--bg-1: #0F172A   /* cards */
--bg-2: #1E293B   /* elevated */
--bg-3: #334155   /* hover */
--border: #1E293B
--text-1: #F8FAFC
--text-2: #94A3B8
--text-3: #64748B
```

### 6.2 Surface — Light (Professional, not pure white)
```
--bg-0: #F8FAFC   /* app canvas (not #FFF) */
--bg-1: #FFFFFF   /* cards */
--bg-2: #F1F5F9   /* elevated */
--bg-3: #E2E8F0   /* hover */
--border: #E2E8F0
--text-1: #0F172A
--text-2: #475569
--text-3: #94A3B8
```

### 6.3 CDS scale (semantic)
- `--cds-low: #22C55E`  — 0.00 – 0.31
- `--cds-mod: #FACC15`  — 0.31 – 0.50
- `--cds-high: #EF4444` — 0.50 – 0.66
- `--cds-na: #7C3AED`   — no data / insufficient history

### 6.4 CDS delta / trend (NEW in v2)
- `--trend-up: #22C55E`   — improving (CDS lower / mastery higher)
- `--trend-down: #EF4444` — worsening
- `--trend-flat: #94A3B8` — no change

Format: `0.62 ▲ +0.08` · used in TimelineRail, InterventionCard, ConceptRow, command hub KPI deltas.

### 6.5 Typography
- **Inter** — UI sans (Variable, 14–16px body)
- **JetBrains Mono** — code, KPIs, codes, IDs

### 6.6 Visual direction: Dark-first IDE-adjacent
Maximum information per pixel. Mono accents. Dense heatmaps. Terminal-adjacent. Feels like a developer's analytics tool — close to Monaco, GitHub Insights, or JetBrains. Students see a code editor anyway, so this is on-brand.

---

## 7. Component library (Section 2 v2)

**15 atoms** (unchanged from v1): Button, Input, Select, Checkbox, Radio, Switch, Badge, Tag, Tooltip, Avatar (initials, no photos), Spinner, Skeleton, Toast, Modal, Drawer.

**12 molecules** (3 new, 1 expanded):

| Molecule | Status | Notes |
|---|---|---|
| `CDSPill` | existing | small color-coded score with classification label |
| `CDSPillDelta` | **NEW** | CDSPill + Δ arrow + value, color = trend. Default in analytics contexts. |
| `CDSGauge` | existing | radial gauge for student detail / command hub |
| `RiskBadge` | **NEW** | 4-tier: Low / Medium / High / Critical. One badge per student per view, color = highest severity. |
| `InsightCard` | existing (expanded) | requires `insight` prop; shows summary + chart + drill |
| `CdsHeatmap` | existing | D3 SVG, students × concepts, row+col click → drill |
| `ConceptRow` | existing | one concept in `/concepts` list |
| `ConceptMasteryRadar` | **NEW** | 7-axis radar, student view ("My Programming Skills") and instructor view ("Class Concept Profile") |
| `FlagEvidence` | existing | integrity review card |
| `InterventionCard` | **NEW** | 4-slot layout: Student · Problem · Evidence · Suggested Action. Only component allowed to call a primary action on a student. |
| `TimelineRail` | existing | vertical student submission history with CDSPillDelta markers |
| `ExerciseCard` | existing | student-facing: difficulty estimate, concepts, starter |

### 7.1 RiskBadge 4-tier

| Tier | Trigger | Color |
|---|---|---|
| Low | CDS ≤ 0.31, no flags | `#22C55E` |
| Medium | CDS 0.31–0.50 OR 1 flag | `#FACC15` |
| High | CDS 0.50–0.66 OR 2 flags | `#FB923C` |
| Critical | CDS > 0.66 OR ≥ 3 flags | `#EF4444` |

### 7.2 InterventionCard
**The thesis's research contribution, made visible.** 4-slot layout:
- **Student** — name + identifier
- **Problem** — concept, CDS, trend (`CDS 0.71 (High) ▲ +0.12 this week`)
- **Evidence** — failed attempts, time vs class avg, behavioral signals
- **Suggested Action** — concrete next step, primary CTA executes it

The primary CTA is reserved for this component. Everywhere else, "Suggested:" is text-only.

### 7.3 ConceptMasteryRadar
7-axis radar (one per C++ concept: DT, VR, CD, LP, FN, AR, OP).
- **Student view** — "My Programming Skills", shaded = current mastery, inner ring = class avg. Lowest-scoring axis highlighted.
- **Instructor view** — "Class Concept Profile", shaded = class avg. Hardest axis highlighted.

### 7.4 Insight-first, restated
- `<InsightCard insight={...} chart={...} drillTo={...} />` is the canonical analytics pattern. Reading order: Insight (1 sentence, what/why/action) → Chart (evidence) → Drill (next question).
- `CDSPill` now ships as `CDSPillDelta` by default in analytics contexts. Bare `CDSPill` is allowed only in dense tables where trend is the same column for every row.
- `RiskBadge` consolidates the "needs help" signal that was previously split across CDS classification + flag count.
- `InterventionCard` is the only component allowed to call a primary action on a student.
- Empty states always have a "what should I do?" CTA, never just "No data."

---

## 8. Instructor Command Center (Section 3 v3)

**Route:** `/instructor/command`
**Headline screen.** The CDS lens, applied to the entire instructor's teaching load. Reading order is fixed: What → Why → Who → Action.

### 8.1 Layout (top to bottom)

**Row 0 — Weekly Teaching Insight**
- One rule-of-the-week generated from a small library of templates (e.g., "Functions is the hardest concept this week, with 14 of 47 students in High").
- Rule citation: "Rule: concept-difficulty-rising | n=47 | Wilson 95% CI half-width = 0.08".
- Action affordance: "View question template →".
- Progressive disclosure: full template list collapsed by default; this week = expanded.

**Row 1 — 4 insight cards (progressive disclosure)**
Each card answers one of the four questions, in fixed order. The card body is the *answer* (1 sentence). The chart is *evidence*. The drill is the *next question*.

- What: "Functions is the hardest concept this week. Class CDS 0.62."
- Why: "12 of those 14 students fail on the same test case — pass-by-reference is the dominant misconception."
- Who: "7 students on the at-risk roster. 3 moved Low → High in the last 7 days."
- Action: "Assign Function-Args-Warmup to BSIT-1A before Wednesday's class. 12 students covered."

**Row 2 — KPI strip with 6-week trend**
- Class avg CDS (with CDSPillDelta vs prior 6 weeks)
- Submissions per week (with sparkline)
- At-risk count (with trend)
- Integrity flags open (with trend, dashed)
- Active sections (with new-this-week count)
- Mastery rate (with trend)

Each KPI is a tile with: label · current value · trend arrow · mini sparkline (last 6 weeks).

**Row 3 — 7-concept sortable bars + at-risk roster**
- Two-column layout.
- Left: 7-concept bars (DT, VR, CD, LP, FN, AR, OP) sorted by current CDS desc. Each row: concept code · CDS pill · Δ vs last week · at-risk count. Sortable.
- Right: at-risk roster. Each row: avatar · name · RiskBadge · dominant struggling concept · signal buttons (e.g., "View submission", "Assign warmup", "Message", "Schedule 1:1").

**Row 4 — Learning signals (interpreted) + Intervention queue**
- Two-column layout.
- Left: Learning signals as interpreted bullets, NOT raw counts. "3 students repeated the same Ex-3 attempt 4+ times this week." Each signal is a sentence, not a number.
- Right: Intervention queue — top 5 InterventionCards (Student · Problem · Evidence · Action), ordered by severity.

**Row 5 — Integrity monitoring**
- Dashed border, muted background. Collapsed by default.
- Headline: "3 integrity flags open across 2 sections. [Review queue →]"
- Separate epistemic mode: this is hypothesis, not verdict. The visual treatment enforces it.

### 8.2 Page-level confidence badge
At the top of the page:
> **Confidence: High** (n=312 submissions · 18 days · Wilson 95% CI half-width ≤ 0.10)

### 8.3 Empty / early-term states
- **Week 1 (no data):** Low confidence badge. "Awaiting data. CDS needs at least 3 exercises per student."
- **Mid-term, all clear:** Show the all-clear state explicitly. "No concept above Moderate this week. Mastery rate 78%."
- **Low-N class (n<10):** "Insights disabled for this section — too few students for stable CIs. See raw roster."

### 8.4 Wilson score CI threshold
Insights are gated by Wilson 95% CI half-width ≤ 0.10. Anchoring rule: **High** confidence requires n ≥ 10 AND ≥ 14 days of data AND Wilson CI half-width ≤ 0.10. Lower confidence is shown explicitly, never silently.

### 8.5 K-tier ImpactTag reporting
- K ≥ 5 points + 80% CI: render full ImpactTag with effect-size estimate.
- K = 2–4: widened range, label "directional".
- K < 2: render "—", never a number.

### 8.6 Pattern vs Why Now
Insight cards describe the **observable pattern**, not causal inference. The card reads "12 of 14 students fail the same test case — pass-by-reference misconception dominates," not "Because students didn't study pass-by-reference." Pattern is observation; cause is for the office hour.

### 8.7 "Why am I seeing this?" affordance
Every insight card, every InterventionCard, every signal row, every flag has a "Why am I seeing this?" link that opens a modal explaining the rule, the data inputs, the confidence, and the threshold. This is the trust engine.

---

## 9. Student learning journey (Section 4 v1)

**Routes:** `/student/today` · `/student/progress` · `/student/recommendations`

### 9.1 Anti-patterns avoided
The student surface must never:
- Compare a student to other students by name
- Show raw class rank ("you are #14 of 47")
- Frame difficulty as personal failing
- Create a grade-shame loop ("you are behind N students")
- Surface raw behavioral counts from the integrity system

The student sees **interpreted signals about their own learning**, not behavioral telemetry.

### 9.2 `/student/today` — Today's plan
Reading order: 4 questions restated for the student.
- **What** — "Today: Ex-4 on Functions (estimated 15–20 min)."
- **Why** — "Functions is currently your highest-CDS concept at 0.62. Working on it now will have the biggest effect on your week."
- **Who** — "You, in BSIT-1A. Class avg on this concept: 0.38."
- **Action** — Start Ex-4 button + 2 next-move cards (warmup, related concept).

Below: 7-concept mastery bars (the student's own CDS, sorted descending). Brief signals-as-pedagogy (only 2 of 4 signals, all interpreted, no raw counts).

### 9.3 `/student/progress` — Trends
- **CDS over time** — solid green line = student. Dashed purple line = class average, **faded, explicitly labeled "not a rank."** The student's curve is the protagonist.
- **Per-concept 6-week trend** — list of 7 concepts with sparklines. Each row: concept code · current CDS · Δ vs 6 weeks ago · trend arrow.
- **Mastered concepts** — count + small badge cluster. Plain language: "You've shown consistent mastery on Datatypes and Conditionals this term."

### 9.4 `/student/recommendations` — Next moves
- 3 prioritized cards: **priority** (1) · **optional** (1) · **stretch** (1).
- Each card has: Pattern (what's observed) · Confidence badge · "Why am I seeing this?" link.
- No deadlines, no "you must complete by" framing.

### 9.5 `/student/integrity` — Reflective surface
See Section 10.

---

## 10. Integrity Dashboard (Section 4 v1)

**Routes:** `/instructor/integrity` · `/instructor/integrity/:id` · `/student/integrity`

### 10.1 Three epistemic commitments
1. **A flag is a hypothesis, not a verdict.** The system surfaces patterns the instructor should investigate. The system does not conclude.
2. **Pattern, not accusation.** The wording is observational ("z-score +2.1σ on code growth"), not moralizing ("cheating suspected").
3. **Student transparency.** The student sees the same flag, in plain language, with 3 affordances: request 1:1, appeal, read full rule.

### 10.2 `/instructor/integrity` — Flag queue
For each flag:
- Rule name (e.g., "behavioral_anomaly · code_growth_spike")
- "Why am I seeing this?" link → rule modal
- Evidence: z-score, code growth ratio, paste sequence, literal match span
- Confidence badge (Wilson 95% CI)
- Pattern observation (one sentence)
- Instructor actions: Mark reviewed · Request 1:1 · Refer to registrar · Dismiss (with reason)

### 10.3 `/instructor/integrity/:id` — Single flag
Full evidence chain. Code diff viewer. Timeline of signals leading to the flag. Comparison to class baseline. Confidence breakdown. Suggested next action.

### 10.4 `/student/integrity` — Reflected back
The same flag, in plain language, with:
- "Why am I seeing this?" link
- Three affordances: Request 1:1 · Appeal · Read full rule
- No behavioral telemetry, no class comparison
- The student sees the rule that flagged them, the evidence in plain language ("your code grew faster than 95% of the class in this session"), and the path to resolution.

### 10.5 Privacy boundary (hard)
> **The student sees interpreted signals about their own learning. The instructor sees behavioral telemetry for the class. Raw behavioral counts are not surfaced to students.**

This is enforced at the API layer. The student's `/integrity` endpoint returns different fields than the instructor's.

---

## 11. Section Management (Section 5 v2)

**The provenance layer for everything else.**

### 11.1 Three actors & their jobs

| Actor | Powers |
|---|---|
| **Instructor** | Create / archive their sections · Generate & rotate join codes · Approve or decline join requests · Drop students (with audit trail) · Assign roles (TA / co-instructor) · See the section landing hub |
| **Student** | Join via 6-character code · Request to join (if code-protected) · See which sections they're in · Request to leave (requires instructor acknowledgment) · **Never** see another section's roster |
| **Admin** | See *all* sections in the department · Assign / re-assign instructors to sections · Archive sections · Bulk-import sections from CSV at semester start · Department-wide audit log export |

### 11.2 v1 cut list (defensibility discipline)

| Cut | Why |
|---|---|
| **Merge / split sections** | Deferred to post-thesis. The data-model questions (which CDS pool wins, do flags carry over, what happens to the loser's audit log) are not worth answering in v1. |
| **Waitlist** | Deferred to v2. Capacity is a hard "Section is full" message. |
| **Co-instructor / TA screens** | Represented in the data model and the audit log, but the management UI is a thin tab inside the section hub. |
| **`open` join policy** | Removed in v2. "Anyone with the link can join" in a grade-bearing academic system contradicts the audit-log thesis. |
| **`pending_approval` section status** | Removed in v2. Sections are `active` or `archived`. |

### 11.3 Join policy (REVISED in v2)

Three policies. `open` is killed in v1.

| Policy | Behavior | Color |
|---|---|---|
| `code` (default) | Students need the 6-character code shared by the instructor. Anyone with the code can join. The audit log records who joined, when, and which code they used. | green |
| `request` | Students submit a one-paragraph note; instructor approves or declines. Both outcomes are audited. Used when the instructor wants to gate enrollment (e.g., a section capped by equipment). | yellow |
| `closed` | No new joins. Used during finals week or after the add/drop deadline. Existing members retain access. To re-open, the instructor flips the policy back to `code` or `request`. | red |

**Why no `open` policy:** "Anyone with the link can join" in a grade-bearing academic system is a footgun. It contradicts the audit-log thesis — you can't defend "who is in this section and why" if the answer is "whoever clicked a link." If a use case for open enrollment surfaces, the right answer is an auth-gated variant: "anyone with a valid `@psu.edu.ph` account can join," which is auditable. v1 ships with only the three policies above.

### 11.4 Leave vs Drop (REVISED in v2 — asymmetric, registrar-style)

| Operation | Instructor ("drop") | Student ("leave") |
|---|---|---|
| Actor | Instructor clicks "Drop" on a roster row | Student clicks "Request to leave" |
| Reason required? | **Yes** — short note (e.g., "transferred to BSIT-1B per registrar") | **Yes** — short note (e.g., "schedule conflict") |
| Effective when? | Immediately (or scheduled end-of-term) | **Pending instructor acknowledgment** (default 7-day grace) |
| What happens to data? | Submissions, CDS, flags preserved (soft delete) | Same — soft delete, restoreable |
| Audit log entry | `student_dropped` with reason | `student_leave_requested` → `student_left` (when acked) |

**Why "leave" requires instructor acknowledgment in v2:** In most real programs, students cannot unilaterally leave a section mid-term — the registrar controls enrollment. Allowing it would let a student dodge a bad grade by leaving before a flagged submission is reviewed. The 7-day grace is the default; instructors can shorten it (e.g., to 1 day) for late-term requests or lengthen it.

**The instructor can also decline a leave request** — the student is notified, the audit log records the decline reason, and the student's status reverts to `active`.

### 11.5 Data model

```
sections
  id (uuid)
  code          text  -- 6-char join code, e.g. "K7P-3QX"  (rotates on instructor demand)
  name          text  -- "BSIT-1A · Morning"
  term          text  -- "2026-1"
  instructor_id uuid  -- primary instructor
  status        enum  -- 'active' | 'archived'   (v1; 'pending_approval' dropped)
  join_policy   enum  -- 'code' | 'request' | 'closed'  (v2; 'open' removed)
  max_size      int   -- hard cap, default 60. No waitlist in v1.
  created_at    timestamptz

section_memberships
  id (uuid)
  section_id    uuid
  user_id       uuid
  role          enum  -- 'student' | 'ta' | 'co_instructor'
  status        enum  -- 'active' | 'pending' | 'denied' | 'dropped' | 'left_requested' | 'left'
  joined_at     timestamptz
  dropped_at    timestamptz  -- soft delete for audit
  drop_reason   text         -- required for drops and leaves; short free-text
  unique(section_id, user_id)  -- one membership row per (section, user)

section_audit_log
  id (uuid)
  section_id    uuid
  actor_id      uuid
  action        text  -- see enumeration below
  meta          jsonb -- who/what/when/why
  created_at    timestamptz
```

### 11.6 Endpoints

| Verb | Path | Purpose |
|---|---|---|
| `POST` | `/sections` | Create section |
| `POST` | `/sections/:id/rotate-code` | Rotate join code |
| `POST` | `/sections/join` | Student joins via code |
| `POST` | `/sections/:id/memberships` | Instructor adds a member |
| `PATCH` | `/sections/:id/memberships/:mid` | Drop, leave-request, leave-ack, leave-decline, restore |
| `POST` | `/sections/bulk-import` | Admin CSV (all-or-nothing) |
| `GET` | `/sections/:id/audit` | Section audit log |
| `GET` | `/sections/audit?term=...` | Admin: department-wide audit |

**Every mutating action writes to `section_audit_log`.** The audit log table is append-only at the DB level (no `UPDATE` or `DELETE` granted to the application role).

### 11.7 Audit action enumeration (final — 17 actions)

`section_created` · `code_rotated` · `student_joined` (via code, also fired per-row on bulk import) · `student_requested_to_join` · `student_join_approved` · `student_join_denied` · `student_dropped` · `student_leave_requested` · `student_leave_acknowledged` · `student_leave_declined` · `instructor_assigned` · `instructor_reassigned` · `ta_added` · `ta_removed` · `policy_changed` · `section_archived` · `bulk_import_run` (a grouping row written once per import, with `meta` containing the row count and CSV filename; the per-section `section_created` + `instructor_assigned` rows are the audit entries for the import itself).

### 11.8 Concurrency & race conditions (stated policies)

| Scenario | Policy |
|---|---|
| Two students race-join with the same code at the same time | Both succeed if the section is below `max_size`. Each gets a distinct `section_memberships.id`; the `unique(section_id, user_id)` constraint prevents the same user from getting two rows. The audit log records both inserts. |
| Instructor A and Instructor B both try to add the same student | **Last-writer-wins on add**, but the audit log captures both attempts. The losing attempt is not a no-op — it writes a `student_added` row with the actor's id and the section's id, so the trail is intact. |
| Instructor rotates the code while a student is mid-typing | The student's submit fails with "Code changed — try again with the new one from your instructor." No data is created. The audit log records the rotation but not the failed attempt. |
| Section is at `max_size`; two students race-join | Atomic check + insert via `SELECT ... FOR UPDATE` on the section row. The first wins; the second sees the post-increment count and is rejected with "Section is full." |
| Bulk CSV import is interrupted mid-write | Wrapped in a single transaction. If any row fails, the whole import rolls back. Partial imports are impossible. |

**Defense-ready phrasing:** "The section lifecycle is governed by an append-only audit log and a `unique(section_id, user_id)` constraint on the membership table. Race conditions on capacity are resolved by a `SELECT ... FOR UPDATE` on the section row inside the join transaction. Last-writer-wins on duplicate adds is a chosen policy, not an oversight: the audit log preserves the trace."

### 11.9 Screens

#### A — `/instructor/sections` (the index)
3 active section cards + 1 "+ New section" card. Each card: name · term · code (mono) · policy · 3 KPIs (students / avg CDS / at risk) · top-line insight ("Functions is the hardest concept this week · 3 flags open") · 3 buttons (Open hub, Roster, Code).

#### B — `/instructor/sections/:id` (the section hub)
- **Purple chip** at the top to differentiate visually from the green Command Center band. Breadcrumb: `/instructor/sections › BSIT-1A › Morning · code K7P-3QX · 47 / 60 students`.
- **Section-hub banner:** "This page is the section's provenance: who is in it, how they got here, what's happening to them."
- **Join code card** — code, Copy / Rotate / QR buttons.
- **Tabs:** Hub · Roster (47) · Join requests (3) · Codes & policy · TAs (1) · Audit log.
- **Section summary** (4 questions, scoped to this section): What / Why / Who / Action.
- **3 mini command cards:** Concept Ranking · Recent Membership Activity · Policy & Limits.

#### C — `/student/sections`
- List of sections the student is in, with status badge (active / pending / leave req).
- "Join another section" card with 6-character code input.
- "Code not working?" troubleshooting.

#### D — Roster tab
- Search by name · filter (All / At risk / Pending / Leave requested / Dropped this term) · sort.
- 6-column grid: avatar · student · joined · status · risk · actions.
- New row type: **leave req** (purple), with Acknowledge / Decline affordances.
- **Drop modal** — required reason textarea, written to the audit log.
- **Acknowledge leave modal** — optional note to student, decline path available.

#### E — Codes & policy tab
- Join policy (3 options, `open` not offered).
- Capacity (no waitlist toggle in v1).
- Code history — all codes ever issued, with rotation date and use count.

#### F — Audit log tab
- 4 columns: WHEN · WHAT · WHO · WHY.
- Append-only. Exportable as CSV.
- Defense artifact banner: "every row below is the system's evidence that a roster change was intentional and traceable."

#### G — `/admin/sections`
- Department overview table.
- Bulk CSV import with **all-or-nothing** validation:
  - Duplicate `(section_name, term)` → row rejected, import fails.
  - Bad instructor email → row rejected, import fails.
  - Invalid `join_policy` / `max_size` → row rejected, import fails.
  - Empty file / header-only / missing columns → import fails with a clear message, not a stack trace.
  - On any failure: whole import rolled back; CSV is returned with line numbers and reasons annotated.
  - On success: each new section writes a `section_created` + `instructor_assigned` row in `section_audit_log` with actor = the admin who ran the import. A `bulk_import_run` row groups them.
- Re-assign instructor, archive section, export department-wide audit log.

### 11.10 Edge cases (v2 — reduced)

| Case | Behavior |
|---|---|
| Student tries a code for an archived section | "This section is no longer active. Ask your instructor." |
| Section is at `max_size` | Hard "Section is full." No waitlist in v1. |
| Student joins a section they're already in | Idempotent: "You're already in this section." |
| Instructor rotates code while a student is mid-typing | Submit fails gracefully; UI says "Code changed — try again with the new one." |
| A student is dropped mid-term | Submissions, CDS, flags preserved. Re-add is one click, no data loss. Drop reason is required and shown to the student. |
| Student requests to leave | Status `left_requested`. Instructor must acknowledge (default 7-day grace). Decline reverts to `active`; both outcomes are audited. |
| Instructor declines a leave request | Student notified, audit log records decline reason, status reverts to `active`. |
| Two students race-join with the same code | Both succeed if below cap; audit log captures both. Above cap, `SELECT ... FOR UPDATE` serializes. |
| Bulk CSV import hits an invalid row | All-or-nothing rollback. The annotated CSV is returned; no partial import is possible. |
| Instructor tries to use the `open` policy (no longer in enum) | UI doesn't offer it. DB enum doesn't accept it. Defense artifact: "We deliberately removed `open` in v2 to keep the audit log defensible." |
| Merge / split requested | "Not supported in v1. Open a department-level ticket." (Defense: "deferred to v2; the data-model questions are non-trivial.") |

### 11.11 Why this is the provenance layer (not just roster management)

- **Entry point of the system.** Before analytics can run, students must be in a section. The join flow is the first thing a real user touches.
- **Every analytics claim depends on it.** "Functions is the hardest concept this week" is a section-scoped claim. "7 students are at risk" is a roster-scoped claim. "3 integrity flags are open" is a roster-scoped claim. None of them exist without the provenance this section provides.
- **Three actors share one mental model, with asymmetric powers.** Instructor creates → student joins → admin oversees. The screens above are the same model, three lenses. Drop is instructor-initiated, leave is student-initiated and instructor-acknowledged — the asymmetry is the registrar pattern, not a UX whim.
- **It is the only place where the system is operational rather than analytical.** Every other screen assumes the section already exists, the roster is already set, and the audit log is already trustworthy. **This section is where those assumptions are made defensible.**
- **The audit log is the system's evidence that it is fair.** The append-only constraint is the answer to "how do you prevent the instructor from quietly removing a flagged student?" The `drop_reason` field is the answer to "why was this student removed?" The `bulk_import_run` row is the answer to "who created the roster and when?" Each design decision in this section is a defense decision.

---

## 12. API endpoints (additions for the redesign)

| Verb | Path | Purpose |
|---|---|---|
| `GET` | `/api/analytics/section/:id/hub` | Aggregated Command Center payload (one round trip) |
| `POST` | `/api/sections` | Create section |
| `POST` | `/api/sections/:id/rotate-code` | Rotate join code |
| `POST` | `/api/sections/join` | Student joins via code |
| `POST` | `/api/sections/:id/memberships` | Instructor adds a member |
| `PATCH` | `/api/sections/:id/memberships/:mid` | Drop / leave / ack / decline / restore |
| `POST` | `/api/sections/bulk-import` | Admin CSV (all-or-nothing) |
| `GET` | `/api/sections/:id/audit` | Section audit log |
| `GET` | `/api/sections/audit` | Admin: department-wide audit |
| `POST` | `/api/evaluation/responses` | ISO/IEC 25010 instrument submission |
| `GET` | `/api/evaluation/export` | Admin: CSV export for analysis |

All existing 50+ endpoints remain. No endpoint is removed. The redesign is additive at the API layer.

---

## 13. Database changes (additive only)

| Change | Type | Notes |
|---|---|---|
| `evaluation_responses` | new table | ISO/IEC 25010 instrument storage |
| `sections` | already exists | add / modify columns: `code`, `name`, `term`, `instructor_id`, `status` (remove `pending_approval`), `join_policy` (remove `open`), `max_size`, `created_at` |
| `section_memberships` | new table | soft delete, drop reason, status enum |
| `section_audit_log` | new table | append-only at DB level, 17-action enum |
| All other tables | unchanged | `users`, `exercises`, `submissions`, `concept_mastery`, `cds_scores`, `integrity_flags`, `micro_concepts`, etc. |

The migration is **additive**. No existing data is touched. The redesign can ship behind a feature flag.

---

## 14. ISO/IEC 25010 instrument (in-app)

Built into `/admin/evaluation`. The admin shares a link with respondents; they complete the 4-point Likert instrument; responses land in `evaluation_responses`; the admin exports a CSV for thesis-chapter analysis.

Three attributes:
1. **Functional Suitability** — does the system do what the thesis claims it does?
2. **Usability** — can instructors and students use it without training?
3. **Performance Efficiency** — does it respond in time to be useful?

Target sample: n=85 (per thesis Chapter 3). The instrument itself is a screen in the admin surface, not a separate Google Form.

---

## 15. Open questions / future work (post-thesis)

| Item | Reason deferred |
|---|---|
| Section merge / split | Non-trivial data-model questions (CDS pool, flag carryover, audit log destiny) |
| Waitlist | v2 |
| `open` join policy | Contradicts audit-log thesis |
| Co-instructor / TA management UI | Tab inside section hub for v1 |
| Real-time websocket on Command Center | Batch refresh acceptable for thesis defense |
| Native mobile apps | Web responsive for v1 |
| Per-concept intervention templates library | Bootstrap with 5, expand post-defense |

---

## 16. What this spec deliberately does NOT do

- Does not add a new CDS formula. The thesis formula is locked.
- Does not change the seven C++ concepts. The thesis taxonomy is locked.
- Does not introduce a new chart library. D3 + Chart.js. **No Recharts.**
- Does not introduce a new backend framework. Express + Node.
- Does not change the DB engine. PostgreSQL.
- Does not introduce a new deployment target. Oracle Cloud ARM.
- Does not remove any existing API endpoint. Additive only.
- Does not redesign the code editor. Monaco, as shipped.
- Does not introduce a new auth provider. Existing email-based auth remains.
- Does not add real-time websocket in v1. Polling / batch refresh only.

---

## 17. Acceptance criteria

The redesign is "done enough to defend" when:
- [ ] All routes in Section 5 are reachable and render the specified screens.
- [ ] `GET /api/analytics/section/:id/hub` returns the 5-row command-center payload in a single round trip.
- [ ] Every analytics endpoint returns a `summary` field; every chart component requires an `insight` prop.
- [ ] The 12-molecule component library is in place, with `RiskBadge`, `InterventionCard`, `ConceptMasteryRadar`, `CDSPillDelta` shipped.
- [ ] Section management is fully wired: 6-character codes, 3 policies (no `open`), `request` flow, `closed` flow, leave-request + acknowledge, drop with required reason, audit log append-only at DB level.
- [ ] The CSV bulk import is all-or-nothing with annotated error CSV.
- [ ] The integrity dashboard reflects the same flag to student and instructor with the privacy boundary enforced at the API layer.
- [ ] The ISO/IEC 25010 instrument is reachable at `/admin/evaluation` and exports to CSV.
- [ ] The existing 50+ endpoints remain functional; no regression in 16/16 unit tests and 71/71 backend API tests.
- [ ] The defense script (Section 16 "deliberately does not do" + the audit-log framing) is rehearsed.

---

**End of spec. Next steps per brainstorming flow: self-review → user review → invoke writing-plans skill.**
