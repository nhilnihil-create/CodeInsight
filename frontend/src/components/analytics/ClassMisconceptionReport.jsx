import { useState } from 'react';
import { X, AlertTriangle, ChevronRight, TrendingUp, Target, Code2 } from 'lucide-react';

function MetricCard({ label, value, suffix = '' }) {
  return (
    <div className="bg-muted/40 rounded-lg p-3 text-center border border-border">
      <div className="text-xl font-bold font-mono tabular-nums">{value}{suffix}</div>
      <div className="text-[10px] text-muted-foreground uppercase tracking-wider font-semibold mt-0.5">{label}</div>
    </div>
  );
}

function IssueCard({ rank, issue, count, percent, isPrimary }) {
  if (!issue) return null;
  return (
    <div className={`rounded-lg p-3 border-l-[3px] ${isPrimary ? 'border-chart-4 bg-chart-4/5' : 'border-chart-2 bg-chart-2/5'}`}>
      <div className="flex items-start gap-3">
        <span className={`text-xs font-bold w-5 h-5 rounded-full flex items-center justify-center shrink-0 mt-0.5 ${isPrimary ? 'bg-chart-4/20 text-chart-4' : 'bg-chart-2/20 text-chart-2'}`}>
          {rank}
        </span>
        <div className="min-w-0 flex-1">
          <div className="text-sm font-semibold">{issue.name}</div>
          {issue.description && (
            <div className="text-xs text-muted-foreground mt-0.5">{issue.description}</div>
          )}
          <div className="text-xs text-muted-foreground mt-1">
            <strong>{count}</strong> student{count === 1 ? '' : 's'} ({percent.toFixed(1)}%)
          </div>
        </div>
      </div>
    </div>
  );
}

function CommonErrorCard({ rank, error, totalStudents }) {
  const pct = totalStudents > 0 ? ((error.count / totalStudents) * 100).toFixed(1) : '0.0';
  return (
    <div className="rounded-lg p-3 border-l-[3px] border-chart-3 bg-chart-3/5">
      <div className="flex items-start gap-3">
        <span className="text-xs font-bold w-5 h-5 rounded-full flex items-center justify-center shrink-0 mt-0.5 bg-chart-3/20 text-chart-3">
          {rank}
        </span>
        <div className="min-w-0 flex-1">
          <div className="text-sm font-semibold">{error.friendly}</div>
          <div className="text-xs text-muted-foreground mt-1">
            <strong>{error.count}</strong> student{error.count === 1 ? '' : 's'} ({pct}%)
          </div>
        </div>
      </div>
    </div>
  );
}

function InsightCard({ icon: Icon, title, text, highlight = false }) {
  return (
    <div className={`rounded-lg p-3 border ${highlight ? 'bg-chart-2/5 border-chart-2/25' : 'bg-muted/40 border-border'}`}>
      <div className="flex items-start gap-2">
        {Icon && <Icon className="h-4 w-4 text-muted-foreground shrink-0 mt-0.5" strokeWidth={1.5} />}
        <div className="min-w-0">
          <div className="text-xs font-semibold mb-0.5">{title}</div>
          <div className="text-xs text-muted-foreground leading-relaxed">{text}</div>
        </div>
      </div>
    </div>
  );
}

function ReportBody({ report }) {
  const hasCommonErrors = report.commonErrors && report.commonErrors.length > 0;
  const hasTaxonomyIssues = !!report.mostCommonIssue;
  const noData = report.totalStudents === 0;
  const completelyEmpty = !hasCommonErrors && !hasTaxonomyIssues;

  if (noData) {
    return (
      <div className="py-8 text-center">
        <AlertTriangle className="h-8 w-8 text-muted-foreground/40 mx-auto mb-2" strokeWidth={1.5} />
        <p className="text-sm text-muted-foreground">
          No submissions yet. Check back after students complete the exercise.
        </p>
      </div>
    );
  }

  if (completelyEmpty) {
    return (
      <div className="py-8 text-center">
        <AlertTriangle className="h-8 w-8 text-muted-foreground/40 mx-auto mb-2" strokeWidth={1.5} />
        <p className="text-sm text-muted-foreground">
          No patterns detected.
        </p>
      </div>
    );
  }

  return (
    <div className="space-y-4">
      <MetricCard label="Total Students" value={report.totalStudents} />

      {hasCommonErrors && (
        <div>
          <div className="flex items-center gap-2 mb-2">
            <Code2 className="h-3.5 w-3.5 text-muted-foreground" strokeWidth={1.5} />
            <span className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">Common Class Errors</span>
          </div>
          <div className="space-y-2">
            {report.commonErrors.map((err, i) => (
              <CommonErrorCard key={err.normalized} rank={i + 1} error={err} totalStudents={report.totalStudents} />
            ))}
          </div>
        </div>
      )}

      {!hasCommonErrors && hasTaxonomyIssues && (
        <div>
          <div className="flex items-center gap-2 mb-2">
            <Target className="h-3.5 w-3.5 text-muted-foreground" strokeWidth={1.5} />
            <span className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">Detected Patterns</span>
          </div>
          <div className="space-y-2">
            <IssueCard rank={1} issue={report.mostCommonIssue} count={report.affectedCount} percent={report.affectedPercent} isPrimary />
            {report.secondIssue && (
              <IssueCard rank={2} issue={report.secondIssue} count={report.secondCount} percent={report.totalStudents > 0 ? (report.secondCount / report.totalStudents) * 100 : 0} />
            )}
          </div>
        </div>
      )}

      <div className="grid grid-cols-2 gap-3">
        {report.classSummary && <InsightCard icon={TrendingUp} title="Class Summary" text={report.classSummary} />}
        {report.recommendedAction && <InsightCard icon={Target} title="Recommended Action" text={report.recommendedAction} highlight />}
      </div>
    </div>
  );
}

export default function ClassMisconceptionReport({ report, onClose, embedded = false }) {
  if (!report) return null;

  const content = (
    <div className={embedded ? '' : 'bg-background border border-border rounded-xl overflow-hidden shadow-lg'}>
      {!embedded && (
        <div className="flex items-center justify-between p-4 border-b border-border">
          <div className="min-w-0">
            <h2 className="text-base font-semibold">Misconception Report</h2>
            <p className="text-xs text-muted-foreground truncate">{report.exerciseTitle || 'Exercise Analysis'}</p>
          </div>
          {onClose && (
            <button
              onClick={onClose}
              className="h-8 w-8 inline-flex items-center justify-center rounded-md hover:bg-muted transition-colors"
              aria-label="Close"
            >
              <X className="h-4 w-4" strokeWidth={1.5} />
            </button>
          )}
        </div>
      )}
      <div className={embedded ? '' : 'p-4'}>
        <ReportBody report={report} />
      </div>
      {!embedded && onClose && (
        <div className="flex justify-end p-3 border-t border-border">
          <button
            onClick={onClose}
            className="inline-flex items-center gap-1 text-xs font-medium text-muted-foreground hover:text-foreground transition-colors"
          >
            Close Report <ChevronRight className="h-3 w-3" strokeWidth={1.5} />
          </button>
        </div>
      )}
    </div>
  );

  if (embedded) return content;

  return (
    <div className="fixed inset-0 z-50 flex items-center justify-center bg-black/40 backdrop-blur-sm p-4">
      <div className="w-full max-w-lg max-h-[90vh] overflow-y-auto">
        {content}
      </div>
    </div>
  );
}
