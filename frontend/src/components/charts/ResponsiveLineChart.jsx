import { useMemo } from 'react';
import {
  ResponsiveContainer,
  LineChart,
  Line,
  XAxis,
  YAxis,
  CartesianGrid,
  Tooltip,
  Legend,
} from 'recharts';
import { format, parseISO, isValid } from 'date-fns';
import { cn } from '@/lib/utils';

/**
 * ResponsiveLineChart — themed line chart primitive for CodeInsight.
 *
 * Designed to wrap recharts 3.8.1 with the design tokens from
 * src/index.css so callers don't have to re-pass colors per usage.
 *
 * Input shape: `data` is a flat array of points with the same field name
 * for the y-value across the whole chart (default "y"). For multi-series,
 * use the `series` prop instead.
 *
 * For the class-average CDS report, `data` will look like:
 *   [{ x: '2026-05-28', y: 0.42 }, { x: '2026-05-30', y: 0.39 }, ...]
 *
 * @param {Object} props
 * @param {Array<{x: string|number|Date, y: number}>} props.data
 * @param {string} [props.title]
 * @param {string} [props.subtitle]
 * @param {string} [props.xLabel]
 * @param {string} [props.yLabel]
 * @param {[number, number]} [props.yDomain=[0, 1]] - Y-axis domain (CDS is [0,1]).
 * @param {string} [props.yFmt] - Custom Y tick formatter, e.g. v => v.toFixed(2).
 * @param {string} [props.xFmt] - Custom X tick formatter, e.g. date string format.
 * @param {string} [props.color] - Line color, defaults to --color-primary.
 * @param {string} [props.className]
 * @param {string} [props.emptyMessage]
 */
export default function ResponsiveLineChart({
  data = [],
  title,
  subtitle,
  xLabel,
  yLabel,
  yDomain = [0, 1],
  yFmt = (v) => v.toFixed(2),
  xFmt,
  color = 'var(--color-primary, #85D2D0)',
  className,
  emptyMessage = 'No data available yet.',
}) {
  // Pre-process: parse ISO strings, drop invalid points, sort by x ascending.
  const normalized = useMemo(() => {
    if (!Array.isArray(data) || data.length === 0) return [];
    const out = data
      .map((p) => {
        let xVal = p.x;
        if (typeof p.x === 'string') {
          const parsed = parseISO(p.x);
          if (isValid(parsed)) xVal = parsed;
        }
        const yNum = typeof p.y === 'number' ? p.y : parseFloat(p.y);
        return { x: xVal, y: Number.isFinite(yNum) ? yNum : null };
      })
      .filter((p) => p.y !== null)
      .sort((a, b) => (a.x instanceof Date ? a.x - b.x : a.x - b.x));
    return out;
  }, [data]);

  // Empty state
  if (normalized.length === 0) {
    return (
      <div
        className={cn(
          'flex h-full min-h-[220px] flex-col items-center justify-center rounded-lg border border-dashed border-border bg-card/50 p-6 text-center',
          className
        )}
      >
        {title && <div className="mb-1 text-sm font-semibold text-foreground">{title}</div>}
        <div className="text-xs text-muted-foreground">{emptyMessage}</div>
      </div>
    );
  }

  const tickColor = '#6a85a8';
  const gridColor = '#1e304d';

  return (
    <div className={cn('flex h-full min-h-[260px] flex-col rounded-lg border border-border bg-card p-4', className)}>
      {(title || subtitle) && (
        <div className="mb-3">
          {title && <div className="text-sm font-semibold text-foreground">{title}</div>}
          {subtitle && <div className="text-[11px] text-muted-foreground">{subtitle}</div>}
        </div>
      )}

      <div className="flex-1">
        <ResponsiveContainer width="100%" height="100%" minHeight={220}>
          <LineChart
            data={normalized}
            margin={{ top: 8, right: 16, left: 0, bottom: 8 }}
          >
            <CartesianGrid stroke={gridColor} strokeDasharray="3 3" vertical={false} />
            <XAxis
              dataKey="x"
              stroke={tickColor}
              tick={{ fill: tickColor, fontSize: 11 }}
              tickFormatter={
                xFmt
                  ? xFmt
                  : (v) =>
                      v instanceof Date && isValid(v) ? format(v, 'MMM d') : String(v)
              }
              label={
                xLabel
                  ? { value: xLabel, position: 'insideBottom', offset: -2, fill: tickColor, fontSize: 11 }
                  : undefined
              }
              tickMargin={6}
            />
            <YAxis
              domain={yDomain}
              stroke={tickColor}
              tick={{ fill: tickColor, fontSize: 11 }}
              tickFormatter={yFmt}
              label={
                yLabel
                  ? {
                      value: yLabel,
                      angle: -90,
                      position: 'insideLeft',
                      offset: 10,
                      fill: tickColor,
                      fontSize: 11,
                    }
                  : undefined
              }
              width={48}
            />
            <Tooltip
              contentStyle={{
                background: '#131d30',
                border: '1px solid #1e304d',
                borderRadius: 8,
                fontSize: 12,
                color: '#dce8f5',
              }}
              labelStyle={{ color: '#dce8f5', fontWeight: 600, marginBottom: 4 }}
              itemStyle={{ color: '#dce8f5' }}
              formatter={(v) => [yFmt(v), yLabel || 'Value']}
              labelFormatter={(v) =>
                v instanceof Date && isValid(v) ? format(v, 'PP') : String(v)
              }
            />
            <Legend
              wrapperStyle={{ fontSize: 11, color: tickColor, paddingTop: 4 }}
              iconType="line"
            />
            <Line
              type="monotone"
              dataKey="y"
              name={yLabel || 'Value'}
              stroke={color}
              strokeWidth={2}
              dot={{ r: 3, fill: color, stroke: color }}
              activeDot={{ r: 5, fill: color, stroke: '#dce8f5', strokeWidth: 2 }}
              isAnimationActive={false}
              connectNulls
            />
          </LineChart>
        </ResponsiveContainer>
      </div>
    </div>
  );
}
