import { cn } from '@/lib/utils';

const TIERS = {
  low:      { label: 'Low',      color: '#22C55E', bg: 'bg-[#22C55E]/15',  text: 'text-[#22C55E]' },
  medium:   { label: 'Medium',   color: '#FACC15', bg: 'bg-[#FACC15]/15',  text: 'text-[#FACC15]' },
  high:     { label: 'High',     color: '#FB923C', bg: 'bg-[#FB923C]/15',  text: 'text-[#FB923C]' },
  critical: { label: 'Critical', color: '#EF4444', bg: 'bg-[#EF4444]/15',  text: 'text-[#EF4444]' },
};

export default function RiskBadge({ tier, className }) {
  const t = TIERS[tier] || TIERS.low;
  return (
    <span className={cn('inline-flex items-center gap-1 rounded-full px-2 py-0.5 text-xs font-semibold', t.bg, t.text, className)}>
      <span className="h-1.5 w-1.5 rounded-full" style={{ backgroundColor: t.color }} />
      {t.label}
    </span>
  );
}

export { TIERS };
