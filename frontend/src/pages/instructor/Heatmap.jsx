import { useEffect, useState } from 'react';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import SectionFilter from '@/components/SectionFilter';
import api from '@/services/api';
import { cn } from '@/lib/utils';

/* ── Reports engagement heatmap palette (from Reports.jsx:69-75) ─────────── */
const HEAT_TONE = [
  'bg-muted/40',     // 0: Unscored / empty baseline
  'bg-primary/15',   // 1: Low
  'bg-primary/30',   // 2: Mid
  'bg-primary/50',   // 3: High
  'bg-primary/75',   // 4: Critical
];

/**
 * Map a CDS percentage (0-100) to a HEAT_TONE index (0-4).
 * null/undefined → 0 (unscored shell)
 * 0-25  → 1 (low risk)
 * 26-50 → 2 (mid)
 * 51-75 → 3 (high)
 * 76+   → 4 (critical)
 */
function heatIndex(cdsPct) {
  if (cdsPct == null) return 0;
  if (cdsPct <= 25) return 1;
  if (cdsPct <= 50) return 2;
  if (cdsPct <= 75) return 3;
  return 4;
}

/**
 * Tile classes for a given heat index.
 * State 0 = empty shell with faint outline.
 * States 1-4 = Reports density colors with readable text.
 */
function cellClasses(idx) {
  const base =
    'rounded-md p-2 text-center font-mono text-xs ' +
    'transition-all duration-150 ease-out hover:scale-105 hover:border-card-border cursor-pointer';
  if (idx === 0) {
    return `${base} bg-muted/20 border border-border/40 text-muted-foreground/30`;
  }
  const tone = HEAT_TONE[idx];
  const textClass =
    idx >= 4 ? 'text-white font-bold'
    : idx >= 3 ? 'text-white font-medium'
    : idx >= 2 ? 'text-card-foreground/80'
    : 'text-muted-foreground';
  return `${base} ${tone} ${textClass} border border-border/30`;
}

/**
 * Intensity legend — bottom-right corner.
 * Labels reflect CDS *struggle* (not submission density).
 */
function Legend() {
  return (
    <div className="flex items-center justify-end gap-2 pt-3">
      <span className="text-[10px] uppercase tracking-wider text-muted-foreground">Low risk</span>
      {HEAT_TONE.map((tone, i) => (
        <div key={i} className={cn('h-3 w-5 rounded-sm border border-border/40', tone)} />
      ))}
      <span className="text-[10px] uppercase tracking-wider text-muted-foreground">High risk</span>
    </div>
  );
}

/**
 * Class-wide concept struggle heatmap.
 *
 * - Uses the exact Reports engagement density palette (HEAT_TONE)
 * - Flex layout fills vertical space (no dead space below card)
 * - 5-state tile matrix: empty-shell → 4-step density gradient
 * - Legend: LESS ■ ■ ■ ■ MORE (bottom-right)
 * - Sticky student column + concept header
 * - Row-level hover tracking, micro-lift on cell hover with sibling dim
 */
