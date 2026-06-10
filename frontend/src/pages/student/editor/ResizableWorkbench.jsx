import { Group, Panel, Separator, useGroupRef } from "react-resizable-panels";
import { RotateCcw } from "lucide-react";
import { useCallback, useEffect, useLayoutEffect } from "react";
import ProblemPanel from "./ProblemPanel";
import CodeEditorSurface from "./CodeEditorSurface";
import SubmissionsPanel from "./SubmissionsPanel";
import OutputPanel from "./OutputPanel";

/**
 * Workbench
 * Desktop 3-column IDE layout with resizable panels + bottom terminal.
 *
 *   ┌──────────┬─────────────────────────────┬────────────┐
 *   │          │                             │            │
 *   │  LEFT    │           CENTER            │   RIGHT    │
 *   │ Problem  │  ┌─────────────────────┐    │ Submissions│
 *   │  + Tests │  │      Editor         │    │  History   │
 *   │          │  ├─────────────────────┤    │            │
 *   │          │  │  Terminal (3 tabs)  │    │            │
 *   │          │  └─────────────────────┘    │            │
 *   └──────────┴─────────────────────────────┴─────────────────────┘
 *
 *   - Outer Group (horizontal): left (25%) | center (55%) | right (20%)
 *   - Inner Group (vertical, inside center): editor (70%) | terminal (30%)
 *   - Drag handles are 6px wide (col) / 6px tall (row) with a 1px
 *     visible line in the center and 12px transparent hit areas.
 *   - Resize is **persistent** across page reloads (manual
 *     localStorage — see PERSISTENCE block below).
 *   - All panels have a minSize floor so they stay usable; the user
 *     cannot collapse them by accident. (Panels are not marked
 *     collapsible; only resizeable.)
 *   - The Reset button (top-right) restores the default 25/55/20 +
 *     70/30 layout and clears localStorage.
 *
 * On < lg the orchestrator swaps in MobileEditorTabs.
 *
 * SIZING — react-resizable-panels v4 API:
 *   The v4 library treats `defaultSize`/`minSize`/`maxSize` values
 *   differently by JS type (see `bt()` in
 *   node_modules/react-resizable-panels/dist/react-resizable-panels.js):
 *     - number         → interpreted as pixels
 *     - string with %  → interpreted as percent of the parent Group
 *   We pass strings (e.g. "25%") so the library uses the intended
 *   percentages. `setLayout()` is a different API: it takes a
 *   `{[panelId]: number}` map of percentages (numbers are correct
 *   there), see the d.ts `GroupImperativeHandle.setLayout`.
 *
 * PERSISTENCE — manual localStorage (v4-compatible):
 *   react-resizable-panels@4 removed the v3 `autoSaveId` prop; v4
 *   exposes only `onLayoutChanged` + `getLayout()` / `setLayout()`.
 *   We implement persistence here: a useState layout is seeded from
 *   localStorage on mount and re-saved on every drag, keyed under
 *   a versioned namespace so corrupt or stale values (from the
 *   v1-number-props era or any v3 era) are ignored.
 *   Storage keys: `codeinsight:workbench:outer:v2` /
 *                 `codeinsight:workbench:center:v2`
 */

// localStorage keys. The v2 suffix means: this version of the
// workbench code is layout-persistent. Any other suffix (or a key
// that fails to JSON.parse) is treated as corrupt and discarded so
// the user gets the 25/55/20 / 70/30 defaults.
const STORAGE_KEY_OUTER = "codeinsight:workbench:outer:v2";
const STORAGE_KEY_CENTER = "codeinsight:workbench:center:v2";

// `setLayout()` payload — numbers, percent (0..100).
const DEFAULT_OUTER_LAYOUT = { left: 25, center: 55, right: 20 };
const DEFAULT_CENTER_LAYOUT = { editor: 70, output: 30 };

