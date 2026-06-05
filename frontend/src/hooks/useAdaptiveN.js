// frontend/src/hooks/useAdaptiveN.js
import { useEffect, useState } from 'react';

export const DEFAULT_CHROME_HEIGHT = 104;   // 48 (app bar) + 56 (bottom nav)
export const DEFAULT_PRIMARY_HEIGHT = 200; // primary widget
export const DEFAULT_ROW_HEIGHT = 88;      // one queue row

/**
 * Pure formula: how many rows fit in the available viewport space.
 * Spec: min(5, floor((viewportHeight - chromeHeight - primaryHeight) / rowHeight))
 */
export function computeN(viewportHeight, chromeHeight = DEFAULT_CHROME_HEIGHT,
                        primaryHeight = DEFAULT_PRIMARY_HEIGHT,
                        rowHeight = DEFAULT_ROW_HEIGHT) {
  if (viewportHeight <= 0) return 1;
  const available = viewportHeight - chromeHeight - primaryHeight;
  const fitted = Math.floor(available / rowHeight);
  return Math.max(1, Math.min(5, fitted));
}

/**
 * React hook: re-runs computeN on window resize, throttled to rAF.
 */
export function useAdaptiveN(chromeHeight, primaryHeight, rowHeight) {
  const [n, setN] = useState(() => {
    if (typeof window === 'undefined') return 5;
    return computeN(window.innerHeight, chromeHeight, primaryHeight, rowHeight);
  });

  useEffect(() => {
    let raf = 0;
    const onResize = () => {
      cancelAnimationFrame(raf);
      raf = requestAnimationFrame(() => {
        setN(computeN(window.innerHeight, chromeHeight, primaryHeight, rowHeight));
      });
    };
    window.addEventListener('resize', onResize);
    return () => {
      window.removeEventListener('resize', onResize);
      cancelAnimationFrame(raf);
    };
  }, [chromeHeight, primaryHeight, rowHeight]);

  return n;
}
