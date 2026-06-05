import React, { useState, useEffect, useCallback } from 'react';
import { cn } from '@/lib/utils';
import api from '../../services/api';
import ClassMisconceptionReport from './ClassMisconceptionReport';
import LiveCDSPanel from '../LiveCDSPanel';
import IntegrityFlagDropdown from './IntegrityFlagDropdown';

/**
 * ExerciseAccordion — see spec §3 row 5.
 *
 * Ported from hard-coded dark teal hexes to the shadcn semantic token system.
 * Card chrome, action buttons, distribution bar, and difficulty colors all
 * resolve through Tailwind utilities that respect the active theme.
 */
function ExerciseAccordion({
  sectionId,
  exercises: exercisesProp,
  loading: loadingProp,
  onExerciseStatsUpdate,
  showManagement = false,
  onEditExercise,
  onToggleExerciseStatus,
  onDeleteExercise,
  liveCDSExerciseId,
  onLiveCDSToggle,
  showDeleteConfirm,
  selectedExerciseId,
  formatCDS = (v) => (v == null ? '—' : Number(v).toFixed(2)),
  getDifficulty = (cds) => {
    if (cds == null) return 'unscored';
    if (cds <= 0.33) return 'low';
    if (cds <= 0.66) return 'moderate';
    return 'high';
  }
}) {
  const [exercisesLocal, setExercisesLocal] = useState([]);
  const [loadingLocal, setLoadingLocal] = useState(!exercisesProp);
  const [error, setError] = useState(null);
  const [reports, setReports] = useState({});
  const [loadingReports, setLoadingReports] = useState({});
  const [reportErrors, setReportErrors] = useState({});
  const [expandedExercise, setExpandedExercise] = useState(null);
  const [integrityFlagsExerciseId, setIntegrityFlagsExerciseId] = useState(null);

  const exercises = exercisesProp ?? exercisesLocal;
  const loading = loadingProp ?? loadingLocal;

  const fetchSectionExercises = useCallback(async () => {
    if (exercisesProp) return;
    try {
      setLoadingLocal(true);
      setError(null);
      const res = await api.get(`/api/sections/${sectionId}/exercises`);
      setExercisesLocal(res.data || []);
    } catch (err) {
      console.error('Error fetching section exercises:', err);
      setError('Failed to load exercises');
      setExercisesLocal([]);
    } finally {
      setLoadingLocal(false);
    }
  }, [sectionId, exercisesProp]);

  useEffect(() => {
    fetchSectionExercises();
  }, [fetchSectionExercises]);

  const applyExerciseStats = (exerciseId, stats) => {
    if (!stats) return;
    const patch = (ex) =>
      ex.id === exerciseId
        ? {
            ...ex,
            avg_cds: stats.avg_cds ?? ex.avg_cds,
            low_count: stats.low_count ?? ex.low_count,
            moderate_count: stats.moderate_count ?? ex.moderate_count,
            high_count: stats.high_count ?? ex.high_count,
            submitted_count: stats.submitted_count ?? ex.submitted_count,
            total_students: stats.total_students ?? ex.total_students,
            closed_at: stats.closed_at ?? ex.closed_at
          }
        : ex;

    if (!exercisesProp) {
      setExercisesLocal(prev => prev.map(patch));
    }
    if (onExerciseStatsUpdate) {
      onExerciseStatsUpdate(exerciseId, stats);
    }
  };

  const fetchExerciseReport = async (exerciseId) => {
    try {
      setLoadingReports(prev => ({ ...prev, [exerciseId]: true }));
      setReportErrors(prev => ({ ...prev, [exerciseId]: null }));

      const res = await api.get(
        `/api/analytics/sections/${sectionId}/class-insights/${exerciseId}`,
        { params: { refresh: 'true' } }
      );

      const payload = res.data;
      const report = payload.report ?? payload;

      setReports(prev => ({ ...prev, [exerciseId]: report }));
      applyExerciseStats(exerciseId, payload.exerciseStats);
    } catch (err) {
      console.error(`Error fetching report for exercise ${exerciseId}:`, err);
      const message =
        err.response?.data?.message || 'Failed to load class insights for this exercise';
      setReportErrors(prev => ({ ...prev, [exerciseId]: message }));
    } finally {
      setLoadingReports(prev => ({ ...prev, [exerciseId]: false }));
    }
  };

  const handleToggle = async (exerciseId) => {
    if (expandedExercise === exerciseId) {
      setExpandedExercise(null);
      return;
    }
    setExpandedExercise(exerciseId);
    if (!reports[exerciseId]) {
      await fetchExerciseReport(exerciseId);
    }
  };

  const handleLiveCDSToggle = (exerciseId) => {
    setIntegrityFlagsExerciseId((openId) =>
      openId === exerciseId ? null : openId
    );
    onLiveCDSToggle?.(exerciseId);
  };

  const handleIntegrityToggle = (exerciseId) => {
    setIntegrityFlagsExerciseId((prev) => {
      const next = prev === exerciseId ? null : exerciseId;
      if (next !== null && liveCDSExerciseId === exerciseId) {
        onLiveCDSToggle?.(null);
      }
      return next;
    });
  };

  // Tailwind tones that adapt to light + dark via the dark: variant.
  const CDS_TONE = {
    low:      'text-emerald-600 dark:text-emerald-400',
    moderate: 'text-amber-600 dark:text-amber-400',
    high:     'text-red-600 dark:text-red-400',
  };

  const CDS_BAR = {
    low:      'bg-emerald-500',
    moderate: 'bg-amber-500',
    high:     'bg-red-500',
  };

  if (loading) {
    return (
      <div className="rounded-lg border border-border bg-card p-5 text-center text-sm text-muted-foreground">
        Loading exercises...
      </div>
    );
  }

  if (error) {
    return (
      <div className="rounded-lg border border-destructive/40 bg-destructive/10 p-5 text-center text-sm text-destructive">
        {error}
      </div>
    );
  }

  if (!exercises.length) {
    return (
      <div className="rounded-lg border border-border bg-card p-5 text-center text-sm text-muted-foreground">
        No exercises assigned to this section yet.
      </div>
    );
  }

  return (
    <div className="flex flex-col gap-3">
      {showManagement && (
        <p className="mb-1 text-xs text-muted-foreground">
          Use the arrow on each card to run an automated CDS check and view the class misconception report.
        </p>
      )}

      {exercises.map(exercise => {
        const isExpanded = expandedExercise === exercise.id;
        const isReportLoading = loadingReports[exercise.id];
        const report = reports[exercise.id];
        const reportError = reportErrors[exercise.id];
        const totalScores =
          (Number(exercise.low_count) || 0) +
          (Number(exercise.moderate_count) || 0) +
          (Number(exercise.high_count) || 0);
        const avgCdsNum =
          exercise.avg_cds != null ? parseFloat(exercise.avg_cds) : null;
        const difficulty = getDifficulty(avgCdsNum);
        const isHighAvg = avgCdsNum != null && !Number.isNaN(avgCdsNum) && avgCdsNum > 0.66;
        const panelId = `exercise-accordion-panel-${exercise.id}`;
        const description = exercise.description?.trim();
        const isDeleteConfirm =
          showDeleteConfirm && selectedExerciseId === exercise.id;

        return (
          <article
            key={exercise.id}
            className={cn(
              'rounded-lg border bg-card overflow-hidden transition-colors',
              isHighAvg ? 'border-red-300 dark:border-red-900/60' : 'border-border',
              isExpanded && 'ring-1 ring-primary/30'
            )}
          >
            <div className="px-4 pt-4">
              <div className="mb-2 flex items-start justify-between gap-3">
                <div className="min-w-0 flex-1">
                  <h3 className="mb-1 text-sm font-bold leading-tight text-foreground">
                    {exercise.title}
                  </h3>
                  {description && (
                    <p className="m-0 text-xs leading-relaxed text-muted-foreground">
                      {description.length > 100
                        ? `${description.substring(0, 100)}...`
                        : description}
                    </p>
                  )}
                </div>
                {exercise.concept_name && (
                  <span className="shrink-0 rounded-md border border-primary/30 bg-primary/10 px-2 py-0.5 text-[10px] font-bold uppercase tracking-wider text-primary">
                    {exercise.concept_name}
                  </span>
                )}
              </div>

              <div className="mb-3 flex flex-wrap gap-x-6 gap-y-1 text-[11px] text-muted-foreground">
                <div>
                  Submitted:{' '}
                  <strong className="font-mono font-semibold text-foreground">
                    {exercise.submitted_count || 0}/{exercise.total_students || 0}
                  </strong>
                </div>
                <div>
                  Avg CDS:{' '}
                  <strong className={cn('font-mono font-semibold', CDS_TONE[difficulty])}>
                    {formatCDS(avgCdsNum)}
                  </strong>
                </div>
                <div>
                  Status:{' '}
                  <strong
                    className={cn(
                      'font-semibold',
                      exercise.closed_at
                        ? 'text-muted-foreground'
                        : 'text-emerald-600 dark:text-emerald-400'
                    )}
                  >
                    {exercise.closed_at ? 'Closed' : 'Active'}
                  </strong>
                </div>
              </div>

              <div>
                <div
                  className={cn(
                    'mb-1 flex justify-between text-[10px] uppercase tracking-wider text-muted-foreground',
                    isHighAvg && 'text-red-600 dark:text-red-400'
                  )}
                >
                  <span>Difficulty Distribution</span>
                  <span>
                    Low {exercise.low_count || 0} · Mod {exercise.moderate_count || 0} · High{' '}
                    {exercise.high_count || 0}
                  </span>
                </div>
                <div className="mb-3 flex h-2 overflow-hidden rounded-full bg-muted">
                  {totalScores > 0 && (
                    <>
                      <div
                        className={cn('h-full', CDS_BAR.low)}
                        style={{
                          width: `${((exercise.low_count || 0) / totalScores) * 100}%`
                        }}
                      />
                      <div
                        className={cn('h-full', CDS_BAR.moderate)}
                        style={{
                          width: `${((exercise.moderate_count || 0) / totalScores) * 100}%`
                        }}
                      />
                      <div
                        className={cn('h-full', CDS_BAR.high)}
                        style={{
                          width: `${((exercise.high_count || 0) / totalScores) * 100}%`
                        }}
                      />
                    </>
                  )}
                </div>
              </div>
            </div>

            {showManagement && (
              <div className="mt-2 flex flex-wrap items-center justify-between gap-3 border-t border-border px-4 py-3">
                <div className="flex flex-1 flex-wrap items-center gap-2">
                  <button
                    type="button"
                    className="rounded-md px-2.5 py-1 text-[11px] font-semibold text-primary transition-colors hover:bg-primary/10"
                    onClick={() => onEditExercise?.(exercise)}
                  >
                    ✎ Edit
                  </button>
                  <button
                    type="button"
                    className="rounded-md px-2.5 py-1 text-[11px] font-semibold text-primary transition-colors hover:bg-primary/10"
                    onClick={() => handleLiveCDSToggle(exercise.id)}
                  >
                    📊 Live CDS
                  </button>
                  <button
                    type="button"
                    className={cn(
                      'rounded-md px-2.5 py-1 text-[11px] font-semibold transition-colors',
                      integrityFlagsExerciseId === exercise.id
                        ? 'border border-primary/40 bg-primary/15 text-primary'
                        : 'text-primary hover:bg-primary/10'
                    )}
                    onClick={() => handleIntegrityToggle(exercise.id)}
                  >
                    🛡 Integrity Flags
                  </button>
                  <button
                    type="button"
                    className={cn(
                      'rounded-md px-2.5 py-1 text-[11px] font-semibold transition-colors',
                      exercise.closed_at
                        ? 'text-emerald-600 hover:bg-emerald-500/10 dark:text-emerald-400'
                        : 'text-red-600 hover:bg-red-500/10 dark:text-red-400'
                    )}
                    onClick={() => onToggleExerciseStatus?.(exercise)}
                  >
                    {exercise.closed_at ? '↻ Reopen' : '⊗ Close'}
                  </button>
                  <button
                    type="button"
                    className={cn(
                      'rounded-md px-2.5 py-1 text-[11px] font-semibold transition-colors',
                      isDeleteConfirm
                        ? 'bg-destructive text-destructive-foreground hover:bg-destructive/90'
                        : 'text-red-600 hover:bg-red-500/10 dark:text-red-400'
                    )}
                    onClick={() => onDeleteExercise?.(exercise)}
                  >
                    {isDeleteConfirm ? '⚠ Confirm Delete' : '🗑 Delete'}
                  </button>
                </div>
                <button
                  type="button"
                  className={cn(
                    'flex h-8 w-8 shrink-0 items-center justify-center rounded-md border text-xs transition-colors',
                    isExpanded
                      ? 'border-primary/40 bg-primary/15 text-primary'
                      : 'border-border bg-muted text-muted-foreground hover:border-foreground/30 hover:text-foreground'
                  )}
                  onClick={() => handleToggle(exercise.id)}
                  aria-expanded={isExpanded}
                  aria-controls={panelId}
                  aria-label={
                    isExpanded
                      ? `Collapse class insights for ${exercise.title}`
                      : `Expand class insights for ${exercise.title}`
                  }
                >
                  <span
                    className={cn(
                      'inline-block transition-transform duration-200',
                      isExpanded && 'rotate-180'
                    )}
                  >
                    ▼
                  </span>
                </button>
              </div>
            )}

            {!showManagement && (
              <div className="mt-2 flex items-center justify-between gap-3 border-t border-border px-4 py-3">
                <button
                  type="button"
                  className={cn(
                    'rounded-md px-2.5 py-1 text-[11px] font-semibold transition-colors',
                    integrityFlagsExerciseId === exercise.id
                      ? 'border border-primary/40 bg-primary/15 text-primary'
                      : 'text-primary hover:bg-primary/10'
                  )}
                  onClick={() => handleIntegrityToggle(exercise.id)}
                >
                  🛡 Integrity Flags
                </button>
                <span className="flex-1 text-[11px] text-muted-foreground">
                  Class misconception report
                </span>
                <button
                  type="button"
                  className={cn(
                    'flex h-8 w-8 shrink-0 items-center justify-center rounded-md border text-xs transition-colors',
                    isExpanded
                      ? 'border-primary/40 bg-primary/15 text-primary'
                      : 'border-border bg-muted text-muted-foreground hover:border-foreground/30 hover:text-foreground'
                  )}
                  onClick={() => handleToggle(exercise.id)}
                  aria-expanded={isExpanded}
                  aria-controls={panelId}
                  aria-label={
                    isExpanded
                      ? `Collapse details for ${exercise.title}`
                      : `Expand details for ${exercise.title}`
                  }
                >
                  <span
                    className={cn(
                      'inline-block transition-transform duration-200',
                      isExpanded && 'rotate-180'
                    )}
                  >
                    ▼
                  </span>
                </button>
              </div>
            )}

            {liveCDSExerciseId === exercise.id && (
              <div className="border-t border-border px-4 py-3">
                <LiveCDSPanel
                  exerciseId={exercise.id}
                  onClose={() => onLiveCDSToggle?.(null)}
                />
              </div>
            )}

            {integrityFlagsExerciseId === exercise.id && (
              <IntegrityFlagDropdown
                sectionId={sectionId}
                exerciseId={exercise.id}
                isOpen
              />
            )}

            <div
              id={panelId}
              className={cn(
                'grid border-t border-transparent transition-[grid-template-rows] duration-300',
                isExpanded ? 'grid-rows-[1fr] border-border' : 'grid-rows-[0fr]'
              )}
              role="region"
              aria-hidden={!isExpanded}
            >
              <div className="overflow-hidden">
                {isExpanded && isReportLoading && (
                  <div className="px-4 py-5 text-center text-sm text-muted-foreground">
                    Running CDS check and loading report...
                  </div>
                )}
                {isExpanded && !isReportLoading && report && (
                  <div className="px-4 py-4">
                    <ClassMisconceptionReport report={report} embedded />
                  </div>
                )}
                {isExpanded && !isReportLoading && !report && (
                  <div className="px-4 py-5 text-center text-sm text-destructive">
                    {reportError || 'No report available for this exercise'}
                  </div>
                )}
              </div>
            </div>
          </article>
        );
      })}
    </div>
  );
}

export default ExerciseAccordion;
