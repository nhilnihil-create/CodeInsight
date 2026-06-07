import { useMemo, useState } from "react";
import { Link } from "react-router-dom";
import {
  ResponsiveContainer,
  RadarChart,
  PolarGrid,
  PolarAngleAxis,
  PolarRadiusAxis,
  Radar,
} from "recharts";
import {
  Mail,
  MoreHorizontal,
  ArrowRight,
  MessageSquare,
  Flag,
  Download,
  UserMinus,
  FileText,
} from "lucide-react";
import { Button } from "@/components/ui/button";
import { Badge } from "@/components/ui/badge";
import { Tabs, TabsList, TabsTrigger, TabsContent } from "@/components/ui/tabs";
import { Textarea } from "@/components/ui/textarea";
import { Avatar, AvatarFallback } from "@/components/ui/avatar";
import {
  Table,
  TableBody,
  TableCell,
  TableHead,
  TableHeader,
  TableRow,
} from "@/components/ui/table";
import {
  DropdownMenu,
  DropdownMenuContent,
  DropdownMenuItem,
  DropdownMenuSeparator,
  DropdownMenuTrigger,
} from "@/components/ui/dropdown-menu";
import PageBreadcrumb from "@/components/ui/page-breadcrumb";
import InsightHeader from "@/components/ui/insight-header";
import EvidenceRow from "@/components/ui/evidence-row";
import CDSPillDelta from "@/components/ui/cds-pill-delta";
import RiskBadge from "@/components/ui/risk-badge";
import DetailDrawer from "@/components/ui/detail-drawer";
import DecisionList from "@/components/ui/decision-list";
import { MOCK_USERS } from "@/data/mockData";

const STUDENT = MOCK_USERS.find((u) => u.id === "u2") ?? MOCK_USERS[1];

const CONCEPT_MASTERY = [
  { concept: "Variables",   value: 88, level: "high" },
  { concept: "Conditionals", value: 74, level: "high" },
  { concept: "Loops",       value: 62, level: "moderate" },
  { concept: "Functions",   value: 54, level: "moderate" },
  { concept: "Arrays",      value: 41, level: "low" },
  { concept: "Recursion",   value: 28, level: "low" },
];

const STRUGGLING = [
  { id: "rc", title: "Recursion",   subtitle: "Mastery 28%",  meta: "▼ 18%", level: "high" },
  { id: "ar", title: "Arrays",      subtitle: "Mastery 41%",  meta: "▼ 9%",  level: "high" },
  { id: "fn", title: "Functions",   subtitle: "Mastery 54%",  meta: "▼ 6%",  level: "moderate" },
];

const SUBMISSIONS = [
  { id: "s1", exercise: "Recursion I",        when: "2h ago",  status: "Late",      cds: 0.82, anomalies: ["behavioral_anomaly"] },
  { id: "s2", exercise: "Functions Calculator", when: "1d ago", status: "Submitted", cds: 0.71, anomalies: [] },
  { id: "s3", exercise: "Array Reversal",      when: "3d ago", status: "Submitted", cds: 0.66, anomalies: ["code_growth_spike"] },
  { id: "s4", exercise: "Loops II",           when: "5d ago", status: "Submitted", cds: 0.58, anomalies: [] },
  { id: "s5", exercise: "Conditionals",        when: "1w ago", status: "Submitted", cds: 0.49, anomalies: [] },
  { id: "s6", exercise: "Basic Loops",         when: "2w ago", status: "Submitted", cds: 0.42, anomalies: [] },
];

const FLAGS = [
  {
    id: "f1",
    title: "Behavioral anomaly · Recursion I",
    subtitle: "Code grew from 5 → 85 lines in <1s",
    meta: "2h ago",
    level: "high",
  },
  {
    id: "f2",
    title: "Code growth spike · Array Reversal",
    subtitle: "+220 LOC in single commit",
    meta: "3d ago",
    level: "moderate",
  },
];

const INITIAL_NOTES = [
  { id: "n1", author: "You",         when: "2 days ago", body: "Recursion workshop on Friday. Pair with H. Singh for Loops review." },
  { id: "n2", author: "You",         when: "1 week ago", body: "Submissions up to date. Office hours Mon/Wed 2-4pm." },
  { id: "n3", author: "Dr. E. Chen", when: "2 weeks ago", body: "Midterm concerns: needs targeted support on Functions → Recursion." },
];

function initials(name) {
  if (!name) return "??";
  return name
    .split(" ")
    .map((p) => p[0])
    .filter(Boolean)
    .slice(0, 2)
    .join("")
    .toUpperCase();
}

