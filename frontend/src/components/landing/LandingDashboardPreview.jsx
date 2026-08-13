import { Link } from 'react-router-dom';
import { motion } from 'framer-motion';
import { ArrowRight, CalendarDays, Download } from 'lucide-react';
import { ResponsiveContainer, LineChart, Line, XAxis, YAxis, CartesianGrid, Tooltip, Legend } from 'recharts';
import GlassPanel, {
  GlassPanelHeader,
  GlassPanelTitle,
} from '@/components/ui/glass-panel';
import { Badge } from '@/components/ui/badge';
import { Button } from '@/components/ui/button';
import RiskBadge from '@/components/ui/risk-badge';
import { TIER_META, TIER_BAR } from '@/components/ui/mastery-bar';
import { flagTypeLabel } from '@/lib/flagTypes';
import { cn } from '@/lib/utils';

/* ── Shared reveal variants ─────────────────────────────────────────── */
const stagger = {
  hidden: {},
  show: { transition: { staggerChildren: 0.07, delayChildren: 0.1 } },
};
const fadeUp = {
  hidden: { opacity: 0, y: 24 },
  show: { opacity: 1, y: 0, transition: { duration: 0.6, ease: [0.25, 0.46, 0.45, 0.94] } },
};

/* ── Static demo data (explicit tiers, no derivation) ───────────────── */
const CONCEPT_ROWS = [
  { name: 'Loops', tier: 'critical', mastery: 22 },
  { name: 'Pointers', tier: 'needs_support', mastery: 41 },
  { name: 'Arrays', tier: 'developing', mastery: 58 },
  { name: 'Recursion', tier: 'needs_support', mastery: 45 },
];

const FLAG_ROWS = [
  { student: 'kirbs', type: 'HARDCODING', time: '2h', severity: 'high' },
  { student: 'Maria Reyes', type: 'BLANK_TEMPLATE', time: '5h', severity: 'moderate' },
  { student: 'Jack Smith', type: 'BEHAVIORAL_ANOMALY', time: '1d', severity: 'moderate' },
  { student: 'Black Tulips', type: 'CODE_GROWTH_ANOMALY', time: '2d', severity: 'low' },
];

/* ── Class trend chart (recharts, mirrors instructor dashboard) ────── */
const TREND_DATA = [
  { date: 'Wk 1', cds: 42 },
  { date: 'Wk 2', cds: 40 },
  { date: 'Wk 3', cds: 39 },
  { date: 'Wk 4', cds: 37 },
  { date: 'Wk 5', cds: 35 },
  { date: 'Wk 6', cds: 34 },
];

const TOOLTIP_STYLE = {
  backgroundColor: "rgba(19, 27, 46, 0.92)",
  border: "1px solid rgba(255,255,255,0.08)",
  borderRadius: "8px",
  fontSize: "12px",
  color: "hsl(215 32% 86%)",
  backdropFilter: "blur(12px)",
  boxShadow: "0 8px 32px rgba(0,0,0,0.5)",
};

const METRICS = [
  { label: 'Avg CDS', value: '0.34', accent: TIER_META.strong.text, sub: TIER_META.strong.label },
  { label: 'At Risk', value: '3', accent: 'text-warning' },
  { label: 'Students', value: '42', accent: 'text-info' },
];

