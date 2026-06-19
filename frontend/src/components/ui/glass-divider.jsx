import { cn } from "@/lib/utils";

/**
 * GlassDivider
 * Gradient border separator that fades out smoothly. Replaces thick
 * solid container boundaries between analytical zones.
 *
 * Props:
 *   - direction   "horizontal" | "vertical"
 *   - className   string
 */
export default function GlassDivider({ direction = "horizontal", className }) {
  return (
    <div
      role="separator"
      aria-orientation={direction}
      className={cn(
        direction === "horizontal" ? "glass-divider-h" : "glass-divider-v",
        "shrink-0",
        className
      )}
    />
  );
}
