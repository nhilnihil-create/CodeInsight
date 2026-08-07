import { Check, X, Lock, Clock } from "lucide-react";
import { cn } from "@/lib/utils";

/**
 * TestOutputPanel
 * Body for the Test Cases section of the left panel. Renders:
 *   - Visible test cases immediately on mount (input + expected)
 *   - After Run: each row gets a Pass/Fail indicator + runtime
 *   - Hidden tests pinned footer (never leaks names)
 *
 * `bare` strips the outer border so the body can be embedded inside
 * a section card without double chrome.
 *
 * Tokens only.
 */
export default function TestOutputPanel({ testResults, testCases = [], bare = false }) {
  const hasResults = Boolean(testResults);
  const results = testResults?.publicTests ?? [];

  // Filter visible test cases from the exercise definition
  const visibleTestCases = (testCases || []).filter(
    (tc) => tc.isVisible !== false && tc.hidden !== true && tc.is_hidden !== true
  );

  // Build merged rows: static test case data + execution results
  // Results are indexed in the same order as the API returns them,
  // so we can zip by index.
  const rows = visibleTestCases.map((tc, i) => {
    const result = results[i] ?? null;
    return {
      id: tc.id ?? i,
      name: tc.name || result?.name || `Test ${i + 1}`,
      input: tc.input ?? result?.input ?? null,
      expected: tc.expected ?? tc.expectedOutput ?? result?.expected ?? null,
      passed: result ? result.passed : null,
      runtimeMs: result?.runtimeMs ?? null,
      hasRun: hasResults,
    };
  });

  return (
    <div
      className={cn(
        "flex flex-col h-full min-h-0",
        !bare && "bg-card border-l border-border",
      )}
    >
      <div className="flex-1 min-h-0 overflow-y-auto">
        <div className="px-3 py-3">
          {rows.length > 0 ? (
            <ul className="rounded-md border border-border bg-card divide-y divide-border overflow-hidden">
              {rows.map((row) => (
                <TestRow key={row.id} row={row} />
              ))}
            </ul>
          ) : (
            <div className="rounded-md border border-dashed border-border bg-muted/20 p-4 text-center">
              <p className="text-sm text-muted-foreground">
                No visible test cases for this exercise.
              </p>
            </div>
          )}
        </div>
      </div>

      {/* Hidden tests — pinned footer, single line, never leaks names */}
      {hasResults && testResults.hidden ? (
        <div className="border-t border-border p-3 shrink-0">
          <div
            className={cn(
              "flex items-center gap-2 text-xs",
              testResults.hidden.failed === 0
                ? "text-success"
                : "text-destructive",
            )}
          >
            <Lock className="h-3 w-3" strokeWidth={1.5} aria-hidden="true" />
            <span className="font-mono tabular-nums">
              {testResults.hidden.total} hidden test
              {testResults.hidden.total === 1 ? "" : "s"} ·{" "}
              {testResults.hidden.failed === 0
                ? "all passed"
                : `${testResults.hidden.failed} failed`}
            </span>
          </div>
        </div>
      ) : null}
    </div>
  );
}

/** Single test row — shows Clock before run, Check/X after. */
function TestRow({ row }) {
  const { passed, hasRun, name, input, expected, runtimeMs } = row;

  return (
    <li className="grid grid-cols-[auto_1fr_auto] items-center gap-3 px-3 py-2.5">
      {/* Status icon */}
      {!hasRun ? (
        <Clock
          className="h-4 w-4 text-muted-foreground shrink-0"
          strokeWidth={1.5}
          aria-hidden="true"
        />
      ) : passed ? (
        <Check
          className="h-4 w-4 text-success shrink-0"
          strokeWidth={2.25}
          aria-hidden="true"
        />
      ) : (
        <X
          className="h-4 w-4 text-destructive shrink-0"
          strokeWidth={2.25}
          aria-hidden="true"
        />
      )}

      {/* Name + input / expected */}
      <div className="min-w-0">
        <p className="text-sm font-medium truncate">{name}</p>
        <p className="text-[11px] font-mono text-muted-foreground">
          {input ? <span>Input: {input}</span> : null}
          {input && expected ? <span className="mx-1">·</span> : null}
          {expected ? <span>Expected: {expected}</span> : null}
        </p>
      </div>

      {/* Runtime (only after run) */}
      {hasRun && runtimeMs != null ? (
        <span
          className={cn(
            "text-[11px] font-mono tabular-nums shrink-0",
            passed ? "text-success" : "text-destructive",
          )}
        >
          {runtimeMs}ms
        </span>
      ) : null}
    </li>
  );
}
