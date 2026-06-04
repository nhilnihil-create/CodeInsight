import { useState } from 'react';
import { Link, useParams } from 'react-router-dom';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Input } from '@/components/ui/input';
import { Label } from '@/components/ui/label';
import { Textarea } from '@/components/ui/textarea';
import { Select, SelectContent, SelectItem, SelectTrigger, SelectValue } from '@/components/ui/select';
import { ChevronLeft } from 'lucide-react';
import { MOCK_EXERCISES } from '@/data/mockData';

/**
 * Exercise form — see spec §3 row 6.
 * One component, two modes: 'new' (from /instructor/exercises/new) and
 * 'edit' (from /instructor/exercises/:id/edit). The form holds local state
 * for the 5 fields; submission is a console log for this mock slice.
 */
const DIFFICULTIES = ['Beginner', 'Intermediate', 'Advanced'];

export default function InstructorExerciseForm() {
  const { id } = useParams();
  const isEdit = id && id !== 'new';
  const existing = isEdit ? MOCK_EXERCISES.find((e) => e.id === id) : null;

  const [title, setTitle] = useState(existing?.title ?? '');
  const [description, setDescription] = useState(existing?.description ?? '');
  const [difficulty, setDifficulty] = useState(existing?.difficulty ?? 'Beginner');
  const [starterCode, setStarterCode] = useState(existing?.starterCode ?? '');
  const [dueDate, setDueDate] = useState(existing?.dueDate?.slice(0, 10) ?? '');

  if (isEdit && !existing) {
    return (
      <div className="space-y-4">
        <Button asChild variant="ghost" size="sm">
          <Link to="/instructor/exercises"><ChevronLeft className="w-4 h-4 mr-1" /> Back to exercises</Link>
        </Button>
        <Card>
          <CardContent className="p-6">
            <h2 className="text-lg font-semibold mb-2">Exercise not found</h2>
            <p className="text-muted-foreground">No exercise with id <code>{id}</code>.</p>
          </CardContent>
        </Card>
      </div>
    );
  }

  const handleSubmit = (e) => {
    e.preventDefault();
    // Real-API cutover: POST /api/exercises or PUT /api/exercises/:id
    console.log('submit', { mode: isEdit ? 'edit' : 'new', id, title, description, difficulty, starterCode, dueDate });
  };

  return (
    <div className="space-y-6 max-w-3xl">
      <div>
        <Button asChild variant="ghost" size="sm" className="mb-2 -ml-2">
          <Link to="/instructor/exercises"><ChevronLeft className="w-4 h-4 mr-1" /> Back to exercises</Link>
        </Button>
        <h1 className="text-3xl font-bold tracking-tight">{isEdit ? 'Edit Exercise' : 'New Exercise'}</h1>
      </div>

      <form onSubmit={handleSubmit}>
        <Card>
          <CardHeader>
            <CardTitle>Details</CardTitle>
          </CardHeader>
          <CardContent className="space-y-4">
            <div className="space-y-1.5">
              <Label htmlFor="title">Title</Label>
              <Input id="title" value={title} onChange={(e) => setTitle(e.target.value)} required />
            </div>
            <div className="space-y-1.5">
              <Label htmlFor="description">Description</Label>
              <Textarea id="description" rows={4} value={description} onChange={(e) => setDescription(e.target.value)} required />
            </div>
            <div className="grid grid-cols-2 gap-4">
              <div className="space-y-1.5">
                <Label htmlFor="difficulty">Difficulty</Label>
                <Select value={difficulty} onValueChange={setDifficulty}>
                  <SelectTrigger id="difficulty"><SelectValue /></SelectTrigger>
                  <SelectContent>
                    {DIFFICULTIES.map((d) => <SelectItem key={d} value={d}>{d}</SelectItem>)}
                  </SelectContent>
                </Select>
              </div>
              <div className="space-y-1.5">
                <Label htmlFor="dueDate">Due Date</Label>
                <Input id="dueDate" type="date" value={dueDate} onChange={(e) => setDueDate(e.target.value)} />
              </div>
            </div>
            <div className="space-y-1.5">
              <Label htmlFor="starterCode">Starter Code</Label>
              <Textarea
                id="starterCode"
                rows={10}
                value={starterCode}
                onChange={(e) => setStarterCode(e.target.value)}
                className="font-mono text-sm"
              />
            </div>
            <div className="flex justify-end gap-2 pt-2">
              <Button asChild variant="ghost"><Link to="/instructor/exercises">Cancel</Link></Button>
              <Button type="submit">{isEdit ? 'Save Changes' : 'Create Exercise'}</Button>
            </div>
          </CardContent>
        </Card>
      </form>
    </div>
  );
}