export default function LandingDashboardPreview() {

  return (
    <motion.div
      variants={stagger}
      initial="hidden"
      whileInView="show"
      viewport={{ once: true, margin: '-80px' }}
    >
      <GlassPanel variant="dense" className="overflow-hidden">
        {/* ── Header: Class Status ─────────────────────────────── */}
        <GlassPanelHeader className="flex-wrap gap-3">
          <GlassPanelTitle>Class Status</GlassPanelTitle>
          <div className="flex flex-wrap items-center gap-2">
            <Badge variant="outline" className="bg-primary/15 text-primary border-primary/30">
              All Sections
            </Badge>
            <Badge variant="outline" className="text-muted-foreground border-border/60">
              Section A
            </Badge>
            <Badge
              variant="outline"
              className="text-muted-foreground border-border/60 hidden sm:inline-flex"
            >
              Section B
            </Badge>
            <span className="inline-flex items-center gap-1.5 rounded-full border border-border/60 bg-background/60 px-2.5 py-1 text-[11px] font-medium text-muted-foreground">
              <CalendarDays className="h-3 w-3 text-primary" />
              This Week
            </span>
            <Button variant="ghost" size="sm" type="button" className="font-medium text-muted-foreground">
              <Download className="mr-1.5 h-3.5 w-3.5" strokeWidth={1.5} />
              Export
            </Button>
          </div>
        </GlassPanelHeader>

        {/* ── Insight banner ───────────────────────────────────── */}
        <motion.div
          variants={fadeUp}
          className="relative overflow-hidden border-b border-white/[0.06] px-5 py-4"
        >
          <div className="absolute inset-x-0 top-0 h-px bg-gradient-to-r from-transparent via-primary/60 to-transparent" />
          <div className="relative z-10 flex flex-col gap-3 sm:flex-row sm:items-center sm:justify-between">
            <div className="min-w-0 space-y-1">
              <p className="metric-label">Insight</p>
              <p className="text-sm font-medium leading-snug text-foreground">
                Class average CDS normalized to 0.34 — 3 students need intervention
              </p>
            </div>
            <Button asChild size="sm" className="shrink-0">
              <Link to="/instructor/alerts">
                Open intervention queue
                <ArrowRight className="ml-1.5 h-4 w-4" strokeWidth={2} />
              </Link>
            </Button>
          </div>
        </motion.div>

        {/* ── Micro-metric strip ───────────────────────────────── */}
        <motion.div
          variants={fadeUp}
          className="grid grid-cols-3 gap-px border-b border-white/[0.06] bg-white/[0.06]"
        >
          {METRICS.map((m) => (
            <div key={m.label} className="flex flex-col gap-1 bg-white/[0.02] px-5 py-4">
              <span className="metric-label">{m.label}</span>
              <span
                className={cn(
                  'font-mono text-3xl font-extrabold tracking-tight tabular-nums',
                  m.accent
                )}
              >
                {m.value}
              </span>
              {m.sub && (
                <span
                  className={cn(
                    'text-[11px] font-medium uppercase tracking-wide opacity-70',
                    m.accent
                  )}
                >
                  {m.sub}
                </span>
              )}
            </div>
          ))}
        </motion.div>

        {/* ── Class trend chart (recharts) ─────────────────────── */}
        <motion.div variants={fadeUp} className="border-b border-white/[0.06] px-5 py-4">
          <h4 className="mb-3 text-xs font-semibold tracking-tight text-foreground">
            Class trend
          </h4>
          <div
            className="h-56 w-full"
            role="img"
            aria-label="Class average CDS trending down over the last six weeks"
          >
            <ResponsiveContainer width="100%" height="100%">
              <LineChart data={TREND_DATA} margin={{ top: 8, right: 12, bottom: 0, left: 8 }}>
                <CartesianGrid stroke="rgba(255,255,255,0.04)" strokeDasharray="3 3" vertical={false} />
                <XAxis dataKey="date" tick={{ fill: "rgba(255,255,255,0.4)", fontSize: 11 }} axisLine={{ stroke: "rgba(255,255,255,0.06)" }} tickLine={false} />
                <YAxis domain={[0, 100]} tickFormatter={(v) => `${v}%`} tick={{ fill: "rgba(255,255,255,0.4)", fontSize: 11 }} axisLine={false} tickLine={false} width={40} />
                <Tooltip contentStyle={TOOLTIP_STYLE} cursor={{ stroke: "rgba(255,255,255,0.06)" }} />
                <Legend wrapperStyle={{ fontSize: "11px", paddingTop: "8px" }} iconType="circle" iconSize={8} />
                <Line type="monotone" dataKey="cds" name="CDS" stroke="#f43f5e" strokeWidth={2} dot={false} isAnimationActive={false} />
              </LineChart>
            </ResponsiveContainer>
          </div>
        </motion.div>

        {/* ── Concepts + Flags ─────────────────────────────────── */}
        <div className="grid md:grid-cols-[1.2fr_1fr]">
          <motion.div
            variants={fadeUp}
            className="border-b border-white/[0.06] md:border-b-0 md:border-r"
          >
            <h4 className="px-5 pb-2 pt-4 text-xs font-semibold tracking-tight text-foreground">
              Top struggling concepts
            </h4>
            <ul className="divide-y divide-white/[0.04]">
              {CONCEPT_ROWS.map((c, i) => {
                const meta = TIER_META[c.tier];
                const cds = ((100 - c.mastery) / 100).toFixed(2);
                return (
                  <motion.li key={c.name} variants={fadeUp}>
                    <div className="grid grid-cols-[1fr_4.5rem] items-center gap-3 px-5 py-3.5">
                      <div className="min-w-0 space-y-2">
                        <div className="flex min-w-0 items-center gap-2">
                          <span className="truncate text-sm font-medium text-foreground">
                            {c.name}
                          </span>
                          <span className="flex shrink-0 items-center gap-1.5">
                            <span className={cn('h-1.5 w-1.5 rounded-full', meta.dot)} />
                            <span
                              className={cn(
                                'text-[10px] font-medium uppercase tracking-wider',
                                meta.text
                              )}
                            >
                              {meta.label}
                            </span>
                          </span>
                        </div>
                        <div className="mastery-track h-1.5 w-full overflow-hidden rounded-full">
                          <motion.div
                            className={cn('h-full rounded-full', TIER_BAR[c.tier])}
                            initial={{ width: 0 }}
                            whileInView={{ width: `${c.mastery}%` }}
                            viewport={{ once: true, margin: '-40px' }}
                            transition={{
                              duration: 0.9,
                              delay: i * 0.08,
                              ease: [0.25, 0.46, 0.45, 0.94],
                            }}
                          />
                        </div>
                        <p className="font-mono text-[10px] tabular-nums text-muted-foreground/50">
                          Mastery: {c.mastery}%
                        </p>
                      </div>
                      <span className="flex shrink-0 flex-col items-end gap-0.5">
                        <span className="text-[10px] uppercase tracking-wider text-muted-foreground/40">
                          CDS
                        </span>
                        <span className="font-mono text-sm font-semibold tabular-nums text-foreground">
                          {cds}
                        </span>
                      </span>
                    </div>
                  </motion.li>
                );
              })}
            </ul>
          </motion.div>

          <motion.div variants={fadeUp}>
            <h4 className="px-5 pb-2 pt-4 text-xs font-semibold tracking-tight text-foreground">
              Recent integrity flags
            </h4>
            <ul className="divide-y divide-white/[0.04]">
              {FLAG_ROWS.map((f) => (
                <motion.li key={f.student} variants={fadeUp}>
                  <motion.div
                    whileHover={{ x: 3, transition: { type: 'tween', duration: 0.15, ease: 'easeOut' } }}
                    className="flex h-14 cursor-default items-center gap-3 px-5 transition-colors hover:bg-card/80"
                  >
                    <div className="min-w-0 flex-1">
                      <p className="truncate text-sm font-medium text-foreground">{f.student}</p>
                      <p className="truncate text-[11px] text-muted-foreground/60">
                        {flagTypeLabel(f.type)}
                      </p>
                    </div>
                    <div className="flex shrink-0 items-center gap-2.5">
                      <span className="font-mono text-[11px] tabular-nums text-muted-foreground/50">
                        {f.time}
                      </span>
                      <RiskBadge level={f.severity} />
                    </div>
                  </motion.div>
                </motion.li>
              ))}
            </ul>
          </motion.div>
        </div>
      </GlassPanel>
    </motion.div>
  );
}
