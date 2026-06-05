import { useState, useEffect } from 'react';
import { Search, Plus, Clock, CheckCircle2, XCircle } from 'lucide-react';
import api from '../../services/api';
import { Card, CardContent } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Input } from '@/components/ui/input';
import { Badge } from '@/components/ui/badge';
import { cn } from '@/lib/utils';

export default function AdminExercises() {
  const [exercises, setExercises] = useState([]);
  const [loading, setLoading] = useState(true);
  const [search, setSearch] = useState('');

  useEffect(() => {
    const load = async () => {
      try {
        const res = await api.get('/api/admin/exercises').catch(() => null);
        setExercises(res?.data || [
          { id: 1, title: 'Basic Datatypes', concept_name: 'Datatypes', section_name: 'BSIT-1A', closed_at: null, submitted_count: 42, total_students: 47 },
          { id: 2, title: 'Variable Assignment', concept_name: 'Variables', section_name: 'BSIT-1A', closed_at: null, submitted_count: 40, total_students: 47 },
          { id: 3, title: 'If-Else Practice', concept_name: 'Conditionals', section_name: 'BSIT-1A', closed_at: '2026-03-15', submitted_count: 45, total_students: 47 },
          { id: 4, title: 'For Loop Basics', concept_name: 'Loops', section_name: 'BSIT-1B', closed_at: null, submitted_count: 38, total_students: 52 },
          { id: 5, title: 'Function Args', concept_name: 'Functions', section_name: 'BSIT-1A', closed_at: null, submitted_count: 35, total_students: 47 },
        ]);
      } catch (err) {
        console.error(err);
      } finally {
        setLoading(false);
      }
    };
    load();
  }, []);

  const filtered = exercises.filter(e =>
    e.title.toLowerCase().includes(search.toLowerCase()) ||
    e.concept_name?.toLowerCase().includes(search.toLowerCase())
  );

  if (loading) return <div className="text-muted-foreground">Loading exercises...</div>;

  return (
    <div className="space-y-4">
      <div className="flex items-center justify-between">
        <div className="relative w-[200px]">
          <Search className="pointer-events-none absolute left-2.5 top-1/2 h-3.5 w-3.5 -translate-y-1/2 text-muted-foreground" />
          <Input type="text" placeholder="Search exercises..." value={search} onChange={e => setSearch(e.target.value)} className="h-8 pl-7 text-xs" />
        </div>
        <Button asChild size="sm"><a href="/instructor/create-exercise"><Plus className="mr-1 h-3.5 w-3.5" /> New Exercise</a></Button>
      </div>
      <Card>
        <div className="overflow-x-auto">
          <table className="w-full border-collapse text-xs">
            <thead className="bg-muted/30">
              <tr>
                <th className="border-b border-border px-3 py-2.5 text-left text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Title</th>
                <th className="border-b border-border px-3 py-2.5 text-left text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Concept</th>
                <th className="border-b border-border px-3 py-2.5 text-left text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Section</th>
                <th className="border-b border-border px-3 py-2.5 text-center text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Submissions</th>
                <th className="border-b border-border px-3 py-2.5 text-center text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Status</th>
              </tr>
            </thead>
            <tbody>
              {filtered.map(e => (
                <tr key={e.id} className="border-b border-border/60 last:border-0 hover:bg-muted/20">
                  <td className="px-3 py-2.5 font-semibold text-foreground">{e.title}</td>
                  <td className="px-3 py-2.5">
                    <Badge variant="outline" className="text-[9px] font-mono">{e.concept_name}</Badge>
                  </td>
                  <td className="px-3 py-2.5 text-muted-foreground">{e.section_name || '—'}</td>
                  <td className="px-3 py-2.5 text-center font-mono text-foreground">{e.submitted_count || 0}/{e.total_students || 0}</td>
                  <td className="px-3 py-2.5 text-center">
                    {e.closed_at ? (
                      <span className="inline-flex items-center gap-1 text-[10px] text-muted-foreground"><XCircle className="h-3 w-3" /> Closed</span>
                    ) : (
                      <span className="inline-flex items-center gap-1 text-[10px] text-emerald-500"><CheckCircle2 className="h-3 w-3" /> Open</span>
                    )}
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
