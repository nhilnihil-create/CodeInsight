import { useState } from "react";
import { Link } from "react-router-dom";
import {
  Mail,
  MoreHorizontal,
  ArrowRight,
  Download,
  Copy,
  Settings,
  Users,
  FileText,
} from "lucide-react";
import { Button } from "@/components/ui/button";
import { Tabs, TabsList, TabsTrigger, TabsContent } from "@/components/ui/tabs";
import {
  DropdownMenu,
  DropdownMenuContent,
  DropdownMenuItem,
  DropdownMenuTrigger,
  DropdownMenuSeparator,
} from "@/components/ui/dropdown-menu";
import PageBreadcrumb from "@/components/ui/page-breadcrumb";
import InsightHeader from "@/components/ui/insight-header";
import EvidenceRow from "@/components/ui/evidence-row";
import RosterTab from "./tabs/RosterTab";
import AnalyticsTab from "./tabs/AnalyticsTab";
import SubmissionsTab from "./tabs/SubmissionsTab";
import SettingsTab from "./tabs/SettingsTab";

export default function SectionDetail() {
  const [tab, setTab] = useState("roster");

  return (
    <div className="space-y-6 sm:space-y-8">
      {/* ---------- PageHeader ---------- */}
      <div className="space-y-2">
        <PageBreadcrumb
          crumbs={[
            { label: "Sections", href: "/instructor/sections" },
            { label: "Section 04" },
          ]}
        />
        <div className="flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between">
          <div className="min-w-0">
            <h1 className="text-2xl font-semibold tracking-tight">
              Section 04 — Intro CS
            </h1>
            <p className="text-sm text-muted-foreground mt-1">
              CS101 · Sem 1 · AY 2025–2026 · 22 students
            </p>
          </div>
          <div className="flex items-center gap-2 shrink-0">
            <Button variant="outline" size="sm" className="font-medium">
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
                <DropdownMenuItem>
                  <Download className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                  Export section
                </DropdownMenuItem>
                <DropdownMenuItem>
                  <Copy className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                  Copy join code
                </DropdownMenuItem>
                <DropdownMenuItem>
                  <Users className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                  Manage roster
                </DropdownMenuItem>
                <DropdownMenuSeparator />
                <DropdownMenuItem>
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
        insight="6 students are at risk; 2 have active integrity flags."
        action={
          <Button asChild size="sm" className="font-medium">
            <Link to="/instructor/integrity?section=4">
              Schedule intervention
              <ArrowRight className="ml-1.5 h-3.5 w-3.5" strokeWidth={2} />
            </Link>
          </Button>
        }
      />

      {/* ---------- Evidence ---------- */}
      <EvidenceRow
        chips={[
          { label: "At Risk",     value: 6,   delta: 1,  series: [3, 4, 4, 5, 5, 6, 6], comparison: "vs. last week" },
          { label: "Avg CDS",     value: "0.71", delta: 0.04, series: [0.62, 0.64, 0.66, 0.68, 0.69, 0.70, 0.71], comparison: "rising" },
          { label: "Open Flags",  value: 2,   delta: 0,  series: [1, 1, 2, 2, 2, 2, 2], comparison: "this week" },
          { label: "Submissions", value: 142, delta: 18, series: [98, 108, 116, 122, 128, 136, 142], comparison: "this week" },
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
            <Settings className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
            Settings
          </TabsTrigger>
        </TabsList>

        <TabsContent value="roster" className="mt-6">
          <RosterTab />
        </TabsContent>
        <TabsContent value="analytics" className="mt-6">
          <AnalyticsTab />
        </TabsContent>
        <TabsContent value="submissions" className="mt-6">
          <SubmissionsTab />
        </TabsContent>
        <TabsContent value="settings" className="mt-6">
          <SettingsTab />
        </TabsContent>
      </Tabs>
    </div>
  );
}
