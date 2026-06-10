import { useMemo, useState, useEffect } from "react";
import { Link } from "react-router-dom";
import {
  ArrowRight,
  ArrowUpDown,
  ArrowUp,
  ArrowDown,
  TrendingUp,
  TrendingDown,
  Minus,
  RefreshCw,
} from "lucide-react";
import {
  ResponsiveContainer,
  RadarChart,
  PolarGrid,
  PolarAngleAxis,
  PolarRadiusAxis,
  Radar,
} from "recharts";
import { Button } from "@/components/ui/button";
import { Card, CardContent, CardHeader, CardTitle } from "@/components/ui/card";
import { Tabs, TabsList, TabsTrigger, TabsContent } from "@/components/ui/tabs";
import InsightHeader from "@/components/ui/insight-header";
import EvidenceRow from "@/components/ui/evidence-row";
import PeriodSelector from "@/components/ui/period-selector";
import StudentDashboardShell from "@/components/student-dashboard-shell";
import api from "@/services/api";
import { cn } from "@/lib/utils";

const PERIOD_OPTIONS = ["7d", "30d", "90d", "All"];

/**
 * METRIC SEMANTICS (documented so future changes don't reintroduce confusion):
 *
 * CDS (Concept Difficulty Score) — lower is BETTER.
 *   0–25 = Low Difficulty (good)
 *   26–50 = Moderate
 *   51–75 = High
 *   76–100 = Critical
 *
 * Mastery = 100 − CDS — higher is BETTER.
 *   Direct inverse of difficulty. A student with CDS 0.56 has mastery 44%.
 *
 * Completion = completed exercises / assigned exercises — activity metric.
 *   Does NOT imply understanding. A student can submit everything with
 *   heavy struggle and still have low mastery.
 *
 * Progress = change in mastery over time. A snapshot is NOT progress.
 */

const FILL_TONE = {
  strong:         "bg-success",
  developing:     "bg-warning",
  needs_support:  "bg-destructive",
};

const LEVEL_LABELS = {
  strong:         "Strong",
  developing:     "Developing",
  needs_support:  "Needs Support",
};

const HEAT_TONE = [
  "bg-muted/30",
  "bg-success/20",
  "bg-success/45",
  "bg-success/70",
  "bg-success",
];

const TRIGGER_BASE =
  "rounded-none border-b-2 border-transparent data-[state=active]:border-b-foreground data-[state=active]:bg-transparent data-[state=active]:text-foreground data-[state=active]:shadow-none -mb-px px-3";

function trendIcon(delta) {
  if (delta > 0) return <TrendingUp className="h-3 w-3" strokeWidth={2} aria-hidden="true" />;
  if (delta < 0) return <TrendingDown className="h-3 w-3" strokeWidth={2} aria-hidden="true" />;
  return <Minus className="h-3 w-3" strokeWidth={2} aria-hidden="true" />;
}

function trendTone(delta) {
  if (delta === 0) return "text-muted-foreground";
  return delta > 0 ? "text-success" : "text-destructive";
}

function monthLabel(weekIdx) {
  const today = new Date();
  const HEAT_WEEKS = 12;
  const start = new Date(today);
  start.setDate(today.getDate() - (HEAT_WEEKS - 1 - weekIdx) * 7);
  return start.toLocaleDateString("en-US", { month: "short" });
}

function formatTimeAgo(dateStr) {
  if (!dateStr) return '';
  const now = Date.now();
  const then = new Date(dateStr).getTime();
  const diffSec = Math.round((now - then) / 1000);
  if (diffSec < 60) return 'just now';
  const diffMin = Math.round(diffSec / 60);
  if (diffMin < 60) return `${diffMin}m ago`;
  const diffHour = Math.round(diffMin / 60);
  if (diffHour < 24) return `${diffHour}h ago`;
  const diffDay = Math.round(diffHour / 24);
  if (diffDay === 1) return 'yesterday';
  if (diffDay < 7) return `${diffDay}d ago`;
  return new Date(dateStr).toLocaleDateString();
}

