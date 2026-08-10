import { describe, it, expect, vi, beforeEach, afterEach } from 'vitest';
import { render, screen, fireEvent, cleanup } from '@testing-library/react';
import { MemoryRouter } from 'react-router-dom';
import RequireSection from './require-section';

vi.mock('@/context/StudentContext', () => ({
  useStudentContext: () => mockContext,
}));

vi.mock('@/services/api', () => ({
  default: { get: vi.fn(), post: vi.fn() },
}));

let mockContext;

function renderGate(children = <div>page content</div>) {
  return render(
    <MemoryRouter>
      <RequireSection>{children}</RequireSection>
    </MemoryRouter>
  );
}

describe('RequireSection', () => {
  beforeEach(() => {
    vi.clearAllMocks();
    mockContext = {
      sections: [
        { id: 1, name: 'CS101 A', code: 'K7P-3QX', term: 'Fall 2026' },
        { id: 2, name: 'CS101 B', code: 'X9M-2LP', term: 'Fall 2026' },
      ],
      loading: false,
      activeSectionId: 1,
      setActiveSectionId: vi.fn(),
      recheck: vi.fn(),
      hasSections: true,
    };
  });

  afterEach(() => {
    cleanup();
  });

  it('renders a spinner while sections are loading', () => {
    mockContext.loading = true;
    renderGate();
    expect(screen.getByText('Loading your sections…')).toBeInTheDocument();
    expect(screen.queryByText('page content')).not.toBeInTheDocument();
  });

  it('renders the full-page picker when sections exist but no active section is set', () => {
    mockContext.activeSectionId = null;
    renderGate();
    expect(screen.getByRole('heading', { name: 'Select a Section' })).toBeInTheDocument();
    expect(screen.getByText(/enrolled in 2 sections/i)).toBeInTheDocument();
    expect(screen.getByText('CS101 A')).toBeInTheDocument();
    expect(screen.getByText('K7P-3QX · Fall 2026')).toBeInTheDocument();
    expect(screen.getByRole('link', { name: /Join another section/i })).toHaveAttribute('href', '/student/sections');
  });

  it('activates the picked section from the picker', () => {
    mockContext.activeSectionId = null;
    renderGate();
    fireEvent.click(screen.getByText('CS101 B'));
    expect(mockContext.setActiveSectionId).toHaveBeenCalledWith(2);
  });

  it('renders the join gate when there are no enrolled sections', () => {
    mockContext.sections = [];
    mockContext.hasSections = false;
    mockContext.activeSectionId = null;
    renderGate();
    expect(screen.getByRole('heading', { name: 'Join a Section' })).toBeInTheDocument();
    expect(screen.getByPlaceholderText('e.g. K7P-3QX')).toBeInTheDocument();
  });

  it('renders the wrapped page when an active section is set', () => {
    renderGate();
    expect(screen.getByText('page content')).toBeInTheDocument();
    expect(screen.queryByText('Select a Section')).not.toBeInTheDocument();
  });
});