// Panel prop values — strings with %, percent of the parent Group.
const PANEL_PROPS = {
  outer: {
    left:   { defaultSize: "25%", minSize: "18%", maxSize: "40%" },
    center: { defaultSize: "55%", minSize: "36%" },
    right:  { defaultSize: "20%", minSize: "15%", maxSize: "35%" },
  },
  center: {
    editor: { defaultSize: "70%", minSize: "40%" },
    output: { defaultSize: "30%", minSize: "18%", maxSize: "55%" },
  },
};

// Expected percentages for the runtime validator (numbers, 0..100).
const EXPECTED_OUTER = { left: 25, center: 55, right: 20 };
const EXPECTED_CENTER = { editor: 70, output: 30 };
const TOLERANCE = 1; // ±1%
const TOLERANCE_SMALL = 0.5; // for defaultSize-only checks (center has no max)

export default function ResizableWorkbench({
  exercise,
  code,
  onCodeChange,
  testResults,
  onMount,
  language = "cpp",
  submissions = [],
  history = [],
  consoleLog = "",
  compilationLog = "",
  programOutput = "",
  onClearTerminal,
  isReviewMode = false,
}) {
  const centerGroupRef = useGroupRef();
  const outerGroupRef = useGroupRef();

  // Apply the persisted layout to each Group. The v4 library is
  // deeply finicky: `defaultLayout` is sometimes discarded, and
  // `setLayout()` is a no-op while the Group is in its "deferred"
  // state (groupSize === 0). To work around both, we read the
  // stored layout synchronously in `useLayoutEffect` (which runs
  // after the refs are attached but before the Group's useEffect
  // commits its computed layout) and call `setLayout()`. We also
  // retry on the next paint in case the layout effect ran while
  // the Group was still deferred.
  //
  // Persistence: the Group's `onLayoutChanged` callback fires with
  // the current layout. We always write the layout to localStorage,
  // EXCEPT for the very first mount-time call per group — that's
  // the library's default layout, not a user choice, and writing
  // it would clobber a stored value. We distinguish mount-time
  // by comparing the layout to the defaults.
  const handleReset = useCallback(() => {
    outerGroupRef.current?.setLayout(DEFAULT_OUTER_LAYOUT);
    centerGroupRef.current?.setLayout(DEFAULT_CENTER_LAYOUT);
    // Also clear any stored value so a reload returns to defaults.
    try {
      window.localStorage?.removeItem(STORAGE_KEY_OUTER);
      window.localStorage?.removeItem(STORAGE_KEY_CENTER);
    } catch {
      /* localStorage may be unavailable (e.g. private mode) */
    }
  }, [outerGroupRef, centerGroupRef]);

  const handleOuterLayoutChanged = useCallback((layout) => {
    // First mount-time fire is the library default. Compare to
    // the default outer layout; if equal, skip the write. Any
    // subsequent fire (including post-reset) is a real change.
    if (layoutEquals(layout, DEFAULT_OUTER_LAYOUT)) return;
    try {
      window.localStorage?.setItem(
        STORAGE_KEY_OUTER,
        JSON.stringify(layout),
      );
    } catch {
      /* ignore */
    }
  }, []);

  const handleCenterLayoutChanged = useCallback((layout) => {
    if (layoutEquals(layout, DEFAULT_CENTER_LAYOUT)) return;
    try {
      window.localStorage?.setItem(
        STORAGE_KEY_CENTER,
        JSON.stringify(layout),
      );
    } catch {
      /* ignore */
    }
  }, []);

  useLayoutEffect(() => {
    const storedOuter = readStoredLayout(STORAGE_KEY_OUTER, EXPECTED_OUTER);
    const storedCenter = readStoredLayout(STORAGE_KEY_CENTER, EXPECTED_CENTER);
    if (storedOuter) outerGroupRef.current?.setLayout(storedOuter);
    if (storedCenter) centerGroupRef.current?.setLayout(storedCenter);
  }, [outerGroupRef, centerGroupRef]);

  useEffect(() => {
    const storedOuter = readStoredLayout(STORAGE_KEY_OUTER, EXPECTED_OUTER);
    const storedCenter = readStoredLayout(STORAGE_KEY_CENTER, EXPECTED_CENTER);
    if (!storedOuter && !storedCenter) return undefined;
    // Re-apply on the next paint, in case the layout effect above
    // ran while the Group was still deferred.
    const id = window.requestAnimationFrame(() => {
      if (storedOuter) outerGroupRef.current?.setLayout(storedOuter);
      if (storedCenter) centerGroupRef.current?.setLayout(storedCenter);
    });
    return () => window.cancelAnimationFrame(id);
  }, [outerGroupRef, centerGroupRef]);

  // --- RUNTIME VALIDATION -----------------------------------------------
  // After mount, read the actual layout that react-resizable-panels
  // committed to the DOM, log it, and assert the panel widths/heights
  // match the expected percentages within ±1%. The expected layout
  // is the stored layout (if any) or the default layout. Also
  // checks the document for horizontal overflow and verifies
  // localStorage was written/cleared as expected.
  useEffect(() => {
    if (typeof window === "undefined") return undefined;

    // Run a tick after mount: the Group's useEffect + ResizeObserver
    // need a moment to write its computed layout into the Panels'
    // styles, and our `setLayout(stored)` retry (in the effect
    // above) needs to commit too.
    const id = window.setTimeout(() => {
      const outer = readGroupLayout(outerGroupRef.current, [
        "left",
        "center",
        "right",
      ]);
      const inner = readGroupLayout(centerGroupRef.current, [
        "editor",
        "output",
      ]);
      const overflow = checkHorizontalOverflow();

      // The expected layout is the stored layout (if any) or the
      // default. This way the validator correctly reports "OK" for
      // a restored user layout, not "MISMATCH" against the default.
      const storedOuter = readStoredLayout(STORAGE_KEY_OUTER, EXPECTED_OUTER);
      const storedCenter = readStoredLayout(STORAGE_KEY_CENTER, EXPECTED_CENTER);
      const expectedOuter = storedOuter ?? EXPECTED_OUTER;
      const expectedCenter = storedCenter ?? EXPECTED_CENTER;

      // Persist verification
      const persisted = readPersistedLayouts();

      const result = {
        outer: { expected: expectedOuter, actual: outer },
        center: { expected: expectedCenter, actual: inner },
        overflow,
        persisted,
      };
      const failures = collectFailures(result);

      if (process.env.NODE_ENV !== 'production') {
        if (failures.length === 0) {
          console.info(
            "[workbench] layout OK",
            result.outer.actual,
            result.center.actual,
          );
        } else {
          console.warn(
            "[workbench] layout MISMATCH",
            result,
            "failures:",
            failures,
          );
        }
      }
    }, 100);

    return () => window.clearTimeout(id);
  }, [outerGroupRef, centerGroupRef]);

  return (
    <div className="relative flex flex-1 min-h-0 w-full overflow-hidden">
      <Group
        id="codeinsight.workbench.outer"
        orientation="horizontal"
        groupRef={outerGroupRef}
        onLayoutChanged={handleOuterLayoutChanged}
        className="h-full w-full"
      >
        {/* LEFT — Problem | Test Cases */}
        <Panel
          id="left"
          defaultSize={PANEL_PROPS.outer.left.defaultSize}
          minSize={PANEL_PROPS.outer.left.minSize}
          maxSize={PANEL_PROPS.outer.left.maxSize}
          order={1}
        >
          <ProblemPanel
            exercise={exercise}
            testResults={testResults}
          />
        </Panel>
        <DragHandle axis="col" />

        {/* CENTER — Editor (top) | Terminal (bottom) */}
        <Panel
          id="center"
          defaultSize={PANEL_PROPS.outer.center.defaultSize}
          minSize={PANEL_PROPS.outer.center.minSize}
          order={2}
        >
          <Group
            id="codeinsight.workbench.center"
            orientation="vertical"
            groupRef={centerGroupRef}
            onLayoutChanged={handleCenterLayoutChanged}
            className="h-full w-full"
          >
            <Panel
              id="editor"
              defaultSize={PANEL_PROPS.center.editor.defaultSize}
              minSize={PANEL_PROPS.center.editor.minSize}
              order={1}
            >
              <CodeEditorSurface
                value={code}
                onChange={onCodeChange}
                onMount={onMount}
                language={language}
              />
            </Panel>
            <DragHandle axis="row" />
            <Panel
              id="output"
              defaultSize={PANEL_PROPS.center.output.defaultSize}
              minSize={PANEL_PROPS.center.output.minSize}
              maxSize={PANEL_PROPS.center.output.maxSize}
              order={2}
            >
              <OutputPanel
                testResults={testResults}
                testCases={exercise?.test_cases || []}
                consoleLog={consoleLog}
                compilationLog={compilationLog}
                programOutput={programOutput}
                onClear={onClearTerminal}
              />
            </Panel>
          </Group>
        </Panel>
        <DragHandle axis="col" />

        {/* RIGHT — Submissions | History (or Review Mode) */}
        <Panel
          id="right"
          defaultSize={PANEL_PROPS.outer.right.defaultSize}
          minSize={PANEL_PROPS.outer.right.minSize}
          maxSize={PANEL_PROPS.outer.right.maxSize}
          order={3}
        >
          {isReviewMode ? (
            <div className="h-full flex items-center justify-center p-4">
              <div className="text-center space-y-2">
                <div className="text-2xl">👁️</div>
                <p className="text-sm font-medium">Review Mode</p>
                <p className="text-xs text-muted-foreground">
                  Your code changes and test runs won't be saved.
                </p>
              </div>
            </div>
          ) : (
            <SubmissionsPanel
              submissions={submissions}
              history={history}
            />
          )}
        </Panel>
      </Group>

      {/* Reset Layout button — top-right corner of the workbench. */}
      <button
        type="button"
        onClick={handleReset}
        aria-label="Reset panel sizes"
        title="Reset panel sizes to defaults"
        className="absolute top-2 right-2 z-40 inline-flex items-center gap-1.5 h-7 px-2 rounded-md border border-border bg-card text-xs font-medium text-muted-foreground hover:text-foreground hover:bg-muted transition-colors shadow-sm"
      >
        <RotateCcw className="h-3 w-3" strokeWidth={1.75} aria-hidden="true" />
        Reset
      </button>
    </div>
  );
}

