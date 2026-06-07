import { useState } from "react";
import { Flag, AlertTriangle } from "lucide-react";
import InsightHeader from "@/components/ui/insight-header";
import { cn } from "@/lib/utils";

const SUBMISSIONS = [
  { id: 1, student: "A. Khan",  exercise: "Ex.4 — Recursion",  submitted: "2h",  score: 0.62, anomaly: "Hardcode detected" },
  { id: 2, student: "B. Reyes", exercise: "Ex.7 — Hashing",    submitted: "5h",  score: 0.74, anomaly: "Paste from URL" },
  { id: 3, student: "C. Park",  exercise: "Ex.3 — Loops",      submitted: "1d",  score: 0.68, anomaly: "Behavioral anomaly" },
  { id: 4, student: "D. Lopez", exercise: "Ex.5 — Sorting",    submitted: "1d",  score: 0.61, anomaly: "Blank template" },
  { id: 5, student: "E. Chen",  exercise: "Ex.2 — Strings",    submitted: "2d",  score: 0.88, anomaly: null },
  { id: 6, student: "F. Adams", exercise: "Ex.4 — Recursion",  submitted: "2d",  score: 0.79, anomaly: null },
  { id: 7, student: "G. Park",  exercise: "Ex.1 — Arrays",     submitted: "3d",  score: 0.91, anomaly: null },
  { id: 8, student: "H. Singh", exercise: "Ex.3 — Loops",      submitted: "3d",  score: 0.85, anomaly: null },
];

export default function SubmissionsTab() {
  const [filter, setFilter] = useState("all"); // "all" | "flagged"

  const rows =
    filter === "flagged"
      ? SUBMISSIONS.filter((s) => s.anomaly != null)
      : SUBMISSIONS;

  return (
    <div className="space-y-6">
      <InsightHeader
        insight="4 submissions flagged for anomalies this week."
      />

      <div className="flex items-center gap-2">
        <button
          type="button"
          onClick={() => setFilter("all")}
          className={cn(
            "px-3 py-1 text-sm rounded-md transition-colors",
            filter === "all"
              ? "bg-muted text-foreground font-medium"
              : "text-muted-foreground hover:text-foreground",
          )}
        >
          All ({SUBMISSIONS.length})
        </button>
        <button
          type="button"
          onClick={() => setFilter("flagged")}
          className={cn(
            "inline-flex items-center gap-1.5 px-3 py-1 text-sm rounded-md transition-colors",
            filter === "flagged"
              ? "bg-destructive/10 text-destructive border border-destructive/20 font-medium"
              : "text-muted-foreground hover:text-foreground border border-transparent",
          )}
        >
          <Flag className="h-3 w-3" strokeWidth={1.5} />
          Flagged ({SUBMISSIONS.filter((s) => s.anomaly).length})
        </button>
      </div>

      <div className="rounded-lg border border-border bg-card overflow-hidden">
        <div className="grid grid-cols-[1fr_12rem_5rem_5rem_14rem] items-center gap-3 px-4 h-9 border-b border-border bg-muted/40">
          <span className="text-xs font-medium text-muted-foreground">Student</span>
          <span className="text-xs font-medium text-muted-foreground">Exercise</span>
          <span className="text-xs font-medium text-muted-foreground text-right">Score</span>
          <span className="text-xs font-medium text-muted-foreground text-right">Submitted</span>
          <span className="text-xs font-medium text-muted-foreground">Anomaly</span>
        </div>
        <ul className="divide-y divide-border">
          {rows.map((s) => (
            <li
              key={s.id}
              className="grid grid-cols-[1fr_12rem_5rem_5rem_14rem] items-center gap-3 px-4 h-14 hover:bg-muted/40 transition-colors cursor-pointer"
            >
              <span className="text-sm font-medium text-foreground truncate">
                {s.student}
              </span>
              <span className="text-sm text-muted-foreground truncate">
                {s.exercise}
              </span>
              <span className="text-sm font-mono tabular-nums text-right">
                {(s.score * 100).toFixed(0)}%
              </span>
              <span className="text-xs font-mono tabular-nums text-muted-foreground text-right">
                {s.submitted} ago
              </span>
              {s.anomaly ? (
                <span className="inline-flex items-center gap-1.5 px-2 py-0.5 rounded-full text-[11px] font-medium bg-destructive/10 text-destructive border border-destructive/20 w-fit">
                  <AlertTriangle className="h-3 w-3" strokeWidth={1.5} aria-hidden="true" />
                  {s.anomaly}
                </span>
              ) : (
                <span className="text-xs text-muted-foreground">—</span>
              )}
            </li>
          ))}
        </ul>
      </div>
    </div>
  );
}
