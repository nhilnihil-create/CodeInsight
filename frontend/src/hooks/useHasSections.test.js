import { describe, it, expect, vi, beforeEach } from 'vitest';
import { renderHook, waitFor } from '@testing-library/react';
import useHasSections from './useHasSections';

vi.mock('@/services/api');

import api from '@/services/api';

describe('useHasSections', () => {
  beforeEach(() => {
    vi.clearAllMocks();
  });

  it('returns hasSections=true when sections exist', async () => {
    api.get.mockResolvedValue({ data: [{ id: 1, name: 'CS101' }] });

    const { result } = renderHook(() => useHasSections());

    expect(result.current.checking).toBe(true);
    expect(result.current.hasSections).toBeNull();

    await waitFor(() => expect(result.current.checking).toBe(false));

    expect(result.current.hasSections).toBe(true);
  });

  it('returns hasSections=false when no sections exist', async () => {
    api.get.mockResolvedValue({ data: [] });

    const { result } = renderHook(() => useHasSections());

    await waitFor(() => expect(result.current.checking).toBe(false));

    expect(result.current.hasSections).toBe(false);
  });

  it('returns hasSections=false on API error', async () => {
    api.get.mockRejectedValue(new Error('Network error'));

    const { result } = renderHook(() => useHasSections());

    await waitFor(() => expect(result.current.checking).toBe(false));

    expect(result.current.hasSections).toBe(false);
  });

  it('handles non-array response gracefully', async () => {
    api.get.mockResolvedValue({ data: null });

    const { result } = renderHook(() => useHasSections());

    await waitFor(() => expect(result.current.checking).toBe(false));

    expect(result.current.hasSections).toBe(false);
  });

  it('provides recheck function', async () => {
    api.get
      .mockResolvedValueOnce({ data: [] })
      .mockResolvedValueOnce({ data: [{ id: 1 }] });

    const { result } = renderHook(() => useHasSections());

    await waitFor(() => expect(result.current.checking).toBe(false));
    expect(result.current.hasSections).toBe(false);

    await result.current.recheck();

    await waitFor(() => expect(result.current.hasSections).toBe(true));
  });
});
