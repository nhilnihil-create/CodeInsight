import { useEffect, useState, useMemo, useRef, useCallback } from 'react';
import { createPortal } from 'react-dom';
import { motion, AnimatePresence } from 'framer-motion';
import { Input } from '@/components/ui/input';
import { GripVertical } from 'lucide-react';
import SectionFilter from '@/components/SectionFilter';
import useLastSection from '@/hooks/useLastSection';
import api from '@/services/api';
import { cn } from '@/lib/utils';

/* ═══════════════════════════════════════════════════════════════════════════
   CONTINUOUS GRADIENT CDS COLOR SCALE
   Smooth interpolation from teal (low) → amber (mid) → rose (high).
   ═══════════════════════════════════════════════════════════════════════════ */

function lerp(a, b, t) {
  return a + (b - a) * t;
}

function lerpColor(c1, c2, t) {
  return [
    Math.round(lerp(c1[0], c2[0], t)),
    Math.round(lerp(c1[1], c2[1], t)),
    Math.round(lerp(c1[2], c2[2], t)),
  ];
}

function cdsColor(cds) {
  if (cds == null) return { bg: 'rgba(15,23,42,0.6)', text: 'text-slate-500', label: 'No Data' };
  const v = Math.max(0, Math.min(1, Number(cds)));
  if (v === 0) return { bg: 'rgba(15,23,42,0.6)', text: 'text-slate-500', label: 'No Data' };

  const stops = [
    { pos: 0.00, rgb: [26, 95, 80] },
    { pos: 0.20, rgb: [16, 185, 129] },
    { pos: 0.40, rgb: [245, 158, 11] },
    { pos: 0.60, rgb: [249, 115, 22] },
    { pos: 0.80, rgb: [225, 29, 72] },
    { pos: 1.00, rgb: [190, 18, 60] },
  ];

  let lower = stops[0], upper = stops[stops.length - 1];
  for (let i = 0; i < stops.length - 1; i++) {
    if (v >= stops[i].pos && v <= stops[i + 1].pos) {
      lower = stops[i];
      upper = stops[i + 1];
      break;
    }
  }

  const range = upper.pos - lower.pos || 1;
  const t = (v - lower.pos) / range;
  const rgb = lerpColor(lower.rgb, upper.rgb, t);

  const alpha = lerp(0.15, 0.55, v);
  const textColor = v < 0.20 ? 'text-slate-300' : v < 0.40 ? 'text-emerald-300' : v < 0.60 ? 'text-amber-300' : 'text-rose-300';

  const label =
    v <= 0.20 ? 'Very Low' :
    v <= 0.40 ? 'Low' :
    v <= 0.60 ? 'Moderate' :
    v <= 0.80 ? 'High' : 'Very High';

  return {
    bg: `rgba(${rgb[0]},${rgb[1]},${rgb[2]},${alpha})`,
    text: textColor,
    label,
  };
}

const CDS_TIERS = [
  { min: -1,   max: -1,   label: 'No Data',  cell: 'bg-slate-900/60 text-slate-500',        text: '' },
  { min: 0.00, max: 0.00, label: 'No Data',  cell: 'bg-slate-900/60 text-slate-500',        text: '' },
  { min: 0.01, max: 0.20, label: 'Very Low',  cell: 'bg-slate-800/20 text-slate-500',        text: 'text-slate-500' },
  { min: 0.21, max: 0.40, label: 'Low',       cell: 'bg-emerald-500/20 text-emerald-400',    text: 'text-emerald-400' },
  { min: 0.41, max: 0.60, label: 'Moderate',  cell: 'bg-amber-500/20 text-amber-400',        text: 'text-amber-400' },
  { min: 0.61, max: 0.80, label: 'High',      cell: 'bg-orange-500/25 text-orange-400',      text: 'text-orange-400' },
  { min: 0.81, max: 1.00, label: 'Very High', cell: 'bg-rose-600/35 text-rose-400 font-bold', text: 'text-rose-400' },
];

