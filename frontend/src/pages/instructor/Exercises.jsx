import { Link } from 'react-router-dom';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Badge } from '@/components/ui/badge';
import { Table, TableBody, TableCell, TableHead, TableHeader, TableRow } from '@/components/ui/table';
import { Plus } from 'lucide-react';
import { MOCK_EXERCISES } from '@/data/mockData';
import ExerciseAccordion from '@/components/analytics/ExerciseAccordion';
import '@/components/analytics/ExerciseAccordion.css';

/**
 * Exercises list — see spec §3 row 5.
 * The new design's "Create Exercise" button is the CTA in the header; the
 * table row link to /instructor/exercises/:id/edit. The per-exercise
 * ExerciseAccordion lives below the table for richer detail.
 *
 * NOTE: ExerciseAccordion is API-driven (takes sectionId + exercises). Until
 * the section/exercise wiring lands the accordion will show its empty/error
 * state (spec §2.3 "single place to wire up real data later").
 */
export default function InstructorExercises() {
  return (
    <div className="space-y-6">
      <div className="flex flex-col sm:flex-row sm:items-center justify-between gap-4">
        <div>
          <h1 className="text-3xl font-bold tracking-tight">Exercises</h1>
          <p className="text-muted-foreground">Manage programming assignments and test cases.</p>
        </div>
        <Button asChild>
          <Link to="/instructor/exercises/new" className="gap-2">
            <Plus className="w-4 h-4" /> Create Exercise
          </Link>
        </Button>
      </div>

      <Card>
        <CardContent className="p-0">
          <Table>
            <TableHeader>
              <TableRow>
                <TableHead>Title</TableHead>
                <TableHead>Concepts</TableHead>
                <TableHead>Difficulty</TableHead>
                <TableHead>Due</TableHead>
                <TableHead />
              </TableRow>
            </TableHeader>
            <TableBody>
              {MOCK_EXERCISES.map((e) => (
                <TableRow key={e.id}>
                  <TableCell className="font-medium">{e.title}</TableCell>
                  <TableCell>
                    <div className="flex gap-1 flex-wrap">
                      {e.conceptTags.map((t) => <Badge key={t} variant="secondary">{t}</Badge>)}
                    </div>
                  </TableCell>
                  <TableCell>
                    <Badge variant={e.difficulty === 'Beginner' ? 'outline' : e.difficulty === 'Intermediate' ? 'secondary' : 'destructive'}>
                      {e.difficulty}
                    </Badge>
                  </TableCell>
                  <TableCell className="text-muted-foreground">
                    {new Date(e.dueDate).toLocaleDateString()}
                  </TableCell>
                  <TableCell className="text-right">
                    <Button asChild variant="ghost" size="sm">
                      <Link to={`/instructor/exercises/${e.id}/edit`}>Edit</Link>
                    </Button>
                  </TableCell>
                </TableRow>
              ))}
            </TableBody>
          </Table>
        </CardContent>
      </Card>

      <Card>
        <CardHeader>
          <CardTitle>Exercise Detail</CardTitle>
        </CardHeader>
        <CardContent>
          <ExerciseAccordion />
        </CardContent>
      </Card>
    </div>
  );
}
