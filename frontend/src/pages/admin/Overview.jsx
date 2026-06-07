import { useState, useEffect } from 'react';
import api from '../../services/api';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import PageBreadcrumb from '@/components/ui/page-breadcrumb';
import { cn } from '@/lib/utils';

const TONE_BG = {
  success: 'bg-emerald-500/10 text-emerald-600 border-emerald-500/30',
  destructive: 'bg-rose-500/10 text-rose-600 border-rose-500/30',
  warning: 'bg-amber-500/10 text-amber-600 border-amber-500/30',
  muted: 'bg-muted text-muted-foreground border-border',
};

export default function AdminOverview() {
  const [data, setData] = useState(null);
  const [error, setError] = useState(null);

  useEffect(() => {
    const load = async () => {
      try {
        const res = await api.get('/api/admin/overview');
        setData(res.data);
      } catch (err) {
        setError(err.response?.data?.message || err.message);
      }
    };
    load();
  }, []);

  if (error) return <p className="text-destructive text-sm">Failed to load: {error}</p>;
  if (!data) return <p className="text-muted-foreground text-sm">Loading overview…</p>;

  const { totals = {}, counts = {}, flagged = [] } = data;
  const totalUsers = (totals.students || 0) + (totals.instructors || 0) + (totals.admins || 0);
  const flaggedCount = flagged.reduce((s, f) => s + (f.count || 0), 0);

  return (
    <div className="space-y-6 sm:space-y-8">
      <div className="space-y-2">
        <PageBreadcrumb crumbs={[{ label: 'Admin' }, { label: 'System Overview' }]} />
        <div className="min-w-0 space-y-1">
          <h1 className="text-2xl font-semibold tracking-tight">System Overview</h1>
          <p className="text-sm text-muted-foreground">Live deployment snapshot.</p>
        </div>
      </div>

      <div className="grid grid-cols-2 lg:grid-cols-4 gap-4">
        <StatTile label="Total users" value={totalUsers} sub={`${totals.students || 0} students · ${totals.instructors || 0} instructors · ${totals.admins || 0} admins`} />
        <StatTile label="Sections" value={counts.sections || 0} sub="active" />
        <StatTile label="Exercises" value={counts.exercises || 0} sub={`${counts.submissions || 0} submissions`} />
        <StatTile label="Open flags" value={counts.openFlags || 0} sub={`${flaggedCount} flagged CDS`} tone={flaggedCount > 0 ? 'destructive' : 'success'} />
      </div>

      <div className="grid grid-cols-1 md:grid-cols-2 gap-4">
        <Card>
          <CardHeader className="pb-3 border-b border-border">
            <CardTitle className="text-sm">Users by role</CardTitle>
          </CardHeader>
          <CardContent className="pt-4 space-y-2">
            <RoleBar label="Students"    value={totals.students    || 0} max={totalUsers} />
            <RoleBar label="Instructors" value={totals.instructors || 0} max={totalUsers} />
            <RoleBar label="Admins"      value={totals.admins      || 0} max={totalUsers} />
          </CardContent>
        </Card>
        <Card>
          <CardHeader className="pb-3 border-b border-border">
            <CardTitle className="text-sm">Flagged CDS</CardTitle>
          </CardHeader>
          <CardContent className="pt-4 space-y-2">
            {flagged.length === 0 ? (
              <p className="text-xs text-muted-foreground">No flagged CDS in window.</p>
            ) : flagged.map(f => (
              <div key={f.classification} className="flex items-center justify-between text-xs">
                <span className="font-medium">{f.classification}</span>
                <span className="font-mono">{f.count}</span>
              </div>
            ))}
          </CardContent>
        </Card>
      </div>

      <Card>
        <CardHeader className="pb-3 border-b border-border">
          <CardTitle className="text-sm">Evaluation</CardTitle>
        </CardHeader>
        <CardContent className="pt-4">
          <p className="text-xs text-muted-foreground">
            {counts.evaluations || 0} ISO/IEC 25010 evaluation responses recorded.
            {' '}
            <a className="text-primary underline" href="/admin/evaluation">View / export →</a>
          </p>
        </CardContent>
      </Card>
    </div>
  );
}

function StatTile({ label, value, sub, tone }) {
  return (
    <div className={cn('bg-card border border-border rounded-lg shadow-sm p-5 flex flex-col gap-2', tone && TONE_BG[tone])}>
      <p className="text-[10px] font-semibold uppercase tracking-wider opacity-80">{label}</p>
      <p className="text-2xl font-semibold font-mono tabular-nums tracking-tight">{value}</p>
      <p className="text-xs opacity-80">{sub}</p>
    </div>
  );
}

function RoleBar({ label, value, max }) {
  const pct = max > 0 ? Math.round((value / max) * 100) : 0;
  return (
    <div>
      <div className="flex items-center justify-between text-xs">
        <span className="font-medium">{label}</span>
        <span className="font-mono">{value}</span>
      </div>
      <div className="mt-1 h-1.5 w-full bg-muted rounded">
        <div className="h-full bg-primary rounded transition-all" style={{ width: `${pct}%` }} />
      </div>
    </div>
  );
}
