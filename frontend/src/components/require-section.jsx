import { useNavigate } from 'react-router-dom';
import { Loader2 } from 'lucide-react';
import { useStudentContext } from '@/context/StudentContext';
import JoinSectionGate from '@/components/join-section-gate';
import SectionPickerPage from '@/components/SectionPickerPage';
import StudentDashboardShell from '@/components/student-dashboard-shell';

/**
 * RequireSection
 * Route-level gate for student tab pages. Enforces the product requirement
 * that a student with >=1 enrolled section must first see a full-page
 * section picker and pick a section BEFORE any of the tab pages
 * (Dashboard / Today / Exercises / Progress / Recommendations / CodeEditor)
 * become visible.
 *
 * Flow
 *   1. Sections still loading           → centered spinner
 *   2. No enrolled sections             → JoinSectionGate (join by code)
 *   3. Sections exist, none active      → SectionPickerPage (pick one)
 *   4. Active section set               → render the wrapped page
 */
export default function RequireSection({ children }) {
  const { sections, loading, activeSectionId, setActiveSectionId, recheck, hasSections } =
    useStudentContext();
  const navigate = useNavigate();

  if (loading) {
    return (
      <StudentDashboardShell>
        <div className="flex flex-col items-center justify-center py-24 gap-3">
          <Loader2 className="h-8 w-8 animate-spin text-muted-foreground" />
          <p className="text-sm text-muted-foreground">Loading your sections…</p>
        </div>
      </StudentDashboardShell>
    );
  }

  if (!hasSections) {
    return <JoinSectionGate onJoined={recheck} />;
  }

  if (activeSectionId === null || activeSectionId === undefined) {
    return (
      <SectionPickerPage
        sections={sections}
        onSelected={(section) => {
          setActiveSectionId(section.id);
          navigate('/student/dashboard', { replace: true });
        }}
      />
    );
  }

  return children;
}
