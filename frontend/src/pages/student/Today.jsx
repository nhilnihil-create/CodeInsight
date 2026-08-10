import { useState, useEffect } from 'react';
import { Link } from 'react-router-dom';
import { motion } from 'framer-motion';
import { Button } from '@/components/ui/button';
import { cn } from '@/lib/utils';
import CDSPillDelta from '@/components/CDSPillDelta';
import StudentDashboardShell from '@/components/student-dashboard-shell';
import GlassPanel, {
  GlassPanelHeader,
  GlassPanelTitle,
  GlassPanelContent,
} from '@/components/ui/glass-panel';
import GlassDivider from '@/components/ui/glass-divider';
import MasteryBar, { tierForCds, TIER_META } from '@/components/ui/mastery-bar';
import EmptyState from '@/components/ui/empty-state';
import { Sparkles, ArrowRight } from 'lucide-react';
import { useStudentContext } from '@/context/StudentContext';
import api from '@/services/api';

/* ── Stagger config ──────────────────────────────────────────────── */
const stagger = {
  hidden: {},
  show: { transition: { staggerChildren: 0.07, delayChildren: 0.1 } },
};

const fadeUp = {
  hidden: { opacity: 0, y: 12 },
  show: { opacity: 1, y: 0, transition: { duration: 0.5, ease: [0.25, 0.46, 0.45, 0.94] } },
};

