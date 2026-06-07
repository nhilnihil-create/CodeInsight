import { Link } from 'react-router-dom';
import { Card, CardContent } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Badge } from '@/components/ui/badge';
import { cn } from '@/lib/utils';
import StudentDashboardShell from '@/components/student-dashboard-shell';
import { MOCK_RECOMMENDATIONS } from '@/data/mockData';

export default function StudentRecommendations() {
  return (
    <StudentDashboardShell
      breadcrumb={[
        { label: 'Student', href: '/student/dashboard' },
        { label: 'Recommended Next Moves' },
      ]}
      subtitle="Personalized suggestions based on your progress."
    >
      {MOCK_RECOMMENDATIONS.map(rec => (
        <Card
          key={rec.priority}
          className={rec.priority === 1 ? 'border-l-4 border-l-primary' : ''}
        >
          <CardContent className="p-4 space-y-3">
            <div className="flex items-center justify-between">
              <Badge
                variant={
                  rec.priority === 1
                    ? 'default'
                    : rec.priority === 2
                      ? 'secondary'
                      : 'outline'
                }
              >
                {rec.priority === 1
                  ? 'Priority'
                  : rec.priority === 2
                    ? 'Optional'
                    : 'Stretch'}
              </Badge>
              <span
                className={cn(
                  'text-[10px] font-medium uppercase tracking-wider px-1.5 py-0.5 rounded',
                  rec.confidence === 'high'
                    ? 'text-[#22C55E] bg-[#22C55E]/10'
                    : 'text-[#FACC15] bg-[#FACC15]/10'
                )}
              >
                Confidence:{' '}
                {rec.confidence.charAt(0).toUpperCase() +
                  rec.confidence.slice(1)}
              </span>
            </div>
            <p className="text-sm">{rec.pattern}</p>
            <div className="flex items-center gap-2 pt-1">
              <Button asChild size="sm">
                <Link to={rec.action.to}>{rec.action.label}</Link>
              </Button>
              {rec.whyLink && (
                <button
                  type="button"
                  className="text-[10px] text-muted-foreground underline underline-offset-2"
                >
                  Why am I seeing this?
                </button>
              )}
            </div>
          </CardContent>
        </Card>
      ))}
    </StudentDashboardShell>
  );
}
