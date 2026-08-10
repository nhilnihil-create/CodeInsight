// StudentExercises List Tests
// Verifies the Google Classroom-style work-status tabs (To-do / Late /
// Missing / Done), the completion-aware "Review" / "Start" labels, and
// the background refresh listeners (pageshow bfcache restore + debounced
// window focus).

import { describe, it, expect, vi, beforeEach, afterEach } from 'vitest';
import { render, screen, waitFor, cleanup, fireEvent } from '@testing-library/react';
import { BrowserRouter } from 'react-router-dom';
import StudentExercises from './Exercises';

// Mock api module (fetch-only page)
vi.mock('@/services/api', () => ({
  default: { get: vi.fn() },
}));

// Enrolled with sections, no loading gate
vi.mock('@/context/StudentContext', () => ({
  useStudentContext: () => ({ hasSections: true, checking: false, activeSectionId: null, recheck: vi.fn() }),
}));

import api from '@/services/api';

const exercises = [
  { id: 1, title: 'Loops Basics', description: 'Loops', isCompleted: true, deadline: null, work_status: 'done' },
  { id: 2, title: 'Arrays 101', description: 'Arrays', isCompleted: false, deadline: null, work_status: 'todo' },
  { id: 3, title: 'Pointers Late', description: 'Pointers', isCompleted: true, deadline: '2026-01-01T00:00:00.000Z', work_status: 'late' },
  { id: 4, title: 'Strings Missing', description: 'Strings', isCompleted: false, deadline: '2026-01-01T00:00:00.000Z', work_status: 'missing' },
];

function renderPage() {
  return render(
    <BrowserRouter>
      <StudentExercises />
    </BrowserRouter>
  );
}

function goToTab(name) {
  fireEvent.click(screen.getByRole('tab', { name: new RegExp(name) }));
}

function dispatchPageShow(persisted) {
  const evt = new Event('pageshow');
  Object.defineProperty(evt, 'persisted', { value: persisted });
  window.dispatchEvent(evt);
}

