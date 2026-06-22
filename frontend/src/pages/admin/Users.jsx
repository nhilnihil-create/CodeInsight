import { useState, useEffect } from 'react';
import { Search, UserPlus, Shield, User, Pencil, Trash2, KeyRound } from 'lucide-react';
import { ResponsiveTable } from '@/components/ui/responsive-table';
import api from '../../services/api';
import { Button } from '@/components/ui/button';
import { Input } from '@/components/ui/input';
import { Badge } from '@/components/ui/badge';
import {
  Dialog, DialogContent, DialogHeader, DialogTitle, DialogFooter, DialogTrigger,
} from '@/components/ui/dialog';
import { Label } from '@/components/ui/label';
import { Select, SelectContent, SelectItem, SelectTrigger, SelectValue } from '@/components/ui/select';
import { cn } from '@/lib/utils';

const ROLES = ['instructor', 'student', 'admin'];

const emptyForm = { name: '', email: '', password: '', role: 'student' };

export default function AdminUsers() {
  const [users, setUsers] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [search, setSearch] = useState('');
  const [roleFilter, setRoleFilter] = useState('all');
  const [dialogOpen, setDialogOpen] = useState(false);
  const [editing, setEditing] = useState(null);
  const [form, setForm] = useState(emptyForm);
  const [busy, setBusy] = useState(false);
  const [resetTarget, setResetTarget] = useState(null);
  const [resetPassword, setResetPassword] = useState('');
  const [resetConfirm, setResetConfirm] = useState('');
  const [resetBusy, setResetBusy] = useState(false);

  const load = async () => {
    setLoading(true);
    setError(null);
    try {
      const params = {};
      if (search) params.search = search;
      if (roleFilter !== 'all') params.role = roleFilter;
      const res = await api.get('/api/admin/users', { params });
      setUsers(res.data.users || []);
    } catch (err) {
      setError(err.response?.data?.message || err.message);
    } finally {
      setLoading(false);
    }
  };

  useEffect(() => { load(); /* eslint-disable-next-line */ }, [roleFilter]);

  const openCreate = () => {
    setEditing(null);
    setForm(emptyForm);
    setDialogOpen(true);
  };

  const openEdit = (u) => {
    setEditing(u);
    setForm({ name: u.name, email: u.email, password: '', role: u.role });
    setDialogOpen(true);
  };

  const handleSubmit = async (e) => {
    e.preventDefault();
    setBusy(true);
    try {
      if (editing) {
        const { password, ...body } = form;
        await api.put(`/api/admin/users/${editing.id}`, body);
      } else {
        await api.post('/api/admin/users', form);
      }
      setDialogOpen(false);
      await load();
    } catch (err) {
      setError(err.response?.data?.message || err.message);
    } finally {
      setBusy(false);
    }
  };

  const handleDelete = async (u) => {
    if (!window.confirm(`Delete ${u.name}? This cannot be undone.`)) return;
    try {
      await api.delete(`/api/admin/users/${u.id}`);
      await load();
    } catch (err) {
      setError(err.response?.data?.message || err.message);
    }
  };

  const filtered = users.filter(u =>
    (roleFilter === 'all' || u.role === roleFilter) &&
    (!search ||
      u.name.toLowerCase().includes(search.toLowerCase()) ||
      u.email.toLowerCase().includes(search.toLowerCase()))
  );

  return (
    <div className="space-y-4">
      <div className="flex items-center justify-between gap-2 flex-wrap">
        <div className="flex items-center gap-2">
          <div className="relative w-[200px]">
            <Search className="pointer-events-none absolute left-2.5 top-1/2 h-3.5 w-3.5 -translate-y-1/2 text-muted-foreground" />
            <Input type="text" placeholder="Search users..." value={search} onChange={e => setSearch(e.target.value)} onKeyDown={(e) => e.key === 'Enter' && load()} className="h-8 pl-7 text-xs" />
          </div>
          <Select value={roleFilter} onValueChange={setRoleFilter}>
            <SelectTrigger className="h-8 w-[140px] text-xs"><SelectValue /></SelectTrigger>
            <SelectContent>
              <SelectItem value="all">All roles</SelectItem>
              {ROLES.map(r => <SelectItem key={r} value={r}>{r}</SelectItem>)}
            </SelectContent>
          </Select>
        </div>
        <Dialog open={dialogOpen} onOpenChange={setDialogOpen}>
          <DialogTrigger asChild>
            <Button size="sm" onClick={openCreate}><UserPlus className="mr-1 h-3.5 w-3.5" /> Add User</Button>
          </DialogTrigger>
          <DialogContent>
            <DialogHeader><DialogTitle>{editing ? 'Edit user' : 'Add user'}</DialogTitle></DialogHeader>
            <form onSubmit={handleSubmit} className="space-y-3">
              <div className="space-y-1">
                <Label htmlFor="name">Name</Label>
                <Input id="name" value={form.name} onChange={e => setForm({ ...form, name: e.target.value })} required />
              </div>
              <div className="space-y-1">
                <Label htmlFor="email">Email</Label>
                <Input id="email" type="email" value={form.email} onChange={e => setForm({ ...form, email: e.target.value })} required />
              </div>
              {!editing && (
                <div className="space-y-1">
                  <Label htmlFor="password">Password</Label>
                  <Input id="password" type="password" value={form.password} onChange={e => setForm({ ...form, password: e.target.value })} required minLength={8} />
                </div>
              )}
              <div className="space-y-1">
                <Label>Role</Label>
                <Select value={form.role} onValueChange={v => setForm({ ...form, role: v })}>
                  <SelectTrigger><SelectValue /></SelectTrigger>
                  <SelectContent>
                    {ROLES.map(r => <SelectItem key={r} value={r}>{r}</SelectItem>)}
                  </SelectContent>
                </Select>
              </div>
              {error && <p className="text-xs text-destructive">{error}</p>}
              <DialogFooter>
                <Button type="button" variant="outline" onClick={() => setDialogOpen(false)}>Cancel</Button>
                <Button type="submit" disabled={busy}>{busy ? 'Saving…' : (editing ? 'Save changes' : 'Create user')}</Button>
              </DialogFooter>
            </form>
          </DialogContent>
        </Dialog>

        <Dialog open={resetTarget !== null} onOpenChange={(open) => { if (!open) setResetTarget(null); }}>
          <DialogContent>
            <DialogHeader><DialogTitle>Reset Password for {resetTarget?.name}</DialogTitle></DialogHeader>
            <form onSubmit={async (e) => {
              e.preventDefault();
              if (resetPassword !== resetConfirm) return;
              setResetBusy(true);
              try {
                await api.put(`/api/admin/users/${resetTarget.id}/reset-password`, { password: resetPassword });
                setResetTarget(null);
                setResetPassword('');
                setResetConfirm('');
                setError('Password updated successfully');
              } catch (err) {
                setError(err.response?.data?.message || err.message);
              } finally {
                setResetBusy(false);
              }
            }} className="space-y-3">
              <div className="space-y-1">
                <Label htmlFor="reset-password">New Password</Label>
                <Input id="reset-password" type="password" value={resetPassword} onChange={e => setResetPassword(e.target.value)} required minLength={8} />
              </div>
              <div className="space-y-1">
                <Label htmlFor="reset-confirm">Confirm Password</Label>
                <Input id="reset-confirm" type="password" value={resetConfirm} onChange={e => setResetConfirm(e.target.value)} required />
              </div>
              {resetPassword && resetConfirm && resetPassword !== resetConfirm && (
                <p className="text-xs text-destructive">Passwords do not match</p>
              )}
              <DialogFooter>
                <Button type="button" variant="outline" onClick={() => { setResetTarget(null); setResetPassword(''); setResetConfirm(''); }}>Cancel</Button>
                <Button type="submit" disabled={resetBusy || resetPassword !== resetConfirm || !resetPassword}>Reset</Button>
              </DialogFooter>
            </form>
          </DialogContent>
        </Dialog>
      </div>

      {error && <p className="text-xs text-destructive">Failed to load: {error}</p>}

      {loading ? (
        <div className="py-16 text-center text-muted-foreground text-sm">
          <div className="animate-spin h-5 w-5 border-2 border-muted-foreground/30 border-t-muted-foreground rounded-full mx-auto mb-3" />
          Loading users…
        </div>
      ) : (
        <ResponsiveTable
          columns={[
            { key: 'name', header: 'Name', mobile: 'primary',
              renderCell: (u) => <span className="font-semibold text-foreground">{u.name}</span>,
            },
            { key: 'email', header: 'Email', mobile: 'label',
              renderCell: (u) => <span className="text-muted-foreground">{u.email}</span>,
            },
            { key: 'role', header: 'Role', mobile: 'label',
              renderCell: (u) => (
                <Badge variant="outline" className={cn('text-[9px]', u.role === 'admin' ? 'border-purple-500/30 text-purple-500' : u.role === 'instructor' ? 'border-blue-500/30 text-blue-500' : 'border-emerald-500/30 text-emerald-500')}>
                  {u.role === 'admin' ? <Shield className="mr-1 h-2.5 w-2.5" /> : <User className="mr-1 h-2.5 w-2.5" />}
                  {u.role}
                </Badge>
              ),
              renderMobileCell: (u) => <span className="capitalize">{u.role}</span>,
            },
            { key: 'joined', header: 'Joined', mobile: 'hidden',
              renderCell: (u) => <span className="text-muted-foreground">{u.created_at ? new Date(u.created_at).toLocaleDateString() : '—'}</span>,
            },
            { key: 'actions', header: 'Actions', mobile: 'actions',
              renderCell: (u) => (
                <div className="inline-flex gap-1 justify-center w-full">
                  <Button variant="ghost" size="sm" className="h-6 text-[9px]" onClick={(e) => { e.stopPropagation(); openEdit(u); }}><Pencil className="h-3 w-3" /></Button>
                  <Button variant="ghost" size="sm" className="h-6 text-[9px]" onClick={(e) => { e.stopPropagation(); setResetTarget(u); }}><KeyRound className="h-3 w-3" /></Button>
                  <Button variant="ghost" size="sm" className="h-6 text-[9px] text-destructive" onClick={(e) => { e.stopPropagation(); handleDelete(u); }}><Trash2 className="h-3 w-3" /></Button>
                </div>
              ),
              renderMobileCell: (u) => (
                <div className="flex gap-2 w-full">
                  <Button variant="outline" size="sm" className="flex-1 text-xs" onClick={(e) => { e.stopPropagation(); openEdit(u); }}>Edit</Button>
                  <Button variant="outline" size="sm" className="flex-1 text-xs" onClick={(e) => { e.stopPropagation(); setResetTarget(u); }}>Reset</Button>
                  <Button variant="ghost" size="sm" className="flex-1 text-xs text-destructive" onClick={(e) => { e.stopPropagation(); handleDelete(u); }}>Delete</Button>
                </div>
              ),
            },
          ]}
          data={filtered}
          keyExtractor={(u) => String(u.id)}
          emptyMessage="No users found."
        />
      )}
    </div>
  );
}
