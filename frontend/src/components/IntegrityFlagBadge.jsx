import React from 'react';

/**
 * IntegrityFlagBadge — small pill that labels an integrity-flag type.
 *
 * Per the research paper, the four deterministic integrity flags are:
 *   1. HARDCODING — literal output instead of computed values
 *   2. BLANK_TEMPLATE — no changes to starter code
 *   3. BEHAVIORAL_ANOMALY — instant success or extreme speed
 *   4. CODE_GROWTH_ANOMALY — >30% growth spike between submissions
 *
 * Colors use shadcn semantic tokens for light/dark theme support.
 */
const IntegrityFlagBadge = ({ flagType }) => {
  const flagConfig = {
    HARDCODING: {
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
    PASSIVE_BEHAVIOR_LOG: {
      label: 'Contextual Activity',
      bg: 'hsl(280 60% 60% / 0.12)',
      color: 'hsl(280 60% 35%)',
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
