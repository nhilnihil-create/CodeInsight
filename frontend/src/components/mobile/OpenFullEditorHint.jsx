// frontend/src/components/mobile/OpenFullEditorHint.jsx
// Spec §5.4. CTA to switch to the full Monaco editor on tablet+.

export function OpenFullEditorHint({ copy = '↗ Open in full editor (tablet+)' }) {
  return (
    <a href="?mode=full" className="mobile-card" style={{
      display: 'block', textAlign: 'center', fontSize: 12, color: '#94A3B8', textDecoration: 'none',
    }}>
      {copy}
    </a>
  );
}
