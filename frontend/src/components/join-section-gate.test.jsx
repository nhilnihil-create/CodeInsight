import { describe, it, expect, vi, beforeEach, afterEach } from 'vitest';
import { render, screen, fireEvent, waitFor, cleanup } from '@testing-library/react';
import { MemoryRouter } from 'react-router-dom';
import JoinSectionGate from './join-section-gate';

vi.mock('@/services/api', () => ({
  default: { post: vi.fn() },
}));

vi.mock('sonner', () => ({
  toast: { success: vi.fn(), error: vi.fn() },
  Toaster: () => null,
}));

vi.mock('@/context/AuthContext', () => ({
  useAuth: () => ({ logout: vi.fn() }),
}));

import api from '@/services/api';
import { toast } from 'sonner';

function renderGate(props = {}) {
  return render(
    <MemoryRouter>
      <JoinSectionGate {...props} />
    </MemoryRouter>
  );
}

function typeAndJoin() {
  fireEvent.change(screen.getByPlaceholderText(/e\.g\. K7P-3QX/i), { target: { value: 'ABC-123' } });
  fireEvent.click(screen.getByRole('button', { name: /join/i }));
}

describe('JoinSectionGate', () => {
  beforeEach(() => {
    vi.clearAllMocks();
  });

  afterEach(() => {
    cleanup();
  });

  it('treats 409 as already-enrolled recovery', async () => {
    const onJoined = vi.fn();
    const onBack = vi.fn();
    api.post.mockRejectedValue({
      response: { status: 409, data: { error: 'Already enrolled' } },
    });

    renderGate({ onJoined, onBack });
    typeAndJoin();

    await waitFor(() => {
      expect(toast.success).toHaveBeenCalledWith('You are already enrolled in this section.');
    });
    expect(toast.error).not.toHaveBeenCalled();
    expect(onBack).toHaveBeenCalled();
    expect(onJoined).toHaveBeenCalled();
    expect(screen.getByPlaceholderText(/e\.g\. K7P-3QX/i)).toHaveValue('');
    expect(screen.queryByText('You are already enrolled in this section.')).not.toBeInTheDocument();
  });

  it('still shows an error toast for 404 and does not call onJoined', async () => {
    const onJoined = vi.fn();
    api.post.mockRejectedValue({
      response: { status: 404, data: { error: 'Invalid code' } },
    });

    renderGate({ onJoined });
    typeAndJoin();

    await waitFor(() => {
      expect(toast.error).toHaveBeenCalledWith('Invalid join code. Please check the code and try again.');
    });
    expect(toast.success).not.toHaveBeenCalled();
    expect(onJoined).not.toHaveBeenCalled();
  });

  it('shows a success toast and calls onJoined after a successful join', async () => {
    const onJoined = vi.fn();
    api.post.mockResolvedValue({});

    renderGate({ onJoined });
    typeAndJoin();

    await waitFor(() => {
      expect(toast.success).toHaveBeenCalledWith('Successfully joined the section!');
    });
    expect(onJoined).toHaveBeenCalled();
    expect(toast.error).not.toHaveBeenCalled();
  });
});
