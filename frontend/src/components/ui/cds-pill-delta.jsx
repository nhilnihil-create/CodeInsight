/**
 * CDSPillDelta
 * CDS score as a pill, with an optional delta arrow next to it.
 *
 * Props
 *   - value      number  (0–1)
 *   - delta      number  (optional; negative = improving, positive = worsening)
 *   - showDelta  boolean (render the delta arrow at all)
 *
 * Score     font-mono tabular-nums, 2 decimal places
 * Level     very_low ≤ 0.20 · low ≤ 0.40 · moderate ≤ 0.60 · elevated ≤ 0.80 · high > 0.80
 * Delta     text-xs ml-1
 *             negative → text-success (improving)
 *             positive → text-destructive (worsening)
 *             zero     → text-muted-foreground
 *
 * Tokens only.
 */
function levelFromValue(value) {
  if (typeof value !== "number" || Number.isNaN(value)) return "na";
  if (value <= 0.20) return "very_low";
  if (value <= 0.40) return "low";
  if (value <= 0.60) return "moderate";
  if (value <= 0.80) return "elevated";
  return "high";
}

const PILL_TONE = {
  very_low: "bg-cds-low/10 text-cds-low border border-cds-low/20",
  low: "bg-cds-low/10 text-cds-low border border-cds-low/20",
  moderate: "bg-cds-mod/10 text-cds-mod border border-cds-mod/20",
  elevated: "bg-cds-high/10 text-cds-high border border-cds-high/20",
  high: "bg-cds-high/10 text-cds-high border border-cds-high/20",
  na: "bg-cds-na/10 text-cds-na border border-cds-na/20",
};

export default function CDSPillDelta({ value, delta, showDelta = false }) {
  const level = levelFromValue(value);
  const score =
    typeof value === "number" && !Number.isNaN(value) ? value.toFixed(2) : "—";

  const deltaTone =
    delta == null
      ? null
      : delta < 0
        ? "text-success"
        : delta > 0
          ? "text-destructive"
          : "text-muted-foreground";

  const deltaArrow =
    delta == null ? null : delta < 0 ? "▼" : delta > 0 ? "▲" : "■";

  return (
    <span className="inline-flex items-center">
      <span
        className={`px-2 py-0.5 rounded-full text-[11px] font-semibold font-mono tabular-nums uppercase tracking-wide ${PILL_TONE[level]}`}
      >
        {score}
      </span>
      {showDelta && deltaTone && deltaArrow ? (
        <span
          className={`text-xs ml-1 font-mono tabular-nums ${deltaTone}`}
          aria-label={
            delta < 0
              ? `Improving by ${Math.abs(delta).toFixed(2)}`
              : delta > 0
                ? `Worsening by ${Math.abs(delta).toFixed(2)}`
                : "No change"
          }
        >
          <span aria-hidden="true">{deltaArrow}</span>
          {Math.abs(delta).toFixed(2)}
        </span>
      ) : null}
    </span>
  );
}
