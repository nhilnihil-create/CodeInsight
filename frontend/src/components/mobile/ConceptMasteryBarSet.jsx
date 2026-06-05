// frontend/src/components/mobile/ConceptMasteryBarSet.jsx
// Spec §5.4. 7 concept bars (one per concept). Sticky overall mastery header.
// Wire format: [{ code, name, mastery: 0..1 }]

const COLOR = (m) =>
  m >= 0.8 ? '#22C55E' : m >= 0.6 ? '#86EFAC' : m >= 0.4 ? '#FACC15' : m >= 0.2 ? '#FB923C' : '#EF4444';

export function ConceptMasteryBarSet({ data }) {
  if (!data) return null;
  const overall = data.length
    ? (data.reduce((s, c) => s + (c.mastery ?? 0), 0) / data.length)
    : 0;
  return (
    <section className="mobile-card" style={{ position: 'relative' }}>
      <header style={{ position: 'sticky', top: 0, background: 'inherit', padding: '4px 0' }}>
        <p style={{ fontSize: 10, opacity: 0.6, letterSpacing: '0.18em', margin: 0 }}>OVERALL MASTERY</p>
        <div style={{ fontSize: 24, fontWeight: 700 }}>{Math.round(overall * 100)}%</div>
      </header>
      {data.map((c) => (
        <div key={c.code} style={{ marginTop: 8 }}>
          <div style={{ display: 'flex', justifyContent: 'space-between', fontSize: 13 }}>
            <span>{c.code} · {c.name}</span>
            <span style={{ opacity: 0.7 }}>{Math.round((c.mastery ?? 0) * 100)}%</span>
          </div>
          <div style={{ background: '#334155', height: 8, borderRadius: 4, marginTop: 4 }}>
            <div style={{
              background: COLOR(c.mastery), height: 8, borderRadius: 4,
              width: `${Math.round((c.mastery ?? 0) * 100)}%`,
            }} />
          </div>
        </div>
      ))}
    </section>
  );
}
