import { useEffect, useState } from 'react';
import { Link } from 'react-router-dom';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Badge } from '@/components/ui/badge';
import { Table, TableBody, TableCell, TableHead, TableHeader, TableRow } from '@/components/ui/table';
import { Plus, Lock, Unlock } from 'lucide-react';
import { MOCK_EXERCISES } from '@/data/mockData';
import ExerciseAccordion from '@/components/analytics/ExerciseAccordion';
import SectionFilter from '@/components/SectionFilter';
import api from '@/services/api';
import '@/components/analytics/ExerciseAccordion.css';

/**
 * Exercises list — see spec §3 row 5.
 * "All Sections" falls back to MOCK_EXERCISES for design continuity when
 * the instructor has no created exercises yet. A chosen section re-sources
 * the table from /api/sections/:id/exercises; the "All Sections" + new flow
 * re-sources from /api/exercises (instructor-scoped).
 */
export default function InstructorExercises() {
  const [sectionId, setSectionId] = useState('all');
  const [exercises, setExercises] = useState(MOCK_EXERCISES);
  const [busyId, setBusyId] = useState(null);
  const [error, setError] = useState(null);

  const loadAll = async () => {
    try {
      const res = await api.get('/api/exercises');
      const list = Array.isArray(res.data) ? res.data : [];
      if (list.length === 0) {
        setExercises(MOCK_EXERCISES);
        return;
      }
      setExercises(list.map(e => ({
        id: e.id,
        title: e.title,
        conceptTags: e.concept_name ? [e.concept_name] : [],
        difficulty: 'Beginner',
        dueDate: e.deadline,
        isDraft: e.is_draft,
        closedAt: e.closed_at,
        sectionId: e.section_id,
      })));
    } catch {
      setExercises(MOCK_EXERCISES);
    }
  };

  useEffect(() => {
    if (sectionId !== 'all') return;
    let cancelled = false;
    loadAll().then(() => { if (cancelled) setExercises(get => get); });
    return () => { cancelled = true; };
    // eslint-disable-next-line react-hooks/exhaustive-deps
  }, [sectionId]);

  useEffect(() => {
    if (sectionId === 'all') return;
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
              isDraft: e.is_draft,
              closedAt: e.closed_at,
              sectionId: e.section_id,
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

  const handleClose = async (e) => {
    setBusyId(e.id); setError(null);
    try {
      await api.post(`/api/exercises/${e.id}/close`);
      await loadAll();
    } catch (err) {
      setError(err.response?.data?.message || err.message);
    } finally { setBusyId(null); }
  };

  const handleReopen = async (e) => {
    setBusyId(e.id); setError(null);
    try {
      await api.post(`/api/exercises/${e.id}/reopen`);
      await loadAll();
    } catch (err) {
      setError(err.response?.data?.message || err.message);
    } finally { setBusyId(null); }
  };

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

      {error && <p className="text-sm text-destructive">{error}</p>}

      <Card>
        <CardContent className="p-0">
          <Table>
            <TableHeader>
              <TableRow>
                <TableHead>Title</TableHead>
                <TableHead>Concepts</TableHead>
                <TableHead>Difficulty</TableHead>
                <TableHead>Due</TableHead>
                <TableHead>Status</TableHead>
                <TableHead />
              </TableRow>
            </TableHeader>
            <TableBody>
              {exercises.length === 0 ? (
                <TableRow>
                  <TableCell colSpan={6} className="text-center text-muted-foreground py-6">
                    No exercises found for this selection.
                  </TableCell>
                </TableRow>
              ) : (
                exercises.map((e) => {
                  const isClosed = !!e.closedAt;
                  return (
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
                      <TableCell>
                        {e.isDraft ? <Badge variant="outline">Draft</Badge>
                          : isClosed ? <Badge variant="secondary">Closed</Badge>
                          : <Badge className="bg-emerald-500/15 text-emerald-600 border-emerald-500/30">Open</Badge>}
                      </TableCell>
                      <TableCell className="text-right">
                        <div className="inline-flex gap-1">
                          <Button asChild variant="ghost" size="sm">
                            <Link to={`/instructor/exercises/${e.id}/edit`}>Edit</Link>
                          </Button>
                          {isClosed ? (
                            <Button variant="ghost" size="sm" onClick={() => handleReopen(e)} disabled={busyId === e.id} title="Reopen exercise">
                              <Unlock className="w-3.5 h-3.5" />
                            </Button>
                          ) : (
                            <Button variant="ghost" size="sm" onClick={() => handleClose(e)} disabled={busyId === e.id} title="Close exercise (compute CDS)">
                              <Lock className="w-3.5 h-3.5" />
                            </Button>
                          )}
                        </div>
                      </TableCell>
                    </TableRow>
                  );
                })
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
