import { useMemo, useState, useEffect } from "react";
import { useParams, useSearchParams, Link } from "react-router-dom";
import ConceptRadarPanel from "@/components/concept-radar/ConceptRadarPanel";
import {
  MoreHorizontal,
  ArrowLeft,
  ArrowRight,
  UserMinus,
  AlertTriangle,
  RefreshCw,
  CheckCircle,
  XCircle,
  ChevronRight,
  Clock,
  Flag,
} from "lucide-react";
import { Button } from "@/components/ui/button";
import { Badge } from "@/components/ui/badge";
import ExportDropdown from "@/components/ui/export-dropdown";
import VisualReportButton from "@/components/ui/visual-report-button";
import { Tabs, TabsList, TabsTrigger, TabsContent } from "@/components/ui/tabs";
import { Avatar, AvatarFallback } from "@/components/ui/avatar";
import {
  DropdownMenu,
  DropdownMenuContent,
  DropdownMenuItem,
  DropdownMenuTrigger,
} from "@/components/ui/dropdown-menu";
import PageBreadcrumb from "@/components/ui/page-breadcrumb";
import InsightHeader from "@/components/ui/insight-header";
import EvidenceRow from "@/components/ui/evidence-row";
import RiskBadge from "@/components/ui/risk-badge";
import { tierForMastery, NEW_TIER_META } from "@/components/ui/mastery-bar";
import DetailDrawer from "@/components/ui/detail-drawer";
import SubmissionDetailDrawer from "@/components/analytics/SubmissionDetailDrawer";
import DecisionList from "@/components/ui/decision-list";
import { flagTypeLabel } from "@/lib/flagTypes";
import { formatDateAgo, formatDuration } from "@/lib/format";
import { cn } from "@/lib/utils";
import api from "@/services/api";
import useLastSection from "@/hooks/useLastSection";

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

function evidenceToString(evidence) {
  if (!evidence) return "No evidence";
  if (typeof evidence === "string") return evidence;
  try {
    const obj = typeof evidence === "string" ? JSON.parse(evidence) : evidence;
    if (Array.isArray(obj)) return obj.join("\n");
    if (typeof obj === "object") {
      return Object.entries(obj)
        .map(([k, v]) => `${k}: ${v}`)
        .join("\n");
    }
    return String(evidence);
  } catch {
    return String(evidence);
  }
}

const SEVERITY_RISK_LEVEL = { high: "high", medium: "moderate", low: "low", na: "na" };

const STATUS_BADGE = {
  done: {
    label: "Done",
    cls: "bg-emerald-500/10 text-emerald-400 border-emerald-500/30",
    icon: CheckCircle,
  },
  late: {
    label: "Late",
    cls: "bg-amber-500/10 text-amber-400 border-amber-500/30",
    icon: Clock,
  },
  missing: {
    label: "Missing",
    cls: "bg-muted/40 text-muted-foreground border-border",
    icon: XCircle,
  },
};

function StatusBadge({ status }) {
  const meta = STATUS_BADGE[status] || STATUS_BADGE.missing;
  const Icon = meta.icon;
  return (
    <Badge variant="outline" className={`text-[11px] font-medium ${meta.cls}`}>
      <Icon className="h-3 w-3 mr-1" strokeWidth={1.5} />
      {meta.label}
    </Badge>
  );
}

// CDS tier text colors — mirrors Heatmap.jsx CDS_TIERS (high CDS = struggling).
function cdsTierText(cds) {
  const v = Number(cds);
  if (cds === null || cds === undefined || Number.isNaN(v)) return "text-muted-foreground";
  if (v <= 0.20) return "text-slate-500";
  if (v <= 0.40) return "text-emerald-400";
  if (v <= 0.60) return "text-amber-400";
  if (v <= 0.80) return "text-orange-400";
  return "text-rose-400";
}

function formatCds(cds) {
  const v = Number(cds);
  return Number.isNaN(v) ? "—" : v.toFixed(2);
}

