import { useLocation, Navigate } from 'react-router-dom';
import { Loader2 } from 'lucide-react';
import { useStudentContext } from '@/context/StudentContext';
import { Button } from '@/components/ui/button';
import StudentDashboardShell from '@/components/student-dashboard-shell';

/**
 * RequireSection
 * Route-level gate for student tab pages. Enforces the product requirement
 * that a student with >=1 enrolled section must first pick a section
 * BEFORE any of the tab pages (Dashboard / Today / Exercises / Progress /
 * Recommendations / CodeEditor) become visible.
 *
 * Flow
 *   1. Sections still loading           → centered spinner
 *   2. Last recheck failed              → error screen with Retry
 *   3. No enrolled sections             → redirect to the section gate
 *   4. Sections exist, none active      → redirect to the section gate
 *   5. Active section set               → render the wrapped page
 *
 * The redirect carries the original location in state.from so the section
 * picker can return the student where they were headed.
 */
export default function RequireSection({ children }) {
  const { loading, error, activeSectionId, hasSections, recheck } = useStudentContext();
  const location = useLocation();

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

  if (error) {
    return (
      <StudentDashboardShell>
        <div className="flex flex-col items-center justify-center py-24 gap-3 text-center">
          <h1 className="text-xl font-semibold text-foreground">Couldn't load your classes</h1>
          <p className="text-sm text-muted-foreground">Check your connection and try again.</p>
          <div className="mt-2">
            <Button onClick={recheck}>Retry</Button>
          </div>
        </div>
      </StudentDashboardShell>
    );
  }

  if (!hasSections || activeSectionId === null || activeSectionId === undefined) {
    return (
      <Navigate
        to="/student/select-section"
        replace
        state={{ from: location.pathname + location.search }}
      />
    );
  }

  return children;
}
