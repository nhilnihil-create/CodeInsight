import { useState } from "react";
import {
  ArrowUpDown,
  ArrowRight,
  Mail,
  MoreHorizontal,
  Flag,
} from "lucide-react";
import InsightHeader from "@/components/ui/insight-header";
import DetailDrawer from "@/components/ui/detail-drawer";
import CDSPillDelta from "@/components/ui/cds-pill-delta";
import RiskBadge from "@/components/ui/risk-badge";
import { Button } from "@/components/ui/button";
import {
  DropdownMenu,
  DropdownMenuContent,
  DropdownMenuItem,
  DropdownMenuTrigger,
} from "@/components/ui/dropdown-menu";
import { cn } from "@/lib/utils";

const ROSTER = [
  { id: 1, name: "A. Khan",   cds: 0.82, delta: 0.10, flags: 1, last: "2h",  level: "high" },
  { id: 2, name: "B. Reyes",  cds: 0.74, delta: 0.05, flags: 0, last: "1d",  level: "high" },
  { id: 3, name: "C. Park",   cds: 0.68, delta: 0.02, flags: 1, last: "3h",  level: "moderate" },
  { id: 4, name: "D. Lopez",  cds: 0.61, delta: -0.01, flags: 0, last: "5h", level: "moderate" },
  { id: 5, name: "E. Chen",   cds: 0.55, delta: 0.04, flags: 0, last: "1d",  level: "moderate" },
  { id: 6, name: "F. Adams",  cds: 0.48, delta: -0.03, flags: 0, last: "2d", level: "moderate" },
  { id: 7, name: "G. Park",   cds: 0.41, delta: -0.05, flags: 0, last: "1d",  level: "low" },
  { id: 8, name: "H. Singh",  cds: 0.33, delta: -0.08, flags: 0, last: "4h",  level: "low" },
  { id: 9, name: "I. Diaz",   cds: 0.27, delta: -0.06, flags: 0, last: "1d",  level: "low" },
  { id: 10, name: "J. Ortiz", cds: 0.18, delta: -0.04, flags: 0, last: "2d", level: "low" },
];

const SORTS = [
  { id: "cds",   label: "CDS" },
  { id: "delta", label: "Δ" },
  { id: "flags", label: "Flags" },
  { id: "name",  label: "Name" },
];

export default function RosterTab() {
  const [sort, setSort] = useState("cds");
  const [selected, setSelected] = useState(null);

  const rows = [...ROSTER].sort((a, b) => {
    if (sort === "name") return a.name.localeCompare(b.name);
    if (sort === "delta") return b.delta - a.delta;
    if (sort === "flags") return b.flags - a.flags;
    return b.cds - a.cds;
  });

  return (
    <div className="space-y-6">
      <InsightHeader
        insight="Ranked by CDS — highest risk first."
      />

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
                {r.last} ago
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
                  <DropdownMenuItem>
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
        subtitle={selected ? `Student · Section 04` : undefined}
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
                  {selected.last} ago
                </p>
              </div>
            </div>

            <div className="space-y-2">
              <h3 className="text-sm font-semibold">Quick actions</h3>
              <div className="flex flex-col gap-2">
                <Button variant="outline" size="sm" className="justify-start">
                  <Mail className="h-3.5 w-3.5 mr-2" strokeWidth={1.5} />
                  Send message
                </Button>
                <Button variant="outline" size="sm" className="justify-start">
                  <ArrowRight className="h-3.5 w-3.5 mr-2" strokeWidth={1.5} />
                  Schedule check-in
                </Button>
              </div>
            </div>
          </div>
        ) : null}
      </DetailDrawer>
    </div>
  );
}
