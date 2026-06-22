import { useState, useEffect } from 'react';
import api from '../../services/api';
import PageBreadcrumb from '@/components/ui/page-breadcrumb';
import { Badge } from '@/components/ui/badge';
import { Input } from '@/components/ui/input';
import { format } from 'date-fns';
import { ResponsiveTable } from '@/components/ui/responsive-table';

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
      {error && <p className="text-destructive text-sm">Failed to load: {error}</p>}

      <div className="flex items-center justify-between mb-4">
        <h2 className="text-lg font-semibold">Department Audit Log</h2>
        <Input
          placeholder="Search audit log..."
          value={search}
          onChange={e => setSearch(e.target.value)}
          className="max-w-[200px] h-8 text-xs"
        />
      </div>

      <ResponsiveTable
        columns={[
          { key: 'date', header: 'Date', mobile: 'label',
            renderCell: (l) => (
              <span className="text-muted-foreground whitespace-nowrap">
                {format(new Date(l.created_at), 'MMM d, HH:mm')}
              </span>
            ),
          },
          { key: 'actor', header: 'Actor', mobile: 'primary',
            renderCell: (l) => <span className="font-medium">{l.actor_name || '—'}</span>,
          },
          { key: 'action', header: 'Action', mobile: 'label',
            renderCell: (l) => (
              <Badge className={ACTION_COLORS[l.action] || 'bg-muted text-muted-foreground border-border'}>
                {l.action?.replace(/_/g, ' ')}
              </Badge>
            ),
          },
          { key: 'section', header: 'Section', mobile: 'hidden',
            renderCell: (l) => <span>{l.section_name || '—'}</span>,
          },
          { key: 'details', header: 'Details', mobile: 'hidden',
            renderCell: (l) => (
              <span className="text-muted-foreground max-w-xs truncate block">{metaStr(l.meta)}</span>
            ),
          },
        ]}
        data={filtered}
        keyExtractor={(l) => String(l.id)}
        emptyMessage="No audit entries found."
      />
    </div>
  );
}
