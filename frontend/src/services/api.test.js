import { describe, it, expect, vi, beforeEach } from 'vitest';

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
