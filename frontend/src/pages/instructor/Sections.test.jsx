// InstructorSections Component Tests
// Tests join code display and copy functionality

import { describe, it, expect, vi, beforeEach, afterEach } from 'vitest';
import { render, screen, fireEvent, waitFor, cleanup } from '@testing-library/react';
import { BrowserRouter } from 'react-router-dom';
import { QueryClient, QueryClientProvider } from '@tanstack/react-query';
import { Toaster } from 'sonner';
import InstructorSections from './Sections';

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

// Mock navigator.clipboard
const mockClipboard = {
  writeText: vi.fn().mockResolvedValue(undefined),
};
Object.assign(navigator, { clipboard: mockClipboard });

import api from '@/services/api';
import { toast } from 'sonner';

function renderWithProviders(ui) {
  const queryClient = new QueryClient({
    defaultOptions: {
      queries: {
        retry: false,
      },
    },
  });
  
  return render(
    <BrowserRouter>
      <QueryClientProvider client={queryClient}>
        {ui}
        <Toaster />
      </QueryClientProvider>
    </BrowserRouter>
  );
}

describe('InstructorSections', () => {
  beforeEach(() => {
    vi.clearAllMocks();
    mockClipboard.writeText.mockResolvedValue(undefined);
  });

  afterEach(() => {
    cleanup();
  });

  describe('Join Code Display', () => {
    it('displays join code in section rows', async () => {
      api.get.mockResolvedValue({
        data: [{
          id: 1,
          name: 'CS101-A',
          course_code: 'CS101',
          code: 'ABC-123',
          student_count: 5,
          integrity_flags_count: 0,
          avg_cds: 0.25,
          difficulty_distribution: { low: 4, moderate: 1, high: 0 }
        }]
      });
      
      renderWithProviders(<InstructorSections />);
      
      await waitFor(() => {
        expect(screen.getByText('CS101-A')).toBeInTheDocument();
      });
      
      expect(screen.getByText('ABC-123')).toBeInTheDocument();
    });

    it('displays copy button with code', async () => {
      api.get.mockResolvedValue({
        data: [{
          id: 1,
          name: 'CS101-A',
          course_code: 'CS101',
          code: 'XYZ-789',
          student_count: 5,
          integrity_flags_count: 0,
          avg_cds: 0.25,
          difficulty_distribution: { low: 4, moderate: 1, high: 0 }
        }]
      });
      
      renderWithProviders(<InstructorSections />);
      
      await waitFor(() => {
        expect(screen.getByLabelText(/copy join code xyz-789/i)).toBeInTheDocument();
      });
    });

    it('shows multiple sections with codes', async () => {
      api.get.mockResolvedValue({
        data: [
          { id: 1, name: 'CS101-A', course_code: 'CS101', code: 'AAA-111', student_count: 5, integrity_flags_count: 0, avg_cds: 0.25, difficulty_distribution: { low: 4, moderate: 1, high: 0 } },
          { id: 2, name: 'CS101-B', course_code: 'CS101', code: 'BBB-222', student_count: 3, integrity_flags_count: 0, avg_cds: 0.30, difficulty_distribution: { low: 2, moderate: 1, high: 0 } }
        ]
      });
      
      renderWithProviders(<InstructorSections />);
      
      await waitFor(() => {
        expect(screen.getByText('AAA-111')).toBeInTheDocument();
        expect(screen.getByText('BBB-222')).toBeInTheDocument();
      });
    });
  });

  describe('Copy Code Functionality', () => {
    it('copies code to clipboard when copy button clicked', async () => {
      api.get.mockResolvedValue({
        data: [{
          id: 1,
          name: 'CS101-A',
          course_code: 'CS101',
          code: 'COPY-123',
          student_count: 5,
          integrity_flags_count: 0,
          avg_cds: 0.25,
          difficulty_distribution: { low: 4, moderate: 1, high: 0 }
        }]
      });
      
      renderWithProviders(<InstructorSections />);
      
      await waitFor(() => {
        expect(screen.getByLabelText(/copy join code copy-123/i)).toBeInTheDocument();
      });
      
      fireEvent.click(screen.getByLabelText(/copy join code copy-123/i));
      
      await waitFor(() => {
        expect(mockClipboard.writeText).toHaveBeenCalledWith('COPY-123');
      });
    });

    it('shows success toast after copying', async () => {
      api.get.mockResolvedValue({
        data: [{
          id: 1,
          name: 'CS101-A',
          course_code: 'CS101',
          code: 'TOAST-01',
          student_count: 5,
          integrity_flags_count: 0,
          avg_cds: 0.25,
          difficulty_distribution: { low: 4, moderate: 1, high: 0 }
        }]
      });
      
      renderWithProviders(<InstructorSections />);
      
      await waitFor(() => {
        expect(screen.getByLabelText(/copy join code toast-01/i)).toBeInTheDocument();
      });
      
      fireEvent.click(screen.getByLabelText(/copy join code toast-01/i));
      
      await waitFor(() => {
        expect(toast.success).toHaveBeenCalledWith('Join code copied to clipboard');
      });
    });

    it('shows error toast when clipboard fails', async () => {
      mockClipboard.writeText.mockRejectedValue(new Error('Clipboard failed'));
      
      api.get.mockResolvedValue({
        data: [{
          id: 1,
          name: 'CS101-A',
          course_code: 'CS101',
          code: 'FAIL-01',
          student_count: 5,
          integrity_flags_count: 0,
          avg_cds: 0.25,
          difficulty_distribution: { low: 4, moderate: 1, high: 0 }
        }]
      });
      
      renderWithProviders(<InstructorSections />);
      
      await waitFor(() => {
        expect(screen.getByLabelText(/copy join code fail-01/i)).toBeInTheDocument();
      });
      
      fireEvent.click(screen.getByLabelText(/copy join code fail-01/i));
      
      await waitFor(() => {
        expect(toast.error).toHaveBeenCalledWith('Failed to copy join code');
      });
    });

    it('does not trigger row navigation when clicking copy', async () => {
      api.get.mockResolvedValue({
        data: [{
          id: 1,
          name: 'CS101-A',
          course_code: 'CS101',
          code: 'NO-NAV',
          student_count: 5,
          integrity_flags_count: 0,
          avg_cds: 0.25,
          difficulty_distribution: { low: 4, moderate: 1, high: 0 }
        }]
      });
      
      const onAction = vi.fn();
      renderWithProviders(<InstructorSections />);
      
      await waitFor(() => {
        expect(screen.getByLabelText(/copy join code no-nav/i)).toBeInTheDocument();
      });
      
      // Click copy button - should not call onAction
      fireEvent.click(screen.getByLabelText(/copy join code no-nav/i));
      
      await waitFor(() => {
        // onAction should not be called because we used stopPropagation
        expect(mockClipboard.writeText).toHaveBeenCalled();
      });
    });
  });

  describe('Section List', () => {
    it('shows loading state', async () => {
      api.get.mockImplementation(() => new Promise(resolve => setTimeout(resolve, 100)));
      
      renderWithProviders(<InstructorSections />);
      
      const loadingElements = screen.getAllByText(/loading sections/i);
      expect(loadingElements.length).toBeGreaterThan(0);
    });

    it('shows empty state when no sections', async () => {
      api.get.mockResolvedValue({ data: [] });
      
      renderWithProviders(<InstructorSections />);
      
      await waitFor(() => {
        expect(screen.getByText(/no sections match/i)).toBeInTheDocument();
      });
    });

    it('filters sections by search query', async () => {
      api.get.mockResolvedValue({
        data: [
          { id: 1, name: 'CS101-A', course_code: 'CS101', code: 'AAA-111', student_count: 5, integrity_flags_count: 0, avg_cds: 0.25, difficulty_distribution: { low: 4, moderate: 1, high: 0 } },
          { id: 2, name: 'IT201-B', course_code: 'IT201', code: 'BBB-222', student_count: 3, integrity_flags_count: 0, avg_cds: 0.30, difficulty_distribution: { low: 2, moderate: 1, high: 0 } }
        ]
      });
      
      renderWithProviders(<InstructorSections />);
      
      await waitFor(() => {
        expect(screen.getByText('CS101-A')).toBeInTheDocument();
        expect(screen.getByText('IT201-B')).toBeInTheDocument();
      });
      
      const searchInput = screen.getByPlaceholderText(/search sections/i);
      fireEvent.change(searchInput, { target: { value: 'CS101' } });
      
      await waitFor(() => {
        expect(screen.getByText('CS101-A')).toBeInTheDocument();
        expect(screen.queryByText('IT201-B')).not.toBeInTheDocument();
      });
    });
  });
});
