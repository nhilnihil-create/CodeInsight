// frontend/src/components/mobile/TestResultList.jsx
// Spec §5.4. Test results after Run/Submit on /student/exercises/:id.
// Wire format: [{ name, passed, expected, got }]

export function TestResultList({ data }) {
  if (!data || data.length === 0) return null;
  return (
    <section className="mobile-card">
      <p style={{ fontSize: 10, opacity: 0.6, letterSpacing: '0.18em', margin: 0 }}>OUTPUT</p>
      {data.map((t, i) => (
        <div key={i} style={{ fontSize: 12, color: t.passed ? '#22C55E' : '#EF4444', padding: '2px 0' }}>
          {t.passed ? '✓' : '✗'} Test {i + 1} {t.passed ? 'passed' : `failed — expected '${t.expected}' got '${t.got}'`}
        </div>
      ))}
    </section>
  );
}
