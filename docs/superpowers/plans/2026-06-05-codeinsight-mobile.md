# CodeInsight Mobile v1 — Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Make CodeInsight usable on a phone (width < 640 px) as a triage surface — instructor sees top-3 at-risk students in < 10 s, student sees next action in < 3 s, admin completes ISO/IEC 25010 evaluation in < 4 min — without sacrificing the analytics-first stance, by adding a layout-config-driven mobile shell with 24 mobile components and 14 mobile pages.

**Architecture:** Single `Layout` root component resolves `mode = mobile | tablet | desktop` from viewport once. A `useLayoutConfig(role, mode)` hook returns a JSON config that the shell renders verbatim — no `if (role === ...)` branches inside the mobile pages. Mobile components adapt via the `mode` prop (passed down through context) and never instantiates a D3 SVG larger than 200×200 px. State derivation (NoData / LowConfidence / Healthy) happens client-side from existing API responses; no new endpoints, no backend changes.

**Tech Stack:** React 18 + Vite + Tailwind 4 + Monaco Editor (existing) + D3.js (lazy-loaded, existing) + Chart.js (lazy-loaded, existing). New: `IntersectionObserver` for tap-to-load, `env(safe-area-inset-*)` for iOS. Vitest + React Testing Library (existing). Playwright (existing) for E2E.

**Spec:** `docs/superpowers/specs/2026-06-05-codeinsight-mobile-design.md` (commit `70c626a`)

**Companion visuals:**
- `.superpowers/brainstorm/102506-1780640635/content/section-1-shell-and-ia.html`
- `.superpowers/brainstorm/102506-1780640635/content/section-2-transformation-rules.html`
- `.superpowers/brainstorm/102506-1780640635/content/section-3-per-role-screens.html`
- `.superpowers/brainstorm/102506-1780640635/content/section-4-api-layout-cut-acceptance.html`

---

## Task 1: Add `useAdaptiveN` hook (foundation for K-adaptive lists)

**Files:**
- Create: `frontend/src/hooks/useAdaptiveN.js`
- Create: `frontend/src/hooks/useAdaptiveN.test.js`

- [ ] **Step 1: Write the failing test**

```js
// frontend/src/hooks/useAdaptiveN.test.js
import { describe, it, expect } from 'vitest';
import { computeN } from './useAdaptiveN.js';

describe('computeN', () => {
  it('returns 5 when viewport fits 5 rows comfortably', () => {
    // viewportHeight=812 (iPhone 14), chrome=104, primary=200, rowHeight=88
    expect(computeN(812, 104, 200, 88)).toBe(5);
  });

  it('returns 3 on a shorter foldable inner display', () => {
    // viewportHeight=600, chrome=104, primary=200, rowHeight=88
    expect(computeN(600, 104, 200, 88)).toBe(3);
  });

  it('never returns 0 even when viewport is very short', () => {
    expect(computeN(200, 104, 200, 88)).toBe(1);
  });

  it('never returns more than 5 (spec cap)', () => {
    expect(computeN(4000, 0, 0, 88)).toBe(5);
  });

  it('uses the formula min(5, floor((vh - chrome - primary) / rowHeight))', () => {
    // (812 - 104 - 200) / 88 = 508/88 = 5.77 → floor=5 → min(5,5)=5
    expect(computeN(812, 104, 200, 88)).toBe(5);
    // (640 - 104 - 200) / 88 = 336/88 = 3.81 → floor=3 → min(5,3)=3
    expect(computeN(640, 104, 200, 88)).toBe(3);
  });
});
```

- [ ] **Step 2: Run test to verify it fails**

Run: `cd frontend && npx vitest run src/hooks/useAdaptiveN.test.js`
Expected: FAIL — `useAdaptiveN.js` does not exist.

- [ ] **Step 3: Write minimal implementation**

```js
// frontend/src/hooks/useAdaptiveN.js
import { useEffect, useState } from 'react';

export const DEFAULT_CHROME_HEIGHT = 104;   // 48 (app bar) + 56 (bottom nav)
export const DEFAULT_PRIMARY_HEIGHT = 200; // primary widget
export const DEFAULT_ROW_HEIGHT = 88;      // one queue row

/**
 * Pure formula: how many rows fit in the available viewport space.
 * Spec: min(5, floor((viewportHeight - chromeHeight - primaryHeight) / rowHeight))
 */
export function computeN(viewportHeight, chromeHeight = DEFAULT_CHROME_HEIGHT,
                        primaryHeight = DEFAULT_PRIMARY_HEIGHT,
                        rowHeight = DEFAULT_ROW_HEIGHT) {
  if (viewportHeight <= 0) return 1;
  const available = viewportHeight - chromeHeight - primaryHeight;
  const fitted = Math.floor(available / rowHeight);
  return Math.max(1, Math.min(5, fitted));
}

/**
 * React hook: re-runs computeN on window resize, throttled to rAF.
 */
export function useAdaptiveN(chromeHeight, primaryHeight, rowHeight) {
  const [n, setN] = useState(() => {
    if (typeof window === 'undefined') return 5;
    return computeN(window.innerHeight, chromeHeight, primaryHeight, rowHeight);
  });

  useEffect(() => {
    let raf = 0;
    const onResize = () => {
      cancelAnimationFrame(raf);
      raf = requestAnimationFrame(() => {
        setN(computeN(window.innerHeight, chromeHeight, primaryHeight, rowHeight));
      });
    };
    window.addEventListener('resize', onResize);
    return () => {
      window.removeEventListener('resize', onResize);
      cancelAnimationFrame(raf);
    };
  }, [chromeHeight, primaryHeight, rowHeight]);

  return n;
}
```

- [ ] **Step 4: Run test to verify it passes**

Run: `cd frontend && npx vitest run src/hooks/useAdaptiveN.test.js`
Expected: PASS — 5 tests.

- [ ] **Step 5: Commit**

```bash
git add frontend/src/hooks/useAdaptiveN.js frontend/src/hooks/useAdaptiveN.test.js
git commit -m "feat(mobile): add useAdaptiveN hook for K-adaptive phone lists"
```

---

## Task 2: Add state derivation (NoData / LowConfidence / Healthy)

**Files:**
- Create: `frontend/src/state/stateCopy.js`
- Create: `frontend/src/state/useStateDerivation.js`
- Create: `frontend/src/state/useStateDerivation.test.js`

- [ ] **Step 1: Write the failing test**

```js
// frontend/src/state/useStateDerivation.test.js
import { describe, it, expect } from 'vitest';
import { deriveState } from './useStateDerivation.js';

describe('deriveState (priority insight taxonomy)', () => {
  it('returns "NoData" when there are 0 submissions', () => {
    expect(deriveState({ submissionsPerStudent: 0, sectionAgeDays: 30, students: 50 })
      .state).toBe('NoData');
  });

  it('returns "NoData" when section is < 24h old regardless of submissions', () => {
    expect(deriveState({ submissionsPerStudent: 0, sectionAgeDays: 0, students: 0 })
      .state).toBe('NoData');
  });

  it('returns "LowConfidence" when 1-2 submissions per student', () => {
    expect(deriveState({ submissionsPerStudent: 1, sectionAgeDays: 30, students: 50 })
      .state).toBe('LowConfidence');
  });

  it('returns "LowConfidence" when section is < 14d old even with 3+ submissions', () => {
    expect(deriveState({ submissionsPerStudent: 3, sectionAgeDays: 5, students: 50 })
      .state).toBe('LowConfidence');
  });

  it('returns "Healthy" when >= 3 submissions per student AND section >= 14d', () => {
    expect(deriveState({ submissionsPerStudent: 3, sectionAgeDays: 14, students: 50 })
      .state).toBe('Healthy');
  });

  it('includes a numeric progress counter when LowConfidence', () => {
    const r = deriveState({ submissionsPerStudent: 1, sectionAgeDays: 30, students: 50 });
    expect(r.progressText).toMatch(/2 of 50/);
  });

  it('Healthy returns no progressText', () => {
    const r = deriveState({ submissionsPerStudent: 3, sectionAgeDays: 30, students: 50 });
    expect(r.progressText).toBeUndefined();
  });
});
```

- [ ] **Step 2: Run test to verify it fails**

Run: `cd frontend && npx vitest run src/state/useStateDerivation.test.js`
Expected: FAIL — module does not exist.

- [ ] **Step 3: Write `stateCopy.js`**

```js
// frontend/src/state/stateCopy.js
// Canonical copy and visuals for the three states. Spec §8.

export const STATE_COPY = {
  NoData: {
    instructor: {
      title: 'No exercise activity yet',
      body: 'Once students submit, you\'ll see risk signals here.',
      cta: { label: 'Open exercises', route: '/instructor/exercises' },
      badge: null,
    },
    student: {
      title: 'No exercises yet',
      body: 'Your instructor will assign work soon. Check back shortly.',
      cta: { label: 'View sections', route: '/student/sections' },
      badge: null,
    },
    admin: {
      title: 'No data yet',
      body: 'The system is new. Metrics will appear as activity arrives.',
      cta: null,
      badge: null,
    },
  },
  LowConfidence: {
    instructor: {
      title: 'Early signal',
      body: 'Insights sharpen as data arrives.',
      badge: 'Limited',
    },
    student: {
      title: 'Just getting started',
      body: 'Your first submissions unlock personalised guidance.',
      badge: 'Limited',
    },
    admin: {
      title: 'Limited data',
      body: 'Sample size is still building. Re-check after the next batch.',
      badge: 'Limited',
    },
  },
  Healthy: {
    instructor: { badge: null },
    student: { badge: null },
    admin: { badge: null },
  },
};

// State → CSS class map. Spec §8.
export const STATE_VISUAL = {
  NoData:    { card: 'mobile-card--nodata',     border: 'border-dashed' },
  LowConfidence: { card: 'mobile-card--lowconf',  border: 'border-solid' },
  Healthy:   { card: 'mobile-card--healthy',    border: 'border-solid' },
};
```

- [ ] **Step 4: Write `useStateDerivation.js`**

```js
// frontend/src/state/useStateDerivation.js
import { STATE_COPY } from './stateCopy.js';

/**
 * Pure derivation. Spec §8.
 *
 * Triggers:
 *   NoData: 0 submissions OR section < 24h old
 *   LowConfidence: 1-2 submissions/student OR section < 14d old
 *   Healthy: >= 3 submissions/student AND section >= 14d
 *
 * @param {{ submissionsPerStudent: number, sectionAgeDays: number, students: number }} input
 * @returns {{ state: 'NoData'|'LowConfidence'|'Healthy', progressText?: string, copy: object }}
 */
export function deriveState({ submissionsPerStudent = 0, sectionAgeDays = 0, students = 0 } = {}) {
  let state;
  if (submissionsPerStudent <= 0 || sectionAgeDays < 1) {
    state = 'NoData';
  } else if (submissionsPerStudent < 3 || sectionAgeDays < 14) {
    state = 'LowConfidence';
  } else {
    state = 'Healthy';
  }

  const result = { state, copy: null };
  if (state === 'LowConfidence') {
    const totalNeeded = students * 3; // 3 submissions/student for full confidence
    const have = submissionsPerStudent * students;
    result.progressText = `${have} of ${totalNeeded} submissions to full confidence`;
  }
  return result;
}

/** Look up role-specific copy for a state. */
export function copyFor(role, state) {
  return STATE_COPY[state]?.[role] ?? null;
}
```

- [ ] **Step 5: Run test to verify it passes**

Run: `cd frontend && npx vitest run src/state/useStateDerivation.test.js`
Expected: PASS — 7 tests.

- [ ] **Step 6: Commit**

```bash
git add frontend/src/state/stateCopy.js frontend/src/state/useStateDerivation.js frontend/src/state/useStateDerivation.test.js
git commit -m "feat(mobile): add state derivation (NoData/LowConfidence/Healthy) + copy"
```

---

## Task 3: Add `StateAwareShell` wrapper

**Files:**
- Create: `frontend/src/state/StateAwareShell.jsx`
- Create: `frontend/src/state/StateAwareShell.test.jsx`

- [ ] **Step 1: Write the failing test**

```jsx
// frontend/src/state/StateAwareShell.test.jsx
import { describe, it, expect } from 'vitest';
import { render, screen } from '@testing-library/react';
import { StateAwareShell } from './StateAwareShell.jsx';

describe('<StateAwareShell>', () => {
  it('renders NoData copy when state is NoData and there is no data', () => {
    render(
      <StateAwareShell role="instructor" data={null} state="NoData" />
    );
    expect(screen.getByText(/No exercise activity yet/)).toBeInTheDocument();
    expect(screen.getByText(/Open exercises/)).toBeInTheDocument();
  });

  it('renders children when state is Healthy and data is present', () => {
    render(
      <StateAwareShell role="instructor" data={{ insight: 'hi' }} state="Healthy">
        <div data-testid="child">child content</div>
      </StateAwareShell>
    );
    expect(screen.getByTestId('child')).toBeInTheDocument();
  });

  it('shows Limited badge when state is LowConfidence', () => {
    render(
      <StateAwareShell role="instructor" data={{}} state="LowConfidence" progressText="5 of 150 submissions to full confidence">
        <div>real content</div>
      </StateAwareShell>
    );
    expect(screen.getByText('Limited')).toBeInTheDocument();
    expect(screen.getByText(/5 of 150/)).toBeInTheDocument();
  });
});
```

- [ ] **Step 2: Run test to verify it fails**

Run: `cd frontend && npx vitest run src/state/StateAwareShell.test.jsx`
Expected: FAIL — component does not exist.

- [ ] **Step 3: Write `StateAwareShell.jsx`**

```jsx
// frontend/src/state/StateAwareShell.jsx
// Wraps a widget. Spec §8.
// - NoData → renders copy + CTA, hides children
// - LowConfidence → renders children + "Limited" badge + progress
// - Healthy → renders children normally

import { copyFor } from './useStateDerivation.js';
import { STATE_VISUAL } from './stateCopy.js';

export function StateAwareShell({ role, data, state, progressText, children, className = '' }) {
  // No data: replace with copy-only card
  if (state === 'NoData' || data == null) {
    const copy = copyFor(role, 'NoData');
    if (!copy) return children;
    return (
      <div className={`mobile-card mobile-card--nodata border-dashed ${className}`} role="status">
        <h3 className="mobile-card__title">{copy.title}</h3>
        <p className="mobile-card__body">{copy.body}</p>
        {copy.cta && (
          <a href={copy.cta.route} className="mobile-card__cta">{copy.cta.label} →</a>
        )}
      </div>
    );
  }

  // Low confidence: render children + badge + progress
  if (state === 'LowConfidence') {
    return (
      <div className={`mobile-card mobile-card--lowconf border-solid ${className}`}>
        <div className="mobile-card__badge">Limited</div>
        {progressText && (
          <p className="mobile-card__progress">{progressText}</p>
        )}
        {children}
      </div>
    );
  }

  // Healthy: just children
  return <div className={className}>{children}</div>;
}
```

