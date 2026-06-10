import { Slider } from '@/components/ui/slider';
import { cn } from '@/lib/utils';

const PILLARS = [
  { key: 'functional',   label: 'Functional Correctness', desc: '% of test cases passed', default: 40 },
  { key: 'efficiency',   label: 'Efficiency',             desc: 'Time vs class median',   default: 25 },
  { key: 'standards',    label: 'Standards & Style',      desc: 'Cppcheck warning penalty', default: 20 },
  { key: 'integrity',    label: 'Integrity',              desc: 'Behavioral flag penalty', default: 15 },
];

/**
 * RubricConfigurator — 4-pillar weight sliders for Assessment Mode.
 *
 * Props:
 *   value    — { functional, efficiency, standards, integrity } (numeric weights)
 *   onChange — (value: { [key]: number }) => void
 */
export default function RubricConfigurator({ value, onChange }) {
  const weights = value || { functional: 40, efficiency: 25, standards: 20, integrity: 15 };
  const total = Object.values(weights).reduce((a, b) => a + (b || 0), 0);
  const isValid = total === 100;

  function update(key, val) {
    // val from slider is [number], take first element
    const num = Array.isArray(val) ? val[0] : val;
    onChange({ ...weights, [key]: num });
  }

  return (
    <div className="space-y-3">
      <div>
        <h4 className="text-sm font-medium">Rubric Weights</h4>
        <p className="text-[10px] text-muted-foreground mt-0.5">
          Configure how the 4 pillars contribute to the final grade. Must total 100%.
        </p>
      </div>

      <div className="space-y-4">
        {PILLARS.map(p => (
          <div key={p.key} className="space-y-1">
            <div className="flex items-center justify-between">
              <div>
                <span className="text-xs font-medium">{p.label}</span>
                <p className="text-[10px] text-muted-foreground">{p.desc}</p>
              </div>
              <span className="text-xs font-mono font-semibold tabular-nums">
                {weights[p.key] || 0}%
              </span>
            </div>
            <Slider
              value={[weights[p.key] || 0]}
              onValueChange={(v) => update(p.key, v)}
              min={0}
              max={100}
              step={5}
            />
          </div>
        ))}
      </div>

      {/* Total indicator */}
      <div className={cn(
        'flex items-center justify-between p-2 rounded-lg border text-xs font-medium',
        isValid
          ? 'border-green-500/30 bg-green-500/5 text-green-700'
          : 'border-destructive/30 bg-destructive/5 text-destructive'
      )}>
        <span>Total</span>
        <span className="font-mono">
          {total}% {isValid ? '✓' : `(must equal 100%)`}
        </span>
      </div>
    </div>
  );
}
