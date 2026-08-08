import { useMemo, useState, useEffect } from "react";
import { useParams, useSearchParams, Link } from "react-router-dom";
import ConceptRadarPanel from "@/components/concept-radar/ConceptRadarPanel";
import {
  MoreHorizontal,
  ArrowLeft,
  ArrowRight,
  Download,
  UserMinus,
  AlertTriangle,
  RefreshCw,
} from "lucide-react";
import { Button } from "@/components/ui/button";
import { Badge } from "@/components/ui/badge";
import { Tabs, TabsList, TabsTrigger, TabsContent } from "@/components/ui/tabs";
import { Avatar, AvatarFallback } from "@/components/ui/avatar";
import { ResponsiveTable } from "@/components/ui/responsive-table";
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
import RiskBadge from "@/components/ui/risk-badge";
import { tierForMastery, NEW_TIER_META } from "@/components/ui/mastery-bar";
import DetailDrawer from "@/components/ui/detail-drawer";
import DecisionList from "@/components/ui/decision-list";
import { flagTypeLabel } from "@/lib/flagTypes";
import { formatDateAgo, formatDuration } from "@/lib/format";
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

export default function InstructorStudentDetail() {
  const { id } = useParams();
  const [searchParams] = useSearchParams();
  const sectionId = searchParams.get("section");
  const [sectionName, setSectionName] = useState(null);
  const [tab, setTab] = useState("mastery");
  const [drawerOpen, setDrawerOpen] = useState(false);
  const [drawerFlag, setDrawerFlag] = useState(null);
  const [dismissing, setDismissing] = useState(false);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [retryCount, setRetryCount] = useState(0);

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
    if (sectionId) {
      api.get(`/api/sections/${sectionId}`).then(res => {
        if (!cancelled) setSectionName(res.data.name);
      }).catch((err) => console.warn('Failed to load section name:', err.message));
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
          <div className="flex items-center gap-2 shrink-0">
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
          <div className="grid gap-6 lg:grid-cols-5">
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
          <ResponsiveTable
            columns={[
              { key: 'exercise', header: 'Exercise', mobile: 'primary',
                renderCell: (s) => <span className="font-medium">{s.exercise_title}</span>,
              },
              { key: 'attempt', header: 'Attempt', mobile: 'label',
                renderCell: (s) => <span className="text-muted-foreground">#{s.attempt_number}</span>,
              },
              { key: 'when', header: 'When', mobile: 'label',
                renderCell: (s) => <span className="text-muted-foreground">{formatDateAgo(s.submitted_at)}</span>,
              },
              { key: 'passed', header: 'Passed', mobile: 'label',
                renderCell: (s) => (
                  <Badge variant={s.is_correct ? "secondary" : "destructive"} className="font-medium">
                    {s.is_correct ? "Pass" : "Fail"}
                  </Badge>
                ),
              },
              { key: 'time', header: 'Time', mobile: 'hidden',
                renderCell: (s) => (
                  <span className="font-mono tabular-nums text-xs text-muted-foreground block text-right">
                    {formatDuration(s.time_spent_seconds)}
                  </span>
                ),
              },
            ]}
            data={submissions}
            keyExtractor={(s) => String(s.id)}
            emptyMessage="No submissions yet"
          />
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
    </div>
  );
}