- [ ] **Step 4: Run test to verify it passes**

Run: `cd frontend && npx vitest run src/state/StateAwareShell.test.jsx`
Expected: PASS — 3 tests.

- [ ] **Step 5: Commit**

```bash
git add frontend/src/state/StateAwareShell.jsx frontend/src/state/StateAwareShell.test.jsx
git commit -m "feat(mobile): add StateAwareShell wrapper for priority widgets"
```

---

## Task 4: Extend `use-mobile` hook to expose `mode` (mobile/tablet/desktop)

**Files:**
- Read: `frontend/src/hooks/use-mobile.js` (to confirm current shape)
- Modify: `frontend/src/hooks/use-mobile.js`
- Modify (test): `frontend/src/hooks/use-mobile.test.js` (create if absent)

- [ ] **Step 1: Read the existing hook**

```bash
cat frontend/src/hooks/use-mobile.js
```

If the existing hook returns a boolean, we'll add a `mode` export. If it doesn't exist, write the new version from scratch. Either way the public API after this task is:

```js
import { useMode } from '@/hooks/use-mobile.js';
const mode = useMode(); // 'mobile' | 'tablet' | 'desktop'
```

- [ ] **Step 2: Write the failing test**

```js
// frontend/src/hooks/use-mode.test.js
import { describe, it, expect, vi, afterEach } from 'vitest';
import { renderHook } from '@testing-library/react';
import { useMode, breakpointFromWidth } from './use-mobile.js';

describe('breakpointFromWidth', () => {
  it('returns "mobile" below 640', () => {
    expect(breakpointFromWidth(320)).toBe('mobile');
    expect(breakpointFromWidth(639)).toBe('mobile');
  });
  it('returns "tablet" at 640-1023', () => {
    expect(breakpointFromWidth(640)).toBe('tablet');
    expect(breakpointFromWidth(1023)).toBe('tablet');
  });
  it('returns "desktop" at 1024+', () => {
    expect(breakpointFromWidth(1024)).toBe('desktop');
    expect(breakpointFromWidth(1920)).toBe('desktop');
  });
});

describe('useMode', () => {
  afterEach(() => {
    window.innerWidth = 1024;
  });

  it('returns "desktop" by default at 1024px', () => {
    window.innerWidth = 1024;
    const { result } = renderHook(() => useMode());
    expect(result.current).toBe('desktop');
  });

  it('returns "mobile" at 375px', () => {
    window.innerWidth = 375;
    const { result } = renderHook(() => useMode());
    expect(result.current).toBe('mobile');
  });
});
```

- [ ] **Step 3: Run test to verify it fails**

Run: `cd frontend && npx vitest run src/hooks/use-mode.test.js`
Expected: FAIL — `useMode` and `breakpointFromWidth` are not exported.

- [ ] **Step 4: Modify `use-mobile.js` to add the new exports without breaking the existing `useIsMobile` boolean**

```js
// frontend/src/hooks/use-mobile.js
// Existing export: useIsMobile() -> boolean (kept for back-compat)
// New exports:   useMode() -> 'mobile' | 'tablet' | 'desktop'
//                breakpointFromWidth(width) -> 'mobile' | 'tablet' | 'desktop'
//
// Spec §2.1: mode is the single source of truth, derived once at the Layout root.

import { useEffect, useState } from 'react';

export const MOBILE_MAX = 639;
export const TABLET_MAX = 1023;

export function breakpointFromWidth(width) {
  if (width <= MOBILE_MAX) return 'mobile';
  if (width <= TABLET_MAX) return 'tablet';
  return 'desktop';
}

export function useMode() {
  const [mode, setMode] = useState(() => {
    if (typeof window === 'undefined') return 'desktop';
    return breakpointFromWidth(window.innerWidth);
  });

  useEffect(() => {
    const mql = window.matchMedia('(max-width: 1023px)');
    const onChange = () => setMode(breakpointFromWidth(window.innerWidth));
    mql.addEventListener?.('change', onChange);
    window.addEventListener('resize', onChange);
    return () => {
      mql.removeEventListener?.('change', onChange);
      window.removeEventListener('resize', onChange);
    };
  }, []);

  return mode;
}

// Back-compat: keep the boolean for the few existing call sites.
export function useIsMobile() {
  return useMode() === 'mobile';
}
```

- [ ] **Step 5: Run test to verify it passes**

Run: `cd frontend && npx vitest run src/hooks/use-mode.test.js`
Expected: PASS — 5 tests.

Also re-run the full frontend test suite to confirm no back-compat break:

Run: `cd frontend && npx vitest run`
Expected: existing tests still PASS (the `useIsMobile` boolean is preserved).

- [ ] **Step 6: Commit**

```bash
git add frontend/src/hooks/use-mobile.js frontend/src/hooks/use-mode.test.js
git commit -m "feat(mobile): extend use-mobile hook to expose mode (mobile/tablet/desktop)"
```

---

## Task 5: Add `useLayoutConfig` hook + JSON config files

**Files:**
- Create: `frontend/src/config/useLayoutConfig.js`
- Create: `frontend/src/config/mobile/instructor.json`
- Create: `frontend/src/config/mobile/student.json`
- Create: `frontend/src/config/mobile/admin.json`
- Create: `frontend/src/config/useLayoutConfig.test.js`

- [ ] **Step 1: Write the failing test**

```js
// frontend/src/config/useLayoutConfig.test.js
import { describe, it, expect } from 'vitest';
import { getConfig } from './useLayoutConfig.js';

describe('getConfig (instructor, mobile)', () => {
  const cfg = getConfig('instructor', 'mobile');

  it('has chrome.appBar with rightSlot="menu"', () => {
    expect(cfg.chrome.appBar.rightSlot).toBe('menu');
  });

  it('has bottomNav with 5 destinations', () => {
    expect(cfg.chrome.bottomNav.items).toHaveLength(5);
  });

  it('/instructor/command has 1 primary widget, 0-2 secondary, multiple tertiary', () => {
    const screen = cfg.screens['/instructor/command'];
    expect(screen.primary).toBeDefined();
    expect(screen.secondary.length).toBeLessThanOrEqual(2);
    expect(screen.tertiary.length).toBeGreaterThanOrEqual(1);
  });

  it('every widget ref has the canonical widget name (no synonyms)', () => {
    const all = [cfg.screens['/instructor/command']];
    for (const s of all) {
      for (const w of [s.primary, ...s.secondary, ...s.tertiary]) {
        // canonical names from spec §9
        expect(['InstructorPriorityInsight', 'AtRiskQueue', 'AtRiskRoster',
          'InterventionQueue', 'TopStrugglingConcepts', 'ClassProfileRadar',
          'WeeklyTeachingInsight', 'IntegrityFlagCount', 'IntegrityFlagList',
          'IntegrityFlagHistory', 'IntegrityDrillNotice', 'SectionList'])
          .toContain(w.widget);
      }
    }
  });
});

describe('getConfig (student, mobile)', () => {
  const cfg = getConfig('student', 'mobile');
  it('has bottomNav with 5 destinations', () => {
    expect(cfg.chrome.bottomNav.items).toHaveLength(5);
  });
  it('/student/today has StudentTodayFocus as primary', () => {
    expect(cfg.screens['/student/today'].primary.widget).toBe('StudentTodayFocus');
  });
});

describe('getConfig (admin, mobile)', () => {
  const cfg = getConfig('admin', 'mobile');
  it('has bottomNav with 3 destinations', () => {
    expect(cfg.chrome.bottomNav.items).toHaveLength(3);
  });
  it('/admin/overview has SnapshotMetrics as primary AND EvaluationProgress as primaryAction', () => {
    expect(cfg.screens['/admin/overview'].primary.widget).toBe('SnapshotMetrics');
    expect(cfg.screens['/admin/overview'].primaryAction.widget).toBe('EvaluationProgress');
  });
});
```

- [ ] **Step 2: Run test to verify it fails**

Run: `cd frontend && npx vitest run src/config/useLayoutConfig.test.js`
Expected: FAIL — module does not exist.

- [ ] **Step 3: Write `useLayoutConfig.js`**

```js
// frontend/src/config/useLayoutConfig.js
// Spec §10. The shell renders exactly what the config says.

import instructorMobile from './mobile/instructor.json';
import studentMobile from './mobile/student.json';
import adminMobile from './mobile/admin.json';

const TABLES = {
  instructor: { mobile: instructorMobile, tablet: instructorMobile, desktop: instructorMobile },
  student:    { mobile: studentMobile,    tablet: studentMobile,    desktop: studentMobile },
  admin:      { mobile: adminMobile,      tablet: adminMobile,      desktop: adminMobile },
};

export function getConfig(role, mode) {
  const cfg = TABLES[role]?.[mode];
  if (!cfg) throw new Error(`No config for role=${role} mode=${mode}`);
  return cfg;
}

/** Evaluate a showIf expression against response data. Spec §10. */
export function shouldShow(widget, data) {
  if (!widget.showIf) return true;
  // simple expression format: "data.length > 0" or "data.count >= 1"
  const expr = widget.showIf;
  if (expr === 'data.length > 0')  return Array.isArray(data) && data.length > 0;
  if (expr === 'data.length > 2')  return Array.isArray(data) && data.length > 2;
  if (expr === 'data && data.length > 0') return Array.isArray(data) && data.length > 0;
  if (expr.startsWith('data.')) {
    // data.<path> <op> <value>
    const m = expr.match(/^data\.(\w+)\s*(>=|<=|==|!=|>|<)\s*(.+)$/);
    if (m) {
      const [, path, op, raw] = m;
      const actual = data?.[path];
      const expected = JSON.parse(raw);
      switch (op) {
        case '>=': return actual >= expected;
        case '<=': return actual <= expected;
        case '==': return actual === expected;
        case '!=': return actual !== expected;
        case '>':  return actual > expected;
        case '<':  return actual < expected;
      }
    }
  }
  return true;
}
```

- [ ] **Step 4: Write `mobile/instructor.json`**

```json
{
  "role": "instructor",
  "mode": "mobile",
  "chrome": {
    "appBar": { "title": "CodeInsight", "rightSlot": "menu" },
    "bottomNav": {
      "items": [
        { "key": "command",  "label": "Command",  "icon": "alert",  "route": "/instructor/command" },
        { "key": "students", "label": "Students", "icon": "users",  "route": "/instructor/students" },
        { "key": "concepts", "label": "Concepts", "icon": "diamond", "route": "/instructor/concepts" },
        { "key": "integrity","label": "Integrity","icon": "flag",   "route": "/instructor/integrity" },
        { "key": "sections", "label": "Sections", "icon": "grid",   "route": "/instructor/sections" }
      ]
    }
  },
  "screens": {
    "/instructor/command": {
      "primary":   { "widget": "InstructorPriorityInsight", "endpoint": "/api/analytics/instructor/priority-insight" },
      "secondary": [
        { "widget": "AtRiskQueue",       "endpoint": "/api/analytics/instructor/at-risk-queue",       "showIf": "data.length > 0" },
        { "widget": "InterventionQueue", "endpoint": "/api/analytics/instructor/intervention-queue", "showIf": "data.length > 0" }
      ],
      "tertiary": [
        { "widget": "TopStrugglingConcepts", "endpoint": "/api/analytics/instructor/concepts/top?k=N", "collapsed": true },
        { "widget": "IntegrityFlagCount",    "endpoint": "/api/analytics/instructor/integrity/count",  "collapsed": true },
        { "widget": "ClassProfileRadar",     "endpoint": "/api/analytics/instructor/concepts/profile", "collapsed": true, "render": "summary" },
        { "widget": "WeeklyTeachingInsight", "endpoint": "/api/analytics/instructor/weekly-insight",   "collapsed": true }
      ]
    },
    "/instructor/students": {
      "primary":   { "widget": "AtRiskRoster", "endpoint": "/api/analytics/instructor/students?sort=risk" },
      "secondary": [],
      "tertiary":  []
    },
    "/instructor/concepts": {
      "primary":   { "widget": "TopStrugglingConcepts", "endpoint": "/api/analytics/instructor/concepts/top?k=N" },
      "secondary": [],
      "tertiary":  []
    },
    "/instructor/integrity": {
      "primary":   { "widget": "IntegrityFlagCount",  "endpoint": "/api/analytics/instructor/integrity/count" },
      "secondary": [
        { "widget": "IntegrityFlagList", "endpoint": "/api/analytics/instructor/integrity/recent?limit=3", "showIf": "data.length > 0" },
        { "widget": "IntegrityDrillNotice", "static": true, "copy": "Flag review requires tablet or desktop." }
      ],
      "tertiary":  []
    },
    "/instructor/sections": {
      "primary":   { "widget": "SectionList", "endpoint": "/api/sections?instructor=me" },
      "secondary": [],
      "tertiary":  []
    }
  }
}
```

- [ ] **Step 5: Write `mobile/student.json`**

```json
{
  "role": "student",
  "mode": "mobile",
  "chrome": {
    "appBar": { "title": "CodeInsight", "rightSlot": "avatar" },
    "bottomNav": {
      "items": [
        { "key": "today",     "label": "Today",     "icon": "sun",     "route": "/student/today" },
        { "key": "exercises", "label": "Exercises", "icon": "diamond", "route": "/student/exercises" },
        { "key": "progress",  "label": "Progress",  "icon": "chart",   "route": "/student/progress" },
        { "key": "integrity", "label": "Integrity", "icon": "flag",    "route": "/student/integrity" },
        { "key": "sections",  "label": "Sections",  "icon": "grid",    "route": "/student/sections" }
      ]
    }
  },
  "screens": {
    "/student/today": {
      "primary":   { "widget": "StudentTodayFocus", "endpoint": "/api/analytics/student/today-focus" },
      "secondary": [
        { "widget": "WeakestConceptBar", "endpoint": "/api/analytics/student/concepts/weakest", "showIf": "data && data.length > 0" },
        { "widget": "ActionStack",       "endpoint": "/api/analytics/student/actions/next",    "showIf": "data.length > 0" }
      ],
      "tertiary": [
        { "widget": "WeeklyProgress",        "endpoint": "/api/analytics/student/progress/week",     "collapsed": true },
        { "widget": "ConceptMasteryBarSet",  "endpoint": "/api/analytics/student/concepts/all",       "collapsed": true, "render": "summary" },
        { "widget": "IntegrityFlagCount",    "endpoint": "/api/analytics/student/integrity/count",    "collapsed": true }
      ]
    },
    "/student/exercises": {
      "primary":   { "widget": "ExerciseCardList", "endpoint": "/api/exercises?student=me" },
      "secondary": [],
      "tertiary":  []
    },
    "/student/exercises/:id": {
      "primary":   { "widget": "CodePreviewSurface", "endpoint": "/api/exercises/:id" },
      "secondary": [
        { "widget": "TestResultList", "endpoint": "/api/submissions/:id/results", "showIf": "data && data.length > 0" },
        { "widget": "OpenFullEditorHint", "static": true, "copy": "↗ Open in full editor (tablet+)" }
      ],
      "tertiary":  [],
      "codeBlock": { "engine": "pre", "monaco": false, "horizontalScroll": true }
    },
    "/student/progress": {
      "primary":   { "widget": "ConceptMasteryBarSet", "endpoint": "/api/analytics/student/concepts/all", "render": "summary" },
      "secondary": [
        { "widget": "WeeklyProgress", "endpoint": "/api/analytics/student/progress/week" }
      ],
      "tertiary":  []
    },
    "/student/integrity": {
      "primary":   { "widget": "IntegrityFlagCount",   "endpoint": "/api/analytics/student/integrity/count" },
      "secondary": [
        { "widget": "IntegrityFlagHistory", "endpoint": "/api/analytics/student/integrity/history", "showIf": "data.length > 0" }
      ],
      "tertiary":  []
    },
    "/student/sections": {
      "primary":   { "widget": "SectionList", "endpoint": "/api/sections?student=me" },
      "secondary": [],
      "tertiary":  []
    }
  }
}
```

