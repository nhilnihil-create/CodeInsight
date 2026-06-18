import { useState, useEffect } from 'react';
import { Link } from 'react-router-dom';
import { motion } from 'framer-motion';
import { Button } from '@/components/ui/button';
import StudentDashboardShell from '@/components/student-dashboard-shell';
import GlassPanel, {
  GlassPanelContent,
} from '@/components/ui/glass-panel';
import EmptyState from '@/components/ui/empty-state';
import { Sparkles, ChevronRight } from 'lucide-react';
import JoinSectionGate from '@/components/join-section-gate';
import useHasSections from '@/hooks/useHasSections';
import api from '@/services/api';
import { cn } from '@/lib/utils';

/* ── Stagger config ──────────────────────────────────────────────── */
const stagger = {
  hidden: {},
  show: { transition: { staggerChildren: 0.06, delayChildren: 0.1 } },
};

const fadeUp = {
  hidden: { opacity: 0, y: 12 },
  show: { opacity: 1, y: 0, transition: { duration: 0.5, ease: [0.25, 0.46, 0.45, 0.94] } },
};

export default function StudentExercises() {
  const { hasSections, checking, recheck } = useHasSections();
  const [exercises, setExercises] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [fetchKey, setFetchKey] = useState(0);

  useEffect(() => {
    if (hasSections === null || !hasSections) return;
    let cancelled = false;
    const load = async () => {
      try {
        setLoading(true);
        setError(null);
        const res = await api.get('/api/student/exercises');
        if (!cancelled) setExercises(Array.isArray(res.data) ? res.data : []);
      } catch (err) {
        if (!cancelled) setError(err.response?.data?.error || 'Failed to load exercises');
      } finally {
        if (!cancelled) setLoading(false);
      }
    };
    load();
    return () => { cancelled = true; };
  }, [hasSections, fetchKey]);

  const handleJoined = () => {
    recheck();
    setFetchKey((k) => k + 1);
  };

  // ---------- No sections — show join gate ----------
  if (hasSections === false) {
    return <JoinSectionGate onJoined={handleJoined} />;
  }

  // ---------- Loading ----------
  if (checking || loading) {
    return (
      <div className="py-16 text-center text-muted-foreground/60 text-sm">Loading exercises…</div>
    );
  }

  return (
    <StudentDashboardShell
      breadcrumb={[
        { label: 'Student', href: '/student/dashboard' },
        { label: 'Exercises' },
      ]}
      subtitle="Practice and improve your programming skills."
    >
      {error ? (
        <div className="py-16 text-center text-rose-400 text-sm">{error}</div>
      ) : exercises.length === 0 ? (
        <div className="rounded-2xl border border-white/[0.06] bg-white/[0.02] backdrop-blur-xl py-16">
          <EmptyState
            icon={<Sparkles />}
            title="No exercises available yet"
            description="When your instructor publishes exercises, they'll appear here."
          />
        </div>
      ) : (
        <motion.div variants={stagger} initial="hidden" animate="show" className="grid gap-4 md:grid-cols-2 lg:grid-cols-3">
          {exercises.map((ex) => {
            const isCompleted = ex.status === 'completed';
            return (
              <motion.div key={ex.id} variants={fadeUp}>
                <motion.div
                  whileHover={{ scale: 1.015, borderColor: "rgba(255,255,255,0.12)" }}
                  transition={{ type: "spring", stiffness: 400, damping: 25 }}
                  className={cn(
                    "relative rounded-2xl overflow-hidden",
                    "bg-white/[0.02] border border-white/[0.06]",
                    "backdrop-blur-xl noise-overlay",
                    "transition-colors duration-200 hover:bg-white/[0.04]",
                    "flex flex-col h-full"
                  )}
                >
                  {/* Top accent line */}
                  <div className="absolute top-0 inset-x-0 h-px bg-gradient-to-r from-transparent via-white/[0.1] to-transparent" />

                  <GlassPanelContent className="flex flex-col flex-1">
                    {/* Deadline + Status */}
                    <div className="flex items-center justify-between mb-3">
                      {ex.deadline ? (
                        <span className="text-[11px] text-muted-foreground/50 font-mono tabular-nums">
                          Due: {new Date(ex.deadline).toLocaleDateString()}
                        </span>
                      ) : <span />}
                      {isCompleted && (
                        <span className="text-[10px] font-medium uppercase tracking-wider text-emerald-400">
                          Completed
                        </span>
                      )}
                    </div>

                    {/* Title */}
                    <h3 className="text-base font-semibold text-foreground mb-2 leading-snug">
                      {ex.title}
                    </h3>

                    {/* Description */}
                    <p className="text-sm text-muted-foreground/60 mb-4 line-clamp-2 leading-relaxed">
                      {ex.description}
                    </p>

                    {/* Concept tag */}
                    {ex.concept_name && (
                      <div className="mb-4">
                        <span className="inline-flex items-center rounded-full border border-white/[0.08] bg-white/[0.04] px-2 py-0.5 text-[10px] font-mono uppercase tracking-wider text-muted-foreground/70">
                          {ex.concept_name}
                        </span>
                      </div>
                    )}

                    {/* Spacer */}
                    <div className="flex-1" />

                    {/* Action */}
                    <motion.div whileHover={{ scale: 1.02 }} whileTap={{ scale: 0.98 }}>
                      <Button
                        asChild
                        className={cn(
                          "w-full font-medium",
                          isCompleted
                            ? "bg-white/[0.06] hover:bg-white/[0.10] text-foreground border border-white/[0.08]"
                            : "bg-gradient-to-r from-teal-400 to-emerald-500 text-slate-950 font-semibold border-0 hover:shadow-[0_0_20px_rgba(45,212,191,0.4)] transition-shadow duration-300"
                        )}
                        variant={isCompleted ? 'outline' : 'default'}
                        size="sm"
                      >
                        <Link to={`/student/exercises/${ex.id}`}>
                          {isCompleted ? 'Review Exercise' : 'Start Exercise'}
                          {!isCompleted && <ChevronRight className="ml-1 h-3.5 w-3.5" strokeWidth={2} />}
                        </Link>
                      </Button>
                    </motion.div>
                  </GlassPanelContent>
                </motion.div>
              </motion.div>
            );
          })}
        </motion.div>
      )}
    </StudentDashboardShell>
  );
}
