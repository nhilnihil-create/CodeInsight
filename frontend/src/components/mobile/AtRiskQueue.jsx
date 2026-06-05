// frontend/src/components/mobile/AtRiskQueue.jsx
// Spec §5.1. K-adaptive list of at-risk students. N is from useAdaptiveN.
// Wire format: [{ id, name, risk: 'critical'|'high'|'medium'|'low', concept, cds, delta, fails }]

import { useAdaptiveN, DEFAULT_PRIMARY_HEIGHT } from '../../hooks/useAdaptiveN.js';
import { RiskBadge } from './primitives/RiskBadge.jsx';

const ROW_HEIGHT = 88;

export function AtRiskQueue({ data, onTap, actionLabel = 'tap queue to expand' }) {
  const n = useAdaptiveN(undefined, DEFAULT_PRIMARY_HEIGHT, ROW_HEIGHT);
  if (!data || data.length === 0) return null;

  const shown = data.slice(0, n);
  const more = data.length - shown.length;

  return (
    <section className="mobile-card">
      <p style={{ fontSize: 10, opacity: 0.6, letterSpacing: '0.18em', margin: 0 }}>
        AT-RISK QUEUE · TOP {shown.length}
      </p>
      {shown.map((row) => (
        <button
          key={row.id}
          type="button"
          className="mobile-list-row"
          onClick={() => onTap?.(row)}
          style={{
            display: 'flex', justifyContent: 'space-between', alignItems: 'center',
            minHeight: 56, width: '100%', background: 'transparent',
            border: 'none', borderBottom: '1px solid #334155',
            color: 'inherit', padding: '8px 0', textAlign: 'left',
          }}
        >
          <span>{row.name}</span>
          <RiskBadge level={row.risk} mode="mobile" />
        </button>
      ))}
      {more > 0 && (
        <p style={{ fontSize: 11, opacity: 0.5, marginTop: 6, textAlign: 'center' }}>
          + {more} more · {actionLabel}
        </p>
      )}
    </section>
  );
}