/**
 * DragHandle
 * Vertical (col) or horizontal (row) 6px-wide separator with a 1px
 * visible line in the center. Hover/active states tint with the
 * primary color. The library sets `data-separator` to "active" /
 * "focus" / "disabled" on the element.
 */
function DragHandle({ axis = "col" }) {
  const isCol = axis === "col";
  return (
    <Separator
      className={
        isCol
          ? "group relative flex h-full w-1.5 items-center justify-center bg-transparent hover:bg-primary/10 data-[separator=active]:bg-primary/20 transition-colors"
          : "group relative flex h-1.5 w-full items-center justify-center bg-transparent hover:bg-primary/10 data-[separator=active]:bg-primary/20 transition-colors"
      }
    >
      <div
        aria-hidden="true"
        className={
          isCol
            ? "h-full w-px bg-border group-hover:bg-primary/60 group-data-[separator=active]:bg-primary"
            : "h-px w-full bg-border group-hover:bg-primary/60 group-data-[separator=active]:bg-primary"
        }
      />
    </Separator>
  );
}

// --- runtime-validation helpers -----------------------------------------

/**
 * Read a stored layout from localStorage. Returns `null` if the
 * key is missing, the JSON is malformed, or the stored value
 * doesn't have the expected panelIds with numeric values.
 */
