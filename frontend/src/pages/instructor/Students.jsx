import { useState } from 'react';
import { Link } from 'react-router-dom';
import { Card, CardContent } from '@/components/ui/card';
import { Input } from '@/components/ui/input';
import { Badge } from '@/components/ui/badge';
import { Table, TableBody, TableCell, TableHead, TableHeader, TableRow } from '@/components/ui/table';
import { Search } from 'lucide-react';
import { MOCK_USERS, MOCK_STUDENT_STATS } from '@/data/mockData';

/**
 * Students list — see spec §3 row 3.
 * Reads MOCK_USERS for the table rows and MOCK_STUDENT_STATS for the
 * per-student summary columns. Replaces the design's Math.random() with
 * a deterministic lookup so screenshots are stable.
 */
export default function InstructorStudents() {
  const [search, setSearch] = useState('');
  const students = MOCK_USERS.filter(
    (u) =>
      u.role === 'student' &&
      (u.name.toLowerCase().includes(search.toLowerCase()) ||
        u.studentId?.toLowerCase().includes(search.toLowerCase()))
  );

  const statsById = Object.fromEntries(MOCK_STUDENT_STATS.map((s) => [s.studentId, s]));

  return (
    <div className="space-y-6">
      <div className="flex flex-col sm:flex-row sm:items-center justify-between gap-4">
        <div>
          <h1 className="text-3xl font-bold tracking-tight">Students</h1>
          <p className="text-muted-foreground">Manage and monitor student progress.</p>
        </div>
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

      <Card>
        <CardContent className="p-0">
          <Table>
            <TableHeader>
              <TableRow>
                <TableHead>Student</TableHead>
                <TableHead>Student ID</TableHead>
                <TableHead>Avg CDS</TableHead>
                <TableHead>Strongest Concept</TableHead>
                <TableHead>Last Active</TableHead>
                <TableHead>Status</TableHead>
              </TableRow>
            </TableHeader>
            <TableBody>
              {students.length === 0 ? (
                <TableRow>
                  <TableCell colSpan={6} className="text-center text-muted-foreground py-6">
                    No students found matching your search.
                  </TableCell>
                </TableRow>
              ) : (
                students.map((s) => {
                  const stats = statsById[s.id] || { avgCds: 0, highestConcept: '—', lastActiveDays: 0, hasAlert: false };
                  return (
                    <TableRow key={s.id}>
                      <TableCell className="font-medium">
                        <Link to={`/instructor/students/${s.id}`} className="hover:underline text-primary">
                          {s.name}
                        </Link>
                      </TableCell>
                      <TableCell className="text-muted-foreground">{s.studentId}</TableCell>
                      <TableCell>{stats.avgCds}</TableCell>
                      <TableCell>
                        <Badge variant="secondary">{stats.highestConcept}</Badge>
                      </TableCell>
                      <TableCell className="text-muted-foreground">
                        {stats.lastActiveDays === 0 ? 'today' : `${stats.lastActiveDays}d ago`}
                      </TableCell>
                      <TableCell>
                        {stats.hasAlert ? (
                          <Badge variant="destructive">Alert</Badge>
                        ) : (
                          <Badge variant="outline">OK</Badge>
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
    </div>
  );
}
