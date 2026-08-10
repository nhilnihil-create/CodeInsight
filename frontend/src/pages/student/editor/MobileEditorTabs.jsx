import { useState } from "react";
import { Code2, TerminalSquare, FileText, Clock } from "lucide-react";
import { cn } from "@/lib/utils";
import InstructionsPanel from "./InstructionsPanel";
import CodeEditorSurface from "./CodeEditorSurface";
import TestOutputPanel from "./TestOutputPanel";
import SubmissionsPanel from "./SubmissionsPanel";
import OutputPanel from "./OutputPanel";

/**
 * MobileEditorTabs
 * Mobile-only 4-tab switcher: Code | Output | Problem | History.
 * Renders the correct panel based on `activeTab`. Full height minus
 * the header and the mobile action bar.
 *
 * Visible on < lg (the orchestrator gates this with `flex lg:hidden`).
 *
 * Tokens only.
 */
const TABS = [
  { id: "code",     label: "Code",     icon: Code2 },
  { id: "output",   label: "Output",   icon: TerminalSquare },
  { id: "problem",  label: "Problem",  icon: FileText },
  { id: "history",  label: "History",  icon: Clock },
];

export default function MobileEditorTabs({
  activeTab,
  onTabChange,
  exercise,
  code,
  onCodeChange,
  testResults,
  onMount,
  onAutocompleteAccept,
  submissions,
  history,
  compilationLog = "",
  programOutput = "",
  isReviewMode = false,
}) {
  return (
    <div className="flex flex-col flex-1 min-h-0">
      <div
        role="tablist"
        aria-label="Editor panels"
        className="flex items-center gap-0 bg-card border-b border-border px-1 h-10 shrink-0"
      >
        {TABS.map((t) => {
          const Icon = t.icon;
          const active = t.id === activeTab;
          return (
            <button
              key={t.id}
              type="button"
              role="tab"
              aria-selected={active}
              onClick={() => onTabChange(t.id)}
              className={cn(
                "inline-flex items-center justify-center gap-1.5 flex-1 h-full text-xs font-medium rounded-sm transition-colors",
                active
                  ? "text-foreground bg-muted/40"
                  : "text-muted-foreground hover:text-foreground",
              )}
            >
              <Icon className="h-3.5 w-3.5" strokeWidth={1.5} aria-hidden="true" />
              {t.label}
            </button>
          );
        })}
      </div>

      <div className="flex-1 min-h-0 overflow-hidden">
        {activeTab === "code" ? (
          <CodeEditorSurface
            value={code}
            onChange={onCodeChange}
            onMount={onMount}
            onAutocompleteAccept={onAutocompleteAccept}
            readOnly={isReviewMode}
          />
        ) : activeTab === "output" ? (
          <div className="h-full">
            <OutputPanel
              testResults={testResults}
              compilationLog={compilationLog}
              programOutput={programOutput}
            />
          </div>
        ) : activeTab === "history" ? (
          <SubmissionsPanel
            exercise={exercise}
            submissions={submissions}
            history={history}
          />
        ) : (
          <ProblemContent exercise={exercise} testResults={testResults} />
        )}
      </div>
    </div>
  );
}

function ProblemContent({ exercise, testResults }) {
  // Mobile reuses the same two tabs as the desktop ProblemPanel.
  const [tab, setTab] = useState("problem");
  return (
    <div className="flex flex-col h-full min-h-0 bg-card">
      <div
        role="tablist"
        aria-label="Mobile problem panel"
        className="flex items-center gap-0 h-9 px-2 border-b border-border bg-card shrink-0"
      >
        {[
          { id: "problem", label: "Problem" },
          { id: "tests",   label: "Tests"   },
        ].map((t) => {
          const active = t.id === tab;
          return (
            <button
              key={t.id}
              type="button"
              role="tab"
              aria-selected={active}
              onClick={() => setTab(t.id)}
              className={cn(
                "inline-flex items-center justify-center h-full px-3 text-xs font-medium transition-colors",
                "border-b-2 -mb-px",
                active
                  ? "text-foreground border-foreground"
                  : "text-muted-foreground border-transparent hover:text-foreground",
              )}
            >
              {t.label}
            </button>
          );
        })}
      </div>
      <div className="flex-1 min-h-0 overflow-hidden">
        {tab === "problem" ? (
          <InstructionsPanel exercise={exercise} bare />
        ) : (
          <TestOutputPanel testResults={testResults} bare />
        )}
      </div>
    </div>
  );
}
