import { useState, useMemo, useCallback } from "react";
import { useQuery } from "@tanstack/react-query";
import {
  Search,
  Flag,
  AlertTriangle,
  RefreshCw,
  CheckCircle,
  XCircle,
  ChevronDown,
  ExternalLink,
} from "lucide-react";
import { Input } from "@/components/ui/input";
import { Button } from "@/components/ui/button";
import { Badge } from "@/components/ui/badge";
import InsightHeader from "@/components/ui/insight-header";
import SubmissionDetailDrawer from "@/components/analytics/SubmissionDetailDrawer";
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
  const [search, setSearch] = useState("");
  const [exerciseFilter, setExerciseFilter] = useState("");
  const [statusFilter, setStatusFilter] = useState("all");
  const [selectedSubmission, setSelectedSubmission] = useState(null);

  const { data, isLoading, isError, refetch } = useQuery({
    queryKey: ["section-submissions", sectionId],
    queryFn: async () => {
      const { data } = await api.get(
        `/api/analytics/sections/${sectionId}/submissions?limit=250`
      );
      return data;
    },
    enabled: !!sectionId,
  });

  const submissions = useMemo(() => data?.submissions || [], [data]);

  // Extract unique exercises for filter dropdown
  const exercises = useMemo(() => {
    const map = {};
    submissions.forEach((s) => {
      if (!map[s.exercise_id]) {
        map[s.exercise_id] = {
          id: s.exercise_id,
          title: s.exercise_title,
        };
      }
    });
    return Object.values(map).sort((a, b) => a.title.localeCompare(b.title));
  }, [submissions]);

  const flaggedCount = useMemo(
    () => submissions.filter((s) => s.flag_count > 0).length,
    [submissions]
  );

  const filtered = useMemo(() => {
    let list = submissions;

    if (search) {
      const q = search.toLowerCase();
      list = list.filter(
        (s) =>
          s.student_name?.toLowerCase().includes(q) ||
          s.student_email?.toLowerCase().includes(q)
      );
    }
    if (exerciseFilter) {
      list = list.filter((s) => s.exercise_id === parseInt(exerciseFilter, 10));
    }
    if (statusFilter === "flagged") {
      list = list.filter((s) => s.flag_count > 0);
    } else if (statusFilter === "pass") {
      list = list.filter((s) => s.is_correct);
    } else if (statusFilter === "fail") {
      list = list.filter((s) => !s.is_correct);
    }

    return list;
  }, [submissions, search, exerciseFilter, statusFilter]);

  const handleSubmissionClick = useCallback((sub) => {
    setSelectedSubmission(sub);
  }, []);

  if (isLoading) {
    return (
      <div className="space-y-6">
        <InsightHeader insight="Loading submissions…" />
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
        insight={`${submissions.length} submission${submissions.length === 1 ? "" : "s"} across ${exercises.length} exercise${exercises.length === 1 ? "" : "s"}. ${flaggedCount} flagged.`}
      />

      {/* Filters */}
      <div className="flex flex-wrap items-center gap-3">
        {/* Search */}
        <div className="relative flex-1 min-w-[200px] max-w-sm">
          <Search className="absolute left-2.5 top-1/2 -translate-y-1/2 h-3.5 w-3.5 text-muted-foreground" strokeWidth={1.5} />
          <Input
            type="text"
            placeholder="Search student…"
            value={search}
            onChange={(e) => setSearch(e.target.value)}
            className="h-9 pl-8 text-sm"
          />
        </div>

        {/* Exercise filter */}
        <select
          value={exerciseFilter}
          onChange={(e) => setExerciseFilter(e.target.value)}
          className="h-9 rounded-md border border-input bg-background px-3 text-sm text-muted-foreground focus-visible:outline-none focus-visible:ring-1 focus-visible:ring-ring"
        >
          <option value="">All exercises</option>
          {exercises.map((ex) => (
            <option key={ex.id} value={ex.id}>
              {ex.title}
            </option>
          ))}
        </select>

        {/* Action: Refresh */}
        <Button variant="ghost" size="sm" onClick={() => refetch()} title="Refresh">
          <RefreshCw className="h-3.5 w-3.5" strokeWidth={1.5} />
        </Button>
      </div>

      {/* Status tabs */}
      <div className="flex items-center gap-2">
        {[
          { key: "all", label: `All (${submissions.length})` },
          { key: "pass", label: "Pass" },
          { key: "fail", label: "Fail" },
          { key: "flagged", label: `Flagged (${flaggedCount})` },
        ].map((tab) => (
          <button
            key={tab.key}
            type="button"
            onClick={() => setStatusFilter(tab.key)}
            className={cn(
              "px-3 py-1 text-sm rounded-md transition-colors",
              statusFilter === tab.key
                ? tab.key === "flagged"
                  ? "bg-destructive/10 text-destructive border border-destructive/20 font-medium"
                  : "bg-muted text-foreground font-medium"
                : "text-muted-foreground hover:text-foreground border border-transparent"
            )}
          >
            {tab.key === "flagged" && (
              <Flag className="h-3 w-3 inline mr-1" strokeWidth={1.5} />
            )}
            {tab.label}
          </button>
        ))}
      </div>

      {/* Submissions table */}
      {filtered.length === 0 ? (
        <div className="rounded-lg border border-dashed border-border bg-card/50 py-12 px-6 text-center">
          <p className="text-sm font-semibold text-foreground">No submissions found</p>
          <p className="text-sm text-muted-foreground mt-1">
            {search
              ? "Try a different search term."
              : "Submissions will appear here once students submit exercises."}
          </p>
        </div>
      ) : (
        <div className="rounded-lg border border-border bg-card overflow-hidden">
          {/* Table header */}
          <div className="grid grid-cols-[1fr_1fr_5rem_5rem_7rem_3rem] items-center gap-3 px-4 h-9 border-b border-border bg-muted/40">
            <span className="text-xs font-medium text-muted-foreground">Student</span>
            <span className="text-xs font-medium text-muted-foreground">Exercise</span>
            <span className="text-xs font-medium text-muted-foreground text-right">Attempt</span>
            <span className="text-xs font-medium text-muted-foreground text-right">Status</span>
            <span className="text-xs font-medium text-muted-foreground text-right">Submitted</span>
            <span className="text-xs font-medium text-muted-foreground"></span>
          </div>
          <ul className="divide-y divide-border max-h-[600px] overflow-y-auto">
            {filtered.map((s) => (
              <li
                key={s.id}
                onClick={() => handleSubmissionClick(s)}
                className="grid grid-cols-[1fr_1fr_5rem_5rem_7rem_3rem] items-center gap-3 px-4 h-14 hover:bg-muted/40 transition-colors cursor-pointer"
              >
                <span className="text-sm font-medium text-foreground truncate">
                  {s.student_name}
                </span>
                <span className="text-sm text-muted-foreground truncate">
                  {s.exercise_title}
                </span>
                <span className="text-sm text-muted-foreground text-right tabular-nums">
                  #{s.attempt_number}
                </span>
                <span className="text-right">
                  {s.is_correct ? (
                    <Badge variant="outline" className="bg-emerald-500/10 text-emerald-400 border-emerald-500/30 text-[11px]">
                      <CheckCircle className="h-3 w-3 mr-1" strokeWidth={1.5} />
                      Pass
                    </Badge>
                  ) : (
                    <Badge variant="outline" className="bg-destructive/10 text-destructive border-destructive/30 text-[11px]">
                      <XCircle className="h-3 w-3 mr-1" strokeWidth={1.5} />
                      Fail
                    </Badge>
                  )}
                </span>
                <span className="text-xs font-mono tabular-nums text-muted-foreground text-right">
                  {timeAgo(s.submitted_at)}
                </span>
                <span className="flex justify-center">
                  {s.flag_count > 0 ? (
                    <Flag className="h-3.5 w-3.5 text-destructive" strokeWidth={1.5} />
                  ) : (
                    <ExternalLink className="h-3.5 w-3.5 text-muted-foreground/40" strokeWidth={1.5} />
                  )}
                </span>
              </li>
            ))}
          </ul>
        </div>
      )}

      {/* Submission detail drawer */}
      <SubmissionDetailDrawer
        submission={selectedSubmission}
        open={!!selectedSubmission}
        onClose={() => setSelectedSubmission(null)}
      />
    </div>
  );
}