function readStoredLayout(key, expectedPanelIds) {
  if (typeof window === "undefined" || !window.localStorage) return null;
  try {
    const raw = window.localStorage.getItem(key);
    if (!raw) return null;
    const parsed = JSON.parse(raw);
    if (!parsed || typeof parsed !== "object") return null;
    // expectedPanelIds is an object; iterate its keys
    for (const id of Object.keys(expectedPanelIds)) {
      const v = Number(parsed[id]);
      if (!Number.isFinite(v)) return null;
    }
    // Always use the stored values as-is; this is the layout the
    // user dragged to, no default-filling (we already verified all
    // expected panel ids are present and finite above).
    return { ...parsed };
  } catch {
    return null;
  }
}

/**
 * Are two layouts the same within a small tolerance? Used to
 * distinguish mount-time default fires from real user changes.
 */
function layoutEquals(a, b) {
  if (!a || !b) return false;
  for (const k of Object.keys(b)) {
    if (Math.abs((a[k] ?? 0) - b[k]) > 0.01) return false;
  }
  return true;
}

/**
 * Read the live layout of a Group by reading each Panel's
 * `offsetWidth` (or `offsetHeight` for vertical groups) as a
 * percentage of the Group's total. This reflects what the user
 * actually sees in the DOM, not what was passed as a prop.
 */
