// frontend/src/components/mobile/IntegrityFlagList.jsx
// Spec §5.4. Three most recent critical flags. NO review on phone.
// Wire format: [{ id, type, studentName, summary, createdAt }]

export function IntegrityFlagList({ data, onDrill }) {
  if (!data || data.length === 0) return null;
  return (
    <section className="mobile-card">
      <p style={{ fontSize: 10, opacity: 0.6, letterSpacing: '0.18em', margin: 0 }}>RECENT FLAGS</p>
      {data.map((f) => (
        <article key={f.id} style={{ padding: '6px 0', borderBottom: '1px solid #334155' }}>
          <div style={{ fontSize: 13, fontWeight: 600 }}>{f.type} · {f.studentName}</div>
          <div style={{ fontSize: 11, opacity: 0.7 }}>{f.summary}</div>
        </article>
      ))}
      <button type="button" className="mobile-card__cta" style={{ marginTop: 8 }} onClick={onDrill}>
        View all (tablet+) →
      </button>
    </section>
  );
}
