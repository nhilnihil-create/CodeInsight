import { useMemo, useState } from "react";
import { Link } from "react-router-dom";
import {
  ArrowRight,
  ChevronDown,
  Search,
  Check,
  X,
  AlertTriangle,
  ShieldAlert,
} from "lucide-react";
import { Button } from "@/components/ui/button";
import { Input } from "@/components/ui/input";
import { Checkbox } from "@/components/ui/checkbox";
import {
  Select,
  SelectContent,
  SelectItem,
  SelectTrigger,
  SelectValue,
} from "@/components/ui/select";
import {
  DropdownMenu,
  DropdownMenuContent,
  DropdownMenuItem,
  DropdownMenuLabel,
  DropdownMenuSeparator,
  DropdownMenuTrigger,
} from "@/components/ui/dropdown-menu";
import PageBreadcrumb from "@/components/ui/page-breadcrumb";
import InsightHeader from "@/components/ui/insight-header";
import EvidenceRow from "@/components/ui/evidence-row";
import RiskBadge from "@/components/ui/risk-badge";
import DecisionList from "@/components/ui/decision-list";
import DetailDrawer from "@/components/ui/detail-drawer";
import { cn } from "@/lib/utils";

/**
 * Unified Integrity page. Replaces the legacy /instructor/warnings
 * ("Early warnings", behavioral risk) and /instructor/violations
 * ("Structure violations", structural anomalies) sub-pages — both
 * surfaces are merged into one queue ordered by severity, then recency.
 *
 * Hierarchy
 *   1. PageHeader     "Integrity" + bulk-action menu
 *   2. InsightHeader  top actionable flag + "Review" action
 *   3. EvidenceRow    severity counts (Critical / High / Moderate / Low)
 *   4. Filter row     severity + type + free-text search
 *   5. DecisionList   selectable queue; first row highlighted
 *   6. DetailDrawer   row click → flag detail with code diff
 */

