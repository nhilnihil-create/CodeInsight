import axios from 'axios';

// The deployed backend runs on Render.com's free tier, which spins down after
// ~15 min of inactivity. A cold start can take 30–60s while the dyno wakes, and
// Render's proxy can drop the connection (ERR_CONNECTION_CLOSED) during boot,
// so requests need a generous timeout plus a retry-with-backoff that spans the
// whole wake-up window — otherwise the first hit after idle fails fast and the
// UI never recovers.
export const REQUEST_TIMEOUT_MS = 75_000;
export const MAX_RETRIES = 5;
export const RETRY_DELAYS_MS = [3_000, 6_000, 12_000, 20_000, 30_000];

const api = axios.create({
  baseURL: import.meta.env.VITE_API_BASE_URL || (import.meta.env.DEV ? '' : 'http://127.0.0.1:5000'),
  withCredentials: true, // send httpOnly cookie with every request
  timeout: REQUEST_TIMEOUT_MS,
});

// No Authorization header interceptor — the JWT lives in the httpOnly
// ci_token cookie set by the backend and sent automatically via withCredentials.

const sleep = (ms) => new Promise((resolve) => setTimeout(resolve, ms));

/**
 * Decide whether a failed request is safe and worthwhile to retry.
 * - Idempotent methods (GET/HEAD) retry on timeout / network failure /
 *   Render wake-up statuses (502/503/504).
 * - The login POST is also retried on the same failures: it is the very first
 *   request a user makes after the backend sleeps, and a retried login is
 *   harmless (worst case a fresh session cookie). Never retried on 4xx — a
 *   401/403 response is a real auth failure, not a cold start.
 * - All other mutating methods (PUT/PATCH/DELETE…) are never retried — a
 *   retried submit could double-submit.
 */
export function isRetryableError(err) {
  const cfg = err?.config;
  if (!cfg) return false;
  const method = String(cfg.method || '').toLowerCase();
  const status = err.response?.status;
  const transportFailure = err.code === 'ECONNABORTED' || !err.response;
  const wakeUpStatus = status === 502 || status === 503 || status === 504;

  if (method === 'get' || method === 'head') {
    return transportFailure || wakeUpStatus;
  }
  if (method === 'post' && String(cfg.url || '').includes('/api/auth/login')) {
    return transportFailure || wakeUpStatus;
  }
  return false;
}

api.interceptors.response.use(
  res => res,
  async (err) => {
    const cfg = err.config;

    if (isRetryableError(err)) {
      const attempts = cfg._retried || 0;
      if (attempts < MAX_RETRIES) {
        cfg._retried = attempts + 1;
        const delay = RETRY_DELAYS_MS[attempts] ?? RETRY_DELAYS_MS[RETRY_DELAYS_MS.length - 1];
        await sleep(delay);
        try {
          return await api(cfg);
        } catch (retryErr) {
          // Fall through to the shared error handling below with the retry error.
          err = retryErr;
        }
      }
    }

    if (err.response?.status === 401 && window.location.pathname !== '/login') {
      // Cookie expired or cleared — redirect to login unless already there.
      window.location.href = '/login';
    }
    return Promise.reject(err);
  }
);

export default api;
