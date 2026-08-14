import { useState, useEffect, useCallback, useRef } from "react";
import { Badge } from "@/components/ui/badge";
import { Skeleton } from "@/components/ui/skeleton";
import {
  Play,
  CheckCircle,
  XCircle,
  Terminal,
  FileCode,
  Clock,
  AlertTriangle,
  X,
  ChevronLeft,
  ChevronDown,
  Shield,
} from "lucide-react";
import { cn } from "@/lib/utils";
import { formatDuration } from "@/lib/format";
import api from "@/services/api";
import { useSidebar } from "@/context/SidebarContext";
import CodeViewer from "./CodeViewer";
import FlagEvidencePanel from "./FlagEvidencePanel";

const DESKTOP_QUERY = "(min-width: 1024px)";

function timeAgo(dateStr) {
  if (!dateStr) return "";
  const ms = Date.now() - new Date(dateStr).getTime();
  const mins = Math.floor(ms / 60000);
  if (mins < 1) return "just now";
  if (mins < 60) return `${mins}m ago`;
  const hours = Math.floor(mins / 60);
  if (hours < 24) return `${hours}h ago`;
  const days = Math.floor(hours / 24);
  return `${days}d ago`;
}

function ordinal(n) {
  const s = ["th", "st", "nd", "rd"];
  const v = n % 100;
  return n + (s[(v - 20) % 10] || s[v] || s[0]);
}

const ANIM_DURATION = 200;

const SEVERITY_RING = {
  high: "ring-rose-500/40",
  medium: "ring-amber-500/40",
  low: "ring-emerald-500/40",
};

