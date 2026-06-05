import { useEffect, useState } from 'react';
import { Link } from 'react-router-dom';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Badge } from '@/components/ui/badge';
import { Table, TableBody, TableCell, TableHead, TableHeader, TableRow } from '@/components/ui/table';
import { Plus } from 'lucide-react';
import { MOCK_EXERCISES } from '@/data/mockData';
import ExerciseAccordion from '@/components/analytics/ExerciseAccordion';
import SectionFilter from '@/components/SectionFilter';
import api from '@/services/api';
import '@/components/analytics/ExerciseAccordion.css';

/**
 * Exercises list — see spec §3 row 5.
 * "All Sections" shows the design MOCK_EXERCISES; a chosen section
 * re-sources the table from /api/sections/:id/exercises.
 */
export default function InstructorExercises() {
  const [sectionId, setSectionId] = useState('all');
  const [exercises, setExercises] = useState(MOCK_EXERCISES);

  useEffect(() => {
    if (sectionId === 'all') {
      setExercises(MOCK_EXERCISES);
      return;
    }
    let cancelled = false;
    const load = async () => {
      try {
        const res = await api.get(`/api/sections/${sectionId}/exercises`);
        if (!cancelled) {
          const list = Array.isArray(res.data) ? res.data : [];
          setExercises(
            list.map((e) => ({
              id: e.id,
              title: e.title,
              conceptTags: e.concept_tags || e.conceptTags || [],
              difficulty: e.difficulty || 'Beginner',
              dueDate: e.due_date || e.dueDate,
            }))
          );
        }
      } catch {
        if (!cancelled) setExercises([]);
      }
    };
    load();
    return () => { cancelled = true; };
  }, [sectionId]);

  return (
    <div className="space-y-6">
      <div className="flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between">
        <div>
          <h1 className="text-3xl font-bold tracking-tight">Exercises</h1>
          <p className="text-muted-foreground">Manage programming assignments and test cases.</p>
        </div>
        <div className="flex flex-col gap-2 sm:flex-row sm:items-center">
          <SectionFilter value={sectionId} onChange={setSectionId} />
          <Button asChild>
            <Link to="/instructor/exercises/new" className="gap-2">
              <Plus className="w-4 h-4" /> Create Exercise
            </Link>
          </Button>
        </div>
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
              {exercises.length === 0 ? (
                <TableRow>
                  <TableCell colSpan={5} className="text-center text-muted-foreground py-6">
                    No exercises found for this selection.
                  </TableCell>
                </TableRow>
              ) : (
                exercises.map((e) => (
                  <TableRow key={e.id}>
                    <TableCell className="font-medium">{e.title}</TableCell>
                    <TableCell>
                      <div className="flex gap-1 flex-wrap">
                        {(e.conceptTags || []).map((t) => (
                          <Badge key={t} variant="secondary">{t}</Badge>
                        ))}
                      </div>
                    </TableCell>
                    <TableCell>
                      <Badge variant={e.difficulty === 'Beginner' ? 'outline' : e.difficulty === 'Intermediate' ? 'secondary' : 'destructive'}>
                        {e.difficulty}
                      </Badge>
                    </TableCell>
                    <TableCell className="text-muted-foreground">
                      {e.dueDate ? new Date(e.dueDate).toLocaleDateString() : '—'}
                    </TableCell>
                    <TableCell className="text-right">
                      <Button asChild variant="ghost" size="sm">
                        <Link to={`/instructor/exercises/${e.id}/edit`}>Edit</Link>
                      </Button>
                    </TableCell>
                  </TableRow>
                ))
              )}
            </TableBody>
          </Table>
        </CardContent>
      </Card>

      <Card>
        <CardHeader>
          <CardTitle>Exercise Detail</CardTitle>
        </CardHeader>
        <CardContent>
          <ExerciseAccordion sectionId={sectionId === 'all' ? undefined : sectionId} />
        </CardContent>
      </Card>
    </div>
  );
}
