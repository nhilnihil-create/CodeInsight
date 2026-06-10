import { CheckCircle2, XCircle, Loader2, AlertTriangle } from 'lucide-react';
import { Badge } from '@/components/ui/badge';

/**
 * ValidationResultsPanel — shows per-test-case validation results.
 *
 * Props:
 *   results     — array of { passed, status, validationType, actual, expected, error }
 *   is_validating — boolean, shows loading spinner when true
 *   onTestClick — (index: number) => void, scrolls to the failing test case row
 */
export default function ValidationResultsPanel({ results, is_validating, onTestClick }) {
  if (is_validating) {
    return (
      <div className="flex items-center gap-2 py-6 justify-center text-muted-foreground">
        <Loader2 className="w-4 h-4 animate-spin" />
        <span className="text-sm">Running reference solution against test cases…</span>
      </div>
    );
  }

  if (!results || results.length === 0) {
    return null;
  }

  const passedCount = results.filter(r => r.passed).length;
  const totalCount = results.length;
  const allPassed = passedCount === totalCount;

  return (
    <div className="space-y-3">
      {/* Summary */}
      <div className={`flex items-center gap-2 p-3 rounded-lg border ${
        allPassed ? 'border-green-500/30 bg-green-500/5' : 'border-destructive/30 bg-destructive/5'
      }`}>
        {allPassed ? (
          <CheckCircle2 className="w-4 h-4 text-green-500" />
        ) : (
          <XCircle className="w-4 h-4 text-destructive" />
        )}
        <span className="text-sm font-medium">
          {allPassed ? 'All test cases passed!' : `${totalCount - passedCount} of ${totalCount} test(s) failed`}
        </span>
      </div>

      {/* Per-test results */}
      <div className="space-y-2">
        {results.map((r, i) => (
          <button
            key={i}
            type="button"
            onClick={() => { if (!r.passed && onTestClick) onTestClick(i); }}
            className={`w-full text-left p-3 rounded-lg border transition-colors ${
              r.passed
                ? 'border-green-500/20 bg-green-500/5'
                : 'border-destructive/20 bg-destructive/5 cursor-pointer hover:bg-destructive/10'
            }`}
          >
            <div className="flex items-center gap-2">
              {r.passed ? (
                <CheckCircle2 className="w-4 h-4 text-green-500 shrink-0" />
              ) : (
                <XCircle className="w-4 h-4 text-destructive shrink-0" />
              )}
              <span className="text-xs font-medium">Test {i + 1}</span>
              <Badge variant="outline" className="text-[10px] px-1 py-0 h-4">
                {r.validationType}
              </Badge>
              {r.status !== 'Success' && (
                <Badge variant="destructive" className="text-[10px] px-1 py-0 h-4">
                  {r.status}
                </Badge>
              )}
              {!r.passed && r.status === 'Success' && (
                <Badge variant="secondary" className="text-[10px] px-1 py-0 h-4">
                  Mismatch
                </Badge>
              )}
            </div>

            {!r.passed && r.error && (
              <div className="mt-1.5 flex items-start gap-1.5 text-[10px] text-muted-foreground">
                <AlertTriangle className="w-3 h-3 text-amber-500 shrink-0 mt-px" />
                <span className="font-mono">{r.error}</span>
              </div>
            )}
          </button>
        ))}
      </div>
    </div>
  );
}
