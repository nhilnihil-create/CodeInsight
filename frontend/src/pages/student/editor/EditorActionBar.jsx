import { Play, Send } from "lucide-react";
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
export default function EditorActionBar({ onRun, onSubmit, isRunning }) {
  return (
    <div
      className="h-14 bg-card border-t border-border flex items-center gap-2 px-3 shrink-0"
      role="toolbar"
      aria-label="Editor actions"
    >
      <Button
        variant="ghost"
        onClick={onRun}
        disabled={isRunning}
        className="flex-1 font-medium"
      >
        <Play className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
        Run
      </Button>
      {onSubmit ? (
        <Button onClick={onSubmit} className="flex-1 font-medium">
          <Send className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
          Submit
        </Button>
      ) : (
        <span className="flex-1 inline-flex items-center justify-center text-[10px] font-medium text-muted-foreground">
          Review Mode
        </span>
      )}
    </div>
  );
}
