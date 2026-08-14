import { useState, useEffect } from "react";
import { Link } from "react-router-dom";
import {
  ArrowRight,
  Sparkles,
  ChevronRight,
  AlertCircle,
} from "lucide-react";
import { motion } from "framer-motion";
import { Button } from "@/components/ui/button";
import { cn } from "@/lib/utils";
import { formatDurationFromNow } from "@/lib/relative-time";
import EmptyState from "@/components/ui/empty-state";
import InsightHeader from "@/components/ui/insight-header";
import GlassDivider from "@/components/ui/glass-divider";
import GlassPanel, {
  GlassPanelHeader,
  GlassPanelTitle,
  GlassPanelContent,
} from "@/components/ui/glass-panel";
import MasteryBar, { tierForCds, TIER_META } from "@/components/ui/mastery-bar";
import StudentDashboardShell from "@/components/student-dashboard-shell";
import { useStudentContext } from "@/context/StudentContext";
import api from "@/services/api";

function formatToday() {
  const d = new Date();
  const weekday = d.toLocaleDateString("en-US", { weekday: "long" });
  const month = d.toLocaleDateString("en-US", { month: "long" });
  const day = d.getDate();
  return `Today, ${weekday} ${month} ${day}`;
}

const FILL_TONE = {
  low: "bg-success",
  moderate: "bg-warning",
  high: "bg-destructive",
};

