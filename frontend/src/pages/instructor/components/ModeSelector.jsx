import { Brain, ClipboardCheck } from 'lucide-react';
import { cn } from '@/lib/utils';

/**
 * ModeSelector — Learning vs Assessment mode toggle.
 *
 * Props:
 *   value    — 'learning' | 'assessment'
 *   onChange — (mode: 'learning' | 'assessment') => void
 */
export default function ModeSelector({ value, onChange }) {
  return (
    <div className="space-y-3">
      <div>
        <h4 className="text-sm font-medium">Exercise Mode</h4>
        <p className="text-[10px] text-muted-foreground mt-0.5">
          Determines how student submissions are evaluated and tracked.
        </p>
      </div>

      <div className="grid grid-cols-2 gap-3">
        {/* Learning Mode */}
        <button
          type="button"
          onClick={() => onChange('learning')}
          className={cn(
            'flex flex-col items-start gap-2 p-4 rounded-lg border-2 transition-all text-left',
            value === 'learning'
              ? 'border-primary bg-primary/5'
              : 'border-border/60 hover:border-border hover:bg-muted/50'
          )}
        >
          <div className="flex items-center gap-2">
            <Brain className={cn('w-4 h-4', value === 'learning' ? 'text-primary' : 'text-muted-foreground')} />
            <span className={cn('text-sm font-semibold', value === 'learning' && 'text-primary')}>
              Learning Mode
            </span>
          </div>
          <ul className="text-[10px] text-muted-foreground space-y-0.5">
            <li>• Diagnostic — CDS analytics apply</li>
            <li>• Students can retry freely</li>
            <li>• Behavioral tracking enabled</li>
          </ul>
        </button>

        {/* Assessment Mode */}
        <button
          type="button"
          onClick={() => onChange('assessment')}
          className={cn(
            'flex flex-col items-start gap-2 p-4 rounded-lg border-2 transition-all text-left',
            value === 'assessment'
              ? 'border-primary bg-primary/5'
              : 'border-border/60 hover:border-border hover:bg-muted/50'
          )}
        >
          <div className="flex items-center gap-2">
            <ClipboardCheck className={cn('w-4 h-4', value === 'assessment' ? 'text-primary' : 'text-muted-foreground')} />
            <span className={cn('text-sm font-semibold', value === 'assessment' && 'text-primary')}>
              Assessment Mode
            </span>
          </div>
          <ul className="text-[10px] text-muted-foreground space-y-0.5">
            <li>• Graded — 4-Pillar Rubric scoring</li>
            <li>• Timed exam conditions</li>
            <li>• Standards &amp; integrity checks</li>
          </ul>
        </button>
      </div>
    </div>
  );
}
