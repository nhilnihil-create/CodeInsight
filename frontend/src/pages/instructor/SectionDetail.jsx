import { useState, useCallback, useEffect } from "react";
import { useParams, Link, useNavigate, useSearchParams } from "react-router-dom";
import { useQuery } from "@tanstack/react-query";
import useLastSection from "@/hooks/useLastSection";
import {
  MoreHorizontal,
  ArrowRight,
  Copy,
  Users,
  FileText,
  AlertTriangle,
  RefreshCw,
  RotateCw,
  CheckCircle,
  Check,
} from "lucide-react";
import {
  DropdownMenu,
  DropdownMenuContent,
  DropdownMenuItem,
  DropdownMenuTrigger,
  DropdownMenuSeparator,
} from "@/components/ui/dropdown-menu";
import { Button } from "@/components/ui/button";
import ExportDropdown from "@/components/ui/export-dropdown";
import { Tabs, TabsList, TabsTrigger, TabsContent } from "@/components/ui/tabs";
import { toast } from "sonner";
import PageBreadcrumb from "@/components/ui/page-breadcrumb";
import InsightHeader from "@/components/ui/insight-header";
import EvidenceRow from "@/components/ui/evidence-row";
import RosterTab from "./tabs/RosterTab";
import AnalyticsTab from "./tabs/AnalyticsTab";
import SubmissionsTab from "./tabs/SubmissionsTab";
import SettingsTab from "./tabs/SettingsTab";
import api from "@/services/api";

async function fetchSection(id) {
  const { data } = await api.get(`/api/sections/${id}`);
  return data;
}

function buildSeriesArray(current) {
  return Array.from({ length: 7 }, () => current);
}

/** Build a real-looking CDS time series (flat when no trend data exists). */
function emptySeries() {
  return [];
}

