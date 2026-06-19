import { describe, it, expect, vi, beforeEach, afterEach } from 'vitest';
import { renderHook, waitFor, act } from '@testing-library/react';
import useLastSection from './useLastSection';

vi.mock('@/services/api');

import api from '@/services/api';

const STORAGE_KEY = 'codeinsight:lastSection';

describe('useLastSection', () => {
  beforeEach(() => {
    vi.clearAllMocks();
    localStorage.clear();
  });

  afterEach(() => {
    localStorage.clear();
  });

  it('reads stored section from localStorage on mount', () => {
    localStorage.setItem(STORAGE_KEY, '42');

    const { result } = renderHook(() => useLastSection());

    expect(result.current[0]).toBe(42);
  });

  it('returns null and fetches when no stored section', async () => {
    api.get.mockResolvedValue({ data: [{ id: 10, name: 'Section A' }] });

    const { result } = renderHook(() => useLastSection());

    expect(result.current[0]).toBeNull();

    await waitFor(() => {
      expect(result.current[0]).toBe(10);
    });
  });

  it('persists to localStorage when update is called', async () => {
    api.get.mockResolvedValue({ data: [] });
    const { result } = renderHook(() => useLastSection());

    await waitFor(() => expect(result.current[0]).toBeNull());

    act(() => { result.current[1](99); });

    expect(localStorage.getItem(STORAGE_KEY)).toBe('99');
    expect(result.current[0]).toBe(99);
  });

  it('fetches first section when API returns multiple', async () => {
    api.get.mockResolvedValue({ data: [{ id: 1, name: 'First' }, { id: 2, name: 'Second' }] });

    const { result } = renderHook(() => useLastSection());

    await waitFor(() => expect(result.current[0]).toBe(1));
  });

  it('returns null when API returns empty array', async () => {
    api.get.mockResolvedValue({ data: [] });

    const { result } = renderHook(() => useLastSection());

    await waitFor(() => {
      expect(result.current[0]).toBeNull();
    });
  });

  it('handles API error without crashing', async () => {
    api.get.mockRejectedValue(new Error('Network error'));

    const { result } = renderHook(() => useLastSection());

    await waitFor(() => {
      expect(result.current[0]).toBeNull();
    });
  });

  it('handles non-array API response', async () => {
    api.get.mockResolvedValue({ data: null });

    const { result } = renderHook(() => useLastSection());

    await waitFor(() => {
      expect(result.current[0]).toBeNull();
    });
  });

  it('ignores stored value "all"', () => {
    localStorage.setItem(STORAGE_KEY, 'all');

    api.get.mockResolvedValue({ data: [{ id: 1 }] });

    const { result } = renderHook(() => useLastSection());

    expect(result.current[0]).toBeNull();
  });

  it('handles localStorage read errors gracefully', () => {
    const getItem = vi.spyOn(Storage.prototype, 'getItem').mockImplementation(() => {
      throw new Error('Storage error');
    });

    api.get.mockResolvedValue({ data: [{ id: 5 }] });

    const { result } = renderHook(() => useLastSection());

    expect(result.current[0]).toBeNull();
    getItem.mockRestore();
  });
});
