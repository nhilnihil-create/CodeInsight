import * as React from "react";
import { cn } from "@/lib/utils";

/**
 * Skeleton — a pulsing placeholder block used while data loads.
 *
 * Inherits the CodeInsight design token colors via Tailwind so it
 * matches the existing Card / muted surfaces without any inline styles.
 */
function Skeleton({ className, ...props }) {
  return (
    <div
      className={cn(
        "animate-pulse rounded-md bg-muted",
        className
      )}
      {...props}
    />
  );
}

export { Skeleton };
export default Skeleton;