function readGroupLayout(groupHandle, panelIds) {
  if (!groupHandle) return null;
  const layout = groupHandle.getLayout();
  if (layout) {
    // Authoritative source: the Group's own getLayout() returns
    // percentages (0..100) for each panelId. This is the value
    // the library stores after constraints are applied.
    return { ...layout };
  }
  return null;
}

function checkHorizontalOverflow() {
  if (typeof document === "undefined") return null;
  const docW = document.documentElement.scrollWidth;
  const winW = window.innerWidth;
  return {
    documentScrollWidth: docW,
    viewportWidth: winW,
    overflow: docW > winW + 1,
    delta: docW - winW,
  };
}

function readPersistedLayouts() {
  if (typeof window === "undefined" || !window.localStorage) return null;
  try {
    const outer = window.localStorage.getItem(STORAGE_KEY_OUTER);
    const center = window.localStorage.getItem(STORAGE_KEY_CENTER);
    return {
      outer: outer ? JSON.parse(outer) : null,
      center: center ? JSON.parse(center) : null,
    };
  } catch {
    return null;
  }
}

function collectFailures({ outer, center, overflow, persisted }) {
  const failures = [];
  if (outer && outer.actual) {
    for (const id of Object.keys(outer.expected)) {
      const expected = outer.expected[id];
      const actual = Number(outer.actual[id]);
      if (Number.isFinite(actual)) {
        const diff = Math.abs(actual - expected);
        // center has no maxSize, so use a tighter tolerance on its
        // defaultSize; side panels may have clamped to their maxSize
        // if the viewport is unusually narrow.
        const tol = id === "center" ? TOLERANCE_SMALL : TOLERANCE;
        if (diff > tol) {
          failures.push(`outer.${id} expected ${expected}%, got ${actual.toFixed(2)}% (Δ ${diff.toFixed(2)})`);
        }
      } else {
        failures.push(`outer.${id} expected ${expected}%, got null`);
      }
    }
  } else {
    failures.push("outer layout not available from getLayout()");
  }
  if (center && center.actual) {
    for (const id of Object.keys(center.expected)) {
      const expected = center.expected[id];
      const actual = Number(center.actual[id]);
      if (Number.isFinite(actual)) {
        const diff = Math.abs(actual - expected);
        if (diff > TOLERANCE) {
          failures.push(`center.${id} expected ${expected}%, got ${actual.toFixed(2)}% (Δ ${diff.toFixed(2)})`);
        }
      } else {
        failures.push(`center.${id} expected ${expected}%, got null`);
      }
    }
  } else {
    failures.push("center layout not available from getLayout()");
  }
  if (overflow && overflow.overflow) {
    failures.push(
      `horizontal overflow: documentScrollWidth=${overflow.documentScrollWidth} > viewportWidth=${overflow.viewportWidth} (Δ ${overflow.delta})`,
    );
  }
  return failures;
}
