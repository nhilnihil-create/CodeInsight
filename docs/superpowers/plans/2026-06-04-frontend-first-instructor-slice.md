# Frontend-First Instructor Slice Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Port the 10 Frontend-Design instructor pages, restore the legacy Monaco code editor, and ship a 3-theme toggle (light / dark teal / PSU maroon-gold). All data is mock for this slice; the design paths are canonical and the existing CodeInsight paths become aliases.

**Architecture:** Mechanical TSX→JSX port for the 10 instructor pages (wouter→react-router-dom v6, `<Link href>`→`<Link to>`, `useRoute`→`useParams`). Two new `lib/` modules (`theme.js` for the React state + `<html data-theme>` write, `monacoThemes.js` for the 3 Monaco palettes). One new `components/ThemeToggle.jsx` segmented control rendered in the existing sticky top bar. The 9 existing `analytics/*` components and `ResponsiveLineChart` are re-homed inside `<Card>` shells on the new design pages. The 7 obsolete CodeInsight-only instructor pages are deleted in a final task.

**Tech Stack:** JavaScript / JSX, React 18, react-router-dom v6, Vite 5, Tailwind v4, shadcn/ui (Card, Badge, Button, Tabs, Table, Dialog, Input, Select, etc. — already present), recharts (already present), lucide-react (already present), `@monaco-editor/react@^4.6.0` (already in `package.json`).

**Reference Spec:** `docs/superpowers/specs/2026-06-04-instructor-slice-design.md`

**Reference Source:** `Frontend-Design/Frontend-Design/artifacts/codeinsight/src/pages/instructor/*.tsx` (10 TSX files to port) and `git show 62fa4cd:frontend/src/pages/student/CodeEditor.jsx` (the 473-line legacy Monaco implementation to port).

**Reference Plan:** `docs/superpowers/plans/2026-06-04-frontend-first-student-slice.md` (same pattern, same TDD-light posture, same build-green gate).

---

## File Structure

| Path | Status | Responsibility |
|------|--------|----------------|
| `frontend/src/lib/theme.js` | **Create** | `useTheme()` hook + `ThemeContext` + `ThemeProvider`. Reads/writes `localStorage` key `codeinsight:theme`, mirrors to `<html data-theme>`. Default `'light'`. |
| `frontend/src/lib/monacoThemes.js` | **Create** | `registerMonacoThemes(monaco)` — defines `ci-light`, `ci-dark-teal`, `ci-psu` via `monaco.editor.defineTheme()`. |
| `frontend/src/components/ThemeToggle.jsx` | **Create** | 3-button segmented control (Sun / Moon / Shield icons), `aria-pressed`, `aria-label`, calls `useTheme().setTheme()`. |
| `frontend/src/pages/instructor/Dashboard.jsx` | **Modify** | Port of `Dashboard.tsx` (114 LOC) — class overview, embeds `ClassMisconceptionReport` + `IntegrityMonitoringBanner` in `<Card>` shells. |
| `frontend/src/pages/instructor/Heatmap.jsx` | **Create** | Port of `Heatmap.tsx` (89 LOC) — class-wide concept heatmap table. |
| `frontend/src/pages/instructor/Students.jsx` | **Create** | Port of `Students.tsx` (93 LOC) — student list with search, swaps `getStudentStats()` for `MOCK_STUDENT_STATS` lookup. |
| `frontend/src/pages/instructor/StudentDetail.jsx` | **Create** | Port of `StudentDetail.tsx` (128 LOC) — single-student view, embeds `MicroConceptAlertCard` + `LongitudinalProgressChart`. |
| `frontend/src/pages/instructor/Exercises.jsx` | **Modify** | Port of `Exercises.tsx` (81 LOC) — exercise list with "Create" CTA, embeds `ExerciseAccordion`. |
| `frontend/src/pages/instructor/ExerciseForm.jsx` | **Modify** | Port of `ExerciseForm.tsx` (158 LOC) — create + edit form, mode from `useParams().id`. |
| `frontend/src/pages/instructor/Warnings.jsx` | **Create** | Port of `Warnings.tsx` (74 LOC) — early-warnings list, embeds `StudentAlertCard`. |
| `frontend/src/pages/instructor/Reports.jsx` | **Modify** | Port of `Reports.tsx` (100 LOC) — class trends, embeds `ClassWideLongitudinalChart` + `LongitudinalTab` + `ResponsiveLineChart`. |
| `frontend/src/pages/instructor/Violations.jsx` | **Create** | Port of `Violations.tsx` (65 LOC) — structure violations table. |
| `frontend/src/pages/instructor/Integrity.jsx` | **Create** | Port of `Integrity.tsx` (88 LOC) — integrity flags, embeds `IntegrityFlagDropdown` + `IntegrityMonitoringBanner`. |
| `frontend/src/pages/student/CodeEditor.jsx` | **Modify** | Replace `<textarea>` with `@monaco-editor/react` `<Editor>`. Port the legacy's 2-tab output (Output/Compiler Log), deadline countdown, attempt history, per-line error highlight, abort-controller Stop button, Space Mono output. |
| `frontend/src/App.jsx` | **Modify** | Wrap `<AppContent />` with `<ThemeProvider>`. Re-point 10 instructor routes to design pages with `pageTitle`; add 4 missing aliases. |
| `frontend/src/components/Sidebar.jsx` | **Modify** | Add Heatmap + Violations nav items. Rename `My Sections` → `Students`, `Create Exercise` → `Exercises`. Update `to:` paths. |
| `frontend/src/data/mockData.js` | **Modify** | Add 6 new `MOCK_*` exports: `MOCK_STUDENT_STATS`, `MOCK_HEATMAP`, `MOCK_INTEGRITY_FLAGS`, `MOCK_STRUCTURE_VIOLATIONS`, `MOCK_REPORTS_TIMELINE`, `MOCK_MOST_DIFFICULT_CONCEPTS`. |
| `frontend/src/components/Layout.jsx` | **Modify** | Render `<ThemeToggle />` in the sticky top bar; switch `<header>` to a `flex` container. |
| `frontend/src/index.css` | **Modify** | Add `[data-theme="dark"]` (dark teal) and `[data-theme="psu"]` (maroon + gold + white) blocks overriding the shadcn tokens. |
| `frontend/src/pages/instructor/Sections.jsx` | **Preserve** | **Section management is preserved (user directive 2026-06-04).** The file stays as-is; `/instructor/sections` continues to point at it. A future sub-task may re-skin it to design tokens, but the route, the file, and the section-management feature all stay. |
| `frontend/src/pages/instructor/SectionDetail.jsx` | **Preserve** | **Section detail is preserved (user directive 2026-06-04).** The file stays as-is; `/instructor/sections/:sectionId` continues to point at it. |
| `frontend/src/pages/instructor/AcademicIntegrityFlags.jsx` | **Preserve** | **Per-section academic-integrity view is preserved (user directive 2026-06-04).** The file stays as-is; `/instructor/sections/:sectionId/academic-integrity` continues to point at it. The new design-wide `Integrity.jsx` lives at `/instructor/integrity` (design-canonical) — these are two separate surfaces, not duplicates. |
| `frontend/src/pages/instructor/CreateExercise.jsx` | **Delete** | Replaced by `ExerciseForm.jsx` (new) + `Exercises.jsx` (list). |
| `frontend/src/pages/instructor/EditExercise.jsx` | **Delete** | Replaced by `ExerciseForm.jsx` (edit mode). |
| `frontend/src/pages/instructor/Alerts.jsx` | **Delete** | Replaced by `Warnings.jsx`. |
| `frontend/src/pages/instructor/Analytics.jsx` | **Delete** (verify) | Already removed in prior work. |

**Untouched:** `Developer.jsx` (kept per spec §2.5). `Sections.jsx`, `SectionDetail.jsx`, `AcademicIntegrityFlags.jsx` (preserved per user directive 2026-06-04). All `analytics/*` components and their CSS files. `ResponsiveLineChart.jsx`. `ErrorBoundary.jsx`, `AuthContext.jsx`, `SidebarContext.jsx`. All shadcn primitives in `components/ui/*`. Backend.

**Commit count:** 21. Theme + Monaco commits land first so the instructor pages inherit the theming for free.

---

## Task 1: Add `useTheme()` hook + `ThemeContext` + `localStorage` persistence

**Files:**
- Create: `frontend/src/lib/theme.js`

- [ ] **Step 1: Create the file**

Write `frontend/src/lib/theme.js` with the following content:

```js
import { createContext, useContext, useEffect, useLayoutEffect, useMemo, useState } from 'react';

const STORAGE_KEY = 'codeinsight:theme';
const VALID_THEMES = ['light', 'dark', 'psu'];
const DEFAULT_THEME = 'light';

/**
 * Theme system — see spec §2.4.
 *
 * - 3 themes: 'light' (default, Frontend-Design blue), 'dark' (pre-design dark teal),
 *   'psu' (PSU maroon + gold + white).
 * - localStorage key: 'codeinsight:theme'
 * - Mirrors the active theme to <html data-theme="..."> on mount + on change.
 * - On first load with no localStorage value, no data-theme attribute is set:
 *   the :root tokens in index.css (the Frontend-Design light palette) apply.
 * - If localStorage is unavailable (private mode, etc.) we fall back to in-memory
 *   state; the toggle still works for the session but doesn't persist.
 * - useLayoutEffect (not useEffect) prevents flash of wrong theme on refresh.
 */
const ThemeContext = createContext({
  theme: DEFAULT_THEME,
  setTheme: () => {},
});

function readStoredTheme() {
  try {
    const raw = window.localStorage.getItem(STORAGE_KEY);
    if (VALID_THEMES.includes(raw)) return raw;
  } catch {
    // localStorage unavailable — fall through to default
  }
  return DEFAULT_THEME;
}

function writeStoredTheme(theme) {
  try {
    window.localStorage.setItem(STORAGE_KEY, theme);
  } catch {
    // best-effort; in-memory state is the source of truth for this session
  }
}

function applyThemeAttribute(theme) {
  const root = document.documentElement;
  if (theme === DEFAULT_THEME) {
    root.removeAttribute('data-theme');
  } else {
    root.setAttribute('data-theme', theme);
  }
}

export function ThemeProvider({ children }) {
  const [theme, setThemeState] = useState(DEFAULT_THEME);

  // Read localStorage synchronously before paint to avoid FOUC.
  useLayoutEffect(() => {
    const initial = readStoredTheme();
    setThemeState(initial);
    applyThemeAttribute(initial);
  }, []);

  // Mirror to <html data-theme> whenever the React state changes (toggle clicks).
  useEffect(() => {
    applyThemeAttribute(theme);
  }, [theme]);

  const value = useMemo(
    () => ({
      theme,
      setTheme: (next) => {
        if (!VALID_THEMES.includes(next)) return;
        setThemeState(next);
        writeStoredTheme(next);
      },
    }),
    [theme]
  );

  return <ThemeContext.Provider value={value}>{children}</ThemeContext.Provider>;
}

export function useTheme() {
  return useContext(ThemeContext);
}

export { STORAGE_KEY, VALID_THEMES, DEFAULT_THEME };
```

- [ ] **Step 2: Verify the file is parseable**

Run: `cd frontend && node -e "require('@babel/parser').parse(require('fs').readFileSync('src/lib/theme.js','utf8'), {sourceType:'module', plugins:['jsx']}); console.log('ok')"`

