// frontend/src/components/mobile/IntegrityFlagCount.jsx
// Spec §5.4. Flag count summary + drill.
// Wire format: { openCount, recentCritical }

export function IntegrityFlagCount({ data, onDrill }) {
  if (!data) return null;
  return (
    <button type="button" className="mobile-card" onClick={onDrill} style={{
      display: 'flex', justifyContent: 'space-between', alignItems: 'center', width: '100%',
      textAlign: 'left', color: 'inherit',
    }}>
      <span>Integrity flags open</span>
      <span style={{ background: data.openCount > 0 ? '#EF4444' : '#22C55E', color: '#450A0A', padding: '2px 8px', borderRadius: 4, fontWeight: 600 }}>
        {data.openCount}
      </span>
    </button>
  );
}
