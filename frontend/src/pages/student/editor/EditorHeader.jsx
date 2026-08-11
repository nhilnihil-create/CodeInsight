import { Play, Send, Clock, ChevronLeft } from "lucide-react";
import { Button } from "@/components/ui/button";
import { cn } from "@/lib/utils";

/**
 * EditorHeader
 * Sticky h-14 (56px) header bar for the code editor.
 *
 *   [Back]  Title + concept chips  |  N / M passing  |  Timer · Run · Submit
 *
 * Emerald-accented glassmorphic theme.
 */
const MAX_CHIPS = 3;
const VISIBLE_CHIPS = 2;

export default function EditorHeader({
  title,
  concepts = [],
  testResults,
  timeLimitMinutes,
  activeElapsedSeconds = 0,
  isRunning = false,
  isReviewMode = false,
  onRun,
  onSubmit,
  onBack,
}) {
  const passing = testResults?.passing ?? 0;
  const total = testResults?.total ?? 0;

  const timeLimitSeconds = timeLimitMinutes ? timeLimitMinutes * 60 : 0;
  const countdownSeconds = timeLimitSeconds > 0
    ? Math.max(0, timeLimitSeconds - activeElapsedSeconds)
    : 0;

  const visibleConcepts = concepts.slice(0, VISIBLE_CHIPS);
  const overflow = Math.max(0, concepts.length - VISIBLE_CHIPS);
  const showOverflowChip = concepts.length > MAX_CHIPS;

  return (
    <header
      className="sticky top-0 z-20 flex items-center gap-3 h-14 min-h-[56px] bg-[#0D1220]/80 backdrop-blur-md border-b border-white/[0.05] shadow-xs px-6 shrink-0"
    >
      {/* Back */}
      {onBack ? (
        <Button
          variant="ghost"
          size="icon"
          onClick={onBack}
          aria-label="Back to exercises"
          title="Back to exercises"
          className="h-8 w-8 shrink-0 hover:bg-white/[0.04]"
        >
          <ChevronLeft className="h-4 w-4" strokeWidth={1.75} aria-hidden="true" />
        </Button>
      ) : null}

      {/* Left: title + concepts */}
      <div className="flex items-center gap-2 min-w-0 flex-1">
        <h1 className="text-sm font-semibold tracking-tight truncate text-white">{title}</h1>
        {concepts.length > 0 ? (
          <div className="hidden sm:flex items-center gap-1.5 min-w-0">
            {visibleConcepts.map((c) => (
              <span
                key={c.name}
                title={c.name}
                className="shrink-0 inline-flex items-center px-2.5 py-0.5 rounded-full text-xs font-medium bg-emerald-500/10 text-emerald-400 border border-emerald-500/20"
              >
                {c.name}
              </span>
            ))}
            {showOverflowChip ? (
              <span
                title={concepts.slice(VISIBLE_CHIPS).map((c) => c.name).join(", ")}
                className="shrink-0 inline-flex items-center px-2.5 py-0.5 rounded-full text-xs font-medium bg-emerald-500/10 text-emerald-400 border border-emerald-500/20"
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
              ? "bg-emerald-500/10 text-emerald-400 border-emerald-500/20"
              : "bg-white/[0.04] text-muted-foreground border-white/[0.06]",
          )}
          aria-label={`${passing} of ${total} tests passing`}
        >
          {passing} / {total} passing
        </span>
      </div>

      {/* Right: timer · Run · Submit */}
      <div className="flex items-center gap-1.5 sm:gap-2 shrink-0">
        {/* Timer countdown (hidden in review mode — the exercise is already done) */}
        {!isReviewMode && timeLimitSeconds > 0 && countdownSeconds > 0 && (
          <div className={cn(
            "hidden sm:flex items-center gap-1.5 text-sm font-mono tabular-nums",
            countdownSeconds <= 60 ? "text-destructive" : "text-muted-foreground",
          )}>
            <Clock className="h-3.5 w-3.5" strokeWidth={1.5} aria-hidden="true" />
            <span className="sr-only">Time remaining:</span>
            <span aria-hidden="true">{formatTime(countdownSeconds)}</span>
          </div>
        )}

        <button
          type="button"
          onClick={onRun}
          disabled={isRunning || isReviewMode}
          className="inline-flex items-center gap-1.5 h-8 px-3 rounded-lg text-xs font-semibold bg-gradient-to-r from-emerald-400 to-teal-500 text-slate-950 shadow-[0_0_15px_rgba(16,185,129,0.25)] hover:shadow-[0_0_20px_rgba(16,185,129,0.35)] hover:brightness-110 transition-all disabled:opacity-50 disabled:cursor-not-allowed"
        >
          <Play className="h-3.5 w-3.5" strokeWidth={2} />
          Run
          <span className="ml-1 hidden sm:inline-flex items-center gap-0.5 text-[10px] font-mono opacity-70">
            <kbd className="inline-flex items-center justify-center min-w-4 h-4 px-1 rounded border border-slate-950/20 bg-white/20">⌘</kbd>
            <kbd className="inline-flex items-center justify-center min-w-4 h-4 px-1 rounded border border-slate-950/20 bg-white/20">↵</kbd>
          </span>
        </button>
        {isReviewMode ? (
          <span className="inline-flex items-center gap-1 h-7 px-2.5 rounded-md bg-white/[0.04] text-[10px] font-medium text-muted-foreground border border-white/[0.06]">
            Review Mode
          </span>
        ) : (
          <button
            type="button"
            onClick={onSubmit}
            className="inline-flex items-center gap-1.5 h-8 px-4 rounded-lg text-xs font-semibold bg-gradient-to-r from-emerald-500 to-teal-600 text-white shadow-[0_0_15px_rgba(16,185,129,0.2)] hover:shadow-[0_0_20px_rgba(16,185,129,0.3)] hover:brightness-110 transition-all"
          >
            Submit
            <Send className="h-3.5 w-3.5" strokeWidth={1.5} />
          </button>
        )}
      </div>
    </header>
  );
}

function formatTime(seconds) {
  if (!seconds) return "0:00";
  const m = Math.floor(seconds / 60);
  const s = seconds % 60;
  return `${m}:${String(s).padStart(2, "0")}`;
}
