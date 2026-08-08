import { Checkbox } from "./checkbox";
import { cn } from "@/lib/utils";

/**
 * DecisionList
 * Ranked actionable list of items. The canonical replacement for a flat table
 * on instructor/integrity/sections surfaces.
 *
 * Props
 *   - items          Array<{ id, title?, subtitle?, meta?, badge?, [arbitrary] }>
 *   - selectable     boolean — when true, renders a leading Checkbox per row
 *   - highlightIndex number, optional — row at this index gets the accent
 *   - onAction       (item) => void — fired on row click
 *   - renderRow      optional (item, { highlighted, selectable }) => ReactNode
 *                    When provided, takes over the row body. Container,
 *                    leading Checkbox, highlight, and click/keyboard handlers
 *                    are still managed by DecisionList. If `renderRow` is
 *                    supplied, items[].title/subtitle/meta/badge are ignored
 *                    (the caller controls row content).
 *   - maxHeight      Tailwind max-height class string, optional — when set,
 *                    the container becomes a scrollable region capped at that
 *                    height (overflow-y-auto + custom-scroll). When absent,
 *                    the container renders with plain overflow-hidden.
 *
 * Container  rounded-lg border border-border bg-card divide-y divide-border overflow-hidden
 *            (scrollable variant when `maxHeight` is set: overflow-y-auto
 *            overflow-x-hidden custom-scroll + the max-height token)
 * Row        flex items-center gap-3 px-4 h-16 hover:bg-muted/40 transition-colors cursor-pointer
 * Highlight  bg-primary/5 border-l-2 border-primary (when i === highlightIndex)
 * Title      text-sm font-medium
 * Subtitle   text-xs text-muted-foreground
 *
 * Tokens only.
 */
export default function DecisionList({
  items = [],
  selectable = false,
  highlightIndex,
  onAction,
  renderRow,
  maxHeight,
}) {
  if (!Array.isArray(items) || items.length === 0) {
    return null;
  }

  return (
    <ul
      className={cn(
        "rounded-xl border border-border/60 bg-card/50 backdrop-blur-sm divide-y divide-border/40",
        maxHeight
          ? "overflow-y-auto overflow-x-hidden custom-scroll " + maxHeight
          : "overflow-hidden",
      )}
      role="list"
      aria-label="Decision list"
    >
      {items.map((item, i) => {
        const highlighted = i === highlightIndex;
        const key = item.id ?? i;
        return (
          <li
            key={key}
            role="button"
            tabIndex={0}
            onClick={() => onAction?.(item)}
            onKeyDown={(e) => {
              if (e.key === "Enter" || e.key === " ") {
                e.preventDefault();
                onAction?.(item);
              }
            }}
            className={cn(
              "flex items-center gap-3 px-4 h-16 transition-all duration-200 ease-out cursor-pointer",
              "hover:bg-slate-900/80 hover:scale-[1.01]",
              "focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-ring focus-visible:ring-inset",
              highlighted && "bg-primary/5 border-l-2 border-primary",
            )}
          >
            {selectable ? (
              <span
                onClick={(e) => e.stopPropagation()}
                onKeyDown={(e) => e.stopPropagation()}
                className="shrink-0"
              >
                <Checkbox aria-label={`Select ${item.title ?? `item ${i + 1}`}`} />
              </span>
            ) : null}

            {renderRow ? (
              <div className="min-w-0 flex-1 flex items-center gap-3">
                {renderRow(item, { highlighted, selectable })}
              </div>
            ) : (
              <>
                <div className="min-w-0 flex-1">
                  <p className="text-sm font-medium text-foreground truncate">
                    {item.title}
                  </p>
                  {item.subtitle ? (
                    <p className="text-xs text-muted-foreground truncate">
                      {item.subtitle}
                    </p>
                  ) : null}
                </div>

                <div className="flex items-center gap-2 shrink-0">
                  {item.meta ? (
                    <span className="text-xs text-muted-foreground font-mono tabular-nums">
                      {item.meta}
                    </span>
                  ) : null}
                  {item.badge ? (
                    <span className="shrink-0">{item.badge}</span>
                  ) : null}
                </div>
              </>
            )}
          </li>
        );
      })}
    </ul>
  );
}
