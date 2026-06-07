import { useMemo, useState } from "react";
import { Link } from "react-router-dom";
import { useQuery } from "@tanstack/react-query";
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

/**
 * Student Progress — 4-tier hierarchy.
 *   1. PageHeader   "Progress" + PeriodSelector (default 30d)
 *   2. Insight      mastery grew 12% in the last 30 days (64% → 76%)
 *   3. Evidence     4 chips: Mastery / Streak / Exercises / Avg Attempts
 *   4. Tabs         Mastery | Activity | Submissions
 *      Mastery      RadarChart (7 concepts) + per-concept progress list
 *      Activity     12-week × 7-day contribution heatmap (success / muted)
 *      Submissions  Sortable table: exercise / date / score / attempts / status
 *
 * Data is mocked at module scope; the prior /api/analytics/my-scores poll
 * is preserved as a follow-up wiring target (see CLAUDE.md).
 */

const PERIOD_OPTIONS = ["7d", "30d", "90d", "All"];

const CONCEPTS = [
  { id: "DT", name: "Datatypes",    current: 88, delta: 6,  level: "high" },
  { id: "VR", name: "Variables",    current: 84, delta: 4,  level: "high" },
  { id: "CD", name: "Conditionals", current: 78, delta: 8,  level: "high" },
  { id: "LP", name: "Loops",        current: 74, delta: 5,  level: "moderate" },
  { id: "FN", name: "Functions",    current: 80, delta: 18, level: "high" },
  { id: "AR", name: "Arrays",       current: 68, delta: 11, level: "moderate" },
  { id: "OP", name: "OOP",          current: 62, delta: 9,  level: "moderate" },
];

const WEAKEST = [...CONCEPTS].sort((a, b) => a.current - b.current)[0];

const HEAT_WEEKS = 12;
const DAYS = ["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"];

// 12 weeks × 7 days, density 0–4. Realistic curve: weekdays busier than
// weekends, ramp up over the 12-week window.
const HEATMAP = (() => {
  const rows = [];
  for (let w = 0; w < HEAT_WEEKS; w++) {
    const row = [];
    for (let d = 0; d < 7; d++) {
      const weekend = d >= 5;
      const ramp = 0.6 + w * 0.04;
      const base = weekend ? 0.6 : 2.4;
      const noise = ((w * 7 + d) % 3) - 1;
      const v = Math.max(0, Math.min(4, Math.round((base + noise) * ramp) - (weekend ? 2 : 0)));
      row.push(v);
    }
    rows.push(row);
  }
  return rows;
})();

const SUBMISSIONS = [
  { id: "s01", exercise: "Recursion Warmup",   date: "Today, 2:14 PM",  score: 0.92, attempts: 2, status: "Submitted" },
  { id: "s02", exercise: "Functions II",       date: "Yesterday",      score: 0.78, attempts: 1, status: "Submitted" },
  { id: "s03", exercise: "Array Filter",       date: "2 days ago",     score: 0.84, attempts: 3, status: "Resubmitted" },
  { id: "s04", exercise: "Loops Practice",     date: "3 days ago",     score: 0.66, attempts: 2, status: "Submitted" },
  { id: "s05", exercise: "Conditionals Quiz",  date: "5 days ago",     score: 0.71, attempts: 1, status: "Submitted" },
  { id: "s06", exercise: "Variables Refresher",date: "1 week ago",     score: 0.58, attempts: 4, status: "Late" },
  { id: "s07", exercise: "Datatypes Intro",    date: "1 week ago",     score: 0.95, attempts: 1, status: "Submitted" },
  { id: "s08", exercise: "Recursion I",        date: "2 weeks ago",    score: 0.42, attempts: 5, status: "Resubmitted" },
  { id: "s09", exercise: "Function Calculator",date: "2 weeks ago",    score: 0.74, attempts: 2, status: "Submitted" },
  { id: "s10", exercise: "Array Reversal",     date: "3 weeks ago",    score: 0.68, attempts: 3, status: "Submitted" },
];

const STATUS_VARIANT = {
  Submitted:   "secondary",
  Resubmitted: "default",
  Late:        "warning",
};

