import { useState, useEffect } from "react";
import { Link } from "react-router-dom";
import {
  ArrowRight,
  TrendingUp,
  TrendingDown,
  Minus,
  RefreshCw,
  Sparkles,
} from "lucide-react";
import { motion } from "framer-motion";
import { Button } from "@/components/ui/button";
import PeriodSelector from "@/components/ui/period-selector";
import GlassDivider from "@/components/ui/glass-divider";
import GlassPanel, {
  GlassPanelHeader,
  GlassPanelTitle,
  GlassPanelContent,
} from "@/components/ui/glass-panel";
import MasteryBar, { tierForCds, TIER_META } from "@/components/ui/mastery-bar";
import StudentDashboardShell from "@/components/student-dashboard-shell";
import EmptyState from "@/components/ui/empty-state";
import { useStudentContext } from "@/context/StudentContext";
import api from "@/services/api";
import { cn } from "@/lib/utils";

const PERIOD_OPTIONS = ["7d", "30d", "90d", "All"];

/**
 * METRIC SEMANTICS:
 * CDS (Concept Difficulty Score) — lower is BETTER.
 * Mastery = 100 - CDS — higher is BETTER.
 * Completion = completed exercises / assigned exercises.
 * Progress = change in mastery over time.
 */

function trendIcon(delta) {
  if (delta > 0) return <TrendingUp className="h-3 w-3" strokeWidth={2} aria-hidden="true" />;
  if (delta < 0) return <TrendingDown className="h-3 w-3" strokeWidth={2} aria-hidden="true" />;
  return <Minus className="h-3 w-3" strokeWidth={2} aria-hidden="true" />;
}

function trendTone(delta) {
  if (delta === 0) return "text-muted-foreground/50";
  return delta > 0 ? "text-emerald-400" : "text-rose-400";
}

/* ── Stagger config ──────────────────────────────────────────────── */
const stagger = {
  hidden: {},
  show: { transition: { staggerChildren: 0.07, delayChildren: 0.1 } },
};

const fadeUp = {
  hidden: { opacity: 0, y: 12 },
  show: { opacity: 1, y: 0, transition: { duration: 0.5, ease: [0.25, 0.46, 0.45, 0.94] } },
};

