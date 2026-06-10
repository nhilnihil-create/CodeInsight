import { useState, useEffect } from 'react';
import { Link } from 'react-router-dom';
import {
  Card,
  CardContent,
  CardHeader,
  CardTitle,
  CardFooter,
} from '@/components/ui/card';
import { Badge } from '@/components/ui/badge';
import { Button } from '@/components/ui/button';
import StudentDashboardShell from '@/components/student-dashboard-shell';
import api from '@/services/api';

const difficultyColors = {
  Beginner: 'secondary',
  Intermediate: 'default',
  Advanced: 'destructive',
};

function getDifficulty(timeLimitMinutes) {
  if (!timeLimitMinutes || timeLimitMinutes <= 30) return 'Beginner';
  if (timeLimitMinutes <= 60) return 'Intermediate';
  return 'Advanced';
}

export default function StudentExercises() {
  const [exercises, setExercises] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);

  useEffect(() => {
    let cancelled = false;
    const load = async () => {
      try {
        const res = await api.get('/api/student/exercises');
        if (!cancelled) setExercises(res.data);
      } catch (err) {
        if (!cancelled) setError(err.response?.data?.error || 'Failed to load exercises');
      } finally {
        if (!cancelled) setLoading(false);
      }
    };
    load();
    return () => { cancelled = true; };
  }, []);

  return (
    <StudentDashboardShell
      breadcrumb={[
        { label: 'Student', href: '/student/dashboard' },
        { label: 'Exercises' },
      ]}
      subtitle="Practice and improve your programming skills."
    >
      {loading ? (
        <div className="py-12 text-center text-muted-foreground">Loading exercises…</div>
      ) : error ? (
        <div className="py-12 text-center text-destructive">{error}</div>
      ) : exercises.length === 0 ? (
        <div className="py-12 text-center text-muted-foreground">No exercises available yet.</div>
      ) : (
        <div className="grid gap-4 md:grid-cols-2 lg:grid-cols-3">
          {exercises.map((ex) => {
            const difficulty = getDifficulty(ex.time_limit_minutes);
            const tags = ex.concept_name ? [ex.concept_name] : [];
            const isCompleted = ex.status === 'completed';
            return (
              <Card key={ex.id} className="flex flex-col h-full">
                <CardHeader>
                  <div className="flex justify-between items-start mb-2">
                    <Badge variant={difficultyColors[difficulty] || 'default'}>
                      {difficulty}
                    </Badge>
                    {ex.deadline && (
                      <span className="text-xs text-muted-foreground">
                        Due: {new Date(ex.deadline).toLocaleDateString()}
                      </span>
                    )}
                  </div>
                  <CardTitle className="text-xl">{ex.title}</CardTitle>
                </CardHeader>
                <CardContent className="flex-1">
                  <p className="text-sm text-muted-foreground mb-4 line-clamp-2">
                    {ex.description}
                  </p>
                  <div className="flex flex-wrap gap-2">
                    {tags.map((tag) => (
                      <Badge key={tag} variant="outline">{tag}</Badge>
                    ))}
                    {isCompleted && (
                      <Badge variant="outline" className="text-success border-success/40">
                        Completed
                      </Badge>
                    )}
                  </div>
                </CardContent>
                <CardFooter className="pt-4 border-t">
                  <Button asChild className="w-full" variant={isCompleted ? 'outline' : 'default'}>
                    <Link to={`/student/exercises/${ex.id}`}>
                      {isCompleted ? 'Review Exercise' : 'Start Exercise'}
                    </Link>
                  </Button>
                </CardFooter>
              </Card>
            );
          })}
        </div>
      )}
    </StudentDashboardShell>
  );
}
