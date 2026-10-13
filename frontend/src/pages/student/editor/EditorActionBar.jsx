import { Play, Send, Loader2 } from "lucide-react";
import { Button } from "@/components/ui/button";

/**
 * EditorActionBar
 * Mobile fixed-bottom action bar (h-14). Always visible on < lg.
 *
 * Layout  bg-card border-t border-border flex items-center gap-2 px-3
 *         Run (ghost, flex-1)  ·  Submit (primary, flex-1)
 *
 * Tokens only.
 */
export default function EditorActionBar({ onRun, onSubmit, isRunning, runningKind = null, isReviewMode = false, isClosed = false }) {
  const isRunningRun = isRunning && runningKind !== "submit";
  const isRunningSubmit = isRunning && runningKind === "submit";
  return (
    <div
      className="min-h-14 bg-card border-t border-border flex items-center gap-2 px-3 shrink-0 pb-[env(safe-area-inset-bottom)]"
      role="toolbar"
      aria-label="Editor actions"
    >
      <Button
        variant="ghost"
        onClick={onRun}
        disabled={isRunning || isReviewMode}
        className="flex-1 font-medium cursor-pointer disabled:cursor-not-allowed"
        aria-busy={isRunningRun}
      >
        {isRunningRun ? (
          <Loader2 className="h-3.5 w-3.5 mr-1.5 animate-spin" strokeWidth={1.5} aria-hidden="true" />
        ) : (
          <Play className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} aria-hidden="true" />
        )}
        {isRunningRun ? "Running…" : "Run"}
      </Button>
      {onSubmit ? (
        <Button
          onClick={onSubmit}
          disabled={isRunning}
          className="flex-1 font-medium cursor-pointer disabled:cursor-not-allowed"
          aria-busy={isRunningSubmit}
        >
          {isRunningSubmit ? (
            <Loader2 className="h-3.5 w-3.5 mr-1.5 animate-spin" strokeWidth={1.5} aria-hidden="true" />
          ) : (
            <Send className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} aria-hidden="true" />
          )}
          {isRunningSubmit ? "Submitting…" : "Submit"}
        </Button>
      ) : (
        <span className="flex-1 inline-flex items-center justify-center text-[10px] font-medium text-muted-foreground">
          {isClosed ? '🔒 Closed — submissions disabled' : 'Review Mode'}
        </span>
      )}
    </div>
  );
}
