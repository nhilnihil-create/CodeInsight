// frontend/src/components/mobile/WeeklyTeachingInsight.jsx
// Spec §6.1. One-sentence teaching insight + drill.
// Wire format: { headline, body, route }

export function WeeklyTeachingInsight({ data }) {
  if (!data) return null;
  return (
    <section className="mobile-card">
      <p style={{ fontSize: 10, opacity: 0.6, letterSpacing: '0.18em', margin: 0 }}>WEEKLY INSIGHT</p>
      <p style={{ fontSize: 14, fontWeight: 600, margin: '4px 0' }}>{data.headline}</p>
      <p style={{ fontSize: 12, opacity: 0.85, margin: '0 0 8px 0' }}>{data.body}</p>
      {data.route && <a href={data.route} className="mobile-card__cta">Open full insight →</a>}
    </section>
  );
}