export default function StudentProgress() {
  const [period, setPeriod] = useState("30d");
  const [tab, setTab] = useState("mastery");
  const [data, setData] = useState(null);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [refetching, setRefetching] = useState(false);

  const days = period === 'All' ? 365 : parseInt(period.replace('d', ''), 10) || 30;

  useEffect(() => {
    let cancelled = false;
    const load = async () => {
      setLoading(true);
      try {
        const res = await api.get(`/api/student/progress?days=${days}`);
        if (!cancelled) setData(res.data);
      } catch (err) {
        if (!cancelled) setError(err.response?.data?.error || 'Failed to load progress');
      } finally {
        if (!cancelled) setLoading(false);
      }
    };
    load();
    return () => { cancelled = true; };
  }, [days]);

  // ---------- Metric decomposition ----------
  const overallMastery = data?.overallMastery ?? 0;    // CDS-based understanding
  const completion = data?.completion;                  // activity metric
  const completionPct = completion?.percentage ?? 0;
  const completedEx = completion?.completed ?? 0;
  const totalEx = completion?.total ?? 0;
  const streak = data?.streak?.current ?? 0;
  const avgAttempts = data?.avgAttempts ?? 0;
  const concepts = data?.concepts ?? [];
  const heatData = data?.activity?.data ?? [];
  const submissions = data?.submissions ?? [];

  // Weakest concept = lowest mastery (= highest difficulty)
  const weakest = concepts.length > 0
    ? [...concepts].sort((a, b) => a.mastery - b.mastery)[0]
    : null;

  return (
    <StudentDashboardShell
      breadcrumb={[
        { label: "Student", href: "/student/dashboard" },
        { label: "Progress" },
      ]}
      subtitle="Mastery, completion, and submissions over the selected window."
      action={
        <div className="flex items-center gap-3">
          <span
            className="inline-flex items-center gap-1.5 text-[10px] font-mono uppercase tracking-wider text-muted-foreground"
          >
            <RefreshCw className={cn('h-3 w-3', refetching && 'animate-spin')} />
            {loading ? 'Loading…' : `${concepts.length} concepts · ${completedEx}/${totalEx} done`}
          </span>
          <PeriodSelector
            value={period}
            onChange={(p) => { setPeriod(p); }}
            options={PERIOD_OPTIONS}
          />
        </div>
      }
    >
      {loading ? (
        <div className="py-12 text-center text-muted-foreground">Loading progress…</div>
      ) : error ? (
        <div className="py-12 text-center text-destructive">{error}</div>
      ) : (
        <>
          {/* ---------- Trajectory / Insight ---------- */}
          <InsightHeader
            eyebrow="Trajectory"
            insight={
              weakest
                ? `${weakest.concept_name} needs attention at ${weakest.mastery}% mastery. Your overall mastery is ${overallMastery}%.`
                : `Your mastery is ${overallMastery}% across ${concepts.length} concept${concepts.length !== 1 ? 's' : ''}.`
            }
            description={
              weakest
                ? `Difficulty score: ${weakest.cds.toFixed(2)} · Targets: ${weakest.concept_name}`
                : `${streak} day streak${streak !== 1 ? 's' : ''} · Avg attempts: ${avgAttempts.toFixed(1)} per exercise`
            }
            action={
              <Button asChild size="sm" className="font-medium">
                <Link to="/student/exercises">
                  Practice weakest concept
                  <ArrowRight className="ml-1.5 h-3.5 w-3.5" strokeWidth={2} />
                </Link>
              </Button>
            }
          />

          {/* ---------- Evidence chips ---------- */}
          <EvidenceRow
            chips={[
              {
                label: "Mastery",
                value: `${overallMastery}%`,
                delta: 0,
                series: [],
                comparison: "concept understanding",
              },
              {
                label: "Completion",
                value: `${completionPct}%`,
                delta: completedEx,
                series: [],
                comparison: `${totalEx} exercises total`,
              },
              {
                label: "Streak",
                value: `${streak}d`,
                delta: 0,
                series: [],
                comparison: "consecutive days",
              },
              {
                label: "Avg Attempts",
                value: avgAttempts.toFixed(1),
                delta: 0,
                series: [],
                comparison: "per exercise",
              },
            ]}
          />

          {/* ---------- Tabs ---------- */}
          <Tabs value={tab} onValueChange={setTab}>
            <TabsList className="inline-flex h-10 items-center gap-0 bg-transparent p-0 border-b border-border rounded-none w-full justify-start">
              <TabsTrigger value="mastery"     className={TRIGGER_BASE}>Mastery</TabsTrigger>
              <TabsTrigger value="activity"    className={TRIGGER_BASE}>Activity</TabsTrigger>
              <TabsTrigger value="submissions" className={TRIGGER_BASE}>Submissions</TabsTrigger>
            </TabsList>

            <TabsContent value="mastery" className="mt-6">
              <MasteryTab concepts={concepts} />
            </TabsContent>
            <TabsContent value="activity" className="mt-6">
              <ActivityTab heatData={heatData} submissions={submissions} />
            </TabsContent>
            <TabsContent value="submissions" className="mt-6">
              <SubmissionsTab submissions={submissions} />
            </TabsContent>
          </Tabs>
        </>
      )}
    </StudentDashboardShell>
  );
}

