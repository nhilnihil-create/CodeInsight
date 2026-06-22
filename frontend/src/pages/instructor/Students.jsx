import { useEffect, useState } from 'react';
import { Link, useNavigate } from 'react-router-dom';
import { Input } from '@/components/ui/input';
import { Badge } from '@/components/ui/badge';
import { ResponsiveTable } from '@/components/ui/responsive-table';
import { Search } from 'lucide-react';
import SectionFilter from '@/components/SectionFilter';
import useLastSection from '@/hooks/useLastSection';
import api from '@/services/api';

/**
 * Students list — see spec §3 row 3.
 *
 * Now respects the section filter (All / per-section). When a section is
 * chosen, the table is sourced from /api/sections/:id/students-with-scores;
 * "All Sections" falls back to the design MOCK_USERS rows.
 */
export default function InstructorStudents() {
  const navigate = useNavigate();
  const [search, setSearch] = useState('');
  const [sectionId, setSectionId] = useLastSection();
  const [realStudents, setRealStudents] = useState(null);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);

  useEffect(() => {
    let cancelled = false;
    const load = async () => {
      setLoading(true);
      setError(null);
      try {
        const url = `/api/sections/${sectionId}/students-with-scores`;
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
      latestCds: s.latest_cds != null ? parseFloat(s.latest_cds) : null,
      submittedCount: s.submitted_count ?? 0,
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
      <ResponsiveTable
        columns={[
          {
            key: 'name',
            header: 'Student',
            mobile: 'primary',
            renderCell: (s) => (
              <Link to={`/instructor/students/${s.id}`} className="hover:underline text-primary font-medium">
                {s.name}
              </Link>
            ),
          },
          { key: 'studentId', header: 'Student ID', mobile: 'hidden' },
          {
            key: 'cdsPct',
            header: 'Avg CDS',
            mobile: 'label',
            renderCell: (s) => {
              if (s.latestCds == null || Number.isNaN(s.latestCds)) return '—';
              return <span className="font-mono tabular-nums">{Math.round(s.latestCds * 100)}%</span>;
            },
            renderMobileCell: (s) => {
              if (s.latestCds == null || Number.isNaN(s.latestCds)) return '—';
              return <span className="font-mono font-medium">{Math.round(s.latestCds * 100)}%</span>;
            },
          },
          {
            key: 'status',
            header: 'Status',
            mobile: 'label',
            renderCell: (s) => {
              const cdsPct = s.latestCds != null && !Number.isNaN(s.latestCds) ? Math.round(s.latestCds * 100) : null;
              const unstarted = cdsPct === null || s.submittedCount === 0;
              if (unstarted) {
                return <Badge className="bg-cds-na/10 text-cds-na border border-cds-na/20">Unstarted</Badge>;
              }
              return cdsPct > 50
                ? <Badge className="bg-cds-high/10 text-cds-high border border-cds-high/15">At risk</Badge>
                : <Badge className="bg-cds-low/10 text-cds-low border border-cds-low/15">OK</Badge>;
            },
            renderMobileCell: (s) => {
              const cdsPct = s.latestCds != null && !Number.isNaN(s.latestCds) ? Math.round(s.latestCds * 100) : null;
              const unstarted = cdsPct === null || s.submittedCount === 0;
              if (unstarted) return <span className="text-cds-na">Unstarted</span>;
              return cdsPct > 50
                ? <span className="text-cds-high">At risk</span>
                : <span className="text-cds-low">OK</span>;
            },
          },
        ]}
        data={students}
        keyExtractor={(s) => String(s.id)}
        onRowClick={(s) => navigate(`/instructor/students/${s.id}`)}
        emptyMessage={
          realStudents?.length === 0
            ? 'No students enrolled in this section.'
            : 'No students found matching your search.'
        }
      />
      )}
    </div>
  );
}
