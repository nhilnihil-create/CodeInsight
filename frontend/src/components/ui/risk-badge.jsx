/**
 * RiskBadge
 * Pill badge driven entirely by CDS domain tokens. Canonical replacement
 * for arbitrary-hex CDS indicators across the app.
 *
 * Props
 *   - level  "low" | "moderate" | "high" | "na"
 *
 * Tokens only.
 */
const VARIANTS = {
  low: "bg-cds-low/10 text-cds-low border border-cds-low/20",
  moderate: "bg-cds-mod/10 text-cds-mod border border-cds-mod/20",
  high: "bg-cds-high/10 text-cds-high border border-cds-high/20",
  na: "bg-cds-na/10 text-cds-na border border-cds-na/20",
};

const LABELS = {
  low: "Low",
  moderate: "Moderate",
  high: "High",
  na: "N/A",
};

export default function RiskBadge({ level = "na" }) {
  const variant = VARIANTS[level] || VARIANTS.na;
  const label = LABELS[level] || LABELS.na;

  return (
    <span
      className={`px-2 py-0.5 rounded-full text-[11px] font-semibold uppercase tracking-wide ${variant}`}
    >
      {label}
    </span>
  );
}
