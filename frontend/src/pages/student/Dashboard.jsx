import { useState, useEffect } from "react";
import { Link } from "react-router-dom";
import {
  ArrowRight,
  Sparkles,
  MessageSquare,
  Clock,
  ChevronRight,
  AlertCircle,
} from "lucide-react";
import { Button } from "@/components/ui/button";
import { Card, CardContent, CardHeader, CardTitle } from "@/components/ui/card";
import { Avatar, AvatarFallback } from "@/components/ui/avatar";
import { cn } from "@/lib/utils";
import EmptyState from "@/components/ui/empty-state";
import InsightHeader from "@/components/ui/insight-header";
import EvidenceRow from "@/components/ui/evidence-row";
import StudentDashboardShell from "@/components/student-dashboard-shell";
import api from "@/services/api";

function formatToday() {
  const d = new Date();
  const weekday = d.toLocaleDateString("en-US", { weekday: "long" });
  const month = d.toLocaleDateString("en-US", { month: "long" });
  const day = d.getDate();
  return `Today, ${weekday} ${month} ${day}`;
}

const FILL_TONE = {
  low: "bg-destructive",
  moderate: "bg-warning",
  high: "bg-success",
};

function Skeleton({ className }) {
  return <div className={cn("animate-pulse rounded-md bg-muted", className)} />;
}

