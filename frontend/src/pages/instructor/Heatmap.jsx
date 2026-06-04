import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { MOCK_HEATMAP } from '@/data/mockData';

/**
 * Class-wide concept heatmap — see spec §3 row 2.
 *
 * Cells colored on a red→yellow→green scale derived from MOCK_HEATMAP scores.
 * If MOCK_HEATMAP is empty we render an explicit empty-state row (spec §7).
 */
function cellColor(score) {
  if (score >= 80) return 'bg-green-500/80 text-white';
  if (score >= 60) return 'bg-green-500/40';
  if (score >= 40) return 'bg-yellow-500/40';
  if (score >= 20) return 'bg-orange-500/50 text-white';
  return 'bg-destructive/80 text-white';
}

const CONCEPTS = ['Loops', 'Arrays', 'Functions', 'Pointers', 'OOP', 'Variables', 'Datatypes', 'Conditionals'];

export default function InstructorHeatmap() {
  return (
    <div className="space-y-6">
      <div>
        <h1 className="text-3xl font-bold tracking-tight">Class Heatmap</h1>
        <p className="text-muted-foreground">Concept mastery across the class.</p>
      </div>
      <Card>
        <CardHeader>
          <CardTitle>Concept × Student</CardTitle>
        </CardHeader>
        <CardContent className="overflow-x-auto">
          <table className="w-full text-sm">
            <thead>
              <tr>
                <th className="text-left p-2 font-medium text-muted-foreground">Student</th>
                {CONCEPTS.map((c) => (
                  <th key={c} className="p-2 font-medium text-muted-foreground">{c}</th>
                ))}
              </tr>
            </thead>
            <tbody>
              {MOCK_HEATMAP.length === 0 ? (
                <tr>
                  <td colSpan={CONCEPTS.length + 1} className="p-6 text-center text-muted-foreground">
                    No heatmap data available.
                  </td>
                </tr>
              ) : (
                MOCK_HEATMAP.map((row) => (
                  <tr key={row.studentId} className="border-t border-border">
                    <td className="p-2 font-medium">{row.name}</td>
                    {CONCEPTS.map((c) => {
                      const score = row.scores[c] ?? 0;
                      return (
                        <td key={c} className="p-1">
                          <div className={`rounded p-2 text-center text-xs font-semibold ${cellColor(score)}`}>
                            {score}
                          </div>
                        </td>
                      );
                    })}
                  </tr>
                ))
              )}
            </tbody>
          </table>
        </CardContent>
      </Card>
    </div>
  );
}