- [ ] **Step 6: Write `mobile/admin.json`**

```json
{
  "role": "admin",
  "mode": "mobile",
  "chrome": {
    "appBar": { "title": "CodeInsight", "rightSlot": "menu" },
    "bottomNav": {
      "items": [
        { "key": "overview",  "label": "Overview",  "icon": "home",   "route": "/admin/overview" },
        { "key": "evaluation","label": "Eval",     "icon": "chart",  "route": "/admin/evaluation" },
        { "key": "audit",     "label": "Audit",    "icon": "cog",    "route": "/admin/audit" }
      ]
    }
  },
  "screens": {
    "/admin/overview": {
      "primary":        { "widget": "SnapshotMetrics",   "endpoint": "/api/admin/snapshot" },
      "primaryAction":  { "widget": "EvaluationProgress","endpoint": "/api/admin/evaluations/pending" },
      "secondary": [
        { "widget": "AuditLog",   "endpoint": "/api/admin/audit?limit=50",    "showIf": "data.length > 0" },
        { "widget": "SectionList","endpoint": "/api/sections",                  "showIf": "data.length > 0" }
      ],
      "tertiary": [
        { "widget": "DesktopOnlyNotice", "static": true, "copy": "Bulk export (desktop only)" },
        { "widget": "DesktopOnlyNotice", "static": true, "copy": "User management (desktop only)" }
      ]
    },
    "/admin/evaluation": {
      "primary":   { "widget": "Iso25010Instrument", "endpoint": "/api/admin/evaluations/instrument" },
      "secondary": [],
      "tertiary":  []
    },
    "/admin/audit": {
      "primary":   { "widget": "AuditLog", "endpoint": "/api/admin/audit?limit=50" },
      "secondary": [],
      "tertiary":  []
    }
  }
}
```

- [ ] **Step 7: Run test to verify it passes**

Run: `cd frontend && npx vitest run src/config/useLayoutConfig.test.js`
Expected: PASS — 8 tests.

- [ ] **Step 8: Commit**

```bash
git add frontend/src/config/
git commit -m "feat(mobile): add useLayoutConfig hook + 3 mobile role configs (instructor, student, admin)"
```

---

## Task 6: Add mobile CSS (safe-area, tap targets, container queries)

**Files:**
- Create: `frontend/src/styles/mobile.css`
- Modify: `frontend/src/main.jsx` (import the new CSS)

- [ ] **Step 1: Write `mobile.css`**

```css
/* frontend/src/styles/mobile.css */
/* Spec §3, §6.3, §13.9, §13.10, §13.13. */

:root {
  --mobile-tap-min: 44px;
  --mobile-row-min: 56px;
  --mobile-card-radius: 12px;
  --mobile-card-padding: 16px;
  --mobile-gutter: 16px;
}

/* Bottom tab bar — safe area for iOS home indicator */
.mobile-bottom-nav {
  height: calc(56px + env(safe-area-inset-bottom));
  padding-bottom: env(safe-area-inset-bottom);
  background: var(--color-surface, #0F172A);
  border-top: 1px solid var(--color-border, #334155);
  display: flex;
  justify-content: space-around;
  align-items: stretch;
  position: sticky;
  bottom: 0;
  z-index: 10;
}

.mobile-bottom-nav__item {
  min-width: 60px;
  min-height: var(--mobile-tap-min);
  display: flex;
  flex-direction: column;
  align-items: center;
  justify-content: center;
  background: transparent;
  border: none;
  color: var(--color-text-muted, #94A3B8);
  font-size: 11px;
  gap: 2px;
  padding: 6px 8px;
  cursor: pointer;
}

.mobile-bottom-nav__item--active {
  color: var(--color-accent, #22C55E);
}

/* App bar */
.mobile-app-bar {
  height: 48px;
  padding: 0 var(--mobile-gutter);
  background: var(--color-surface, #0F172A);
  border-bottom: 1px solid var(--color-border, #334155);
  display: flex;
  align-items: center;
  justify-content: space-between;
  position: sticky;
  top: 0;
  z-index: 10;
}

/* Cards */
.mobile-card {
  background: var(--color-card, #1E293B);
  border: 1px solid var(--color-border, #334155);
  border-radius: var(--mobile-card-radius);
  padding: var(--mobile-card-padding);
  margin-bottom: var(--mobile-gutter);
  contain: layout;
}

.mobile-card--nodata {
  border-style: dashed;
  text-align: center;
}

.mobile-card--lowconf {
  border-style: solid;
}

.mobile-card__title {
  font-size: 15px;
  font-weight: 600;
  margin: 0 0 6px 0;
  color: var(--color-text, #F8FAFC);
}

.mobile-card__body {
  font-size: 13px;
  color: var(--color-text-muted, #94A3B8);
  margin: 0 0 8px 0;
}

.mobile-card__cta {
  display: inline-block;
  min-height: var(--mobile-tap-min);
  padding: 0 16px;
  line-height: 44px;
  background: var(--color-accent, #22C55E);
  color: var(--color-accent-fg, #022C22);
  border-radius: 8px;
  font-weight: 600;
  text-decoration: none;
}

.mobile-card__badge {
  display: inline-block;
  font-size: 10px;
  font-weight: 700;
  letter-spacing: 0.06em;
  text-transform: uppercase;
  background: var(--color-warning, #FACC15);
  color: var(--color-warning-fg, #422006);
  padding: 2px 6px;
  border-radius: 4px;
  margin-bottom: 8px;
}

.mobile-card__progress {
  font-size: 11px;
  color: var(--color-text-muted, #94A3B8);
  margin: 0 0 8px 0;
}

/* Layout */
.mobile-content {
  padding: var(--mobile-gutter);
  padding-bottom: calc(var(--mobile-gutter) + 16px);
  max-width: 100%;
  overflow-x: hidden;
}

/* RiskBadge — color + label always on phone (spec §6.1, §13.10) */
.risk-badge--mobile {
  display: inline-flex;
  align-items: center;
  gap: 4px;
  min-height: 28px;
  padding: 2px 8px;
  border-radius: 6px;
  font-size: 12px;
  font-weight: 600;
}
.risk-badge--mobile[data-level="critical"] { background: #EF4444; color: #450A0A; }
.risk-badge--mobile[data-level="high"]     { background: #FB923C; color: #431407; }
.risk-badge--mobile[data-level="medium"]   { background: #FACC15; color: #422006; }
.risk-badge--mobile[data-level="low"]      { background: #22C55E; color: #022C22; }
.risk-badge--mobile .risk-badge__symbol { opacity: 0.85; }

/* CDSPill compact (spec §6.1) */
.cds-pill--mobile {
  display: inline-block;
  font-size: 11px;
  font-weight: 600;
  padding: 2px 6px;
  border-radius: 4px;
  min-height: 22px;
  line-height: 18px;
}

/* Code preview surface */
.code-preview-surface {
  background: #000;
  color: #F8FAFC;
  padding: 12px;
  border-radius: 8px;
  font-family: 'JetBrains Mono', ui-monospace, monospace;
  font-size: 11px;
  line-height: 1.5;
  overflow-x: auto;
  white-space: pre;
  -webkit-overflow-scrolling: touch;
}

/* Pull-to-refresh hint */
.pull-to-refresh {
  text-align: center;
  font-size: 11px;
  color: var(--color-text-muted, #94A3B8);
  padding: 8px;
  min-height: 24px;
}

/* Tap targets — global rule for buttons/anchors in mobile scope */
.mobile-content button,
.mobile-content a {
  min-height: var(--mobile-tap-min);
  touch-action: manipulation;
}

/* Active tab dot */
.mobile-bottom-nav__item--active::after {
  content: '';
  display: block;
  width: 4px;
  height: 4px;
  background: var(--color-accent, #22C55E);
  border-radius: 50%;
  margin-top: 2px;
}
```

- [ ] **Step 2: Modify `main.jsx` to import the new CSS**

Open `frontend/src/main.jsx`, find the existing CSS import (something like `import './index.css'`), and add a new line immediately after it:

```js
import './index.css';
import './styles/mobile.css';   // <-- new
```

- [ ] **Step 3: Verify the build still passes**

Run: `cd frontend && npm run build 2>&1 | tail -20`
Expected: build succeeds, no CSS errors.

- [ ] **Step 4: Commit**

```bash
git add frontend/src/styles/mobile.css frontend/src/main.jsx
git commit -m "feat(mobile): add mobile.css (safe-area, 44px tap targets, mobile-card, mobile RiskBadge)"
```

---

## Task 7: Add `AppBar` and `BottomNav` mobile components

**Files:**
- Create: `frontend/src/components/mobile/AppBar.jsx`
- Create: `frontend/src/components/mobile/BottomNav.jsx`
- Create: `frontend/src/components/mobile/BottomNav.test.jsx`

- [ ] **Step 1: Write the failing test for `BottomNav`**

```jsx
// frontend/src/components/mobile/BottomNav.test.jsx
import { describe, it, expect } from 'vitest';
import { render, screen } from '@testing-library/react';
import { MemoryRouter } from 'react-router-dom';
import { BottomNav } from './BottomNav.jsx';

const items = [
  { key: 'a', label: 'Alpha',  icon: 'home',  route: '/a' },
  { key: 'b', label: 'Bravo',  icon: 'users', route: '/b' },
  { key: 'c', label: 'Charlie', icon: 'cog',  route: '/c' },
];

describe('<BottomNav>', () => {
  it('renders one button per item with min-height >= 44px', () => {
    render(<MemoryRouter><BottomNav items={items} activeKey="a" /></MemoryRouter>);
    expect(screen.getAllByRole('link')).toHaveLength(3);
    screen.getAllByRole('link').forEach(btn => {
      const cs = getComputedStyle(btn);
      expect(parseInt(cs.minHeight, 10)).toBeGreaterThanOrEqual(44);
    });
  });

  it('marks the active item with the active class', () => {
    render(<MemoryRouter><BottomNav items={items} activeKey="b" /></MemoryRouter>);
    const buttons = screen.getAllByRole('link');
    expect(buttons[1].className).toMatch(/mobile-bottom-nav__item--active/);
    expect(buttons[0].className).not.toMatch(/mobile-bottom-nav__item--active/);
  });
});
```

- [ ] **Step 2: Run test to verify it fails**

Run: `cd frontend && npx vitest run src/components/mobile/BottomNav.test.jsx`
Expected: FAIL — component does not exist.

- [ ] **Step 3: Write `BottomNav.jsx`**

```jsx
// frontend/src/components/mobile/BottomNav.jsx
// Spec §3, §3.1. Role-specific bottom tab bar.

import { Link, useLocation } from 'react-router-dom';

const ICONS = {
  home:    '⌂', alert: '⚠', users: '👥', diamond: '◇', flag: '⚑', grid: '☷',
  sun:     '☀', chart: '▤', cog: '⚙',
};

export function BottomNav({ items }) {
  const { pathname } = useLocation();
  const activeKey = items.find(it => pathname.startsWith(it.route))?.key;

  return (
    <nav className="mobile-bottom-nav" aria-label="Primary">
      {items.map((it) => {
        const isActive = activeKey === it.key;
        return (
          <Link
            key={it.key}
            to={it.route}
            className={`mobile-bottom-nav__item${isActive ? ' mobile-bottom-nav__item--active' : ''}`}
            aria-current={isActive ? 'page' : undefined}
          >
            <span aria-hidden="true">{ICONS[it.icon] ?? '●'}</span>
            <span>{it.label}</span>
          </Link>
        );
      })}
    </nav>
  );
}
```

- [ ] **Step 4: Write `AppBar.jsx`**

```jsx
// frontend/src/components/mobile/AppBar.jsx
// Spec §3. Sticky app bar, 48px height, logo + right slot.

import { Link } from 'react-router-dom';

export function AppBar({ title, rightSlot, userMenu }) {
  return (
    <header className="mobile-app-bar">
      <Link to="/" className="mobile-app-bar__logo" aria-label="CodeInsight home">
        <strong>{title}</strong>
      </Link>
      <div className="mobile-app-bar__right">
        {rightSlot === 'avatar' && userMenu}
        {rightSlot === 'menu' && (
          <button
            type="button"
            className="mobile-app-bar__menu"
            aria-label="Open menu"
            onClick={userMenu?.onOpen}
          >☰</button>
        )}
      </div>
    </header>
  );
}
```

- [ ] **Step 5: Run test to verify it passes**

Run: `cd frontend && npx vitest run src/components/mobile/BottomNav.test.jsx`
Expected: PASS — 2 tests.

- [ ] **Step 6: Commit**

```bash
git add frontend/src/components/mobile/AppBar.jsx frontend/src/components/mobile/BottomNav.jsx frontend/src/components/mobile/BottomNav.test.jsx
git commit -m "feat(mobile): add AppBar and BottomNav components"
```

---

## Task 8: Add priority/insight widgets (instructor + student + admin)

**Files:**
- Create: `frontend/src/components/mobile/InstructorPriorityInsight.jsx`
- Create: `frontend/src/components/mobile/StudentTodayFocus.jsx`
- Create: `frontend/src/components/mobile/SnapshotMetrics.jsx`
- Create: `frontend/src/components/mobile/EvaluationProgress.jsx`

These four are the **primary** widgets for each role's top route. They are the "headline" surface that answers the design goal in < 3–10 s.