function cdsTier(cds) {
  if (cds == null) return CDS_TIERS[0];
  const v = Number(cds);
  if (Number.isNaN(v)) return CDS_TIERS[0];
  if (v === 0) return CDS_TIERS[1];
  for (let i = 2; i < CDS_TIERS.length; i++) {
    if (v >= CDS_TIERS[i].min && v <= CDS_TIERS[i].max) return CDS_TIERS[i];
  }
  return CDS_TIERS[CDS_TIERS.length - 1];
}

/* ═══════════════════════════════════════════════════════════════════════════
   LEGEND — inline tier swatches
   ═══════════════════════════════════════════════════════════════════════════ */

function Legend() {
  return (
    <div className="flex items-center gap-2.5 flex-wrap">
      <span className="text-[9px] text-white/30 whitespace-nowrap">Very Low</span>
      <div
        className="h-2.5 w-24 rounded-[2px]"
        style={{
          background: 'linear-gradient(to right, rgba(26,95,80,0.35), rgba(16,185,129,0.5), rgba(245,158,11,0.5), rgba(249,115,22,0.55), rgba(225,29,72,0.6))',
        }}
      />
      <span className="text-[9px] text-white/30 whitespace-nowrap">Very High</span>
    </div>
  );
}

/* ═══════════════════════════════════════════════════════════════════════════
   MOSAIC CELL — uniform gapless data block
   ═══════════════════════════════════════════════════════════════════════════ */

const CELL_SIZE = 'w-10 h-10';

function Cell({ cds, onHover, onLeave }) {
  const color = cdsColor(cds);

  return (
    <div
      className={cn(
        CELL_SIZE,
        'flex items-center justify-center rounded-[2px]',
        'text-[9px] font-mono tabular-nums select-none cursor-default',
        'transition-colors duration-75',
      )}
      style={{
        backgroundColor: cds != null && cds > 0 ? color.bg : 'rgba(15,23,42,0.6)',
        color: cds != null && cds > 0 ? undefined : undefined,
      }}
      onMouseEnter={(e) => onHover?.(e)}
      onMouseMove={(e) => onHover?.(e)}
      onMouseLeave={onLeave}
    >
      <span className={cds != null && cds > 0 ? color.text : 'text-slate-500'}>
        {cds != null && cds > 0 ? Number(cds).toFixed(2) : ''}
      </span>
    </div>
  );
}

/* ═══════════════════════════════════════════════════════════════════════════
   GLASSMORPHIC PORTAL TOOLTIP
   Rendered via createPortal to body for true overlay positioning.
   ═══════════════════════════════════════════════════════════════════════════ */

function PortalTooltip({ x, y, data, visible }) {
  if (!visible || !data) return null;
  const color = cdsColor(data.cds);

  return createPortal(
    <div
      className="fixed z-[9999] pointer-events-none
                 bg-white/[0.06] backdrop-blur-2xl
                 border border-white/[0.12] rounded-xl px-4 py-3
                 shadow-[0_8px_32px_rgba(0,0,0,0.4),inset_0_1px_0_rgba(255,255,255,0.08)]
                 text-xs leading-relaxed min-w-[180px] select-none"
      style={{ left: x + 18, top: y - 14 }}
    >
      {/* Concept Title */}
      <div className="font-semibold text-white/90 text-[11px] mb-1">{data.concept}</div>
      <div className="text-white/40 text-[10px] mb-2">{data.student}</div>

      {/* CDS Struggle Index */}
      <div className="flex items-center gap-2 mb-2">
        <span className="font-mono tabular-nums font-semibold text-white/90 text-sm">
          {Number(data.cds).toFixed(2)}
        </span>
        <span className={cn(
          'text-[9px] px-1.5 py-[1px] rounded-full font-medium',
          'bg-white/[0.08] border border-white/[0.08]',
          color.text,
        )}>
          {color.label}
        </span>
      </div>

      {/* Underlying Metrics */}
      {data.raw && (
        <div className="space-y-1 pt-2 border-t border-white/[0.08]">
          <div className="flex justify-between gap-6">
            <span className="text-white/40 text-[10px]">NER</span>
            <span className="font-mono tabular-nums text-white/70 text-[10px]">
              {Number(data.raw.ner).toFixed(2)}
            </span>
          </div>
          <div className="flex justify-between gap-6">
            <span className="text-white/40 text-[10px]">NRS</span>
            <span className="font-mono tabular-nums text-white/70 text-[10px]">
              {Number(data.raw.nrs).toFixed(2)}
            </span>
          </div>
          <div className="flex justify-between gap-6">
            <span className="text-white/40 text-[10px]">NTS</span>
            <span className="font-mono tabular-nums text-white/70 text-[10px]">
              {Number(data.raw.nts).toFixed(2)}
            </span>
          </div>
        </div>
      )}
    </div>,
    document.body,
  );
}