// ============================================================================
// Mastery tab — radar = mastery footprint (larger = better)
// ============================================================================
function MasteryTab({ concepts }) {
  // Radar plots mastery (100 - CDS), so larger area = better performance.
  // This matches the progress bars where wider = better.
  const radarData = useMemo(
    () => concepts.map((c) => ({ subject: c.concept_code, mastery: c.mastery, name: c.concept_name })),
    [concepts],
  );

  if (concepts.length === 0) {
    return (
      <Card>
        <CardContent className="py-12 text-center text-muted-foreground">
          No concept data yet. Complete some exercises to see your mastery profile.
        </CardContent>
      </Card>
    );
  }

  return (
    <div className="grid gap-6 lg:grid-cols-5">
      <Card className="lg:col-span-3">
        <CardHeader className="pb-3 border-b border-border">
          <div className="space-y-1">
            <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
              Coverage
            </p>
            <CardTitle className="text-sm font-semibold">
              Concept Mastery Footprint · {concepts.length} tracked concepts
            </CardTitle>
          </div>
        </CardHeader>
        <CardContent className="pt-4">
          <div className="h-80 w-full">
            <ResponsiveContainer width="100%" height="100%">
              <RadarChart
                data={radarData}
                margin={{ top: 8, right: 16, bottom: 8, left: 16 }}
              >
                <PolarGrid stroke="hsl(var(--border))" />
                <PolarAngleAxis
                  dataKey="subject"
                  tick={{ fill: "hsl(var(--muted-foreground))", fontSize: 11 }}
                />
                <PolarRadiusAxis
                  domain={[0, 100]}
                  tick={{ fill: "hsl(var(--muted-foreground))", fontSize: 10 }}
                  stroke="hsl(var(--border))"
                />
                <Radar
                  name="Mastery"
                  dataKey="mastery"
                  stroke="hsl(var(--primary))"
                  fill="hsl(var(--primary))"
                  fillOpacity={0.25}
                  strokeWidth={1.5}
                  isAnimationActive={false}
                />
              </RadarChart>
            </ResponsiveContainer>
          </div>
        </CardContent>
      </Card>

      <Card className="lg:col-span-2">
        <CardHeader className="pb-3 border-b border-border">
          <CardTitle className="text-sm font-semibold">Per-Concept Mastery</CardTitle>
        </CardHeader>
        <CardContent className="p-0">
          <ul className="divide-y divide-border">
            {concepts.map((c) => {
              const fillTone = FILL_TONE[c.level] ?? "bg-primary";
              const levelLabel = LEVEL_LABELS[c.level] ?? c.level;
              return (
                <li
                  key={c.concept_code}
                  className="grid grid-cols-[1fr_3.5rem_3rem] items-center gap-3 px-4 py-3"
                >
                  <div className="min-w-0 space-y-1.5">
                    <div className="flex items-center gap-2 min-w-0">
                      <span className="text-sm font-medium truncate">{c.concept_name}</span>
                      <LevelPill level={levelLabel} toneKey={c.level} />
                    </div>
                    <div className="h-1.5 rounded-full bg-muted overflow-hidden">
                      <div
                        className={cn("h-full rounded-full transition-all", fillTone)}
                        style={{ width: `${c.mastery}%` }}
                        aria-hidden="true"
                      />
                    </div>
                  </div>
                  <span className="text-sm font-mono tabular-nums text-right">
                    {c.mastery}%
                  </span>
                  <span
                    className={cn(
                      "inline-flex items-center justify-end gap-1 text-xs font-mono tabular-nums",
                      trendTone(c.delta ?? 0),
                    )}
                  >
                    {trendIcon(c.delta ?? 0)}
                    {(c.delta ?? 0) > 0 ? "+" : ""}
                    {c.delta ?? 0}
                  </span>
                </li>
              );
            })}
          </ul>
        </CardContent>
      </Card>
    </div>
  );
}

function LevelPill({ level, toneKey }) {
  const tone = {
    strong:         "bg-success/10 text-success border border-success/20",
    developing:     "bg-warning/10 text-warning border border-warning/20",
    needs_support:  "bg-destructive/10 text-destructive border border-destructive/20",
  }[toneKey] ?? "bg-muted text-muted-foreground border border-border";
  return (
    <span className={cn("shrink-0 inline-flex items-center rounded-full px-1.5 py-0.5 text-[10px] font-semibold uppercase tracking-wide", tone)}>
      {level}
    </span>
  );
}

