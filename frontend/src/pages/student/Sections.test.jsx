// StudentSections Component Tests
// Tests the join code form, error handling, and UX polish

import { describe, it, expect, vi, beforeEach, afterEach } from 'vitest';
import { render, screen, fireEvent, waitFor, cleanup } from '@testing-library/react';
import { BrowserRouter } from 'react-router-dom';
import { Toaster } from 'sonner';
import StudentSections from './Sections';

// Mock api module
vi.mock('@/services/api', () => ({
  default: {
    get: vi.fn(),
    post: vi.fn(),
  },
}));

// Mock sonner toast
vi.mock('sonner', () => ({
  toast: {
    success: vi.fn(),
    error: vi.fn(),
  },
  Toaster: () => null,
}));

// Mock lucide-react icons
vi.mock('lucide-react', async (importOriginal) => {
  const actual = await importOriginal();
  return {
    ...actual,
    Loader2: (props) => <span data-testid="loader-icon" {...props} />,
  };
});

// Mock student context
vi.mock('@/context/StudentContext', () => ({
  useStudentContext: () => mockContext,
}));

let mockContext;

import api from '@/services/api';
import { toast } from 'sonner';

function renderWithProviders(ui) {
  return render(
    <BrowserRouter>
      {ui}
      <Toaster />
    </BrowserRouter>
  );
}

