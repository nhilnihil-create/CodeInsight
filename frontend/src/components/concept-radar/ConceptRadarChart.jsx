import {
  ResponsiveContainer,
  RadarChart,
  PolarGrid,
  PolarAngleAxis,
  PolarRadiusAxis,
  Radar,
  Tooltip,
} from 'recharts';

const RADAR_MARGIN = { top: 8, right: 24, bottom: 8, left: 24 };

const CustomTooltip = ({ active, payload }) => {
  if (!active || !payload?.length) return null;
  const d = payload[0].payload;
  return (
    <div className="backdrop-blur-xl bg-white/[0.06] border border-white/[0.1] rounded-lg px-4 py-3 shadow-xl min-w-[180px]">
      <p className="text-sm font-semibold text-foreground mb-2">{d.subject}</p>
      <div className="space-y-1">
        <div className="flex items-center justify-between gap-4">
          <span className="text-[11px] text-muted-foreground">Mastery</span>
          <span className="text-xs font-semibold font-mono tabular-nums text-emerald-400">
            {Number(d.mastery) || 0}%
          </span>
        </div>
        {d.ner != null && (
          <div className="flex items-center justify-between gap-4">
            <span className="text-[11px] text-muted-foreground">NER</span>
            <span className="text-xs font-mono tabular-nums text-foreground/80">
              {(Number(d.ner) || 0).toFixed(2)}
            </span>
          </div>
        )}
        {d.nrs != null && (
          <div className="flex items-center justify-between gap-4">
            <span className="text-[11px] text-muted-foreground">NRS</span>
            <span className="text-xs font-mono tabular-nums text-foreground/80">
              {(Number(d.nrs) || 0).toFixed(2)}
            </span>
          </div>
        )}
        {d.nts != null && (
          <div className="flex items-center justify-between gap-4">
            <span className="text-[11px] text-muted-foreground">NTS</span>
            <span className="text-xs font-mono tabular-nums text-foreground/80">
              {(Number(d.nts) || 0).toFixed(2)}
            </span>
          </div>
        )}
        <div className="flex items-center justify-between gap-4 pt-1 border-t border-white/[0.06] mt-1">
          <span className="text-[11px] text-muted-foreground">Attempts</span>
          <span className="text-xs font-mono tabular-nums text-foreground/80">
            {d.attempts || 0}
          </span>
        </div>
      </div>
    </div>
  );
};

export default function ConceptRadarChart({ data = [] }) {
  const hasData = data.some((d) => (Number(d.mastery) || 0) > 0);
  return (
    <div className="relative w-full h-full">
      <svg width="0" height="0" className="absolute">
        <defs>
          <linearGradient id="emeraldTealGradient" x1="0%" y1="0%" x2="100%" y2="100%">
            <stop offset="0%" stopColor="#10B981" stopOpacity={1} />
            <stop offset="100%" stopColor="#14B8A6" stopOpacity={1} />
          </linearGradient>
          <filter id="radarGlow">
            <feGaussianBlur stdDeviation="3" result="blur" />
            <feMerge>
              <feMergeNode in="blur" />
              <feMergeNode in="SourceGraphic" />
            </feMerge>
          </filter>
        </defs>
      </svg>
      <ResponsiveContainer width="100%" height="100%">
        <RadarChart data={data} margin={RADAR_MARGIN}>
          <PolarGrid
            stroke="rgba(255, 255, 255, 0.05)"
            strokeWidth={1}
          />
          <PolarAngleAxis
            dataKey="subject"
            tick={{
              fill: 'hsl(var(--muted-foreground))',
              fontSize: 10,
              fontWeight: 500,
            }}
            stroke="rgba(255,255,255,0.04)"
          />
          <PolarRadiusAxis
            domain={[0, 100]}
            tick={false}
            axisLine={false}
            stroke="rgba(255,255,255,0.03)"
          />
          <Tooltip content={<CustomTooltip />} cursor={{ stroke: 'rgba(255,255,255,0.1)', strokeWidth: 1 }} />
          <Radar
            name="Mastery"
            dataKey="mastery"
            fill="url(#emeraldTealGradient)"
            fillOpacity={0.15}
            stroke="#10B981"
            strokeWidth={2}
            strokeLinejoin="round"
            dot={{
              r: 3,
              fill: '#10B981',
              stroke: 'rgba(16, 185, 129, 0.3)',
              strokeWidth: 2,
            }}
            activeDot={{
              r: 5,
              fill: '#10B981',
              stroke: '#10B981',
              strokeWidth: 2,
              filter: 'url(#radarGlow)',
            }}
          />
        </RadarChart>
      </ResponsiveContainer>
      {!hasData && data.length > 0 && (
        <div className="absolute inset-0 flex items-center justify-center pointer-events-none">
          <span className="text-[11px] text-muted-foreground/50 font-mono tracking-wider uppercase">
            No submissions yet
          </span>
        </div>
      )}
    </div>
  );
}
