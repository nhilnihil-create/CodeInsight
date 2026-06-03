import React, { useState, useEffect, useCallback } from 'react';
import api from '../../services/api';
import ClassMisconceptionReport from './ClassMisconceptionReport';
import LiveCDSPanel from '../LiveCDSPanel';
import './ExerciseAccordion.css';

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

  const cdsColorClass = (difficulty, isHighAvg) => {
    if (isHighAvg) return 'stat-cds-high';
    if (difficulty === 'moderate') return 'stat-cds-moderate';
    if (difficulty === 'low') return 'stat-cds-low';
    return '';
  };

  if (loading) {
    return <div className="exercise-accordion-state">Loading exercises...</div>;
  }

  if (error) {
    return <div className="exercise-accordion-state is-error">{error}</div>;
  }

  if (!exercises.length) {
    return (
      <div className="exercise-accordion-state">
        No exercises assigned to this section yet.
      </div>
    );
  }

  return (
    <div className="exercise-accordion-list">
      {showManagement && (
        <p className="exercise-accordion-hint">
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
          <article key={exercise.id} className="exercise-accordion-item">
            <div
              className={[
                'exercise-accordion-shell',
                isExpanded ? 'is-expanded' : '',
                isHighAvg ? 'is-high-avg' : ''
              ]
                .filter(Boolean)
                .join(' ')}
            >
              <div className="exercise-accordion-body">
                <div className="exercise-accordion-top">
                  <div className="exercise-accordion-title-block">
                    <h3 className="exercise-accordion-title">{exercise.title}</h3>
                    {description && (
                      <p className="exercise-accordion-description">
                        {description.length > 100
                          ? `${description.substring(0, 100)}...`
                          : description}
                      </p>
                    )}
                  </div>
                  {exercise.concept_name && (
                    <span className="exercise-accordion-concept">
                      {exercise.concept_name}
                    </span>
                  )}
                </div>

                <div className="exercise-accordion-stats">
                  <div>
                    Submitted:{' '}
                    <strong style={{ color: '#e8e6f0' }}>
                      {exercise.submitted_count || 0}/{exercise.total_students || 0}
                    </strong>
                  </div>
                  <div>
                    Avg CDS:{' '}
                    <strong className={cdsColorClass(difficulty, isHighAvg)}>
                      {formatCDS(avgCdsNum)}
                    </strong>
                  </div>
                  <div>
                    Status:{' '}
                    <strong
                      className={
                        exercise.closed_at
                          ? 'stat-status-closed'
                          : 'stat-status-active'
                      }
                    >
                      {exercise.closed_at ? 'Closed' : 'Active'}
                    </strong>
                  </div>
                </div>

                <div>
                  <div
                    className={`exercise-accordion-distribution-label${
                      isHighAvg ? ' dist-high' : ''
                    }`}
                  >
                    <span>Difficulty Distribution</span>
                    <span className={isHighAvg ? 'dist-high' : ''}>
                      Low {exercise.low_count || 0} · Mod{' '}
                      {exercise.moderate_count || 0} · High {exercise.high_count || 0}
                    </span>
                  </div>
                  <div className="exercise-accordion-distribution-bar">
                    {totalScores > 0 && (
                      <>
                        <div
                          className="exercise-accordion-bar-low"
                          style={{
                            width: `${((exercise.low_count || 0) / totalScores) * 100}%`
                          }}
                        />
                        <div
                          className="exercise-accordion-bar-moderate"
                          style={{
                            width: `${((exercise.moderate_count || 0) / totalScores) * 100}%`
                          }}
                        />
                        <div
                          className="exercise-accordion-bar-high"
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
                <div className="exercise-accordion-footer">
                  <div className="exercise-accordion-actions">
                    <button
                      type="button"
                      className="exercise-accordion-action-btn exercise-accordion-action-btn--primary"
                      onClick={() => onEditExercise?.(exercise)}
                    >
                      ✎ Edit
                    </button>
                    <button
                      type="button"
                      className="exercise-accordion-action-btn exercise-accordion-action-btn--primary"
                      onClick={() => onLiveCDSToggle?.(exercise.id)}
                    >
                      📊 Live CDS
                    </button>
                    <button
                      type="button"
                      className={`exercise-accordion-action-btn ${
                        exercise.closed_at
                          ? 'exercise-accordion-action-btn--success'
                          : 'exercise-accordion-action-btn--danger'
                      }`}
                      onClick={() => onToggleExerciseStatus?.(exercise)}
                    >
                      {exercise.closed_at ? '↻ Reopen' : '⊗ Close'}
                    </button>
                    <button
                      type="button"
                      className={`exercise-accordion-action-btn exercise-accordion-action-btn--danger${
                        isDeleteConfirm ? ' exercise-accordion-action-btn--danger-confirm' : ''
                      }`}
                      onClick={() => onDeleteExercise?.(exercise)}
                    >
                      {isDeleteConfirm ? '⚠ Confirm Delete' : '🗑 Delete'}
                    </button>
                  </div>

                  <button
                    type="button"
                    className={`exercise-accordion-toggle${isExpanded ? ' is-expanded' : ''}`}
                    onClick={() => handleToggle(exercise.id)}
                    aria-expanded={isExpanded}
                    aria-controls={panelId}
                    aria-label={
                      isExpanded
                        ? `Collapse class insights for ${exercise.title}`
                        : `Expand class insights for ${exercise.title}`
                    }
                  >
                    <span className="exercise-accordion-chevron" aria-hidden="true">
                      ▼
                    </span>
                  </button>
                </div>
              )}

              {!showManagement && (
                <div className="exercise-accordion-footer">
                  <span style={{ fontSize: '11px', color: '#8884a0', flex: 1 }}>
                    Class misconception report
                  </span>
                  <button
                    type="button"
                    className={`exercise-accordion-toggle${isExpanded ? ' is-expanded' : ''}`}
                    onClick={() => handleToggle(exercise.id)}
                    aria-expanded={isExpanded}
                    aria-controls={panelId}
                    aria-label={
                      isExpanded
                        ? `Collapse details for ${exercise.title}`
                        : `Expand details for ${exercise.title}`
                    }
                  >
                    <span className="exercise-accordion-chevron" aria-hidden="true">
                      ▼
                    </span>
                  </button>
                </div>
              )}

              {showManagement && liveCDSExerciseId === exercise.id && (
                <div className="exercise-accordion-live-panel">
                  <LiveCDSPanel
                    exerciseId={exercise.id}
                    onClose={() => onLiveCDSToggle?.(null)}
                  />
                </div>
              )}

              <div
                id={panelId}
                className={`exercise-accordion-panel${isExpanded ? ' is-open' : ''}`}
                role="region"
                aria-hidden={!isExpanded}
              >
                <div className="exercise-accordion-panel-inner">
                  {isExpanded && isReportLoading && (
                    <div className="exercise-accordion-panel-body is-loading">
                      Running CDS check and loading report...
                    </div>
                  )}
                  {isExpanded && !isReportLoading && report && (
                    <div className="exercise-accordion-panel-body">
                      <ClassMisconceptionReport report={report} embedded />
                    </div>
                  )}
                  {isExpanded && !isReportLoading && !report && (
                    <div className="exercise-accordion-panel-body is-error">
                      {reportError || 'No report available for this exercise'}
                    </div>
                  )}
                </div>
              </div>
            </div>
          </article>
        );
      })}
    </div>
  );
}

export default ExerciseAccordion;
