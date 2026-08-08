import { Sheet, SheetContent, SheetClose } from "./sheet";
import { Button } from "./button";
import { X } from "lucide-react";

/**
 * DetailDrawer
 * Slide-in panel for atomic drilldown. Replaces full-page routes for
 * "view one thing" actions (e.g., open a single integrity flag).
 *
 * Built on shadcn Sheet primitive (side="right").
 *
 * Props
 *   - open      boolean
 *   - onClose   () => void
 *   - title     string
 *   - subtitle  optional string
 *   - children  ReactNode (body content)
 *
 * Width      w-full sm:max-w-lg
 * Header     flex items-center justify-between p-6 border-b border-border
 * Title      text-lg font-semibold
 * Subtitle   text-sm text-muted-foreground
 * Close      shadcn Button variant="ghost" with lucide X
 * Body       overflow-y-auto p-6 space-y-6
 *
 * Tokens only.
 */
export default function DetailDrawer({
  open,
  onClose,
  title,
  subtitle,
  children,
}) {
  return (
    <Sheet
      open={open}
      onOpenChange={(next) => {
        if (!next) onClose?.();
      }}
    >
      <SheetContent
        side="right"
        className="w-full sm:max-w-lg p-0 gap-0 [&>.absolute]:hidden flex flex-col h-full"
      >
        <div className="flex-none flex items-center justify-between p-6 border-b border-border">
          <div className="min-w-0 space-y-1">
            <h2 className="text-lg font-semibold text-foreground truncate">
              {title}
            </h2>
            {subtitle ? (
              <p className="text-sm text-muted-foreground truncate">
                {subtitle}
              </p>
            ) : null}
          </div>
          <SheetClose asChild>
            <Button
              variant="ghost"
              size="icon"
              aria-label="Close"
              className="shrink-0"
            >
              <X className="h-4 w-4" strokeWidth={1.5} />
            </Button>
          </SheetClose>
        </div>
        <div className="flex-1 min-h-0 overflow-y-auto p-6 space-y-6">{children}</div>
      </SheetContent>
    </Sheet>
  );
}
