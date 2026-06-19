import * as React from "react";
import { cn } from "@/lib/utils";

/**
 * GlassPanel
 * Core glassmorphic container — replaces solid Card throughout the dashboard.
 *
 * Variants:
 *   - "default"  — translucent blur, subtle inner glow
 *   - "dense"    — higher opacity for data-heavy sections
 *   - "flat"     — no border, pure blur backdrop
 *
 * Props:
 *   - variant   "default" | "dense" | "flat"
 *   - glow      string | null — optional glow accent class (e.g. "glow-primary")
 *   - interactive boolean — enable hover depth shift
 *   - className  string
 *   - children   ReactNode
 */
const GlassPanel = React.forwardRef(function GlassPanel(
  { variant = "default", glow = null, interactive = false, className, as: Tag = "div", ...props },
  ref
) {
  const base =
    variant === "dense"
      ? "glass-panel-dense"
      : variant === "flat"
        ? "relative overflow-hidden backdrop-blur-xl"
        : "glass-panel";

  return (
    <Tag
      ref={ref}
      className={cn(
        "relative rounded-xl noise-overlay",
        base,
        interactive && "hover-glass cursor-default",
        glow,
        className
      )}
      {...props}
    />
  );
});

const GlassPanelHeader = React.forwardRef(function GlassPanelHeader(
  { className, ...props },
  ref
) {
  return (
    <div
      ref={ref}
      className={cn(
        "flex items-center justify-between px-5 py-3.5 border-b border-white/[0.06]",
        className
      )}
      {...props}
    />
  );
});

const GlassPanelTitle = React.forwardRef(function GlassPanelTitle(
  { className, ...props },
  ref
) {
  return (
    <h3
      ref={ref}
      className={cn("text-sm font-semibold tracking-tight text-foreground", className)}
      {...props}
    />
  );
});

const GlassPanelContent = React.forwardRef(function GlassPanelContent(
  { className, ...props },
  ref
) {
  return (
    <div ref={ref} className={cn("relative z-10 p-5", className)} {...props} />
  );
});

export { GlassPanel, GlassPanelHeader, GlassPanelTitle, GlassPanelContent };
export default GlassPanel;
