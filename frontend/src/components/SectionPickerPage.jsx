import { useNavigate } from 'react-router-dom';
import { motion } from 'framer-motion';
import { Layers, Plus, LogOut, BookOpen, Hash, Calendar, ChevronRight } from 'lucide-react';
import { useAuth } from '@/context/AuthContext';
import { Button } from '@/components/ui/button';

/* ── Stagger config ─────────────────────────────────────────────── */
const stagger = {
  hidden: {},
  show: { transition: { staggerChildren: 0.07, delayChildren: 0.1 } },
};

const fadeUp = {
  hidden: { opacity: 0, y: 12 },
  show: { opacity: 1, y: 0, transition: { duration: 0.45, ease: [0.25, 0.46, 0.45, 0.94] } },
};

function termOf(section) {
  const sem = section.semester || section.term || '';
  const year = section.school_year || '';
  return [sem, year].filter(Boolean).join(' · ');
}

/**
 * SectionPickerPage
 * Standalone Google Classroom-style home for students. Shown by
 * SectionGatePage when the student has enrolled sections but no active
 * one picked yet — pick a class to enter it.
 *
 * Props
 *   - sections    Array of enrolled sections ({ id, name, course_code, term })
 *   - onSelected  (section) => void — called when a class card is clicked
 *   - onJoin      () => void — called when "+ Join class" is clicked
 */
export default function SectionPickerPage({ sections, onSelected, onJoin }) {
  const { logout } = useAuth();
  const navigate = useNavigate();

  const handleLogout = async () => {
    await logout();
    navigate('/login', { replace: true });
  };

  return (
    <div className="mesh-bg noise-overlay min-h-dvh bg-[#0B0F19] text-foreground">
      <div className="relative z-10 mx-auto max-w-6xl px-6 py-8">
        {/* Top bar */}
        <div className="flex flex-col gap-4 mb-8 sm:flex-row sm:items-center sm:justify-between">
          <div className="flex items-center gap-3 min-w-0">
            <div className="h-11 w-11 shrink-0 rounded-xl bg-gradient-to-br from-teal-400 to-emerald-500 flex items-center justify-center shadow-[0_0_24px_rgba(45,212,191,0.25)]">
              <Layers className="h-5 w-5 text-slate-950" strokeWidth={2} />
            </div>
            <div className="min-w-0">
              <h1 className="text-xl font-semibold tracking-tight">My Classes</h1>
              <p className="text-xs text-muted-foreground truncate">
                {sections.length} class{sections.length !== 1 ? 'es' : ''} · pick one to continue
              </p>
            </div>
          </div>
          <div className="flex items-center gap-2 shrink-0">
            <Button
              onClick={onJoin}
              size="sm"
              className="bg-gradient-to-r from-teal-400 to-emerald-500 text-slate-950 font-semibold hover:shadow-[0_0_24px_rgba(45,212,191,0.4)] transition-shadow duration-300"
            >
              <Plus className="h-4 w-4 mr-1" strokeWidth={2} />
              Join class
            </Button>
            <Button
              variant="ghost"
              size="sm"
              onClick={handleLogout}
              className="text-muted-foreground hover:text-foreground"
            >
              <LogOut className="h-4 w-4 mr-1.5" strokeWidth={2} />
              Logout
            </Button>
          </div>
        </div>

        {/* Class cards */}
        {sections.length > 0 ? (
          <motion.div variants={stagger} initial="hidden" animate="show" className="grid gap-4 sm:grid-cols-2 lg:grid-cols-3">
            {sections.map((section) => {
              const title = section.name || section.course_code || `Section ${section.id}`;
              const term = termOf(section);
              return (
                <motion.button
                  key={section.id}
                  type="button"
                  onClick={() => onSelected(section)}
                  variants={fadeUp}
                  whileHover={{ scale: 1.015 }}
                  whileTap={{ scale: 0.985 }}
                  transition={{ type: "spring", stiffness: 400, damping: 25 }}
                  className="group relative overflow-hidden rounded-2xl border border-white/[0.06] bg-white/[0.02] backdrop-blur-xl text-left transition-colors duration-200 hover:border-teal-400/30 hover:bg-white/[0.04] focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-ring"
                >
                  {/* Top accent */}
                  <div className="h-px w-full bg-gradient-to-r from-transparent via-teal-400/40 to-transparent opacity-0 group-hover:opacity-100 transition-opacity duration-300" />

                  <div className="flex items-center gap-3.5 px-4 py-4 sm:px-5">
                    {/* Gradient icon */}
                    <div className="h-11 w-11 shrink-0 rounded-xl bg-gradient-to-br from-teal-400/20 to-emerald-500/20 border border-teal-400/20 flex items-center justify-center">
                      <BookOpen className="h-5 w-5 text-teal-400" strokeWidth={1.5} />
                    </div>

                    {/* Info */}
                    <div className="min-w-0 flex-1">
                      <p className="text-sm font-semibold text-foreground truncate">{title}</p>
                      <div className="flex flex-wrap items-center gap-x-2.5 gap-y-0.5 mt-0.5">
                        {section.course_code && (
                          <span className="inline-flex items-center gap-1 text-[11px] text-muted-foreground/70">
                            <Hash className="h-3 w-3" strokeWidth={1.5} />
                            {section.course_code}
                          </span>
                        )}
                        {term && (
                          <span className="inline-flex items-center gap-1 text-[11px] text-muted-foreground/70">
                            <Calendar className="h-3 w-3" strokeWidth={1.5} />
                            {term}
                          </span>
                        )}
                      </div>
                    </div>

                    {/* Enter affordance */}
                    <ChevronRight
                      className="h-4 w-4 shrink-0 text-muted-foreground/40 transition-all duration-200 group-hover:text-teal-400 group-hover:translate-x-0.5"
                      strokeWidth={1.5}
                    />
                  </div>
                </motion.button>
              );
            })}
          </motion.div>
        ) : (
          <div className="rounded-2xl border border-white/[0.06] bg-white/[0.02] backdrop-blur-xl py-16 text-center">
            <p className="text-sm text-muted-foreground">No classes yet — join one to get started.</p>
          </div>
        )}
      </div>
    </div>
  );
}
