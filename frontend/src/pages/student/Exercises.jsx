import { useState, useEffect, useCallback, useMemo, useRef } from 'react';
import { Link } from 'react-router-dom';
import { motion } from 'framer-motion';
import { Button } from '@/components/ui/button';
import StudentDashboardShell from '@/components/student-dashboard-shell';
import GlassPanel, {
  GlassPanelContent,
} from '@/components/ui/glass-panel';
import EmptyState from '@/components/ui/empty-state';
import {
  Sparkles,
  ChevronRight,
  Clock,
  AlertCircle,
  CheckCircle2,
  CalendarClock,
  ListChecks,
  Search,
  X,
} from 'lucide-react';
import { useStudentContext } from '@/context/StudentContext';
import api from '@/services/api';
import { cn } from '@/lib/utils';
import { tierForCds, TIER_META } from '@/components/ui/mastery-bar';

/* ── Stagger config ──────────────────────────────────────────────── */
const stagger = {
  hidden: {},
  show: { transition: { staggerChildren: 0.06, delayChildren: 0.1 } },
};

const fadeUp = {
  hidden: { opacity: 0, y: 12 },
  show: { opacity: 1, y: 0, transition: { duration: 0.5, ease: [0.25, 0.46, 0.45, 0.94] } },
};

/* ── Skeleton + shared shell props ───────────────────────────────── */
function Skeleton({ className }) {
  return <div className={cn('animate-pulse rounded-md bg-muted', className)} />;
}

const SHELL_BREADCRUMB = [
  { label: 'Student', href: '/student/dashboard' },
  { label: 'Exercises' },
];

const SHELL_SUBTITLE = 'Practice and improve your programming skills.';

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

/* ── Pure helpers ────────────────────────────────────────────────── */
function formatDeadline(deadline, now = Date.now()) {
  if (deadline == null) return 'No deadline';
  const time = new Date(deadline).getTime();
  if (Number.isNaN(time)) return 'No deadline';

  const diff = time - now;
  if (diff <= 0) {
    const absMinutes = Math.floor(Math.abs(diff) / 60000);
    if (absMinutes < 1) return 'Due now';
    const days = Math.floor(absMinutes / 1440);
    const hours = Math.floor((absMinutes % 1440) / 60);
    if (days >= 1) return `Overdue ${days}d`;
    if (hours >= 1) return `Overdue ${hours}h`;
    return `Overdue ${absMinutes}m`;
  }

  const minutes = Math.floor(diff / 60000);
  if (minutes < 1) return 'Due now';
  const days = Math.floor(minutes / 1440);
  const hours = Math.floor((minutes % 1440) / 60);
  if (days >= 1) return hours > 0 ? `Due in ${days}d ${hours}h` : `Due in ${days}d`;
  if (hours >= 1) return `Due in ${hours}h`;
  return `Due in ${minutes}m`;
}

function countTestCases(test_cases) {
  if (Array.isArray(test_cases)) return test_cases.length;
  if (test_cases && typeof test_cases === 'object') return Object.keys(test_cases).length;
  if (typeof test_cases === 'string') {
    try {
      return countTestCases(JSON.parse(test_cases));
    } catch {
      return null;
    }
  }
  return null;
}

function cdsTierClass(cds) {
  if (cds == null || isNaN(Number(cds))) return null;
  return TIER_META[tierForCds(Number(cds))].text;
}

function sortExercises(list, tab) {
  const toTime = (deadline) => {
    if (deadline == null) return Infinity;
    const t = new Date(deadline).getTime();
    return Number.isNaN(t) ? Infinity : t;
  };

  const sorted = [...list];
  if (tab === 'done') {
    sorted.sort((a, b) => {
      const ac = a.cds == null || isNaN(Number(a.cds)) ? Infinity : Number(a.cds);
      const bc = b.cds == null || isNaN(Number(b.cds)) ? Infinity : Number(b.cds);
      if (ac !== bc) return ac - bc;
      return String(a.title ?? '').localeCompare(String(b.title ?? ''), undefined, { sensitivity: 'base' });
    });
  } else {
    sorted.sort((a, b) => toTime(a.deadline) - toTime(b.deadline));
  }
  return sorted;
}