export default function SubmissionDetailDrawer({ submission, open, onClose }) {
  const [runs, setRuns] = useState([]);
  const [flags, setFlags] = useState([]);
  const [selectedIdx, setSelectedIdx] = useState(0);
  const [loading, setLoading] = useState(false);
  const [flagsExpanded, setFlagsExpanded] = useState(false);
  const { isOpen } = useSidebar();

  const [mounted, setMounted] = useState(false);
  const [visible, setVisible] = useState(false);
  const closeTimer = useRef(null);

  // Responsive: on mobile the sidebar is off-canvas, so left offset is 0.
  const [isDesktop, setIsDesktop] = useState(
    () => typeof window !== "undefined" && window.matchMedia(DESKTOP_QUERY).matches,
  );
  useEffect(() => {
    const mql = window.matchMedia(DESKTOP_QUERY);
    const handler = (e) => setIsDesktop(e.matches);
    mql.addEventListener("change", handler);
    return () => mql.removeEventListener("change", handler);
  }, []);

  useEffect(() => {
    if (open) {
      setMounted(true);
      requestAnimationFrame(() => {
        requestAnimationFrame(() => setVisible(true));
      });
    } else if (mounted) {
      setVisible(false);
      closeTimer.current = setTimeout(() => {
        setMounted(false);
        setFlags([]);
        setFlagsExpanded(false);
      }, ANIM_DURATION);
    }
    return () => clearTimeout(closeTimer.current);
  }, [open, mounted]);

  const fetchData = useCallback(async () => {
    if (!submission?.id) return;
    setLoading(true);
    try {
      const [runsRes, flagsRes] = await Promise.all([
        api.get(`/api/analytics/submissions/${submission.id}/runs`),
        api.get(`/api/analytics/submissions/${submission.id}/flags`).catch(() => ({ data: { flags: [] } })),
      ]);
      setRuns(runsRes.data.runs || []);
      setSelectedIdx((runsRes.data.runs || []).length - 1);
      setFlags(flagsRes.data.flags || []);
    } catch {
      setRuns([]);
      setFlags([]);
    } finally {
      setLoading(false);
    }
  }, [submission?.id]);

  useEffect(() => {
    if (open) fetchData();
  }, [open, fetchData]);

  useEffect(() => {
    if (!open) return;
    const handler = (e) => {
      if (e.key === "Escape") onClose();
    };
    window.addEventListener("keydown", handler);
    return () => window.removeEventListener("keydown", handler);
  }, [open, onClose]);

  const current = runs[selectedIdx];

  // Mobile: auto-select latest run when data changes
  useEffect(() => {
    if (!isDesktop && runs.length > 0) {
      setSelectedIdx(runs.length - 1);
    }
  }, [isDesktop, runs.length]);

  const highFlagCount = flags.filter((f) => f.severity === "high").length;
  const topSeverity =
    highFlagCount > 0
      ? "high"
      : flags.some((f) => f.severity === "medium")
        ? "medium"
        : "low";

  if (!mounted) return null;

  // On mobile the sidebar drawer is off-canvas → no left offset.
  const sidebarLeft = isDesktop ? (isOpen ? 220 : 70) : 0;

  return (
    <>
      {/* Backdrop */}
      <div
        className="fixed inset-0 z-50 bg-black/40 backdrop-blur-sm transition-opacity"
        style={{
          left: sidebarLeft,
          opacity: visible ? 1 : 0,
          transitionDuration: `${ANIM_DURATION}ms`,
          transitionTimingFunction: "cubic-bezier(0.16, 1, 0.3, 1)",
        }}
        onClick={onClose}
      />        {/* Panel */}
      <div
        className="fixed inset-y-0 right-0 z-50 flex flex-col bg-background border-l border-border shadow-2xl"
        style={{
          left: sidebarLeft,
          right: 0,
          opacity: visible ? 1 : 0,
          transform: visible ? "translateX(0)" : "translateX(8px)",
          transition: `opacity ${ANIM_DURATION}ms cubic-bezier(0.16, 1, 0.3, 1), transform ${ANIM_DURATION}ms cubic-bezier(0.16, 1, 0.3, 1)`,
        }}
      >
        {/* Header bar */}
        <div className="flex items-center justify-between px-3 sm:px-5 py-2.5 sm:py-3 border-b border-border shrink-0 bg-muted/20 gap-2">
          <div className="flex items-center gap-2 sm:gap-4 min-w-0 flex-1">
            <button
              onClick={onClose}
              className="inline-flex items-center gap-1 text-xs font-medium text-muted-foreground hover:text-foreground transition-colors shrink-0"
            >
              <ChevronLeft className="h-4 w-4" strokeWidth={1.5} />
              <span className="hidden sm:inline">Back</span>
            </button>
            <div className="h-4 w-px bg-border hidden sm:block" />
            <div className="min-w-0">
              <div className="text-sm font-semibold truncate">
                {submission?.student_name || "Submission Detail"}
              </div>
              <div className="text-xs text-muted-foreground truncate">
                {submission?.student_email}
                <span className="mx-1.5 text-muted-foreground/40 hidden sm:inline">·</span>
                <span className="hidden sm:inline">{submission?.exercise_title}</span>
                {submission?.time_spent_seconds !== null &&
                  submission?.time_spent_seconds !== undefined && (
                  <>
                    <span className="mx-1.5 text-muted-foreground/40">·</span>
                    <span className="inline-flex items-center gap-1" title="Time spent on this attempt">
                      <Clock className="h-3 w-3" strokeWidth={1.5} />
                      {formatDuration(submission.time_spent_seconds)}
                    </span>
                  </>
                )}
              </div>
            </div>
          </div>
          <div className="flex items-center gap-1.5 sm:gap-2 shrink-0">
            {/* Flags badge */}
            {flags.length > 0 && (
              <button
                onClick={() => setFlagsExpanded(!flagsExpanded)}
                className={cn(
                  "inline-flex items-center gap-1.5 rounded-md px-2.5 py-1 text-xs font-semibold transition-all duration-200",
                  "border",
                  flagsExpanded
                    ? cn(
                        "bg-rose-500/15 border-rose-500/40 text-rose-400",
                        "ring-1 ring-rose-500/20"
                      )
                    : "border-border/60 bg-muted/40 text-muted-foreground hover:text-foreground hover:bg-muted/60"
                )}
              >
                <Shield className="h-3 w-3" strokeWidth={2} />
                <span>{flags.length}</span>
                <ChevronDown
                  className={cn(
                    "h-3 w-3 transition-transform duration-200",
                    flagsExpanded ? "rotate-180" : ""
                  )}
                />
              </button>
            )}

            <Badge
              variant={submission?.is_correct ? "default" : "destructive"}
              className="hidden sm:inline-flex"
            >
              {submission?.is_correct ? (
                <>
                  <CheckCircle className="h-3 w-3 mr-1" /> Pass
                </>
              ) : (
                <>
                  <XCircle className="h-3 w-3 mr-1" /> Fail
                </>
              )}
            </Badge>
            <button
              onClick={onClose}
              className="h-8 w-8 inline-flex items-center justify-center rounded-md hover:bg-muted transition-colors"
              aria-label="Close"
            >
              <X className="h-4 w-4" strokeWidth={1.5} />
            </button>
          </div>
        </div>

        {/* Flags bar (collapsible) */}
        {flags.length > 0 && (
          <div
            className="border-b border-border/60 overflow-hidden transition-all duration-300 ease-out"
            style={{
              maxHeight: flagsExpanded ? "200px" : "0px",
              opacity: flagsExpanded ? 1 : 0,
            }}
          >
            <div className="px-5 py-2.5 bg-muted/10 overflow-y-auto" style={{ maxHeight: "200px" }}>
              <FlagEvidencePanel flags={flags} />
            </div>
          </div>
        )}

        {/* Body */}
        {loading ? (
          <div className="flex-1 p-5 space-y-3">
            <Skeleton className="h-4 w-1/3" />
            <Skeleton className="h-4 w-1/2" />
            <Skeleton className="h-60 w-full" />
          </div>
        ) : runs.length === 0 ? (
          <div className="flex-1 flex items-center justify-center text-sm text-muted-foreground p-5">
            No run history available for this submission.
          </div>
        ) : (
          <div className="flex flex-1 min-h-0">
            {/* Mobile run selector — compact dropdown visible below lg */}
            {runs.length > 1 && (
              <div className="lg:hidden flex items-center gap-2 px-3 py-2 border-b border-border bg-muted/10 shrink-0">
                <span className="text-[11px] font-semibold text-muted-foreground uppercase tracking-wider shrink-0">
                  Run
                </span>
                <select
                  value={selectedIdx}
                  onChange={(e) => setSelectedIdx(Number(e.target.value))}
                  className="flex-1 h-7 rounded-md border border-border bg-background px-2 text-xs text-foreground focus:outline-none focus:ring-1 focus:ring-ring"
                >
                  {runs.map((run, idx) => {
                    const runCount = runs.slice(0, idx + 1).filter((r) => !r.is_submission).length;
                    const submissionCount = runs.slice(0, idx + 1).filter((r) => r.is_submission).length;
                    return (
                      <option key={idx} value={idx}>
                        {run.is_submission
                          ? `${ordinal(submissionCount)} Submission`
                          : `Run #${runCount}`}
                        {run.error_count > 0 ? ` (${run.error_count}E)` : ""}
                        {run.is_submission && submissionCount === runs.filter((r) => r.is_submission).length ? " • FINAL" : ""}
                      </option>
                    );
                  })}
                </select>
              </div>
            )}

            {/* Timeline sidebar — desktop only */}
            <div className="hidden lg:flex w-56 shrink-0 border-r border-border overflow-y-auto bg-muted/10">
              <div className="px-4 py-3 text-[11px] font-semibold text-muted-foreground uppercase tracking-wider border-b border-border sticky top-0 bg-muted/10 backdrop-blur-sm">
                <Clock className="h-3 w-3 inline mr-1.5" strokeWidth={1.5} />
                Run History ({runs.length})
              </div>
              <div className="py-1">
                {runs.map((run, idx) => {
                  const runCount = runs.slice(0, idx + 1).filter((r) => !r.is_submission).length;
                  const submissionCount = runs.slice(0, idx + 1).filter((r) => r.is_submission).length;
                  const totalSubmissions = runs.filter((r) => r.is_submission).length;
                  return (
                    <button
                      key={idx}
                      onClick={() => setSelectedIdx(idx)}
                      className={cn(
                        "w-full text-left px-4 py-3 text-xs transition-colors flex items-start gap-3 border-l-2",
                        selectedIdx === idx
                          ? "bg-muted/50 border-l-primary text-foreground"
                          : "border-l-transparent text-muted-foreground hover:bg-muted/30 hover:text-foreground"
                      )}
                    >
                      <div className="shrink-0 mt-0.5">
                        {run.is_submission ? (
                          <FileCode
                            className="h-4 w-4 text-primary"
                            strokeWidth={1.5}
                          />
                        ) : run.error_count > 0 ? (
                          <AlertTriangle
                            className="h-4 w-4 text-warning"
                            strokeWidth={1.5}
                          />
                        ) : (
                          <Play
                            className="h-4 w-4 text-emerald-400"
                            strokeWidth={1.5}
                          />
                        )}
                      </div>
                      <div className="min-w-0 flex-1">
                        <div className="font-medium truncate">
                          {run.is_submission
                            ? `${ordinal(submissionCount)} Submission`
                            : `Run #${runCount}`}
                        </div>
                        <div className="flex items-center gap-2 mt-0.5">
                          <span className="text-[10px] text-muted-foreground">
                            {timeAgo(run.run_at)}
                          </span>
                          {run.error_count > 0 && (
                            <span className="text-[10px] text-destructive font-medium">
                              {run.error_count}E
                            </span>
                          )}
                          {run.is_submission && (
                            <span className="text-[10px] text-primary font-medium">
                              {ordinal(submissionCount)}{submissionCount === totalSubmissions ? " • FINAL" : ""}
                            </span>
                          )}
                        </div>
                      </div>
                    </button>
                  );
                })}
              </div>
            </div>

            {/* Code + compiler log */}
            <div className="flex-1 flex flex-col min-w-0 min-h-0">
              <div className="flex-1 min-h-0">
                {current && (
                  <CodeViewer
                    key={current.code?.slice(0, 100)}
                    code={current.code}
                  />
                )}
              </div>

              {current?.compiler_log && (
                <div className="border-t border-border shrink-0 max-h-32 sm:max-h-48 overflow-y-auto bg-muted/20">
                  <div className="flex items-center gap-1.5 px-5 py-2 text-[11px] font-semibold text-muted-foreground uppercase tracking-wider border-b border-border sticky top-0 bg-muted/20 backdrop-blur-sm">
                    <Terminal className="h-3 w-3" strokeWidth={1.5} />
                    Compiler Output
                  </div>
                  <pre className="px-5 py-3 text-xs font-mono text-amber-300/90 whitespace-pre-wrap leading-relaxed">
                    {current.compiler_log}
                  </pre>
                </div>
              )}
            </div>
          </div>
        )}
      </div>
    </>
  );
}
