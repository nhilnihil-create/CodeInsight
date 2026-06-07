import { useState } from "react";
import {
  ResponsiveContainer,
  LineChart,
  Line,
  XAxis,
  YAxis,
  CartesianGrid,
  Tooltip,
  Legend,
  BarChart,
  Bar,
} from "recharts";
import {
  ArrowRight,
  Download,
  ChevronDown,
  ArrowUpDown,
  ArrowUp,
  ArrowDown,
} from "lucide-react";
import { Button } from "@/components/ui/button";
import { Card, CardContent, CardHeader, CardTitle } from "@/components/ui/card";
import { Tabs, TabsList, TabsTrigger, TabsContent } from "@/components/ui/tabs";
import {
  DropdownMenu,
  DropdownMenuContent,
  DropdownMenuItem,
  DropdownMenuTrigger,
} from "@/components/ui/dropdown-menu";
import PageBreadcrumb from "@/components/ui/page-breadcrumb";
import InsightHeader from "@/components/ui/insight-header";
import EvidenceRow from "@/components/ui/evidence-row";
import PeriodSelector from "@/components/ui/period-selector";
import RiskBadge from "@/components/ui/risk-badge";
import { cn } from "@/lib/utils";

/**
 * Reports — 4-tier hierarchy.
 *   1. PageHeader   "Reports" + PeriodSelector + Export ▾
 *   2. Insight      class mastery is up 7% over the last 4 weeks
 *   3. Evidence     4 chips: Mastery / Completion / At Risk / Flags
 *   4. Tabs         Mastery | Completion | Engagement | Integrity
 *      Each tab: h-72 chart + sortable supporting table
 *
 * PeriodSelector drives a local state variable; data is mocked at module
 * scope and does not actually re-filter on change.
 */

const PERIOD_OPTIONS = ["1w", "2w", "4w", "12w"];

const TOOLTIP_STYLE = {
  backgroundColor: "hsl(var(--popover))",
  border: "1px solid hsl(var(--border))",
  borderRadius: "6px",
  fontSize: "12px",
  color: "hsl(var(--popover-foreground))",
};

// ---------- Mastery: 7 concepts × 5 weeks ----------
const MASTERY_WEEKS = ["W-4", "W-3", "W-2", "W-1", "Now"];
const MASTERY_CONCEPTS = [
  { id: "DT",  name: "Datatypes",    series: [78, 80, 81, 83, 85], color: "hsl(var(--primary))" },
  { id: "VR",  name: "Variables",    series: [72, 74, 76, 78, 80], color: "hsl(var(--info))" },
  { id: "CD",  name: "Conditionals", series: [65, 68, 71, 73, 76], color: "hsl(var(--success))" },
  { id: "LP",  name: "Loops",        series: [58, 60, 62, 64, 66], color: "hsl(var(--warning))" },
  { id: "FN",  name: "Functions",    series: [50, 53, 56, 60, 64], color: "hsl(var(--destructive))" },
  { id: "AR",  name: "Arrays",       series: [44, 47, 50, 53, 56], color: "hsl(var(--cds-mod))" },
  { id: "OP",  name: "OOP",          series: [38, 42, 45, 49, 52], color: "hsl(var(--cds-high))" },
];

const MASTERY_TABLE = MASTERY_CONCEPTS
  .map((c) => ({
    id: c.id,
    name: c.name,
    current: c.series[c.series.length - 1],
    delta: c.series[c.series.length - 1] - c.series[0],
  }))
  .sort((a, b) => b.current - a.current);

// ---------- Completion: per-exercise stacked bar ----------
const COMPLETION_DATA = [
  { exercise: "Basic Loops",          on_time: 76, late: 18, missing: 6 },
  { exercise: "Function Calculator",  on_time: 68, late: 22, missing: 10 },
  { exercise: "Array Reversal",       on_time: 54, late: 28, missing: 18 },
  { exercise: "Loops II",             on_time: 48, late: 31, missing: 21 },
  { exercise: "Recursion I",          on_time: 32, late: 38, missing: 30 },
  { exercise: "OOP Basics",           on_time: 41, late: 33, missing: 26 },
];

