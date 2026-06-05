// frontend/src/components/mobile/ActionStack.jsx
// Spec §5.2. Student's next actions (priority + optional).
// Wire format: [{ id, label, kind: 'priority'|'optional' }]

export function ActionStack({ data }) {
  if (!data || data.length === 0) return null;
  return (
    <section className="mobile-card">
      <p style={{ fontSize: 10, opacity: 0.6, letterSpacing: '0.18em', margin: 0 }}>NEXT ACTIONS</p>
      {data.map((a) => (
        <div key={a.id} style={{ padding: '4px 0', opacity: a.kind === 'optional' ? 0.7 : 1 }}>
          {a.kind === 'priority' ? '▶ ' : '▸ '}{a.label}
        </div>
      ))}
    </section>
  );
}
