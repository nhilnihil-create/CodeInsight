import { useEffect, useState } from 'react';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Badge } from '@/components/ui/badge';
import { Table, TableBody, TableCell, TableHead, TableHeader, TableRow } from '@/components/ui/table';
import { ShieldAlert } from 'lucide-react';
import IntegrityMonitoringBanner from '@/components/analytics/IntegrityMonitoringBanner';
import IntegrityFlagDropdown from '@/components/analytics/IntegrityFlagDropdown';
import { MOCK_INTEGRITY_FLAGS } from '@/data/mockData';
import SectionFilter from '@/components/SectionFilter';
import api from '@/services/api';
import '@/components/analytics/IntegrityFlagDropdown.css';

/**
 * Academic Integrity — see spec §3 row 10.
 * Banner at the top (IntegrityMonitoringBanner), followed by a Table of
 * integrity flags. "All Sections" preserves the design MOCK_INTEGRITY_FLAGS;
 * a chosen section re-sources the table from
 * /api/analytics/sections/:id/integrity-flags (the same endpoint the
 * integrity dropdown uses server-side).
 */
export default function InstructorIntegrity() {
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
        setRows(
          flags.map((f) => ({
            id: f.id,
            student: f.student_name || `Student #${f.student_id || ''}`,
            exercise: f.exercise_title || '—',
            type: f.flag_type,
            confidence: f.severity === 'high' ? 95 : f.severity === 'medium' ? 70 : 40,
            desc: f.evidence || '',
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

  const data = rows === null ? MOCK_INTEGRITY_FLAGS : rows;

  return (
    <div className="space-y-6">
      <div className="flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between">
        <div>
          <h1 className="text-3xl font-bold tracking-tight">Academic Integrity</h1>
          <p className="text-muted-foreground">Behavioral and structural anomalies requiring review.</p>
        </div>
        <SectionFilter value={sectionId} onChange={setSectionId} />
      </div>

      <IntegrityMonitoringBanner />

      <Card>
        <CardHeader className="flex flex-row items-center gap-2">
          <ShieldAlert className="w-4 h-4 text-muted-foreground" />
          <CardTitle>Active Flags</CardTitle>
        </CardHeader>
        <CardContent className="p-0">
          <Table>
            <TableHeader>
              <TableRow>
                <TableHead>Student</TableHead>
                <TableHead>Exercise</TableHead>
                <TableHead>Type</TableHead>
                <TableHead>Confidence</TableHead>
                <TableHead>Description</TableHead>
                <TableHead>Time</TableHead>
                <TableHead />
              </TableRow>
            </TableHeader>
            <TableBody>
              {data.length === 0 ? (
                <TableRow>
                  <TableCell colSpan={7} className="text-center text-muted-foreground py-6">
                    No integrity flags for this selection.
                  </TableCell>
                </TableRow>
              ) : (
                data.map((f) => (
                  <TableRow key={f.id}>
                    <TableCell className="font-medium">{f.student}</TableCell>
                    <TableCell>{f.exercise}</TableCell>
                    <TableCell><Badge variant="destructive">{f.type}</Badge></TableCell>
                    <TableCell>{f.confidence}%</TableCell>
                    <TableCell className="text-muted-foreground max-w-md">{f.desc}</TableCell>
                    <TableCell className="text-muted-foreground text-xs">{f.time}</TableCell>
                    <TableCell>
                      <IntegrityFlagDropdown flagId={f.id} />
                    </TableCell>
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
