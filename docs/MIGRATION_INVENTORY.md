# Frontend-Design × CodeInsight — Migration Inventory

**Date:** 2026-06-04

## PHASE 1 — Inventory

### 1.1 Frontend-Design (`Frontend-Design/Frontend-Design/artifacts/codeinsight/`)
**App shell:**
- `src/main.tsx` — `createRoot` + `<App />`
- `src/App.tsx` — `wouter` `<Switch>` + `<Route>`, `QueryClientProvider` + `TooltipProvider`
- `src/components/layout/AppLayout.tsx` — sidebar + topbar wrapper
- `src/lib/auth.ts` — `getCurrentUser` / `login` / `logout` from `localStorage['codeinsight_user']`
- `src/lib/utils.ts` — `cn()` (clsx + tailwind-merge)
- `src/hooks/use-mobile.tsx`, `use-toast.ts`
- `src/data/mockData.ts` — types + `MOCK_USERS`, `MOCK_EXERCISES`, etc.

**Routes (17 total):**
- `/` → Landing
- `/login`, `/register`
- `/student/dashboard`, `/student/exercises`, `/student/exercises/:id`, `/student/profile`, `/student/progress`
- `/instructor/dashboard`, `/instructor/heatmap`, `/instructor/students`, `/instructor/students/:id`, `/instructor/exercises`, `/instructor/exercises/new`, `/instructor/exercises/:id/edit`, `/instructor/warnings`, `/instructor/reports`, `/instructor/violations`, `/instructor/integrity`

**UI primitives (60+):** accordion, alert-dialog, alert, aspect-ratio, avatar, badge, breadcrumb, button-group, button, calendar, card, carousel, chart, checkbox, collapsible, command, context-menu, dialog, drawer, dropdown-menu, empty, field, form, hover-card, input-group, input-otp, input, item, kbd, label, menubar, navigation-menu, pagination, popover, progress, radio-group, resizable, scroll-area, select, separator, sheet, sidebar, skeleton, slider, sonner, spinner, switch, table, tabs, textarea, toast, toaster, toggle-group, toggle, tooltip.

**Pages (1732 lines total):** all in `.tsx`, all use mock data. Routes use wouter. Auth is localStorage-only.

### 1.2 CodeInsight (current `frontend/`)
**Routes (15):** `/`, `/login`, `/instructor`, `/instructor/sections`, `/instructor/sections/:sectionId`, `/instructor/sections/:sectionId/academic-integrity`, `/instructor/create-exercise`, `/instructor/exercises/:id/edit`, `/instructor/alerts`, `/instructor/reports`, `/instructor/developer`, `/student`, `/student/exercises`, `/student/exercises/:exerciseId`, `/student/progress`, `*` → NotFound.

**Pages (13):** Landing, Login, NotFound, instructor/{Dashboard, Sections, SectionDetail, CreateExercise, EditExercise, ExerciseForm, Reports, Developer, Alerts, AcademicIntegrityFlags}, student/{ExerciseList, CodeEditor_new, Progress}.

**UI primitives (18):** alert, avatar, badge, button, card, dialog, dropdown-menu, input, label, scroll-area, select, separator, sheet, skeleton, table, tabs, textarea, tooltip. (Same shadcn pattern as design.)

**Auth:** `AuthContext` (localStorage `ci_token` + `ci_user`), `useAuth()`, `ProtectedRoute` in `App.jsx`.

**API:** `services/api.js` — axios + 401 interceptor → `/login`, Vite proxy `/api` → `http://localhost:5000`.

**State:** raw `useState`/`useEffect`, no React Query. Some pages poll on interval.

### 1.3 Feature Mapping Matrix

| Design feature | CodeInsight counterpart | Status | Migration action |
| --- | --- | --- | --- |
| Landing | `pages/Landing.jsx` | exists, design-aligned | keep current (already parity) |
| Login (mock role-pick) | `pages/Login.jsx` (real auth) | design is mock, current is real | keep current; port design layout |
| Register | none | new | port design (mock) — gated as low priority |
| Student Dashboard | `pages/student/ExerciseList.jsx` | exercises-with-CDS view | port design's Dashboard layout, use real `/api/student/exercises` + `/api/student/stats` |
| Student Exercises | `pages/student/ExerciseList.jsx` | merged with dashboard | split: list vs dashboard |
| Student CodeEditor | `pages/student/CodeEditor_new.jsx` | real Monaco + submission | keep current; port design's editorial chrome |
| Student Profile | none | new | port design (mock) — gated as low priority |
| Student Progress | `pages/student/Progress.jsx` | real `/api/analytics/my-scores` | port design's Progress layout, keep current data |
| Instructor Dashboard | `pages/instructor/Dashboard.jsx` | real `/api/analytics/sections/:id/longitudinal` | port design's Dashboard layout, keep current data |
| Instructor Heatmap | none | new | port design (mock heatmap) — gated as low priority |
| Instructor Students | `pages/instructor/Sections.jsx` | sections list | port design's Students layout, keep current API |
| Instructor StudentDetail | `pages/instructor/SectionDetail.jsx` | per-section detail | map design's URL params to current |
| Instructor Exercises | `pages/instructor/CreateExercise.jsx` + `EditExercise.jsx` + section-scoped list | split | port design's list layout |
| Instructor ExerciseForm | `pages/instructor/CreateExercise.jsx` | real form | port design's form layout |
| Instructor Warnings | `pages/instructor/Alerts.jsx` | real alerts | port design's Warnings layout, keep current API |
| Instructor Reports | `pages/instructor/Reports.jsx` | real reports | port design's Reports layout, keep current data |
| Instructor Violations | none | new | port design (mock) — gated as low priority |
| Instructor Integrity | `pages/instructor/AcademicIntegrityFlags.jsx` | real flags | port design's Integrity layout, keep current API |

**Net new pages design has that CodeInsight doesn't:**
- Register (mock)
- Student Profile (mock)
- Instructor Heatmap (mock)
- Instructor Violations (mock)

These are all design-only / mock data. To add them with real backend would be new product features, not migration.

**CodeInsight features not in design:**
- `/instructor/sections/:id/academic-integrity` (sub-route) → preserved in current
- `/instructor/developer` → preserved in current
- Auto-grading, hidden tests, CDS job queue, integrity engine → all backend, not visible in design

### 1.4 Preservation Contract (must NOT change)
- 50+ backend API endpoints
- `AuthContext` + `ProtectedRoute` + RBAC
- `services/api.js` (axios + 401 interceptor)
- CDS formula
- Real data flows in: Progress, Alerts, AcademicIntegrityFlags, Reports, ExerciseList, CodeEditor, Dashboard, Sections, SectionDetail, CreateExercise, EditExercise

### 1.5 Migration Delta

| Layer | Direction | Risk |
| --- | --- | --- |
| Routing | keep react-router-dom, port wouter pages | LOW |
| Language | `.tsx` → `.jsx` strip types | LOW |
| Data fetching | design's mock → current API; add React Query selectively | MED |
| Auth | design's localStorage `codeinsight_user` → current `AuthContext` | LOW (don't import design's `lib/auth`) |
| Layout | design's `AppLayout` (sidebar + topbar) → current `Layout` + `Sidebar` | MED (SidebarContext must survive) |
| UI primitives | design's 60+ → current's 18 — fill the gap | MED (need to copy 42 more primitives) |
| Build config | design's Replit env-var Vite → current's plain Vite | LOW (drop Replit plugins) |
