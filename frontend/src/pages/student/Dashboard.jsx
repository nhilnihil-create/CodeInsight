import { Link } from "react-router-dom";
import {
  ArrowRight,
  CalendarClock,
  Sparkles,
  MessageSquare,
  Clock,
  ChevronRight,
} from "lucide-react";
import { Button } from "@/components/ui/button";
import { Card, CardContent, CardHeader, CardTitle } from "@/components/ui/card";
import { Avatar, AvatarFallback } from "@/components/ui/avatar";
import { cn } from "@/lib/utils";
import InsightHeader from "@/components/ui/insight-header";
import EvidenceRow from "@/components/ui/evidence-row";
import StudentDashboardShell from "@/components/student-dashboard-shell";

/**
 * Student "Today" page — mobile-first reference.
 * URL: /student/dashboard · file: student/Dashboard.jsx
 *
 * Layout
 *   Mobile  max-w-lg mx-auto px-4 py-4 (tighter gaps)
 *   Desktop max-w-none px-6 py-8 (full width)
 *
 * Hierarchy
 *   1. PageHeader     "Today, <weekday> <month> <day>"
 *   2. InsightHeader  due-soon flag + Start action
 *   3. EvidenceRow    Mastery / Streak / CDS (3 chips)
 *   4. Card           "You're close on recursion" — 3 weakest concepts
 *   5. Card           "Recent feedback" — 2 instructor notes
 *   6. Card           "Recommended next" — 3 ranked exercise suggestions
 */

const WEAKEST = [
  { id: "rc", name: "Recursion",   value: 32, level: "low",      hint: "3 exercises to go" },
  { id: "ar", name: "Arrays",      value: 48, level: "low",      hint: "2 exercises to go" },
  { id: "fn", name: "Functions",   value: 56, level: "moderate", hint: "1 exercise to go" },
];

const NOTES = [
  {
    id: "n1",
    author: "Dr. E. Chen",
    initials: "EC",
    when: "2 days ago",
    body: "Recursion workshop Friday 3pm, Lab 204. Pair with H. Singh for the Loops review.",
  },
  {
    id: "n2",
    author: "Dr. E. Chen",
    initials: "EC",
    when: "1 week ago",
    body: "Midterm: 78% on Functions. Watch edge cases on empty input arrays — 3/5 missed there.",
  },
];

const RECOMMENDED = [
  {
    id: "e7",
    rank: 1,
    title: "Recursion Warmup",
    blurb: "Base cases, the call stack, and tracing factorial.",
    minutes: 20,
    concept: "RC",
    conceptName: "Recursion",
  },
  {
    id: "e8",
    rank: 2,
    title: "Functions II",
    blurb: "Closures, lambdas, and pass-by-reference gotchas.",
    minutes: 25,
    concept: "FN",
    conceptName: "Functions",
  },
  {
    id: "e9",
    rank: 3,
    title: "Array Filter",
    blurb: "Predicate-based filtering with one and two-pass patterns.",
    minutes: 15,
    concept: "AR",
    conceptName: "Arrays",
  },
];

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

export default function StudentDashboard() {
  return (
    <StudentDashboardShell>
      {/* ---------- PageHeader ---------- */}
      <header className="flex items-center justify-between gap-3">
        <div className="min-w-0 space-y-0.5">
          <h1 className="text-xl font-semibold tracking-tight truncate sm:text-2xl">
            {formatToday()}
          </h1>
          <p className="text-xs text-muted-foreground sm:text-sm">
            3 exercises due this week · 1 in 2 hours
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
      <InsightHeader
        eyebrow="Due soon"
        insight="Exercise 7 (Recursion) is due in 2 hours. You haven't started."
        description="~35 min · Targets: recursion, base case"
        action={
          <Button asChild size="sm" className="font-medium">
            <Link to="/student/exercises/e7">
              Start Exercise 7
              <ArrowRight className="ml-1.5 h-3.5 w-3.5" strokeWidth={2} />
            </Link>
          </Button>
        }
      />

      {/* ---------- Evidence ---------- */}
      <EvidenceRow
        chips={[
          { label: "Mastery", value: "64%",  delta: 2,    series: [60, 61, 62, 63, 64], comparison: "this week" },
          { label: "Streak",  value: "5 days", delta: 1,  series: [2, 3, 3, 4, 5],         comparison: "personal best" },
          { label: "CDS",     value: "0.28",  delta: -0.04, series: [0.34, 0.32, 0.31, 0.30, 0.28], comparison: "improving" },
        ]}
      />

      {/* ---------- Card 4: weakest concepts ---------- */}
      <div className="grid gap-4 sm:grid-cols-2 sm:gap-6">
        <Card>
          <CardHeader className="flex flex-row items-center justify-between space-y-0 pb-3 border-b border-border">
            <div className="space-y-1 min-w-0">
              <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
                Focus
              </p>
              <CardTitle className="text-sm font-semibold truncate">
                You're close on recursion
              </CardTitle>
            </div>
            <Sparkles className="h-4 w-4 text-muted-foreground shrink-0" strokeWidth={1.5} />
          </CardHeader>
          <CardContent className="pt-4 space-y-3">
            {WEAKEST.map((c) => {
              const fillTone = FILL_TONE[c.level] ?? "bg-primary";
              return (
                <div
                  key={c.id}
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
                      style={{ width: `${c.value}%` }}
                      aria-hidden="true"
                    />
                  </div>
                  <span className="text-xs font-mono tabular-nums text-muted-foreground text-right">
                    {c.value}%
                  </span>
                </div>
              );
            })}
          </CardContent>
        </Card>

        {/* ---------- Card 5: recent feedback ---------- */}
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
            <ul className="divide-y divide-border">
              {NOTES.map((n) => (
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
          </CardContent>
        </Card>
      </div>

      {/* ---------- Card 6: recommended next ---------- */}
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
          <ul className="divide-y divide-border">
            {RECOMMENDED.map((r) => (
              <li key={r.id}>
                <Link
                  to={`/student/exercises/${r.id}`}
                  className="flex items-center gap-3 px-4 py-3 sm:px-5 sm:py-4 transition-colors hover:bg-muted/40 focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-ring focus-visible:ring-inset"
                >
                  <span
                    className="flex h-7 w-7 shrink-0 items-center justify-center rounded-full bg-muted text-xs font-semibold text-muted-foreground font-mono tabular-nums"
                    aria-hidden="true"
                  >
                    {r.rank}
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
        </CardContent>
      </Card>

      {/* ---------- Tiny foot ---------- */}
      <p className="text-[11px] text-muted-foreground text-center pt-2 inline-flex items-center gap-1.5 w-full justify-center">
        <CalendarClock className="h-3 w-3" strokeWidth={1.5} aria-hidden="true" />
        Next sync in 14 min · last 2 min ago
      </p>
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