// ---------- Engagement: 7 days × 8 time bins ----------
const DAYS = ["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"];
const HOUR_BINS = [
  "00–03", "03–06", "06–09", "09–12",
  "12–15", "15–18", "18–21", "21–24",
];
// Density 0–4 per cell, derived from a realistic curve (peak 18–21 weekdays,
// weekend afternoon).
const ENGAGEMENT = [
  // Mon
  [0, 0, 1, 2, 3, 2, 4, 3],
  // Tue
  [0, 0, 1, 2, 3, 3, 4, 3],
  // Wed
  [0, 0, 1, 2, 3, 2, 4, 2],
  // Thu
  [0, 0, 1, 2, 3, 3, 4, 3],
  // Fri
  [0, 0, 1, 2, 3, 3, 3, 2],
  // Sat
  [0, 0, 0, 1, 2, 3, 3, 2],
  // Sun
  [0, 0, 0, 1, 2, 3, 2, 1],
];

const ENGAGEMENT_TABLE = DAYS.map((day, dIdx) => {
  const total = ENGAGEMENT[dIdx].reduce((s, v) => s + v, 0);
  const peakBin = ENGAGEMENT[dIdx].indexOf(Math.max(...ENGAGEMENT[dIdx]));
  return { day, submissions: total * 14, peak: HOUR_BINS[peakBin] };
}).sort((a, b) => b.submissions - a.submissions);

// ---------- Integrity: flags over time + breakdown ----------
const INTEGRITY_TIMELINE = [
  { week: "W-4", critical: 0, high: 2, moderate: 5, low: 11 },
  { week: "W-3", critical: 1, high: 2, moderate: 4, low: 9 },
  { week: "W-2", critical: 0, high: 1, moderate: 3, low: 8 },
  { week: "W-1", critical: 1, high: 1, moderate: 3, low: 7 },
  { week: "Now", critical: 1, high: 1, moderate: 3, low: 7 },
];

const INTEGRITY_BREAKDOWN = [
  { type: "Behavioral Anomaly", level: "critical", count: 2, share: 16, delta: 1 },
  { type: "Hardcoding",         level: "high",     count: 1, share: 8,  delta: 0 },
  { type: "Code Growth Spike",  level: "moderate", count: 4, share: 31, delta: 2 },
  { type: "Output Mismatch",    level: "moderate", count: 3, share: 23, delta: -1 },
  { type: "Off-By-One",         level: "low",      count: 1, share: 8,  delta: 0 },
  { type: "Blank Template",     level: "low",      count: 1, share: 8,  delta: 0 },
  { type: "Passive Behavior",   level: "low",      count: 1, share: 8,  delta: 0 },
];

const RISK_LEVEL = {
  critical: "high",
  high: "high",
  moderate: "moderate",
  low: "low",
};

const HEAT_TONE = [
  "bg-muted/40",
  "bg-primary/15",
  "bg-primary/30",
  "bg-primary/50",
  "bg-primary/75",
];

const TRIGGER_BASE =
  "rounded-none border-b-2 border-transparent data-[state=active]:border-b-foreground data-[state=active]:bg-transparent data-[state=active]:text-foreground data-[state=active]:shadow-none -mb-px px-3";

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
    return sort.dir === "asc"
      ? String(av).localeCompare(String(bv))
      : String(bv).localeCompare(String(av));
  });
  return sorted;
}

