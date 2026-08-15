import axios from 'axios';

// The deployed backend runs on Render.com's free tier, which spins down after
// ~15 min of inactivity. A cold start can take 30–60s while the dyno wakes, so
// requests need a generous timeout plus a retry-with-backoff — otherwise the
// first hit after idle hangs forever and charts silently never load.
export const REQUEST_TIMEOUT_MS = 75_000;
export const MAX_RETRIES = 2;
export const RETRY_DELAYS_MS = [3_000, 8_000];

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
 * - Only idempotent methods (GET/HEAD) — a retried POST/PUT could double-submit.
 * - Only on timeout / network failure / Render wake-up statuses (502/503/504).
 * - Never on 4xx auth errors (401/403/404…).
 */
export function isRetryableError(err) {
  const cfg = err?.config;
  if (!cfg) return false;
  const method = String(cfg.method || '').toLowerCase();
  if (method !== 'get' && method !== 'head') return false;
  const status = err.response?.status;
  return (
    err.code === 'ECONNABORTED' || // request timed out
    !err.response || // network failure (dyno still waking / connection reset)
    status === 502 || status === 503 || status === 504
  );
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
