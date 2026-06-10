import { useMemo, useState } from "react";
import { useQuery } from "@tanstack/react-query";
import { Flag, AlertTriangle, RefreshCw } from "lucide-react";
import { Button } from "@/components/ui/button";
import InsightHeader from "@/components/ui/insight-header";
import { cn } from "@/lib/utils";
import api from "@/services/api";

function timeAgo(dateStr) {
  if (!dateStr) return "—";
  const ms = Date.now() - new Date(dateStr).getTime();
  const mins = Math.floor(ms / 60000);
  if (mins < 1) return "just now";
  if (mins < 60) return `${mins}m ago`;
  const hours = Math.floor(mins / 60);
  if (hours < 24) return `${hours}h ago`;
  const days = Math.floor(hours / 24);
  return `${days}d ago`;
}

export default function SubmissionsTab({ sectionId }) {
  const [filter, setFilter] = useState("all");

  const { data: rawFlags = [], isLoading, isError, refetch } = useQuery({
    queryKey: ["submissions-flags", sectionId],
    queryFn: async () => {
      const { data } = await api.get(`/api/analytics/integrity-flags/${sectionId}?limit=100`);
      return data.flags || [];
    },
    enabled: !!sectionId,
  });

  const submissions = useMemo(() => {
    return rawFlags.map((f, idx) => ({
      id: f.id || idx,
      student: f.student_name || "Unknown",
      exercise: f.exercise_title || "Unknown",
      submitted: timeAgo(f.created_at),
      score: 0,
      anomaly: formatFlagType(f.flag_type),
      severity: f.severity,
      status: f.status,
    }));
  }, [rawFlags]);

  const flaggedSubmissions = useMemo(() => submissions.filter((s) => s.anomaly != null), [submissions]);

  const rows = filter === "flagged" ? flaggedSubmissions : submissions;

  if (isLoading) {
    return (
      <div className="space-y-6">
        <InsightHeader insight="Loading submissions data…" />
        <div className="rounded-lg border border-border bg-card/50 py-8 px-6 text-center">
          <p className="text-sm font-semibold text-foreground">Loading submissions…</p>
        </div>
      </div>
    );
  }

  if (isError) {
    return (
      <div className="space-y-6">
        <InsightHeader insight="Failed to load submissions." />
        <div className="flex items-center gap-3 rounded-lg border border-destructive/30 bg-destructive/5 px-4 py-3">
          <AlertTriangle className="h-4 w-4 text-destructive shrink-0" />
          <p className="text-sm text-destructive flex-1">Failed to load submissions.</p>
          <Button size="sm" variant="outline" className="border-destructive/30 text-destructive" onClick={() => refetch()}>
            <RefreshCw className="h-3.5 w-3.5 mr-1.5" />
            Retry
          </Button>
        </div>
      </div>
    );
  }

  return (
    <div className="space-y-6">
      <InsightHeader
        insight={`${flaggedSubmissions.length} submission${flaggedSubmissions.length === 1 ? "" : "s"} flagged for anomalies.`}
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
          All ({submissions.length})
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
          Flagged ({flaggedSubmissions.length})
        </button>
      </div>

      {submissions.length === 0 ? (
        <div className="rounded-lg border border-dashed border-border bg-card/50 py-12 px-6 text-center">
          <p className="text-sm font-semibold text-foreground">No submissions yet</p>
          <p className="text-sm text-muted-foreground mt-1">
            Submissions will appear here once students submit exercises.
          </p>
        </div>
      ) : (
        <div className="rounded-lg border border-border bg-card overflow-hidden">
          <div className="grid grid-cols-[1fr_12rem_5rem_5rem_14rem] items-center gap-3 px-4 h-9 border-b border-border bg-muted/40">
            <span className="text-xs font-medium text-muted-foreground">Student</span>
            <span className="text-xs font-medium text-muted-foreground">Exercise</span>
            <span className="text-xs font-medium text-muted-foreground text-right">Severity</span>
            <span className="text-xs font-medium text-muted-foreground text-right">Submitted</span>
            <span className="text-xs font-medium text-muted-foreground">Flag</span>
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
                <span className="text-right">
                  {s.severity ? (
                    <span className={cn(
                      "inline-flex items-center px-1.5 py-0.5 rounded text-[11px] font-medium",
                      s.severity === "high" ? "bg-destructive/10 text-destructive" :
                      s.severity === "medium" ? "bg-warning/10 text-warning" :
                      "bg-muted text-muted-foreground"
                    )}>
                      {s.severity}
                    </span>
                  ) : (
                    <span className="text-xs text-muted-foreground">—</span>
                  )}
                </span>
                <span className="text-xs font-mono tabular-nums text-muted-foreground text-right">
                  {s.submitted}
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
      )}
    </div>
  );
}

function formatFlagType(type) {
  const map = {
    code_paste_detected: "Paste from URL",
    code_growth_anomaly: "Code growth anomaly",
    retry_storm: "Retry storm",
    hardcoded: "Hardcode detected",
    blank_template: "Blank template",
    behavioral_anomaly: "Behavioral anomaly",
  };
  return map[type] || type || null;
}
