# Frontend-First Instructor Slice — Design

**Date:** 2026-06-04
**Author:** Claude + Nihil
**Status:** Draft (awaiting user review)
**Builds on:** `2026-06-04-frontend-first-migration-design.md` (full migration plan) and the student slice that is already merged on `feature/cds-auto-trigger`.
**Goal:** Port the 10 Frontend-Design instructor pages to the CodeInsight frontend, with mock data, leaving a one-import-swap path to real APIs.

---

## 1. Goal & Scope

**In scope:**

1. Port 10 instructor pages from `Frontend-Design/Frontend-Design/artifacts/codeinsight/src/pages/instructor/*.tsx` into `frontend/src/pages/instructor/*.jsx`.
2. Re-point 10 existing CodeInsight instructor routes (in `frontend/src/App.jsx`) so they resolve to the new design-aligned pages, with the **design paths canonical** and the **old CodeInsight paths kept as aliases**.
3. Add the missing instructor nav links to `frontend/src/components/Sidebar.jsx` so the design's 8-link nav is reachable from the existing shell.
4. Extend `frontend/src/data/mockData.js` with the additional instructor-only mock constants needed for the new pages.
5. **Keep** the existing `frontend/src/components/analytics/*` components and the `ResponsiveLineChart` chart. **Embed** each of them inside a `<Card>`/`<CardHeader>`/`<CardContent>` shell on the new design page that is the natural home for its content, with its existing CSS file untouched.
6. **Keep** `frontend/src/pages/instructor/Developer.jsx` as a CodeInsight-only page (it is in the existing nav and has no design equivalent). The remaining 8 CodeInsight-only pages (`Sections`, `SectionDetail`, `CreateExercise`, `EditExercise`, `Alerts`, `AcademicIntegrityFlags`, `Reports`, plus the deleted `Analytics.jsx`) are removed once their replacement is in place.

**Out of scope:**

- Real API calls in this slice — all new pages read from `MOCK_*` constants.
- Unit tests, E2E tests, or a new testing framework.
- Accessibility audit beyond what the shadcn primitives already provide.
- Backend changes (CDS engine, integrity engine, schema, etc. are untouched).
- New design pages for student/login/landing (covered in prior slice).
- Mock data for the student dashboard / exercises / code editor (already in place).

**Non-goals (explicitly not in scope for this slice):**

- We are NOT going to refactor the existing `analytics/*` components into a different shape — embedding them in a Card shell is a layout, not a code, change.
- We are NOT going to expose the `analytics/*` components outside their new host pages.
- We are NOT going to re-style the `analytics/*` components to match the design tokens; the existing CSS files stay as-is. This is deliberate: those components already use shadcn primitives, and the Card wrapper provides the visual frame.

---

## 2. Architecture

### 2.0 Two cross-cutting additions

In addition to the 10 instructor pages, this slice ships two cross-cutting concerns that apply to both student and instructor routes:

1. **3-theme toggle** — a 3-way theme switcher (light = current Frontend-Design, dark teal = pre-design CodeInsight palette reconstructed from git history, PSU = maroon + gold + white) accessible from the top-right of every page. Persisted to `localStorage` only.
2. **Monaco code editor restoration** — replace the `<textarea>` in `frontend/src/pages/student/CodeEditor.jsx` with `@monaco-editor/react`, registering 3 Monaco themes (one per app theme) so the editor's chrome matches the page chrome.

These are scoped here in the same spec because the user requested them in the same conversation as the instructor-slice brainstorm. They are independent of the 10 instructor pages and could be sliced out into their own plans; doing it together keeps the UI coherent (theme toggle ships with the redesigned pages, Monaco ships while the CodeEditor is being touched in scope of the student code editor work).

### 2.1 Porting pattern (proven in student slice)

The instructor slice mirrors the student slice's TSX→JSX port pattern exactly:

| Design (TS) | CodeInsight (JSX) |
| --- | --- |
| `wouter` (`useRoute`, `useLocation`, `<Link href>`) | `react-router-dom` v6 (`useParams`, `useNavigate`, `<Link to>`, `<NavLink>`) |
| `export default function X()` | `export default function X()` (same) |
| `import type { ... }` / TS interfaces | JSDoc typedefs (not needed; we use plain object literals) |
| Extensionless imports, `@/...` alias | Extensionless imports, `@/...` alias (already configured in `vite.config.js`) |
| `<Card>`, `<Table>`, `<Badge>`, `<Button>` from `@/components/ui/*` | Same components (already exist in `frontend/src/components/ui/*`) |
| Recharts `<RadarChart>`, `<LineChart>`, `<BarChart>` | Same (Recharts is already a dependency) |
| `lucide-react` icons | Same |

This is a 1:1 mechanical port for ~90% of each file. The only judgment calls are:

