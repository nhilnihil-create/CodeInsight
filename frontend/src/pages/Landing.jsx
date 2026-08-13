import { Link, useNavigate } from 'react-router-dom';
import { useEffect } from 'react';
import { motion } from 'framer-motion';
import {
  Activity,
  ArrowDown,
  BarChart3,
  BrainCircuit,
  Code2,
  LayoutDashboard,
  ScanSearch,
  ShieldCheck,
  Sparkles,
  TrendingUp,
} from 'lucide-react';
import { useAuth } from '../context/AuthContext';
import { Button } from '@/components/ui/button';
import { Badge } from '@/components/ui/badge';
import Waves from '../components/Waves';
import BlurText from '../components/BlurText';
import AnimatedCounter from '../components/AnimatedCounter';
import MagneticButton from '../components/MagneticButton';
import ScrollProgress from '../components/ScrollProgress';
import Logo from '../components/Logo';
import CursorGlow from '../components/landing/CursorGlow';
import LandingDashboardPreview from '../components/landing/LandingDashboardPreview';
import { TIER_BAR, TIER_META, TIER_RANGES } from '@/components/ui/mastery-bar';
import { cn } from '@/lib/utils';

const FEATURES = [
  {
    icon: Activity,
    title: 'Concept Difficulty Score',
    description:
      'Quantifies how much a student struggles per exercise — combining error rate, attempt count, and time into a single class-normalized score. Students see it live; instructors get at-risk alerts automatically.',
    details: [
      'Three-component formula: Error Rate (40%), Attempts (35%), Time (25%)',
      'Class-wide p95-capped normalization — scores are relative, not absolute',
      'Five-tier classification from Very Low to High difficulty',
      'Automatic at-risk alerts when scores cross thresholds',
      'Live score after every submission, batch computation on exercise close',
    ],
    visual: null,
    reverse: false,
  },
  {
    icon: TrendingUp,
    title: 'Difficulty Heatmap',
    description:
      'Every student against every concept, color-coded so patterns surface in seconds. Spot which concepts are hardest and which students need help — all in one view.',
    details: [
      'Five color tiers — cool gray for very low, scaling through emerald and amber to rose for high difficulty',
      'Drag columns to compare any two concepts side-by-side',
      'Hardest concepts automatically sort to the right',
      'Hover any cell for a quick breakdown of what\'s behind the score',
      'Search by student name to find specific individuals instantly',
    ],
    visual: null,
    reverse: true,
  },
  {
    icon: ShieldCheck,
    title: 'Academic Integrity Monitoring',
    description:
      'Five layers of integrity analysis — not to punish, but to understand. Every flag is a hypothesis for instructor review, not an automatic verdict.',
    details: [
      'Hardcoding detection — catches literal output instead of computed results',
      'Blank/template detection — flags unmodified starter code submissions',
      'Behavioral anomaly — unusual timing patterns like sudden success after many failures',
      'Code growth spike — flags sudden large code additions between attempts',
      'Contextual activity — tab switches and paste events logged for context',
    ],
    visual: null,
    reverse: false,
  },
  {
    icon: ScanSearch,
    title: 'Code Structure Verification',
    description:
      'Goes beyond pass/fail — verifies that required constructs like loops, conditionals, and functions are present, non-empty, and actually affect the output.',
    details: [
      'AST-based verification using tree-sitter for precise C++ parsing',
      'Detects empty bodies, hardcoded conditions, and dead code',
      'Confirms constructs actually affect the program\'s output',
      '50+ bad pattern rules across 25 C++ concepts',
      'Falls back to regex analysis when tree-sitter is unavailable',
    ],
    visual: null,
    reverse: true,
  },
  {
    icon: BrainCircuit,
    title: 'Micro-Concept Analysis',
    description:
      'Pinpoints exactly where students are confused — not just "wrong answer" but "integer division truncating decimals." Instructors see which misconceptions affect the most students.',
    details: [
      '76+ deterministic detection rules across 25 C++ concepts',
      'Analyzes compiler errors, test output patterns, and code structure',
      'Each issue comes with a targeted suggestion for the student',
      'Class-wide misconception reports generated on exercise close',
      'Covers Datatypes, Variables, Conditionals, Loops, Functions, Arrays, and OOP',
    ],
    visual: null,
    reverse: false,
  },
];

/* ── Local constants ─────────────────────────────────────────────────── */
const STATS = [
  { value: '50', suffix: '+', label: 'API Endpoints', icon: BarChart3 },
  { value: '5', label: 'Integrity Layers', icon: ShieldCheck },
  { value: '76', label: 'Detection Rules', icon: BrainCircuit },
  { value: '25', label: 'C++ Concepts', icon: Activity },
];

