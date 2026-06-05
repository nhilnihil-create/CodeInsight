import { useState, useEffect } from 'react';
import { Plus, Edit3, Code } from 'lucide-react';
import api from '../../services/api';
import { Card, CardContent } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Badge } from '@/components/ui/badge';
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

  useEffect(() => {
    const load = async () => {
      try {
        const res = await api.get('/api/admin/concepts').catch(() => null);
        setConcepts(res?.data || [
          { id: 1, name: 'Datatypes', ast_nodes: [], exercise_count: 3 },
          { id: 2, name: 'Variables', ast_nodes: [], exercise_count: 3 },
          { id: 3, name: 'Conditionals', ast_nodes: ['if_statement', 'switch_statement'], exercise_count: 4 },
          { id: 4, name: 'Loops', ast_nodes: ['for_statement', 'while_statement', 'do_statement'], exercise_count: 4 },
          { id: 5, name: 'Functions', ast_nodes: ['function_definition'], exercise_count: 4 },
          { id: 6, name: 'Arrays', ast_nodes: ['array_declarator', 'subscript_expression'], exercise_count: 3 },
          { id: 7, name: 'OOP', ast_nodes: ['class_specifier'], exercise_count: 3 },
        ]);
      } catch (err) {
        console.error(err);
      } finally {
        setLoading(false);
      }
    };
    load();
  }, []);

  if (loading) return <div className="text-muted-foreground">Loading concepts...</div>;

  return (
    <div className="space-y-4">
      <div className="flex items-center justify-between">
        <p className="text-sm text-muted-foreground">{concepts.length} concepts · {concepts.reduce((s, c) => s + (c.exercise_count || 0), 0)} total exercises</p>
        <Button size="sm"><Plus className="mr-1 h-3.5 w-3.5" /> Add Concept</Button>
      </div>
      <div className="grid grid-cols-1 gap-3 sm:grid-cols-2 lg:grid-cols-3">
        {concepts.map(c => (
          <Card key={c.id} className="transition-all hover:-translate-y-0.5 hover:shadow-md">
            <CardContent className="p-4">
              <div className="flex items-start justify-between mb-2">
                <Badge variant="outline" className={cn('text-[10px] font-mono', CONCEPT_COLORS[c.name])}>
                  {c.name}
                </Badge>
                <Button variant="ghost" size="sm" className="h-6 w-6 p-0"><Edit3 className="h-3 w-3" /></Button>
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
