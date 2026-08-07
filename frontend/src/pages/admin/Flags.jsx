import { useState, useEffect } from 'react';
import api from '../../services/api';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Badge } from '@/components/ui/badge';
import PageBreadcrumb from '@/components/ui/page-breadcrumb';
import { Select, SelectContent, SelectItem, SelectTrigger, SelectValue } from '@/components/ui/select';
import { format } from 'date-fns';
import { flagTypeLabel } from '../../lib/flagTypes';

const SEVERITY_COLORS = {
  critical: 'bg-rose-500/10 text-rose-600 border-rose-500/30',
  high: 'bg-orange-500/10 text-orange-600 border-orange-500/30',
  medium: 'bg-amber-500/10 text-amber-600 border-amber-500/30',
  low: 'bg-yellow-500/10 text-yellow-600 border-yellow-500/30',
};

const STATUS_COLORS = {
  flagged: 'bg-rose-500/10 text-rose-600 border-rose-500/30',
  resolved: 'bg-emerald-500/10 text-emerald-600 border-emerald-500/30',
  dismissed: 'bg-muted text-muted-foreground border-border',
};

export default function AdminFlags() {
  const [flags, setFlags] = useState([]);
  const [total, setTotal] = useState(0);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [statusFilter, setStatusFilter] = useState('flagged');

  const load = async () => {
    setLoading(true);
    setError(null);
    try {
      const params = {};
      if (statusFilter) params.status = statusFilter;
      const res = await api.get('/api/admin/flags', { params });
      setFlags(res.data.flags || []);
      setTotal(res.data.total || 0);
    } catch (err) {
      setError(err.response?.data?.message || err.message);
    } finally {
      setLoading(false);
    }
  };

  useEffect(() => { load(); }, [statusFilter]);

  const handleResolve = async (id) => {
    try {
      await api.patch(`/api/admin/flags/${id}`, { status: 'resolved' });
      await load();
    } catch (err) {
      setError(err.response?.data?.message || err.message);
    }
  };

  const handleDismiss = async (id) => {
    try {
      await api.patch(`/api/admin/flags/${id}`, { status: 'dismissed' });
      await load();
    } catch (err) {
      setError(err.response?.data?.message || err.message);
    }
  };

  return (
    <div className="space-y-6">
      <PageBreadcrumb crumbs={[{ label: 'Admin', href: '/admin' }, { label: 'Integrity Flags' }]} />
      <Card>
        <CardHeader className="flex flex-row items-center justify-between">
          <CardTitle>Integrity Flags ({total})</CardTitle>
          <Select value={statusFilter} onValueChange={setStatusFilter}>
            <SelectTrigger className="w-32 h-8 text-xs"><SelectValue /></SelectTrigger>
            <SelectContent>
              <SelectItem value="">All</SelectItem>
              <SelectItem value="flagged">Flagged</SelectItem>
              <SelectItem value="resolved">Resolved</SelectItem>
              <SelectItem value="dismissed">Dismissed</SelectItem>
            </SelectContent>
          </Select>
        </CardHeader>
        <CardContent>
          {error && <p className="text-destructive text-sm">Failed: {error}</p>}
          {loading ? (
            <p className="text-muted-foreground text-sm text-center py-8">Loading flags…</p>
          ) : flags.length === 0 ? (
            <p className="text-muted-foreground text-sm text-center py-8">No flags match filter.</p>
          ) : (
            <div className="divide-y divide-border">
              {flags.map(f => (
                <div key={f.id} className="py-4 space-y-2">
                  <div className="flex items-start justify-between gap-4">
                    <div className="space-y-1 min-w-0">
                      <div className="flex items-center gap-2 flex-wrap">
                        <Badge variant="outline" className={SEVERITY_COLORS[f.severity] || ''}>{f.severity}</Badge>
                        <Badge variant="outline" className="font-mono text-[10px]">{flagTypeLabel(f.flag_type)}</Badge>
                        <Badge variant="outline" className={STATUS_COLORS[f.status] || ''}>{f.status}</Badge>
                      </div>
                      <p className="text-sm font-medium">{f.student_name}</p>
                      <p className="text-xs text-muted-foreground">{f.exercise_title} · {f.section_name}</p>
                      <p className="text-[10px] text-muted-foreground">{format(new Date(f.created_at), 'MMM d, yyyy HH:mm')}</p>
                    </div>
                    {f.status === 'flagged' && (
                      <div className="flex gap-1 shrink-0">
                        <Button size="sm" variant="outline" className="h-7 text-xs" onClick={() => handleDismiss(f.id)}>Dismiss</Button>
                        <Button size="sm" className="h-7 text-xs" onClick={() => handleResolve(f.id)}>Resolve</Button>
                      </div>
                    )}
                  </div>
                  {f.evidence && typeof f.evidence === 'object' && Object.keys(f.evidence).length > 0 && (
                    <details className="text-[10px] text-muted-foreground">
                      <summary className="cursor-pointer hover:text-foreground">Evidence</summary>
                      <pre className="mt-1 p-2 bg-muted/30 rounded text-[9px] overflow-x-auto">{JSON.stringify(f.evidence, null, 2)}</pre>
                    </details>
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
