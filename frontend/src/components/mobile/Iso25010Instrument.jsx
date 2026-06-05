// frontend/src/components/mobile/Iso25010Instrument.jsx
// Spec §5.4. ISO/IEC 25010 evaluation instrument, 4-point Likert, one question per screen.
// Wire format: { questions: [{ id, characteristic, text, scale: [1,2,3,4] }], progress: { current, total } }

import { useState } from 'react';

export function Iso25010Instrument({ data, onSubmit }) {
  const [answers, setAnswers] = useState({});
  if (!data?.questions) return <p style={{ padding: 16, opacity: 0.6 }}>No instrument loaded.</p>;
  const total = data.questions.length;
  const idx = Object.keys(answers).length;
  const q = data.questions[idx];
  const isLast = idx === total - 1;

  if (!q) {
    return (
      <section className="mobile-card" style={{ textAlign: 'center' }}>
        <p>All {total} questions answered. Tap submit to send.</p>
        <button type="button" className="mobile-card__cta" onClick={() => onSubmit?.(answers)}>
          Submit evaluation
        </button>
      </section>
    );
  }

  return (
    <section className="mobile-card">
      <p style={{ fontSize: 11, opacity: 0.6, margin: 0 }}>
        Question {idx + 1} of {total} · ISO/IEC 25010 — {q.characteristic}
      </p>
      <div style={{ background: '#334155', height: 4, borderRadius: 2, margin: '6px 0 12px 0' }}>
        <div style={{ background: '#7C3AED', height: 4, borderRadius: 2, width: `${((idx + 1) / total) * 100}%` }} />
      </div>
      <h3 style={{ fontSize: 16, margin: '0 0 16px 0' }}>{q.text}</h3>
      <div style={{ display: 'grid', gridTemplateColumns: '1fr 1fr', gap: 8 }}>
        {q.scale.map((v) => (
          <button
            key={v}
            type="button"
            onClick={() => setAnswers((a) => ({ ...a, [q.id]: v }))}
            className="mobile-list-row__btn"
            style={{
              background: answers[q.id] === v ? '#7C3AED' : undefined,
              color: answers[q.id] === v ? '#F8FAFC' : undefined,
            }}
          >
            {v} — {labelFor(v)}
          </button>
        ))}
      </div>
    </section>
  );
}

function labelFor(v) {
  return ['Strongly disagree', 'Disagree', 'Agree', 'Strongly agree'][v - 1] ?? '';
}
