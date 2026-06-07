import KPIChartCard from "./kpi-chart-card";

/**
 * EvidenceRow
 * Responsive grid of KPIChartCards driven by a `chips` array.
 *
 * Props
 *   - chips: Array<{ label: string, value: string|number, delta?: number, series?: number[] }>
 *
 * Layout
 *   Mobile:  grid-cols-2
 *   Desktop: grid-cols-4
 *   gap-4
 *
 * Tokens only.
 */
export default function EvidenceRow({ chips = [] }) {
  return (
    <div
      className="grid grid-cols-2 lg:grid-cols-4 gap-4"
      role="group"
      aria-label="Supporting evidence"
    >
      {chips.map((chip) => (
        <KPIChartCard
          key={chip.label}
          label={chip.label}
          value={chip.value}
          delta={chip.delta}
          series={chip.series}
          comparison={chip.comparison}
        />
      ))}
    </div>
  );
}
