// frontend/src/components/mobile/EvaluationProgress.jsx
// Spec §5.3. Single primary action for admin: "Review pending evaluations (N)".
// Wire format: { pendingCount }

export function EvaluationProgress({ data }) {
  if (!data) return null;
  return (
    <a
      href="/admin/evaluation"
      className="mobile-card"
      style={{
        display: 'block', textAlign: 'center',
        background: '#7C3AED', color: '#F8FAFC', textDecoration: 'none',
      }}
    >
      <div style={{ fontWeight: 600 }}>
        ▶ Review pending evaluations ({data.pendingCount ?? 0})
      </div>
      <div style={{ fontSize: 11, opacity: 0.7, marginTop: 2 }}>
        ISO/IEC 25010 instrument
      </div>
    </a>
  );
}
