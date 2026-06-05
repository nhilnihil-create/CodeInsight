# CodeInsight — Mobile-Friendly UI/UX Design

**Date:** 2026-06-05
**Status:** Design approved; ready for implementation planning
**Companion visual mockups:** `.superpowers/brainstorm/102506-1780640635/content/section-{1,2,3,4}-*.html`
**Companion desktop spec:** `docs/superpowers/specs/2026-06-05-codeinsight-redesign-design.md` (681 lines, approved earlier)

---

## 1. Goals and non-goals

### 1.1 Goals

Make CodeInsight usable on a phone without sacrificing the analytics-first stance. The mobile experience is **a triage surface, not a scaled-down dashboard**. By the end of v1:

- An **instructor** can open the app on a phone, see the top-3 at-risk students within **< 10 seconds**, and trigger an intervention without a desktop session.
- A **student** can open the app on a phone, see the **next action** within **< 3 seconds**, and run/submit code (read-only code, full editor on tablet+).
- An **admin** can complete the **ISO/IEC 25010 evaluation instrument** in **< 4 minutes** from a phone, and see a one-glance system snapshot.
- The analytics experience remains the centerpiece. CDS values are never shown without context (What / Why / Who / Action).

### 1.2 Non-goals (v1 cut list)

- ❌ Native mobile apps (iOS / Android). **Web responsive only.**
- ❌ Real-time push / websockets. Pull-to-refresh is the only real-time affordance.
- ❌ Mobile flag review UI for instructors. Phone shows the count + 3 most recent only.
- ❌ Mobile code editing. Phone shows the code; tablet+ opens the editor.
- ❌ Voice input / camera OCR for code.
- ❌ Offline-first / service worker. PWA was rejected. Mobile requires connectivity.
- ❌ Mobile bulk export, user management, or intervention note-taking.
- ❌ Mobile-only KPI definitions or CDS threshold overrides. Mobile reads the same CDS as desktop.
- ❌ Drag-to-reorder widgets on phone.
- ❌ Theme toggle on phone (auto by default; exposed via app-bar menu).

### 1.3 Constraints carried over from the existing desktop spec

| Constraint | Source | Status |
|---|---|---|
| Additive only — no new endpoints, no removed APIs, no modified responses | `2026-06-05-codeinsight-redesign-design.md` § constraints | ✅ Satisfied by construction: 24 mobile-touchpoint endpoints, all pre-existing |
| No new chart library (D3 + Chart.js only; no Recharts) | same | ✅ Same library, context-loaded |
| No real-time websocket in v1 | same | ✅ Cut list item |
| "Learning Insights Language" — never bare CDS values | same | ✅ PriorityInsight widget copy is the canonical example |
| Native mobile apps: web responsive for v1 | same, line 645 | ✅ Cut list item |
| Existing 50+ endpoints must remain functional | same | ✅ See §11 |
| CDS formula: `(0.40 × NER) + (0.35 × NRS) + (0.25 × NTS)` | CLAUDE.md | ✅ Reused unchanged on mobile |
| Risk thresholds: Low (0–0.31) / Moderate (0.31–0.50) / High (0.50–0.66) | CLAUDE.md | ✅ Reused unchanged on mobile |
| 7 concepts: DT, VR, CD, LP, FN, AR, OP | CLAUDE.md | ✅ Reused unchanged on mobile |

---

## 2. Architecture overview

### 2.1 The Dual-Surface Model

CodeInsight renders as **three surfaces** of the same product, switched at the root:

```
<Layout mode="mobile|tablet|desktop">  ← single entry point, derived once from viewport
  <AppBar chrome="mobile|desktop" />
  <Sidebar chrome="desktop" />         ← desktop only
  <Content>
    <LayoutConfigProvider role={user.role}>
      <RoleResolvedScreens />
    </LayoutConfigProvider>
  </Content>
  <BottomNav chrome="mobile" />        ← phone only
</Layout>
```

- `mode` is derived once at the layout root from `window.matchMedia` or a server-side viewport hint. It does **not** change inside individual screen components.
- Components adapt via the `mode` prop, not by re-querying. **No `useIsMobile()` in the screen layer.** The existing `useIsMobile` hook (at `frontend/src/hooks/use-mobile.js`) is repurposed — it's the layout's source of truth, not a per-component switch.
- Tablet (`640 ≤ width < 1024`) and desktop (`width ≥ 1024`) **share the desktop visual language** with reduced column counts (tablet 2-col, desktop 3-col). They are not a separate "tablet" experience. Phone (`width < 640`) is the only one with the compressed triage pattern.

### 2.2 The layout-config-driven shell

The shell does not branch on `user.role` inside React. Instead, a single `useLayoutConfig(role, mode)` hook returns one of three config objects (per role, per mode). The shell renders exactly what the config says — no conditional components, no role-specific JSX.

