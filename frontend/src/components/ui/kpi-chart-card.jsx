import { ResponsiveContainer, LineChart, Line } from "recharts";
import { cn } from "@/lib/utils";
import { motion } from "framer-motion";

/**
 * KPIChartCard
 * Single KPI tile: label, value, delta chip, sparkline.
 *
 * Unified glassmorphic micro-metric style:
 *   - Floating typography with high-contrast values
 *   - 3-tier color accent based on delta
 *   - Ambient sparkline stroke
 */
export default function KPIChartCard({
  label,
  value,
  delta,
  comparison = "vs. last week",
  series = [],
  inverted = false,
}) {
  const hasSeries = Array.isArray(series) && series.length >= 2;
  const data = hasSeries ? series.map((v) => ({ v })) : [];

  const deltaTone =
    delta == null
      ? null
      : !inverted
        ? delta > 0
          ? "text-emerald-400"
          : delta < 0
            ? "text-rose-400"
            : "text-muted-foreground/60"
        : delta < 0
          ? "text-emerald-400"
          : delta > 0
            ? "text-rose-400"
            : "text-muted-foreground/60";

  const arrow = delta > 0 ? "\u25B2" : delta < 0 ? "\u25BC" : "\u25CF";

  return (
    <motion.div
      whileHover={{ scale: 1.015, borderColor: "rgba(255,255,255,0.12)" }}
      transition={{ type: "spring", stiffness: 400, damping: 25 }}
      className={cn(
        "relative rounded-xl p-5 flex flex-col gap-2",
        "bg-white/[0.02] border border-white/[0.05]",
        "backdrop-blur-sm noise-overlay",
        "transition-colors duration-200 hover:bg-white/[0.04]"
      )}
    >
      {/* Label */}
      <span className="metric-label">{label}</span>

      {/* Value + Delta */}
      <div className="relative z-10 flex items-baseline gap-2">
        <span className="text-3xl font-extrabold tracking-tight font-mono tabular-nums text-foreground">
          {value}
        </span>
        {deltaTone ? (
          <span
            className={cn(
              "inline-flex items-center gap-0.5 font-mono text-[10px] font-medium tabular-nums",
              deltaTone
            )}
            aria-label={
              delta > 0
                ? `Up ${delta} ${comparison}`
                : delta < 0
                  ? `Down ${Math.abs(delta)} ${comparison}`
                  : `No change ${comparison}`
            }
          >
            <span aria-hidden="true" className="text-[8px]">{arrow}</span>
            {Math.abs(delta)}
          </span>
        ) : null}
      </div>

      {/* Comparison */}
      {comparison && (
        <p className="relative z-10 text-[10px] text-muted-foreground/50">{comparison}</p>
      )}

      {/* Sparkline */}
      <div className="relative z-10 h-8 w-full mt-1">
        {hasSeries ? (
          <ResponsiveContainer width="100%" height="100%">
            <LineChart data={data} margin={{ top: 0, right: 0, bottom: 0, left: 0 }}>
              <Line
                type="monotone"
                dataKey="v"
                stroke="rgba(52, 211, 153, 0.5)"
                strokeWidth={1.5}
                dot={false}
                isAnimationActive={false}
              />
            </LineChart>
          </ResponsiveContainer>
        ) : (
          <div className="h-full w-full bg-white/[0.03] rounded" aria-hidden="true" />
        )}
      </div>
    </motion.div>
  );
}
