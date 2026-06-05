// frontend/src/components/mobile/WeakestConceptBar.jsx
// Spec §5.2. Single concept bar with mastery %.
// Wire format: [{ code, name, mastery, passedCount, totalCount }]  (length 1)

export function WeakestConceptBar({ data }) {
  const c = Array.isArray(data) ? data[0] : data;
  if (!c) return null;
  return (
    <section className="mobile-card">
      <p style={{ fontSize: 10, opacity: 0.6, letterSpacing: '0.18em', margin: 0 }}>YOUR WEAKEST CONCEPT</p>
      <div style={{ display: 'flex', justifyContent: 'space-between', marginTop: 6 }}>
        <span>{c.code} · {c.name}</span>
        <span style={{ background: '#FACC15', color: '#422006', padding: '1px 6px', borderRadius: 3, fontSize: 12 }}>
          {(c.mastery ?? 0).toFixed(2)}
        </span>
      </div>
      <div style={{ background: '#334155', height: 8, borderRadius: 4, marginTop: 4 }}>
        <div style={{
          background: '#FACC15', height: 8, borderRadius: 4,
          width: `${Math.round((c.mastery ?? 0) * 100)}%`,
        }} />
      </div>
      <p style={{ fontSize: 11, opacity: 0.7, marginTop: 4 }}>
        {c.passedCount} of {c.totalCount} exercises passed
      </p>
    </section>
  );
}
