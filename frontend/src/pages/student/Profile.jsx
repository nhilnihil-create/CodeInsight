import { useState, useEffect } from 'react';
import {
  Radar,
  RadarChart,
  PolarGrid,
  PolarAngleAxis,
  PolarRadiusAxis,
  ResponsiveContainer,
} from 'recharts';
import {
  Card,
  CardContent,
  CardHeader,
  CardTitle,
  CardDescription,
} from '@/components/ui/card';
import { Badge } from '@/components/ui/badge';
import { Skeleton } from '@/components/ui/skeleton';
import StudentDashboardShell from '@/components/student-dashboard-shell';
import api from '../../services/api';

/**
 * Student Concept Profile
 *
 * Derived from the design's Profile page but uses REAL data
 * (GET /api/analytics/my-scores). Aggregates the per-exercise CDS scores
 * into per-concept buckets, then renders a radar chart and per-concept cards.
 *
 * PRESERVED FUNCTIONALITY:
 *   - Real data source: /api/analytics/my-scores
 *   - Polling pattern (5s) — same as the rest of the app
 *   - CDS classification thresholds: 0-25 Low, 26-50 Medium, 51-75 High, 76+ Critical
 *
 * REPLACED (visual layer only):
 *   - Design's MOCK_RADAR_DATA → aggregated real CDS by concept
 *   - Hard-coded "Exercises Attempted" → real count from data
 */
/**
 * getDifficultyBadge — takes CDS as a 0–1 value (the raw API format).
 * Converts to 0–100 scale for classification.
 * CDS measures difficulty, so lower = better.
 */
const getDifficultyBadge = (cds01) => {
  if (cds01 == null) return null;
  const cds100 = cds01 * 100; // convert 0–1 to 0–100 scale
  if (cds100 <= 25)
    return (
      <Badge variant="secondary" className="bg-green-500/10 text-green-700">
        Low
      </Badge>
    );
  if (cds100 <= 50)
    return (
      <Badge variant="secondary" className="bg-blue-500/10 text-blue-700">
        Medium
      </Badge>
    );
  if (cds100 <= 75)
    return (
      <Badge variant="secondary" className="bg-orange-500/10 text-orange-700">
        High
      </Badge>
    );
  return <Badge variant="destructive">Critical</Badge>;
};

const aggregateByConcept = (scores) => {
  const buckets = new Map();
  for (const s of scores || []) {
    const concept = s.concept_name || 'Unknown';
    if (!buckets.has(concept)) {
      buckets.set(concept, { subject: concept, cdsTotal: 0, cdsCount: 0, attempts: 0 });
    }
    const b = buckets.get(concept);
    b.cdsTotal += Number(s.cds) || 0;
    b.cdsCount += 1;
    b.attempts += 1;
  }
  // Convert CDS → mastery (100 - CDS×100) so larger radar area = better.
  // This aligns with the Progress page radar where larger = better.
  return Array.from(buckets.values()).map((b) => {
    const avgCds = b.cdsCount > 0 ? (b.cdsTotal / b.cdsCount) : 0;
    return {
      subject: b.subject,
      mastery: Math.round((1 - avgCds) * 10000) / 100, // 0–100 scale
      cds: Math.round(avgCds * 100) / 100,
      attempts: b.attempts,
    };
  });
};