export default function InstructorStudentDetail() {
  const [tab, setTab] = useState("mastery");
  const [drawerOpen, setDrawerOpen] = useState(false);
  const [drawerFlag, setDrawerFlag] = useState(null);
  const [note, setNote] = useState("");
  const [notes, setNotes] = useState(INITIAL_NOTES);

  const radarData = useMemo(
    () => CONCEPT_MASTERY.map((c) => ({ subject: c.concept, mastery: c.value })),
    [],
  );

  const flagItems = useMemo(
    () =>
      FLAGS.map((f) => ({
        ...f,
        badge: <RiskBadge level={f.level} />,
      })),
    [],
  );

  if (!STUDENT) {
    return (
      <div className="space-y-4">
        <PageBreadcrumb crumbs={[{ label: "Sections", href: "/instructor/sections" }]} />
        <p className="text-sm text-muted-foreground">Student not found.</p>
      </div>
    );
  }

  const handleSaveNote = () => {
    const trimmed = note.trim();
    if (!trimmed) return;
    setNotes((prev) => [
      { id: `n${Date.now()}`, author: "You", when: "just now", body: trimmed },
      ...prev,
    ]);
    setNote("");
  };

  const openFlag = (item) => {
    setDrawerFlag(item);
    setDrawerOpen(true);
  };

  const cdsSeries = [0.72, 0.74, 0.75, 0.77, 0.79, 0.81, 0.82];
  const masterySeries = [70, 68, 67, 66, 65, 64, 64];

  return (
    <div className="space-y-6 sm:space-y-8">
      {/* ---------- PageHeader ---------- */}
      <div className="space-y-2">
        <PageBreadcrumb
          crumbs={[
            { label: "Sections", href: "/instructor/sections" },
            { label: "Section 04", href: "/instructor/sections/4" },
            { label: STUDENT.name },
          ]}
        />
        <div className="flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between">
          <div className="flex items-center gap-4 min-w-0">
            <Avatar className="h-12 w-12">
              <AvatarFallback className="text-sm font-semibold text-muted-foreground">
                {initials(STUDENT.name)}
              </AvatarFallback>
            </Avatar>
            <div className="min-w-0 space-y-1">
              <div className="flex items-center gap-2">
                <h1 className="text-2xl font-semibold tracking-tight truncate">
                  {STUDENT.name}
                </h1>
                <RiskBadge level="high" />
              </div>
              <p className="text-sm text-muted-foreground truncate">
                {STUDENT.email} · {STUDENT.studentId} · Section 04 — Intro CS
              </p>
            </div>
          </div>
          <div className="flex items-center gap-2 shrink-0">
            <Button variant="outline" size="sm" className="font-medium">
              <Mail className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
              Email
            </Button>
            <Button size="sm" className="font-medium">
              Schedule check-in
            </Button>
            <DropdownMenu>
              <DropdownMenuTrigger asChild>
                <Button variant="outline" size="icon" aria-label="More actions">
                  <MoreHorizontal className="h-4 w-4" strokeWidth={1.5} />
                </Button>
              </DropdownMenuTrigger>
              <DropdownMenuContent align="end">
                <DropdownMenuItem>
                  <FileText className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                  View full report
                </DropdownMenuItem>
                <DropdownMenuItem>
                  <Download className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                  Export submissions
                </DropdownMenuItem>
                <DropdownMenuSeparator />
                <DropdownMenuItem className="text-destructive focus:text-destructive">
                  <UserMinus className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                  Remove from section
                </DropdownMenuItem>
              </DropdownMenuContent>
            </DropdownMenu>
          </div>
        </div>
      </div>

      {/* ---------- Insight ---------- */}
      <InsightHeader
        eyebrow="At-risk signal"
        insight="CDS rose 0.10 this week (0.72 → 0.82). Recursion mastery dropped 18%."
        description="Check-in before Friday's submission deadline — the trajectory is up and to the right."
        action={
          <Button asChild size="sm" className="font-medium">
            <Link to={`/instructor/students/${STUDENT.id}/check-in`}>
              Schedule check-in
              <ArrowRight className="ml-1.5 h-3.5 w-3.5" strokeWidth={2} />
            </Link>
          </Button>
        }
      />

      {/* ---------- Evidence ---------- */}
      <EvidenceRow
        chips={[
          { label: "CDS",          value: "0.82", delta: 0.10, series: cdsSeries,    comparison: "vs. last week" },
          { label: "Mastery",      value: "64%",  delta: -6,   series: masterySeries, comparison: "vs. last week" },
          { label: "Flags",        value: 1,      delta: 1,    series: [0, 0, 0, 0, 0, 0, 1], comparison: "this week" },
          { label: "Last Active",  value: "2h",   delta: null, series: null,         comparison: "ago" },
        ]}
      />

      {/* ---------- Tabs ---------- */}
      <Tabs value={tab} onValueChange={setTab}>
        <TabsList className="inline-flex h-10 items-center gap-0 bg-transparent p-0 border-b border-border rounded-none w-full justify-start">
          <TabsTrigger
            value="mastery"
            className="rounded-none border-b-2 border-transparent data-[state=active]:border-b-foreground data-[state=active]:bg-transparent data-[state=active]:text-foreground data-[state=active]:shadow-none -mb-px px-3"
          >
            Mastery
          </TabsTrigger>
          <TabsTrigger
            value="submissions"
            className="rounded-none border-b-2 border-transparent data-[state=active]:border-b-foreground data-[state=active]:bg-transparent data-[state=active]:text-foreground data-[state=active]:shadow-none -mb-px px-3"
          >
            Submissions
          </TabsTrigger>
          <TabsTrigger
            value="integrity"
            className="rounded-none border-b-2 border-transparent data-[state=active]:border-b-foreground data-[state=active]:bg-transparent data-[state=active]:text-foreground data-[state=active]:shadow-none -mb-px px-3"
          >
            Integrity
            <Badge variant="destructive" className="ml-2 h-4 min-w-4 px-1 text-[10px]">
              {FLAGS.length}
            </Badge>
          </TabsTrigger>
          <TabsTrigger
            value="notes"
            className="rounded-none border-b-2 border-transparent data-[state=active]:border-b-foreground data-[state=active]:bg-transparent data-[state=active]:text-foreground data-[state=active]:shadow-none -mb-px px-3"
          >
            Notes
          </TabsTrigger>
        </TabsList>

        {/* ----- Mastery ----- */}
        <TabsContent value="mastery" className="mt-6">
          <div className="grid gap-6 lg:grid-cols-5">
            <div className="lg:col-span-3 rounded-lg border border-border bg-card p-6">
              <div className="flex items-center justify-between mb-4">
                <div>
                  <h3 className="text-sm font-semibold">Concept mastery</h3>
                  <p className="text-xs text-muted-foreground mt-0.5">
                    Six tracked concepts · last 7 days
                  </p>
                </div>
                <RiskBadge level="moderate" />
              </div>
              <div className="h-72">
                <ResponsiveContainer width="100%" height="100%">
                  <RadarChart data={radarData} margin={{ top: 8, right: 16, bottom: 8, left: 16 }}>
                    <PolarGrid stroke="hsl(var(--border))" />
                    <PolarAngleAxis
                      dataKey="subject"
                      tick={{ fill: "hsl(var(--muted-foreground))", fontSize: 11 }}
                    />
                    <PolarRadiusAxis
                      domain={[0, 100]}
                      tick={{ fill: "hsl(var(--muted-foreground))", fontSize: 10 }}
                      stroke="hsl(var(--border))"
                    />
                    <Radar
                      name="Mastery"
                      dataKey="mastery"
                      stroke="hsl(var(--primary))"
                      fill="hsl(var(--primary))"
                      fillOpacity={0.25}
                      strokeWidth={1.5}
                    />
                  </RadarChart>
                </ResponsiveContainer>
              </div>
            </div>

            <div className="lg:col-span-2 space-y-3">
              <div>
                <h3 className="text-sm font-semibold">Top 3 struggling concepts</h3>
                <p className="text-xs text-muted-foreground mt-0.5">
                  Ranked by week-over-week decline
                </p>
              </div>
              <DecisionList items={STRUGGLING} />
            </div>
          </div>
        </TabsContent>

        {/* ----- Submissions ----- */}
        <TabsContent value="submissions" className="mt-6">
          <div className="rounded-lg border border-border bg-card overflow-hidden">
            <Table>
              <TableHeader>
                <TableRow className="bg-muted/40 hover:bg-muted/40">
                  <TableHead className="h-9 text-xs font-medium">Exercise</TableHead>
                  <TableHead className="h-9 text-xs font-medium">When</TableHead>
                  <TableHead className="h-9 text-xs font-medium">Status</TableHead>
                  <TableHead className="h-9 text-xs font-medium text-right">CDS</TableHead>
                  <TableHead className="h-9 text-xs font-medium">Anomalies</TableHead>
                </TableRow>
              </TableHeader>
              <TableBody>
                {SUBMISSIONS.map((s) => (
                  <TableRow key={s.id}>
                    <TableCell className="font-medium">{s.exercise}</TableCell>
                    <TableCell className="text-muted-foreground">{s.when}</TableCell>
                    <TableCell>
                      <Badge
                        variant={s.status === "Late" ? "warning" : "secondary"}
                        className="font-medium"
                      >
                        {s.status}
                      </Badge>
                    </TableCell>
                    <TableCell className="text-right">
                      <CDSPillDelta value={s.cds} showDelta={false} />
                    </TableCell>
                    <TableCell>
                      {s.anomalies.length > 0 ? (
                        <div className="flex flex-wrap items-center gap-1.5">
                          {s.anomalies.map((a) => (
                            <Badge
                              key={a}
                              variant="destructive"
                              className="font-medium text-[10px] uppercase tracking-wide"
                            >
                              <Flag className="h-3 w-3 mr-1" strokeWidth={2} />
                              {a.replace(/_/g, " ")}
                            </Badge>
                          ))}
                        </div>
                      ) : (
                        <span className="text-xs text-muted-foreground">—</span>
                      )}
                    </TableCell>
                  </TableRow>
                ))}
              </TableBody>
            </Table>
          </div>
        </TabsContent>

        {/* ----- Integrity ----- */}
        <TabsContent value="integrity" className="mt-6">
          <div className="space-y-3">
            <div>
              <h3 className="text-sm font-semibold">Active flags</h3>
              <p className="text-xs text-muted-foreground mt-0.5">
                {FLAGS.length} flag{FLAGS.length === 1 ? "" : "s"} require instructor review
              </p>
            </div>
            <DecisionList items={flagItems} onAction={openFlag} />
          </div>
        </TabsContent>

        {/* ----- Notes ----- */}
        <TabsContent value="notes" className="mt-6">
          <div className="space-y-6">
            <div className="rounded-lg border border-border bg-card p-4 space-y-3">
              <label
                htmlFor="instructor-note"
                className="text-xs font-medium text-muted-foreground"
              >
                New note
              </label>
              <Textarea
                id="instructor-note"
                value={note}
                onChange={(e) => setNote(e.target.value)}
                placeholder="Write a private note about this student…"
                className="min-h-[96px]"
              />
              <div className="flex items-center justify-end gap-2">
                <Button
                  variant="ghost"
                  size="sm"
                  onClick={() => setNote("")}
                  disabled={!note}
                >
                  Clear
                </Button>
                <Button
                  size="sm"
                  onClick={handleSaveNote}
                  disabled={!note.trim()}
                  className="font-medium"
                >
                  Save note
                </Button>
              </div>
            </div>

            <div className="space-y-3">
              <h3 className="text-sm font-semibold">Past notes</h3>
              <ul className="rounded-lg border border-border bg-card divide-y divide-border overflow-hidden">
                {notes.map((n) => (
                  <li key={n.id} className="p-4 space-y-1">
                    <div className="flex items-center justify-between gap-2">
                      <span className="text-sm font-medium">{n.author}</span>
                      <span className="text-xs text-muted-foreground font-mono tabular-nums">
                        {n.when}
                      </span>
                    </div>
                    <p className="text-sm text-foreground">{n.body}</p>
                  </li>
                ))}
              </ul>
            </div>
          </div>
        </TabsContent>
      </Tabs>

      {/* ---------- Flag Drawer ---------- */}
      <DetailDrawer
        open={drawerOpen}
        onClose={() => setDrawerOpen(false)}
        title={drawerFlag?.title ?? "Flag detail"}
        subtitle={drawerFlag?.subtitle}
      >
        {drawerFlag ? (
          <div className="space-y-6">
            <div className="flex items-center justify-between">
              <span className="text-xs uppercase tracking-wider text-muted-foreground">
                Classification
              </span>
              <RiskBadge level={drawerFlag.level} />
            </div>

            <div className="rounded-md border border-border bg-muted/40 p-4 space-y-2">
              <p className="text-xs uppercase tracking-wider text-muted-foreground">
                Evidence
              </p>
              <p className="text-sm font-mono tabular-nums">
                {drawerFlag.subtitle}
              </p>
              <p className="text-xs text-muted-foreground">
                Exercise: Recursion I · Session #4821 · 2h ago
              </p>
            </div>

            <div className="space-y-2">
              <p className="text-xs uppercase tracking-wider text-muted-foreground">
                Recommended action
              </p>
              <p className="text-sm text-foreground">
                Schedule a 1:1 to walk through the Recursion I submission step-by-step.
                Compare session timing against the section baseline (median 12m).
              </p>
            </div>

            <div className="flex items-center justify-end gap-2 pt-2 border-t border-border">
              <Button
                variant="outline"
                size="sm"
                onClick={() => setDrawerOpen(false)}
              >
                Dismiss
              </Button>
              <Button size="sm" className="font-medium">
                <MessageSquare className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                Message student
              </Button>
            </div>
          </div>
        ) : null}
      </DetailDrawer>
    </div>
  );
}
