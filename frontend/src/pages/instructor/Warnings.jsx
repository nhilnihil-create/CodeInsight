import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Bell } from 'lucide-react';
import StudentAlertCard from '@/components/analytics/StudentAlertCard';

/**
 * Early warnings — see spec §3 row 7.
 * The StudentAlertCard analytics component renders the per-student alert
 * cards; this host page provides the title, subhead, and Card frame.
 */
export default function InstructorWarnings() {
  return (
    <div className="space-y-6">
      <div>
        <h1 className="text-3xl font-bold tracking-tight">Early Warnings</h1>
        <p className="text-muted-foreground">Students showing signs of falling behind.</p>
      </div>

      <Card>
        <CardHeader className="flex flex-row items-center gap-2">
          <Bell className="w-4 h-4 text-muted-foreground" />
          <CardTitle>Active Alerts</CardTitle>
        </CardHeader>
        <CardContent>
          <StudentAlertCard />
        </CardContent>
      </Card>
    </div>
  );
}