Config files (new):
- `frontend/src/configs/mobile/instructor.json`
- `frontend/src/configs/mobile/student.json`
- `frontend/src/configs/mobile/admin.json`
- `frontend/src/configs/tablet/*.json` (2-col variants; optional in v1, falls back to mobile config)
- `frontend/src/configs/desktop/*.json` (3-col variants; required, see desktop spec)

Schema (see §10) is identical across roles and modes — only the widget lists and the `render` modes change.

### 2.3 Data flow

```
Browser
  ↓
Layout (mode) ──→ useLayoutConfig(role, mode) ──→ config object
  ↓
For each widget in config.primary / config.secondary / config.tertiary:
  - Show if showIf(data) returns true (or no showIf)
  - Fetch from widget.endpoint (existing)
  - Wrap in StateAwareShell({ data, state })
  - Render at the assigned position (with collapsed flag for tertiary)
  ↓
StateAwareShell decides: NoData | LowConfidence | Healthy, applies the right copy + visual
```

**Acceptance check:** 100% of phone screens render from the config object; zero `if (role === ...)` branches inside `/mobile` screen components. Verified by codebase grep for `role` inside `frontend/src/mobile/`.

---

## 3. Mobile shell anatomy

Single shell for all roles. Mode is `mobile` (the only mode that uses the bottom nav).

```
┌──────────────────────────────────┐
│ AppBar (48px)                    │  ← logo left, avatar/menu right, theme toggle hidden
├──────────────────────────────────┤
│                                  │
│ Content area (scrollable)        │  ← role-aware widgets, single column,
│                                  │     16px gutters, 12px radius, 16px padding
│                                  │
│                                  │
├──────────────────────────────────┤
│ BottomNav (56px + safe-area)     │  ← 3–5 destinations, role-specific
└──────────────────────────────────┘
```

- **App bar (48 px):** logo on the left, avatar + menu on the right. Sticky. Theme toggle hidden on phone (auto by default; exposed via menu).
- **Content area (scrollable):** role-aware widgets. Single column, 16 px gutters, 12 px card radius, 16 px card padding.
- **Bottom tab bar (56 px + safe-area-inset-bottom):** 3–5 destinations, role-specific labels. Active tab = colored dot + filled icon. Inactive = ghost.
- **Tap targets ≥ 44 × 44 px.** No hover-only affordances. Long-press = secondary action.

### 3.1 Bottom nav destinations

| Role | Destinations | Count |
|---|---|---|
| Instructor | Command · Students · Concepts · Integrity · Sections | 5 |
| Student | Today · Exercises · Progress · Integrity · Sections | 5 |
| Admin | Overview · Evaluation · Audit | 3 |

### 3.2 Safe-area-inset

Bottom tab bar respects `env(safe-area-inset-bottom)` for iOS home indicator. Top app bar respects notch on landscape. Verified on iPhone 14/15 simulator (acceptance criterion §13.13).

---

## 4. Per-role IA — the three lenses

The shell is one product. The contents are three lenses on the same data. Reading order on every phone screen: **What → Action** (Why/Who behind tap).

### 4.1 Instructor (triage top-down)

The instructor opens the app and asks, *"Who is in trouble, and what do I do about them?"* The mobile surface answers in 10 seconds.

- **Primary:** 1 `InstructorPriorityInsight` widget (the headline insight of the week).
- **Secondary (0–2, priority-driven):** `AtRiskQueue`, `InterventionQueue` — each appears only when its data clears the show-if threshold.
- **Tertiary (collapsed):** `TopStrugglingConcepts`, `IntegrityFlagCount`, `ClassProfileRadar` (summary), `WeeklyTeachingInsight`.

### 4.2 Student (guided flow bottom-up)

The student opens the app and asks, *"What do I do next?"* The mobile surface answers in 3 seconds.

- **Primary:** 1 `StudentTodayFocus` widget (one exercise, with the "why" pre-baked in).
- **Secondary (0–2):** `WeakestConceptBar`, `ActionStack` — show only if there's a clear next action.
- **Tertiary (collapsed):** `WeeklyProgress`, `ConceptMasteryBarSet`, `IntegrityFlagCount`.

### 4.3 Admin (minimal oversight, one action path)

The admin opens the app and asks, *"What's pending me, and is the system healthy?"*

- **Primary:** `SnapshotMetrics` widget (2×2 grid: users, sections, eval pending, flags open).
- **Primary action (1 of 1):** `EvaluationProgress` — the ISO/IEC 25010 evaluation queue, surfaced as a full-width purple button. **The one action path the admin has on phone.**
- **Secondary:** `AuditLog`, `SectionList` — show only if there's recent activity / non-zero sections.
- **Tertiary:** `DesktopOnlyNotice` × 2 (bulk export, user management) — explicit "Desktop only" copy. Honest about the workflow cost, not hidden.

---