export default function StudentProfile() {
  const [scores, setScores] = useState([]);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    let active = true;
    const load = async () => {
      try {
        const res = await api.get('/api/analytics/my-scores');
        if (active) setScores(res.data || []);
      } catch (err) {
        // network errors are expected for unauthenticated users; leave empty
      } finally {
        if (active) setLoading(false);
      }
    };
    load();
    const t = setInterval(load, 5000);
    return () => {
      active = false;
      clearInterval(t);
    };
  }, []);

  const radarData = aggregateByConcept(scores);

  return (
    <StudentDashboardShell
      breadcrumb={[
        { label: 'Student', href: '/student/dashboard' },
        { label: 'My Concept Profile' },
      ]}
      subtitle="Concept mastery and difficulty scores across programming topics."
    >
      <div className="grid gap-6 md:grid-cols-3">
        <Card className="md:col-span-1">
          <CardHeader>
            <CardTitle>What is CDS?</CardTitle>
          </CardHeader>
          <CardContent className="space-y-4 text-sm text-muted-foreground">
            <p>
              The Concept Difficulty Score (CDS) measures how much you are
              struggling with a specific programming concept.
            </p>
            <ul className="list-disc space-y-2 pl-5">
              <li>
                <strong className="text-foreground">0–25 (Low):</strong> You have
                a strong grasp of this concept.
              </li>
              <li>
                <strong className="text-foreground">26–50 (Medium):</strong>{' '}
                Normal learning curve, some mistakes but recovering well.
              </li>
              <li>
                <strong className="text-foreground">51–75 (High):</strong> You
                are experiencing significant difficulty. Consider reviewing
                materials.
              </li>
              <li>
                <strong className="text-foreground">76–100 (Critical):</strong>{' '}
                Severe difficulty detected. Reach out to your instructor for
                help.
              </li>
            </ul>
            <p>
              CDS = (0.40 × NER) + (0.35 × NRS) + (0.25 × NTS), normalized to a
              0–100 scale.
            </p>
            <p className="text-xs text-muted-foreground border-t border-border pt-2">
              <strong>Mastery = 100 − CDS.</strong> The radar chart below shows
              mastery (larger area = better understanding), not difficulty.
            </p>
          </CardContent>
        </Card>

        <Card className="md:col-span-2">
          <CardHeader>
            <CardTitle>Concept Mastery Footprint</CardTitle>
            <CardDescription>
              {radarData.length === 0
                ? 'Submit some exercises to see your mastery profile.'
                : `${radarData.length} concepts, ${scores.length} submissions — larger area = better understanding`}
            </CardDescription>
          </CardHeader>
          <CardContent className="h-[400px]">
            {loading ? (
              <Skeleton className="h-full w-full" />
            ) : radarData.length === 0 ? (
              <div className="flex h-full items-center justify-center text-sm text-muted-foreground">
                No data yet.
              </div>
            ) : (
              <ResponsiveContainer width="100%" height="100%">
                <RadarChart
                  cx="50%"
                  cy="50%"
                  outerRadius="80%"
                  data={radarData}
                >
                  <PolarGrid />
                  <PolarAngleAxis
                    dataKey="subject"
                    tick={{ fill: 'hsl(var(--foreground))', fontSize: 12 }}
                  />
                  <PolarRadiusAxis angle={30} domain={[0, 100]} />
                  <Radar
                    name="Mastery"
                    dataKey="mastery"
                    stroke="hsl(var(--primary))"
                    fill="hsl(var(--primary))"
                    fillOpacity={0.6}
                  />
                </RadarChart>
              </ResponsiveContainer>
            )}
          </CardContent>
        </Card>
      </div>

      {radarData.length > 0 && (
        <div className="grid gap-4 md:grid-cols-2 lg:grid-cols-3 xl:grid-cols-4">
          {radarData.map((data) => {
            const masteryScore = data.mastery;
            const cdsScore = data.cds;
            const difficultyLabel = cdsScore <= 0.25 ? 'Low' : cdsScore <= 0.50 ? 'Medium' : cdsScore <= 0.75 ? 'High' : 'Critical';
            return (
              <Card key={data.subject}>
                <CardHeader className="pb-2">
                  <div className="flex items-start justify-between">
                    <CardTitle className="text-lg">{data.subject}</CardTitle>
                    {getDifficultyBadge(cdsScore)}
                  </div>
                  <CardDescription>
                    Mastery: {masteryScore.toFixed(0)}% · Difficulty: {cdsScore.toFixed(2)} ({difficultyLabel})
                  </CardDescription>
                </CardHeader>
                <CardContent>
                  <p className="mb-1 text-sm text-muted-foreground">
                    Submissions: {data.attempts}
                  </p>
                  <div className="mt-2 h-2 w-full rounded-full bg-muted overflow-hidden">
                    <div
                      className={
                        masteryScore > 75
                          ? 'h-2 rounded-full bg-green-500'
                          : masteryScore > 50
                            ? 'h-2 rounded-full bg-blue-500'
                            : masteryScore > 25
                              ? 'h-2 rounded-full bg-orange-500'
                              : 'h-2 rounded-full bg-destructive'
                      }
                      style={{ width: `${masteryScore}%` }}
                    />
                  </div>
                </CardContent>
              </Card>
            );
          })}
        </div>
      )}
    </StudentDashboardShell>
  );
}
