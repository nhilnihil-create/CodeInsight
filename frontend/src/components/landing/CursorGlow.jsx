import { useEffect } from 'react';
import {
  motion,
  useMotionValue,
  useSpring,
  useTransform,
} from 'framer-motion';

const GLOW_SIZE = 600;

/**
 * CursorGlow
 * Page-level mouse spotlight: a 600px radial glow that trails the cursor
 * with spring smoothing.
 */
export default function CursorGlow() {

  const mouseX = useMotionValue(-1000);
  const mouseY = useMotionValue(-1000);

  const springX = useSpring(mouseX, { stiffness: 50, damping: 20, mass: 0.5 });
  const springY = useSpring(mouseY, { stiffness: 50, damping: 20, mass: 0.5 });

  // Center the glow on the cursor.
  const x = useTransform(springX, (v) => v - GLOW_SIZE / 2);
  const y = useTransform(springY, (v) => v - GLOW_SIZE / 2);

  useEffect(() => {
    const onPointerMove = (e) => {
      mouseX.set(e.clientX);
      mouseY.set(e.clientY);
    };
    window.addEventListener('pointermove', onPointerMove, { passive: true });
    return () => window.removeEventListener('pointermove', onPointerMove);
  }, [mouseX, mouseY]);

  return (
    <motion.div
      aria-hidden="true"
      className="pointer-events-none fixed left-0 top-0 z-0 will-change-transform"
      style={{
        x,
        y,
        width: GLOW_SIZE,
        height: GLOW_SIZE,
        background:
          'radial-gradient(circle at center, hsl(var(--primary) / 0.06), transparent 60%)',
      }}
    />
  );
}
