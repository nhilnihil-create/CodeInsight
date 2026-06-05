import { useEffect, useState } from 'react';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Badge } from '@/components/ui/badge';
import { Table, TableBody, TableCell, TableHead, TableHeader, TableRow } from '@/components/ui/table';
import { AlertOctagon } from 'lucide-react';
import { MOCK_STRUCTURE_VIOLATIONS } from '@/data/mockData';
import SectionFilter from '@/components/SectionFilter';
import api from '@/services/api';

const SEVERITY_VARIANT = {
  high: 'destructive',
  medium: 'default',
  low: 'secondary',
};

const STRUCTURAL_FLAG_TYPES = new Set(['HARDCODING', 'BLANK_TEMPLATE']);

/**
 * Structure violations — see spec §3 row 9.
 * "All Sections" preserves the design MOCK_STRUCTURE_VIOLATIONS list. When a
 * section is picked, the table is sourced from
 * /api/analytics/sections/:id/integrity-flags filtered to the structural
 * flag types (HARDCODING + BLANK_TEMPLATE) — i.e. the same data the
 * academic-integrity engine emits at submission time, scoped to the
 * chosen section.
 */
export default function InstructorViolations() {
  const [sectionId, setSectionId] = useState('all');
  const [rows, setRows] = useState(null);

  useEffect(() => {
    if (sectionId === 'all') {
      setRows(null);
      return;
    }
    let cancelled = false;
    const load = async () => {
      try {
        const res = await api.get(`/api/analytics/sections/${sectionId}/integrity-flags`, {
          params: { limit: 200 },
        });
        if (cancelled) return;
        const flags = res.data?.flags || [];
        const structural = flags.filter((f) => STRUCTURAL_FLAG_TYPES.has(f.flag_type));
        setRows(
          structural.map((f) => ({
            id: f.id,
            student: f.student_name || `Student #${f.student_id || ''}`,
            exercise: f.exercise_title || '—',
            concept: f.flag_type,
            type: f.flag_type,
            message: f.evidence || '',
            severity: (f.severity || 'low').toLowerCase(),
            time: f.created_at ? new Date(f.created_at).toLocaleString() : '',
          }))
        );
      } catch {
        if (!cancelled) setRows([]);
      }
    };
    load();
    return () => { cancelled = true; };
  }, [sectionId]);

  const data = rows === null ? MOCK_STRUCTURE_VIOLATIONS : rows;

  return (
    <div className="space-y-6">
      <div className="flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between">
        <div>
          <h1 className="text-3xl font-bold tracking-tight">Structure Violations</h1>
          <p className="text-muted-foreground">Output and structural issues detected at submission time.</p>
        </div>
        <SectionFilter value={sectionId} onChange={setSectionId} />
      </div>

      <Card>
        <CardHeader className="flex flex-row items-center gap-2">
          <AlertOctagon className="w-4 h-4 text-muted-foreground" />
          <CardTitle>Detected Violations</CardTitle>
        </CardHeader>
        <CardContent className="p-0">
          <Table>
            <TableHeader>
              <TableRow>
                <TableHead>Student</TableHead>
                <TableHead>Exercise</TableHead>
                <TableHead>Concept</TableHead>
                <TableHead>Type</TableHead>
                <TableHead>Message</TableHead>
                <TableHead>Severity</TableHead>
                <TableHead>Time</TableHead>
              </TableRow>
            </TableHeader>
            <TableBody>
              {data.length === 0 ? (
                <TableRow>
                  <TableCell colSpan={7} className="text-center text-muted-foreground py-6">
                    No violations found for this selection.
                  </TableCell>
                </TableRow>
              ) : (
                data.map((v) => (
                  <TableRow key={v.id}>
                    <TableCell className="font-medium">{v.student}</TableCell>
                    <TableCell>{v.exercise}</TableCell>
                    <TableCell><Badge variant="secondary">{v.concept}</Badge></TableCell>
                    <TableCell>{v.type}</TableCell>
                    <TableCell className="text-muted-foreground max-w-md">{v.message}</TableCell>
                    <TableCell>
                      <Badge variant={SEVERITY_VARIANT[v.severity] || 'outline'}>{v.severity}</Badge>
                    </TableCell>
                    <TableCell className="text-muted-foreground text-xs">{v.time}</TableCell>
                  </TableRow>
                ))
              )}
            </TableBody>
          </Table>
        </CardContent>
      </Card>
    </div>
  );
}
