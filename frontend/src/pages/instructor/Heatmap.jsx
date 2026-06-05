import { useEffect, useState } from 'react';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { MOCK_HEATMAP } from '@/data/mockData';
import SectionFilter from '@/components/SectionFilter';
import api from '@/services/api';

/**
 * Class-wide concept heatmap — see spec §3 row 2.
 *
 * Cells colored on a red→yellow→green scale. When a section is picked from
 * the filter, the heatmap is sourced from /api/analytics/heatmap/:sectionId
 * (the same endpoint SectionDetail uses). "All Sections" falls back to the
 * design mock so the page never renders empty in the absence of data.
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
  const [sectionId, setSectionId] = useState('all');
  const [rows, setRows] = useState(MOCK_HEATMAP);
  const [loading, setLoading] = useState(false);

  useEffect(() => {
    if (sectionId === 'all') {
      setRows(MOCK_HEATMAP);
      return;
    }
    let cancelled = false;
    const load = async () => {
      try {
        setLoading(true);
        const res = await api.get(`/api/analytics/heatmap/${sectionId}`);
        const students = res.data?.students || [];
        const scores = res.data?.scores || {};
        const studentNames = {};
        for (const s of students) studentNames[s.studentId] = s.studentName;
        const out = Object.keys(scores).map((studentId) => {
          const conceptScores = {};
          for (const c of CONCEPTS) {
            const cds = scores[studentId]?.[c]?.cds;
            const num = typeof cds === 'string' ? parseFloat(cds) : cds;
            conceptScores[c] = typeof num === 'number' && !isNaN(num)
              ? Math.round(num * 100)
              : 0;
          }
          return {
            studentId,
            name: studentNames[studentId] || `Student #${studentId}`,
            scores: conceptScores,
          };
        });
        if (!cancelled) {
          setRows(out);
          setLoading(false);
        }
      } catch {
        if (!cancelled) {
          setRows([]);
          setLoading(false);
        }
      }
    };
    load();
    return () => { cancelled = true; };
  }, [sectionId]);

  return (
    <div className="space-y-6">
      <div className="flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between">
        <div>
          <h1 className="text-3xl font-bold tracking-tight">Class Heatmap</h1>
          <p className="text-muted-foreground">Concept mastery across the class.</p>
        </div>
        <SectionFilter value={sectionId} onChange={setSectionId} />
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
              {loading ? (
                <tr>
                  <td colSpan={CONCEPTS.length + 1} className="p-6 text-center text-muted-foreground">
                    Loading heatmap…
                  </td>
                </tr>
              ) : rows.length === 0 ? (
                <tr>
                  <td colSpan={CONCEPTS.length + 1} className="p-6 text-center text-muted-foreground">
                    No heatmap data available for this selection.
                  </td>
                </tr>
              ) : (
                rows.map((row) => (
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
