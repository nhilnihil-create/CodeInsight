// frontend/src/components/mobile/ExerciseCardList.jsx
// Spec §5.4. Compact card list of available exercises.
// Wire format: [{ id, title, concept, difficulty, route }]

export function ExerciseCardList({ data, onTap }) {
  if (!data || data.length === 0) {
    return <p style={{ padding: 16, opacity: 0.6 }}>No exercises assigned yet.</p>;
  }
  return (
    <section>
      {data.map((ex) => (
        <button
          key={ex.id}
          type="button"
          className="mobile-card"
          onClick={() => onTap?.(ex)}
          style={{ display: 'block', width: '100%', textAlign: 'left', color: 'inherit' }}
        >
          <div style={{ fontSize: 14, fontWeight: 600 }}>{ex.title}</div>
          <div style={{ fontSize: 11, opacity: 0.7, marginTop: 2 }}>
            {ex.concept} · difficulty {(ex.difficulty * 100).toFixed(0)}%
          </div>
        </button>
      ))}
    </section>
  );
}
