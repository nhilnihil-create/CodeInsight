import { useState } from "react";
import { Link } from "react-router-dom";
import {
  Download,
  ArrowRight,
} from "lucide-react";
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
  Card,
  CardContent,
  CardHeader,
  CardTitle,
} from "@/components/ui/card";
import { Button } from "@/components/ui/button";
import InsightHeader from "@/components/ui/insight-header";
import EvidenceRow from "@/components/ui/evidence-row";
import PageBreadcrumb from "@/components/ui/page-breadcrumb";
import PeriodSelector from "@/components/ui/period-selector";
import RiskBadge from "@/components/ui/risk-badge";

const TREND_DATA = [
  { date: "Mon", cds: 0.48, mastery: 60, engagement: 72 },
  { date: "Tue", cds: 0.47, mastery: 61, engagement: 75 },
  { date: "Wed", cds: 0.45, mastery: 61, engagement: 71 },
  { date: "Thu", cds: 0.46, mastery: 62, engagement: 78 },
  { date: "Fri", cds: 0.44, mastery: 63, engagement: 76 },
  { date: "Sat", cds: 0.43, mastery: 63, engagement: 68 },
  { date: "Sun", cds: 0.42, mastery: 64, engagement: 70 },
];

const STRUGGLING_CONCEPTS = [
  { name: "Recursion", cds: 78 },
  { name: "Dynamic Programming", cds: 72 },
  { name: "Graphs", cds: 65 },
  { name: "Hashing", cds: 58 },
  { name: "Trees", cds: 52 },
];

const RECENT_FLAGS = [
  { id: 1, title: "A. Khan", subtitle: "Hardcode detected", meta: "Ex.4 · 2h", level: "high" },
  { id: 2, title: "B. Reyes", subtitle: "Paste from URL", meta: "Ex.7 · 5h", level: "high" },
  { id: 3, title: "C. Park", subtitle: "Behavioral anomaly", meta: "Ex.3 · 1d", level: "moderate" },
  { id: 4, title: "D. Lopez", subtitle: "Blank template", meta: "Ex.5 · 1d", level: "moderate" },
  { id: 5, title: "E. Chen", subtitle: "Hardcode detected", meta: "Ex.2 · 2d", level: "low" },
];

const TOOLTIP_STYLE = {
  backgroundColor: "hsl(var(--popover))",
  border: "1px solid hsl(var(--border))",
  borderRadius: "6px",
  fontSize: "12px",
  color: "hsl(var(--popover-foreground))",
};

