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
/**
 * Coerce a value that may arrive as a Postgres NUMERIC string (e.g. "0.35")
 * or a JSON number into a real number. Returns NaN when there is genuinely
 * no data (null/undefined/empty/NaN), preserving the "—" fallback.
 */
function toNumber(value) {
  if (value === null || value === undefined || value === "") return NaN;
  if (typeof value === "number") return value;
  const n = Number(value);
  return Number.isNaN(n) ? NaN : n;
}

function levelFromValue(value) {
  const num = toNumber(value);
  if (Number.isNaN(num)) return "na";
  if (num <= 0.20) return "very_low";
  if (num <= 0.40) return "low";
  if (num <= 0.60) return "moderate";
  if (num <= 0.80) return "elevated";
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
  const num = toNumber(value);
  const score = !Number.isNaN(num) ? num.toFixed(2) : "—";
  const deltaNum = toNumber(delta);
  const deltaTone =
    Number.isNaN(deltaNum)
      ? null
      : deltaNum < 0
        ? "text-success"
        : deltaNum > 0
          ? "text-destructive"
          : "text-muted-foreground";

  const deltaArrow =
    Number.isNaN(deltaNum) ? null : deltaNum < 0 ? "▼" : deltaNum > 0 ? "▲" : "■";

  return (
    <span className="inline-flex items-center">
      <span
        className={`px-2 py-0.5 rounded-full text-[11px] font-semibold font-mono tabular-nums uppercase tracking-wide ${PILL_TONE[level]}`}
      >
        {score}
      </span>
      {showDelta && deltaTone && deltaArrow && !Number.isNaN(deltaNum) ? (
        <span
          className={`text-xs ml-1 font-mono tabular-nums ${deltaTone}`}
          aria-label={
            deltaNum < 0
              ? `Improving by ${Math.abs(deltaNum).toFixed(2)}`
              : deltaNum > 0
                ? `Worsening by ${Math.abs(deltaNum).toFixed(2)}`
                : "No change"
          }
        >
          <span aria-hidden="true">{deltaArrow}</span>
          {Math.abs(deltaNum).toFixed(2)}
        </span>
      ) : null}
    </span>
  );
}