// ============================================================================
// Activity tab
// ============================================================================
function ActivityTab({ heatData, submissions }) {
  const HEAT_WEEKS = 12;
  const DAYS = ["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"];

  const flat = heatData.flat();
  const totalSubmissions = flat.reduce((s, v) => s + v, 0);
  const activeDays = flat.filter((v) => v > 0).length;
  const bestDay = flat.length > 0 ? flat.reduce((max, v) => Math.max(max, v), 0) : 0;

  if (totalSubmissions === 0) {
    return (
      <Card>
        <CardContent className="py-12 text-center text-muted-foreground">
          No submission activity yet.
        </CardContent>
      </Card>
    );
  }

  return (
    <div className="space-y-6">
      <Card>
        <CardHeader className="pb-3 border-b border-border">
          <div className="flex flex-col gap-3 sm:flex-row sm:items-end sm:justify-between">
            <div className="space-y-1 min-w-0">
              <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
                Activity
              </p>
              <CardTitle className="text-sm font-semibold">
                Submissions · last 12 weeks
              </CardTitle>
            </div>
            <div className="flex items-center gap-4 text-xs text-muted-foreground font-mono tabular-nums shrink-0">
              <span>
                <span className="text-foreground font-medium">{totalSubmissions}</span> total
              </span>
              <span>
                <span className="text-foreground font-medium">{activeDays}</span>/84 active days
              </span>
              <span>
                <span className="text-foreground font-medium">{bestDay}</span> best day
              </span>
            </div>
          </div>
        </CardHeader>
        <CardContent className="pt-4">
          <div className="overflow-x-auto">
            <div className="inline-flex flex-col gap-1 min-w-full">
              <div className="flex items-end gap-1 pl-9">
                {heatData.map((_, w) => {
                  const showLabel = w === 0 || monthLabel(w) !== monthLabel(w - 1);
                  return (
                    <div
                      key={w}
                      className="w-3.5 text-[10px] font-mono tabular-nums text-muted-foreground"
                    >
                      {showLabel ? monthLabel(w) : ""}
                    </div>
                  );
                })}
              </div>

              {DAYS.map((day, dIdx) => (
                <div
                  key={day}
                  className="grid items-center gap-1"
                  style={{ gridTemplateColumns: "2.25rem repeat(12, minmax(0, 0.875rem))" }}
                >
                  <div className="text-[10px] font-medium text-muted-foreground pr-1">
                    {day}
                  </div>
                  {heatData.map((week, wIdx) => {
                    const density = Math.min(4, week[dIdx] ?? 0);
                    return (
                      <div
                        key={wIdx}
                        className={cn(
                          "h-3.5 w-3.5 rounded-sm border border-border/40",
                          HEAT_TONE[density],
                        )}
                        title={`${day} · week of ${monthLabel(wIdx)} · ${density} submission${density === 1 ? "" : "s"}`}
                        aria-label={`${day} week of ${monthLabel(wIdx)} — ${density} submissions`}
                      />
                    );
                  })}
                </div>
              ))}

              <div className="flex items-center justify-end gap-2 pt-3">
                <span className="text-[10px] uppercase tracking-wider text-muted-foreground">
                  Less
                </span>
                {HEAT_TONE.map((tone, i) => (
                  <div
                    key={i}
                    className={cn("h-3 w-3.5 rounded-sm border border-border/40", tone)}
                  />
                ))}
                <span className="text-[10px] uppercase tracking-wider text-muted-foreground">
                  More
                </span>
              </div>
            </div>
          </div>
        </CardContent>
      </Card>
    </div>
  );
}

// ============================================================================
// Submissions tab
// ============================================================================
function SubmissionsTab({ submissions }) {
  const [sort, setSort] = useState({ key: "submittedAt", dir: "desc" });
  const rows = useMemo(() => applySort(submissions, sort), [submissions, sort]);

  const onSort = (key) => {
    setSort((prev) =>
      prev.key === key
        ? { key, dir: prev.dir === "asc" ? "desc" : "asc" }
        : { key, dir: "asc" },
    );
  };

  if (submissions.length === 0) {
    return (
      <Card>
        <CardContent className="py-12 text-center text-muted-foreground">
          No submissions yet.
        </CardContent>
      </Card>
    );
  }

  return (
    <Card>
      <CardHeader className="pb-3 border-b border-border">
        <div className="flex flex-col gap-1 sm:flex-row sm:items-end sm:justify-between">
          <CardTitle className="text-sm font-semibold">
            Recent submissions · {submissions.length}
          </CardTitle>
          <span className="text-xs text-muted-foreground">
            Sorted by{" "}
            <span className="font-medium text-foreground">{sort.key}</span>{" "}
            ({sort.dir === "asc" ? "ascending" : "descending"})
          </span>
        </div>
      </CardHeader>
      <CardContent className="p-0">
        <SortableTable
          columns={[
            { key: "exercise", label: "Exercise", align: "left"  },
            { key: "concept",  label: "Concept",    align: "left"  },
            { key: "submittedAt", label: "Date",     align: "left"  },
            { key: "score",    label: "Score",    align: "right" },
            { key: "attempts", label: "Attempts", align: "right" },
            { key: "status",   label: "Status",   align: "left"  },
          ]}
          sort={sort}
          onSort={onSort}
          rows={rows}
          renderCell={renderSubmissionCell}
        />
      </CardContent>
    </Card>
  );
}