describe('StudentSections', () => {
  beforeEach(() => {
    vi.clearAllMocks();
    mockContext = { sections: [], loading: false, recheck: vi.fn() };
  });

  afterEach(() => {
    cleanup();
    vi.restoreAllMocks();
  });

  describe('Join Form', () => {
    it('renders join form with input and button', async () => {
      renderWithProviders(<StudentSections />);
      
      await waitFor(() => {
        expect(screen.getByPlaceholderText(/e\.g\. K7P-3QX/i)).toBeInTheDocument();
      });
      
      expect(screen.getByRole('button', { name: /join/i })).toBeInTheDocument();
    });

    it('disables join button when code is less than 7 characters', async () => {
      renderWithProviders(<StudentSections />);
      
      await waitFor(() => {
        expect(screen.getByPlaceholderText(/e\.g\. K7P-3QX/i)).toBeInTheDocument();
      });
      
      const input = screen.getByPlaceholderText(/e\.g\. K7P-3QX/i);
      const button = screen.getByRole('button', { name: /join/i });
      
      fireEvent.change(input, { target: { value: 'ABC' } });
      expect(button).toBeDisabled();
    });

    it('enables join button when code is 7 characters', async () => {
      renderWithProviders(<StudentSections />);
      
      await waitFor(() => {
        expect(screen.getByPlaceholderText(/e\.g\. K7P-3QX/i)).toBeInTheDocument();
      });
      
      const input = screen.getByPlaceholderText(/e\.g\. K7P-3QX/i);
      const button = screen.getByRole('button', { name: /join/i });
      
      fireEvent.change(input, { target: { value: 'ABC-123' } });
      expect(button).not.toBeDisabled();
    });
  });

  describe('Code Formatting', () => {
    it('auto-formats code to uppercase', async () => {
      renderWithProviders(<StudentSections />);
      
      await waitFor(() => {
        expect(screen.getByPlaceholderText(/e\.g\. K7P-3QX/i)).toBeInTheDocument();
      });
      
      const input = screen.getByPlaceholderText(/e\.g\. K7P-3QX/i);
      fireEvent.change(input, { target: { value: 'abc123' } });
      
      expect(input.value).toBe('ABC-123');
    });

    it('inserts hyphen at position 3', async () => {
      renderWithProviders(<StudentSections />);
      
      await waitFor(() => {
        expect(screen.getByPlaceholderText(/e\.g\. K7P-3QX/i)).toBeInTheDocument();
      });
      
      const input = screen.getByPlaceholderText(/e\.g\. K7P-3QX/i);
      fireEvent.change(input, { target: { value: 'ABC123' } });
      
      expect(input.value).toBe('ABC-123');
    });

    it('removes invalid characters', async () => {
      renderWithProviders(<StudentSections />);
      
      await waitFor(() => {
        expect(screen.getByPlaceholderText(/e\.g\. K7P-3QX/i)).toBeInTheDocument();
      });
      
      const input = screen.getByPlaceholderText(/e\.g\. K7P-3QX/i);
      fireEvent.change(input, { target: { value: 'ABC!@#123' } });
      
      expect(input.value).toBe('ABC-123');
    });

    it('limits input to 7 characters', async () => {
      renderWithProviders(<StudentSections />);
      
      await waitFor(() => {
        expect(screen.getByPlaceholderText(/e\.g\. K7P-3QX/i)).toBeInTheDocument();
      });
      
      const input = screen.getByPlaceholderText(/e\.g\. K7P-3QX/i);
      fireEvent.change(input, { target: { value: 'ABC-123DEF' } });
      
      expect(input.value).toBe('ABC-123');
    });
  });

  describe('Join Action', () => {
    it('calls API with formatted code on join', async () => {
      api.post.mockResolvedValue({});
      
      renderWithProviders(<StudentSections />);
      
      await waitFor(() => {
        expect(screen.getByPlaceholderText(/e\.g\. K7P-3QX/i)).toBeInTheDocument();
      });
      
      const input = screen.getByPlaceholderText(/e\.g\. K7P-3QX/i);
      const button = screen.getByRole('button', { name: /join/i });
      
      fireEvent.change(input, { target: { value: 'abc-123' } });
      fireEvent.click(button);
      
      await waitFor(() => {
        expect(api.post).toHaveBeenCalledWith('/api/sections/join', { code: 'ABC-123' });
      });
      expect(mockContext.recheck).toHaveBeenCalled();
    });

    it('shows success toast on successful join', async () => {
      api.post.mockResolvedValue({});
      
      renderWithProviders(<StudentSections />);
      
      await waitFor(() => {
        expect(screen.getByPlaceholderText(/e\.g\. K7P-3QX/i)).toBeInTheDocument();
      });
      
      const input = screen.getByPlaceholderText(/e\.g\. K7P-3QX/i);
      const button = screen.getByRole('button', { name: /join/i });
      
      fireEvent.change(input, { target: { value: 'ABC-123' } });
      fireEvent.click(button);
      
      await waitFor(() => {
        expect(toast.success).toHaveBeenCalledWith('Successfully joined the section!');
      });
      expect(mockContext.recheck).toHaveBeenCalled();
    });

    it('clears input after successful join', async () => {
      api.post.mockResolvedValue({});
      
      renderWithProviders(<StudentSections />);
      
      await waitFor(() => {
        expect(screen.getByPlaceholderText(/e\.g\. K7P-3QX/i)).toBeInTheDocument();
      });
      
      const input = screen.getByPlaceholderText(/e\.g\. K7P-3QX/i);
      fireEvent.change(input, { target: { value: 'ABC-123' } });
      fireEvent.click(screen.getByRole('button', { name: /join/i }));
      
      await waitFor(() => {
        expect(input.value).toBe('');
      });
      expect(mockContext.recheck).toHaveBeenCalled();
    });

    it('shows loading state while joining', async () => {
      api.post.mockImplementation(() => new Promise(resolve => setTimeout(resolve, 100)));
      
      renderWithProviders(<StudentSections />);
      
      await waitFor(() => {
        expect(screen.getByPlaceholderText(/e\.g\. K7P-3QX/i)).toBeInTheDocument();
      });
      
      const input = screen.getByPlaceholderText(/e\.g\. K7P-3QX/i);
      const button = screen.getByRole('button', { name: /join/i });
      
      fireEvent.change(input, { target: { value: 'ABC-123' } });
      fireEvent.click(button);
      
      await waitFor(() => {
        expect(button).toBeDisabled();
        // Loading spinner shown instead of text
        expect(button.querySelector('.animate-spin')).toBeInTheDocument();
      });
    });
  });

  describe('Error Handling', () => {
    it('shows error toast for invalid code (404)', async () => {
      api.post.mockRejectedValue({
        response: { status: 404, data: { error: 'Invalid code' } }
      });
      
      renderWithProviders(<StudentSections />);
      
      await waitFor(() => {
        expect(screen.getByPlaceholderText(/e\.g\. K7P-3QX/i)).toBeInTheDocument();
      });
      
      const input = screen.getByPlaceholderText(/e\.g\. K7P-3QX/i);
      fireEvent.change(input, { target: { value: 'BAD-CODE' } });
      fireEvent.click(screen.getByRole('button', { name: /join/i }));
      
      await waitFor(() => {
        expect(toast.error).toHaveBeenCalledWith('Invalid join code. Please check the code and try again.');
      });
    });

    it('shows error toast for full section (403)', async () => {
      api.post.mockRejectedValue({
        response: { status: 403, data: { error: 'Section is full' } }
      });
      
      renderWithProviders(<StudentSections />);
      
      await waitFor(() => {
        expect(screen.getByPlaceholderText(/e\.g\. K7P-3QX/i)).toBeInTheDocument();
      });
      
      const input = screen.getByPlaceholderText(/e\.g\. K7P-3QX/i);
      fireEvent.change(input, { target: { value: 'FULL-SEC' } });
      fireEvent.click(screen.getByRole('button', { name: /join/i }));
      
      await waitFor(() => {
        expect(toast.error).toHaveBeenCalledWith('This section is full. Contact your instructor for availability.');
      });
    });

    it('shows error toast for closed section (403)', async () => {
      api.post.mockRejectedValue({
        response: { status: 403, data: { error: 'Section is closed to new join requests' } }
      });
      
      renderWithProviders(<StudentSections />);
      
      await waitFor(() => {
        expect(screen.getByPlaceholderText(/e\.g\. K7P-3QX/i)).toBeInTheDocument();
      });
      
      const input = screen.getByPlaceholderText(/e\.g\. K7P-3QX/i);
      fireEvent.change(input, { target: { value: 'CLOSED-1' } });
      fireEvent.click(screen.getByRole('button', { name: /join/i }));
      
      await waitFor(() => {
        expect(toast.error).toHaveBeenCalledWith('This section is not accepting new students at this time.');
      });
    });

    it('treats 409 as already-enrolled recovery', async () => {
      api.post.mockRejectedValue({
        response: { status: 409, data: { error: 'Already enrolled' } }
      });
      
      renderWithProviders(<StudentSections />);
      
      await waitFor(() => {
        expect(screen.getByPlaceholderText(/e\.g\. K7P-3QX/i)).toBeInTheDocument();
      });
      
      const input = screen.getByPlaceholderText(/e\.g\. K7P-3QX/i);
      fireEvent.change(input, { target: { value: 'ALREADY' } });
      fireEvent.click(screen.getByRole('button', { name: /join/i }));
      
      await waitFor(() => {
        expect(toast.success).toHaveBeenCalledWith('You are already enrolled in this section.');
      });
      expect(toast.error).not.toHaveBeenCalled();
      expect(mockContext.recheck).toHaveBeenCalled();
    });

    it('displays error message inline', async () => {
      api.post.mockRejectedValue({
        response: { status: 404, data: { error: 'Invalid code' } }
      });
      
      renderWithProviders(<StudentSections />);
      
      await waitFor(() => {
        expect(screen.getByPlaceholderText(/e\.g\. K7P-3QX/i)).toBeInTheDocument();
      });
      
      const input = screen.getByPlaceholderText(/e\.g\. K7P-3QX/i);
      fireEvent.change(input, { target: { value: 'BAD-CODE' } });
      fireEvent.click(screen.getByRole('button', { name: /join/i }));
      
      await waitFor(() => {
        expect(screen.getByText(/invalid join code/i)).toBeInTheDocument();
      });
    });

    it('clears error when typing new code', async () => {
      api.post.mockRejectedValue({
        response: { status: 404, data: { error: 'Invalid code' } }
      });
      
      renderWithProviders(<StudentSections />);
      
      await waitFor(() => {
        expect(screen.getByPlaceholderText(/e\.g\. K7P-3QX/i)).toBeInTheDocument();
      });
      
      const input = screen.getByPlaceholderText(/e\.g\. K7P-3QX/i);
      fireEvent.change(input, { target: { value: 'BAD-CODE' } });
      fireEvent.click(screen.getByRole('button', { name: /join/i }));
      
      await waitFor(() => {
        expect(screen.getByText(/invalid join code/i)).toBeInTheDocument();
      });
      
      // Type new code
      fireEvent.change(input, { target: { value: 'NEW-CODE' } });
      
      await waitFor(() => {
        expect(screen.queryByText(/invalid join code/i)).not.toBeInTheDocument();
      });
    });
  });

  describe('Section List', () => {
    it('displays enrolled sections', async () => {
      mockContext.sections = [
        { id: 1, name: 'CS101-A', code: 'ABC-123', term: 'Sem 1' },
        { id: 2, name: 'CS101-B', code: 'DEF-456', term: 'Sem 2' },
      ];

      renderWithProviders(<StudentSections />);

      await waitFor(() => {
        expect(screen.getByText('CS101-A')).toBeInTheDocument();
        expect(screen.getByText('CS101-B')).toBeInTheDocument();
        expect(screen.queryByText('ABC-123')).not.toBeInTheDocument();
        expect(screen.queryByText('DEF-456')).not.toBeInTheDocument();
      });
    });

    it('shows empty state when no sections', async () => {
      renderWithProviders(<StudentSections />);

      await waitFor(() => {
        // EmptyState component shows the title
        expect(screen.getAllByText(/no sections yet/i).length).toBeGreaterThan(0);
      });
    });
  });

  describe('Leave Section', () => {
    it('leaves a section after confirming', async () => {
      vi.spyOn(window, 'confirm').mockReturnValue(true);
      mockContext.sections = [{ id: 2, name: 'CS101-B', code: 'DEF-456', term: 'Sem 2' }];
      api.post.mockResolvedValue({});

      renderWithProviders(<StudentSections />);

      await waitFor(() => {
        expect(screen.getByText('CS101-B')).toBeInTheDocument();
      });

      fireEvent.click(screen.getByRole('button', { name: /leave/i }));

      await waitFor(() => {
        expect(api.post).toHaveBeenCalledWith('/api/sections/2/leave');
      });
      expect(toast.success).toHaveBeenCalledWith('You left CS101-B');
      expect(mockContext.recheck).toHaveBeenCalled();
    });

    it('does not leave when confirmation is declined', async () => {
      vi.spyOn(window, 'confirm').mockReturnValue(false);
      mockContext.sections = [{ id: 2, name: 'CS101-B', code: 'DEF-456', term: 'Sem 2' }];

      renderWithProviders(<StudentSections />);

      await waitFor(() => {
        expect(screen.getByText('CS101-B')).toBeInTheDocument();
      });

      fireEvent.click(screen.getByRole('button', { name: /leave/i }));

      expect(api.post).not.toHaveBeenCalled();
      expect(toast.success).not.toHaveBeenCalled();
      expect(mockContext.recheck).not.toHaveBeenCalled();
    });

    it('shows pending state while leaving', async () => {
      vi.spyOn(window, 'confirm').mockReturnValue(true);
      mockContext.sections = [{ id: 2, name: 'CS101-B', code: 'DEF-456', term: 'Sem 2' }];
      api.post.mockImplementation(() => new Promise(() => {}));

      renderWithProviders(<StudentSections />);

      await waitFor(() => {
        expect(screen.getByText('CS101-B')).toBeInTheDocument();
      });

      fireEvent.click(screen.getByRole('button', { name: /leave/i }));

      await waitFor(() => {
        // Loading spinner shown instead of text
        const leaveButton = screen.getByRole('button', { name: /leave/i });
        expect(leaveButton.querySelector('.animate-spin')).toBeInTheDocument();
        expect(leaveButton).toBeDisabled();
      });
    });

    it('shows error toast when leave fails with 404', async () => {
      vi.spyOn(window, 'confirm').mockReturnValue(true);
      mockContext.sections = [{ id: 2, name: 'CS101-B', code: 'DEF-456', term: 'Sem 2' }];
      api.post.mockRejectedValue({ response: { status: 404, data: {} } });

      renderWithProviders(<StudentSections />);

      await waitFor(() => {
        expect(screen.getByText('CS101-B')).toBeInTheDocument();
      });

      fireEvent.click(screen.getByRole('button', { name: /leave/i }));

      await waitFor(() => {
        expect(toast.error).toHaveBeenCalledWith('This section is no longer active for you.');
      });
      expect(mockContext.recheck).not.toHaveBeenCalled();
    });
  });
});
