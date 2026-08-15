import { describe, it, expect, vi, beforeEach } from 'vitest';
import { isRetryableError, MAX_RETRIES, RETRY_DELAYS_MS, REQUEST_TIMEOUT_MS } from './api';

describe('API cold-start retry policy (isRetryableError)', () => {
  it('retries on 503 (Render dyno waking)', () => {
    expect(isRetryableError({ config: { method: 'get' }, response: { status: 503 } })).toBe(true);
  });

  it('retries on 502 and 504', () => {
    expect(isRetryableError({ config: { method: 'get' }, response: { status: 502 } })).toBe(true);
    expect(isRetryableError({ config: { method: 'get' }, response: { status: 504 } })).toBe(true);
  });

  it('retries on network failure (no response — connection reset while waking)', () => {
    expect(isRetryableError({ config: { method: 'get' }, message: 'Network Error' })).toBe(true);
  });

  it('retries on timeout (ECONNABORTED)', () => {
    expect(isRetryableError({ config: { method: 'get' }, code: 'ECONNABORTED' })).toBe(true);
  });

  it('does not retry 401/403/404 (auth/not-found errors)', () => {
    expect(isRetryableError({ config: { method: 'get' }, response: { status: 401 } })).toBe(false);
    expect(isRetryableError({ config: { method: 'get' }, response: { status: 403 } })).toBe(false);
    expect(isRetryableError({ config: { method: 'get' }, response: { status: 404 } })).toBe(false);
  });

  it('does not retry mutating methods (POST could double-submit)', () => {
    expect(isRetryableError({ config: { method: 'post', url: '/api/submissions' }, response: { status: 503 } })).toBe(false);
    expect(isRetryableError({ config: { method: 'put', url: '/api/x' }, response: { status: 503 } })).toBe(false);
    expect(isRetryableError({ config: { method: 'delete', url: '/api/x' }, response: { status: 503 } })).toBe(false);
    expect(isRetryableError({ config: { method: 'post', url: '/api/submissions' } })).toBe(false); // network failure on a submit
  });

  it('retries the login POST on cold-start failures (first request after idle)', () => {
    expect(isRetryableError({ config: { method: 'post', url: '/api/auth/login' }, response: { status: 503 } })).toBe(true);
    expect(isRetryableError({ config: { method: 'post', url: '/api/auth/login' } })).toBe(true); // connection closed mid-boot
    expect(isRetryableError({ config: { method: 'post', url: '/api/auth/login' }, code: 'ECONNABORTED' })).toBe(true);
  });

  it('never retries the login POST on 4xx (real auth failure, not a cold start)', () => {
    expect(isRetryableError({ config: { method: 'post', url: '/api/auth/login' }, response: { status: 401 } })).toBe(false);
    expect(isRetryableError({ config: { method: 'post', url: '/api/auth/login' }, response: { status: 400 } })).toBe(false);
  });

  it('returns false for malformed errors', () => {
    expect(isRetryableError(null)).toBe(false);
    expect(isRetryableError({})).toBe(false);
    expect(isRetryableError({ config: { method: 'get' } })).toBe(true); // no response at all = network-ish
  });

  it('exposes a generous timeout and bounded retries spanning the cold-start window', () => {
    expect(REQUEST_TIMEOUT_MS).toBeGreaterThanOrEqual(60_000);
    expect(MAX_RETRIES).toBeGreaterThanOrEqual(3);
    expect(RETRY_DELAYS_MS.length).toBe(MAX_RETRIES);
    // Delays grow (backoff) and total wait covers Render's ~30–60s wake-up.
    for (let i = 1; i < RETRY_DELAYS_MS.length; i++) {
      expect(RETRY_DELAYS_MS[i]).toBeGreaterThan(RETRY_DELAYS_MS[i - 1]);
    }
    const totalWait = RETRY_DELAYS_MS.reduce((a, b) => a + b, 0);
    expect(totalWait).toBeGreaterThanOrEqual(60_000);
  });
});

describe('API interceptor logic', () => {
  beforeEach(() => {
    vi.restoreAllMocks();
  });

  function createInterceptor() {
    const onFulfilled = (res) => res;
    const onRejected = (err) => {
      if (err.response?.status === 401 && window.location.pathname !== '/login') {
        window.location.href = '/login';
      }
      return Promise.reject(err);
    };
    return { onFulfilled, onRejected };
  }

  it('passes through successful responses', () => {
    const { onFulfilled } = createInterceptor();
    const response = { data: 'ok' };
    expect(onFulfilled(response)).toBe(response);
  });

  it('redirects to /login on 401 when not already there', async () => {
    Object.defineProperty(window, 'location', {
      value: { pathname: '/dashboard', href: '/dashboard' },
      writable: true,
    });

    const { onRejected } = createInterceptor();
    const error = { response: { status: 401 } };

    await expect(onRejected(error)).rejects.toEqual(error);
    expect(window.location.href).toBe('/login');
  });

  it('does not redirect on 401 when already on /login', async () => {
    Object.defineProperty(window, 'location', {
      value: { pathname: '/login', href: '/login' },
      writable: true,
    });

    const { onRejected } = createInterceptor();
    const error = { response: { status: 401 } };

    await expect(onRejected(error)).rejects.toEqual(error);
    expect(window.location.href).toBe('/login');
  });

  it('passes through non-401 errors', async () => {
    Object.defineProperty(window, 'location', {
      value: { pathname: '/dashboard', href: '/dashboard' },
      writable: true,
    });

    const { onRejected } = createInterceptor();
    const error = { response: { status: 403, data: 'Forbidden' } };

    await expect(onRejected(error)).rejects.toEqual(error);
    expect(window.location.href).toBe('/dashboard');
  });

  it('rejects errors without response', async () => {
    const { onRejected } = createInterceptor();
    const error = new Error('Network error');

    await expect(onRejected(error)).rejects.toEqual(error);
  });
});
