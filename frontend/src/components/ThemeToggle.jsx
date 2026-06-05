import { Sun, Moon } from 'lucide-react';
import { cn } from '@/lib/utils';
import { useTheme, VALID_THEMES } from '@/lib/theme.jsx';

/**
 * 2-button segmented theme toggle.
 *
 * Reads useTheme(); clicking a button calls setTheme(key). Renders in the sticky
 * top bar of Layout. The 2 icons (Sun = light, Moon = dark teal) are 4×4 lucide
 * icons inside 7×7 buttons. The active theme gets a primary ring.
 */
const OPTIONS = [
  { key: 'light', label: 'Light', icon: Sun },
  { key: 'dark', label: 'Dark teal', icon: Moon },
];

export default function ThemeToggle() {
  const { theme, setTheme } = useTheme();

  return (
    <div
      role="group"
      aria-label="Theme selector"
      className="flex items-center gap-1 rounded-md border border-border bg-card p-1"
    >
      {OPTIONS.map(({ key, label, icon: Icon }) => {
        const active = theme === key;
        return (
          <button
            key={key}
            type="button"
            aria-label={`Theme: ${label}`}
            aria-pressed={active}
            onClick={() => setTheme(key)}
            className={cn(
              'inline-flex h-7 w-7 items-center justify-center rounded transition-colors',
              active
                ? 'bg-primary text-primary-foreground ring-2 ring-primary ring-offset-1 ring-offset-card'
                : 'text-muted-foreground hover:bg-muted hover:text-foreground'
            )}
          >
            <Icon className="h-4 w-4" />
          </button>
        );
      })}
    </div>
  );
}

// re-export the option keys for tests / future consumers
export { VALID_THEMES };
