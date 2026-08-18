import React, { useEffect, useState, useCallback } from 'react';
import { Link, useNavigate } from 'react-router-dom';
import { motion } from 'framer-motion';
import { Button } from '@/components/ui/button';
import { Badge } from '@/components/ui/badge';
import {
  Plus,
  Lock,
  Unlock,
  Trash2,
  ChevronRight,
  AlertTriangle,
  Code2,
  Calendar,
  Users,
  PencilLine,
  Inbox,
} from 'lucide-react';
import { cn } from '@/lib/utils';
import ExerciseAccordionRow from '@/components/analytics/ExerciseAccordionRow';
import SectionFilter from '@/components/SectionFilter';
import useLastSection from '@/hooks/useLastSection';
import api from '@/services/api';
import EmptyState from '@/components/ui/empty-state';

/* ── Motion ─────────────────────────────────────────────────────── */
const stagger = {
  hidden: {},
  show: { transition: { staggerChildren: 0.06, delayChildren: 0.08 } },
};

const fadeUp = {
  hidden: { opacity: 0, y: 10 },
  show: { opacity: 1, y: 0, transition: { duration: 0.4, ease: [0.25, 0.46, 0.45, 0.94] } },
};

/* ── Status helpers ─────────────────────────────────────────────── */
function statusOf(e) {
  if (e.isDraft) return { label: 'Saved', className: 'bg-white/[0.04] text-muted-foreground border-white/[0.08]' };
  if (e.closedAt) return { label: 'Closed', className: 'bg-slate-500/10 text-slate-400 border-slate-500/20' };
  return { label: 'Open', className: 'bg-emerald-500/10 text-emerald-400 border-emerald-500/20' };
}

function cdsPctOf(e) {
  const raw = e.avg_cds ?? e.avgCds;
  if (raw == null || raw === '' || Number.isNaN(Number(raw))) return null;
  return Math.round(Number(raw) * 100);
}

const CDS_COLOR = (pct) =>
  pct == null ? 'text-muted-foreground'
  : pct >= 75 ? 'text-rose-400'
  : pct >= 50 ? 'text-amber-400'
  : pct >= 25 ? 'text-indigo-300'
  : 'text-indigo-400';

/**
 * Exercises list — responsive glass-card redesign (2026-08-15).
 *
 * Replaces the wide 6-column table that forced horizontal swiping on
 * mobile with stacked cards: title + status, concept chips, due / progress
 * / CDS meta, and inline actions. Clicking a card expands an analytics
 * detail panel (ClassMisconceptionReport) beneath it.
 */
