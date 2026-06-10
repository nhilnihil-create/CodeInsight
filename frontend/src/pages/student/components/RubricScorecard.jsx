import { cn } from '@/lib/utils';

const PILLARS = [
  { key: 'functional',   label: 'Functional Correctness', max: 100 },
  { key: 'efficiency',   label: 'Efficiency',              max: 100 },
  { key: 'standards',    label: 'Standards & Style',       max: 100 },
  { key: 'integrity',    label: 'Integrity',               max: 100 },
];

function pillarColor(score) {
  if (score >= 70) return 'bg-green-500';
  if (score >= 40) return 'bg-amber-500';
  return 'bg-destructive';
}

function pillarTextColor(score) {
  if (score >= 70) return 'text-green-700';
  if (score >= 40) return 'text-amber-700';
  return 'text-destructive';
}

function totalColor(total) {
  if (total >= 70) return 'text-green-600';
  if (total >= 40) return 'text-amber-600';
  return 'text-destructive';
}

/**
 * RubricScorecard — displays 4-pillar rubric breakdown for assessment submissions.
 *
 * Props:
 *   rubricScore — { pillars, weightedTotal, rubricConfig, details }
 */
export default function RubricScorecard({ rubricScore }) {
  if (!rubricScore) return null;

  const { pillars, weightedTotal, rubricConfig, details } = rubricScore;

  return (
    <div className="space-y-3">
      <div>
        <h4 className="text-sm font-semibold">Assessment Rubric</h4>
        <p className="text-[10px] text-muted-foreground">
          Weighted score based on 4 pillars
        </p>
      </div>

      {/* Pillar bars */}
      {PILLARS.map(p => {
        const score = pillars[p.key] || 0;
        const weight = rubricConfig?.[p.key] || 0;
        return (
          <div key={p.key} className="space-y-1">
            <div className="flex items-center justify-between text-xs">
              <span className="font-medium">{p.label}</span>
              <span className={cn('font-mono font-semibold', pillarTextColor(score))}>
                {score}%
                <span className="text-muted-foreground font-normal ml-1 text-[10px]">
                  (×{weight}%)
                </span>
              </span>
            </div>
            <div className="h-2 rounded-full bg-muted overflow-hidden">
              <div
                className={cn('h-full rounded-full transition-all', pillarColor(score))}
                style={{ width: `${Math.min(score, 100)}%` }}
              />
            </div>
          </div>
        );
      })}

      {/* Total */}
      <div className={cn(
        'flex items-center justify-between p-3 rounded-lg border mt-2',
        totalColor(weightedTotal) === 'text-green-600' ? 'border-green-500/30 bg-green-500/5' :
        totalColor(weightedTotal) === 'text-amber-600' ? 'border-amber-500/30 bg-amber-500/5' :
        'border-destructive/30 bg-destructive/5'
      )}>
        <span className="text-sm font-semibold">Weighted Total</span>
        <span className={cn('text-xl font-mono font-bold', totalColor(weightedTotal))}>
          {weightedTotal}%
        </span>
      </div>

      {/* Details (if available) */}
      {details && (
        <div className="text-[10px] text-muted-foreground space-y-0.5 pt-1">
          {details.medianTime && (
            <p>Class median time: {details.medianTime}s · Your time: {details.studentTime}s</p>
          )}
          {details.cppcheckWarningCount > 0 && (
            <p>Cppcheck warnings: {details.cppcheckWarningCount}</p>
          )}
          {details.integrityFlagCount > 0 && (
            <p>Integrity flags: {details.integrityFlagCount}</p>
          )}
        </div>
      )}
    </div>
  );
}