- `useRoute("/instructor/exercises/:id/edit")` → read `useParams().id` and decide "edit mode" if the param is present and not `"new"`.
- `<Link href>` → `<Link to>` (and the `asChild` Button pattern works unchanged because shadcn's Button is a `React.forwardRef` slot).
- `onClick={() => setLocation("/x")}` → `onClick={() => navigate("/x")}`.

### 2.2 Data boundary

`frontend/src/data/mockData.js` is the **single source of truth** for every page in this slice. Each page imports only the constants it needs. A real-API cutover is a 2-line change per page:

```jsx
// before
import { MOCK_EXERCISES } from '@/data/mockData';
// after
import { fetchExercises } from '@/api/exercises';

// inside the component
const [exercises, setExercises] = useState([]);
useEffect(() => { fetchExercises().then(setExercises); }, []);
```

This is the same contract the student slice used.

### 2.3 Analytics embedding strategy

The existing `frontend/src/components/analytics/*` components (`ClassMisconceptionReport`, `ClassWideLongitudinalChart`, `ExerciseAccordion`, `IntegrityFlagDropdown`, `IntegrityMonitoringBanner`, `LongitudinalProgressChart`, `LongitudinalTab`, `MicroConceptAlertCard`, `StudentAlertCard`) and the orphan `frontend/src/components/charts/ResponsiveLineChart` are already-written visualizations. They are consumed by the OLD `SectionDetail.jsx` and `AcademicIntegrityFlags.jsx`, both of which are being deleted in this slice.

Rather than delete these components, we **re-home each one on a new design page that is its semantic home**, wrapped in a Card shell. The component's existing CSS file is loaded unchanged. The new design page imports the component directly, places it inside `<Card>`, and the host page's Card frame + header provide the visual identity. This preserves the work that's already in those files, makes the new design pages genuinely data-rich (rather than a single visualization per page), and gives us a single place to wire up real data later.

| Existing analytics component | New design page (host) |
| --- | --- |
| `ClassMisconceptionReport` | `InstructorDashboard` (under the "Class Concept Averages" bar list) |
| `MicroConceptAlertCard` | `StudentDetail` (in the "Micro-Concept Insights" column) |
| `LongitudinalProgressChart` | `StudentDetail` (replacing the inline recharts `<LineChart>`) |
| `ExerciseAccordion` | `InstructorExercises` (replacing the simple table rows with a richer per-exercise panel) |
| `IntegrityFlagDropdown` | `Integrity` (alongside the existing flag list, as the per-flag review action) |
| `IntegrityMonitoringBanner` | `Integrity` (at the top of the page, as a status banner) |
| `LongitudinalTab` | `Reports` (as one of the period tabs) |
| `ClassWideLongitudinalChart` | `Reports` (replacing the inline recharts `<LineChart>` for the class-average trend) |
| `StudentAlertCard` | `Warnings` (replacing the simple `Card` rows with the richer alert card) |
| `charts/ResponsiveLineChart` | `Reports` (replacing the recharts `<LineChart>` for class-average trend OR used by the `LongitudinalProgressChart` if it isn't already self-contained) |

The new design pages also keep the simpler inline visualizations (RadarChart, BarChart, heatmap table) that don't have an existing analytics-component equivalent, because writing a wrapper just to call Card around a one-off recharts component would be make-work.

**Embedding pattern (uniform):**

```jsx
import ClassMisconceptionReport from '@/components/analytics/ClassMisconceptionReport';
// ... inside the page:
<Card>
  <CardHeader>
    <CardTitle>Class Misconceptions</CardTitle>
  </CardHeader>
  <CardContent>
    <ClassMisconceptionReport sectionId={sectionId} />
  </CardContent>
</Card>
```

The component's existing CSS file (`ClassMisconceptionReport.css`, etc.) is imported in the **host page's** imports (or, if the host page doesn't import it, we add a one-line `import './ClassMisconceptionReport.css';` to the host page). The component file itself is not edited.

### 2.4 Theme system architecture

The app supports **3 themes** switched at runtime by a top-right toggle:

| Key | Name | Description |
| --- | --- | --- |
| `light` | Light (default) | The current Frontend-Design palette, expressed in `index.css` as `:root` CSS custom properties |
| `dark` | Dark teal | The pre-design CodeInsight palette reconstructed from commits `b4016ff` (Sidebar) and `62fa4cd` (index.css) |
| `psu` | Pampanga State University | Maroon primary (`#7B0F1B`), gold accent (`#FFC72C`), white background |

**Mechanism:** A `<html data-theme="...">` attribute, plus theme-scoped CSS custom properties. We extend the existing `index.css` shadcn token block with theme-specific overrides:

```css
:root { /* light (default) — unchanged */
  --background: 0 0% 100%;
  --foreground: 222 47% 11%;
  /* ... current tokens ... */
}

[data-theme="dark"] {
  --background: 224 53% 8%;   /* #0c1220 */
  --foreground: 215 32% 86%;  /* #dce8f5 */
  --card: 222 39% 13%;        /* #131d30 */
  --card-foreground: 215 32% 86%;
  --primary: 176 50% 67%;     /* #85D2D0 teal */
  --primary-foreground: 224 53% 8%;
  --muted: 218 36% 27%;       /* #1a2640 */
  --muted-foreground: 213 24% 56%;  /* #6a85a8 */
  --border: 213 41% 22%;      /* #1e304d */
  --sidebar: 240 24% 9%;      /* #0f0f1a */
  --sidebar-border: 240 17% 24%;  /* #2e2e4a */
  /* secondary tokens (--accent, --destructive, --ring) get parallel overrides */
}

[data-theme="psu"] {
  --background: 0 0% 100%;
  --foreground: 350 78% 27%;  /* maroon #7B0F1B */
  --card: 0 0% 100%;
  --card-foreground: 350 78% 27%;
  --primary: 350 78% 27%;     /* maroon */
  --primary-foreground: 0 0% 100%;
  --accent: 45 100% 59%;      /* gold #FFC72C */
  --accent-foreground: 350 78% 27%;
  --border: 350 30% 80%;
  --sidebar: 350 78% 27%;     /* maroon sidebar */
  --sidebar-foreground: 0 0% 100%;
  --sidebar-border: 350 50% 35%;
  --sidebar-primary: 45 100% 59%;
  --sidebar-primary-foreground: 350 78% 27%;
}
```

Every shadcn primitive already references these tokens (`bg-background`, `text-foreground`, `bg-card`, `bg-sidebar`, etc.), so no page JSX needs to change. Components like the `Sidebar.jsx` background (`bg-sidebar`) and the destructive badge (`bg-destructive`) automatically re-skin.

**State management:** a tiny `useTheme()` hook (in `frontend/src/lib/theme.js`) reads/writes a single `localStorage` key `codeinsight:theme`, defaults to `light`, and writes the value to `<html data-theme>` on mount + on change.

**Default:** `light` (the Frontend-Design blue palette the student slice is already on). This means the toggle is the only thing the user has to touch to see the new themes; nothing else changes by default.

**First-load behavior:** `useTheme()` synchronously reads `localStorage.getItem('codeinsight:theme')` inside a `useLayoutEffect` (so there's no flash of the wrong theme on refresh). If the value is missing or unrecognized, the default is `light` and no `data-theme` attribute is set — meaning `:root` tokens apply, which IS the light theme. (No migration story needed; the first release ships with the toggle and users who haven't picked a theme are unaffected.)

**Role-switching:** the theme is per-browser, not per-user. When a user logs out and back in (or switches between a student and instructor account in the same browser), the theme persists. The login page is the only page that doesn't show the toggle (it has its own layout).

**Monaco integration:** `frontend/src/lib/monacoThemes.js` registers 3 Monaco themes (`ci-light`, `ci-dark-teal`, `ci-psu`) via `monaco.editor.defineTheme()`. The `CodeEditor` page uses a `useEffect` that watches the `useTheme()` value and calls `monaco.editor.setTheme()` to swap. Monaco theme tokens are independent of the CSS custom properties (Monaco doesn't read CSS vars at runtime), so the 3 Monaco themes are hand-mapped in JS to mirror the 3 app palettes.

### 2.5 Per-page edit boundaries

- **In scope of the instructor-slice touches:** `Layout.jsx` (add `<ThemeToggle />` to the sticky top bar), `index.css` (add 2 theme-scoped blocks), `App.jsx` (`<ThemeProvider>` wrap), and the 10 new/overwritten instructor pages.
- **In scope of the Monaco touches:** `CodeEditor.jsx` (replace `<textarea>` with Monaco, port the legacy's feature set), plus 1 new `monacoThemes.js` file. No other page uses Monaco.
- **Untouched by this slice but living in the same project:** all `analytics/*` components, the existing instructor-only `Developer.jsx`, the student `Dashboard.jsx`/`Exercises.jsx` (which the slice inherits from the prior session), and the login/landing pages.

---

## 3. Per-Page Port Matrix

All paths are relative to `frontend/src/`. New files are created; old files are deleted at the end (last task) after smoke tests pass.

| # | New file (design visual) | Replaces | LOC (TSX) | Embeds existing analytics |
| --- | --- | --- | --- | --- |
| 1 | `pages/instructor/Dashboard.jsx` (overwrite) | `pages/instructor/Dashboard.jsx` (current) | 114 | `ClassMisconceptionReport`, `IntegrityMonitoringBanner` |
| 2 | `pages/instructor/Heatmap.jsx` | (no direct equivalent — `SectionDetail.jsx` has the closest, but is a different page) | 89 | none |
| 3 | `pages/instructor/Students.jsx` | `pages/instructor/Sections.jsx` | 93 | none |
| 4 | `pages/instructor/StudentDetail.jsx` | `pages/instructor/SectionDetail.jsx` (when navigated to a specific student) | 128 | `MicroConceptAlertCard`, `LongitudinalProgressChart` |
| 5 | `pages/instructor/Exercises.jsx` | `pages/instructor/CreateExercise.jsx` (the list) | 81 | `ExerciseAccordion` |
| 6 | `pages/instructor/ExerciseForm.jsx` | `pages/instructor/CreateExercise.jsx` (the form) + `EditExercise.jsx` | 158 | none |
| 7 | `pages/instructor/Warnings.jsx` | `pages/instructor/Alerts.jsx` | 74 | `StudentAlertCard` |
| 8 | `pages/instructor/Reports.jsx` | `pages/instructor/Reports.jsx` (current) | 100 | `ClassWideLongitudinalChart`, `LongitudinalTab`, `charts/ResponsiveLineChart` |
| 9 | `pages/instructor/Violations.jsx` | (no direct equivalent — closest is a section in `SectionDetail.jsx`) | 65 | none |
| 10 | `pages/instructor/Integrity.jsx` | `pages/instructor/AcademicIntegrityFlags.jsx` | 88 | `IntegrityFlagDropdown`, `IntegrityMonitoringBanner` |
| 11 | `pages/student/CodeEditor.jsx` (overwrite — Monaco) | `pages/student/CodeEditor.jsx` (current `<textarea>` version, ported in the student slice) | 473 (ported from legacy commit `62fa4cd`) | none |

**Total LOC to port:** ~990 instructor lines (TSX → JSX) + 473 student lines (Monaco port from legacy).

**Net file count change:** +1 student page (CodeEditor.jsx is overwritten in place — no rename). The 10 instructor pages net to 0 (10 new, 10 old deleted).

**Net route count change:** 0 (the 10 design-aligned routes replace the 10 CodeInsight routes; old paths kept as aliases).

**`Developer.jsx` is untouched** and stays on its existing `/instructor/developer` route.

### 3.1 Monaco code editor scope (row 11)

The student `CodeEditor.jsx` is the only page in this slice that uses a code editor, and the user has requested Monaco over the current `<textarea>`. We port the legacy implementation from commit `62fa4cd` (473 lines), preserving its feature set faithfully:

**Carried over from legacy:**
- 2-tab output panel: **Output** (per-test stdout/stderr) and **Compiler Log** (parsed error blocks with code-context highlighting and click-to-jump-to-line).
- **Run** and **Submit** buttons in the top-right of the editor, with a **Stop** button that fires during an in-flight run via `AbortController`.
- **Deadline countdown** in the page header (only when the exercise has a `deadline`), ticking down every second.
- **Attempt history** list below the output panel (most recent first).
- **Per-line error highlighting** in the editor: when a compiler error is reported at line N, the editor reveals the line, sets the cursor there, and `setHighlightedLine(N)` adds a translucent red overlay.
- **Editor ref** (`editorRef`) so the parent can call `revealLineInCenter` / `setPosition` from the error-block click handler.
- **Space Mono** monospace font for the terminal output panel.

**Replaced from the textarea version (current student-slice file):**
- The VS Code-style dark `<div>` chrome + plain `<Textarea>` → `<Editor>` from `@monaco-editor/react` with `theme="ci-light"` / `"ci-dark-teal"` / `"ci-psu"` (the Monaco theme name tracks the app theme — see §2.4).
- The two `<Button>` rows become a single compact row with `Run` / `Submit` / `Stop` based on `running` / `submitting` state.
- The mock stdout rendering (from `MOCK_EXERCISES[i].testCases`) stays — the editor's value is the same React state, so the "Run" mock handler just reads the same `code` state and renders the same per-test output.

**Carried over from the student-slice file:**
- The two-panel layout (left: description + test cases, right: editor + output).
- The `useParams().exerciseId` lookup against `MOCK_EXERCISES`.
- The "✓ All tests passed" submission banner.
- The shadcn `Card` shell around the left panel (matches the design's information architecture).

**New in this slice (Monaco-specific):**
- `onMount` callback that stashes the Monaco editor instance in `editorRef.current` for the error-jump handler.
- `onChange` callback that updates the same `code` state the textarea used.
- A second `useEffect` that watches `useTheme()` and calls `monaco.editor.setTheme()` to swap Monaco themes live (the toggle works mid-edit without re-mounting the editor).

**Out of scope (kept simple):**
- Multi-language support: the editor is hard-coded to `language="cpp"`. All current `MOCK_EXERCISES` are C++, and a language picker would be a follow-up slice.
- Per-exercise stored language: same as above.
- Live collaboration / shared cursors / language server: not in the legacy, not in the new scope.

---

## 4. Routes

### 4.1 Design paths (canonical)

These are the URLs the new pages own. They are the first match in `App.jsx`.

| Path | Component | pageTitle |
| --- | --- | --- |
| `/instructor/dashboard` | `InstructorDashboard` | `Dashboard` |
| `/instructor/heatmap` | `InstructorHeatmap` | `Class Heatmap` |
| `/instructor/students` | `InstructorStudents` | `Students` |
| `/instructor/students/:id` | `InstructorStudentDetail` | `Student Detail` |
| `/instructor/exercises` | `InstructorExercises` | `Exercises` |
| `/instructor/exercises/new` | `InstructorExerciseForm` (mode=new) | `New Exercise` |
| `/instructor/exercises/:id/edit` | `InstructorExerciseForm` (mode=edit) | `Edit Exercise` |
| `/instructor/warnings` | `InstructorWarnings` | `Early Warnings` |
| `/instructor/reports` | `InstructorReports` | `Reports` |
| `/instructor/violations` | `InstructorViolations` | `Structure Violations` |
| `/instructor/integrity` | `InstructorIntegrity` | `Academic Integrity` |
| `/instructor/developer` | `InstructorDeveloper` (existing, untouched) | `Developer` |

### 4.2 CodeInsight paths (kept as aliases)

These are the URLs the OLD pages owned. We keep them as thin aliases so that bookmarks, links from emails, and the existing nav history don't 404. The 4 examples below are the ones the existing CodeInsight shell already exposes; the rest exist for any external link. **This is unchanged from the student slice's policy.**

| Old CodeInsight path | New target | pageTitle |
| --- | --- | --- |
| `/instructor` | `InstructorDashboard` | `Dashboard` |
| `/instructor/sections` | `InstructorStudents` | `Students` |
| `/instructor/sections/:sectionId` | `InstructorStudents` (no section → list view) | `Students` |
| `/instructor/sections/:sectionId/academic-integrity` | `InstructorIntegrity` | `Academic Integrity` |
| `/instructor/create-exercise` | `InstructorExerciseForm` (mode=new) | `New Exercise` |
| `/instructor/exercises/:id/edit` | `InstructorExerciseForm` (mode=edit) | `Edit Exercise` |
| `/instructor/alerts` | `InstructorWarnings` | `Early Warnings` |
| `/instructor/reports` | `InstructorReports` | `Reports` |
| `/instructor/my-sections` | `InstructorStudents` | `Students` |

The `pageTitle` for the alias routes is the same as the canonical route, so the sticky top bar reads consistently regardless of which URL the user lands on.

### 4.3 The 4 currently-broken alias routes

Today, the existing `App.jsx` has 4 broken routes that point old paths at the wrong page:

- `/instructor/integrity` → `AcademicIntegrityFlags` (should be `InstructorIntegrity` after the port)
- `/instructor/warnings` → `InstructorAlerts` (will become `InstructorWarnings` after the port)
- `/instructor/violations` → `AcademicIntegrityFlags` (should be `InstructorViolations`)
- `/instructor/students` → `InstructorSections` (should be `InstructorStudents`)

The cutover in Task 10 fixes all four. The student-slice report had a "currently mis-wired" caveat for the same reason — that pattern is now retired.

---

## 5. Components

### 5.1 Sidebar — add 2 missing nav items

`frontend/src/components/Sidebar.jsx` already has 7 instructor links. The design's nav has 8. The 2 missing are:

- **Heatmap** (`LayoutGrid` icon) — `/instructor/heatmap`
- **Violations** (`AlertOctagon` icon) — `/instructor/violations`

After the slice, `instructorLinks` becomes:

```js
const instructorLinks = [
  { to: '/instructor/dashboard', label: 'Dashboard', icon: LayoutDashboard, end: true },
  { to: '/instructor/heatmap', label: 'Heatmap', icon: LayoutGrid },
  { to: '/instructor/students', label: 'Students', icon: ListChecks, end: true },
  { to: '/instructor/exercises', label: 'Exercises', icon: PlusSquare },
  { to: '/instructor/warnings', label: 'Warnings', icon: Bell },
  { to: '/instructor/reports', label: 'Reports', icon: FileBarChart2 },
  { to: '/instructor/violations', label: 'Violations', icon: AlertOctagon },
  { to: '/instructor/integrity', label: 'Integrity', icon: ShieldAlert },
  { to: '/instructor/developer', label: 'Developer', icon: Settings },
];
```

The `My Sections` link is renamed to `Students` and its `end: true` is added (so `/instructor/students/:id` doesn't light up the parent item). `Create Exercise` becomes `Exercises` (the new list page IS the create-entry-point, matching the design). The existing Tooltip / `NavLink` / role-filtering contract is unchanged.

### 5.2 Existing analytics components — used unchanged

The 9 analytics components in `frontend/src/components/analytics/*` and the 1 chart in `frontend/src/components/charts/ResponsiveLineChart` are imported as-is by their new host pages. No JSX, CSS, or prop changes in this slice. Their existing `useEffect`/fetch logic continues to hit their existing API endpoints (or returns empty/mock data when offline) — we do NOT cut them over to mocks in this slice. They will simply render their existing data or empty state, framed by the new Card.

### 5.3 New mockData.js exports (instructor-side only)

The student slice already added `MOCK_USERS`, `MOCK_EXERCISES`, `MOCK_RADAR_DATA`, plus the `Role` enum. The instructor slice adds:

| Export | Type | Used by | Notes |
| --- | --- | --- | --- |
| `MOCK_STUDENT_STATS` | `Array<{ studentId, avgCds, highestConcept, lastActiveDays, hasAlert }>` | `InstructorStudents` (the table's stats columns) | One entry per `MOCK_USERS` student |
| `MOCK_HEATMAP` | `Array<{ studentId, scores: Record<ConceptTag, number> }>` | `InstructorHeatmap` | Mirrors the design's `generateHeatmapData()` output, but deterministic |
| `MOCK_INTEGRITY_FLAGS` | `Array<{ id, studentId, exerciseId, type, description, confidence, time }>` | `InstructorIntegrity` | 4 entries matching the design's `flags` array |
| `MOCK_STRUCTURE_VIOLATIONS` | `Array<{ id, studentId, exerciseId, concept, type, message, severity, time }>` | `InstructorViolations` | 4 entries matching the design's `violations` array |
| `MOCK_REPORTS_TIMELINE` | `Array<{ week, avgCds, highRiskStudents }>` | `InstructorReports` | 5 weeks of class-average + high-risk data |
| `MOCK_MOST_DIFFICULT_CONCEPTS` | `Array<{ concept, score }>` | `InstructorReports` | 4 concepts with their avg CDS |

**Total:** ~70 lines added to `mockData.js` (6 new exports, not 7 — see note on `MOCK_SECTIONS` below). The existing 3 exports and 2 enum entries stay unchanged. No exports are removed.

**`MOCK_SECTIONS` is NOT added.** The 9 existing analytics components self-fetch from the real backend via `services/api` — they do not look up sections from `mockData.js`. Adding `MOCK_SECTIONS` would be dead code in this slice. If a future slice needs section data for the host pages, it can be added then.

### 5.4 PageTitle (sticky top bar)

The existing `Layout` component accepts an optional `pageTitle` prop and renders it in a sticky `bg-card/80` header. All 10 new pages pass `pageTitle` to `ProtectedRoute` so the header reads "Dashboard", "Students", etc. — matching the design's `<h1>` content. The mapping is in the routes table in §4.1.

The sticky top bar is also where the **theme toggle** (next section) lives, anchored to the right of the `pageTitle`.

### 5.5 ThemeToggle (top-right of every page)

A new `frontend/src/components/ThemeToggle.jsx` component renders in the sticky top bar of `Layout`. It's a 3-button segmented control with a sun/moon/PSU-shield icon for each option. Visual style matches the shadcn `Button` `variant="outline"` with `size="sm"`, plus an `aria-pressed` for the active theme.

```jsx
<button
  aria-label="Theme: Light"
  aria-pressed={theme === 'light'}
  onClick={() => setTheme('light')}
  className={cn(
    'h-8 w-8 rounded-md border border-border bg-card hover:bg-muted',
    theme === 'light' && 'ring-2 ring-primary'
  )}
>
  <Sun className="h-4 w-4" />
</button>
<button aria-label="Theme: Dark teal" aria-pressed={theme === 'dark'} onClick={() => setTheme('dark')} … >
  <Moon className="h-4 w-4" />
</button>
<button aria-label="Theme: PSU" aria-pressed={theme === 'psu'} onClick={() => setTheme('psu')} … >
  <Shield className="h-4 w-4" />
</button>
```

The toggle calls `useTheme().setTheme(key)`, which:
1. Writes `localStorage.setItem('codeinsight:theme', key)`.
2. Sets `document.documentElement.setAttribute('data-theme', key)` (or removes the attribute when `key === 'light'`, the default).
3. Updates the in-memory `theme` state (so consumers like Monaco re-render).

**Layout integration:** `Layout.jsx` adds `<ThemeToggle />` as a sibling of the `pageTitle` `<h1>`, justified to the right via a flex container:

```jsx
<header className="sticky top-0 z-30 border-b border-border bg-card/80 px-6 py-4 backdrop-blur">
  <div className="flex items-center justify-between gap-4">
    <h1 className="text-xl font-semibold tracking-tight text-foreground">{pageTitle}</h1>
    <ThemeToggle />
  </div>
</header>
```

**No new dependencies.** `lucide-react` (Sun, Moon, Shield) is already a dependency; `cn` is already exported from `frontend/src/lib/utils.js`.

### 5.6 Monaco theme registration

A new `frontend/src/lib/monacoThemes.js` exports a `registerMonacoThemes()` function that calls `monaco.editor.defineTheme()` three times. The themes follow Monaco's documented token schema (base colors + `tokenColors` array).

```js
// sketch — the plan's implementation task fills in the full color array
export function registerMonacoThemes(monaco) {
  monaco.editor.defineTheme('ci-light', {
    base: 'vs',
    inherit: true,
    rules: [
      { token: 'comment', foreground: '6a737d', fontStyle: 'italic' },
      { token: 'keyword', foreground: 'd73a49' },
      { token: 'string', foreground: '032f62' },
      { token: 'number', foreground: '005cc5' },
    ],
    colors: {
      'editor.background': '#ffffff',
      'editor.foreground': '#24292e',
    },
  });
  monaco.editor.defineTheme('ci-dark-teal', {
    base: 'vs-dark',
    inherit: true,
    rules: [/* … */],
    colors: {
      'editor.background': '#0a1018',
      'editor.foreground': '#dce8f5',
      'editorLineNumber.foreground': '#3a4860',
      'editorCursor.foreground': '#85D2D0',
      'editor.selectionBackground': '#1e304d',
    },
  });
  monaco.editor.defineTheme('ci-psu', {
    base: 'vs',
    inherit: true,
    rules: [/* … */],
    colors: {
      'editor.background': '#ffffff',
      'editor.foreground': '#7B0F1B',
      'editorCursor.foreground': '#7B0F1B',
    },
  });
}
```

`CodeEditor.jsx` calls `registerMonacoThemes(monaco)` once inside its `onMount` callback (idempotent — Monaco is happy to re-define the same name), then sets the initial theme to match `useTheme()` and adds a `useEffect` to switch the active Monaco theme whenever `useTheme()` changes.

The Monaco theme registration is **monaco-side only** — it does not need to know about the app's CSS variables. The 3 hand-mapped color sets above mirror the 3 app palettes in §2.4 by hand.

---

## 6. Data Flow

### 6.1 Read path (this slice)

```
User → URL → React Router → ProtectedRoute
  → Layout (sticky top bar) → new page component
    → MOCK_* imports from @/data/mockData
    → (optional) embedded analytics component (e.g., ClassMisconceptionReport)
      → its own fetch logic (untouched, hits its existing API)
    → shadcn primitives (Card, Table, Badge, Button) → Recharts (where used)
```

The MOCK_* reads are **synchronous** (top-of-module constants). Pages do not need `useState`/`useEffect` for their primary data. Two pages (`InstructorStudents`, `InstructorStudentDetail`) need `useState` for search/filter, but the underlying data is still a synchronous import.

### 6.2 Real-API cutover path (future slice, not this one)

For each MOCK_* export, we add a corresponding API client method (e.g., `api.exercises.list()`) and the page swap is:

```diff
- import { MOCK_EXERCISES } from '@/data/mockData';
+ import { listExercises } from '@/api/exercises';

  function InstructorExercises() {
+   const [exercises, setExercises] = useState([]);
+   useEffect(() => { listExercises().then(setExercises); }, []);
-   const exercises = MOCK_EXERCISES;
    return <Table>...</Table>;
  }
```

This is the same pattern the student slice used; the design pages are explicitly written to keep the data access at the top of the component so the swap is mechanical.

### 6.3 Embedded analytics components' data path (unchanged)

The 9 existing analytics components and the 1 chart component already have their own fetch logic (some hit real APIs, some are pure render). This slice does NOT modify them. They may show loading states, empty states, or real data — all of which are valid for this slice. When the host page's Card frame is visible and the embedded component is loading, the user sees a Card with a title and a blank content area, which is acceptable for a mock-data slice.

### 6.4 Theme data flow

```
First page load (or refresh)
  → App boots, AuthContext + SidebarContext initialize
  → ThemeProvider (in App.jsx) runs useLayoutEffect
  → reads localStorage.getItem('codeinsight:theme')
  → if value is 'dark' or 'psu', sets <html data-theme={value}>
  → if value is missing or 'light', removes the data-theme attribute (default)
  → CSS custom properties resolve at paint time, no FOUC

User clicks ThemeToggle
  → useTheme().setTheme(key) called
  → writes localStorage, sets <html data-theme>, updates React state
  → Layout re-renders (ThemeToggle is inside it; the segmented control re-paints the active highlight)
  → CodeEditor (if mounted) listens to useTheme() in a useEffect and calls monaco.editor.setTheme()
  → all other pages automatically re-skin via CSS var cascade — no re-render needed

User logs out / switches role
  → theme state is in localStorage, not React state above AuthContext
  → theme persists across login transitions
  → Login page renders without ThemeToggle (its own layout), so there's no toggle to interact with
```

**No backend round-trip.** The theme is purely a UI concern. There is no `prefers-color-scheme` follow (the user picks explicitly; auto-detect can be a follow-up).

**Storage key:** `codeinsight:theme`. Value: `'light' | 'dark' | 'psu'`. Missing or unparseable → `light`.

**`ThemeProvider` boundary:** lives in `App.jsx` as a wrapper around `<AppContent />` (next to `<SidebarProvider>` and `<ErrorBoundary>`). It exposes `useTheme()` via a `ThemeContext`. `ThemeToggle` and `CodeEditor` are the only consumers in this slice; future components that want to read the theme (e.g., a "theme picker" modal) can `useTheme()` too.

---

## 7. Error Handling

Three layers, matching the student slice:

1. **Route layer (existing):** `ProtectedRoute` redirects to `/login` when unauthenticated, or to the user's home when the role doesn't match. Unchanged.
2. **ErrorBoundary (existing):** `App.jsx`'s `<ErrorBoundary>` catches render-time exceptions. Unchanged.
3. **Page-level (new, lightweight):**
   - `InstructorStudentDetail` reads `useParams().id` and looks the student up in `MOCK_USERS`. If the id doesn't match, render a "Student not found" `<Card>` with a back-link to `/instructor/students` (mirrors the design's `if (!student) return null;` — we make it more visible by replacing the silent null with the card).
   - `InstructorExercises` (the form) handles both `/new` and `/:id/edit`. If the edit id doesn't match a `MOCK_EXERCISES` entry, render a "Exercise not found" `<Card>` with a back-link to `/instructor/exercises`.
   - `InstructorStudents` renders a "No students found matching your search." message in the table body when the search filter is empty (mirrors the design verbatim).
   - `InstructorHeatmap` renders the heatmap table; if `MOCK_HEATMAP` is empty (which it won't be in this slice), it would render an empty body — we add an explicit empty-state row in the table to match the design's tone.

No try/catch, no toast service, no global error toaster. The student slice's "no error toaster" decision is preserved.

4. **Theme layer (new):**
   - If `localStorage` is unavailable (e.g., user disabled it, private-browsing in some browsers), `useTheme()` falls back to an in-memory default (`'light'`). The toggle still works for the session; it just doesn't persist.
   - If `localStorage` has a value that isn't `'light' | 'dark' | 'psu'` (e.g., leftover from a previous version), `useTheme()` ignores it and treats it as missing. No crash, no log.
   - If the toggle's `setTheme` is called before `ThemeProvider` mounts (theoretically impossible given the provider wraps `<AppContent />`, but defensive), the localStorage write still happens — the React state update is just dropped.

5. **Monaco layer (new):**
   - If `@monaco-editor/react` fails to load (e.g., network failure to the Monaco CDN), the `onMount` callback never fires. `editorRef.current` stays `null`, so the "click-to-jump" error handler is a no-op. The page still renders, just without the editor chrome.
   - If `monaco.editor.setTheme('ci-bogus')` is called (e.g., the user picks a theme we later rename), Monaco falls back to the default `vs` theme and logs a console warning. No crash.
   - If the user types into the editor faster than the React state can update, the latest `code` state is what gets submitted — `onChange` is debounced by React's batching, so this is not a real concern at human typing speeds.

---

## 8. Testing

This slice does **not** introduce a new testing framework or new test files. We rely on:

1. **Build:** `cd frontend && npm run build` must succeed. This is the primary signal.
2. **Smoke test (dev server):** `cd frontend && npm run dev` followed by visiting each of the 12 routes (10 new + 2 already-existing) in a browser, and confirming:
   - The page renders without a console error.
   - The pageTitle appears in the sticky top bar.
   - The expected data appears (mocked) in the expected place.
   - Clicking nav links navigates to the next page.
   - The sidebar's "active" highlight matches the current route.
3. **Regression:** The 3 student routes (`/student`, `/student/exercises`, `/student/exercises/:id`) must continue to work unchanged.

Smoke testing is **manual** in this slice, performed by the implementer. No automated browser test, no Playwright, no Vitest. This matches the student slice's testing posture.

---

## 9. Open Questions / Risks

1. **`analytics/*` components may show empty/error states.** They fetch from real APIs that the instructor user may not have data for. The Card frame still renders, but the content area may be empty. This is acceptable for a mock slice and is documented in §6.3.

2. **Sidebar link count grows from 7 → 9.** The collapsed sidebar still fits. The expanded sidebar with 9 links + user + logout may be slightly tall on short screens; the existing `overflow-y-auto` on the `<nav>` handles it.

3. **`ExerciseForm` covers both create and edit.** The form's edit mode is currently `useRoute("/instructor/exercises/:id/edit")` in TSX. In JSX, we read `useParams().id` and check `id !== 'new'`. If the id is missing or equal to `"new"`, we're in create mode. This is a small judgment call vs. the student-slice pattern of two separate routes — but the design uses one component, so we follow.

4. **`MOCK_STUDENT_STATS` table is generated.** The design's `getStudentStats()` uses `Math.random()`; we replace that with a deterministic `MOCK_STUDENT_STATS` lookup keyed by `studentId`. This means screenshots are stable, which is better for the design review.

5. **No developer page in design.** `Developer.jsx` stays untouched. The user explicitly chose to keep it.

---

## 10. Out of Scope (Restated)

For clarity, here is what is NOT delivered in this slice:

1. Real API calls (the new pages import `MOCK_*` constants only).
2. Unit tests, E2E tests, or a new test framework.
3. Accessibility audit beyond what shadcn primitives provide.
4. Backend changes (CDS engine, integrity engine, schema, tests).
5. Student-side changes beyond the `CodeEditor.jsx` Monaco port (already done in the prior slice).
6. New design pages for landing, login, or 404 (already done or untouched).
7. Re-styling of the existing `analytics/*` components (Card frame is the only visual change; the components' CSS is unchanged).
8. E2E submission → CDS → alerts flow (tracked in `CLAUDE.md`).
9. Hidden test case leakage audit (tracked in `CLAUDE.md`).
10. **Per-user backend setting for the theme** — the theme is localStorage-only. A future slice could persist the preference to the `users` table and sync across devices, but the schema/endpoint work is out of scope here.
11. **Auto theme detection** — `prefers-color-scheme` is not consulted. The user picks explicitly via the toggle.
12. **Monaco multi-language support** — the editor is hard-coded to C++. A language picker is a follow-up.
13. **Monaco language server / intellisense** — not in the legacy, not in the new scope. We use Monaco's built-in C++ tokenizer only.

---

## 11. Files Touched (Summary)

**Created (13):**

- `frontend/src/pages/instructor/Heatmap.jsx`
- `frontend/src/pages/instructor/Students.jsx`
- `frontend/src/pages/instructor/StudentDetail.jsx`
- `frontend/src/pages/instructor/Exercises.jsx` (overwrite)
- `frontend/src/pages/instructor/ExerciseForm.jsx`
- `frontend/src/pages/instructor/Warnings.jsx`
- `frontend/src/pages/instructor/Violations.jsx`
- `frontend/src/pages/instructor/Integrity.jsx`
- `frontend/src/pages/instructor/Dashboard.jsx` (overwrite)
- `frontend/src/pages/instructor/Reports.jsx` (overwrite)
- `frontend/src/lib/theme.js` — `useTheme()` hook + `ThemeContext` + `ThemeProvider` (localStorage persistence, `<html data-theme>` write)
- `frontend/src/lib/monacoThemes.js` — `registerMonacoThemes(monaco)` (defines `ci-light`, `ci-dark-teal`, `ci-psu`)
- `frontend/src/components/ThemeToggle.jsx` — 3-button segmented control (Sun / Moon / Shield icons)

**Modified (6):**

- `frontend/src/App.jsx` — re-point 10 instructor routes, add 4 missing aliases, add `pageTitle` to all 10, wrap with `<ThemeProvider>`.
- `frontend/src/components/Sidebar.jsx` — add 2 nav items, rename `My Sections` → `Students`, rename `Create Exercise` → `Exercises`, update `to:` paths.
- `frontend/src/data/mockData.js` — add 6 new `MOCK_*` exports (~70 lines).
- `frontend/src/components/Layout.jsx` — add `<ThemeToggle />` to the sticky top bar; switch the `<header>` to a `flex` container with the title and toggle.
- `frontend/src/index.css` — add `[data-theme="dark"]` and `[data-theme="psu"]` blocks that override the shadcn CSS custom properties.
- `frontend/src/pages/student/CodeEditor.jsx` (overwrite) — replace the `<textarea>` with `@monaco-editor/react`'s `<Editor>`, porting the legacy's 2-tab output, deadline countdown, attempt history, and per-line error highlighting from commit `62fa4cd`.

**Deleted (7):**

- `frontend/src/pages/instructor/Sections.jsx`
- `frontend/src/pages/instructor/SectionDetail.jsx`
- `frontend/src/pages/instructor/CreateExercise.jsx`
- `frontend/src/pages/instructor/EditExercise.jsx`
- `frontend/src/pages/instructor/Alerts.jsx`
- `frontend/src/pages/instructor/AcademicIntegrityFlags.jsx`
- `frontend/src/pages/instructor/Analytics.jsx` (already deleted in prior work; verify)

**Untouched:**

- `frontend/src/pages/instructor/Developer.jsx`
- All 9 `frontend/src/components/analytics/*` components and their CSS files
- `frontend/src/components/charts/ResponsiveLineChart.jsx`
- `frontend/src/components/ErrorBoundary.jsx`
- `frontend/src/context/AuthContext.jsx`, `frontend/src/context/SidebarContext.jsx`
- All shadcn primitives in `frontend/src/components/ui/*`
- Backend (no changes)

---

## 12. Commit Strategy (mirrors student slice)

Per the student slice, each task is its own commit. The expected commit sequence is:

```
feat(theme): add useTheme() hook + ThemeContext + localStorage persistence
feat(theme): register 3 Monaco themes in lib/monacoThemes.js
feat(theme): add dark teal + PSU palettes to index.css (data-theme overrides)
feat(theme): add ThemeToggle component + ThemeProvider wrap in App.jsx
feat(theme): add <ThemeToggle /> to Layout.jsx top bar
feat(monaco): port legacy CodeEditor.jsx (run/submit tabs, countdown, error jumps) with @monaco-editor/react
feat(instructor-slice): extend mockData.js with 6 instructor MOCK_* exports
feat(instructor-slice): port Dashboard.tsx → Dashboard.jsx (design visual)
feat(instructor-slice): port Heatmap.tsx → Heatmap.jsx
feat(instructor-slice): port Students.tsx → Students.jsx
feat(instructor-slice): port StudentDetail.tsx → StudentDetail.jsx (embed analytics)
feat(instructor-slice): port Exercises.tsx → Exercises.jsx (embed ExerciseAccordion)
feat(instructor-slice): port ExerciseForm.tsx → ExerciseForm.jsx
feat(instructor-slice): port Warnings.tsx → Warnings.jsx (embed StudentAlertCard)
feat(instructor-slice): port Reports.tsx → Reports.jsx (embed longitudinal chart + tab)
feat(instructor-slice): port Violations.tsx → Violations.jsx
feat(instructor-slice): port Integrity.tsx → Integrity.jsx (embed flag dropdown + banner)
feat(instructor-slice): update Sidebar.jsx (9 instructor links, design paths)
feat(instructor-slice): re-point 10 instructor routes in App.jsx (design-first)
feat(instructor-slice): delete 7 obsolete CodeInsight instructor pages
feat(instructor-slice): smoke test all 12 routes + build green
```

21 commits, oldest first. The theme and Monaco commits go first because the instructor pages reference `useTheme()` (via the Layout's `<ThemeToggle />`) — landing the theme system first means the instructor pages automatically pick up the dark/PSU themes for free once they're ported.

The build-green check is its own commit because it's the cutover gate.

---

## 13. Success Criteria

This slice is complete when:

1. `cd frontend && npm run build` exits 0.
2. All 12 instructor routes (10 new + 2 untouched) render without console errors in `npm run dev`.
3. The 3 student routes still render without regression.
4. The sidebar shows 9 instructor links; clicking each navigates to the right page; the active highlight is correct.
5. The 9 `analytics/*` components and 1 `charts/ResponsiveLineChart` are still present and rendered (inside Card frames) on their new host pages. They may be empty/loading — that's acceptable.
6. The 7 deleted files are gone, and no `import` statements in the surviving code reference them.
7. The student-slice features (3 routes, 3 pages, 1 mockData extension, real auth) are unaffected.
8. **Theme toggle (new):** `<ThemeToggle />` is visible in the top-right of every authenticated page (12 instructor + 4 student). Clicking each of the 3 buttons switches the active palette within ~100ms. The choice persists across a page refresh (verified by hard-refreshing after picking a theme). The `data-theme` attribute on `<html>` reflects the choice. Default (no localStorage value) is light.
9. **Theme coverage (new):** Switching to dark teal or PSU visibly re-skins all shadcn primitives, the sidebar background, the sticky top bar, all card surfaces, all badges, and the radar/line/bar charts in the embedded analytics components. The Monaco editor's chrome is themed separately, per criterion 10.
10. **Monaco (new):** `/student/exercises/e1` renders a Monaco editor (not a `<textarea>`). The C++ syntax highlights (keywords, strings, numbers, comments). The 3 Monaco themes match the 3 app themes — switching the app theme live-updates the Monaco theme without remounting the editor. The 2-tab output panel (Output / Compiler Log) renders, with per-test stdout and clickable error blocks that jump the editor cursor to the failing line. The deadline countdown (if the exercise has a deadline) and the attempt history list are present. Run / Submit / Stop buttons work against `MOCK_EXERCISES`'s test cases.

If 1–10 are all true, the slice is done. The real-API cutover is a separate future slice.