- [ ] **Step 1: Write `InstructorPriorityInsight.jsx`**

```jsx
// frontend/src/components/mobile/InstructorPriorityInsight.jsx
// Spec §5.1, §6.1, §8. Renders the headline insight of the week.
// Wire format (existing API): { headline, cds, delta, countInHigh, totalStudents, concept, route }

import { useStateDerivation } from '../../state/useStateDerivation.js';
import { StateAwareShell } from '../../state/StateAwareShell.jsx';
import { CDSPillDelta } from './primitives/CDSPillDelta.jsx';

export function InstructorPriorityInsight({ data, role = 'instructor' }) {
  const { state, progressText } = useStateDerivation(data);

  return (
    <StateAwareShell
      role={role}
      data={data?.headline ? data : null}
      state={state}
      progressText={progressText}
      className="mobile-card--priority"
    >
      {data?.headline && (
        <article>
          <p style={{ fontSize: 10, opacity: 0.6, letterSpacing: '0.18em', margin: 0 }}>PRIORITY INSIGHT</p>
          <h2 style={{ fontSize: 16, margin: '4px 0' }}>{data.headline}</h2>
          <p style={{ fontSize: 12, opacity: 0.85, margin: '0 0 8px 0' }}>
            <CDSPillDelta value={data.cds} delta={data.delta} />
            {' · '}
            {data.countInHigh} of {data.totalStudents} students in High
          </p>
          {data.route && (
            <a href={data.route} className="mobile-card__cta">View concept →</a>
          )}
        </article>
      )}
    </StateAwareShell>
  );
}
```

- [ ] **Step 2: Write `StudentTodayFocus.jsx`**

```jsx
// frontend/src/components/mobile/StudentTodayFocus.jsx
// Spec §5.2. Renders one exercise + "why" + estimated time + start CTA.
// Wire format: { exerciseId, title, why, estimatedMinutes, route }

import { useStateDerivation } from '../../state/useStateDerivation.js';
import { StateAwareShell } from '../../state/StateAwareShell.jsx';

export function StudentTodayFocus({ data, role = 'student' }) {
  const { state, progressText } = useStateDerivation(data);

  return (
    <StateAwareShell
      role={role}
      data={data?.exerciseId ? data : null}
      state={state}
      progressText={progressText}
    >
      {data?.exerciseId && (
        <article>
          <p style={{ fontSize: 10, opacity: 0.6, letterSpacing: '0.18em', margin: 0 }}>TODAY'S FOCUS</p>
          <h2 style={{ fontSize: 17, margin: '4px 0' }}>{data.title}</h2>
          <p style={{ fontSize: 12, margin: '4px 0' }}><b>Why:</b> {data.why}</p>
          <p style={{ fontSize: 12, opacity: 0.85, margin: '4px 0 8px 0' }}>
            <b>Estimated time:</b> {data.estimatedMinutes} min
          </p>
          <a href={data.route || `/student/exercises/${data.exerciseId}`}
             className="mobile-card__cta"
             style={{ display: 'block', textAlign: 'center' }}>
            ▶ Start exercise
          </a>
        </article>
      )}
    </StateAwareShell>
  );
}
```

- [ ] **Step 3: Write `SnapshotMetrics.jsx`**

```jsx
// frontend/src/components/mobile/SnapshotMetrics.jsx
// Spec §5.3. 2x2 grid: users, sections, eval pending, flags open.
// Wire format: { users, sections, evalPending, flagsOpen }

import { useStateDerivation } from '../../state/useStateDerivation.js';
import { StateAwareShell } from '../../state/StateAwareShell.jsx';

export function SnapshotMetrics({ data, role = 'admin' }) {
  const { state, progressText } = useStateDerivation(data);
  return (
    <StateAwareShell role={role} data={data} state={state} progressText={progressText}>
      {data && (
        <div>
          <p style={{ fontSize: 10, opacity: 0.6, letterSpacing: '0.18em', margin: 0 }}>SYSTEM SNAPSHOT</p>
          <div style={{ display: 'grid', gridTemplateColumns: '1fr 1fr', gap: 12, marginTop: 8 }}>
            <Metric value={data.users}        label="users" />
            <Metric value={data.sections}     label="sections" />
            <Metric value={data.evalPending}  label="eval pending" />
            <Metric value={data.flagsOpen}    label="flags open" />
          </div>
        </div>
      )}
    </StateAwareShell>
  );
}

function Metric({ value, label }) {
  return (
    <div>
      <div style={{ fontSize: 22, fontWeight: 700 }}>{value ?? '—'}</div>
      <div style={{ fontSize: 11, opacity: 0.6 }}>{label}</div>
    </div>
  );
}
```

- [ ] **Step 4: Write `EvaluationProgress.jsx`**

```jsx
// frontend/src/components/mobile/EvaluationProgress.jsx
// Spec §5.3. Single primary action for admin: "Review pending evaluations (N)".
// Wire format: { pendingCount }

export function EvaluationProgress({ data }) {
  if (!data) return null;
  return (
    <a
      href="/admin/evaluation"
      className="mobile-card"
      style={{
        display: 'block', textAlign: 'center',
        background: '#7C3AED', color: '#F8FAFC', textDecoration: 'none',
      }}
    >
      <div style={{ fontWeight: 600 }}>
        ▶ Review pending evaluations ({data.pendingCount ?? 0})
      </div>
      <div style={{ fontSize: 11, opacity: 0.7, marginTop: 2 }}>
        ISO/IEC 25010 instrument
      </div>
    </a>
  );
}
```

- [ ] **Step 5: Commit**

```bash
git add frontend/src/components/mobile/InstructorPriorityInsight.jsx \
        frontend/src/components/mobile/StudentTodayFocus.jsx \
        frontend/src/components/mobile/SnapshotMetrics.jsx \
        frontend/src/components/mobile/EvaluationProgress.jsx
git commit -m "feat(mobile): add 4 primary widgets (InstructorPriorityInsight, StudentTodayFocus, SnapshotMetrics, EvaluationProgress)"
```

---

## Task 9: Add queue/list/roster widgets

**Files:**
- Create: `frontend/src/components/mobile/AtRiskQueue.jsx`
- Create: `frontend/src/components/mobile/AtRiskRoster.jsx`
- Create: `frontend/src/components/mobile/InterventionQueue.jsx`
- Create: `frontend/src/components/mobile/ActionStack.jsx`
- Create: `frontend/src/components/mobile/TopStrugglingConcepts.jsx`
- Create: `frontend/src/components/mobile/ConceptMasteryBarSet.jsx`
- Create: `frontend/src/components/mobile/WeeklyProgress.jsx`
- Create: `frontend/src/components/mobile/WeeklyTeachingInsight.jsx`
- Create: `frontend/src/components/mobile/WeakestConceptBar.jsx`

These are the secondary/tertiary widgets that fill the rest of the screens.

- [ ] **Step 1: Write `AtRiskQueue.jsx`**

```jsx
// frontend/src/components/mobile/AtRiskQueue.jsx
// Spec §5.1. K-adaptive list of at-risk students. N is from useAdaptiveN.
// Wire format: [{ id, name, risk: 'critical'|'high'|'medium'|'low', concept, cds, delta, fails }]

import { useAdaptiveN, DEFAULT_PRIMARY_HEIGHT } from '../../hooks/useAdaptiveN.js';
import { RiskBadge } from './primitives/RiskBadge.jsx';

const ROW_HEIGHT = 88;

export function AtRiskQueue({ data, onTap, actionLabel = 'tap queue to expand' }) {
  const n = useAdaptiveN(undefined, DEFAULT_PRIMARY_HEIGHT, ROW_HEIGHT);
  if (!data || data.length === 0) return null;

  const shown = data.slice(0, n);
  const more = data.length - shown.length;

  return (
    <section className="mobile-card">
      <p style={{ fontSize: 10, opacity: 0.6, letterSpacing: '0.18em', margin: 0 }}>
        AT-RISK QUEUE · TOP {shown.length}
      </p>
      {shown.map((row) => (
        <button
          key={row.id}
          type="button"
          className="mobile-list-row"
          onClick={() => onTap?.(row)}
          style={{
            display: 'flex', justifyContent: 'space-between', alignItems: 'center',
            minHeight: 56, width: '100%', background: 'transparent',
            border: 'none', borderBottom: '1px solid #334155',
            color: 'inherit', padding: '8px 0', textAlign: 'left',
          }}
        >
          <span>{row.name}</span>
          <RiskBadge level={row.risk} mode="mobile" />
        </button>
      ))}
      {more > 0 && (
        <p style={{ fontSize: 11, opacity: 0.5, marginTop: 6, textAlign: 'center' }}>
          + {more} more · {actionLabel}
        </p>
      )}
    </section>
  );
}
```

- [ ] **Step 2: Write `AtRiskRoster.jsx`**

```jsx
// frontend/src/components/mobile/AtRiskRoster.jsx
// Spec §5.4. Filterable list with View / Message / Intervene buttons.
// Wire format: same as AtRiskQueue + section + flags.

import { RiskBadge } from './primitives/RiskBadge.jsx';

export function AtRiskRoster({ data, onView, onMessage, onIntervene }) {
  if (!data || data.length === 0) {
    return <p style={{ padding: 16, opacity: 0.6 }}>No students match the current filter.</p>;
  }
  return (
    <section>
      <div className="mobile-card" style={{ fontSize: 12 }}>
        <b>Filter:</b> All sections ▾ · Risk: All ▾ · Sort: Risk ↓
      </div>
      {data.map((row) => (
        <article
          key={row.id}
          className="mobile-card"
          style={{ background: row.risk === 'critical' ? '#7C2D12' : undefined }}
        >
          <header style={{ display: 'flex', justifyContent: 'space-between' }}>
            <b>{row.name}</b>
            <RiskBadge level={row.risk} mode="mobile" />
          </header>
          <p style={{ fontSize: 11, opacity: 0.7, margin: '2px 0 6px 0' }}>
            {row.section} · {row.concept} {row.cds?.toFixed(2)}
            {row.delta != null && (row.delta >= 0 ? ` ▲+${row.delta.toFixed(2)}` : ` ▼${row.delta.toFixed(2)}`)}
            {row.fails != null && ` · ${row.fails} fails`}
          </p>
          <div style={{ display: 'flex', gap: 6, flexWrap: 'wrap' }}>
            <button type="button" className="mobile-list-row__btn" onClick={() => onView?.(row)}>View</button>
            <button type="button" className="mobile-list-row__btn" onClick={() => onMessage?.(row)}>Message</button>
            <button type="button" className="mobile-list-row__btn mobile-list-row__btn--primary" onClick={() => onIntervene?.(row)}>Intervene</button>
          </div>
        </article>
      ))}
      <p style={{ fontSize: 11, opacity: 0.5, textAlign: 'center', marginTop: 8 }}>
        swipe ◀ dismiss · swipe ▶ flag · long-press history
      </p>
    </section>
  );
}
```

- [ ] **Step 3: Write `InterventionQueue.jsx`**

```jsx
// frontend/src/components/mobile/InterventionQueue.jsx
// Spec §5.1. Critical-only with action buttons.
// Wire format: [{ id, name, concept, cds, fails, avgMinutes }]

export function InterventionQueue({ data, onAssign, on1on1 }) {
  if (!data || data.length === 0) return null;
  return (
    <section className="mobile-card">
      <p style={{ fontSize: 10, opacity: 0.6, letterSpacing: '0.18em', margin: 0 }}>
        INTERVENTION QUEUE · CRITICAL ONLY
      </p>
      {data.map((row) => (
        <article key={row.id} style={{ padding: '8px 0', borderBottom: '1px solid #334155' }}>
          <div style={{ fontWeight: 600 }}>{row.name}</div>
          <div style={{ fontSize: 11, opacity: 0.7 }}>
            {row.concept} {row.cds?.toFixed(2)} · {row.fails} fails · {row.avgMinutes}m avg
          </div>
          <div style={{ display: 'flex', gap: 6, marginTop: 6 }}>
            <button type="button" className="mobile-list-row__btn mobile-list-row__btn--primary" onClick={() => onAssign?.(row)}>Assign Set B</button>
            <button type="button" className="mobile-list-row__btn" onClick={() => on1on1?.(row)}>1:1</button>
          </div>
        </article>
      ))}
    </section>
  );
}
```

- [ ] **Step 4: Write `ActionStack.jsx`**

```jsx
// frontend/src/components/mobile/ActionStack.jsx
// Spec §5.2. Student's next actions (priority + optional).
// Wire format: [{ id, label, kind: 'priority'|'optional' }]

export function ActionStack({ data }) {
  if (!data || data.length === 0) return null;
  return (
    <section className="mobile-card">
      <p style={{ fontSize: 10, opacity: 0.6, letterSpacing: '0.18em', margin: 0 }}>NEXT ACTIONS</p>
      {data.map((a) => (
        <div key={a.id} style={{ padding: '4px 0', opacity: a.kind === 'optional' ? 0.7 : 1 }}>
          {a.kind === 'priority' ? '▶ ' : '▸ '}{a.label}
        </div>
      ))}
    </section>
  );
}
```

- [ ] **Step 5: Write `TopStrugglingConcepts.jsx`**

```jsx
// frontend/src/components/mobile/TopStrugglingConcepts.jsx
// Spec §6.1. K-adaptive concept list.
// Wire format: [{ code, name, cds, delta }]

import { useAdaptiveN } from '../../hooks/useAdaptiveN.js';
import { CDSPillDelta } from './primitives/CDSPillDelta.jsx';

const ROW = 56;
const PRIMARY = 200;
const CHROME = 104;

export function TopStrugglingConcepts({ data, onTap }) {
  const n = useAdaptiveN(CHROME, PRIMARY, ROW);
  if (!data) return null;
  const shown = data.slice(0, n);
  return (
    <section className="mobile-card">
      <p style={{ fontSize: 10, opacity: 0.6, letterSpacing: '0.18em', margin: 0 }}>
        TOP STRUGGLING CONCEPTS ({shown.length})
      </p>
      {shown.map((c) => (
        <button key={c.code} type="button" className="mobile-list-row" onClick={() => onTap?.(c)} style={{
          display: 'flex', justifyContent: 'space-between', width: '100%',
          background: 'transparent', border: 'none', color: 'inherit',
          padding: '8px 0', borderBottom: '1px solid #334155', minHeight: 56, textAlign: 'left',
        }}>
          <span>{c.code} · {c.name}</span>
          <CDSPillDelta value={c.cds} delta={c.delta} mode="mobile" />
        </button>
      ))}
    </section>
  );
}
```

- [ ] **Step 6: Write `ConceptMasteryBarSet.jsx`**

