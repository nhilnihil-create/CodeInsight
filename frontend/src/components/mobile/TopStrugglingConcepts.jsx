// frontend/src/components/mobile/TopStrugglingConcepts.jsx
// Spec §6.1. K-adaptive concept list.
// Wire format: [{ code, name, cds, delta }]

import { useAdaptiveN } from '../../hooks/useAdaptiveN.js';
import { CDSPillDelta } from './primitives/CDSPillDelta.jsx';

const ROW = 56;
const PRIMARY = 200;
const CHROME = 104;

export function TopStrugglingConcepts({ data, onTap }) {
  const n = useAdaptiveN(CHROME, PRIMARY, ROW);
  if (!data) return null;
  const shown = data.slice(0, n);
  return (
    <section className="mobile-card">
      <p style={{ fontSize: 10, opacity: 0.6, letterSpacing: '0.18em', margin: 0 }}>
        TOP STRUGGLING CONCEPTS ({shown.length})
      </p>
      {shown.map((c) => (
        <button key={c.code} type="button" className="mobile-list-row" onClick={() => onTap?.(c)} style={{
          display: 'flex', justifyContent: 'space-between', width: '100%',
          background: 'transparent', border: 'none', color: 'inherit',
          padding: '8px 0', borderBottom: '1px solid #334155', minHeight: 56, textAlign: 'left',
        }}>
          <span>{c.code} · {c.name}</span>
          <CDSPillDelta value={c.cds} delta={c.delta} mode="mobile" />
        </button>
      ))}
    </section>
  );
}
