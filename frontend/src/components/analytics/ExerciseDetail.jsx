import { useState, useEffect } from 'react';
import { Card, CardContent } from '@/components/ui/card';
import { Badge } from '@/components/ui/badge';
import ClassMisconceptionReport from './ClassMisconceptionReport';
import api from '../../services/api';

/**
 * ExerciseDetail — single-exercise analytics (Master-Detail slave, 2026-06-09).
 *
 * Receives a selected exercise from the master table and renders:
 *   - Header with title, concept tag, submission count, CDS %
 *   - Class Misconception Report (reuses existing component)
 *
 * CDS is displayed as an integer percentage with 4-tier indigo coloring:
 *   < 25% → indigo-400 (mastery)
 *   25-49% → indigo-300 (developing)
 *   50-74% → amber-400 (at-risk)
 *   ≥ 75% → rose-400 (critical)
 */
export default function ExerciseDetail({ exercise, sectionId }) {
  const [report, setReport] = useState(null);
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState(null);

  useEffect(() => {
    if (!sectionId || !exercise?.id) return;
    let cancelled = false;
    const load = async () => {
      try {
        setLoading(true);
        setError(null);
        const res = await api.get(`/api/analytics/sections/${sectionId}/class-insights/${exercise.id}`);
        if (!cancelled) setReport(res.data);
      } catch (err) {
        if (!cancelled) setError(err.message);
      } finally {
        if (!cancelled) setLoading(false);
      }
    };
    load();
    return () => { cancelled = true };
  }, [exercise?.id, sectionId]);

  // CDS helpers
  const cdsValue = exercise.avg_cds ?? exercise.avgCds;
  const cdsPct = cdsValue != null ? Math.round(parseFloat(cdsValue) * 100) : null;
  const cdsTier = cdsPct != null
    ? cdsPct >= 75 ? 'critical'
    : cdsPct >= 50 ? 'warning'
    : cdsPct >= 25 ? 'developing'
    : 'mastery'
    : null;
  const cdsColor = cdsTier === 'critical' ? 'text-rose-400'
    : cdsTier === 'warning' ? 'text-amber-400'
    : cdsTier === 'developing' ? 'text-indigo-300'
    : 'text-indigo-400';

  const isClosed = !!exercise.closedAt;

  return (
    <Card>
      <CardContent className="p-0">
        {/* Header */}
        <div className="px-6 py-4 border-b border-slate-800/50 flex items-center justify-between">
          <div className="flex items-center gap-3">
            <h2 className="text-lg font-semibold">{exercise.title}</h2>
            {(exercise.conceptTags?.length > 0) && (
              <span className="bg-slate-900 text-indigo-400 border border-indigo-950 px-2 py-0.5 rounded text-xs">
                {exercise.conceptTags[0]}
              </span>
            )}
          </div>
          <div className="flex items-center gap-6 text-sm">
            <span className="text-muted-foreground">
              Submitted:{' '}
              <span className="font-medium text-foreground">
                {exercise.submitted_count ?? '—'}/{exercise.total_students ?? '—'}
              </span>
            </span>
            {cdsPct != null ? (
              <span className="text-muted-foreground">
                Avg CDS:{' '}
                <span className={`font-semibold ${cdsColor}`}>
                  {cdsPct}%
                </span>
              </span>
            ) : (
              <span className="text-muted-foreground">Avg CDS: <span className="text-foreground">—</span></span>
            )}
            {isClosed && <Badge className="bg-slate-800/50 text-slate-400 border-slate-700/50">Closed</Badge>}
          </div>
        </div>

        {/* Body */}
        <div className="p-6">
          {loading && (
            <div className="py-8 text-center text-sm text-muted-foreground">
              Loading analytics…
            </div>
          )}

          {error && (
            <div className="py-8 text-center text-sm text-destructive">
              Failed to load analytics: {error}
            </div>
          )}

          {!loading && !error && report && (
            <ClassMisconceptionReport report={report} />
          )}

          {!loading && !error && !report && (
            <div className="py-8 text-center text-sm text-muted-foreground">
              No analytics data available for this exercise.
            </div>
          )}
        </div>
      </CardContent>
    </Card>
  );
}
