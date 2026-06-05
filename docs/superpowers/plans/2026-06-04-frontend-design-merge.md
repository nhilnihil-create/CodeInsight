# CodeInsight Frontend Design Merge Plan

**Date:** 2026-06-04
**Status:** Ready for execution
**Goal:** Merge visual design from `Frontend-Design/Frontend-Design/artifacts/codeinsight/` into the live `frontend/src/` while preserving all CodeInsight functionality.

**Architecture:**
- Adopt the design's Tailwind v4 HSL color tokens (light/dark mode, sidebar, card, destructive variants)
- Adopt Plus Jakarta Sans + JetBrains Mono typography
- Keep the existing react-router-dom routing (do NOT switch to wouter)
- Keep the existing AuthContext (do NOT switch to mock auth)
- Keep the existing API integrations (axios/api.js, services)
- Replace the layout shell, login page, and add a landing page using the design's visual language
- Add missing UI components (alert, dialog, select, table, tabs, sheet, dropdown-menu, sidebar, separator, scroll-area, textarea, avatar) used by the design
- Update the two dashboard pages (instructor, student) to use design cards with real data
- Preserve every existing route; map design routes to existing CodeInsight routes

**Tech Stack:**
- React 18 + Vite 5
- Tailwind CSS v4 (already in use, design uses same)
- shadcn/ui-style components (Radix UI primitives)
- react-router-dom v6 (preserve)
- TanStack React Query (preserve)
- axios (preserve)

---

## PHASE 2 — Files Map

### Files to REPLACE (content from design, structure preserved)

| Path | Reason |
|------|--------|
| `frontend/src/index.css` | New HSL color tokens, Plus Jakarta Sans typography, design's Tailwind v4 theme block |
| `frontend/src/components/Layout.jsx` | Switch to design's sidebar + main flex pattern (uses wouter; rewrite to react-router) |
| `frontend/src/pages/Login.jsx` | Match design's card-based role login but keep real auth |
| `frontend/src/pages/instructor/Dashboard.jsx` | Use design's card grid layout with real API data |
| `frontend/src/pages/student/ExerciseList.jsx` | Use design's card pattern (renamed role 'dashboard' page) |

### Files to ADD (new components from design, ported to react-router)

| Path | Reason |
|------|--------|
| `frontend/src/components/ui/alert.jsx` | Design uses this for dashboard destructive alerts |
| `frontend/src/components/ui/dialog.jsx` | Design's modal pattern |
| `frontend/src/components/ui/select.jsx` | Forms |
| `frontend/src/components/ui/table.jsx` | Data tables |
| `frontend/src/components/ui/tabs.jsx` | Tabbed sections |
| `frontend/src/components/ui/sheet.jsx` | Side panels |
| `frontend/src/components/ui/dropdown-menu.jsx` | Header menus |
| `frontend/src/components/ui/separator.jsx` | Visual divider |
| `frontend/src/components/ui/scroll-area.jsx` | Scrollable areas |
| `frontend/src/components/ui/textarea.jsx` | Forms |
| `frontend/src/components/ui/avatar.jsx` | User avatars |
| `frontend/src/pages/Landing.jsx` | Public landing page |
| `frontend/src/components/Sidebar.jsx` | Replace with design's sidebar pattern |

### Files to MODIFY (preserve, just adjust imports/visuals if needed)

- `frontend/src/App.jsx` — Add `/` route for Landing page
- All other page files — Touch only if design components require it

### Files NOT to change (preserved 100%)

- All `services/`, `api/`, `context/AuthContext.jsx`, `hooks/`, `lib/utils.js`
- `pages/instructor/Sections.jsx`, `SectionDetail.jsx`, `CreateExercise.jsx`, `EditExercise.jsx`, `ExerciseForm.jsx`, `Alerts.jsx`, `AcademicIntegrityFlags.jsx`, `Developer.jsx`, `Analytics.jsx`, `Reports.jsx`
- `pages/student/Exercises.jsx`, `CodeEditor_new.jsx`, `Progress.jsx`
- `components/analytics/*` (CDS reports, integrity, etc.)
- `components/ErrorBoundary.jsx`, `CodeComparisonModal.jsx`, `EnrollStudentsModal.jsx`, `LiveCDSPanel.jsx`, `IntegrityFlagBadge.jsx`

### Risks

1. **Lucide-react icon set** — Design uses lucide-react; current frontend has it (v1.17). May need to check icon name availability.
2. **Tailwind v4** — Both use v4. No migration needed.
3. **CSS class divergence** — Design's `bg-destructive/5`, `text-muted-foreground`, `bg-card`, etc. need to be defined in our theme.
4. **Wouter vs react-router** — Design uses wouter; current uses react-router. Port all design pages/components to react-router (or use wouter hooks via simple wrappers).
5. **Radar chart from recharts** — Verify recharts RadarChart works in our version.

### Route Mapping (design → current)

| Design route | Current route | Note |
|--------------|---------------|------|
| `/` | `/` (new Landing) | Add new public route |
| `/login` | `/login` | Replace component, keep real auth |
| `/register` | (none) | Design has it; we don't — skip |
| `/student/dashboard` | `/student` (ExerciseList) | Map to existing |
| `/student/exercises` | `/student/exercises` | Map to existing |
| `/student/exercises/:id` | `/student/exercises/:exerciseId` | Map to existing |
| `/student/profile` | (none) | Skip (no profile page) |
| `/student/progress` | `/student/progress` | Map to existing |
| `/instructor/dashboard` | `/instructor` | Map to existing |
| `/instructor/heatmap` | (none) | Map to Analytics |
| `/instructor/students` | (none) | Map to SectionDetail list |
| `/instructor/students/:id` | (none) | Skip |
| `/instructor/exercises` | (none) | Map to existing CreateExercise |
| `/instructor/exercises/new` | `/instructor/create-exercise` | Map |
| `/instructor/exercises/:id/edit` | `/instructor/exercises/:id/edit` | Map to existing |
| `/instructor/warnings` | `/instructor/alerts` | Map |
| `/instructor/reports` | `/instructor/reports` | Map to existing |
| `/instructor/violations` | `/instructor/alerts` | Map to same page |
| `/instructor/integrity` | `/instructor/sections/:id/academic-integrity` | Map |

### Execution Order

1. Update `index.css` with new theme tokens and font imports
2. Add missing shadcn/ui components (alert, dialog, select, table, tabs, sheet, dropdown-menu, separator, scroll-area, textarea, avatar)
3. Update `components/Sidebar.jsx` to use design pattern
4. Update `components/Layout.jsx` to use design's flex shell with new sidebar
5. Add `pages/Landing.jsx` public landing page
6. Update `pages/Login.jsx` with design styling + real auth
7. Update `pages/instructor/Dashboard.jsx` with design cards + real data
8. Update `pages/student/ExerciseList.jsx` with design cards + real data
9. Update `App.jsx` to add `/` route
10. Build, fix errors, verify

