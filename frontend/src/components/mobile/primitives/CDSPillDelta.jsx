// frontend/src/components/mobile/primitives/CDSPillDelta.jsx
// Spec §6.1. Mobile: tiny pill (numeric only) + small arrow. No Δ number.

export function CDSPillDelta({ value, delta, mode = 'desktop' }) {
  const cls = value <= 0.20 ? 'low' : value <= 0.40 ? 'medium' : value <= 0.80 ? 'elevated' : 'critical';
  const arrow = delta == null ? '▬' : delta > 0 ? '▲' : delta < 0 ? '▼' : '▬';

  if (mode === 'mobile') {
    return (
      <span style={{ display: 'inline-flex', alignItems: 'center', gap: 4 }}>
        <span className="cds-pill--mobile" data-level={cls}>{value?.toFixed(2)}</span>
        <span style={{ fontSize: 10 }} aria-hidden="true">{arrow}</span>
      </span>
    );
  }
  return (
    <span className="cds-pill cds-pill--with-delta" data-level={cls}>
      {value?.toFixed(2)} {arrow} {delta != null && `${delta >= 0 ? '+' : ''}${delta.toFixed(2)}`}
    </span>
  );
}
