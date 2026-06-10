import { useState, useMemo } from "react";
import { useQuery } from "@tanstack/react-query";
import {
  ArrowRight,
  Mail,
  MoreHorizontal,
  Flag,
  AlertTriangle,
  RefreshCw,
} from "lucide-react";
import { toast } from "sonner";
import InsightHeader from "@/components/ui/insight-header";
import DetailDrawer from "@/components/ui/detail-drawer";
import CDSPillDelta from "@/components/ui/cds-pill-delta";
import RiskBadge from "@/components/ui/risk-badge";
import { Button } from "@/components/ui/button";
import { Textarea } from "@/components/ui/textarea";
import {
  Dialog,
  DialogContent,
  DialogHeader,
  DialogTitle,
  DialogDescription,
  DialogFooter,
} from "@/components/ui/dialog";
import {
  DropdownMenu,
  DropdownMenuContent,
  DropdownMenuItem,
  DropdownMenuTrigger,
} from "@/components/ui/dropdown-menu";
import { cn } from "@/lib/utils";
import api from "@/services/api";

const LEVEL_THRESHOLDS = { low: 0.33, moderate: 0.66 };
function computeLevel(cds) {
  if (cds == null) return "low";
  if (cds <= LEVEL_THRESHOLDS.low) return "low";
  if (cds <= LEVEL_THRESHOLDS.moderate) return "moderate";
  return "high";
}

function timeAgo(dateStr) {
  if (!dateStr) return "—";
  const ms = Date.now() - new Date(dateStr).getTime();
  const mins = Math.floor(ms / 60000);
  if (mins < 1) return "just now";
  if (mins < 60) return `${mins}m`;
  const hours = Math.floor(mins / 60);
  if (hours < 24) return `${hours}h`;
  const days = Math.floor(hours / 24);
  return `${days}d`;
}

const SORTS = [
  { id: "cds",   label: "CDS" },
  { id: "delta", label: "Δ" },
  { id: "flags", label: "Flags" },
  { id: "name",  label: "Name" },
];

