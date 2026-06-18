import { cn } from "@/lib/utils";
import { tierForCds } from "@/components/ui/mastery-bar";

/**
 * ConceptMasteryBarSet
 * Horizontal bar chart of concept mastery values, rendered as a token-only
 * list. No chart library — just a styled `<ul>` of `<progress>`-like rows.
 *
 * Uses the shared 5-tier system from mastery-bar for consistent coloring.
 *
 * Props
 *   - concepts  Array<{ id, name, value: number (0-100), cds?: number (0-1) }>
 *   - max       number (default 100)
 *
 * Each row: name (sm font-medium) | bar (h-2 rounded-full) | value (mono tabular-nums)
 */
const TIER_BAR_CLASS = {
  excellent:     "tier-excellent-bar",
  strong:        "tier-strong-bar",
  developing:    "tier-developing-bar",
  needs_support: "tier-needs-support-bar",
  critical:      "tier-critical-bar",
};

export default function ConceptMasteryBarSet({ concepts = [], max = 100 }) {
  if (!Array.isArray(concepts) || concepts.length === 0) {
    return (
      <p className="text-sm text-muted-foreground">No concept data yet.</p>
    );
  }

  return (
    <ul className="space-y-3">
      {concepts.map((c) => {
        const pct = Math.max(0, Math.min(max, c.value));
        const cds = c.cds != null ? c.cds : 1 - pct / 100;
        const tier = tierForCds(cds);
        const fillClass = TIER_BAR_CLASS[tier] || TIER_BAR_CLASS.strong;
        return (
          <li
            key={c.id ?? c.name}
            className="grid grid-cols-[10rem_1fr_3rem] items-center gap-3 min-w-0"
          >
            <span className="text-sm font-medium text-foreground truncate">
              {c.name}
            </span>
            <div className="h-2 rounded-full bg-muted overflow-hidden min-w-0">
              <div
                className={cn("h-full rounded-full transition-all", fillClass)}
                style={{ width: `${pct}%` }}
                aria-hidden="true"
              />
            </div>
            <span
              className="text-xs font-mono tabular-nums text-muted-foreground text-right"
              style={{ fontFeatureSettings: '"tnum"' }}
            >
              {Math.round(pct)}
            </span>
          </li>
        );
      })}
    </ul>
  );
}
