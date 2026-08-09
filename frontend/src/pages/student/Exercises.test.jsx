// StudentExercises List Tests
// Verifies the completion-aware "Review" / "Start" labels and the
// background refresh listeners (pageshow bfcache restore + debounced
// window focus).

import { describe, it, expect, vi, beforeEach, afterEach } from 'vitest';
import { render, screen, waitFor, cleanup } from '@testing-library/react';
import { BrowserRouter } from 'react-router-dom';
import StudentExercises from './Exercises';

// Mock api module (fetch-only page)
vi.mock('@/services/api', () => ({
  default: { get: vi.fn() },
}));

// Enrolled with sections, no loading gate
vi.mock('@/hooks/useHasSections', () => ({
  default: () => ({ hasSections: true, checking: false, recheck: vi.fn() }),
}));

import api from '@/services/api';

const exercises = [
  { id: 1, title: 'Loops Basics', description: 'Loops', isCompleted: true, deadline: null },
  { id: 2, title: 'Arrays 101', description: 'Arrays', isCompleted: false, deadline: null },
];

function renderPage() {
  return render(
    <BrowserRouter>
      <StudentExercises />
    </BrowserRouter>
  );
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

  it('renders "Review" for completed exercises and "Start" for pending ones', async () => {
    renderPage();

    await waitFor(() => {
      expect(screen.getByRole('link', { name: 'Review' })).toBeInTheDocument();
    });
    expect(screen.getByRole('link', { name: 'Start' })).toBeInTheDocument();
    expect(api.get).toHaveBeenCalledWith('/api/student/exercises');
  });

  it('renders "Start" when isCompleted is absent but status is completed', async () => {
    api.get.mockResolvedValue({
      data: [{ id: 3, title: 'Fallback', description: 'x', status: 'completed', deadline: null }],
    });

    renderPage();

    await waitFor(() => {
      expect(screen.getByRole('link', { name: 'Review' })).toBeInTheDocument();
    });
  });

  it('re-fetches on bfcache restore (pageshow with persisted=true)', async () => {
    renderPage();

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