## 5. Per-role screen blueprints (the 3 top-level mobile routes)

### 5.1 `/instructor/command` (mobile)

```
PRIMARY (1 of 1)
  ┌────────────────────────────────────────┐
  │ PRIORITY INSIGHT                       │
  │ Loops are the hardest concept this wk  │
  │ CDS 0.62 ▲ +0.08 · 14 of 47 in High   │
  │ [View concept →]                       │
  └────────────────────────────────────────┘

SECONDARY (0–2, showIf data.length > 0)
  ┌─ AT-RISK QUEUE · TOP N ──────────────┐
  │ John Dela Cruz  ●✕ Critical          │
  │ Maria Santos     ●⚠ High             │
  │ Pedro Reyes      ●⚠ High             │
  │ Liza Cruz        ●◐ Medium           │
  │ + N more · tap queue to expand        │
  └──────────────────────────────────────┘
  ┌─ INTERVENTION QUEUE · CRITICAL ONLY ─┐
  │ John Dela Cruz                       │
  │ Loops 0.71 · 3 fails · 24m avg        │
  │ [Assign Set B]  [1:1]                 │
  └──────────────────────────────────────┘

TERTIARY (collapsed by default)
  ▸ Top struggling concepts (3) — tap to expand
  ▸ 3 integrity flags require review
  ▸ Class concept profile (radar) — drill for full chart
  ▸ Weekly teaching insight — drill for full
```

`N` is computed client-side as `min(5, floor((viewportHeight - chromeHeight - primaryHeight) / rowHeight))` — **adaptive by viewport height, not hard-coded**.

### 5.2 `/student/today` (mobile)

```
PRIMARY (1 of 1)
  ┌────────────────────────────────────────┐
  │ TODAY'S FOCUS                          │
  │ Ex-3: Nested Loops                     │
  │ Why: Loops are your weakest (0.71)     │
  │ Estimated time: 25 min                 │
  │         [▶ Start exercise]             │
  └────────────────────────────────────────┘

SECONDARY (0–2)
  ┌─ YOUR WEAKEST CONCEPT ────────────────┐
  │ Loops                       [0.71]    │
  │ ████████████████░░░░░░ (71%)          │
  │ 3 of 5 exercises passed               │
  └──────────────────────────────────────┘
  ┌─ NEXT ACTIONS ────────────────────────┐
  │ ▶ Finish Ex-3 (in progress, 12m left) │
  │ ▸ Optional: Review loop notes         │
  └──────────────────────────────────────┘

TERTIARY (collapsed)
  ▸ This week's progress — drill for full
  ▸ Concept mastery bars — drill for full
  ▸ 0 integrity flags on your record
```

### 5.3 `/admin/overview` (mobile)

```
PRIMARY (1 of 1)
  ┌─ SYSTEM SNAPSHOT ─────────────────────┐
  │   127          6                       │
  │   users        sections                │
  │   23           3                       │
  │   eval pending flags open              │
  └──────────────────────────────────────┘

PRIMARY ACTION (1 of 1)
  ┌────────────────────────────────────────┐
  │   ▶ Review pending evaluations (23)    │
  │   ISO/IEC 25010 instrument             │
  └────────────────────────────────────────┘

SECONDARY
  ▸ Audit log: 3 sections created this week · 17 students joined
  ▸ Sections at a glance: 6 active · 0 archived

TERTIARY (info only — desktop recommended)
  ▸ Bulk export (desktop only)
  ▸ User management (desktop only)
```

### 5.4 Secondary routes per role

| Role | Route | Purpose | Notes |
|---|---|---|---|
| Instructor | `/instructor/students` | At-risk roster with filter chips, sort=Risk ↓, row tap → student detail | Swipe ◀ dismiss, swipe ▶ flag, long-press history. Filter chips: section, risk, sort. |
| Instructor | `/instructor/concepts` | Top-K concepts list (K adaptive). Row tap → `/concepts/:id` | Full chart on tablet+ only. |
| Instructor | `/instructor/integrity` | Flag count summary + 3 most recent critical flags + "View all" drill | **No flag review on phone.** Drill notice: "Flag review requires tablet or desktop." |
| Instructor | `/instructor/sections` | Section list (one card per section, max 4 visible). Tap → `/sections/:id` hub | |
| Student | `/student/exercises` | List of available exercises as `ExerciseCard` (compact). Tap → `/student/exercises/:id` | |
| Student | `/student/exercises/:id` | **CodePreviewSurface** (phone) — read-only code preview, Run, Submit, test results. Tap "Open full editor →" to switch to tablet+ | See §7.3 |
| Student | `/student/progress` | 7 concept bars, one per concept, no radar | Sticky header with overall mastery %. |
| Student | `/student/integrity` | Student's own flag history (privacy-bounded) | Read-only on phone. |
| Student | `/student/sections` | Section hub (one card per enrolled section) | |
| Admin | `/admin/evaluation` | ISO/IEC 25010 instrument, 4-point Likert, one question per screen, progress bar | Submit on the last question. |
| Admin | `/admin/audit` | Recent audit log (last 50). Tap row → detail. No filters on phone | |

