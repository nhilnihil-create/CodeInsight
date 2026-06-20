import { useState, useEffect } from 'react';
import api from '../../services/api';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import PageBreadcrumb from '@/components/ui/page-breadcrumb';
import { Badge } from '@/components/ui/badge';
import { Input } from '@/components/ui/input';
import { ScrollArea } from '@/components/ui/scroll-area';
import { format } from 'date-fns';

const ACTION_COLORS = {
  section_created: 'bg-blue-500/10 text-blue-600 border-blue-500/30',
  section_updated: 'bg-amber-500/10 text-amber-600 border-amber-500/30',
  section_deleted: 'bg-rose-500/10 text-rose-600 border-rose-500/30',
  member_added: 'bg-emerald-500/10 text-emerald-600 border-emerald-500/30',
  member_removed: 'bg-orange-500/10 text-orange-600 border-orange-500/30',
  role_changed: 'bg-purple-500/10 text-purple-600 border-purple-500/30',
};

const metaStr = m => typeof m === 'object' && m ? JSON.stringify(m) : String(m || '');

export default function AdminAudit() {
  const [logs, setLogs] = useState([]);
  const [error, setError] = useState(null);
  const [search, setSearch] = useState('');

  useEffect(() => {
    const load = async () => {
      try {
        const res = await api.get('/api/sections/audit/all');
        setLogs(res.data);
      } catch (err) {
        setError(err.response?.data?.message || err.message);
      }
    };
    load();
  }, []);

  const filtered = logs.filter(l =>
    !search || l.actor_name?.toLowerCase().includes(search.toLowerCase()) ||
    l.section_name?.toLowerCase().includes(search.toLowerCase()) ||
    l.action?.toLowerCase().includes(search.toLowerCase())
  );

  return (
    <div className="space-y-6">
      <PageBreadcrumb items={[{ label: 'Admin', href: '/admin' }, { label: 'Audit Log' }]} />
      <Card>
        <CardHeader className="flex flex-row items-center justify-between">
          <CardTitle>Department Audit Log</CardTitle>
          <Input
            placeholder="Search audit log..."
            value={search}
            onChange={e => setSearch(e.target.value)}
            className="max-w-xs"
          />
        </CardHeader>
        <CardContent>
          {error && <p className="text-destructive text-sm">Failed to load: {error}</p>}
          {!error && filtered.length === 0 && (
            <p className="text-muted-foreground text-sm text-center py-8">No audit entries found.</p>
          )}
          <ScrollArea className="h-[65vh]">
            <table className="w-full text-sm">
              <thead>
                <tr className="border-b text-left text-muted-foreground">
                  <th className="pb-2 pr-4 font-medium">Date</th>
                  <th className="pb-2 pr-4 font-medium">Actor</th>
                  <th className="pb-2 pr-4 font-medium">Action</th>
                  <th className="pb-2 font-medium">Section</th>
                  <th className="pb-2 pl-4 font-medium hidden md:table-cell">Details</th>
                </tr>
              </thead>
              <tbody>
                {filtered.map(l => (
                  <tr key={l.id} className="border-b last:border-0 hover:bg-muted/30">
                    <td className="py-2 pr-4 text-muted-foreground whitespace-nowrap">
                      {format(new Date(l.created_at), 'MMM d, HH:mm')}
                    </td>
                    <td className="py-2 pr-4 font-medium">{l.actor_name || '—'}</td>
                    <td className="py-2 pr-4">
                      <Badge className={ACTION_COLORS[l.action] || 'bg-muted text-muted-foreground border-border'}>
                        {l.action?.replace(/_/g, ' ')}
                      </Badge>
                    </td>
                    <td className="py-2 pr-4">{l.section_name || '—'}</td>
                    <td className="py-2 pl-4 text-muted-foreground hidden md:table-cell max-w-xs truncate">
                      {metaStr(l.meta)}
                    </td>
                  </tr>
                ))}
              </tbody>
            </table>
          </ScrollArea>
        </CardContent>
      </Card>
    </div>
  );
}
