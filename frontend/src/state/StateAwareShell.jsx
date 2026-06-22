// frontend/src/state/StateAwareShell.jsx
// Wraps a widget. Spec §8.
// - NoData → renders copy + CTA, hides children
// - LowConfidence → renders children + "Limited" badge + progress
// - Healthy → renders children normally

import { copyFor } from './useStateDerivation.js';

export function StateAwareShell({ role, data, state, progressText, children, className = '' }) {
  if (state === 'NoData' || data == null) {
    const copy = copyFor(role, 'NoData');
    if (!copy) return children;
    return (
      <div className={`rounded-xl border border-dashed bg-card p-6 text-center ${className}`} role="status">
        <h3 className="text-sm font-semibold text-foreground mb-1">{copy.title}</h3>
        <p className="text-xs text-muted-foreground mb-3">{copy.body}</p>
        {copy.cta && (
          <a href={copy.cta.route} className="text-xs font-medium text-primary hover:underline">{copy.cta.label} →</a>
        )}
      </div>
    );
  }

  if (state === 'LowConfidence') {
    return (
      <div className={`rounded-xl border border-solid bg-card p-4 ${className}`}>
        <div className="text-xs font-semibold text-amber-500 mb-1">Limited</div>
        {progressText && (
          <p className="text-xs text-muted-foreground mb-2">{progressText}</p>
        )}
        {children}
      </div>
    );
  }

  return <div className={className}>{children}</div>;
}
