import { useEffect, useState } from 'react';
import { Link } from 'react-router-dom';
import { Card, CardContent } from '@/components/ui/card';
import { Input } from '@/components/ui/input';
import { Badge } from '@/components/ui/badge';
import { Table, TableBody, TableCell, TableHead, TableHeader, TableRow } from '@/components/ui/table';
import { Search } from 'lucide-react';
import SectionFilter from '@/components/SectionFilter';
import api from '@/services/api';

/**
 * Students list — see spec §3 row 3.
 *
 * Now respects the section filter (All / per-section). When a section is
 * chosen, the table is sourced from /api/sections/:id/students-with-scores;
 * "All Sections" falls back to the design MOCK_USERS rows.
 */
export default function InstructorStudents() {
  const [search, setSearch] = useState('');
  const [sectionId, setSectionId] = useState('all');
  const [realStudents, setRealStudents] = useState(null);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);

  useEffect(() => {
    let cancelled = false;
    const load = async () => {
      setLoading(true);
      setError(null);
      try {
        const url = sectionId === 'all'
          ? '/api/sections/students-all'
          : `/api/sections/${sectionId}/students-with-scores`;
        const res = await api.get(url);
        if (!cancelled) setRealStudents(Array.isArray(res.data) ? res.data : []);
      } catch (err) {
        if (!cancelled) {
          setRealStudents([]);
          setError(err.response?.data?.message || 'Failed to load students.');
        }
      } finally {
        if (!cancelled) setLoading(false);
      }
    };
    load();
    return () => { cancelled = true; };
  }, [sectionId]);

  const students = (realStudents || [])
    .map((s) => ({
      id: s.id,
      name: s.name,
      studentId: s.studentId || s.student_id || String(s.id),
      email: s.email || '',
      latestCds: s.latest_cds != null ? parseFloat(s.latest_cds) : null,
      submittedCount: s.submitted_count ?? 0,
      totalExercises: s.total_exercises ?? 0,
      flagCount: s.integrity_flag_count ?? 0,
      strongestConcept: s.strongest_concept || null,
    }))
    .filter((u) => {
      if (!search) return true;
      const q = search.toLowerCase();
      return u.name.toLowerCase().includes(q) || u.studentId.toLowerCase().includes(q);
    });

  return (
    <div className="space-y-6">
      <div className="flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between">
        <div>
          <h1 className="text-3xl font-bold tracking-tight">Students</h1>
          <p className="text-muted-foreground">Manage and monitor student progress.</p>
        </div>
        <div className="flex flex-col gap-2 sm:flex-row sm:items-center">
          <SectionFilter value={sectionId} onChange={setSectionId} />
          <div className="relative w-full sm:w-72">
            <Search className="absolute left-2.5 top-2.5 h-4 w-4 text-muted-foreground" />
            <Input
              type="search"
              placeholder="Search by name or ID..."
              className="pl-8"
              value={search}
              onChange={(e) => setSearch(e.target.value)}
            />
          </div>
        </div>
      </div>

      {loading ? (
        <div className="py-16 text-center text-muted-foreground text-sm">
          <div className="animate-spin h-5 w-5 border-2 border-muted-foreground/30 border-t-muted-foreground rounded-full mx-auto mb-3" />
          Loading students…
        </div>
      ) : error ? (
        <div className="py-16 text-center">
          <p className="text-sm text-destructive font-medium">{error}</p>
          <p className="text-xs text-muted-foreground mt-1">Try selecting a different section or refreshing.</p>
        </div>
      ) : (
      <Card>
        <CardContent className="p-0">
          <Table>
            <TableHeader>
              <TableRow>
                <TableHead>Student</TableHead>
                <TableHead>Student ID</TableHead>
                <TableHead>Avg CDS</TableHead>
                <TableHead>Strongest Concept</TableHead>
                <TableHead>Flags</TableHead>
                <TableHead>Status</TableHead>
              </TableRow>
            </TableHeader>
            <TableBody>
              {students.length === 0 ? (
                <TableRow>
                  <TableCell colSpan={6} className="text-center text-muted-foreground py-6">
                    {realStudents?.length === 0
                      ? 'No students enrolled in this section.'
                      : 'No students found matching your search.'}
                  </TableCell>
                </TableRow>
              ) : (
                students.map((s) => {
                  const cdsPct = s.latestCds != null && !Number.isNaN(s.latestCds) ? Math.round(s.latestCds * 100) : null;
                  const unstarted = cdsPct === null || s.submittedCount === 0;

                  return (
                    <TableRow key={s.id}>
                      <TableCell className="font-medium">
                        <Link to={`/instructor/students/${s.id}`} className="hover:underline text-primary">
                          {s.name}
                        </Link>
                      </TableCell>
                      <TableCell className="text-muted-foreground">{s.studentId}</TableCell>
                      <TableCell className="font-mono tabular-nums">
                        {cdsPct != null ? `${cdsPct}%` : '—'}
                      </TableCell>
                      <TableCell className="text-muted-foreground">
                        {s.strongestConcept || '—'}
                      </TableCell>
                      <TableCell className="text-muted-foreground">
                        {s.flagCount > 0 ? `${s.flagCount} flag${s.flagCount === 1 ? '' : 's'}` : '—'}
                      </TableCell>
                      <TableCell>
                        {unstarted ? (
                          <Badge className="bg-cds-na/10 text-cds-na border border-cds-na/20">Unstarted</Badge>
                        ) : cdsPct > 50 ? (
                          <Badge className="bg-cds-high/10 text-cds-high border border-cds-high/15">At risk</Badge>
                        ) : (
                          <Badge className="bg-cds-low/10 text-cds-low border border-cds-low/15">OK</Badge>
                        )}
                      </TableCell>
                    </TableRow>
                  );
                })
              )}
            </TableBody>
          </Table>
        </CardContent>
      </Card>
      )}
    </div>
  );
}