export default function InstructorStudentDetail() {
  const { id } = useParams();
  const [searchParams] = useSearchParams();
  const [lastSectionId] = useLastSection();
  const sectionId = searchParams.get("section") ?? lastSectionId;
  const [sectionName, setSectionName] = useState(null);
  const [tab, setTab] = useState("mastery");
  const [drawerOpen, setDrawerOpen] = useState(false);
  const [drawerFlag, setDrawerFlag] = useState(null);
  const [dismissing, setDismissing] = useState(false);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [retryCount, setRetryCount] = useState(0);
  const [subStatusFilter, setSubStatusFilter] = useState("all");
  const [expandedExercise, setExpandedExercise] = useState(null);
  const [selectedSubmission, setSelectedSubmission] = useState(null);

  const [data, setData] = useState(null);
  const [sectionExercises, setSectionExercises] = useState([]);

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
    if (sectionId) {
      api.get(`/api/sections/${sectionId}`).then(res => {
        if (!cancelled) setSectionName(res.data.name);
      }).catch((err) => console.warn('Failed to load section name:', err.message));
      api.get(`/api/sections/${sectionId}/exercises`).then(res => {
        if (!cancelled) setSectionExercises(Array.isArray(res.data) ? res.data : []);
      }).catch(() => {
        if (!cancelled) setSectionExercises([]);
      });
    }
    return () => { cancelled = true; };
  }, [id, sectionId, retryCount]);

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
      const mastery = Math.round((1 - avg) * 100);
      return { concept: name, mastery };
    });
  }, [cdsScores]);

  const struggling = useMemo(() =>
    [...conceptMastery]
      .filter((c) => {
        const tier = tierForMastery(c.mastery);
        return tier === "significant" || tier === "critical";
      })
      .sort((a, b) => a.mastery - b.mastery)
      .slice(0, 3)
      .map((c, i) => {
        const tier = tierForMastery(c.mastery);
        const meta = NEW_TIER_META[tier];
        return {
          id: String(i),
          title: c.concept,
          subtitle: `Mastery ${c.mastery}%`,
          badge: (
            <Badge className={`bg-white/[0.03] border-white/[0.08] ${meta.text}`}>
              {meta.label}
            </Badge>
          ),
          level: tier,
        };
      }),
  [conceptMastery]);

  const flagCount = integrityFlags.length;

  const flagItems = useMemo(() =>
    integrityFlags.map((f) => ({
      id: f.id,
      title: `${flagTypeLabel(f.flag_type)} · ${f.exercise_title || ""}`,
      subtitle: f.evidence?.summary || f.flag_type,
      meta: formatDateAgo(f.created_at),
      level: f.severity,
      badge: <RiskBadge level={f.severity} />,
    })),
  [integrityFlags]);

  // CDS per exercise (keyed by exercise_id) for the submissions table.
  const cdsByExercise = useMemo(() => {
    const map = new Map();
    for (const s of cdsScores) {
      const key = Number(s.exercise_id);
      if (!Number.isNaN(key) && !map.has(key)) map.set(key, s);
    }
    return map;
  }, [cdsScores]);

  // ── Submission groups ─────────────────────────────────────────────
  // One group per exercise. Groups with zero attempts become "missing"
  // (only when we know the section's full exercise list); "late" when the
  // latest attempt landed after the exercise deadline.
  const submissionGroups = useMemo(() => {
    const byExercise = new Map();

    // Start from the section's exercise list so exercises the student never
    // attempted still surface as "missing".
    for (const ex of sectionExercises) {
      const id = Number(ex.id);
      if (!byExercise.has(id)) {
        byExercise.set(id, {
          exercise_id: id,
          exercise_title: ex.title || `Exercise #${id}`,
          deadline: ex.deadline || null,
          attempts: [],
          attempt_count: 0,
          latest_is_correct: null,
          latest_submitted_at: null,
          total_time_spent_seconds: 0,
          flagged: false,
        });
      }
    }

    // Fold in actual submissions (they may reference exercises missing from
    // the section list if the exercises fetch failed).
    for (const s of submissions) {
      const id = Number(s.exercise_id);
      let g = byExercise.get(id);
      if (!g) {
        g = {
          exercise_id: id,
          exercise_title: s.exercise_title || `Exercise #${id}`,
          deadline: s.deadline || null,
          attempts: [],
          attempt_count: 0,
          latest_is_correct: null,
          latest_submitted_at: null,
          total_time_spent_seconds: 0,
          flagged: false,
        };
        byExercise.set(id, g);
      }
      g.attempts.push(s);
      g.attempt_count += 1;
      g.total_time_spent_seconds += (s.time_spent_seconds || 0);
      if (s.is_correct) g.latest_is_correct = true;
      const ts = new Date(s.submitted_at).getTime();
      if (!g.latest_submitted_at || ts > new Date(g.latest_submitted_at).getTime()) {
        g.latest_submitted_at = s.submitted_at;
      }
      if (integrityFlags.some((f) =>
        f.exercise_title && String(f.exercise_title) === String(s.exercise_title)
      )) {
        g.flagged = true;
      }
    }

    const groups = Array.from(byExercise.values());

    // Status: missing → late → done (latest attempt vs deadline).
    // Attach this student's CDS for the exercise (null when unscored).
    for (const g of groups) {
      const c = cdsByExercise.get(Number(g.exercise_id));
      g.cds = c?.cds ?? null;
      g.cds_classification = c?.classification ?? null;
      g.status =
        g.attempt_count === 0
          ? "missing"
          : g.deadline &&
              g.latest_submitted_at &&
              new Date(g.latest_submitted_at).getTime() > new Date(g.deadline).getTime()
            ? "late"
            : "done";
    }

    // Sort: exercises with attempts first (most recent submission first),
    // then missing ones by deadline.
    return groups.sort((a, b) => {
      if (a.attempt_count > 0 && b.attempt_count === 0) return -1;
      if (a.attempt_count === 0 && b.attempt_count > 0) return 1;
      if (a.attempt_count === 0 && b.attempt_count === 0) {
        return (a.deadline || "") < (b.deadline || "") ? -1 : 1;
      }
      return (b.latest_submitted_at || "") < (a.latest_submitted_at || "") ? -1 : 1;
    });
  }, [submissions, sectionExercises, integrityFlags, cdsByExercise]);

  const filteredGroups = useMemo(() => {
    if (subStatusFilter === "all") return submissionGroups;
    return submissionGroups.filter((g) => g.status === subStatusFilter);
  }, [submissionGroups, subStatusFilter]);

  const doneCount = submissionGroups.filter((g) => g.status === "done").length;
  const lateCount = submissionGroups.filter((g) => g.status === "late").length;
  const missingCount = submissionGroups.filter((g) => g.status === "missing").length;

  const activeFlags = integrityFlags.filter((f) => f.status !== "resolved");

  const openFlag = (item) => {
    const full = integrityFlags.find((f) => f.id === item.id) || item;
    setDrawerFlag(full);
    setDrawerOpen(true);
  };

  const dismissFlag = async () => {
    if (!drawerFlag?.id) return;
    setDismissing(true);
    try {
      await api.put(`/api/analytics/integrity-flags/${drawerFlag.id}/review`, {
        status: "dismissed",
        instructor_note: "Dismissed from student detail",
      });
      setData((prev) => ({
        ...prev,
        submissions: {
          ...prev?.submissions,
          integrityFlags: (prev?.submissions?.integrityFlags || []).filter(
            (f) => f.id !== drawerFlag.id,
          ),
        },
      }));
      setDrawerOpen(false);
    } catch (err) {
      console.error("Dismiss failed:", err);
    } finally {
      setDismissing(false);
    }
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
          <Button size="sm" variant="outline" className="border-destructive/30 text-destructive" onClick={() => setRetryCount(c => c + 1)}>
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
        {sectionId && (
          <Link
            to={`/instructor/sections/${sectionId}`}
            className="inline-flex items-center gap-1 text-sm text-muted-foreground hover:text-foreground transition-colors"
          >
            <ArrowLeft className="h-3.5 w-3.5" strokeWidth={1.5} />
            Back to roster
          </Link>
        )}
        <PageBreadcrumb
          crumbs={sectionId
            ? [
                { label: "Sections", href: "/instructor/sections" },
                { label: sectionName || "Section", href: `/instructor/sections/${sectionId}` },
                { label: student.name },
              ]
            : [
                { label: "Students", href: "/instructor/students" },
                { label: student.name },
              ]
          }
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
                <RiskBadge level={avgCds <= 0.20 ? "low" : avgCds <= 0.40 ? "moderate" : avgCds <= 0.80 ? "high" : "critical"} />
              </div>
              <p className="text-sm text-muted-foreground truncate">
                {student.email}
              </p>
            </div>
          </div>
          <div className="flex flex-wrap items-center gap-2 shrink-0">
            <ExportDropdown
              sectionId={sectionId}
              domain="summary"
              studentId={id}
              formats={["csv", "xlsx"]}
              label="Student Summary"
            />
            <ExportDropdown
              sectionId={sectionId}
              domain="student_attempts"
              studentId={id}
              formats={["csv", "xlsx"]}
              label="Export Submissions"
            />
            <VisualReportButton sectionId={sectionId} studentId={id} label="Dossier (PDF)" />
            <DropdownMenu>
              <DropdownMenuTrigger asChild>
                <Button variant="outline" size="icon" aria-label="More actions">
                  <MoreHorizontal className="h-4 w-4" strokeWidth={1.5} />
                </Button>
              </DropdownMenuTrigger>
              <DropdownMenuContent align="end">
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
          { label: "CDS", value: `${Math.round(avgCds * 100)}%`, delta: cdsSeries.length >= 2 ? parseFloat((cdsSeries[cdsSeries.length - 1] - cdsSeries[0]).toFixed(2)) : 0, series: cdsSeries, comparison: "over time", inverted: true },
          { label: "Submissions", value: submissions.length, delta: null, comparison: "total" },
          { label: "Flags", value: flagCount, delta: null, comparison: "total" },
          { label: "Last Active", value: submissions.length > 0 ? formatDateAgo(submissions[0].submitted_at) : "—", delta: null, comparison: "" },
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
        </TabsList>

        {/* ----- Mastery ----- */}
        <TabsContent value="mastery" className="mt-6">
          <div className="grid grid-cols-1 gap-6 lg:grid-cols-5">
            <div className="lg:col-span-3 min-h-80">
              <ConceptRadarPanel scores={profile} loading={loading} />
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
                <p className="text-sm text-muted-foreground text-center py-8">No concepts in the struggling threshold.</p>
              )}
            </div>
          </div>
        </TabsContent>

        {/* ----- Submissions ----- */}
        <TabsContent value="submissions" className="mt-6">
          {/* Status filter tabs — same semantics as the section submissions tab */}
          <div className="flex flex-wrap items-center gap-2">
            {[
              { key: "all", label: `All (${submissionGroups.length})` },
              { key: "done", label: `Done (${doneCount})` },
              { key: "late", label: `Late (${lateCount})` },
              { key: "missing", label: `Missing (${missingCount})` },
            ].map((tab) => (
              <button
                key={tab.key}
                type="button"
                onClick={() => setSubStatusFilter(tab.key)}
                className={cn(
                  "px-3 py-1 text-sm rounded-md transition-colors",
                  subStatusFilter === tab.key
                    ? "bg-muted text-foreground font-medium"
                    : "text-muted-foreground hover:text-foreground border border-transparent"
                )}
              >
                {tab.label}
              </button>
            ))}
          </div>

          {filteredGroups.length === 0 ? (
            <div className="rounded-lg border border-dashed border-border bg-card/50 py-12 px-6 text-center mt-6">
              <p className="text-sm font-semibold text-foreground">No submissions found</p>
              <p className="text-sm text-muted-foreground mt-1">
                {subStatusFilter === "missing"
                  ? "No missing exercises — this student attempted every exercise."
                  : "Submissions will appear here once the student submits exercises."}
              </p>
            </div>
          ) : (
            <div className="rounded-lg border border-border bg-card overflow-hidden mt-6">
              {/* Desktop header (hidden on mobile — rows render as cards) */}
              <div className="hidden sm:grid grid-cols-[minmax(0,1.6fr)_4rem_3.5rem_5rem_5rem_6rem_4.5rem] items-center gap-3 px-4 h-9 border-b border-border bg-muted/40">
                <span className="text-xs font-medium text-muted-foreground">Exercise</span>
                <span className="text-xs font-medium text-muted-foreground text-center">CDS</span>
                <span className="text-xs font-medium text-muted-foreground text-right">Attempts</span>
                <span className="text-xs font-medium text-muted-foreground text-right">Status</span>
                <span className="text-xs font-medium text-muted-foreground text-right">Total time</span>
                <span className="text-xs font-medium text-muted-foreground text-right">Submitted</span>
                <span className="text-xs font-medium text-muted-foreground"></span>
              </div>
              <ul className="divide-y divide-border">
                {filteredGroups.map((g) => {
                  const isExpanded = expandedExercise === g.exercise_id;
                  return (
                    <li key={g.exercise_id}>
                      {/* Group row */}
                      <div
                        onClick={() => g.attempt_count > 0 && setExpandedExercise(isExpanded ? null : g.exercise_id)}
                        className={cn(
                          "grid grid-cols-1 sm:grid-cols-[minmax(0,1.6fr)_4rem_3.5rem_5rem_5rem_6rem_4.5rem] items-start sm:items-center gap-1 sm:gap-3 px-4 py-3 sm:h-14 transition-colors",
                          g.attempt_count > 0 && "hover:bg-muted/40 cursor-pointer"
                        )}
                      >
                        {/* Exercise + status chips (mobile card) */}
                        <span className="min-w-0">
                          <span className="flex items-center gap-2 min-w-0">
                            <span className="text-sm font-medium text-foreground truncate">
                              {g.exercise_title}
                            </span>
                            {g.flagged && (
                              <Flag className="h-3.5 w-3.5 text-destructive shrink-0" strokeWidth={1.5} />
                            )}
                          </span>
                          <span className="flex flex-wrap items-center gap-1.5 mt-1 sm:hidden">
                            <StatusBadge status={g.status} />
                            <span className="text-xs text-muted-foreground">×{g.attempt_count}</span>
                            <span className={cn("text-xs tabular-nums", cdsTierText(g.cds))}>
                              CDS {g.cds !== null && g.cds !== undefined ? formatCds(g.cds) : "—"}
                            </span>
                            {g.attempt_count > 0 && (
                              <span className="text-xs text-muted-foreground">
                                {formatDateAgo(g.latest_submitted_at)}
                              </span>
                            )}
                          </span>
                        </span>
                        {g.cds !== null && g.cds !== undefined ? (
                          <span
                            title={g.cds_classification ? `CDS ${formatCds(g.cds)} · ${g.cds_classification}` : `CDS ${formatCds(g.cds)}`}
                            className={cn("hidden sm:block text-sm tabular-nums text-center font-medium", cdsTierText(g.cds))}
                          >
                            {formatCds(g.cds)}
                          </span>
                        ) : (
                          <span className="hidden sm:block text-sm text-muted-foreground text-center">—</span>
                        )}
                        <span className="hidden sm:block text-sm text-muted-foreground text-right tabular-nums">
                          ×{g.attempt_count}
                        </span>
                        <span className="hidden sm:flex justify-end">
                          <StatusBadge status={g.status} />
                        </span>
                        <span className="hidden sm:block text-xs font-mono tabular-nums text-muted-foreground text-right">
                          {formatDuration(g.total_time_spent_seconds)}
                        </span>
                        <span className="hidden sm:block text-xs font-mono tabular-nums text-muted-foreground text-right">
                          {g.attempt_count > 0 ? formatDateAgo(g.latest_submitted_at) : "—"}
                        </span>
                        <span className="flex justify-end">
                          {g.attempt_count > 0 ? (
                            <ChevronRight
                              className={cn(
                                "h-4 w-4 text-muted-foreground transition-transform duration-200",
                                isExpanded && "rotate-90 text-foreground"
                              )}
                              strokeWidth={1.5}
                            />
                          ) : (
                            <span className="w-4" />
                          )}
                        </span>
                      </div>

                      {/* Expanded attempts */}
                      {isExpanded && g.attempt_count > 0 && (
                        <div className="bg-muted/20 border-l-2 border-l-primary/40">
                          {g.attempts.map((a) => (
                            <div
                              key={a.id}
                              className="grid grid-cols-1 sm:grid-cols-[minmax(0,1.6fr)_4rem_3.5rem_5rem_5rem_6rem_4.5rem] items-start sm:items-center gap-1 sm:gap-3 px-4 pl-8 sm:h-11"
                            >
                              <span className="text-sm text-foreground font-medium tabular-nums">
                                #{a.attempt_number}
                              </span>
                              <span className="hidden sm:block"></span>
                              <span className="hidden sm:block"></span>
                              <span className="sm:hidden flex items-center gap-2 mt-0.5">
                                <Badge
                                  variant={a.is_correct ? "secondary" : "destructive"}
                                  className="font-medium text-[11px]"
                                >
                                  {a.is_correct ? "Pass" : "Fail"}
                                </Badge>
                                <span className="text-xs text-muted-foreground">
                                  {formatDateAgo(a.submitted_at)}
                                </span>
                              </span>
                              <span className="hidden sm:flex justify-end">
                                <Badge
                                  variant={a.is_correct ? "secondary" : "destructive"}
                                  className="font-medium text-[11px]"
                                >
                                  {a.is_correct ? "Pass" : "Fail"}
                                </Badge>
                              </span>
                              <span className="hidden sm:flex items-center justify-end gap-1 text-xs font-mono tabular-nums text-muted-foreground">
                                <Clock className="h-3 w-3" strokeWidth={1.5} />
                                {formatDuration(a.time_spent_seconds)}
                              </span>
                              <span className="hidden sm:block text-xs font-mono tabular-nums text-muted-foreground text-right">
                                {formatDateAgo(a.submitted_at)}
                              </span>
                              <span className="flex justify-end">
                                <Button
                                  variant="ghost"
                                  size="sm"
                                  className="h-7 px-2 text-xs"
                                  onClick={(ev) => {
                                    ev.stopPropagation();
                                    setSelectedSubmission({
                                      ...a,
                                      student_name: student.name,
                                      student_email: student.email,
                                    });
                                  }}
                                >
                                  Review
                                </Button>
                              </span>
                            </div>
                          ))}
                        </div>
                      )}
                    </li>
                  );
                })}
              </ul>
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
      </Tabs>

      {/* ---------- Flag Drawer ---------- */}
      <DetailDrawer
        open={drawerOpen}
        onClose={() => setDrawerOpen(false)}
        title={drawerFlag?.flag_type ?? "Flag detail"}
        subtitle={drawerFlag?.exercise_title ? `${drawerFlag.exercise_title}` : ""}
      >
        {drawerFlag ? (
          <div className="space-y-6">
            <div className="flex items-center justify-between">
              <div className="space-y-1">
                <p className="text-xs uppercase tracking-wider text-muted-foreground">
                  Classification
                </p>
                <RiskBadge level={SEVERITY_RISK_LEVEL[drawerFlag.severity] || "na"} />
              </div>
              <div className="text-right">
                <p className="text-xs uppercase tracking-wider text-muted-foreground">
                  Flagged
                </p>
                <p className="text-sm font-mono tabular-nums">{formatDateAgo(drawerFlag.created_at)}</p>
              </div>
            </div>

            <div className="rounded-md border border-border bg-muted/40 p-4 space-y-1">
              <p className="text-xs uppercase tracking-wider text-muted-foreground">
                Exercise
              </p>
              <p className="text-sm font-medium">{drawerFlag.exercise_title || "—"}</p>
              <p className="text-xs text-muted-foreground">Status: {drawerFlag.status || "flagged"}</p>
            </div>

            <div className="space-y-2">
              <p className="text-xs uppercase tracking-wider text-muted-foreground">
                Evidence
              </p>
              <pre className="rounded-md bg-muted/40 p-3 font-mono text-xs leading-relaxed overflow-x-auto whitespace-pre-wrap">
                {evidenceToString(drawerFlag.evidence)}
              </pre>
            </div>

            {drawerFlag.context_behaviors?.length > 0 && (
              <div className="space-y-2">
                <p className="text-xs uppercase tracking-wider text-muted-foreground">
                  Context behaviors
                </p>
                <ul className="list-disc list-inside text-sm text-muted-foreground space-y-1">
                  {drawerFlag.context_behaviors.map((b, i) => (
                    <li key={i}>{b}</li>
                  ))}
                </ul>
              </div>
            )}

            <div className="flex items-center justify-end gap-2 pt-2 border-t border-border">
              <Button
                variant="outline"
                size="sm"
                disabled={dismissing}
                onClick={dismissFlag}
              >
                {dismissing ? "Saving\u2026" : "Dismiss"}
              </Button>
            </div>
          </div>
        ) : null}
      </DetailDrawer>

      {/* ---------- Submission Drawer ---------- */}
      <SubmissionDetailDrawer
        submission={selectedSubmission}
        open={!!selectedSubmission}
        onClose={() => setSelectedSubmission(null)}
      />
    </div>
  );
}
