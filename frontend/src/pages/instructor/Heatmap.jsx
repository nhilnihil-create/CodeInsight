import { useEffect, useState, useMemo, Fragment } from 'react';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import SectionFilter from '@/components/SectionFilter';
import api from '@/services/api';
import { cn } from '@/lib/utils';

/* ── Knowledge Area Labels ─────────────────────────────────────────────── */

const KA_LABELS = {
  'SDF-FPC': 'Procedural Fundamentals',
  'SDF-PMD': 'Program Design & Logic',
  'SDF-FDS': 'Data Structures & Memory',
  'SDF-OOP': 'Object-Oriented Paradigms',
};

/* ── Sequential blue gradient — the original HEAT_TONE palette ────────────
 *  CDS 0-100: higher = more struggle.
 *  Empty (no data) cells are completely transparent — zero visual noise.
 *  Active cells use a cool-to-strong blue gradient.
 *  Colorblind-safe, perceptually uniform.
 */

const HEAT_LEVELS = [
  { min: 0,  max: 39, label: 'Low',      cell: 'bg-blue-500/[0.06]', text: 'text-blue-400/80' },
  { min: 40, max: 69, label: 'Moderate', cell: 'bg-blue-500/[0.18]', text: 'text-blue-300' },
  { min: 70, max: 100,label: 'High',     cell: 'bg-blue-500/[0.35]', text: 'text-blue-100 font-semibold' },
];

function heatLevel(cdsPct) {
  if (cdsPct == null) return null; // no data → transparent
  for (const l of HEAT_LEVELS) {
    if (cdsPct >= l.min && cdsPct <= l.max) return l;
  }
  return HEAT_LEVELS[HEAT_LEVELS.length - 1];
}

/* ── Compact cell — transparent when no data ──────────────────────────── */

function Cell({ cdsPct }) {
  const level = heatLevel(cdsPct);
  if (!level) {
    // No data → completely invisible
    return <div className="w-full h-7" />;
  }

  return (
    <div className={cn(
      'w-full h-7 flex items-center justify-center rounded-md',
      'transition-all duration-150 cursor-default',
      level.cell,
    )}>
      <span className={cn('text-[11px] font-mono tabular-nums', level.text)}>
        {cdsPct}
      </span>
    </div>
  );
}

/* ── Legend ───────────────────────────────────────────────────────────── */

function Legend() {
  return (
    <div className="flex items-center justify-end gap-3 pt-2">
      {HEAT_LEVELS.map((l, i) => (
        <div key={i} className="flex items-center gap-1.5">
          <div className={cn('w-4 h-3 rounded-sm', l.cell)} />
          <span className="text-[10px] text-muted-foreground">{l.label}</span>
        </div>
      ))}
      <div className="flex items-center gap-1.5 ml-2">
        <div className="w-4 h-3 rounded-sm border border-dashed border-border/30" />
        <span className="text-[10px] text-muted-foreground">No data</span>
      </div>
    </div>
  );
}

/* ── Main Heatmap ─────────────────────────────────────────────────────── */