export default function InstructorExercises() {
  const [sectionId, setSectionId] = useLastSection();
  const navigate = useNavigate();
  const [exercises, setExercises] = useState([]);
  const [expandedId, setExpandedId] = useState(null);
  const [busyId, setBusyId] = useState(null);
  const [error, setError] = useState(null);
  const [loading, setLoading] = useState(true);

  const toggleExpand = useCallback((id) => {
    setExpandedId(prev => prev === id ? null : id);
  }, []);

  const fetchExercises = async (secId) => {
    const url = `/api/sections/${secId}/exercises`;
    const res = await api.get(url);
    const list = Array.isArray(res.data) ? res.data : [];
    return list.map(e => ({
      id: e.id,
      title: e.title,
      conceptTags: e.concept_name ? [e.concept_name] : (e.concept_tags || e.conceptTags || []),
      dueDate: e.deadline || e.due_date || e.dueDate,
      isDraft: e.is_draft,
      closedAt: e.closed_at,
      sectionId: e.section_id,
      avg_cds: e.avg_cds ?? e.avgCds,
      submitted_count: e.submitted_count ?? e.submittedCount,
      total_students: e.total_students ?? e.totalStudents,
    }));
  };

  const loadAll = async () => {
    try {
      const list = await fetchExercises(sectionId);
      setExercises(list);
    } catch {
      setExercises([]);
    }
  };

  useEffect(() => {
    let cancelled = false;
    setLoading(true);
    setExpandedId(null);
    loadAll().finally(() => { if (!cancelled) setLoading(false); });
    return () => { cancelled = true; };
    // eslint-disable-next-line react-hooks/exhaustive-deps
  }, [sectionId]);

  const handleClose = async (e) => {
    setBusyId(e.id); setError(null);
    try {
      await api.post(`/api/exercises/${e.id}/close`);
      await loadAll();
    } catch (err) {
      setError(err.response?.data?.message || err.message);
    } finally { setBusyId(null); }
  };

  const handleReopen = async (e) => {
    setBusyId(e.id); setError(null);
    try {
      await api.post(`/api/exercises/${e.id}/reopen`);
      await loadAll();
    } catch (err) {
      setError(err.response?.data?.message || err.message);
    } finally { setBusyId(null); }
  };

  const handleDelete = async (e) => {
    if (!confirm(`Delete "${e.title}"? This cannot be undone.`)) return;
    setBusyId(e.id); setError(null);
    try {
      await api.delete(`/api/exercises/${e.id}`);
      await loadAll();
    } catch (err) {
      setError(err.response?.data?.message || err.message);
    } finally { setBusyId(null); }
  };

  return (
    <div className="space-y-6">
      {/* ---------- PageHeader ---------- */}
      <div className="flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between">
        <div className="min-w-0">
          <h1 className="text-2xl font-semibold tracking-tight">Exercises</h1>
          <p className="text-sm text-muted-foreground mt-1">
            {loading ? 'Loading exercises…' : `${exercises.length} exercise${exercises.length === 1 ? '' : 's'} in this section`}
          </p>
        </div>
        <div className="flex flex-col gap-2 sm:flex-row sm:items-center">
          <SectionFilter value={sectionId} onChange={setSectionId} />
          <Button asChild size="sm" className="font-medium">
            <Link to="/instructor/exercises/new" className="gap-2">
              <Plus className="w-4 h-4" /> Create Exercise
            </Link>
          </Button>
        </div>
      </div>

      {error && (
        <div className="flex items-center gap-3 rounded-lg border border-destructive/30 bg-destructive/5 px-4 py-3">
          <AlertTriangle className="h-4 w-4 text-destructive shrink-0" />
          <p className="text-sm text-destructive flex-1">{error}</p>
          <Button size="sm" variant="ghost" className="text-destructive" onClick={() => setError(null)}>
            Dismiss
          </Button>
        </div>
      )}

      {/* ---------- Exercise list ---------- */}
      {loading ? (
        <div className="rounded-xl border border-white/[0.06] bg-white/[0.02] backdrop-blur-xl py-16 text-center">
          <div className="animate-spin h-5 w-5 border-2 border-muted-foreground/30 border-t-muted-foreground rounded-full mx-auto mb-3" />
          <p className="text-sm text-muted-foreground">Loading exercises…</p>
        </div>
      ) : exercises.length === 0 ? (
        <div className="rounded-2xl border border-white/[0.06] bg-white/[0.02] backdrop-blur-xl py-12">
          <EmptyState
            icon={<Code2 />}
            title="No exercises yet"
            description="Create your first exercise to start collecting submissions."
          />
        </div>
      ) : (
        <motion.div variants={stagger} initial="hidden" animate="show" className="space-y-3">
          {exercises.map((e) => {
            const isClosed = !!e.closedAt;
            const isExpanded = expandedId === e.id;
            const st = statusOf(e);
            const cdsPct = cdsPctOf(e);
            const submitted = e.submitted_count ?? '—';
            const total = e.total_students ?? '—';
            const due = e.dueDate ? new Date(e.dueDate).toLocaleDateString() : '—';

            return (
              <motion.div key={e.id} variants={fadeUp} className="group">
                <div
                  className={cn(
                    'rounded-xl border bg-white/[0.02] backdrop-blur-xl transition-colors duration-200 overflow-hidden',
                    'border-white/[0.06]',
                    isExpanded ? 'border-teal-400/30' : 'hover:border-white/[0.12]'
                  )}
                >
                  {/* Top accent */}
                  <div
                    className={cn(
                      'h-px w-full bg-gradient-to-r from-transparent via-teal-400/40 to-transparent transition-opacity duration-300',
                      isExpanded ? 'opacity-100' : 'opacity-0 group-hover:opacity-100'
                    )}
                  />

                  {/* Row body — clickable to expand */}
                  <div
                    role="button"
                    tabIndex={0}
                    onClick={() => toggleExpand(e.id)}
                    onKeyDown={(ev) => { if (ev.key === 'Enter' || ev.key === ' ') { ev.preventDefault(); toggleExpand(e.id); } }}
                    className="px-4 py-3.5 sm:px-5 cursor-pointer"
                  >
                    {/* Line 1: chevron + title + status */}
                    <div className="flex items-start gap-2.5">
                      <ChevronRight
                        className={cn(
                          'h-4 w-4 text-muted-foreground/50 mt-0.5 shrink-0 transition-transform duration-200',
                          isExpanded && 'rotate-90 text-teal-400'
                        )}
                        strokeWidth={1.5}
                      />
                      <div className="min-w-0 flex-1">
                        <div className="flex items-center gap-2 min-w-0">
                          <h3 className="text-sm font-semibold text-foreground truncate">
                            {e.title}
                          </h3>
                          <Badge
                            variant="outline"
                            className={cn('shrink-0 text-[10px] font-mono uppercase tracking-wider', st.className)}
                          >
                            {st.label}
                          </Badge>
                        </div>

                        {/* Meta chips */}
                        <div className="flex flex-wrap items-center gap-x-3 gap-y-1 mt-1.5">
                          {e.conceptTags?.length > 0 ? (
                            e.conceptTags.map((t) => (
                              <span
                                key={t}
                                className="inline-flex items-center rounded-full bg-indigo-500/10 text-indigo-400 border border-indigo-500/20 px-2 py-0.5 text-[11px] font-medium"
                              >
                                {t}
                              </span>
                            ))
                          ) : (
                            <span className="text-xs text-muted-foreground/60">No concept tagged</span>
                          )}

                          <span className="inline-flex items-center gap-1 text-[11px] text-muted-foreground/60">
                            <Calendar className="h-3 w-3" strokeWidth={1.5} />
                            Due {due}
                          </span>

                          <span className="inline-flex items-center gap-1 text-[11px] text-muted-foreground/60">
                            <Users className="h-3 w-3" strokeWidth={1.5} />
                            {submitted}/{total} submitted
                          </span>

                          <span className={cn('text-[11px] font-mono tabular-nums', CDS_COLOR(cdsPct))}>
                            CDS {cdsPct != null ? `${cdsPct}%` : '—'}
                          </span>
                        </div>
                      </div>
                    </div>

                    {/* Line 2: actions */}
                    <div className="flex flex-wrap items-center gap-1.5 mt-2.5 pl-6 sm:pl-7" onClick={(ev) => ev.stopPropagation()}>
                      <Button asChild variant="ghost" size="sm" className="h-7 px-2.5 text-xs">
                        <Link to={`/instructor/exercises/${e.id}/edit`}>
                          <PencilLine className="w-3.5 h-3.5 mr-1" strokeWidth={1.5} />
                          Edit
                        </Link>
                      </Button>
                      <Button
                        variant="ghost"
                        size="sm"
                        className="h-7 px-2.5 text-xs"
                        onClick={() => navigate(`/instructor/sections/${sectionId}?tab=submissions&exercise=${e.id}`)}
                        title="View submissions"
                        aria-label="View submissions"
                      >
                        <Inbox className="w-3.5 h-3.5 mr-1" strokeWidth={1.5} />
                        Submissions
                      </Button>
                      {isClosed ? (
                        <Button variant="ghost" size="sm" className="h-7 px-2.5 text-xs" onClick={() => handleReopen(e)} disabled={busyId === e.id} title="Reopen exercise" aria-label="Reopen exercise">
                          <Unlock className="w-3.5 h-3.5 mr-1" strokeWidth={1.5} />
                          Reopen
                        </Button>
                      ) : (
                        <Button variant="ghost" size="sm" className="h-7 px-2.5 text-xs" onClick={() => handleClose(e)} disabled={busyId === e.id} title="Close exercise (compute CDS)" aria-label="Close exercise">
                          <Lock className="w-3.5 h-3.5 mr-1" strokeWidth={1.5} />
                          Close
                        </Button>
                      )}
                      <Button
                        variant="ghost"
                        size="sm"
                        className="h-7 px-2.5 text-xs text-destructive hover:bg-destructive/10 hover:text-destructive"
                        onClick={() => handleDelete(e)}
                        disabled={busyId === e.id}
                        title="Delete exercise"
                        aria-label="Delete exercise"
                      >
                        <Trash2 className="w-3.5 h-3.5 mr-1" strokeWidth={1.5} />
                        Delete
                      </Button>
                    </div>
                  </div>

                  {/* Accordion detail panel */}
                  {isExpanded && (
                    <div className="border-t border-white/[0.06] bg-[#0D1126]/40">
                      <ExerciseAccordionRow exercise={e} sectionId={sectionId} />
                    </div>
                  )}
                </div>
              </motion.div>
            );
          })}
        </motion.div>
      )}
    </div>
  );
}
