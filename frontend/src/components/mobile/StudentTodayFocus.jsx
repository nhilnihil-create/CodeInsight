// frontend/src/components/mobile/StudentTodayFocus.jsx
// Spec §5.2. Renders one exercise + "why" + estimated time + start CTA.
// Wire format: { exerciseId, title, why, estimatedMinutes, route }

import { useStateDerivation } from '../../state/useStateDerivation.js';
import { StateAwareShell } from '../../state/StateAwareShell.jsx';

export function StudentTodayFocus({ data, role = 'student' }) {
  const { state, progressText } = useStateDerivation(data);

  return (
    <StateAwareShell
      role={role}
      data={data?.exerciseId ? data : null}
      state={state}
      progressText={progressText}
    >
      {data?.exerciseId && (
        <article>
          <p style={{ fontSize: 10, opacity: 0.6, letterSpacing: '0.18em', margin: 0 }}>TODAY'S FOCUS</p>
          <h2 style={{ fontSize: 17, margin: '4px 0' }}>{data.title}</h2>
          <p style={{ fontSize: 12, margin: '4px 0' }}><b>Why:</b> {data.why}</p>
          <p style={{ fontSize: 12, opacity: 0.85, margin: '4px 0 8px 0' }}>
            <b>Estimated time:</b> {data.estimatedMinutes} min
          </p>
          <a href={data.route || `/student/exercises/${data.exerciseId}`}
             className="mobile-card__cta"
             style={{ display: 'block', textAlign: 'center' }}>
            ▶ Start exercise
          </a>
        </article>
      )}
    </StateAwareShell>
  );
}
