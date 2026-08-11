import { describe, it, expect, vi, beforeEach } from 'vitest';
import { render, screen, fireEvent, waitFor } from '@testing-library/react';
import VisualReportButton from './visual-report-button';

// The hook pulls in the api client + export service; stub both so the
// download flow is observable without real requests.
vi.mock('@/services/api', () => ({
  default: { get: vi.fn() },
}));

vi.mock('@/services/exportApi', () => ({
  fetchExportBlob: vi.fn(),
  fetchVisualReportBlob: vi.fn(),
  triggerDownload: vi.fn(),
}));

vi.mock('sonner', () => ({
  toast: { success: vi.fn(), error: vi.fn() },
}));

import { fetchVisualReportBlob } from '@/services/exportApi';

describe('VisualReportButton', () => {
  beforeEach(() => {
    vi.clearAllMocks();
    fetchVisualReportBlob.mockResolvedValue({ blob: new Blob(['x']), fileName: 'report.pdf' });
  });

  it('renders a button with the default label', () => {
    render(<VisualReportButton sectionId={7} />);
    expect(screen.getByRole('button', { name: /visual report \(pdf\)/i })).toBeInTheDocument();
  });

  it('renders a custom label', () => {
    render(<VisualReportButton sectionId={7} label="Dossier (PDF)" />);
    expect(screen.getByRole('button', { name: /dossier \(pdf\)/i })).toBeInTheDocument();
  });

  it('starts a class visual report export on click', async () => {
    render(<VisualReportButton sectionId={7} />);

    fireEvent.click(screen.getByRole('button', { name: /visual report \(pdf\)/i }));

    await waitFor(() => {
      expect(fetchVisualReportBlob).toHaveBeenCalledWith(7, {});
    });
  });

  it('passes studentId through for a per-student dossier', async () => {
    render(<VisualReportButton sectionId={7} studentId={42} label="Dossier (PDF)" />);

    fireEvent.click(screen.getByRole('button', { name: /dossier \(pdf\)/i }));

    await waitFor(() => {
      expect(fetchVisualReportBlob).toHaveBeenCalledWith(7, { studentId: 42 });
    });
  });

  it('is disabled when sectionId is missing', () => {
    render(<VisualReportButton sectionId={null} />);
    expect(screen.getByRole('button', { name: /visual report \(pdf\)/i })).toBeDisabled();
  });

  it('is disabled when the disabled prop is set', () => {
    render(<VisualReportButton sectionId={7} disabled />);
    expect(screen.getByRole('button', { name: /visual report \(pdf\)/i })).toBeDisabled();
  });

  it('shows a spinner and disables the button while loading', async () => {
    fetchVisualReportBlob.mockReturnValue(new Promise(() => {})); // never resolves
    render(<VisualReportButton sectionId={7} />);

    fireEvent.click(screen.getByRole('button', { name: /visual report \(pdf\)/i }));

    await waitFor(() => {
      expect(fetchVisualReportBlob).toHaveBeenCalledTimes(1);
    });

    const button = screen.getByRole('button', { name: /visual report \(pdf\)/i });
    expect(button).toBeDisabled();
  });
});
