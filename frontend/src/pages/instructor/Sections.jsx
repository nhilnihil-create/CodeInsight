import { useState, useEffect } from 'react';
import { Link } from 'react-router-dom';
import { Plus, Users, BarChart3, AlertTriangle, CheckCircle2, Copy, ArrowRight } from 'lucide-react';
import api from '../../services/api';
import { Card, CardContent } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Input } from '@/components/ui/input';
import { Badge } from '@/components/ui/badge';
import CDSPillDelta from '@/components/CDSPillDelta';
import { cn } from '@/lib/utils';

const POLICY_COLORS = {
  code: 'text-[#22C55E] bg-[#22C55E]/10 border-[#22C55E]/30',
  request: 'text-[#FACC15] bg-[#FACC15]/10 border-[#FACC15]/30',
  closed: 'text-[#EF4444] bg-[#EF4444]/10 border-[#EF4444]/30',
};

export default function InstructorSections() {
  const [sections, setSections] = useState([]);
  const [loading, setLoading] = useState(true);
  const [showForm, setShowForm] = useState(false);
  const [formData, setFormData] = useState({ name: '', course_code: '', school_year: '', semester: 'Sem 1' });

  useEffect(() => { fetchSections(); }, []);

  const fetchSections = async () => {
    try {
      const res = await api.get('/api/sections');
      setSections(res.data || []);
    } catch (err) {
      console.error('Error fetching sections:', err);
    } finally {
      setLoading(false);
    }
  };

  const handleSubmit = async (e) => {
    e.preventDefault();
    try {
      await api.post('/api/sections', formData);
      setFormData({ name: '', course_code: '', school_year: '', semester: 'Sem 1' });
      setShowForm(false);
      await fetchSections();
    } catch (err) {
      console.error('Error creating section:', err);
    }
  };

  if (loading) return <div className="text-muted-foreground">Loading sections...</div>;

  return (
    <div className="space-y-6">
      <div className="flex items-start justify-between gap-4">
        <p className="text-sm text-muted-foreground">
          AY 2025–2026 · {sections.length} active sections
        </p>
        <Button onClick={() => setShowForm(!showForm)} size="sm">
          <Plus className="mr-1 h-3.5 w-3.5" /> New Section
        </Button>
      </div>

      {showForm && (
        <Card>
          <CardContent className="pt-6">
            <form onSubmit={handleSubmit} className="space-y-4">
              <div className="grid grid-cols-1 gap-4 sm:grid-cols-2 lg:grid-cols-4">
                <div className="space-y-1.5">
                  <label className="block text-xs font-semibold text-muted-foreground">Section Name</label>
                  <Input required value={formData.name} onChange={(e) => setFormData({ ...formData, name: e.target.value })} placeholder="e.g., CS101 - Section A" />
                </div>
                <div className="space-y-1.5">
                  <label className="block text-xs font-semibold text-muted-foreground">Course Code</label>
                  <Input required value={formData.course_code} onChange={(e) => setFormData({ ...formData, course_code: e.target.value })} placeholder="e.g., CS101" />
                </div>
                <div className="space-y-1.5">
                  <label className="block text-xs font-semibold text-muted-foreground">School Year</label>
                  <Input value={formData.school_year} onChange={(e) => setFormData({ ...formData, school_year: e.target.value })} placeholder="e.g., AY 2025-2026" />
                </div>
                <div className="space-y-1.5">
                  <label className="block text-xs font-semibold text-muted-foreground">Semester</label>
                  <select value={formData.semester} onChange={(e) => setFormData({ ...formData, semester: e.target.value })} className="flex h-10 w-full rounded-md border border-input bg-background px-3 py-2 text-sm ring-offset-background focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-ring focus-visible:ring-offset-2">
                    <option value="Sem 1">Sem 1</option>
                    <option value="Sem 2">Sem 2</option>
                    <option value="Summer">Summer</option>
                  </select>
                </div>
              </div>
              <div className="flex gap-2">
                <Button type="submit" size="sm">Create Section</Button>
                <Button type="button" variant="outline" size="sm" onClick={() => setShowForm(false)}>Cancel</Button>
              </div>
            </form>
          </CardContent>
        </Card>
      )}

      {/* Section Cards — spec §11.9A */}
      <div className="grid grid-cols-1 gap-4 sm:grid-cols-2 lg:grid-cols-3">
        {sections.map(section => {
          const avgCDS = section.avg_cds ? parseFloat(section.avg_cds) : null;
          return (
            <Card key={section.id} className="flex flex-col overflow-hidden transition-all duration-200 hover:-translate-y-0.5 hover:shadow-lg">
              <CardContent className="flex flex-1 flex-col p-4">
                {/* Header: name + term */}
                <div className="mb-2">
                  <div className="flex items-center gap-2 mb-1">
                    <h3 className="font-semibold text-sm">{section.name}</h3>
                    <span className="text-[10px] font-mono text-muted-foreground">{section.course_code}</span>
                  </div>
                  <div className="flex items-center gap-2 text-[10px] text-muted-foreground">
                    <span className="font-mono tracking-wider text-foreground/70">{section.code || '—'}</span>
                    <Badge variant="outline" className={cn('text-[9px] px-1.5 py-0', POLICY_COLORS[section.join_policy] || '')}>
                      {section.join_policy || 'code'}
                    </Badge>
                    <span>{section.school_year || 'AY 2025–2026'} · {section.semester || 'Sem 1'}</span>
                  </div>
                </div>

                {/* 3 KPIs */}
                <div className="grid grid-cols-3 gap-2 my-3 py-3 border-y border-border/50">
                  <div className="text-center">
                    <div className="font-mono text-lg font-bold text-foreground">{section.student_count || 0}</div>
                    <div className="text-[9px] uppercase tracking-wider text-muted-foreground">Students</div>
                  </div>
                  <div className="text-center">
                    <div className="font-mono text-lg font-bold text-foreground">
                      {avgCDS != null ? avgCDS.toFixed(2) : '—'}
                    </div>
                    <div className="text-[9px] uppercase tracking-wider text-muted-foreground">Avg CDS</div>
                  </div>
                  <div className="text-center">
                    <div className={cn('font-mono text-lg font-bold', section.alert_count > 0 ? 'text-destructive' : 'text-foreground')}>
                      {section.alert_count || 0}
                    </div>
                    <div className="text-[9px] uppercase tracking-wider text-muted-foreground">At Risk</div>
                  </div>
                </div>

                {/* Top-line insight */}
                <p className="text-[10px] text-muted-foreground mb-3 line-clamp-2">
                  {section.topInsight || `${section.exercise_count || 0} exercises assigned`}
                </p>

                {/* 3 action buttons */}
                <div className="mt-auto flex gap-2">
                  <Button asChild variant="default" size="sm" className="flex-1 h-7 text-[10px]">
                    <Link to={`/instructor/sections/${section.id}`}>Open hub</Link>
                  </Button>
                  <Button asChild variant="outline" size="sm" className="h-7 text-[10px]">
                    <Link to={`/instructor/sections/${section.id}?tab=roster`}>Roster</Link>
                  </Button>
                  <Button asChild variant="ghost" size="sm" className="h-7 text-[10px] w-7 p-0">
                    <Link to={`/instructor/sections/${section.id}?tab=codes`}><Copy className="h-3 w-3" /></Link>
                  </Button>
                </div>
              </CardContent>
            </Card>
          );
        })}

        {/* New Section Card */}
        <button
          onClick={() => setShowForm(!showForm)}
          className="group flex min-h-[240px] flex-col items-center justify-center gap-2.5 rounded-xl border-2 border-dashed border-border bg-transparent p-5 transition-colors hover:border-primary/50 hover:bg-primary/5"
        >
          <div className="flex h-10 w-10 items-center justify-center rounded-full border-2 border-dashed border-muted-foreground text-xl text-muted-foreground transition-colors group-hover:border-primary group-hover:text-primary">
            +
          </div>
          <div className="text-xs font-semibold text-muted-foreground transition-colors group-hover:text-primary">
            Create New Section
          </div>
        </button>
      </div>
    </div>
  );
}