export default function InstructorDashboard() {
  const [period, setPeriod] = useState("7d");

  return (
    <div className="space-y-6 sm:space-y-8">
      {/* ---------- PageHeader ---------- */}
      <div className="flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between">
        <div className="min-w-0 space-y-2">
          <PageBreadcrumb crumbs={[{ label: "Class Status" }]} />
          <div>
            <h1 className="text-2xl font-semibold tracking-tight">Class Status</h1>
            <p className="text-sm text-muted-foreground mt-1">
              Aggregated metrics for all sections, updated live.
            </p>
          </div>
        </div>
        <div className="flex items-center gap-2 shrink-0">
          <PeriodSelector value={period} onChange={setPeriod} />
          <Button variant="ghost" size="sm" className="font-medium">
            <Download className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
            Export
          </Button>
        </div>
      </div>

      {/* ---------- Insight ---------- */}
      <InsightHeader
        insight="3 students are at high risk of failing this week."
        action={
          <Button asChild size="sm" className="font-medium">
            <Link to="/instructor/integrity">
              Open intervention queue
              <ArrowRight className="ml-1.5 h-3.5 w-3.5" strokeWidth={2} />
            </Link>
          </Button>
        }
      />

      {/* ---------- Evidence ---------- */}
      <EvidenceRow
        chips={[
          {
            label: "At risk",
            value: 3,
            delta: 2,
            series: [1, 1, 2, 2, 2, 3, 3],
            comparison: "vs. last week",
          },
          {
            label: "Avg CDS",
            value: "0.42",
            delta: -0.06,
            series: [0.48, 0.47, 0.45, 0.46, 0.44, 0.43, 0.42],
            comparison: "improving",
          },
          {
            label: "Mastery",
            value: "64%",
            delta: 2,
            series: [60, 61, 61, 62, 63, 63, 64],
            comparison: "this week",
          },
          {
            label: "Flags",
            value: 7,
            delta: 3,
            series: [4, 4, 5, 5, 6, 6, 7],
            comparison: "last 24h",
          },
        ]}
      />

      {/* ---------- Class trend ---------- */}
      <Card>
        <CardHeader className="flex flex-row items-center justify-between space-y-0 pb-3 border-b border-border">
          <div className="space-y-1">
            <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
              Details
            </p>
            <CardTitle className="text-sm font-semibold">Class trend</CardTitle>
          </div>
          <PeriodSelector
            value={period}
            onChange={setPeriod}
            options={["7d", "30d", "90d"]}
          />
        </CardHeader>
        <CardContent className="pt-4">
          <div className="h-64 w-full">
            <ResponsiveContainer width="100%" height="100%">
              <LineChart
                data={TREND_DATA}
                margin={{ top: 8, right: 12, bottom: 0, left: -8 }}
              >
                <CartesianGrid
                  stroke="hsl(var(--border))"
                  strokeDasharray="3 3"
                  vertical={false}
                />
                <XAxis
                  dataKey="date"
                  tick={{ fill: "hsl(var(--muted-foreground))", fontSize: 11 }}
                  axisLine={{ stroke: "hsl(var(--border))" }}
                  tickLine={false}
                />
                <YAxis
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
                <Line
                  type="monotone"
                  dataKey="cds"
                  name="CDS"
                  stroke="hsl(var(--destructive))"
                  strokeWidth={2}
                  dot={false}
                  isAnimationActive={false}
                />
                <Line
                  type="monotone"
                  dataKey="mastery"
                  name="Mastery"
                  stroke="hsl(var(--success))"
                  strokeWidth={2}
                  dot={false}
                  isAnimationActive={false}
                />
                <Line
                  type="monotone"
                  dataKey="engagement"
                  name="Engagement"
                  stroke="hsl(var(--info))"
                  strokeWidth={2}
                  dot={false}
                  isAnimationActive={false}
                />
              </LineChart>
            </ResponsiveContainer>
          </div>
        </CardContent>
      </Card>

      {/* ---------- Details grid ---------- */}
      <div className="grid gap-6 md:grid-cols-2">
        <Card>
          <CardHeader className="pb-3 border-b border-border">
            <div className="space-y-1">
              <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
                Details
              </p>
              <CardTitle className="text-sm font-semibold">
                Top struggling concepts
              </CardTitle>
            </div>
          </CardHeader>
          <CardContent className="pt-4">
            <div className="h-64 w-full">
              <ResponsiveContainer width="100%" height="100%">
                <BarChart
                  data={STRUGGLING_CONCEPTS}
                  layout="vertical"
                  margin={{ top: 4, right: 16, bottom: 0, left: 0 }}
                  barCategoryGap={6}
                >
                  <CartesianGrid
                    stroke="hsl(var(--border))"
                    strokeDasharray="3 3"
                    horizontal={false}
                  />
                  <XAxis
                    type="number"
                    domain={[0, 100]}
                    tick={{ fill: "hsl(var(--muted-foreground))", fontSize: 11 }}
                    axisLine={{ stroke: "hsl(var(--border))" }}
                    tickLine={false}
                  />
                  <YAxis
                    type="category"
                    dataKey="name"
                    tick={{ fill: "hsl(var(--muted-foreground))", fontSize: 11 }}
                    axisLine={false}
                    tickLine={false}
                    width={130}
                  />
                  <Tooltip contentStyle={TOOLTIP_STYLE} cursor={{ fill: "hsl(var(--muted) / 0.4)" }} />
                  <Bar
                    dataKey="cds"
                    name="CDS"
                    fill="hsl(var(--destructive))"
                    radius={[0, 4, 4, 0]}
                    isAnimationActive={false}
                  />
                </BarChart>
              </ResponsiveContainer>
            </div>
          </CardContent>
        </Card>

        <Card>
          <CardHeader className="flex flex-row items-center justify-between space-y-0 pb-3 border-b border-border">
            <div className="space-y-1">
              <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
                Details
              </p>
              <CardTitle className="text-sm font-semibold">
                Recent integrity flags
              </CardTitle>
            </div>
            <Button asChild variant="ghost" size="sm" className="text-xs font-medium">
              <Link to="/instructor/integrity">
                View all
                <ArrowRight className="ml-1 h-3 w-3" strokeWidth={2} />
              </Link>
            </Button>
          </CardHeader>
          <CardContent className="pt-4">
            <ul className="rounded-lg border border-border bg-card divide-y divide-border overflow-hidden">
              {RECENT_FLAGS.map((flag, i) => (
                <li
                  key={flag.id}
                  className="flex items-center gap-3 px-4 h-16 transition-colors cursor-pointer hover:bg-muted/40"
                >
                  <div className="min-w-0 flex-1">
                    <p className="text-sm font-medium text-foreground truncate">
                      {flag.title}
                    </p>
                    <p className="text-xs text-muted-foreground truncate">
                      {flag.subtitle}
                    </p>
                  </div>
                  <div className="flex items-center gap-2 shrink-0">
                    <span className="text-xs text-muted-foreground font-mono tabular-nums">
                      {flag.meta}
                    </span>
                    <RiskBadge level={flag.level} />
                  </div>
                </li>
              ))}
            </ul>
          </CardContent>
        </Card>
      </div>
    </div>
  );
}