/* ═══════════════════════════════════════════════════════════════════════════
   DRAGGABLE COLUMN HEADER
   Hold-to-drag reordering via framer-motion drag="x".
   ═══════════════════════════════════════════════════════════════════════════ */

function DraggableColumnHeader({ concept, index, onSwap, totalColumns }) {
  const cellW = 40; // w-10 cell width
  const headerRef = useRef(null);
  const dragStartX = useRef(0);

  return (
    <motion.th
      ref={headerRef}
      drag="x"
      dragConstraints={{ left: 0, right: 0 }}
      dragElastic={0.15}
      dragSnapToOrigin={true}
      onDragStart={() => { dragStartX.current = 0; }}
      onDrag={(e, info) => {
        const dx = info.offset.x;
        const threshold = cellW * 0.5;
        const currentIdx = index;

        if (Math.abs(dx) > threshold) {
          const direction = dx > 0 ? 1 : -1;
          const targetIdx = currentIdx + direction;
          if (targetIdx >= 0 && targetIdx < totalColumns) {
            onSwap(currentIdx, targetIdx);
          }
        }
      }}
      whileDrag={{ scale: 1.05, zIndex: 50, cursor: 'grabbing' }}
      className={cn(
        'relative h-28 p-0 m-0 text-center align-bottom',
        'border-b border-white/5 cursor-grab active:cursor-grabbing',
        'text-white/35 hover:text-white/60 transition-colors',
        'select-none touch-none overflow-visible',
      )}
      title={concept}
      style={{ width: cellW }}
    >
      <div className="absolute inset-0 flex items-end justify-center pb-2">
        <div className="origin-bottom-left -rotate-45 translate-x-[30%] whitespace-nowrap">
          <GripVertical className="w-2.5 h-2.5 opacity-0 group-hover/th:opacity-40 transition-opacity inline-block mr-0.5 -translate-y-px" />
          <span className="text-[9px] font-medium">{concept}</span>
        </div>
      </div>
    </motion.th>
  );
}

/* ═══════════════════════════════════════════════════════════════════════════
   MAIN COMPONENT — Loua-style Dense Mosaic Heatmap
   ═══════════════════════════════════════════════════════════════════════════ */

