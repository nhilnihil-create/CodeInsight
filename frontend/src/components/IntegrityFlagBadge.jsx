import React from 'react';

/**
 * IntegrityFlagBadge — small pill that labels an integrity-flag type.
 *
 * Colors are resolved from shadcn semantic tokens (defined in
 * src/index.css) so the badge reads correctly in both light and dark
 * themes. The hue is preserved (red/amber/green/teal) so the visual
 * signal of "severity category" is stable, but the chroma is dialled
 * down in light mode to a softer, still legible fill.
 */
const IntegrityFlagBadge = ({ flagType }) => {
  // Each entry: label + token name. bg is an `hsl()` string built from
  // the active theme's --destructive / --chart-4 / --chart-2 / --primary
  // (defined in src/index.css) with a low alpha so the pill stays subtle.
  const flagConfig = {
    HARDCODING: {
      label: 'Hardcoding',
      bg: 'hsl(0 84% 60% / 0.10)',
      color: 'hsl(0 84% 40%)',
    },
    HARD_CODING: {
      label: 'Hardcoding',
      bg: 'hsl(0 84% 60% / 0.10)',
      color: 'hsl(0 84% 40%)',
    },
    BLANK_TEMPLATE: {
      label: 'Blank/Template',
      bg: 'hsl(43 74% 66% / 0.18)',
      color: 'hsl(32 81% 30%)',
    },
    BEHAVIORAL_ANOMALY: {
      label: 'Behavioral',
      bg: 'hsl(221 83% 53% / 0.10)',
      color: 'hsl(221 83% 40%)',
    },
    CODE_GROWTH_ANOMALY: {
      label: 'Code growth',
      bg: 'hsl(142 71% 45% / 0.12)',
      color: 'hsl(142 71% 28%)',
    },
    code_paste_detected: {
      label: 'Code paste',
      bg: 'hsl(0 84% 60% / 0.10)',
      color: 'hsl(0 84% 40%)',
    },
    retry_storm: {
      label: 'Retry storm',
      bg: 'hsl(43 74% 66% / 0.18)',
      color: 'hsl(32 81% 30%)',
    },
  };

  const config = flagConfig[flagType] || {
    label: (flagType || 'Flag').replace(/_/g, ' '),
    bg: 'hsl(var(--secondary))',
    color: 'hsl(var(--muted-foreground))',
  };

  return (
    <span
      style={{
        display: 'inline-block',
        padding: '2px 8px',
        fontSize: '10px',
        fontWeight: 700,
        letterSpacing: '0.02em',
        borderRadius: '9999px',
        background: config.bg,
        color: config.color,
        textTransform: 'capitalize',
        border: '1px solid hsl(var(--border) / 0.6)',
      }}
    >
      {config.label}
    </span>
  );
};

export default IntegrityFlagBadge;
