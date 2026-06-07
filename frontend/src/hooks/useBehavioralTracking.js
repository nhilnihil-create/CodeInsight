import { useEffect, useRef } from "react";

/**
 * useBehavioralTracking
 *
 * Passive event collection for academic-integrity signal #5
 * (per spec §5.4.5 "Passive Behavioral Logging").
 *
 * Captures: tab blur/focus, paste, keystroke bursts, idle/active.
 * Returns a ref to the buffer that is later attached to the
 * submission request as `behavioralEvents` (see backend
 * validators.submitCode).
 *
 * Usage:
 *   const { eventsRef, captureEvent } = useBehavioralTracking({ idleMs: 30000 });
 *   onSubmit={() => api.post('/api/student/exercises/:id/submit', { code, behavioralEvents: eventsRef.current });
 */
export function useBehavioralTracking({ idleMs = 30_000, burstThreshold = 12, burstWindowMs = 1500 } = {}) {
  const eventsRef = useRef([]);
  const lastKeystrokeAtRef = useRef(0);
  const keystrokeWindowRef = useRef([]);
  const idleTimerRef = useRef(null);
  const isIdleRef = useRef(false);

  const captureEvent = (type, payload = {}) => {
    eventsRef.current.push({
      type,
      timestamp: new Date().toISOString(),
      payload,
    });
  };

  useEffect(() => {
    if (typeof window === 'undefined') return undefined;

    const onVisibility = () => {
      if (document.hidden) captureEvent('tab_blur');
      else captureEvent('tab_focus');
    };
    const onPaste = (e) => {
      const text = e.clipboardData?.getData('text') || '';
      captureEvent('paste', { length: text.length });
    };
    const onKeyDown = () => {
      const now = performance.now();
      lastKeystrokeAtRef.current = now;
      keystrokeWindowRef.current.push(now);
      // prune window
      keystrokeWindowRef.current = keystrokeWindowRef.current.filter(
        (t) => now - t <= burstWindowMs
      );
      if (keystrokeWindowRef.current.length >= burstThreshold) {
        captureEvent('keystroke_burst', {
          count: keystrokeWindowRef.current.length,
          windowMs: burstWindowMs,
        });
        keystrokeWindowRef.current = [];
      }
      // wake from idle
      if (isIdleRef.current) {
        isIdleRef.current = false;
        captureEvent('idle_end');
      }
      if (idleTimerRef.current) clearTimeout(idleTimerRef.current);
      idleTimerRef.current = setTimeout(() => {
        isIdleRef.current = true;
        captureEvent('idle_start');
      }, idleMs);
    };

    document.addEventListener('visibilitychange', onVisibility);
    document.addEventListener('paste', onPaste);
    document.addEventListener('keydown', onKeyDown);

    return () => {
      document.removeEventListener('visibilitychange', onVisibility);
      document.removeEventListener('paste', onPaste);
      document.removeEventListener('keydown', onKeyDown);
      if (idleTimerRef.current) clearTimeout(idleTimerRef.current);
    };
  }, [idleMs, burstThreshold, burstWindowMs]);

  return { eventsRef, captureEvent };
}
