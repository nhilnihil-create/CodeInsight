import { useNavigate } from 'react-router-dom';
import { motion } from 'framer-motion';
import { Layers, Plus, LogOut } from 'lucide-react';
import { useAuth } from '@/context/AuthContext';
import { Button } from '@/components/ui/button';

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
    <div className="mesh-bg noise-overlay min-h-screen bg-[#0B0F19] text-foreground">
      <div className="relative z-10 mx-auto max-w-6xl px-6 py-8">
        {/* Top bar */}
        <div className="flex items-center justify-between gap-4 mb-8">
          <div className="flex items-center gap-3">
            <div className="h-10 w-10 rounded-full bg-gradient-to-br from-teal-400 to-emerald-500 flex items-center justify-center">
              <Layers className="h-5 w-5 text-slate-950" strokeWidth={2} />
            </div>
            <div>
              <h1 className="text-lg font-semibold tracking-tight">My Classes</h1>
              <p className="text-xs text-muted-foreground">
                {sections.length} class{sections.length !== 1 ? 'es' : ''} · pick one to continue
              </p>
            </div>
          </div>
          <div className="flex items-center gap-2">
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
        <div className="grid gap-5 sm:grid-cols-2 lg:grid-cols-3">
          {sections.map((section) => (
            <motion.button
              key={section.id}
              type="button"
              onClick={() => onSelected(section)}
              whileHover={{ scale: 1.015, borderColor: "rgba(255,255,255,0.12)" }}
              transition={{ type: "spring", stiffness: 400, damping: 25 }}
              className="group relative overflow-hidden rounded-2xl border border-white/[0.06] bg-white/[0.02] backdrop-blur-xl text-left transition-colors duration-200 hover:bg-white/[0.04] focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-ring"
            >
              {/* Gradient banner header */}
              <div className="h-24 bg-gradient-to-r from-teal-500/80 to-emerald-500/80 flex items-end px-5 pb-3">
                <span className="text-sm font-semibold text-slate-950 truncate">
                  {section.name || section.course_code || `Section ${section.id}`}
                </span>
              </div>
              <div className="px-5 py-4 space-y-1">
                {(section.course_code || section.term) && (
                  <p className="text-xs font-mono text-muted-foreground/70 truncate">
                    {[section.course_code, section.term].filter(Boolean).join(' · ')}
                  </p>
                )}
                <p className="text-xs text-muted-foreground/50">Open class</p>
              </div>
            </motion.button>
          ))}
        </div>
      </div>
    </div>
  );
}
