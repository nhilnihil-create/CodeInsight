import { describe, it, expect, vi, beforeEach, afterEach } from 'vitest';
import { renderHook, waitFor, act } from '@testing-library/react';
import { StudentProvider, useStudentContext } from './StudentContext';

vi.mock('@/services/api');

vi.mock('@/context/AuthContext', () => ({
  useAuth: () => ({ user: { role: 'student' } }),
}));

import api from '@/services/api';

const STORAGE_KEY = 'codeinsight:activeSection';

const wrapper = ({ children }) => <StudentProvider>{children}</StudentProvider>;

function renderStudentContext() {
  return renderHook(() => useStudentContext(), { wrapper });
}

describe('StudentContext', () => {
  beforeEach(() => {
    vi.clearAllMocks();
    localStorage.clear();
  });

  afterEach(() => {
    localStorage.clear();
  });

  it('loads enrolled sections without auto-activating one when nothing is stored', async () => {
    api.get.mockResolvedValue({
      data: [{ id: 1, name: 'CS101 A' }, { id: 2, name: 'CS101 B' }],
    });

    const { result } = renderStudentContext();

    await waitFor(() => expect(result.current.hasSections).toBe(true));
    expect(result.current.sections).toHaveLength(2);
    expect(result.current.activeSectionId).toBeNull();
    expect(api.get).toHaveBeenCalledWith('/api/sections');
  });

  it('reads the stored active section from localStorage', async () => {
    localStorage.setItem(STORAGE_KEY, '42');
    api.get.mockResolvedValue({
      data: [{ id: 41, name: 'A' }, { id: 42, name: 'B' }],
    });

    const { result } = renderStudentContext();

    await waitFor(() => expect(result.current.hasSections).toBe(true));
    expect(result.current.activeSectionId).toBe(42);
  });

  it('leaves the active section unset when the stored id is no longer enrolled', async () => {
    localStorage.setItem(STORAGE_KEY, '99');
    api.get.mockResolvedValue({
      data: [{ id: 7, name: 'CS101 C' }],
    });

    const { result } = renderStudentContext();

    await waitFor(() => expect(result.current.hasSections).toBe(true));
    expect(result.current.sections).toHaveLength(1);
    expect(result.current.activeSectionId).toBeNull();
  });

  it('setActiveSectionId switches and persists the active section', async () => {
    api.get.mockResolvedValue({
      data: [{ id: 1, name: 'A' }, { id: 2, name: 'B' }],
    });

    const { result } = renderStudentContext();
    await waitFor(() => expect(result.current.hasSections).toBe(true));

    act(() => { result.current.setActiveSectionId(2); });

    expect(result.current.activeSectionId).toBe(2);
    expect(localStorage.getItem(STORAGE_KEY)).toBe('2');
  });

  it('reports no sections when the API returns an empty list', async () => {
    api.get.mockResolvedValue({ data: [] });

    const { result } = renderStudentContext();

    await waitFor(() => expect(result.current.checking).toBe(false));
    expect(result.current.hasSections).toBe(false);
    expect(result.current.activeSectionId).toBeNull();
  });

  it('handles API errors without crashing', async () => {
    api.get.mockRejectedValue(new Error('Network error'));

    const { result } = renderStudentContext();

    await waitFor(() => expect(result.current.checking).toBe(false));
    expect(result.current.hasSections).toBe(false);
    expect(result.current.error).toBe(true);
    expect(result.current.sections).toEqual([]);
    expect(result.current.activeSectionId).toBeNull();
  });

  it('clears error and recovers after a successful recheck', async () => {
    api.get.mockRejectedValueOnce(new Error('Network error'));
    api.get.mockResolvedValueOnce({ data: [{ id: 1, name: 'CS101 A' }] });

    const { result } = renderStudentContext();

    await waitFor(() => expect(result.current.error).toBe(true));

    await act(() => result.current.recheck());

    expect(result.current.error).toBe(false);
    expect(result.current.hasSections).toBe(true);
  });

  it('keeps last-known-good sections and active section when a recheck fails', async () => {
    localStorage.setItem(STORAGE_KEY, '42');
    api.get.mockResolvedValue({ data: [{ id: 42, name: 'CS101 B' }] });

    const { result } = renderStudentContext();

    await waitFor(() => expect(result.current.hasSections).toBe(true));
    expect(result.current.activeSectionId).toBe(42);

    api.get.mockRejectedValueOnce(new Error('Network error'));
    await act(() => result.current.recheck());

    expect(result.current.error).toBe(true);
    expect(result.current.sections).toHaveLength(1);
    expect(result.current.activeSectionId).toBe(42);
  });
});
