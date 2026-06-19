import { useEffect, useState, useMemo } from 'react';
import { useParams, Link } from 'react-router-dom';
import { motion, AnimatePresence } from 'framer-motion';
import { Tags, ArrowLeft, Loader2, AlertTriangle } from 'lucide-react';
import { Button } from '@/components/ui/button';
import api from '@/services/api';
import { cn } from '@/lib/utils';

/* ── Knowledge Area Labels ─────────────────────────────────────────────── */

const KA_LABELS = {
  'SDF-FPC': 'Procedural Fundamentals',
  'SDF-PMD': 'Program Design & Logic',
  'SDF-FDS': 'Data Structures & Memory',
  'SDF-OOP': 'Object-Oriented Paradigms',
};

/* ── 5-Tier CDS Color Gradient ─────────────────────────────────────────── */

const CDS_TIERS = [
  { min: -1,  max: -1,  label: 'No Data',
    cell: 'bg-slate-900/60 text-slate-600/40 border border-white/5' },
  { min: 0.00, max: 0.00, label: 'No Data',
    cell: 'bg-slate-900/60 text-slate-600/40 border border-white/5' },
  { min: 0.01, max: 15, label: 'Very Low',
    cell: 'bg-emerald-950/40 text-emerald-500/70 border border-emerald-500/10' },
  { min: 16, max: 35, label: 'Low',
    cell: 'bg-emerald-500/20 text-emerald-400 border border-emerald-500/25' },
  { min: 36, max: 55, label: 'Moderate',
    cell: 'bg-amber-500/20 text-amber-400 border border-amber-500/25' },
  { min: 56, max: 75, label: 'High',
    cell: 'bg-orange-500/25 text-orange-400 border border-orange-500/30' },
  { min: 76, max: 100, label: 'Very High',
    cell: 'bg-rose-600/35 text-rose-400 border border-rose-500/40 font-bold shadow-[inset_0_0_12px_rgba(244,63,94,0.15)]' },
];

function cdsCellClass(cds) {
  const v = Number(cds) || 0;
  for (const t of CDS_TIERS) {
    if (v >= t.min && v <= t.max) return t.cell;
  }
  return CDS_TIERS[CDS_TIERS.length - 1].cell;
}

/* ── Knowledge Area Picker ─────────────────────────────────────────────── */

function KnowledgeAreaPicker({ areas, active, onChange }) {
  if (areas.length <= 1) return null;
  return (
    <div className="backdrop-blur-md bg-slate-900/40 border border-white/10 p-1.5 rounded-xl flex gap-1.5 w-max mb-5">
      {areas.map(([ka, label]) => (
        <button
          key={ka}
          onClick={() => onChange(ka)}
          className={cn(
            'relative px-3 py-1.5 rounded-lg text-[11px] font-medium tracking-wide transition-colors duration-200 z-10 select-none',
            active === ka ? 'text-white/90' : 'text-white/35 hover:text-white/55',
          )}
        >
          {active === ka && (
            <motion.div
              layoutId="customHeatmapTab"
              className="absolute inset-0 bg-white/10 border border-white/10 rounded-lg"
              transition={{ type: 'spring', stiffness: 400, damping: 30 }}
            />
          )}
          <span className="relative z-10">{label}</span>
        </button>
      ))}
    </div>
  );
}

/* ── Main Component ────────────────────────────────────────────────────── */

