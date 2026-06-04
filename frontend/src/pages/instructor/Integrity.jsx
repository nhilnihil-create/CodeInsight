import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Badge } from '@/components/ui/badge';
import { Table, TableBody, TableCell, TableHead, TableHeader, TableRow } from '@/components/ui/table';
import { ShieldAlert } from 'lucide-react';
import IntegrityMonitoringBanner from '@/components/analytics/IntegrityMonitoringBanner';
import IntegrityFlagDropdown from '@/components/analytics/IntegrityFlagDropdown';
import { MOCK_INTEGRITY_FLAGS } from '@/data/mockData';
import '@/components/analytics/IntegrityFlagDropdown.css';

/**
 * Academic Integrity — see spec §3 row 10.
 * Banner at the top (IntegrityMonitoringBanner), followed by a Table of
 * MOCK_INTEGRITY_FLAGS with the IntegrityFlagDropdown as the per-row
 * review action.
 */
export default function InstructorIntegrity() {
  return (
    <div className="space-y-6">
      <div>
        <h1 className="text-3xl font-bold tracking-tight">Academic Integrity</h1>
        <p className="text-muted-foreground">Behavioral and structural anomalies requiring review.</p>
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
              {MOCK_INTEGRITY_FLAGS.map((f) => (
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
              ))}
            </TableBody>
          </Table>
        </CardContent>
      </Card>
    </div>
  );
}