export default function SectionDetail() {
  const { sectionId: id } = useParams();
  const navigate = useNavigate();
  const [searchParams, setSearchParams] = useSearchParams();
  const [, setLastSectionId] = useLastSection();

  useEffect(() => {
    if (id) setLastSectionId(Number(id));
  }, [id, setLastSectionId]);

  // Tab is URL-driven so deep links like ?tab=submissions&exercise=5 work.
  const [tab, setTab] = useState(() => {
    const t = searchParams.get("tab");
    return ["roster", "analytics", "submissions", "settings"].includes(t)
      ? t
      : "roster";
  });
  const [copied, setCopied] = useState(false);
  const [rotating, setRotating] = useState(false);

  const handleTabChange = useCallback(
    (value) => {
      setTab(value);
      const next = new URLSearchParams(searchParams);
      next.set("tab", value);
      setSearchParams(next, { replace: true });
    },
    [searchParams, setSearchParams]
  );

  const { data: section, isLoading, isError, refetch } = useQuery({
    queryKey: ["section", id],
    queryFn: () => fetchSection(id),
    enabled: !!id,
  });

  const buildTerm = useCallback(() => {
    if (!section) return "";
    const sem = section.semester || "Sem 1";
    const year = section.school_year || "";
    return year ? `${sem} · AY ${year}` : sem;
  }, [section]);

  const handleCopyJoinCode = useCallback(async () => {
    if (!section?.code) return;
    try {
      await navigator.clipboard.writeText(section.code);
      setCopied(true);
      toast.success("Join code copied to clipboard");
      setTimeout(() => setCopied(false), 2000);
    } catch {
      toast.error("Failed to copy join code");
    }
  }, [section]);

  const handleRotateCode = useCallback(async () => {
    if (!id) return;
    setRotating(true);
    try {
      const { data } = await api.post(`/api/sections/${id}/rotate-code`);
      toast.success(`New join code: ${data.code}`);
      refetch();
    } catch {
      toast.error("Failed to rotate join code");
    } finally {
      setRotating(false);
    }
  }, [id, refetch]);

  if (isLoading) {
    return (
      <div className="space-y-6 sm:space-y-8">
        <div className="rounded-lg border border-border bg-card/50 py-12 px-6 text-center">
          <p className="text-sm font-semibold text-foreground">Loading section…</p>
        </div>
      </div>
    );
  }

  if (isError || !section) {
    return (
      <div className="space-y-6 sm:space-y-8">
        <div className="flex items-center gap-3 rounded-lg border border-destructive/30 bg-destructive/5 px-4 py-3">
          <AlertTriangle className="h-4 w-4 text-destructive shrink-0" />
          <p className="text-sm text-destructive flex-1">Failed to load section details.</p>
          <Button size="sm" variant="outline" className="border-destructive/30 text-destructive hover:bg-destructive/10" onClick={() => refetch()}>
            <RefreshCw className="h-3.5 w-3.5 mr-1.5" strokeWidth={2} />
            Retry
          </Button>
        </div>
      </div>
    );
  }

  const atRisk = section.at_risk_count ?? 0;
  const avgCds = Number(section.avg_cds ?? 0);
  const flags = section.integrity_flags_count ?? 0;
  const totalSubmissions = section.total_submissions ?? 0;
  const studentCount = section.student_count ?? 0;
  const exerciseCount = section.exercise_count ?? 0;

  return (
    <div className="space-y-6 sm:space-y-8">
      {/* ---------- PageHeader ---------- */}
      <div className="space-y-2">
        <PageBreadcrumb
          crumbs={[
            { label: "Sections", href: "/instructor/sections" },
            { label: section.name },
          ]}
        />
        <div className="flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between">
          <div className="min-w-0">
            <h1 className="text-2xl font-semibold tracking-tight">
              {section.name} — {section.course_code}
            </h1>
            <p className="text-sm text-muted-foreground mt-1">
              {section.course_code} · {buildTerm()} · {studentCount} students
            </p>
            {section.code && (
              <div className="mt-3 flex items-center gap-2">
                <span className="text-xs font-mono tabular-nums text-muted-foreground">
                  Code: {section.code}
                </span>
                <button
                  type="button"
                  onClick={handleCopyJoinCode}
                  className="inline-flex items-center gap-1 text-xs font-mono text-muted-foreground hover:text-foreground transition-colors px-1.5 py-0.5 rounded hover:bg-accent"
                  aria-label={`Copy join code ${section.code}`}
                  title={`Copy code: ${section.code}`}
                >
                  {copied ? (
                    <CheckCircle className="h-3 w-3 text-emerald-400" strokeWidth={2} />
                  ) : (
                    <Copy className="h-3 w-3" strokeWidth={1.5} />
                  )}
                  {copied ? "Copied" : "Copy"}
                </button>
                <button
                  type="button"
                  onClick={handleRotateCode}
                  disabled={rotating}
                  className="inline-flex items-center gap-1 text-xs font-mono text-muted-foreground hover:text-foreground transition-colors px-1.5 py-0.5 rounded hover:bg-accent disabled:opacity-50 disabled:cursor-not-allowed"
                  aria-label="Rotate join code"
                  title="Rotate join code"
                >
                  <RotateCw className="h-3 w-3" strokeWidth={1.5} />
                  {rotating ? "Rotating..." : "Rotate"}
                </button>
              </div>
            )}
          </div>
          <div className="flex items-center gap-2 shrink-0">
            <ExportDropdown sectionId={id} domain="roster" formats={["csv", "xlsx"]} />
            <DropdownMenu>
              <DropdownMenuTrigger asChild>
                <Button
                  variant="outline"
                  size="icon"
                  aria-label="More actions"
                >
                  <MoreHorizontal className="h-4 w-4" strokeWidth={1.5} />
                </Button>
              </DropdownMenuTrigger>
              <DropdownMenuContent align="end">
                <DropdownMenuItem onClick={handleCopyJoinCode}>
                  <Copy className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                  Copy join code
                </DropdownMenuItem>
                <DropdownMenuItem onClick={handleRotateCode} disabled={rotating}>
                  <RotateCw className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                  Rotate join code
                </DropdownMenuItem>
                <DropdownMenuSeparator />
                <DropdownMenuItem onClick={() => handleTabChange("settings")}>
                  <Users className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                  Manage roster
                </DropdownMenuItem>
                <DropdownMenuSeparator />
                <DropdownMenuItem onClick={() => navigate(`/instructor/reports?section=${id}`)}>
                  <FileText className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                  View reports
                </DropdownMenuItem>
              </DropdownMenuContent>
            </DropdownMenu>
          </div>
        </div>
      </div>

      {/* ---------- Insight ---------- */}
      <InsightHeader
        insight={
          atRisk === 0 && flags === 0
            ? `${section.name} is on track — no at-risk students or integrity flags.`
            : atRisk === 0
              ? `No students at risk; ${flags} active integrity flag${flags === 1 ? "" : "s"}.`
              : flags === 0
                ? `${atRisk} student${atRisk === 1 ? " is" : "s are"} at risk — no active integrity flags.`
                : `${atRisk} student${atRisk === 1 ? " is" : "s are"} at risk; ${flags} have active integrity flag${flags === 1 ? "" : "s"}.`
        }
      />

      {/* ---------- Evidence ---------- */}
      <EvidenceRow
        chips={[
          { label: "At Risk",     value: atRisk,    delta: null, series: emptySeries(), comparison: "this week" },
          { label: "Avg CDS",     value: `${Math.round(avgCds * 100)}%`, delta: null, series: emptySeries(), comparison: "current" },
          { label: "Open Flags",  value: flags,    delta: null, series: emptySeries(), comparison: "this week" },
          { label: "Submissions", value: totalSubmissions, delta: null, series: emptySeries(), comparison: "all time" },
        ]}
      />

      {/* ---------- Tabs ---------- */}
      <Tabs value={tab} onValueChange={handleTabChange}>
        <TabsList className="inline-flex h-10 items-center gap-0 bg-transparent p-0 border-b border-border rounded-none w-full justify-start overflow-x-auto [&::-webkit-scrollbar]:hidden">
          <TabsTrigger
            value="roster"
            className="rounded-none border-b-2 border-transparent data-[state=active]:border-b-foreground data-[state=active]:bg-transparent data-[state=active]:text-foreground data-[state=active]:shadow-none -mb-px px-3 whitespace-nowrap"
          >
            Roster
          </TabsTrigger>
          <TabsTrigger
            value="analytics"
            className="rounded-none border-b-2 border-transparent data-[state=active]:border-b-foreground data-[state=active]:bg-transparent data-[state=active]:text-foreground data-[state=active]:shadow-none -mb-px px-3 whitespace-nowrap"
          >
            Analytics
          </TabsTrigger>
          <TabsTrigger
            value="submissions"
            className="rounded-none border-b-2 border-transparent data-[state=active]:border-b-foreground data-[state=active]:bg-transparent data-[state=active]:text-foreground data-[state=active]:shadow-none -mb-px px-3 whitespace-nowrap"
          >
            Submissions
          </TabsTrigger>
          <TabsTrigger
            value="settings"
            className="rounded-none border-b-2 border-transparent data-[state=active]:border-b-foreground data-[state=active]:bg-transparent data-[state=active]:text-foreground data-[state=active]:shadow-none -mb-px px-3 whitespace-nowrap"
          >
            <Users className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
            Settings
          </TabsTrigger>
        </TabsList>

        <TabsContent value="roster" className="mt-6">
          <RosterTab sectionId={id} sectionName={section.name} />
        </TabsContent>
        <TabsContent value="analytics" className="mt-6">
          <AnalyticsTab sectionId={id} />
        </TabsContent>
        <TabsContent value="submissions" className="mt-6">
          <SubmissionsTab sectionId={id} initialExerciseId={searchParams.get("exercise")} />
        </TabsContent>
        <TabsContent value="settings" className="mt-6">
          <SettingsTab
            sectionId={id}
            sectionName={section.name}
            courseCode={section.course_code}
            onUpdated={() => refetch()}
            onDeleted={() => navigate("/instructor/sections")}
          />
        </TabsContent>
      </Tabs>
    </div>
  );
}
