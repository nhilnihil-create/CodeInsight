import { useMemo, useState, useEffect, useCallback } from "react";
import { Link } from "react-router-dom";
import {
  Search,
  Check,
  AlertTriangle,
  ShieldAlert,
  RefreshCw,
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
import InsightHeader from "@/components/ui/insight-header";
import EvidenceRow from "@/components/ui/evidence-row";
import RiskBadge from "@/components/ui/risk-badge";
import DecisionList from "@/components/ui/decision-list";
import DetailDrawer from "@/components/ui/detail-drawer";
import SectionFilter from "@/components/SectionFilter";
import { cn } from "@/lib/utils";
import { flagTypeLabel } from "@/lib/flagTypes";
import api from "@/services/api";
import useLastSection from "@/hooks/useLastSection";
import ExportDropdown from "@/components/ui/export-dropdown";

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

const SEVERITY_ORDER = { high: 0, medium: 1, low: 2 };

const SEVERITY_RANK = {
  high: "High",
  medium: "Moderate",
  low: "Low",
};

const SEVERITY_BADGE_TONE = {
  high: "bg-rose-500/10 text-rose-400 border border-rose-500/15",
  medium: "bg-amber-500/10 text-amber-300 border border-amber-500/15",
  low: "bg-emerald-500/10 text-emerald-400 border border-emerald-500/15",
};

const SEVERITY_RISK_LEVEL = {
  high: "high",
  medium: "moderate",
  low: "low",
};

export default function InstructorIntegrity() {
  const [sectionId, setSectionId] = useLastSection();
  const [flags, setFlags] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [severity, setSeverity] = useState("All severities");
  const [type, setType] = useState("All types");
  const [query, setQuery] = useState("");
  const [selected, setSelected] = useState(() => new Set());
  const [openFlag, setOpenFlag] = useState(null);
  const [saving, setSaving] = useState(null);

  const fetchFlags = useCallback(async () => {
    setLoading(true);
    setError(null);
    try {
      const url = sectionId
        ? `/api/analytics/sections/${sectionId}/integrity-flags`
        : "/api/analytics/integrity";
      const res = await api.get(url);
      setFlags((res.data.flags || []).map(f => ({ ...f, severity: (f.severity || "").toLowerCase() })));
    } catch (err) {
      setError(err.response?.data?.error || "Failed to load integrity flags");
    } finally {
      setLoading(false);
    }
  }, [sectionId]);

  useEffect(() => {
    fetchFlags();
  }, [fetchFlags]);

  const typeOptions = useMemo(() => {
    const set = new Set(flags.map((f) => f.flag_type));
    return ["All types", ...[...set].sort()];
  }, [flags]);

  const severityOptions = ["All severities", "High", "Moderate", "Low"];

  const counts = useMemo(
    () => ({
      high: flags.filter((f) => f.severity === "high" && f.status === "flagged").length,
      medium: flags.filter((f) => f.severity === "medium" && f.status === "flagged").length,
      low: flags.filter((f) => f.severity === "low" && f.status === "flagged").length,
    }),
    [flags],
  );

  const totalFlagged = flags.filter((f) => f.status === "flagged").length;

  const awaitingReview = useMemo(
    () => flags.filter((f) => f.status === "flagged" && (f.severity === "high" || f.severity === "medium")).length,
    [flags],
  );

  const filtered = useMemo(() => {
    const q = query.trim().toLowerCase();
    return flags
      .filter((f) => {
        if (severity !== "All severities" && SEVERITY_RANK[f.severity] !== severity) return false;
        if (type !== "All types" && f.flag_type !== type) return false;
        if (q) {
          const hay = `${f.student_name} ${f.exercise_title} ${f.flag_type}`.toLowerCase();
          if (!hay.includes(q)) return false;
        }
        return true;
      })
      .sort((a, b) => {
        const sev = (SEVERITY_ORDER[a.severity] ?? 99) - (SEVERITY_ORDER[b.severity] ?? 99);
        if (sev !== 0) return sev;
        return new Date(b.created_at).getTime() - new Date(a.created_at).getTime();
      });
      }, [flags, severity, type, query]);

  const filteredIds = useMemo(() => filtered.map((f) => f.id), [filtered]);

  const allSelected = filteredIds.length > 0 && filteredIds.every((id) => selected.has(id));
  const someSelected = filteredIds.some((id) => selected.has(id));

  const toggleSelected = (id) => {
    setSelected((prev) => {
      const next = new Set(prev);
      if (next.has(id)) next.delete(id);
      else next.add(id);
      return next;
    });
  };

  const clearSelection = () => setSelected(new Set());

  useEffect(() => {
    clearSelection();
  }, [severity, type]);

  const toggleSelectAll = () => {
    if (allSelected) {
      setSelected((prev) => {
        const next = new Set(prev);
        filteredIds.forEach((id) => next.delete(id));
        return next;
      });
    } else {
      setSelected((prev) => {
        const next = new Set(prev);
        filteredIds.forEach((id) => next.add(id));
        return next;
      });
    }
  };

  const onBulk = async (action) => {
    const ids = [...selected];
    if (!ids.length) return;
    setSaving("bulk");
    try {
      await Promise.all(
        ids.map((id) =>
          api.put(`/api/analytics/integrity-flags/${id}/review`, {
            status: action === "dismiss" ? "dismissed" : "reviewed",
            instructor_note: `Bulk ${action === "dismiss" ? "dismissed" : "reviewed"} from Integrity page`,
          }),
        ),
      );
      if (action === "reviewed") {
        setFlags((prev) => prev.filter((f) => !ids.includes(f.id)));
      } else {
        setFlags((prev) =>
          prev.map((f) => (ids.includes(f.id) ? { ...f, status: "dismissed" } : f)),
        );
      }
    } catch (err) {
      console.error(`Bulk ${action} failed:`, err);
    } finally {
      setSaving(null);
      clearSelection();
    }
  };

  const handleAction = async (item, status) => {
    setSaving(item.id);
    try {
      await api.put(`/api/analytics/integrity-flags/${item.id}/review`, { status });
      // Eject reviewed/dismissed flags from the list so UI recalculates
      if (status === "reviewed" || status === "dismissed") {
        setFlags((prev) => prev.filter((f) => f.id !== item.id));
      } else {
        setFlags((prev) =>
          prev.map((f) => (f.id === item.id ? { ...f, status } : f)),
        );
      }
      setOpenFlag(null);
    } catch (err) {
      console.error("Flag action failed:", err);
    } finally {
      setSaving(null);
    }
  };

  const openDetail = (item) => {
    setOpenFlag(item);
  };

  const renderRow = (item) => {
    const isSelected = selected.has(item.id);
    const isReviewed = item.status === "reviewed";
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
            aria-label={`Select ${flagTypeLabel(item.flag_type)} for ${item.student_name}`}
          />
        </span>

        <RiskBadge level={SEVERITY_RISK_LEVEL[item.severity] || "low"} />

        <span className="text-sm font-medium text-foreground truncate min-w-[10rem]">
          {flagTypeLabel(item.flag_type)}
        </span>

        <span className="text-sm text-muted-foreground truncate min-w-[6rem]">
          {item.student_name}
        </span>

        <span className="text-sm text-muted-foreground truncate min-w-[10rem] flex-1">
          {item.exercise_title}
        </span>

        <span className="text-xs text-muted-foreground font-mono tabular-nums shrink-0 w-14 text-right">
          {timeAgo(item.created_at)}
        </span>

        {isReviewed ? (
          <span className="inline-flex items-center gap-1 text-xs text-muted-foreground font-medium shrink-0">
            <Check className="h-3.5 w-3.5" strokeWidth={2} />
            Reviewed
          </span>
        ) : (
          <Button
            variant="ghost"
            size="sm"
            className="font-medium shrink-0"
            onClick={(e) => {
              e.stopPropagation();
              handleAction(item, "reviewed");
            }}
          >
            Mark Reviewed
            <Check className="ml-1.5 h-3.5 w-3.5" strokeWidth={2} />
          </Button>
        )}
      </>
    );
  };

  const topFlag = filtered[0];

  if (loading && flags.length === 0) {
    return (
      <div className="space-y-6 sm:space-y-8">
        <div className="flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between">
          <div className="min-w-0 space-y-1">
            <h1 className="text-2xl font-semibold tracking-tight">Integrity</h1>
            <p className="text-sm text-muted-foreground">Loading integrity flags…</p>
          </div>
          <SectionFilter value={sectionId} onChange={setSectionId} />
        </div>
        <div className="rounded-xl border border-border/60 bg-card/50 backdrop-blur-sm py-12 px-6 text-center">
          <RefreshCw className="h-6 w-6 text-muted-foreground mx-auto mb-2 animate-spin" />
          <p className="text-sm text-muted-foreground">Loading flags…</p>
        </div>
      </div>
    );
  }

  return (
    <div className="space-y-6 sm:space-y-8">
      {/* ---------- PageHeader ---------- */}
      <div className="flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between">
        <div className="min-w-0 space-y-1">
          <h1 className="text-2xl font-semibold tracking-tight">Integrity</h1>
          <p className="text-sm text-muted-foreground">
            Contextual indicators for instructor review. These flags are hypotheses, not verdicts.
          </p>
        </div>
        <div className="flex items-center gap-2 shrink-0">
          <SectionFilter value={sectionId} onChange={setSectionId} />
          <ExportDropdown sectionId={sectionId} domain="integrity" label="Export Integrity" />
          {error ? (
            <span className="text-xs text-destructive font-medium">{error}</span>
          ) : null}
          <Button variant="ghost" size="icon" onClick={fetchFlags} title="Refresh">
            <RefreshCw className="h-4 w-4" strokeWidth={1.5} />
          </Button>
        </div>
      </div>

      {error && (
        <div className="flex items-center gap-3 rounded-xl border border-rose-500/15 bg-rose-500/5 px-4 py-3">
          <AlertTriangle className="h-4 w-4 text-rose-400 shrink-0" />
          <p className="text-sm text-rose-400 flex-1">{error}</p>
          <Button size="sm" variant="outline" className="border-destructive/30 text-destructive" onClick={fetchFlags}>
            <RefreshCw className="h-3.5 w-3.5 mr-1.5" />
            Retry
          </Button>
        </div>
      )}

      {/* ---------- Insight ---------- */}
      <InsightHeader
        eyebrow={awaitingReview > 0 ? "Action required" : "No pending flags"}
        insight={
          awaitingReview > 0
            ? `${awaitingReview} flag${awaitingReview === 1 ? "" : "s"} awaiting review — highest severity first.`
            : totalFlagged > 0
              ? `${totalFlagged} flag${totalFlagged === 1 ? "" : "s"} reviewed.`
              : "All clear — no integrity flags."
        }
        description={
          awaitingReview > 0
            ? "High and medium-severity flags are at the top of the queue."
            : undefined
        }
        action={
          topFlag && awaitingReview > 0 ? (
            <Button
              size="sm"
              className="font-medium"
              onClick={() => handleAction(topFlag, "reviewed")}
              disabled={topFlag.status !== "flagged"}
            >
              {topFlag.status === "reviewed" ? "Reviewed" : "Review top flag"}
              <Check className="ml-1.5 h-3.5 w-3.5" strokeWidth={2} />
            </Button>
          ) : undefined
        }
      />

      {/* ---------- Evidence ---------- */}
      <EvidenceRow
        chips={[
          { label: "High", value: counts.high, delta: null, series: [0, 0, 0, 0, 0, 0, counts.high], comparison: "total" },
          { label: "Moderate", value: counts.medium, delta: null, series: [0, 0, 0, 0, 0, 0, counts.medium], comparison: "total" },
          { label: "Low", value: counts.low, delta: null, series: [0, 0, 0, 0, 0, 0, counts.low], comparison: "total" },
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
              {severityOptions.map((s) => (
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
              {typeOptions.map((t) => (
                <SelectItem key={t} value={t}>
                  {t.replace(/_/g, " ")}
                </SelectItem>
              ))}
            </SelectContent>
          </Select>
        </div>
      </div>

      {/* ---------- Bulk Action Bar ---------- */}
      {selected.size > 0 ? (
        <div className="sticky top-0 z-10 flex items-center gap-3 rounded-xl border border-primary/20 bg-primary/5 backdrop-blur-sm px-4 py-3">
          <Checkbox
            checked={allSelected ? true : someSelected ? "indeterminate" : false}
            onCheckedChange={toggleSelectAll}
            aria-label="Select all visible flags"
          />
          <span className="text-xs text-muted-foreground font-mono tabular-nums shrink-0">
            {selected.size} of {filtered.length} selected
          </span>
          <div className="flex-1" />
          <Button
            variant="ghost"
            size="sm"
            onClick={clearSelection}
            className="font-medium text-muted-foreground"
          >
            Clear
          </Button>
          <Button
            variant="outline"
            size="sm"
            onClick={() => onBulk("dismiss")}
            disabled={saving === "bulk"}
          >
            {saving === "bulk" ? "Saving…" : "Dismiss"}
          </Button>
          <Button
            size="sm"
            onClick={() => onBulk("reviewed")}
            disabled={saving === "bulk"}
          >
            {saving === "bulk" ? "Saving…" : "Mark Reviewed"}
          </Button>
        </div>
      ) : null}

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
        <div className="rounded-xl border border-dashed border-border/40 bg-card/30 backdrop-blur-sm p-8 text-center">
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
        title={openFlag ? openFlag.flag_type : "Flag detail"}
        subtitle={openFlag ? `${openFlag.student_name} · ${openFlag.exercise_title}` : ""}
      >
        {openFlag ? (
          <div className="space-y-6">
            <div className="flex items-center justify-between">
              <div className="space-y-1">
                <p className="text-xs uppercase tracking-wider text-muted-foreground">
                  Classification
                </p>
                <RiskBadge level={SEVERITY_RISK_LEVEL[openFlag.severity] || "low"} />
              </div>
              <div className="text-right">
                <p className="text-xs uppercase tracking-wider text-muted-foreground">
                  Flagged
                </p>
                <p className="text-sm font-mono tabular-nums">{timeAgo(openFlag.created_at)}</p>
              </div>
            </div>

            <div className="rounded-md border border-border bg-muted/40 p-4 space-y-1">
              <p className="text-xs uppercase tracking-wider text-muted-foreground">
                Student
              </p>
              <p className="text-sm font-medium">{openFlag.student_name}</p>
              <p className="text-xs text-muted-foreground">{openFlag.exercise_title}</p>
            </div>

            <div className="space-y-2">
              <p className="text-xs uppercase tracking-wider text-muted-foreground">
                Evidence
              </p>
              <pre className="rounded-md bg-muted/40 p-3 font-mono text-xs leading-relaxed overflow-x-auto whitespace-pre-wrap">
                {evidenceToString(openFlag.evidence)}
              </pre>
            </div>

            {openFlag.context_behaviors?.length > 0 && (
              <div className="space-y-2">
                <p className="text-xs uppercase tracking-wider text-muted-foreground">
                  Context behaviors
                </p>
                <ul className="list-disc list-inside text-sm text-muted-foreground space-y-1">
                  {openFlag.context_behaviors.map((b, i) => (
                    <li key={i}>{b}</li>
                  ))}
                </ul>
              </div>
            )}

            <div className="flex items-center justify-end gap-2 pt-2 border-t border-border">
              <Button
                size="sm"
                onClick={() => handleAction(openFlag, "reviewed")}
                disabled={saving === openFlag.id || openFlag.status !== "flagged"}
                className="font-medium"
              >
                {saving === openFlag.id ? (
                  <RefreshCw className="h-3.5 w-3.5 mr-1.5 animate-spin" />
                ) : openFlag.status === "reviewed" ? (
                  <Check className="h-3.5 w-3.5 mr-1.5" strokeWidth={2} />
                ) : (
                  <Check className="h-3.5 w-3.5 mr-1.5" strokeWidth={2} />
                )}
                {openFlag.status === "reviewed" ? "Reviewed" : "Mark Reviewed"}
              </Button>
            </div>
          </div>
        ) : null}
      </DetailDrawer>
    </div>
  );
}
