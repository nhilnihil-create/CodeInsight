import { useState, useEffect } from 'react';
import { Link } from 'react-router-dom';
import { Download, Upload } from 'lucide-react';
import api from '../../services/api';
import { Card } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Badge } from '@/components/ui/badge';
import {
  Dialog, DialogContent, DialogHeader, DialogTitle, DialogFooter, DialogTrigger,
} from '@/components/ui/dialog';
import { Textarea } from '@/components/ui/textarea';
import { cn } from '@/lib/utils';

const POLICY_COLORS = {
  code: 'text-[#22C55E] bg-[#22C55E]/10 border-[#22C55E]/30',
  request: 'text-[#FACC15] bg-[#FACC15]/10 border-[#FACC15]/30',
  closed: 'text-[#EF4444] bg-[#EF4444]/10 border-[#EF4444]/30',
};

export default function AdminSections() {
  const [sections, setSections] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [bulkOpen, setBulkOpen] = useState(false);
  const [csvText, setCsvText] = useState('email,name\n');
  const [bulkResult, setBulkResult] = useState(null);
  const [busy, setBusy] = useState(false);

  const load = async () => {
    setLoading(true);
    setError(null);
    try {
      const res = await api.get('/api/admin/sections');
      setSections(res.data.sections || []);
    } catch (err) {
      setError(err.response?.data?.message || err.message);
    } finally {
      setLoading(false);
    }
  };

  useEffect(() => { load(); }, []);

  const handleExport = () => {
    const header = 'id,name,course_code,instructor_email,student_count,exercise_count,join_policy\n';
    const rows = sections.map(s =>
      [s.id, JSON.stringify(s.name), s.course_code, s.instructor_email, s.student_count, s.exercise_count, s.join_policy].join(',')
    ).join('\n');
    const blob = new Blob([header + rows], { type: 'text/csv' });
    const url = URL.createObjectURL(blob);
    const a = document.createElement('a');
    a.href = url; a.download = 'sections.csv'; a.click();
    URL.revokeObjectURL(url);
  };

  const handleBulkImport = async () => {
    setBusy(true); setBulkResult(null);
    try {
      const lines = csvText.split(/\r?\n/).filter(l => l.trim() && !l.toLowerCase().startsWith('email'));
      const rows = lines.map(l => {
        const [email, name] = l.split(',').map(s => s.trim());
        return { email, name: name || undefined };
      });
      // Find first instructor section to import into (admin bulk = first section)
      const target = sections[0];
      if (!target) throw new Error('No sections available to import into');
      const res = await api.post(`/api/sections/${target.id}/enroll`, { emails: rows.map(r => r.email) });
      setBulkResult({ ok: rows.length, ...res.data });
      setCsvText('email,name\n');
      await load();
    } catch (err) {
      setBulkResult({ error: err.response?.data?.message || err.message });
    } finally {
      setBusy(false);
    }
  };

  return (
    <div className="space-y-4">
      <div className="flex items-center justify-between flex-wrap gap-2">
        <p className="text-sm text-muted-foreground">{sections.length} sections · {sections.reduce((s, sec) => s + (sec.student_count || 0), 0)} total students</p>
        <div className="flex gap-2">
          <Button variant="outline" size="sm" onClick={handleExport}><Download className="mr-1 h-3.5 w-3.5" /> Export CSV</Button>
          <Dialog open={bulkOpen} onOpenChange={setBulkOpen}>
            <DialogTrigger asChild>
              <Button size="sm"><Upload className="mr-1 h-3.5 w-3.5" /> Bulk Import</Button>
            </DialogTrigger>
            <DialogContent>
              <DialogHeader><DialogTitle>Bulk Import Students</DialogTitle></DialogHeader>
              <p className="text-xs text-muted-foreground">
                Paste CSV rows: <code className="font-mono">email,name</code>. The first section in the list will be the destination.
              </p>
              <Textarea rows={8} value={csvText} onChange={e => setCsvText(e.target.value)} className="font-mono text-xs" />
              {bulkResult?.error && <p className="text-xs text-destructive">{bulkResult.error}</p>}
              {bulkResult && !bulkResult.error && <p className="text-xs text-emerald-600">Imported {bulkResult.ok} students.</p>}
              <DialogFooter>
                <Button variant="outline" onClick={() => setBulkOpen(false)}>Close</Button>
                <Button onClick={handleBulkImport} disabled={busy}>{busy ? 'Importing…' : 'Import'}</Button>
              </DialogFooter>
            </DialogContent>
          </Dialog>
        </div>
      </div>

      {error && <p className="text-xs text-destructive">Failed to load: {error}</p>}

      <Card>
        <div className="overflow-x-auto">
          <table className="w-full border-collapse text-xs">
            <thead className="bg-muted/30">
              <tr>
                <th className="border-b border-border px-3 py-2.5 text-left text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Section</th>
                <th className="border-b border-border px-3 py-2.5 text-left text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Course</th>
                <th className="border-b border-border px-3 py-2.5 text-left text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Instructor</th>
                <th className="border-b border-border px-3 py-2.5 text-center text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Students</th>
                <th className="border-b border-border px-3 py-2.5 text-center text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Exercises</th>
                <th className="border-b border-border px-3 py-2.5 text-center text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Policy</th>
              </tr>
            </thead>
            <tbody>
              {loading ? (
                <tr><td colSpan="6" className="px-3 py-6 text-center text-muted-foreground">Loading sections…</td></tr>
              ) : sections.length === 0 ? (
                <tr><td colSpan="6" className="px-3 py-6 text-center text-muted-foreground">No sections yet.</td></tr>
              ) : sections.map(sec => (
                <tr key={sec.id} className="border-b border-border/60 last:border-0 hover:bg-muted/20">
                  <td className="px-3 py-2.5">
                    <Link to={`/instructor/sections/${sec.id}`} className="font-semibold text-foreground hover:text-primary">{sec.name}</Link>
                    <div className="text-[9px] text-muted-foreground">{[sec.school_year, sec.term].filter(Boolean).join(' · ') || '—'}</div>
                  </td>
                  <td className="px-3 py-2.5 font-mono text-muted-foreground">{sec.course_code}</td>
                  <td className="px-3 py-2.5 text-muted-foreground">{sec.instructor_name || '—'}</td>
                  <td className="px-3 py-2.5 text-center font-mono font-bold text-foreground">{sec.student_count || 0}</td>
                  <td className="px-3 py-2.5 text-center font-mono text-muted-foreground">{sec.exercise_count || 0}</td>
                  <td className="px-3 py-2.5 text-center">
                    <Badge variant="outline" className={cn('text-[9px] px-1.5 py-0', POLICY_COLORS[sec.join_policy] || '')}>
                      {sec.join_policy || 'code'}
                    </Badge>
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
