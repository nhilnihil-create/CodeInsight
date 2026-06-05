// frontend/src/components/mobile/AtRiskRoster.jsx
// Spec §5.4. Filterable list with View / Message / Intervene buttons.
// Wire format: same as AtRiskQueue + section + flags.

import { RiskBadge } from './primitives/RiskBadge.jsx';

export function AtRiskRoster({ data, onView, onMessage, onIntervene }) {
  if (!data || data.length === 0) {
    return <p style={{ padding: 16, opacity: 0.6 }}>No students match the current filter.</p>;
  }
  return (
    <section>
      <div className="mobile-card" style={{ fontSize: 12 }}>
        <b>Filter:</b> All sections ▾ · Risk: All ▾ · Sort: Risk ↓
      </div>
      {data.map((row) => (
        <article
          key={row.id}
          className="mobile-card"
          style={{ background: row.risk === 'critical' ? '#7C2D12' : undefined }}
        >
          <header style={{ display: 'flex', justifyContent: 'space-between' }}>
            <b>{row.name}</b>
            <RiskBadge level={row.risk} mode="mobile" />
          </header>
          <p style={{ fontSize: 11, opacity: 0.7, margin: '2px 0 6px 0' }}>
            {row.section} · {row.concept} {row.cds?.toFixed(2)}
            {row.delta != null && (row.delta >= 0 ? ` ▲+${row.delta.toFixed(2)}` : ` ▼${row.delta.toFixed(2)}`)}
            {row.fails != null && ` · ${row.fails} fails`}
          </p>
          <div style={{ display: 'flex', gap: 6, flexWrap: 'wrap' }}>
            <button type="button" className="mobile-list-row__btn" onClick={() => onView?.(row)}>View</button>
            <button type="button" className="mobile-list-row__btn" onClick={() => onMessage?.(row)}>Message</button>
            <button type="button" className="mobile-list-row__btn mobile-list-row__btn--primary" onClick={() => onIntervene?.(row)}>Intervene</button>
          </div>
        </article>
      ))}
      <p style={{ fontSize: 11, opacity: 0.5, textAlign: 'center', marginTop: 8 }}>
        swipe ◀ dismiss · swipe ▶ flag · long-press history
      </p>
    </section>
  );
}
