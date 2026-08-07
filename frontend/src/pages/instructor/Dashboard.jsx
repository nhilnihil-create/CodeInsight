import { useEffect, useState } from "react";
import { Link } from "react-router-dom";
import {
  Download,
  ArrowRight,
  ChevronDown,
  ShieldAlert,
  TrendingUp,
  BarChart3,
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
} from "recharts";
import { motion } from "framer-motion";
import { Button } from "@/components/ui/button";
import {
  DropdownMenu,
  DropdownMenuContent,
  DropdownMenuItem,
  DropdownMenuTrigger,
} from "@/components/ui/dropdown-menu";
import PeriodSelector from "@/components/ui/period-selector";
import RiskBadge from "@/components/ui/risk-badge";
import { flagTypeLabel } from "@/lib/flagTypes";
import GlassPanel, {
  GlassPanelHeader,
  GlassPanelTitle,
  GlassPanelContent,
} from "@/components/ui/glass-panel";
import GlassDivider from "@/components/ui/glass-divider";
import MasteryBar, { tierForCds, TIER_META } from "@/components/ui/mastery-bar";
import SectionFilter from "@/components/SectionFilter";
import EmptyState from "@/components/ui/empty-state";
import InsightHeader from "@/components/ui/insight-header";
import useLastSection from "@/hooks/useLastSection";
import api from "@/services/api";
import { cn } from "@/lib/utils";

const TOOLTIP_STYLE = {
  backgroundColor: "rgba(19, 27, 46, 0.92)",
  border: "1px solid rgba(255,255,255,0.08)",
  borderRadius: "8px",
  fontSize: "12px",
  color: "hsl(215 32% 86%)",
  backdropFilter: "blur(12px)",
  boxShadow: "0 8px 32px rgba(0,0,0,0.5)",
};

/* ── Stagger config ──────────────────────────────────────────────── */
const stagger = {
  hidden: {},
  show: { transition: { staggerChildren: 0.07, delayChildren: 0.1 } },
};
const fadeUp = {
  hidden: { opacity: 0, y: 12 },
  show: { opacity: 1, y: 0, transition: { duration: 0.5, ease: [0.25, 0.46, 0.45, 0.94] } },
};

