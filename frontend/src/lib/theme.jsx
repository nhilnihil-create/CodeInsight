import { createContext, useContext, useEffect, useLayoutEffect, useMemo, useState } from 'react';

const STORAGE_KEY = 'codeinsight:theme';
const VALID_THEMES = ['light', 'dark'];
const DEFAULT_THEME = 'light';

/**
 * Theme system — see spec §2.4.
 *
 * - 2 themes: 'light' (default, Frontend-Design blue), 'dark' (pre-design dark teal).
 * - localStorage key: 'codeinsight:theme'
 * - Mirrors the active theme to <html data-theme="..."> on mount + on change.
 * - On first load with no localStorage value, no data-theme attribute is set:
 *   the :root tokens in index.css (the Frontend-Design light palette) apply.
 * - If localStorage is unavailable (private mode, etc.) we fall back to in-memory
 *   state; the toggle still works for the session but doesn't persist.
 * - useLayoutEffect (not useEffect) prevents flash of wrong theme on refresh.
 */
const ThemeContext = createContext({
  theme: DEFAULT_THEME,
  setTheme: () => {},
});

function readStoredTheme() {
  try {
    const raw = window.localStorage.getItem(STORAGE_KEY);
    if (VALID_THEMES.includes(raw)) return raw;
  } catch {
    // localStorage unavailable — fall through to default
  }
  return DEFAULT_THEME;
}

function writeStoredTheme(theme) {
  try {
    window.localStorage.setItem(STORAGE_KEY, theme);
  } catch {
    // best-effort; in-memory state is the source of truth for this session
  }
}

function applyThemeAttribute(theme) {
  const root = document.documentElement;
  if (theme === DEFAULT_THEME) {
    root.removeAttribute('data-theme');
  } else {
    root.setAttribute('data-theme', theme);
  }
}

export function ThemeProvider({ children }) {
  const [theme, setThemeState] = useState(DEFAULT_THEME);

  // Read localStorage synchronously before paint to avoid FOUC.
  useLayoutEffect(() => {
    const initial = readStoredTheme();
    setThemeState(initial);
    applyThemeAttribute(initial);
  }, []);

  // Mirror to <html data-theme> whenever the React state changes (toggle clicks).
  useEffect(() => {
    applyThemeAttribute(theme);
  }, [theme]);

  const value = useMemo(
    () => ({
      theme,
      setTheme: (next) => {
        if (!VALID_THEMES.includes(next)) return;
        setThemeState(next);
        writeStoredTheme(next);
      },
    }),
    [theme]
  );

  return <ThemeContext.Provider value={value}>{children}</ThemeContext.Provider>;
}

export function useTheme() {
  return useContext(ThemeContext);
}

export { STORAGE_KEY, VALID_THEMES, DEFAULT_THEME };
