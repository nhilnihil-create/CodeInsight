import { Link, useParams } from 'react-router-dom';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Badge } from '@/components/ui/badge';
import { ChevronLeft } from 'lucide-react';
import { MOCK_USERS } from '@/data/mockData';
import MicroConceptAlertCard from '@/components/analytics/MicroConceptAlertCard';
import LongitudinalProgressChart from '@/components/analytics/LongitudinalProgressChart';
import '@/components/analytics/MicroConceptAlertCard.css';
import '@/components/analytics/LongitudinalProgressChart.css';

/**
 * Student detail — see spec §3 row 4.
 * Reads MOCK_USERS to find the student. Embeds the existing analytics
 * components (MicroConceptAlertCard, LongitudinalProgressChart) inside
 * their own <Card> shells.
 *
 * NOTE: The embedded analytics components are API-driven
 * (MicroConceptAlertCard takes `alert`+`onDismiss`; LongitudinalProgressChart
 * takes `data`+`studentName`). Per spec §2.3 the real-data wiring is a
 * follow-up; we pass null/empty stubs so the components render their
 * built-in empty states instead of crashing on undefined props.
 */
export default function InstructorStudentDetail() {
  const { id } = useParams();
  const student = MOCK_USERS.find((u) => u.id === id && u.role === 'student');

  if (!student) {
    return (
      <div className="space-y-4">
        <Button asChild variant="ghost" size="sm">
          <Link to="/instructor/students"><ChevronLeft className="w-4 h-4 mr-1" /> Back to students</Link>
        </Button>
        <Card>
          <CardContent className="p-6">
            <h2 className="text-lg font-semibold mb-2">Student not found</h2>
            <p className="text-muted-foreground">No student with id <code>{id}</code>.</p>
          </CardContent>
        </Card>
      </div>
    );
  }

  // Minimal-valid stub: required fields populated with the student's name so
  // MicroConceptAlertCard renders harmlessly. Optional fields (microConceptDifficulty,
  // evidence, instructorNote) are omitted to hit its built-in "no detail" branch.
  const alertStub = {
    id: null,
    student_id: student.id,
    exercise_id: null,
    student_name: student.name,
    exercise_title: '—',
    classification: 'Low',
    cds_score: 0,
  };

  return (
    <div className="space-y-6">
      <div className="flex items-center justify-between">
        <div>
          <Button asChild variant="ghost" size="sm" className="mb-2 -ml-2">
            <Link to="/instructor/students"><ChevronLeft className="w-4 h-4 mr-1" /> Back to students</Link>
          </Button>
          <h1 className="text-3xl font-bold tracking-tight">{student.name}</h1>
          <p className="text-muted-foreground">{student.email} · {student.studentId}</p>
        </div>
        <Badge variant="outline">Active</Badge>
      </div>

      <div className="grid gap-6 md:grid-cols-2">
        <Card>
          <CardHeader>
            <CardTitle>Longitudinal Progress</CardTitle>
          </CardHeader>
          <CardContent>
            <LongitudinalProgressChart data={null} studentName={student.name} />
          </CardContent>
        </Card>
        <Card>
          <CardHeader>
            <CardTitle>Micro-Concept Insights</CardTitle>
          </CardHeader>
          <CardContent>
            <MicroConceptAlertCard alert={alertStub} />
          </CardContent>
        </Card>
      </div>
    </div>
  );
}
