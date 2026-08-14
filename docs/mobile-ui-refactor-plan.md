# Mobile UI Refactor Plan — Instructor & Student Pages

**Goal**: Make every instructor and student page fit comfortably on all viewport widths (320px phones → 375px → 768px tablets → 1024px+ desktop), eliminating elements that overflow to the right or get squeezed on slim screens.

**Approach (in order of execution)**:
1. Fix **hard overflows** first (content visibly clipped or pushing past the right edge).
2. Then **convert dense grid/table rows** to mobile card layouts.
3. Then **harden shared components** so every page inherits the fix.
4. Verify at 360×740 and 768×1024 (Playwright Chromium mobile emulation).

**Verification harness**: `frontend/tests/e2e/mobile-triage.spec.js` (login helper, Pixel-5 emulation). Add a page-by-page walkthrough spec that navigates each route at 360×740 and asserts `document.documentElement.scrollWidth <= window.innerWidth` (no horizontal overflow) plus key elements visible.

---

## Phase 1 — Hard Overflows (P0)

### 1.1 `instructor/tabs/SettingsTab.jsx` — Assigned exercises grid overflows
- **Problem**: `<ul className="divide-y divide-border">` rows use `grid grid-cols-[1fr_5rem_6rem_3rem] items-center gap-3 px-5 h-14` with **no** `overflow-x-auto` wrapper. At 360px: 5rem+6rem+3rem = 14rem (224px) + gaps (36px) + px-5 (40px) = 300px fixed, leaving only ~60px for the title column → content clipped, and with long titles the row forces horizontal scroll of the page.
- **Fix**: 
  - Wrap in `overflow-x-auto` as a stopgap, AND/OR restructure the row to stack on mobile:
    - `<li>` becomes `flex flex-col sm:grid sm:grid-cols-[1fr_5rem_6rem_3rem] sm:items-center gap-1 sm:gap-3 px-4 sm:px-5 py-3 sm:h-14`
    - Title takes full width; `submitted/total` + `concept` become inline meta chips on mobile.
- **Also in same file**: roster rows `flex items-center gap-3 px-3 h-10` with `(email)` span + trash button — on 320px long emails squeeze; add `truncate`/`min-w-0` on name + `hidden xs:inline` or truncation on email. Roster header "Assign exercise" button + title row: allow wrap (`flex flex-wrap items-center justify-between`).

### 1.2 `instructor/Heatmap.jsx` — Toolbar + header overflow
- **Problem**: 
  - Toolbar: `flex items-center justify-between px-4 py-2.5` containing label `"Student × Concept — Struggle Index"` + `<Input className="w-40" />` + `<Legend />` (~180px: "Very Low" + w-24 gradient + "Very High"). Total far exceeds 360px → clips/overflows.
  - Page header: `flex items-center gap-2` with `SectionFilter` (`min-w-[200px]` trigger) + `ExportDropdown` — overflows on 360px.
- **Fix**:
  - Toolbar: `flex flex-col gap-2 sm:flex-row sm:items-center sm:justify-between`; move search+legend into a `flex flex-wrap items-center gap-3` cluster; legend text `hidden sm:inline`.
  - Header: add `flex-wrap` and give `SectionFilter` a `w-full sm:w-auto` class.

### 1.3 `instructor/Command.jsx` — Concept difficulty rows overflow
- **Problem**: `flex items-center gap-3` row = `w-8` label + `CDSPillDelta` (long pill: `0.42 +0.05 (moderate)` ≈ 130px+) + `flex-1` bar + `"N at risk"` text. On 360px the fixed pieces (32+130+~60) leave < 140px for the bar; long labels wrap awkwardly and the row can exceed width.
- **Fix**: `flex flex-col sm:flex-row sm:items-center gap-1.5 sm:gap-3`; on mobile put label + pill on row 1, bar + count on row 2 (`flex items-center gap-2`). Hide `(classification)` from pill on xs (see §3.2).
- **Also**: at-risk roster rows `flex items-center justify-between` (name + RiskBadge + concept badge + View) → add `flex-wrap` + `gap`.

### 1.4 `instructor/SectionDetail.jsx` — Header action cluster
- **Problem**: `flex items-center gap-2 shrink-0` holding `Export Roster` + `VisualReportButton` + `MoreHorizontal` dropdown — three wide controls; no wrap → overflow at 320–360px. Same pattern at `StudentDetail.jsx:285`.
- **Fix**: `flex flex-wrap items-center gap-2 shrink-0`; give Export/Visual buttons `w-full sm:w-auto` on xs or shrink labels ("Roster", "Report") below sm.
- **Also**: page title `{section.name} — {section.course_code}` — add `break-words` / `min-w-0`.

