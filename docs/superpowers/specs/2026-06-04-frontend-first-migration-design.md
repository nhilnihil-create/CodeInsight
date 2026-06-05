# Frontend-First Migration — Student-Flow Vertical Slice

**Status:** Draft, awaiting user approval
**Date:** 2026-06-04
**Branch:** feature/cds-auto-trigger
**Scope:** Student flow only (3 pages + supporting shell). Instructor and follow-up slices are explicitly out of scope.

---

## 1. Context & Motivation

The repository contains two parallel frontend efforts:

- **`frontend/`** — the live, production-tied React app. JavaScript / JSX, react-router-dom v6, real `AuthContext` + axios `api.js`, ~6,000 LoC across ~30 files. It is already 98% complete (per `CLAUDE.md`) and wired to the live backend (`/api/*`).
- **`Frontend-Design/Frontend-Design/artifacts/codeinsight/`** — a design reference implementation. TypeScript / TSX, `wouter` router, mock data only, ~1,500 LoC across 16 page files. No backend integration.

The migration directive in the user's prompt assumes the live frontend is "NOT the UI source of truth anymore" and that Frontend-Design should be adopted wholesale. Inventory reveals the situation is more nuanced:

1. The live `frontend/src/components/Sidebar.jsx` was already partially migrated to Frontend-Design's design tokens in a prior pass (uses `bg-sidebar`, `text-foreground`, shadcn primitives, semantic tokens).
2. The live `frontend/src/components/Layout.jsx` is a thin 41-line wrapper.
3. The live `AuthContext.jsx` is real (localStorage token, real backend) and must NOT be replaced with `Frontend-Design/src/lib/auth.ts` (which is mocked).
4. Frontend-Design's pages (`Dashboard.tsx`, `Exercises.tsx`, `CodeEditor.tsx`) are pure UI shells with hard-coded `MOCK_RADAR_DATA`, `MOCK_EXERCISES` — they cannot replace the real pages that talk to `/api/exercises`, `/api/submissions`, etc.

The honest framing: this is a **visual / structural adoption**, not a wholesale replacement. The work is real and substantial, but the framing "Frontend-Design is the new shell" is misleading. This spec corrects the framing and scopes the work honestly.

## 2. Decisions Made (Brainstorming Outcomes)

Confirmed with the user before this spec:

1. **Stack:** Keep JavaScript / JSX + react-router-dom v6 + Vite + Tailwind v4 + shadcn/ui. Do NOT migrate to TypeScript or wouter. Frontend-Design's TSX files will be ported to JSX as needed.
2. **Mock strategy for this slice:** Hybrid — real `AuthContext` (login hits the real backend), Frontend-Design's mock data files for page content (exercises list, dashboard stats). Real-API integration deferred to a follow-up slice.
3. **Scope:** Vertical slice — student flow only. 3 student pages. No instructor changes.
4. **Process:** This spec exists. Wait for explicit "go" before any code changes.

## 3. In Scope

### 3.1 New files to create

| Path | Source | Notes |
|------|--------|-------|
| `frontend/src/data/mockData.js` | Port of `Frontend-Design/src/data/mockData.ts` (TS→JS) | `MOCK_EXERCISES`, `MOCK_RADAR_DATA`, `Role` enum. |
| `frontend/src/lib/auth.js` | Port of `Frontend-Design/src/lib/auth.ts` (TS→JS) | Mock `getCurrentUser` / `login` / `logout` for the student flow only. Real `AuthContext.jsx` is left in place for `/login`. |
| `frontend/src/pages/student/Dashboard.new.jsx` | Port of `Frontend-Design/src/pages/student/Dashboard.tsx` | Uses real `AuthContext` for `user`; uses `MOCK_RADAR_DATA` for chart; keeps shadcn `Card` + recharts `RadarChart`. |
| `frontend/src/pages/student/Exercises.new.jsx` | Port of `Frontend-Design/src/pages/student/Exercises.tsx` | Uses `MOCK_EXERCISES`; uses `react-router-dom` `Link` instead of wouter `Link`. |
| `frontend/src/pages/student/CodeEditor.new.jsx` | Port of `Frontend-Design/src/pages/student/CodeEditor.tsx` | Same — wouter→RRD, mock output strings. Replaces the 753-line `CodeEditor_new.jsx.bak`'s logic with a clean, minimal UI shell. |

The `.new.jsx` suffix lets us keep the existing `Dashboard.jsx`, `ExerciseList.jsx`, `CodeEditor_new.jsx` in place as fallbacks during the cutover. After validation, the old files are deleted and the new ones renamed.

### 3.2 Files to modify

| Path | Change |
|------|--------|
| `frontend/src/App.jsx` | Change the 3 student route imports to point to the new files (`StudentDashboard` → `./pages/student/Dashboard.new`, etc.). Keep all other routes untouched. |
| `frontend/src/components/Layout.jsx` | Lightly align with Frontend-Design's `AppLayout.tsx` rhythm: keep current `Sidebar` + `pageTitle` header, but make the page container use `max-w-7xl` and `p-6 lg:p-8` (matches `AppLayout.tsx` content area). |
| `frontend/src/components/Sidebar.jsx` | No structural change. Already uses design tokens. |

### 3.3 Files explicitly NOT touched in this slice

- `frontend/src/pages/instructor/**` (10 files, ~4,000 LoC) — instructor vertical slice is a follow-up.
- `frontend/src/services/api.js`, `frontend/src/api/analyticsService.js`, `frontend/src/services/sectionAnalyticsApi.js` — real backend clients; preserved.
- `frontend/src/context/AuthContext.jsx` — real auth; preserved.
- `frontend/src/components/LiveCDSPanel.jsx`, `IntegrityFlagBadge.jsx`, `CodeComparisonModal.jsx`, `EnrollStudentsModal.jsx`, `analytics/**`, `charts/**` — CodeInsight-only features; out of scope for this slice.

