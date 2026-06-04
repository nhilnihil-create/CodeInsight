import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Badge } from '@/components/ui/badge';
import { Table, TableBody, TableCell, TableHead, TableHeader, TableRow } from '@/components/ui/table';
import { AlertOctagon } from 'lucide-react';
import { MOCK_STRUCTURE_VIOLATIONS } from '@/data/mockData';

const SEVERITY_VARIANT = {
  high: 'destructive',
  medium: 'default',
  low: 'secondary',
};

/**
 * Structure violations — see spec §3 row 9.
 * Renders MOCK_STRUCTURE_VIOLATIONS as a Table; severity is a colored Badge.
 */
export default function InstructorViolations() {
  return (
    <div className="space-y-6">
      <div>
        <h1 className="text-3xl font-bold tracking-tight">Structure Violations</h1>
        <p className="text-muted-foreground">Output and structural issues detected at submission time.</p>
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
              {MOCK_STRUCTURE_VIOLATIONS.map((v) => (
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
              ))}
            </TableBody>
          </Table>
        </CardContent>
      </Card>
    </div>
  );
}