function matchesQuery(ex, q) {
  return `${ex.title} ${ex.concept_name} ${ex.description}`.toLowerCase().includes(q);
}

export default function StudentExercises() {
  const { activeSectionId } = useStudentContext();
  const [exercises, setExercises] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [activeTab, setActiveTab] = useState('todo');
  const [query, setQuery] = useState('');

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

  const tabExercises = useMemo(
    () => exercises.filter((ex) => workStatusOf(ex) === activeTab),
    [exercises, activeTab]
  );

  const visibleExercises = useMemo(() => {
    const q = query.trim().toLowerCase();
    const list = q ? tabExercises.filter((ex) => matchesQuery(ex, q)) : tabExercises;
    return sortExercises(list, activeTab);
  }, [tabExercises, activeTab, query]);

  // ---------- Loading ----------
  if (loading) {
    return (
      <StudentDashboardShell breadcrumb={SHELL_BREADCRUMB} subtitle={SHELL_SUBTITLE}>
        <div className="space-y-6">
          <div className="flex items-center justify-between gap-3">
            <Skeleton className="h-6 w-40" />
            <Skeleton className="h-9 w-64" />
          </div>
          <Skeleton className="h-16 w-full rounded-2xl" />
          <Skeleton className="h-9 w-96 rounded-xl" />
          <div className="grid gap-4 md:grid-cols-2 lg:grid-cols-3">
            {[1, 2, 3, 4, 5, 6].map((i) => (
              <div
                key={i}
                className="rounded-2xl border border-white/[0.06] bg-white/[0.02] p-5 space-y-3"
              >
                <div className="flex items-center justify-between">
                  <Skeleton className="h-3 w-24" />
                  <Skeleton className="h-3 w-14" />
                </div>
                <Skeleton className="h-4 w-3/4" />
                <Skeleton className="h-3 w-full" />
                <Skeleton className="h-3 w-2/3" />
                <Skeleton className="h-5 w-24" />
                <Skeleton className="h-9 w-full" />
              </div>
            ))}
          </div>
        </div>
      </StudentDashboardShell>
    );
  }

  return (
    <StudentDashboardShell breadcrumb={SHELL_BREADCRUMB} subtitle={SHELL_SUBTITLE}>
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
          {/* Page header: title + search */}
          <div className="flex items-center justify-between gap-3 mb-4">
            <h1 className="text-xl font-semibold tracking-tight text-foreground">My Exercises</h1>
            <div className="relative w-full sm:w-72">
              <Search className="absolute left-3 top-1/2 -translate-y-1/2 h-4 w-4 text-muted-foreground/50" />
              <input
                type="search"
                aria-label="Search exercises"
                placeholder="Search exercises…"
                value={query}
                onChange={(e) => setQuery(e.target.value)}
                className="h-9 w-full rounded-lg border border-white/[0.08] bg-white/[0.02] pl-9 pr-8 text-sm placeholder:text-muted-foreground/40 focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-ring"
              />
              {query && (
                <button
                  type="button"
                  aria-label="Clear search"
                  onClick={() => setQuery('')}
                  className="absolute right-2 top-1/2 -translate-y-1/2 text-muted-foreground/60 hover:text-foreground cursor-pointer"
                >
                  <X className="h-4 w-4" />
                </button>
              )}
            </div>
          </div>

          {/* Summary strip */}
          <div className="rounded-2xl border border-white/[0.06] bg-white/[0.02] backdrop-blur-xl p-4 mb-5">
            <div className="grid grid-cols-2 sm:grid-cols-4 gap-3">
              {[
                { key: 'todo', label: 'To-do', icon: <ListChecks className="h-4 w-4 text-muted-foreground/60" /> },
                { key: 'late', label: 'Late', icon: <Clock className="h-4 w-4 text-amber-400" /> },
                { key: 'missing', label: 'Missing', icon: <AlertCircle className="h-4 w-4 text-rose-400" /> },
                { key: 'done', label: 'Done', icon: <CheckCircle2 className="h-4 w-4 text-emerald-400" /> },
              ].map((stat) => (
                <div key={stat.key} className="flex items-center gap-2.5">
                  {stat.icon}
                  <div className="flex flex-col">
                    <span className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground/60">
                      {stat.label}
                    </span>
                    <span className="text-lg font-semibold font-mono tabular-nums text-foreground">
                      {tabCounts[stat.key] || 0}
                    </span>
                  </div>
                </div>
              ))}
            </div>
          </div>

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

          {tabExercises.length === 0 ? (
            <div className="rounded-2xl border border-white/[0.06] bg-white/[0.02] backdrop-blur-xl">
              <EmptyState
                icon={TAB_EMPTY[activeTab]?.icon}
                title={TAB_EMPTY[activeTab]?.title}
                description={TAB_EMPTY[activeTab]?.description}
              />
            </div>
          ) : visibleExercises.length === 0 ? (
            <div className="rounded-2xl border border-white/[0.06] bg-white/[0.02] backdrop-blur-xl">
              <EmptyState
                icon={<Search />}
                title="No exercises match your search"
                description="Try a different keyword or clear the search filter."
                action={
                  <Button variant="outline" size="sm" onClick={() => setQuery('')}>
                    Clear search
                  </Button>
                }
              />
            </div>
          ) : (
            <motion.div variants={stagger} initial="hidden" animate="show" className="grid gap-4 md:grid-cols-2 lg:grid-cols-3">
              {visibleExercises.map((ex) => {
                const isCompleted = ex.isCompleted ?? ex.status === 'completed';
                const workStatus = workStatusOf(ex);
                const chip = STATUS_CHIP[workStatus];
                const chipBase =
                  "inline-flex items-center gap-1 rounded-full border border-white/[0.08] bg-white/[0.04] px-2 py-0.5 text-[10px] font-mono text-muted-foreground/70";
                const testsCount = countTestCases(ex.test_cases);
                const showChips =
                  Boolean(ex.concept_name) ||
                  Boolean(ex.time_limit_minutes) ||
                  (typeof testsCount === 'number' && testsCount >= 0) ||
                  (workStatus === 'done' && ex.cds != null && !isNaN(Number(ex.cds)));
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
                          {workStatus !== 'done' ? (
                            <span className="flex items-center gap-1 text-[11px] text-muted-foreground/50 font-mono tabular-nums">
                              <CalendarClock className="h-3 w-3" aria-hidden="true" />
                              {formatDeadline(ex.deadline)}
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

                        {/* Chips: concept · time limit · tests · CDS */}
                        {showChips && (
                          <div className="flex flex-wrap gap-1.5 mb-4">
                            {ex.concept_name && (
                              <span className={chipBase}>{ex.concept_name}</span>
                            )}
                            {ex.time_limit_minutes && (
                              <span className={chipBase}>
                                <Clock className="h-3 w-3" aria-hidden="true" />
                                {ex.time_limit_minutes} min
                              </span>
                            )}
                            {typeof testsCount === 'number' && testsCount >= 0 && (
                              <span className={chipBase}>
                                {testsCount} test{testsCount === 1 ? '' : 's'}
                              </span>
                            )}
                            {workStatus === 'done' && ex.cds != null && !isNaN(Number(ex.cds)) && (
                              <span className={cn(chipBase, cdsTierClass(ex.cds))}>
                                CDS {Number(ex.cds).toFixed(2)}
                              </span>
                            )}
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
