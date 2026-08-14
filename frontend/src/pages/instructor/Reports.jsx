import { useState, useCallback, useEffect, useMemo } from "react";
import { useSearchParams } from "react-router-dom";
import { motion } from "framer-motion";
import {
  ResponsiveContainer,
  LineChart,
  Line,
  AreaChart,
  Area,
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
  ArrowUpDown,
  ArrowUp,
  ArrowDown,
  RefreshCw,
  AlertTriangle,
} from "lucide-react";
import { Button } from "@/components/ui/button";
import { Card, CardContent, CardHeader, CardTitle } from "@/components/ui/card";
import { Tabs, TabsList, TabsTrigger, TabsContent } from "@/components/ui/tabs";
import ExportDropdown from "@/components/ui/export-dropdown";
import InsightHeader from "@/components/ui/insight-header";
import EvidenceRow from "@/components/ui/evidence-row";
import SectionFilter from "@/components/SectionFilter";
import useLastSection from "@/hooks/useLastSection";

import { cn } from "@/lib/utils";
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

// ── Knowledge Area Group Registry ─────────────────────────────────────────

const KA_GROUPS = [
  { code: "SDF-FPC", label: "Procedural Fundamentals", shortLabel: "Procedural" },
  { code: "SDF-PMD", label: "Program Design & Logic", shortLabel: "Design & Logic" },
  { code: "SDF-OOP", label: "Object-Oriented Paradigms", shortLabel: "OOP" },
  { code: "SDF-FDS", label: "Advanced Structures", shortLabel: "Adv. Structures" },
];

const KA_CONCEPT_MEMBERSHIP = {
  "SDF-FPC": ["datatypes", "variables", "strings", "input-output", "enums", "file-io", "type-casting"],
  "SDF-PMD": ["conditionals", "loops", "functions", "scope", "switch-case", "nested-loops", "recursion", "error-handling"],
  "SDF-OOP": ["oop", "preprocessor", "namespaces", "inheritance", "polymorphism"],
  "SDF-FDS": ["arrays", "pointers", "structs", "dynamic-memory", "linked-lists"],
};

// Color ramps per knowledge area — each concept gets a shade within its group
const KA_PALETTE = {
  "SDF-FPC": ["#06B6D4", "#22D3EE", "#67E8F9", "#A5F3FC"],
  "SDF-PMD": ["#F59E0B", "#FBBF24", "#FCD34D", "#FDE68A", "#FEF3C7", "#F59E0B", "#D97706", "#B45309"],
  "SDF-OOP": ["#F43F5E", "#FB7185", "#FDA4AF", "#FECDD3", "#FFF1F2"],
  "SDF-FDS": ["#8B5CF6", "#A78BFA", "#C4B5FD", "#DDD6FE", "#EDE9FE"],
};

function getConceptColor(conceptId, indexInGroup = 0) {
  for (const code of Object.keys(KA_PALETTE)) {
    const concepts = KA_CONCEPT_MEMBERSHIP[code];
    const idx = concepts.indexOf(conceptId);
    if (idx !== -1) {
      const palette = KA_PALETTE[code];
      return palette[idx % palette.length];
    }
  }
  return "#64748b";
}

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

// ── Main Component ────────────────────────────────────────────────────────