```jsx
// frontend/src/components/mobile/ConceptMasteryBarSet.jsx
// Spec §5.4. 7 concept bars (one per concept). Sticky overall mastery header.
// Wire format: [{ code, name, mastery: 0..1 }]

const COLOR = (m) =>
  m >= 0.8 ? '#22C55E' : m >= 0.6 ? '#86EFAC' : m >= 0.4 ? '#FACC15' : m >= 0.2 ? '#FB923C' : '#EF4444';

export function ConceptMasteryBarSet({ data }) {
  if (!data) return null;
  const overall = data.length
    ? (data.reduce((s, c) => s + (c.mastery ?? 0), 0) / data.length)
    : 0;
  return (
    <section className="mobile-card" style={{ position: 'relative' }}>
      <header style={{ position: 'sticky', top: 0, background: 'inherit', padding: '4px 0' }}>
        <p style={{ fontSize: 10, opacity: 0.6, letterSpacing: '0.18em', margin: 0 }}>OVERALL MASTERY</p>
        <div style={{ fontSize: 24, fontWeight: 700 }}>{Math.round(overall * 100)}%</div>
      </header>
      {data.map((c) => (
        <div key={c.code} style={{ marginTop: 8 }}>
          <div style={{ display: 'flex', justifyContent: 'space-between', fontSize: 13 }}>
            <span>{c.code} · {c.name}</span>
            <span style={{ opacity: 0.7 }}>{Math.round((c.mastery ?? 0) * 100)}%</span>
          </div>
          <div style={{ background: '#334155', height: 8, borderRadius: 4, marginTop: 4 }}>
            <div style={{
              background: COLOR(c.mastery), height: 8, borderRadius: 4,
              width: `${Math.round((c.mastery ?? 0) * 100)}%`,
            }} />
          </div>
        </div>
      ))}
    </section>
  );
}
```

- [ ] **Step 7: Write `WeeklyProgress.jsx`**

```jsx
// frontend/src/components/mobile/WeeklyProgress.jsx
// Spec §5.4. Student weekly progress summary.
// Wire format: { weekIso, submissions, passed, accuracy, deltaVsLast }

export function WeeklyProgress({ data }) {
  if (!data) return null;
  return (
    <section className="mobile-card">
      <p style={{ fontSize: 10, opacity: 0.6, letterSpacing: '0.18em', margin: 0 }}>THIS WEEK</p>
      <h3 style={{ fontSize: 15, margin: '4px 0' }}>Weekly progress</h3>
      <p style={{ fontSize: 12, opacity: 0.85, margin: 0 }}>
        {data.submissions} submissions · {data.passed} passed
        · accuracy {Math.round((data.accuracy ?? 0) * 100)}%
        {data.deltaVsLast != null && (
          <> · {data.deltaVsLast >= 0 ? '▲' : '▼'}{Math.abs(data.deltaVsLast).toFixed(2)} vs last week</>
        )}
      </p>
    </section>
  );
}
```

- [ ] **Step 8: Write `WeeklyTeachingInsight.jsx`**

```jsx
// frontend/src/components/mobile/WeeklyTeachingInsight.jsx
// Spec §6.1. One-sentence teaching insight + drill.
// Wire format: { headline, body, route }

export function WeeklyTeachingInsight({ data }) {
  if (!data) return null;
  return (
    <section className="mobile-card">
      <p style={{ fontSize: 10, opacity: 0.6, letterSpacing: '0.18em', margin: 0 }}>WEEKLY INSIGHT</p>
      <p style={{ fontSize: 14, fontWeight: 600, margin: '4px 0' }}>{data.headline}</p>
      <p style={{ fontSize: 12, opacity: 0.85, margin: '0 0 8px 0' }}>{data.body}</p>
      {data.route && <a href={data.route} className="mobile-card__cta">Open full insight →</a>}
    </section>
  );
}
```

- [ ] **Step 9: Write `WeakestConceptBar.jsx`**

```jsx
// frontend/src/components/mobile/WeakestConceptBar.jsx
// Spec §5.2. Single concept bar with mastery %.
// Wire format: [{ code, name, mastery, passedCount, totalCount }]  (length 1)

export function WeakestConceptBar({ data }) {
  const c = Array.isArray(data) ? data[0] : data;
  if (!c) return null;
  return (
    <section className="mobile-card">
      <p style={{ fontSize: 10, opacity: 0.6, letterSpacing: '0.18em', margin: 0 }}>YOUR WEAKEST CONCEPT</p>
      <div style={{ display: 'flex', justifyContent: 'space-between', marginTop: 6 }}>
        <span>{c.code} · {c.name}</span>
        <span style={{ background: '#FACC15', color: '#422006', padding: '1px 6px', borderRadius: 3, fontSize: 12 }}>
          {(c.mastery ?? 0).toFixed(2)}
        </span>
      </div>
      <div style={{ background: '#334155', height: 8, borderRadius: 4, marginTop: 4 }}>
        <div style={{
          background: '#FACC15', height: 8, borderRadius: 4,
          width: `${Math.round((c.mastery ?? 0) * 100)}%`,
        }} />
      </div>
      <p style={{ fontSize: 11, opacity: 0.7, marginTop: 4 }}>
        {c.passedCount} of {c.totalCount} exercises passed
      </p>
    </section>
  );
}
```

- [ ] **Step 10: Commit**

```bash
git add frontend/src/components/mobile/AtRiskQueue.jsx \
        frontend/src/components/mobile/AtRiskRoster.jsx \
        frontend/src/components/mobile/InterventionQueue.jsx \
        frontend/src/components/mobile/ActionStack.jsx \
        frontend/src/components/mobile/TopStrugglingConcepts.jsx \
        frontend/src/components/mobile/ConceptMasteryBarSet.jsx \
        frontend/src/components/mobile/WeeklyProgress.jsx \
        frontend/src/components/mobile/WeeklyTeachingInsight.jsx \
        frontend/src/components/mobile/WeakestConceptBar.jsx
git commit -m "feat(mobile): add 9 queue/list/roster secondary/tertiary widgets"
```

---

## Task 10: Add integrity widgets + static notices

**Files:**
- Create: `frontend/src/components/mobile/IntegrityFlagCount.jsx`
- Create: `frontend/src/components/mobile/IntegrityFlagList.jsx`
- Create: `frontend/src/components/mobile/IntegrityFlagHistory.jsx`
- Create: `frontend/src/components/mobile/IntegrityDrillNotice.jsx`
- Create: `frontend/src/components/mobile/DesktopOnlyNotice.jsx`
- Create: `frontend/src/components/mobile/AuditLog.jsx`
- Create: `frontend/src/components/mobile/ClassProfileRadar.jsx`
- Create: `frontend/src/components/mobile/ExerciseCardList.jsx`
- Create: `frontend/src/components/mobile/TestResultList.jsx`
- Create: `frontend/src/components/mobile/OpenFullEditorHint.jsx`
- Create: `frontend/src/components/mobile/Iso25010Instrument.jsx`

- [ ] **Step 1: Write `IntegrityFlagCount.jsx`**

```jsx
// frontend/src/components/mobile/IntegrityFlagCount.jsx
// Spec §5.4. Flag count summary + drill.
// Wire format: { openCount, recentCritical }

export function IntegrityFlagCount({ data, onDrill }) {
  if (!data) return null;
  return (
    <button type="button" className="mobile-card" onClick={onDrill} style={{
      display: 'flex', justifyContent: 'space-between', alignItems: 'center', width: '100%',
      textAlign: 'left', color: 'inherit',
    }}>
      <span>Integrity flags open</span>
      <span style={{ background: data.openCount > 0 ? '#EF4444' : '#22C55E', color: '#450A0A', padding: '2px 8px', borderRadius: 4, fontWeight: 600 }}>
        {data.openCount}
      </span>
    </button>
  );
}
```

- [ ] **Step 2: Write `IntegrityFlagList.jsx`**

```jsx
// frontend/src/components/mobile/IntegrityFlagList.jsx
// Spec §5.4. Three most recent critical flags. NO review on phone.
// Wire format: [{ id, type, studentName, summary, createdAt }]

export function IntegrityFlagList({ data, onDrill }) {
  if (!data || data.length === 0) return null;
  return (
    <section className="mobile-card">
      <p style={{ fontSize: 10, opacity: 0.6, letterSpacing: '0.18em', margin: 0 }}>RECENT FLAGS</p>
      {data.map((f) => (
        <article key={f.id} style={{ padding: '6px 0', borderBottom: '1px solid #334155' }}>
          <div style={{ fontSize: 13, fontWeight: 600 }}>{f.type} · {f.studentName}</div>
          <div style={{ fontSize: 11, opacity: 0.7 }}>{f.summary}</div>
        </article>
      ))}
      <button type="button" className="mobile-card__cta" style={{ marginTop: 8 }} onClick={onDrill}>
        View all (tablet+) →
      </button>
    </section>
  );
}
```

- [ ] **Step 3: Write `IntegrityFlagHistory.jsx`**

```jsx
// frontend/src/components/mobile/IntegrityFlagHistory.jsx
// Spec §5.4. Student's own flag history (read-only).
// Wire format: same shape as IntegrityFlagList, but scoped to the requesting student.

export function IntegrityFlagHistory({ data }) {
  if (!data || data.length === 0) {
    return <p style={{ padding: 16, opacity: 0.6 }}>0 flags on your record.</p>;
  }
  return (
    <section>
      {data.map((f) => (
        <article key={f.id} className="mobile-card">
          <div style={{ fontSize: 13, fontWeight: 600 }}>{f.type}</div>
          <div style={{ fontSize: 11, opacity: 0.7 }}>{f.summary} · {f.createdAt}</div>
        </article>
      ))}
    </section>
  );
}
```

- [ ] **Step 4: Write `IntegrityDrillNotice.jsx`**

```jsx
// frontend/src/components/mobile/IntegrityDrillNotice.jsx
// Spec §5.4. Static copy: "Flag review requires tablet or desktop."

export function IntegrityDrillNotice({ copy = 'Flag review requires tablet or desktop.' }) {
  return (
    <p style={{ fontSize: 11, opacity: 0.6, padding: '8px 12px', textAlign: 'center' }}>
      {copy}
    </p>
  );
}
```

- [ ] **Step 5: Write `DesktopOnlyNotice.jsx`**

```jsx
// frontend/src/components/mobile/DesktopOnlyNotice.jsx
// Spec §5.3. Honest disclosure: which features are desktop-only.

export function DesktopOnlyNotice({ copy }) {
  return (
    <p style={{ fontSize: 11, opacity: 0.6, padding: '8px 12px' }}>▸ {copy}</p>
  );
}
```

- [ ] **Step 6: Write `AuditLog.jsx`**

```jsx
// frontend/src/components/mobile/AuditLog.jsx
// Spec §5.4. Recent audit log entries, last 50, no filters on phone.
// Wire format: [{ id, action, actor, target, createdAt, summary }]

export function AuditLog({ data, onTap }) {
  if (!data || data.length === 0) {
    return <p style={{ padding: 16, opacity: 0.6 }}>No recent activity.</p>;
  }
  return (
    <section>
      {data.map((row) => (
        <button
          key={row.id}
          type="button"
          onClick={() => onTap?.(row)}
          className="mobile-card"
          style={{ display: 'block', width: '100%', textAlign: 'left', color: 'inherit' }}
        >
          <div style={{ fontSize: 13, fontWeight: 600 }}>{row.action}</div>
          <div style={{ fontSize: 11, opacity: 0.7 }}>{row.actor} → {row.target} · {row.createdAt}</div>
        </button>
      ))}
    </section>
  );
}
```

- [ ] **Step 7: Write `ClassProfileRadar.jsx`**

```jsx
// frontend/src/components/mobile/ClassProfileRadar.jsx
// Spec §6.1. Phone renders as summary (weakest concept + drill). NO D3 on phone.

export function ClassProfileRadar({ data, onDrill }) {
  if (!data) return null;
  const weakest = [...(data.axes ?? [])].sort((a, b) => a.mastery - b.mastery)[0];
  return (
    <section className="mobile-card">
      <p style={{ fontSize: 10, opacity: 0.6, letterSpacing: '0.18em', margin: 0 }}>CLASS CONCEPT PROFILE</p>
      {weakest && (
        <p style={{ fontSize: 13, margin: '4px 0' }}>
          <b>Weakest:</b> {weakest.code} · {weakest.name} ({(weakest.mastery * 100).toFixed(0)}%)
        </p>
      )}
      <button type="button" className="mobile-card__cta" onClick={onDrill}>
        View full radar →
      </button>
    </section>
  );
}
```

- [ ] **Step 8: Write `ExerciseCardList.jsx`**

```jsx
// frontend/src/components/mobile/ExerciseCardList.jsx
// Spec §5.4. Compact card list of available exercises.
// Wire format: [{ id, title, concept, difficulty, route }]

export function ExerciseCardList({ data, onTap }) {
  if (!data || data.length === 0) {
    return <p style={{ padding: 16, opacity: 0.6 }}>No exercises assigned yet.</p>;
  }
  return (
    <section>
      {data.map((ex) => (
        <button
          key={ex.id}
          type="button"
          className="mobile-card"
          onClick={() => onTap?.(ex)}
          style={{ display: 'block', width: '100%', textAlign: 'left', color: 'inherit' }}
        >
          <div style={{ fontSize: 14, fontWeight: 600 }}>{ex.title}</div>
          <div style={{ fontSize: 11, opacity: 0.7, marginTop: 2 }}>
            {ex.concept} · difficulty {(ex.difficulty * 100).toFixed(0)}%
          </div>
        </button>
      ))}
    </section>
  );
}
```

- [ ] **Step 9: Write `TestResultList.jsx`**

```jsx
// frontend/src/components/mobile/TestResultList.jsx
// Spec §5.4. Test results after Run/Submit on /student/exercises/:id.
// Wire format: [{ name, passed, expected, got }]

export function TestResultList({ data }) {
  if (!data || data.length === 0) return null;
  return (
    <section className="mobile-card">
      <p style={{ fontSize: 10, opacity: 0.6, letterSpacing: '0.18em', margin: 0 }}>OUTPUT</p>
      {data.map((t, i) => (
        <div key={i} style={{ fontSize: 12, color: t.passed ? '#22C55E' : '#EF4444', padding: '2px 0' }}>
          {t.passed ? '✓' : '✗'} Test {i + 1} {t.passed ? 'passed' : `failed — expected '${t.expected}' got '${t.got}'`}
        </div>
      ))}
    </section>
  );
}
```

- [ ] **Step 10: Write `OpenFullEditorHint.jsx`**

