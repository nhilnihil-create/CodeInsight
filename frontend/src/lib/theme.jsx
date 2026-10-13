import { createContext, useCallback, useContext, useEffect, useMemo, useState } from 'react';

export const DARK_THEME = 'dark';
export const LIGHT_THEME = 'light';
export const SYSTEM_THEME = 'system';

const STORAGE_KEY = 'codeinsight-theme';
const THEMES = [LIGHT_THEME, DARK_THEME, SYSTEM_THEME];

// Standard dark navy used by the OS chrome / splash before CSS loads.
const META_THEMES = { dark: '#0B0F19', light: '#F8FAFC' };

function systemIsDark() {
  if (typeof window === 'undefined' || !window.matchMedia) return false;
  return window.matchMedia('(prefers-color-scheme: dark)').matches;
}

function readStored() {
  try {
    const v = window.localStorage.getItem(STORAGE_KEY);
    return THEMES.includes(v) ? v : SYSTEM_THEME;
  } catch {
    return SYSTEM_THEME;
  }
}

export function resolveTheme(mode) {
  if (mode === LIGHT_THEME) return LIGHT_THEME;
  if (mode === DARK_THEME) return DARK_THEME;
  return systemIsDark() ? DARK_THEME : LIGHT_THEME;
}

/** Apply the resolved theme to <html>. Idempotent. Safe to call pre-React. */
export function applyTheme(mode) {
  const resolved = resolveTheme(mode);
  if (typeof document === 'undefined') return resolved;
  const root = document.documentElement;
  // NOTE: only data-theme is toggled — never a .dark class. Dead `dark:`
  // utilities in the codebase never applied, and activating them now would
  // alter dark-mode rendering. Light styles use the `light:` variant below.
  root.setAttribute('data-theme', resolved);
  // Native form controls, scrollbars and overscroll follow the theme.
  root.style.colorScheme = resolved;
  const meta = document.querySelector('meta[name="theme-color"]');
  if (meta) meta.setAttribute('content', META_THEMES[resolved]);
  return resolved;
}

const ThemeContext = createContext({
  theme: DARK_THEME,
  mode: SYSTEM_THEME,
  setTheme: () => {},
});

export function ThemeProvider({ children }) {
  const [mode, setMode] = useState(() => {
    if (typeof window === 'undefined') return SYSTEM_THEME;
    return readStored();
  });
  const [theme, setResolved] = useState(() => resolveTheme(readStoredSafe()));

  function readStoredSafe() {
    try {
      return readStored();
    } catch {
      return SYSTEM_THEME;
    }
  }

  const setTheme = useCallback((next) => {
    if (!THEMES.includes(next)) return;
    try {
      window.localStorage.setItem(STORAGE_KEY, next);
    } catch {
      /* private mode — session-only */
    }
    setMode(next);
    setResolved(applyTheme(next));
  }, []);

  // Apply on mount (covers the case where the pre-paint script didn't run,
  // e.g. cached HTML) and follow OS changes while in system mode.
  useEffect(() => {
    setResolved(applyTheme(mode));
    if (mode !== SYSTEM_THEME || typeof window === 'undefined' || !window.matchMedia) return undefined;
    const mq = window.matchMedia('(prefers-color-scheme: dark)');
    const onChange = () => setResolved(applyTheme(SYSTEM_THEME));
    if (typeof mq.addEventListener === 'function') mq.addEventListener('change', onChange);
    else if (typeof mq.addListener === 'function') mq.addListener(onChange);
    return () => {
      if (typeof mq.removeEventListener === 'function') mq.removeEventListener('change', onChange);
      else if (typeof mq.removeListener === 'function') mq.removeListener(onChange);
    };
  }, [mode]);

  const value = useMemo(() => ({ theme, mode, setTheme }), [theme, mode, setTheme]);
  return <ThemeContext.Provider value={value}>{children}</ThemeContext.Provider>;
}

export function useTheme() {
  return useContext(ThemeContext);
}
