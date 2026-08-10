import { describe, it, expect, vi, beforeEach, afterEach } from 'vitest';
import { render, screen, cleanup } from '@testing-library/react';
import { MemoryRouter, Routes, Route, useLocation } from 'react-router-dom';
import RequireSection from './require-section';

vi.mock('@/context/StudentContext', () => ({
  useStudentContext: () => mockContext,
}));

vi.mock('@/services/api', () => ({
  default: { get: vi.fn(), post: vi.fn() },
}));

let mockContext;

function SelectSectionMarker() {
  const location = useLocation();
  return <div>select-section-marker:{location.state?.from ?? 'none'}</div>;
}

function renderGate(children = <div>page content</div>, initialEntries = ['/student/exercises']) {
  return render(
    <MemoryRouter initialEntries={initialEntries}>
      <Routes>
        <Route path="/student/select-section" element={<SelectSectionMarker />} />
        <Route path="*" element={<RequireSection>{children}</RequireSection>} />
      </Routes>
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

  it('redirects to the section gate when sections exist but no active section is set', () => {
    mockContext.activeSectionId = null;
    renderGate();
    expect(screen.getByText('select-section-marker:/student/exercises')).toBeInTheDocument();
    expect(screen.queryByText('page content')).not.toBeInTheDocument();
  });

  it('redirects to the section gate when there are no enrolled sections', () => {
    mockContext.sections = [];
    mockContext.hasSections = false;
    mockContext.activeSectionId = null;
    renderGate(undefined, ['/student/progress']);
    expect(screen.getByText('select-section-marker:/student/progress')).toBeInTheDocument();
    expect(screen.queryByText('page content')).not.toBeInTheDocument();
  });

  it('renders the wrapped page when an active section is set', () => {
    renderGate();
    expect(screen.getByText('page content')).toBeInTheDocument();
    expect(screen.queryByText(/select-section-marker/)).not.toBeInTheDocument();
  });
});