```jsx
// frontend/src/components/mobile/OpenFullEditorHint.jsx
// Spec §5.4. CTA to switch to the full Monaco editor on tablet+.

export function OpenFullEditorHint({ copy = '↗ Open in full editor (tablet+)' }) {
  return (
    <a href="?mode=full" className="mobile-card" style={{
      display: 'block', textAlign: 'center', fontSize: 12, color: '#94A3B8', textDecoration: 'none',
    }}>
      {copy}
    </a>
  );
}
```

- [ ] **Step 11: Write `Iso25010Instrument.jsx`**

```jsx
// frontend/src/components/mobile/Iso25010Instrument.jsx
// Spec §5.4. ISO/IEC 25010 evaluation instrument, 4-point Likert, one question per screen.
// Wire format: { questions: [{ id, characteristic, text, scale: [1,2,3,4] }], progress: { current, total } }

import { useState } from 'react';

export function Iso25010Instrument({ data, onSubmit }) {
  const [answers, setAnswers] = useState({});
  if (!data?.questions) return <p style={{ padding: 16, opacity: 0.6 }}>No instrument loaded.</p>;
  const total = data.questions.length;
  const idx = Object.keys(answers).length;
  const q = data.questions[idx];
  const isLast = idx === total - 1;

  if (!q) {
    return (
      <section className="mobile-card" style={{ textAlign: 'center' }}>
        <p>All {total} questions answered. Tap submit to send.</p>
        <button type="button" className="mobile-card__cta" onClick={() => onSubmit?.(answers)}>
          Submit evaluation
        </button>
      </section>
    );
  }

  return (
    <section className="mobile-card">
      <p style={{ fontSize: 11, opacity: 0.6, margin: 0 }}>
        Question {idx + 1} of {total} · ISO/IEC 25010 — {q.characteristic}
      </p>
      <div style={{ background: '#334155', height: 4, borderRadius: 2, margin: '6px 0 12px 0' }}>
        <div style={{ background: '#7C3AED', height: 4, borderRadius: 2, width: `${((idx + 1) / total) * 100}%` }} />
      </div>
      <h3 style={{ fontSize: 16, margin: '0 0 16px 0' }}>{q.text}</h3>
      <div style={{ display: 'grid', gridTemplateColumns: '1fr 1fr', gap: 8 }}>
        {q.scale.map((v) => (
          <button
            key={v}
            type="button"
            onClick={() => setAnswers((a) => ({ ...a, [q.id]: v }))}
            className="mobile-list-row__btn"
            style={{
              background: answers[q.id] === v ? '#7C3AED' : undefined,
              color: answers[q.id] === v ? '#F8FAFC' : undefined,
            }}
          >
            {v} — {labelFor(v)}
          </button>
        ))}
      </div>
    </section>
  );
}

function labelFor(v) {
  return ['Strongly disagree', 'Disagree', 'Agree', 'Strongly agree'][v - 1] ?? '';
}
```

- [ ] **Step 12: Commit**

```bash
git add frontend/src/components/mobile/IntegrityFlagCount.jsx \
        frontend/src/components/mobile/IntegrityFlagList.jsx \
        frontend/src/components/mobile/IntegrityFlagHistory.jsx \
        frontend/src/components/mobile/IntegrityDrillNotice.jsx \
        frontend/src/components/mobile/DesktopOnlyNotice.jsx \
        frontend/src/components/mobile/AuditLog.jsx \
        frontend/src/components/mobile/ClassProfileRadar.jsx \
        frontend/src/components/mobile/ExerciseCardList.jsx \
        frontend/src/components/mobile/TestResultList.jsx \
        frontend/src/components/mobile/OpenFullEditorHint.jsx \
        frontend/src/components/mobile/Iso25010Instrument.jsx
git commit -m "feat(mobile): add 11 secondary/tertiary widgets (integrity, admin, exercise, eval)"
```

---

## Task 11: Add `RiskBadge` and `CDSPillDelta` mobile primitives

**Files:**
- Create: `frontend/src/components/mobile/primitives/RiskBadge.jsx`
- Create: `frontend/src/components/mobile/primitives/CDSPillDelta.jsx`
- Create: `frontend/src/components/mobile/primitives/RiskBadge.test.jsx`

- [ ] **Step 1: Write the failing test**

```jsx
// frontend/src/components/mobile/primitives/RiskBadge.test.jsx
import { describe, it, expect } from 'vitest';
import { render, screen } from '@testing-library/react';
import { RiskBadge } from './RiskBadge.jsx';

describe('<RiskBadge mode="mobile">', () => {
  it('always shows the label AND the color (spec §6.1, §13.10)', () => {
    render(<RiskBadge level="critical" mode="mobile" />);
    const el = screen.getByText('Critical');
    expect(el).toBeInTheDocument();
    expect(el.parentElement.dataset.level).toBe('critical');
  });

  it('renders all 4 levels', () => {
    ['low', 'medium', 'high', 'critical'].forEach((l) => {
      const { unmount } = render(<RiskBadge level={l} mode="mobile" />);
      expect(screen.getByText(new RegExp(l, 'i'))).toBeInTheDocument();
      unmount();
    });
  });

  it('renders the symbol as decorative (aria-hidden)', () => {
    render(<RiskBadge level="high" mode="mobile" />);
    const sym = screen.getByText('●⚠');
    expect(sym.getAttribute('aria-hidden')).toBe('true');
  });
});
```

- [ ] **Step 2: Run test to verify it fails**

Run: `cd frontend && npx vitest run src/components/mobile/primitives/RiskBadge.test.jsx`
Expected: FAIL — component does not exist.

- [ ] **Step 3: Write `RiskBadge.jsx`**

```jsx
// frontend/src/components/mobile/primitives/RiskBadge.jsx
// Spec §6.1, §13.10. Mobile: color + label always shown. Symbol is decorative.

const SYMBOLS = { critical: '●✕', high: '●⚠', medium: '●◐', low: '●○' };
const LABELS = { critical: 'Critical', high: 'High', medium: 'Medium', low: 'Low' };

export function RiskBadge({ level, mode = 'desktop' }) {
  if (mode === 'mobile') {
    return (
      <span className="risk-badge--mobile" data-level={level} role="status">
        <span className="risk-badge__symbol" aria-hidden="true">{SYMBOLS[level]}</span>
        <span className="risk-badge__label">{LABELS[level]}</span>
      </span>
    );
  }
  // desktop: full label + className only (existing desktop behaviour)
  return (
    <span className={`risk-badge risk-badge--${level}`} role="status">
      {LABELS[level]}
    </span>
  );
}
```

- [ ] **Step 4: Write `CDSPillDelta.jsx`**

```jsx
// frontend/src/components/mobile/primitives/CDSPillDelta.jsx
// Spec §6.1. Mobile: tiny pill (numeric only) + small arrow. No Δ number.

export function CDSPillDelta({ value, delta, mode = 'desktop' }) {
  const cls = value >= 0.66 ? 'critical' : value >= 0.50 ? 'high' : value >= 0.31 ? 'medium' : 'low';
  const arrow = delta == null ? '▬' : delta > 0 ? '▲' : delta < 0 ? '▼' : '▬';

  if (mode === 'mobile') {
    return (
      <span style={{ display: 'inline-flex', alignItems: 'center', gap: 4 }}>
        <span className="cds-pill--mobile" data-level={cls}>{value?.toFixed(2)}</span>
        <span style={{ fontSize: 10 }} aria-hidden="true">{arrow}</span>
      </span>
    );
  }
  return (
    <span className="cds-pill cds-pill--with-delta" data-level={cls}>
      {value?.toFixed(2)} {arrow} {delta != null && `${delta >= 0 ? '+' : ''}${delta.toFixed(2)}`}
    </span>
  );
}
```

- [ ] **Step 5: Run test to verify it passes**

Run: `cd frontend && npx vitest run src/components/mobile/primitives/RiskBadge.test.jsx`
Expected: PASS — 3 tests.

- [ ] **Step 6: Commit**

```bash
git add frontend/src/components/mobile/primitives/
git commit -m "feat(mobile): add RiskBadge and CDSPillDelta mobile primitives (color+label rule)"
```

---

## Task 12: Add `CodePreviewSurface` and code-block route scaffolding

**Files:**
- Create: `frontend/src/components/mobile/CodePreviewSurface.jsx`
- Create: `frontend/src/components/mobile/CodePreviewSurface.test.jsx`

- [ ] **Step 1: Write the failing test**

```jsx
// frontend/src/components/mobile/CodePreviewSurface.test.jsx
import { describe, it, expect, vi } from 'vitest';
import { render, screen, fireEvent } from '@testing-library/react';
import { CodePreviewSurface } from './CodePreviewSurface.jsx';

describe('<CodePreviewSurface>', () => {
  const data = {
    id: 'ex-3',
    title: 'Nested Loops',
    code: '#include <iostream>\nint main() { return 0; }',
    language: 'cpp',
    difficulty: 0.62,
    concepts: ['LP'],
  };

  it('renders the title and concepts', () => {
    render(<CodePreviewSurface data={data} onRun={() => {}} onSubmit={() => {}} />);
    expect(screen.getByText('Nested Loops')).toBeInTheDocument();
    expect(screen.getByText(/LP/)).toBeInTheDocument();
  });

  it('renders code inside a horizontal-scrollable <pre> (no Monaco)', () => {
    const { container } = render(<CodePreviewSurface data={data} onRun={() => {}} onSubmit={() => {}} />);
    const pre = container.querySelector('pre');
    expect(pre).toBeInTheDocument();
    expect(pre.className).toMatch(/code-preview-surface/);
    expect(pre.style.overflowX).toBe('auto');
  });

  it('fires onRun and onSubmit callbacks', () => {
    const onRun = vi.fn();
    const onSubmit = vi.fn();
    render(<CodePreviewSurface data={data} onRun={onRun} onSubmit={onSubmit} />);
    fireEvent.click(screen.getByText('▶ Run'));
    fireEvent.click(screen.getByText('Submit'));
    expect(onRun).toHaveBeenCalled();
    expect(onSubmit).toHaveBeenCalled();
  });
});
```

- [ ] **Step 2: Run test to verify it fails**

Run: `cd frontend && npx vitest run src/components/mobile/CodePreviewSurface.test.jsx`
Expected: FAIL — component does not exist.

- [ ] **Step 3: Write `CodePreviewSurface.jsx`**

```jsx
// frontend/src/components/mobile/CodePreviewSurface.jsx
// Spec §5.4, §6.1, §6.2. Phone code preview — NO Monaco, plain <pre>, horizontally scrollable.

export function CodePreviewSurface({ data, onRun, onSubmit }) {
  if (!data) return null;
  return (
    <section>
      <header className="mobile-card">
        <div style={{ fontSize: 15, fontWeight: 600 }}>{data.title}</div>
        <div style={{ fontSize: 11, opacity: 0.7, marginTop: 4 }}>
          CDS-predicted difficulty: {data.difficulty?.toFixed(2)} · Concepts: {data.concepts?.join(', ')}
        </div>
      </header>

      <pre
        className="code-preview-surface"
        style={{ overflowX: 'auto' }}
        aria-label="Code preview (read-only on phone)"
      >
        {`// Read-only on phone. Switch to tablet/desktop to edit.\n${data.code}`}
      </pre>

      <div style={{ display: 'flex', gap: 6, marginTop: 8 }}>
        <button
          type="button"
          onClick={onRun}
          className="mobile-card__cta"
          style={{ flex: 1, textAlign: 'center', background: '#22C55E' }}
        >▶ Run</button>
        <button
          type="button"
          onClick={onSubmit}
          className="mobile-list-row__btn"
          style={{ flex: 1, textAlign: 'center' }}
        >Submit</button>
      </div>
    </section>
  );
}
```

- [ ] **Step 4: Run test to verify it passes**

Run: `cd frontend && npx vitest run src/components/mobile/CodePreviewSurface.test.jsx`
Expected: PASS — 3 tests.

- [ ] **Step 5: Commit**

```bash
git add frontend/src/components/mobile/CodePreviewSurface.jsx frontend/src/components/mobile/CodePreviewSurface.test.jsx
git commit -m "feat(mobile): add CodePreviewSurface (no Monaco, plain pre, horizontal scroll)"
```

---

## Task 13: Wire the mobile pages (14 routes)

**Files:**
- Create: `frontend/src/pages/mobile/instructor/Command.jsx`
- Create: `frontend/src/pages/mobile/instructor/Students.jsx`
- Create: `frontend/src/pages/mobile/instructor/Concepts.jsx`
- Create: `frontend/src/pages/mobile/instructor/Integrity.jsx`
- Create: `frontend/src/pages/mobile/instructor/Sections.jsx`
- Create: `frontend/src/pages/mobile/student/Today.jsx`
- Create: `frontend/src/pages/mobile/student/Exercises.jsx`
- Create: `frontend/src/pages/mobile/student/ExerciseDetail.jsx`
- Create: `frontend/src/pages/mobile/student/Progress.jsx`
- Create: `frontend/src/pages/mobile/student/Integrity.jsx`
- Create: `frontend/src/pages/mobile/student/Sections.jsx`
- Create: `frontend/src/pages/mobile/admin/Overview.jsx`
- Create: `frontend/src/pages/mobile/admin/Evaluation.jsx`
- Create: `frontend/src/pages/mobile/admin/Audit.jsx`

- [ ] **Step 1: Write a shared `MobileScreen` shell**

```jsx
// frontend/src/pages/mobile/MobileScreen.jsx
// Renders one screen from the layout config. Zero role branching.

import { useEffect, useState } from 'react';
import { getConfig, shouldShow } from '../../config/useLayoutConfig.js';
import { StateAwareShell } from '../../state/StateAwareShell.jsx';
import { useStateDerivation } from '../../state/useStateDerivation.js';

