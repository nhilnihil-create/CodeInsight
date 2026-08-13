import { describe, it, expect, vi, beforeEach, afterEach } from 'vitest';
import { render, screen, cleanup } from '@testing-library/react';
import GoogleAuthButton from './GoogleAuthButton';

vi.mock('../context/AuthContext', () => ({
  useAuth: () => ({ login: vi.fn() }),
}));

vi.mock('react-router-dom', () => ({
  useNavigate: () => vi.fn(),
}));

vi.mock('../services/api', () => ({
  default: { post: vi.fn() },
}));

describe('GoogleAuthButton', () => {
  beforeEach(() => {
    delete window.google;
  });

  afterEach(() => {
    vi.unstubAllEnvs();
    delete window.google;
    cleanup();
  });

  it('renders a muted dev hint when VITE_GOOGLE_CLIENT_ID is unset', () => {
    vi.stubEnv('VITE_GOOGLE_CLIENT_ID', '');
    render(<GoogleAuthButton onError={vi.fn()} />);
    expect(screen.getByText(/Google sign-in is not configured/)).toBeInTheDocument();
  });

  it('renders nothing (null) in production when VITE_GOOGLE_CLIENT_ID is unset', () => {
    vi.stubEnv('VITE_GOOGLE_CLIENT_ID', '');
    const originalDev = import.meta.env.DEV;
    import.meta.env.DEV = false;
    try {
      const { container } = render(<GoogleAuthButton onError={vi.fn()} />);
      expect(container.firstChild).toBeNull();
    } finally {
      import.meta.env.DEV = originalDev;
    }
  });

  it('initializes and renders the Google button when the client id is set', () => {
    vi.stubEnv('VITE_GOOGLE_CLIENT_ID', 'test-client.apps.googleusercontent.com');
    const initialize = vi.fn();
    const renderButton = vi.fn();
    const cancel = vi.fn();
    window.google = { accounts: { id: { initialize, renderButton, cancel } } };

    render(<GoogleAuthButton onError={vi.fn()} />);

    expect(initialize).toHaveBeenCalledWith(
      expect.objectContaining({ client_id: 'test-client.apps.googleusercontent.com' })
    );
    expect(renderButton).toHaveBeenCalledWith(
      expect.any(HTMLElement),
      expect.objectContaining({ theme: 'outline', size: 'large', text: 'continue_with', width: 320 })
    );
    expect(screen.queryByText(/not configured/)).not.toBeInTheDocument();
  });
});
