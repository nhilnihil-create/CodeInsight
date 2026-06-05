// frontend/src/hooks/use-mobile.js
//
// Public surface:
//   - useIsMobile(query?)    -> boolean (back-compat; default 768px to match Tailwind md)
//   - useMode()              -> 'mobile' | 'tablet' | 'desktop' (spec: 640/1024)
//   - breakpointFromWidth(n) -> 'mobile' | 'tablet' | 'desktop' (pure helper)
//
// The default useIsMobile boundary (768px) is intentionally different from
// useMode's 640/1024 boundary -- existing callers expect the Tailwind `md` line.

import { useEffect, useState } from "react";

export const MOBILE_MAX = 639;
export const TABLET_MAX = 1023;

export function breakpointFromWidth(width) {
  if (width <= MOBILE_MAX) return "mobile";
  if (width <= TABLET_MAX) return "tablet";
  return "desktop";
}

export function useMode() {
  const [mode, setMode] = useState(() => {
    if (typeof window === "undefined") return "desktop";
    return breakpointFromWidth(window.innerWidth);
  });

  useEffect(() => {
    if (typeof window === "undefined") return;
    if (typeof window.matchMedia !== "function") return;
    const mql = window.matchMedia("(max-width: 1023px)");
    const onChange = () => setMode(breakpointFromWidth(window.innerWidth));
    if (mql.addEventListener) mql.addEventListener("change", onChange);
    window.addEventListener("resize", onChange);
    return () => {
      if (mql.removeEventListener) mql.removeEventListener("change", onChange);
      window.removeEventListener("resize", onChange);
    };
  }, []);

  return mode;
}

/**
 * Returns true when the viewport is below Tailwind's `md` breakpoint (768px).
 * Mirrors the shadcn/ui use-mobile hook so the sidebar/layout can switch
 * between mobile drawer and desktop rail layouts.
 */
export function useIsMobile(query = "(max-width: 767px)") {
  const [isMobile, setIsMobile] = useState(
    () => typeof window !== "undefined" && window.matchMedia(query).matches,
  );

  useEffect(() => {
    if (typeof window === "undefined") return;
    const mql = window.matchMedia(query);
    const onChange = (e) => setIsMobile(e.matches);
    mql.addEventListener("change", onChange);
    return () => mql.removeEventListener("change", onChange);
  }, [query]);

  return isMobile;
}

export default useIsMobile;