export default function InstructorDashboard() {
  const [period, setPeriod] = useState("7d");
  const [sectionId, setSectionId] = useLastSection();
  const [data, setData] = useState(null);
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState(null);

  const days = parseInt(period.replace("d", ""), 10) || 7;

  useEffect(() => {
    if (sectionId == null) { setLoading(false); return; }
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
    const headers = ["Date", "CDS"];
    const rows = data.trend.map((r) =>
      [r.date, r.cds].join(",")
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
    if (!sectionId) return;
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

  /* Derive micro-metrics from KPIs (fall back to raw data) */
  const avgCDSRaw = kpis.find((k) => k.label?.toLowerCase().includes("cds"))?.value ?? "--";
  const studentCount = kpis.find((k) => k.label?.toLowerCase().includes("student"))?.value ?? "--";
  const atRiskCount = kpis.find((k) => k.label?.toLowerCase().includes("risk"))?.value ?? "--";

  const avgCDSNum = parseFloat(avgCDSRaw);
  const avgCDSValid = !isNaN(avgCDSNum);
  const avgCDSColor = avgCDSValid
    ? avgCDSNum <= 0.20 ? "text-slate-300"
      : avgCDSNum <= 0.40 ? "text-emerald-400"
      : avgCDSNum <= 0.60 ? "text-amber-400"
      : avgCDSNum <= 0.80 ? "text-orange-400"
      : "text-rose-400"
    : "text-muted-foreground";
  const avgCDSLabel = avgCDSValid
    ? avgCDSNum <= 0.20 ? "Excellent"
      : avgCDSNum <= 0.40 ? "Nominal"
      : avgCDSNum <= 0.60 ? "Moderate"
      : avgCDSNum <= 0.80 ? "Struggle"
      : "Critical"
    : "";

  return (
    <motion.div variants={stagger} initial="hidden" animate="show" className="space-y-5 sm:space-y-6">
      {/* ── Page Header ───────────────────────────────────────────── */}
      <motion.div variants={fadeUp} className="flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between">
        <div className="min-w-0 space-y-1">
          <h1 className="text-2xl font-semibold tracking-tight text-foreground">
            Class Status
          </h1>
          <p className="text-sm text-muted-foreground/70">
            Aggregated metrics for this section, updated live.
          </p>
        </div>
        <div className="flex items-center gap-2 shrink-0">
          <SectionFilter value={sectionId} onChange={setSectionId} />
          <PeriodSelector value={period} onChange={setPeriod} />
          <DropdownMenu>
            <DropdownMenuTrigger asChild>
              <Button variant="ghost" size="sm" className="font-medium text-muted-foreground" disabled={!trendData.length}>
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
              <DropdownMenuItem onClick={handleExportExcel}>
                <Download className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                Export Excel
              </DropdownMenuItem>
            </DropdownMenuContent>
          </DropdownMenu>
        </div>
      </motion.div>

      {/* ── Insight Banner (glowing accent) ──────────────────── */}
      <motion.section variants={fadeUp} className="relative overflow-hidden rounded-2xl border border-white/[0.06] bg-white/[0.02] backdrop-blur-xl">
        <div className="absolute top-0 inset-x-0 h-px bg-gradient-to-r from-transparent via-emerald-400/60 to-transparent" />
        <div className="relative z-10 flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between px-6 py-5">
          <div className="min-w-0 space-y-1.5">
            <p className="metric-label">Insight</p>
            <h2 className="text-lg font-semibold text-foreground leading-snug">{insight}</h2>
          </div>
          <motion.div whileHover={{ scale: 1.03 }} whileTap={{ scale: 0.97 }} className="shrink-0">
            <Button asChild className="bg-gradient-to-r from-teal-400 to-emerald-500 text-slate-950 font-semibold border-0 hover:shadow-[0_0_24px_rgba(45,212,191,0.4)] transition-shadow duration-300">
              <Link to="/instructor/alerts">
                Open intervention queue
                <ArrowRight className="ml-1.5 h-4 w-4" strokeWidth={2} />
              </Link>
            </Button>
          </motion.div>
        </div>
      </motion.section>

      {/* ── Micro-Metrics Strip (floating typography-first) ─── */}
      <motion.div variants={fadeUp} className="grid grid-cols-2 sm:grid-cols-3 gap-px rounded-2xl overflow-hidden border border-white/[0.06] bg-white/[0.06]">
        {[
          { label: "Avg CDS", value: avgCDSRaw, accent: avgCDSColor, sub: avgCDSLabel },
          { label: "At Risk", value: atRiskCount, accent: "text-amber-400" },
          { label: "Students", value: studentCount, accent: "text-sky-400" },
        ].map((m) => (
          <div key={m.label} className="flex flex-col gap-1 px-5 py-4 bg-white/[0.02] backdrop-blur-xl">
            <span className="metric-label">{m.label}</span>
            <span className={cn("text-3xl font-extrabold tracking-tight font-mono tabular-nums", m.accent)}>
              {m.value}
            </span>
            {m.sub && <span className={cn("text-[11px] font-medium uppercase tracking-wide", m.accent, "opacity-70")}>{m.sub}</span>}
          </div>
        ))}
      </motion.div>

      {/* ── Gradient Divider ─────────────────────────────────── */}
      <GlassDivider />

      {loading ? (
        <GlassPanel variant="dense">
          <GlassPanelContent className="py-16 text-center text-muted-foreground/60 text-sm">
            Loading dashboard data...
          </GlassPanelContent>
        </GlassPanel>
      ) : error ? (
        <GlassPanel variant="dense">
          <GlassPanelContent className="py-16 text-center text-rose-400 text-sm">
            {error}
          </GlassPanelContent>
        </GlassPanel>
      ) : (
        <>
          {/* ── Class Trend Chart ────────────────────────────────── */}
          <motion.div variants={fadeUp}>
            <GlassPanel interactive>
              <GlassPanelHeader>
                <GlassPanelTitle>Class trend</GlassPanelTitle>
              </GlassPanelHeader>
              <GlassPanelContent>
                <div className="h-64 w-full">
                  {trendData.length > 0 ? (
                    <ResponsiveContainer width="100%" height="100%">
                      <LineChart data={trendData} margin={{ top: 8, right: 12, bottom: 0, left: 8 }}>
                        <CartesianGrid stroke="rgba(255,255,255,0.04)" strokeDasharray="3 3" vertical={false} />
                        <XAxis dataKey="date" tick={{ fill: "rgba(255,255,255,0.4)", fontSize: 11 }} axisLine={{ stroke: "rgba(255,255,255,0.06)" }} tickLine={false} />
                        <YAxis domain={[0, 100]} tickFormatter={(v) => `${v}%`} tick={{ fill: "rgba(255,255,255,0.4)", fontSize: 11 }} axisLine={false} tickLine={false} width={40} />
                        <Tooltip contentStyle={TOOLTIP_STYLE} cursor={{ stroke: "rgba(255,255,255,0.06)" }} />
                        <Legend wrapperStyle={{ fontSize: "11px", paddingTop: "8px" }} iconType="circle" iconSize={8} />
                        <Line type="monotone" dataKey="cds" name="CDS" stroke="#f43f5e" strokeWidth={2} dot={false} isAnimationActive={false} />
                      </LineChart>
                    </ResponsiveContainer>
                  ) : (
                    <EmptyState icon={<TrendingUp />} title="No trend data yet" description="Submit some exercises and CDS metrics will populate this chart over time." />
                  )}
                </div>
              </GlassPanelContent>
            </GlassPanel>
          </motion.div>

          {/* ── Gradient Divider ─────────────────────────────────── */}
          <GlassDivider />

          {/* ── Details Grid ─────────────────────────────────────── */}
          <motion.div variants={fadeUp} className="grid gap-5 md:grid-cols-[1.2fr_1fr]">
            {/* Struggling Concepts — neon bars */}
            <GlassPanel interactive>
              <GlassPanelHeader>
                <GlassPanelTitle>Top struggling concepts</GlassPanelTitle>
              </GlassPanelHeader>
              <GlassPanelContent className="p-0">
                {strugglingConcepts.length > 0 ? (
                  <ul className="divide-y divide-white/[0.04]">
                    {strugglingConcepts.map((c, i) => {
                      const cds = (c.cds ?? c.value ?? 0) / 100;
                      const tier = tierForCds(cds);
                      const meta = TIER_META[tier];
                      return (
                        <li key={c.name}>
                          <motion.div whileHover={{ backgroundColor: "rgba(255,255,255,0.025)" }} transition={{ duration: 0.15 }} className="grid grid-cols-[1fr_4.5rem] items-center gap-3 px-5 py-3.5">
                            <div className="min-w-0 space-y-2">
                              <div className="flex items-center gap-2 min-w-0">
                                <span className="text-sm font-medium text-foreground truncate">{c.name}</span>
                                <span className="flex items-center gap-1.5 shrink-0">
                                  <span className={cn("w-1.5 h-1.5 rounded-full", meta.dot)} />
                                  <span className={cn("text-[10px] font-medium uppercase tracking-wider", meta.text)}>{meta.label}</span>
                                </span>
                              </div>
                              <div className="space-y-0.5">
                                <MasteryBar percent={Math.round((1 - cds) * 100)} tier={tier} delay={i * 0.08} />
                                <p className="text-[10px] text-muted-foreground/50 font-mono tabular-nums">
                                  Mastery: {Math.round((1 - cds) * 100)}%
                                </p>
                              </div>
                            </div>
                            <span className="flex flex-col items-end gap-0.5 shrink-0">
                              <span className="text-[10px] text-muted-foreground/40 uppercase tracking-wider">CDS</span>
                              <span className="text-sm font-mono tabular-nums text-foreground font-semibold">{c.cds ?? c.value ?? 0}</span>
                            </span>
                          </motion.div>
                        </li>
                      );
                    })}
                  </ul>
                ) : (
                  <div className="py-12">
                    <EmptyState icon={<BarChart3 />} title="No concept data yet" description="Student submissions will generate concept-level analytics here." />
                  </div>
                )}
              </GlassPanelContent>
            </GlassPanel>

            {/* Recent Integrity Flags */}
            <GlassPanel interactive>
              <GlassPanelHeader>
                <GlassPanelTitle>Recent integrity flags</GlassPanelTitle>
                <Button asChild variant="ghost" size="sm" className="text-xs font-medium text-muted-foreground">
                  <Link to="/instructor/integrity">
                    View all
                    <ArrowRight className="ml-1 h-3 w-3" strokeWidth={2} />
                  </Link>
                </Button>
              </GlassPanelHeader>
              <GlassPanelContent className="p-0">
                {recentFlags.length > 0 ? (
                  <ul className="divide-y divide-white/[0.04]">
                    {recentFlags.map((flag) => (
                      <li key={flag.id}>
                        <motion.div whileHover={{ backgroundColor: "rgba(255,255,255,0.03)", scale: 1.005 }} transition={{ duration: 0.15 }}>
                          <Link to="/instructor/integrity" className="flex items-center gap-3 px-5 h-14">
                            <div className="min-w-0 flex-1">
                              <p className="text-sm font-medium text-foreground truncate">{flag.studentName}</p>
                              <p className="text-[11px] text-muted-foreground/60 truncate">
                                {flagTypeLabel(flag.flagType)}{flag.exerciseTitle ? ` · ${flag.exerciseTitle}` : ""}
                              </p>
                            </div>
                            <div className="flex items-center gap-2.5 shrink-0">
                              <span className="text-[11px] text-muted-foreground/50 font-mono tabular-nums">{flag.timeAgo}</span>
                              <RiskBadge level={flag.severity} />
                            </div>
                          </Link>
                        </motion.div>
                      </li>
                    ))}
                  </ul>
                ) : (
                  <div className="py-12">
                    <EmptyState icon={<ShieldAlert />} title="All clear" description="No integrity flags detected. Student submissions are being monitored automatically." />
                  </div>
                )}
              </GlassPanelContent>
            </GlassPanel>
          </motion.div>
        </>
      )}
    </motion.div>
  );
}
