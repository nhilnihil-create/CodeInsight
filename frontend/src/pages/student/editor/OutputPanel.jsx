import { TerminalSquare, AlertOctagon, Trash2, CheckCircle2 } from "lucide-react";
import { cn } from "@/lib/utils";

/**
 * OutputPanel — DevC++-style terminal
 *
 * Single unified view (no tabs) that mirrors a real compiler console:
 *   - Compilation succeeded → shows program stdout
 *   - Compilation failed    → shows compiler errors in "file:line: message" format
 *
 * Hidden test cases are NEVER shown here — they only appear as
 * an aggregate "X hidden, all passed / Y failed" footer.
 */

export default function OutputPanel({
  testResults,
  compilationLog = "",
  programOutput = "",
  onClear,
}) {
  const error = testResults?.error;
  const hasRun = testResults !== null;
  const hasError = Boolean(error || compilationLog);
  const hasOutput = Boolean(programOutput);

  // Summary badge
  const testsSummary = testResults
    ? `${testResults.passing}/${testResults.total}`
    : null;
  const failedCount = Array.isArray(testResults?.testResults)
    ? testResults.testResults.filter((r) => !r.passed).length
    : 0;

  return (
    <div className="flex flex-col h-full min-h-0 bg-card border-t border-border">
      {/* Sticky bar */}
      <div className="flex items-center gap-0 h-9 px-2 border-b border-border bg-card shrink-0">
        <div className="inline-flex items-center gap-1.5 h-full px-3 text-xs font-medium text-foreground border-b-2 -mb-px border-foreground">
          <TerminalSquare className="h-3.5 w-3.5" strokeWidth={1.5} aria-hidden="true" />
          Terminal
        </div>

        <div className="ml-auto flex items-center gap-2 pr-2">
          {testsSummary && (
            <span
              className={cn(
                "inline-flex items-center gap-1 px-1.5 py-0.5 rounded-full text-[10px] font-semibold uppercase tracking-wide border",
                testResults.passed === true
                  ? "bg-success/10 text-success border-success/20"
                  : failedCount > 0
                  ? "bg-destructive/10 text-destructive border-destructive/20"
                  : "bg-muted text-muted-foreground border-border/30",
              )}
            >
              {testResults.passed === true ? (
                <CheckCircle2 className="h-3 w-3" strokeWidth={2} />
              ) : failedCount > 0 ? (
                <AlertOctagon className="h-3 w-3" strokeWidth={2} />
              ) : null}
              {testResults.passed === true ? "Passed" : failedCount > 0 ? "Failed" : "Run"}
              · {testsSummary}
            </span>
          )}
          {onClear && (
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
          )}
        </div>
      </div>

      <div className="flex-1 min-h-0 overflow-hidden">
        {/* Not run yet */}
        {!hasRun && !compilationLog && !programOutput && !error && (
          <EmptyState>
            Press <strong>Run</strong> to compile and execute your code.
          </EmptyState>
        )}

        {/* Compilation error → DevC++-style error display */}
        {hasError && (
          <AutoScrollLog content={`${compilationLog ?? ""}\n${error ?? ""}`}>
            <CompilerErrorView compilationLog={compilationLog} error={error} />
          </AutoScrollLog>
        )}

        {/* No compilation error → show program output */}
        {!hasError && (hasOutput || hasRun) && (
          <AutoScrollLog content={programOutput}>
            <pre className="whitespace-pre-wrap break-words text-foreground font-mono text-[12px] leading-relaxed">
              {programOutput || <span className="text-muted-foreground italic">Program executed successfully — no output.</span>}
            </pre>
          </AutoScrollLog>
        )}
      </div>
    </div>
  );
}

/**
 * CompilerErrorView — formats errors in DevC++ style:
 *   file:line: error message
 *   ^ (pointer)
 */
function CompilerErrorView({ compilationLog, error }) {
  return (
    <div className="space-y-2">
      {compilationLog && (
        <pre className="text-amber-500 whitespace-pre-wrap break-words font-mono text-[11px] leading-relaxed">
          {compilationLog}
        </pre>
      )}
      {error && (
        <pre className="text-destructive whitespace-pre-wrap break-words font-mono text-[11px] leading-relaxed">
          {error}
        </pre>
      )}
    </div>
  );
}

function AutoScrollLog({ children, content }) {
  return (
    <div className="h-full overflow-y-auto px-3 py-2 font-mono text-[11px] leading-relaxed">
      {children}
    </div>
  );
}

function EmptyState({ children }) {
  return (
    <div className="h-full flex items-center justify-center px-6 text-center text-xs text-muted-foreground font-mono">
      {children}
    </div>
  );
}
