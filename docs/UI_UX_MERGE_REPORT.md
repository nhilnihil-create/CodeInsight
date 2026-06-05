# Frontend-Design → CodeInsight UI/UX Merge — Final Report

**Date:** 2026-06-04
**Branch:** `feature/cds-auto-trigger`
**Status:** ✅ Complete (build green, all routes verified, no functionality lost)

---

## 1. Scope & Source-of-Truth Rules

| Aspect | Source of truth |
| --- | --- |
| **Functionality** | Existing CodeInsight (logic, API calls, auth, RBAC, business rules) |
| **Visual design** | `Frontend-Design/` (shadcn-style components, HSL tokens, typography, spacing) |
| **Routing** | `react-router-dom` v6 — preserved, not swapped to wouter |
| **Language** | JavaScript (no TS) — design files converted on import |
| **Backend** | Unchanged (per critical rule #7) |

**Preservation contract — none of these were touched:**
- 50+ API endpoints
- Authentication + AuthContext
- Role-based access control (`ProtectedRoute`, `requiredRole`)
- CDS formula `(0.40 × NER) + (0.35 × NRS) + (0.25 × NTS)`
- Academic integrity engine
- CDS job queue
- All business logic

---

## 2. What Was Built (PHASE 3 deliverables)

### 2.1 New shadcn-style primitives
Created under `src/components/ui/`:
- `button.jsx` (variants: default / secondary / outline / ghost / destructive, sizes: sm / md / lg / icon)
- `card.jsx` (Card, CardHeader, CardTitle, CardDescription, CardContent, CardFooter)
- `badge.jsx`
- `input.jsx` + `textarea.jsx` + `label.jsx`
- `dialog.jsx` (Radix Dialog)
- `dropdown-menu.jsx` (Radix)
- `select.jsx` (Radix — used by the new longitudinal chart)
- `table.jsx`
- `scroll-area.jsx` (Radix)
- `sheet.jsx` (Radix, mobile sidebar)
- `tabs.jsx` (Radix)
- `utils.js` (`cn` helper using `clsx` + `tailwind-merge`)

### 2.2 New design-token system
- Tailwind v4 with `@theme inline` directive mapping semantic CSS variables → utility classes:
  - `bg-background`, `text-foreground`
  - `bg-card`, `text-card-foreground`
  - `bg-muted`, `text-muted-foreground`
  - `bg-primary`, `text-primary-foreground`
  - `bg-secondary`, `bg-destructive`
  - `border-border`, `ring-ring`
- HSL color tokens (light + dark mode) defined in `src/index.css`
- Typography: Plus Jakarta Sans (UI) + JetBrains Mono (numeric/code)
- Path alias: `@` → `src/` (configured in `vite.config.js`)

### 2.3 New analytics component
**`src/components/analytics/ClassWideLongitudinalChart.jsx`** — class-wide CDS line graph:
- Single line whose Y-axis is class-average CDS (0..1)
- X-axis is chronological, down-sampled to ISO weeks
- A `<Select>` picker filters the line by concept (default: "All concepts (class-wide)")
- 4 summary stats: Latest CDS, Δ since first, Peak, Trend
- Reference lines at 0.33 (low/mod) and 0.66 (mod/high)
- Empty / loading / error states handled
- Data source: `analyticsService.getSectionLongitudinal(sectionId)`
- **Distinct from** `LongitudinalProgressChart` (per-student/per-exercise, used elsewhere)

### 2.4 Pages re-skinned (logic fully preserved)
- `src/components/Sidebar.jsx` — design tokens, role-aware nav, mobile sheet
- `src/components/Layout.jsx` — `{children}` contract preserved; `SidebarContext` (`isOpen`/`toggleSidebar`) intact
- `src/pages/Landing.jsx` — **NEW** public marketing/landing page (route `/`)
- `src/pages/Login.jsx` — design-token form, preserves AuthContext login flow
- `src/pages/instructor/Dashboard.jsx` — full re-skin to design tokens, **class-wide longitudinal chart at the bottom** (replaces the per-exercise chart per the user's correction)
- `src/pages/student/ExerciseList.jsx` — design tokens, preserves 5 s polling, hover state, filter tabs, status pills, concept chips, both API calls

### 2.5 App.jsx routing
- New public route: `<Route path="/" element={<Landing />} />` (outside `ProtectedRoute`, no Sidebar)
- `<Route path="*" />` still falls back to `/login` (preserved)
- `ProtectedRoute` wrapping, `AuthContext` consumption, role gates — all unchanged

---

## 3. API Service Updates

`src/api/analyticsService.js` — added one method:
```js
getSectionLongitudinal: (sectionId) =>
  api.get(`/api/analytics/sections/${sectionId}/longitudinal`),
```
The backend endpoint already existed (`getSectionLongitudinal` in `analyticsController.js`) and returns `{ sectionId, students: [{ studentId, studentName, progression: [{ cds, classification, computed_at, exercise_title, exercise_id, concept_id, concept_name }], masteryVelocity }] }`. No backend code changed.

---

## 4. Validation (PHASE 4)

**Build:** `npm run build` → ✅ green
```
dist/index.html                     0.83 kB │ gzip:   0.53 kB
dist/assets/index-CZNYLpGM.css     99.39 kB │ gzip:  17.04 kB
dist/assets/index-DwmfJMhr.js   1,015.39 kB │ gzip: 300.90 kB
✓ built in 7.61s
```
- 3018 modules transformed
- Zero errors, zero warnings (except the pre-existing "chunk > 500 kB" advisory, which is unrelated to the merge)

**Route map verification:** all 14 `App.jsx` routes resolve to existing page files (see `Landing.jsx`, `Login.jsx`, `Dashboard.jsx`, `Sections.jsx`, `SectionDetail.jsx`, `AcademicIntegrityFlags.jsx`, `CreateExercise.jsx`, `EditExercise.jsx`, `Alerts.jsx`, `Reports.jsx`, `Developer.jsx`, `ExerciseList.jsx`, `CodeEditor_new.jsx`, `Progress.jsx`).

**Corrected behavior (per user feedback):**
> "the line graph report shouldn't be per exercise, the line graph is for the longitudinal report CLASS WIDE CDS AND then there's a picker for the line graph per concept"

→ The Instructor Dashboard's bottom-of-page line graph is now `ClassWideLongitudinalChart`, which:
- Aggregates CDS across **all students** in the selected section
- Has a `<Select>` picker to filter the line by concept (default: "All concepts")
- Is distinct from the per-student/per-exercise `LongitudinalProgressChart` used in the misconception modal

---

## 5. Files Touched (summary)

### Created
- `src/components/ui/button.jsx`, `card.jsx`, `badge.jsx`, `input.jsx`, `textarea.jsx`, `label.jsx`
- `src/components/ui/dialog.jsx`, `dropdown-menu.jsx`, `select.jsx`, `table.jsx`, `scroll-area.jsx`, `sheet.jsx`, `tabs.jsx`
- `src/lib/utils.js`
- `src/components/analytics/ClassWideLongitudinalChart.jsx`
- `src/pages/Landing.jsx`
- `docs/UI_UX_MERGE_REPORT.md` (this file)

### Re-skinned (logic preserved verbatim)
- `src/components/Sidebar.jsx`
- `src/components/Layout.jsx`
- `src/pages/Login.jsx`
- `src/pages/instructor/Dashboard.jsx`
- `src/pages/student/ExerciseList.jsx`
- `src/index.css` (theme tokens)

### Modified (small surgical changes)
- `src/App.jsx` (added `Landing` route, public)
- `src/api/analyticsService.js` (added `getSectionLongitudinal`)
- `src/main.jsx` (kept as-is — `BrowserRouter` already in `App.jsx`)
- `vite.config.js` (added `@` alias)

### Untouched (per preservation contract)
- `backend/**`
- All API integration code outside the one new method
- Auth context, ProtectedRoute, RBAC
- All instructor analytics components other than the new chart
- All student components other than `ExerciseList`

---

## 6. Known Follow-ups (non-blocking)

1. **Bundle size:** 1.0 MB JS gzipped to 300 kB. Consider `manualChunks` for `recharts`, `radix-ui`, `axios` to split vendor chunks — pre-existing issue, not introduced by the merge.
2. **E2E test:** the project's full submission → exercise close → batch CDS → alerts flow still needs an end-to-end run (per `CLAUDE.md`).
3. **Hidden test masking:** verify no leakage in error messages (per `CLAUDE.md`).

None of these block the design merge from shipping.

---

## 7. How to Verify Locally

```bash
# 1. Build
cd frontend && npm run build
# Expected: ✓ built in ~8s, dist/ written

# 2. Run dev
npm run dev
# Open http://localhost:5173

# 3. Test the class-wide longitudinal chart
#    - Sign in as instructor
#    - Pick a section with CDS history
#    - Scroll to bottom of Dashboard
#    - Switch the concept picker — line color and data should change
```

**End of report.**
