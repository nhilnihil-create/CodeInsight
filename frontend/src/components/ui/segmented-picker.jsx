import { useRef, useState, useEffect, useCallback } from "react";
import { motion } from "framer-motion";
import { cn } from "@/lib/utils";

/**
 * SegmentedPicker
 * Edge-to-edge floating category selector with a moving translucent
 * backdrop indicator powered by Framer Motion. Replaces the blocky
 * PeriodSelector and tab bars.
 *
 * Props:
 *   - value       string     currently selected key
 *   - onChange    (key: string) => void
 *   - options     Array<{ key: string, label: string, icon?: ReactNode }>
 *   - className   string
 *   - size        "sm" | "md"
 */
export default function SegmentedPicker({
  value,
  onChange,
  options = [],
  className,
  size = "md",
}) {
  const containerRef = useRef(null);
  const [indicator, setIndicator] = useState({ left: 0, width: 0 });

  const updateIndicator = useCallback(() => {
    if (!containerRef.current) return;
    const activeIdx = options.findIndex((o) => o.key === value);
    if (activeIdx < 0) return;

    const buttons = containerRef.current.querySelectorAll("[data-picker-btn]");
    const btn = buttons[activeIdx];
    if (!btn) return;

    const containerRect = containerRef.current.getBoundingClientRect();
    const btnRect = btn.getBoundingClientRect();

    setIndicator({
      left: btnRect.left - containerRect.left,
      width: btnRect.width,
    });
  }, [value, options]);

  useEffect(() => {
    updateIndicator();
    window.addEventListener("resize", updateIndicator);
    return () => window.removeEventListener("resize", updateIndicator);
  }, [updateIndicator]);

  const isSm = size === "sm";

  return (
    <div
      ref={containerRef}
      role="radiogroup"
      aria-label="Filter"
      className={cn(
        "relative inline-flex items-center gap-0 rounded-lg",
        "bg-white/[0.04] border border-white/[0.06] p-1",
        isSm ? "h-8" : "h-9",
        className
      )}
    >
      {/* Animated backdrop indicator */}
      <motion.div
        className="picker-indicator"
        animate={{ left: indicator.left, width: indicator.width }}
        transition={{ type: "spring", stiffness: 400, damping: 30 }}
      />

      {options.map((opt) => {
        const isActive = opt.key === value;
        return (
          <button
            key={opt.key}
            type="button"
            role="radio"
            aria-checked={isActive}
            data-picker-btn
            onClick={() => onChange?.(opt.key)}
            className={cn(
              "relative z-10 inline-flex items-center justify-center gap-1.5",
              "font-medium rounded-md transition-colors cursor-pointer",
              "select-none whitespace-nowrap",
              isSm ? "px-2.5 text-[11px]" : "px-3.5 text-xs",
              isActive
                ? "text-foreground"
                : "text-muted-foreground hover:text-foreground/80"
            )}
          >
            {opt.icon}
            {opt.label}
          </button>
        );
      })}
    </div>
  );
}
