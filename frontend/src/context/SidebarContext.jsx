import { createContext, useCallback, useContext, useEffect, useRef, useState } from 'react';

const SidebarContext = createContext();

const DESKTOP_QUERY = '(min-width: 1024px)';

export function SidebarProvider({ children }) {
  // Below lg the sidebar becomes an off-canvas drawer (closed by default);
  // at/above lg it is a persistent rail that remembers its last state.
  const [isOpen, setIsOpen] = useState(() => {
    if (typeof window === 'undefined') return true;
    return window.matchMedia(DESKTOP_QUERY).matches;
  });
  const desktopOpenRef = useRef(true);
  const isOpenRef = useRef(isOpen);

  useEffect(() => {
    isOpenRef.current = isOpen;
  }, [isOpen]);

  useEffect(() => {
    const mql = window.matchMedia(DESKTOP_QUERY);
    const handleChange = (e) => {
      if (e.matches) {
        // Back to desktop: restore the last desktop-sidebar choice.
        setIsOpen(desktopOpenRef.current);
      } else {
        // Below lg: remember the desktop choice, then close the drawer.
        desktopOpenRef.current = isOpenRef.current;
        setIsOpen(false);
      }
    };
    mql.addEventListener('change', handleChange);
    return () => mql.removeEventListener('change', handleChange);
  }, []);

  // Stable identities: Layout's "close drawer on navigation" effect depends on
  // setOpen, so an unstable (per-render) identity would re-run that effect and
  // slam the mobile drawer shut on every render. Memoizing keeps the effect
  // firing only on actual pathname changes.
  const toggleSidebar = useCallback(() => setIsOpen((prev) => !prev), []);
  const setOpen = useCallback((open) => setIsOpen(open), []);

  return (
    <SidebarContext.Provider value={{ isOpen, toggleSidebar, setOpen }}>
      {children}
    </SidebarContext.Provider>
  );
}

export function useSidebar() {
  const context = useContext(SidebarContext);
  if (!context) {
    throw new Error('useSidebar must be used within SidebarProvider');
  }
  return context;
}
