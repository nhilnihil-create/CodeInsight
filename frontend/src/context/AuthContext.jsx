import { createContext, useContext, useState, useEffect } from 'react';

const AuthContext = createContext(null);

export function AuthProvider({ children }) {
  const [user, setUser] = useState(null);
  const [token, setToken] = useState(null);
  const [isLoggedIn, setIsLoggedIn] = useState(false);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    const t = localStorage.getItem('ci_token');
    const u = localStorage.getItem('ci_user');
    if (t && u) {
      setToken(t);
      setUser(JSON.parse(u));
      setIsLoggedIn(true);
    }
    setLoading(false);
  }, []);

  const login = (newToken, newUser) => {
    localStorage.setItem('ci_token', newToken);
    localStorage.setItem('ci_user', JSON.stringify(newUser));
    setToken(newToken);
    setUser(newUser);
    setIsLoggedIn(true);
  };

  const logout = () => {
    localStorage.removeItem('ci_token');
    localStorage.removeItem('ci_user');
    setToken(null);
    setUser(null);
    setIsLoggedIn(false);
  };

  if (loading) {
    return <div className="loading">Loading...</div>;
  }

  return (
    <AuthContext.Provider value={{ user, token, isLoggedIn, login, logout }}>
      {children}
    </AuthContext.Provider>
  );
}

export const useAuth = () => useContext(AuthContext);
