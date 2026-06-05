import { cn } from '@/lib/utils';

const CDS_CLASSES = {
  low: 'cds-low',
  mod: 'cds-mod',
  high: 'cds-high',
  na: 'cds-na',
};

const TREND_ICONS = {
  up: '▲',
  down: '▼',
  flat: '—',
};

const TREND_CLASSES = {
  up: 'trend-up',
  down: 'trend-down',
  flat: 'trend-flat',
};

export default function CDSPillDelta({ value, delta, classification, trend, insight, className }) {
  const cdsClass = CDS_CLASSES[classification] || CDS_CLASSES.na;
  const trendIcon = TREND_ICONS[trend] || TREND_ICONS.flat;
  const trendClass = TREND_CLASSES[trend] || TREND_CLASSES.flat;

  return (
    <span className={cn('inline-flex items-center gap-1.5 rounded-full px-2.5 py-0.5 text-xs font-semibold font-mono', cdsClass, className)}>
      <span className="cds-value">{value.toFixed(2)}</span>
      {delta != null && (
        <span className={cn('flex items-center gap-0.5', trendClass)}>
          {trendIcon}
          {(delta >= 0 ? '+' : '')}{delta.toFixed(2)}
        </span>
      )}
      {classification && (
        <span className="ml-0.5 text-[10px] uppercase tracking-wider opacity-70">
          ({classification})
        </span>
      )}
    </span>
  );
}
