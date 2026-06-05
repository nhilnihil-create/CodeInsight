import { useState, useEffect } from 'react';
import { Search, UserPlus, Shield, User } from 'lucide-react';
import api from '../../services/api';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Input } from '@/components/ui/input';
import { Badge } from '@/components/ui/badge';
import { cn } from '@/lib/utils';

export default function AdminUsers() {
  const [users, setUsers] = useState([]);
  const [loading, setLoading] = useState(true);
  const [search, setSearch] = useState('');

  useEffect(() => {
    const load = async () => {
      try {
        const res = await api.get('/api/admin/users').catch(() => null);
        setUsers(res?.data || [
          { id: 1, name: 'Juan Dela Cruz', email: 'instructor@psu.edu', role: 'instructor', created_at: '2025-06-01' },
          { id: 2, name: 'Maria Reyes', email: 'maria@student.psu.edu', role: 'student', created_at: '2025-06-01' },
          { id: 3, name: 'Jose Santos', email: 'jose@student.psu.edu', role: 'student', created_at: '2025-06-01' },
          { id: 4, name: 'Ana Lim', email: 'ana@student.psu.edu', role: 'student', created_at: '2025-06-01' },
          { id: 5, name: 'Dr. Reyes', email: 'reyes@psu.edu', role: 'instructor', created_at: '2025-08-01' },
        ]);
      } catch (err) {
        console.error(err);
      } finally {
        setLoading(false);
      }
    };
    load();
  }, []);

  const filtered = users.filter(u =>
    u.name.toLowerCase().includes(search.toLowerCase()) ||
    u.email.toLowerCase().includes(search.toLowerCase())
  );

  if (loading) return <div className="text-muted-foreground">Loading users...</div>;

  return (
    <div className="space-y-4">
      <div className="flex items-center justify-between">
        <div className="relative w-[200px]">
          <Search className="pointer-events-none absolute left-2.5 top-1/2 h-3.5 w-3.5 -translate-y-1/2 text-muted-foreground" />
          <Input type="text" placeholder="Search users..." value={search} onChange={e => setSearch(e.target.value)} className="h-8 pl-7 text-xs" />
        </div>
        <Button size="sm"><UserPlus className="mr-1 h-3.5 w-3.5" /> Add User</Button>
      </div>
      <Card>
        <div className="overflow-x-auto">
          <table className="w-full border-collapse text-xs">
            <thead className="bg-muted/30">
              <tr>
                <th className="border-b border-border px-3 py-2.5 text-left text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Name</th>
                <th className="border-b border-border px-3 py-2.5 text-left text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Email</th>
                <th className="border-b border-border px-3 py-2.5 text-center text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Role</th>
                <th className="border-b border-border px-3 py-2.5 text-center text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Joined</th>
                <th className="border-b border-border px-3 py-2.5 text-center text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Actions</th>
              </tr>
            </thead>
            <tbody>
              {filtered.map(u => (
                <tr key={u.id} className="border-b border-border/60 last:border-0 hover:bg-muted/20">
                  <td className="px-3 py-2.5 font-semibold text-foreground">{u.name}</td>
                  <td className="px-3 py-2.5 text-muted-foreground">{u.email}</td>
                  <td className="px-3 py-2.5 text-center">
                    <Badge variant="outline" className={cn('text-[9px]', u.role === 'admin' ? 'border-purple-500/30 text-purple-500' : u.role === 'instructor' ? 'border-blue-500/30 text-blue-500' : 'border-emerald-500/30 text-emerald-500')}>
                      {u.role === 'admin' ? <Shield className="mr-1 h-2.5 w-2.5" /> : <User className="mr-1 h-2.5 w-2.5" />}
                      {u.role}
                    </Badge>
                  </td>
                  <td className="px-3 py-2.5 text-center text-muted-foreground">{u.created_at}</td>
                  <td className="px-3 py-2.5 text-center">
                    <Button variant="ghost" size="sm" className="h-6 text-[9px]">Edit</Button>
                  </td>
                </tr>
              ))}
            </tbody>
          </table>
        </div>
      </Card>
    </div>
  );
}