const FLAGS = [
  {
    id: "f01",
    type: "Behavioral Anomaly",
    severity: "critical",
    student: "A. Khan",
    studentId: "u2",
    exercise: "Recursion I",
    exerciseId: "e4",
    time: "2h ago",
    evidence: [
      "+  def factorial(n):",
      "+    if n <= 1:",
      "+        return 1",
      "+    return n * factorial(n - 1)",
      " ",
      "  Keystroke delta: 0 → 87 LOC in 0.8s (baseline median 12m)",
    ],
    recommendation:
      "Schedule a 1:1 to walk through Recursion I step-by-step. Compare session timing against the section baseline (median 12m).",
    course: "CS101 · Section 04",
  },
  {
    id: "f02",
    type: "Hardcoding",
    severity: "high",
    student: "J. Doe",
    studentId: "u4",
    exercise: "Basic Loops",
    exerciseId: "e1",
    time: "5h ago",
    evidence: [
      "  for n in range(1, 6):",
      "-    print(n)",
      "+    print('1 2 3 4 5')",
      " ",
      "  Student output matches expected exactly using hardcoded string.",
    ],
    recommendation:
      "Open submission side-by-side with the section baseline. Confirm with a 5-minute live-coding session.",
    course: "CS101 · Section 02",
  },
  {
    id: "f03",
    type: "Code Growth Spike",
    severity: "moderate",
    student: "J. Doe",
    studentId: "u4",
    exercise: "Array Reversal",
    exerciseId: "e3",
    time: "3d ago",
    evidence: [
      "  def reverse(arr):",
      "+    arr.reverse()",
      "+    return arr",
      " ",
      "  Code size increased 220 LOC in a single commit (median session: 18 LOC).",
    ],
    recommendation:
      "Review with the student whether the helper was understood. Suggest a rewrite from scratch without the library call.",
    course: "CS101 · Section 02",
  },
  {
    id: "f04",
    type: "Output Mismatch",
    severity: "moderate",
    student: "A. Santos",
    studentId: "u2",
    exercise: "Array Reversal",
    exerciseId: "e3",
    time: "1d ago",
    evidence: [
      "  expected: '5 4 3 2 1'",
      "  actual:   '1 2 3 4 5'",
      "  status:   3/5 tests passed",
    ],
    recommendation: "Off-by-one on the loop bound. Pair with a stronger peer for the next attempt.",
    course: "CS101 · Section 04",
  },
  {
    id: "f05",
    type: "Behavioral Anomaly",
    severity: "moderate",
    student: "C. Park",
    studentId: "u6",
    exercise: "Loops II",
    exerciseId: "e2",
    time: "1w ago",
    evidence: [
      "  Editor open: 47m",
      "  Keystrokes:  9",
      "  Paste events: 2",
      "  Status:       Submitted correct",
    ],
    recommendation: "Behavior pattern matches prior flagged sessions. Schedule a check-in this week.",
    course: "CS101 · Section 04",
  },
  {
    id: "f06",
    type: "Hardcoding",
    severity: "low",
    student: "D. Lopez",
    studentId: "u7",
    exercise: "Function Calculator",
    exerciseId: "e2",
    time: "1w ago",
    evidence: [
      "  return a + b",
      "-# note: works for inputs 2, 3 only",
      "+# return 5  # hardcoded for test",
    ],
    recommendation: "Low confidence — likely a dev shortcut. No action required unless repeated.",
    course: "CS101 · Section 04",
  },
  {
    id: "f07",
    type: "Off-By-One",
    severity: "low",
    student: "M. Garcia",
    studentId: "u3",
    exercise: "Basic Loops",
    exerciseId: "e1",
    time: "4d ago",
    evidence: [
      "  for i in range(n + 1):   # off-by-one",
      "      print(i)",
      "  expected: n iterations, got n+1",
    ],
    recommendation: "Common error. Auto-credit if next attempt is correct.",
    course: "CS101 · Section 02",
  },
  {
    id: "f08",
    type: "Missing Return",
    severity: "low",
    student: "J. Doe",
    studentId: "u4",
    exercise: "Function Calculator",
    exerciseId: "e2",
    time: "5d ago",
    evidence: [
      "  int add(int a, int b) {",
      "-    return a + b;",
      "+    // TODO",
      "  }",
    ],
    recommendation: "Compile-time error. Submission cannot be evaluated. Re-attempt encouraged.",
    course: "CS101 · Section 02",
  },
  {
    id: "f09",
    type: "Passive Behavior",
    severity: "low",
    student: "M. Garcia",
    studentId: "u3",
    exercise: "Array Reversal",
    exerciseId: "e3",
    time: "2d ago",
    evidence: [
      "  Editor open: 45m",
      "  Keystrokes:  8",
      "  Submissions: 0",
    ],
    recommendation: "Student may be stuck. Send an offer for office hours.",
    course: "CS101 · Section 02",
  },
  {
    id: "f10",
    type: "Infinite Loop",
    severity: "low",
    student: "J. Doe",
    studentId: "u4",
    exercise: "Basic Loops",
    exerciseId: "e1",
    time: "1w ago",
    evidence: [
      "  while True:",
      "      print('hello')",
      "  # no break",
    ],
    recommendation: "Standard first-week error. No further action needed.",
    course: "CS101 · Section 02",
  },
  {
    id: "f11",
    type: "Blank Template",
    severity: "low",
    student: "F. Adams",
    studentId: "u8",
    exercise: "Array Reversal",
    exerciseId: "e3",
    time: "2w ago",
    evidence: [
      "  # starter code unchanged",
      "  # no student code present",
    ],
    recommendation: "Follow up — student may not have started. Auto-message at 24h idle threshold.",
    course: "CS101 · Section 04",
  },
  {
    id: "f12",
    type: "Code Growth Spike",
    severity: "low",
    student: "E. Chen",
    studentId: "u9",
    exercise: "Functions Calculator",
    exerciseId: "e2",
    time: "2w ago",
    evidence: [
      "  import math",
      "+ def solve(x):",
      "+     return math.sqrt(x)",
      " ",
      "  LOC delta: +18 in 0.4s (baseline median 8m)",
    ],
    recommendation: "Likely IDE autocompletion. Monitor — escalate if repeats.",
    course: "CS101 · Section 04",
  },
];

