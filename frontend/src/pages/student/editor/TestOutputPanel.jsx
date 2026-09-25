import { Check, X, Lock, Clock } from "lucide-react";
import { cn } from "@/lib/utils";

/**
 * TestOutputPanel
 * Body for the Test Cases section of the left panel. Renders:
 *   - Visible test cases immediately on mount as stacked, labeled
 *     Input / Expected / Got value blocks
 *   - Per-row status (Clock before run, Check/X after) derived from
 *     the result zipped by index with the static test case
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

  // Build merged rows: static test case data + execution results.
  // Results are indexed in the same order as the API returns them,
  // so we can zip by index. When no visible static test cases exist,
  // fall back to results-only rows so results-first consumers still
  // render rows instead of the empty state.
  const rows =
    visibleTestCases.length > 0
      ? visibleTestCases.map((tc, i) => {
          const result = results[i] ?? null;
          return {
            id: tc.id ?? i,
            name: tc.name || result?.name || `Test ${i + 1}`,
            input: tc.input ?? tc.stdin ?? result?.input ?? null,
            expected: tc.expected ?? tc.expectedOutput ?? tc.expected_output ?? tc.output ?? result?.expected ?? null,
            actual: result?.actual ?? null,
            result,
          };
        })
      : results.map((r, i) => ({
          id: r.id ?? i,
          name: r.name || `Test ${i + 1}`,
          input: r.input ?? null,
          expected: r.expected ?? null,
          actual: r.actual ?? null,
          result: r ?? null,
        }));

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

/** Single test row — header (icon + name + verdict + runtime) over labeled value blocks. */
function TestRow({ row }) {
  const { name, input, expected, actual } = row;
  const result = row.result ?? null;
  const pending = result === null || result === undefined;
  const passed = !pending && result.passed === true;
  const failed = !pending && result.passed === false;
  const showRuntime =
    !pending && result.runtimeMs !== null && result.runtimeMs !== undefined;

  return (
    <li className="space-y-2 px-3 py-2.5">
      {/* Status + name + verdict + runtime */}
      <div className="flex items-center gap-2 min-w-0">
        {pending ? (
          <Clock className="h-4 w-4 text-muted-foreground shrink-0" strokeWidth={1.5} aria-hidden="true" />
        ) : passed ? (
          <Check className="h-4 w-4 text-success shrink-0" strokeWidth={2.25} aria-hidden="true" />
        ) : (
          <X className="h-4 w-4 text-destructive shrink-0" strokeWidth={2.25} aria-hidden="true" />
        )}
        <p className="flex-1 min-w-0 text-sm font-medium truncate">{name}</p>
        {passed ? (
          <span className="shrink-0 text-[11px] font-semibold text-success">Passed</span>
        ) : failed ? (
          <span className="shrink-0 text-[11px] font-semibold text-destructive">Failed</span>
        ) : null}
        {showRuntime ? (
          <span className={cn("shrink-0 text-[11px] font-mono tabular-nums", passed ? "text-success" : "text-destructive")}>
            {result.runtimeMs}ms
          </span>
        ) : null}
      </div>

      {/* Labeled I/O blocks */}
      <div className="space-y-1.5">
        {input !== null && input !== undefined ? (
          <ValueBlock label="Input" value={input} />
        ) : null}
        {expected !== null && expected !== undefined ? (
          <ValueBlock label="Expected" value={expected} />
        ) : null}
        {!pending ? (
          <ValueBlock
            label="Got"
            value={actual}
            placeholder="(no output)"
            tone={passed ? "success" : "destructive"}
          />
        ) : null}
      </div>
    </li>
  );
}

function ValueBlock({ label, value, tone = "muted", placeholder = "(empty)" }) {
  const hasValue =
    value !== null && value !== undefined && String(value).length > 0;
  return (
    <div className="rounded-md border border-border bg-muted/30 px-2.5 py-1.5 space-y-1 min-w-0">
      <p
        className={cn(
          "text-[10px] font-semibold uppercase tracking-wider",
          tone === "success"
            ? "text-success"
            : tone === "destructive"
            ? "text-destructive"
            : "text-muted-foreground",
        )}
      >
        {label}
      </p>
      <pre className="font-mono text-xs leading-relaxed whitespace-pre-wrap break-words text-foreground">
        {hasValue ? String(value) : <span className="italic text-muted-foreground">{placeholder}</span>}
      </pre>
    </div>
  );
}
