import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Badge } from '@/components/ui/badge';
import StudentDashboardShell from '@/components/student-dashboard-shell';
import { MOCK_STUDENT_INTEGRITY } from '@/data/mockData';

export default function StudentIntegrityView() {
  const { flags } = MOCK_STUDENT_INTEGRITY;

  return (
    <StudentDashboardShell
      breadcrumb={[
        { label: 'Student', href: '/student/dashboard' },
        { label: 'My Learning Dashboard' },
      ]}
      subtitle="Patterns detected in your work — always hypotheses, never verdicts."
    >
      {flags.length === 0 ? (
        <Card>
          <CardContent className="p-6 text-center text-muted-foreground">
            No patterns detected. Keep coding!
          </CardContent>
        </Card>
      ) : (
        flags.map(flag => (
          <Card
            key={flag.id}
            className="border-dashed border-muted-foreground/30"
          >
            <CardContent className="p-4 space-y-3">
              <div className="flex items-start justify-between">
                <div>
                  <Badge variant="outline" className="text-xs font-mono">
                    {flag.rule}
                  </Badge>
                  <p className="text-sm mt-2">{flag.description}</p>
                </div>
                <button
                  type="button"
                  className="text-[10px] text-muted-foreground underline underline-offset-2 hover:text-foreground shrink-0"
                >
                  Why am I seeing this?
                </button>
              </div>

              {flag.evidence && (
                <p className="text-xs text-muted-foreground bg-muted/50 p-2 rounded">
                  {flag.evidence}
                </p>
              )}

              <div className="flex gap-2 pt-1 border-t border-border/50">
                <Button variant="outline" size="sm" className="text-xs">
                  Request 1:1
                </Button>
                <Button variant="outline" size="sm" className="text-xs">
                  Appeal
                </Button>
                <Button variant="ghost" size="sm" className="text-xs">
                  Read full rule
                </Button>
              </div>
            </CardContent>
          </Card>
        ))
      )}
    </StudentDashboardShell>
  );
}