export default function InstructorCustomHeatmap() {
  const { sectionId } = useParams();
  const [heatmapData, setHeatmapData] = useState({ columns: [], rows: [] });
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [activeKA, setActiveKA] = useState(null);

  useEffect(() => {
    if (!sectionId) return;
    setLoading(true);
    setError(null);
    api.get(`/api/analytics/custom-heatmap/${sectionId}`)
      .then(({ data }) => {
        setHeatmapData(data);
        setLoading(false);
      })
      .catch((err) => {
        setError(err.response?.data?.error || 'Failed to load heatmap data');
        setLoading(false);
      });
  }, [sectionId]);

  /* Derive available knowledge areas from columns */
  const availableAreas = useMemo(() => {
    const kaSet = new Set();
    for (const col of heatmapData.columns) {
      if (col.knowledgeArea) kaSet.add(col.knowledgeArea);
    }
    const areas = [...kaSet].map(ka => [ka, KA_LABELS[ka] || ka]);
    return areas;
  }, [heatmapData.columns]);

  /* Auto-select first KA when data loads */
  useEffect(() => {
    if (availableAreas.length > 0 && (activeKA == null || !availableAreas.some(([ka]) => ka === activeKA))) {
      setActiveKA(availableAreas[0][0]);
    }
  }, [availableAreas, activeKA]);

  /* Filter columns by active KA */
  const filteredColumns = useMemo(() => {
    if (!activeKA) return heatmapData.columns;
    return heatmapData.columns.filter(col => col.knowledgeArea === activeKA);
  }, [heatmapData.columns, activeKA]);

  if (loading) {
    return (
      <div className="flex items-center justify-center min-h-[400px]">
        <div className="flex items-center gap-3 text-muted-foreground">
          <Loader2 className="h-5 w-5 animate-spin" />
          <span className="text-sm">Loading custom tag matrix...</span>
        </div>
      </div>
    );
  }

  if (error) {
    return (
      <div className="flex items-center gap-3 rounded-lg border border-destructive/30 bg-destructive/5 px-4 py-3">
        <AlertTriangle className="h-4 w-4 text-destructive shrink-0" />
        <p className="text-sm text-destructive flex-1">{error}</p>
        <Button variant="outline" size="sm" onClick={() => window.location.reload()}>
          Retry
        </Button>
      </div>
    );
  }

  const hasTags = filteredColumns.length > 0;

  return (
    <div className="w-full space-y-6">
      <div className="flex items-center justify-between">
        <div className="flex items-center gap-3">
          <Link to={`/instructor/sections/${sectionId}`}>
            <Button variant="ghost" size="icon" className="h-8 w-8">
              <ArrowLeft className="h-4 w-4" />
            </Button>
          </Link>
          <div>
            <h1 className="text-xl font-semibold text-foreground tracking-wide">
              Custom Concept Difficulty Matrix
            </h1>
            <p className="text-xs text-muted-foreground mt-0.5">
              Dynamically tracking pedagogical concepts aggregated across mapped programming exercises.
            </p>
          </div>
        </div>
        <Button variant="outline" size="sm" className="gap-2" asChild>
          <Link to={`/instructor/sections/${sectionId}/custom-tags`}>
            <Tags className="h-3.5 w-3.5" />
            Configure Tag Columns
          </Link>
        </Button>
      </div>

      {/* Knowledge Area Picker */}
      <KnowledgeAreaPicker
        areas={availableAreas}
        active={activeKA}
        onChange={setActiveKA}
      />

      {!hasTags ? (
        <div className="flex flex-col items-center justify-center py-20 rounded-xl border border-dashed border-border bg-card/30">
          <Tags className="h-10 w-10 text-muted-foreground/40 mb-4" />
          <p className="text-sm font-medium text-muted-foreground mb-1">
            {activeKA ? 'No custom tags in this Knowledge Area' : 'No custom tag columns configured'}
          </p>
          <p className="text-xs text-muted-foreground/60 mb-4">
            Create custom tags to organize exercises and visualize student CDS by pedagogical concept.
          </p>
          <Button variant="outline" size="sm" asChild>
            <Link to={`/instructor/sections/${sectionId}/custom-tags`}>
              Configure Custom Tags
            </Link>
          </Button>
        </div>
      ) : (
        <div className="w-full overflow-x-auto rounded-xl border border-border bg-card shadow-sm">
          <AnimatePresence mode="wait">
            <motion.div
              key={activeKA}
              initial={{ opacity: 0, y: 4 }}
              animate={{ opacity: 1, y: 0 }}
              exit={{ opacity: 0, y: -4 }}
              transition={{ duration: 0.2 }}
            >
              <table className="min-w-full table-fixed divide-y divide-border">
                <thead>
                  <tr>
                    <th className="w-[200px] text-left text-xs font-semibold uppercase tracking-wider text-muted-foreground p-4 sticky left-0 bg-card z-10">
                      Student
                    </th>
                    {filteredColumns.map((col) => (
                      <th
                        key={col.id}
                        className="text-center text-xs font-semibold uppercase tracking-wider text-muted-foreground p-4"
                      >
                        <span className="px-2.5 py-1 rounded-md bg-muted/50 border border-border">
                          {col.label}
                        </span>
                      </th>
                    ))}
                  </tr>
                </thead>
                <tbody className="divide-y divide-border text-sm">
                  {heatmapData.rows.map((row) => (
                    <tr key={row.studentId} className="hover:bg-muted/20 transition-colors duration-150">
                      <td className="font-medium text-foreground/90 p-4 sticky left-0 bg-card border-r border-border">
                        {row.studentName}
                      </td>
                      {filteredColumns.map((col) => {
                        const cell = row.metrics[col.id] || { cds: 0, submissions: 0 };
                        return (
                          <td key={col.id} className="p-3 text-center">
                            <div className={cn(
                              'mx-auto max-w-[120px] py-2 px-3 rounded-lg text-xs',
                              cdsCellClass(cell.cds),
                            )}>
                              <div className="font-mono text-sm">{cell.cds}%</div>
                              <div className="text-[10px] opacity-60 mt-0.5">{cell.submissions} subs</div>
                            </div>
                          </td>
                        );
                      })}
                    </tr>
                  ))}
                </tbody>
              </table>
            </motion.div>
          </AnimatePresence>
        </div>
      )}

      <div className="flex items-center gap-4 text-xs text-muted-foreground/60">
        <span className="flex items-center gap-1.5">
          <span className="inline-block w-3 h-3 rounded-sm bg-slate-900/60 border border-white/5" />
          No Data
        </span>
        <span className="flex items-center gap-1.5">
          <span className="inline-block w-3 h-3 rounded-sm bg-emerald-950/40 border border-emerald-500/10" />
          Very Low
        </span>
        <span className="flex items-center gap-1.5">
          <span className="inline-block w-3 h-3 rounded-sm bg-emerald-500/20 border border-emerald-500/25" />
          Low
        </span>
        <span className="flex items-center gap-1.5">
          <span className="inline-block w-3 h-3 rounded-sm bg-amber-500/20 border border-amber-500/25" />
          Moderate
        </span>
        <span className="flex items-center gap-1.5">
          <span className="inline-block w-3 h-3 rounded-sm bg-orange-500/25 border border-orange-500/30" />
          High
        </span>
        <span className="flex items-center gap-1.5">
          <span className="inline-block w-3 h-3 rounded-sm bg-rose-600/35 border border-rose-500/40" />
          Very High
        </span>
      </div>
    </div>
  );
}
