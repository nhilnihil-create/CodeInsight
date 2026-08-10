import { describe, it, expect, vi, beforeEach, afterEach } from 'vitest';
import { render, screen, fireEvent, cleanup } from '@testing-library/react';
import { MemoryRouter } from 'react-router-dom';
import SectionGatePage from './section-gate-page';

vi.mock('@/context/StudentContext', () => ({
  useStudentContext: () => mockContext,
}));

vi.mock('@/context/AuthContext', () => ({
  useAuth: () => ({ logout: vi.fn() }),
}));

vi.mock('@/components/SectionPickerPage', () => ({
  default: () => <div>PICKER</div>,
}));

vi.mock('@/components/join-section-gate', () => ({
  default: () => <div>JOIN GATE</div>,
}));

let mockContext;

function renderGate() {
  return render(
    <MemoryRouter>
      <SectionGatePage />
    </MemoryRouter>
  );
}

describe('SectionGatePage', () => {
  beforeEach(() => {
    vi.clearAllMocks();
    mockContext = {
      sections: [{ id: 1, name: 'CS101 A' }],
      loading: false,
      error: false,
      hasSections: true,
      setActiveSectionId: vi.fn(),
      recheck: vi.fn(),
    };
  });

  afterEach(() => {
    cleanup();
  });

  it('renders the retry screen when error is set and clicking Retry calls recheck', () => {
    mockContext.error = true;
    mockContext.hasSections = false;
    renderGate();
    expect(screen.getByText("Couldn't load your classes")).toBeInTheDocument();
    expect(screen.getByText('Check your connection and try again.')).toBeInTheDocument();
    expect(screen.queryByText('JOIN GATE')).not.toBeInTheDocument();

    fireEvent.click(screen.getByRole('button', { name: 'Retry' }));
    expect(mockContext.recheck).toHaveBeenCalled();
  });

  it('shows the join gate when there are no sections and no error', () => {
    mockContext.sections = [];
    mockContext.hasSections = false;
    renderGate();
    expect(screen.getByText('JOIN GATE')).toBeInTheDocument();
    expect(screen.queryByText('PICKER')).not.toBeInTheDocument();
  });

  it('shows the picker when sections exist and there is no error', () => {
    renderGate();
    expect(screen.getByText('PICKER')).toBeInTheDocument();
    expect(screen.queryByText('JOIN GATE')).not.toBeInTheDocument();
  });

  it('renders the loading screen while loading even with error set', () => {
    mockContext.loading = true;
    mockContext.error = true;
    renderGate();
    expect(screen.getByText('Loading your classes…')).toBeInTheDocument();
    expect(screen.queryByText("Couldn't load your classes")).not.toBeInTheDocument();
  });
});
