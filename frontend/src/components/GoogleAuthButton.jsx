import { useEffect, useRef, useCallback } from 'react';
import { useNavigate } from 'react-router-dom';
import { useAuth } from '../context/AuthContext';
import api from '../services/api';

const GSI_SCRIPT_ID = 'gsi-client-script';
const GSI_SCRIPT_SRC = 'https://accounts.google.com/gsi/client';

/**
 * Google Sign-In button (GIS). Renders a placeholder that Google's script
 * upgrades in place, then exchanges the ID token for a session via
 * POST /api/auth/google.
 *
 * Reads VITE_GOOGLE_CLIENT_ID. When it is unset the button degrades
 * gracefully: a muted dev hint in development, nothing at all in
 * production/e2e builds (so CI and prod are unaffected).
 */
export default function GoogleAuthButton({ onError }) {
  const containerRef = useRef(null);
  const onErrorRef = useRef(onError);
  onErrorRef.current = onError;
  const { login } = useAuth() || {};
  const navigate = useNavigate();

  const clientId = import.meta.env.VITE_GOOGLE_CLIENT_ID;

  const handleCredentialResponse = useCallback(async (response) => {
    try {
      const res = await api.post('/api/auth/google', { credential: response?.credential });
      if (login) login(res.data.user);
      const role = res.data.user.role;
      const dest = role === 'instructor'
        ? '/instructor/dashboard'
        : role === 'admin' ? '/admin' : '/student/dashboard';
      navigate(dest, { replace: true });
    } catch (err) {
      if (onErrorRef.current) {
        onErrorRef.current(err.response?.data?.message || 'Google sign-in failed');
      }
    }
  }, [login, navigate]);

  useEffect(() => {
    if (typeof window === 'undefined') return undefined;
    if (!clientId) return undefined;

    const initGoogleButton = () => {
      if (!window.google?.accounts?.id || !containerRef.current) return;
      window.google.accounts.id.initialize({ client_id: clientId, callback: handleCredentialResponse });
      window.google.accounts.id.renderButton(containerRef.current, {
        theme: 'outline',
        size: 'large',
        text: 'continue_with',
        shape: 'rectangular',
        width: 320,
        locale: 'en',
      });
    };

    // Already loaded (or stubbed in tests) — init directly.
    if (window.google?.accounts?.id) {
      initGoogleButton();
      return undefined;
    }

    // Idempotently inject the GIS loader script (guarded against double-inject).
    let script = document.getElementById(GSI_SCRIPT_ID);
    if (!script) {
      script = document.createElement('script');
      script.id = GSI_SCRIPT_ID;
      script.src = GSI_SCRIPT_SRC;
      script.async = true;
      script.defer = true;
      document.head.appendChild(script);
    }
    script.addEventListener('load', initGoogleButton);

    return () => {
      script.removeEventListener('load', initGoogleButton);
      window.google?.accounts?.id?.cancel?.();
    };
  }, [clientId, handleCredentialResponse]);

  if (!clientId) {
    if (!import.meta.env.DEV) return null;
    return (
      <div className="rounded-md border border-dashed border-border px-3 py-2.5 text-center text-[11px] text-muted-foreground">
        Google sign-in is not configured — set VITE_GOOGLE_CLIENT_ID
      </div>
    );
  }

  return <div ref={containerRef} className="flex justify-center" />;
}
