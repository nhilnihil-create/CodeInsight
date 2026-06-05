/**
 * ClassWideLongitudinalChart
 *
 * Renders the CLASS-WIDE longitudinal view: a single line graph whose
 * X-axis is chronological CDS samples and Y-axis is class-average CDS
 * (0..1), with a `<select>` that filters the line down to one concept
 * (or "All concepts" for the cross-section trend).
 *
 * This is intentionally distinct from LongitudinalProgressChart (which is
 * per-student/per-exercise and used in the misconception modal). On the
 * Instructor Dashboard, the line graph that summarises how the *class*
 * is doing over time lives here.
 *
 * Data source: analyticsService.getSectionLongitudinal(sectionId)
 * → { sectionId, students: [{ studentId, studentName, progression: [...] }] }
 *
 * Aggregation: for each (concept, timestamp) we average CDS across all
 * students who have a sample for that concept at-or-before that timestamp.
 * To keep the line stable across the whole class we sort all samples
 * chronologically and down-sample to unique weeks (ISO week of computed_at).
 */

import { useEffect, useMemo, useState } from 'react';
import {
  LineChart,
  Line,
  XAxis,
  YAxis,
  CartesianGrid,
  Tooltip,
  ReferenceLine,
  ResponsiveContainer,
  Area,
  ComposedChart,
} from 'recharts';
import {
  Select,
  SelectContent,
  SelectItem,
  SelectTrigger,
  SelectValue,
} from '@/components/ui/select';
import analyticsService from '@/api/analyticsService';

const CONCEPT_COLORS = {
  Datatypes: '#85D2D0',
  Variables: '#a99dd4',
  Conditionals: '#fbbf24',
  Loops: '#60a5fa',
  Functions: '#34d399',
  Arrays: '#f472b6',
  OOP: '#fb7185',
};

const ALL_CONCEPTS = '__all__';

const formatDate = (iso) => {
  const d = new Date(iso);
  if (isNaN(d.getTime())) return iso;
  return d.toLocaleDateString(undefined, { month: 'short', day: 'numeric' });
};

const weekKey = (iso) => {
  const d = new Date(iso);
  // ISO week number
  const target = new Date(d.valueOf());
  const dayNr = (d.getUTCDay() + 6) % 7;
  target.setUTCDate(target.getUTCDate() - dayNr + 3);
  const firstThursday = target.valueOf();
  target.setUTCMonth(0, 1);
  if (target.getUTCDay() !== 4) {
    target.setUTCMonth(0, 1 + ((4 - target.getUTCDay()) + 7) % 7);
  }
  const weekNumber = 1 + Math.ceil((firstThursday - target) / 604800000);
  return `${d.getUTCFullYear()}-W${String(weekNumber).padStart(2, '0')}`;
};