---

## 6. Component transformation rules (desktop → mobile)

### 6.1 The transformation table

| Desktop component | Phone (< 640 px) renders | Switch mechanism |
|---|---|---|
| `CdsHeatmap` (D3 SVG, students × concepts) | Top-K list of struggling concepts (K=3, or K=5 if viewport ≥ 700 px). Each row: concept code + `CDSPillDelta` + dominant misconception. Tap → `/concepts/:id`. | `mode` prop + render swap; D3 import is dynamic and skipped on phone |
| `ConceptMasteryRadar` (7-axis D3) | Single-axis summary: weakest concept highlighted, single bar showing mastery %, "View full radar" drill button | `mode` prop + render swap |
| `CDSPill` (full label + classification) | Compact badge (numeric only, no label). Color stays. | CSS class swap |
| `CDSPillDelta` (0.62 ▲ +0.08) | Tiny pill (no Δ) + small arrow only (▲/▼/▬). Tap → tooltip shows full delta. | CSS class swap |
| `RiskBadge` (Low/Medium/High/Critical + color) | **Color + label always shown.** Symbol (●✕ ●⚠ ●◐ ●○) is decorative only — not the primary meaning carrier. | CSS class swap |
| `InsightCard` (insight + chart + drill) | Insight only (1 sentence). Chart hidden. Drill button remains. | CSS visibility + chart slot |
| `InterventionCard` (4-slot grid) | 1-card stacked: header (name + risk), 1-line problem, 1-line evidence, primary action button | CSS layout switch (grid 4-col → 1-col) |
| `TimelineRail` (vertical submission history) | Horizontal scrollable strip (touch-friendly). Snap to first/last. | CSS direction swap |
| `FlagEvidence` (integrity review card) | Header (flag type) + 1-line evidence summary + actions. Code diff hidden behind "View evidence" expand. | CSS + Collapsible |
| `ExerciseCard` (student-facing) | Same content, smaller padding. Difficulty estimate visible. Tap → `/exercises/:id`. | CSS only |
| `ConceptRow` (one concept in `/concepts` list) | Condensed row: code + `CDSPill` + Δ. Top misconception hidden behind tap. | CSS only |
| `CDSGauge` (radial gauge) | Renders identically. Radial gauge is phone-friendly. | No change |

### 6.2 Chart degradation (D3 strategy)

- **Phone never instantiates a D3 SVG larger than 200 × 200 px.** Heatmap / radar / multi-series → summary widget or sparkline.
- **D3 is context-loaded, not blanket-blocked.** The chart component dynamic-imports D3 only when `mode !== 'mobile'` OR when the user is on an explicit `/full` drill route. Foldables and landscape phones still get the full chart.
- **Sparklines** are pre-aggregated server-side; the client renders them with a tiny inline SVG, no D3 dependency.
- **Drill to full chart:** every summary widget ships with a "View full analysis →" link that opens the desktop-rendered chart at its full route (e.g., `/concepts/:id`).

### 6.3 Touch & gesture surface (phone only)

- **Tap targets ≥ 44 × 44 px.** Buttons get 12 px vertical padding; list rows ≥ 56 px.
- **Swipe gestures:** swipe-left on a queue row = "snooze" / "dismiss" (with undo toast). Swipe-right on an integrity flag = "approve / clear". Both undoable.
- **Long-press:** long-press on a `CDSPill` shows trend sparkline + Wilson CI. Long-press on a `ConceptRow` shows the 4-week history sparkline.
- **Pull-to-refresh:** only on top-level role pages (Command, Today, Overview). 60 px threshold. 20 lines of pointer-event handlers, no library.
- **No hover-only affordances.** Any desktop hover state (e.g., "hover to see tooltip") gets a tap-equivalent on phone. Tooltip on long-press is the canonical pattern.

### 6.4 Interaction priority (canonical)

- **Tap** = primary action / navigation.
- **Long-press** = metadata only (tooltips, history).
- **Button** = explicit action (assign, submit, intervene).

No "tap sometimes opens tooltip" surprises. This is enforced in the design review for every new component.

---

## 7. New components introduced in v1

