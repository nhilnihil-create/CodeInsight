import { useState } from 'react';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Input } from '@/components/ui/input';
import { Badge } from '@/components/ui/badge';
import StudentDashboardShell from '@/components/student-dashboard-shell';
import api from '@/services/api';
import { toast } from 'sonner';
import { Loader2 } from 'lucide-react';
import { useStudentContext } from '@/context/StudentContext';

function getJoinErrorMessage(error) {
  const status = error.response?.status;
  const data = error.response?.data;

  if (status === 404) return 'Invalid join code. Please check the code and try again.';
  if (status === 403) {
    if (data?.error?.includes('full')) return 'This section is full. Contact your instructor for availability.';
    if (data?.error?.includes('closed')) return 'This section is not accepting new students at this time.';
    return 'You cannot join this section.';
  }
  if (status === 409) return 'You are already enrolled in this section.';
  if (status === 401) return 'Please log in to join a section.';
  return data?.error || data?.message || 'Failed to join section. Please try again.';
}

function formatJoinCode(value) {
  const cleaned = value.toUpperCase().replace(/[^A-Z0-9]/g, '');
  if (cleaned.length > 3) {
    return cleaned.slice(0, 3) + '-' + cleaned.slice(3, 6);
  }
  return cleaned;
}

export default function StudentSections() {
  const { sections, recheck } = useStudentContext();
  const visibleSections = (Array.isArray(sections) ? sections : []).filter(s => !s.is_archived);
  const [joinCode, setJoinCode] = useState('');
  const [joining, setJoining] = useState(false);
  const [leavingId, setLeavingId] = useState(null);
  const [error, setError] = useState(null);

  const handleJoin = async () => {
    setError(null);
    setJoining(true);
    try {
      await api.post('/api/sections/join', { code: joinCode });
      toast.success('Successfully joined the section!');
      setJoinCode('');
      await recheck();
    } catch (err) {
      const msg = getJoinErrorMessage(err);
      toast.error(msg);
      setError(msg);
    } finally {
      setJoining(false);
    }
  };

  const handleLeave = async (section) => {
    if (!window.confirm(`Leave "${section.name}"? You can rejoin anytime with the section code.`)) return;
    setLeavingId(section.id);
    try {
      await api.post(`/api/sections/${section.id}/leave`);
      toast.success(`You left ${section.name}`);
      await recheck();
    } catch (err) {
      toast.error(err.response?.status === 404 ? 'This section is no longer active for you.' : err.response?.data?.error || 'Failed to leave section.');
    } finally {
      setLeavingId(null);
    }
  };

  const handleCodeChange = (e) => {
    const formatted = formatJoinCode(e.target.value);
    setJoinCode(formatted);
    setError(null);
  };

  return (
    <StudentDashboardShell
      breadcrumb={[
        { label: 'Student', href: '/student/dashboard' },
        { label: 'My Sections' },
      ]}
      subtitle="View and manage your enrolled sections."
    >
      {visibleSections.length === 0 ? (
        <Card>
          <CardContent className="p-6 text-center text-muted-foreground">
            You're not enrolled in any sections yet. Join one below!
          </CardContent>
        </Card>
      ) : (
        visibleSections.map(section => (
          <Card key={section.id}>
            <CardContent className="p-4 flex items-center justify-between">
              <div>
                <h3 className="font-semibold">{section.name}</h3>
                <p className="text-xs text-muted-foreground font-mono">
                  {section.code} &middot; {section.term || 'Active'}
                </p>
              </div>
              <div className="flex items-center gap-2">
                <Badge variant="outline" className="text-xs">Active</Badge>
                <Button
                  variant="outline"
                  size="sm"
                  disabled={leavingId === section.id}
                  onClick={() => handleLeave(section)}
                  className="text-destructive hover:text-destructive"
                >
                  {leavingId === section.id ? (
                    <>
                      <Loader2 className="mr-1.5 h-3.5 w-3.5 animate-spin" />
                      Leaving...
                    </>
                  ) : (
                    'Leave'
                  )}
                </Button>
              </div>
            </CardContent>
          </Card>
        ))
      )}

      <Card>
        <CardHeader>
          <CardTitle className="text-sm">Join Another Section</CardTitle>
        </CardHeader>
        <CardContent className="space-y-3">
          {error && <p className="text-sm text-destructive">{error}</p>}
          <p className="text-xs text-muted-foreground">
            Enter the 6-character code provided by your instructor.
          </p>
          <div className="flex gap-2">
            <Input
              placeholder="e.g. K7P-3QX"
              value={joinCode}
              onChange={handleCodeChange}
              maxLength={7}
              disabled={joining}
              className="font-mono w-40"
            />
            <Button size="sm" disabled={joinCode.length < 7 || joining} onClick={handleJoin}>
              {joining ? (
                <>
                  <Loader2 className="mr-1.5 h-3.5 w-3.5 animate-spin" />
                  Joining...
                </>
              ) : (
                'Join'
              )}
            </Button>
          </div>
        </CardContent>
      </Card>
    </StudentDashboardShell>
  );
}