export default function InstructorHeatmap() {
  const [sectionId, setSectionId] = useState('all');
  const [rows, setRows] = useState([]);
  const [concepts, setConcepts] = useState([]);
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState(null);
  const [hoveredRow, setHoveredRow] = useState(null);

  /* ── data fetch ────────────────────────────────────────────────────────── */
  useEffect(() => {
    let cancelled = false;
    const load = async () => {
      setLoading(true);
      setError(null);
      try {
        const res = await api.get(`/api/analytics/heatmap/${sectionId}`);
        const students = res.data?.students || [];
        const scoresRaw = res.data?.scores || {};
        const conceptsFromApi = res.data?.concepts || [];
        const studentNames = {};
        for (const s of students) studentNames[s.id] = s.name;

        const out = Object.keys(scoresRaw).map((studentId) => {
          const conceptScores = {};
          for (const c of conceptsFromApi) {
            const raw = scoresRaw[studentId]?.[c]?.cds;
            conceptScores[c] = typeof raw === 'string'
              ? parseFloat(raw)
              : (raw === null || raw === undefined ? null : raw);
          }
          return {
            studentId,
            name: studentNames[studentId] || `Student #${studentId}`,
            scores: conceptScores,
          };
        });
        if (!cancelled) {
          setConcepts(conceptsFromApi);
          setRows(out);
        }
      } catch (err) {
        if (!cancelled) {
          setConcepts([]);
          setRows([]);
          setError(err.response?.data?.message || 'Failed to load heatmap data.');
        }
      } finally {
        if (!cancelled) setLoading(false);
      }
    };
    load();
    return () => { cancelled = true; };
  }, [sectionId]);

  /* ── render ───────────────────────────────────────────────────────────── */
  return (
    <div className="flex flex-col grow h-full w-full">
      {/* Page header */}
      <div className="flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between mb-4">
        <div>
          <h1 className="text-2xl font-bold tracking-tight">Class Heatmap</h1>
          <p className="text-muted-foreground">CDS struggle index across the class.</p>
        </div>
        <SectionFilter value={sectionId} onChange={setSectionId} />
      </div>

      {/* Card — flex-1 to consume all vertical space */}
      <Card className="flex flex-col flex-1 min-h-0 w-full overflow-hidden">
        <CardHeader className="pb-3 flex-shrink-0">
          <CardTitle>Concept × Student — Struggle Index</CardTitle>
        </CardHeader>

        <CardContent className="flex-1 min-h-0 p-0 flex flex-col">
          {loading ? (
            <div className="py-16 text-center text-muted-foreground text-sm">
              <div className="animate-spin h-5 w-5 border-2 border-muted-foreground/30 border-t-muted-foreground rounded-full mx-auto mb-3" />
              Loading heatmap…
            </div>
          ) : error ? (
            <div className="py-16 text-center">
              <p className="text-sm text-destructive font-medium">{error}</p>
              <p className="text-xs text-muted-foreground mt-1">Try selecting a different section or refresh the page.</p>
            </div>
          ) : rows.length === 0 ? (
            <div className="py-16 text-center text-muted-foreground text-sm">
              <p>No heatmap data available for this selection.</p>
              <p className="text-xs mt-1">Students must have CDS scores computed to appear here.</p>
            </div>
          ) : (
            <>
              {/* Table area — flex-1 to fill remaining space */}
              <div className="flex-1 min-h-0 overflow-y-auto custom-scroll">
                <table className="w-full text-sm">
                  <thead className="sticky top-0 z-20 bg-card">
                    <tr>
                      <th
                        className="sticky left-0 z-30 bg-card text-left px-4 py-3 font-medium text-muted-foreground whitespace-nowrap"
                        style={{ minWidth: 130 }}
                      >
                        Student
                      </th>
                      {concepts.map((c) => (
                        <th
                          key={c}
                          className="bg-card px-3 py-3 font-medium text-muted-foreground text-center whitespace-nowrap"
                        >
                          {c}
                        </th>
                      ))}
                    </tr>
                  </thead>

                  <tbody>
                    {rows.map((row) => (
                      <tr
                        key={row.studentId}
                        className={`transition-colors duration-150 ${
                          hoveredRow === row.studentId
                            ? 'bg-accent/40'
                            : hoveredRow
                              ? 'opacity-50'
                              : ''
                        }`}
                        onMouseEnter={() => setHoveredRow(row.studentId)}
                        onMouseLeave={() => setHoveredRow(null)}
                      >
                        <td
                          className="sticky left-0 z-10 bg-card px-4 py-2 font-medium whitespace-nowrap"
                          style={{ minWidth: 130 }}
                        >
                          {row.name}
                        </td>
                        {concepts.map((c) => {
                          const rawCds = row.scores[c];
                          const hasData = rawCds !== null && rawCds !== undefined;
                          const cdsPct = hasData ? Math.round(rawCds * 100) : null;
                          const idx = heatIndex(cdsPct);
                          const cls = cellClasses(idx);

                          return (
                            <td key={c} className="p-1">
                              <div className={cls}>
                                {idx === 0 ? (cdsPct ?? '—') : cdsPct}
                              </div>
                            </td>
                          );
                        })}
                      </tr>
                    ))}
                  </tbody>
                </table>
              </div>

              {/* Legend — bottom-right */}
              <div className="flex-shrink-0 px-4 pb-4">
                <Legend />
              </div>
            </>
          )}
        </CardContent>
      </Card>
    </div>
  );
}
