import { useState, useEffect } from 'react';
import { CheckCircle2, AlertTriangle, TrendingUp, Activity } from 'lucide-react';
import api from '../../services/api';
import {
  Card,
  CardContent,
  CardHeader,
  CardTitle,
  CardDescription,
} from '@/components/ui/card';
import { Badge } from '@/components/ui/badge';
import {
  Table,
  TableHeader,
  TableBody,
  TableHead,
  TableRow,
  TableCell,
} from '@/components/ui/table';
import { Skeleton } from '@/components/ui/skeleton';
import { cn } from '@/lib/utils';

/**
 * Student Progress
 *
 * PRESERVED FUNCTIONALITY (do not regress):
 *   - GET /api/analytics/my-scores — returns array of CDS scores
 *   - Polls every 5 s for new CDS scores
 *   - Each row: concept_name, exercise_title, cds, classification, ner, nrs, nts
 *   - Summary stats derived from the real response: distinct exercises,
 *     average CDS, count of "Low" classification rows
 *   - getClassificationColor mapping: Low → green, Moderate → amber, High → red
 *   - formatNumber helper: string/number → fixed decimal, "—" for null
 *
 * REPLACED (visual layer only):
 *   - Dark-hex inline styles → shadcn Card / Table / Badge primitives
 *   - Design-token typography, spacing, borders, hover states
 *   - Added a "Needs Attention" insight card derived from the real data
 *     (closest design analog — design has a Needs-Attention card, the data
 *     here is real, not mock)
 */

const CLASSIFICATION_VARIANT = {
  Low: 'success',
  Moderate: 'warning',
  High: 'destructive',
};

const formatNumber = (value, decimals = 3) => {
  if (value === null || value === undefined) return '—';
  const num = typeof value === 'string' ? parseFloat(value) : value;
  return isNaN(num) ? '—' : num.toFixed(decimals);
};

const parseScore = (s) => ({
  cds: typeof s.cds === 'string' ? parseFloat(s.cds) : s.cds || 0,
  ner: typeof s.ner === 'string' ? parseFloat(s.ner) : s.ner || 0,
  nrs: typeof s.nrs === 'string' ? parseFloat(s.nrs) : s.nrs || 0,
  nts: typeof s.nts === 'string' ? parseFloat(s.nts) : s.nts || 0,
});

