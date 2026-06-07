/**
 * PeriodSelector
 * Segmented control for time-window selection (7d / 30d / 90d / etc.).
 * Not a dropdown.
 *
 * Props
 *   - value     string  currently selected option
 *   - onChange  (next: string) => void
 *   - options   string[] (default ["7d", "30d", "90d"])
 *
 * Container  inline-flex rounded-md border border-border bg-muted p-0.5 gap-0.5
 * Option      px-3 py-1 text-sm rounded transition-colors cursor-pointer
 * Active      bg-card text-foreground shadow-sm font-medium
 * Inactive    text-muted-foreground hover:text-foreground
 *
 * Tokens only.
 */
export default function PeriodSelector({
  value,
  onChange,
  options = ["7d", "30d", "90d"],
}) {
  return (
    <div
      role="radiogroup"
      aria-label="Period"
      className="inline-flex rounded-md border border-border bg-muted p-0.5 gap-0.5"
    >
      {options.map((opt) => {
        const isActive = opt === value;
        return (
          <button
            key={opt}
            type="button"
            role="radio"
            aria-checked={isActive}
            onClick={() => onChange?.(opt)}
            className={
              isActive
                ? "px-3 py-1 text-sm rounded transition-colors cursor-pointer bg-card text-foreground shadow-sm font-medium"
                : "px-3 py-1 text-sm rounded transition-colors cursor-pointer text-muted-foreground hover:text-foreground"
            }
          >
            {opt}
          </button>
        );
      })}
    </div>
  );
}
