// frontend/src/components/mobile/primitives/RiskBadge.jsx
// Spec §6.1, §13.10. Mobile: color + label always shown. Symbol is decorative.

const SYMBOLS = { critical: '●✕', high: '●⚠', medium: '●◐', low: '●○' };
const LABELS = { critical: 'Critical', high: 'High', medium: 'Medium', low: 'Low' };

export function RiskBadge({ level, mode = 'desktop' }) {
  if (mode === 'mobile') {
    return (
      <span className="risk-badge--mobile" data-level={level} role="status">
        <span className="risk-badge__symbol" aria-hidden="true">{SYMBOLS[level]}</span>
        <span className="risk-badge__label">{LABELS[level]}</span>
      </span>
    );
  }
  // desktop: full label + className only (existing desktop behaviour)
  return (
    <span className={`risk-badge risk-badge--${level}`} role="status">
      {LABELS[level]}
    </span>
  );
}