### 1.5 `instructor/ExerciseExplorer.jsx` — Header action cluster
- **Problem**: `flex items-center gap-2` with "Bulk Create" + "Create Exercise" buttons → overflows on 320px.
- **Fix**: `flex flex-wrap items-center gap-2` (buttons naturally wrap to two rows on xs).

### 1.6 `instructor/tabs/SubmissionsTab.jsx` — 7-column GRID_CLASS
- **Problem**: `grid grid-cols-[minmax(0,1.4fr)_minmax(0,1fr)_3.5rem_5.5rem_5rem_7rem_2rem]` per row. Wrapped in `overflow-x-auto` so it scrolls, but on mobile the group row + inline attempt rows are a poor horizontal-scroll experience, and the "Review" button (last col, 2rem) is nearly unusable.
- **Fix**: Add a **mobile card row** variant below `sm`:
  - Header hidden on mobile (`hidden sm:grid`).
  - Group row: `<div>` becomes `flex flex-col sm:grid sm:grid-cols-... gap-1 sm:gap-3 px-4 py-3 sm:h-14` — student avatar+name+email on line 1, exercise title + attempts + status + time + flag on line 2 (as chips), chevron at right.
  - Attempt rows: same pattern; "Review" becomes a full-width `w-full` button on mobile.
  - Exercise filter `<select>`: `w-full sm:w-auto` (it's currently a raw select that hugs content — give it `max-w-full` and `truncate`).

### 1.7 `instructor/tabs/RosterTab.jsx` — 5-column grid
- **Problem**: `grid grid-cols-[1fr_5.5rem_4rem_5.5rem_2.5rem]` inside `overflow-x-auto` — scrolls; name+tier chip column is cramped on mobile.
- **Fix**: Mobile card variant (same pattern as 1.6): name + tier chip line 1; CDS + flags + last-active line 2 as chips; `MoreHorizontal` menu stays right-aligned. Keep the desktop grid above `sm`.

### 1.8 `instructor/Alerts.jsx` + `instructor/Integrity.jsx` — DecisionList wide rows
- **Problem**: `renderRow` outputs 8–10 fixed/min-width columns (e.g. `min-w-[8rem]`, `min-w-[10rem]`, `w-16`, `w-20`, `w-14`, `w-24`). DecisionList wraps them in `overflow-x-auto` → horizontal scroll, most columns off-screen.
- **Fix**: Extend `DecisionList` with a `renderMobileRow` prop (or auto mobile layout): below `sm`, render a card: line 1 = risk badge + primary label + chevron; line 2 = secondary fields as chips; line 3 = action buttons full-width. Implement once in `components/ui/decision-list.jsx`, wire both pages.

### 1.9 `instructor/Exercises.jsx` — 4-button action cluster per row
- **Problem**: 6-col `Table` (base Table scrolls), but each row has `inline-flex gap-1` with **Edit + View submissions + Lock/Unlock + Delete** → at 360px the actions wrap inside a fixed-height row and clip.
- **Fix**: Collapse actions into a `MoreHorizontal` `DropdownMenu` below `sm` (Edit / View submissions / Close-or-Reopen / Delete), or make the action cell `flex flex-wrap` with icon-only buttons (`size="icon"`) and text hidden on xs.

### 1.10 `student/Sections.jsx` — Section row
- **Problem**: `flex items-center justify-between` with name + term + Active badge + Leave button — tight on 320px; long section names push the button.
- **Fix**: `flex items-center justify-between gap-2 flex-wrap`; name block gets `min-w-0 flex-1` + `truncate`.

---

## Phase 2 — Tables → Mobile Column Strategy (P1)

Pages still using raw `<Table>` (scrolls, no mobile column hiding) — convert to `ResponsiveTable` with `mobile` keys:

| File | Columns | Mobile plan |
|---|---|---|
| `instructor/Exercises.jsx` | Title, Concepts, Due, Status, actions | primary=Title+Status chip, label=Concepts/Due, actions dropdown |
| `instructor/ClassMicroConceptReport.jsx` | Issue, Students, Severity, Recommendation | primary=Issue+Severity chip, label=Students, hidden=Recommendation (or card) |

`ResponsiveTable` already supports `renderMobileCell` + `mobile: 'primary'|'label'|'hidden'|'actions'` — reuse it; do **not** hand-roll new table logic.

---

## Phase 3 — Shared Component Hardening (P1/P2)

### 3.1 `SectionFilter.jsx`
- Trigger `min-w-[200px]` → `w-full sm:w-[200px] sm:min-w-[200px]` and add a `className` passthrough so pages can control width (`w-full sm:w-auto`). Parents that pair it with Export/Refresh already use `flex-wrap`; ensure the ones that don't (Heatmap 1.2, SectionDetail 1.4) get it.

### 3.2 `CDSPillDelta.jsx`
- Pill renders `0.42 +0.05 (moderate)` — the `(classification)` suffix costs ~70–90px. Hide below `sm`: `<span className="hidden sm:inline ml-0.5 ...">({classification})</span>`. Keep value+delta always.

### 3.3 `DecisionList.jsx`
- Add `renderMobileRow` (or auto card layout below `sm`) per 1.8. Keep desktop row identical.

### 3.4 `InsightHeader` (used on every page)
- Action cluster `flex items-center gap-2 shrink-0` → add `flex-wrap`; if multiple actions, allow stacking. Low risk, high coverage.

### 3.5 `student-dashboard-shell.jsx` / `instructor-dashboard-shell.jsx`
- Action block is `flex items-center gap-2 shrink-0` inside a `flex-col sm:flex-row` wrapper → already stacks on mobile. Just add `flex-wrap` to the action cluster for multi-action cases (e.g. `student/Progress.jsx` text + PeriodSelector).

### 3.6 `mastery-bar.jsx`
- Verify bar's fixed width / `min-w` inside grid rows (Today/Progress/Dashboard use `grid-cols-[1fr_auto_auto]`) — currently OK, but confirm `MasteryBar` uses `w-full` + `min-w-0` so it never forces row width.

---

## Phase 4 — Page-by-Page Verification Checklist

Add a Playwright spec (new file `frontend/tests/e2e/mobile-widths.spec.js`) that at **360×740** and **768×1024** (Chromium emulation), for each route below, signs in (maria@student.psu.edu / instructor@psu.edu / admin@psu.edu as applicable), navigates, and asserts:
```js
expect(await page.evaluate(() => document.documentElement.scrollWidth <= window.innerWidth)).toBe(true)
```

**Instructor routes**:
- `/instructor/dashboard`, `/instructor/command`, `/instructor/reports`, `/instructor/sections`, `/instructor/sections/:id` (+ each tab: roster/analytics/submissions/settings), `/instructor/students`, `/instructor/students/:id`, `/instructor/exercises`, `/instructor/exercises/:id/edit`, `/instructor/exercises/new`, `/instructor/exercise-explorer`, `/instructor/alerts`, `/instructor/integrity`, `/instructor/heatmap`, `/instructor/class-micro-concept-report` (route name to confirm)

**Student routes**:
- `/student/dashboard`, `/student/today`, `/student/progress`, `/student/profile`, `/student/recommendations`, `/student/exercises`, `/student/exercises/:id` (editor), `/student/sections`

**Interaction checks**: hamburger → drawer open/close; on Reports Mastery tab, the 4-KA-group picker wraps; in Submissions tab, open a group row and tap Review → drawer full-width, timeline opens as slide-in sidebar (SubmissionDetailDrawer), no horizontal scroll.

---

## Global Rules to Apply While Editing
1. **Never let a flex/grid row exceed viewport**: default to `flex-wrap`, `min-w-0` on truncating children, and `overflow-hidden`/`overflow-x-auto` only where intentional.
2. **Custom `grid-cols-[...]` templates**: always audit against 320px; prefer `1fr` + `auto` + `minmax(0,…)`; add a mobile stacked variant below `sm` when fixed rem columns sum > ~12rem.
3. **Header action clusters**: `flex flex-wrap items-center gap-2 shrink-0` is the house pattern (Reports/Integrity/Alerts/Dashboard already do it) — replicate everywhere.
4. **Buttons in tables**: on xs prefer icon-only or a `DropdownMenu`; never `inline-flex` more than 2 buttons.
5. **Tables**: route through `ResponsiveTable` with `mobile` keys; raw `<Table>` only for truly wide data that is *supposed* to scroll (e.g., Heatmap mosaic).
6. **Drawers/sheets**: already `w-full sm:max-w-lg` (DetailDrawer) / full-width on mobile (SubmissionDetailDrawer) — keep, don't regress.
7. **Run lint + `npm test` (244 unit tests) after each phase**; never break the existing green E2E suite.

## Suggested Commit Sequence
1. `fix(mobile): SettingsTab + Heatmap + Command overflow at <375px` (1.1–1.3)
2. `fix(mobile): wrap header action clusters on SectionDetail/StudentDetail/ExerciseExplorer/Sections` (1.4, 1.5, 1.10)
3. `feat(mobile): card layout for SubmissionsTab + RosterTab rows below sm` (1.6, 1.7)
4. `feat(mobile): DecisionList mobile row variant; wire Alerts + Integrity` (1.8)
5. `fix(mobile): collapse instructor exercise row actions into dropdown on xs` (1.9)
6. `refactor(mobile): convert raw Tables to ResponsiveTable with mobile keys` (Phase 2)
7. `fix(mobile): shared components — SectionFilter, CDSPillDelta, InsightHeader wrap` (Phase 3)
8. `test(e2e): mobile no-overflow walkthrough at 360x740 and 768x1024` (Phase 4)
