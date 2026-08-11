import { describe, it, expect, vi, beforeEach } from 'vitest';
import { render, screen, fireEvent, waitFor } from '@testing-library/react';
import ExportDropdown from './export-dropdown';

// The hook pulls in the api client + export service; stub both so the
// download flow is observable without real requests.
vi.mock('@/services/api', () => ({
  default: { get: vi.fn() },
}));

vi.mock('@/services/exportApi', () => ({
  fetchExportBlob: vi.fn(),
  triggerDownload: vi.fn(),
}));

vi.mock('sonner', () => ({
  toast: { success: vi.fn(), error: vi.fn() },
}));

import { fetchExportBlob, triggerDownload } from '@/services/exportApi';

// Radix DropdownMenu opens on pointerdown (not click), so tests open the
// menu with fireEvent.pointerDown and select items with fireEvent.click.
function openMenu() {
  fireEvent.pointerDown(screen.getByRole('button', { name: /export/i }));
}

describe('ExportDropdown', () => {
  beforeEach(() => {
    vi.clearAllMocks();
    fetchExportBlob.mockResolvedValue({ blob: new Blob(['x']), fileName: 'export.csv' });
  });

  it('renders a trigger with the default label', () => {
    render(<ExportDropdown sectionId={7} domain="roster" />);
    expect(screen.getByRole('button', { name: /export/i })).toBeInTheDocument();
  });

  it('renders one menu item per format', () => {
    render(<ExportDropdown sectionId={7} domain="roster" formats={['csv', 'xlsx', 'json']} />);

    openMenu();

    expect(screen.getByText('CSV')).toBeInTheDocument();
    expect(screen.getByText('Excel')).toBeInTheDocument();
    expect(screen.getByText('JSON')).toBeInTheDocument();
  });

  it('is disabled when sectionId is missing', () => {
    render(<ExportDropdown sectionId={null} domain="roster" />);
    expect(screen.getByRole('button', { name: /export/i })).toBeDisabled();
  });

  it('is disabled when the disabled prop is set', () => {
    render(<ExportDropdown sectionId={7} domain="roster" disabled />);
    expect(screen.getByRole('button', { name: /export/i })).toBeDisabled();
  });

  it('starts an export with the right domain, format and sectionId on item click', async () => {
    render(<ExportDropdown sectionId={7} domain="cds" formats={['csv', 'xlsx']} />);

    openMenu();
    fireEvent.click(screen.getByText('CSV'));

    await waitFor(() => {
      expect(fetchExportBlob).toHaveBeenCalledWith('cds', 7, { format: 'csv' });
    });
    expect(triggerDownload).toHaveBeenCalledTimes(1);
  });

  it('passes studentId through for student-scoped exports', async () => {
    render(
      <ExportDropdown sectionId={3} domain="submissions" studentId={42} formats={['csv']} />
    );

    openMenu();
    fireEvent.click(screen.getByText('CSV'));

    await waitFor(() => {
      expect(fetchExportBlob).toHaveBeenCalledWith('submissions', 3, {
        format: 'csv',
        studentId: 42,
      });
    });
  });

  it('disables menu items while an export is loading', async () => {
    fetchExportBlob.mockReturnValue(new Promise(() => {})); // never resolves
    render(<ExportDropdown sectionId={7} domain="roster" formats={['csv']} />);

    openMenu();
    fireEvent.click(screen.getByText('CSV')); // menu closes on selection

    await waitFor(() => {
      expect(fetchExportBlob).toHaveBeenCalledTimes(1);
    });

    // Re-open the menu while the export is in flight: the item is disabled.
    openMenu();
    const item = screen.getByText('CSV');
    expect(item.closest('[data-disabled]')).not.toBeNull();
  });
});
