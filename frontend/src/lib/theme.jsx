import { createContext, useContext, useMemo } from 'react';

const DARK_THEME = 'dark';

const ThemeContext = createContext({
  theme: DARK_THEME,
  setTheme: () => {},
});

export function ThemeProvider({ children }) {
  const value = useMemo(
    () => ({
      theme: DARK_THEME,
      setTheme: () => {},
    }),
    []
  );

  return <ThemeContext.Provider value={value}>{children}</ThemeContext.Provider>;
}

export function useTheme() {
  return useContext(ThemeContext);
}

export { DARK_THEME };
