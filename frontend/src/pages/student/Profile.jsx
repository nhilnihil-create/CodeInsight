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
const getDifficultyBadge = (score) => {
  if (score == null) return null;
  if (score <= 25)
    return (
      <Badge variant="secondary" className="bg-green-500/10 text-green-700">
        Low
      </Badge>
    );
  if (score <= 50)
    return (
      <Badge variant="secondary" className="bg-blue-500/10 text-blue-700">
        Medium
      </Badge>
    );
  if (score <= 75)
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
      buckets.set(concept, { subject: concept, total: 0, count: 0, attempts: 0 });
    }
    const b = buckets.get(concept);
    b.total += Number(s.cds) || 0;
    b.count += 1;
    b.attempts += 1;
  }
  return Array.from(buckets.values()).map((b) => ({
    subject: b.subject,
    A: b.count > 0 ? Math.round((b.total / b.count) * 100) / 100 : 0,
    attempts: b.attempts,
  }));
};

export default function StudentProfile() {
  const [scores, setScores] = useState([]);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    let active = true;
    const load = async () => {
      try {
        const res = await api.get('/analytics/my-scores');
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
    <div className="space-y-6">
      <div>
        <h1 className="text-3xl font-bold tracking-tight">My Concept Profile</h1>
        <p className="text-muted-foreground">
          Understanding your Concept Difficulty Score (CDS) across different
          programming topics.
        </p>
      </div>

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
          </CardContent>
        </Card>

        <Card className="md:col-span-2">
          <CardHeader>
            <CardTitle>Overall Concept Footprint</CardTitle>
            <CardDescription>
              {radarData.length === 0
                ? 'Submit some exercises to see your profile.'
                : `${radarData.length} concepts, ${scores.length} submissions`}
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
                    name="CDS"
                    dataKey="A"
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
          {radarData.map((data) => (
            <Card key={data.subject}>
              <CardHeader className="pb-2">
                <div className="flex items-start justify-between">
                  <CardTitle className="text-lg">{data.subject}</CardTitle>
                  {getDifficultyBadge(data.A)}
                </div>
                <CardDescription>CDS: {data.A}</CardDescription>
              </CardHeader>
              <CardContent>
                <p className="mb-1 text-sm text-muted-foreground">
                  Submissions: {data.attempts}
                </p>
                <div className="mt-2 h-2 w-full rounded-full bg-muted">
                  <div
                    className={
                      data.A > 75
                        ? 'h-2 rounded-full bg-destructive'
                        : data.A > 50
                          ? 'h-2 rounded-full bg-orange-500'
                          : data.A > 25
                            ? 'h-2 rounded-full bg-blue-500'
                            : 'h-2 rounded-full bg-green-500'
                    }
                    style={{ width: `${data.A}%` }}
                  />
                </div>
              </CardContent>
            </Card>
          ))}
        </div>
      )}
    </div>
  );
}
