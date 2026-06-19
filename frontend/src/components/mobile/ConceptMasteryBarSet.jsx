// frontend/src/components/mobile/ConceptMasteryBarSet.jsx
// Spec §5.4. 7 concept bars (one per concept). Sticky overall mastery header.
// Wire format: [{ code, name, mastery: 0..1 }]
//
// 5-tier color system aligned with desktop MasteryBar:
//   mastery 80-100% → excellent (green)
//   mastery 60-79%  → strong (emerald)
//   mastery 40-59%  → developing (amber)
//   mastery 20-39%  → needs_support (orange)
//   mastery 0-19%   → critical (rose)

const TIER_COLORS = {
  excellent:     '#22c55e',
  strong:        '#34d399',
  developing:    '#f59e0b',
  needs_support: '#f97316',
  critical:      '#f43f5e',
};

const tierForMastery = (m) => {
  if (m >= 0.8) return 'excellent';
  if (m >= 0.6) return 'strong';
  if (m >= 0.4) return 'developing';
  if (m >= 0.2) return 'needs_support';
  return 'critical';
};

export function ConceptMasteryBarSet({ data }) {
  if (!data) return null;
  const overall = data.length
    ? (data.reduce((s, c) => s + (c.mastery ?? 0), 0) / data.length)
    : 0;
  const overallTier = tierForMastery(overall);
  return (
    <section className="mobile-card" style={{ position: 'relative' }}>
      <header style={{ position: 'sticky', top: 0, background: 'inherit', padding: '4px 0' }}>
        <p style={{ fontSize: 10, opacity: 0.6, letterSpacing: '0.18em', margin: 0 }}>OVERALL MASTERY</p>
        <div style={{ fontSize: 24, fontWeight: 700, color: TIER_COLORS[overallTier] }}>{Math.round(overall * 100)}%</div>
      </header>
      {data.map((c) => {
        const m = c.mastery ?? 0;
        const tier = tierForMastery(m);
        return (
          <div key={c.code} style={{ marginTop: 8 }}>
            <div style={{ display: 'flex', justifyContent: 'space-between', fontSize: 13 }}>
              <span>{c.code} · {c.name}</span>
              <span style={{ opacity: 0.7 }}>{Math.round(m * 100)}%</span>
            </div>
            <div style={{ background: '#334155', height: 8, borderRadius: 4, marginTop: 4 }}>
              <div style={{
                background: TIER_COLORS[tier], height: 8, borderRadius: 4,
                width: `${Math.round(m * 100)}%`,
              }} />
            </div>
          </div>
        );
      })}
    </section>
  );
}
