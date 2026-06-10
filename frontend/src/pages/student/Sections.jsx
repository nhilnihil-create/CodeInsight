import { useState, useEffect } from 'react';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Input } from '@/components/ui/input';
import { Badge } from '@/components/ui/badge';
import StudentDashboardShell from '@/components/student-dashboard-shell';
import api from '@/services/api';

export default function StudentSections() {
  const [sections, setSections] = useState([]);
  const [joinCode, setJoinCode] = useState('');
  const [joining, setJoining] = useState(false);
  const [error, setError] = useState(null);
  const [success, setSuccess] = useState(null);

  useEffect(() => {
    let cancelled = false;
    const load = async () => {
      try {
        const res = await api.get('/api/sections');
        if (!cancelled) {
          const all = Array.isArray(res.data) ? res.data : [];
          setSections(all.filter(s => !s.is_archived));
        }
      } catch {
        if (!cancelled) setSections([]);
      }
    };
    load();
    return () => { cancelled = true; };
  }, []);

  const handleJoin = async () => {
    setError(null);
    setSuccess(null);
    setJoining(true);
    try {
      await api.post('/api/sections/join', { code: joinCode });
      setSuccess('Successfully joined the section!');
      setJoinCode('');
      // Refresh sections
      const res = await api.get('/api/sections');
      const all = Array.isArray(res.data) ? res.data : [];
      setSections(all.filter(s => !s.is_archived));
    } catch (err) {
      setError(err.response?.data?.error || err.response?.data?.message || 'Failed to join section');
    } finally {
      setJoining(false);
    }
  };

  return (
    <StudentDashboardShell
      breadcrumb={[
        { label: 'Student', href: '/student/dashboard' },
        { label: 'My Sections' },
      ]}
      subtitle="View and manage your enrolled sections."
    >
      {sections.length === 0 ? (
        <Card>
          <CardContent className="p-6 text-center text-muted-foreground">
            You're not enrolled in any sections yet. Join one below!
          </CardContent>
        </Card>
      ) : (
        sections.map(section => (
          <Card key={section.id}>
            <CardContent className="p-4 flex items-center justify-between">
              <div>
                <h3 className="font-semibold">{section.name}</h3>
                <p className="text-xs text-muted-foreground font-mono">
                  {section.code} &middot; {section.term || 'Active'}
                </p>
              </div>
              <Badge variant="outline" className="text-xs">Active</Badge>
            </CardContent>
          </Card>
        ))
      )}

      <Card>
        <CardHeader>
          <CardTitle className="text-sm">Join Another Section</CardTitle>
        </CardHeader>
        <CardContent className="space-y-3">
          {success && <p className="text-sm text-green-600">{success}</p>}
          {error && <p className="text-sm text-destructive">{error}</p>}
          <p className="text-xs text-muted-foreground">
            Enter the 6-character code provided by your instructor.
          </p>
          <div className="flex gap-2">
            <Input
              placeholder="e.g. K7P-3QX"
              value={joinCode}
              onChange={e => setJoinCode(e.target.value.toUpperCase())}
              maxLength={7}
              className="font-mono w-40"
            />
            <Button size="sm" disabled={joinCode.length < 7 || joining} onClick={handleJoin}>
              {joining ? 'Joining...' : 'Join'}
            </Button>
          </div>
        </CardContent>
      </Card>
    </StudentDashboardShell>
  );
}
