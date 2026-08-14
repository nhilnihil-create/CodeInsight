import { useMemo, useState, useEffect, useCallback } from "react";
import {
  Search,
  AlertTriangle,
  ShieldAlert,
  RefreshCw,
} from "lucide-react";
import { Button } from "@/components/ui/button";
import { Input } from "@/components/ui/input";
import {
  Select,
  SelectContent,
  SelectItem,
  SelectTrigger,
  SelectValue,
} from "@/components/ui/select";
import InsightHeader from "@/components/ui/insight-header";
import EvidenceRow from "@/components/ui/evidence-row";
import RiskBadge from "@/components/ui/risk-badge";
import MasteryBar, { tierForCds, TIER_META } from "@/components/ui/mastery-bar";
import DecisionList from "@/components/ui/decision-list";
import DetailDrawer from "@/components/ui/detail-drawer";
import SectionFilter from "@/components/SectionFilter";
import useLastSection from "@/hooks/useLastSection";
import ExportDropdown from "@/components/ui/export-dropdown";
import analyticsService from "@/api/analyticsService";
import { cn } from "@/lib/utils";

const REFRESH_MS = 15000;

function timeAgo(dateStr) {
  if (!dateStr) return "—";
  const ms = Date.now() - new Date(dateStr).getTime();
  const mins = Math.floor(ms / 60000);
  if (mins < 1) return "just now";
  if (mins < 60) return `${mins}m ago`;
  const hours = Math.floor(mins / 60);
  if (hours < 24) return `${hours}h ago`;
  const days = Math.floor(hours / 24);
  return `${days}d ago`;
}

const TIER_RISK_BADGE = {
  critical: "critical",
  needs_support: "high",
  developing: "moderate",
  strong: "low",
  excellent: "low",
};

const TIER_ORDER = ["critical", "needs_support", "developing", "strong", "excellent", "unstarted"];

const TIER_META_WITH_UNSTARTED = {
  ...TIER_META,
  unstarted: {
    dot: "bg-muted-foreground/40",
    text: "text-muted-foreground",
    label: "Unstarted",
  },
};

const TIER_INSTRUCTOR_NOTE = {
  critical:
    "This student is in the critical range (CDS 0.81–1.00). Immediate one-on-one intervention is strongly recommended. Review foundational errors and consider pausing new material until gaps are addressed.",
  needs_support:
    "This student needs targeted support (CDS 0.61–0.80). Schedule a brief check-in to review the specific misconception. Peer tutoring or a focused practice exercise may help.",
  developing:
    "This student is developing but not yet proficient (CDS 0.41–0.60). A well-placed hint or class-wide review of this concept could accelerate improvement.",
  strong:
    "This student is performing well (CDS 0.21–0.40). Monitor their progress; minor reinforcement may be all that's needed.",
  excellent:
    "This student demonstrates strong mastery (CDS 0.00–0.20). No intervention required—consider assigning enrichment material.",
};

const TIER_CHIP_SERIES = {
  critical: [0, 0, 0, 0, 0, 0, 0],
  needs_support: [0, 0, 0, 0, 0, 0, 0],
  developing: [0, 0, 0, 0, 0, 0, 0],
  strong: [0, 0, 0, 0, 0, 0, 0],
  excellent: [0, 0, 0, 0, 0, 0, 0],
  unstarted: [0, 0, 0, 0, 0, 0, 0],
};

