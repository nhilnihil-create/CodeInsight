// frontend/src/components/mobile/PullToRefresh.jsx
// Spec §6.3. Pointer-based pull-to-refresh, 60px threshold, no library.

import { useRef, useState } from 'react';

const THRESHOLD = 60;

export function PullToRefresh({ onRefresh, children }) {
  const startY = useRef(null);
  const [pullY, setPullY] = useState(0);

  const onPointerDown = (e) => { startY.current = e.clientY; };
  const onPointerMove = (e) => {
    if (startY.current == null) return;
    const dy = e.clientY - startY.current;
    if (dy > 0) setPullY(Math.min(dy, THRESHOLD + 20));
  };
  const onPointerUp = () => {
    if (pullY >= THRESHOLD) onRefresh?.();
    setPullY(0);
    startY.current = null;
  };

  return (
    <div
      onPointerDown={onPointerDown}
      onPointerMove={onPointerMove}
      onPointerUp={onPointerUp}
      onPointerCancel={onPointerUp}
    >
      {pullY > 0 && (
        <p className="pull-to-refresh">
          {pullY >= THRESHOLD ? 'Release to refresh' : 'Pull to refresh'}
        </p>
      )}
      {children}
    </div>
  );
}