const FILL_TONE = {
  high:     "bg-success",
  moderate: "bg-warning",
  low:      "bg-destructive",
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
  // Anchor: today is 2026-06-06 (Saturday). 12 weeks back → 2026-03-14 (Sat).
  const today = new Date(2026, 5, 6);
  const start = new Date(today);
  start.setDate(today.getDate() - (HEAT_WEEKS - 1 - weekIdx) * 7);
  return start.toLocaleDateString("en-US", { month: "short" });
}

export default function StudentProgress() {
  const [period, setPeriod] = useState("30d");
  const [tab, setTab] = useState("mastery");

  // Poll real CDS scores every 30s so the page reflects fresh submissions
  // and any batch CDS computation that runs after exercise close.
  const scoresQuery = useQuery({
    queryKey: ['my-scores'],
    queryFn: async () => {
      const r = await api.get('/api/analytics/my-scores');
      return Array.isArray(r.data) ? r.data : [];
    },
    refetchInterval: 30_000,
    refetchOnWindowFocus: true,
  });
  const liveScores = scoresQuery.data || [];
  const liveAvg = liveScores.length
    ? liveScores.reduce((s, x) => s + (x.cds || 0), 0) / liveScores.length
    : null;

  return (
    <StudentDashboardShell
      breadcrumb={[
        { label: "Student", href: "/student/dashboard" },
        { label: "Progress" },
      ]}
      subtitle="Mastery, activity, and submissions over the selected window."
      action={
        <div className="flex items-center gap-3">
          <span
            className="inline-flex items-center gap-1.5 text-[10px] font-mono uppercase tracking-wider text-muted-foreground"
            title={scoresQuery.isFetching ? 'Refreshing…' : `Updated ${scoresQuery.dataUpdatedAt ? new Date(scoresQuery.dataUpdatedAt).toLocaleTimeString() : '—'}`}
          >
            <RefreshCw className={cn('h-3 w-3', scoresQuery.isFetching && 'animate-spin')} />
            Live · {liveScores.length} CDS
          </span>
          <PeriodSelector
            value={period}
            onChange={setPeriod}
            options={PERIOD_OPTIONS}
          />
        </div>
      }
    >
      {/* ---------- Insight ---------- */}
      <InsightHeader
        eyebrow="Trajectory"
        insight={liveAvg != null
          ? `Live average CDS: ${(liveAvg * 100).toFixed(0)}% across ${liveScores.length} scored exercise${liveScores.length === 1 ? '' : 's'}.`
          : "Your mastery grew 12% in the last 30 days (64% → 76%)."}
        description={liveAvg != null
          ? 'Polled every 30s from /api/analytics/my-scores — reflects latest submissions and batch CDS.'
          : "Functions is your biggest mover at +18%. Keep the streak alive — 5 days and counting."}
        action={
          <Button asChild size="sm" className="font-medium">
            <Link to="/student/exercises">
              Practice weakest concept
              <ArrowRight className="ml-1.5 h-3.5 w-3.5" strokeWidth={2} />
            </Link>
          </Button>
        }
      />

      {/* ---------- Evidence ---------- */}
      <EvidenceRow
        chips={[
          { label: "Mastery",      value: "76%",     delta: 12,    series: [64, 66, 68, 70, 72, 74, 76], comparison: "this window" },
          { label: "Streak",       value: "5d",      delta: 1,     series: [2, 3, 3, 4, 5],                 comparison: "personal best" },
          { label: "Exercises",    value: "24/30",   delta: 5,     series: [19, 20, 21, 22, 23, 24],        comparison: "completed" },
          { label: "Avg Attempts", value: "2.3",     delta: -0.3,  series: [2.6, 2.5, 2.4, 2.3, 2.3],       comparison: "fewer than class" },
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
          <MasteryTab />
        </TabsContent>
        <TabsContent value="activity" className="mt-6">
          <ActivityTab />
        </TabsContent>
        <TabsContent value="submissions" className="mt-6">
          <SubmissionsTab />
        </TabsContent>
      </Tabs>
    </StudentDashboardShell>
  );
}

// ============================================================================
// Mastery tab
// ============================================================================
function MasteryTab() {
  const radarData = useMemo(
    () => CONCEPTS.map((c) => ({ subject: c.name, mastery: c.current })),
    [],
  );

  return (
    <div className="grid gap-6 lg:grid-cols-5">
      <Card className="lg:col-span-3">
        <CardHeader className="pb-3 border-b border-border">
          <div className="space-y-1">
            <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
              Coverage
            </p>
            <CardTitle className="text-sm font-semibold">
              Concept mastery · 7 tracked concepts
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
          <CardTitle className="text-sm font-semibold">Per-concept progress</CardTitle>
        </CardHeader>
        <CardContent className="p-0">
          <ul className="divide-y divide-border">
            {CONCEPTS.map((c) => {
              const fillTone = FILL_TONE[c.level] ?? "bg-primary";
              return (
                <li
                  key={c.id}
                  className="grid grid-cols-[1fr_3.5rem_3rem] items-center gap-3 px-4 py-3"
                >
                  <div className="min-w-0 space-y-1.5">
                    <div className="flex items-center gap-2 min-w-0">
                      <span className="text-sm font-medium truncate">{c.name}</span>
                      <LevelPill level={c.level} />
                    </div>
                    <div className="h-1.5 rounded-full bg-muted overflow-hidden">
                      <div
                        className={cn("h-full rounded-full transition-all", fillTone)}
                        style={{ width: `${c.current}%` }}
                        aria-hidden="true"
                      />
                    </div>
                  </div>
                  <span className="text-sm font-mono tabular-nums text-right">
                    {c.current}%
                  </span>
                  <span
                    className={cn(
                      "inline-flex items-center justify-end gap-1 text-xs font-mono tabular-nums",
                      trendTone(c.delta),
                    )}
                  >
                    {trendIcon(c.delta)}
                    {c.delta > 0 ? "+" : ""}
                    {c.delta}
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

function LevelPill({ level }) {
  const tone = {
    high:     "bg-success/10 text-success border border-success/20",
    moderate: "bg-warning/10 text-warning border border-warning/20",
    low:      "bg-destructive/10 text-destructive border border-destructive/20",
  }[level] ?? "bg-muted text-muted-foreground border border-border";
  return (
    <span className={cn("shrink-0 inline-flex items-center rounded-full px-1.5 py-0.5 text-[10px] font-semibold uppercase tracking-wide", tone)}>
      {level}
    </span>
  );
}

// ============================================================================
// Activity tab
// ============================================================================
function ActivityTab() {
  const totalSubmissions = HEATMAP.flat().reduce((s, v) => s + v, 0);
  const activeDays = HEATMAP.flat().filter((v) => v > 0).length;
  const bestDay = HEATMAP.flat().reduce((max, v) => Math.max(max, v), 0);

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
              {/* Month axis */}
              <div className="flex items-end gap-1 pl-9">
                {HEATMAP.map((_, w) => {
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
                  {HEATMAP.map((week, wIdx) => {
                    const density = week[dIdx];
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
function SubmissionsTab() {
  const { sort, onSort } = useSort({ key: "date", dir: "desc" });
  const rows = applySort(SUBMISSIONS, sort);

  return (
    <Card>
      <CardHeader className="pb-3 border-b border-border">
        <div className="flex flex-col gap-1 sm:flex-row sm:items-end sm:justify-between">
          <CardTitle className="text-sm font-semibold">
            Recent submissions · {SUBMISSIONS.length}
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
            { key: "date",     label: "Date",     align: "left"  },
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
        to={`/student/exercises/${row.id}`}
        className="text-sm font-medium hover:underline underline-offset-2"
      >
        {row.exercise}
      </Link>
    );
  }
  if (col.key === "date") {
    return <span className="text-sm text-muted-foreground">{row.date}</span>;
  }
  if (col.key === "score") {
    return (
      <span
        className={cn(
          "text-sm font-mono tabular-nums",
          row.score >= 0.7 ? "text-success" : row.score >= 0.5 ? "text-warning" : "text-destructive",
        )}
      >
        {(row.score * 100).toFixed(0)}%
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
          row.status === "Submitted" && "border-border bg-muted text-muted-foreground",
          row.status === "Resubmitted" && "border-primary/30 bg-primary/10 text-primary",
          row.status === "Late" && "border-warning/30 bg-warning/10 text-warning",
        )}
      >
        {row.status}
      </span>
    );
  }
  return null;
}

// ============================================================================
// Shared: SortableTable (re-declared locally to keep this file standalone)
// ============================================================================
function useSort(initial) {
  const [sort, setSort] = useState(initial);
  const onSort = (key) => {
    setSort((prev) =>
      prev.key === key
        ? { key, dir: prev.dir === "asc" ? "desc" : "asc" }
        : { key, dir: "asc" },
    );
  };
  return { sort, onSort };
}

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
