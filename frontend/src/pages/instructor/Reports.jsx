import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Tabs, TabsList, TabsTrigger, TabsContent } from '@/components/ui/tabs';
import ResponsiveLineChart from '@/components/charts/ResponsiveLineChart';
import { MOCK_REPORTS_TIMELINE, MOCK_MOST_DIFFICULT_CONCEPTS } from '@/data/mockData';
import ClassWideLongitudinalChart from '@/components/analytics/ClassWideLongitudinalChart';
import LongitudinalTab from '@/components/analytics/LongitudinalTab';

/**
 * Reports — see spec §3 row 8.
 * Three sections: class trend (ResponsiveLineChart on MOCK_REPORTS_TIMELINE),
 * the embedded ClassWideLongitudinalChart analytics component, and the
 * LongitudinalTab (with Most-Difficult-Concepts data).
 *
 * NOTE: ResponsiveLineChart in this codebase takes a flat [{x, y}] array
 * with xFmt/yFmt/yDomain (per the component's own JSDoc), not nivo-style
 * xKey/yKey/seriesKey — the spec's literal call was adjusted to match the
 * real signature.
 */
export default function InstructorReports() {
  const lineData = MOCK_REPORTS_TIMELINE.map((p) => ({ x: p.week, y: p.avgCds }));

  return (
    <div className="space-y-6">
      <div>
        <h1 className="text-3xl font-bold tracking-tight">Reports</h1>
        <p className="text-muted-foreground">Class-wide trends and concept-level difficulty.</p>
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
          <ClassWideLongitudinalChart />
        </TabsContent>
        <TabsContent value="concepts">
          <LongitudinalTab data={MOCK_MOST_DIFFICULT_CONCEPTS} />
        </TabsContent>
      </Tabs>
    </div>
  );
}
