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
 * Frosted glassmorphic theme with emerald accents.
 */
export default function ProblemPanel({ exercise, testResults }) {
  const allPassing =
    testResults && testResults.total > 0 && testResults.passing === testResults.total;
  const badge = testResults ? `${testResults.passing}/${testResults.total}` : null;

  return (
    <div className="flex flex-col h-full min-h-0 bg-[#131B2E]/40 backdrop-blur-md border-r border-white/[0.05]">
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
        className="flex-1 min-h-0 border-t border-white/[0.05]"
      >
        <TestOutputPanel
          testResults={testResults}
          testCases={exercise?.test_cases || []}
          bare
        />
      </Section>
    </div>
  );
}

function Section({ icon: Icon, title, badge, badgeTone = "muted", className, children }) {
  return (
    <section className={cn("flex flex-col min-h-0", className)}>
      <header className="flex items-center gap-2 h-9 px-3 border-b border-white/[0.06] bg-[#131B2E]/30 backdrop-blur-sm shrink-0">
        <Icon className="h-3.5 w-3.5 text-emerald-400/70" strokeWidth={1.5} aria-hidden="true" />
        <h2 className="text-xs font-semibold tracking-tight text-white/80">{title}</h2>
        {badge != null ? (
          <span
            className={cn(
              "inline-flex items-center px-1.5 py-0.5 rounded-full text-[10px] font-mono tabular-nums",
              badgeTone === "success"
                ? "bg-emerald-500/10 text-emerald-400"
                : "bg-white/[0.04] text-muted-foreground",
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