export default function InstructorHeatmap() {
  const [sectionId, setSectionId] = useState('all');
  const [rows, setRows] = useState([]);
  const [concepts, setConcepts] = useState([]);
  const [conceptMeta, setConceptMeta] = useState({});
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState(null);
  const [hoveredRow, setHoveredRow] = useState(null);
  const [collapsedTracks, setCollapsedTracks] = useState({});

  /* ── Group concepts by knowledge area ────────────────────────────── */
  const groupedConcepts = useMemo(() => {
    const groups = {};
    for (const c of concepts) {
      const ka = conceptMeta[c]?.knowledgeAreaCode || 'UNCATEGORIZED';
      if (!groups[ka]) groups[ka] = [];
      groups[ka].push(c);
    }
    // Sort groups by known priority, filter out empty groups
    const kaOrder = ['SDF-FPC', 'SDF-PMD', 'SDF-FDS', 'SDF-OOP', 'UNCATEGORIZED'];
    const sorted = {};
    for (const ka of kaOrder) {
      if (groups[ka] && groups[ka].length > 0) sorted[ka] = groups[ka];
    }
    return sorted;
  }, [concepts, conceptMeta]);

  /* ── Collapse all tracks by default on first data load ───────────── */
  const initDoneRef = useState(false)[1];
  useEffect(() => {
    if (Object.keys(groupedConcepts).length > 0 && !initDoneRef.current) {
      const defaults = {};
      for (const ka of Object.keys(groupedConcepts)) defaults[ka] = true;
      setCollapsedTracks(defaults);
      initDoneRef.current = true;
    }
    // Reset init flag when section changes
    if (Object.keys(groupedConcepts).length === 0) initDoneRef.current = false;
  }, [groupedConcepts, initDoneRef, sectionId]);

  /* ── Data fetch ──────────────────────────────────────────────────── */
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

        // Fetch concept metadata for grouping by knowledge area
        try {
          const metaRes = await api.get('/api/exercises/concepts');
          const meta = {};
          for (const c of metaRes.data || []) {
            meta[c.name] = {
              knowledgeAreaCode: c.knowledge_area_code || null,
              slug: c.slug || null,
              bloomLevel: c.bloom_level || null,
              difficultyTier: c.difficulty_tier || 1,
            };
          }
          if (!cancelled) setConceptMeta(meta);
        } catch (_) { /* metadata is optional enhancement */ }

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
    return () => { cancelled = true };
  }, [sectionId]);

  const toggleTrack = (ka) => {
    setCollapsedTracks(prev => ({ ...prev, [ka]: !prev[ka] }));
  };

  /* ── Track average for a collapsed group ─────────────────────────── */
  const trackAverage = (row, trackConcepts) => {
    const vals = trackConcepts
      .map(c => row.scores[c])
      .filter(v => v != null)
      .map(v => Math.round(v * 100));
    if (vals.length === 0) return null;
    return Math.round(vals.reduce((a, b) => a + b, 0) / vals.length);
  };

  /* ── render ──────────────────────────────────────────────────────── */
  return (
    <div className="flex flex-col grow h-full w-full">
      {/* Page header */}
      <div className="flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between mb-4">
        <div>
          <h1 className="text-2xl font-bold tracking-tight">Class Heatmap</h1>
          <p className="text-muted-foreground">
            CDS struggle index grouped by conceptual track. Click track headers to collapse.
          </p>
        </div>
        <SectionFilter value={sectionId} onChange={setSectionId} />
      </div>

      {/* Card */}
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
              {/* Table area */}
              <div className="flex-1 min-h-0 overflow-auto custom-scroll">
                <table className="w-full text-sm border-collapse">
                  <thead>
                    {/* TIER 1: Track headers (knowledge areas) */}
                    <tr className="bg-muted/20">
                      <th
                        className="sticky left-0 z-30 bg-muted/30 text-left px-4 py-2 text-[10px] font-bold uppercase tracking-wider text-muted-foreground border-b border-r border-border/50"
                        style={{ minWidth: 160 }}
                      >
                        Student
                      </th>
                      {Object.entries(groupedConcepts).map(([ka, trackConcepts]) => {
                        const isCollapsed = collapsedTracks[ka];
                        const label = KA_LABELS[ka] || ka;
                        return (
                          <th
                            key={ka}
                            colSpan={Math.max(1, isCollapsed ? 1 : trackConcepts.length)}
                            className="px-2 py-2 text-center border-b border-border/40 cursor-pointer select-none hover:bg-muted/40 transition-colors group"
                            onClick={() => toggleTrack(ka)}
                          >
                            <div className="flex items-center justify-center gap-1.5 min-w-0">
                              <span className="text-[10px] font-bold uppercase tracking-wider text-muted-foreground group-hover:text-foreground transition-colors truncate whitespace-nowrap max-w-[120px]">
                                {label}
                              </span>
                              <span className="text-[9px] text-muted-foreground/60 transition-transform group-hover:scale-110 shrink-0">
                                {isCollapsed ? '▸' : '▾'}
                              </span>
                            </div>
                          </th>
                        );
                      })}
                    </tr>

                    {/* TIER 2: Concept sub-headers — every row includes cells for ALL tracks */}
                    <tr className="bg-muted/5">
                      <th
                        className="sticky left-0 z-20 bg-muted/10 px-4 py-1 border-b border-r border-border/30"
                        style={{ minWidth: 160 }}
                      />
                      {Object.entries(groupedConcepts).map(([ka, trackConcepts]) => {
                        const isCollapsed = collapsedTracks[ka];
                        return (
                          <Fragment key={`sub-${ka}`}>
                            {isCollapsed ? (
                              // Placeholder cell for collapsed track (keeps column alignment)
                              <th
                                key={ka}
                                className="px-2 py-1 text-center text-[9px] text-muted-foreground/40 border-b border-border/10 cursor-pointer select-none"
                                onClick={() => toggleTrack(ka)}
                              >
                                {KA_LABELS[ka] || ka}
                              </th>
                            ) : (
                              trackConcepts.map((c) => (
                                <th
                                  key={c}
                                  className="px-1 py-1 text-center text-[10px] font-medium text-muted-foreground whitespace-nowrap border-b border-border/20 truncate max-w-[70px]"
                                  title={conceptMeta[c]?.bloomLevel || ''}
                                >
                                  {c}
                                </th>
                              ))
                            )}
                          </Fragment>
                        );
                      })}
                    </tr>
                  </thead>

                  <tbody>
                    {rows.map((row) => (
                      <tr
                        key={row.studentId}
                        className={`transition-colors duration-150 ${
                          hoveredRow === row.studentId
                            ? 'bg-accent/30'
                            : hoveredRow
                              ? 'opacity-60'
                              : ''
                        }`}
                        onMouseEnter={() => setHoveredRow(row.studentId)}
                        onMouseLeave={() => setHoveredRow(null)}
                      >
                        {/* Sticky student name */}
                        <td
                          className="sticky left-0 z-10 bg-card px-4 py-1 font-medium whitespace-nowrap border-r border-border/40 shadow-[4px_0_8px_-4px_rgba(0,0,0,0.15)]"
                          style={{ minWidth: 160 }}
                        >
                          {row.name}
                        </td>

                        {/* Data cells grouped by track */}
                        {Object.entries(groupedConcepts).map(([ka, trackConcepts]) => {
                          const isCollapsed = collapsedTracks[ka];
                          if (isCollapsed) {
                            const avg = trackAverage(row, trackConcepts);
                            return (
                              <td key={`avg-${ka}`} className="p-0.5 border-r border-border/5">
                                <Cell cdsPct={avg} />
                              </td>
                            );
                          }
                          return trackConcepts.map((c) => (
                            <td key={c} className="p-0.5">
                              <Cell cdsPct={row.scores[c] != null ? Math.round(row.scores[c] * 100) : null} />
                            </td>
                          ));
                        })}
                      </tr>
                    ))}
                  </tbody>
                </table>
              </div>

              {/* Legend */}
              <div className="flex-shrink-0 px-4 pb-3 pt-1 border-t border-border/30">
                <Legend />
              </div>
            </>
          )}
        </CardContent>
      </Card>
    </div>
  );
}
