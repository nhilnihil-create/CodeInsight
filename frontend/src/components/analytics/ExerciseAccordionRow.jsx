import { useState, useEffect } from 'react';
import { Badge } from '@/components/ui/badge';
import { Button } from '@/components/ui/button';

import api from '../../services/api';
import ClassMisconceptionReport from './ClassMisconceptionReport';

/**
 * ExerciseAccordionRow — in-row accordion detail (push-down, 2026-06-09).
 *
 * Renders as a <tr> with colSpan inside the master table body.
 * Fetches class-insights report for the given exercise and renders
 * the misconception report inline (embedded mode, no overlay).
 *
 * CDS shown as integer % with 4-tier coloring:
 *   < 25% → indigo-400  (mastery)
 *   25-49% → indigo-300 (developing)
 *   50-74% → amber-400  (at-risk)
 *   ≥ 75% → rose-400    (critical)
 */
export default function ExerciseAccordionRow({ exercise, sectionId, colSpan }) {
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
        if (!cancelled) setReport(res.data.report);
      } catch (err) {
        if (!cancelled) setError(err.message);
      } finally {
        if (!cancelled) setLoading(false);
      }
    };
    load();
    return () => { cancelled = true };
  }, [exercise?.id, sectionId]);

  // CDS formatting
  const cdsValue = exercise.avg_cds ?? exercise.avgCds;
  const cdsPct = cdsValue != null ? Math.round(parseFloat(cdsValue) * 100) : null;
  const cdsColor = cdsPct != null
    ? cdsPct >= 75 ? 'text-rose-400'
    : cdsPct >= 50 ? 'text-amber-400'
    : cdsPct >= 25 ? 'text-indigo-300'
    : 'text-indigo-400'
    : 'text-muted-foreground';
  const isClosed = !!exercise.closedAt;

  return (
    <tr className="bg-[#0D1126]/40 border-b border-slate-800/50">
      <td colSpan={colSpan} className="p-0">
        <div className="border-l-2 border-indigo-500/50 bg-[#0D1126]/30 m-1 rounded-r-lg">
          {/* Inline header: exercise name + stats */}
          <div className="px-5 py-3 flex items-center justify-between border-b border-slate-800/30">
            <div className="flex items-center gap-3">
              <span className="text-sm font-semibold">{exercise.title}</span>
              {(exercise.conceptTags?.length > 0) && (
                <span className="bg-slate-900 text-indigo-400 border border-indigo-950 px-2 py-0.5 rounded text-xs">
                  {exercise.conceptTags[0]}
                </span>
              )}
            </div>
            <div className="flex items-center gap-5 text-xs text-muted-foreground">
              <span>
                Submitted:{' '}
                <span className="font-medium text-foreground">
                  {exercise.submitted_count ?? '—'}/{exercise.total_students ?? '—'}
                </span>
              </span>
              {cdsPct != null ? (
                <span>
                  Avg CDS:{' '}
                  <span className={`font-semibold ${cdsColor}`}>
                    {cdsPct}%
                  </span>
                </span>
              ) : (
                <span>Avg CDS: <span className="text-foreground">—</span></span>
              )}
              {isClosed && <Badge className="bg-slate-800/50 text-slate-400 border-slate-700/50 text-[10px]">Closed</Badge>}
            </div>
          </div>

          {/* Analytics body */}
          <div className="px-5 py-4">
            {loading && (
              <div className="py-6 text-center text-sm text-muted-foreground animate-pulse">
                Loading analytics…
              </div>
            )}

            {error && (
              <div className="py-6 text-center text-sm text-destructive">
                Failed to load analytics: {error}
              </div>
            )}

            {!loading && !error && report && (
              <>
                <ClassMisconceptionReport report={report} embedded />

                {report.mostCommonIssue && null}
              </>
            )}

            {!loading && !error && !report && (
              <div className="py-4 text-center text-sm text-muted-foreground">
                No analytics data available for this exercise.
              </div>
            )}
          </div>
        </div>

      </td>
    </tr>
  );
}


