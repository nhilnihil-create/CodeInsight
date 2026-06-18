import React from "react";
import { motion } from "framer-motion";
import { cn } from "@/lib/utils";

/**
 * MotionContainer
 * Staggered page-load animation wrapper using Framer Motion.
 * Children float up along Y-axis sequentially.
 *
 * Simple approach: wraps each child in a motion.div directly,
 * avoiding motion.create/forwardRef ref-chain issues.
 *
 * Props:
 *   - className   string
 *   - stagger     number  — delay between children (default 0.06s)
 *   - delay       number  — initial delay before first child (default 0.1s)
 *   - duration    number  — animation duration (default 0.5s)
 *   - y           number  — Y offset to animate from (default 15)
 *   - children    ReactNode
 */
export default function MotionContainer({
  className,
  stagger = 0.06,
  delay = 0.1,
  duration = 0.5,
  y = 15,
  children,
}) {
  const items = React.Children.toArray(children);

  return (
    <div className={cn("space-y-5", className)}>
      {items.map((child, i) => (
        <motion.div
          key={child.key || i}
          initial={{ opacity: 0, y }}
          animate={{ opacity: 1, y: 0 }}
          transition={{
            duration,
            delay: delay + i * stagger,
            ease: [0.25, 0.46, 0.45, 0.94],
          }}
        >
          {child}
        </motion.div>
      ))}
    </div>
  );
}