export default function InstructorAlerts() {
  const [sectionId, setSectionId] = useLastSection();
  const [queue, setQueue] = useState(null);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [tierFilter, setTierFilter] = useState("All");
  const [query, setQuery] = useState("");
  const [openAlert, setOpenAlert] = useState(null);

  const fetchQueue = useCallback(
    async (silent = false) => {
      if (!sectionId) return;
      if (!silent) setLoading(true);
      setError(null);
      try {
        const res = await analyticsService.getInterventionQueue(sectionId);
        setQueue(res.data);
      } catch (err) {
        setError(err.response?.data?.error || "Failed to load alerts");
      } finally {
        if (!silent) setLoading(false);
      }
    },
    [sectionId]
  );

  // Poll so the queue stays in sync with live CDS scores without requiring
  // the instructor to refresh manually.
  useEffect(() => {
    fetchQueue();
    const id = setInterval(() => fetchQueue(true), REFRESH_MS);
    return () => clearInterval(id);
  }, [fetchQueue]);

  const atRisk = useMemo(() => queue?.atRisk || [], [queue]);
  const tierCounts = useMemo(
    () => ({
      critical: 0,
      needs_support: 0,
      developing: 0,
      strong: 0,
      excellent: 0,
      unstarted: 0,
      ...(queue?.tierDistribution || {}),
    }),
    [queue]
  );

  const filtered = useMemo(() => {
    const q = query.trim().toLowerCase();
    return atRisk
      .filter((item) => {
        const tier = item.tier || tierForCds(parseFloat(item.avgCds) || 0);
        if (tierFilter !== "All" && tier !== tierFilter) return false;
        if (q) {
          const hay = `${item.studentName} ${item.exerciseTitle} ${item.conceptName || ""}`.toLowerCase();
          if (!hay.includes(q)) return false;
        }
        return true;
      })
      .sort((a, b) => {
        const rank = { critical: 0, needs_support: 1 };
        return (rank[a.tier] ?? 1) - (rank[b.tier] ?? 1) || (parseFloat(b.avgCds) || 0) - (parseFloat(a.avgCds) || 0);
      });
  }, [atRisk, tierFilter, query]);

  const openDetail = (item) => {
    setOpenAlert(item);
  };

  const renderRow = (item) => {
    const cds = parseFloat(item.avgCds) || 0;
    const tier = item.tier || tierForCds(cds);
    const meta = TIER_META_WITH_UNSTARTED[tier] || TIER_META_WITH_UNSTARTED.excellent;
    const riskLevel = TIER_RISK_BADGE[tier] || "low";

    return (
      <>
        <RiskBadge level={riskLevel} />

        <span className="text-sm font-medium truncate min-w-[8rem] text-foreground">
          {item.studentName}
        </span>

        <span className="min-w-[8rem] flex items-center gap-1.5">
          <span className={cn("w-1.5 h-1.5 rounded-full shrink-0", meta.dot)} />
          <span className={cn("text-[11px] font-medium uppercase tracking-wider", meta.text)}>
            {meta.label}
          </span>
        </span>

        <span className="text-sm text-muted-foreground truncate min-w-[8rem]">
          {item.conceptName || "—"}
        </span>

        <span className="text-sm text-muted-foreground truncate min-w-[10rem] flex-1">
          {item.exerciseTitle}
        </span>

        <span className="text-sm font-mono tabular-nums text-foreground font-semibold shrink-0 w-16 text-right">
          {cds.toFixed(2)}
        </span>

        <div className="shrink-0 w-20">
          <MasteryBar percent={Math.round((1 - cds) * 100)} tier={tier} />
        </div>

        <span className="text-xs text-muted-foreground font-mono tabular-nums shrink-0 w-14 text-right">
          {timeAgo(item.computedAt)}
        </span>

        <span className="shrink-0 w-24 text-right text-xs font-medium text-primary">
          Needs attention
        </span>
      </>
    );
  };

  if (loading && !queue) {
    return (
      <div className="space-y-6 sm:space-y-8">
        <div className="flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between">
          <div className="min-w-0 space-y-1">
            <h1 className="text-2xl font-semibold tracking-tight">Intervention Queue</h1>
            <p className="text-sm text-muted-foreground">Loading alerts…</p>
          </div>
        </div>
        <div className="rounded-xl border border-border/60 bg-card/50 backdrop-blur-sm py-12 px-6 text-center">
          <RefreshCw className="h-6 w-6 text-muted-foreground mx-auto mb-2 animate-spin" />
          <p className="text-sm text-muted-foreground">Loading alerts…</p>
        </div>
      </div>
    );
  }

  const atRiskCount = queue?.insight?.atRiskCount ?? atRisk.length;

  return (
    <div className="space-y-6 sm:space-y-8">
      {/* ---------- Page Header ---------- */}
      <div className="flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between">
        <div className="min-w-0 space-y-1">
          <h1 className="text-2xl font-semibold tracking-tight">Intervention Queue</h1>
          <p className="text-sm text-muted-foreground">
            Students at risk of falling behind — derived live from CDS scores. Students enter
            the queue when their average CDS exceeds the High risk threshold (0.60) — the same
            signal as the dashboard banner — and leave on their own as their CDS improves.
          </p>
        </div>
        <div className="flex flex-wrap items-center gap-2 shrink-0">
          {error ? (
            <span className="text-xs text-destructive font-medium">{error}</span>
          ) : null}
          <SectionFilter value={sectionId} onChange={setSectionId} />
          <ExportDropdown sectionId={sectionId} domain="summary" label="Export" />
          <Button variant="ghost" size="icon" onClick={() => fetchQueue()} title="Refresh">
            <RefreshCw className="h-4 w-4" strokeWidth={1.5} />
          </Button>
        </div>
      </div>

      {error && (
        <div className="flex items-center gap-3 rounded-xl border border-rose-500/15 bg-rose-500/5 px-4 py-3">
          <AlertTriangle className="h-4 w-4 text-rose-400 shrink-0" />
          <p className="text-sm text-rose-400 flex-1">{error}</p>
          <Button size="sm" variant="outline" className="border-destructive/30 text-destructive" onClick={() => fetchQueue()}>
            <RefreshCw className="h-3.5 w-3.5 mr-1.5" />
            Retry
          </Button>
        </div>
      )}

      {/* ---------- Insight ---------- */}
      <InsightHeader
        eyebrow={atRiskCount > 0 ? "Action required" : "All clear"}
        insight={
          queue?.insight?.summary ||
          (atRiskCount > 0
            ? `${atRiskCount} student${atRiskCount === 1 ? "" : "s"} need${atRiskCount === 1 ? "s" : ""} attention — sorted by severity.`
            : "No students currently at high risk in this section.")
        }
        description={
          atRiskCount > 0
            ? "Sorted by Concept Difficulty Score (CDS). Higher CDS = greater difficulty. Review Critical and Needs Support tiers first."
            : undefined
        }
      />

      {/* ---------- 6-Tier Evidence ---------- */}
      <EvidenceRow
        chips={[
          { label: "Critical", value: tierCounts.critical, delta: null, series: [...TIER_CHIP_SERIES.critical, tierCounts.critical], comparison: "total", inverted: true },
          { label: "Needs Support", value: tierCounts.needs_support, delta: null, series: [...TIER_CHIP_SERIES.needs_support, tierCounts.needs_support], comparison: "total", inverted: true },
          { label: "Developing", value: tierCounts.developing, delta: null, series: [...TIER_CHIP_SERIES.developing, tierCounts.developing], comparison: "total" },
          { label: "Strong", value: tierCounts.strong, delta: null, series: [...TIER_CHIP_SERIES.strong, tierCounts.strong], comparison: "total" },
          { label: "Excellent", value: tierCounts.excellent, delta: null, series: [...TIER_CHIP_SERIES.excellent, tierCounts.excellent], comparison: "total" },
          { label: "Unstarted", value: tierCounts.unstarted, delta: null, series: [...TIER_CHIP_SERIES.unstarted, tierCounts.unstarted], comparison: "total" },
        ]}
      />

      {/* ---------- Filter row ---------- */}
      <div className="flex flex-col gap-3 sm:flex-row sm:items-center">
        <div className="relative flex-1 min-w-0">
          <Search
            className="absolute left-3 top-1/2 -translate-y-1/2 h-3.5 w-3.5 text-muted-foreground pointer-events-none"
            strokeWidth={1.5}
            aria-hidden="true"
          />
          <Input
            value={query}
            onChange={(e) => setQuery(e.target.value)}
            placeholder="Search student, concept, or exercise…"
            className="pl-9 h-9"
          />
        </div>
        <Select value={tierFilter} onValueChange={setTierFilter}>
          <SelectTrigger className="h-9 w-full sm:w-48">
            <SelectValue />
          </SelectTrigger>
          <SelectContent>
            <SelectItem value="All">All tiers</SelectItem>
            {TIER_ORDER.map((t) => (
              <SelectItem key={t} value={t}>
                {TIER_META_WITH_UNSTARTED[t].label} ({tierCounts[t]})
              </SelectItem>
            ))}
          </SelectContent>
        </Select>
      </div>

      {/* ---------- DecisionList ---------- */}
      {filtered.length > 0 ? (
        <div className="space-y-2">
          <div className="flex items-center justify-between">
            <h2 className="text-sm font-semibold">Queue</h2>
            <span className="text-xs text-muted-foreground font-mono tabular-nums">
              {filtered.length} student{filtered.length === 1 ? "" : "s"}
              {queue?.totalStudents !== null ? ` · ${queue.totalStudents} enrolled` : ""}
            </span>
          </div>
          <DecisionList
            items={filtered}
            highlightIndex={0}
            onAction={openDetail}
            renderRow={renderRow}
            maxHeight="max-h-[20rem]"
          />
        </div>
      ) : (
        <div className="rounded-xl border border-dashed border-border/40 bg-card/30 backdrop-blur-sm p-8 text-center">
          <ShieldAlert
            className="h-6 w-6 text-muted-foreground mx-auto mb-2"
            strokeWidth={1.5}
          />
          <p className="text-sm font-medium">
            {atRisk.length === 0
              ? "No students currently at high risk."
              : "No alerts match the current filters."}
          </p>
          <p className="text-xs text-muted-foreground mt-1">
            {atRisk.length === 0
              ? "The queue updates live as CDS scores change."
              : "Try clearing the search or tier filter."}
          </p>
        </div>
      )}

      {/* ---------- Detail Drawer ---------- */}
      <DetailDrawer
        open={Boolean(openAlert)}
        onClose={() => setOpenAlert(null)}
        title={openAlert ? openAlert.studentName : "Alert detail"}
        subtitle={openAlert ? `${openAlert.exerciseTitle} · ${openAlert.conceptName || "N/A"}` : ""}
      >
        {openAlert ? (
          <div className="space-y-6">
            {(() => {
              const cds = parseFloat(openAlert.avgCds) || 0;
              const tier = openAlert.tier || tierForCds(cds);
              const meta = TIER_META_WITH_UNSTARTED[tier] || TIER_META_WITH_UNSTARTED.excellent;
              const riskLevel = TIER_RISK_BADGE[tier] || "low";
              return (
                <>
                  <div className="flex items-center justify-between">
                    <div className="space-y-1">
                      <p className="text-xs uppercase tracking-wider text-muted-foreground">
                        Concept Difficulty
                      </p>
                      <div className="flex items-center gap-2">
                        <RiskBadge level={riskLevel} />
                        <span className={cn("text-sm font-medium", meta.text)}>
                          {meta.label}
                        </span>
                      </div>
                    </div>
                    <div className="text-right">
                      <p className="text-xs uppercase tracking-wider text-muted-foreground">
                        CDS Score
                      </p>
                      <p className="text-2xl font-mono tabular-nums font-bold text-foreground">
                        {cds.toFixed(2)}
                      </p>
                    </div>
                  </div>

                  <div className="space-y-1.5">
                    <p className="text-xs uppercase tracking-wider text-muted-foreground">
                      Mastery
                    </p>
                    <MasteryBar percent={Math.round((1 - cds) * 100)} tier={tier} />
                    <p className="text-xs text-muted-foreground text-right">
                      {Math.round((1 - cds) * 100)}% mastery
                    </p>
                  </div>

                  <div className="rounded-md border border-border bg-muted/40 p-4 space-y-1">
                    <p className="text-xs uppercase tracking-wider text-muted-foreground">
                      Student
                    </p>
                    <p className="text-sm font-medium">{openAlert.studentName}</p>
                  </div>

                  <div className="rounded-md border border-border bg-muted/40 p-4 space-y-1">
                    <p className="text-xs uppercase tracking-wider text-muted-foreground">
                      Concept
                    </p>
                    <p className="text-sm font-medium">{openAlert.conceptName || "Not specified"}</p>
                  </div>

                  <div className="rounded-md border border-border bg-muted/40 p-4 space-y-1">
                    <p className="text-xs uppercase tracking-wider text-muted-foreground">
                      Exercise
                    </p>
                    <p className="text-sm font-medium">{openAlert.exerciseTitle}</p>
                  </div>

                  <div className="space-y-2">
                    <p className="text-xs uppercase tracking-wider text-muted-foreground">
                      Instructor Notes
                    </p>
                    <div className="rounded-md bg-muted/40 p-3 text-sm text-muted-foreground leading-relaxed">
                      {TIER_INSTRUCTOR_NOTE[tier] || TIER_INSTRUCTOR_NOTE.needs_support}
                    </div>
                  </div>

                  <div className="flex items-center justify-end pt-2 border-t border-border">
                    <Button
                      variant="outline"
                      size="sm"
                      onClick={() => setOpenAlert(null)}
                    >
                      Close
                    </Button>
                  </div>
                </>
              );
            })()}
          </div>
        ) : null}
      </DetailDrawer>
    </div>
  );
}
