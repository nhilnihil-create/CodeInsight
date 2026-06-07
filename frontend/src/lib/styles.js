import { cn } from "./utils";

/**
 * Class-string utilities for the CodeInsight design system.
 * All values reference CSS tokens defined in `src/index.css` —
 * no arbitrary hex, no inline styles.
 *
 * Reference: ../../DESIGN_SYSTEM.md
 */

export const cardSurface = "bg-card text-card-foreground border border-border rounded-lg shadow-sm";
export const cardPad = "p-4 sm:p-5";
export const cardPadDense = "p-4";

export const pageShell = "max-w-7xl mx-auto px-4 sm:px-6 lg:px-8 py-6 sm:py-8";
export const pageStack = "space-y-6 sm:space-y-8";
export const sectionStack = "space-y-4 sm:space-y-6";

export const kpiValue =
  "text-2xl font-semibold font-mono tabular-nums tracking-tight leading-[1.1]";
export const kpiLabel =
  "text-[10px] font-semibold uppercase tracking-wider text-muted-foreground";
export const kpiDelta = "inline-flex items-center gap-1 px-1.5 py-0.5 rounded-md text-[11px] font-medium font-mono tabular-nums";
export const kpiDeltaPositive = "bg-success/10 text-success border border-success/20";
export const kpiDeltaNegative = "bg-destructive/10 text-destructive border border-destructive/20";
export const kpiDeltaFlat = "bg-muted text-muted-foreground border border-border";

export const formLabel =
  "text-sm font-medium leading-none text-foreground mb-1.5 block";
export const formInput =
  "flex h-9 w-full rounded-md border border-input bg-card px-3 py-1 text-sm text-foreground placeholder:text-muted-foreground focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-ring focus-visible:ring-offset-2 focus-visible:ring-offset-background disabled:cursor-not-allowed disabled:opacity-50";
export const formHelper = "mt-1.5 text-xs text-muted-foreground";
export const formField = "flex flex-col gap-1.5";

export const statusChip =
  "inline-flex items-center gap-1.5 px-2 py-0.5 rounded-full text-[11px] font-medium";
export const statusDot = "h-1.5 w-1.5 rounded-full";

export const focusRing =
  "focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-ring focus-visible:ring-offset-2 focus-visible:ring-offset-background";

/**
 * Status chip variant helper.
 * @param {"success"|"warning"|"destructive"|"info"|"muted"} variant
 */
export function statusChipVariant(variant) {
  switch (variant) {
    case "success":
      return "bg-success/10 text-success border border-success/20";
    case "warning":
      return "bg-warning/10 text-warning-foreground border border-warning/20";
    case "destructive":
      return "bg-destructive/10 text-destructive border border-destructive/20";
    case "info":
      return "bg-info/10 text-info-foreground border border-info/20";
    default:
      return "bg-muted text-muted-foreground border border-border";
  }
}

/**
 * CDS risk variant helper.
 * @param {"low"|"mod"|"high"|"na"} variant
 */
export function cdsVariant(variant) {
  switch (variant) {
    case "low":
      return "bg-cds-low/10 text-cds-low border border-cds-low/20";
    case "mod":
      return "bg-cds-mod/10 text-cds-mod border border-cds-mod/20";
    case "high":
      return "bg-cds-high/10 text-cds-high border border-cds-high/20";
    case "na":
    default:
      return "bg-cds-na/10 text-cds-na border border-cds-na/20";
  }
}

/**
 * Compact number formatter for KPI values.
 */
export function formatCompact(value) {
  if (value == null) return "—";
  const num = typeof value === "string" ? parseFloat(value) : value;
  if (typeof num !== "number" || Number.isNaN(num)) return String(value);
  if (Math.abs(num) >= 1_000_000) return `${(num / 1_000_000).toFixed(1)}M`;
  if (Math.abs(num) >= 1_000) return `${(num / 1_000).toFixed(1)}k`;
  return num.toLocaleString();
}

/**
 * Trend direction from a delta value.
 */
export function trendDirection(delta) {
  if (delta == null || delta === 0) return "flat";
  return delta > 0 ? "up" : "down";
}