export default function InstructorReports() {
  const [period, setPeriod] = useState("4w");
  const [tab, setTab] = useState("mastery");

  return (
    <div className="space-y-6 sm:space-y-8">
      {/* ---------- PageHeader ---------- */}
      <div className="space-y-2">
        <PageBreadcrumb crumbs={[{ label: "Reports" }]} />
        <div className="flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between">
          <div className="min-w-0 space-y-1">
            <h1 className="text-2xl font-semibold tracking-tight">Reports</h1>
            <p className="text-sm text-muted-foreground">
              Class-wide trends and concept-level difficulty across all sections.
            </p>
          </div>
          <div className="flex items-center gap-2 shrink-0">
            <PeriodSelector
              value={period}
              onChange={setPeriod}
              options={PERIOD_OPTIONS}
            />
            <DropdownMenu>
              <DropdownMenuTrigger asChild>
                <Button size="sm" className="font-medium">
                  <Download className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                  Export
                  <ChevronDown className="ml-1.5 h-3.5 w-3.5" strokeWidth={1.5} />
                </Button>
              </DropdownMenuTrigger>
              <DropdownMenuContent align="end" className="w-48">
                <DropdownMenuItem>Export as CSV</DropdownMenuItem>
                <DropdownMenuItem>Export as PDF</DropdownMenuItem>
                <DropdownMenuItem>Copy share link</DropdownMenuItem>
              </DropdownMenuContent>
            </DropdownMenu>
          </div>
        </div>
      </div>

      {/* ---------- Insight ---------- */}
      <InsightHeader
        eyebrow="Headline"
        insight="Class mastery is up 7% over the last 4 weeks."
        description="Driven by Functions (+14%) and OOP (+14%) — Recursion still the highest-CDS concept."
        action={
          <Button size="sm" className="font-medium">
            Export report
            <ArrowRight className="ml-1.5 h-3.5 w-3.5" strokeWidth={2} />
          </Button>
        }
      />

      {/* ---------- Evidence ---------- */}
      <EvidenceRow
        chips={[
          { label: "Mastery",    value: "64%",       delta: 7,    series: [57, 58, 60, 62, 64], comparison: "vs. 4w ago" },
          { label: "Completion", value: "78%",       delta: 3,    series: [75, 76, 77, 77, 78], comparison: "vs. 4w ago" },
          { label: "At Risk",    value: "14%",       delta: -4,   series: [18, 17, 16, 15, 14], comparison: "improving" },
          { label: "Flags",      value: "0.3/student", delta: -0.1, series: [0.4, 0.4, 0.35, 0.32, 0.30], comparison: "vs. 4w ago" },
        ]}
      />

      {/* ---------- Tabs ---------- */}
      <Tabs value={tab} onValueChange={setTab}>
        <TabsList className="inline-flex h-10 items-center gap-0 bg-transparent p-0 border-b border-border rounded-none w-full justify-start">
          <TabsTrigger value="mastery"    className={TRIGGER_BASE}>Mastery</TabsTrigger>
          <TabsTrigger value="completion" className={TRIGGER_BASE}>Completion</TabsTrigger>
          <TabsTrigger value="engagement" className={TRIGGER_BASE}>Engagement</TabsTrigger>
          <TabsTrigger value="integrity"  className={TRIGGER_BASE}>Integrity</TabsTrigger>
        </TabsList>

        <TabsContent value="mastery" className="mt-6">
          <MasteryTab />
        </TabsContent>
        <TabsContent value="completion" className="mt-6">
          <CompletionTab />
        </TabsContent>
        <TabsContent value="engagement" className="mt-6">
          <EngagementTab />
        </TabsContent>
        <TabsContent value="integrity" className="mt-6">
          <IntegrityTab />
        </TabsContent>
      </Tabs>
    </div>
  );
}