describe('StudentExercises', () => {
  beforeEach(() => {
    vi.clearAllMocks();
    api.get.mockResolvedValue({ data: exercises });
  });

  afterEach(() => {
    cleanup();
  });

  it('defaults to the To-do tab and shows only to-do items', async () => {
    renderPage();

    await waitFor(() => {
      expect(screen.getByRole('link', { name: 'Start' })).toBeInTheDocument();
    });
    expect(screen.getByText('Arrays 101')).toBeInTheDocument();
    expect(screen.queryByText('Loops Basics')).not.toBeInTheDocument();
    expect(screen.queryByText('Pointers Late')).not.toBeInTheDocument();
    expect(screen.queryByText('Strings Missing')).not.toBeInTheDocument();
    expect(api.get).toHaveBeenCalledWith('/api/student/exercises', { params: {} });
  });

  it('switches tabs to filter exercises by work status', async () => {
    renderPage();

    await waitFor(() => {
      expect(screen.getByRole('link', { name: 'Start' })).toBeInTheDocument();
    });

    // Done tab
    goToTab('Done');
    await waitFor(() => {
      expect(screen.getByRole('link', { name: 'Review' })).toBeInTheDocument();
    });
    expect(screen.getByText('Loops Basics')).toBeInTheDocument();
    expect(screen.queryByText('Arrays 101')).not.toBeInTheDocument();

    // Late tab — completed after the deadline, still shows "Review"
    goToTab('Late');
    await waitFor(() => {
      expect(screen.getByText('Pointers Late')).toBeInTheDocument();
    });
    expect(screen.getByRole('link', { name: 'Review' })).toBeInTheDocument();
    expect(screen.queryByText('Loops Basics')).not.toBeInTheDocument();

    // Missing tab — not completed, shows "Start"
    goToTab('Missing');
    await waitFor(() => {
      expect(screen.getByText('Strings Missing')).toBeInTheDocument();
    });
    expect(screen.getByRole('link', { name: 'Start' })).toBeInTheDocument();
    expect(screen.queryByText('Pointers Late')).not.toBeInTheDocument();
  });

  it('renders a per-tab empty state when a tab has no items', async () => {
    api.get.mockResolvedValue({
      data: [
        { id: 1, title: 'Loops Basics', description: 'Loops', isCompleted: true, deadline: null, work_status: 'done' },
        { id: 2, title: 'Arrays 101', description: 'Arrays', isCompleted: false, deadline: null, work_status: 'todo' },
      ],
    });

    renderPage();

    await waitFor(() => {
      expect(screen.getByRole('link', { name: 'Start' })).toBeInTheDocument();
    });
    goToTab('Missing');
    expect(await screen.findByText('No missing work')).toBeInTheDocument();

    goToTab('Late');
    expect(await screen.findByText('Nothing turned in late')).toBeInTheDocument();

    // The To-do tab has items with this fixture, so it shows the card, not the empty state.
    goToTab('To-do');
    expect(screen.getByText('Arrays 101')).toBeInTheDocument();
    expect(screen.queryByText("Nothing to do — you're all caught up")).not.toBeInTheDocument();
  });

  it('renders the To-do and Done empty states when those tabs have no items', async () => {
    api.get.mockResolvedValue({
      data: [
        { id: 3, title: 'Pointers Late', description: 'Pointers', isCompleted: true, deadline: '2026-01-01T00:00:00.000Z', work_status: 'late' },
        { id: 4, title: 'Strings Missing', description: 'Strings', isCompleted: false, deadline: '2026-01-01T00:00:00.000Z', work_status: 'missing' },
      ],
    });

    renderPage();

    // No to-do items → the default tab renders its empty state directly.
    expect(await screen.findByText("Nothing to do — you're all caught up")).toBeInTheDocument();

    goToTab('Done');
    expect(await screen.findByText('No completed exercises yet')).toBeInTheDocument();
  });

  it('renders a legacy payload (no work_status, status completed) under the default tab with a Review label', async () => {
    api.get.mockResolvedValue({
      data: [{ id: 3, title: 'Fallback', description: 'x', status: 'completed', deadline: null }],
    });

    renderPage();

    // Legacy payload without work_status falls back to the To-do tab.
    await waitFor(() => {
      expect(screen.getByRole('link', { name: 'Review' })).toBeInTheDocument();
    });
    expect(screen.getByText('Fallback')).toBeInTheDocument();
  });

  it('re-fetches on bfcache restore (pageshow with persisted=true)', async () => {
    renderPage();

    await waitFor(() => {
      expect(screen.getByRole('link', { name: 'Start' })).toBeInTheDocument();
    });
    goToTab('Done');
    await waitFor(() => {
      expect(screen.getByRole('link', { name: 'Review' })).toBeInTheDocument();
    });
    expect(api.get).toHaveBeenCalledTimes(1);

    dispatchPageShow(true);

    await waitFor(() => {
      expect(api.get).toHaveBeenCalledTimes(2);
    });
  });

  it('does not double-fetch on initial pageshow (persisted=false)', async () => {
    renderPage();

    await waitFor(() => {
      expect(screen.getByRole('link', { name: 'Start' })).toBeInTheDocument();
    });
    goToTab('Done');
    await waitFor(() => {
      expect(screen.getByRole('link', { name: 'Review' })).toBeInTheDocument();
    });
    expect(api.get).toHaveBeenCalledTimes(1);

    dispatchPageShow(false);

    // Give any (wrongly) scheduled refresh a chance to run.
    await new Promise((resolve) => setTimeout(resolve, 50));
    expect(api.get).toHaveBeenCalledTimes(1);
  });

  it('debounces window focus so rapid focus events trigger a single refresh', async () => {
    renderPage();

    await waitFor(() => {
      expect(screen.getByRole('link', { name: 'Start' })).toBeInTheDocument();
    });
    goToTab('Done');
    await waitFor(() => {
      expect(screen.getByRole('link', { name: 'Review' })).toBeInTheDocument();
    });
    expect(api.get).toHaveBeenCalledTimes(1);

    window.dispatchEvent(new Event('focus'));
    window.dispatchEvent(new Event('focus'));
    window.dispatchEvent(new Event('focus'));

    await waitFor(
      () => {
        expect(api.get).toHaveBeenCalledTimes(2);
      },
      { timeout: 2000 }
    );

    // No further focus events → no further fetches.
    await new Promise((resolve) => setTimeout(resolve, 500));
    expect(api.get).toHaveBeenCalledTimes(2);
  });
});
