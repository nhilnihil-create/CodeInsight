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
import { MOCK_EXERCISES } from '../../data/mockData';

const difficultyVariant = {
  Beginner: 'secondary',
  Intermediate: 'default',
  Advanced: 'destructive',
};

export default function StudentExercises() {
  return (
    <StudentDashboardShell
      breadcrumb={[
        { label: 'Student', href: '/student/dashboard' },
        { label: 'Exercises' },
      ]}
      subtitle="Practice and improve your programming skills."
    >
      <div className="grid gap-4 md:grid-cols-2 lg:grid-cols-3">
        {MOCK_EXERCISES.map((ex) => (
          <Card key={ex.id} className="flex flex-col h-full">
            <CardHeader>
              <div className="flex justify-between items-start mb-2">
                <Badge variant={difficultyVariant[ex.difficulty] || 'default'}>
                  {ex.difficulty}
                </Badge>
                <span className="text-xs text-muted-foreground">
                  Due: {new Date(ex.dueDate).toLocaleDateString()}
                </span>
              </div>
              <CardTitle className="text-xl">{ex.title}</CardTitle>
            </CardHeader>
            <CardContent className="flex-1">
              <p className="text-sm text-muted-foreground mb-4 line-clamp-2">
                {ex.description}
              </p>
              <div className="flex flex-wrap gap-2">
                {ex.conceptTags.map((tag) => (
                  <Badge key={tag} variant="outline">
                    {tag}
                  </Badge>
                ))}
              </div>
            </CardContent>
            <CardFooter className="pt-4 border-t">
              <Button asChild className="w-full">
                <Link to={`/student/exercises/${ex.id}`}>Start Exercise</Link>
              </Button>
            </CardFooter>
          </Card>
        ))}
      </div>
    </StudentDashboardShell>
  );
}
