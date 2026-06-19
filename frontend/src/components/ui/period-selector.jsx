/**
 * PeriodSelector
 * Segmented control for time-window selection (7d / 30d / 90d / etc.).
 *
 * Refactored for glassmorphic design:
 *   - Uses translucent background with glass border
 *   - Matches SegmentedPicker aesthetic
 *
 * Props
 *   - value     string  currently selected option
 *   - onChange  (next: string) => void
 *   - options   string[] (default ["7d", "30d", "90d"])
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
      className="inline-flex items-center gap-0 rounded-lg bg-white/[0.04] border border-white/[0.06] p-1 h-8"
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
                ? "relative z-10 px-3 text-[11px] font-medium rounded-md text-foreground bg-white/[0.08] border border-white/[0.08] shadow-sm transition-colors cursor-pointer"
                : "relative z-10 px-3 text-[11px] font-medium rounded-md text-muted-foreground hover:text-foreground/80 transition-colors cursor-pointer"
            }
          >
            {opt}
          </button>
        );
      })}
    </div>
  );
}