Expected: prints `ok` and exits 0. (We use babel to parse JSX from Node; if babel isn't installed locally, fall back to a visual check — the file should be 100 lines or so.)

- [ ] **Step 3: Commit**

```bash
git add frontend/src/lib/theme.js
git commit -m "feat(theme): add useTheme() hook + ThemeContext + localStorage persistence"
```

---

## Task 2: Register 3 Monaco themes in `lib/monacoThemes.js`

**Files:**
- Create: `frontend/src/lib/monacoThemes.js`

- [ ] **Step 1: Create the file**

Write `frontend/src/lib/monacoThemes.js` with the following content:

```js
/**
 * Monaco theme registration — see spec §5.6.
 *
 * Monaco doesn't read CSS custom properties at runtime, so the 3 themes are
 * hand-mapped to mirror the 3 app palettes in index.css (data-theme overrides).
 * Call registerMonacoThemes(monaco) once on editor mount; the returned
 * MONACO_THEMES map lets CodeEditor pick the right name for the current theme.
 *
 * Idempotent: monaco.editor.defineTheme is happy to redefine a name.
 */

export const MONACO_THEMES = {
  light: 'ci-light',
  dark: 'ci-dark-teal',
  psu: 'ci-psu',
};

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
      'editorLineNumber.foreground': '#959da5',
      'editorCursor.foreground': '#044289',
      'editor.selectionBackground': '#c8c8fa',
    },
  });

  monaco.editor.defineTheme('ci-dark-teal', {
    base: 'vs-dark',
    inherit: true,
    rules: [
      { token: 'comment', foreground: '6a85a8', fontStyle: 'italic' },
      { token: 'keyword', foreground: '85D2D0' },
      { token: 'string', foreground: 'a99dd4' },
      { token: 'number', foreground: 'fbbf24' },
    ],
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
    rules: [
      { token: 'comment', foreground: '888888', fontStyle: 'italic' },
      { token: 'keyword', foreground: '7B0F1B' },
      { token: 'string', foreground: '0F4D2E' },
      { token: 'number', foreground: 'B45309' },
    ],
    colors: {
      'editor.background': '#ffffff',
      'editor.foreground': '#7B0F1B',
      'editorLineNumber.foreground': '#B7A6A8',
      'editorCursor.foreground': '#7B0F1B',
      'editor.selectionBackground': '#FFC72C66',
    },
  });
}
```

- [ ] **Step 2: Verify the file is parseable**

Run: `cd frontend && node -e "require('@babel/parser').parse(require('fs').readFileSync('src/lib/monacoThemes.js','utf8'), {sourceType:'module', plugins:['jsx']}); console.log('ok')"`

Expected: prints `ok`. (Static data file, no runtime behavior to test until Monaco is mounted.)

- [ ] **Step 3: Commit**

```bash
git add frontend/src/lib/monacoThemes.js
git commit -m "feat(theme): register 3 Monaco themes in lib/monacoThemes.js"
```

---

## Task 3: Add dark teal + PSU palettes to `index.css`

**Files:**
- Modify: `frontend/src/index.css` (append two new blocks after the existing `.dark { ... }` block at line 159)

- [ ] **Step 1: Add the two theme blocks**

In `frontend/src/index.css`, immediately after the closing brace of the existing `.dark { ... }` block (line 159), insert the following two blocks. (Do not modify any of the existing `:root` or `.dark` rules — they remain the light and shadcn-dark defaults.)

```css
[data-theme="dark"] {
  /* Pre-design CodeInsight dark teal palette (commits b4016ff / 62fa4cd) */
  --background: 224 53% 8%;        /* #0c1220 */
  --foreground: 215 32% 86%;       /* #dce8f5 */

  --card: 222 39% 13%;             /* #131d30 */
  --card-foreground: 215 32% 86%;
  --card-border: 213 41% 22%;

  --popover: 222 39% 13%;
  --popover-foreground: 215 32% 86%;
  --popover-border: 213 41% 22%;

  --primary: 176 50% 67%;          /* #85D2D0 teal */
  --primary-foreground: 224 53% 8%;

  --secondary: 218 36% 21%;        /* #1a2640 */
  --secondary-foreground: 215 32% 86%;

  --muted: 218 36% 21%;
  --muted-foreground: 213 24% 56%; /* #6a85a8 */

  --accent: 218 36% 27%;
  --accent-foreground: 215 32% 86%;

  --destructive: 0 75% 65%;        /* #f87171 */
  --destructive-foreground: 224 53% 8%;

  --border: 213 41% 22%;           /* #1e304d */
  --input: 213 41% 22%;
  --ring: 176 50% 67%;

  --chart-1: 176 50% 67%;
  --chart-2: 256 35% 70%;
  --chart-3: 80 65% 65%;
  --chart-4: 40 90% 60%;
  --chart-5: 0 75% 65%;

  --sidebar: 240 24% 9%;           /* #0f0f1a */
  --sidebar-foreground: 215 32% 86%;
  --sidebar-border: 240 17% 24%;   /* #2e2e4a */
  --sidebar-primary: 176 50% 67%;
  --sidebar-primary-foreground: 240 24% 9%;
  --sidebar-accent: 240 17% 16%;
  --sidebar-accent-foreground: 215 32% 86%;
  --sidebar-ring: 176 50% 67%;
}

[data-theme="psu"] {
  /* Pampanga State University palette: maroon primary, gold accent, white bg */
  --background: 0 0% 100%;
  --foreground: 350 78% 27%;       /* #7B0F1B maroon */

  --card: 0 0% 100%;
  --card-foreground: 350 78% 27%;
  --card-border: 350 30% 80%;

  --popover: 0 0% 100%;
  --popover-foreground: 350 78% 27%;
  --popover-border: 350 30% 80%;

  --primary: 350 78% 27%;          /* maroon */
  --primary-foreground: 0 0% 100%;

  --secondary: 350 30% 92%;
  --secondary-foreground: 350 78% 27%;

  --muted: 350 30% 92%;
  --muted-foreground: 350 25% 40%;

  --accent: 45 100% 59%;           /* #FFC72C gold */
  --accent-foreground: 350 78% 27%;

  --destructive: 0 75% 50%;
  --destructive-foreground: 0 0% 100%;

  --border: 350 30% 80%;
  --input: 350 30% 80%;
  --ring: 350 78% 27%;

  --chart-1: 350 78% 27%;
  --chart-2: 45 100% 59%;
  --chart-3: 350 30% 50%;
  --chart-4: 45 80% 50%;
  --chart-5: 0 75% 50%;

  --sidebar: 350 78% 27%;
  --sidebar-foreground: 0 0% 100%;
  --sidebar-border: 350 50% 35%;
  --sidebar-primary: 45 100% 59%;
  --sidebar-primary-foreground: 350 78% 27%;
  --sidebar-accent: 350 70% 35%;
  --sidebar-accent-foreground: 0 0% 100%;
  --sidebar-ring: 45 100% 59%;
}
```

- [ ] **Step 2: Build the project**

Run: `cd frontend && npm run build`

Expected: exits 0. The build doesn't apply the new themes at runtime, so this only confirms the CSS parses.

- [ ] **Step 3: Commit**

```bash
git add frontend/src/index.css
git commit -m "feat(theme): add dark teal + PSU palettes to index.css (data-theme overrides)"
```

---

## Task 4: Add `ThemeToggle` component + `ThemeProvider` wrap in `App.jsx`

**Files:**
- Create: `frontend/src/components/ThemeToggle.jsx`
- Modify: `frontend/src/App.jsx` (import `ThemeProvider`; wrap `<AppContent />`)

- [ ] **Step 1: Create `ThemeToggle.jsx`**

Write `frontend/src/components/ThemeToggle.jsx` with the following content:

```jsx
import { Sun, Moon, Shield } from 'lucide-react';
import { cn } from '@/lib/utils';
import { useTheme, VALID_THEMES } from '@/lib/theme';

/**
 * 3-button segmented theme toggle — see spec §5.5.
 *
 * Reads useTheme(); clicking a button calls setTheme(key). Renders in the sticky
 * top bar of Layout. The 3 icons (Sun = light, Moon = dark, Shield = PSU) are
 * 1.5x4 lucide icons inside 8x8 buttons. The active theme gets a primary ring.
 */
const OPTIONS = [
  { key: 'light', label: 'Light', icon: Sun },
  { key: 'dark', label: 'Dark teal', icon: Moon },
  { key: 'psu', label: 'PSU', icon: Shield },
];

export default function ThemeToggle() {
  const { theme, setTheme } = useTheme();

  return (
    <div
      role="group"
      aria-label="Theme selector"
      className="flex items-center gap-1 rounded-md border border-border bg-card p-1"
    >
      {OPTIONS.map(({ key, label, icon: Icon }) => {
        const active = theme === key;
        return (
          <button
            key={key}
            type="button"
            aria-label={`Theme: ${label}`}
            aria-pressed={active}
            onClick={() => setTheme(key)}
            className={cn(
              'inline-flex h-7 w-7 items-center justify-center rounded transition-colors',
              active
                ? 'bg-primary text-primary-foreground ring-2 ring-primary ring-offset-1 ring-offset-card'
                : 'text-muted-foreground hover:bg-muted hover:text-foreground'
            )}
          >
            <Icon className="h-4 w-4" />
          </button>
        );
      })}
    </div>
  );
}

// re-export the option keys for tests / future consumers
export { VALID_THEMES };
```

- [ ] **Step 2: Wrap `<AppContent />` in `<ThemeProvider>` in `App.jsx`**

In `frontend/src/App.jsx`:

1. Add this import at the top (next to the other context imports on lines 2-3):

```jsx
import { ThemeProvider } from './lib/theme';
```

2. Modify the `App()` function (lines 174-182) to wrap `<AppContent />` with `<ThemeProvider>`:

Replace:

```jsx
function App() {
  return (
    <ErrorBoundary>
      <SidebarProvider>
        <AppContent />
      </SidebarProvider>
    </ErrorBoundary>
  );
}
```

With:

```jsx
function App() {
  return (
    <ErrorBoundary>
      <SidebarProvider>
        <ThemeProvider>
          <AppContent />
        </ThemeProvider>
      </SidebarProvider>
    </ErrorBoundary>
  );
}
```

- [ ] **Step 3: Build the project**

Run: `cd frontend && npm run build`

Expected: exits 0. The toggle isn't yet visible (we add it to `Layout.jsx` in Task 5), but the provider must compile.

- [ ] **Step 4: Commit**

```bash
git add frontend/src/components/ThemeToggle.jsx frontend/src/App.jsx
git commit -m "feat(theme): add ThemeToggle component + ThemeProvider wrap in App.jsx"
```

---

## Task 5: Add `<ThemeToggle />` to `Layout.jsx` top bar

**Files:**
- Modify: `frontend/src/components/Layout.jsx` (add ThemeToggle import, restructure `<header>` to a flex container)

- [ ] **Step 1: Add the import and the toggle to the header**

In `frontend/src/components/Layout.jsx`:

1. Add this import at the top (after the existing `import Sidebar from './Sidebar';` on line 1):

```jsx
import ThemeToggle from './ThemeToggle';
```

2. Replace the entire `return` block (lines 21-39) with the version below. The only change is the `<header>` — it now wraps `pageTitle` and `<ThemeToggle />` in a `flex` container so the toggle sits on the right edge of the sticky top bar.

```jsx
  return (
    <div className="min-h-screen bg-background text-foreground">
      <Sidebar />
      <main
        className={cn(
          'min-h-screen overflow-auto bg-background transition-[margin] duration-300 ease-in-out',
          isOpen ? 'ml-[220px]' : 'ml-[70px]'
        )}
      >
        {pageTitle && (
          <header className="sticky top-0 z-30 border-b border-border bg-card/80 px-6 py-4 backdrop-blur supports-[backdrop-filter]:bg-card/60">
            <div className="flex items-center justify-between gap-4">
              <h1 className="text-xl font-semibold tracking-tight text-foreground">
                {pageTitle}
              </h1>
              <ThemeToggle />
            </div>
          </header>
        )}
        <div className="w-full max-w-7xl mx-auto p-6 lg:p-8">{children}</div>
      </main>
    </div>
  );
```

- [ ] **Step 2: Build the project**

Run: `cd frontend && npm run build`

Expected: exits 0.

- [ ] **Step 3: Commit**

```bash
git add frontend/src/components/Layout.jsx
git commit -m "feat(theme): add <ThemeToggle /> to Layout.jsx top bar"
```

---

## Task 6: Port legacy Monaco `CodeEditor.jsx` (run/submit tabs, countdown, error jumps)

**Files:**
- Modify: `frontend/src/pages/student/CodeEditor.jsx` (overwrite)

- [ ] **Step 1: Read the legacy Monaco source**

Run:

```bash
git -C /home/nihil/projects/codeinsight show 62fa4cd:frontend/src/pages/student/CodeEditor.jsx
```

This is the 473-line reference. Read it in full; this task ports its feature set to the new mock-data + theme-aware shape.

- [ ] **Step 2: Overwrite `CodeEditor.jsx` with the ported version**

Replace `frontend/src/pages/student/CodeEditor.jsx` with the following content. This port:

- Replaces the legacy's `api` calls with mock data derived from `MOCK_EXERCISES` (matching the student-slice pattern).
- Replaces the legacy's `api` calls for fetching the exercise + attempts with a synchronous `MOCK_EXERCISES.find(...)` lookup.
- Replaces the legacy's `useEffect` countdown with the same pattern (seconds → formatted `m:ss`), but pulls `deadline` from `MOCK_EXERCISES[i].dueDate`.
- Wires the new `useTheme()` to `monaco.editor.setTheme()` so the editor re-themes live.
- Calls `registerMonacoThemes(monaco)` from `lib/monacoThemes.js` inside the `onMount` callback.
- Keeps every feature from the legacy: 2-tab output, deadline countdown, attempt history, per-line error highlight, abort-controller Stop button, Space Mono output, click-to-jump-to-line, `editorRef` stash.
- Reuses the existing `Card` / `Button` / `Badge` / shadcn primitives.

```jsx
import { useState, useEffect, useRef } from 'react';
import { useParams, Link } from 'react-router-dom';
import Editor from '@monaco-editor/react';
import { Button } from '@/components/ui/button';
import { Badge } from '@/components/ui/badge';
import { Card, CardContent } from '@/components/ui/card';
import { Play, Send, Square, Clock, AlertCircle, RefreshCw, ChevronLeft } from 'lucide-react';
import { MOCK_EXERCISES } from '@/data/mockData';
import { useTheme, MONACO_THEMES, registerMonacoThemes } from '@/lib/theme-reexports';
// NOTE: import the helpers directly below — this line is rewritten in step 2a.
import { useTheme, DEFAULT_THEME } from '@/lib/theme';
import { MONACO_THEMES, registerMonacoThemes } from '@/lib/monacoThemes';

/**
 * Code Editor (Monaco port) — see spec §3.1.
 *
 * Ported from commit 62fa4cd (473 lines). Differences from the legacy:
 *  - Reads MOCK_EXERCISES synchronously (no /api/student/exercises/:id fetch).
 *  - Mock run/submit handlers render the same per-test output shape.
 *  - Monaco themes (ci-light / ci-dark-teal / ci-psu) registered on mount,
 *    and the active theme is re-applied whenever useTheme() changes.
 *  - The 2-tab output panel (Output / Compiler Log) is preserved verbatim,
 *    including the clickable error blocks and per-line highlight.
 */

function formatTime(seconds) {
  if (!seconds || seconds < 0) return '0:00';
  const m = Math.floor(seconds / 60);
  const s = seconds % 60;
  return `${m}:${s.toString().padStart(2, '0')}`;
}

function parseErrorBlocks(errorText) {
  if (!errorText) return [];
  const blocks = [];
  const lines = errorText.split('\n');
  let i = 0;
  while (i < lines.length) {
    const line = lines[i];
    const m = line.match(/(?:\[Line\s+(\d+):(\d+)\]|^.*?:(\d+):(?:\d+):)\s*(ERROR|WARNING|error|warning):\s*(.+)/i);
    if (m) {
      const lineNum = parseInt(m[1] || m[3]);
      const col = parseInt(m[2] || 0) || 1;
      const errorType = m[4];
      const message = m[5];
      let codeLine = '';
      let pointer = '';
      if (i + 1 < lines.length && /^\s+/.test(lines[i + 1])) {
        codeLine = lines[i + 1].trim();
        i++;
      }
      if (i + 1 < lines.length && lines[i + 1].includes('^')) {
        pointer = lines[i + 1].trim();
        i++;
      }
      blocks.push({ type: 'error', lineNum, col, errorType, message, codeLine, pointer });
    } else if (line.trim()) {
      blocks.push({ type: 'text', content: line });
    }
    i++;
  }
  return blocks;
}

export default function StudentCodeEditor() {
  const { exerciseId } = useParams();
  const exercise = MOCK_EXERCISES.find((e) => e.id === exerciseId) || MOCK_EXERCISES[0];
  const { theme } = useTheme();

  const [code, setCode] = useState(exercise.starterCode);
  const [testResults, setTestResults] = useState(null);
  const [attempts, setAttempts] = useState([]);
  const [running, setRunning] = useState(false);
  const [submitting, setSubmitting] = useState(false);
  const [activeTab, setActiveTab] = useState('output');
  const [timeRemaining, setTimeRemaining] = useState(null);
  const [abortController, setAbortController] = useState(null);
  const [highlightedLine, setHighlightedLine] = useState(null);

  const exerciseStartTimeRef = useRef(Date.now());
  const editorRef = useRef(null);

  // Initialize deadline countdown from MOCK_EXERCISES[i].dueDate
  useEffect(() => {
    if (exercise.dueDate) {
      const diff = new Date(exercise.dueDate) - new Date();
      if (diff > 0) setTimeRemaining(Math.floor(diff / 1000));
    }
  }, [exercise.dueDate]);

  // Tick the countdown
  useEffect(() => {
    if (timeRemaining == null || timeRemaining <= 0) return;
    const t = setTimeout(() => setTimeRemaining((s) => (s > 0 ? s - 1 : 0)), 1000);
    return () => clearTimeout(t);
  }, [timeRemaining]);

  // Swap Monaco theme live when useTheme() changes
  useEffect(() => {
    if (editorRef.current) {
      const monacoTheme = MONACO_THEMES[theme] || MONACO_THEMES[DEFAULT_THEME];
      editorRef.current._monaco?.editor.setTheme(monacoTheme);
    }
  }, [theme]);

  const handleEditorMount = (editor, monaco) => {
    registerMonacoThemes(monaco);
    monaco.editor.setTheme(MONACO_THEMES[theme] || MONACO_THEMES[DEFAULT_THEME]);
    editorRef.current = { ...editor, _monaco: monaco };
  };

  const goToErrorLine = (lineNumber) => {
    if (!editorRef.current || !lineNumber) return;
    setHighlightedLine(lineNumber);
    editorRef.current.revealLineInCenter(lineNumber);
    editorRef.current.setPosition({ lineNumber, column: 1 });
    editorRef.current.focus();
  };

  const handleRun = async () => {
    setRunning(true);
    setActiveTab('output');
    const controller = new AbortController();
    setAbortController(controller);
    // Mock: render the first test's expected output, and synthesize a
    // compiler-log error if the code is empty.
    await new Promise((r) => setTimeout(r, 200));
    controller.signal.throwIfAborted?.();
    const empty = code.trim().length === 0;
    const result = {
      passed: !empty,
      testResults: empty
        ? []
        : exercise.testCases.map((tc, i) => ({
            name: `Test ${i + 1}`,
            input: tc.input || '',
            expected: tc.expectedOutput,
            actual: empty ? '' : tc.expectedOutput,
            passed: true,
          })),
      compilation_log: empty
        ? '[Line 5:1] ERROR: expected unqualified-id\n    int main() {\n    ^'
        : '',
    };
    setTestResults(result);
    if (result.compilation_log) setActiveTab('compiler-log');
    setRunning(false);
    setAbortController(null);
  };

  const handleStop = () => {
    if (abortController) {
      abortController.abort();
      setAbortController(null);
    }
    setRunning(false);
  };

  const handleSubmit = async () => {
    setSubmitting(true);
    await new Promise((r) => setTimeout(r, 200));
    const elapsed = exerciseStartTimeRef.current
      ? Math.floor((Date.now() - exerciseStartTimeRef.current) / 1000)
      : 0;
    const result = {
      passed: true,
      testResults: exercise.testCases.map((tc, i) => ({
        name: `Test ${i + 1}`,
        input: tc.input || '',
        expected: tc.expectedOutput,
        actual: tc.expectedOutput,
        passed: true,
      })),
      timeSpentSeconds: elapsed,
    };
    setTestResults(result);
    setAttempts((prev) => [{ id: Date.now(), passed: true, time: elapsed }, ...prev]);
    setActiveTab('output');
    setSubmitting(false);
  };

  const errorBlocks = testResults?.compilation_log ? parseErrorBlocks(testResults.compilation_log) : [];

  return (
    <div className="h-[calc(100vh-100px)] flex flex-col space-y-4">
      <div className="flex items-center justify-between">
        <div>
          <Link
            to="/student/exercises"
            className="inline-flex items-center text-sm text-muted-foreground hover:text-foreground mb-2"
          >
            <ChevronLeft className="w-4 h-4 mr-1" /> Back to exercises
          </Link>
          <h1 className="text-2xl font-bold tracking-tight">{exercise.title}</h1>
          <div className="flex items-center gap-2 mt-1">
            <Badge variant="outline">{exercise.difficulty}</Badge>
            {exercise.conceptTags.map((tag) => (
              <Badge key={tag} variant="secondary">{tag}</Badge>
            ))}
          </div>
        </div>
        <div className="flex gap-4 text-sm text-muted-foreground">
          {timeRemaining != null && timeRemaining > 0 && (
            <div className="flex items-center gap-1">
              <Clock className="w-4 h-4" /> {formatTime(timeRemaining)}
            </div>
          )}
          <div className="flex items-center gap-1">
            <AlertCircle className="w-4 h-4" /> {errorBlocks.length} errors
          </div>
          <div className="flex items-center gap-1">
            <RefreshCw className="w-4 h-4" /> {attempts.length} submits
          </div>
        </div>
      </div>

      <div className="flex-1 grid grid-cols-1 lg:grid-cols-2 gap-4 min-h-0">
        <div className="flex flex-col gap-4 overflow-hidden">
          <Card className="flex-1 overflow-auto">
            <CardContent className="p-6">
              <h2 className="font-semibold mb-4">Description</h2>
              <p className="text-sm leading-relaxed mb-6">{exercise.description}</p>
              <h3 className="font-semibold text-sm mb-2 text-muted-foreground uppercase tracking-wider">
                Visible Test Case
              </h3>
              <div className="bg-muted p-4 rounded-md space-y-3 font-mono text-sm">
                <div>
                  <div className="text-muted-foreground mb-1">Input:</div>
                  <div className="bg-background p-2 rounded border">
                    {exercise.testCases[0]?.input || '(none)'}
                  </div>
                </div>
                <div>
                  <div className="text-muted-foreground mb-1">Expected Output:</div>
                  <div className="bg-background p-2 rounded border">
                    {exercise.testCases[0]?.expectedOutput}
                  </div>
                </div>
              </div>
            </CardContent>
          </Card>
        </div>

        <div className="flex flex-col gap-4 overflow-hidden">
          <div className="flex-1 rounded-xl border overflow-hidden flex flex-col">
            <div className="h-9 bg-muted flex items-center px-4 text-xs font-mono text-muted-foreground border-b border-border">
              main.cpp
            </div>
            <Editor
              height="100%"
              defaultLanguage="cpp"
              language="cpp"
              value={code}
              onChange={(v) => setCode(v ?? '')}
              theme={MONACO_THEMES[theme] || MONACO_THEMES[DEFAULT_THEME]}
              onMount={handleEditorMount}
              options={{
                fontFamily: "'JetBrains Mono', monospace",
                fontSize: 13,
                minimap: { enabled: false },
                scrollBeyondLastLine: false,
                automaticLayout: true,
              }}
            />
          </div>

          <div className="h-56 bg-card rounded-xl border p-3 flex flex-col">
            <div className="flex justify-between items-center mb-2">
              <div className="flex gap-1">
                <button
                  type="button"
                  onClick={() => setActiveTab('output')}
                  className={
                    'px-3 py-1 text-xs font-medium rounded ' +
                    (activeTab === 'output'
                      ? 'bg-primary text-primary-foreground'
                      : 'text-muted-foreground hover:bg-muted')
                  }
                >
                  Output
                </button>
                <button
                  type="button"
                  onClick={() => setActiveTab('compiler-log')}
                  className={
                    'px-3 py-1 text-xs font-medium rounded ' +
                    (activeTab === 'compiler-log'
                      ? 'bg-primary text-primary-foreground'
                      : 'text-muted-foreground hover:bg-muted')
                  }
                >
                  Compiler Log
                </button>
              </div>
              <div className="flex gap-2">
                {running ? (
                  <Button variant="destructive" size="sm" onClick={handleStop} className="gap-1">
                    <Square className="w-4 h-4" /> Stop
                  </Button>
                ) : (
                  <Button variant="secondary" size="sm" onClick={handleRun} className="gap-1" disabled={submitting}>
                    <Play className="w-4 h-4" /> Run
                  </Button>
                )}
                <Button size="sm" onClick={handleSubmit} className="gap-1" disabled={running || submitting}>
                  <Send className="w-4 h-4" /> Submit
                </Button>
              </div>
            </div>
            <div
              className="flex-1 bg-muted rounded-md p-3 text-sm overflow-auto whitespace-pre-wrap"
              style={{ fontFamily: "'JetBrains Mono', monospace" }}
            >
              {activeTab === 'output' ? (
                testResults ? (
                  testResults.testResults.length === 0 ? (
                    <span className="text-muted-foreground">No test results.</span>
                  ) : (
                    testResults.testResults.map((r, i) => (
                      <div key={i} className="mb-2">
                        <span className={r.passed ? 'text-green-600' : 'text-destructive'}>
                          {r.passed ? '✓' : '✗'} {r.name}
                        </span>
                        <div className="text-muted-foreground ml-4 text-xs">
                          in: {r.input || '(none)'} | expected: {r.expected} | actual: {r.actual}
                        </div>
                      </div>
                    ))
                  )
                ) : (
                  <span className="text-muted-foreground">Run your code to see output here.</span>
                )
              ) : errorBlocks.length === 0 ? (
                <span className="text-muted-foreground">No compiler errors.</span>
              ) : (
                errorBlocks.map((b, i) =>
                  b.type === 'error' ? (
                    <div
                      key={i}
                      onClick={() => goToErrorLine(b.lineNum)}
                      role="button"
                      tabIndex={0}
                      className="mb-2 p-2 rounded border border-destructive/30 bg-destructive/10 cursor-pointer"
                    >
                      <div className="text-destructive font-semibold text-xs">
                        ● [Line {b.lineNum}:{b.col}] {b.errorType}
                      </div>
                      <div className="ml-4 text-xs text-amber-600">{b.message}</div>
                      {b.codeLine && (
                        <div className="ml-4 mt-1 bg-background/50 px-2 py-1 rounded text-xs font-mono">
                          {b.codeLine}
                          {b.pointer && <div className="text-destructive font-bold">{b.pointer}</div>}
                        </div>
                      )}
                      {highlightedLine === b.lineNum && (
                        <div className="ml-4 text-[10px] text-primary mt-1">↑ editor scrolled to line {b.lineNum}</div>
                      )}
                    </div>
                  ) : (
                    <div key={i} className="text-muted-foreground text-xs">{b.content}</div>
                  )
                )
              )}
            </div>
          </div>

          {attempts.length > 0 && (
            <div className="rounded-xl border bg-card p-3 max-h-32 overflow-auto">
              <h3 className="text-xs font-semibold text-muted-foreground uppercase tracking-wider mb-2">
                Attempt History
              </h3>
              {attempts.map((a) => (
                <div key={a.id} className="text-xs flex justify-between py-1 border-b border-border/50 last:border-0">
                  <span className="text-green-600">✓ Submitted</span>
                  <span className="text-muted-foreground">{formatTime(a.time)}</span>
                </div>
              ))}
            </div>
          )}
        </div>
      </div>
    </div>
  );
}
```

- [ ] **Step 2a: Remove the stale import line**

The block above includes a temporary `// NOTE: import the helpers directly below` line. Remove the line that begins `import { useTheme, MONACO_THEMES, registerMonacoThemes } from '@/lib/theme-reexports';` and the comment above it. The correct imports are the two lines that follow (`useTheme, DEFAULT_THEME` from `@/lib/theme` and `MONACO_THEMES, registerMonacoThemes` from `@/lib/monacoThemes`).

- [ ] **Step 3: Build the project**

Run: `cd frontend && npm run build`

Expected: exits 0. The Monaco editor is dynamically loaded from a CDN, so the build is unaffected; the `onMount` runs in the browser.

- [ ] **Step 4: Commit**

```bash
git add frontend/src/pages/student/CodeEditor.jsx
git commit -m "feat(monaco): port legacy CodeEditor.jsx (run/submit tabs, countdown, error jumps) with @monaco-editor/react"
```

---

## Task 7: Extend `mockData.js` with 6 instructor `MOCK_*` exports

**Files:**
- Modify: `frontend/src/data/mockData.js` (append 6 new exports at the end of the file)

- [ ] **Step 1: Append the 6 new exports**

Add the following block to the end of `frontend/src/data/mockData.js` (after the existing `MOCK_RADAR_DATA` export):

```js
// ----------------------------------------------------------------------------
// Instructor-slice mock data (added 2026-06-04) — see spec §5.3.
// ----------------------------------------------------------------------------

// Per-student summary stats for the InstructorStudents table.
export const MOCK_STUDENT_STATS = [
  { studentId: 'u2', avgCds: 72, highestConcept: 'Loops',      lastActiveDays: 1, hasAlert: false },
  { studentId: 'u3', avgCds: 58, highestConcept: 'Arrays',     lastActiveDays: 4, hasAlert: true  },
  { studentId: 'u4', avgCds: 41, highestConcept: 'Conditionals', lastActiveDays: 9, hasAlert: true  },
];

// Class-wide concept heatmap: rows = students, cols = concepts, value 0-100.
export const MOCK_HEATMAP = [
  { studentId: 'u2', name: 'Alex Santos',  scores: { Loops: 90, Arrays: 75, Functions: 60, Pointers: 40, OOP: 55, Variables: 85, Datatypes: 80, Conditionals: 70 } },
  { studentId: 'u3', name: 'Maria Garcia', scores: { Loops: 55, Arrays: 60, Functions: 45, Pointers: 30, OOP: 40, Variables: 70, Datatypes: 65, Conditionals: 50 } },
  { studentId: 'u4', name: 'John Doe',    scores: { Loops: 35, Arrays: 25, Functions: 20, Pointers: 15, OOP: 30, Variables: 55, Datatypes: 50, Conditionals: 40 } },
];

// Integrity flags rendered on the InstructorIntegrity page.
export const MOCK_INTEGRITY_FLAGS = [
  { id: 1, student: 'John Doe',     exercise: 'Basic Loops',         type: 'Hardcoding',           confidence: 95, desc: 'Student output matches expected exactly using hardcoded string outputs rather than logic.', time: '2 hours ago' },
  { id: 2, student: 'Alex Santos',  exercise: 'Function Calculator', type: 'Behavioral Anomaly',   confidence: 88, desc: 'Solution pasted directly. 0 keystrokes tracked prior to correct submission.',                       time: '1 day ago'   },
  { id: 3, student: 'Maria Garcia', exercise: 'Array Reversal',      type: 'Passive Behavior',     confidence: 75, desc: 'Editor open for 45 minutes with less than 10 keystrokes.',                                         time: '2 days ago'  },
  { id: 4, student: 'John Doe',     exercise: 'Array Reversal',      type: 'Code Growth Spike',    confidence: 92, desc: 'Code size increased by 500% in a single second. Possible copy-paste.',                            time: '3 days ago'  },
];

// Structure violations rendered on the InstructorViolations page.
export const MOCK_STRUCTURE_VIOLATIONS = [
  { id: 1, student: 'Alex Santos',  exercise: 'Array Reversal',  concept: 'Arrays', type: 'Output Mismatch', message: 'Expected "5 4 3 2 1" but got "1 2 3 4 5"',     severity: 'high',   time: '5 hours ago' },
  { id: 2, student: 'John Doe',     exercise: 'Function Calculator', concept: 'Functions', type: 'Missing Return',  message: 'Function declares int return type but returns nothing.', severity: 'medium', time: '1 day ago'  },
  { id: 3, student: 'Maria Garcia', exercise: 'Basic Loops',     concept: 'Loops',     type: 'Off-By-One',       message: 'Loop runs n+1 times; expected n iterations.',          severity: 'low',    time: '2 days ago'  },
  { id: 4, student: 'John Doe',     exercise: 'Basic Loops',     concept: 'Loops',     type: 'Infinite Loop',    message: 'Loop condition never becomes false.',                  severity: 'high',   time: '3 days ago'  },
];

// Weekly class-average CDS + high-risk-student counts for the Reports page.
export const MOCK_REPORTS_TIMELINE = [
  { week: 'W1', avgCds: 52, highRiskStudents: 4 },
  { week: 'W2', avgCds: 58, highRiskStudents: 3 },
  { week: 'W3', avgCds: 61, highRiskStudents: 2 },
  { week: 'W4', avgCds: 64, highRiskStudents: 2 },
  { week: 'W5', avgCds: 68, highRiskStudents: 1 },
];

// Concept-level average CDS for the "Most Difficult Concepts" card.
export const MOCK_MOST_DIFFICULT_CONCEPTS = [
  { concept: 'Pointers',     score: 32 },
  { concept: 'OOP',          score: 45 },
  { concept: 'Functions',    score: 55 },
  { concept: 'Conditionals', score: 62 },
];
```

- [ ] **Step 2: Build the project**

Run: `cd frontend && npm run build`

Expected: exits 0. (Mock data is static, so the build just confirms JS parses.)

- [ ] **Step 3: Commit**

```bash
git add frontend/src/data/mockData.js
git commit -m "feat(instructor-slice): extend mockData.js with 6 instructor MOCK_* exports"
```

---

## Task 8: Port `Dashboard.tsx` → `Dashboard.jsx` (design visual, embed analytics)

**Files:**
- Modify: `frontend/src/pages/instructor/Dashboard.jsx` (overwrite)

- [ ] **Step 1: Read the design source**

Run: `cat Frontend-Design/Frontend-Design/artifacts/codeinsight/src/pages/instructor/Dashboard.tsx`

(Use the Read tool on the absolute path `/home/nihil/projects/codeinsight/Frontend-Design/Frontend-Design/artifacts/codeinsight/src/pages/instructor/Dashboard.tsx` if cat is not available in your shell.)

- [ ] **Step 2: Overwrite the page**

Replace `frontend/src/pages/instructor/Dashboard.jsx` with a JSX port of the TSX. Required mechanical changes:

- `import { Link } from "wouter"` → `import { Link } from 'react-router-dom'`
- `<Link href="/x">` → `<Link to="/x">`
- `import AppLayout from "@/components/layout/AppLayout"` + the wrapping `<AppLayout role="instructor">…</AppLayout>` → drop the AppLayout wrapper (the page is rendered inside `<Layout>` from `App.jsx`); the page's content lives directly inside that.
- TypeScript `: string` annotations on the random-stat helpers → drop them.
- `useState("")` / `useState(0)` stay the same; the existing analytics components are imported from `@/components/analytics/...`.

Add these analytics embeds inside their own `<Card>` shells (per spec §2.3 + §3 row 1):

```jsx
import ClassMisconceptionReport from '@/components/analytics/ClassMisconceptionReport';
import IntegrityMonitoringBanner from '@/components/analytics/IntegrityMonitoringBanner';
```

And render them near the bottom of the page (after the existing class-overview content):

```jsx
<Card>
  <CardHeader>
    <CardTitle>Class Misconceptions</CardTitle>
  </CardHeader>
  <CardContent>
    <ClassMisconceptionReport />
  </CardContent>
</Card>

<IntegrityMonitoringBanner />
```

(Import `ClassMisconceptionReport.css` once at the top of the file: `import '@/components/analytics/ClassMisconceptionReport.css';` — the analytics component's CSS is global.)

- [ ] **Step 3: Build the project**

Run: `cd frontend && npm run build`

Expected: exits 0.

- [ ] **Step 4: Commit**

```bash
git add frontend/src/pages/instructor/Dashboard.jsx
git commit -m "feat(instructor-slice): port Dashboard.tsx → Dashboard.jsx (design visual)"
```

---

## Task 9: Port `Heatmap.tsx` → `Heatmap.jsx`

**Files:**
- Create: `frontend/src/pages/instructor/Heatmap.jsx`

- [ ] **Step 1: Read the design source**

Run: `cat Frontend-Design/Frontend-Design/artifacts/codeinsight/src/pages/instructor/Heatmap.tsx`

- [ ] **Step 2: Create the ported file**

Write `frontend/src/pages/instructor/Heatmap.jsx` with the following content (JSX port of the 89-LOC TSX; replaces `Math.random()` heatmap generator with a deterministic `MOCK_HEATMAP` lookup):

```jsx
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { MOCK_HEATMAP } from '@/data/mockData';

/**
 * Class-wide concept heatmap — see spec §3 row 2.
 *
 * Cells colored on a red→yellow→green scale derived from MOCK_HEATMAP scores.
 * If MOCK_HEATMAP is empty we render an explicit empty-state row (spec §7).
 */
function cellColor(score) {
  if (score >= 80) return 'bg-green-500/80 text-white';
  if (score >= 60) return 'bg-green-500/40';
  if (score >= 40) return 'bg-yellow-500/40';
  if (score >= 20) return 'bg-orange-500/50 text-white';
  return 'bg-destructive/80 text-white';
}

const CONCEPTS = ['Loops', 'Arrays', 'Functions', 'Pointers', 'OOP', 'Variables', 'Datatypes', 'Conditionals'];

export default function InstructorHeatmap() {
  return (
    <div className="space-y-6">
      <div>
        <h1 className="text-3xl font-bold tracking-tight">Class Heatmap</h1>
        <p className="text-muted-foreground">Concept mastery across the class.</p>
      </div>
      <Card>
        <CardHeader>
          <CardTitle>Concept × Student</CardTitle>
        </CardHeader>
        <CardContent className="overflow-x-auto">
          <table className="w-full text-sm">
            <thead>
              <tr>
                <th className="text-left p-2 font-medium text-muted-foreground">Student</th>
                {CONCEPTS.map((c) => (
                  <th key={c} className="p-2 font-medium text-muted-foreground">{c}</th>
                ))}
              </tr>
            </thead>
            <tbody>
              {MOCK_HEATMAP.length === 0 ? (
                <tr>
                  <td colSpan={CONCEPTS.length + 1} className="p-6 text-center text-muted-foreground">
                    No heatmap data available.
                  </td>
                </tr>
              ) : (
                MOCK_HEATMAP.map((row) => (
                  <tr key={row.studentId} className="border-t border-border">
                    <td className="p-2 font-medium">{row.name}</td>
                    {CONCEPTS.map((c) => {
                      const score = row.scores[c] ?? 0;
                      return (
                        <td key={c} className="p-1">
                          <div className={`rounded p-2 text-center text-xs font-semibold ${cellColor(score)}`}>
                            {score}
                          </div>
                        </td>
                      );
                    })}
                  </tr>
                ))
              )}
            </tbody>
          </table>
        </CardContent>
      </Card>
    </div>
  );
}
```

- [ ] **Step 3: Build the project**

Run: `cd frontend && npm run build`

Expected: exits 0.

- [ ] **Step 4: Commit**

```bash
git add frontend/src/pages/instructor/Heatmap.jsx
git commit -m "feat(instructor-slice): port Heatmap.tsx → Heatmap.jsx"
```

---

## Task 10: Port `Students.tsx` → `Students.jsx`

**Files:**
- Create: `frontend/src/pages/instructor/Students.jsx`

- [ ] **Step 1: Read the design source**

Run: `cat Frontend-Design/Frontend-Design/artifacts/codeinsight/src/pages/instructor/Students.tsx`

- [ ] **Step 2: Create the ported file**

Write `frontend/src/pages/instructor/Students.jsx` with the following content (JSX port of the 93-LOC TSX; deterministic `MOCK_STUDENT_STATS` lookup replaces `getStudentStats()`):

```jsx
import { useState } from 'react';
import { Link } from 'react-router-dom';
import { Card, CardContent } from '@/components/ui/card';
import { Input } from '@/components/ui/input';
import { Badge } from '@/components/ui/badge';
import { Table, TableBody, TableCell, TableHead, TableHeader, TableRow } from '@/components/ui/table';
import { Search } from 'lucide-react';
import { MOCK_USERS, MOCK_STUDENT_STATS } from '@/data/mockData';

/**
 * Students list — see spec §3 row 3.
 * Reads MOCK_USERS for the table rows and MOCK_STUDENT_STATS for the
 * per-student summary columns. Replaces the design's Math.random() with
 * a deterministic lookup so screenshots are stable.
 */
export default function InstructorStudents() {
  const [search, setSearch] = useState('');
  const students = MOCK_USERS.filter(
    (u) =>
      u.role === 'student' &&
      (u.name.toLowerCase().includes(search.toLowerCase()) ||
        u.studentId?.toLowerCase().includes(search.toLowerCase()))
  );

  const statsById = Object.fromEntries(MOCK_STUDENT_STATS.map((s) => [s.studentId, s]));

  return (
    <div className="space-y-6">
      <div className="flex flex-col sm:flex-row sm:items-center justify-between gap-4">
        <div>
          <h1 className="text-3xl font-bold tracking-tight">Students</h1>
          <p className="text-muted-foreground">Manage and monitor student progress.</p>
        </div>
        <div className="relative w-full sm:w-72">
          <Search className="absolute left-2.5 top-2.5 h-4 w-4 text-muted-foreground" />
          <Input
            type="search"
            placeholder="Search by name or ID..."
            className="pl-8"
            value={search}
            onChange={(e) => setSearch(e.target.value)}
          />
        </div>
      </div>

      <Card>
        <CardContent className="p-0">
          <Table>
            <TableHeader>
              <TableRow>
                <TableHead>Student</TableHead>
                <TableHead>Student ID</TableHead>
                <TableHead>Avg CDS</TableHead>
                <TableHead>Strongest Concept</TableHead>
                <TableHead>Last Active</TableHead>
                <TableHead>Status</TableHead>
              </TableRow>
            </TableHeader>
            <TableBody>
              {students.length === 0 ? (
                <TableRow>
                  <TableCell colSpan={6} className="text-center text-muted-foreground py-6">
                    No students found matching your search.
                  </TableCell>
                </TableRow>
              ) : (
                students.map((s) => {
                  const stats = statsById[s.id] || { avgCds: 0, highestConcept: '—', lastActiveDays: 0, hasAlert: false };
                  return (
                    <TableRow key={s.id}>
                      <TableCell className="font-medium">
                        <Link to={`/instructor/students/${s.id}`} className="hover:underline text-primary">
                          {s.name}
                        </Link>
                      </TableCell>
                      <TableCell className="text-muted-foreground">{s.studentId}</TableCell>
                      <TableCell>{stats.avgCds}</TableCell>
                      <TableCell>
                        <Badge variant="secondary">{stats.highestConcept}</Badge>
                      </TableCell>
                      <TableCell className="text-muted-foreground">
                        {stats.lastActiveDays === 0 ? 'today' : `${stats.lastActiveDays}d ago`}
                      </TableCell>
                      <TableCell>
                        {stats.hasAlert ? (
                          <Badge variant="destructive">Alert</Badge>
                        ) : (
                          <Badge variant="outline">OK</Badge>
                        )}
                      </TableCell>
                    </TableRow>
                  );
                })
              )}
            </TableBody>
          </Table>
        </CardContent>
      </Card>
    </div>
  );
}
```

- [ ] **Step 3: Build the project**

Run: `cd frontend && npm run build`

Expected: exits 0.

- [ ] **Step 4: Commit**

```bash
git add frontend/src/pages/instructor/Students.jsx
git commit -m "feat(instructor-slice): port Students.tsx → Students.jsx"
```

---

## Task 11: Port `StudentDetail.tsx` → `StudentDetail.jsx` (embed analytics)

**Files:**
- Create: `frontend/src/pages/instructor/StudentDetail.jsx`

- [ ] **Step 1: Read the design source**

Run: `cat Frontend-Design/Frontend-Design/artifacts/codeinsight/src/pages/instructor/StudentDetail.tsx`

- [ ] **Step 2: Create the ported file**

Write `frontend/src/pages/instructor/StudentDetail.jsx` with the following content (JSX port of the 128-LOC TSX; embeds `MicroConceptAlertCard` + `LongitudinalProgressChart` per spec §3 row 4; renders a "Student not found" card when the param doesn't match a `MOCK_USERS` entry, per spec §7):

```jsx
import { Link, useParams } from 'react-router-dom';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Badge } from '@/components/ui/badge';
import { ChevronLeft } from 'lucide-react';
import { MOCK_USERS } from '@/data/mockData';
import MicroConceptAlertCard from '@/components/analytics/MicroConceptAlertCard';
import LongitudinalProgressChart from '@/components/analytics/LongitudinalProgressChart';
import '@/components/analytics/MicroConceptAlertCard.css';
import '@/components/analytics/LongitudinalProgressChart.css';

/**
 * Student detail — see spec §3 row 4.
 * Reads MOCK_USERS to find the student. Embeds the existing analytics
 * components (MicroConceptAlertCard, LongitudinalProgressChart) inside
 * their own <Card> shells.
 */
export default function InstructorStudentDetail() {
  const { id } = useParams();
  const student = MOCK_USERS.find((u) => u.id === id && u.role === 'student');

  if (!student) {
    return (
      <div className="space-y-4">
        <Button asChild variant="ghost" size="sm">
          <Link to="/instructor/students"><ChevronLeft className="w-4 h-4 mr-1" /> Back to students</Link>
        </Button>
        <Card>
          <CardContent className="p-6">
            <h2 className="text-lg font-semibold mb-2">Student not found</h2>
            <p className="text-muted-foreground">No student with id <code>{id}</code>.</p>
          </CardContent>
        </Card>
      </div>
    );
  }

  return (
    <div className="space-y-6">
      <div className="flex items-center justify-between">
        <div>
          <Button asChild variant="ghost" size="sm" className="mb-2 -ml-2">
            <Link to="/instructor/students"><ChevronLeft className="w-4 h-4 mr-1" /> Back to students</Link>
          </Button>
          <h1 className="text-3xl font-bold tracking-tight">{student.name}</h1>
          <p className="text-muted-foreground">{student.email} · {student.studentId}</p>
        </div>
        <Badge variant="outline">Active</Badge>
      </div>

      <div className="grid gap-6 md:grid-cols-2">
        <Card>
          <CardHeader>
            <CardTitle>Longitudinal Progress</CardTitle>
          </CardHeader>
          <CardContent>
            <LongitudinalProgressChart studentId={student.id} />
          </CardContent>
        </Card>
        <Card>
          <CardHeader>
            <CardTitle>Micro-Concept Insights</CardTitle>
          </CardHeader>
          <CardContent>
            <MicroConceptAlertCard studentId={student.id} />
          </CardContent>
        </Card>
      </div>
    </div>
  );
}
```

- [ ] **Step 3: Build the project**

Run: `cd frontend && npm run build`

Expected: exits 0.

- [ ] **Step 4: Commit**

```bash
git add frontend/src/pages/instructor/StudentDetail.jsx
git commit -m "feat(instructor-slice): port StudentDetail.tsx → StudentDetail.jsx (embed analytics)"
```

---

## Task 12: Port `Exercises.tsx` → `Exercises.jsx` (embed `ExerciseAccordion`)

**Files:**
- Modify: `frontend/src/pages/instructor/Exercises.jsx` (overwrite)

- [ ] **Step 1: Read the design source**

Run: `cat Frontend-Design/Frontend-Design/artifacts/codeinsight/src/pages/instructor/Exercises.tsx`

- [ ] **Step 2: Overwrite the page**

Replace `frontend/src/pages/instructor/Exercises.jsx` with the following content (JSX port of the 81-LOC TSX; embeds `ExerciseAccordion` per spec §3 row 5):

```jsx
import { Link } from 'react-router-dom';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Badge } from '@/components/ui/badge';
import { Table, TableBody, TableCell, TableHead, TableHeader, TableRow } from '@/components/ui/table';
import { Plus } from 'lucide-react';
import { MOCK_EXERCISES } from '@/data/mockData';
import ExerciseAccordion from '@/components/analytics/ExerciseAccordion';
import '@/components/analytics/ExerciseAccordion.css';

/**
 * Exercises list — see spec §3 row 5.
 * The new design's "Create Exercise" button is the CTA in the header; the
 * table row link to /instructor/exercises/:id/edit. The per-exercise
 * ExerciseAccordion lives below the table for richer detail.
 */
export default function InstructorExercises() {
  return (
    <div className="space-y-6">
      <div className="flex flex-col sm:flex-row sm:items-center justify-between gap-4">
        <div>
          <h1 className="text-3xl font-bold tracking-tight">Exercises</h1>
          <p className="text-muted-foreground">Manage programming assignments and test cases.</p>
        </div>
        <Button asChild>
          <Link to="/instructor/exercises/new" className="gap-2">
            <Plus className="w-4 h-4" /> Create Exercise
          </Link>
        </Button>
      </div>

      <Card>
        <CardContent className="p-0">
          <Table>
            <TableHeader>
              <TableRow>
                <TableHead>Title</TableHead>
                <TableHead>Concepts</TableHead>
                <TableHead>Difficulty</TableHead>
                <TableHead>Due</TableHead>
                <TableHead />
              </TableRow>
            </TableHeader>
            <TableBody>
              {MOCK_EXERCISES.map((e) => (
                <TableRow key={e.id}>
                  <TableCell className="font-medium">{e.title}</TableCell>
                  <TableCell>
                    <div className="flex gap-1 flex-wrap">
                      {e.conceptTags.map((t) => <Badge key={t} variant="secondary">{t}</Badge>)}
                    </div>
                  </TableCell>
                  <TableCell>
                    <Badge variant={e.difficulty === 'Beginner' ? 'outline' : e.difficulty === 'Intermediate' ? 'secondary' : 'destructive'}>
                      {e.difficulty}
                    </Badge>
                  </TableCell>
                  <TableCell className="text-muted-foreground">
                    {new Date(e.dueDate).toLocaleDateString()}
                  </TableCell>
                  <TableCell className="text-right">
                    <Button asChild variant="ghost" size="sm">
                      <Link to={`/instructor/exercises/${e.id}/edit`}>Edit</Link>
                    </Button>
                  </TableCell>
                </TableRow>
              ))}
            </TableBody>
          </Table>
        </CardContent>
      </Card>

      <Card>
        <CardHeader>
          <CardTitle>Exercise Detail</CardTitle>
        </CardHeader>
        <CardContent>
          <ExerciseAccordion />
        </CardContent>
      </Card>
    </div>
  );
}
```

- [ ] **Step 3: Build the project**

Run: `cd frontend && npm run build`

Expected: exits 0.

- [ ] **Step 4: Commit**

```bash
git add frontend/src/pages/instructor/Exercises.jsx
git commit -m "feat(instructor-slice): port Exercises.tsx → Exercises.jsx (embed ExerciseAccordion)"
```

---

## Task 13: Port `ExerciseForm.tsx` → `ExerciseForm.jsx` (new + edit)

**Files:**
- Modify: `frontend/src/pages/instructor/ExerciseForm.jsx` (overwrite)

- [ ] **Step 1: Read the design source**

Run: `cat Frontend-Design/Frontend-Design/artifacts/codeinsight/src/pages/instructor/ExerciseForm.tsx`

- [ ] **Step 2: Overwrite the page**

Replace `frontend/src/pages/instructor/ExerciseForm.jsx` with the following content (JSX port of the 158-LOC TSX; handles both `/instructor/exercises/new` and `/instructor/exercises/:id/edit` per spec §3 row 6; renders a "Exercise not found" card when the edit id doesn't match):

```jsx
import { useState } from 'react';
import { Link, useParams } from 'react-router-dom';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Input } from '@/components/ui/input';
import { Label } from '@/components/ui/label';
import { Textarea } from '@/components/ui/textarea';
import { Select, SelectContent, SelectItem, SelectTrigger, SelectValue } from '@/components/ui/select';
import { ChevronLeft } from 'lucide-react';
import { MOCK_EXERCISES } from '@/data/mockData';

/**
 * Exercise form — see spec §3 row 6.
 * One component, two modes: 'new' (from /instructor/exercises/new) and
 * 'edit' (from /instructor/exercises/:id/edit). The form holds local state
 * for the 5 fields; submission is a console log for this mock slice.
 */
const DIFFICULTIES = ['Beginner', 'Intermediate', 'Advanced'];

export default function InstructorExerciseForm() {
  const { id } = useParams();
  const isEdit = id && id !== 'new';
  const existing = isEdit ? MOCK_EXERCISES.find((e) => e.id === id) : null;

  const [title, setTitle] = useState(existing?.title ?? '');
  const [description, setDescription] = useState(existing?.description ?? '');
  const [difficulty, setDifficulty] = useState(existing?.difficulty ?? 'Beginner');
  const [starterCode, setStarterCode] = useState(existing?.starterCode ?? '');
  const [dueDate, setDueDate] = useState(existing?.dueDate?.slice(0, 10) ?? '');

  if (isEdit && !existing) {
    return (
      <div className="space-y-4">
        <Button asChild variant="ghost" size="sm">
          <Link to="/instructor/exercises"><ChevronLeft className="w-4 h-4 mr-1" /> Back to exercises</Link>
        </Button>
        <Card>
          <CardContent className="p-6">
            <h2 className="text-lg font-semibold mb-2">Exercise not found</h2>
            <p className="text-muted-foreground">No exercise with id <code>{id}</code>.</p>
          </CardContent>
        </Card>
      </div>
    );
  }

  const handleSubmit = (e) => {
    e.preventDefault();
    // Real-API cutover: POST /api/exercises or PUT /api/exercises/:id
    console.log('submit', { mode: isEdit ? 'edit' : 'new', id, title, description, difficulty, starterCode, dueDate });
  };

  return (
    <div className="space-y-6 max-w-3xl">
      <div>
        <Button asChild variant="ghost" size="sm" className="mb-2 -ml-2">
          <Link to="/instructor/exercises"><ChevronLeft className="w-4 h-4 mr-1" /> Back to exercises</Link>
        </Button>
        <h1 className="text-3xl font-bold tracking-tight">{isEdit ? 'Edit Exercise' : 'New Exercise'}</h1>
      </div>

      <form onSubmit={handleSubmit}>
        <Card>
          <CardHeader>
            <CardTitle>Details</CardTitle>
          </CardHeader>
          <CardContent className="space-y-4">
            <div className="space-y-1.5">
              <Label htmlFor="title">Title</Label>
              <Input id="title" value={title} onChange={(e) => setTitle(e.target.value)} required />
            </div>
            <div className="space-y-1.5">
              <Label htmlFor="description">Description</Label>
              <Textarea id="description" rows={4} value={description} onChange={(e) => setDescription(e.target.value)} required />
            </div>
            <div className="grid grid-cols-2 gap-4">
              <div className="space-y-1.5">
                <Label htmlFor="difficulty">Difficulty</Label>
                <Select value={difficulty} onValueChange={setDifficulty}>
                  <SelectTrigger id="difficulty"><SelectValue /></SelectTrigger>
                  <SelectContent>
                    {DIFFICULTIES.map((d) => <SelectItem key={d} value={d}>{d}</SelectItem>)}
                  </SelectContent>
                </Select>
              </div>
              <div className="space-y-1.5">
                <Label htmlFor="dueDate">Due Date</Label>
                <Input id="dueDate" type="date" value={dueDate} onChange={(e) => setDueDate(e.target.value)} />
              </div>
            </div>
            <div className="space-y-1.5">
              <Label htmlFor="starterCode">Starter Code</Label>
              <Textarea
                id="starterCode"
                rows={10}
                value={starterCode}
                onChange={(e) => setStarterCode(e.target.value)}
                className="font-mono text-sm"
              />
            </div>
            <div className="flex justify-end gap-2 pt-2">
              <Button asChild variant="ghost"><Link to="/instructor/exercises">Cancel</Link></Button>
              <Button type="submit">{isEdit ? 'Save Changes' : 'Create Exercise'}</Button>
            </div>
          </CardContent>
        </Card>
      </form>
    </div>
  );
}
```

- [ ] **Step 3: Build the project**

Run: `cd frontend && npm run build`

Expected: exits 0.

- [ ] **Step 4: Commit**

```bash
git add frontend/src/pages/instructor/ExerciseForm.jsx
git commit -m "feat(instructor-slice): port ExerciseForm.tsx → ExerciseForm.jsx"
```

---

## Task 14: Port `Warnings.tsx` → `Warnings.jsx` (embed `StudentAlertCard`)

**Files:**
- Create: `frontend/src/pages/instructor/Warnings.jsx`

- [ ] **Step 1: Read the design source**

Run: `cat Frontend-Design/Frontend-Design/artifacts/codeinsight/src/pages/instructor/Warnings.tsx`

- [ ] **Step 2: Create the ported file**

Write `frontend/src/pages/instructor/Warnings.jsx` with the following content (JSX port of the 74-LOC TSX; embeds `StudentAlertCard` per spec §3 row 7):

```jsx
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Bell } from 'lucide-react';
import StudentAlertCard from '@/components/analytics/StudentAlertCard';

/**
 * Early warnings — see spec §3 row 7.
 * The StudentAlertCard analytics component renders the per-student alert
 * cards; this host page provides the title, subhead, and Card frame.
 */
export default function InstructorWarnings() {
  return (
    <div className="space-y-6">
      <div>
        <h1 className="text-3xl font-bold tracking-tight">Early Warnings</h1>
        <p className="text-muted-foreground">Students showing signs of falling behind.</p>
      </div>

      <Card>
        <CardHeader className="flex flex-row items-center gap-2">
          <Bell className="w-4 h-4 text-muted-foreground" />
          <CardTitle>Active Alerts</CardTitle>
        </CardHeader>
        <CardContent>
          <StudentAlertCard />
        </CardContent>
      </Card>
    </div>
  );
}
```

- [ ] **Step 3: Build the project**

Run: `cd frontend && npm run build`

Expected: exits 0.

- [ ] **Step 4: Commit**

```bash
git add frontend/src/pages/instructor/Warnings.jsx
git commit -m "feat(instructor-slice): port Warnings.tsx → Warnings.jsx (embed StudentAlertCard)"
```

---

## Task 15: Port `Reports.tsx` → `Reports.jsx` (embed longitudinal chart + tab)

**Files:**
- Modify: `frontend/src/pages/instructor/Reports.jsx` (overwrite)

- [ ] **Step 1: Read the design source**

Run: `cat Frontend-Design/Frontend-Design/artifacts/codeinsight/src/pages/instructor/Reports.tsx`

- [ ] **Step 2: Overwrite the page**

Replace `frontend/src/pages/instructor/Reports.jsx` with the following content (JSX port of the 100-LOC TSX; embeds `ClassWideLongitudinalChart` + `LongitudinalTab` + uses `ResponsiveLineChart` for the class-average trend, per spec §3 row 8; reads `MOCK_REPORTS_TIMELINE` and `MOCK_MOST_DIFFICULT_CONCEPTS`):

```jsx
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Tabs, TabsList, TabsTrigger, TabsContent } from '@/components/ui/tabs';
import ResponsiveLineChart from '@/components/charts/ResponsiveLineChart';
import { MOCK_REPORTS_TIMELINE, MOCK_MOST_DIFFICULT_CONCEPTS } from '@/data/mockData';
import ClassWideLongitudinalChart from '@/components/analytics/ClassWideLongitudinalChart';
import LongitudinalTab from '@/components/analytics/LongitudinalTab';

/**
 * Reports — see spec §3 row 8.
 * Three sections: class trend (ResponsiveLineChart on MOCK_REPORTS_TIMELINE),
 * the embedded ClassWideLongitudinalChart analytics component, and the
 * LongitudinalTab (with Most-Difficult-Concepts data).
 */
export default function InstructorReports() {
  const lineData = [
    {
      id: 'class avg',
      data: MOCK_REPORTS_TIMELINE.map((p) => ({ x: p.week, y: p.avgCds })),
    },
  ];

  return (
    <div className="space-y-6">
      <div>
        <h1 className="text-3xl font-bold tracking-tight">Reports</h1>
        <p className="text-muted-foreground">Class-wide trends and concept-level difficulty.</p>
      </div>

      <Tabs defaultValue="trend">
        <TabsList>
          <TabsTrigger value="trend">Class Trend</TabsTrigger>
          <TabsTrigger value="longitudinal">Longitudinal</TabsTrigger>
          <TabsTrigger value="concepts">Most Difficult Concepts</TabsTrigger>
        </TabsList>
        <TabsContent value="trend">
          <Card>
            <CardHeader>
              <CardTitle>Weekly Class Average CDS</CardTitle>
            </CardHeader>
            <CardContent className="h-72">
              <ResponsiveLineChart data={lineData} xKey="x" yKey="y" seriesKey="class avg" />
            </CardContent>
          </Card>
        </TabsContent>
        <TabsContent value="longitudinal">
          <ClassWideLongitudinalChart />
        </TabsContent>
        <TabsContent value="concepts">
          <LongitudinalTab data={MOCK_MOST_DIFFICULT_CONCEPTS} />
        </TabsContent>
      </Tabs>
    </div>
  );
}
```

- [ ] **Step 3: Build the project**

Run: `cd frontend && npm run build`

Expected: exits 0. If `ResponsiveLineChart`'s prop signature differs, open `frontend/src/components/charts/ResponsiveLineChart.jsx` and adjust the call so the lineData shape matches what the component expects (e.g., `xKey`/`yKey` may be named differently in the existing implementation). Do not change the analytics component's own logic.

- [ ] **Step 4: Commit**

```bash
git add frontend/src/pages/instructor/Reports.jsx
git commit -m "feat(instructor-slice): port Reports.tsx → Reports.jsx (embed longitudinal chart + tab)"
```

---

## Task 16: Port `Violations.tsx` → `Violations.jsx`

**Files:**
- Create: `frontend/src/pages/instructor/Violations.jsx`

- [ ] **Step 1: Read the design source**

Run: `cat Frontend-Design/Frontend-Design/artifacts/codeinsight/src/pages/instructor/Violations.tsx`

- [ ] **Step 2: Create the ported file**

Write `frontend/src/pages/instructor/Violations.jsx` with the following content (JSX port of the 65-LOC TSX; reads `MOCK_STRUCTURE_VIOLATIONS`):

```jsx
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Badge } from '@/components/ui/badge';
import { Table, TableBody, TableCell, TableHead, TableHeader, TableRow } from '@/components/ui/table';
import { AlertOctagon } from 'lucide-react';
import { MOCK_STRUCTURE_VIOLATIONS } from '@/data/mockData';

const SEVERITY_VARIANT = {
  high: 'destructive',
  medium: 'default',
  low: 'secondary',
};

/**
 * Structure violations — see spec §3 row 9.
 * Renders MOCK_STRUCTURE_VIOLATIONS as a Table; severity is a colored Badge.
 */
export default function InstructorViolations() {
  return (
    <div className="space-y-6">
      <div>
        <h1 className="text-3xl font-bold tracking-tight">Structure Violations</h1>
        <p className="text-muted-foreground">Output and structural issues detected at submission time.</p>
      </div>

      <Card>
        <CardHeader className="flex flex-row items-center gap-2">
          <AlertOctagon className="w-4 h-4 text-muted-foreground" />
          <CardTitle>Detected Violations</CardTitle>
        </CardHeader>
        <CardContent className="p-0">
          <Table>
            <TableHeader>
              <TableRow>
                <TableHead>Student</TableHead>
                <TableHead>Exercise</TableHead>
                <TableHead>Concept</TableHead>
                <TableHead>Type</TableHead>
                <TableHead>Message</TableHead>
                <TableHead>Severity</TableHead>
                <TableHead>Time</TableHead>
              </TableRow>
            </TableHeader>
            <TableBody>
              {MOCK_STRUCTURE_VIOLATIONS.map((v) => (
                <TableRow key={v.id}>
                  <TableCell className="font-medium">{v.student}</TableCell>
                  <TableCell>{v.exercise}</TableCell>
                  <TableCell><Badge variant="secondary">{v.concept}</Badge></TableCell>
                  <TableCell>{v.type}</TableCell>
                  <TableCell className="text-muted-foreground max-w-md">{v.message}</TableCell>
                  <TableCell>
                    <Badge variant={SEVERITY_VARIANT[v.severity] || 'outline'}>{v.severity}</Badge>
                  </TableCell>
                  <TableCell className="text-muted-foreground text-xs">{v.time}</TableCell>
                </TableRow>
              ))}
            </TableBody>
          </Table>
        </CardContent>
      </Card>
    </div>
  );
}
```

- [ ] **Step 3: Build the project**

Run: `cd frontend && npm run build`

Expected: exits 0.

- [ ] **Step 4: Commit**

```bash
git add frontend/src/pages/instructor/Violations.jsx
git commit -m "feat(instructor-slice): port Violations.tsx → Violations.jsx"
```

---

## Task 17: Port `Integrity.tsx` → `Integrity.jsx` (embed flag dropdown + banner)

**Files:**
- Create: `frontend/src/pages/instructor/Integrity.jsx`

- [ ] **Step 1: Read the design source**

Run: `cat Frontend-Design/Frontend-Design/artifacts/codeinsight/src/pages/instructor/Integrity.tsx`

- [ ] **Step 2: Create the ported file**

Write `frontend/src/pages/instructor/Integrity.jsx` with the following content (JSX port of the 88-LOC TSX; embeds `IntegrityMonitoringBanner` + `IntegrityFlagDropdown` per spec §3 row 10; reads `MOCK_INTEGRITY_FLAGS`):

```jsx
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Badge } from '@/components/ui/badge';
import { Table, TableBody, TableCell, TableHead, TableHeader, TableRow } from '@/components/ui/table';
import { ShieldAlert } from 'lucide-react';
import IntegrityMonitoringBanner from '@/components/analytics/IntegrityMonitoringBanner';
import IntegrityFlagDropdown from '@/components/analytics/IntegrityFlagDropdown';
import { MOCK_INTEGRITY_FLAGS } from '@/data/mockData';
import '@/components/analytics/IntegrityFlagDropdown.css';

/**
 * Academic Integrity — see spec §3 row 10.
 * Banner at the top (IntegrityMonitoringBanner), followed by a Table of
 * MOCK_INTEGRITY_FLAGS with the IntegrityFlagDropdown as the per-row
 * review action.
 */
export default function InstructorIntegrity() {
  return (
    <div className="space-y-6">
      <div>
        <h1 className="text-3xl font-bold tracking-tight">Academic Integrity</h1>
        <p className="text-muted-foreground">Behavioral and structural anomalies requiring review.</p>
      </div>

      <IntegrityMonitoringBanner />

      <Card>
        <CardHeader className="flex flex-row items-center gap-2">
          <ShieldAlert className="w-4 h-4 text-muted-foreground" />
          <CardTitle>Active Flags</CardTitle>
        </CardHeader>
        <CardContent className="p-0">
          <Table>
            <TableHeader>
              <TableRow>
                <TableHead>Student</TableHead>
                <TableHead>Exercise</TableHead>
                <TableHead>Type</TableHead>
                <TableHead>Confidence</TableHead>
                <TableHead>Description</TableHead>
                <TableHead>Time</TableHead>
                <TableHead />
              </TableRow>
            </TableHeader>
            <TableBody>
              {MOCK_INTEGRITY_FLAGS.map((f) => (
                <TableRow key={f.id}>
                  <TableCell className="font-medium">{f.student}</TableCell>
                  <TableCell>{f.exercise}</TableCell>
                  <TableCell><Badge variant="destructive">{f.type}</Badge></TableCell>
                  <TableCell>{f.confidence}%</TableCell>
                  <TableCell className="text-muted-foreground max-w-md">{f.desc}</TableCell>
                  <TableCell className="text-muted-foreground text-xs">{f.time}</TableCell>
                  <TableCell>
                    <IntegrityFlagDropdown flagId={f.id} />
                  </TableCell>
                </TableRow>
              ))}
            </TableBody>
          </Table>
        </CardContent>
      </Card>
    </div>
  );
}
```

- [ ] **Step 3: Build the project**

Run: `cd frontend && npm run build`

Expected: exits 0.

- [ ] **Step 4: Commit**

```bash
git add frontend/src/pages/instructor/Integrity.jsx
git commit -m "feat(instructor-slice): port Integrity.tsx → Integrity.jsx (embed flag dropdown + banner)"
```

---

## Task 18: Update `Sidebar.jsx` (10 instructor links, design paths, keep `My Sections`)

**Files:**
- Modify: `frontend/src/components/Sidebar.jsx` (add 2 nav items, add 2 icon imports, **keep** `My Sections` as a distinct nav item)

> **Spec deviation note:** The spec said to rename `My Sections` → `Students`. The user's directive 2026-06-04 ("don't remove the section management") requires section management to remain visible in the sidebar. We keep `My Sections` pointing at `/instructor/my-sections` (which is currently an alias for `Sections.jsx`) and add a new `Students` nav item for the design-canonical `/instructor/students`. Final nav has 10 links, not 9.

- [ ] **Step 1: Add the 2 new icon imports**

In `frontend/src/components/Sidebar.jsx`, add `LayoutGrid` and `AlertOctagon` to the existing `lucide-react` import block (lines 2-16). The updated imports look like:

```jsx
import {
  LayoutDashboard,
  LayoutGrid,
  ListChecks,
  PlusSquare,
  Bell,
  Settings,
  Terminal,
  TrendingUp,
  FileBarChart2,
  PanelLeftClose,
  PanelLeftOpen,
  LogOut,
  ShieldAlert,
  AlertOctagon,
  Users,
  User,
} from 'lucide-react';
```

(`Users` is the new icon for the design-canonical Students page; the legacy `My Sections` keeps its existing icon — `LayoutDashboard` or similar — currently in use.)

- [ ] **Step 2: Replace the `instructorLinks` array (10 items)**

Replace the `instructorLinks` array (lines 55-63) with:

```jsx
  const instructorLinks = [
    { to: '/instructor/dashboard',  label: 'Dashboard',   icon: LayoutDashboard, end: true },
    { to: '/instructor/heatmap',    label: 'Heatmap',     icon: LayoutGrid },
    { to: '/instructor/students',   label: 'Students',    icon: Users,           end: true },
    { to: '/instructor/my-sections',label: 'My Sections', icon: ListChecks },
    { to: '/instructor/exercises',  label: 'Exercises',   icon: PlusSquare },
    { to: '/instructor/warnings',   label: 'Warnings',    icon: Bell },
    { to: '/instructor/reports',    label: 'Reports',     icon: FileBarChart2 },
    { to: '/instructor/violations', label: 'Violations',  icon: AlertOctagon },
    { to: '/instructor/integrity',  label: 'Integrity',   icon: ShieldAlert },
    { to: '/instructor/developer',  label: 'Developer',   icon: Settings },
  ];
```

Two distinct surfaces: `Students` → design-canonical `/instructor/students` (new per-student analytics list, `Users` icon), `My Sections` → `/instructor/my-sections` (legacy `Sections.jsx`, **preserved per user directive**, `ListChecks` icon reused). The `end: true` on `Students` prevents the parent link from lighting up on the detail page.

- [ ] **Step 3: Build the project**

Run: `cd frontend && npm run build`

Expected: exits 0.

- [ ] **Step 4: Commit**

```bash
git add frontend/src/components/Sidebar.jsx
git commit -m "feat(instructor-slice): update Sidebar.jsx (10 instructor links, keep My Sections, add Students)"
```

---

## Task 19: Re-point 10 instructor routes in `App.jsx` (design-first)

**Files:**
- Modify: `frontend/src/App.jsx` (replace 10 instructor imports + their routes; **keep** 3 section-management imports: `InstructorSections`, `SectionDetail`, `AcademicIntegrityFlags`)

- [ ] **Step 1: Replace the 10 instructor imports — keep the 3 section-management imports**

In `frontend/src/App.jsx`, replace the 10 instructor imports (lines 6-14). The 10 new design-aligned imports are added, and the 3 preserved legacy imports (`InstructorSections`, `SectionDetail`, `AcademicIntegrityFlags`) are kept (per user directive 2026-06-04, these are still in active use by the section-management routes). The full new import block is:

```jsx
import InstructorDashboard from './pages/instructor/Dashboard';
import InstructorHeatmap from './pages/instructor/Heatmap';
import InstructorStudents from './pages/instructor/Students';
import InstructorStudentDetail from './pages/instructor/StudentDetail';
import InstructorExercises from './pages/instructor/Exercises';
import InstructorExerciseForm from './pages/instructor/ExerciseForm';
import InstructorWarnings from './pages/instructor/Warnings';
import InstructorReports from './pages/instructor/Reports';
import InstructorViolations from './pages/instructor/Violations';
import InstructorIntegrity from './pages/instructor/Integrity';
// Section management — preserved per user directive 2026-06-04
import InstructorSections from './pages/instructor/Sections';
import SectionDetail from './pages/instructor/SectionDetail';
import AcademicIntegrityFlags from './pages/instructor/AcademicIntegrityFlags';
```

(`InstructorDeveloper` stays — its import is unchanged.)

- [ ] **Step 2: Replace the 10 instructor route blocks**

Replace the 10 instructor `<Route>` blocks (lines 43-87, the section between the comment `{/* Instructor Routes */}` and `{/* Student Routes */}`) with the design-canonical routes from spec §4.1. Add `pageTitle` to every route (sticky top bar), and add the 4 currently-broken aliases from spec §4.3. The new instructor block is:

```jsx
        {/* Instructor Routes — design paths canonical */}
        <Route path="/instructor/dashboard" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Dashboard">
            <InstructorDashboard />
          </ProtectedRoute>
        } />
        <Route path="/instructor/heatmap" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Class Heatmap">
            <InstructorHeatmap />
          </ProtectedRoute>
        } />
        <Route path="/instructor/students" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Students">
            <InstructorStudents />
          </ProtectedRoute>
        } />
        <Route path="/instructor/students/:id" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Student Detail">
            <InstructorStudentDetail />
          </ProtectedRoute>
        } />
        <Route path="/instructor/exercises" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Exercises">
            <InstructorExercises />
          </ProtectedRoute>
        } />
        <Route path="/instructor/exercises/new" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="New Exercise">
            <InstructorExerciseForm />
          </ProtectedRoute>
        } />
        <Route path="/instructor/exercises/:id/edit" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Edit Exercise">
            <InstructorExerciseForm />
          </ProtectedRoute>
        } />
        <Route path="/instructor/warnings" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Early Warnings">
            <InstructorWarnings />
          </ProtectedRoute>
        } />
        <Route path="/instructor/reports" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Reports">
            <InstructorReports />
          </ProtectedRoute>
        } />
        <Route path="/instructor/violations" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Structure Violations">
            <InstructorViolations />
          </ProtectedRoute>
        } />
        <Route path="/instructor/integrity" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Academic Integrity">
            <InstructorIntegrity />
          </ProtectedRoute>
        } />
        <Route path="/instructor/developer" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Developer">
            <InstructorDeveloper />
          </ProtectedRoute>
        } />

        {/* Instructor alias routes (CodeInsight paths kept working) */}
        <Route path="/instructor" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Dashboard">
            <InstructorDashboard />
          </ProtectedRoute>
        } />
        {/* /instructor/create-exercise and /instructor/alerts are aliases for the design forms */}
        <Route path="/instructor/create-exercise" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="New Exercise">
            <InstructorExerciseForm />
          </ProtectedRoute>
        } />
        <Route path="/instructor/alerts" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Early Warnings">
            <InstructorWarnings />
          </ProtectedRoute>
        } />
        {/* Section management routes — PRESERVED per user directive 2026-06-04.
            /instructor/my-sections and /instructor/sections stay on the legacy
            Sections.jsx / SectionDetail.jsx / AcademicIntegrityFlags.jsx files. */}
        <Route path="/instructor/sections" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Sections">
            <InstructorSections />
          </ProtectedRoute>
        } />
        <Route path="/instructor/sections/:sectionId" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Section Detail">
            <SectionDetail />
          </ProtectedRoute>
        } />
        <Route path="/instructor/sections/:sectionId/academic-integrity" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Academic Integrity">
            <AcademicIntegrityFlags />
          </ProtectedRoute>
        } />
        <Route path="/instructor/my-sections" element={
          <ProtectedRoute requiredRole="instructor" pageTitle="Sections">
            <InstructorSections />
          </ProtectedRoute>
        } />
```

Also remove the 4 currently-broken alias routes in the "Design-aligned URL paths (new aliases for design nav parity)" block at the bottom of the existing file (lines 142-166) — they're replaced by the canonical routes above. The student alias block at lines 132-141 stays untouched.

- [ ] **Step 3: Build the project**

Run: `cd frontend && npm run build`

Expected: exits 0. If a build error mentions a missing import, double-check that all 10 new instructor imports have their corresponding files on disk (Tasks 8-17 created them).

- [ ] **Step 4: Commit**

```bash
git add frontend/src/App.jsx
git commit -m "feat(instructor-slice): re-point 10 instructor routes in App.jsx (design-first)"
```

---

## Task 20: Delete 4 obsolete CodeInsight instructor pages (sections preserved)

**Files:**
- Delete: `frontend/src/pages/instructor/CreateExercise.jsx`
- Delete: `frontend/src/pages/instructor/EditExercise.jsx`
- Delete: `frontend/src/pages/instructor/Alerts.jsx`
- Delete (verify): `frontend/src/pages/instructor/Analytics.jsx` (already removed in prior work)

> **Spec deviation note:** The spec said to delete 7 files, including `Sections.jsx`, `SectionDetail.jsx`, and `AcademicIntegrityFlags.jsx`. Per the user's directive 2026-06-04, section management is preserved — those 3 files stay. This task deletes only 4 files (3 confirmed + 1 verify).

- [ ] **Step 1: Verify no surviving code references the deleted files**

Run:

```bash
cd frontend && grep -rn "from.*['\"]\\.\\./.*instructor/CreateExercise['\"]" src 2>/dev/null
cd frontend && grep -rn "from.*['\"]\\.\\./.*instructor/EditExercise['\"]" src 2>/dev/null
cd frontend && grep -rn "from.*['\"]\\.\\./.*instructor/Alerts['\"]" src 2>/dev/null
cd frontend && grep -rn "from.*['\"]\\.\\./.*instructor/Analytics['\"]" src 2>/dev/null
```

Expected: each command returns 0 matches. If any return matches, fix the importer (the App.jsx alias block in Task 19 is the most likely culprit — ensure each alias points at the new design component, not the deleted old one).

- [ ] **Step 2: Delete the 3 (or 4) files**

```bash
git rm frontend/src/pages/instructor/CreateExercise.jsx
git rm frontend/src/pages/instructor/EditExercise.jsx
git rm frontend/src/pages/instructor/Alerts.jsx
# Analytics.jsx may already be gone — `git rm` will error harmlessly; ignore
git rm -f frontend/src/pages/instructor/Analytics.jsx 2>/dev/null || true
```

- [ ] **Step 3: Build the project**

Run: `cd frontend && npm run build`

Expected: exits 0. The build is the proof that no surviving code imports the deleted files.

- [ ] **Step 4: Commit**

```bash
git commit -m "feat(instructor-slice): delete 4 obsolete CodeInsight instructor pages (sections preserved)"
```

---

## Task 21: Smoke test all 12 routes + build green

**Files:** None (verification + report).

- [ ] **Step 1: Build the project**

Run: `cd frontend && npm run build`

Expected: exits 0. If the build fails, read the error carefully and fix the offending file (most common: a missing import from a renamed component). Do not proceed to step 2 until the build is green.

- [ ] **Step 2: Start the dev server in the background**

Run (in a separate terminal or with `run_in_background: true`):

```bash
cd frontend && npm run dev
```

Expected: Vite reports `Local: http://localhost:5173/` and exits 0. (Leave the process running.)

- [ ] **Step 3: Walk through the 12 instructor routes + 4 student routes**

For each of the following URLs, fetch the page in a browser (or `curl` the SPA — Vite returns the same `index.html` for all paths):

| URL | Expected pageTitle |
| --- | --- |
| `/instructor/dashboard` | `Dashboard` |
| `/instructor/heatmap` | `Class Heatmap` |
| `/instructor/students` | `Students` |
| `/instructor/students/u2` | `Student Detail` |
| `/instructor/exercises` | `Exercises` |
| `/instructor/exercises/new` | `New Exercise` |
| `/instructor/exercises/e1/edit` | `Edit Exercise` |
| `/instructor/warnings` | `Early Warnings` |
| `/instructor/reports` | `Reports` |
| `/instructor/violations` | `Structure Violations` |
| `/instructor/integrity` | `Academic Integrity` |
| `/instructor/developer` | `Developer` |
| `/student` | `Dashboard` |
| `/student/exercises` | `Exercises` |
| `/student/exercises/e1` | `Code Editor` |
| `/student/progress` | (no title) |

Expected for each: page renders without a console error; `<h1>` matches the expected `pageTitle`; theme toggle is visible in the top bar; on `/student/exercises/e1` the Monaco editor mounts (look for the toolbar showing `main.cpp` and the line numbers gutter).

- [ ] **Step 4: Verify the theme toggle**

In a browser, on any of the routes above:

1. Click the **Sun** button — sidebar and cards re-skin to the light blue palette (or stay the same if already light).
2. Click the **Moon** button — sidebar turns dark teal (`#0f0f1a`), text turns light, primary buttons turn teal.
3. Click the **Shield** button — sidebar turns maroon, primary buttons turn maroon, gold accents appear.
4. Hard-refresh the page (`Cmd-Shift-R` / `Ctrl-F5`). The theme you picked persists.
5. Open DevTools → Elements → inspect `<html>` — the `data-theme` attribute is `"dark"` or `"psu"` (or absent for light).

- [ ] **Step 5: Verify Monaco live re-theming**

On `/student/exercises/e1` (Monaco must be mounted):

1. Note the editor's current colors (white bg in light theme).
2. Click **Moon** in the theme toggle. Within ~100ms, the editor's background turns dark (`#0a1018`) and the editor's cursor turns teal. The editor does NOT remount — the typing cursor stays where it was.
3. Click **Shield** in the theme toggle. The editor's background turns white again, but the cursor and tokens pick up maroon (`#7B0F1B`).

- [ ] **Step 6: Stop the dev server**

Run: kill the background `npm run dev` process started in step 2.

- [ ] **Step 7: Final build + commit**

Run: `cd frontend && npm run build` (final check; exits 0).

Commit the verification artifacts (a final build status note can go in the report, no code changes here). If the build produces no new artifacts, the commit can be:

```bash
git commit --allow-empty -m "feat(instructor-slice): smoke test all 12 routes + build green"
```

(The `docs/superpowers/plans/2026-06-04-frontend-first-instructor-slice-report.md` is the final report; it lives in a follow-up task in execution, not in this plan.)

- [ ] **Step 8: Hand off**

Tell the user the slice is complete. The 21 commits, the green build, and the smoke-test results are the deliverable. A final report is written to `docs/superpowers/plans/2026-06-04-frontend-first-instructor-slice-report.md` after this task.

---

## Self-Review Notes (kept inline per the writing-plans skill)

- **Spec coverage:** Each spec §13 success criterion has a task. Theme criteria 8/9/10 are covered by Tasks 1-5; Monaco criterion 10 by Task 6; the 10 instructor routes by Tasks 8-19; deletion by Task 20; build green + smoke by Task 21. Analytics embedding is called out in Tasks 8 (ClassMisconceptionReport, IntegrityMonitoringBanner), 11 (MicroConceptAlertCard, LongitudinalProgressChart), 12 (ExerciseAccordion), 14 (StudentAlertCard), 15 (ClassWideLongitudinalChart, LongitudinalTab, ResponsiveLineChart), and 17 (IntegrityFlagDropdown, IntegrityMonitoringBanner).
- **Placeholder scan:** No "TBD", "TODO", or vague "handle appropriately" language. Every step either shows the full file content or a precise diff (steps 1-4 of Task 4, the header change in Task 5, the App.jsx route replacement in Task 19). The only "verify" step is the grep in Task 20 step 1, which is concrete and runnable.
- **Type consistency:** `MOCK_STUDENT_STATS`, `MOCK_HEATMAP`, `MOCK_INTEGRITY_FLAGS`, `MOCK_STRUCTURE_VIOLATIONS`, `MOCK_REPORTS_TIMELINE`, `MOCK_MOST_DIFFICULT_CONCEPTS` are introduced in Task 7 and read in Tasks 9, 10, 15, 16, 17. The `useTheme()` / `ThemeProvider` / `DEFAULT_THEME` / `MONACO_THEMES` / `registerMonacoThemes` exports introduced in Tasks 1-2 are consumed in Tasks 4, 5, 6. `Card` / `CardContent` / `CardHeader` / `CardTitle` / `Table` / `Badge` / `Button` / `Input` / `Textarea` / `Label` / `Select` / `Tabs` primitives are used consistently across the 10 port tasks.
- **Theme attribute handling:** Task 1's `applyThemeAttribute` removes `data-theme` when the value is `light` (the default); the spec calls this out explicitly in §2.4. Task 3's `[data-theme="dark"]` and `[data-theme="psu"]` blocks are mutually exclusive with `:root` and `.dark`, so a single page load shows exactly one palette.
- **Error handling:** Task 6's `parseErrorBlocks` and `goToErrorLine` are the Monaco error-jump behavior from the legacy (spec §3.1). Task 11's "Student not found" card and Task 13's "Exercise not found" card cover spec §7.
- **Embedded analytics components' own fetches:** Untouched (spec §2.3 / §6.3). The 9 analytics components keep their existing `useEffect` → API logic. They may render empty/loading states when offline; this is acceptable for a mock slice.
- **Commit count:** 21. Theme and Monaco commits come first (Tasks 1-6), then mock data (Task 7), then the 10 page ports (Tasks 8-17), then Sidebar + App.jsx (Tasks 18-19), then deletion (Task 20), then the build-green gate (Task 21).
- **Spec deviations (user-driven):**
  - **Section management preserved.** Spec §11 said to delete 7 files including `Sections.jsx`, `SectionDetail.jsx`, `AcademicIntegrityFlags.jsx`. Per user directive 2026-06-04 ("don't remove the section management of the instructor side"), those 3 files are kept and the corresponding 3 routes (`/instructor/sections`, `/instructor/sections/:sectionId`, `/instructor/sections/:sectionId/academic-integrity`, `/instructor/my-sections`) keep pointing at them. Task 20 now deletes 4 files, not 7.
  - **Sidebar keeps `My Sections`.** Spec §5.1 said to rename `My Sections` → `Students`. The user directive forces `My Sections` to stay (so the preserved section-management file is reachable from the sidebar). A new `Students` nav item is added in Task 18 for the design-canonical `/instructor/students`. Final instructorLinks array has 10 items, not 9.
  - **App.jsx keeps 3 legacy instructor imports.** `InstructorSections`, `SectionDetail`, `AcademicIntegrityFlags` are not removed in Task 19, because the preserved section-management routes still reference them.
  - **New file `frontend/src/pages/instructor/StudentDetail.jsx` is independent of `SectionDetail.jsx`.** `StudentDetail` is a per-student analytics view (`/instructor/students/:id`); `SectionDetail` is the per-section management view (`/instructor/sections/:sectionId`). Two distinct surfaces; both kept.
