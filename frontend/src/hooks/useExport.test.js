import { describe, it, expect, vi, beforeEach, afterEach } from 'vitest';
import { renderHook, act } from '@testing-library/react';
import useExport from './useExport';

vi.mock('@/services/exportApi', () => ({
  fetchExportBlob: vi.fn(),
  fetchVisualReportBlob: vi.fn(),
  triggerDownload: vi.fn(),
}));

vi.mock('sonner', () => ({
  toast: { success: vi.fn(), error: vi.fn() },
}));

import { fetchExportBlob, fetchVisualReportBlob, triggerDownload } from '@/services/exportApi';
import { toast } from 'sonner';

const BLOB = new Blob(['a,b']);

describe('useExport', () => {
  beforeEach(() => {
    vi.clearAllMocks();
    fetchExportBlob.mockResolvedValue({ blob: BLOB, fileName: 'roster_2026-08-12.csv' });
    fetchVisualReportBlob.mockResolvedValue({ blob: BLOB, fileName: 'visual-report.pdf' });
  });

  afterEach(() => {
    vi.useRealTimers();
  });

  it('returns idle defaults', () => {
    const { result } = renderHook(() => useExport());
    expect(result.current.status).toBe('idle');
    expect(result.current.error).toBeNull();
    expect(result.current.fileName).toBeNull();
  });

  it('no-ops when sectionId is missing', async () => {
    const { result } = renderHook(() => useExport());

    await act(async () => {
      await result.current.startExport({ domain: 'roster', sectionId: null });
    });

    expect(fetchExportBlob).not.toHaveBeenCalled();
    expect(result.current.status).toBe('idle');
  });

  it('downloads, toasts success and flips status done then idle', async () => {
    vi.useFakeTimers();
    const { result } = renderHook(() => useExport());

    await act(async () => {
      await result.current.startExport({ domain: 'roster', sectionId: 7 });
    });

    expect(fetchExportBlob).toHaveBeenCalledWith('roster', 7, { format: 'csv' });
    expect(triggerDownload).toHaveBeenCalledWith(BLOB, 'roster_2026-08-12.csv');
    expect(toast.success).toHaveBeenCalledWith('Export ready: roster_2026-08-12.csv');
    expect(result.current.fileName).toBe('roster_2026-08-12.csv');
    expect(result.current.status).toBe('done');

    act(() => {
      vi.advanceTimersByTime(2000);
    });
    expect(result.current.status).toBe('idle');
  });

  it('prefers the caller-supplied fileName over the server header', async () => {
    const { result } = renderHook(() => useExport());

    await act(async () => {
      await result.current.startExport({ domain: 'cds', sectionId: 3, fileName: 'cds-trend.csv' });
    });

    expect(triggerDownload).toHaveBeenCalledWith(BLOB, 'cds-trend.csv');
    expect(toast.success).toHaveBeenCalledWith('Export ready: cds-trend.csv');
  });

  it('ignores a second startExport while one is loading', async () => {
    let resolveFetch;
    fetchExportBlob.mockReturnValue(
      new Promise((resolve) => {
        resolveFetch = resolve;
      })
    );
    const { result } = renderHook(() => useExport());

    let first;
    act(() => {
      first = result.current.startExport({ domain: 'cds', sectionId: 3, format: 'xlsx' });
    });
    act(() => {
      result.current.startExport({ domain: 'cds', sectionId: 3, format: 'xlsx' });
    });

    await act(async () => {
      resolveFetch({ blob: BLOB, fileName: 'cds.xlsx' });
      await first;
    });

    expect(fetchExportBlob).toHaveBeenCalledTimes(1);
  });

  it('toasts the error and sets status error on failure', async () => {
    fetchExportBlob.mockRejectedValue(
      Object.assign(new Error('boom'), { response: { data: { error: 'Export failed' } } })
    );
    const { result } = renderHook(() => useExport());

    await act(async () => {
      await result.current.startExport({ domain: 'roster', sectionId: 7 });
    });

    expect(toast.error).toHaveBeenCalledWith('Export failed');
    expect(result.current.status).toBe('error');
    expect(result.current.error).toBe('Export failed');
    expect(triggerDownload).not.toHaveBeenCalled();
  });

  it('downloads a visual report via the visual-report branch', async () => {
    fetchVisualReportBlob.mockResolvedValue({
      blob: BLOB,
      fileName: 'Test Section_visual-report_2026-08-12.pdf',
    });
    const { result } = renderHook(() => useExport());

    await act(async () => {
      await result.current.startExport({ kind: 'visual-report', sectionId: 7 });
    });

    expect(fetchExportBlob).not.toHaveBeenCalled();
    expect(fetchVisualReportBlob).toHaveBeenCalledWith(7, {});
    expect(triggerDownload).toHaveBeenCalledWith(BLOB, 'Test Section_visual-report_2026-08-12.pdf');
    expect(toast.success).toHaveBeenCalledWith('Export ready: Test Section_visual-report_2026-08-12.pdf');
    expect(result.current.status).toBe('done');
  });

  it('passes studentId through for a per-student dossier', async () => {
    fetchVisualReportBlob.mockResolvedValue({ blob: BLOB, fileName: 'dossier.pdf' });
    const { result } = renderHook(() => useExport());

    await act(async () => {
      await result.current.startExport({ kind: 'visual-report', sectionId: 7, studentId: 42 });
    });

    expect(fetchVisualReportBlob).toHaveBeenCalledWith(7, { studentId: 42 });
    expect(triggerDownload).toHaveBeenCalledWith(BLOB, 'dossier.pdf');
  });

  it('ignores a second visual report while one is loading', async () => {
    let resolveFetch;
    fetchVisualReportBlob.mockReturnValue(
      new Promise((resolve) => {
        resolveFetch = resolve;
      })
    );
    const { result } = renderHook(() => useExport());

    let first;
    act(() => {
      first = result.current.startExport({ kind: 'visual-report', sectionId: 3 });
    });
    act(() => {
      result.current.startExport({ kind: 'visual-report', sectionId: 3 });
    });

    await act(async () => {
      resolveFetch({ blob: BLOB, fileName: 'visual-report.pdf' });
      await first;
    });

    expect(fetchVisualReportBlob).toHaveBeenCalledTimes(1);
  });

  it('toasts the error and sets status error when the visual report fails', async () => {
    fetchVisualReportBlob.mockRejectedValue(
      Object.assign(new Error('boom'), { response: { data: { error: 'Report failed' } } })
    );
    const { result } = renderHook(() => useExport());

    await act(async () => {
      await result.current.startExport({ kind: 'visual-report', sectionId: 7 });
    });

    expect(toast.error).toHaveBeenCalledWith('Report failed');
    expect(result.current.status).toBe('error');
    expect(result.current.error).toBe('Report failed');
    expect(triggerDownload).not.toHaveBeenCalled();
  });
});
