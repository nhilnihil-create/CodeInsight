import { cn } from "@/lib/utils";
import KPIChartCard from "./kpi-chart-card";

/**
 * EvidenceRow
 * Fluid responsive grid of KPIChartCards.
 * Uses gap-px rounded-2xl overflow-hidden pattern for the
 * unified micro-metrics strip aesthetic.
 */
export default function EvidenceRow({ chips = [] }) {
  return (
    <div
      className={cn(
        "grid gap-px rounded-2xl overflow-hidden border border-white/[0.06] bg-white/[0.06]",
        chips.length <= 2
          ? "grid-cols-1 sm:grid-cols-2"
          : chips.length === 3
            ? "grid-cols-3"
            : "grid-cols-2 lg:grid-cols-4"
      )}
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
          inverted={chip.inverted ?? false}
        />
      ))}
    </div>
  );
}