export default function StudentProgress() {
  const { activeSectionId } = useStudentContext();
  const [period, setPeriod] = useState("30d");
  const [data, setData] = useState(null);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [refetching, setRefetching] = useState(false);

  const days = period === "All" ? 365 : parseInt(period.replace("d", ""), 10) || 30;

  useEffect(() => {
    let cancelled = false;
    const load = async () => {
      setLoading(true);
      try {
        const params = { days };
        if (activeSectionId) params.sectionId = activeSectionId;
        const res = await api.get(`/api/student/progress`, { params });
        if (!cancelled) setData(res.data);
      } catch (err) {
        if (!cancelled) setError(err.response?.data?.error || "Failed to load progress");
      } finally {
        if (!cancelled) setLoading(false);
      }
    };
    load();
    return () => { cancelled = true; };
  }, [activeSectionId, days]);

  const overallMastery = data?.overallMastery ?? 0;
  const completion = data?.completion;
  const completionPct = completion?.percentage ?? 0;
  const completedEx = completion?.completed ?? 0;
  const totalEx = completion?.total ?? 0;
  const avgAttempts = data?.avgAttempts ?? 0;
  const concepts = data?.concepts ?? [];
  const trajectory = data?.trajectory;

  return (
    <StudentDashboardShell
      breadcrumb={[
        { label: "Student", href: "/student/dashboard" },
        { label: "Progress" },
      ]}
      subtitle="Mastery, completion, and submissions over the selected window."
      action={
        <div className="flex items-center gap-3">
          <span className="inline-flex items-center gap-1.5 text-[10px] font-mono uppercase tracking-wider text-muted-foreground/60">
            <RefreshCw className={cn("h-3 w-3", refetching && "animate-spin")} />
            {loading ? "Loading…" : `${concepts.length} concepts · ${completedEx}/${totalEx} done`}
          </span>
          <PeriodSelector value={period} onChange={setPeriod} options={PERIOD_OPTIONS} />
        </div>
      }
    >
      {loading ? (
        <div className="py-16 text-center text-muted-foreground/60 text-sm">Loading progress...</div>
      ) : error ? (
        <div className="py-16 text-center text-rose-400 text-sm">{error}</div>
      ) : (
        <motion.div variants={stagger} initial="hidden" animate="show" className="space-y-5">
          {/* ═══════════════════════════════════════════════════════════
              SECTION 1 — TRAJECTORY BANNER (glowing accent border)
             ═══════════════════════════════════════════════════════════ */}
          <motion.section
            variants={fadeUp}
            className="relative overflow-hidden rounded-2xl border border-white/[0.06] bg-white/[0.02] backdrop-blur-xl"
          >
            {/* Ambient glow line at top */}
            <div className="absolute top-0 inset-x-0 h-px bg-gradient-to-r from-transparent via-teal-400/60 to-transparent" />

              <div className="relative z-10 flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between px-6 py-5">
                <div className="min-w-0 space-y-1.5">
                  <p className="metric-label flex items-center gap-1.5">
                    <Sparkles className="w-3 h-3 text-teal-400" />
                    Trajectory
                  </p>
                  <h2 className="text-lg font-semibold text-foreground leading-snug">
                    {trajectory?.message ?? `Your mastery is ${overallMastery}% across ${concepts.length} concept${concepts.length !== 1 ? "s" : ""}.`}
                  </h2>
                  <p className="text-sm text-muted-foreground/60">
                    {trajectory?.detail ?? `Avg attempts: ${avgAttempts.toFixed(1)} per exercise`}
                  </p>
                </div>

                {/* Floating action button with ambient glow */}
                <motion.div whileHover={{ scale: 1.03 }} whileTap={{ scale: 0.97 }} className="shrink-0">
                  <Button
                    asChild
                    className="bg-gradient-to-r from-teal-400 to-emerald-500 text-slate-950 font-semibold border-0 hover:shadow-[0_0_24px_rgba(45,212,191,0.4)] transition-shadow duration-300"
                  >
                    <Link to={trajectory?.actionTo ?? "/student/exercises"}>
                      {trajectory?.actionLabel ?? "Practice"}
                      <ArrowRight className="ml-1.5 h-4 w-4" strokeWidth={2} />
                    </Link>
                  </Button>
                </motion.div>
              </div>
          </motion.section>

          {/* ═══════════════════════════════════════════════════════════
              SECTION 2 — FLOATING MICRO-METRICS (typography-first)
             ═══════════════════════════════════════════════════════════ */}
          <motion.div
            variants={fadeUp}
            className="grid grid-cols-1 sm:grid-cols-3 gap-px rounded-2xl overflow-hidden border border-white/[0.06] bg-white/[0.06]"
          >
            {[
              { label: "Mastery", value: `${overallMastery}%`, sub: "concept understanding", accent: "text-teal-400" },
              { label: "Completion", value: `${completionPct}%`, sub: `${completedEx}/${totalEx} exercises`, accent: "text-emerald-400" },
              { label: "Avg Attempts", value: avgAttempts.toFixed(1), sub: "per exercise", accent: "text-amber-400" },
            ].map((m) => (
              <div
                key={m.label}
                className="relative flex flex-col gap-1 px-6 py-5 bg-white/[0.02] backdrop-blur-xl"
              >
                <span className="metric-label">{m.label}</span>
                <span className={cn("text-4xl font-extrabold tracking-tight font-mono tabular-nums", m.accent)}>
                  {m.value}
                </span>
                <span className="text-[11px] text-muted-foreground/50">{m.sub}</span>
              </div>
            ))}
          </motion.div>

          <GlassDivider />

          {/* ═══════════════════════════════════════════════════════════
              SECTION 3 — PER-CONCEPT MASTERY (neon tracks)
             ═══════════════════════════════════════════════════════════ */}
          <motion.section variants={fadeUp}>
            {concepts.length === 0 ? (
              <div className="rounded-2xl border border-white/[0.06] bg-white/[0.02] backdrop-blur-xl py-16 text-center text-muted-foreground/60 text-sm">
                No concept data yet. Complete some exercises to see your mastery profile.
              </div>
            ) : (
              <GlassPanel interactive>
                <GlassPanelHeader>
                  <div className="flex items-center gap-2">
                    <GlassPanelTitle>Per-Concept Mastery</GlassPanelTitle>
                    <span className="text-[10px] font-mono uppercase tracking-wider text-muted-foreground/50">
                      {concepts.length} tracked concept{concepts.length !== 1 ? "s" : ""}
                    </span>
                  </div>
                </GlassPanelHeader>
                <GlassPanelContent className="p-0">
                  <ul>
                    {concepts.map((c, i) => {
                      const cds = c.cds ?? (1 - (c.mastery ?? 0) / 100);
                      const tier = tierForCds(cds);
                      const meta = TIER_META[tier];
                      return (
                        <li key={c.concept_code}>
                          <motion.div
                            whileHover={{ backgroundColor: "rgba(255,255,255,0.025)" }}
                            transition={{ duration: 0.15 }}
                            className={cn(
                              "grid grid-cols-[1fr_auto_auto] items-center gap-4 px-6 py-4",
                              i < concepts.length - 1 && "border-b border-white/[0.04]"
                            )}
                          >
                            {/* Name + bar */}
                            <div className="min-w-0 space-y-2">
                              <div className="flex items-center gap-2.5 min-w-0">
                                <span className="text-sm font-medium text-foreground truncate">
                                  {c.concept_name}
                                </span>
                                <span className="flex items-center gap-1.5 shrink-0">
                                  <span className={cn("w-1.5 h-1.5 rounded-full", meta.dot)} />
                                  <span className={cn("text-[10px] font-medium uppercase tracking-wider", meta.text)}>
                                    {meta.label}
                                  </span>
                                </span>
                              </div>
                              <MasteryBar percent={c.mastery ?? 0} tier={tier} delay={i * 0.08} />
                            </div>

                            {/* Percentage */}
                            <span className="text-sm font-mono tabular-nums text-foreground font-semibold">
                              {c.mastery ?? 0}%
                            </span>

                            {/* Delta */}
                            <span
                              className={cn(
                                "inline-flex items-center gap-1 text-xs font-mono tabular-nums w-12 justify-end",
                                trendTone(c.delta ?? 0)
                              )}
                            >
                              {trendIcon(c.delta ?? 0)}
                              {(c.delta ?? 0) > 0 ? "+" : ""}
                              {c.delta ?? 0}
                            </span>
                          </motion.div>
                        </li>
                      );
                    })}
                  </ul>
                </GlassPanelContent>
              </GlassPanel>
            )}
          </motion.section>
        </motion.div>
      )}
    </StudentDashboardShell>
  );
}
