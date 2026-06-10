import { useState, useCallback, useEffect } from "react";
import { useSearchParams } from "react-router-dom";
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
  RefreshCw,
  AlertTriangle,
  FileSpreadsheet,
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
import InsightHeader from "@/components/ui/insight-header";
import EvidenceRow from "@/components/ui/evidence-row";
import SectionFilter from "@/components/SectionFilter";
import RiskBadge from "@/components/ui/risk-badge";
import { cn } from "@/lib/utils";
import { toast } from "sonner";
import api from "@/services/api";

/**
 * Reports — 4-tier hierarchy with real API data.
 *   1. PageHeader   "Reports" + SectionFilter + PeriodSelector + Export ▾
 *   2. Insight      dynamic headline from API
 *   3. Evidence     4 chips: Mastery / Completion / At Risk / Flags (real KPIs)
 *   4. Tabs         Mastery | Completion | Engagement | Integrity (real data)
 */

const PERIOD_OPTIONS = [1, 2, 4, 12];
const PERIOD_LABELS = { 1: "1w", 2: "2w", 4: "4w", 12: "12w" };

const TOOLTIP_STYLE = {
  backgroundColor: "hsl(var(--popover))",
  border: "1px solid hsl(var(--border))",
  borderRadius: "6px",
  fontSize: "12px",
  color: "hsl(var(--popover-foreground))",
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

const DAYS = ["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"];
const HOUR_BINS = [
  "00–03", "03–06", "06–09", "09–12",
  "12–15", "15–18", "18–21", "21–24",
];

// ── Sort helpers ──────────────────────────────────────────────────────────

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
          {rows.map((row, i) => (
            <tr key={row.id ?? row.day ?? row.exercise ?? row.type ?? i} className="hover:bg-slate-900/60 transition-all duration-200 ease-out">
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

// ── Export helpers ────────────────────────────────────────────────────────

function downloadCSV(filename, rows) {
  const csv = rows.map((r) => r.map((v) => `"${String(v).replace(/"/g, '""')}"`).join(",")).join("\n");
  const blob = new Blob([csv], { type: "text/csv;charset=utf-8;" });
  const url = URL.createObjectURL(blob);
  const a = document.createElement("a");
  a.href = url;
  a.download = filename;
  a.click();
  URL.revokeObjectURL(url);
}

// ── Main Component ────────────────────────────────────────────────────────

export default function InstructorReports() {
  const [searchParams, setSearchParams] = useSearchParams();
  const initialSection = (() => {
    const s = searchParams.get("section");
    return s && s !== "all" ? Number(s) : "all";
  })();
  const [sectionId, setSectionId] = useState(initialSection);
  const [period, setPeriod] = useState(4);
  const [tab, setTab] = useState("mastery");
  const [refreshing, setRefreshing] = useState(false);

  // Summary KPIs
  const [kpi, setKpi] = useState(null);
  const [kpiLoading, setKpiLoading] = useState(true);

  // Mastery data
  const [masteryData, setMasteryData] = useState({ weeks: [], concepts: [] });
  const [masteryLoading, setMasteryLoading] = useState(false);

  // Completion data
  const [completionData, setCompletionData] = useState([]);
  const [completionLoading, setCompletionLoading] = useState(false);

  // Engagement data
  const [engagementMatrix, setEngagementMatrix] = useState([]);
  const [engagementTable, setEngagementTable] = useState([]);
  const [engagementLoading, setEngagementLoading] = useState(false);

  // Integrity data
  const [integrityTimeline, setIntegrityTimeline] = useState([]);
  const [integrityBreakdown, setIntegrityBreakdown] = useState([]);
  const [integrityWeeks, setIntegrityWeeks] = useState([]);
  const [integrityLoading, setIntegrityLoading] = useState(false);

  const activeSectionId = sectionId; // 'all' is a valid API parameter now

  const fetchSummary = useCallback(async () => {
    if (!activeSectionId) { setKpi(null); setKpiLoading(false); return; }
    setKpiLoading(true);
    try {
      const { data } = await api.get(`/api/analytics/reports/${activeSectionId}/summary?period=${period}`);
      setKpi(data);
    } catch (err) {
      console.error("Report summary fetch error:", err);
      setKpi(null);
    } finally {
      setKpiLoading(false);
    }
  }, [activeSectionId, period]);

  const fetchMastery = useCallback(async () => {
    if (!activeSectionId) { setMasteryData({ weeks: [], concepts: [] }); return; }
    setMasteryLoading(true);
    try {
      const { data } = await api.get(`/api/analytics/reports/${activeSectionId}/concept-mastery?weeks=5`);
      setMasteryData(data);
    } catch (err) {
      console.error("Concept mastery fetch error:", err);
      setMasteryData({ weeks: [], concepts: [] });
    } finally {
      setMasteryLoading(false);
    }
  }, [activeSectionId]);

  const fetchCompletion = useCallback(async () => {
    if (!activeSectionId) { setCompletionData([]); return; }
    setCompletionLoading(true);
    try {
      const { data } = await api.get(`/api/analytics/reports/${activeSectionId}/completion`);
      setCompletionData(data);
    } catch (err) {
      console.error("Completion fetch error:", err);
      setCompletionData([]);
    } finally {
      setCompletionLoading(false);
    }
  }, [activeSectionId]);

  const fetchEngagement = useCallback(async () => {
    if (!activeSectionId) { setEngagementMatrix([]); setEngagementTable([]); return; }
    setEngagementLoading(true);
    try {
      const { data } = await api.get(`/api/analytics/reports/${activeSectionId}/engagement`);
      setEngagementMatrix(data.matrix || []);
      setEngagementTable(data.table || []);
    } catch (err) {
      console.error("Engagement fetch error:", err);
      setEngagementMatrix([]);
      setEngagementTable([]);
    } finally {
      setEngagementLoading(false);
    }
  }, [activeSectionId]);

  const fetchIntegrity = useCallback(async () => {
    if (!activeSectionId) { setIntegrityTimeline([]); setIntegrityBreakdown([]); return; }
    setIntegrityLoading(true);
    try {
      const { data } = await api.get(`/api/analytics/reports/${activeSectionId}/integrity-trends?weeks=5`);
      setIntegrityTimeline(data.timeline || []);
      setIntegrityBreakdown(data.breakdown || []);
      setIntegrityWeeks(data.weeks || []);
    } catch (err) {
      console.error("Integrity trends fetch error:", err);
      setIntegrityTimeline([]);
      setIntegrityBreakdown([]);
    } finally {
      setIntegrityLoading(false);
    }
  }, [activeSectionId]);

  // Fetch all report data when section or period changes
  const refreshAll = useCallback(() => {
    setRefreshing(true);
    Promise.allSettled([
      fetchSummary(),
      fetchMastery(),
      fetchCompletion(),
      fetchEngagement(),
      fetchIntegrity(),
    ]).finally(() => setRefreshing(false));
  }, [fetchSummary, fetchMastery, fetchCompletion, fetchEngagement, fetchIntegrity]);

  useEffect(() => {
    refreshAll();
  }, [refreshAll]);

  const handleSectionChange = (next) => {
    setSectionId(next);
    setSearchParams(next === "all" ? {} : { section: next });
  };

  const handlePeriodChange = (next) => {
    setPeriod(next);
  };

  // Export handlers
  const handleExportCSV = useCallback(() => {
    const sectionName = sectionId === "all" ? "all-sections" : `section-${sectionId}`;
    if (tab === "mastery") {
      const header = ["Concept", "Current", "Weeks"].concat(masteryData.weeks);
      const nWeeks = masteryData.weeks.length;
      const rows = masteryData.concepts.map(c => {
        const padded = [...c.series];
        while (padded.length < nWeeks) padded.push("");
        return [c.name, c.current + "%", "Series", ...padded];
      });
      downloadCSV(`mastery-report-${sectionName}.csv`, [header, ...rows]);
    } else if (tab === "completion") {
      const header = ["Exercise", "On Time", "Late", "Missing"];
      const rows = completionData.map(c => [c.exercise, c.on_time + "%", c.late + "%", c.missing + "%"]);
      downloadCSV(`completion-report-${sectionName}.csv`, [header, ...rows]);
    } else if (tab === "engagement") {
      const header = ["Day", "Submissions", "Peak Hour"];
      const rows = engagementTable.map(e => [e.day, e.submissions, e.peak]);
      downloadCSV(`engagement-report-${sectionName}.csv`, [header, ...rows]);
    } else if (tab === "integrity") {
      const header = ["Week", "Critical", "High", "Moderate", "Low"];
      const rows = integrityTimeline.map(t => [t.week, t.critical, t.high, t.moderate, t.low]);
      downloadCSV(`integrity-report-${sectionName}.csv`, [header, ...rows]);
    }
    toast.success("Report exported as CSV");
  }, [tab, sectionId, masteryData, completionData, engagementTable, integrityTimeline]);

  const handleExportExcel = useCallback(async () => {
    if (!sectionId || sectionId === "all") {
      toast.info("Select a specific section to export Excel");
      return;
    }
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
      toast.success("Report exported as Excel");
    } catch (err) {
      console.error("Excel export failed:", err);
      toast.error("Failed to export Excel report");
    }
  }, [sectionId]);

  // Download helper for new export endpoints
  const downloadEndpointExport = useCallback(async (endpoint, filename) => {
    if (!activeSectionId) {
      toast.info("Select a section first");
      return;
    }
    try {
      const res = await api.get(`/api/export/${activeSectionId}`, {
        params: { format: "csv" },
      });
      const blob = new Blob([res.data], { type: "text/csv;charset=utf-8;" });
      const url = URL.createObjectURL(blob);
      const a = document.createElement("a");
      a.href = url;
      a.download = `${filename}.csv`;
      a.click();
      URL.revokeObjectURL(url);
      toast.success(`${filename} exported`);
    } catch (err) {
      console.error(`${endpoint} export failed:`, err);
      toast.error(`Failed to export ${filename}`);
    }
  }, [activeSectionId]);

  return (
    <div className="space-y-6 sm:space-y-8">
      {/* ---------- PageHeader ---------- */}
      <div className="flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between">
        <div className="min-w-0 space-y-1">
          <h1 className="text-2xl font-semibold tracking-tight">Reports</h1>
          <p className="text-sm text-muted-foreground">
            Class-wide trends and concept-level difficulty across all sections.
          </p>
        </div>
        <div className="flex items-center gap-2 shrink-0 flex-wrap">
          <SectionFilter value={sectionId} onChange={handleSectionChange} placeholder="All Sections" />
          <div
            role="radiogroup"
            aria-label="Period"
            className="inline-flex rounded-md border border-border bg-muted p-0.5 gap-0.5"
          >
            {PERIOD_OPTIONS.map((opt) => (
              <button
                key={opt}
                type="button"
                role="radio"
                aria-checked={opt === period}
                onClick={() => handlePeriodChange(opt)}
                className={
                  opt === period
                    ? "px-3 py-1 text-sm rounded transition-colors cursor-pointer bg-card text-foreground shadow-sm font-medium"
                    : "px-3 py-1 text-sm rounded transition-colors cursor-pointer text-muted-foreground hover:text-foreground"
                }
              >
                {PERIOD_LABELS[opt]}
              </button>
            ))}
          </div>
          <DropdownMenu>
            <DropdownMenuTrigger asChild>
              <Button size="sm" className="font-medium">
                <Download className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                Export
                <ChevronDown className="ml-1.5 h-3.5 w-3.5" strokeWidth={1.5} />
              </Button>
            </DropdownMenuTrigger>
            <DropdownMenuContent align="end" className="w-56">
              <DropdownMenuItem onClick={handleExportCSV}>
                <Download className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                Export CSV
              </DropdownMenuItem>
              <DropdownMenuItem onClick={handleExportExcel}>
                <FileSpreadsheet className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                Export Excel
              </DropdownMenuItem>
              <DropdownMenuItem onClick={() => downloadEndpointExport("behavioral", "behavioral-audit")}>
                <Download className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                Behavioral Audit Log
              </DropdownMenuItem>
              <DropdownMenuItem onClick={() => downloadEndpointExport("cds-snapshots", "cds-snapshots")}>
                <Download className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                CDS Snapshots
              </DropdownMenuItem>
            </DropdownMenuContent>
          </DropdownMenu>
        </div>
      </div>

      {/* ---------- Insight ---------- */}
      {kpiLoading ? (
        <InsightHeader
          eyebrow="Headline"
          insight="Loading report data…"
        />
      ) : kpi ? (
        <InsightHeader
          eyebrow="Report"
          insight={
            sectionId === "all"
              ? `Across all your sections: mastery is ${kpi.mastery?.value || "N/A"}${kpi.mastery?.delta != null ? ` (${kpi.mastery.delta >= 0 ? "+" : ""}${kpi.mastery.delta}%)` : ""}.`
              : kpi.mastery?.delta > 0
                ? `Class mastery is up ${kpi.mastery.delta}% over the last ${PERIOD_LABELS[period]}.`
                : kpi.mastery?.delta < 0
                  ? `Class mastery is down ${Math.abs(kpi.mastery.delta)}% over the last ${PERIOD_LABELS[period]}.`
                  : `Class mastery is steady at ${kpi.mastery?.value || "N/A"}.`
          }
          description={(() => {
            const parts = [];
            if (kpi.atRisk?.value && parseInt(kpi.atRisk.value) > 0) {
              parts.push(`${kpi.atRisk.value} of students are at risk`);
            } else if (sectionId !== "all") {
              // single-section: don't show "no students at risk" — it's obvious
            }
            if (kpi.flags?.value != null && kpi.flags.value !== "—") {
              const flagsPct = parseInt(kpi.flags.value);
              parts.push(`${flagsPct}% of students flagged`);
            }
            if (parts.length === 0 && sectionId === "all") {
              return "No students currently at risk across all sections.";
            }
            return parts.length ? parts.join(" — ") : undefined;
          })()}
          action={
            <Button size="sm" className="font-medium" onClick={refreshAll} disabled={refreshing}>
              {refreshing ? "Refreshing…" : "Refresh"}
              <RefreshCw className={cn("ml-1.5 h-3.5 w-3.5", refreshing && "animate-spin")} strokeWidth={2} />
            </Button>
          }
        />
      ) : (
        <InsightHeader
          eyebrow="Select a section"
          insight="Choose a section from the filter above to see report data."
        />
      )}

      {/* ---------- Evidence ---------- */}
      {kpi ? (
        <EvidenceRow
          chips={[
            { label: "Mastery",    value: kpi.mastery?.value ?? "—",       delta: kpi.mastery?.delta,       series: kpi.mastery?.series,       comparison: kpi.mastery?.comparison },
            { label: "Completion", value: kpi.completion?.value ?? "—",    delta: kpi.completion?.delta,    series: kpi.completion?.series,    comparison: kpi.completion?.comparison },
            { label: "At Risk",    value: kpi.atRisk?.value ?? "—",        delta: kpi.atRisk?.delta,        series: kpi.atRisk?.series,        comparison: kpi.atRisk?.comparison, inverted: kpi.atRisk?.inverted },
            { label: "Flags",      value: kpi.flags?.value ?? "—",         delta: kpi.flags?.delta,         series: kpi.flags?.series,         comparison: kpi.flags?.comparison, inverted: kpi.flags?.inverted },
          ]}
        />
      ) : (
        <EvidenceRow chips={[]} />
      )}

      {/* ---------- Tabs ---------- */}
      <Tabs value={tab} onValueChange={setTab}>
        <TabsList className="inline-flex h-10 items-center gap-0 bg-transparent p-0 border-b border-border rounded-none w-full justify-start">
          <TabsTrigger value="mastery"    className={TRIGGER_BASE}>Mastery</TabsTrigger>
          <TabsTrigger value="completion" className={TRIGGER_BASE}>Completion</TabsTrigger>
          <TabsTrigger value="engagement" className={TRIGGER_BASE}>Engagement</TabsTrigger>
          <TabsTrigger value="integrity"  className={TRIGGER_BASE}>Integrity</TabsTrigger>
        </TabsList>

        <TabsContent value="mastery" className="mt-6">
          {activeSectionId ? (
            masteryLoading ? (
              <div className="rounded-xl border border-border/60 bg-card/50 backdrop-blur-sm py-8 px-6 text-center">
                <RefreshCw className="h-6 w-6 text-muted-foreground mx-auto mb-2 animate-spin" />
                <p className="text-sm text-muted-foreground">Loading mastery data…</p>
              </div>
            ) : (
              <MasteryTab data={masteryData} />
            )
          ) : (
            <EmptyTab message="Select a section to view concept mastery data." />
          )}
        </TabsContent>
        <TabsContent value="completion" className="mt-6">
          {activeSectionId ? (
            completionLoading ? (
              <div className="rounded-xl border border-border/60 bg-card/50 backdrop-blur-sm py-8 px-6 text-center">
                <RefreshCw className="h-6 w-6 text-muted-foreground mx-auto mb-2 animate-spin" />
                <p className="text-sm text-muted-foreground">Loading completion data…</p>
              </div>
            ) : (
              <CompletionTab data={completionData} />
            )
          ) : (
            <EmptyTab message="Select a section to view completion breakdown." />
          )}
        </TabsContent>
        <TabsContent value="engagement" className="mt-6">
          {activeSectionId ? (
            engagementLoading ? (
              <div className="rounded-xl border border-border/60 bg-card/50 backdrop-blur-sm py-8 px-6 text-center">
                <RefreshCw className="h-6 w-6 text-muted-foreground mx-auto mb-2 animate-spin" />
                <p className="text-sm text-muted-foreground">Loading engagement data…</p>
              </div>
            ) : (
              <EngagementTab matrix={engagementMatrix} table={engagementTable} />
            )
          ) : (
            <EmptyTab message="Select a section to view engagement heatmap." />
          )}
        </TabsContent>
        <TabsContent value="integrity" className="mt-6">
          {activeSectionId ? (
            integrityLoading ? (
              <div className="rounded-xl border border-border/60 bg-card/50 backdrop-blur-sm py-8 px-6 text-center">
                <RefreshCw className="h-6 w-6 text-muted-foreground mx-auto mb-2 animate-spin" />
                <p className="text-sm text-muted-foreground">Loading integrity data…</p>
              </div>
            ) : (
              <IntegrityTab timeline={integrityTimeline} breakdown={integrityBreakdown} weeks={integrityWeeks} />
            )
          ) : (
            <EmptyTab message="Select a section to view integrity trends." />
          )}
        </TabsContent>
      </Tabs>
    </div>
  );
}

function EmptyTab({ message }) {
  return (
    <div className="rounded-xl border border-dashed border-border/40 bg-card/30 backdrop-blur-sm p-12 text-center">
      <AlertTriangle className="h-6 w-6 text-muted-foreground mx-auto mb-2" strokeWidth={1.5} />
      <p className="text-sm font-medium">{message}</p>
    </div>
  );
}

// ── Tab Components ────────────────────────────────────────────────────────

function MasteryTab({ data }) {
  const { sort, onSort } = useSort({ key: "current", dir: "desc" });

  const chartData = data.weeks.map((week, i) => {
    const row = { week };
    for (const c of data.concepts) {
      row[c.id] = c.series[i] ?? 0;
    }
    return row;
  });

  const tableRows = applySort(
    data.concepts.map(c => ({
      id: c.id,
      name: c.name,
      current: c.current,
      delta: c.series.length >= 2 ? c.series[c.series.length - 1] - c.series[0] : 0,
    })),
    sort,
  );

  if (!data.concepts.length) {
    return <EmptyTab message="No mastery data available for this section yet." />;
  }

  return (
    <div className="space-y-6">
      <Card>
        <CardHeader className="pb-3 border-b border-border">
          <div className="space-y-1">
            <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
              Trend
            </p>
            <CardTitle className="text-sm font-semibold">
              Concept mastery · {data.weeks.length}-week rolling
            </CardTitle>
          </div>
        </CardHeader>
        <CardContent className="pt-4">
          <div className="h-72 w-full">
            <ResponsiveContainer width="100%" height="100%">
              <LineChart data={chartData} margin={{ top: 8, right: 12, bottom: 0, left: -8 }}>
                <CartesianGrid stroke="hsl(var(--border))" strokeDasharray="3 3" vertical={false} />
                <XAxis dataKey="week" tick={{ fill: "hsl(var(--muted-foreground))", fontSize: 11 }} axisLine={{ stroke: "hsl(var(--border))" }} tickLine={false} />
                <YAxis domain={[0, 100]} tick={{ fill: "hsl(var(--muted-foreground))", fontSize: 11 }} axisLine={false} tickLine={false} width={40} />
                <Tooltip contentStyle={TOOLTIP_STYLE} cursor={{ stroke: "hsl(var(--muted))" }} />
                <Legend wrapperStyle={{ fontSize: "11px", paddingTop: "8px" }} iconType="circle" iconSize={8} />
                {data.concepts.map((c) => (
                  <Line key={c.id} type="monotone" dataKey={c.id} name={c.name}
                    stroke={conceptColor(c.id)} strokeWidth={1.5} dot={false} isAnimationActive={false} />
                ))}
              </LineChart>
            </ResponsiveContainer>
          </div>
        </CardContent>
      </Card>

      <Card>
        <CardHeader className="pb-3 border-b border-border">
          <CardTitle className="text-sm font-semibold">Concepts · current vs. {data.weeks.length}w ago</CardTitle>
        </CardHeader>
        <CardContent className="p-0">
          <SortableTable
            columns={[
              { key: "name", label: "Concept", align: "left" },
              { key: "current", label: "Current", align: "right" },
              { key: "delta", label: "Δ", align: "right" },
            ]}
            sort={sort}
            onSort={onSort}
            rows={tableRows}
            renderCell={(col, row) => {
              if (col.key === "name") return <span className="text-sm font-medium">{row.name}</span>;
              if (col.key === "current") return <span className="text-sm font-mono tabular-nums">{row.current}%</span>;
              if (col.key === "delta") {
                const positive = row.delta > 0;
                return (
                  <span className={cn(
                    "text-xs font-mono tabular-nums",
                    positive ? "text-success" : row.delta < 0 ? "text-destructive" : "text-muted-foreground",
                  )}>
                    {positive ? "+" : ""}{row.delta}
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

function CompletionTab({ data }) {
  const { sort, onSort } = useSort({ key: "on_time", dir: "desc" });
  const rows = applySort(data, sort);

  if (!data.length) {
    return <EmptyTab message="No exercises found in this section." />;
  }

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
              <BarChart data={data} margin={{ top: 8, right: 12, bottom: 0, left: -8 }} barCategoryGap={6}>
                <CartesianGrid stroke="hsl(var(--border))" strokeDasharray="3 3" vertical={false} />
                <XAxis dataKey="exercise" tick={{ fill: "hsl(var(--muted-foreground))", fontSize: 10 }} axisLine={{ stroke: "hsl(var(--border))" }} tickLine={false} interval={0} angle={-20} textAnchor="end" height={56} />
                <YAxis tick={{ fill: "hsl(var(--muted-foreground))", fontSize: 11 }} axisLine={false} tickLine={false} width={32} tickFormatter={(v) => `${v}%`} />
                <Tooltip contentStyle={TOOLTIP_STYLE} cursor={{ fill: "hsl(var(--muted) / 0.4)" }} />
                <Legend wrapperStyle={{ fontSize: "11px", paddingTop: "8px" }} iconType="circle" iconSize={8} />
                <Bar dataKey="on_time" name="On time" stackId="status" fill="hsl(var(--success))" isAnimationActive={false} />
                <Bar dataKey="late" name="Late" stackId="status" fill="hsl(var(--warning))" isAnimationActive={false} />
                <Bar dataKey="missing" name="Missing" stackId="status" fill="hsl(var(--destructive))" isAnimationActive={false} />
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
              { key: "exercise", label: "Exercise", align: "left" },
              { key: "on_time", label: "On time", align: "right" },
              { key: "late", label: "Late", align: "right" },
              { key: "missing", label: "Missing", align: "right" },
            ]}
            sort={sort}
            onSort={onSort}
            rows={rows}
            renderCell={(col, row) => {
              if (col.key === "exercise") return <span className="text-sm font-medium">{row.exercise}</span>;
              return <span className="text-sm font-mono tabular-nums">{row[col.key]}%</span>;
            }}
          />
        </CardContent>
      </Card>
    </div>
  );
}

function EngagementTab({ matrix, table }) {
  const { sort, onSort } = useSort({ key: "submissions", dir: "desc" });
  const rows = applySort(table, sort);

  if (!matrix.length) {
    return <EmptyTab message="No submission data for the engagement heatmap." />;
  }

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
              <div className="grid" style={{ gridTemplateColumns: "3rem repeat(8, minmax(0, 1fr))" }}>
                <div />
                {HOUR_BINS.map((bin) => (
                  <div key={bin} className="text-[10px] font-mono tabular-nums text-muted-foreground text-center px-1">{bin}</div>
                ))}
              </div>
              {DAYS.map((day, dIdx) => (
                <div key={day} className="grid items-center" style={{ gridTemplateColumns: "3rem repeat(8, minmax(0, 1fr))" }}>
                  <div className="text-xs font-medium text-muted-foreground pr-2">{day}</div>
                  {(matrix[dIdx] || Array(8).fill(0)).map((density, hIdx) => (
                    <div
                      key={hIdx}
                      className={cn("h-7 rounded-sm border border-border/40", HEAT_TONE[density])}
                      title={`${day} · ${HOUR_BINS[hIdx]} · ${density}`}
                    />
                  ))}
                </div>
              ))}
              <div className="flex items-center justify-end gap-2 pt-3">
                <span className="text-[10px] uppercase tracking-wider text-muted-foreground">Less</span>
                {HEAT_TONE.map((tone, i) => (
                  <div key={i} className={cn("h-3 w-5 rounded-sm border border-border/40", tone)} />
                ))}
                <span className="text-[10px] uppercase tracking-wider text-muted-foreground">More</span>
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
              { key: "day", label: "Day", align: "left" },
              { key: "submissions", label: "Submissions", align: "right" },
              { key: "peak", label: "Peak hour", align: "left" },
            ]}
            sort={sort}
            onSort={onSort}
            rows={rows}
            renderCell={(col, row) => {
              if (col.key === "day") return <span className="text-sm font-medium">{row.day}</span>;
              if (col.key === "submissions") return <span className="text-sm font-mono tabular-nums">{row.submissions}</span>;
              return <span className="text-sm text-muted-foreground font-mono tabular-nums">{row.peak}</span>;
            }}
          />
        </CardContent>
      </Card>
    </div>
  );
}

function IntegrityTab({ timeline, breakdown, weeks }) {
  const { sort, onSort } = useSort({ key: "count", dir: "desc" });
  const rows = applySort(breakdown, sort);

  if (!timeline.length) {
    return <EmptyTab message="No integrity flag data for this section." />;
  }

  return (
    <div className="space-y-6">
      <Card>
        <CardHeader className="pb-3 border-b border-border">
          <div className="space-y-1">
            <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
              Trend
            </p>
            <CardTitle className="text-sm font-semibold">
              Integrity flags · {weeks.length}-week rolling
            </CardTitle>
          </div>
        </CardHeader>
        <CardContent className="pt-4">
          <div className="h-72 w-full">
            <ResponsiveContainer width="100%" height="100%">
              <LineChart data={timeline} margin={{ top: 8, right: 12, bottom: 0, left: -8 }}>
                <CartesianGrid stroke="hsl(var(--border))" strokeDasharray="3 3" vertical={false} />
                <XAxis dataKey="week" tick={{ fill: "hsl(var(--muted-foreground))", fontSize: 11 }} axisLine={{ stroke: "hsl(var(--border))" }} tickLine={false} />
                <YAxis allowDecimals={false} tick={{ fill: "hsl(var(--muted-foreground))", fontSize: 11 }} axisLine={false} tickLine={false} width={32} />
                <Tooltip contentStyle={TOOLTIP_STYLE} cursor={{ stroke: "hsl(var(--muted))" }} />
                <Legend wrapperStyle={{ fontSize: "11px", paddingTop: "8px" }} iconType="circle" iconSize={8} />
                <Line type="monotone" dataKey="critical" name="Critical" stroke="hsl(var(--destructive))" strokeWidth={2} dot={false} isAnimationActive={false} />
                <Line type="monotone" dataKey="high" name="High" stroke="hsl(var(--cds-high))" strokeWidth={2} dot={false} isAnimationActive={false} />
                <Line type="monotone" dataKey="moderate" name="Moderate" stroke="hsl(var(--cds-mod))" strokeWidth={2} dot={false} isAnimationActive={false} />
                <Line type="monotone" dataKey="low" name="Low" stroke="hsl(var(--cds-low))" strokeWidth={2} dot={false} isAnimationActive={false} />
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
              { key: "type", label: "Type", align: "left" },
              { key: "level", label: "Level", align: "left" },
              { key: "count", label: "Count", align: "right" },
              { key: "share", label: "Share", align: "right" },
              { key: "delta", label: "Δ", align: "right" },
            ]}
            sort={sort}
            onSort={onSort}
            rows={rows}
            renderCell={(col, row) => {
              if (col.key === "type") return <span className="text-sm font-medium">{row.type}</span>;
              if (col.key === "level") return <RiskBadge level={row.level} />;
              if (col.key === "count") return <span className="text-sm font-mono tabular-nums">{row.count}</span>;
              if (col.key === "share") return <span className="text-sm text-muted-foreground font-mono tabular-nums">{row.share}%</span>;
              if (col.key === "delta") {
                const positive = row.delta > 0;
                return (
                  <span className={cn(
                    "text-xs font-mono tabular-nums",
                    positive ? "text-destructive" : row.delta < 0 ? "text-success" : "text-muted-foreground",
                  )}>
                    {positive ? "+" : ""}{row.delta}
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

/**
 * Distinct color for each curriculum concept on the mastery line chart.
 * IDs are 2-letter abbreviations generated as name.substring(0,2).toUpperCase().
 */
const CONCEPT_COLORS = {
  DA: '#06B6D4', // Datatypes   — Teal
  VR: '#38BDF8', // Variables   — Sky Blue
  CD: '#6366F1', // Conditionals — Indigo
  LO: '#F59E0B', // Loops       — Amber
  FN: '#A855F7', // Functions   — Purple
  AR: '#FBBF24', // Arrays      — Yellow
  OO: '#F43F5E', // OOP         — Rose
};

function conceptColor(id) {
  return CONCEPT_COLORS[id] || '#64748b'; // fallback: slate
}
