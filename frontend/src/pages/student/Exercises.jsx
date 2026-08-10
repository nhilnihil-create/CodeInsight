import { useState, useEffect, useCallback, useMemo, useRef } from 'react';
import { Link } from 'react-router-dom';
import { motion } from 'framer-motion';
import { Button } from '@/components/ui/button';
import StudentDashboardShell from '@/components/student-dashboard-shell';
import GlassPanel, {
  GlassPanelContent,
} from '@/components/ui/glass-panel';
import EmptyState from '@/components/ui/empty-state';
import { Sparkles, ChevronRight, Clock, AlertCircle, CheckCircle2 } from 'lucide-react';
import { useStudentContext } from '@/context/StudentContext';
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

/* ── Work-status tabs (Google Classroom style) ───────────────────── */
const TABS = [
  { key: 'todo', label: 'To-do' },
  { key: 'late', label: 'Late' },
  { key: 'missing', label: 'Missing' },
  { key: 'done', label: 'Done' },
];

const TAB_EMPTY = {
  todo: {
    icon: <Sparkles />,
    title: "Nothing to do — you're all caught up",
    description: "New exercises your instructor publishes will appear here.",
  },
  late: {
    icon: <Clock />,
    title: 'Nothing turned in late',
    description: 'Exercises you complete after the deadline will show up here.',
  },
  missing: {
    icon: <AlertCircle />,
    title: 'No missing work',
    description: "Exercises past their deadline with no correct submission will show up here.",
  },
  done: {
    icon: <CheckCircle2 />,
    title: 'No completed exercises yet',
    description: 'Exercises with a correct submission will be listed here.',
  },
};

const STATUS_CHIP = {
  done: { label: 'Completed', color: 'text-emerald-400' },
  late: { label: 'Late', color: 'text-amber-400' },
  missing: { label: 'Missing', color: 'text-rose-400' },
};

// Fallback for legacy payloads that predate work_status. Deliberately does
// NOT consult `status` — only completion flags map to work state.
function workStatusOf(ex) {
  return ex.work_status ?? (ex.isCompleted ? 'done' : 'todo');
}

export default function StudentExercises() {
  const { activeSectionId } = useStudentContext();
  const [exercises, setExercises] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [activeTab, setActiveTab] = useState('todo');

  const sectionParams = useMemo(
    () => (activeSectionId ? { sectionId: activeSectionId } : {}),
    [activeSectionId]
  );

  useEffect(() => {
    let cancelled = false;
    const load = async () => {
      try {
        setLoading(true);
        setError(null);
        const res = await api.get('/api/student/exercises', { params: sectionParams });
        if (!cancelled) setExercises(Array.isArray(res.data) ? res.data : []);
      } catch (err) {
        if (!cancelled) setError(err.response?.data?.error || 'Failed to load exercises');
      } finally {
        if (!cancelled) setLoading(false);
      }
    };
    load();
    return () => { cancelled = true; };
  }, [sectionParams]);

  // Silent background refresh so completion state stays fresh when navigating
  // Back (bfcache restore via `pageshow` with persisted=true) or when the
  // window regains focus. The focus refresh is debounced/guarded so repeated
  // focus events don't hammer the API. `pageshow` with persisted=false (the
  // initial page load) is skipped to avoid a duplicate first fetch.
  const loadExercises = useCallback(async () => {
    try {
      const res = await api.get('/api/student/exercises', { params: sectionParams });
      setExercises(Array.isArray(res.data) ? res.data : []);
    } catch {
      // Silent refresh — keep the current list on transient failures.
    }
  }, [sectionParams]);

  const focusRefreshTimerRef = useRef(null);

  useEffect(() => {
    const handlePageShow = (e) => {
      if (!e.persisted) return;
      loadExercises();
    };
    const handleFocus = () => {
      if (focusRefreshTimerRef.current) return;
      focusRefreshTimerRef.current = setTimeout(() => {
        focusRefreshTimerRef.current = null;
        loadExercises();
      }, 400);
    };
    window.addEventListener('pageshow', handlePageShow);
    window.addEventListener('focus', handleFocus);
    return () => {
      window.removeEventListener('pageshow', handlePageShow);
      window.removeEventListener('focus', handleFocus);
      if (focusRefreshTimerRef.current) {
        clearTimeout(focusRefreshTimerRef.current);
        focusRefreshTimerRef.current = null;
      }
    };
  }, [loadExercises]);

  // Per-tab counts from the current dataset + client-side filtering.
  const tabCounts = useMemo(() => {
    const counts = { todo: 0, late: 0, missing: 0, done: 0 };
    for (const ex of exercises) {
      const key = workStatusOf(ex);
      if (key in counts) counts[key] += 1;
    }
    return counts;
  }, [exercises]);

  const filteredExercises = useMemo(
    () => exercises.filter((ex) => workStatusOf(ex) === activeTab),
    [exercises, activeTab]
  );

  // ---------- Loading ----------
  if (loading) {
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
        <>
          {/* Segmented work-status tabs */}
          <div
            role="tablist"
            aria-label="Filter exercises by work status"
            className="inline-flex flex-wrap items-center gap-1 rounded-xl border border-white/[0.06] bg-white/[0.02] p-1 mb-6"
          >
            {TABS.map((tab) => {
              const active = activeTab === tab.key;
              return (
                <button
                  key={tab.key}
                  type="button"
                  role="tab"
                  aria-selected={active}
                  onClick={() => setActiveTab(tab.key)}
                  className={cn(
                    "inline-flex items-center gap-1.5 rounded-lg px-3.5 py-1.5 text-xs font-medium transition-colors focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-ring",
                    active
                      ? "bg-gradient-to-r from-teal-400 to-emerald-500 text-slate-950 font-semibold"
                      : "text-muted-foreground hover:text-foreground hover:bg-white/[0.04]"
                  )}
                >
                  {tab.label}
                  <span
                    className={cn(
                      "text-[10px] font-mono tabular-nums rounded-full px-1.5",
                      active ? "text-slate-950/70" : "text-muted-foreground/60 bg-white/[0.04]"
                    )}
                  >
                    {tabCounts[tab.key] || 0}
                  </span>
                </button>
              );
            })}
          </div>

          {filteredExercises.length === 0 ? (
            <div className="rounded-2xl border border-white/[0.06] bg-white/[0.02] backdrop-blur-xl">
              <EmptyState
                icon={TAB_EMPTY[activeTab]?.icon}
                title={TAB_EMPTY[activeTab]?.title}
                description={TAB_EMPTY[activeTab]?.description}
              />
            </div>
          ) : (
            <motion.div variants={stagger} initial="hidden" animate="show" className="grid gap-4 md:grid-cols-2 lg:grid-cols-3">
              {filteredExercises.map((ex) => {
                const isCompleted = ex.isCompleted ?? ex.status === 'completed';
                const workStatus = workStatusOf(ex);
                const chip = STATUS_CHIP[workStatus];
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
                          {chip && (
                            <span className={cn("text-[10px] font-medium uppercase tracking-wider", chip.color)}>
                              {chip.label}
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
                              {isCompleted ? 'Review' : 'Start'}
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
        </>
      )}
    </StudentDashboardShell>
  );
}
