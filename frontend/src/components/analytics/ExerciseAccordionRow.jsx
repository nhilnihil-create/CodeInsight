import { useState, useEffect } from 'react';
import { Badge } from '@/components/ui/badge';
import api from '../../services/api';

/**
 * ExerciseAccordionRow — in-row accordion detail (push-down, 2026-06-09).
 *
 * Renders as a <tr> with colSpan inside the master table body.
 * Fetches class-insights report for the given exercise and renders
 * the misconception report inline (embedded mode, no overlay).
 *
 * CDS shown as integer % with 4-tier coloring using semantic tokens:
 *   < 25% → text-success   (mastery)
 *   25-49% → text-warning  (developing)
 *   50-74% → text-cds-high (at-risk)
 *   ≥ 75% → text-destructive (critical)
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

  // CDS formatting
  const cdsValue = exercise.avg_cds ?? exercise.avgCds;
  const cdsPct = cdsValue != null ? Math.round(parseFloat(cdsValue) * 100) : null;
  const cdsColor = cdsPct != null
    ? cdsPct >= 75 ? 'text-destructive'
    : cdsPct >= 50 ? 'text-cds-high'
    : cdsPct >= 25 ? 'text-warning'
    : 'text-success'
    : 'text-muted-foreground';
  const isClosed = !!exercise.closedAt;

  return (
    <tr className="bg-muted/20 border-b border-border">
      <td colSpan={colSpan} className="p-0">
        <div className="border-l-2 border-primary/50 bg-muted/10 m-1 rounded-r-lg">
          {/* Inline header: exercise name + stats */}
          <div className="px-5 py-3 flex items-center justify-between border-b border-border/40">
            <div className="flex items-center gap-3">
              <span className="text-sm font-semibold">{exercise.title}</span>
              {(exercise.conceptTags?.length > 0) && (
                <span className="bg-info/10 text-info border-info/20 px-2 py-0.5 rounded text-xs">
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
              {isClosed && <Badge className="bg-muted text-muted-foreground border-border text-[10px]">Closed</Badge>}
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

            {!loading && !error && report && report.mostCommonIssue ? (
              <MisconceptionSummary report={report} />
            ) : !loading && !error && report ? (
              <div className="py-4 text-center text-sm text-muted-foreground">
                {report.totalStudents === 0
                  ? '⏳ No submissions yet. Check back after students complete the exercise.'
                  : 'No misconception patterns detected.'}
              </div>
            ) : null}

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

/**
 * MisconceptionSummary — lightweight inline rendering of the report
 * (avoids the modal overlay from ClassMisconceptionReport).
 */
function MisconceptionSummary({ report }) {
  const completionPct = report.completedStudents && report.totalStudents
    ? Math.round((report.completedStudents / report.totalStudents) * 100)
    : 0;

  return (
    <div className="space-y-4">
      {/* Metrics row */}
      <div className="grid grid-cols-3 gap-3">
        <div className="bg-secondary rounded-lg p-3 text-center border border-border">
          <div className="text-xl font-bold font-mono">{report.totalStudents}</div>
          <div className="text-[10px] text-muted-foreground uppercase tracking-wider font-semibold">Total Students</div>
        </div>
        <div className="bg-secondary rounded-lg p-3 text-center border border-border">
          <div className="text-xl font-bold font-mono">{report.completedStudents || 0}</div>
          <div className="text-[10px] text-muted-foreground uppercase tracking-wider font-semibold">Completed</div>
        </div>
        <div className="bg-secondary rounded-lg p-3 text-center border border-border">
          <div className="text-xl font-bold font-mono">{completionPct}%</div>
          <div className="text-[10px] text-muted-foreground uppercase tracking-wider font-semibold">Completion Rate</div>
        </div>
      </div>

      {/* Issues */}
      {report.mostCommonIssue && (
        <div className="rounded-lg p-3 bg-warning/5 border-l-[3px] border-warning">
          <div className="text-sm font-semibold">{report.mostCommonIssue}</div>
          <div className="text-xs text-muted-foreground mt-1">
            <strong>{report.affectedCount}</strong> students ({report.affectedPercent?.toFixed(1) || '0'}%)
          </div>
        </div>
      )}

      {report.secondIssue && (
        <div className="rounded-lg p-3 bg-info/5 border-l-[3px] border-info">
          <div className="text-sm font-semibold">{report.secondIssue}</div>
          <div className="text-xs text-muted-foreground mt-1">
            <strong>{report.secondCount || 0}</strong> students ({report.secondPercent?.toFixed(1) || '0'}%)
          </div>
        </div>
      )}

      {/* Insights grid */}
      {(report.classSummary || report.recommendedAction) && (
        <div className="grid grid-cols-2 gap-3">
          {report.classSummary && (
            <div className="bg-secondary rounded-lg p-3 border border-border">
              <div className="text-xs font-semibold mb-1">Class Summary</div>
              <div className="text-xs text-muted-foreground leading-relaxed">{report.classSummary}</div>
            </div>
          )}
          {report.rootCause && (
            <div className="bg-secondary rounded-lg p-3 border border-border">
              <div className="text-xs font-semibold mb-1">Root Cause</div>
              <div className="text-xs text-muted-foreground leading-relaxed">{report.rootCause}</div>
            </div>
          )}
          {report.recommendedAction && (
            <div className="bg-success/5 rounded-lg p-3 border border-success/25">
              <div className="text-xs font-semibold mb-1">Recommended Action</div>
              <div className="text-xs text-muted-foreground leading-relaxed">{report.recommendedAction}</div>
            </div>
          )}
          {report.beforeAdvancing && (
            <div className="bg-secondary rounded-lg p-3 border border-border">
              <div className="text-xs font-semibold mb-1">Before Advancing</div>
              <div className="text-xs text-muted-foreground leading-relaxed">{report.beforeAdvancing}</div>
            </div>
          )}
        </div>
      )}
    </div>
  );
}
