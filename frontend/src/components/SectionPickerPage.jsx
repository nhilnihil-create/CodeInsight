import { Link } from 'react-router-dom';
import { Layers, ChevronRight, ArrowRight } from 'lucide-react';
import StudentDashboardShell from '@/components/student-dashboard-shell';
import { Button } from '@/components/ui/button';

/**
 * SectionPickerPage
 * Full-page entry point for students who are enrolled in sections but have
 * not picked an active one yet. Shown by RequireSection BEFORE the student
 * tabs (My Exercises / My Progress / My Profile) become visible.
 *
 * Props
 *   - sections    Array of enrolled sections ({ id, name, code, term })
 *   - onSelected  (section) => void — called when a card is clicked
 */
export default function SectionPickerPage({ sections, onSelected }) {
  const count = sections.length;

  return (
    <StudentDashboardShell>
      <div className="flex flex-col items-center justify-center py-16 px-6">
        <div className="w-full max-w-md space-y-6 text-center">
          <div className="mx-auto h-14 w-14 rounded-full bg-gradient-to-br from-teal-400 to-emerald-500 flex items-center justify-center">
            <Layers className="h-6 w-6 text-slate-950" strokeWidth={2} />
          </div>
          <div className="space-y-2">
            <h1 className="text-xl font-semibold text-foreground">Select a Section</h1>
            <p className="text-sm text-muted-foreground">
              You are enrolled in {count} section{count !== 1 ? 's' : ''} — pick one to view its exercises and progress.
            </p>
          </div>

          <div className="space-y-3 text-left">
            {sections.map((section) => (
              <button
                key={section.id}
                type="button"
                onClick={() => onSelected(section)}
                className="w-full flex items-center justify-between gap-3 rounded-2xl border border-white/[0.06] bg-white/[0.02] backdrop-blur-xl px-5 py-4 text-left transition-colors duration-200 hover:bg-white/[0.04] hover:border-white/[0.12] focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-ring"
              >
                <div className="min-w-0">
                  <p className="text-sm font-semibold text-foreground truncate">
                    {section.name || section.course_code || `Section ${section.id}`}
                  </p>
                  <p className="mt-0.5 text-xs font-mono text-muted-foreground/70 truncate">
                    {section.code || section.course_code || `#${section.id}`}
                    {section.term ? ` · ${section.term}` : ''}
                  </p>
                </div>
                <ChevronRight className="h-4 w-4 text-muted-foreground/40 shrink-0" strokeWidth={1.5} aria-hidden="true" />
              </button>
            ))}
          </div>

          <div className="pt-1">
            <Button asChild variant="outline" size="sm">
              <Link
                to="/student/sections"
                className="inline-flex items-center gap-1.5 text-sm text-muted-foreground transition-colors hover:text-foreground"
              >
                Join another section
                <ArrowRight className="h-3.5 w-3.5" strokeWidth={2} aria-hidden="true" />
              </Link>
            </Button>
          </div>
        </div>
      </div>
    </StudentDashboardShell>
  );
}
