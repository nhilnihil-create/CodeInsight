import { Link, useNavigate } from 'react-router-dom';
import { useEffect } from 'react';
import { useAuth } from '../context/AuthContext';
import { Button } from '@/components/ui/button';
import {
  Activity,
  ShieldCheck,
  Sparkles,
  TrendingUp,
  BarChart3,
  ScanSearch,
  BrainCircuit,
  ArrowDown,
} from 'lucide-react';
import Waves from '../components/Waves';
import BlurText from '../components/BlurText';
import FeatureRow from '../components/FeatureRow';
import AnimatedCounter from '../components/AnimatedCounter';
import MagneticButton from '../components/MagneticButton';
import ScrollProgress from '../components/ScrollProgress';
import {
  CDSVisual,
  HeatmapVisual,
  IntegrityVisual,
  ASTVisual,
  MicroConceptVisual,
} from '../components/FeatureVisuals';

const FEATURES = [
  {
    icon: Activity,
    title: 'Concept Difficulty Score',
    description:
      'Measures how much a student struggles on each exercise — combining errors, attempts, and time into a single score that adjusts to your class. Students see their score after every submission, and instructors get automatic at-risk alerts when scores cross thresholds.',
    details: [
      'Students get a live difficulty score after each submission',
      'Instructors see per-student, per-exercise scores with class-wide context',
      'Automatic classification: Low, Moderate, or High difficulty',
      'At-risk alerts generated when students consistently score high',
      'Rubric breakdown shows exactly which pillar (correctness, speed, style, integrity) needs work',
    ],
    visual: <CDSVisual />,
    reverse: false,
  },
  {
    icon: TrendingUp,
    title: 'Difficulty Heatmap',
    description:
      'A bird\'s-eye view of your entire class — every student against every concept, color-coded so you can spot patterns in seconds. Drag columns to compare concepts, hover for details, and filter by student name.',
    details: [
      '6 color tiers from green (easy) to red (needs help) — not just traffic lights',
      'Drag columns to compare any two concepts side-by-side',
      'Hardest concepts automatically sort to the right',
      'Hover any cell for a quick breakdown of what\'s behind the score',
      'Search by student name to find specific individuals instantly',
    ],
    visual: <HeatmapVisual />,
    reverse: true,
  },
  {
    icon: ShieldCheck,
    title: 'Academic Integrity Monitoring',
    description:
      'Five layers of integrity monitoring — not to punish, but to understand. Every flag is a hypothesis for review, not a verdict. Students see what was detected; instructors decide what to do about it.',
    details: [
      'Hardcoding — catches literal output instead of computed results',
      'Blank/template — flags unmodified starter code submissions',
      'Behavioral anomaly — unusual timing patterns like sudden success after many failures',
      'Code growth — flags sudden large code additions between attempts',
      'Passive tracking — tab switches, paste events, and idle time logged during coding',
    ],
    visual: <IntegrityVisual />,
    reverse: false,
  },
  {
    icon: ScanSearch,
    title: 'Code Structure Verification',
    description:
      'Goes beyond pass/fail — checks that required programming constructs like loops, conditionals, and functions are actually present and doing real work in the code, not just written but never used.',
    details: [
      'Verifies loops, conditionals, and functions are present in submitted code',
      'Catches empty bodies — code that compiles but does nothing',
      'Detects common beginner mistakes like hardcoded conditions',
      'Confirms that code actually affects the program\'s output',
      'Works even without tree-sitter — falls back to regex analysis',
    ],
    visual: <ASTVisual />,
    reverse: true,
  },
  {
    icon: BrainCircuit,
    title: 'Micro-Concept Analysis',
    description:
      'Pinpoints exactly where students are confused — not just "wrong answer" but "integer division truncating decimals." Instructors get a class-wide view of which misconceptions are most common, with targeted suggestions for each.',
    details: [
      '33 detection rules across 7 core C++ concepts',
      'Analyzes compiler errors, test output patterns, and code structure',
      'Each issue comes with a targeted suggestion for the student',
      'Class-wide reports show which misconceptions affect the most students',
      'Covers Datatypes, Variables, Conditionals, Loops, Functions, Arrays, and OOP',
    ],
    visual: <MicroConceptVisual />,
    reverse: false,
  },
];

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
    <div className="flex min-h-[100dvh] flex-col bg-background text-foreground">
      <ScrollProgress />
      <main className="relative flex flex-1 flex-col">
        {/* ─── Hero ─── */}
        <section className="relative flex min-h-[100dvh] flex-col items-center justify-center overflow-hidden px-6 text-center">
          <Waves
            lineColor="rgba(96, 165, 250, 0.35)"
            waveAmpX={40}
            waveAmpY={20}
            waveSpeedX={0.015}
            waveSpeedY={0.006}
            xGap={12}
            yGap={28}
          />
          <div className="absolute inset-0 bg-gradient-to-b from-background/40 via-transparent to-background/80 z-[1]" />

          <div className="relative z-10 max-w-4xl">
            <div className="mb-6 inline-flex items-center gap-2 rounded-full border border-border/60 bg-background/60 px-3 py-1 text-xs font-medium text-muted-foreground shadow-sm backdrop-blur-sm">
              <Sparkles className="h-3.5 w-3.5 text-primary" />
              Precision analytics for C++ education · PSU
            </div>

            <h1 className="mb-6 text-5xl font-extrabold tracking-tight text-balance md:text-7xl">
              <BlurText text="Precision Analytics for" className="block" delay={0.2} />
              <BlurText text="C++ Education" className="block text-primary" delay={0.6} />
            </h1>

            <p className="mb-10 max-w-2xl mx-auto text-xl text-muted-foreground">
              Detect concept-level programming difficulties in real-time. A quiet ally
              for students, a mission control for educators at Pampanga State University.
            </p>

            <div className="flex flex-col items-center justify-center gap-3 sm:flex-row">
              <MagneticButton>
                <Button asChild size="lg" className="px-8 text-base font-semibold shadow-lg">
                  <Link to="/register">Get Started</Link>
                </Button>
              </MagneticButton>
              <MagneticButton>
                <Button asChild variant="secondary" size="lg" className="px-8 text-base font-semibold shadow-lg">
                  <Link to="/login">Login</Link>
                </Button>
              </MagneticButton>
            </div>
          </div>

          <a
            href="#about"
            className="absolute bottom-10 left-1/2 z-10 -translate-x-1/2 text-muted-foreground/50 hover:text-muted-foreground transition-colors"
          >
            <ArrowDown className="h-5 w-5 animate-bounce" />
          </a>
        </section>

        {/* ─── About ─── */}
        <section id="about" className="relative z-10 border-t border-border/40 bg-background px-6 py-20">
          <div className="mx-auto max-w-3xl text-center space-y-6">
            <h2 className="text-3xl font-bold tracking-tight md:text-4xl">What is CodeInsight?</h2>
            <p className="text-lg text-muted-foreground leading-relaxed">
              CodeInsight is a C++ learning platform that helps instructors understand
              where students struggle — and helps students see their own progress. Every
              code submission is analyzed in real time for difficulty, structure, and
              integrity concerns.
            </p>
            <p className="text-muted-foreground leading-relaxed">
              Built for Pampanga State University&apos;s College of Computer Studies, CodeInsight
              replaces guesswork with data. Instructors get dashboards that show which
              concepts need re-teaching and which students need help. Students get
              immediate feedback on their submissions, including a rubric breakdown and
              personalized learning recommendations.
            </p>
          </div>
        </section>

        {/* ─── Core Features (alternating) ─── */}
        <section className="relative z-10 bg-background px-6 py-20">
          <div className="mx-auto max-w-6xl space-y-24">
            <div className="text-center space-y-3 mb-16">
              <h2 className="text-3xl font-bold tracking-tight md:text-4xl">Core Features</h2>
              <p className="text-muted-foreground max-w-xl mx-auto">
                The five pillars that make CodeInsight more than just a code runner.
              </p>
            </div>
            {FEATURES.map((f) => (
              <FeatureRow key={f.title} {...f} />
            ))}
          </div>
        </section>

        {/* ─── Quick Stats ─── */}
        <section className="relative z-10 border-t border-border/40 bg-card/30 px-6 py-16">
          <div className="mx-auto grid max-w-4xl grid-cols-2 gap-8 md:grid-cols-4">
            {[
              { value: '5', label: 'Integrity Layers', icon: ShieldCheck },
              { value: '25', label: 'Concepts × 4 Areas', icon: BarChart3 },
              { value: '33', label: 'Detection Rules', icon: BrainCircuit },
              { value: '5', label: 'CDS Tiers', icon: Activity },
            ].map(({ value, suffix = '', label, icon: Icon }) => (
              <div key={label} className="text-center group cursor-default">
                <div className="inline-flex items-center justify-center rounded-xl bg-primary/10 p-3 mb-3 transition-transform duration-300 group-hover:scale-110 group-hover:rotate-3">
                  <Icon className="h-5 w-5 text-primary" />
                </div>
                <div className="text-3xl font-bold text-primary font-mono">
                  <AnimatedCounter value={value} suffix={suffix} />
                </div>
                <div className="text-xs text-muted-foreground mt-1">{label}</div>
              </div>
            ))}
          </div>
        </section>

        {/* ─── CTA ─── */}
        <section className="relative z-10 px-6 py-20 text-center">
          <div className="mx-auto max-w-xl space-y-6">
            <h2 className="text-3xl font-bold tracking-tight">Ready to see your class differently?</h2>
            <p className="text-muted-foreground">
              Join instructors and students at PSU who use CodeInsight to understand
              programming difficulties at the concept level.
            </p>
            <div className="flex flex-col items-center justify-center gap-3 sm:flex-row">
              <MagneticButton>
                <Button asChild size="lg" className="px-8 text-base font-semibold">
                  <Link to="/register">Create Account</Link>
                </Button>
              </MagneticButton>
              <MagneticButton>
                <Button asChild variant="secondary" size="lg" className="px-8 text-base font-semibold">
                  <Link to="/login">Sign In</Link>
                </Button>
              </MagneticButton>
            </div>
          </div>
        </section>

        {/* ─── Footer ─── */}
        <footer className="relative z-10 border-t border-border/40 px-6 py-6 text-center text-xs text-muted-foreground lg:px-12">
          Pampanga State University · College of Computer Studies · {new Date().getFullYear()}
        </footer>
      </main>
    </div>
  );
}