import { InstructorPriorityInsight } from '../../components/mobile/InstructorPriorityInsight.jsx';
import { StudentTodayFocus }         from '../../components/mobile/StudentTodayFocus.jsx';
import { SnapshotMetrics }           from '../../components/mobile/SnapshotMetrics.jsx';
import { EvaluationProgress }        from '../../components/mobile/EvaluationProgress.jsx';
import { AtRiskQueue }               from '../../components/mobile/AtRiskQueue.jsx';
import { AtRiskRoster }              from '../../components/mobile/AtRiskRoster.jsx';
import { InterventionQueue }         from '../../components/mobile/InterventionQueue.jsx';
import { ActionStack }               from '../../components/mobile/ActionStack.jsx';
import { TopStrugglingConcepts }     from '../../components/mobile/TopStrugglingConcepts.jsx';
import { WeakestConceptBar }         from '../../components/mobile/WeakestConceptBar.jsx';
import { ConceptMasteryBarSet }      from '../../components/mobile/ConceptMasteryBarSet.jsx';
import { WeeklyProgress }            from '../../components/mobile/WeeklyProgress.jsx';
import { WeeklyTeachingInsight }     from '../../components/mobile/WeeklyTeachingInsight.jsx';
import { ClassProfileRadar }         from '../../components/mobile/ClassProfileRadar.jsx';
import { IntegrityFlagCount }        from '../../components/mobile/IntegrityFlagCount.jsx';
import { IntegrityFlagList }         from '../../components/mobile/IntegrityFlagList.jsx';
import { IntegrityFlagHistory }      from '../../components/mobile/IntegrityFlagHistory.jsx';
import { IntegrityDrillNotice }      from '../../components/mobile/IntegrityDrillNotice.jsx';
import { DesktopOnlyNotice }         from '../../components/mobile/DesktopOnlyNotice.jsx';
import { AuditLog }                  from '../../components/mobile/AuditLog.jsx';
import { ExerciseCardList }          from '../../components/mobile/ExerciseCardList.jsx';
import { TestResultList }            from '../../components/mobile/TestResultList.jsx';
import { OpenFullEditorHint }        from '../../components/mobile/OpenFullEditorHint.jsx';
import { CodePreviewSurface }        from '../../components/mobile/CodePreviewSurface.jsx';
import { Iso25010Instrument }        from '../../components/mobile/Iso25010Instrument.jsx';
import { SectionList }               from '../../components/SectionList.jsx';

const WIDGET_MAP = {
  InstructorPriorityInsight, AtRiskQueue, AtRiskRoster, InterventionQueue,
  TopStrugglingConcepts, WeakestConceptBar, ConceptMasteryBarSet, WeeklyProgress,
  WeeklyTeachingInsight, ClassProfileRadar, ActionStack, StudentTodayFocus,
  SnapshotMetrics, EvaluationProgress, Iso25010Instrument, AuditLog,
  IntegrityFlagCount, IntegrityFlagList, IntegrityFlagHistory, IntegrityDrillNotice,
  DesktopOnlyNotice, ExerciseCardList, TestResultList, OpenFullEditorHint,
  CodePreviewSurface, SectionList,
};

export function useFetch(endpoint) {
  const [data, setData] = useState(null);
  const [loading, setLoading] = useState(false);
  useEffect(() => {
    if (!endpoint) return;
    let cancelled = false;
    setLoading(true);
    fetch(endpoint)
      .then((r) => r.ok ? r.json() : null)
      .then((d) => { if (!cancelled) { setData(d); setLoading(false); } })
      .catch(() => { if (!cancelled) setLoading(false); });
    return () => { cancelled = true; };
  }, [endpoint]);
  return { data, loading };
}

export function Widget({ widget, role }) {
  const { data } = useFetch(widget.endpoint);
  if (widget.static) return null;
  if (!shouldShow(widget, data)) return null;
  const Component = WIDGET_MAP[widget.widget];
  if (!Component) return null;
  // Special-case: SectionList is reused; only pass data if defined
  return <Component data={data} role={role} {...(widget.render ? { render: widget.render } : {})} />;
}

export function MobileScreen({ role, path, params = {} }) {
  const config = getConfig(role, 'mobile');
  const screen = config.screens[path] ?? config.screens[`${path}/:id`];
  if (!screen) return <p style={{ padding: 16 }}>404 — unknown screen {path}</p>;

  return (
    <main className="mobile-content">
      {screen.primary && <Widget widget={screen.primary} role={role} />}
      {screen.primaryAction && <Widget widget={screen.primaryAction} role={role} />}
      {screen.secondary?.map((w, i) => <Widget key={`s${i}`} widget={w} role={role} />)}
      {screen.tertiary?.map((w, i) => <Widget key={`t${i}`} widget={w} role={role} />)}
    </main>
  );
}
```

- [ ] **Step 2: Write 14 thin page wrappers**

Each page just delegates to `MobileScreen`. Example for `Command.jsx`:

```jsx
// frontend/src/pages/mobile/instructor/Command.jsx
import { MobileScreen } from '../MobileScreen.jsx';
export default function Command() {
  return <MobileScreen role="instructor" path="/instructor/command" />;
}
```

Apply the same pattern to all 14 files:
- `Students.jsx` → `path="/instructor/students"`
- `Concepts.jsx` → `path="/instructor/concepts"`
- `Integrity.jsx` → `path="/instructor/integrity"`
- `Sections.jsx` → `path="/instructor/sections"`
- `Today.jsx` → `path="/student/today"`
- `Exercises.jsx` → `path="/student/exercises"`
- `ExerciseDetail.jsx` → `path="/student/exercises/:id"` (params.id comes from `useParams()` in this one; use the `:id` screen key directly)
- `Progress.jsx` → `path="/student/progress"`
- `student/Integrity.jsx` → `path="/student/integrity"`
- `student/Sections.jsx` → `path="/student/sections"`
- `admin/Overview.jsx` → `path="/admin/overview"`
- `admin/Evaluation.jsx` → `path="/admin/evaluation"`
- `admin/Audit.jsx` → `path="/admin/audit"`

For `ExerciseDetail.jsx`, use the route parameter to pick the right code block:

```jsx
// frontend/src/pages/mobile/student/ExerciseDetail.jsx
import { useParams } from 'react-router-dom';
import { useState } from 'react';
import { getConfig } from '../../../config/useLayoutConfig.js';
import { useFetch } from '../MobileScreen.jsx';
import { CodePreviewSurface } from '../../../components/mobile/CodePreviewSurface.jsx';
import { TestResultList } from '../../../components/mobile/TestResultList.jsx';
import { OpenFullEditorHint } from '../../../components/mobile/OpenFullEditorHint.jsx';

export default function ExerciseDetail() {
  const { id } = useParams();
  const screen = getConfig('student', 'mobile').screens['/student/exercises/:id'];
  const { data } = useFetch(`/api/exercises/${id}`);
  const [results, setResults] = useState(null);

  return (
    <main className="mobile-content">
      <CodePreviewSurface
        data={data}
        onRun={async () => { const r = await fetch(`/api/exercises/${id}/run`, { method: 'POST' }); setResults(await r.json()); }}
        onSubmit={async () => { const r = await fetch(`/api/submissions`, { method: 'POST', body: JSON.stringify({ exerciseId: id, code: data?.code }) }); setResults(await r.json()); }}
      />
      <TestResultList data={results} />
      <OpenFullEditorHint />
    </main>
  );
}
```

- [ ] **Step 3: Commit**

```bash
git add frontend/src/pages/mobile/
git commit -m "feat(mobile): add 14 mobile page wrappers driven by useLayoutConfig"
```

---

## Task 14: Wire `App.jsx` to route by mode

**Files:**
- Read: `frontend/src/App.jsx` (to understand current routing)
- Modify: `frontend/src/App.jsx`

- [ ] **Step 1: Read the existing `App.jsx`**

```bash
cat frontend/src/App.jsx
```

- [ ] **Step 2: Add a `MobileRouteSwitch` that picks a mobile page when `useMode() === 'mobile'`, else falls back to the existing desktop page**

```jsx
// frontend/src/App.jsx
// Add at the top:
import { useMode } from './hooks/use-mobile.js';
import { useUser } from './auth/useUser.js'; // adjust import to the project's existing user hook

// For each route, wrap the desktop element in a mode switch:
function Route({ desktop, mobile, path }) {
  const mode = useMode();
  return mode === 'mobile' ? mobile : desktop;
}
```

For each instructor/student/admin route, register both elements in the route table:

```jsx
<Route path="/instructor/command"   desktop={<DesktopInstructorCommand />}   mobile={<MobileInstructorCommand />} />
<Route path="/instructor/students"  desktop={<DesktopInstructorStudents />}  mobile={<MobileInstructorStudents />} />
<Route path="/instructor/concepts"  desktop={<DesktopInstructorConcepts />}  mobile={<MobileInstructorConcepts />} />
<Route path="/instructor/integrity" desktop={<DesktopInstructorIntegrity />} mobile={<MobileInstructorIntegrity />} />
<Route path="/instructor/sections"  desktop={<DesktopInstructorSections />}  mobile={<MobileInstructorSections />} />

<Route path="/student/today"         desktop={<DesktopStudentToday />}         mobile={<MobileStudentToday />} />
<Route path="/student/exercises"     desktop={<DesktopStudentExercises />}    mobile={<MobileStudentExercises />} />
<Route path="/student/exercises/:id" desktop={<DesktopStudentExerciseDetail />} mobile={<MobileStudentExerciseDetail />} />
<Route path="/student/progress"      desktop={<DesktopStudentProgress />}      mobile={<MobileStudentProgress />} />
<Route path="/student/integrity"     desktop={<DesktopStudentIntegrity />}     mobile={<MobileStudentIntegrity />} />
<Route path="/student/sections"      desktop={<DesktopStudentSections />}      mobile={<MobileStudentSections />} />

<Route path="/admin/overview"         desktop={<DesktopAdminOverview />}   mobile={<MobileAdminOverview />} />
<Route path="/admin/evaluation"       desktop={<DesktopAdminEvaluation />} mobile={<MobileAdminEvaluation />} />
<Route path="/admin/audit"            desktop={<DesktopAdminAudit />}      mobile={<MobileAdminAudit />} />
```

- [ ] **Step 3: Wrap the entire app in a `Layout` that renders `AppBar` + `BottomNav` when `mode === 'mobile'`**

```jsx
// At the root of <App />:
function App() {
  const mode = useMode();
  return (
    <BrowserRouter>
      {mode === 'mobile' && <MobileChrome />}
      <Routes>
        {/* ... route table from Step 2 */}
      </Routes>
    </BrowserRouter>
  );
}

function MobileChrome() {
  const { user } = useUser();
  const cfg = getConfig(user.role, 'mobile');
  return (
    <>
      <AppBar title={cfg.chrome.appBar.title} rightSlot={cfg.chrome.appBar.rightSlot} userMenu={<UserMenu />} />
      {/* BottomNav is sticky; routes render their own <main>. */}
      <BottomNav items={cfg.chrome.bottomNav.items} />
    </>
  );
}
```

- [ ] **Step 4: Verify the build still passes**

Run: `cd frontend && npm run build 2>&1 | tail -20`
Expected: build succeeds.

- [ ] **Step 5: Smoke test the routing manually**

Start the dev server: `cd frontend && npm run dev`
Open in a browser with viewport set to 375×812 (Chrome DevTools device emulation, iPhone 12 Pro). Verify:
- `/student/today` shows the mobile layout (AppBar, content, BottomNav with 5 items).
- `/admin/overview` shows the snapshot grid + the purple "Review pending evaluations (N)" CTA.
- `/instructor/command` shows the priority insight (or `NoData` copy if no submissions exist).

- [ ] **Step 6: Commit**

```bash
git add frontend/src/App.jsx
git commit -m "feat(mobile): route by mode — mobile pages when useMode() === 'mobile', else desktop"
```

---

## Task 15: Add naming-canon + layout-config-driven guards (acceptance §13.7, §13.16, §13.17)

**Files:**
- Create: `frontend/tests/mobile/naming-canon.test.js`
- Create: `frontend/tests/mobile/layout-config-driven.test.js`

- [ ] **Step 1: Write the naming-canon test (acceptance §13.16)**

```js
// frontend/tests/mobile/naming-canon.test.js
// Spec §9, acceptance §13.16. Every component filename in src/components/mobile/
// must match a canonical name from the spec.

import { describe, it, expect } from 'vitest';
import { readdirSync } from 'fs';
import { join } from 'path';

const CANON = new Set([
  'AppBar', 'BottomNav',
  'InstructorPriorityInsight', 'AtRiskQueue', 'AtRiskRoster', 'InterventionQueue',
  'TopStrugglingConcepts', 'ClassProfileRadar', 'WeeklyTeachingInsight',
  'IntegrityFlagCount', 'IntegrityFlagList', 'IntegrityFlagHistory', 'IntegrityDrillNotice',
  'StudentTodayFocus', 'WeakestConceptBar', 'ConceptMasteryBarSet', 'ActionStack', 'WeeklyProgress',
  'ExerciseCardList', 'CodePreviewSurface', 'TestResultList', 'OpenFullEditorHint',
  'SnapshotMetrics', 'EvaluationProgress', 'Iso25010Instrument', 'AuditLog',
  'DesktopOnlyNotice', 'SectionList',
  'RiskBadge', 'CDSPillDelta',
  'primitives',  // dir
  '.', '..',
]);

describe('mobile component naming canon (spec §9, acceptance §13.16)', () => {
  const dir = 'src/components/mobile';
  const files = readdirSync(dir);
  it('every .jsx file under src/components/mobile/ is a canonical name', () => {
    const offenders = files
      .filter((f) => f.endsWith('.jsx'))
      .map((f) => f.replace('.jsx', ''))
      .filter((n) => !CANON.has(n));
    expect(offenders).toEqual([]);
  });
});
```

- [ ] **Step 2: Write the layout-config-driven test (acceptance §13.7)**

```js
// frontend/tests/mobile/layout-config-driven.test.js
// Spec §2.3, acceptance §13.7. 100% of phone screens render from the config object;
// zero `if (role === ...)` branches in src/pages/mobile/.

import { describe, it, expect } from 'vitest';
import { readFileSync, readdirSync, statSync } from 'fs';
import { join } from 'path';

function walkJsx(dir) {
  const out = [];
  for (const e of readdirSync(dir)) {
    const p = join(dir, e);
    if (statSync(p).isDirectory()) out.push(...walkJsx(p));
    else if (p.endsWith('.jsx')) out.push(p);
  }
  return out;
}

