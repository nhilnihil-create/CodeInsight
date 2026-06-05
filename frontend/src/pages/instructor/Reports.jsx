import { useEffect, useState } from 'react';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Tabs, TabsList, TabsTrigger, TabsContent } from '@/components/ui/tabs';
import ResponsiveLineChart from '@/components/charts/ResponsiveLineChart';
import { MOCK_REPORTS_TIMELINE, MOCK_MOST_DIFFICULT_CONCEPTS } from '@/data/mockData';
import ClassWideLongitudinalChart from '@/components/analytics/ClassWideLongitudinalChart';
import LongitudinalTab from '@/components/analytics/LongitudinalTab';
import SectionFilter from '@/components/SectionFilter';
import api from '@/services/api';

/**
 * Reports — see spec §3 row 8.
 * Now respects the section filter. "All Sections" uses the design mock
 * series; a chosen section re-sources the trend line from
 * /api/analytics/sections/:id/longitudinal (weekly average CDS) and the
 * most-difficult-concepts list from /api/analytics/heatmap/:id.
 */
export default function InstructorReports() {
  const [sectionId, setSectionId] = useState('all');
  const [lineData, setLineData] = useState(
    MOCK_REPORTS_TIMELINE.map((p) => ({ x: p.week, y: p.avgCds }))
  );
  const [concepts, setConcepts] = useState(MOCK_MOST_DIFFICULT_CONCEPTS);

  useEffect(() => {
    if (sectionId === 'all') {
      setLineData(MOCK_REPORTS_TIMELINE.map((p) => ({ x: p.week, y: p.avgCds })));
      setConcepts(MOCK_MOST_DIFFICULT_CONCEPTS);
      return;
    }
    let cancelled = false;
    const load = async () => {
      try {
        const [longRes, heatRes] = await Promise.all([
          api.get(`/api/analytics/sections/${sectionId}/longitudinal`),
          api.get(`/api/analytics/heatmap/${sectionId}`),
        ]);
        if (cancelled) return;

        // Aggregate weekly avg CDS from the per-student progression.
        const students = longRes.data?.students || [];
        const weekBuckets = {};
        for (const student of students) {
          for (const point of student.progression || []) {
            const ts = point.computed_at;
            const cds = typeof point.cds === 'string' ? parseFloat(point.cds) : point.cds;
            if (!ts || typeof cds !== 'number' || isNaN(cds)) continue;
            const d = new Date(ts);
            if (isNaN(d.getTime())) continue;
            const year = d.getFullYear();
            const start = new Date(year, 0, 1);
            const wk = Math.floor((d - start) / (1000 * 60 * 60 * 24 * 7)) + 1;
            const key = `${year}-W${wk}`;
            if (!weekBuckets[key]) weekBuckets[key] = { sum: 0, count: 0 };
            weekBuckets[key].sum += cds;
            weekBuckets[key].count += 1;
          }
        }
        const series = Object.keys(weekBuckets)
          .sort()
          .map((k) => {
            const pct = Math.round((weekBuckets[k].sum / weekBuckets[k].count) * 100);
            return { x: k.replace(/^\d+-/, 'W'), y: pct };
          });
        setLineData(series);

        // Aggregate most-difficult concepts from heatmap scores.
        const scores = heatRes.data?.scores || {};
        const totals = {};
        const counts = {};
        for (const studentId in scores) {
          for (const concept in scores[studentId]) {
            const cds = scores[studentId][concept]?.cds;
            const num = typeof cds === 'string' ? parseFloat(cds) : cds;
            if (typeof num === 'number' && !isNaN(num)) {
              totals[concept] = (totals[concept] || 0) + num;
              counts[concept] = (counts[concept] || 0) + 1;
            }
          }
        }
        const rows = Object.keys(totals).map((concept) => ({
          concept,
          score: Math.round((totals[concept] / counts[concept]) * 100),
        }));
        rows.sort((a, b) => a.score - b.score);
        setConcepts(rows);
      } catch {
        if (!cancelled) {
          setLineData([]);
          setConcepts([]);
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
          <h1 className="text-3xl font-bold tracking-tight">Reports</h1>
          <p className="text-muted-foreground">Class-wide trends and concept-level difficulty.</p>
        </div>
        <SectionFilter value={sectionId} onChange={setSectionId} />
      </div>

      <Tabs defaultValue="trend">
        <TabsList>
          <TabsTrigger value="trend">Class Trend</TabsTrigger>
          <TabsTrigger value="longitudinal">Longitudinal</TabsTrigger>
          <TabsTrigger value="concepts">Most Difficult Concepts</TabsTrigger>
        </TabsList>
        <TabsContent value="trend">
          <Card>
            <CardHeader>
              <CardTitle>Weekly Class Average CDS</CardTitle>
            </CardHeader>
            <CardContent className="h-72">
              <ResponsiveLineChart
                data={lineData}
                yDomain={[0, 100]}
                yFmt={(v) => v.toFixed(0)}
                emptyMessage="No class trend data yet."
              />
            </CardContent>
          </Card>
        </TabsContent>
        <TabsContent value="longitudinal">
          {sectionId === 'all' ? (
            <ClassWideLongitudinalChart />
          ) : (
            <ClassWideLongitudinalChart sectionId={sectionId} />
          )}
        </TabsContent>
        <TabsContent value="concepts">
          <Card>
            <CardHeader>
              <CardTitle>Most Difficult Concepts</CardTitle>
            </CardHeader>
            <CardContent>
              {concepts.length === 0 ? (
                <div className="rounded-md border border-border bg-muted/30 p-6 text-center text-sm text-muted-foreground">
                  No concept data for this selection.
                </div>
              ) : (
                <LongitudinalTab data={concepts} />
              )}
            </CardContent>
          </Card>
        </TabsContent>
      </Tabs>
    </div>
  );
}
