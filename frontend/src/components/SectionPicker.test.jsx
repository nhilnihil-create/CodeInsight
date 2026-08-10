import { describe, it, expect, vi, beforeEach, afterEach } from 'vitest';
import { render, screen, fireEvent, cleanup } from '@testing-library/react';
import SectionPicker from './SectionPicker';

vi.mock('@/context/StudentContext', () => ({
  useStudentContext: () => mockContext,
}));

let mockContext;

function renderPicker() {
  return render(<SectionPicker />);
}

function openDropdown() {
  // Radix opens the select via the trigger's onClick when no prior
  // pointerdown was seen (pointerTypeRef defaults to "touch"), so a plain
  // fireEvent.click is enough to open the list in jsdom.
  fireEvent.click(screen.getByRole('combobox'));
}

describe('SectionPicker', () => {
  beforeEach(() => {
    vi.clearAllMocks();
    mockContext = {
      sections: [
        { id: 1, name: 'CS101 A', course_code: 'CS101' },
        { id: 2, name: 'CS101 B', course_code: 'CS101' },
      ],
      loading: false,
      activeSectionId: 1,
      setActiveSectionId: vi.fn(),
    };
  });

  afterEach(() => {
    cleanup();
  });

  it('renders the active section name in the trigger', () => {
    renderPicker();
    expect(screen.getByRole('combobox')).toHaveTextContent('CS101 A');
  });

  it('lists every enrolled section in the dropdown', () => {
    renderPicker();
    openDropdown();
    expect(screen.getAllByText(/CS101 A/).length).toBeGreaterThan(0);
    expect(screen.getByText('CS101 B · CS101')).toBeInTheDocument();
  });

  it('switches the active section when another section is picked', () => {
    renderPicker();
    openDropdown();
    fireEvent.click(screen.getByText('CS101 B · CS101'));
    expect(mockContext.setActiveSectionId).toHaveBeenCalledWith(2);
  });

  it('is disabled while sections are loading', () => {
    mockContext.loading = true;
    mockContext.sections = [];
    mockContext.activeSectionId = null;
    renderPicker();
    expect(screen.getByRole('combobox')).toBeDisabled();
  });
});
