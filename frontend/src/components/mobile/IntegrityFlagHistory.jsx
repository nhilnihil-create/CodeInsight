// frontend/src/components/mobile/IntegrityFlagHistory.jsx
// Spec §5.4. Student's own flag history (read-only).
// Wire format: same shape as IntegrityFlagList, but scoped to the requesting student.

export function IntegrityFlagHistory({ data }) {
  if (!data || data.length === 0) {
    return <p style={{ padding: 16, opacity: 0.6 }}>0 flags on your record.</p>;
  }
  return (
    <section>
      {data.map((f) => (
        <article key={f.id} className="mobile-card">
          <div style={{ fontSize: 13, fontWeight: 600 }}>{f.type}</div>
          <div style={{ fontSize: 11, opacity: 0.7 }}>{f.summary} · {f.createdAt}</div>
        </article>
      ))}
    </section>
  );
}
