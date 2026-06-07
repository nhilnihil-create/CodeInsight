import { FileText, ListChecks } from "lucide-react";
import { cn } from "@/lib/utils";
import InstructionsPanel from "./InstructionsPanel";
import TestOutputPanel from "./TestOutputPanel";

/**
 * ProblemPanel
 * Left pane of the desktop workbench. Two scrollable sections:
 *   - Instructions  problem description, I/O format, constraints, examples
 *   - Test Cases    public test rows with Pass/Fail + input + expected
 *
 * Each section is a sticky-header card with its own scroll. The
 * sections are stacked vertically and the panel as a whole never
 * collapses (handled by the workbench's minSize=18 floor).
 *
 * Tokens only.
 */
export default function ProblemPanel({ exercise, testResults }) {
  const allPassing =
    testResults && testResults.total > 0 && testResults.passing === testResults.total;
  const badge = testResults ? `${testResults.passing}/${testResults.total}` : null;

  return (
    <div className="flex flex-col h-full min-h-0 bg-card border-r border-border">
      <Section
        icon={FileText}
        title="Instructions"
        className="flex-1 min-h-0"
      >
        <InstructionsPanel exercise={exercise} bare />
      </Section>

      <Section
        icon={ListChecks}
        title="Test Cases"
        badge={badge}
        badgeTone={allPassing ? "success" : "muted"}
        className="flex-1 min-h-0 border-t border-border"
      >
        <TestOutputPanel testResults={testResults} bare />
      </Section>
    </div>
  );
}

function Section({ icon: Icon, title, badge, badgeTone = "muted", className, children }) {
  return (
    <section className={cn("flex flex-col min-h-0", className)}>
      <header className="flex items-center gap-2 h-9 px-3 border-b border-border bg-card shrink-0">
        <Icon className="h-3.5 w-3.5 text-muted-foreground" strokeWidth={1.5} aria-hidden="true" />
        <h2 className="text-xs font-semibold tracking-tight">{title}</h2>
        {badge != null ? (
          <span
            className={cn(
              "inline-flex items-center px-1.5 py-0.5 rounded-full text-[10px] font-mono tabular-nums",
              badgeTone === "success"
                ? "bg-success/10 text-success"
                : "bg-muted text-muted-foreground",
            )}
          >
            {badge}
          </span>
        ) : null}
      </header>
      <div className="flex-1 min-h-0 overflow-hidden">{children}</div>
    </section>
  );
}
