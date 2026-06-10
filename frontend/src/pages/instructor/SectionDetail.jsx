import { useState, useCallback } from "react";
import { useParams, Link, useNavigate } from "react-router-dom";
import { useQuery } from "@tanstack/react-query";
import {
  Mail,
  MoreHorizontal,
  ArrowRight,
  Download,
  Copy,
  Users,
  FileText,
  AlertTriangle,
  RefreshCw,
  FileSpreadsheet,
} from "lucide-react";
import {
  Dialog,
  DialogContent,
  DialogHeader,
  DialogTitle,
  DialogDescription,
  DialogFooter,
} from "@/components/ui/dialog";
import { Textarea } from "@/components/ui/textarea";
import { Button } from "@/components/ui/button";
import { Tabs, TabsList, TabsTrigger, TabsContent } from "@/components/ui/tabs";
import {
  DropdownMenu,
  DropdownMenuContent,
  DropdownMenuItem,
  DropdownMenuTrigger,
  DropdownMenuSeparator,
} from "@/components/ui/dropdown-menu";
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
  const [tab, setTab] = useState("roster");
  const [msgOpen, setMsgOpen] = useState(false);
  const [msgBody, setMsgBody] = useState("");
  const [msgSending, setMsgSending] = useState(false);

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
      toast.success("Join code copied to clipboard");
    } catch {
      toast.error("Failed to copy join code");
    }
  }, [section]);

  const handleSendAtRiskMessage = useCallback(async () => {
    if (!msgBody.trim() || !id) return;
    setMsgSending(true);
    try {
      await api.post(`/api/sections/${id}/messages`, { message: msgBody.trim() });
      toast.success("Message sent to all students in this section");
      setMsgOpen(false);
      setMsgBody("");
    } catch {
      toast.error("Failed to send message");
    } finally {
      setMsgSending(false);
    }
  }, [id, msgBody]);

  const handleExportCSV = useCallback(async () => {
    if (!id) return;
    try {
      const { data: students } = await api.get(`/api/sections/${id}/students`);
      const csvRows = students.map((s) =>
        [
          `"${(s.name || "").replace(/"/g, '""')}"`,
          `"${(s.email || "").replace(/"/g, '""')}"`,
          s.enrolled_at || "",
        ].join(",")
      );
      const csv = ["Name,Email,Enrolled At", ...csvRows].join("\n");
      const blob = new Blob([csv], { type: "text/csv;charset=utf-8;" });
      const url = URL.createObjectURL(blob);
      const a = document.createElement("a");
      a.href = url;
      a.download = `section-${id}-roster.csv`;
      a.click();
      URL.revokeObjectURL(url);
      toast.success("Roster exported as CSV");
    } catch {
      toast.error("Failed to export roster");
    }
  }, [id]);

  const handleExportExcel = useCallback(async () => {
    if (!id) return;
    try {
      const res = await api.get(`/api/sections/${id}/export`, {
        responseType: "blob",
      });
      const url = URL.createObjectURL(res.data);
      const a = document.createElement("a");
      a.href = url;
      a.download = `section-${id}-report.xlsx`;
      a.click();
      URL.revokeObjectURL(url);
      toast.success("Section exported as Excel");
    } catch {
      toast.error("Failed to export section");
    }
  }, [id]);

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
          </div>
          <div className="flex items-center gap-2 shrink-0">
            <Button
              variant="outline"
              size="sm"
              className="font-medium"
              onClick={() => setMsgOpen(true)}
            >
              <Mail className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
              Message at-risk
            </Button>
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
                <DropdownMenuItem onClick={handleExportCSV}>
                  <Download className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                  Export CSV (Roster)
                </DropdownMenuItem>
                <DropdownMenuItem onClick={handleExportExcel}>
                  <FileSpreadsheet className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                  Export Excel (Full Report)
                </DropdownMenuItem>
                <DropdownMenuSeparator />
                <DropdownMenuItem onClick={handleCopyJoinCode}>
                  <Copy className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                  Copy join code
                </DropdownMenuItem>
                <DropdownMenuItem onClick={() => setTab("settings")}>
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
        action={
          <Button asChild size="sm" className="font-medium">
            <Link to={`/instructor/integrity?section=${id}`}>
              Schedule intervention
              <ArrowRight className="ml-1.5 h-3.5 w-3.5" strokeWidth={2} />
            </Link>
          </Button>
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
      <Tabs value={tab} onValueChange={setTab}>
        <TabsList className="inline-flex h-10 items-center gap-0 bg-transparent p-0 border-b border-border rounded-none w-full justify-start">
          <TabsTrigger
            value="roster"
            className="rounded-none border-b-2 border-transparent data-[state=active]:border-b-foreground data-[state=active]:bg-transparent data-[state=active]:text-foreground data-[state=active]:shadow-none -mb-px px-3"
          >
            Roster
          </TabsTrigger>
          <TabsTrigger
            value="analytics"
            className="rounded-none border-b-2 border-transparent data-[state=active]:border-b-foreground data-[state=active]:bg-transparent data-[state=active]:text-foreground data-[state=active]:shadow-none -mb-px px-3"
          >
            Analytics
          </TabsTrigger>
          <TabsTrigger
            value="submissions"
            className="rounded-none border-b-2 border-transparent data-[state=active]:border-b-foreground data-[state=active]:bg-transparent data-[state=active]:text-foreground data-[state=active]:shadow-none -mb-px px-3"
          >
            Submissions
          </TabsTrigger>
          <TabsTrigger
            value="settings"
            className="rounded-none border-b-2 border-transparent data-[state=active]:border-b-foreground data-[state=active]:bg-transparent data-[state=active]:text-foreground data-[state=active]:shadow-none -mb-px px-3"
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
          <SubmissionsTab sectionId={id} />
        </TabsContent>
        <TabsContent value="settings" className="mt-6">
          <SettingsTab
            sectionId={id}
            sectionName={section.name}
            courseCode={section.course_code}
            onUpdated={() => refetch()}
          />
        </TabsContent>
      </Tabs>

      {/* ---------- Message Dialog ---------- */}
      <Dialog open={msgOpen} onOpenChange={setMsgOpen}>
        <DialogContent>
          <DialogHeader>
            <DialogTitle>Message Students</DialogTitle>
            <DialogDescription>
              Send an in-app notification to all students in {section.name}.
            </DialogDescription>
          </DialogHeader>
          <Textarea
            id="msg-body"
            value={msgBody}
            onChange={(e) => setMsgBody(e.target.value)}
            placeholder="Write a message to your students…"
            className="min-h-[120px]"
            autoFocus
          />
          <DialogFooter>
            <Button variant="ghost" onClick={() => { setMsgOpen(false); setMsgBody(""); }} disabled={msgSending}>
              Cancel
            </Button>
            <Button onClick={handleSendAtRiskMessage} disabled={msgSending || !msgBody.trim()}>
              {msgSending ? "Sending…" : "Send to All Students"}
            </Button>
          </DialogFooter>
        </DialogContent>
      </Dialog>
    </div>
  );
}
