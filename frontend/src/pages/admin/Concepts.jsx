import { useState, useEffect } from 'react';
import { Plus, Edit3, Code, Trash2 } from 'lucide-react';
import api from '../../services/api';
import { Card, CardContent } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Badge } from '@/components/ui/badge';
import {
  Dialog, DialogContent, DialogHeader, DialogTitle, DialogFooter, DialogTrigger,
} from '@/components/ui/dialog';
import { Input } from '@/components/ui/input';
import { Label } from '@/components/ui/label';
import { cn } from '@/lib/utils';

const CONCEPT_COLORS = {
  Datatypes: 'text-blue-500 bg-blue-500/10 border-blue-500/30',
  Variables: 'text-emerald-500 bg-emerald-500/10 border-emerald-500/30',
  Conditionals: 'text-amber-500 bg-amber-500/10 border-amber-500/30',
  Loops: 'text-purple-500 bg-purple-500/10 border-purple-500/30',
  Functions: 'text-rose-500 bg-rose-500/10 border-rose-500/30',
  Arrays: 'text-cyan-500 bg-cyan-500/10 border-cyan-500/30',
  OOP: 'text-orange-500 bg-orange-500/10 border-orange-500/30',
};

export default function AdminConcepts() {
  const [concepts, setConcepts] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [open, setOpen] = useState(false);
  const [name, setName] = useState('');
  const [astNodes, setAstNodes] = useState('');
  const [busy, setBusy] = useState(false);

  const load = async () => {
    setLoading(true);
    setError(null);
    try {
      const res = await api.get('/api/admin/concepts');
      setConcepts(res.data.concepts || []);
    } catch (err) {
      setError(err.response?.data?.message || err.message);
    } finally {
      setLoading(false);
    }
  };

  useEffect(() => { load(); }, []);

  const handleCreate = async (e) => {
    e.preventDefault();
    setBusy(true);
    try {
      const ast_nodes = astNodes.split(',').map(s => s.trim()).filter(Boolean);
      await api.post('/api/admin/concepts', { name, ast_nodes });
      setName(''); setAstNodes(''); setOpen(false);
      await load();
    } catch (err) {
      setError(err.response?.data?.message || err.message);
    } finally {
      setBusy(false);
    }
  };

  const handleDelete = async (c) => {
    if (!window.confirm(`Delete concept "${c.name}"?`)) return;
    try {
      await api.delete(`/api/admin/concepts/${c.id}`);
      await load();
    } catch (err) {
      setError(err.response?.data?.message || err.message);
    }
  };

  return (
    <div className="space-y-4">
      <div className="flex items-center justify-between">
        <p className="text-sm text-muted-foreground">{concepts.length} concepts · {concepts.reduce((s, c) => s + (c.exercise_count || 0), 0)} total exercises</p>
        <Dialog open={open} onOpenChange={setOpen}>
          <DialogTrigger asChild>
            <Button size="sm"><Plus className="mr-1 h-3.5 w-3.5" /> Add Concept</Button>
          </DialogTrigger>
          <DialogContent>
            <DialogHeader><DialogTitle>Add concept</DialogTitle></DialogHeader>
            <form onSubmit={handleCreate} className="space-y-3">
              <div className="space-y-1">
                <Label>Name</Label>
                <Input value={name} onChange={e => setName(e.target.value)} required />
              </div>
              <div className="space-y-1">
                <Label>AST nodes (comma separated)</Label>
                <Input value={astNodes} onChange={e => setAstNodes(e.target.value)} placeholder="if_statement, switch_statement" />
              </div>
              {error && <p className="text-xs text-destructive">{error}</p>}
              <DialogFooter>
                <Button type="button" variant="outline" onClick={() => setOpen(false)}>Cancel</Button>
                <Button type="submit" disabled={busy}>{busy ? 'Saving…' : 'Create'}</Button>
              </DialogFooter>
            </form>
          </DialogContent>
        </Dialog>
      </div>

      {error && <p className="text-xs text-destructive">Failed to load: {error}</p>}

      <div className="grid grid-cols-1 gap-3 sm:grid-cols-2 lg:grid-cols-3">
        {loading ? (
          <p className="text-muted-foreground col-span-full text-center py-6">Loading concepts…</p>
        ) : concepts.length === 0 ? (
          <p className="text-muted-foreground col-span-full text-center py-6">No concepts yet.</p>
        ) : concepts.map(c => (
          <Card key={c.id} className="transition-all hover:-translate-y-0.5 hover:shadow-md">
            <CardContent className="p-4">
              <div className="flex items-start justify-between mb-2">
                <Badge variant="outline" className={cn('text-[10px] font-mono', CONCEPT_COLORS[c.name])}>
                  {c.name}
                </Badge>
                <div className="inline-flex gap-1">
                  <Button variant="ghost" size="sm" className="h-6 w-6 p-0"><Edit3 className="h-3 w-3" /></Button>
                  <Button variant="ghost" size="sm" className="h-6 w-6 p-0 text-destructive" onClick={() => handleDelete(c)}><Trash2 className="h-3 w-3" /></Button>
                </div>
              </div>
              <div className="space-y-1.5">
                <div className="flex items-center justify-between text-[10px]">
                  <span className="text-muted-foreground">Exercises</span>
                  <span className="font-mono font-bold text-foreground">{c.exercise_count || 0}</span>
                </div>
                {c.ast_nodes?.length > 0 && (
                  <div className="flex items-center gap-1 text-[10px] text-muted-foreground">
                    <Code className="h-3 w-3" />
                    <span>{c.ast_nodes.length} AST nodes</span>
                  </div>
                )}
              </div>
            </CardContent>
          </Card>
        ))}
      </div>
    </div>
  );
}
