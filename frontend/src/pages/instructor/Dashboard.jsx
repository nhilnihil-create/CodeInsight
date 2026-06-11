import { useEffect, useState } from "react";
import { Link } from "react-router-dom";
import {
  Download,
  ArrowRight,
  ChevronDown,
  BarChart3,
  ShieldAlert,
  TrendingUp,
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
import {
  DropdownMenu,
  DropdownMenuContent,
  DropdownMenuItem,
  DropdownMenuTrigger,
} from "@/components/ui/dropdown-menu";
import InsightHeader from "@/components/ui/insight-header";
import EvidenceRow from "@/components/ui/evidence-row";
import PeriodSelector from "@/components/ui/period-selector";
import RiskBadge from "@/components/ui/risk-badge";
import SectionFilter from "@/components/SectionFilter";
import EmptyState from "@/components/ui/empty-state";
import api from "@/services/api";

const TOOLTIP_STYLE = {
  backgroundColor: "hsl(var(--popover))",
  border: "1px solid hsl(var(--border))",
  borderRadius: "6px",
  fontSize: "12px",
  color: "hsl(var(--popover-foreground))",
};

export default function InstructorDashboard() {
  const [period, setPeriod] = useState("7d");
  const [sectionId, setSectionId] = useState("all");
  const [data, setData] = useState(null);
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState(null);

  const days = parseInt(period.replace("d", ""), 10) || 7;

  useEffect(() => {
    let cancelled = false;
    const fetchData = async () => {
      setLoading(true);
      setError(null);
      try {
        const res = await api.get(
          `/api/analytics/instructor/dashboard/${sectionId}?period=${days}`
        );
        if (!cancelled) setData(res.data);
      } catch (err) {
        if (!cancelled) setError(err.response?.data?.error || "Failed to load dashboard");
      } finally {
        if (!cancelled) setLoading(false);
      }
    };
    fetchData();
    return () => { cancelled = true; };
  }, [sectionId, days]);

  const handleExportCSV = () => {
    if (!data?.trend?.length) return;
    const headers = ["Date", "CDS", "Mastery", "Engagement"];
    const rows = data.trend.map((r) =>
      [r.date, r.cds, r.mastery, r.engagement].join(",")
    );
    const csv = [headers.join(","), ...rows].join("\n");
    const blob = new Blob([csv], { type: "text/csv" });
    const url = URL.createObjectURL(blob);
    const a = document.createElement("a");
    a.href = url;
    a.download = `dashboard-trend-${sectionId}.csv`;
    a.click();
    URL.revokeObjectURL(url);
  };

  const handleExportExcel = async () => {
    if (!sectionId || sectionId === "all") return;
    try {
      const res = await api.get(`/api/sections/${sectionId}/export`, {
        responseType: "blob",
      });
      const url = URL.createObjectURL(res.data);
      const a = document.createElement("a");
      a.href = url;
      a.download = `section-${sectionId}-report.xlsx`;
      a.click();
      URL.revokeObjectURL(url);
    } catch (err) {
      console.error("Excel export failed:", err);
    }
  };

  const insight = data?.insight?.summary || "Select a section to view metrics.";
  const kpis = data?.kpis || [];
  const trendData = data?.trend || [];
  const strugglingConcepts = data?.strugglingConcepts || [];
  const recentFlags = data?.recentFlags || [];

  return (
    <div className="space-y-6 sm:space-y-8">
      {/* ---------- PageHeader ---------- */}
      <div className="flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between">
        <div className="min-w-0 space-y-2">
          <div>
            <h1 className="text-2xl font-semibold tracking-tight">Class Status</h1>
            <p className="text-sm text-muted-foreground mt-1">
              {sectionId === "all"
                ? "Aggregated metrics across all your sections, updated live."
                : "Aggregated metrics for this section, updated live."}
            </p>
          </div>
        </div>
        <div className="flex items-center gap-2 shrink-0">
          <SectionFilter value={sectionId} onChange={setSectionId} />
          <PeriodSelector value={period} onChange={setPeriod} />
          <DropdownMenu>
            <DropdownMenuTrigger asChild>
              <Button
                variant="ghost"
                size="sm"
                className="font-medium"
                disabled={!trendData.length}
              >
                <Download className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                Export
                <ChevronDown className="ml-1 h-3 w-3" strokeWidth={1.5} />
              </Button>
            </DropdownMenuTrigger>
            <DropdownMenuContent align="end">
              <DropdownMenuItem onClick={handleExportCSV}>
                <Download className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                Export CSV
              </DropdownMenuItem>
              <DropdownMenuItem
                onClick={handleExportExcel}
                disabled={sectionId === "all"}
              >
                <Download className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                Export Excel
              </DropdownMenuItem>
            </DropdownMenuContent>
          </DropdownMenu>
        </div>
      </div>

      {loading ? (
        <Card>
          <CardContent className="py-12 text-center text-muted-foreground">
            Loading dashboard data…
          </CardContent>
        </Card>
      ) : error ? (
        <Card>
          <CardContent className="py-12 text-center text-rose-400">
            {error}
          </CardContent>
        </Card>
      ) : (
        <>
          {/* ---------- Insight ---------- */}
          <InsightHeader
            insight={insight}
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
          <EvidenceRow chips={kpis} />

          {/* ---------- Class trend ---------- */}
          <Card>
            <CardHeader className="pb-3 border-b border-border">
              <CardTitle className="text-sm font-semibold">Class trend</CardTitle>
            </CardHeader>
            <CardContent className="pt-4">
              <div className="h-64 w-full">
                {trendData.length > 0 ? (
                  <ResponsiveContainer width="100%" height="100%">
                    <LineChart
                      data={trendData}
                      margin={{ top: 8, right: 12, bottom: 0, left: 8 }}
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
                        domain={[0, 100]}
                        tickFormatter={(v) => `${v}%`}
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
                ) : (
                  <EmptyState
                    icon={<TrendingUp />}
                    title="No trend data yet"
                    description="Submit some exercises and CDS metrics will populate this chart over time."
                  />
                )}
              </div>
            </CardContent>
          </Card>

          {/* ---------- Details grid ---------- */}
          <div className="grid gap-6 md:grid-cols-2">
            <Card>
              <CardHeader className="pb-3 border-b border-border">
                <CardTitle className="text-sm font-semibold">
                  Top struggling concepts
                </CardTitle>
              </CardHeader>
              <CardContent className="pt-4">
                <div className="h-64 w-full">
                  {strugglingConcepts.length > 0 ? (
                    <ResponsiveContainer width="100%" height="100%">
                      <BarChart
                        data={strugglingConcepts}
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
                  ) : (
                    <EmptyState
                      icon={<BarChart3 />}
                      title="No concept data yet"
                      description="Student submissions will generate concept-level analytics here."
                    />
                  )}
                </div>
              </CardContent>
            </Card>

            <Card>
              <CardHeader className="flex flex-row items-center justify-between space-y-0 pb-3 border-b border-border">
                <CardTitle className="text-sm font-semibold">
                  Recent integrity flags
                </CardTitle>
                <Button asChild variant="ghost" size="sm" className="text-xs font-medium">
                  <Link to="/instructor/integrity">
                    View all
                    <ArrowRight className="ml-1 h-3 w-3" strokeWidth={2} />
                  </Link>
                </Button>
              </CardHeader>
              <CardContent className="pt-4">
                {recentFlags.length > 0 ? (
                  <ul className="rounded-xl border border-border/60 bg-card/50 backdrop-blur-sm divide-y divide-border/40 overflow-hidden">
                    {recentFlags.map((flag) => (
                      <li key={flag.id}>
                        <Link
                          to="/instructor/integrity"
                          className="flex items-center gap-3 px-4 h-16 transition-all duration-200 ease-out hover:bg-slate-900/80 hover:scale-[1.01]"
                        >
                          <div className="min-w-0 flex-1">
                            <p className="text-sm font-medium text-foreground truncate">
                              {flag.studentName}
                            </p>
                            <p className="text-xs text-muted-foreground truncate">
                              {flag.flagType}{flag.exerciseTitle ? ` · ${flag.exerciseTitle}` : ""}
                            </p>
                          </div>
                          <div className="flex items-center gap-2 shrink-0">
                            <span className="text-xs text-muted-foreground font-mono tabular-nums">
                              {flag.timeAgo}
                            </span>
                            <RiskBadge level={flag.severity} />
                          </div>
                        </Link>
                      </li>
                    ))}
                  </ul>
                ) : (
                  <EmptyState
                    icon={<ShieldAlert />}
                    title="All clear"
                    description="No integrity flags detected. Student submissions are being monitored automatically."
                  />
                )}
              </CardContent>
            </Card>
          </div>
        </>
      )}
    </div>
  );
}
