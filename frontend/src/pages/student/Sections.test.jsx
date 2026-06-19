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
    api.get.mockResolvedValue({ data: [] });
  });

  afterEach(() => {
    cleanup();
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
      api.get.mockResolvedValueOnce({ data: [{ id: 1, name: 'CS101', code: 'ABC-123' }] });
      
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
    });

    it('shows success toast on successful join', async () => {
      api.post.mockResolvedValue({});
      api.get.mockResolvedValueOnce({ data: [{ id: 1, name: 'CS101', code: 'ABC-123' }] });
      
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
    });

    it('clears input after successful join', async () => {
      api.post.mockResolvedValue({});
      api.get.mockResolvedValueOnce({ data: [{ id: 1, name: 'CS101', code: 'ABC-123' }] });
      
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
        expect(screen.getByText(/joining/i)).toBeInTheDocument();
        expect(button).toBeDisabled();
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

    it('shows error toast for already enrolled (409)', async () => {
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
        expect(toast.error).toHaveBeenCalledWith('You are already enrolled in this section.');
      });
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
      api.get.mockResolvedValue({
        data: [
          { id: 1, name: 'CS101-A', code: 'ABC-123', term: 'Sem 1' },
          { id: 2, name: 'CS101-B', code: 'DEF-456', term: 'Sem 2' }
        ]
      });
      
      renderWithProviders(<StudentSections />);
      
      await waitFor(() => {
        expect(screen.getByText('CS101-A')).toBeInTheDocument();
        expect(screen.getByText('CS101-B')).toBeInTheDocument();
      });
    });

    it('shows empty state when no sections', async () => {
      api.get.mockResolvedValue({ data: [] });
      
      renderWithProviders(<StudentSections />);
      
      await waitFor(() => {
        expect(screen.getByText(/not enrolled in any sections/i)).toBeInTheDocument();
      });
    });
  });
});
