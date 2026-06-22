import { useState, useEffect } from 'react';
import { Link } from 'react-router-dom';
import { Download, Upload, Edit3, Trash2 } from 'lucide-react';
import api from '../../services/api';
import { ResponsiveTable } from '@/components/ui/responsive-table';
import { Button } from '@/components/ui/button';
import { Badge } from '@/components/ui/badge';
import {
  Dialog, DialogContent, DialogHeader, DialogTitle, DialogFooter, DialogTrigger,
} from '@/components/ui/dialog';
import { Input } from '@/components/ui/input';
import { Textarea } from '@/components/ui/textarea';
import { Label } from '@/components/ui/label';
import { Select, SelectContent, SelectItem, SelectTrigger, SelectValue } from '@/components/ui/select';
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
  const [editTarget, setEditTarget] = useState(null);
  const [editName, setEditName] = useState('');
  const [editCode, setEditCode] = useState('');
  const [editYear, setEditYear] = useState('');
  const [editTerm, setEditTerm] = useState('');
  const [editPolicy, setEditPolicy] = useState('code');
  const [editMaxSize, setEditMaxSize] = useState('60');

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

  const handleDeleteSection = async (sec) => {
    if (!window.confirm(`Delete section "${sec.name}"?`)) return;
    try {
      await api.delete(`/api/admin/sections/${sec.id}`);
      await load();
    } catch (err) {
      setError(err.response?.data?.message || err.message);
    }
  };

  const handleSectionUpdate = async (e) => {
    e.preventDefault();
    setBusy(true);
    try {
      await api.put(`/api/admin/sections/${editTarget.id}`, {
        name: editName,
        course_code: editCode,
        school_year: editYear,
        term: editTerm,
        join_policy: editPolicy,
        max_size: editMaxSize,
      });
      setEditTarget(null);
      await load();
    } catch (err) {
      setError(err.response?.data?.message || err.message);
    } finally {
      setBusy(false);
    }
  };

  useEffect(() => {
    if (editTarget) {
      setEditName(editTarget.name || '');
      setEditCode(editTarget.course_code || '');
      setEditYear(editTarget.school_year || '');
      setEditTerm(editTarget.term || '');
      setEditPolicy(editTarget.join_policy || 'code');
      setEditMaxSize(String(editTarget.max_size ?? '60'));
    }
  }, [editTarget]);

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

      {loading ? (
        <div className="py-16 text-center text-muted-foreground text-sm">
          <div className="animate-spin h-5 w-5 border-2 border-muted-foreground/30 border-t-muted-foreground rounded-full mx-auto mb-3" />
          Loading sections…
        </div>
      ) : (
        <ResponsiveTable
          columns={[
            { key: 'name', header: 'Section', mobile: 'primary',
              renderCell: (sec) => (
                <div>
                  <Link to={`/instructor/sections/${sec.id}`} className="font-semibold text-foreground hover:text-primary">{sec.name}</Link>
                  <div className="text-[9px] text-muted-foreground">{[sec.school_year, sec.term].filter(Boolean).join(' · ') || '—'}</div>
                </div>
              ),
            },
            { key: 'course_code', header: 'Course', mobile: 'hidden',
              renderCell: (sec) => <span className="font-mono text-muted-foreground">{sec.course_code}</span>,
            },
            { key: 'instructor', header: 'Instructor', mobile: 'label',
              renderCell: (sec) => <span className="text-muted-foreground">{sec.instructor_name || '—'}</span>,
            },
            { key: 'student_count', header: 'Students', mobile: 'label',
              renderCell: (sec) => <span className="font-mono font-bold text-foreground text-center block">{sec.student_count || 0}</span>,
            },
            { key: 'exercises', header: 'Exercises', mobile: 'hidden',
              renderCell: (sec) => <span className="font-mono text-muted-foreground text-center block">{sec.exercise_count || 0}</span>,
            },
            { key: 'policy', header: 'Policy', mobile: 'hidden',
              renderCell: (sec) => (
                <div className="text-center">
                  <Badge variant="outline" className={cn('text-[9px] px-1.5 py-0', POLICY_COLORS[sec.join_policy] || '')}>
                    {sec.join_policy || 'code'}
                  </Badge>
                </div>
              ),
            },
            { key: 'actions', header: 'Actions', mobile: 'actions',
              renderCell: (sec) => (
                <div className="inline-flex gap-1 justify-center w-full">
                  <Button variant="ghost" size="sm" className="h-6 w-6 p-0" onClick={(e) => { e.stopPropagation(); setEditTarget(sec); }}><Edit3 className="h-3 w-3" /></Button>
                  <Button variant="ghost" size="sm" className="h-6 w-6 p-0 text-destructive" onClick={(e) => { e.stopPropagation(); handleDeleteSection(sec); }}><Trash2 className="h-3 w-3" /></Button>
                </div>
              ),
              renderMobileCell: (sec) => (
                <div className="flex gap-2 w-full">
                  <Button variant="outline" size="sm" className="flex-1 text-xs" onClick={(e) => { e.stopPropagation(); setEditTarget(sec); }}>Edit</Button>
                  <Button variant="ghost" size="sm" className="flex-1 text-xs text-destructive" onClick={(e) => { e.stopPropagation(); handleDeleteSection(sec); }}>Delete</Button>
                </div>
              ),
            },
          ]}
          data={sections}
          keyExtractor={(sec) => String(sec.id)}
          emptyMessage="No sections yet."
        />
      )}

      <Dialog open={!!editTarget} onOpenChange={open => !open && setEditTarget(null)}>
        <DialogContent>
          <DialogHeader><DialogTitle>Edit section</DialogTitle></DialogHeader>
          <form onSubmit={handleSectionUpdate} className="space-y-3">
            <div className="space-y-1">
              <Label>Name</Label>
              <Input value={editName} onChange={e => setEditName(e.target.value)} required />
            </div>
            <div className="space-y-1">
              <Label>Course Code</Label>
              <Input value={editCode} onChange={e => setEditCode(e.target.value)} required />
            </div>
            <div className="space-y-1">
              <Label>School Year</Label>
              <Input value={editYear} onChange={e => setEditYear(e.target.value)} />
            </div>
            <div className="space-y-1">
              <Label>Term</Label>
              <Input value={editTerm} onChange={e => setEditTerm(e.target.value)} />
            </div>
            <div className="space-y-1">
              <Label>Join Policy</Label>
              <Select value={editPolicy} onValueChange={setEditPolicy}>
                <SelectTrigger><SelectValue /></SelectTrigger>
                <SelectContent>
                  <SelectItem value="code">Code</SelectItem>
                  <SelectItem value="request">Request</SelectItem>
                  <SelectItem value="closed">Closed</SelectItem>
                </SelectContent>
              </Select>
            </div>
            <div className="space-y-1">
              <Label>Max Size</Label>
              <Input type="number" value={editMaxSize} onChange={e => setEditMaxSize(e.target.value)} />
            </div>
            {error && <p className="text-xs text-destructive">{error}</p>}
            <DialogFooter>
              <Button type="button" variant="outline" onClick={() => setEditTarget(null)}>Cancel</Button>
              <Button type="submit" disabled={busy}>{busy ? 'Saving…' : 'Save'}</Button>
            </DialogFooter>
          </form>
        </DialogContent>
      </Dialog>
    </div>
  );
}
