import { useState, useMemo, useCallback } from "react";
import { useQuery } from "@tanstack/react-query";
import {
  Search,
  Flag,
  AlertTriangle,
  RefreshCw,
  CheckCircle,
  XCircle,
  ChevronRight,
  Clock,
} from "lucide-react";
import { Input } from "@/components/ui/input";
import { Button } from "@/components/ui/button";
import { Badge } from "@/components/ui/badge";
import { Switch } from "@/components/ui/switch";
import { Avatar, AvatarFallback } from "@/components/ui/avatar";
import InsightHeader from "@/components/ui/insight-header";
import SubmissionDetailDrawer from "@/components/analytics/SubmissionDetailDrawer";
import { formatDuration } from "@/lib/format";
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

function initials(name) {
  return (name || "?")
    .split(/\s+/)
    .filter(Boolean)
    .slice(0, 2)
    .map((part) => part[0]?.toUpperCase())
    .join("");
}

const GRID_CLASS = "grid grid-cols-1 sm:grid-cols-[minmax(0,1.4fr)_minmax(0,1fr)_3.5rem_5.5rem_5rem_7rem_2rem] items-start sm:items-center gap-1 sm:gap-3";

export default function SubmissionsTab({ sectionId, initialExerciseId = null }) {
  const [search, setSearch] = useState("");
  const [exerciseFilter, setExerciseFilter] = useState(() =>
    initialExerciseId ? String(initialExerciseId) : ""
  );
  const [statusFilter, setStatusFilter] = useState("all");
  const [selectedSubmission, setSelectedSubmission] = useState(null);
  const [expandedKey, setExpandedKey] = useState(null);
  const [showNonSubmitters, setShowNonSubmitters] = useState(false);

  // Grouped submissions (one group per student×exercise pair, latest attempt
  // carries the group status).
  const groupsQuery = useQuery({
    queryKey: ["section-submission-groups", sectionId],
    queryFn: async () => {
      const { data } = await api.get(
        `/api/analytics/sections/${sectionId}/submission-groups`,
        { params: { limit: 250 } }
      );
      return data;
    },
    enabled: !!sectionId,
  });

  // Full exercise list (includes exercises with zero submissions) so the
  // dropdown and the non-submitter filter cover everything.
  const exercisesQuery = useQuery({
    queryKey: ["section-exercises", sectionId],
    queryFn: async () => {
      const { data } = await api.get(`/api/sections/${sectionId}/exercises`);
      return Array.isArray(data) ? data : [];
    },
    enabled: !!sectionId,
    staleTime: 5 * 60 * 1000,
  });

  // Enrolled students who have not submitted (optionally per exercise).
  const nonSubmittersQuery = useQuery({
    queryKey: ["section-non-submitters", sectionId, exerciseFilter || "overall"],
    queryFn: async () => {
      const params = exerciseFilter ? { exerciseId: exerciseFilter } : {};
      const { data } = await api.get(
        `/api/analytics/sections/${sectionId}/non-submitters`,
        { params }
      );
      return data;
    },
    enabled: !!sectionId && showNonSubmitters,
  });

  const groups = useMemo(() => groupsQuery.data?.groups || [], [groupsQuery.data]);

  const exercises = useMemo(() => {
    const map = {};
    (exercisesQuery.data || []).forEach((ex) => {
      if (ex.id !== null && ex.id !== undefined && ex.title) {
        map[ex.id] = { id: ex.id, title: ex.title };
      }
    });
    // Fall back to groups-derived options if the exercises fetch failed.
    groups.forEach((g) => {
      if (!map[g.exercise_id] && g.exercise_title) {
        map[g.exercise_id] = { id: g.exercise_id, title: g.exercise_title };
      }
    });
    return Object.values(map).sort((a, b) => a.title.localeCompare(b.title));
  }, [exercisesQuery.data, groups]);

  // Deep-linked exercise may have zero submissions — keep a synthetic option.
  const exerciseOptions = useMemo(() => {
    const list = [...exercises];
    if (
      exerciseFilter &&
      !list.some((ex) => String(ex.id) === String(exerciseFilter))
    ) {
      list.unshift({ id: exerciseFilter, title: `Exercise #${exerciseFilter} (no data)` });
    }
    return list;
  }, [exercises, exerciseFilter]);

  const flaggedCount = useMemo(
    () => groups.filter((g) => g.flag_count > 0).length,
    [groups]
  );

  // Late = latest attempt landed after the exercise deadline (deadline now
  // comes from the submission-groups payload). Done = has attempts, on time.
  const isLate = (g) =>
    !!g.deadline &&
    !!g.latest_submitted_at &&
    new Date(g.latest_submitted_at).getTime() > new Date(g.deadline).getTime();

  const lateCount = useMemo(
    () => groups.filter(isLate).length,
    [groups]
  );

  const doneCount = useMemo(
    () => groups.filter((g) => !isLate(g)).length,
    [groups]
  );

  const totalAttempts = useMemo(
    () => groups.reduce((acc, g) => acc + (g.attempt_count || 0), 0),
    [groups]
  );

  // Filter semantics: status operates on the LATEST attempt of each group.
  const filtered = useMemo(() => {
    let list = groups;

    if (search) {
      const q = search.toLowerCase();
      list = list.filter(
        (g) =>
          g.student_name?.toLowerCase().includes(q) ||
          g.student_email?.toLowerCase().includes(q)
      );
    }
    if (exerciseFilter) {
      list = list.filter((g) => String(g.exercise_id) === String(exerciseFilter));
    }
    if (statusFilter === "pass") {
      list = list.filter((g) => g.latest_is_correct === true);
    } else if (statusFilter === "fail") {
      list = list.filter((g) => g.latest_is_correct === false);
    } else if (statusFilter === "flagged") {
      list = list.filter((g) => g.flag_count > 0);
    } else if (statusFilter === "late") {
      list = list.filter(isLate);
    } else if (statusFilter === "done") {
      list = list.filter((g) => !isLate(g));
    }

    return list;
  }, [groups, search, exerciseFilter, statusFilter]);

  const filteredNonSubmitters = useMemo(() => {
    let list = nonSubmittersQuery.data?.nonSubmitters || [];
    if (search) {
      const q = search.toLowerCase();
      list = list.filter(
        (s) =>
          s.name?.toLowerCase().includes(q) || s.email?.toLowerCase().includes(q)
      );
    }
    return list;
  }, [nonSubmittersQuery.data, search]);

  const isLoading = showNonSubmitters
    ? nonSubmittersQuery.isLoading
    : groupsQuery.isLoading;
  const isError = showNonSubmitters
    ? nonSubmittersQuery.isError
    : groupsQuery.isError;
  const refetch = showNonSubmitters
    ? nonSubmittersQuery.refetch
    : groupsQuery.refetch;

  const handleSubmissionClick = useCallback((sub) => {
    setSelectedSubmission(sub);
  }, []);

  const toggleGroup = useCallback((key) => {
    setExpandedKey((prev) => (prev === key ? null : key));
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

  const nonSubmittersData = nonSubmittersQuery.data;
  const insight = showNonSubmitters
    ? nonSubmittersData
      ? `${filteredNonSubmitters.length} of ${nonSubmittersData.total_students ?? "?"} enrolled students without submissions${exerciseFilter ? " for the selected exercise" : ""}.`
      : "Loading students without submissions…"
    : `${groups.length} student×exercise pair${groups.length === 1 ? "" : "s"} · ${totalAttempts} attempt${totalAttempts === 1 ? "" : "s"} · ${flaggedCount} flagged.`;

  return (
    <div className="space-y-6">
      <InsightHeader insight={insight} />

      {/* Filters */}
      <div className="flex flex-wrap items-center gap-3">
        {/* Search */}
        <div className="relative flex-1 min-w-0 max-w-sm">
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
          className="h-9 rounded-md border border-input bg-background px-3 text-sm text-muted-foreground focus-visible:outline-none focus-visible:ring-1 focus-visible:ring-ring w-full sm:w-auto"
        >
          <option value="">All exercises</option>
          {exerciseOptions.map((ex) => (
            <option key={ex.id} value={ex.id}>
              {ex.title}
            </option>
          ))}
        </select>

        {/* Action: Refresh */}
        <Button variant="ghost" size="sm" onClick={() => refetch()} title="Refresh">
          <RefreshCw className="h-3.5 w-3.5" strokeWidth={1.5} />
        </Button>

        {/* Non-submitters toggle */}
        <label className="flex items-center gap-2 text-sm text-muted-foreground cursor-pointer select-none">
          <Switch
            checked={showNonSubmitters}
            onCheckedChange={setShowNonSubmitters}
          />
          Show students without submissions
        </label>
      </div>

      {showNonSubmitters ? (
        <>
          {/* Status tabs don't apply to the non-submitter view */}
          {exerciseFilter ? (
            <div className="rounded-lg border border-border bg-card overflow-x-auto">
              <div className={cn(GRID_CLASS, "px-4 h-9 border-b border-border bg-muted/40")}>
                <span className="text-xs font-medium text-muted-foreground">Student</span>
                <span className="text-xs font-medium text-muted-foreground"></span>
                <span className="text-xs font-medium text-muted-foreground text-right"></span>
                <span className="text-xs font-medium text-muted-foreground text-right"></span>
                <span className="text-xs font-medium text-muted-foreground text-right"></span>
                <span className="text-xs font-medium text-muted-foreground text-right"></span>
                <span className="text-xs font-medium text-muted-foreground"></span>
              </div>
              <ul className="divide-y divide-border max-h-[600px] overflow-y-auto">
                {filteredNonSubmitters.map((s) => (
                  <li key={s.id} className={cn(GRID_CLASS, "px-4 sm:h-14")}>
                    <span className="flex items-center gap-2.5 min-w-0">
                      <Avatar className="h-8 w-8">
                        <AvatarFallback className="text-xs font-semibold text-muted-foreground">
                          {initials(s.name)}
                        </AvatarFallback>
                      </Avatar>
                      <span className="min-w-0">
                        <span className="block text-sm font-medium text-foreground truncate">{s.name}</span>
                        <span className="block text-xs text-muted-foreground truncate">{s.email}</span>
                      </span>
                    </span>
                    <span className="text-sm text-muted-foreground truncate"></span>
                    <span className="text-sm text-muted-foreground text-right tabular-nums sm:block"></span>
                    <span className="text-right"></span>
                    <span className="text-xs font-mono tabular-nums text-muted-foreground text-right"></span>
                    <span className="text-xs font-mono tabular-nums text-muted-foreground text-right"></span>
                    <span className="flex justify-center"></span>
                  </li>
                ))}
              </ul>
            </div>
          ) : (
            <div className="rounded-lg border border-border bg-card overflow-hidden">
              <div className="grid grid-cols-[minmax(0,1fr)_7rem] items-center gap-3 px-4 h-9 border-b border-border bg-muted/40 hidden sm:grid">
                <span className="text-xs font-medium text-muted-foreground">Exercise</span>
                <span className="text-xs font-medium text-muted-foreground text-right">Not submitted</span>
              </div>
              <ul className="divide-y divide-border max-h-[600px] overflow-y-auto">
                {(nonSubmittersData?.perExercise || []).map((ex) => (
                  <li
                    key={ex.id}
                    className="grid grid-cols-[minmax(0,1fr)_7rem] items-center gap-3 px-4 sm:h-12"
                  >
                    <span className="text-sm text-foreground truncate">{ex.title}</span>
                    <span className="text-sm text-muted-foreground text-right tabular-nums block">
                      {ex.non_submitter_count}
                    </span>
                  </li>
                ))}
              </ul>
            </div>
          )}

          {filteredNonSubmitters.length === 0 && (
            <div className="rounded-lg border border-dashed border-border bg-card/50 py-12 px-6 text-center">
              <p className="text-sm font-semibold text-foreground">All enrolled students have submitted</p>
              <p className="text-sm text-muted-foreground mt-1">
                {exerciseFilter
                  ? "No enrolled student is missing this exercise."
                  : "No enrolled student is missing any exercise."}
              </p>
            </div>
          )}
        </>
      ) : (
        <>
          {/* Status tabs (latest attempt + timeliness) */}
          <div className="flex flex-wrap items-center gap-2">
            {[
              { key: "all", label: `All (${groups.length})` },
              { key: "done", label: `Done (${doneCount})` },
              { key: "late", label: `Late (${lateCount})` },
              { key: "missing", label: "Missing", missing: true },
              { key: "flagged", label: `Flagged (${flaggedCount})` },
            ].map((tab) => (
              <button
                key={tab.key}
                type="button"
                onClick={() => {
                  if (tab.missing) {
                    setShowNonSubmitters(true);
                    setStatusFilter("all");
                  } else {
                    setShowNonSubmitters(false);
                    setStatusFilter(tab.key);
                  }
                }}
                className={cn(
                  "px-3 py-1 text-sm rounded-md transition-colors",
                  (!tab.missing && statusFilter === tab.key) || (tab.missing && showNonSubmitters)
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

          {/* Grouped submissions table */}
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
              <div className="overflow-x-auto">
                {/* Table header */}
                <div className={cn(GRID_CLASS, "px-4 h-9 border-b border-border bg-muted/40 hidden sm:grid")}>
                  <span className="text-xs font-medium text-muted-foreground">Student</span>
                  <span className="text-xs font-medium text-muted-foreground">Exercise</span>
                  <span className="text-xs font-medium text-muted-foreground text-right">Attempts</span>
                  <span className="text-xs font-medium text-muted-foreground text-right">Status</span>
                  <span className="text-xs font-medium text-muted-foreground text-right">Total time</span>
                  <span className="text-xs font-medium text-muted-foreground text-right">Submitted</span>
                  <span className="text-xs font-medium text-muted-foreground"></span>
                </div>
                <ul className="divide-y divide-border max-h-[600px] overflow-y-auto">
                  {filtered.map((g) => {
                    const key = `${g.student_id}:${g.exercise_id}`;
                    const isExpanded = expandedKey === key;
                    return (
                      <li key={key}>
                        {/* Group row */}
                        <div
                          onClick={() => toggleGroup(key)}
                          className={cn(
                            GRID_CLASS,
                            "px-4 sm:h-14 hover:bg-muted/40 transition-colors cursor-pointer"
                          )}
                        >
                          <span className="flex items-center gap-2.5 min-w-0">
                            <Avatar className="h-8 w-8">
                              <AvatarFallback className="text-xs font-semibold text-muted-foreground">
                                {initials(g.student_name)}
                              </AvatarFallback>
                            </Avatar>
                            <span className="min-w-0">
                              <span className="block text-sm font-medium text-foreground truncate">{g.student_name}</span>
                              <span className="block text-xs text-muted-foreground truncate">{g.student_email}</span>
                            </span>
                          </span>
                          <span className="text-sm text-muted-foreground truncate">
                            {g.exercise_title}
                          </span>
                          <span className="text-sm text-muted-foreground text-right tabular-nums sm:block">
                            ×{g.attempt_count}
                          </span>
                          <span className="flex items-center justify-end gap-1.5">
                            {isLate(g) && (
                              <Badge variant="outline" className="bg-amber-500/10 text-amber-400 border-amber-500/30 text-[11px]">
                                <Clock className="h-3 w-3 mr-1" strokeWidth={1.5} />
                                Late
                              </Badge>
                            )}
                            {g.latest_is_correct ? (
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
                            {formatDuration(g.total_time_spent_seconds)}
                          </span>
                          <span className="text-xs font-mono tabular-nums text-muted-foreground text-right">
                            {timeAgo(g.latest_submitted_at)}
                          </span>
                          <span className="flex justify-center gap-1">
                            {g.flag_count > 0 ? (
                              <Flag className="h-3.5 w-3.5 text-destructive" strokeWidth={1.5} />
                            ) : (
                              <span className="w-3.5" />
                            )}
                            <ChevronRight
                              className={cn(
                                "h-4 w-4 text-muted-foreground transition-transform duration-200",
                                isExpanded && "rotate-90 text-foreground"
                              )}
                              strokeWidth={1.5}
                            />
                          </span>
                        </div>

                        {/* Inline-expanded attempts */}
                        {isExpanded && (
                          <div className="bg-muted/20 border-l-2 border-l-primary/40">
                            {g.attempts.map((a) => (
                              <div
                                key={a.id}
                                className={cn(GRID_CLASS, "px-4 pl-8 sm:h-11")}
                              >
                                <span className="text-sm text-foreground font-medium tabular-nums">
                                  #{a.attempt_number}
                                </span>
                                <span className="text-xs text-muted-foreground truncate"></span>
                                <span className="text-sm text-muted-foreground text-right tabular-nums sm:block"></span>
                                <span className="text-right">
                                  {a.is_correct ? (
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
                                <span className="flex items-center justify-end gap-1 text-xs font-mono tabular-nums text-muted-foreground">
                                  <Clock className="h-3 w-3" strokeWidth={1.5} />
                                  {formatDuration(a.time_spent_seconds)}
                                </span>
                                <span className="text-xs font-mono tabular-nums text-muted-foreground text-right">
                                  {timeAgo(a.submitted_at)}
                                </span>
                                <span className="flex justify-center">
                                  <Button
                                    variant="ghost"
                                    size="sm"
                                    className="h-7 px-2 text-xs"
                                    onClick={(ev) => {
                                      ev.stopPropagation();
                                      handleSubmissionClick(a);
                                    }}
                                  >
                                    Review
                                  </Button>
                                </span>
                              </div>
                            ))}
                          </div>
                        )}
                      </li>
                    );
                  })}
                </ul>
              </div>
            </div>
          )}
        </>
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
