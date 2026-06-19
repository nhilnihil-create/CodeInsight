import { useState } from "react";
import { AlertTriangle, ChevronDown, ChevronRight, Shield } from "lucide-react";
import { cn } from "@/lib/utils";

const FLAG_META = {
  HARDCODING: {
    label: "Hardcoding",
    color: "text-rose-400",
    bg: "bg-rose-500/10",
    border: "border-rose-500/30",
    ring: "ring-rose-500/20",
    icon: Shield,
    description: "Suspicious hardcoded output detected",
  },
  BLANK_TEMPLATE: {
    label: "Blank Template",
    color: "text-amber-400",
    bg: "bg-amber-500/10",
    border: "border-amber-500/30",
    ring: "ring-amber-500/20",
    icon: AlertTriangle,
    description: "Submission matches starter code",
  },
  BEHAVIORAL_ANOMALY: {
    label: "Behavioral Anomaly",
    color: "text-sky-400",
    bg: "bg-sky-500/10",
    border: "border-sky-500/30",
    ring: "ring-sky-500/20",
    icon: AlertTriangle,
    description: "Unusual submission pattern detected",
  },
  CODE_GROWTH_ANOMALY: {
    label: "Code Growth",
    color: "text-emerald-400",
    bg: "bg-emerald-500/10",
    border: "border-emerald-500/30",
    ring: "ring-emerald-500/20",
    icon: AlertTriangle,
    description: "Significant code size change",
  },
  PASSIVE_BEHAVIOR_LOG: {
    label: "Passive Behavior",
    color: "text-violet-400",
    bg: "bg-violet-500/10",
    border: "border-violet-500/30",
    ring: "ring-violet-500/20",
    icon: AlertTriangle,
    description: "Tab switches, pastes, or idle time detected",
  },
};

const SEVERITY_META = {
  high: { label: "HIGH", color: "text-rose-400", dot: "bg-rose-400" },
  medium: { label: "MED", color: "text-amber-400", dot: "bg-amber-400" },
  low: { label: "LOW", color: "text-emerald-400", dot: "bg-emerald-400" },
};

const EVIDENCE_LABELS = {
  idle_ratio: "Idle %",
  paste_count: "Pastes",
  tab_switch_count: "Tab Sw.",
  idle_time_seconds: "Idle",
  total_time_seconds: "Total",
  submission_count: "Submissions",
  avg_score: "Avg Score",
  score_drop: "Drop",
  code_size_change_pct: "Size Δ%",
  lines_added: "+Lines",
  lines_removed: "-Lines",
  similar_students: "Similar",
  identical_count: "Identical",
  time_seconds: "Time",
};

function formatEvidenceKey(key) {
  if (EVIDENCE_LABELS[key]) return EVIDENCE_LABELS[key];
  return key
    .replace(/_/g, " ")
    .replace(/([a-z])([A-Z])/g, "$1 $2")
    .replace(/\b\w/g, (c) => c.toUpperCase());
}

function EvidenceValue({ value }) {
  if (value === null || value === undefined) {
    return <span className="text-muted-foreground/50 italic">null</span>;
  }
  if (typeof value === "boolean") {
    return <span className="text-sky-400">{value ? "true" : "false"}</span>;
  }
  if (typeof value === "number") {
    return <span className="text-amber-400 font-mono">{value}</span>;
  }
  if (typeof value === "string") {
    if (value.length > 120) {
      return (
        <span className="font-mono text-xs text-foreground/80 leading-relaxed">
          {value}
        </span>
      );
    }
    return <span className="text-foreground/90">{value}</span>;
  }
  if (Array.isArray(value)) {
    if (value.length === 0) {
      return <span className="text-muted-foreground/50 italic">empty</span>;
    }
    return (
      <div className="flex flex-wrap gap-1.5">
        {value.map((item, i) => (
          <span
            key={i}
            className="inline-flex items-center rounded-md border border-border/60 bg-muted/40 px-2 py-0.5 text-[11px] font-mono text-foreground/80"
          >
            {typeof item === "string" ? item : JSON.stringify(item)}
          </span>
        ))}
      </div>
    );
  }
  if (typeof value === "object") {
    return (
      <div className="rounded-md border border-border/40 bg-muted/30 p-2.5 font-mono text-[11px] text-foreground/80 space-y-1">
        {Object.entries(value).map(([k, v]) => (
          <div key={k} className="flex gap-2">
            <span className="text-muted-foreground/70 shrink-0">
              {formatEvidenceKey(k)}:
            </span>
            <span className="text-foreground/80 break-all">
              {typeof v === "string" ? v : JSON.stringify(v)}
            </span>
          </div>
        ))}
      </div>
    );
  }
  return <span className="text-foreground/80 font-mono">{String(value)}</span>;
}

const HIDDEN_EVIDENCE_KEYS = new Set(["summary", "confidence", "innocent_explanation"]);

function ConfidenceBar({ confidence }) {
  const pct = Math.round(confidence * 100);
  const color =
    pct < 30 ? "bg-emerald-500" :
    pct < 60 ? "bg-amber-500" :
    "bg-rose-500";
  const label =
    pct < 30 ? "Low" :
    pct < 60 ? "Medium" :
    "High";
  return (
    <div className="flex items-center gap-2">
      <div className="flex-1 h-1.5 rounded-full bg-muted/50 overflow-hidden">
        <div className={cn("h-full rounded-full transition-all", color)} style={{ width: `${pct}%` }} />
      </div>
      <span className="text-[10px] text-muted-foreground/60 font-medium w-12 text-right">{label}</span>
    </div>
  );
}

