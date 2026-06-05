// frontend/src/components/mobile/IntegrityDrillNotice.jsx
// Spec §5.4. Static copy: "Flag review requires tablet or desktop."

export function IntegrityDrillNotice({ copy = 'Flag review requires tablet or desktop.' }) {
  return (
    <p style={{ fontSize: 11, opacity: 0.6, padding: '8px 12px', textAlign: 'center' }}>
      {copy}
    </p>
  );
}