const HOW_IT_WORKS = [
  {
    icon: Code2,
    title: 'Students submit code',
    description:
      'Every submission is analyzed in real time — compiled, tested, and checked against 50+ integrity and structure rules.',
  },
  {
    icon: ScanSearch,
    title: 'CodeInsight analyzes',
    description:
      'Difficulty, structure, and integrity checks run across five detection layers, feeding every metric with evidence.',
  },
  {
    icon: ShieldCheck,
    title: 'Instructors act',
    description:
      'Dashboards surface at-risk students, struggling concepts, and integrity flags so interventions happen early.',
  },
];

const FEATURE_CARDS = [
  ...FEATURES.map((f) => ({ icon: f.icon, title: f.title, description: f.description })),
  {
    icon: LayoutDashboard,
    title: 'Visual Reports',
    description:
      'Class-wide misconception and integrity reports generated on exercise close, with CSV and Excel export.',
  },
];

const NAV_LINKS = [
  { href: '#features', label: 'Features' },
  { href: '#how-it-works', label: 'How it works' },
  { href: '#dashboard', label: 'Dashboard' },
];

/* ── Motion spec ─────────────────────────────────────────────────────── */
const stagger = {
  hidden: {},
  show: { transition: { staggerChildren: 0.07, delayChildren: 0.1 } },
};
const fadeUp = {
  hidden: { opacity: 0, y: 24 },
  show: { opacity: 1, y: 0, transition: { duration: 0.6, ease: [0.25, 0.46, 0.45, 0.94] } },
};

const HOVER_CARD = { type: 'tween', duration: 0.2, ease: 'easeOut' };
const HOVER_TAP = { type: 'tween', duration: 0.15, ease: 'easeOut' };

/* ── Section heading helper ──────────────────────────────────────────── */
function SectionHeading({ eyebrow, title, subtitle }) {
  return (
    <div className="mx-auto mb-12 max-w-2xl space-y-3 text-center">
      <p className="metric-label text-primary">{eyebrow}</p>
      <h2 className="text-3xl font-bold tracking-tight text-foreground md:text-4xl">{title}</h2>
      {subtitle && <p className="text-muted-foreground">{subtitle}</p>}
    </div>
  );
}

