// frontend/src/components/mobile/CodePreviewSurface.jsx
// Spec §5.4, §6.1, §6.2. Phone code preview — NO Monaco, plain <pre>, horizontally scrollable.

export function CodePreviewSurface({ data, onRun, onSubmit }) {
  if (!data) return null;
  return (
    <section>
      <header className="mobile-card">
        <div style={{ fontSize: 15, fontWeight: 600 }}>{data.title}</div>
        <div style={{ fontSize: 11, opacity: 0.7, marginTop: 4 }}>
          CDS-predicted difficulty: {data.difficulty?.toFixed(2)} · Concepts: {data.concepts?.join(', ')}
        </div>
      </header>

      <pre
        className="code-preview-surface"
        style={{ overflowX: 'auto' }}
        aria-label="Code preview (read-only on phone)"
      >
        {`// Read-only on phone. Switch to tablet/desktop to edit.\n${data.code}`}
      </pre>

      <div style={{ display: 'flex', gap: 6, marginTop: 8 }}>
        <button
          type="button"
          onClick={onRun}
          className="mobile-card__cta"
          style={{ flex: 1, textAlign: 'center', background: '#22C55E' }}
        >▶ Run</button>
        <button
          type="button"
          onClick={onSubmit}
          className="mobile-list-row__btn"
          style={{ flex: 1, textAlign: 'center' }}
        >Submit</button>
      </div>
    </section>
  );
}