export default function StudentProgress() {
  const [scores, setScores] = useState([]);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    fetchScores();
    // Poll for updates every 5 seconds to catch new CDS scores
    const interval = setInterval(fetchScores, 5000);
    return () => clearInterval(interval);
  }, []);

  const fetchScores = async () => {
    try {
      const res = await api.get('/api/analytics/my-scores');
      setScores(res.data || []);
    } catch (err) {
      console.error('Error fetching scores:', err);
    } finally {
      setLoading(false);
    }
  };

  if (loading) {
    return (
      <div className="space-y-6 p-6 lg:p-10">
        <div>
          <h1 className="text-3xl font-bold tracking-tight">My Progress</h1>
          <p className="text-sm text-muted-foreground">Track your learning journey over time.</p>
        </div>
        <div className="grid gap-6 md:grid-cols-3">
          <Skeleton className="h-32 w-full" />
          <Skeleton className="h-32 w-full md:col-span-2" />
        </div>
        <Skeleton className="h-64 w-full" />
      </div>
    );
  }

  if (scores.length === 0) {
    return (
      <div className="space-y-6 p-6 lg:p-10">
        <div>
          <h1 className="text-3xl font-bold tracking-tight">My Progress</h1>
          <p className="text-sm text-muted-foreground">Track your learning journey over time.</p>
        </div>
        <Card>
          <CardContent className="flex flex-col items-center justify-center gap-2 py-16 text-center">
            <Activity className="h-10 w-10 text-muted-foreground/50" />
            <p className="text-sm text-muted-foreground">
              No scores yet. Submit exercises to track your progress.
            </p>
          </CardContent>
        </Card>
      </div>
    );
  }

  const distinctExercises = new Set(scores.map((s) => s.exercise_title)).size;
  const numericScores = scores.map(parseScore);
  const avgCDS =
    numericScores.reduce((a, s) => a + s.cds, 0) / numericScores.length;
  const lowCount = scores.filter((s) => s.classification === 'Low').length;
  const highCount = scores.filter((s) => s.classification === 'High').length;

  // Concept with the highest average CDS = "Needs Attention" (hardest).
  const byConcept = new Map();
  for (const s of scores) {
    const key = s.concept_name || 'Unknown';
    if (!byConcept.has(key)) byConcept.set(key, { sum: 0, count: 0 });
    const acc = byConcept.get(key);
    acc.sum += parseScore(s).cds;
    acc.count += 1;
  }
  const conceptRanking = Array.from(byConcept.entries())
    .map(([concept, { sum, count }]) => ({ concept, avg: sum / count }))
    .sort((a, b) => b.avg - a.avg);

  const needsAttention = conceptRanking[0];
  const mostImproved = conceptRanking[conceptRanking.length - 1];

  return (
    <div className="space-y-6 p-6 lg:p-10">
      <div>
        <h1 className="text-3xl font-bold tracking-tight">My Progress</h1>
        <p className="text-sm text-muted-foreground">Track your learning journey over time.</p>
      </div>

      {/* Summary cards */}
      <div className="grid gap-6 md:grid-cols-3">
        <Card>
          <CardHeader className="pb-2">
            <CardTitle className="flex items-center gap-2 text-lg text-muted-foreground">
              <Activity className="h-5 w-5" /> Total Exercises
            </CardTitle>
          </CardHeader>
          <CardContent>
            <div className="font-mono text-2xl font-bold">{distinctExercises}</div>
            <p className="text-sm text-muted-foreground">
              {scores.length} CDS sample{scores.length === 1 ? '' : 's'} recorded
            </p>
          </CardContent>
        </Card>

        <Card>
          <CardHeader className="pb-2">
            <CardTitle className="flex items-center gap-2 text-lg text-muted-foreground">
              <TrendingUp className="h-5 w-5" /> Average CDS
            </CardTitle>
          </CardHeader>
          <CardContent>
            <div className="font-mono text-2xl font-bold text-primary">
              {formatNumber(avgCDS, 3)}
            </div>
            <p className="text-sm text-muted-foreground">
              {lowCount} low · {highCount} high classification
            </p>
          </CardContent>
        </Card>

        <Card
          className={cn(
            highCount > 0
              ? 'border-destructive/20 bg-destructive/5'
              : 'border-green-500/20 bg-green-500/5'
          )}
        >
          <CardHeader className="pb-2">
            <CardTitle
              className={cn(
                'flex items-center gap-2 text-lg',
                highCount > 0 ? 'text-destructive' : 'text-green-700'
              )}
            >
              {highCount > 0 ? (
                <>
                  <AlertTriangle className="h-5 w-5" /> Needs Attention
                </>
              ) : (
                <>
                  <CheckCircle2 className="h-5 w-5" /> On Track
                </>
              )}
            </CardTitle>
          </CardHeader>
          <CardContent>
            {needsAttention && (
              <>
                <div className="text-2xl font-bold">{needsAttention.concept}</div>
                <p className="text-sm text-muted-foreground">
                  Highest avg CDS at {formatNumber(needsAttention.avg, 2)} — consider practicing
                  more exercises in this area.
                </p>
              </>
            )}
          </CardContent>
        </Card>
      </div>

      {mostImproved && needsAttention && mostImproved.concept !== needsAttention.concept && (
        <Card className="border-green-500/20 bg-green-500/5">
          <CardHeader className="pb-2">
            <CardTitle className="flex items-center gap-2 text-lg text-green-700">
              <CheckCircle2 className="h-5 w-5" /> Most Improved
            </CardTitle>
          </CardHeader>
          <CardContent>
            <div className="text-2xl font-bold">{mostImproved.concept}</div>
            <p className="text-sm text-muted-foreground">
              Lowest avg CDS at {formatNumber(mostImproved.avg, 2)} — strongest area.
            </p>
          </CardContent>
        </Card>
      )}

      {/* Scores table */}
      <Card>
        <CardHeader>
          <CardTitle>CDS Scores</CardTitle>
          <CardDescription>
            Per-exercise Concept Difficulty Score with classification and component metrics.
          </CardDescription>
        </CardHeader>
        <CardContent>
          <Table>
            <TableHeader>
              <TableRow>
                <TableHead>Concept</TableHead>
                <TableHead>Exercise</TableHead>
                <TableHead className="text-center">CDS Score</TableHead>
                <TableHead className="text-center">Classification</TableHead>
                <TableHead className="text-center">NER</TableHead>
                <TableHead className="text-center">NRS</TableHead>
                <TableHead className="text-center">NTS</TableHead>
              </TableRow>
            </TableHeader>
            <TableBody>
              {scores.map((score, i) => {
                const variant = CLASSIFICATION_VARIANT[score.classification] || 'outline';
                return (
                  <TableRow key={i}>
                    <TableCell className="font-medium">{score.concept_name}</TableCell>
                    <TableCell className="text-muted-foreground">
                      {score.exercise_title}
                    </TableCell>
                    <TableCell className="text-center font-mono font-bold">
                      {formatNumber(score.cds, 3)}
                    </TableCell>
                    <TableCell className="text-center">
                      <Badge variant={variant}>{score.classification}</Badge>
                    </TableCell>
                    <TableCell className="text-center font-mono text-muted-foreground">
                      {formatNumber(score.ner, 3)}
                    </TableCell>
                    <TableCell className="text-center font-mono text-muted-foreground">
                      {formatNumber(score.nrs, 3)}
                    </TableCell>
                    <TableCell className="text-center font-mono text-muted-foreground">
                      {formatNumber(score.nts, 3)}
                    </TableCell>
                  </TableRow>
                );
              })}
            </TableBody>
          </Table>
        </CardContent>
      </Card>
    </div>
  );
}
