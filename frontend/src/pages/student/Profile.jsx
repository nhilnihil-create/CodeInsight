import { useState, useEffect } from 'react';
import { motion } from 'framer-motion';
import { cn } from '@/lib/utils';
import { NEW_TIER_META } from '@/components/ui/mastery-bar';
import StudentDashboardShell from '@/components/student-dashboard-shell';
import GlassPanel, {
  GlassPanelHeader,
  GlassPanelTitle,
  GlassPanelContent,
} from '@/components/ui/glass-panel';
import ConceptRadarPanel from '@/components/concept-radar/ConceptRadarPanel';
import JoinSectionGate from '@/components/join-section-gate';
import useHasSections from '@/hooks/useHasSections';
import api from '../../services/api';

/* ── Stagger config ──────────────────────────────────────────────── */
const stagger = {
  hidden: {},
  show: { transition: { staggerChildren: 0.07, delayChildren: 0.1 } },
};

const fadeUp = {
  hidden: { opacity: 0, y: 12 },
  show: { opacity: 1, y: 0, transition: { duration: 0.5, ease: [0.25, 0.46, 0.45, 0.94] } },
};

const TIER_LEGEND = [
  { tier: 'excellent', dot: 'bg-slate-500', range: '85%–100%', desc: 'Solid code structure with nominal compilation regressions.' },
  { tier: 'nominal', dot: 'bg-emerald-500', range: '65%–84%', desc: 'Grasping core logic with expected trial-and-error corrections.' },
  { tier: 'moderate', dot: 'bg-amber-500', range: '45%–64%', desc: 'Encountering minor structural roadblocks; review materials recommended.' },
  { tier: 'significant', dot: 'bg-orange-500', range: '25%–44%', desc: 'High error density patterns detected. Code structure needs direct reinforcement.' },
  { tier: 'critical', dot: 'bg-red-500', range: '0%–24%', desc: 'Stuck in severe compilation or logic loops. Immediate instructor assistance recommended.' },
];

export default function StudentProfile() {
  const { hasSections, checking, recheck } = useHasSections();
  const [scores, setScores] = useState([]);
  const [loading, setLoading] = useState(true);
  const [fetchKey, setFetchKey] = useState(0);

  useEffect(() => {
    if (hasSections === null || !hasSections) return;
    let active = true;
    const load = async () => {
      try {
        const res = await api.get('/api/analytics/my-scores');
        if (active) setScores(res.data || []);
      } catch (err) {
      } finally {
        if (active) setLoading(false);
      }
    };
    load();
    const t = setInterval(load, 5000);
    return () => {
      active = false;
      clearInterval(t);
    };
  }, [hasSections, fetchKey]);

  const handleJoined = () => {
    recheck();
    setFetchKey((k) => k + 1);
  };

  if (checking) {
    return (
      <StudentDashboardShell
        breadcrumb={[
          { label: 'Student', href: '/student/dashboard' },
          { label: 'My Concept Profile' },
        ]}
        subtitle="Concept mastery and difficulty scores across programming topics."
      >
        <div className="py-16 text-center text-muted-foreground/60 text-sm">Loading profile...</div>
      </StudentDashboardShell>
    );
  }

  if (!hasSections) {
    return <JoinSectionGate onJoined={handleJoined} />;
  }

  return (
    <StudentDashboardShell
      breadcrumb={[
        { label: 'Student', href: '/student/dashboard' },
        { label: 'My Concept Profile' },
      ]}
      subtitle="Concept mastery and difficulty scores across programming topics."
    >
      <motion.div variants={stagger} initial="hidden" animate="show" className="space-y-5">
        <div className="grid gap-5 md:grid-cols-3">
          {/* ── Left Panel: 5-Tier Behavioral Legend ──────────────── */}
          <motion.div variants={fadeUp} className="md:col-span-1">
            <GlassPanel interactive className="h-full">
              <GlassPanelHeader>
                <GlassPanelTitle>Academic Status Legend</GlassPanelTitle>
              </GlassPanelHeader>
              <GlassPanelContent className="space-y-3">
                {TIER_LEGEND.map((item) => {
                  const meta = NEW_TIER_META[item.tier];
                  return (
                    <motion.div
                      key={item.tier}
                      whileHover={{ backgroundColor: "rgba(255,255,255,0.025)" }}
                      transition={{ duration: 0.15 }}
                      className="flex items-start gap-3 p-3 rounded-lg border border-white/[0.04] bg-white/[0.02]"
                    >
                      <div className={cn("w-2 h-2 rounded-full mt-1 shrink-0", item.dot)} />
                      <div className="flex-1 min-w-0">
                        <div className="flex items-center gap-2 flex-wrap">
                          <span className="text-sm font-semibold text-foreground">{meta.label}</span>
                          <span className={cn("text-[10px] px-1.5 py-0.5 rounded-full border", meta.dot.replace('bg-', 'bg-').replace('500', '500/20'), meta.text, `border-${item.dot.replace('bg-', '')}/30`)}>
                            {item.range}
                          </span>
                        </div>
                        <p className="text-xs text-muted-foreground/60 mt-1">{item.desc}</p>
                      </div>
                    </motion.div>
                  );
                })}
              </GlassPanelContent>
            </GlassPanel>
          </motion.div>

          {/* ── Right Panel: Concept Radar ────────────────────────── */}
          <motion.div variants={fadeUp} className="md:col-span-2">
            <ConceptRadarPanel scores={scores} loading={loading} />
          </motion.div>
        </div>
      </motion.div>
    </StudentDashboardShell>
  );
}