export default function ClassWideLongitudinalChart({ sectionId, defaultConcept = ALL_CONCEPTS }) {
  const [raw, setRaw] = useState(null);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState('');
  const [selectedConcept, setSelectedConcept] = useState(defaultConcept);

  useEffect(() => {
    let alive = true;
    if (!sectionId) return;
    setLoading(true);
    setError('');
    analyticsService
      .getSectionLongitudinal(sectionId)
      .then((res) => {
        if (!alive) return;
        setRaw(res.data);
        setLoading(false);
      })
      .catch((err) => {
        if (!alive) return;
        console.error('ClassWideLongitudinalChart load error:', err);
        setError(err.response?.data?.message || err.message);
        setLoading(false);
      });
    return () => {
      alive = false;
    };
  }, [sectionId]);

  // Build a flat list of (date, weekKey, concept, cds) samples.
  const samples = useMemo(() => {
    if (!raw?.students) return [];
    const out = [];
    for (const student of raw.students) {
      for (const p of student.progression || []) {
        out.push({
          iso: p.computed_at,
          week: weekKey(p.computed_at),
          concept: p.concept_name,
          cds: typeof p.cds === 'string' ? parseFloat(p.cds) : p.cds,
        });
      }
    }
    out.sort((a, b) => new Date(a.iso) - new Date(b.iso));
    return out;
  }, [raw]);

  const availableConcepts = useMemo(() => {
    const set = new Set();
    for (const s of samples) set.add(s.concept);
    return Array.from(set).sort();
  }, [samples]);

  // If the current selected concept isn't in the data, fall back.
  useEffect(() => {
    if (
      selectedConcept !== ALL_CONCEPTS &&
      !availableConcepts.includes(selectedConcept) &&
      availableConcepts.length > 0
    ) {
      setSelectedConcept(ALL_CONCEPTS);
    }
  }, [availableConcepts, selectedConcept]);

  // Build the chart series: for "all" we average across all concepts per week;
  // for a specific concept we average that concept's CDS per week.
  const series = useMemo(() => {
    const filtered =
      selectedConcept === ALL_CONCEPTS
        ? samples
        : samples.filter((s) => s.concept === selectedConcept);

    if (filtered.length === 0) return [];

    const byWeek = new Map();
    for (const s of filtered) {
      if (s.cds === null || s.cds === undefined || isNaN(s.cds)) continue;
      if (!byWeek.has(s.week)) byWeek.set(s.week, { sum: 0, count: 0, date: s.iso });
      const acc = byWeek.get(s.week);
      acc.sum += s.cds;
      acc.count += 1;
    }

    const weeks = Array.from(byWeek.keys()).sort();
    return weeks.map((w) => {
      const acc = byWeek.get(w);
      return {
        week: w,
        label: formatDate(acc.date),
        avgCDS: acc.count > 0 ? Number((acc.sum / acc.count).toFixed(3)) : null,
        n: acc.count,
      };
    });
  }, [samples, selectedConcept]);

  // Trajectory summary stats
  const stats = useMemo(() => {
    if (series.length === 0) return null;
    const values = series.map((p) => p.avgCDS).filter((v) => v !== null);
    if (values.length === 0) return null;
    const first = values[0];
    const last = values[values.length - 1];
    const peak = values.reduce((a, b) => (b > a ? b : a), 0);
    const trough = values.reduce((a, b) => (b < a ? b : a), 1);
    const delta = last - first;
    let trend = 'stable';
    if (delta > 0.05) trend = 'rising';
    else if (delta < -0.05) trend = 'falling';
    return { first, last, peak, trough, delta, trend, samples: values.length };
  }, [series]);

  if (loading) {
    return (
      <div className="rounded-lg border border-border bg-card p-6 text-sm text-muted-foreground">
        Loading class-wide trend…
      </div>
    );
  }

  if (error) {
    return (
      <div className="rounded-lg border border-destructive/30 bg-destructive/10 p-4 text-sm text-destructive">
        Failed to load longitudinal data: {error}
      </div>
    );
  }

  if (samples.length === 0) {
    return (
      <div className="rounded-lg border border-border bg-card p-6 text-sm text-muted-foreground">
        No class-wide longitudinal data yet — submissions will populate this once students begin solving exercises.
      </div>
    );
  }

  const lineColor =
    selectedConcept === ALL_CONCEPTS
      ? '#85D2D0'
      : CONCEPT_COLORS[selectedConcept] || '#85D2D0';

  return (
    <div className="rounded-lg border border-border bg-card p-5 shadow-sm">
      <div className="mb-4 flex flex-wrap items-start justify-between gap-3">
        <div>
          <h3 className="text-sm font-bold text-foreground">📈 Class-Wide Longitudinal Trend</h3>
          <p className="mt-0.5 text-[11px] text-muted-foreground">
            Average Concept Difficulty Score over time, aggregated across all enrolled students.
          </p>
        </div>

        <div className="flex items-center gap-2">
          <label
            htmlFor="longitudinal-concept"
            className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground"
          >
            Concept
          </label>
          <Select value={selectedConcept} onValueChange={setSelectedConcept}>
            <SelectTrigger id="longitudinal-concept" className="h-8 w-[200px] text-xs">
              <SelectValue placeholder="Pick a concept" />
            </SelectTrigger>
            <SelectContent>
              <SelectItem value={ALL_CONCEPTS}>All concepts (class-wide)</SelectItem>
              {availableConcepts.map((c) => (
                <SelectItem key={c} value={c}>
                  {c}
                </SelectItem>
              ))}
            </SelectContent>
          </Select>
        </div>
      </div>

      {/* Summary stats */}
      {stats && (
        <div className="mb-4 grid grid-cols-2 gap-2 sm:grid-cols-4">
          <div className="rounded-md border border-border bg-muted/30 px-3 py-2">
            <div className="text-[10px] font-semibold uppercase tracking-widest text-muted-foreground">
              Latest CDS
            </div>
            <div className="mt-1 font-mono text-base font-bold text-foreground">
              {stats.last.toFixed(2)}
            </div>
          </div>
          <div className="rounded-md border border-border bg-muted/30 px-3 py-2">
            <div className="text-[10px] font-semibold uppercase tracking-widest text-muted-foreground">
              Δ since first
            </div>
            <div
              className={`mt-1 font-mono text-base font-bold ${
                stats.delta > 0
                  ? 'text-red-600'
                  : stats.delta < 0
                    ? 'text-green-600'
                    : 'text-foreground'
              }`}
            >
              {stats.delta > 0 ? '+' : ''}
              {stats.delta.toFixed(2)}
            </div>
          </div>
          <div className="rounded-md border border-border bg-muted/30 px-3 py-2">
            <div className="text-[10px] font-semibold uppercase tracking-widest text-muted-foreground">
              Peak
            </div>
            <div className="mt-1 font-mono text-base font-bold text-foreground">
              {stats.peak.toFixed(2)}
            </div>
          </div>
          <div className="rounded-md border border-border bg-muted/30 px-3 py-2">
            <div className="text-[10px] font-semibold uppercase tracking-widest text-muted-foreground">
              Trend
            </div>
            <div className="mt-1 font-mono text-base font-bold text-foreground">
              {stats.trend === 'rising' && '📈 Rising'}
              {stats.trend === 'falling' && '📉 Falling'}
              {stats.trend === 'stable' && '➡️ Stable'}
            </div>
          </div>
        </div>
      )}

      {/* Chart */}
      <div className="h-64 w-full">
        <ResponsiveContainer width="100%" height="100%">
          <ComposedChart data={series} margin={{ top: 8, right: 16, left: 0, bottom: 4 }}>
            <defs>
              <linearGradient id="classWideFill" x1="0" y1="0" x2="0" y2="1">
                <stop offset="0%" stopColor={lineColor} stopOpacity={0.25} />
                <stop offset="100%" stopColor={lineColor} stopOpacity={0} />
              </linearGradient>
            </defs>
            <CartesianGrid stroke="hsl(var(--border))" strokeDasharray="3 3" vertical={false} />
            <XAxis
              dataKey="label"
              tick={{ fontSize: 10, fill: 'hsl(var(--muted-foreground))' }}
              stroke="hsl(var(--border))"
            />
            <YAxis
              domain={[0, 1]}
              tick={{ fontSize: 10, fill: 'hsl(var(--muted-foreground))' }}
              stroke="hsl(var(--border))"
              tickFormatter={(v) => v.toFixed(1)}
            />
            <Tooltip
              contentStyle={{
                backgroundColor: 'hsl(var(--card))',
                border: '1px solid hsl(var(--border))',
                borderRadius: 6,
                fontSize: 12,
              }}
              labelStyle={{ color: 'hsl(var(--foreground))' }}
              formatter={(value, name, ctx) => {
                if (name === 'avgCDS') {
                  return [Number(value).toFixed(2) + ' CDS', `n=${ctx.payload.n} samples`];
                }
                return [value, name];
              }}
            />
            <ReferenceLine
              y={0.33}
              stroke="#10b981"
              strokeDasharray="4 4"
              label={{ value: 'Low / Moderate threshold', position: 'right', fontSize: 9, fill: '#10b981' }}
            />
            <ReferenceLine
              y={0.66}
              stroke="#f59e0b"
              strokeDasharray="4 4"
              label={{ value: 'Moderate / High threshold', position: 'right', fontSize: 9, fill: '#f59e0b' }}
            />
            <Area
              type="monotone"
              dataKey="avgCDS"
              stroke="none"
              fill="url(#classWideFill)"
              isAnimationActive={false}
            />
            <Line
              type="monotone"
              dataKey="avgCDS"
              stroke={lineColor}
              strokeWidth={2.5}
              dot={{ r: 3, stroke: lineColor, fill: 'hsl(var(--card))' }}
              activeDot={{ r: 5 }}
              isAnimationActive={false}
            />
          </ComposedChart>
        </ResponsiveContainer>
      </div>

      <div className="mt-3 flex items-center gap-4 text-[10px] text-muted-foreground">
        <div className="flex items-center gap-1.5">
          <span className="inline-block h-0.5 w-4 rounded-full" style={{ background: lineColor }} />
          {selectedConcept === ALL_CONCEPTS ? 'Class average' : selectedConcept}
        </div>
        <div>{series.length} week{series.length === 1 ? '' : 's'} of data</div>
      </div>
    </div>
  );
}