export default function StudentToday() {
  const { activeSectionId } = useStudentContext();
  const [data, setData] = useState(null);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);

  useEffect(() => {
    let cancelled = false;
    const load = async () => {
      try {
        setLoading(true);
        setError(null);
        const res = await api.get('/api/student/today', {
          params: activeSectionId ? { sectionId: activeSectionId } : {},
        });
        if (!cancelled) setData(res.data);
      } catch (err) {
        if (!cancelled) setError(err.response?.data?.error || 'Failed to load today\'s plan');
      } finally {
        if (!cancelled) setLoading(false);
      }
    };
    load();
    return () => { cancelled = true; };
  }, [activeSectionId]);

  if (loading) {
    return (
      <StudentDashboardShell
        breadcrumb={[
          { label: 'Student', href: '/student/dashboard' },
          { label: "Today's Plan" },
        ]}
      >
        <div className="py-16 text-center text-muted-foreground/60 text-sm">Loading today's plan…</div>
      </StudentDashboardShell>
    );
  }

  if (error) {
    return (
      <StudentDashboardShell
        breadcrumb={[
          { label: 'Student', href: '/student/dashboard' },
          { label: "Today's Plan" },
        ]}
      >
        <div className="py-16 text-center text-rose-400 text-sm">{error}</div>
      </StudentDashboardShell>
    );
  }

  const focus = data.focus || {};
  const why = data.why || '';
  const classAvg = data.classAvg ?? 0;
  const nextMoves = data.nextMoves || [];

  return (
    <StudentDashboardShell
      breadcrumb={[
        { label: 'Student', href: '/student/dashboard' },
        { label: "Today's Plan" },
      ]}
    >
      <motion.div variants={stagger} initial="hidden" animate="show" className="space-y-5">
        {/* ═══════════════════════════════════════════════════════════
            FOCUS BANNER — glowing accent border
           ═══════════════════════════════════════════════════════════ */}
        {focus.title && (
          <motion.section
            variants={fadeUp}
            className="relative overflow-hidden rounded-2xl border border-white/[0.06] bg-white/[0.02] backdrop-blur-xl"
          >
            <div className="absolute top-0 inset-x-0 h-px bg-gradient-to-r from-transparent via-teal-400/60 to-transparent" />
            <div className="relative z-10 px-6 py-5 space-y-1.5">
              <p className="metric-label flex items-center gap-1.5">
                <Sparkles className="w-3 h-3 text-teal-400" />
                What
              </p>
              <h2 className="text-lg font-semibold text-foreground leading-snug">{focus.title}</h2>
              {focus.estimatedMinutes && (
                <p className="text-sm text-muted-foreground/60">
                  Estimated {focus.estimatedMinutes}
                </p>
              )}
            </div>
          </motion.section>
        )}

        {/* ═══════════════════════════════════════════════════════════
            WHY + CLASS AVG
           ═══════════════════════════════════════════════════════════ */}
        {(why || classAvg > 0) && (
          <motion.div variants={fadeUp} className="grid gap-5 sm:grid-cols-2">
            {why && (
              <GlassPanel interactive>
                <GlassPanelHeader>
                  <GlassPanelTitle>Why</GlassPanelTitle>
                </GlassPanelHeader>
                <GlassPanelContent>
                  <p className="text-sm text-muted-foreground/70 leading-relaxed">{why}</p>
                </GlassPanelContent>
              </GlassPanel>
            )}
            <GlassPanel interactive>
              <GlassPanelHeader>
                <GlassPanelTitle>Who</GlassPanelTitle>
              </GlassPanelHeader>
              <GlassPanelContent>
                <p className="text-sm text-muted-foreground/70">
                  You. Class avg on this concept:{' '}
                  <CDSPillDelta
                    value={classAvg}
                    classification={classAvg <= 0.20 ? 'very_low' : classAvg <= 0.40 ? 'low' : classAvg <= 0.60 ? 'moderate' : classAvg <= 0.80 ? 'elevated' : 'high'}
                  />
                </p>
              </GlassPanelContent>
            </GlassPanel>
          </motion.div>
        )}

        {/* ═══════════════════════════════════════════════════════════
            NEXT MOVES — floating action buttons
           ═══════════════════════════════════════════════════════════ */}
        {nextMoves.length > 0 && (
          <motion.div variants={fadeUp} className="flex gap-3 flex-wrap">
            {nextMoves.map((move, i) => (
              <motion.div key={i} whileHover={{ scale: 1.03 }} whileTap={{ scale: 0.97 }}>
                <Button
                  asChild
                  variant={move.primary ? 'default' : 'outline'}
                  size="sm"
                  className={move.primary
                    ? "bg-gradient-to-r from-teal-400 to-emerald-500 text-slate-950 font-semibold border-0 hover:shadow-[0_0_24px_rgba(45,212,191,0.4)] transition-shadow duration-300"
                    : undefined}
                >
                  <Link to={move.to}>
                    {move.label}
                    {move.primary && <ArrowRight className="ml-1.5 h-3.5 w-3.5" strokeWidth={2} />}
                  </Link>
                </Button>
              </motion.div>
            ))}
          </motion.div>
        )}

        <GlassDivider />

        {/* ═══════════════════════════════════════════════════════════
            CONCEPT MASTERY — neon tracks
           ═══════════════════════════════════════════════════════════ */}
        <motion.section variants={fadeUp}>
          {data.concepts?.length > 0 ? (
            <GlassPanel interactive>
              <GlassPanelHeader>
                <GlassPanelTitle>Your Concept Mastery</GlassPanelTitle>
              </GlassPanelHeader>
              <GlassPanelContent className="p-0">
                <ul>
                  {data.concepts.map((c, i) => {
                    const tier = tierForCds(c.cds);
                    const meta = TIER_META[tier];
                    const mastery = Math.round((1 - c.cds) * 100);
                    return (
                      <li key={c.concept}>
                        <motion.div
                          whileHover={{ backgroundColor: "rgba(255,255,255,0.025)" }}
                          transition={{ duration: 0.15 }}
                          className={cn(
                            "grid grid-cols-[1fr_auto_auto] items-center gap-4 px-6 py-4",
                            i < data.concepts.length - 1 && "border-b border-white/[0.04]"
                          )}
                        >
                          <div className="min-w-0 space-y-2">
                            <div className="flex items-center gap-2.5 min-w-0">
                              <span className="text-sm font-medium text-foreground truncate">
                                {c.concept}
                              </span>
                              <CDSPillDelta
                                value={c.cds}
                                delta={c.delta}
                                trend={c.trend}
                                classification={c.cds <= 0.20 ? 'very_low' : c.cds <= 0.40 ? 'low' : c.cds <= 0.60 ? 'moderate' : c.cds <= 0.80 ? 'elevated' : 'high'}
                              />
                              <span className="flex items-center gap-1.5 shrink-0">
                                <span className={cn("w-1.5 h-1.5 rounded-full", meta.dot)} />
                                <span className={cn("text-[10px] font-medium uppercase tracking-wider", meta.text)}>
                                  {meta.label}
                                </span>
                              </span>
                            </div>
                            <MasteryBar percent={mastery} tier={tier} delay={i * 0.08} />
                          </div>
                          <span className="text-sm font-mono tabular-nums text-foreground font-semibold">
                            {mastery}%
                          </span>
                        </motion.div>
                      </li>
                    );
                  })}
                </ul>
              </GlassPanelContent>
            </GlassPanel>
          ) : (
            <div className="rounded-2xl border border-white/[0.06] bg-white/[0.02] backdrop-blur-xl py-16">
              <EmptyState
                icon={<Sparkles />}
                title="No concept data yet"
                description="Complete exercises to see your concept mastery."
              />
            </div>
          )}
        </motion.section>

        {/* ═══════════════════════════════════════════════════════════
            SIGNALS — subtle alert strip
           ═══════════════════════════════════════════════════════════ */}
        {data.signals?.length > 0 && (
          <motion.section variants={fadeUp}>
            <div className="rounded-2xl border border-dashed border-white/[0.08] bg-white/[0.02] backdrop-blur-xl px-5 py-4 space-y-2">
              {data.signals.map((s, i) => (
                <p key={i} className="text-sm text-muted-foreground/60">
                  <span className="text-muted-foreground/30 mr-1.5" aria-hidden="true">•</span>
                  {s}
                </p>
              ))}
            </div>
          </motion.section>
        )}
      </motion.div>
    </StudentDashboardShell>
  );
}
