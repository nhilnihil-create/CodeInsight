import { Link, useNavigate } from 'react-router-dom';
import { useEffect } from 'react';
import { useAuth } from '../context/AuthContext';
import { Button } from '@/components/ui/button';
import {
  Activity,
  ShieldCheck,
  Sparkles,
  TrendingUp,
  Users,
} from 'lucide-react';

/**
 * Public landing page.
 *
 * Adopts the Frontend-Design visual language: large tracking-tight headline,
 * muted subtext, two CTAs that route to /login. Real auth is unchanged —
 * if the visitor is already signed in we bounce them to their dashboard so
 * the landing page only shows up for unauthenticated visitors.
 */
export default function Landing() {
  const { isLoggedIn, user } = useAuth();
  const navigate = useNavigate();

  useEffect(() => {
    if (isLoggedIn) {
      const dest = user?.role === 'instructor'
        ? '/instructor/dashboard'
        : user?.role === 'admin'
          ? '/admin'
          : '/student/dashboard';
      navigate(dest, { replace: true });
    }
  }, [isLoggedIn, user, navigate]);

  return (
    <div className="flex min-h-[100dvh] flex-col bg-background text-foreground">
      <header className="flex h-20 items-center justify-between border-b border-border/40 px-6 lg:px-12">
        <div className="flex items-center gap-2 font-mono text-2xl font-bold tracking-tight text-primary">
          CodeInsight
        </div>
        <nav className="flex items-center gap-3">
          <Link
            to="/login"
            className="text-sm font-medium text-foreground transition-colors hover:text-primary"
          >
            Login
          </Link>
          <Button asChild size="sm">
            <Link to="/login" className="font-semibold">
              Get started
            </Link>
          </Button>
        </nav>
      </header>

      <main className="flex flex-1 flex-col items-center justify-center px-6 py-16 text-center">
        <div className="mb-6 inline-flex items-center gap-2 rounded-full border border-border bg-card px-3 py-1 text-xs font-medium text-muted-foreground shadow-sm">
          <Sparkles className="h-3.5 w-3.5 text-primary" />
          Precision analytics for C++ education · PSU
        </div>

        <h1 className="mb-6 max-w-4xl text-5xl font-extrabold tracking-tight text-balance md:text-7xl">
          Precision Analytics for <br className="hidden md:block" /> C++ Education
        </h1>
        <p className="mb-10 max-w-2xl text-xl text-muted-foreground">
          Detect concept-level programming difficulties in real-time. A quiet ally
          for students, a mission control for educators at Pampanga State University.
        </p>

        <div className="flex flex-col gap-3 sm:flex-row">
          <Button asChild size="lg" className="px-8 text-lg font-semibold shadow-lg">
            <Link to="/login">Instructor Portal</Link>
          </Button>
          <Button asChild variant="secondary" size="lg" className="px-8 text-lg font-semibold">
            <Link to="/login">Student Access</Link>
          </Button>
        </div>

        {/* Feature highlights — drives the design's card rhythm */}
        <div className="mt-20 grid w-full max-w-5xl grid-cols-1 gap-4 sm:grid-cols-2 lg:grid-cols-4">
          {[
            { icon: Activity, title: 'CDS Engine', body: 'Concept Difficulty Score tracks real-time student struggle.' },
            { icon: TrendingUp, title: 'Heatmaps', body: 'See which concepts the class is stuck on this week.' },
            { icon: ShieldCheck, title: 'Integrity', body: 'Detect hard-coding, copy-paste, and behavioral anomalies.' },
            { icon: Users, title: 'Sections', body: 'Manage multiple courses and rosters from one place.' },
          ].map(({ icon: Icon, title, body }) => (
            <div
              key={title}
              className="rounded-lg border border-border bg-card p-5 text-left shadow-sm transition-shadow hover:shadow-md"
            >
              <div className="mb-3 inline-flex h-9 w-9 items-center justify-center rounded-md bg-primary/10 text-primary">
                <Icon className="h-4 w-4" />
              </div>
              <div className="mb-1 text-sm font-semibold text-foreground">{title}</div>
              <div className="text-xs leading-relaxed text-muted-foreground">{body}</div>
            </div>
          ))}
        </div>
      </main>

      <footer className="border-t border-border/40 px-6 py-6 text-center text-xs text-muted-foreground lg:px-12">
        Pampanga State University · College of Computer Studies · {new Date().getFullYear()}
      </footer>
    </div>
  );
}