const SEVERITY_ORDER = { critical: 0, high: 1, moderate: 2, low: 3 };
const SEVERITY_RANK = {
  critical: "Critical",
  high: "High",
  moderate: "Moderate",
  low: "Low",
};

const TYPE_OPTIONS = [
  "All types",
  "Behavioral Anomaly",
  "Code Growth Spike",
  "Hardcoding",
  "Output Mismatch",
  "Passive Behavior",
  "Off-By-One",
  "Missing Return",
  "Infinite Loop",
  "Blank Template",
];

const SEVERITY_OPTIONS = [
  "All severities",
  "Critical",
  "High",
  "Moderate",
  "Low",
];

const SEVERITY_BADGE_TONE = {
  critical: "border border-destructive/30 bg-destructive/10 text-destructive",
  high: "border border-cds-high/30 bg-cds-high/10 text-cds-high",
  moderate: "border border-cds-mod/30 bg-cds-mod/10 text-cds-mod",
  low: "border border-cds-low/30 bg-cds-low/10 text-cds-low",
};

const SEVERITY_RISK_LEVEL = {
  critical: "high",
  high: "high",
  moderate: "moderate",
  low: "low",
};

function severityCount(list, sev) {
  return list.filter((f) => f.severity === sev).length;
}

export default function InstructorIntegrity() {
  const [severity, setSeverity] = useState("All severities");
  const [type, setType] = useState("All types");
  const [query, setQuery] = useState("");
  const [selected, setSelected] = useState(() => new Set());
  const [openFlag, setOpenFlag] = useState(null);

  const counts = useMemo(
    () => ({
      critical: severityCount(FLAGS, "critical"),
      high: severityCount(FLAGS, "high"),
      moderate: severityCount(FLAGS, "moderate"),
      low: severityCount(FLAGS, "low"),
    }),
    [],
  );

  const filtered = useMemo(() => {
    const q = query.trim().toLowerCase();
    return FLAGS.filter((f) => {
      if (severity !== "All severities" && SEVERITY_RANK[f.severity] !== severity) {
        return false;
      }
      if (type !== "All types" && f.type !== type) {
        return false;
      }
      if (q) {
        const hay = `${f.student} ${f.exercise} ${f.type}`.toLowerCase();
        if (!hay.includes(q)) return false;
      }
      return true;
    }).sort((a, b) => {
      const sev = SEVERITY_ORDER[a.severity] - SEVERITY_ORDER[b.severity];
      if (sev !== 0) return sev;
      return 0;
    });
  }, [severity, type, query]);

  const firstHighlighted = filtered[0]?.id ?? null;

  const toggleSelected = (id) => {
    setSelected((prev) => {
      const next = new Set(prev);
      if (next.has(id)) next.delete(id);
      else next.add(id);
      return next;
    });
  };

  const clearSelection = () => setSelected(new Set());

  const onBulk = (action) => {
    /* wiring target: optimistic update + POST /api/integrity/flags/bulk */
    clearSelection();
  };

  const openDetail = (item) => {
    setOpenFlag(item);
  };

  const renderRow = (item) => {
    const isSelected = selected.has(item.id);
    return (
      <>
        <span
          onClick={(e) => e.stopPropagation()}
          onKeyDown={(e) => e.stopPropagation()}
          className="shrink-0"
        >
          <Checkbox
            checked={isSelected}
            onCheckedChange={() => toggleSelected(item.id)}
            aria-label={`Select ${item.type} for ${item.student}`}
          />
        </span>

        <RiskBadge level={SEVERITY_RISK_LEVEL[item.severity]} />

        <span
          className={cn(
            "shrink-0 px-2 py-0.5 rounded-full text-[10px] font-semibold uppercase tracking-wide",
            SEVERITY_BADGE_TONE[item.severity],
          )}
        >
          {SEVERITY_RANK[item.severity]}
        </span>

        <span className="text-sm font-medium text-foreground truncate min-w-[10rem]">
          {item.type}
        </span>

        <span className="text-sm text-muted-foreground truncate min-w-[6rem]">
          {item.student}
        </span>

        <span className="text-sm text-muted-foreground truncate min-w-[10rem] flex-1">
          {item.exercise}
        </span>

        <span className="text-xs text-muted-foreground font-mono tabular-nums shrink-0 w-14 text-right">
          {item.time}
        </span>

        <Button
          variant="ghost"
          size="sm"
          className="font-medium shrink-0"
          onClick={(e) => {
            e.stopPropagation();
            openDetail(item);
          }}
        >
          Review
          <ArrowRight className="ml-1.5 h-3.5 w-3.5" strokeWidth={2} />
        </Button>
      </>
    );
  };

  return (
    <div className="space-y-6 sm:space-y-8">
      {/* ---------- PageHeader ---------- */}
      <div className="space-y-2">
        <PageBreadcrumb crumbs={[{ label: "Integrity" }]} />
        <div className="flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between">
          <div className="min-w-0 space-y-1">
            <h1 className="text-2xl font-semibold tracking-tight">Integrity</h1>
            <p className="text-sm text-muted-foreground">
              Behavioral and structural anomalies requiring instructor review.
            </p>
          </div>
          <div className="flex items-center gap-2 shrink-0">
            {selected.size > 0 ? (
              <span className="text-xs text-muted-foreground font-mono tabular-nums">
                {selected.size} selected
              </span>
            ) : null}
            <DropdownMenu>
              <DropdownMenuTrigger asChild>
                <Button
                  variant="outline"
                  size="sm"
                  className="font-medium"
                  disabled={selected.size === 0}
                >
                  Bulk action
                  <ChevronDown className="ml-1.5 h-3.5 w-3.5" strokeWidth={1.5} />
                </Button>
              </DropdownMenuTrigger>
              <DropdownMenuContent align="end" className="w-48">
                <DropdownMenuLabel>{selected.size} flag{selected.size === 1 ? "" : "s"} selected</DropdownMenuLabel>
                <DropdownMenuSeparator />
                <DropdownMenuItem onClick={() => onBulk("clear")}>
                  <Check className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                  Clear
                </DropdownMenuItem>
                <DropdownMenuItem onClick={() => onBulk("dismiss")}>
                  <X className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                  Dismiss
                </DropdownMenuItem>
                <DropdownMenuSeparator />
                <DropdownMenuItem
                  onClick={() => onBulk("escalate")}
                  className="text-destructive focus:text-destructive"
                >
                  <AlertTriangle className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                  Escalate
                </DropdownMenuItem>
              </DropdownMenuContent>
            </DropdownMenu>
          </div>
        </div>
      </div>

      {/* ---------- Insight ---------- */}
      <InsightHeader
        eyebrow="Action required"
        insight="2 active flags need your review — highest severity first."
        description="Critical and high-severity flags are pinned to the top of the queue."
        action={
          <Button asChild size="sm" className="font-medium">
            <Link to={`/instructor/integrity/${FLAGS[0].id}`}>
              Review top flag
              <ArrowRight className="ml-1.5 h-3.5 w-3.5" strokeWidth={2} />
            </Link>
          </Button>
        }
      />

      {/* ---------- Evidence ---------- */}
      <EvidenceRow
        chips={[
          { label: "Critical", value: counts.critical, delta: null, series: [0, 0, 0, 0, 0, 0, 1], comparison: "this week" },
          { label: "High",     value: counts.high,     delta: null, series: [0, 0, 0, 0, 1, 1, 1], comparison: "this week" },
          { label: "Moderate", value: counts.moderate, delta: null, series: [1, 1, 2, 2, 3, 3, 3], comparison: "this week" },
          { label: "Low",      value: counts.low,      delta: null, series: [3, 4, 5, 5, 6, 7, 7], comparison: "this week" },
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
            placeholder="Search student, exercise, or type…"
            className="pl-9 h-9"
          />
        </div>
        <div className="grid grid-cols-2 gap-3 sm:flex sm:items-center">
          <Select value={severity} onValueChange={setSeverity}>
            <SelectTrigger className="h-9 w-full sm:w-40">
              <SelectValue />
            </SelectTrigger>
            <SelectContent>
              {SEVERITY_OPTIONS.map((s) => (
                <SelectItem key={s} value={s}>
                  {s}
                </SelectItem>
              ))}
            </SelectContent>
          </Select>
          <Select value={type} onValueChange={setType}>
            <SelectTrigger className="h-9 w-full sm:w-52">
              <SelectValue />
            </SelectTrigger>
            <SelectContent>
              {TYPE_OPTIONS.map((t) => (
                <SelectItem key={t} value={t}>
                  {t}
                </SelectItem>
              ))}
            </SelectContent>
          </Select>
        </div>
      </div>

      {/* ---------- DecisionList ---------- */}
      {filtered.length > 0 ? (
        <div className="space-y-2">
          <div className="flex items-center justify-between">
            <h2 className="text-sm font-semibold">Queue</h2>
            <span className="text-xs text-muted-foreground font-mono tabular-nums">
              {filtered.length} flag{filtered.length === 1 ? "" : "s"}
            </span>
          </div>
          <DecisionList
            items={filtered}
            highlightIndex={0}
            onAction={openDetail}
            renderRow={renderRow}
          />
        </div>
      ) : (
        <div className="rounded-lg border border-dashed border-border bg-card/40 p-8 text-center">
          <ShieldAlert
            className="h-6 w-6 text-muted-foreground mx-auto mb-2"
            strokeWidth={1.5}
          />
          <p className="text-sm font-medium">No flags match the current filters.</p>
          <p className="text-xs text-muted-foreground mt-1">
            Clear the search or pick a different severity to widen the queue.
          </p>
        </div>
      )}

      {/* ---------- DetailDrawer ---------- */}
      <DetailDrawer
        open={Boolean(openFlag)}
        onClose={() => setOpenFlag(null)}
        title={openFlag ? openFlag.type : "Flag detail"}
        subtitle={openFlag ? `${openFlag.student} · ${openFlag.exercise}` : ""}
      >
        {openFlag ? (
          <div className="space-y-6">
            <div className="flex items-center justify-between">
              <div className="space-y-1">
                <p className="text-xs uppercase tracking-wider text-muted-foreground">
                  Classification
                </p>
                <RiskBadge level={SEVERITY_RISK_LEVEL[openFlag.severity]} />
              </div>
              <div className="text-right">
                <p className="text-xs uppercase tracking-wider text-muted-foreground">
                  Flagged
                </p>
                <p className="text-sm font-mono tabular-nums">{openFlag.time}</p>
              </div>
            </div>

            <div className="rounded-md border border-border bg-muted/40 p-4 space-y-1">
              <p className="text-xs uppercase tracking-wider text-muted-foreground">
                Student
              </p>
              <p className="text-sm font-medium">{openFlag.student}</p>
              <p className="text-xs text-muted-foreground">{openFlag.course}</p>
            </div>

            <div className="space-y-2">
              <p className="text-xs uppercase tracking-wider text-muted-foreground">
                Evidence · code diff
              </p>
              <pre className="rounded-md bg-muted/40 p-3 font-mono text-xs leading-relaxed overflow-x-auto">
                {openFlag.evidence.join("\n")}
              </pre>
            </div>

            <div className="rounded-md border border-border bg-card p-4 space-y-1">
              <p className="text-xs uppercase tracking-wider text-muted-foreground">
                Recommended action
              </p>
              <p className="text-sm text-foreground leading-relaxed">
                {openFlag.recommendation}
              </p>
            </div>

            <div className="flex items-center justify-end gap-2 pt-2 border-t border-border">
              <Button
                variant="outline"
                size="sm"
                onClick={() => setOpenFlag(null)}
                className="font-medium"
              >
                <X className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                Dismiss
              </Button>
              <Button
                variant="outline"
                size="sm"
                onClick={() => setOpenFlag(null)}
                className="font-medium text-destructive border-destructive/40 hover:bg-destructive/10"
              >
                <AlertTriangle className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                Escalate
              </Button>
              <Button
                size="sm"
                onClick={() => setOpenFlag(null)}
                className="font-medium"
              >
                <Check className="h-3.5 w-3.5 mr-1.5" strokeWidth={2} />
                Resolve
              </Button>
            </div>
          </div>
        ) : null}
      </DetailDrawer>
    </div>
  );
}
