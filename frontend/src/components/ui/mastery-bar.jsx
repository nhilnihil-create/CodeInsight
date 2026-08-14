import { useRef } from "react";
import { motion, useInView } from "framer-motion";
import { cn } from "@/lib/utils";

/**
 * MasteryBar
 * Unified neon progress bar shared across student & instructor portals.
 *
 * 5-tier semantic gradient system:
 *   - excellent     (CDS 0.00–0.20, Mastery 80–100%): green gradient
 *   - strong        (CDS 0.21–0.40, Mastery 60–79%):  emerald → teal gradient
 *   - developing    (CDS 0.41–0.60, Mastery 40–59%):  amber gradient
 *   - needs_support (CDS 0.61–0.80, Mastery 20–39%):  orange gradient
 *   - critical      (CDS 0.81–1.00, Mastery 0–19%):   rose → red gradient
 *
 * Props:
 *   - percent    number   0–100 mastery value
 *   - tier       "excellent" | "strong" | "developing" | "needs_support" | "critical"
 *   - delay      number   animation delay (default 0)
 *   - className  string
 */
export const TIER_BAR = {
  excellent:     "tier-excellent-bar",
  strong:        "tier-strong-bar",
  developing:    "tier-developing-bar",
  needs_support: "tier-needs-support-bar",
  critical:      "tier-critical-bar",
};

export default function MasteryBar({ percent, tier = "strong", delay = 0, className }) {
  const ref = useRef(null);
  const inView = useInView(ref, { once: true, margin: "-40px" });

  return (
    <div ref={ref} className={cn("h-1.5 w-full rounded-full mastery-track overflow-hidden", className)}>
      <motion.div
        className={cn("h-full rounded-full", TIER_BAR[tier] || TIER_BAR.excellent)}
        initial={{ width: 0 }}
        animate={inView ? { width: `${percent}%` } : { width: 0 }}
        transition={{ duration: 0.9, delay, ease: [0.25, 0.46, 0.45, 0.94] }}
      />
    </div>
  );
}

export function tierForMastery(mastery) {
  if (mastery == null) return "critical";
  if (mastery >= 85) return "excellent";
  if (mastery >= 65) return "nominal";
  if (mastery >= 45) return "moderate";
  if (mastery >= 25) return "significant";
  return "critical";
}

/**
 * tierForCds
 * Maps a CDS value (0–1) to a 5-tier semantic string.
 * CDS measures difficulty: lower = better mastery.
 * Shared across all portals for consistent color mapping.
 */
export function tierForCds(cds) {
  if (cds == null || isNaN(cds) || cds === 0) return "excellent";
  if (cds <= 0.20) return "excellent";
  if (cds <= 0.40) return "strong";
  if (cds <= 0.60) return "developing";
  if (cds <= 0.80) return "needs_support";
  return "critical";
}

/**
 * TIER_META
 * Shared metadata for each tier: dot class, text class, label.
 */
export const TIER_META = {
  excellent:     { dot: "tier-excellent-dot",     text: "tier-excellent-text",     label: "Excellent" },
  strong:        { dot: "tier-strong-dot",        text: "tier-strong-text",        label: "Strong" },
  developing:    { dot: "tier-developing-dot",    text: "tier-developing-text",    label: "Developing" },
  needs_support: { dot: "tier-needs-support-dot", text: "tier-needs-support-text", label: "Needs Support" },
  critical:      { dot: "tier-critical-dot",      text: "tier-critical-text",      label: "Critical" },
};

/**
 * NEW 5-TIER BEHAVIORAL LEGEND SYSTEM
 * Maps mastery percentages to behavioral tiers for student profile display
 */
/** @deprecated Use TIER_BAR for bar fills. MasteryBar renders the academic CDS system; NEW_TIER_META remains the live behavioral legend. */
export const NEW_TIER_BAR = {
  excellent:     "tier-excellent-mastery-bar",
  nominal:        "tier-nominal-progress-bar",
  moderate:       "tier-moderate-challenge-bar",
  significant:    "tier-significant-struggle-bar",
  critical:       "tier-critical-blocker-bar",
};

export const NEW_TIER_META = {
  excellent:     { dot: "tier-excellent-mastery-dot",     text: "tier-excellent-mastery-text",     label: "Excellent Mastery" },
  nominal:        { dot: "tier-nominal-progress-dot",      text: "tier-nominal-progress-text",      label: "Nominal Progress" },
  moderate:       { dot: "tier-moderate-challenge-dot",   text: "tier-moderate-challenge-text",   label: "Moderate Challenge" },
  significant:    { dot: "tier-significant-struggle-dot",  text: "tier-significant-struggle-text",  label: "Significant Struggle" },
  critical:       { dot: "tier-critical-blocker-dot",     text: "tier-critical-blocker-text",     label: "Critical Blocker" },
};

/**
 * TIER_RANGES
 * Canonical per-tier CDS → Mastery mapping (display companion to tierForCds).
 * Keep boundary values in sync with tierForCds thresholds (0.20 / 0.40 / 0.60 / 0.80).
 *   cdsRange:     CDS difficulty interval (lower = easier)
 *   difficulty:   CDS difficulty vocabulary shown across portals
 *   masteryRange: Mastery interval (100% = full mastery) — same scale read in reverse
 *   fill:         mastery midpoint, used for honest animated bar widths
 */
export const TIER_RANGES = [
  { key: "excellent", cdsRange: "0.00–0.20", difficulty: "Very Low", masteryRange: "80–100%", fill: 90 },
  { key: "strong", cdsRange: "0.21–0.40", difficulty: "Low", masteryRange: "60–79%", fill: 70 },
  { key: "developing", cdsRange: "0.41–0.60", difficulty: "Moderate", masteryRange: "40–59%", fill: 50 },
  { key: "needs_support", cdsRange: "0.61–0.80", difficulty: "Elevated", masteryRange: "20–39%", fill: 30 },
  { key: "critical", cdsRange: "0.81–1.00", difficulty: "High", masteryRange: "0–19%", fill: 10 },
];