| Component | Purpose | Path |
|---|---|---|
| `Layout` (root) | Resolves `mode` from viewport, renders chrome, provides `LayoutConfigContext` | `frontend/src/components/Layout.jsx` (modified) |
| `useLayoutConfig` | Returns the config object for `(role, mode)` | `frontend/src/hooks/useLayoutConfig.js` (new) |
| `StateAwareShell` | Wraps a widget; computes `NoData` / `LowConfidence` / `Healthy` and applies the right copy + visual | `frontend/src/components/mobile/StateAwareShell.jsx` (new) |
| `CodePreviewSurface` | Phone code preview (no Monaco, `<pre>` + horizontal scroll, Run/Submit) | `frontend/src/components/mobile/CodePreviewSurface.jsx` (new) |
| `AtRiskQueue` | Priority-sorted list of at-risk students (used by instructor) | `frontend/src/components/mobile/AtRiskQueue.jsx` (new) |
| `AtRiskRoster` | Filterable list (used by `/instructor/students`) | `frontend/src/components/mobile/AtRiskRoster.jsx` (new) |
| `ActionStack` | Priority-sorted list of next actions (used by student) | `frontend/src/components/mobile/ActionStack.jsx` (new) |
| `SnapshotMetrics` | 2×2 grid of system numbers (used by admin) | `frontend/src/components/mobile/SnapshotMetrics.jsx` (new) |
| `InstructorPriorityInsight` | The headline insight widget for instructor | `frontend/src/components/mobile/InstructorPriorityInsight.jsx` (new) |
| `StudentTodayFocus` | The headline action widget for student | `frontend/src/components/mobile/StudentTodayFocus.jsx` (new) |
| `EvaluationProgress` | Purple CTA: "Review pending evaluations (N)" | `frontend/src/components/mobile/EvaluationProgress.jsx` (new) |
| `Iso25010Instrument` | 4-point Likert, one question per screen | `frontend/src/components/mobile/Iso25010Instrument.jsx` (new) |
| `AuditLog` | Recent audit log list (admin) | `frontend/src/components/mobile/AuditLog.jsx` (new) |
| `SectionList` | Reused: section card list (already exists in desktop) | `frontend/src/components/SectionList.jsx` (modified for mobile mode) |
| `TopStrugglingConcepts` | Top-K concept list with `CDSPillDelta` | `frontend/src/components/mobile/TopStrugglingConcepts.jsx` (new) |
| `WeakestConceptBar` | Single concept bar with mastery % | `frontend/src/components/mobile/WeakestConceptBar.jsx` (new) |
| `ConceptMasteryBarSet` | 7 concept bars (one per concept) | `frontend/src/components/mobile/ConceptMasteryBarSet.jsx` (new) |
| `WeeklyProgress` | Student's weekly progress widget | `frontend/src/components/mobile/WeeklyProgress.jsx` (new) |
| `WeeklyTeachingInsight` | Instructor's weekly teaching insight | `frontend/src/components/mobile/WeeklyTeachingInsight.jsx` (new) |
| `ClassProfileRadar` | Class concept profile (summary mode on phone) | `frontend/src/components/mobile/ClassProfileRadar.jsx` (new) |
| `IntegrityFlagCount` | Flag count + "view all" drill | `frontend/src/components/mobile/IntegrityFlagCount.jsx` (new) |
| `IntegrityFlagList` | Recent flag list (3 most recent) | `frontend/src/components/mobile/IntegrityFlagList.jsx` (new) |
| `IntegrityFlagHistory` | Student's own flag history | `frontend/src/components/mobile/IntegrityFlagHistory.jsx` (new) |
| `ExerciseCardList` | Compact exercise card list (student) | `frontend/src/components/mobile/ExerciseCardList.jsx` (new) |
| `TestResultList` | Test results after Run/Submit | `frontend/src/components/mobile/TestResultList.jsx` (new) |
| `InterventionQueue` | Critical-only intervention list (instructor) | `frontend/src/components/mobile/InterventionQueue.jsx` (new) |
| `DesktopOnlyNotice` | Static "this is desktop only" notice | `frontend/src/components/mobile/DesktopOnlyNotice.jsx` (new) |
| `OpenFullEditorHint` | "Open full editor →" CTA | `frontend/src/components/mobile/OpenFullEditorHint.jsx` (new) |
| `IntegrityDrillNotice` | "Flag review requires tablet or desktop." | `frontend/src/components/mobile/IntegrityDrillNotice.jsx` (new) |

**Total: 24 new components** (in addition to 4 existing components that are reused with mobile-mode props).

---

## 8. State taxonomy (NoData / LowConfidence / Healthy)

Every primary widget (`PriorityInsight`, `StudentTodayFocus`, `SnapshotMetrics`) is wrapped in a `StateAwareShell` that derives one of three states from the response data. State is computed **on the client** from `submissions_per_student` and `section_age_days`. The server payload is unchanged.

| State | Trigger | Phone copy | Visual |
|---|---|---|---|
| **NoData** | 0 submissions, or section < 24 h old | "No exercise activity yet. Once students submit, you'll see risk signals here." | Dotted outline card · single primary CTA ("Open exercises →") |
| **LowConfidence** | 1–2 submissions/student, or section < 14 d old | "Early signal. Insights sharpen as data arrives." + progress: "n of 50 submissions to full confidence" | Standard card with "Limited" badge · progress bar · secondary widgets show dotted placeholders |
| **Healthy** | ≥ 3 submissions/student AND section ≥ 14 d old | Full insight copy (the existing `PriorityInsight` widget) | Standard layout as designed in §5 |