export default function InstructorReports() {
  const [, setSearchParams] = useSearchParams();
  const [sectionId, setSectionId] = useLastSection();
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

  // Integrity data
  const [integrityTimeline, setIntegrityTimeline] = useState([]);
  const [integrityBreakdown, setIntegrityBreakdown] = useState([]);
  const [integrityWeeks, setIntegrityWeeks] = useState([]);
  const [integrityLoading, setIntegrityLoading] = useState(false);

  const activeSectionId = sectionId;

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
      fetchIntegrity(),
    ]).finally(() => setRefreshing(false));
  }, [fetchSummary, fetchMastery, fetchCompletion, fetchIntegrity]);

  useEffect(() => {
    refreshAll();
  }, [refreshAll]);

  const handleSectionChange = (next) => {
    setSectionId(next);
    setSearchParams({ section: next });
  };

  const handlePeriodChange = (next) => {
    setPeriod(next);
  };

  // All tabs now export the unified Student Summary via
  // /api/export/summary/:sectionId — the per-tab domain mapping was removed
  // so the Export control always downloads the same canonical summary file.

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
          <SectionFilter value={sectionId} onChange={handleSectionChange} />
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
          <ExportDropdown
            sectionId={sectionId}
            domain="summary"
            formats={["csv", "xlsx"]}
            label="Export"
          />
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
            kpi.mastery?.delta > 0
              ? `Class mastery is up ${kpi.mastery.delta}% over the last ${PERIOD_LABELS[period]}.`
              : kpi.mastery?.delta < 0
                ? `Class mastery is down ${Math.abs(kpi.mastery.delta)}% over the last ${PERIOD_LABELS[period]}.`
                : `Class mastery is steady at ${kpi.mastery?.value || "N/A"}.`
          }
          description={(() => {
            const parts = [];
            if (kpi.atRisk?.value && parseInt(kpi.atRisk.value) > 0) {
              parts.push(`${kpi.atRisk.value} of students are at risk`);
            }
            if (kpi.flags?.value != null && kpi.flags.value !== "—") {
              const flagsPct = parseInt(kpi.flags.value);
              parts.push(`${flagsPct}% of students flagged`);
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

// ── Sparkline ─────────────────────────────────────────────────────────────

function Sparkline({ data, width = 64, height = 20, color = "hsl(var(--primary))" }) {
  const max = Math.max(...data, 1);
  const min = Math.min(...data, 0);
  const range = max - min || 1;
  const pts = data.map((v, i) => {
    const x = (i / Math.max(data.length - 1, 1)) * width;
    const y = height - ((v - min) / range) * (height - 2) - 1;
    return `${x},${y}`;
  }).join(" ");
  return (
    <svg width={width} height={height} className="block">
      <polyline points={pts} fill="none" stroke={color} strokeWidth={1.5} strokeLinecap="round" strokeLinejoin="round" />
    </svg>
  );
}

// ── Tab Components ────────────────────────────────────────────────────────

/**
 * MasteryTab — Knowledge Area–grouped concept trend lines.
 * Glassmorphic segmented picker selects one of 4 KA groups.
 * Only concepts belonging to the selected group are plotted.
 * All series values are coerced through Number().toFixed(2) for safe interpolation.
 */
function MasteryTab({ data }) {
  const { sort, onSort } = useSort({ key: "current", dir: "asc" });
  const [activeKA, setActiveKA] = useState(KA_GROUPS[0].code);

  // Determine which concepts belong to the active knowledge area
  const groupConcepts = useMemo(() => {
    const memberIds = new Set(KA_CONCEPT_MEMBERSHIP[activeKA] || []);
    return data.concepts.filter(c => memberIds.has(c.id));
  }, [data.concepts, activeKA]);

  // Auto-select the first group that has data
  useEffect(() => {
    if (groupConcepts.length === 0) {
      const firstWithData = KA_GROUPS.find(g =>
        data.concepts.some(c => (KA_CONCEPT_MEMBERSHIP[g.code] || []).includes(c.id))
      );
      if (firstWithData && firstWithData.code !== activeKA) {
        setActiveKA(firstWithData.code);
      }
    }
  }, [data.concepts, groupConcepts.length, activeKA]);

  // Build chart data with Number().toFixed(2) coercion for all values
  const chartData = useMemo(() =>
    data.weeks.map((week, i) => {
      const row = { week };
      for (const c of groupConcepts) {
        row[c.id] = Number(Number(c.series[i] ?? 0).toFixed(2));
      }
      return row;
    }),
    [data.weeks, groupConcepts]
  );

  const tableRows = useMemo(() =>
    applySort(
      groupConcepts.map(c => ({
        id: c.id,
        name: c.name,
        current: Number(Number(c.current).toFixed(2)),
        delta: c.series.length >= 2
          ? Number((c.series[c.series.length - 1] - c.series[0]).toFixed(2))
          : 0,
        series: c.series.map(v => Number(Number(v).toFixed(2))),
      })),
      sort,
    ),
    [groupConcepts, sort]
  );

  const activeLabel = KA_GROUPS.find(g => g.code === activeKA)?.label || activeKA;

  if (!data.concepts.length) {
    return <EmptyTab message="No mastery data available for this section yet." />;
  }

  return (
    <div className="space-y-6">
      <Card>
        <CardHeader className="pb-3 border-b border-border">
          <div className="flex items-start justify-between gap-4">
            <div className="space-y-1">
              <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">Trend</p>
              <CardTitle className="text-sm font-semibold">
                Concept mastery · {activeLabel}
              </CardTitle>
              <p className="text-[10px] text-muted-foreground">
                {groupConcepts.length
                  ? `${groupConcepts.length} concepts in this group. Click legend items to toggle.`
                  : `No concepts mapped to this group.`}
              </p>
            </div>
          </div>
        </CardHeader>
        <CardContent className="pt-4">
          {/* ── Glassmorphic KA Group Picker ────────────────────────── */}
          <div className="mb-5">
            <div
              role="radiogroup"
              aria-label="Knowledge Area Group"
              className="relative inline-flex flex-wrap items-center justify-center gap-1 rounded-xl bg-white/[0.04] dark:bg-white/[0.04] border border-white/[0.08] backdrop-blur-xl p-1 shadow-[0_2px_12px_rgba(0,0,0,0.12),inset_0_1px_0_rgba(255,255,255,0.06)]"
            >
              {KA_GROUPS.map((group) => {
                const isActive = group.code === activeKA;
                const count = data.concepts.filter(
                  c => (KA_CONCEPT_MEMBERSHIP[group.code] || []).includes(c.id)
                ).length;
                return (
                  <button
                    key={group.code}
                    type="button"
                    role="radio"
                    aria-checked={isActive}
                    onClick={() => setActiveKA(group.code)}
                    className={cn(
                      "relative z-10 px-2.5 py-1.5 sm:px-4 sm:py-2 rounded-lg text-[10px] sm:text-[11px] font-semibold tracking-wide transition-all duration-200 select-none whitespace-nowrap inline-flex items-center gap-1.5 sm:gap-2",
                      isActive
                        ? "text-foreground"
                        : "text-muted-foreground/60 hover:text-foreground/70"
                    )}
                  >
                    {isActive && (
                      <motion.div
                        layoutId="kaGroupIndicator"
                        className="absolute inset-0 bg-white/[0.08] border border-white/[0.1] rounded-lg shadow-[0_2px_8px_rgba(0,0,0,0.15),inset_0_1px_0_rgba(255,255,255,0.08)]"
                        transition={{ type: "spring", stiffness: 400, damping: 30 }}
                      />
                    )}
                    <span className="relative z-10">{group.shortLabel}</span>
                    <span className={cn(
                      "relative z-10 inline-flex items-center justify-center min-w-[16px] h-[16px] sm:min-w-[18px] sm:h-[18px] px-1 rounded-full text-[8px] sm:text-[9px] font-bold tabular-nums",
                      isActive
                        ? "bg-white/[0.12] text-foreground/80"
                        : "bg-white/[0.04] text-muted-foreground/40"
                    )}>
                      {count}
                    </span>
                  </button>
                );
              })}
            </div>
          </div>

          {groupConcepts.length === 0 ? (
            <div className="h-48 flex items-center justify-center text-sm text-muted-foreground">
              No concept data available for {activeLabel} yet.
            </div>
          ) : (
            <>
              {/* ── Multi-Line Chart ────────────────────────────────── */}
              <div className="h-72 w-full">
                <ResponsiveContainer width="100%" height="100%">
                  <LineChart data={chartData} margin={{ top: 8, right: 12, bottom: 0, left: -8 }}>
                    <CartesianGrid stroke="hsl(var(--border))" strokeDasharray="3 3" vertical={false} opacity={0.3} />
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
                    <Tooltip
                      contentStyle={TOOLTIP_STYLE}
                      cursor={{ stroke: "hsl(var(--muted))", strokeDasharray: "3 3" }}
                      formatter={(value, name) => {
                        const c = groupConcepts.find(c => c.id === name);
                        return [`${Number(value).toFixed(2)}%`, c?.name || name];
                      }}
                    />
                    {groupConcepts.map((c, idx) => (
                      <Line
                        key={c.id}
                        type="monotone"
                        dataKey={c.id}
                        name={c.name}
                        stroke={getConceptColor(c.id, idx)}
                        strokeWidth={groupConcepts.length <= 5 ? 2 : 1.5}
                        dot={groupConcepts.length <= 6}
                        dotSize={4}
                        activeDot={{ r: 5, strokeWidth: 0 }}
                        isAnimationActive={false}
                      />
                    ))}
                  </LineChart>
                </ResponsiveContainer>
              </div>

              {/* ── Interactive Legend ───────────────────────────────── */}
              <div className="mt-3 flex flex-wrap gap-x-4 gap-y-1.5 pt-3 border-t border-border/30">
                {groupConcepts.map((c, idx) => (
                  <span
                    key={c.id}
                    className="inline-flex items-center gap-1.5 text-[11px] px-2 py-0.5 rounded-full border border-border/30 bg-background"
                  >
                    <span
                      className="w-2 h-2 rounded-full shrink-0"
                      style={{ backgroundColor: getConceptColor(c.id, idx) }}
                    />
                    <span className="tabular-nums font-medium">{Number(c.current).toFixed(2)}%</span>
                    <span className="text-muted-foreground">{c.name}</span>
                  </span>
                ))}
              </div>
            </>
          )}
        </CardContent>
      </Card>

      {/* ── Concepts Table ──────────────────────────────────────────── */}
      <Card>
        <CardHeader className="pb-3 border-b border-border">
          <CardTitle className="text-sm font-semibold">
            Concepts · {activeLabel} · current vs. {data.weeks.length}w ago
          </CardTitle>
        </CardHeader>
        <CardContent className="p-0">
          <SortableTable
            columns={[
              { key: "name", label: "Concept", align: "left" },
              { key: "sparkline", label: "Trend", align: "center" },
              { key: "current", label: "Current", align: "right" },
              { key: "delta", label: "\u0394", align: "right" },
            ]}
            sort={sort}
            onSort={onSort}
            rows={tableRows}
            renderCell={(col, row) => {
              if (col.key === "name") {
                const idx = groupConcepts.findIndex(c => c.id === row.id);
                return (
                  <span className="text-sm font-medium inline-flex items-center gap-2">
                    <span
                      className="w-2 h-2 rounded-full shrink-0"
                      style={{ backgroundColor: getConceptColor(row.id, idx) }}
                    />
                    {row.name}
                  </span>
                );
              }
              if (col.key === "sparkline") {
                const hasData = row.series.some(v => v > 0);
                if (!hasData) return <span className="text-[10px] text-muted-foreground/40">no data</span>;
                const idx = groupConcepts.findIndex(c => c.id === row.id);
                return <Sparkline data={row.series} width={64} height={20} color={getConceptColor(row.id, idx)} />;
              }
              if (col.key === "current") {
                return <span className="text-sm font-mono tabular-nums">{Number(row.current).toFixed(2)}%</span>;
              }
              if (col.key === "delta") {
                const positive = row.delta > 0;
                return (
                  <span className={cn(
                    "text-xs font-mono tabular-nums",
                    positive ? "text-success" : row.delta < 0 ? "text-destructive" : "text-muted-foreground"
                  )}>
                    {positive ? "+" : ""}{Number(row.delta).toFixed(2)}
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
                <Tooltip contentStyle={TOOLTIP_STYLE} cursor={{ fill: "hsl(var(--muted) / 0.4)" }} formatter={(value) => [`${value}%`]} />
                <Legend wrapperStyle={{ fontSize: "11px", paddingTop: "8px" }} iconType="circle" iconSize={8} />
                <Bar dataKey="on_time" name="On time" stackId="status" fill="hsl(var(--success))" isAnimationActive={false} />
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
              { key: "count", label: "Count", align: "right" },
              { key: "share", label: "Share", align: "right" },
              { key: "delta", label: "Δ", align: "right" },
            ]}
            sort={sort}
            onSort={onSort}
            rows={rows}
            renderCell={(col, row) => {
              if (col.key === "type") return <span className="text-sm font-medium">{row.type}</span>;
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
 * Legacy concept color lookup — delegates to KA-aware getConceptColor.
 * Kept for backward-compat with any remaining direct callers.
 */
const CONCEPT_COLORS = {};
function conceptColor(id) { return getConceptColor(id); }
