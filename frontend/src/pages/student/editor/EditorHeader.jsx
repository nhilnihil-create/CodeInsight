import { Play, Send, Clock, ChevronLeft, Sun, Moon, ChevronDown } from "lucide-react";
import { Button } from "@/components/ui/button";
import { useTheme } from "@/lib/theme";
import { cn } from "@/lib/utils";

/**
 * EditorHeader
 * Sticky h-12 header bar for the code editor.
 *
 *   [Back]  Title + concept chips  |  N / M passing  |  Timer · Run · Submit · Language · Theme
 *
 * Tokens only.
 */
const MAX_CHIPS = 3;
const VISIBLE_CHIPS = 2;

export default function EditorHeader({
  title,
  concepts = [],
  testResults,
  timerSeconds = 0,
  isRunning = false,
  onRun,
  onSubmit,
  onBack,
  language = "C++",
  languageOptions = [],
  onLanguageChange,
}) {
  const passing = testResults?.passing ?? 0;
  const total = testResults?.total ?? 0;
  const { theme, setTheme } = useTheme();

  const visibleConcepts = concepts.slice(0, VISIBLE_CHIPS);
  const overflow = Math.max(0, concepts.length - VISIBLE_CHIPS);
  const showOverflowChip = concepts.length > MAX_CHIPS;

  return (
    <header
      className="sticky top-0 z-20 flex items-center gap-3 h-12 bg-card border-b border-border shadow-xs px-3 sm:px-4"
    >
      {/* Back */}
      {onBack ? (
        <Button
          variant="ghost"
          size="icon"
          onClick={onBack}
          aria-label="Back to exercises"
          title="Back to exercises"
          className="h-8 w-8 shrink-0"
        >
          <ChevronLeft className="h-4 w-4" strokeWidth={1.75} aria-hidden="true" />
        </Button>
      ) : null}

      {/* Left: title + concepts */}
      <div className="flex items-center gap-2 min-w-0 flex-1">
        <h1 className="text-sm font-semibold tracking-tight truncate">{title}</h1>
        {concepts.length > 0 ? (
          <div className="hidden sm:flex items-center gap-1.5 min-w-0">
            {visibleConcepts.map((c) => (
              <span
                key={c.name}
                title={c.name}
                className="shrink-0 inline-flex items-center px-2 py-0.5 rounded-full text-xs font-medium bg-primary/10 text-primary border border-primary/20"
              >
                {c.name}
              </span>
            ))}
            {showOverflowChip ? (
              <span
                title={concepts.slice(VISIBLE_CHIPS).map((c) => c.name).join(", ")}
                className="shrink-0 inline-flex items-center px-2 py-0.5 rounded-full text-xs font-medium bg-primary/10 text-primary border border-primary/20"
              >
                +{overflow} more
              </span>
            ) : null}
          </div>
        ) : null}
      </div>

      {/* Center: test status */}
      <div className="hidden md:flex items-center gap-2 shrink-0">
        <span
          className={cn(
            "text-xs font-mono tabular-nums px-2 py-0.5 rounded-full border",
            passing === total && total > 0
              ? "bg-success/10 text-success border-success/20"
              : "bg-muted/40 text-muted-foreground border-border",
          )}
          aria-label={`${passing} of ${total} tests passing`}
        >
          {passing} / {total} passing
        </span>
      </div>

      {/* Right: timer · Run · Submit · Language · Theme */}
      <div className="flex items-center gap-1.5 sm:gap-2 shrink-0">
        <div className="hidden sm:flex items-center gap-1.5 text-sm font-mono tabular-nums text-muted-foreground">
          <Clock className="h-3.5 w-3.5" strokeWidth={1.5} aria-hidden="true" />
          <span className="sr-only">Time remaining:</span>
          <span aria-hidden="true">{formatTime(timerSeconds)}</span>
        </div>

        {/* Language selector — simple <select> styled as a pill. */}
        {languageOptions.length > 0 && onLanguageChange ? (
          <label className="hidden md:inline-flex items-center gap-1 h-7 px-2 rounded-md border border-border bg-card text-xs font-medium text-muted-foreground hover:text-foreground hover:bg-muted transition-colors">
            <span className="sr-only">Language</span>
            <select
              value={language}
              onChange={(e) => onLanguageChange(e.target.value)}
              className="appearance-none bg-transparent text-foreground pr-3 focus:outline-none cursor-pointer"
              style={{ backgroundImage: "none" }}
            >
              {languageOptions.map((l) => (
                <option key={l.value} value={l.value}>
                  {l.label}
                </option>
              ))}
            </select>
            <ChevronDown className="h-3 w-3 -ml-2 pointer-events-none" strokeWidth={1.75} aria-hidden="true" />
          </label>
        ) : null}

        {/* Theme toggle — only one button (just flips). Hidden on small
            screens to save space; the global ThemeToggle is reachable
            from other pages. */}
        <button
          type="button"
          onClick={() => setTheme(theme === "dark" ? "light" : "dark")}
          aria-label={theme === "dark" ? "Switch to light theme" : "Switch to dark theme"}
          title={theme === "dark" ? "Switch to light theme" : "Switch to dark theme"}
          className="hidden sm:inline-flex h-7 w-7 items-center justify-center rounded-md border border-border bg-card text-muted-foreground hover:text-foreground hover:bg-muted transition-colors"
        >
          {theme === "dark" ? (
            <Sun className="h-3.5 w-3.5" strokeWidth={1.75} aria-hidden="true" />
          ) : (
            <Moon className="h-3.5 w-3.5" strokeWidth={1.75} aria-hidden="true" />
          )}
        </button>

        <Button
          variant="ghost"
          size="sm"
          onClick={onRun}
          disabled={isRunning}
          className="font-medium"
        >
          <Play className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
          Run
          <KbdHint keys={["⌘", "↵"]} />
        </Button>
        <Button variant="default" size="sm" onClick={onSubmit} className="gap-1.5 px-4">
          Submit
          <Send className="h-3.5 w-3.5" strokeWidth={1.5} />
        </Button>
      </div>
    </header>
  );
}

function KbdHint({ keys }) {
  return (
    <span className="ml-1.5 hidden sm:inline-flex items-center gap-0.5 text-[10px] font-mono text-muted-foreground">
      {keys.map((k, i) => (
        <kbd
          key={i}
          className="inline-flex items-center justify-center min-w-4 h-4 px-1 rounded border border-border bg-muted/60 text-muted-foreground"
        >
          {k}
        </kbd>
      ))}
    </span>
  );
}

function formatTime(seconds) {
  if (!seconds) return "0:00";
  const m = Math.floor(seconds / 60);
  const s = seconds % 60;
  return `${m}:${String(s).padStart(2, "0")}`;
}