export default function Landing() {
  const { isLoggedIn, user } = useAuth();
  const navigate = useNavigate();

  useEffect(() => {
    if (isLoggedIn) {
      const dest =
        user?.role === 'instructor'
          ? '/instructor/dashboard'
          : user?.role === 'admin'
            ? '/admin'
            : '/student/dashboard';
      navigate(dest, { replace: true });
    }
  }, [isLoggedIn, user, navigate]);

  return (
    <div className="flex min-h-[100dvh] flex-col bg-background text-foreground scroll-smooth">
      <ScrollProgress />
      <CursorGlow />
      <main className="relative flex flex-1 flex-col">

        {/* ─── Hero ─── */}
        <section className="relative flex min-h-[100dvh] flex-col items-center justify-center overflow-hidden px-6 pb-24 pt-10 text-center">
          <Waves
            // matches hsl(176 50% 67%) at 35% alpha
            lineColor="rgba(94, 234, 212, 0.35)"
            waveAmpX={40}
            waveAmpY={20}
            waveSpeedX={0.015}
            waveSpeedY={0.006}
            xGap={12}
            yGap={28}
          />
          <div className="absolute inset-0 z-[1] bg-gradient-to-b from-background/50 via-transparent to-background/90" />

          <div className="relative z-10 max-w-4xl">
            <Badge
              variant="outline"
              className="mb-6 gap-2 border-border/60 bg-background/60 px-3 py-1 text-xs font-medium text-muted-foreground shadow-sm backdrop-blur-sm"
            >
              <Sparkles className="h-3.5 w-3.5 text-primary" />
              Precision analytics for C++ education · PSU
            </Badge>

            <motion.div className="animate-float mb-8 flex justify-center">
              <Logo size={48} showText className="text-primary" />
            </motion.div>

            <h1 className="mb-6 text-5xl font-extrabold tracking-tight text-primary text-balance md:text-7xl">
              <BlurText text="See exactly where students" className="block" delay={0.2} />
              <BlurText text="struggle with code" className="block" delay={0.6} />
            </h1>

            <p className="mx-auto mb-10 max-w-2xl text-xl text-muted-foreground">
              Detect concept-level programming difficulties in real-time. A quiet ally
              for students, a mission control for educators at Pampanga State University.
            </p>

            <div className="flex flex-col items-center justify-center gap-3 sm:flex-row">
              <MagneticButton>
                <motion.div whileTap={{ scale: 0.98 }} transition={HOVER_TAP}>
                  <Button asChild size="lg" className="px-8 text-base font-semibold shadow-lg">
                    <Link to="/register">Get Started</Link>
                  </Button>
                </motion.div>
              </MagneticButton>
              <MagneticButton>
                <motion.div whileTap={{ scale: 0.98 }} transition={HOVER_TAP}>
                  <Button asChild variant="secondary" size="lg" className="px-8 text-base font-semibold shadow-lg">
                    <Link to="/login">Login</Link>
                  </Button>
                </motion.div>
              </MagneticButton>
            </div>
          </div>

          <div className="absolute inset-x-0 bottom-10 z-10 flex justify-center">
            <motion.a
              href="#dashboard"
              className="text-muted-foreground/50 transition-colors hover:text-muted-foreground"
              animate={{ y: [0, 6, 0] }}
              transition={{ duration: 2, repeat: Infinity, ease: 'easeInOut' }}
              aria-label="Scroll to dashboard preview"
            >
              <ArrowDown className="h-5 w-5" />
            </motion.a>
          </div>
        </section>

        {/* ─── Stats ─── */}
        <section className="relative z-10 border-t border-border/40 bg-card/30 px-6 py-16">
          <motion.div
            variants={stagger}
            initial="hidden"
            whileInView="show"
            viewport={{ once: true, margin: '-80px' }}
            className="mx-auto grid max-w-4xl grid-cols-2 gap-6 md:grid-cols-4"
          >
            {STATS.map(({ value, suffix = '', label, icon: Icon }) => (
              <motion.div
                key={label}
                variants={fadeUp}
                className="glass-panel hover-lift group cursor-default rounded-xl p-6 text-center hover:border-primary/30"
              >
                <div className="mb-3 inline-flex items-center justify-center rounded-xl bg-primary/10 p-3 transition-transform duration-300 group-hover:scale-110 group-hover:rotate-3">
                  <Icon className="h-5 w-5 text-primary" />
                </div>
                <div className="font-mono text-3xl font-bold text-primary tabular-nums">
                  <AnimatedCounter value={value} suffix={suffix} />
                </div>
                <div className="metric-label mt-1">{label}</div>
              </motion.div>
            ))}
          </motion.div>
        </section>

        {/* ─── Dashboard Preview ─── */}
        <section id="dashboard" className="relative z-10 scroll-mt-24 px-6 py-20">
          <div className="mx-auto max-w-6xl">
            <SectionHeading
              eyebrow="Live Preview"
              title="Mission control for your class"
              subtitle="A look at the instructor dashboard — class trends, struggling concepts, and integrity flags in one place."
            />
            <LandingDashboardPreview />
          </div>
        </section>

        {/* ─── How it works ─── */}
        <section id="how-it-works" className="relative z-10 scroll-mt-24 border-t border-border/40 bg-card/30 px-6 py-20">
          <div className="mx-auto max-w-6xl">
            <SectionHeading
              eyebrow="How it works"
              title="From submission to insight in seconds"
              subtitle="Three steps connect every code submission to the evidence instructors act on."
            />
            <motion.div
              variants={stagger}
              initial="hidden"
              whileInView="show"
              viewport={{ once: true, margin: '-80px' }}
              className="grid gap-6 md:grid-cols-3"
            >
              {HOW_IT_WORKS.map((s, i) => (
                <motion.div
                  key={s.title}
                  variants={fadeUp}
                  whileHover={{ y: -4, scale: 1.01, transition: HOVER_CARD }}
                  className="rounded-xl border border-border/60 bg-card/60 p-6"
                >
                  <span className="font-mono text-3xl font-bold text-primary/25">
                    0{i + 1}
                  </span>
                  <div className="mb-4 mt-4 inline-flex items-center justify-center rounded-xl bg-primary/10 p-3">
                    <s.icon className="h-5 w-5 text-primary" />
                  </div>
                  <h3 className="mb-2 text-lg font-semibold text-foreground">{s.title}</h3>
                  <p className="text-sm leading-relaxed text-muted-foreground">{s.description}</p>
                </motion.div>
              ))}
            </motion.div>
          </div>
        </section>

        {/* ─── Features ─── */}
        <section id="features" className="relative z-10 scroll-mt-24 px-6 py-20">
          <div className="mx-auto max-w-6xl">
            <SectionHeading
              eyebrow="Features"
              title="Six capabilities that turn submissions into answers"
              subtitle="Every feature exists to turn raw submissions into answers instructors can act on."
            />
            <motion.div
              variants={stagger}
              initial="hidden"
              whileInView="show"
              viewport={{ once: true, margin: '-80px' }}
              className="grid gap-6 md:grid-cols-2 lg:grid-cols-3"
            >
              {FEATURE_CARDS.map((f) => (
                <motion.div
                  key={f.title}
                  variants={fadeUp}
                  whileHover={{ y: -4, scale: 1.01, transition: HOVER_CARD }}
                  className="rounded-xl border border-border/60 bg-card/60 p-6"
                >
                  <div className="mb-4 inline-flex items-center justify-center rounded-xl bg-primary/10 p-3">
                    <f.icon className="h-5 w-5 text-primary" />
                  </div>
                  <h3 className="mb-2 text-base font-semibold text-foreground">{f.title}</h3>
                  <p className="text-sm leading-relaxed text-muted-foreground">{f.description}</p>
                </motion.div>
              ))}
            </motion.div>
          </div>
        </section>

        {/* ─── Mastery Scale ─── */}
        <section className="relative z-10 scroll-mt-24 border-t border-border/40 bg-card/30 px-6 py-20">
          <div className="mx-auto max-w-4xl">
            <SectionHeading
              eyebrow="Concept Difficulty Scale"
              title="One scale, every portal"
              subtitle="One continuum, two directions. CDS measures how hard a concept is right now — lower is better. Mastery is the same scale read in reverse."
            />
            <motion.div
              variants={stagger}
              initial="hidden"
              whileInView="show"
              viewport={{ once: true, margin: '-80px' }}
              className="space-y-5"
            >
              {TIER_RANGES.map((t) => (
                <motion.div
                  key={t.key}
                  variants={fadeUp}
                  whileHover={{ y: -3, transition: HOVER_TAP }}
                  className="rounded-xl border border-border/60 bg-card/60 p-5"
                >
                  <div className="flex items-center justify-between gap-4">
                    <div className="flex items-center gap-2.5">
                      <span className={cn('h-2 w-2 rounded-full', TIER_META[t.key].dot)} />
                      <span className="text-sm font-medium text-foreground">
                        {TIER_META[t.key].label}
                      </span>
                    </div>
                    <div className="flex flex-col items-end gap-1 text-right">
                      <span className="font-mono text-xs text-muted-foreground/70">
                        {t.difficulty} difficulty · CDS {t.cdsRange}
                      </span>
                      <span className="font-mono text-xs text-muted-foreground/70">
                        Mastery {t.masteryRange}
                      </span>
                    </div>
                  </div>
                  <div className="mastery-track mt-3 h-1.5 w-full overflow-hidden rounded-full">
                    <motion.div
                      className={cn('h-full rounded-full', TIER_BAR[t.key])}
                      initial={{ width: 0 }}
                      whileInView={{ width: `${t.fill}%` }}
                      viewport={{ once: true, margin: '-40px' }}
                      transition={{ duration: 0.9, ease: [0.25, 0.46, 0.45, 0.94] }}
                    />
                  </div>
                </motion.div>
              ))}
            </motion.div>
          </div>
        </section>

        {/* ─── CTA ─── */}
        <section className="relative z-10 px-6 py-24 text-center">
          <div className="mx-auto max-w-2xl space-y-6">
            <h2 className="text-3xl font-bold tracking-tight text-primary md:text-5xl">
              Ready to teach with evidence?
            </h2>
            <p className="text-lg text-muted-foreground">
              Join instructors and students at PSU who use CodeInsight to understand
              programming difficulties at the concept level.
            </p>
            <div className="flex flex-col items-center justify-center gap-3 sm:flex-row">
              <MagneticButton>
                <motion.div whileTap={{ scale: 0.98 }} transition={HOVER_TAP}>
                  <Button asChild size="lg" className="px-8 text-base font-semibold shadow-lg">
                    <Link to="/register">Get Started</Link>
                  </Button>
                </motion.div>
              </MagneticButton>
              <MagneticButton>
                <motion.div whileTap={{ scale: 0.98 }} transition={HOVER_TAP}>
                  <Button asChild variant="secondary" size="lg" className="px-8 text-base font-semibold">
                    <Link to="/login">Login</Link>
                  </Button>
                </motion.div>
              </MagneticButton>
            </div>
          </div>
        </section>

        {/* ─── Footer ─── */}
        <footer className="relative z-10 border-t border-border/40 px-6 py-8 lg:px-12">
          <div className="mx-auto flex max-w-6xl flex-col items-center justify-between gap-6 md:flex-row">
            <div className="flex flex-col items-center gap-2 md:flex-row md:gap-3">
              <Link to="/" className="shrink-0">
                <Logo size={24} showText />
              </Link>
              <p className="text-xs text-muted-foreground/70">Learning Analytics Platform</p>
            </div>
            <nav className="flex items-center gap-6 text-xs text-muted-foreground">
              {NAV_LINKS.map((l) => (
                <a
                  key={l.href}
                  href={l.href}
                  className="transition-colors hover:text-foreground"
                >
                  {l.label}
                </a>
              ))}
            </nav>
          </div>
          <div className="mt-6 border-t border-border/40 pt-6">
            <p className="text-center text-xs text-muted-foreground/70">
              © {new Date().getFullYear()} CodeInsight · Pampanga State University · College of Computer Studies
            </p>
          </div>
        </footer>
      </main>
    </div>
  );
}
