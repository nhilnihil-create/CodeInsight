import { cn } from "@/lib/utils";

/**
 * ConceptMasteryBarSet
 * Horizontal bar chart of concept mastery values, rendered as a token-only
 * list. No chart library — just a styled `<ul>` of `<progress>`-like rows.
 *
 * Props
 *   - concepts  Array<{ id, name, value: number (0-100), level?: "low"|"moderate"|"high" }>
 *   - max       number (default 100)
 *
 * Each row: name (sm font-medium) | bar (h-2 rounded-full) | value (mono tabular-nums)
 */
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
        const fillTone =
          c.level === "low"
            ? "bg-destructive"
            : c.level === "high"
              ? "bg-success"
              : "bg-warning";
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
                className={cn("h-full rounded-full transition-all", fillTone)}
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
