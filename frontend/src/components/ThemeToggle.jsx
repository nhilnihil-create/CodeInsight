import { Sun, Moon, Monitor } from 'lucide-react';
import { useTheme, LIGHT_THEME, DARK_THEME, SYSTEM_THEME } from '@/lib/theme';
import { cn } from '@/lib/utils';
import {
  Tooltip,
  TooltipTrigger,
  TooltipContent,
  TooltipArrow,
  TooltipPortal,
} from '@/components/ui/tooltip';

const OPTIONS = [
  { mode: LIGHT_THEME, label: 'Light', icon: Sun },
  { mode: DARK_THEME, label: 'Dark', icon: Moon },
  { mode: SYSTEM_THEME, label: 'System', icon: Monitor },
];

function labelFor(mode) {
  return OPTIONS.find((o) => o.mode === mode)?.label ?? 'System';
}

/**
 * ThemeToggle — Light / Dark / System segmented control.
 * Expanded variant: three-button segmented picker. Collapsed (icon-only)
 * variant: single button cycling Light → Dark → System with a tooltip.
 * Styling is token-based so it renders correctly in both themes.
 */
export default function ThemeToggle({ collapsed = false, className }) {
  const { mode, setTheme } = useTheme();

  if (collapsed) {
    const idx = OPTIONS.findIndex((o) => o.mode === mode);
    const next = OPTIONS[(idx + 1) % OPTIONS.length];
    const Current = OPTIONS[idx]?.icon ?? Monitor;
    return (
      <Tooltip>
        <TooltipTrigger asChild>
          <button
            type="button"
            onClick={() => setTheme(next.mode)}
            aria-label={`Theme: ${labelFor(mode)}. Switch to ${next.label}`}
            className={cn(
              'flex h-10 w-10 items-center justify-center rounded-xl text-muted-foreground',
              'transition-colors hover:bg-accent hover:text-accent-foreground',
              className
            )}
          >
            <Current className="h-[18px] w-[18px]" />
          </button>
        </TooltipTrigger>
        <TooltipPortal>
          <TooltipContent side="right" sideOffset={12}>
            Theme: {labelFor(mode)} (click for {next.label})
            <TooltipArrow />
          </TooltipContent>
        </TooltipPortal>
      </Tooltip>
    );
  }

  return (
    <div
      role="group"
      aria-label="Color theme"
      className={cn(
        'grid grid-cols-3 gap-0.5 rounded-xl border border-border bg-muted/40 p-0.5',
        className
      )}
    >
      {OPTIONS.map(({ mode: value, label, icon: Icon }) => {
        const active = mode === value;
        return (
          <button
            key={value}
            type="button"
            onClick={() => setTheme(value)}
            aria-pressed={active}
            title={`${label} theme`}
            className={cn(
              'flex items-center justify-center gap-1 rounded-lg px-2 py-1.5 text-[11px] font-medium transition-colors',
              active
                ? 'bg-card text-foreground shadow-sm border border-border'
                : 'text-muted-foreground hover:text-foreground'
            )}
          >
            <Icon className="h-3.5 w-3.5" />
            {label}
          </button>
        );
      })}
    </div>
  );
}
