import { useEffect, useRef, useState } from "react";
import {
  TerminalSquare,
  AlertOctagon,
  CheckCircle2,
  XCircle,
  Clock,
  Trash2,
} from "lucide-react";
import { cn } from "@/lib/utils";

/**
 * OutputPanel
 * Bottom terminal of the center column. Three tabs:
 *
 *   Output        Program stdout / execution output (monospace log)
 *   Errors        Compilation errors + runtime exceptions + stack traces
 *   Test Results  Per-test pass/fail cards with input / expected / got
 *
 * Features:
 *   - Sticky tab bar (h-9, border-b, shrink-0)
 *   - Clear button in the tab bar that clears all 3 streams
 *   - Per-tab badge (errors count, failing test count, summary)
 *   - Auto-scroll to bottom on new content (unless the user has
 *     scrolled up — then we leave them alone)
 *   - Empty state per tab
 *
 * Tokens only.
 */

const TABS = [
  { id: "output", label: "Output",       icon: TerminalSquare },
  { id: "errors", label: "Errors",       icon: AlertOctagon   },
  { id: "tests",  label: "Test Results", icon: CheckCircle2   },
];

export default function OutputPanel({
  testResults,
  testCases = [],
  consoleLog = "",
  compilationLog = "",
  programOutput = "",
  onClear,
}) {
  // Default to the Test Results tab so students see test cases on load
  const [tab, setTab] = useState("tests");
  const error = testResults?.error;

  // Visible test cases from the exercise (raw format from API)
  const visibleTestCases = (testCases || []).filter(
    tc => tc.isVisible !== false && tc.hidden !== true
  );

  // Transformed test results (after running)
  const results = Array.isArray(testResults?.testResults) ? testResults.testResults : [];
  const hasRun = testResults !== null;
  const testsSummary = testResults
    ? `${testResults.passing}/${testResults.total}`
    : null;

  const errorCount = (error ? 1 : 0) + (compilationLog ? 1 : 0);
  const failedCount = results.filter((r) => !r.passed).length;

  return (
    <div className="flex flex-col h-full min-h-0 bg-card border-t border-border">
      {/* Sticky tab bar */}
      <div className="flex items-center gap-0 h-9 px-2 border-b border-border bg-card shrink-0">
        {TABS.map((t) => {
          const Icon = t.icon;
          const active = t.id === tab;
          const badge =
            t.id === "errors" && errorCount > 0
              ? errorCount
              : t.id === "tests" && failedCount > 0
                ? failedCount
                : null;
          return (
            <button
              key={t.id}
              type="button"
              role="tab"
              aria-selected={active}
              onClick={() => setTab(t.id)}
              className={cn(
                "inline-flex items-center justify-center gap-1.5 h-full px-3 text-xs font-medium transition-colors",
                "border-b-2 -mb-px",
                active
                  ? "text-foreground border-foreground"
                  : "text-muted-foreground border-transparent hover:text-foreground",
              )}
            >
              <Icon className="h-3.5 w-3.5" strokeWidth={1.5} aria-hidden="true" />
              {t.label}
              {badge != null ? (
                <span
                  className={cn(
                    "inline-flex items-center justify-center min-w-4 h-4 px-1 rounded-full text-[10px] font-mono tabular-nums",
                    t.id === "errors" && errorCount > 0
                      ? "bg-destructive/10 text-destructive"
                      : "bg-muted text-muted-foreground",
                  )}
                >
                  {badge}
                </span>
              ) : null}
            </button>
          );
        })}

        <div className="ml-auto flex items-center gap-2 pr-2">
          {testsSummary ? (
            <span
              className={cn(
                "inline-flex items-center gap-1 px-1.5 py-0.5 rounded-full text-[10px] font-semibold uppercase tracking-wide border",
                testResults.passed === true
                  ? "bg-success/10 text-success border-success/20"
                  : "bg-destructive/10 text-destructive border-destructive/20",
              )}
            >
              {testResults.passed === true ? "Passed" : "Failed"} · {testsSummary}
            </span>
          ) : null}
          {onClear ? (
            <button
              type="button"
              onClick={onClear}
              aria-label="Clear terminal"
              title="Clear terminal"
              className="inline-flex items-center gap-1 h-6 px-1.5 rounded-sm text-[11px] text-muted-foreground hover:text-foreground hover:bg-muted transition-colors"
            >
              <Trash2 className="h-3 w-3" strokeWidth={1.5} aria-hidden="true" />
              Clear
            </button>
          ) : null}
        </div>
      </div>

      <div className="flex-1 min-h-0 overflow-hidden">
        {tab === "output" ? (
          <OutputTab
            programOutput={programOutput}
            consoleLog={consoleLog}
          />
        ) : tab === "errors" ? (
          <ErrorsTab error={error} compilationLog={compilationLog} />
        ) : (
          <TestResultsTab results={results} testResults={testResults} testCases={visibleTestCases} hasRun={hasRun} />
        )}
      </div>
    </div>
  );
}

function AutoScrollLog({ children, content }) {
  const ref = useRef(null);
  const stickToBottom = useRef(true);

  // Track whether the user has scrolled away from the bottom; if so,
  // don't auto-scroll (don't yank them back down).
  useEffect(() => {
    const el = ref.current;
    if (!el) return undefined;
    const onScroll = () => {
      const distanceFromBottom = el.scrollHeight - el.scrollTop - el.clientHeight;
      stickToBottom.current = distanceFromBottom < 24;
    };
    el.addEventListener("scroll", onScroll, { passive: true });
    return () => el.removeEventListener("scroll", onScroll);
  }, []);

  useEffect(() => {
    const el = ref.current;
    if (!el) return;
    if (stickToBottom.current) {
      el.scrollTop = el.scrollHeight;
    }
  }, [content]);

  return (
    <div
      ref={ref}
      className="h-full overflow-y-auto px-3 py-2 font-mono text-[11px] leading-relaxed"
    >
      {children}
    </div>
  );
}

