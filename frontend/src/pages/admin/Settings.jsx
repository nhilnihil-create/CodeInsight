import { useState, useEffect } from 'react';
import api from '../../services/api';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Input } from '@/components/ui/input';
import PageBreadcrumb from '@/components/ui/page-breadcrumb';
import { toast } from 'sonner';

export default function AdminSettings() {
  const [settings, setSettings] = useState([]);
  const [loading, setLoading] = useState(true);
  const [busy, setBusy] = useState(null);
  const [error, setError] = useState(null);

  const load = async () => {
    setLoading(true);
    setError(null);
    try {
      const res = await api.get('/api/admin/settings');
      setSettings(res.data.settings || []);
    } catch (err) {
      setError(err.response?.data?.message || err.message);
    } finally {
      setLoading(false);
    }
  };

  useEffect(() => { load(); }, []);

  const handleSave = async (key, rawValue) => {
    setBusy(key);
    try {
      const value = isNaN(Number(rawValue)) ? rawValue : Number(rawValue);
      await api.put('/api/admin/settings', { key, value });
      toast.success(key + ' updated');
      await load();
    } catch (err) {
      toast.error(err.response?.data?.message || err.message);
    } finally {
      setBusy(null);
    }
  };

  return (
    <div className="space-y-6">
      <PageBreadcrumb crumbs={[{ label: 'Admin', href: '/admin' }, { label: 'Settings' }]} />
      <Card>
        <CardHeader><CardTitle>System Settings</CardTitle></CardHeader>
        <CardContent>
          {error && <p className="text-destructive text-sm mb-4">Failed to load: {error}</p>}
          {loading ? (
            <p className="text-muted-foreground text-sm">Loading settings...</p>
          ) : (
            <div className="space-y-4">
              {settings.map(s => (
                <SettingRow key={s.key} setting={s} busy={busy} onSave={handleSave} />
              ))}
            </div>
          )}
        </CardContent>
      </Card>
    </div>
  );
}

function SettingRow({ setting, busy, onSave }) {
  const [value, setValue] = useState(String(setting.value));
  useEffect(() => { setValue(String(setting.value)); }, [setting.value]);
  const isNumber = !isNaN(Number(setting.value));
  const group = setting.key.split('.')[0];

  return (
    <div className="flex items-center justify-between gap-4 p-3 rounded-lg border border-border hover:bg-muted/20">
      <div className="min-w-0 flex-1">
        <p className="text-xs font-mono font-medium">{setting.key}</p>
        {setting.description && (
          <p className="text-[10px] text-muted-foreground mt-0.5">{setting.description}</p>
        )}
      </div>
      <div className="flex items-center gap-2 shrink-0">
        <Input
          value={value}
          onChange={e => setValue(e.target.value)}
          type={isNumber ? 'number' : 'text'}
          className="h-8 w-24 text-xs font-mono text-right"
          step={isNumber && setting.value < 1 ? '0.01' : undefined}
        />
        <Button
          size="sm"
          className="h-8 text-xs"
          onClick={() => onSave(setting.key, value)}
          disabled={busy === setting.key}
        >
          {busy === setting.key ? 'Saving...' : 'Save'}
        </Button>
      </div>
    </div>
  );
}
