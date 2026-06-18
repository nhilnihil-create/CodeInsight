import { ResponsiveContainer, LineChart, Line } from "recharts";
import { cn } from "@/lib/utils";
import { motion } from "framer-motion";

/**
 * MetricHub
 * Minimalist high-contrast metric display. Replaces blocky KPI text cards
 * with sleek typography: bold neon numbers + tiny low-saturation labels.
 *
 * Props:
 *   - label       string
 *   - value       string | number
 *   - delta       number | null — positive = up, negative = down
 *   - inverted    boolean — flip delta color logic
 *   - series      number[] — sparkline data (min 2 points)
 *   - accent      string | null — optional accent color class
 *   - size        "sm" | "md" | "lg"
 *   - className   string
 */
export default function MetricHub({
  label,
  value,
  delta,
  inverted = false,
  series = [],
  accent,
  size = "md",
  className,
}) {
  const hasSeries = Array.isArray(series) && series.length >= 2;
  const data = hasSeries ? series.map((v) => ({ v })) : [];

  const deltaColor =
    delta == null
      ? null
      : !inverted
        ? delta > 0
          ? "text-success"
          : delta < 0
            ? "text-destructive"
            : "text-muted-foreground"
        : delta < 0
          ? "text-success"
          : delta > 0
            ? "text-destructive"
            : "text-muted-foreground";

  const arrow = delta > 0 ? "\u25B2" : delta < 0 ? "\u25BC" : "\u25CF";

  const sizeClasses = {
    sm: { value: "text-xl", label: "text-[9px]", sparkline: "h-6" },
    md: { value: "text-2xl", label: "text-[10px]", sparkline: "h-8" },
    lg: { value: "text-3xl", label: "text-[11px]", sparkline: "h-10" },
  };

  const s = sizeClasses[size] || sizeClasses.md;

  return (
    <motion.div
      whileHover={{ scale: 1.015, borderColor: "rgba(255,255,255,0.12)" }}
      transition={{ type: "spring", stiffness: 400, damping: 25 }}
      className={cn(
        "group relative flex flex-col gap-1 p-4 rounded-xl",
        "bg-white/[0.03] border border-white/[0.06]",
        "backdrop-blur-sm transition-colors duration-200",
        "hover:bg-white/[0.05]",
        className
      )}
    >
      {/* Label */}
      <span className="metric-label">{label}</span>

      {/* Value + Delta row */}
      <div className="flex items-baseline gap-2">
        <span className={cn("metric-value", s.value, accent)}>
          {value}
        </span>
        {delta != null && (
          <span
            className={cn(
              "inline-flex items-center gap-0.5 font-mono text-[10px] font-medium tabular-nums",
              deltaColor
            )}
          >
            <span aria-hidden="true" className="text-[8px]">{arrow}</span>
            {Math.abs(delta)}
          </span>
        )}
      </div>

      {/* Sparkline — only when we have data */}
      {hasSeries && (
        <div className={cn("w-full mt-1", s.sparkline)}>
          <ResponsiveContainer width="100%" height="100%">
            <LineChart data={data} margin={{ top: 0, right: 0, bottom: 0, left: 0 }}>
              <Line
                type="monotone"
                dataKey="v"
                stroke="hsl(var(--primary))"
                strokeWidth={1.5}
                dot={false}
                isAnimationActive={false}
              />
            </LineChart>
          </ResponsiveContainer>
        </div>
      )}
    </motion.div>
  );
}
