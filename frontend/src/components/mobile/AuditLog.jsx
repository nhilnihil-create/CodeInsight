// frontend/src/components/mobile/AuditLog.jsx
// Spec §5.4. Recent audit log entries, last 50, no filters on phone.
// Wire format: [{ id, action, actor, target, createdAt, summary }]

export function AuditLog({ data, onTap }) {
  if (!data || data.length === 0) {
    return <p style={{ padding: 16, opacity: 0.6 }}>No recent activity.</p>;
  }
  return (
    <section>
      {data.map((row) => (
        <button
          key={row.id}
          type="button"
          onClick={() => onTap?.(row)}
          className="mobile-card"
          style={{ display: 'block', width: '100%', textAlign: 'left', color: 'inherit' }}
        >
          <div style={{ fontSize: 13, fontWeight: 600 }}>{row.action}</div>
          <div style={{ fontSize: 11, opacity: 0.7 }}>{row.actor} → {row.target} · {row.createdAt}</div>
        </button>
      ))}
    </section>
  );
}