// ============================================================================
// Mastery tab
// ============================================================================
function MasteryTab() {
  const { sort, onSort } = useSort({ key: "current", dir: "desc" });
  const rows = applySort(MASTERY_TABLE, sort);

  // recharts wants per-week rows with one key per series
  const data = MASTERY_WEEKS.map((week, i) => {
    const row = { week };
    for (const c of MASTERY_CONCEPTS) {
      row[c.id] = c.series[i];
    }
    return row;
  });

  return (
    <div className="space-y-6">
      <Card>
        <CardHeader className="pb-3 border-b border-border">
          <div className="space-y-1">
            <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
              Trend
            </p>
            <CardTitle className="text-sm font-semibold">
              Concept mastery · 4-week rolling
            </CardTitle>
          </div>
        </CardHeader>
        <CardContent className="pt-4">
          <div className="h-72 w-full">
            <ResponsiveContainer width="100%" height="100%">
              <LineChart data={data} margin={{ top: 8, right: 12, bottom: 0, left: -8 }}>
                <CartesianGrid
                  stroke="hsl(var(--border))"
                  strokeDasharray="3 3"
                  vertical={false}
                />
                <XAxis
                  dataKey="week"
                  tick={{ fill: "hsl(var(--muted-foreground))", fontSize: 11 }}
                  axisLine={{ stroke: "hsl(var(--border))" }}
                  tickLine={false}
                />
                <YAxis
                  domain={[0, 100]}
                  tick={{ fill: "hsl(var(--muted-foreground))", fontSize: 11 }}
                  axisLine={false}
                  tickLine={false}
                  width={40}
                />
                <Tooltip contentStyle={TOOLTIP_STYLE} cursor={{ stroke: "hsl(var(--muted))" }} />
                <Legend
                  wrapperStyle={{ fontSize: "11px", paddingTop: "8px" }}
                  iconType="circle"
                  iconSize={8}
                />
                {MASTERY_CONCEPTS.map((c) => (
                  <Line
                    key={c.id}
                    type="monotone"
                    dataKey={c.id}
                    name={c.name}
                    stroke={c.color}
                    strokeWidth={1.5}
                    dot={false}
                    isAnimationActive={false}
                  />
                ))}
              </LineChart>
            </ResponsiveContainer>
          </div>
        </CardContent>
      </Card>

      <Card>
        <CardHeader className="pb-3 border-b border-border">
          <CardTitle className="text-sm font-semibold">Concepts · current vs. 4w ago</CardTitle>
        </CardHeader>
        <CardContent className="p-0">
          <SortableTable
            columns={[
              { key: "name",    label: "Concept", align: "left"  },
              { key: "current", label: "Current", align: "right" },
              { key: "delta",   label: "Δ",       align: "right" },
            ]}
            sort={sort}
            onSort={onSort}
            rows={rows}
            renderCell={(col, row) => {
              if (col.key === "name") {
                return <span className="text-sm font-medium">{row.name}</span>;
              }
              if (col.key === "current") {
                return (
                  <span className="text-sm font-mono tabular-nums">{row.current}%</span>
                );
              }
              if (col.key === "delta") {
                const positive = row.delta > 0;
                return (
                  <span
                    className={cn(
                      "text-xs font-mono tabular-nums",
                      positive ? "text-success" : row.delta < 0 ? "text-destructive" : "text-muted-foreground",
                    )}
                  >
                    {positive ? "+" : ""}
                    {row.delta}
                  </span>
                );
              }
              return null;
            }}
          />
        </CardContent>
      </Card>
    </div>
  );
}

// ============================================================================
// Completion tab
// ============================================================================
function CompletionTab() {
  const { sort, onSort } = useSort({ key: "on_time", dir: "desc" });
  const rows = applySort(COMPLETION_DATA, sort);

  return (
    <div className="space-y-6">
      <Card>
        <CardHeader className="pb-3 border-b border-border">
          <div className="space-y-1">
            <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
              Composition
            </p>
            <CardTitle className="text-sm font-semibold">
              Submission status · per exercise
            </CardTitle>
          </div>
        </CardHeader>
        <CardContent className="pt-4">
          <div className="h-72 w-full">
            <ResponsiveContainer width="100%" height="100%">
              <BarChart
                data={COMPLETION_DATA}
                margin={{ top: 8, right: 12, bottom: 0, left: -8 }}
                barCategoryGap={6}
              >
                <CartesianGrid
                  stroke="hsl(var(--border))"
                  strokeDasharray="3 3"
                  vertical={false}
                />
                <XAxis
                  dataKey="exercise"
                  tick={{ fill: "hsl(var(--muted-foreground))", fontSize: 10 }}
                  axisLine={{ stroke: "hsl(var(--border))" }}
                  tickLine={false}
                  interval={0}
                  angle={-20}
                  textAnchor="end"
                  height={56}
                />
                <YAxis
                  tick={{ fill: "hsl(var(--muted-foreground))", fontSize: 11 }}
                  axisLine={false}
                  tickLine={false}
                  width={32}
                  tickFormatter={(v) => `${v}%`}
                />
                <Tooltip contentStyle={TOOLTIP_STYLE} cursor={{ fill: "hsl(var(--muted) / 0.4)" }} />
                <Legend
                  wrapperStyle={{ fontSize: "11px", paddingTop: "8px" }}
                  iconType="circle"
                  iconSize={8}
                />
                <Bar
                  dataKey="on_time"
                  name="On time"
                  stackId="status"
                  fill="hsl(var(--success))"
                  isAnimationActive={false}
                />
                <Bar
                  dataKey="late"
                  name="Late"
                  stackId="status"
                  fill="hsl(var(--warning))"
                  isAnimationActive={false}
                />
                <Bar
                  dataKey="missing"
                  name="Missing"
                  stackId="status"
                  fill="hsl(var(--destructive))"
                  isAnimationActive={false}
                />
              </BarChart>
            </ResponsiveContainer>
          </div>
        </CardContent>
      </Card>

      <Card>
        <CardHeader className="pb-3 border-b border-border">
          <CardTitle className="text-sm font-semibold">Exercises · completion breakdown</CardTitle>
        </CardHeader>
        <CardContent className="p-0">
          <SortableTable
            columns={[
              { key: "exercise", label: "Exercise", align: "left"  },
              { key: "on_time",  label: "On time",  align: "right" },
              { key: "late",     label: "Late",     align: "right" },
              { key: "missing",  label: "Missing",  align: "right" },
            ]}
            sort={sort}
            onSort={onSort}
            rows={rows}
            renderCell={(col, row) => {
              if (col.key === "exercise") {
                return <span className="text-sm font-medium">{row.exercise}</span>;
              }
              return (
                <span className="text-sm font-mono tabular-nums">{row[col.key]}%</span>
              );
            }}
          />
        </CardContent>
      </Card>
    </div>
  );
}

