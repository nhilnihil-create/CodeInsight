// RosterTab Component Tests
// Verifies the roster badge renders the canonical 5-tier academic status
// (tierForCds + TIER_META from mastery-bar) instead of the legacy CDS buckets.

import { describe, it, expect, vi, beforeEach, afterEach } from 'vitest';
import { render, screen, waitFor, cleanup } from '@testing-library/react';
import { BrowserRouter } from 'react-router-dom';
import { QueryClient, QueryClientProvider } from '@tanstack/react-query';
import RosterTab from './RosterTab';

// Mock api module — RosterTab only uses api.get
vi.mock('@/services/api', () => ({
  default: {
    get: vi.fn(),
  },
}));

import api from '@/services/api';

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
      </QueryClientProvider>
    </BrowserRouter>
  );
}

describe('RosterTab', () => {
  beforeEach(() => {
    vi.clearAllMocks();
  });

  afterEach(() => {
    cleanup();
  });

  describe('Academic Status Badges', () => {
    it('renders the five academic status labels', async () => {
      api.get.mockResolvedValue({
        data: [
          { id: 1, name: 'Test-Excellent', avg_cds: 0.10 },
          { id: 2, name: 'Test-Strong', avg_cds: 0.30 },
          { id: 3, name: 'Test-Developing', avg_cds: 0.50 },
          { id: 4, name: 'Test-Needs-Support', avg_cds: 0.70 },
          { id: 5, name: 'Test-Critical', avg_cds: 0.90 },
        ],
      });

      renderWithProviders(<RosterTab sectionId={1} sectionName="Test Section" />);

      await waitFor(() => {
        expect(screen.getByText('Test-Excellent')).toBeInTheDocument();
      });

      // The five canonical academic statuses, derived from each student's CDS
      for (const label of ['Excellent', 'Strong', 'Developing', 'Needs Support', 'Critical']) {
        expect(screen.getByText(label)).toBeInTheDocument();
      }

      // The legacy CDS buckets must not appear anywhere
      expect(screen.queryByText('Low')).not.toBeInTheDocument();
      expect(screen.queryByText('Moderate')).not.toBeInTheDocument();
      expect(screen.queryByText('High')).not.toBeInTheDocument();
      expect(screen.queryByText('N/A')).not.toBeInTheDocument();
    });

    it('zero CDS renders Excellent', async () => {
      api.get.mockResolvedValue({
        data: [
          { id: 1, name: 'Test-Zero', avg_cds: '0.00' },
        ],
      });

      renderWithProviders(<RosterTab sectionId={1} sectionName="Test Section" />);

      await waitFor(() => {
        expect(screen.getByText('Test-Zero')).toBeInTheDocument();
      });

      expect(screen.getByText('Excellent')).toBeInTheDocument();
    });
  });
});
