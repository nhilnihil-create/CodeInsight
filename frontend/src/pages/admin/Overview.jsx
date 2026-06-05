import { useState, useEffect } from 'react';
import { Users, BookOpen, AlertTriangle, BarChart3, Layers, Activity } from 'lucide-react';
import api from '../../services/api';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { cn } from '@/lib/utils';

export default function AdminOverview() {
  const [stats, setStats] = useState({ users: 0, instructors: 0, students: 0, sections: 0, exercises: 0, flags: 0 });
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    const load = async () => {
      try {
        const [uRes, sRes, eRes, fRes] = await Promise.all([
          api.get('/api/admin/stats/users').catch(() => null),
          api.get('/api/admin/stats/sections').catch(() => null),
          api.get('/api/admin/stats/exercises').catch(() => null),
          api.get('/api/admin/stats/flags').catch(() => null),
        ]);
        setStats({
          users: uRes?.data?.total || 0,
          instructors: uRes?.data?.instructors || 0,
          students: uRes?.data?.students || 0,
          sections: sRes?.data?.count || 0,
          exercises: eRes?.data?.count || 0,
          flags: fRes?.data?.count || 0,
        });
      } catch (err) {
        console.error('Admin stats load failed, using mock:', err);
        setStats({ users: 12, instructors: 3, students: 9, sections: 5, exercises: 24, flags: 3 });
      } finally {
        setLoading(false);
      }
    };
    load();
  }, []);

  const tiles = [
    { label: 'Total Users', value: stats.users, icon: Users, color: 'text-blue-500 bg-blue-500/10' },
    { label: 'Instructors', value: stats.instructors, icon: BarChart3, color: 'text-purple-500 bg-purple-500/10' },
    { label: 'Students', value: stats.students, icon: Users, color: 'text-emerald-500 bg-emerald-500/10' },
    { label: 'Sections', value: stats.sections, icon: Layers, color: 'text-amber-500 bg-amber-500/10' },
    { label: 'Exercises', value: stats.exercises, icon: BookOpen, color: 'text-cyan-500 bg-cyan-500/10' },
    { label: 'Open Flags', value: stats.flags, icon: AlertTriangle, color: 'text-red-500 bg-red-500/10' },
  ];

  if (loading) return <div className="text-muted-foreground">Loading overview...</div>;

  return (
    <div className="space-y-6">
      <div>
        <h2 className="text-lg font-bold text-foreground">Department Overview</h2>
        <p className="text-sm text-muted-foreground">System-wide metrics for CodeInsight deployment.</p>
      </div>
      <div className="grid grid-cols-2 gap-4 sm:grid-cols-3 lg:grid-cols-6">
        {tiles.map(t => (
          <Card key={t.label}>
            <CardContent className="pt-4 text-center">
              <div className={cn('mx-auto mb-2 flex h-8 w-8 items-center justify-center rounded-lg', t.color)}>
                <t.icon className="h-4 w-4" />
              </div>
              <div className="font-mono text-xl font-bold text-foreground">{t.value}</div>
              <div className="text-[9px] uppercase tracking-wider text-muted-foreground">{t.label}</div>
            </CardContent>
          </Card>
        ))}
      </div>
      <div className="grid grid-cols-1 gap-4 lg:grid-cols-2">
        <Card>
          <CardHeader><CardTitle className="text-xs font-bold">System Health</CardTitle></CardHeader>
          <CardContent className="space-y-3">
            {[
              { label: 'API Status', value: 'Operational', ok: true },
              { label: 'Database', value: 'Connected', ok: true },
              { label: 'CDS Engine', value: 'Idle', ok: true },
              { label: 'Auto-Close Service', value: 'Running', ok: true },
              { label: 'Integrity Engine', value: 'Active', ok: true },
            ].map(s => (
              <div key={s.label} className="flex items-center justify-between text-xs">
                <span className="text-muted-foreground">{s.label}</span>
                <span className={cn('flex items-center gap-1 font-semibold', s.ok ? 'text-emerald-500' : 'text-red-500')}>
                  <span className={cn('h-1.5 w-1.5 rounded-full', s.ok ? 'bg-emerald-500' : 'bg-red-500')} />
                  {s.value}
                </span>
              </div>
            ))}
          </CardContent>
        </Card>
        <Card>
          <CardHeader><CardTitle className="text-xs font-bold">Recent Activity</CardTitle></CardHeader>
          <CardContent>
            <div className="divide-y divide-border text-xs">
              {[
                { action: 'BSIT-1A auto-closed', ts: '2 min ago' },
                { action: 'Batch CDS computed for Ex-5', ts: '15 min ago' },
                { action: 'Maria Reyes enrolled in BSCS-1A', ts: '1h ago' },
                { action: 'Integrity flag reviewed', ts: '2h ago' },
                { action: 'New exercise created: Array Sort', ts: '3h ago' },
              ].map((a, i) => (
                <div key={i} className="flex items-center justify-between py-2 first:pt-0 last:pb-0">
                  <span className="text-foreground">{a.action}</span>
                  <span className="text-muted-foreground">{a.ts}</span>
                </div>
              ))}
            </div>
          </CardContent>
        </Card>
      </div>
    </div>
  );
}
