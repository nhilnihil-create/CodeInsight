import { Check, X, Lock } from "lucide-react";
import { cn } from "@/lib/utils";

/**
 * TestOutputPanel
 * Body for the Test Cases section of the left panel. Renders:
 *   - List of test cases with Pass/Fail icon + name + Input + Expected
 *   - Hidden tests pinned footer (never leaks names)
 *
 * `bare` strips the outer border so the body can be embedded inside
 * a section card without double chrome.
 *
 * Tokens only.
 */
export default function TestOutputPanel({ testResults, bare = false }) {
  const hasResults = Boolean(testResults);
  const tests = testResults?.publicTests ?? [];

  return (
    <div
      className={cn(
        "flex flex-col h-full min-h-0",
        !bare && "bg-card border-l border-border",
      )}
    >
      <div className="flex-1 min-h-0 overflow-y-auto">
        <div className="px-3 py-3 space-y-2">
          {hasResults && tests.length > 0 ? (
            <ul className="rounded-md border border-border bg-card divide-y divide-border overflow-hidden">
              {tests.map((t) => (
                <li
                  key={t.id}
                  className="grid grid-cols-[auto_1fr_auto] items-center gap-3 px-3 py-2.5"
                >
                  {t.passed ? (
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
                  <div className="min-w-0">
                    <p className="text-sm font-medium truncate">{t.name}</p>
                    <p className="text-[11px] font-mono text-muted-foreground">
                      {t.input ? <span>Input: {t.input}</span> : null}
                      {t.input && t.expected ? <span className="mx-1">·</span> : null}
                      {t.expected ? <span>Expected: {t.expected}</span> : null}
                    </p>
                  </div>
                  <span
                    className={cn(
                      "text-[11px] font-mono tabular-nums shrink-0",
                      t.passed ? "text-success" : "text-destructive",
                    )}
                  >
                    {t.runtimeMs}ms
                  </span>
                </li>
              ))}
            </ul>
          ) : null}

          {!hasResults ? (
            <div className="rounded-md border border-dashed border-border bg-muted/20 p-4 text-center">
              <p className="text-sm text-muted-foreground">
                Press <Kbd>⌘ ↵</Kbd> or click{" "}
                <span className="font-medium text-foreground">Run</span> to execute the test suite.
              </p>
            </div>
          ) : null}
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

function Kbd({ children }) {
  return (
    <span className="inline-flex items-center gap-0.5 align-middle">
      {children.split(" ").map((k, i) => (
        <kbd
          key={i}
          className="inline-flex items-center justify-center min-w-4 h-4 px-1 rounded border border-border bg-muted/60 text-muted-foreground text-[10px] font-mono"
        >
          {k}
        </kbd>
      ))}
    </span>
  );
}