function FlagCard({ flag, isExpanded, onToggle }) {
  const meta = FLAG_META[flag.flag_type] || FLAG_META.BEHAVIORAL_ANOMALY;
  const sev = SEVERITY_META[flag.severity] || SEVERITY_META.medium;
  const Icon = meta.icon;

  const evidenceIsString = typeof flag.evidence === "string";
  const evidenceIsObj =
    flag.evidence && typeof flag.evidence === "object" && !Array.isArray(flag.evidence);
  const summary = evidenceIsObj ? flag.evidence.summary : (evidenceIsString ? flag.evidence : null);
  const confidence = evidenceIsObj ? flag.evidence.confidence : null;
  const innocentExplanation = evidenceIsObj ? flag.evidence.innocent_explanation : null;
  const evidenceEntries = evidenceIsObj
    ? Object.entries(flag.evidence).filter(([k]) => !HIDDEN_EVIDENCE_KEYS.has(k))
    : [];

  return (
    <div
      className={cn(
        "rounded-lg border transition-all duration-200",
        meta.border,
        meta.bg,
        isExpanded && "ring-1",
        isExpanded && meta.ring
      )}
    >
      <button
        onClick={onToggle}
        className="w-full flex items-center gap-3 px-3.5 py-2.5 text-left group"
      >
        <div
          className={cn(
            "shrink-0 h-7 w-7 rounded-md flex items-center justify-center",
            meta.bg,
            meta.border,
            "border"
          )}
        >
          <Icon className={cn("h-3.5 w-3.5", meta.color)} strokeWidth={1.5} />
        </div>

        <div className="flex-1 min-w-0">
          <div className="flex items-center gap-2">
            <span className={cn("text-xs font-semibold", meta.color)}>
              {meta.label}
            </span>
            <div className="flex items-center gap-1">
              <div className={cn("h-1.5 w-1.5 rounded-full", sev.dot)} />
              <span className={cn("text-[10px] font-bold tracking-wide uppercase", sev.color)}>
                {sev.label}
              </span>
            </div>
          </div>
          <p className="text-[11px] text-muted-foreground mt-0.5 truncate">
            {summary || meta.description}
          </p>
        </div>

        <div className="shrink-0 text-muted-foreground/50 group-hover:text-muted-foreground transition-colors">
          {isExpanded ? (
            <ChevronDown className="h-3.5 w-3.5" />
          ) : (
            <ChevronRight className="h-3.5 w-3.5" />
          )}
        </div>
      </button>

      {isExpanded && flag.evidence && (
        <div className="px-3.5 pb-3 pt-1 border-t border-border/40 space-y-2">
          {summary && (
            <p className="text-xs text-foreground/80">{summary}</p>
          )}

          {confidence !== null && (
            <div className="p-2 rounded bg-muted/30 border border-border/40">
              <span className="text-[10px] text-muted-foreground/60 font-semibold uppercase tracking-wider">Confidence</span>
              <ConfidenceBar confidence={confidence} />
            </div>
          )}

          {innocentExplanation && (
            <div className="p-2.5 rounded bg-emerald-500/8 border border-emerald-500/20">
              <span className="text-[10px] text-emerald-400 font-semibold uppercase tracking-wider">
                Possible innocent explanation
              </span>
              <p className="text-[11px] text-foreground/70 mt-1 leading-relaxed">
                {innocentExplanation}
              </p>
            </div>
          )}

          {evidenceEntries.length > 0 && (
            <div className="grid grid-cols-3 gap-x-4 gap-y-1.5">
              {evidenceEntries.map(([key, value]) => (
                <div key={key} className="flex items-baseline gap-1.5 min-w-0">
                  <span className="text-[10px] text-muted-foreground/50 shrink-0">
                    {formatEvidenceKey(key)}
                  </span>
                  <EvidenceValue value={value} />
                </div>
              ))}
            </div>
          )}

          {flag.context_behaviors && flag.context_behaviors.length > 0 && (
            <div className="flex flex-wrap gap-1">
              {flag.context_behaviors.map((b, i) => (
                <span
                  key={i}
                  className="inline-flex items-center rounded bg-muted/60 px-1.5 py-px text-[10px] text-muted-foreground"
                >
                  {b}
                </span>
              ))}
            </div>
          )}
        </div>
      )}
    </div>
  );
}

export default function FlagEvidencePanel({ flags }) {
  const [expandedIdx, setExpandedIdx] = useState(null);

  if (!flags || flags.length === 0) {
    return (
      <div className="flex items-center gap-2 px-4 py-3 text-xs text-muted-foreground/60">
        <Shield className="h-3.5 w-3.5" strokeWidth={1.5} />
        No integrity flags for this submission.
      </div>
    );
  }

  return (
    <div className="space-y-2">
      {flags.map((flag, idx) => (
        <FlagCard
          key={flag.id || idx}
          flag={flag}
          isExpanded={expandedIdx === idx}
          onToggle={() => setExpandedIdx(expandedIdx === idx ? null : idx)}
        />
      ))}
    </div>
  );
}