function EmptyState({ children }) {
  return (
    <div className="h-full flex items-center justify-center px-6 text-center text-xs text-muted-foreground italic font-mono">
      {children}
    </div>
  );
}

// ----- Tab: Output -----
function OutputTab({ programOutput, consoleLog }) {
  const text = (programOutput || consoleLog || "").trim();
  if (!text) {
    return <EmptyState>(No output yet — press Run to execute)</EmptyState>;
  }
  return (
    <AutoScrollLog content={text}>
      <pre className="whitespace-pre-wrap break-words text-foreground">{text}</pre>
    </AutoScrollLog>
  );
}

// ----- Tab: Errors -----
function ErrorsTab({ error, compilationLog }) {
  const hasError = Boolean(error);
  const hasLog = Boolean(compilationLog);
  if (!hasError && !hasLog) {
    return <EmptyState>(No errors)</EmptyState>;
  }
  return (
    <AutoScrollLog content={`${compilationLog ?? ""}\n${error ?? ""}`}>
      <div className="space-y-2">
        {compilationLog ? (
          <pre className="text-muted-foreground whitespace-pre-wrap break-words">
            {compilationLog}
          </pre>
        ) : null}
        {error ? (
          <pre className="text-destructive whitespace-pre-wrap break-words">
            {error}
          </pre>
        ) : null}
      </div>
    </AutoScrollLog>
  );
}

// ----- Tab: Test Results -----
function TestResultsTab({ results, testResults, testCases = [], hasRun }) {
  // If we haven't run yet, show test cases as pending
  if (!hasRun || !results || results.length === 0) {
    if (testCases.length === 0) {
      return (
        <EmptyState>
          {testResults
            ? "No test cases defined for this exercise."
            : "(No test cases yet — press Run to execute)"}
        </EmptyState>
      );
    }
    return (
      <div className="h-full overflow-y-auto px-3 py-2 font-mono text-[11px] leading-relaxed">
        <p className="text-muted-foreground text-xs mb-2">
          {testCases.length} visible test case{testCases.length === 1 ? '' : 's'} — press Run to check your code.
        </p>
        <ul className="space-y-1.5" role="list">
          {testCases.map((tc, i) => (
            <li
              key={i}
              className="rounded-md border border-border/40 px-2.5 py-2 space-y-1"
            >
              <div className="flex items-center gap-2">
                <Clock className="h-3.5 w-3.5 text-muted-foreground" strokeWidth={1.5} aria-hidden="true" />
                <span className="font-semibold text-muted-foreground">
                  Test case {i + 1}
                </span>
                {tc.validationType && tc.validationType !== 'exact' && (
                  <span className="text-[10px] px-1 py-0 rounded-full bg-muted text-muted-foreground uppercase">
                    {tc.validationType}
                  </span>
                )}
              </div>
              {tc.input ? (
                <p className="text-muted-foreground">
                  <span className="opacity-70">Input:</span>{' '}
                  <span className="text-foreground">{tc.input}</span>
                </p>
              ) : null}
              {tc.expectedOutput || tc.expected ? (
                <p className="text-muted-foreground">
                  <span className="opacity-70">Expected:</span>{' '}
                  <span className="text-foreground">{tc.expectedOutput || tc.expected}</span>
                </p>
              ) : null}
            </li>
          ))}
        </ul>
      </div>
    );
  }
  return (
    <div className="h-full overflow-y-auto px-3 py-2 font-mono text-[11px] leading-relaxed">
      <ul className="space-y-1.5" role="list">
        {results.map((r, i) => {
          const passed = r.passed;
          return (
            <li
              key={i}
              className={cn(
                "rounded-md border px-2.5 py-2 space-y-1",
                passed
                  ? "border-success/20 bg-success/5"
                  : "border-destructive/30 bg-destructive/5",
              )}
            >
              <div className="flex items-center gap-2">
                {passed ? (
                  <CheckCircle2
                    className="h-3.5 w-3.5 text-success"
                    strokeWidth={2}
                    aria-hidden="true"
                  />
                ) : (
                  <XCircle
                    className="h-3.5 w-3.5 text-destructive"
                    strokeWidth={2}
                    aria-hidden="true"
                  />
                )}
                <span
                  className={cn(
                    "font-semibold",
                    passed ? "text-success" : "text-destructive",
                  )}
                >
                  Test case {i + 1}: {passed ? "Pass" : "Fail"}
                </span>
                {r.runtimeMs != null ? (
                  <span className="text-muted-foreground tabular-nums inline-flex items-center gap-1">
                    <Clock className="h-3 w-3" strokeWidth={1.5} aria-hidden="true" />
                    {r.runtimeMs}ms
                  </span>
                ) : null}
              </div>
              {r.input ? (
                <p className="text-muted-foreground">
                  <span className="opacity-70">Input:</span> {r.input}
                </p>
              ) : null}
              {r.expected ? (
                <p className="text-muted-foreground">
                  <span className="opacity-70">Expected:</span> {r.expected}
                </p>
              ) : null}
              {r.actual ? (
                <p className="text-muted-foreground">
                  <span className="opacity-70">Got:</span> {r.actual}
                </p>
              ) : null}
            </li>
          );
        })}
      </ul>
    </div>
  );
}
