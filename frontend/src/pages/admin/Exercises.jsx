import { useState, useEffect, useCallback } from 'react';
import { Link } from 'react-router-dom';
import { Search, Plus, CheckCircle2, XCircle } from 'lucide-react';
import api from '../../services/api';
import { Card } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Input } from '@/components/ui/input';
import { Badge } from '@/components/ui/badge';

export default function AdminExercises() {
  const [exercises, setExercises] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [search, setSearch] = useState('');

  const load = useCallback(async () => {
    setLoading(true);
    setError(null);
    try {
      const res = await api.get('/api/admin/exercises');
      setExercises(res.data.exercises || []);
    } catch (err) {
      setError(err.response?.data?.message || err.message);
    } finally {
      setLoading(false);
    }
  }, []);

  useEffect(() => { load(); }, [load]);

  const toggleExercise = async (id, closed) => {
    try {
      await api.patch(`/api/admin/exercises/${id}`, { closed });
      await load();
    } catch (err) {
      setError(err.response?.data?.message || err.message);
    }
  };

  const filtered = exercises.filter(e =>
    !search ||
    e.title.toLowerCase().includes(search.toLowerCase()) ||
    e.concept_name?.toLowerCase().includes(search.toLowerCase()) ||
    e.section_name?.toLowerCase().includes(search.toLowerCase())
  );

  return (
    <div className="space-y-4">
      <div className="flex items-center justify-between">
        <div className="relative w-[200px]">
          <Search className="pointer-events-none absolute left-2.5 top-1/2 h-3.5 w-3.5 -translate-y-1/2 text-muted-foreground" />
          <Input type="text" placeholder="Search exercises..." value={search} onChange={e => setSearch(e.target.value)} className="h-8 pl-7 text-xs" />
        </div>
        <Button asChild size="sm"><Link to="/instructor/create-exercise"><Plus className="mr-1 h-3.5 w-3.5" /> New Exercise</Link></Button>
      </div>

      {error && <p className="text-xs text-destructive">Failed to load: {error}</p>}

      <Card>
        <div className="overflow-x-auto">
          <table className="w-full border-collapse text-xs">
            <thead className="bg-muted/30">
              <tr>
                <th className="border-b border-border px-3 py-2.5 text-left text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Title</th>
                <th className="border-b border-border px-3 py-2.5 text-left text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Concept</th>
                <th className="border-b border-border px-3 py-2.5 text-left text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Section</th>
                <th className="border-b border-border px-3 py-2.5 text-left text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Creator</th>
                <th className="border-b border-border px-3 py-2.5 text-center text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Submissions</th>
                <th className="border-b border-border px-3 py-2.5 text-center text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Status</th>
                <th className="border-b border-border px-3 py-2.5 text-center text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Actions</th>
              </tr>
            </thead>
            <tbody>
              {loading ? (
                <tr><td colSpan="7" className="px-3 py-6 text-center text-muted-foreground">Loading exercises…</td></tr>
              ) : filtered.length === 0 ? (
                <tr><td colSpan="7" className="px-3 py-6 text-center text-muted-foreground">No exercises found.</td></tr>
              ) : filtered.map(e => (
                <tr key={e.id} className="border-b border-border/60 last:border-0 hover:bg-muted/20">
                  <td className="px-3 py-2.5 font-semibold text-foreground">{e.title}</td>
                  <td className="px-3 py-2.5">
                    <Badge variant="outline" className="text-[9px] font-mono">{e.concept_name}</Badge>
                  </td>
                  <td className="px-3 py-2.5 text-muted-foreground">{e.section_name || '—'}</td>
                  <td className="px-3 py-2.5 text-muted-foreground">{e.creator_name || '—'}</td>
                  <td className="px-3 py-2.5 text-center font-mono text-foreground">{e.submission_count || 0}</td>
                  <td className="px-3 py-2.5 text-center">
                    {e.closed_at ? (
                      <span className="inline-flex items-center gap-1 text-[10px] text-muted-foreground"><XCircle className="h-3 w-3" /> Closed</span>
                    ) : (
                      <span className="inline-flex items-center gap-1 text-[10px] text-emerald-500"><CheckCircle2 className="h-3 w-3" /> Open</span>
                    )}
                  </td>
                  <td className="px-3 py-2.5 text-center">
                    <Button
                      variant={e.closed_at ? 'outline' : 'secondary'}
                      size="sm"
                      className="h-7 text-[10px]"
                      onClick={() => toggleExercise(e.id, !e.closed_at)}
                    >
                      {e.closed_at ? 'Reopen' : 'Close'}
                    </Button>
                  </td>
                </tr>
              ))}
            </tbody>
          </table>
        </div>
      </Card>
    </div>
  );
}
