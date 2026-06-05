// frontend/src/state/StateAwareShell.jsx
// Wraps a widget. Spec §8.
// - NoData → renders copy + CTA, hides children
// - LowConfidence → renders children + "Limited" badge + progress
// - Healthy → renders children normally

import { copyFor } from './useStateDerivation.js';
import { STATE_VISUAL } from './stateCopy.js';

export function StateAwareShell({ role, data, state, progressText, children, className = '' }) {
  // No data: replace with copy-only card
  if (state === 'NoData' || data == null) {
    const copy = copyFor(role, 'NoData');
    if (!copy) return children;
    return (
      <div className={`mobile-card mobile-card--nodata border-dashed ${className}`} role="status">
        <h3 className="mobile-card__title">{copy.title}</h3>
        <p className="mobile-card__body">{copy.body}</p>
        {copy.cta && (
          <a href={copy.cta.route} className="mobile-card__cta">{copy.cta.label} →</a>
        )}
      </div>
    );
  }

  // Low confidence: render children + badge + progress
  if (state === 'LowConfidence') {
    return (
      <div className={`mobile-card mobile-card--lowconf border-solid ${className}`}>
        <div className="mobile-card__badge">Limited</div>
        {progressText && (
          <p className="mobile-card__progress">{progressText}</p>
        )}
        {children}
      </div>
    );
  }

  // Healthy: just children
  return <div className={className}>{children}</div>;
}