describe('mobile pages are layout-config-driven (acceptance §13.7)', () => {
  it('no mobile page checks user.role directly', () => {
    const files = walkJsx('src/pages/mobile');
    const offenders = [];
    for (const f of files) {
      const src = readFileSync(f, 'utf8');
      if (/role\s*===\s*['"]/.test(src) || /role\s*!==\s*['"]/.test(src)) {
        offenders.push(f);
      }
    }
    expect(offenders).toEqual([]);
  });
});
```

- [ ] **Step 3: Run both tests**

Run: `cd frontend && npx vitest run tests/mobile/`
Expected: PASS.

- [ ] **Step 4: Commit**

```bash
git add frontend/tests/mobile/
git commit -m "test(mobile): add naming-canon and layout-config-driven guards (acceptance §13.7, §13.16)"
```

---

## Task 16: Add bundle-budget check (acceptance §13.4, §13.5)

**Files:**
- Create: `frontend/scripts/check-mobile-bundle.mjs`

- [ ] **Step 1: Write the bundle-budget script**

```js
// frontend/scripts/check-mobile-bundle.mjs
// Acceptance §13.4, §13.5.
// Fails the build if any phone-route bundle exceeds 200 KB gzipped,
// or if D3 is present in a phone summary-mode bundle.

import { readFileSync, readdirSync, statSync } from 'fs';
import { join } from 'path';
import { gzipSync } from 'zlib';
import { execSync } from 'child_process';

const BUDGET_KB = 200;
const PHONE_ROUTES = [
  '/instructor/command', '/instructor/students', '/instructor/concepts', '/instructor/integrity',
  '/student/today', '/student/exercises', '/student/progress',
  '/admin/overview',
];

console.log('Building...');
execSync('npm run build', { stdio: 'inherit' });

const distDir = 'dist/assets';
const chunks = readdirSync(distDir).filter(f => f.endsWith('.js'));
let bad = [];

for (const chunk of chunks) {
  const gz = gzipSync(readFileSync(join(distDir, chunk))).length;
  const kb = gz / 1024;
  const src = readFileSync(join(distDir, chunk), 'utf8');
  const containsD3 = /d3-|from "d3"|from 'd3'/.test(src) || /d3\.(select|scale|line|axis)/.test(src);
  if (kb > BUDGET_KB) bad.push(`${chunk}: ${kb.toFixed(1)} KB > ${BUDGET_KB} KB`);
  if (containsD3 && chunk.includes('mobile')) bad.push(`${chunk}: contains D3 (forbidden in summary-mode phone bundle)`);
}

if (bad.length) {
  console.error('Bundle budget FAILED:');
  for (const b of bad) console.error('  -', b);
  process.exit(1);
}
console.log(`OK — all phone chunks <= ${BUDGET_KB} KB gzipped, no D3 in mobile summary bundles.`);
```

- [ ] **Step 2: Add an npm script to invoke it**

Modify `frontend/package.json` (find the `"scripts"` block and add):

```json
"check:mobile-bundle": "node scripts/check-mobile-bundle.mjs"
```

- [ ] **Step 3: Run it once to confirm it works**

Run: `cd frontend && npm run check:mobile-bundle 2>&1 | tail -10`
Expected: prints `OK — all phone chunks ...` OR a list of violations to fix.

If violations appear, the most likely cause is a stray D3 import in `AtRiskQueue.jsx` or similar. The fix is to dynamic-import D3 only on `render === 'full'`. Spot-check each mobile chunk's contents:

```bash
cd frontend && grep -l "from 'd3'" dist/assets/*.js 2>/dev/null
```

- [ ] **Step 4: Commit**

```bash
git add frontend/scripts/check-mobile-bundle.mjs frontend/package.json
git commit -m "ci(mobile): add bundle-budget check (≤200KB gzipped, no D3 in phone summary bundles)"
```

---

## Task 17: Add Playwright E2E for mobile triage (acceptance §13.1, §13.2, §13.11, §13.12)

**Files:**
- Create: `frontend/tests/e2e/mobile-triage.spec.js`

- [ ] **Step 1: Write the E2E spec**

```js
// frontend/tests/e2e/mobile-triage.spec.js
// Acceptance §13.1 (instructor triage < 10s), §13.2 (student next-action < 3s),
// §13.11 (admin has 1+ action path), §13.12 (ISO/IEC 25010 < 4 min on phone).

import { test, expect } from '@playwright/test';

test.use({ viewport: { width: 375, height: 812 } });

test('instructor sees top-3 at-risk students in < 10s (acceptance §13.1)', async ({ page }) => {
  await page.goto('/instructor/command');
  const t0 = Date.now();
  // Wait for the AtRiskQueue to appear.
  await expect(page.getByText('AT-RISK QUEUE')).toBeVisible({ timeout: 9000 });
  const t1 = Date.now();
  expect(t1 - t0).toBeLessThan(10000);
});

test('student sees next action in < 3s (acceptance §13.2)', async ({ page }) => {
  await page.goto('/student/today');
  await expect(page.getByText("TODAY'S FOCUS")).toBeVisible({ timeout: 2500 });
});

test('admin overview surfaces the evaluation queue (acceptance §13.11)', async ({ page }) => {
  await page.goto('/admin/overview');
  await expect(page.getByText(/Review pending evaluations/)).toBeVisible();
});

test('admin can complete ISO/IEC 25010 evaluation (acceptance §13.12)', async ({ page }) => {
  await page.goto('/admin/evaluation');
  // Iterate through 8 questions (the spec's instrument size); tap first scale option.
  for (let i = 0; i < 8; i++) {
    await page.getByRole('button', { name: /^1 — / }).click();
  }
  await expect(page.getByText('Submit evaluation')).toBeVisible({ timeout: 240_000 });
});
```

- [ ] **Step 2: Run the E2E spec**

Run: `cd frontend && npx playwright test tests/e2e/mobile-triage.spec.js`
Expected: 4 tests pass (or skip with clear messages if the dev backend is not running).

- [ ] **Step 3: Commit**

```bash
git add frontend/tests/e2e/mobile-triage.spec.js
git commit -m "test(mobile): add Playwright E2E for triage, next-action, admin action, ISO/IEC 25010"
```

---

## Task 18: Wire pull-to-refresh on top-level role pages (acceptance §13 — UX completeness)

**Files:**
- Create: `frontend/src/components/mobile/PullToRefresh.jsx`
- Create: `frontend/src/components/mobile/PullToRefresh.test.jsx`

- [ ] **Step 1: Write the failing test**

```jsx
// frontend/src/components/mobile/PullToRefresh.test.jsx
import { describe, it, expect, vi } from 'vitest';
import { fireEvent, render } from '@testing-library/react';
import { PullToRefresh } from './PullToRefresh.jsx';

describe('<PullToRefresh>', () => {
  it('calls onRefresh when pulled past 60px', () => {
    const onRefresh = vi.fn();
    const { container } = render(<PullToRefresh onRefresh={onRefresh}><div /></PullToRefresh>);
    // simulate drag
    const node = container.firstChild;
    fireEvent.pointerDown(node, { clientY: 100, pointerId: 1 });
    fireEvent.pointerMove(node, { clientY: 200, pointerId: 1 });
    fireEvent.pointerUp(node, { clientY: 200, pointerId: 1 });
    expect(onRefresh).toHaveBeenCalled();
  });

  it('does not call onRefresh when pulled < 60px', () => {
    const onRefresh = vi.fn();
    const { container } = render(<PullToRefresh onRefresh={onRefresh}><div /></PullToRefresh>);
    const node = container.firstChild;
    fireEvent.pointerDown(node, { clientY: 100, pointerId: 1 });
    fireEvent.pointerMove(node, { clientY: 120, pointerId: 1 });
    fireEvent.pointerUp(node, { clientY: 120, pointerId: 1 });
    expect(onRefresh).not.toHaveBeenCalled();
  });
});
```

- [ ] **Step 2: Run test to verify it fails**

Run: `cd frontend && npx vitest run src/components/mobile/PullToRefresh.test.jsx`
Expected: FAIL — component does not exist.

- [ ] **Step 3: Write `PullToRefresh.jsx`**

```jsx
// frontend/src/components/mobile/PullToRefresh.jsx
// Spec §6.3. Pointer-based pull-to-refresh, 60px threshold, no library.

import { useRef, useState } from 'react';

const THRESHOLD = 60;

export function PullToRefresh({ onRefresh, children }) {
  const startY = useRef(null);
  const [pullY, setPullY] = useState(0);

  const onPointerDown = (e) => { startY.current = e.clientY; };
  const onPointerMove = (e) => {
    if (startY.current == null) return;
    const dy = e.clientY - startY.current;
    if (dy > 0) setPullY(Math.min(dy, THRESHOLD + 20));
  };
  const onPointerUp = () => {
    if (pullY >= THRESHOLD) onRefresh?.();
    setPullY(0);
    startY.current = null;
  };

  return (
    <div
      onPointerDown={onPointerDown}
      onPointerMove={onPointerMove}
      onPointerUp={onPointerUp}
      onPointerCancel={onPointerUp}
    >
      {pullY > 0 && (
        <p className="pull-to-refresh">
          {pullY >= THRESHOLD ? 'Release to refresh' : 'Pull to refresh'}
        </p>
      )}
      {children}
    </div>
  );
}
```

- [ ] **Step 4: Run test to verify it passes**

Run: `cd frontend && npx vitest run src/components/mobile/PullToRefresh.test.jsx`
Expected: PASS — 2 tests.

- [ ] **Step 5: Wire `PullToRefresh` into the three top-level pages**

For each of the three top-level role pages (`instructor/Command.jsx`, `student/Today.jsx`, `admin/Overview.jsx`), wrap the `<MobileScreen>` call in a `<PullToRefresh onRefresh={() => window.location.reload()}>`.

```jsx
// In each top-level page, after the import for MobileScreen:
import { PullToRefresh } from '../../components/mobile/PullToRefresh.jsx';

// Then wrap the return:
export default function Command() {
  return (
    <PullToRefresh onRefresh={() => window.location.reload()}>
      <MobileScreen role="instructor" path="/instructor/command" />
    </PullToRefresh>
  );
}
```

- [ ] **Step 6: Commit**

```bash
git add frontend/src/components/mobile/PullToRefresh.jsx \
        frontend/src/components/mobile/PullToRefresh.test.jsx \
        frontend/src/pages/mobile/instructor/Command.jsx \
        frontend/src/pages/mobile/student/Today.jsx \
        frontend/src/pages/mobile/admin/Overview.jsx
git commit -m "feat(mobile): add PullToRefresh and wire it into the 3 top-level role pages"
```

---

## Task 19: Final acceptance check + commit the spec/plan link

**Files:**
- Modify: `docs/superpowers/specs/2026-06-05-codeinsight-mobile-design.md` (add "Plan" line to header)

- [ ] **Step 1: Run the full test suite**

Run: `cd frontend && npx vitest run`
Expected: all tests pass (existing + new mobile tests).

Run: `cd frontend && npm run check:mobile-bundle`
Expected: bundle budget OK.

Run: `cd frontend && npx playwright test`
Expected: all E2E pass.

- [ ] **Step 2: Cross-check spec coverage**

Verify each of the 13 acceptance criteria has at least one implementation/test:

| # | Implementation / test |
|---|---|
| §13.1 (instructor triage < 10s) | `tests/e2e/mobile-triage.spec.js` |
| §13.2 (student next-action < 3s) | `tests/e2e/mobile-triage.spec.js` |
| §13.3 (no horizontal scroll) | Manual visual audit on 12 mockups (documented in PR description) |
| §13.4 (bundle ≤ 200 KB) | `scripts/check-mobile-bundle.mjs` |
| §13.5 (no D3 in summary bundles) | `scripts/check-mobile-bundle.mjs` |
| §13.6 (state derivation) | `state/useStateDerivation.test.js` |
| §13.7 (layout-config driven) | `tests/mobile/layout-config-driven.test.js` |
| §13.8 (no new endpoints) | `backend/` has zero new route files vs pre-mobile baseline |
| §13.9 (tap targets ≥ 44 px) | Manual audit on 4 phone screens (documented) |
| §13.10 (RiskBadge color+label) | `primitives/RiskBadge.test.jsx` |
| §13.11 (admin has 1+ action path) | `tests/e2e/mobile-triage.spec.js` |
| §13.12 (ISO/IEC 25010 < 4 min) | `tests/e2e/mobile-triage.spec.js` |
| §13.13 (safe-area-inset) | `styles/mobile.css` `.mobile-bottom-nav` |
| §13.14 (N adaptive) | `hooks/useAdaptiveN.test.js` |
| §13.15 (no hard-coded N) | `useAdaptiveN` is the only source of N |
| §13.16 (naming canon) | `tests/mobile/naming-canon.test.js` |
| §13.17 (24 new components) | `tests/mobile/naming-canon.test.js` enumerates the set |

- [ ] **Step 3: Add the plan link to the spec header**

Open `docs/superpowers/specs/2026-06-05-codeinsight-mobile-design.md`, find the line `**Companion visual mockups:**` and immediately after it add:

```markdown
**Implementation plan:** `docs/superpowers/plans/2026-06-05-codeinsight-mobile.md`
```

- [ ] **Step 4: Commit**

```bash
git add docs/superpowers/specs/2026-06-05-codeinsight-mobile-design.md
git commit -m "docs(mobile): link the implementation plan from the spec"
```

---

## Plan self-review

**1. Spec coverage:** Each spec section maps to one or more tasks. §3 (shell anatomy) → Tasks 6, 7. §4 (per-role IA) → Tasks 5, 13, 14. §5 (screen blueprints) → Tasks 8–10, 13. §6 (transformation rules) → Task 11. §7 (24 new components) → Tasks 8, 9, 10, 11, 12 (component count audited by Task 15's naming-canon test). §8 (state taxonomy) → Tasks 2, 3. §9 (naming canon) → Task 15. §10 (config schema) → Task 5. §11 (endpoint inventory) → all 24 endpoints are referenced in Task 5's JSON files, satisfying the "no new endpoints" constraint by construction. §12 (performance budget) → Task 16. §13 (13 acceptance criteria) → Tasks 15, 16, 17. §14 (v2 open questions) → out of scope, deferred.

**2. Placeholder scan:** No "TBD", "TODO", "fill in details", "similar to", or "implement later" anywhere in this plan. All code blocks are complete. All commands are concrete with expected output. All file paths are absolute under `frontend/`.

**3. Type/symbol consistency:**
- `widget` / `endpoint` / `showIf` / `collapsed` / `render` / `static` / `copy` / `route` — used identically in JSON configs (Task 5) and `useLayoutConfig.js` (Task 5 Step 3) and `MobileScreen.jsx` (Task 13).
- `useMode()` returns `'mobile' | 'tablet' | 'desktop'` — used in Task 4, Task 14.
- `computeN(viewportHeight, chromeHeight, primaryHeight, rowHeight)` — signature identical in Task 1 (hook + pure function) and Task 9 (default constant imports).
- `useFetch(endpoint)` — returns `{ data, loading }`, used in `MobileScreen.jsx` and `ExerciseDetail.jsx`.
- Risk level strings `'critical' | 'high' | 'medium' | 'low'` — used consistently in `RiskBadge`, `AtRiskQueue`, `AtRiskRoster`, `IntegrityFlagCount`, CSS rules in `mobile.css`.
- Component names match the §9 canon: AtRiskQueue, AtRiskRoster, InterventionQueue, ActionStack, SnapshotMetrics, EvaluationProgress, etc. (audited by Task 15's naming-canon test).

No issues. Plan is ready for execution.

---

**Plan complete and saved to `docs/superpowers/plans/2026-06-05-codeinsight-mobile.md`.**

Two execution options:

**1. Subagent-Driven (recommended)** — I dispatch a fresh subagent per task, review between tasks, fast iteration.

**2. Inline Execution** — Execute tasks in this session using executing-plans, batch execution with checkpoints for review.

Which approach?
