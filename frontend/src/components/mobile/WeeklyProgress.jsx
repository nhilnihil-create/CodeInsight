// frontend/src/components/mobile/WeeklyProgress.jsx
// Spec §5.4. Student weekly progress summary.
// Wire format: { weekIso, submissions, passed, accuracy, deltaVsLast }

export function WeeklyProgress({ data }) {
  if (!data) return null;
  return (
    <section className="mobile-card">
      <p style={{ fontSize: 10, opacity: 0.6, letterSpacing: '0.18em', margin: 0 }}>THIS WEEK</p>
      <h3 style={{ fontSize: 15, margin: '4px 0' }}>Weekly progress</h3>
      <p style={{ fontSize: 12, opacity: 0.85, margin: 0 }}>
        {data.submissions} submissions · {data.passed} passed
        · accuracy {Math.round((data.accuracy ?? 0) * 100)}%
        {data.deltaVsLast != null && (
          <> · {data.deltaVsLast >= 0 ? '▲' : '▼'}{Math.abs(data.deltaVsLast).toFixed(2)} vs last week</>
        )}
      </p>
    </section>
  );
}