export default function StudentDashboard() {
  const [data, setData] = useState(null);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);

  useEffect(() => {
    let cancelled = false;
    async function fetchDashboard() {
      try {
        setLoading(true);
        setError(null);
        const res = await api.get("/api/student/dashboard");
        if (!cancelled) setData(res.data);
      } catch (err) {
        if (!cancelled) setError(err.message);
      } finally {
        if (!cancelled) setLoading(false);
      }
    }
    fetchDashboard();
    return () => { cancelled = true; };
  }, []);

  // ---------- Loading skeleton ----------
  if (loading) {
    return (
      <StudentDashboardShell>
        <div className="space-y-6">
          <div className="flex items-center justify-between">
            <div className="space-y-2">
              <Skeleton className="h-7 w-64" />
              <Skeleton className="h-4 w-48" />
            </div>
            <Skeleton className="h-9 w-24" />
          </div>
          <Skeleton className="h-24 w-full rounded-lg" />
          <div className="grid grid-cols-2 lg:grid-cols-4 gap-4">
            {[1, 2, 3].map(i => <Skeleton key={i} className="h-28 w-full rounded-lg" />)}
          </div>
          <div className="grid gap-4 sm:grid-cols-2 sm:gap-6">
            <Skeleton className="h-64 w-full rounded-lg" />
            <Skeleton className="h-64 w-full rounded-lg" />
          </div>
          <Skeleton className="h-48 w-full rounded-lg" />
        </div>
      </StudentDashboardShell>
    );
  }

  // ---------- Error state ----------
  if (error) {
    return (
      <StudentDashboardShell>
        <div className="flex flex-col items-center justify-center py-16 gap-4 text-center">
          <AlertCircle className="h-10 w-10 text-destructive" strokeWidth={1.5} />
          <div className="space-y-1">
            <p className="text-base font-semibold text-foreground">Failed to load dashboard</p>
            <p className="text-sm text-muted-foreground max-w-sm">{error}</p>
          </div>
          <Button variant="outline" size="sm" onClick={() => window.location.reload()}>
            Try again
          </Button>
        </div>
      </StudentDashboardShell>
    );
  }

  // ---------- Derived data ----------
  const due = data.dueExercises;
  const dueCount = due?.count ?? 0;
  const nearest = due?.nearestDeadline;
  const mastery = data.mastery;
  const completion = data.completion;
  const streak = data.streak;
  const avgCds = data.avgCds ?? 0;
  const weakest = data.weakestConcepts ?? [];
  const feedback = data.recentFeedback ?? [];
  const recs = data.recommended ?? [];

  // Empty-state gate: no enrolled exercises at all → show EmptyState once.
  const hasAnyData = mastery?.percentage > 0 || completion?.completed > 0 || streak?.current > 0 || weakest.length > 0 || feedback.length > 0 || recs.length > 0 || dueCount > 0;
  if (!hasAnyData && !nearest) {
    return (
      <StudentDashboardShell>
        <EmptyState
          icon={<Sparkles />}
          title="Welcome to CodeInsight!"
          description="You're not enrolled in any exercises yet. Your instructor will add you to a section to get started."
          action={
            <Button asChild variant="outline" size="sm">
              <Link to="/student/sections">Browse sections</Link>
            </Button>
          }
          footnote="Check back once your instructor publishes exercises."
        />
      </StudentDashboardShell>
    );
  }

  return (
    <StudentDashboardShell>
      {/* ---------- PageHeader ---------- */}
      <header className="flex items-center justify-between gap-3">
        <div className="min-w-0 space-y-0.5">
          <h1 className="text-xl font-semibold tracking-tight truncate sm:text-2xl">
            {formatToday()}
          </h1>
          <p className="text-xs text-muted-foreground sm:text-sm">
            {dueCount > 0
              ? `${dueCount} exercise${dueCount > 1 ? 's' : ''} due this week`
              : "No exercises due this week"}
          </p>
        </div>
        <Button asChild variant="outline" size="sm" className="font-medium shrink-0">
          <Link to="/student/exercises">
            View all
            <ChevronRight className="ml-1 h-3.5 w-3.5" strokeWidth={1.5} />
          </Link>
        </Button>
      </header>

      {/* ---------- Insight ---------- */}
      {nearest ? (
        <InsightHeader
          eyebrow={dueCount > 0 ? "Due soon" : "All clear"}
          insight={nearest
            ? `Exercise ${nearest.id} (${nearest.concept}) is due in ${nearest.minutesUntilDue > 60 ? Math.round(nearest.minutesUntilDue / 60) + 'h' : nearest.minutesUntilDue + ' min'}.`
            : "You're all caught up on your exercises."}
          description={nearest
            ? `~${nearest.minutesUntilDue > 60 ? Math.round(nearest.minutesUntilDue / 60) + 'h' : nearest.minutesUntilDue + ' min'} · Targets: ${nearest.concept}`
            : "No deadlines approaching."}
          action={
            <Button asChild size="sm" className="font-medium">
              <Link to={`/student/exercises/${nearest.id}`}>
                Start Exercise {nearest.id}
                <ArrowRight className="ml-1.5 h-3.5 w-3.5" strokeWidth={2} />
              </Link>
            </Button>
          }
        />
      ) : null}

      {/* ---------- Evidence ---------- */}
      <EvidenceRow
        chips={[
          {
            label: "Mastery",
            value: `${mastery?.percentage ?? 0}%`,
            delta: avgCds <= 0.33 ? -1 : avgCds > 0.66 ? 1 : 0,
            series: mastery?.series ?? [],
            comparison: "concept understanding",
          },
          {
            label: "Completion",
            value: `${completion?.percentage ?? 0}%`,
            delta: completion?.completed ?? 0,
            series: [],
            comparison: `${completion?.total ?? 0} exercises total`,
          },
          {
            label: "Streak",
            value: `${streak?.current ?? 0} day${streak?.current !== 1 ? 's' : ''}`,
            delta: streak?.best ?? 0,
            series: streak?.series ?? [],
            comparison: "personal best",
          },
        ]}
      />

      {/* ---------- Card: weakest concepts + feedback ---------- */}
      <div className="grid gap-4 sm:grid-cols-2 sm:gap-6">
        <Card>
          <CardHeader className="flex flex-row items-center justify-between space-y-0 pb-3 border-b border-border">
            <div className="space-y-1 min-w-0">
              <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
                Focus
              </p>
              <CardTitle className="text-sm font-semibold truncate">
                {weakest.length > 0
                  ? `Work on ${weakest[0].name.toLowerCase()}`
                  : "No data yet"}
              </CardTitle>
            </div>
            <Sparkles className="h-4 w-4 text-muted-foreground shrink-0" strokeWidth={1.5} />
          </CardHeader>
          <CardContent className="pt-4 space-y-3">
            {weakest.length > 0 ? weakest.map((c) => {
              const fillTone = FILL_TONE[c.level] ?? "bg-primary";
              const displayValue = Math.round((1 - c.avgCds) * 100);
              return (
                <div
                  key={c.name}
                  className="grid grid-cols-[7rem_1fr_3.5rem] items-center gap-3 min-w-0"
                >
                  <div className="min-w-0">
                    <p className="text-sm font-medium text-foreground truncate">
                      {c.name}
                    </p>
                    <p className="text-[11px] text-muted-foreground truncate">
                      {c.hint}
                    </p>
                  </div>
                  <div className="h-2 rounded-full bg-muted overflow-hidden min-w-0">
                    <div
                      className={cn("h-full rounded-full transition-all", fillTone)}
                      style={{ width: `${displayValue}%` }}
                      aria-hidden="true"
                    />
                  </div>
                  <span className="text-xs font-mono tabular-nums text-muted-foreground text-right">
                    {displayValue}%
                  </span>
                </div>
              );
            }) : (
              <EmptyState
                icon={<Sparkles />}
                title="No progress yet"
                description="Complete exercises to see your concept breakdown here."
              />
            )}
          </CardContent>
        </Card>

        {/* ---------- Card: recent feedback ---------- */}
        <Card>
          <CardHeader className="flex flex-row items-center justify-between space-y-0 pb-3 border-b border-border">
            <div className="space-y-1 min-w-0">
              <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
                From instructor
              </p>
              <CardTitle className="text-sm font-semibold truncate">
                Recent feedback
              </CardTitle>
            </div>
            <MessageSquare
              className="h-4 w-4 text-muted-foreground shrink-0"
              strokeWidth={1.5}
            />
          </CardHeader>
          <CardContent className="p-0">
            {feedback.length > 0 ? (
              <ul className="divide-y divide-border">
                {feedback.map((n) => (
                  <li key={n.id} className="px-4 py-3 sm:px-5 sm:py-4">
                    <div className="flex items-start gap-3">
                      <Avatar className="h-8 w-8 shrink-0">
                        <AvatarFallback className="text-[10px] font-semibold text-muted-foreground">
                          {n.initials}
                        </AvatarFallback>
                      </Avatar>
                      <div className="min-w-0 flex-1 space-y-1">
                        <div className="flex items-center justify-between gap-2">
                          <span className="text-sm font-medium truncate">
                            {n.author}
                          </span>
                          <span className="text-[11px] text-muted-foreground font-mono tabular-nums shrink-0 inline-flex items-center gap-1">
                            <Clock className="h-3 w-3" strokeWidth={1.5} aria-hidden="true" />
                            {n.when}
                          </span>
                        </div>
                        <p className="text-sm text-muted-foreground leading-relaxed">
                          {n.body}
                        </p>
                      </div>
                    </div>
                  </li>
                ))}
              </ul>
            ) : (
              <EmptyState
                icon={<MessageSquare />}
                title="No feedback yet"
                description="Your instructor will share feedback here after reviewing your submissions."
              />
            )}
          </CardContent>
        </Card>
      </div>

      {/* ---------- Card: recommended next ---------- */}
      <Card>
        <CardHeader className="flex flex-row items-center justify-between space-y-0 pb-3 border-b border-border">
          <div className="space-y-1 min-w-0">
            <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
              Up next
            </p>
            <CardTitle className="text-sm font-semibold truncate">
              Recommended next
            </CardTitle>
          </div>
          <Button asChild variant="ghost" size="sm" className="font-medium -mr-2">
            <Link to="/student/exercises">
              See all
              <ChevronRight className="ml-1 h-3.5 w-3.5" strokeWidth={1.5} />
            </Link>
          </Button>
        </CardHeader>
        <CardContent className="p-0">
          {recs.length > 0 ? (
            <ul className="divide-y divide-border">
              {recs.map((r, idx) => (
                <li key={r.id}>
                  <Link
                    to={`/student/exercises/${r.id}`}
                    className="flex items-center gap-3 px-4 py-3 sm:px-5 sm:py-4 transition-all duration-200 ease-out hover:bg-slate-900/80 hover:scale-[1.01] focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-ring focus-visible:ring-inset"
                  >
                    <span
                      className="flex h-7 w-7 shrink-0 items-center justify-center rounded-full bg-muted text-xs font-semibold text-muted-foreground font-mono tabular-nums"
                      aria-hidden="true"
                    >
                      {idx + 1}
                    </span>
                    <div className="min-w-0 flex-1">
                      <div className="flex items-center gap-2 min-w-0">
                        <p className="text-sm font-medium text-foreground truncate">
                          {r.title}
                        </p>
                        <ConceptTag code={r.concept} name={r.conceptName} />
                      </div>
                      <p className="mt-0.5 text-xs text-muted-foreground truncate">
                        {r.blurb} · ~{r.minutes} min
                      </p>
                    </div>
                    <ChevronRight
                      className="h-4 w-4 text-muted-foreground shrink-0"
                      strokeWidth={1.5}
                      aria-hidden="true"
                    />
                  </Link>
                </li>
              ))}
            </ul>
          ) : (
            <EmptyState
              icon={<Sparkles />}
              title="No exercises available yet"
              description="When your instructor publishes exercises, they'll appear here as recommendations."
            />
          )}
        </CardContent>
      </Card>
    </StudentDashboardShell>
  );
}

function ConceptTag({ code, name }) {
  return (
    <span
      className="shrink-0 inline-flex items-center rounded-full border border-border bg-muted/60 px-1.5 py-0.5 text-[10px] font-mono uppercase tracking-wider text-muted-foreground"
      title={name}
    >
      {code}
    </span>
  );
}