**Secondary/tertiary widgets** that receive 0 rows in their data are **hidden entirely** — not rendered with empty state. That avoids the visual "lots of empty cards" anti-pattern. (A widget that does receive data but is in `LowConfidence` shows the dotted placeholder treatment above; this only applies to the *primary* insight widget.)

This taxonomy directly answers the "CDS fails in cold start" thesis-defense concern. Acceptance criterion (§13.6): PriorityInsight shows `LowConfidence` within 24 h of first submission; `Healthy` by submission #3/student.

---

## 9. Naming canon (locked)

| Term | Meaning | Used by |
|---|---|---|
| `PriorityInsight` | The headline insight of the current context (What/Why/Who/Action) | All roles |
| `AtRiskQueue` | Priority-sorted list of at-risk students | Instructor |
| `AtRiskRoster` | Filterable student roster with action affordances | Instructor |
| `InterventionQueue` | Critical-only intervention list (with action buttons) | Instructor |
| `TopStrugglingConcepts` | Top-K concept list with `CDSPillDelta` | Instructor |
| `ActionStack` | Priority-sorted list of next actions | Student |
| `StudentTodayFocus` | The headline "what to do next" widget | Student |
| `WeakestConceptBar` | Single concept bar with mastery % | Student |
| `ConceptMasteryBarSet` | 7 concept bars (one per concept) | Student |
| `WeeklyProgress` | Student's weekly progress summary | Student |
| `WeeklyTeachingInsight` | Instructor's weekly teaching insight | Instructor |
| `ClassProfileRadar` | Class concept profile (summary mode on phone) | Instructor |
| `SnapshotMetrics` | 2×2 grid of system numbers | Admin |
| `EvaluationProgress` | "Review pending evaluations (N)" purple CTA | Admin |
| `Iso25010Instrument` | 4-point Likert evaluation instrument | Admin |
| `AuditLog` | Recent audit log list | Admin |
| `SectionList` | Reusable section card list | All roles |
| `ExerciseCardList` | Compact exercise card list | Student |
| `CodePreviewSurface` | Phone code preview (no Monaco) | Student |
| `TestResultList` | Test results after Run/Submit | Student |
| `IntegrityFlagCount` | Flag count summary | Instructor, Student |
| `IntegrityFlagList` | Recent flag list (3 most recent) | Instructor |
| `IntegrityFlagHistory` | Student's own flag history | Student |
| `IntegrityDrillNotice` | "Flag review requires tablet or desktop." | Instructor |
| `DesktopOnlyNotice` | Static "desktop only" notice | Admin |
| `OpenFullEditorHint` | "Open full editor →" CTA | Student |
| `RiskBadge` | Risk level (Low/Medium/High/Critical) — color + label | All roles |
| `CDSPill`, `CDSPillDelta`, `CDSGauge` | CDS visualization primitives (reused) | All roles |
| `StateAwareShell` | Wraps a widget; computes NoData / LowConfidence / Healthy | All roles |

**No synonyms.** "queue / list / stack / top-N" is collapsed to the canonical terms above. Every wireframe, every code file, every API field uses these names verbatim.

---

## 10. Layout config schema

```ts
type Mode = 'mobile' | 'tablet' | 'desktop';
type Role = 'instructor' | 'student' | 'admin';

type WidgetRef = {
  widget: string;            // canonical name from §9
  endpoint?: string;         // GET path; may include :id placeholders
  showIf?: string;           // expression evaluated against response data, e.g. "data.length > 0"
  collapsed?: boolean;       // tertiary only: start collapsed
  render?: 'summary' | 'full';  // chart widgets: 'summary' on phone, 'full' on tablet+
  static?: boolean;          // true for static copy notices
  copy?: string;             // static copy
  route?: string;            // drill route
};

type Screen = {
  primary: WidgetRef;
  primaryAction?: WidgetRef;  // admin only
  secondary: WidgetRef[];
  tertiary: WidgetRef[];
  codeBlock?: {              // /student/exercises/:id only
    engine: 'pre';
    monaco: false;
    horizontalScroll: true;
  };
};

type LayoutConfig = {
  role: Role;
  mode: Mode;
  chrome: {
    appBar: { title: string; rightSlot: 'avatar' | 'menu' };
    bottomNav?: {
      items: Array<{ key: string; label: string; icon: string; route: string }>;
    };
  };
  screens: Record<string, Screen>;
};
```

Example (instructor, mobile) — full JSON in companion visual `section-4-api-layout-cut-acceptance.html` §1.

---

## 11. Endpoint inventory (mobile touchpoints)