// ============================================================================
// Engagement tab
// ============================================================================
function EngagementTab() {
  const { sort, onSort } = useSort({ key: "submissions", dir: "desc" });
  const rows = applySort(ENGAGEMENT_TABLE, sort);

  return (
    <div className="space-y-6">
      <Card>
        <CardHeader className="pb-3 border-b border-border">
          <div className="space-y-1">
            <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
              Heatmap
            </p>
            <CardTitle className="text-sm font-semibold">
              Submission density · day × hour
            </CardTitle>
          </div>
        </CardHeader>
        <CardContent className="pt-4">
          <div className="overflow-x-auto">
            <div className="inline-flex flex-col gap-1 min-w-full">
              {/* Hour axis */}
              <div className="grid" style={{ gridTemplateColumns: "3rem repeat(8, minmax(0, 1fr))" }}>
                <div />
                {HOUR_BINS.map((bin) => (
                  <div
                    key={bin}
                    className="text-[10px] font-mono tabular-nums text-muted-foreground text-center px-1"
                  >
                    {bin}
                  </div>
                ))}
              </div>
              {DAYS.map((day, dIdx) => (
                <div
                  key={day}
                  className="grid items-center"
                  style={{ gridTemplateColumns: "3rem repeat(8, minmax(0, 1fr))" }}
                >
                  <div className="text-xs font-medium text-muted-foreground pr-2">
                    {day}
                  </div>
                  {ENGAGEMENT[dIdx].map((density, hIdx) => (
                    <div
                      key={hIdx}
                      className={cn(
                        "h-7 rounded-sm border border-border/40",
                        HEAT_TONE[density],
                      )}
                      title={`${day} · ${HOUR_BINS[hIdx]} · ${density * 14} submissions`}
                      aria-label={`${day} ${HOUR_BINS[hIdx]} — ${density * 14} submissions`}
                    />
                  ))}
                </div>
              ))}
              <div className="flex items-center justify-end gap-2 pt-3">
                <span className="text-[10px] uppercase tracking-wider text-muted-foreground">
                  Less
                </span>
                {HEAT_TONE.map((tone, i) => (
                  <div
                    key={i}
                    className={cn("h-3 w-5 rounded-sm border border-border/40", tone)}
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

      <Card>
        <CardHeader className="pb-3 border-b border-border">
          <CardTitle className="text-sm font-semibold">Days · ranked by submissions</CardTitle>
        </CardHeader>
        <CardContent className="p-0">
          <SortableTable
            columns={[
              { key: "day",         label: "Day",         align: "left"  },
              { key: "submissions", label: "Submissions", align: "right" },
              { key: "peak",        label: "Peak hour",   align: "left"  },
            ]}
            sort={sort}
            onSort={onSort}
            rows={rows}
            renderCell={(col, row) => {
              if (col.key === "day") {
                return <span className="text-sm font-medium">{row.day}</span>;
              }
              if (col.key === "submissions") {
                return (
                  <span className="text-sm font-mono tabular-nums">{row.submissions}</span>
                );
              }
              return (
                <span className="text-sm text-muted-foreground font-mono tabular-nums">
                  {row.peak}
                </span>
              );
            }}
          />
        </CardContent>
      </Card>
    </div>
  );
}

// ============================================================================
// Integrity tab
// ============================================================================
function IntegrityTab() {
  const { sort, onSort } = useSort({ key: "count", dir: "desc" });
  const rows = applySort(INTEGRITY_BREAKDOWN, sort);

  return (
    <div className="space-y-6">
      <Card>
        <CardHeader className="pb-3 border-b border-border">
          <div className="space-y-1">
            <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
              Trend
            </p>
            <CardTitle className="text-sm font-semibold">
              Integrity flags · 4-week rolling
            </CardTitle>
          </div>
        </CardHeader>
        <CardContent className="pt-4">
          <div className="h-72 w-full">
            <ResponsiveContainer width="100%" height="100%">
              <LineChart
                data={INTEGRITY_TIMELINE}
                margin={{ top: 8, right: 12, bottom: 0, left: -8 }}
              >
                <CartesianGrid
                  stroke="hsl(var(--border))"
                  strokeDasharray="3 3"
                  vertical={false}
                />
                <XAxis
                  dataKey="week"
                  tick={{ fill: "hsl(var(--muted-foreground))", fontSize: 11 }}
                  axisLine={{ stroke: "hsl(var(--border))" }}
                  tickLine={false}
                />
                <YAxis
                  allowDecimals={false}
                  tick={{ fill: "hsl(var(--muted-foreground))", fontSize: 11 }}
                  axisLine={false}
                  tickLine={false}
                  width={32}
                />
                <Tooltip contentStyle={TOOLTIP_STYLE} cursor={{ stroke: "hsl(var(--muted))" }} />
                <Legend
                  wrapperStyle={{ fontSize: "11px", paddingTop: "8px" }}
                  iconType="circle"
                  iconSize={8}
                />
                <Line
                  type="monotone"
                  dataKey="critical"
                  name="Critical"
                  stroke="hsl(var(--destructive))"
                  strokeWidth={2}
                  dot={false}
                  isAnimationActive={false}
                />
                <Line
                  type="monotone"
                  dataKey="high"
                  name="High"
                  stroke="hsl(var(--cds-high))"
                  strokeWidth={2}
                  dot={false}
                  isAnimationActive={false}
                />
                <Line
                  type="monotone"
                  dataKey="moderate"
                  name="Moderate"
                  stroke="hsl(var(--cds-mod))"
                  strokeWidth={2}
                  dot={false}
                  isAnimationActive={false}
                />
                <Line
                  type="monotone"
                  dataKey="low"
                  name="Low"
                  stroke="hsl(var(--cds-low))"
                  strokeWidth={2}
                  dot={false}
                  isAnimationActive={false}
                />
              </LineChart>
            </ResponsiveContainer>
          </div>
        </CardContent>
      </Card>

      <Card>
        <CardHeader className="pb-3 border-b border-border">
          <CardTitle className="text-sm font-semibold">Flag breakdown</CardTitle>
        </CardHeader>
        <CardContent className="p-0">
          <SortableTable
            columns={[
              { key: "type",   label: "Type",   align: "left"  },
              { key: "level",  label: "Level",  align: "left"  },
              { key: "count",  label: "Count",  align: "right" },
              { key: "share",  label: "Share",  align: "right" },
              { key: "delta",  label: "Δ",      align: "right" },
            ]}
            sort={sort}
            onSort={onSort}
            rows={rows}
            renderCell={(col, row) => {
              if (col.key === "type") {
                return <span className="text-sm font-medium">{row.type}</span>;
              }
              if (col.key === "level") {
                return <RiskBadge level={RISK_LEVEL[row.level]} />;
              }
              if (col.key === "count") {
                return (
                  <span className="text-sm font-mono tabular-nums">{row.count}</span>
                );
              }
              if (col.key === "share") {
                return (
                  <span className="text-sm text-muted-foreground font-mono tabular-nums">
                    {row.share}%
                  </span>
                );
              }
              if (col.key === "delta") {
                const positive = row.delta > 0;
                return (
                  <span
                    className={cn(
                      "text-xs font-mono tabular-nums",
                      positive
                        ? "text-destructive"
                        : row.delta < 0
                          ? "text-success"
                          : "text-muted-foreground",
                    )}
                  >
                    {positive ? "+" : ""}
                    {row.delta}
                  </span>
                );
              }
              return null;
            }}
          />
        </CardContent>
      </Card>
    </div>
  );
}

// ============================================================================
// Shared: SortableTable
// ============================================================================
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
            <tr key={row.id ?? row.day ?? row.exercise ?? row.type} className="hover:bg-muted/30">
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
