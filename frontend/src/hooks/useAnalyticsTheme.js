/**
 * useAnalyticsTheme.js
 *
 * React hook that wraps the 5-tier top-heavy classification framework.
 * Dynamically selects the correct visualizer engine (CDS or Mastery)
 * based on the metricType parameter.
 *
 * Usage:
 *   const theme = useAnalyticsTheme(cdsValue, 'CDS');
 *   const theme = useAnalyticsTheme(masteryPercent, 'MASTERY');
 *
 * Returns: { tier, label, color, tailwind }
 *
 * @module hooks/useAnalyticsTheme
 */

import { useMemo } from "react";

// ──────────────────────────────────────────────────────────────────────
// CONSTANTS (mirrored from backend/utils/analyticsMapper.js)
// ──────────────────────────────────────────────────────────────────────

const NO_DATA = Object.freeze({
  tier: 0,
  label: "No Data",
  color: "slate",
  tailwind: "bg-slate-950/20 text-slate-600 border-transparent",
});

const CDS_TIERS = [
  { tier: 1, label: "Minimal Struggle / Trivial Mastery", color: "slate", tailwind: "bg-slate-900/40 text-slate-400 border-white/5", min: 0.00, max: 0.20 },
  { tier: 2, label: "Expected Resistance", color: "emerald", tailwind: "bg-emerald-500/15 text-emerald-400 border-emerald-500/20", min: 0.21, max: 0.40 },
  { tier: 3, label: "Moderate Friction", color: "amber", tailwind: "bg-amber-500/15 text-amber-400 border-amber-500/20", min: 0.41, max: 0.60 },
  { tier: 4, label: "High Struggle Loop", color: "orange", tailwind: "bg-orange-500/20 text-orange-400 border-orange-500/30", min: 0.61, max: 0.80 },
  { tier: 5, label: "Critical Blocker", color: "rose", tailwind: "bg-rose-600/30 text-rose-400 border-rose-500/40 font-bold shadow-[inset_0_0_12px_rgba(244,63,94,0.15)]", min: 0.81, max: 1.00 },
];

const MASTERY_TIERS = [
  { tier: 1, label: "Excellent Mastery", color: "slate", tailwind: "bg-slate-900/40 text-slate-400 border-white/5", min: 85, max: 100 },
  { tier: 2, label: "Nominal Progress", color: "emerald", tailwind: "bg-emerald-500/15 text-emerald-400 border-emerald-500/20", min: 65, max: 84.99 },
  { tier: 3, label: "Moderate Challenge", color: "amber", tailwind: "bg-amber-500/15 text-amber-400 border-amber-500/20", min: 45, max: 64.99 },
  { tier: 4, label: "Significant Struggle", color: "orange", tailwind: "bg-orange-500/20 text-orange-400 border-orange-500/30", min: 25, max: 44.99 },
  { tier: 5, label: "Critical Support Required", color: "rose", tailwind: "bg-rose-600/30 text-rose-400 border-rose-500/40 font-bold", min: 0, max: 24.99 },
];

// ──────────────────────────────────────────────────────────────────────
// INTERNAL PURE FUNCTIONS (no React dependency — testable in isolation)
// ──────────────────────────────────────────────────────────────────────

function safeNumber(value) {
  if (value == null) return NaN;
  const n = Number(value);
  return Number.isFinite(n) ? n : NaN;
}

function roundToTwo(value) {
  return Math.round(value * 100) / 100;
}

function lookupTier(value, tiers) {
  for (const t of tiers) {
    if (value >= t.min && value <= t.max) {
      return { tier: t.tier, label: t.label, color: t.color, tailwind: t.tailwind };
    }
  }
  if (value < tiers[0].min) {
    const t = tiers[tiers.length - 1];
    return { tier: t.tier, label: t.label, color: t.color, tailwind: t.tailwind };
  }
  const t = tiers[0];
  return { tier: t.tier, label: t.label, color: t.color, tailwind: t.tailwind };
}

function computeCDSTier(value) {
  const num = safeNumber(value);
  if (Number.isNaN(num)) return { ...NO_DATA };
  return lookupTier(roundToTwo(num), CDS_TIERS);
}

function computeMasteryTier(value) {
  const num = safeNumber(value);
  if (Number.isNaN(num)) return { ...NO_DATA };
  return lookupTier(roundToTwo(num), MASTERY_TIERS);
}

// ──────────────────────────────────────────────────────────────────────
// HOOK
// ──────────────────────────────────────────────────────────────────────

/**
 * useAnalyticsTheme
 *
 * Memoized hook that classifies a numeric value into the 5-tier system.
 *
 * @param {*} value           — raw numeric value (CDS decimal or Mastery %)
 * @param {'CDS'|'MASTERY'} metricType — selects the classification engine
 * @returns {{ tier: number, label: string, color: string, tailwind: string }}
 */
export default function useAnalyticsTheme(value, metricType = "CDS") {
  const theme = useMemo(() => {
    const normalized = String(metricType).toUpperCase().trim();

    if (normalized === "MASTERY") {
      return computeMasteryTier(value);
    }

    // Default: CDS engine
    return computeCDSTier(value);
  }, [value, metricType]);

  return theme;
}

// Named exports for direct function usage (non-hook context)
export { computeCDSTier, computeMasteryTier, CDS_TIERS, MASTERY_TIERS, NO_DATA };