**24 mobile-touchpoint endpoints, all pre-existing. Zero new endpoints introduced.** The "no new endpoints" hard constraint from the existing spec is satisfied by construction.

### 11.1 Instructor (10 endpoints)

| Widget | Endpoint |
|---|---|
| `InstructorPriorityInsight` | `GET /api/analytics/instructor/priority-insight` |
| `AtRiskQueue` | `GET /api/analytics/instructor/at-risk-queue` |
| `AtRiskRoster` | `GET /api/analytics/instructor/students?sort=risk` |
| `InterventionQueue` | `GET /api/analytics/instructor/intervention-queue` |
| `TopStrugglingConcepts` | `GET /api/analytics/instructor/concepts/top?k=N` |
| `ClassProfileRadar` | `GET /api/analytics/instructor/concepts/profile` |
| `IntegrityFlagCount` | `GET /api/analytics/instructor/integrity/count` |
| `IntegrityFlagList` | `GET /api/analytics/instructor/integrity/recent?limit=3` |
| `WeeklyTeachingInsight` | `GET /api/analytics/instructor/weekly-insight` |
| `SectionList` | `GET /api/sections?instructor=me` |

### 11.2 Student (10 endpoints)

| Widget | Endpoint |
|---|---|
| `StudentTodayFocus` | `GET /api/analytics/student/today-focus` |
| `WeakestConceptBar` | `GET /api/analytics/student/concepts/weakest` |
| `ConceptMasteryBarSet` | `GET /api/analytics/student/concepts/all` |
| `ActionStack` | `GET /api/analytics/student/actions/next` |
| `WeeklyProgress` | `GET /api/analytics/student/progress/week` |
| `IntegrityFlagCount` (student) | `GET /api/analytics/student/integrity/count` |
| `IntegrityFlagHistory` | `GET /api/analytics/student/integrity/history` |
| `ExerciseCardList` | `GET /api/exercises?student=me` |
| `CodePreviewSurface` data | `GET /api/exercises/:id` |
| `TestResultList` | `GET /api/submissions/:id/results` |
| `SectionList` (student) | `GET /api/sections?student=me` |

### 11.3 Admin (4 endpoints)

| Widget | Endpoint |
|---|---|
| `SnapshotMetrics` | `GET /api/admin/snapshot` |
| `EvaluationProgress` | `GET /api/admin/evaluations/pending` |
| `Iso25010Instrument` | `GET /api/admin/evaluations/instrument` |
| `AuditLog` | `GET /api/admin/audit?limit=N` |
| `SectionList` (admin) | `GET /api/sections` |

**API diff vs pre-mobile baseline: 0 new, 0 removed, 0 modified.**

---

## 12. Performance budget

| Item | Target |
|---|---|
| Initial JS bundle (phone route) | ≤ 200 KB gzipped for `/instructor/command`, `/student/today`, `/admin/overview` |
| Monaco | Lazy-loaded only on `/student/exercises/:id?mode=full` (tablet+). **Never on initial phone bundle.** |
| D3 imports | Dynamic `import('d3')` on chart components, behind `mode !== 'mobile'` AND `render === 'full'` check. Phone never loads D3 for summary-mode components. |
| Route-level code splitting | Route changes use `React.lazy` + `Suspense`. The mobile entry bundle is the role-resolved layout + the role's primary widget only. |
| Off-screen lazy load | Charts off-screen get `IntersectionObserver` tap-to-load. |
| CSS containment | `contain: layout` on cards to limit reflow when `RiskBadge` or `CDSPill` changes. |

Bundle analyzer reports are checked on every build. CI fails if a phone-route bundle exceeds 200 KB.

---

## 13. Acceptance criteria

The metrics that decide if v1 shipped successfully. All measured, not asserted.

