import { useState, useEffect, useCallback } from 'react';
import { Link } from 'react-router-dom';
import { Search, Plus, CheckCircle2, XCircle } from 'lucide-react';
import api from '../../services/api';
import { ResponsiveTable } from '@/components/ui/responsive-table';
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

      {loading ? (
        <div className="py-16 text-center text-muted-foreground text-sm">
          <div className="animate-spin h-5 w-5 border-2 border-muted-foreground/30 border-t-muted-foreground rounded-full mx-auto mb-3" />
          Loading exercises…
        </div>
      ) : (
        <ResponsiveTable
          columns={[
            { key: 'title', header: 'Title', mobile: 'primary',
              renderCell: (e) => <span className="font-semibold text-foreground">{e.title}</span>,
            },
            { key: 'concept', header: 'Concept', mobile: 'label',
              renderCell: (e) => <Badge variant="outline" className="text-[9px] font-mono">{e.concept_name}</Badge>,
            },
            { key: 'section', header: 'Section', mobile: 'hidden',
              renderCell: (e) => <span className="text-muted-foreground">{e.section_name || '—'}</span>,
            },
            { key: 'creator', header: 'Creator', mobile: 'hidden',
              renderCell: (e) => <span className="text-muted-foreground">{e.creator_name || '—'}</span>,
            },
            { key: 'submissions', header: 'Submissions', mobile: 'hidden',
              renderCell: (e) => <span className="font-mono text-foreground text-center block">{e.submission_count || 0}</span>,
            },
            { key: 'status', header: 'Status', mobile: 'label',
              renderCell: (e) => (
                <div className="text-center">
                  {e.closed_at ? (
                    <span className="inline-flex items-center gap-1 text-[10px] text-muted-foreground"><XCircle className="h-3 w-3" /> Closed</span>
                  ) : (
                    <span className="inline-flex items-center gap-1 text-[10px] text-emerald-500"><CheckCircle2 className="h-3 w-3" /> Open</span>
                  )}
                </div>
              ),
            },
            { key: 'actions', header: 'Actions', mobile: 'actions',
              renderCell: (e) => (
                <div className="text-center">
                  <Button
                    variant={e.closed_at ? 'outline' : 'secondary'}
                    size="sm"
                    className="h-7 text-[10px]"
                    onClick={() => toggleExercise(e.id, !e.closed_at)}
                  >
                    {e.closed_at ? 'Reopen' : 'Close'}
                  </Button>
                </div>
              ),
              renderMobileCell: (e) => (
                <div className="w-full">
                  <Button
                    variant={e.closed_at ? 'outline' : 'secondary'}
                    size="sm"
                    className="w-full text-xs"
                    onClick={(el) => { el.stopPropagation(); toggleExercise(e.id, !e.closed_at); }}
                  >
                    {e.closed_at ? 'Reopen' : 'Close'}
                  </Button>
                </div>
              ),
            },
          ]}
          data={filtered}
          keyExtractor={(e) => String(e.id)}
          emptyMessage="No exercises found."
        />
      )}
    </div>
  );
}
