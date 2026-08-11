import { describe, it, expect, vi, beforeEach, afterEach } from 'vitest';
import {
  buildExportUrl,
  buildVisualReportUrl,
  fetchExportBlob,
  fetchVisualReportBlob,
  triggerDownload,
} from './exportApi';

vi.mock('@/services/api', () => ({
  default: { get: vi.fn() },
}));

import api from '@/services/api';

describe('buildExportUrl', () => {
  it('builds a canonical export URL with format', () => {
    expect(buildExportUrl('roster', 7, { format: 'csv' })).toBe('/api/export/roster/7?format=csv');
  });

  it('defaults format to csv', () => {
    expect(buildExportUrl('cds', 3)).toBe('/api/export/cds/3?format=csv');
  });

  it('appends studentId only when provided', () => {
    expect(buildExportUrl('submissions', 3, { format: 'xlsx', studentId: 42 })).toBe(
      '/api/export/submissions/3?format=xlsx&studentId=42'
    );
  });
});

describe('buildVisualReportUrl', () => {
  it('builds the visual report URL for a section', () => {
    expect(buildVisualReportUrl(7)).toBe('/api/export/visual-report/7');
  });

  it('appends studentId only when provided', () => {
    expect(buildVisualReportUrl(7, { studentId: 42 })).toBe(
      '/api/export/visual-report/7?studentId=42'
    );
  });

  it('omits studentId when nullish', () => {
    expect(buildVisualReportUrl(7, { studentId: null })).toBe('/api/export/visual-report/7');
    expect(buildVisualReportUrl(7, {})).toBe('/api/export/visual-report/7');
  });
});

describe('fetchExportBlob', () => {
  beforeEach(() => {
    vi.clearAllMocks();
  });

  it('requests a blob and returns it with the plain-form filename', async () => {
    const blob = new Blob(['a,b']);
    api.get.mockResolvedValue({
      data: blob,
      headers: { 'content-disposition': 'attachment; filename="roster_2026-08-12.csv"' },
    });

    const result = await fetchExportBlob('roster', 7, { format: 'csv' });

    expect(api.get).toHaveBeenCalledWith('/api/export/roster/7?format=csv', {
      responseType: 'blob',
    });
    expect(result.blob).toBe(blob);
    expect(result.fileName).toBe('roster_2026-08-12.csv');
  });

  it('prefers the RFC 5987 encoded filename', async () => {
    const blob = new Blob(['x']);
    api.get.mockResolvedValue({
      data: blob,
      headers: {
        'content-disposition':
          "attachment; filename=\"export.csv\"; filename*=UTF-8''section%20a_cds_2026-08-12.csv",
      },
    });

    const result = await fetchExportBlob('cds', 7);

    expect(result.fileName).toBe('section a_cds_2026-08-12.csv');
  });

  it('falls back to export.<format> when the header is missing', async () => {
    const blob = new Blob(['x']);
    api.get.mockResolvedValue({ data: blob, headers: {} });

    const result = await fetchExportBlob('integrity', 9, { format: 'xlsx' });

    expect(result.fileName).toBe('export.xlsx');
  });
});

describe('fetchVisualReportBlob', () => {
  beforeEach(() => {
    vi.clearAllMocks();
  });

  it('requests the blob and returns it with the Content-Disposition filename', async () => {
    const blob = new Blob(['pdf']);
    api.get.mockResolvedValue({
      data: blob,
      headers: {
        'content-disposition': 'attachment; filename="Test Section_visual-report_2026-08-12.pdf"',
      },
    });

    const result = await fetchVisualReportBlob(7);

    expect(api.get).toHaveBeenCalledWith('/api/export/visual-report/7', {
      responseType: 'blob',
    });
    expect(result.blob).toBe(blob);
    expect(result.fileName).toBe('Test Section_visual-report_2026-08-12.pdf');
  });

  it('passes studentId through for a per-student dossier', async () => {
    const blob = new Blob(['pdf']);
    api.get.mockResolvedValue({
      data: blob,
      headers: { 'content-disposition': 'attachment; filename="dossier.pdf"' },
    });

    const result = await fetchVisualReportBlob(7, { studentId: 42 });

    expect(api.get).toHaveBeenCalledWith('/api/export/visual-report/7?studentId=42', {
      responseType: 'blob',
    });
    expect(result.fileName).toBe('dossier.pdf');
  });

  it('falls back to visual-report.pdf when the header is missing', async () => {
    const blob = new Blob(['pdf']);
    api.get.mockResolvedValue({ data: blob, headers: {} });

    const result = await fetchVisualReportBlob(7);

    expect(result.fileName).toBe('visual-report.pdf');
  });
});

describe('triggerDownload', () => {
  let createSpy;
  let revokeSpy;
  let clickSpy;

  beforeEach(() => {
    // jsdom does not implement URL.createObjectURL / revokeObjectURL, so
    // assign mocks directly instead of spying on missing methods.
    createSpy = vi.fn(() => 'blob:mock');
    revokeSpy = vi.fn();
    URL.createObjectURL = createSpy;
    URL.revokeObjectURL = revokeSpy;
    clickSpy = vi.spyOn(HTMLAnchorElement.prototype, 'click').mockImplementation(() => {});
  });

  afterEach(() => {
    vi.restoreAllMocks();
    delete URL.createObjectURL;
    delete URL.revokeObjectURL;
  });

  it('creates an object URL, clicks a download link, revokes, and removes the node', () => {
    const blob = new Blob(['data']);

    triggerDownload(blob, 'export.csv');

    expect(createSpy).toHaveBeenCalledWith(blob);
    expect(clickSpy).toHaveBeenCalledTimes(1);
    expect(revokeSpy).toHaveBeenCalledWith('blob:mock');

    // The anchor is removed from the DOM after the click.
    expect(document.querySelector('a[download="export.csv"]')).toBeNull();
  });
});
