import { useEffect, useState } from 'react';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Bell } from 'lucide-react';
import StudentAlertCard from '@/components/analytics/StudentAlertCard';
import SectionFilter from '@/components/SectionFilter';
import api from '@/services/api';

/**
 * Early warnings — see spec §3 row 7.
 * When a section is picked, the per-student alert cards are sourced from
 * /api/analytics/alerts/:sectionId; "All Sections" aggregates the alert
 * list across the instructor's sections. The page also accepts a "show
 * all" override for the design mock list when "All Sections" is selected.
 */
export default function InstructorWarnings() {
  const [sectionId, setSectionId] = useState('all');
  const [alerts, setAlerts] = useState(null);

  useEffect(() => {
    if (sectionId === 'all') {
      setAlerts(null);
      return;
    }
    let cancelled = false;
    const load = async () => {
      try {
        const res = await api.get(`/api/analytics/alerts/${sectionId}`);
        if (!cancelled) setAlerts(Array.isArray(res.data) ? res.data : []);
      } catch {
        if (!cancelled) setAlerts([]);
      }
    };
    load();
    return () => { cancelled = true; };
  }, [sectionId]);

  return (
    <div className="space-y-6">
      <div className="flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between">
        <div>
          <h1 className="text-3xl font-bold tracking-tight">Early Warnings</h1>
          <p className="text-muted-foreground">Students showing signs of falling behind.</p>
        </div>
        <SectionFilter value={sectionId} onChange={setSectionId} />
      </div>

      <Card>
        <CardHeader className="flex flex-row items-center gap-2">
          <Bell className="w-4 h-4 text-muted-foreground" />
          <CardTitle>Active Alerts</CardTitle>
        </CardHeader>
        <CardContent>
          {alerts === null ? (
            <StudentAlertCard />
          ) : alerts.length === 0 ? (
            <div className="rounded-md border border-border bg-muted/30 p-6 text-center text-sm text-muted-foreground">
              No active alerts for this section.
            </div>
          ) : (
            <div className="space-y-3">
              {alerts.map((alert, i) => (
                <div key={alert.id || i} className="rounded-md border border-border bg-card p-4">
                  <div className="text-sm font-semibold text-foreground">
                    {alert.student_name || alert.studentName || `Student #${alert.student_id || alert.studentId}`}
                  </div>
                  <div className="mt-1 text-xs text-muted-foreground">
                    {alert.reason || alert.message || 'Alert'}
                  </div>
                  {alert.cds !== undefined && (
                    <div className="mt-2 text-xs text-muted-foreground">
                      CDS: {typeof alert.cds === 'number' ? alert.cds.toFixed(2) : alert.cds}
                    </div>
                  )}
                </div>
              ))}
            </div>
          )}
        </CardContent>
      </Card>
    </div>
  );
}