## 4. Architecture

### 4.1 Routing (in-scope only)

The three student routes are re-pointed:

```
/student/dashboard           → pages/student/Dashboard.new.jsx
/student/exercises           → pages/student/Exercises.new.jsx
/student/exercises/:id       → pages/student/CodeEditor.new.jsx
```

All other routes (including `/student/progress`, `/student/profile`, all `/instructor/*`) continue to render their existing files. `ProtectedRoute` and role-based redirects are unchanged.

### 4.2 Data flow

- **Auth:** `useAuth()` from the real `AuthContext.jsx` (token in `localStorage`, axios interceptor adds `Authorization: Bearer <token>`). Login still POSTs to the real backend.
- **Page content (this slice):** Imported constants from `mockData.js` — `MOCK_EXERCISES`, `MOCK_RADAR_DATA`. No `useEffect`/`fetch` in the new pages.
- **CodeEditor (this slice):** `useState` only. "Run Code" shows the first test case's expected output as a string. "Submit" shows a fake success string. This is a visual demonstration of the new UI — real code execution / submission goes through the existing `CodeEditor_new.jsx.bak` logic, deferred to a follow-up slice.

### 4.3 Design system

The live frontend already uses shadcn/ui + semantic tokens (`bg-sidebar`, `text-foreground`, `text-muted-foreground`, `bg-card`, `bg-muted`, `text-primary`, etc.). The new pages use the same tokens — no custom hex values except the editor pane's `#1e1e1e` / `#2d2d2d` (matching Frontend-Design's intentional VS-Code-style dark editor chrome).

A `docs/superpowers/specs/2026-06-04-design-tokens.md` will be produced as a follow-on artifact (not in this slice) to document the tokens for future instructor / feature slices. For this slice, the design system is "use what's already in `frontend/src/index.css` and the shadcn primitives under `frontend/src/components/ui/`."

## 5. Files Affected — Summary

| Category | Count |
|----------|-------|
| New files | 5 (mockData, auth, 3 new pages) |
| Modified files | 2 (App.jsx routes, Layout.jsx spacing) |
| Deleted files (after validation) | 3 (Dashboard.jsx, ExerciseList.jsx, CodeEditor_new.jsx old versions) |
| Unchanged | ~30 instructor/auth/service files |

Total LoC delta: roughly **+400 / −2,000** net (the new pages are minimal, the old ones are large and stay around during cutover).

## 6. Validation

After the changes:

1. `cd frontend && npm run build` succeeds.
2. `npm run dev` boots; `/login` loads the existing real-backend form.
3. Logging in as a student navigates to `/student/dashboard` which renders the new design (cards + radar chart with mock data).
4. `/student/exercises` renders 3-card grid of mock exercises with "Start Exercise" buttons.
5. Clicking "Start Exercise" navigates to `/student/exercises/<id>` which renders the new editor shell (description left, dark editor right, terminal output bottom).
6. "Run Code" and "Submit" buttons work as visual demos (no real backend hit).
7. The existing `/student/progress` and `/student/profile` continue to work (untouched).
8. All `/instructor/*` routes continue to work (untouched).
9. The dev console shows no React errors or missing-import warnings.
10. `git status` shows the changes are limited to the 7 files listed in §3.1–3.2.

## 7. Out of Scope (Follow-up Slices)

- **Instructor vertical slice** — `Dashboard`, `Exercises`, `ExerciseForm`, `Heatmap`, `Students`, `StudentDetail`, `Warnings`, `Reports`, `Violations`, `Integrity`. The instructor `Sidebar.jsx` link set will need to expand to match Frontend-Design's 8-link instructor nav.
- **CodeInsight-only features** — `LiveCDSPanel`, `IntegrityFlagBadge`, `CodeComparisonModal`, `EnrollStudentsModal`, `analytics/*` widgets, `charts/*`, `MicroConceptEngine` integration, hidden-test management UI, CDS report visualizations.
- **Real-API integration for student pages** — replace `MOCK_EXERCISES` and `MOCK_RADAR_DATA` with calls to `api.js` and `analyticsService.js`.
- **Real code execution in CodeEditor** — wire the editor to the real submission endpoint (currently lives in the `.bak` file).
- **Design tokens doc** — a formal token reference at `docs/superpowers/specs/2026-06-04-design-tokens.md`.
- **Production-hardening** — a11y audit, mobile-responsive pass on the new pages, Lighthouse check, error-boundary tightening.

## 8. Risks

| Risk | Mitigation |
|------|------------|
| `wouter` `Link` and `useRoute` imports leak into the new JSX | Search-and-replace audit in §7 validation step |
| `frontend/src/index.css` is missing a token Frontend-Design assumes (e.g., `--primary` accent) | Compare token lists; copy any missing HSL definitions from Frontend-Design's `index.css` if needed |
| The new pages accidentally import from `@/data/mockData` paths that don't exist in the live tree | All new imports go through `frontend/src/data/mockData.js` (the file we control) |
| Old student files linger after cutover and confuse the next slice | Explicit rename + delete step in validation; commit the deletions in a follow-up commit |
| "Mirror 1:1 with mocks" → user later feels the app is fake | Documented in §7; real-API integration is the first follow-up |

## 9. Success Criteria

- The student dashboard, exercise list, and code editor visually match Frontend-Design's `artifacts/codeinsight/src/pages/student/*` 1:1.
- Login, role-based redirects, and instructor pages continue to work exactly as before.
- `npm run build` passes with zero warnings.
- The diff is small, reviewable, and reversible (old student files kept in git history).
- A short follow-up roadmap is documented in §7.