export default function RosterTab({ sectionId, sectionName }) {
  const [sort, setSort] = useState("cds");
  const [selected, setSelected] = useState(null);
  const [msgOpen, setMsgOpen] = useState(false);
  const [msgBody, setMsgBody] = useState("");
  const [msgSending, setMsgSending] = useState(false);
  const [msgTarget, setMsgTarget] = useState(null); // null = all, or { id, name }

  const sendMessage = async () => {
    if (!msgBody.trim() || !sectionId) return;
    setMsgSending(true);
    try {
      const payload = { message: msgBody.trim() };
      if (msgTarget) payload.student_id = msgTarget.id;
      await api.post(`/api/sections/${sectionId}/messages`, payload);
      toast.success(
        msgTarget
          ? `Message sent to ${msgTarget.name}`
          : `Message sent to all students in ${sectionName}`,
      );
      setMsgOpen(false);
      setMsgBody("");
      setMsgTarget(null);
    } catch {
      toast.error("Failed to send message");
    } finally {
      setMsgSending(false);
    }
  };

  const { data: students = [], isLoading, isError, refetch } = useQuery({
    queryKey: ["section-students", sectionId],
    queryFn: async () => {
      const { data } = await api.get(`/api/sections/${sectionId}/students-with-scores`);
      return data.map((s) => ({
        id: s.id,
        name: s.name,
        cds: s.latest_cds ?? 0,
        delta: 0,
        flags: s.integrity_flag_count ?? 0,
        last: timeAgo(null),
        level: computeLevel(s.latest_cds),
        email: s.email,
      }));
    },
    enabled: !!sectionId,
  });

  const flaggedCount = useMemo(() => students.filter((s) => s.flags > 0).length, [students]);

  const rows = useMemo(() => {
    return [...students].sort((a, b) => {
      if (sort === "name") return a.name.localeCompare(b.name);
      if (sort === "delta") return b.delta - a.delta;
      if (sort === "flags") return b.flags - a.flags;
      return b.cds - a.cds;
    });
  }, [students, sort]);

  if (isLoading) {
    return (
      <div className="rounded-lg border border-border bg-card/50 py-8 px-6 text-center">
        <p className="text-sm font-semibold text-foreground">Loading roster…</p>
      </div>
    );
  }

  if (isError) {
    return (
      <div className="flex items-center gap-3 rounded-lg border border-destructive/30 bg-destructive/5 px-4 py-3">
        <AlertTriangle className="h-4 w-4 text-destructive shrink-0" />
        <p className="text-sm text-destructive flex-1">Failed to load roster.</p>
        <Button size="sm" variant="outline" className="border-destructive/30 text-destructive" onClick={() => refetch()}>
          <RefreshCw className="h-3.5 w-3.5 mr-1.5" />
          Retry
        </Button>
      </div>
    );
  }

  return (
    <div className="space-y-6">
      <InsightHeader
        insight={`Ranked by CDS — ${flaggedCount} student${flaggedCount === 1 ? "" : "s"} flagged.`}
      />

      <div className="flex items-center gap-2">
        {SORTS.map((s) => (
          <button
            key={s.id}
            type="button"
            onClick={() => setSort(s.id)}
            className={cn(
              "px-3 py-1 text-sm rounded-md transition-colors",
              sort === s.id
                ? "bg-muted text-foreground font-medium"
                : "text-muted-foreground hover:text-foreground",
            )}
          >
            {s.label}
          </button>
        ))}
      </div>

      <div className="rounded-lg border border-border bg-card overflow-hidden">
        {/* Header row */}
        <div className="grid grid-cols-[1fr_5.5rem_4rem_4rem_5.5rem_2.5rem] items-center gap-3 px-4 h-9 border-b border-border bg-muted/40">
          <span className="text-xs font-medium text-muted-foreground">Student</span>
          <span className="text-xs font-medium text-muted-foreground text-right">CDS</span>
          <span className="text-xs font-medium text-muted-foreground text-right">Δ</span>
          <span className="text-xs font-medium text-muted-foreground text-right">Flags</span>
          <span className="text-xs font-medium text-muted-foreground text-right">Last Active</span>
          <span className="sr-only">Actions</span>
        </div>

        {/* Body */}
        <ul className="divide-y divide-border">
          {rows.map((r) => (
            <li
              key={r.id}
              className="grid grid-cols-[1fr_5.5rem_4rem_4rem_5.5rem_2.5rem] items-center gap-3 px-4 h-14 hover:bg-muted/40 transition-colors cursor-pointer group"
              onClick={() => setSelected(r)}
            >
              <div className="flex items-center gap-3 min-w-0">
                <div className="h-7 w-7 shrink-0 rounded-full bg-muted text-xs font-semibold flex items-center justify-center text-muted-foreground">
                  {r.name.split(" ").map((p) => p[0]).join("").slice(0, 2)}
                </div>
                <span className="text-sm font-medium text-foreground truncate">
                  {r.name}
                </span>
                <RiskBadge level={r.level} />
              </div>
              <div className="text-right">
                <CDSPillDelta value={r.cds} showDelta={false} />
              </div>
              <span
                className={cn(
                  "text-xs font-mono tabular-nums text-right",
                  r.delta > 0 ? "text-destructive" : r.delta < 0 ? "text-success" : "text-muted-foreground",
                )}
              >
                {r.delta > 0 ? "+" : ""}
                {r.delta.toFixed(2)}
              </span>
              <span
                className={cn(
                  "inline-flex items-center justify-end gap-1 text-xs font-mono tabular-nums",
                  r.flags > 0 ? "text-destructive" : "text-muted-foreground",
                )}
              >
                {r.flags > 0 ? <Flag className="h-3 w-3" strokeWidth={1.5} /> : null}
                {r.flags}
              </span>
              <span className="text-xs font-mono tabular-nums text-muted-foreground text-right">
                {r.last}
              </span>
              <DropdownMenu>
                <DropdownMenuTrigger asChild>
                  <button
                    type="button"
                    onClick={(e) => e.stopPropagation()}
                    className="h-7 w-7 inline-flex items-center justify-center rounded-md text-muted-foreground opacity-0 group-hover:opacity-100 hover:bg-muted hover:text-foreground focus-visible:opacity-100 focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-ring"
                    aria-label={`Actions for ${r.name}`}
                  >
                    <MoreHorizontal className="h-3.5 w-3.5" strokeWidth={1.5} />
                  </button>
                </DropdownMenuTrigger>
                <DropdownMenuContent align="end">
                  <DropdownMenuItem onSelect={() => setSelected(r)}>
                    View detail
                  </DropdownMenuItem>
                  <DropdownMenuItem
                    onSelect={() => {
                      setMsgTarget({ id: r.id, name: r.name });
                      setMsgBody("");
                      setMsgOpen(true);
                    }}
                  >
                    <Mail className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                    Message
                  </DropdownMenuItem>
                </DropdownMenuContent>
              </DropdownMenu>
            </li>
          ))}
        </ul>
      </div>

      <DetailDrawer
        open={selected != null}
        onClose={() => setSelected(null)}
        title={selected?.name ?? ""}
        subtitle={selected ? `Student · ${sectionName}` : undefined}
      >
        {selected ? (
          <div className="space-y-6">
            <div className="grid grid-cols-2 gap-3">
              <div className="rounded-md bg-muted/40 border border-border p-3">
                <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
                  CDS
                </p>
                <div className="mt-1">
                  <CDSPillDelta
                    value={selected.cds}
                    delta={selected.delta}
                    showDelta
                  />
                </div>
              </div>
              <div className="rounded-md bg-muted/40 border border-border p-3">
                <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
                  Risk
                </p>
                <div className="mt-1">
                  <RiskBadge level={selected.level} />
                </div>
              </div>
              <div className="rounded-md bg-muted/40 border border-border p-3">
                <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
                  Flags
                </p>
                <p className="text-2xl font-semibold font-mono tabular-nums tracking-tight leading-[1.1] mt-1">
                  {selected.flags}
                </p>
              </div>
              <div className="rounded-md bg-muted/40 border border-border p-3">
                <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
                  Last active
                </p>
                <p className="text-sm font-medium text-foreground mt-1">
                  {selected.last}
                </p>
              </div>
            </div>

            <div className="space-y-2">
              <h3 className="text-sm font-semibold">Quick actions</h3>
              <div className="flex flex-col gap-2">
                <Button
                  variant="outline"
                  size="sm"
                  className="justify-start"
                  onClick={() => {
                    setMsgTarget({ id: selected.id, name: selected.name });
                    setMsgBody("");
                    setMsgOpen(true);
                  }}
                >
                  <Mail className="h-3.5 w-3.5 mr-2" strokeWidth={1.5} />
                  Send message
                </Button>
                <Button
                  variant="outline"
                  size="sm"
                  className="justify-start"
                  onClick={() => toast.info("Check-in scheduling coming soon")}
                >
                  <ArrowRight className="h-3.5 w-3.5 mr-2" strokeWidth={1.5} />
                  Schedule check-in
                </Button>
              </div>
            </div>
          </div>
        ) : null}
      </DetailDrawer>

      {/* ---------- Message Dialog ---------- */}
      <Dialog open={msgOpen} onOpenChange={(open) => { if (!open) { setMsgOpen(false); setMsgBody(""); setMsgTarget(null); } }}>
        <DialogContent>
          <DialogHeader>
            <DialogTitle>
              {msgTarget ? `Message ${msgTarget.name}` : `Message All Students`}
            </DialogTitle>
            <DialogDescription>
              {msgTarget
                ? `Send an in-app notification to ${msgTarget.name}.`
                : `Send an in-app notification to all students in ${sectionName}.`}
            </DialogDescription>
          </DialogHeader>
          <Textarea
            value={msgBody}
            onChange={(e) => setMsgBody(e.target.value)}
            placeholder="Write a message…"
            className="min-h-[120px]"
            autoFocus
          />
          <DialogFooter>
            <Button variant="ghost" onClick={() => { setMsgOpen(false); setMsgBody(""); setMsgTarget(null); }} disabled={msgSending}>
              Cancel
            </Button>
            <Button onClick={sendMessage} disabled={msgSending || !msgBody.trim()}>
              {msgSending ? "Sending…" : msgTarget ? `Send to ${msgTarget.name}` : "Send to All"}
            </Button>
          </DialogFooter>
        </DialogContent>
      </Dialog>
    </div>
  );
}