function renderSubmissionCell(col, row) {
  if (col.key === "exercise") {
    return (
      <Link
        to={`/student/exercises/${row.exerciseId}`}
        className="text-sm font-medium hover:underline underline-offset-2"
      >
        {row.exercise}
      </Link>
    );
  }
  if (col.key === "concept") {
    return <span className="text-sm text-muted-foreground">{row.concept}</span>;
  }
  if (col.key === "submittedAt") {
    return <span className="text-sm text-muted-foreground">{formatTimeAgo(row.submittedAt)}</span>;
  }
  if (col.key === "score") {
    const scorePct = row.score * 100;
    return (
      <span
        className={cn(
          "text-sm font-mono tabular-nums",
          scorePct >= 70 ? "text-success" : scorePct >= 50 ? "text-warning" : "text-destructive",
        )}
      >
        {scorePct.toFixed(0)}%
      </span>
    );
  }
  if (col.key === "attempts") {
    return (
      <span className="text-sm font-mono tabular-nums text-muted-foreground">
        {row.attempts}
      </span>
    );
  }
  if (col.key === "status") {
    return (
      <span
        className={cn(
          "inline-flex items-center rounded-full border px-2 py-0.5 text-[11px] font-semibold",
          row.isCorrect && "border-success/30 bg-success/10 text-success",
          !row.isCorrect && "border-warning/30 bg-warning/10 text-warning",
        )}
      >
        {row.isCorrect ? "Correct" : "Incorrect"}
      </span>
    );
  }
  return null;
}

// ============================================================================
// Shared: SortableTable
// ============================================================================
function applySort(rows, sort) {
  if (!sort.key) return rows;
  const sorted = [...rows].sort((a, b) => {
    const av = a[sort.key];
    const bv = b[sort.key];
    if (typeof av === "number" && typeof bv === "number") {
      return sort.dir === "asc" ? av - bv : bv - av;
    }
    if (av instanceof Date && bv instanceof Date) {
      return sort.dir === "asc" ? av - bv : bv - av;
    }
    return sort.dir === "asc"
      ? String(av).localeCompare(String(bv))
      : String(bv).localeCompare(String(av));
  });
  return sorted;
}

function SortHeader({ label, sortKey, sort, onSort, align = "left" }) {
  const active = sort.key === sortKey;
  const Icon = !active ? ArrowUpDown : sort.dir === "asc" ? ArrowUp : ArrowDown;
  return (
    <button
      type="button"
      onClick={() => onSort(sortKey)}
      className={cn(
        "inline-flex items-center gap-1 text-xs font-medium text-muted-foreground hover:text-foreground transition-colors",
        align === "right" && "ml-auto",
      )}
    >
      {label}
      <Icon className="h-3 w-3" strokeWidth={1.5} />
    </button>
  );
}

function SortableTable({ columns, rows, sort, onSort, renderCell }) {
  return (
    <div className="overflow-x-auto">
      <table className="w-full text-sm">
        <thead>
          <tr className="border-b border-border bg-muted/40">
            {columns.map((col) => (
              <th
                key={col.key}
                className={cn(
                  "h-9 px-3 font-medium",
                  col.align === "right" ? "text-right" : "text-left",
                )}
              >
                <SortHeader
                  label={col.label}
                  sortKey={col.key}
                  sort={sort}
                  onSort={onSort}
                  align={col.align}
                />
              </th>
            ))}
          </tr>
        </thead>
        <tbody className="divide-y divide-border">
          {rows.map((row) => (
            <tr key={row.id} className="hover:bg-muted/30">
              {columns.map((col) => (
                <td
                  key={col.key}
                  className={cn(
                    "px-3 py-2.5",
                    col.align === "right" ? "text-right" : "text-left",
                  )}
                >
                  {renderCell(col, row)}
                </td>
              ))}
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
}