export default function InstructorHeatmap() {
  const [sectionId, setSectionId] = useLastSection();
  const [rows, setRows] = useState([]);
  const [concepts, setConcepts] = useState([]);
  const [rawScores, setRawScores] = useState({});
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState(null);

  const [search, setSearch] = useState('');
  const [columnOrder, setColumnOrder] = useState([]);
  const [tooltip, setTooltip] = useState({ x: 0, y: 0, data: null, visible: false });
  const [hoveredRow, setHoveredRow] = useState(null);

  /* ── Data fetch ────────────────────────────────────────────────────── */
  useEffect(() => {
    let dead = false;
    const load = async () => {
      setLoading(true);
      setError(null);
      try {
        const res = await api.get(`/api/analytics/heatmap/${sectionId}`);
        const students = res.data?.students || [];
        const sr = res.data?.scores || {};
        const ca = res.data?.concepts || [];
        const names = {};
        for (const s of students) names[s.id] = s.name;

        const out = Object.keys(sr).map((id) => {
          const sc = {};
          for (const c of ca) {
            const raw = sr[id]?.[c]?.cds;
            sc[c] = raw == null ? null : (typeof raw === 'string' ? parseFloat(raw) : Number(raw));
          }
          return { studentId: id, name: names[id] || `Student #${id}`, scores: sc };
        });

        if (!dead) {
          setConcepts(ca);
          setRows(out);
          setRawScores(sr);
        }
      } catch (err) {
        if (!dead) {
          setConcepts([]);
          setRows([]);
          setRawScores({});
          setError(err.response?.data?.message || 'Failed to load heatmap data.');
        }
      } finally {
        if (!dead) setLoading(false);
      }
    };
    load();
    return () => { dead = true; };
  }, [sectionId]);

  /* ── Difficulty-driven column sorting ─────────────────────────────────
     Calculate mean CDS per concept across all students.
     Sort ascending: easiest concepts left, hardest right.
     ──────────────────────────────────────────────────────────────────── */
  const sortedConcepts = useMemo(() => {
    if (!concepts.length || !rows.length) return concepts;

    const meanCDS = {};
    for (const c of concepts) {
      const vals = rows
        .map(r => r.scores[c])
        .filter(v => v != null && v > 0)
        .map(v => Number(v));
      meanCDS[c] = vals.length ? vals.reduce((a, b) => a + b, 0) / vals.length : 0;
    }

    return [...concepts].sort((a, b) => meanCDS[a] - meanCDS[b]);
  }, [concepts, rows]);

  /* ── Initialize column order from sorted concepts ──────────────────── */
  useEffect(() => {
    if (sortedConcepts.length > 0 && columnOrder.length === 0) {
      setColumnOrder(sortedConcepts);
    }
  }, [sortedConcepts, columnOrder.length]);

  /* ── Column reorder via drag-swap ──────────────────────────────────── */
  const handleColumnSwap = useCallback((fromIdx, toIdx) => {
    setColumnOrder(prev => {
      const next = [...prev];
      const [moved] = next.splice(fromIdx, 1);
      next.splice(toIdx, 0, moved);
      return next;
    });
  }, []);

  /* ── Filtered rows by search ───────────────────────────────────────── */
  const filteredRows = useMemo(() => {
    if (!search.trim()) return rows;
    const q = search.toLowerCase();
    return rows.filter(r => r.name.toLowerCase().includes(q));
  }, [rows, search]);

  /* ── Tooltip handlers ──────────────────────────────────────────────── */
  const handleCellHover = useCallback((e, studentName, concept, cds, raw) => {
    setTooltip({
      x: e.clientX,
      y: e.clientY,
      data: { student: studentName, concept, cds, raw },
      visible: true,
    });
  }, []);

  const handleCellLeave = useCallback(() => {
    setTooltip(prev => ({ ...prev, visible: false }));
  }, []);

  /* ── Active columns list (draggable order) ─────────────────────────── */
  const activeColumns = columnOrder.length ? columnOrder : sortedConcepts;

  /* ════════════════════════════════════════════════════════════════════════
     RENDER
     ════════════════════════════════════════════════════════════════════════ */
  return (
    <div className="flex flex-col grow h-full w-full">
      {/* ── Page Header ─────────────────────────────────────────────── */}
      <div className="flex flex-col gap-3 sm:flex-row sm:items-end sm:justify-between mb-3">
        <div>
          <h1 className="text-xl font-bold tracking-tight text-white/90">
            Concept Difficulty Heatmap
          </h1>
          <p className="text-xs text-white/40">
            Dense mosaic — CDS struggle index across all concepts. Columns sorted easiest → hardest.
          </p>
        </div>
        <SectionFilter value={sectionId} onChange={setSectionId} />
      </div>

      {/* ── Glass Panel ─────────────────────────────────────────────── */}
      <div className="flex flex-col flex-1 min-h-0 w-full backdrop-blur-md bg-slate-900/40 border border-white/10 rounded-2xl overflow-hidden">
        {/* Toolbar */}
        <div className="flex items-center justify-between px-4 py-2.5 border-b border-white/5 flex-shrink-0">
          <span className="text-[11px] font-medium text-white/50 uppercase tracking-wider">
            Student × Concept — Struggle Index
          </span>
          <div className="flex items-center gap-3">
            <Input
              placeholder="Search student…"
              value={search}
              onChange={(e) => setSearch(e.target.value)}
              className="h-7 w-40 text-[11px] bg-white/5 border-white/10 text-white/80 placeholder:text-white/30"
            />
            <Legend />
          </div>
        </div>

        {/* Content */}
        <div className="flex flex-col flex-1 min-h-0">
          {loading ? (
            <div className="py-16 text-center text-white/40 text-sm">
              <div className="animate-spin h-5 w-5 border-2 border-white/10 border-t-white/40 rounded-full mx-auto mb-3" />
              Loading heatmap…
            </div>
          ) : error ? (
            <div className="py-16 text-center">
              <p className="text-sm text-rose-400 font-medium">{error}</p>
              <p className="text-xs text-white/30 mt-1">Try selecting a different section or refresh.</p>
            </div>
          ) : rows.length === 0 ? (
            <div className="py-16 text-center text-white/40 text-sm">
              <p>No heatmap data available for this selection.</p>
              <p className="text-xs mt-1 text-white/25">Students must have CDS scores computed to appear here.</p>
            </div>
          ) : (
            /* ── Dense Mosaic Grid ─────────────────────────────────── */
            <div className="flex-1 min-h-0 overflow-x-auto whitespace-nowrap scrollbar-thin px-2 pb-2 pt-1">
              <table
                className="border-collapse"
                style={{ tableLayout: 'fixed' }}
              >
                <thead className="sticky top-0 z-20">
                  <tr>
                    {/* Frozen student column header */}
                    <th
                      className="sticky left-0 z-30 bg-slate-950/90 backdrop-blur-md
                                 text-left px-2 py-1.5 text-[9px] font-bold uppercase tracking-wider
                                 text-white/40 border-b border-r border-white/5 h-28"
                      style={{ minWidth: 120, width: 120 }}
                    >
                      Student
                    </th>
                    {/* Flat draggable concept column headers — no nesting */}
                    {activeColumns.map((c, idx) => (
                      <DraggableColumnHeader
                        key={c}
                        concept={c}
                        index={idx}
                        onSwap={handleColumnSwap}
                        totalColumns={activeColumns.length}
                      />
                    ))}
                  </tr>
                </thead>

                <AnimatePresence mode="popLayout">
                  <motion.tbody
                    key={activeColumns.join(',')}
                    initial={{ opacity: 0 }}
                    animate={{ opacity: 1 }}
                    transition={{ duration: 0.3 }}
                  >
                    {filteredRows.map((row, ri) => (
                      <motion.tr
                        key={row.studentId}
                        initial={{ opacity: 0, y: 3 }}
                        animate={{ opacity: 1, y: 0 }}
                        transition={{ duration: 0.15, delay: Math.min(ri * 0.01, 0.3) }}
                        className={cn(
                          'transition-opacity duration-75',
                          hoveredRow === row.studentId
                            ? 'bg-white/[0.04]'
                            : hoveredRow
                              ? 'opacity-50'
                              : '',
                        )}
                        onMouseEnter={() => setHoveredRow(row.studentId)}
                        onMouseLeave={() => setHoveredRow(null)}
                      >
                        {/* Frozen student name cell */}
                        <td
                          className="sticky left-0 z-10 bg-slate-950/90 backdrop-blur-md
                                     px-2 py-0.5 font-medium whitespace-nowrap border-r border-white/5
                                     shadow-[3px_0_6px_-3px_rgba(0,0,0,0.4)]"
                          style={{ minWidth: 120, width: 120 }}
                        >
                          <span className="text-[10px] text-white/80 truncate block">{row.name}</span>
                        </td>

                        {/* Flat mosaic cells — every intersection filled */}
                        {activeColumns.map((c) => {
                          const val = row.scores[c] != null ? Number(row.scores[c]) : null;
                          const detail = rawScores[row.studentId]?.[c];
                          return (
                            <td key={c} className="p-0 m-0">
                              <Cell
                                cds={val}
                                onHover={(e) => handleCellHover(
                                  e,
                                  row.name,
                                  c,
                                  val != null ? Number(val).toFixed(2) : '—',
                                  detail ? { ner: detail.ner, nrs: detail.nrs, nts: detail.nts } : null,
                                )}
                                onLeave={handleCellLeave}
                              />
                            </td>
                          );
                        })}
                      </motion.tr>
                    ))}
                  </motion.tbody>
                </AnimatePresence>
              </table>
            </div>
          )}
        </div>
      </div>

      {/* ── Portal Tooltip Overlay ──────────────────────────────────── */}
      <PortalTooltip {...tooltip} />
    </div>
  );
}
