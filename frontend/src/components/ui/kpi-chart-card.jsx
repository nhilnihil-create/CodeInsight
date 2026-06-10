import { ResponsiveContainer, LineChart, Line } from "recharts";

/**
 * KPIChartCard
 * Single KPI tile: label, value, delta chip, comparison caption, sparkline.
 *
 * Props
 *   - label       string
 *   - value       string | number
 *   - delta       number (positive = success tone, negative = destructive, zero = muted)
 *   - comparison  string (default "vs. last week")
 *   - series      number[] (length ≥ 2 to render sparkline; < 2 shows muted bar)
 *
 * Tokens only. Sparkline uses recharts ResponsiveContainer at h-12 w-full,
 * no axes, no tooltip.
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
          ? "bg-success/10 text-success"
          : delta < 0
            ? "bg-destructive/10 text-destructive"
            : "bg-muted text-muted-foreground"
        : delta < 0
          ? "bg-success/10 text-success"
          : delta > 0
            ? "bg-destructive/10 text-destructive"
            : "bg-muted text-muted-foreground";

  const arrow = delta > 0 ? "▲" : delta < 0 ? "▼" : "■";

  return (
    <div className="bg-card/50 border border-border/60 rounded-xl backdrop-blur-sm shadow-sm p-5 flex flex-col gap-3 transition-all duration-200 ease-out hover:bg-card/80 hover:scale-[1.01]">
      <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
        {label}
      </p>
      <div className="flex items-baseline gap-2">
        <p className="text-2xl font-semibold font-mono tabular-nums tracking-tight text-card-foreground">
          {value}
        </p>
        {deltaTone ? (
          <span
            className={`inline-flex items-center gap-1 px-1.5 py-0.5 rounded-md text-[11px] font-medium font-mono tabular-nums ${deltaTone}`}
            aria-label={
              delta > 0
                ? `Up ${delta} ${comparison}`
                : delta < 0
                  ? `Down ${Math.abs(delta)} ${comparison}`
                  : `No change ${comparison}`
            }
          >
            <span aria-hidden="true">{arrow}</span>
            {Math.abs(delta)}
          </span>
        ) : null}
      </div>
      <p className="text-xs text-muted-foreground">{comparison}</p>
      <div className="h-12 w-full">
        {hasSeries ? (
          <ResponsiveContainer width="100%" height="100%">
            <LineChart
              data={data}
              margin={{ top: 0, right: 0, bottom: 0, left: 0 }}
            >
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
        ) : (
          <div className="h-full w-full bg-muted/40 rounded" aria-hidden="true" />
        )}
      </div>
    </div>
  );
}
