import { useMemo, useState, useEffect } from "react";
import { useParams, Link } from "react-router-dom";
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
  AlertTriangle,
  RefreshCw,
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
import api from "@/services/api";

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

function timeAgo(dateStr) {
  if (!dateStr) return "—";
  const ms = Date.now() - new Date(dateStr).getTime();
  const mins = Math.floor(ms / 60000);
  if (mins < 1) return "just now";
  if (mins < 60) return `${mins}m`;
  const hours = Math.floor(mins / 60);
  if (hours < 24) return `${hours}h`;
  const days = Math.floor(hours / 24);
  return `${days}d`;
}

const TOOLTIP_STYLE = {
  backgroundColor: "hsl(var(--popover))",
  border: "1px solid hsl(var(--border))",
  borderRadius: "6px",
  fontSize: "12px",
  color: "hsl(var(--popover-foreground))",
};

export default function InstructorStudentDetail() {
  const { id } = useParams();
  const [tab, setTab] = useState("mastery");
  const [drawerOpen, setDrawerOpen] = useState(false);
  const [drawerFlag, setDrawerFlag] = useState(null);
  const [note, setNote] = useState("");
  const [notes, setNotes] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);

  const [data, setData] = useState(null);

  useEffect(() => {
    if (!id) return;
    let cancelled = false;
    const fetchData = async () => {
      setLoading(true);
      setError(null);
      try {
        const [profileRes, subRes] = await Promise.all([
          api.get(`/api/analytics/student/${id}/profile`),
          api.get(`/api/analytics/student/${id}/submissions`).catch(() => ({ data: null })),
        ]);
        if (!cancelled) {
          setData({
            profile: profileRes.data,
            submissions: subRes.data,
          });
        }
      } catch (err) {
        if (!cancelled) setError(err.response?.data?.error || "Failed to load student data");
      } finally {
        if (!cancelled) setLoading(false);
      }
    };
    fetchData();
    return () => { cancelled = true; };
  }, [id]);

  const profile = data?.profile || [];
  const student = data?.submissions?.student || { name: "Student", email: "" };
  const submissions = data?.submissions?.submissions || [];
  const cdsScores = data?.submissions?.cdsScores || [];
  const integrityFlags = data?.submissions?.integrityFlags || [];

  const avgCds = useMemo(() => {
    const vals = cdsScores.map((s) => parseFloat(s.cds)).filter((v) => !isNaN(v));
    return vals.length ? vals.reduce((a, b) => a + b, 0) / vals.length : 0;
  }, [cdsScores]);

  const conceptMastery = useMemo(() => {
    const map = {};
    cdsScores.forEach((s) => {
      if (!s.concept_name) return;
      const cds = parseFloat(s.cds);
      if (isNaN(cds)) return;
      if (!map[s.concept_name]) map[s.concept_name] = [];
      map[s.concept_name].push(cds);
    });
    return Object.entries(map).map(([name, vals]) => {
      const avg = vals.reduce((a, b) => a + b, 0) / vals.length;
      const pct = Math.round(avg * 100);
      const level = avg <= 0.33 ? "low" : avg <= 0.66 ? "moderate" : "high";
      return { concept: name, value: pct, level };
    });
  }, [cdsScores]);

  const radarData = useMemo(
    () => conceptMastery.map((c) => ({ subject: c.concept, mastery: c.value })),
    [conceptMastery],
  );

  const struggling = useMemo(() =>
    [...conceptMastery]
      .sort((a, b) => a.value - b.value)
      .slice(0, 3)
      .map((c, i) => ({
        id: String(i),
        title: c.concept,
        subtitle: `Mastery ${c.value}%`,
        meta: c.level === "low" ? "needs work" : "fair",
        level: c.level,
      })),
  [conceptMastery]);

  const flagCount = integrityFlags.length;
  const flagItems = useMemo(() =>
    integrityFlags.map((f) => ({
      id: f.id,
      title: `${f.flag_type} · ${f.exercise_title || ""}`,
      subtitle: f.evidence?.summary || f.flag_type,
      meta: timeAgo(f.created_at),
      level: f.severity,
      badge: <RiskBadge level={f.severity} />,
    })),
  [integrityFlags]);

  const activeFlags = integrityFlags.filter((f) => f.status !== "resolved");

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

  const handleExportSubmissions = () => {
    if (!submissions.length) return;
    const csv = [
      "Exercise,Attempt,Passed,Submitted",
      ...submissions.map((s) =>
        [s.exercise_title, s.attempt_number, s.is_correct ? "Yes" : "No", s.submitted_at].join(",")
      ),
    ].join("\n");
    const blob = new Blob([csv], { type: "text/csv" });
    const url = URL.createObjectURL(blob);
    const a = document.createElement("a");
    a.href = url;
    a.download = `student-${id}-submissions.csv`;
    a.click();
    URL.revokeObjectURL(url);
  };

  if (loading) {
    return (
      <div className="space-y-6 sm:space-y-8">
        <div className="rounded-lg border border-border bg-card/50 py-12 px-6 text-center">
          <p className="text-sm font-semibold text-foreground">Loading student data…</p>
        </div>
      </div>
    );
  }

  if (error) {
    return (
      <div className="space-y-6 sm:space-y-8">
        <div className="flex items-center gap-3 rounded-lg border border-destructive/30 bg-destructive/5 px-4 py-3">
          <AlertTriangle className="h-4 w-4 text-destructive shrink-0" />
          <p className="text-sm text-destructive flex-1">{error}</p>
          <Button size="sm" variant="outline" className="border-destructive/30 text-destructive" onClick={() => window.location.reload()}>
            <RefreshCw className="h-3.5 w-3.5 mr-1.5" />
            Retry
          </Button>
        </div>
      </div>
    );
  }

  const cdsSeries = cdsScores.slice(0, 7).map((s) => parseFloat(s.cds)).reverse();
  while (cdsSeries.length < 7) cdsSeries.unshift(avgCds);

  return (
    <div className="space-y-6 sm:space-y-8">
      {/* ---------- PageHeader ---------- */}
      <div className="space-y-2">
        <PageBreadcrumb
          crumbs={[
            { label: "Students", href: "/instructor/students" },
            { label: student.name },
          ]}
        />
        <div className="flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between">
          <div className="flex items-center gap-4 min-w-0">
            <Avatar className="h-12 w-12">
              <AvatarFallback className="text-sm font-semibold text-muted-foreground">
                {initials(student.name)}
              </AvatarFallback>
            </Avatar>
            <div className="min-w-0 space-y-1">
              <div className="flex items-center gap-2">
                <h1 className="text-2xl font-semibold tracking-tight truncate">
                  {student.name}
                </h1>
                <RiskBadge level={avgCds > 0.50 ? "high" : avgCds > 0.33 ? "moderate" : "low"} />
              </div>
              <p className="text-sm text-muted-foreground truncate">
                {student.email}
              </p>
            </div>
          </div>
          <div className="flex items-center gap-2 shrink-0">
            <Button
              variant="outline"
              size="sm"
              className="font-medium"
              onClick={() => student.email && window.open(`mailto:${student.email}`)}
            >
              <Mail className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
              Email
            </Button>
            <DropdownMenu>
              <DropdownMenuTrigger asChild>
                <Button variant="outline" size="icon" aria-label="More actions">
                  <MoreHorizontal className="h-4 w-4" strokeWidth={1.5} />
                </Button>
              </DropdownMenuTrigger>
              <DropdownMenuContent align="end">
                <DropdownMenuItem onClick={handleExportSubmissions}>
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
        eyebrow={activeFlags.length > 0 ? "Flagged" : "Student status"}
        insight={
          activeFlags.length > 0
            ? `${activeFlags.length} active flag${activeFlags.length === 1 ? "" : "s"}. Avg CDS ${Math.round(avgCds * 100)}%.`
            : `Avg CDS ${Math.round(avgCds * 100)}%${cdsScores.length > 1 ? ` · trend ${cdsSeries[cdsSeries.length - 1] > cdsSeries[0] ? "up" : "down"}` : ""}.`
        }
        action={
          <Button asChild size="sm" className="font-medium">
            <Link to="/instructor/integrity">
              View integrity dashboard
              <ArrowRight className="ml-1.5 h-3.5 w-3.5" strokeWidth={2} />
            </Link>
          </Button>
        }
      />

      {/* ---------- Evidence ---------- */}
      <EvidenceRow
        chips={[
          { label: "CDS", value: `${Math.round(avgCds * 100)}%`, delta: cdsSeries.length >= 2 ? parseFloat((cdsSeries[cdsSeries.length - 1] - cdsSeries[0]).toFixed(2)) : 0, series: cdsSeries, comparison: "over time" },
          { label: "Submissions", value: submissions.length, delta: null, comparison: "total" },
          { label: "Flags", value: flagCount, delta: null, comparison: "total" },
          { label: "Last Active", value: submissions.length > 0 ? timeAgo(submissions[0].submitted_at) : "—", delta: null, comparison: "" },
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
            {flagCount > 0 && (
              <Badge variant="destructive" className="ml-2 h-4 min-w-4 px-1 text-[10px]">
                {flagCount}
              </Badge>
            )}
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
                    {conceptMastery.length} tracked concepts
                  </p>
                </div>
                <RiskBadge level={avgCds > 0.50 ? "high" : avgCds > 0.33 ? "moderate" : "low"} />
              </div>
              <div className="h-72">
                {radarData.length > 0 ? (
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
                ) : (
                  <div className="flex items-center justify-center h-full text-muted-foreground text-sm">
                    No concept data available.
                  </div>
                )}
              </div>
            </div>

            <div className="lg:col-span-2 space-y-3">
              <div>
                <h3 className="text-sm font-semibold">Top struggling concepts</h3>
                <p className="text-xs text-muted-foreground mt-0.5">
                  Ranked by lowest mastery
                </p>
              </div>
              {struggling.length > 0 ? (
                <DecisionList items={struggling} />
              ) : (
                <p className="text-sm text-muted-foreground text-center py-8">No concept data yet.</p>
              )}
            </div>
          </div>
        </TabsContent>

        {/* ----- Submissions ----- */}
        <TabsContent value="submissions" className="mt-6">
          {submissions.length > 0 ? (
            <div className="rounded-lg border border-border bg-card overflow-hidden">
              <Table>
                <TableHeader>
                  <TableRow className="bg-muted/40 hover:bg-muted/40">
                    <TableHead className="h-9 text-xs font-medium">Exercise</TableHead>
                    <TableHead className="h-9 text-xs font-medium">Attempt</TableHead>
                    <TableHead className="h-9 text-xs font-medium">When</TableHead>
                    <TableHead className="h-9 text-xs font-medium">Passed</TableHead>
                    <TableHead className="h-9 text-xs font-medium text-right">Time</TableHead>
                  </TableRow>
                </TableHeader>
                <TableBody>
                  {submissions.map((s) => (
                    <TableRow key={s.id}>
                      <TableCell className="font-medium">{s.exercise_title}</TableCell>
                      <TableCell className="text-muted-foreground">#{s.attempt_number}</TableCell>
                      <TableCell className="text-muted-foreground">{timeAgo(s.submitted_at)}</TableCell>
                      <TableCell>
                        <Badge variant={s.is_correct ? "secondary" : "destructive"} className="font-medium">
                          {s.is_correct ? "Pass" : "Fail"}
                        </Badge>
                      </TableCell>
                      <TableCell className="text-right font-mono tabular-nums text-xs text-muted-foreground">
                        {s.time_spent_seconds ? `${Math.round(s.time_spent_seconds / 60)}m` : "—"}
                      </TableCell>
                    </TableRow>
                  ))}
                </TableBody>
              </Table>
            </div>
          ) : (
            <div className="rounded-lg border border-dashed border-border bg-card/50 py-12 px-6 text-center">
              <p className="text-sm font-semibold text-foreground">No submissions yet</p>
              <p className="text-sm text-muted-foreground mt-1">
                Submissions will appear here once the student submits exercises.
              </p>
            </div>
          )}
        </TabsContent>

        {/* ----- Integrity ----- */}
        <TabsContent value="integrity" className="mt-6">
          {flagItems.length > 0 ? (
            <div className="space-y-3">
              <div>
                <h3 className="text-sm font-semibold">Active flags</h3>
                <p className="text-xs text-muted-foreground mt-0.5">
                  {flagItems.length} flag{flagItems.length === 1 ? "" : "s"}
                </p>
              </div>
              <DecisionList items={flagItems} onAction={openFlag} />
            </div>
          ) : (
            <div className="rounded-lg border border-dashed border-border bg-card/50 py-12 px-6 text-center">
              <p className="text-sm font-semibold text-foreground">No integrity flags</p>
              <p className="text-sm text-muted-foreground mt-1">
                This student has no flagged submissions.
              </p>
            </div>
          )}
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
                <Button variant="ghost" size="sm" onClick={() => setNote("")} disabled={!note}>
                  Clear
                </Button>
                <Button size="sm" onClick={handleSaveNote} disabled={!note.trim()} className="font-medium">
                  Save note
                </Button>
              </div>
            </div>

            <div className="space-y-3">
              <h3 className="text-sm font-semibold">Past notes</h3>
              {notes.length > 0 ? (
                <ul className="rounded-lg border border-border bg-card divide-y divide-border overflow-hidden">
                  {notes.map((n) => (
                    <li key={n.id} className="p-4 space-y-1">
                      <div className="flex items-center justify-between gap-2">
                        <span className="text-sm font-medium">{n.author}</span>
                        <span className="text-xs text-muted-foreground font-mono tabular-nums">{n.when}</span>
                      </div>
                      <p className="text-sm text-foreground">{n.body}</p>
                    </li>
                  ))}
                </ul>
              ) : (
                <p className="text-sm text-muted-foreground text-center py-8">No notes yet.</p>
              )}
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
              <p className="text-xs uppercase tracking-wider text-muted-foreground">Evidence</p>
              <p className="text-sm font-mono tabular-nums">{drawerFlag.subtitle}</p>
            </div>

            <div className="flex items-center justify-end gap-2 pt-2 border-t border-border">
              <Button variant="outline" size="sm" onClick={() => setDrawerOpen(false)}>
                Dismiss
              </Button>
              <Button size="sm" className="font-medium" onClick={() => student.email && window.open(`mailto:${student.email}`)}>
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
