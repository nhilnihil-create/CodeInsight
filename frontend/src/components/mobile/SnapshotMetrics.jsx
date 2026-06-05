// frontend/src/components/mobile/SnapshotMetrics.jsx
// Spec §5.3. 2x2 grid: users, sections, eval pending, flags open.
// Wire format: { users, sections, evalPending, flagsOpen }

import { useStateDerivation } from '../../state/useStateDerivation.js';
import { StateAwareShell } from '../../state/StateAwareShell.jsx';

export function SnapshotMetrics({ data, role = 'admin' }) {
  const { state, progressText } = useStateDerivation(data);
  return (
    <StateAwareShell role={role} data={data} state={state} progressText={progressText}>
      {data && (
        <div>
          <p style={{ fontSize: 10, opacity: 0.6, letterSpacing: '0.18em', margin: 0 }}>SYSTEM SNAPSHOT</p>
          <div style={{ display: 'grid', gridTemplateColumns: '1fr 1fr', gap: 12, marginTop: 8 }}>
            <Metric value={data.users}        label="users" />
            <Metric value={data.sections}     label="sections" />
            <Metric value={data.evalPending}  label="eval pending" />
            <Metric value={data.flagsOpen}    label="flags open" />
          </div>
        </div>
      )}
    </StateAwareShell>
  );
}

function Metric({ value, label }) {
  return (
    <div>
      <div style={{ fontSize: 22, fontWeight: 700 }}>{value ?? '—'}</div>
      <div style={{ fontSize: 11, opacity: 0.6 }}>{label}</div>
    </div>
  );
}