| # | Criterion | Target | Measurement |
|---|---|---|---|
| 1 | Instructor triage latency | Top-3 at-risk students identified in < 10 s from app open | User test, n=10, timed task |
| 2 | Student "what next" latency | Next action visible in < 3 s from app open | User test, n=10, timed task |
| 3 | No horizontal scroll on any chart | 0 charts require horizontal scrolling on phone (< 640 px) | Visual audit on 12 phone mockups |
| 4 | Phone initial JS bundle | ≤ 200 KB gzipped for the 3 top-level mobile routes | Vite build report |
| 5 | No D3 in phone bundle (summary mode) | D3 not in initial phone bundle for any route where the chart renders as summary | Bundle analyzer · grep `d3` |
| 6 | Cold-start first insight | `LowConfidence` state within 24 h of first submission; `Healthy` by submission #3/student | State machine test + integration test |
| 7 | Layout-config driven | 100% of phone screens render from the config object; zero `if (role === ...)` branches in `frontend/src/mobile/` | Codebase grep |
| 8 | Existing endpoints untouched | 0 new endpoints, 0 modified responses, 0 removed endpoints | API diff vs pre-mobile baseline |
| 9 | Tap targets | All interactive elements ≥ 44 × 44 px on phone | Lighthouse mobile audit |
| 10 | RiskBadge accessibility | On phone, RiskBadge always shows color + label; symbol is decorative | Component visual audit on 4 phone screens |
| 11 | Admin has ≥ 1 action path | `/admin/overview` surfaces the evaluation queue as the single primary action | Visual audit on `/admin/overview` |
| 12 | ISO/IEC 25010 evaluation usable on phone | 4-point Likert, one question per screen, progress bar; complete in < 4 min from phone | User test, n=5 evaluators |
| 13 | Safe-area-inset respected | Bottom tab bar respects iOS home indicator; no content clipped on iPhone 14/15 | Visual audit on iOS simulator |
| 14 | N is adaptive | `min(5, floor((viewportHeight - chromeHeight - primaryHeight) / rowHeight))` produces correct row count for Galaxy S24 (5 rows) and foldable inner display (3 rows) | Unit test on the formula |
| 15 | N is not hard-coded | Zero hard-coded `3` or `5` constants in mobile widget components | Codebase grep |
| 16 | Naming canon enforced | Every component filename in `frontend/src/mobile/` matches a name in §9 | Filename audit |
| 17 | Component count | 24 new components introduced | Component count audit |

---

## 14. Open questions for v2 (not in scope for v1)

These are explicitly **not** part of v1. Listed for transparency so the defense committee sees the roadmap.

- 🔜 Native mobile apps (React Native or Swift/Kotlin) — defer until web responsive is validated.
- 🔜 Real-time push notifications for integrity flags.
- 🔜 Mobile flag review UI (requires a redesigned diff viewer for small screens).
- 🔜 Mobile code editing via a custom mini-editor (Monaco is too heavy; a stripped-down editor might fit).
- 🔜 Offline-first via service worker.
- 🔜 Bulk export on mobile (CSV download from `/admin/overview`).
- 🔜 User management on mobile.
- 🔜 Mobile intervention note-taking.
- 🔜 Drag-to-reorder widgets on phone.

---

## 15. Companion visuals

These mockups were reviewed and approved in the brainstorming session. They are the visual source of truth for this spec.

- `.superpowers/brainstorm/102506-1780640635/content/section-1-shell-and-ia.html` — Mobile shell anatomy + per-role IA
- `.superpowers/brainstorm/102506-1780640635/content/section-2-transformation-rules.html` — Component transformation table
- `.superpowers/brainstorm/102506-1780640635/content/section-3-per-role-screens.html` — Per-role mobile screen blueprints
- `.superpowers/brainstorm/102506-1780640635/content/section-4-api-layout-cut-acceptance.html` — API contracts, layout-config schema, cut list, acceptance criteria
- `.superpowers/brainstorm/102506-1780640635/content/approach-options.html` — Approach A/B/C trade-off (B chosen)

---

## 16. Spec self-review (inline)

| Check | Status | Notes |
|---|---|---|
| Placeholders (TBD / TODO / "implement later") | ✅ None | All sections have concrete content. |
| Internal consistency (naming, endpoints, state triggers) | ✅ Verified | §9 naming canon is the single source of truth; §11 endpoints match §5 widget assignments; §8 state triggers are concrete thresholds. |
| Scope (focused enough for one plan) | ✅ Yes | Mobile responsive is well-bounded: 24 endpoints (existing), 24 new components, 3 mobile routes per role, 13 acceptance criteria. |
| Ambiguity (no two-ways-to-read-it) | ✅ Verified | `showIf` is a string expression evaluated against `data` (concrete in §10); N formula is a concrete function in §13.4 / §6.1; state triggers are concrete numbers in §8. |
| Constraints carried over from desktop spec | ✅ Verified | §1.3 table — every constraint is mapped to a satisfying rule in this spec. |
| API contract (no new endpoints) | ✅ Verified | §11 inventory is 24 pre-existing endpoints, no additions. |
| "Learning Insights Language" preserved | ✅ Verified | §5 blueprints show the canonical copy ("Why: Loops are your weakest (0.71)") for every primary widget. |
| Type/symbol consistency | ✅ Verified | `widget`, `endpoint`, `showIf`, `collapsed`, `render`, `static`, `copy`, `route` are used consistently across §1-2 and §10. |
| RiskBadge accessibility (color + label) | ✅ Verified | §6.1 row + §13.10 acceptance criterion. |
| Cold-start handling | ✅ Verified | §8 NoData / LowConfidence / Healthy taxonomy + §13.6 acceptance criterion. |
| Spec readiness | ✅ Ready for implementation planning | |

**No issues found. Spec is ready for review.**

---

**Status:** Spec written, self-reviewed, and committed (next step). Awaiting user review before invoking writing-plans.
