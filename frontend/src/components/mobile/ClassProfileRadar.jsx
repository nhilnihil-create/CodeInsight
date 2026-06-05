// frontend/src/components/mobile/ClassProfileRadar.jsx
// Spec §6.1. Phone renders as summary (weakest concept + drill). NO D3 on phone.

export function ClassProfileRadar({ data, onDrill }) {
  if (!data) return null;
  const weakest = [...(data.axes ?? [])].sort((a, b) => a.mastery - b.mastery)[0];
  return (
    <section className="mobile-card">
      <p style={{ fontSize: 10, opacity: 0.6, letterSpacing: '0.18em', margin: 0 }}>CLASS CONCEPT PROFILE</p>
      {weakest && (
        <p style={{ fontSize: 13, margin: '4px 0' }}>
          <b>Weakest:</b> {weakest.code} · {weakest.name} ({(weakest.mastery * 100).toFixed(0)}%)
        </p>
      )}
      <button type="button" className="mobile-card__cta" onClick={onDrill}>
        View full radar →
      </button>
    </section>
  );
}
