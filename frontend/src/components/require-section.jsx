import { useLocation, Navigate } from 'react-router-dom';
import { Loader2 } from 'lucide-react';
import { useStudentContext } from '@/context/StudentContext';
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
 *   2. No enrolled sections             → redirect to the section gate
 *   3. Sections exist, none active      → redirect to the section gate
 *   4. Active section set               → render the wrapped page
 *
 * The redirect carries the original location in state.from so the section
 * picker can return the student where they were headed.
 */
export default function RequireSection({ children }) {
  const { loading, activeSectionId, hasSections } = useStudentContext();
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
