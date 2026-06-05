// frontend/src/components/mobile/InterventionQueue.jsx
// Spec §5.1. Critical-only with action buttons.
// Wire format: [{ id, name, concept, cds, fails, avgMinutes }]

export function InterventionQueue({ data, onAssign, on1on1 }) {
  if (!data || data.length === 0) return null;
  return (
    <section className="mobile-card">
      <p style={{ fontSize: 10, opacity: 0.6, letterSpacing: '0.18em', margin: 0 }}>
        INTERVENTION QUEUE · CRITICAL ONLY
      </p>
      {data.map((row) => (
        <article key={row.id} style={{ padding: '8px 0', borderBottom: '1px solid #334155' }}>
          <div style={{ fontWeight: 600 }}>{row.name}</div>
          <div style={{ fontSize: 11, opacity: 0.7 }}>
            {row.concept} {row.cds?.toFixed(2)} · {row.fails} fails · {row.avgMinutes}m avg
          </div>
          <div style={{ display: 'flex', gap: 6, marginTop: 6 }}>
            <button type="button" className="mobile-list-row__btn mobile-list-row__btn--primary" onClick={() => onAssign?.(row)}>Assign Set B</button>
            <button type="button" className="mobile-list-row__btn" onClick={() => on1on1?.(row)}>1:1</button>
          </div>
        </article>
      ))}
    </section>
  );
}
