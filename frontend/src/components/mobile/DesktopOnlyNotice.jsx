// frontend/src/components/mobile/DesktopOnlyNotice.jsx
// Spec §5.3. Honest disclosure: which features are desktop-only.

export function DesktopOnlyNotice({ copy }) {
  return (
    <p style={{ fontSize: 11, opacity: 0.6, padding: '8px 12px' }}>▸ {copy}</p>
  );
}
