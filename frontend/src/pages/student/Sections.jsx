import { useState } from 'react';
import { motion } from 'framer-motion';
import { Link } from 'react-router-dom';
import {
  BookOpen,
  LogOut,
  Plus,
  ArrowRight,
  CheckCircle,
  AlertCircle,
  Hash,
  Calendar,
} from 'lucide-react';
import { Button } from '@/components/ui/button';
import { Input } from '@/components/ui/input';
import { Badge } from '@/components/ui/badge';
import StudentDashboardShell from '@/components/student-dashboard-shell';
import GlassPanel, {
  GlassPanelHeader,
  GlassPanelTitle,
  GlassPanelContent,
} from '@/components/ui/glass-panel';
import EmptyState from '@/components/ui/empty-state';
import api from '@/services/api';
import { toast } from 'sonner';
import { cn } from '@/lib/utils';
import { useStudentContext } from '@/context/StudentContext';

/* ── Stagger config ──────────────────────────────────────────────── */
const stagger = {
  hidden: {},
  show: { transition: { staggerChildren: 0.07, delayChildren: 0.1 } },
};

const fadeUp = {
  hidden: { opacity: 0, y: 12 },
  show: { opacity: 1, y: 0, transition: { duration: 0.5, ease: [0.25, 0.46, 0.45, 0.94] } },
};

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
      if (err.response?.status === 409) {
        toast.success(getJoinErrorMessage(err));
        setJoinCode('');
        setError(null);
        await recheck();
      } else {
        const msg = getJoinErrorMessage(err);
        toast.error(msg);
        setError(msg);
      }
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
      <motion.div variants={stagger} initial="hidden" animate="show" className="space-y-5">
        {/* ═══════════════════════════════════════════════════════════
            PAGE HEADER
           ═══════════════════════════════════════════════════════════ */}
        <motion.header variants={fadeUp} className="flex items-center justify-between gap-3">
          <div className="min-w-0 space-y-0.5">
            <h1 className="text-2xl font-semibold tracking-tight text-foreground">
              My Sections
            </h1>
            <p className="text-xs text-muted-foreground/60 sm:text-sm">
              {visibleSections.length === 0
                ? 'No sections yet — join one below'
                : `${visibleSections.length} enrolled section${visibleSections.length !== 1 ? 's' : ''}`}
            </p>
          </div>
        </motion.header>

        {/* ═══════════════════════════════════════════════════════════
            ENROLLED SECTIONS
           ═══════════════════════════════════════════════════════════ */}
        {visibleSections.length > 0 ? (
          <motion.div variants={fadeUp} className="space-y-3">
            {visibleSections.map((section) => (
              <motion.div
                key={section.id}
                variants={fadeUp}
                className="group"
              >
                <GlassPanel interactive>
                  <div className="relative overflow-hidden">
                    {/* Subtle gradient accent at top */}
                    <div className="absolute top-0 inset-x-0 h-px bg-gradient-to-r from-transparent via-teal-400/40 to-transparent opacity-0 group-hover:opacity-100 transition-opacity duration-300" />

                    <div className="flex items-center gap-4 px-5 py-4">
                      {/* Section icon */}
                      <div className="flex h-10 w-10 shrink-0 items-center justify-center rounded-xl bg-gradient-to-br from-teal-400/20 to-emerald-500/20 border border-teal-400/20">
                        <BookOpen className="h-5 w-5 text-teal-400" strokeWidth={1.5} />
                      </div>

                      {/* Section info */}
                      <div className="min-w-0 flex-1">
                        <div className="flex items-center gap-2.5 min-w-0">
                          <h3 className="text-sm font-semibold text-foreground truncate">
                            {section.name}
                          </h3>
                          <Badge
                            variant="outline"
                            className="shrink-0 text-[10px] font-mono uppercase tracking-wider bg-emerald-500/10 text-emerald-400 border-emerald-500/20"
                          >
                            <CheckCircle className="h-2.5 w-2.5 mr-1" />
                            Active
                          </Badge>
                        </div>
                        <div className="flex items-center gap-3 mt-1">
                          {section.course_code && (
                            <span className="inline-flex items-center gap-1 text-[11px] text-muted-foreground/60">
                              <Hash className="h-3 w-3" strokeWidth={1.5} />
                              {section.course_code}
                            </span>
                          )}
                          {section.term && (
                            <span className="inline-flex items-center gap-1 text-[11px] text-muted-foreground/60">
                              <Calendar className="h-3 w-3" strokeWidth={1.5} />
                              {section.term}
                            </span>
                          )}
                        </div>
                      </div>

                      {/* Actions */}
                      <div className="flex items-center gap-2 shrink-0">
                        <motion.div whileHover={{ scale: 1.03 }} whileTap={{ scale: 0.97 }}>
                          <Button
                            asChild
                            size="sm"
                            className="bg-gradient-to-r from-teal-400 to-emerald-500 text-slate-950 font-semibold border-0 hover:shadow-[0_0_24px_rgba(45,212,191,0.4)] transition-shadow duration-300"
                          >
                            <Link to={`/student/dashboard?section=${section.id}`}>
                              Enter
                              <ArrowRight className="ml-1.5 h-3.5 w-3.5" strokeWidth={2} />
                            </Link>
                          </Button>
                        </motion.div>
                        <Button
                          variant="ghost"
                          size="icon"
                          disabled={leavingId === section.id}
                          onClick={() => handleLeave(section)}
                          className="h-8 w-8 text-muted-foreground/50 hover:text-destructive hover:bg-destructive/10 transition-colors"
                          title={`Leave ${section.name}`}
                        >
                          {leavingId === section.id ? (
                            <div className="h-3.5 w-3.5 animate-spin rounded-full border-2 border-current border-t-transparent" />
                          ) : (
                            <LogOut className="h-3.5 w-3.5" strokeWidth={1.5} />
                          )}
                        </Button>
                      </div>
                    </div>
                  </div>
                </GlassPanel>
              </motion.div>
            ))}
          </motion.div>
        ) : (
          <motion.div variants={fadeUp}>
            <div className="rounded-2xl border border-white/[0.06] bg-white/[0.02] backdrop-blur-xl py-12">
              <EmptyState
                icon={<BookOpen />}
                title="No sections yet"
                description="Join a section using the code from your instructor to get started."
              />
            </div>
          </motion.div>
        )}

        {/* ═══════════════════════════════════════════════════════════
            JOIN SECTION
           ═══════════════════════════════════════════════════════════ */}
        <motion.section variants={fadeUp}>
          <GlassPanel interactive>
            <GlassPanelHeader>
              <div className="flex items-center gap-2">
                <GlassPanelTitle>Join a Section</GlassPanelTitle>
                <span className="text-[10px] font-mono uppercase tracking-wider text-muted-foreground/50">
                  New
                </span>
              </div>
              <div className="flex items-center gap-1.5 text-[11px] text-muted-foreground/50">
                <Plus className="h-3 w-3" strokeWidth={1.5} />
                Enter code
              </div>
            </GlassPanelHeader>
            <GlassPanelContent>
              {error && (
                <div className="flex items-center gap-2 px-3 py-2 mb-3 rounded-lg bg-destructive/10 border border-destructive/20">
                  <AlertCircle className="h-3.5 w-3.5 text-destructive shrink-0" />
                  <p className="text-xs text-destructive">{error}</p>
                </div>
              )}
              <p className="text-xs text-muted-foreground/50 mb-3">
                Enter the 6-character code provided by your instructor.
              </p>
              <div className="flex gap-2">
                <Input
                  placeholder="e.g. K7P-3QX"
                  value={joinCode}
                  onChange={handleCodeChange}
                  maxLength={7}
                  disabled={joining}
                  className="font-mono text-sm h-9 bg-white/[0.03] border-white/[0.08] focus:border-teal-400/50 focus:ring-teal-400/20 placeholder:text-muted-foreground/30"
                />
                <motion.div whileHover={{ scale: 1.02 }} whileTap={{ scale: 0.98 }}>
                  <Button
                    size="sm"
                    disabled={joinCode.length < 7 || joining}
                    onClick={handleJoin}
                    className={cn(
                      "h-9 px-4 font-semibold transition-all duration-300",
                      joinCode.length >= 7 && !joining
                        ? "bg-gradient-to-r from-teal-400 to-emerald-500 text-slate-950 border-0 hover:shadow-[0_0_24px_rgba(45,212,191,0.4)]"
                        : ""
                    )}
                  >
                    {joining ? (
                      <div className="h-3.5 w-3.5 animate-spin rounded-full border-2 border-current border-t-transparent" />
                    ) : (
                      'Join'
                    )}
                  </Button>
                </motion.div>
              </div>
            </GlassPanelContent>
          </GlassPanel>
        </motion.section>
      </motion.div>
    </StudentDashboardShell>
  );
}
