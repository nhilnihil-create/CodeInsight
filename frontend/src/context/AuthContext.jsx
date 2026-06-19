import { createContext, useContext, useState, useEffect, useCallback } from 'react';
import api from '../services/api';

const AuthContext = createContext(null);

export function AuthProvider({ children }) {
  const [user, setUser] = useState(null);
  const [isLoggedIn, setIsLoggedIn] = useState(false);
  const [loading, setLoading] = useState(true);

  // On mount, fetch current user — the httpOnly cookie proves the session.
  useEffect(() => {
    let cancelled = false;
    api
      .get('/api/auth/me')
      .then((res) => {
        if (!cancelled) {
          if (res.data) {
            setUser(res.data);
            setIsLoggedIn(true);
          } else {
            setIsLoggedIn(false);
          }
        }
      })
      .catch(() => {
        // No valid cookie — user is unauthenticated
      })
      .finally(() => {
        if (!cancelled) setLoading(false);
      });
    return () => { cancelled = true; };
  }, []);

  const login = useCallback((newUser) => {
    // The backend already set the httpOnly cookie on the login response.
    // We only update client-side state here.
    setUser(newUser);
    setIsLoggedIn(true);
  }, []);

  const logout = useCallback(async () => {
    // Call the backend logout endpoint to clear the httpOnly cookie,
    // then wipe client-side state.
    try { await api.post('/api/auth/logout'); } catch { /* best-effort */ }
    setUser(null);
    setIsLoggedIn(false);
  }, []);

  if (loading) {
    return <div className="loading">Loading...</div>;
  }

  return (
    <AuthContext.Provider value={{ user, isLoggedIn, login, logout }}>
      {children}
    </AuthContext.Provider>
  );
}

export const useAuth = () => useContext(AuthContext);
