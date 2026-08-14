import { useState } from 'react';
import { useLocation, useNavigate } from 'react-router-dom';
import { Loader2 } from 'lucide-react';
import { useStudentContext } from '@/context/StudentContext';
import { useAuth } from '@/context/AuthContext';
import { Button } from '@/components/ui/button';
import SectionPickerPage from '@/components/SectionPickerPage';
import JoinSectionGate from '@/components/join-section-gate';

/**
 * SectionGatePage
 * Standalone (bare, no sidebar) entry page for students landing on
 * /student/select-section. Shows the Google Classroom-style class picker,
 * or the join-by-code gate when the student has no enrolled sections.
 *
 * Unlike RequireSection, this page NEVER clears the active section — it is
 * a navigation target (e.g. "All classes"), not a gate.
 */
export default function SectionGatePage() {
  const { sections, loading, error, hasSections, setActiveSectionId, recheck } = useStudentContext();
  const location = useLocation();
  const navigate = useNavigate();
  const { logout } = useAuth();
  const [join, setJoin] = useState(false);

  const handleLogout = async () => {
    await logout();
    navigate('/login', { replace: true });
  };

  if (loading) {
    return (
      <div className="mesh-bg noise-overlay flex min-h-dvh items-center justify-center bg-[#0B0F19]">
        <div className="flex flex-col items-center justify-center gap-3">
          <Loader2 className="h-8 w-8 animate-spin text-muted-foreground" />
          <p className="text-sm text-muted-foreground">Loading your classes…</p>
        </div>
      </div>
    );
  }

  if (error) {
    return (
      <div className="mesh-bg noise-overlay flex min-h-dvh items-center justify-center bg-[#0B0F19]">
        <div className="flex flex-col items-center justify-center gap-3 text-center">
          <h1 className="text-xl font-semibold text-foreground">Couldn't load your classes</h1>
          <p className="text-sm text-muted-foreground">Check your connection and try again.</p>
          <div className="mt-2 flex items-center gap-3">
            <Button onClick={recheck}>Retry</Button>
            <Button
              variant="ghost"
              size="sm"
              onClick={handleLogout}
              className="text-muted-foreground hover:text-foreground"
            >
              Logout
            </Button>
          </div>
        </div>
      </div>
    );
  }

  if (!hasSections) {
    return <JoinSectionGate onJoined={recheck} />;
  }

  if (!join) {
    return (
      <SectionPickerPage
        sections={sections}
        onJoin={() => setJoin(true)}
        onSelected={(s) => {
          setActiveSectionId(s.id);
          navigate(location.state?.from ?? '/student/dashboard', { replace: true });
        }}
      />
    );
  }

  return <JoinSectionGate onJoined={recheck} onBack={() => setJoin(false)} />;
}
