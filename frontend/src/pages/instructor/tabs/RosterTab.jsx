import { useState, useMemo } from "react";
import { useNavigate } from "react-router-dom";
import { useQuery } from "@tanstack/react-query";
import {
  MoreHorizontal,
  Flag,
  AlertTriangle,
  RefreshCw,
  ExternalLink,
} from "lucide-react";
import InsightHeader from "@/components/ui/insight-header";
import CDSPillDelta from "@/components/ui/cds-pill-delta";
import { tierForCds, TIER_META } from "@/components/ui/mastery-bar";
import { Button } from "@/components/ui/button";
import {
  DropdownMenu,
  DropdownMenuContent,
  DropdownMenuItem,
  DropdownMenuTrigger,
} from "@/components/ui/dropdown-menu";
import { cn } from "@/lib/utils";
import api from "@/services/api";

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
  { id: "flags", label: "Flags" },
  { id: "name",  label: "Name" },
];

export default function RosterTab({ sectionId, sectionName }) {
  const navigate = useNavigate();
  const [sort, setSort] = useState("cds");

  const { data: students = [], isLoading, isError, refetch } = useQuery({
    queryKey: ["section-students", sectionId],
    queryFn: async () => {
      const { data } = await api.get(`/api/sections/${sectionId}/students-with-scores`);
      return data.map((s) => {
        const cds = parseFloat(s.avg_cds) || 0;
        return {
          id: s.id,
          name: s.name,
          cds,
          flags: s.integrity_flag_count ?? 0,
          last: timeAgo(s.last_active),
          level: tierForCds(cds),
          email: s.email,
        };
      });
    },
    enabled: !!sectionId,
  });

  const flaggedCount = useMemo(() => students.filter((s) => s.flags > 0).length, [students]);

  const rows = useMemo(() => {
    return [...students].sort((a, b) => {
      if (sort === "name") return a.name.localeCompare(b.name);
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

      <div className="flex flex-wrap items-center gap-2">
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

      <div className="rounded-lg border border-border bg-card overflow-x-auto">
        {/* Header row */}
        <div className="hidden sm:grid grid-cols-[1fr_5.5rem_4rem_5.5rem_2.5rem] items-center gap-3 px-4 h-9 border-b border-border bg-muted/40">
          <span className="text-xs font-medium text-muted-foreground">Student</span>
          <span className="text-xs font-medium text-muted-foreground text-right">CDS</span>
          <span className="text-xs font-medium text-muted-foreground text-right">Flags</span>
          <span className="text-xs font-medium text-muted-foreground text-right">Last Active</span>
          <span className="sr-only">Actions</span>
        </div>

        {/* Body */}
        <ul className="divide-y divide-border">
          {rows.map((r) => (
            <li
              key={r.id}
              className="grid grid-cols-1 sm:grid-cols-[1fr_5.5rem_4rem_5.5rem_2.5rem] items-start sm:items-center gap-1 sm:gap-3 px-4 py-3 sm:py-0 sm:h-14 hover:bg-muted/40 transition-colors cursor-pointer group"
              onClick={() => navigate(`/instructor/students/${r.id}?section=${sectionId}`)}
            >
              {/* Mobile card line 1: avatar + name + tier + actions */}
              <div className="flex items-center gap-3 min-w-0">
                <div className="h-7 w-7 shrink-0 rounded-full bg-muted text-xs font-semibold flex items-center justify-center text-muted-foreground">
                  {r.name.split(" ").map((p) => p[0]).join("").slice(0, 2)}
                </div>
                <span className="text-sm font-medium text-foreground truncate flex-1 min-w-0">
                  {r.name}
                </span>
                <span
                  className={`inline-flex items-center gap-1.5 rounded-full px-2.5 py-0.5 text-[11px] font-semibold uppercase tracking-wide ${TIER_META[r.level].text}`}
                  aria-label={`Mastery level: ${TIER_META[r.level].label}`}
                >
                  <span className={`h-1.5 w-1.5 rounded-full ${TIER_META[r.level].dot}`} aria-hidden="true" />
                  {TIER_META[r.level].label}
                </span>
                <DropdownMenu>
                  <DropdownMenuTrigger asChild>
                    <button
                      type="button"
                      onClick={(e) => e.stopPropagation()}
                      className="h-7 w-7 inline-flex items-center justify-center rounded-md text-muted-foreground sm:opacity-0 sm:group-hover:opacity-100 hover:bg-muted hover:text-foreground focus-visible:opacity-100 focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-ring"
                      aria-label={`Actions for ${r.name}`}
                    >
                      <MoreHorizontal className="h-3.5 w-3.5" strokeWidth={1.5} />
                    </button>
                  </DropdownMenuTrigger>
                  <DropdownMenuContent align="end">
                    <DropdownMenuItem onSelect={() => navigate(`/instructor/students/${r.id}?section=${sectionId}`)}>
                      <ExternalLink className="h-3.5 w-3.5 mr-2" strokeWidth={1.5} />
                      Open profile
                    </DropdownMenuItem>
                  </DropdownMenuContent>
                </DropdownMenu>
              </div>
              {/* Mobile card line 2: CDS + flags + last active as chips */}
              <div className="flex items-center gap-3 pl-10 sm:pl-0 sm:contents">
                <div className="sm:text-right">
                  <CDSPillDelta value={r.cds} showDelta={false} />
                </div>
                <span
                  className={cn(
                    "inline-flex items-center gap-1 text-xs font-mono tabular-nums",
                    r.flags > 0 ? "text-destructive" : "text-muted-foreground",
                  )}
                >
                  {r.flags > 0 ? <Flag className="h-3 w-3" strokeWidth={1.5} /> : null}
                  {r.flags} flag{r.flags !== 1 ? "s" : ""}
                </span>
                <span className="text-xs font-mono tabular-nums text-muted-foreground">
                  {r.last}
                </span>
              </div>
            </li>
          ))}
        </ul>
      </div>


    </div>
  );
}
