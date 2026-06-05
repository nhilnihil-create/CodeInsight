// frontend/src/components/mobile/InstructorPriorityInsight.jsx
// Spec §5.1, §6.1, §8. Renders the headline insight of the week.
// Wire format (existing API): { headline, cds, delta, countInHigh, totalStudents, concept, route }

import { useStateDerivation } from '../../state/useStateDerivation.js';
import { StateAwareShell } from '../../state/StateAwareShell.jsx';
import { CDSPillDelta } from './primitives/CDSPillDelta.jsx';

export function InstructorPriorityInsight({ data, role = 'instructor' }) {
  const { state, progressText } = useStateDerivation(data);

  return (
    <StateAwareShell
      role={role}
      data={data?.headline ? data : null}
      state={state}
      progressText={progressText}
      className="mobile-card--priority"
    >
      {data?.headline && (
        <article>
          <p style={{ fontSize: 10, opacity: 0.6, letterSpacing: '0.18em', margin: 0 }}>PRIORITY INSIGHT</p>
          <h2 style={{ fontSize: 16, margin: '4px 0' }}>{data.headline}</h2>
          <p style={{ fontSize: 12, opacity: 0.85, margin: '0 0 8px 0' }}>
            <CDSPillDelta value={data.cds} delta={data.delta} />
            {' · '}
            {data.countInHigh} of {data.totalStudents} students in High
          </p>
          {data.route && (
            <a href={data.route} className="mobile-card__cta">View concept →</a>
          )}
        </article>
      )}
    </StateAwareShell>
  );
}