function Skeleton({ className }) {
  return <div className={cn("animate-pulse rounded-md bg-muted", className)} />;
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

export default function StudentDashboard() {
  const { activeSectionId } = useStudentContext();
  const [data, setData] = useState(null);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [retryCount, setRetryCount] = useState(0);

  useEffect(() => {
    let cancelled = false;
    async function load() {
      try {
        setLoading(true);
        setError(null);
        const res = await api.get("/api/student/dashboard", {
          params: activeSectionId ? { sectionId: activeSectionId } : {},
        });
        if (!cancelled) setData(res.data);
      } catch (err) {
        if (!cancelled) setError(err.message);
      } finally {
        if (!cancelled) setLoading(false);
      }
    }
    load();
    return () => { cancelled = true; };
  }, [activeSectionId, retryCount]);

  // ---------- Loading page data ----------
  if (loading) {
    return (
      <StudentDashboardShell>
        <div className="space-y-6">
          <div className="flex items-center justify-between">
            <div className="space-y-2">
              <Skeleton className="h-7 w-64" />
              <Skeleton className="h-4 w-48" />
            </div>
            <Skeleton className="h-9 w-24" />
          </div>
          <Skeleton className="h-24 w-full rounded-2xl" />
          <div className="grid grid-cols-2 lg:grid-cols-4 gap-px rounded-2xl overflow-hidden border border-white/[0.06] bg-white/[0.06]">
            {[1, 2, 3].map(i => (
              <Skeleton key={i} className="h-28 w-full rounded-none" />
            ))}
          </div>
          <div className="grid gap-5 sm:grid-cols-2">
            <Skeleton className="h-64 w-full rounded-2xl" />
            <Skeleton className="h-64 w-full rounded-2xl" />
          </div>
          <Skeleton className="h-48 w-full rounded-2xl" />
        </div>
      </StudentDashboardShell>
    );
  }

  // ---------- Error state ----------
  if (error) {
    return (
      <StudentDashboardShell>
        <div className="flex flex-col items-center justify-center py-16 gap-4 text-center">
          <AlertCircle className="h-10 w-10 text-destructive" strokeWidth={1.5} />
          <div className="space-y-1">
            <p className="text-base font-semibold text-foreground">Failed to load dashboard</p>
            <p className="text-sm text-muted-foreground max-w-sm">{error}</p>
          </div>
          <Button variant="outline" size="sm" onClick={() => setRetryCount(c => c + 1)}>
            Try again
          </Button>
        </div>
      </StudentDashboardShell>
    );
  }

  // ---------- Derived data ----------
  const due = data.dueExercises;
  const dueCount = due?.count ?? 0;
  const nearest = due?.nearestDeadline;
  const mastery = data.mastery;
  const completion = data.completion;
  const avgCds = data.avgCds ?? 0;
  const weakest = data.weakestConcepts ?? [];
  const recs = data.recommended ?? [];

  // Due-soon banner state (split due vs overdue, human-readable durations).
  const overdueCount = due?.overdueCount ?? 0;
  const min = nearest?.minutesUntilDue ?? null;
  const overdue = (nearest?.minutesUntilDue ?? 0) < 0;
  const duration = formatDurationFromNow(min);
  const bannerTone = overdue ? 'rose' : (min !== null && min <= 1440 ? 'amber' : 'emerald');

  // Empty-state gate: enrolled but no exercises assigned yet
  const hasAnyData = mastery?.percentage > 0 || completion?.completed > 0 || weakest.length > 0 || recs.length > 0 || dueCount > 0;
  if (!hasAnyData && !nearest) {
    return (
      <StudentDashboardShell>
        <EmptyState
          icon={<Sparkles />}
          title="No exercises yet"
          description="Your instructor hasn't published exercises for your section yet. Check back soon!"
        />
      </StudentDashboardShell>
    );
  }

  return (
    <StudentDashboardShell>
      <motion.div variants={stagger} initial="hidden" animate="show" className="space-y-5">
        {/* ═══════════════════════════════════════════════════════════
            PAGE HEADER — floating typography
           ═══════════════════════════════════════════════════════════ */}
        <motion.header variants={fadeUp} className="flex items-center justify-between gap-3">
          <div className="min-w-0 space-y-0.5">
            <h1 className="text-2xl font-semibold tracking-tight truncate text-foreground">
              {formatToday()}
            </h1>
            <p className="text-xs text-muted-foreground/60 sm:text-sm">
              {overdueCount > 0 && dueCount - overdueCount > 0
                ? `${dueCount - overdueCount} exercise${(dueCount - overdueCount) > 1 ? 's' : ''} due this week · ${overdueCount} overdue`
                : overdueCount > 0
                  ? `${overdueCount} exercise${overdueCount > 1 ? 's' : ''} overdue`
                  : dueCount > 0
                    ? `${dueCount} exercise${dueCount > 1 ? 's' : ''} due this week`
                    : "No exercises due this week"}
            </p>
          </div>
          <Button asChild variant="ghost" size="sm" className="font-medium shrink-0 text-muted-foreground hover:text-foreground">
            <Link to="/student/exercises">
              View all
              <ChevronRight className="ml-1 h-3.5 w-3.5" strokeWidth={1.5} />
            </Link>
          </Button>
        </motion.header>

        {/* ═══════════════════════════════════════════════════════════
            SECTION 1 — TRAJECTORY BANNER (glowing accent border)
           ═══════════════════════════════════════════════════════════ */}
        {nearest ? (
          <motion.section variants={fadeUp}>
            <InsightHeader
              eyebrow={overdue ? 'Overdue' : dueCount > 0 ? 'Due soon' : 'Next up'}
              insight={duration === null
                ? 'No deadline set for this exercise.'
                : duration === 'now'
                  ? `${nearest.title} (${nearest.concept}) is due now.`
                  : overdue
                    ? `${nearest.title} (${nearest.concept}) is ${duration} overdue.`
                    : `${nearest.title} (${nearest.concept}) is due in ${duration}.`}
              description={duration === null
                ? `Targets: ${nearest.concept}`
                : duration === 'now'
                  ? `Due now · Targets: ${nearest.concept}`
                  : overdue
                    ? `Overdue by ${duration} · Targets: ${nearest.concept}`
                    : `Due in ${duration} · Targets: ${nearest.concept}`}
              tone={bannerTone}
              action={
                <motion.div whileHover={{ scale: 1.03 }} whileTap={{ scale: 0.97 }}>
                  <Button asChild size="sm" className="bg-gradient-to-r from-teal-400 to-emerald-500 text-slate-950 font-semibold border-0 hover:shadow-[0_0_24px_rgba(45,212,191,0.4)] transition-shadow duration-300">
                    <Link to={`/student/exercises/${nearest.id}`}>
                      {(nearest.isCompleted ?? nearest.status === 'completed') ? 'Review' : 'Start'}
                      <ArrowRight className="ml-1.5 h-3.5 w-3.5" strokeWidth={2} />
                    </Link>
                  </Button>
                </motion.div>
              }
            />
          </motion.section>
        ) : null}

        {/* ═══════════════════════════════════════════════════════════
            SECTION 2 — FLOATING MICRO-METRICS (typography-first)
           ═══════════════════════════════════════════════════════════ */}
        <motion.div
          variants={fadeUp}
          className="grid grid-cols-3 gap-px rounded-2xl overflow-hidden border border-white/[0.06] bg-white/[0.06]"
        >
          {[
            { label: "Mastery", value: `${mastery?.percentage ?? 0}%`, sub: "concept understanding", accent: "text-teal-400" },
            { label: "Completion", value: `${completion?.percentage ?? 0}%`, sub: `${completion?.completed ?? 0}/${completion?.total ?? 0} exercises`, accent: "text-emerald-400" },
            { label: "Avg CDS", value: avgCds.toFixed(2), sub: avgCds <= 0.20 ? "on track" : avgCds <= 0.40 ? "fair" : avgCds <= 0.60 ? "moderate" : avgCds <= 0.80 ? "needs focus" : "critical", accent: avgCds <= 0.20 ? "text-emerald-400" : avgCds <= 0.40 ? "text-teal-400" : avgCds <= 0.60 ? "text-amber-400" : avgCds <= 0.80 ? "text-orange-400" : "text-rose-400" },
          ].map((m) => (
            <div
              key={m.label}
              className="relative flex flex-col gap-1 px-5 py-5 bg-white/[0.02] backdrop-blur-xl"
            >
              <span className="metric-label">{m.label}</span>
              <span className={cn("text-3xl font-extrabold tracking-tight font-mono tabular-nums", m.accent)}>
                {m.value}
              </span>
              <span className="text-[11px] text-muted-foreground/50">{m.sub}</span>
            </div>
          ))}
        </motion.div>

        {/* ═══════════════════════════════════════════════════════════
            SECTION 3 — WEAKEST CONCEPTS
           ═══════════════════════════════════════════════════════════ */}
        <motion.div variants={fadeUp}>
          {/* Weakest Concepts */}
          <GlassPanel interactive>
            <GlassPanelHeader>
              <GlassPanelTitle>Focus areas</GlassPanelTitle>
              <Sparkles className="h-4 w-4 text-muted-foreground/50" strokeWidth={1.5} />
            </GlassPanelHeader>
            <GlassPanelContent className="p-0">
              {weakest.length > 0 ? (
                <ul>
                  {weakest.map((c, i) => {
                    const cds = c.avgCds ?? (1 - (c.mastery ?? 0) / 100);
                    const tier = tierForCds(cds);
                    const meta = TIER_META[tier];
                    const displayValue = Math.round((1 - cds) * 100);
                    return (
                      <li key={c.name}>
                        <motion.div
                          whileHover={{ backgroundColor: "rgba(255,255,255,0.025)" }}
                          transition={{ duration: 0.15 }}
                          className={cn(
                            "grid grid-cols-[1fr_3.5rem] items-center gap-3 px-5 py-3.5",
                            i < weakest.length - 1 && "border-b border-white/[0.04]"
                          )}
                        >
                          <div className="min-w-0 space-y-2">
                            <div className="flex items-center gap-2.5 min-w-0">
                              <span className="text-sm font-medium text-foreground truncate">
                                {c.name}
                              </span>
                              <span className="flex items-center gap-1.5 shrink-0">
                                <span className={cn("w-1.5 h-1.5 rounded-full", meta.dot)} />
                                <span className={cn("text-[10px] font-medium uppercase tracking-wider", meta.text)}>
                                  {meta.label}
                                </span>
                              </span>
                            </div>
                            <p className="text-[11px] text-muted-foreground/60 truncate">{c.hint}</p>
                            <MasteryBar percent={displayValue} tier={tier} delay={i * 0.08} />
                          </div>
                          <span className="text-sm font-mono tabular-nums text-foreground font-semibold">
                            {displayValue}%
                          </span>
                        </motion.div>
                      </li>
                    );
                  })}
                </ul>
              ) : (
                <div className="py-12">
                  <EmptyState
                    icon={<Sparkles />}
                    title="No progress yet"
                    description="Complete exercises to see your concept breakdown here."
                  />
                </div>
              )}
            </GlassPanelContent>
          </GlassPanel>
        </motion.div>

        <GlassDivider />

        {/* ═══════════════════════════════════════════════════════════
            SECTION 4 — RECOMMENDED NEXT
           ═══════════════════════════════════════════════════════════ */}
        <motion.section variants={fadeUp}>
          <GlassPanel interactive>
            <GlassPanelHeader>
              <div className="flex items-center gap-2">
                <GlassPanelTitle>Recommended next</GlassPanelTitle>
                <span className="text-[10px] font-mono uppercase tracking-wider text-muted-foreground/50">
                  Up next
                </span>
              </div>
              <Button asChild variant="ghost" size="sm" className="font-medium -mr-2 text-muted-foreground hover:text-foreground">
                <Link to="/student/exercises">
                  See all
                  <ChevronRight className="ml-1 h-3.5 w-3.5" strokeWidth={1.5} />
                </Link>
              </Button>
            </GlassPanelHeader>
            <GlassPanelContent className="p-0">
              {recs.length > 0 ? (
                <ul className="divide-y divide-white/[0.04]">
                  {recs.map((r, idx) => (
                    <li key={r.id}>
                      <motion.div
                        whileHover={{ backgroundColor: "rgba(255,255,255,0.025)", scale: 1.005 }}
                        transition={{ duration: 0.15 }}
                      >
                        <Link
                          to={`/student/exercises/${r.id}`}
                          className="flex items-center gap-3 px-5 py-4 focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-ring focus-visible:ring-inset"
                        >
                          <span
                            className="flex h-7 w-7 shrink-0 items-center justify-center rounded-full bg-white/[0.05] border border-white/[0.06] text-xs font-semibold text-muted-foreground font-mono tabular-nums"
                            aria-hidden="true"
                          >
                            {idx + 1}
                          </span>
                          <div className="min-w-0 flex-1">
                            <div className="flex items-center gap-2 min-w-0">
                              <p className="text-sm font-medium text-foreground truncate">
                                {r.title}
                              </p>
                              {r.concept && (
                                <span className="shrink-0 inline-flex items-center rounded-full border border-white/[0.08] bg-white/[0.04] px-1.5 py-0.5 text-[10px] font-mono uppercase tracking-wider text-muted-foreground/70">
                                  {r.conceptName || r.concept}
                                </span>
                              )}
                            </div>
                            <p className="mt-0.5 text-xs text-muted-foreground/50 truncate">
                              {r.blurb} · ~{r.minutes} min
                            </p>
                          </div>
                          <ChevronRight
                            className="h-4 w-4 text-muted-foreground/40 shrink-0"
                            strokeWidth={1.5}
                            aria-hidden="true"
                          />
                        </Link>
                      </motion.div>
                    </li>
                  ))}
                </ul>
              ) : (
                <div className="py-12">
                  <EmptyState
                    icon={<Sparkles />}
                    title="No exercises available yet"
                    description="When your instructor publishes exercises, they'll appear here as recommendations."
                  />
                </div>
              )}
            </GlassPanelContent>
          </GlassPanel>
        </motion.section>
      </motion.div>
    </StudentDashboardShell>
  );
}
