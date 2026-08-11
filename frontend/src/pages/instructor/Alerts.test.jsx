// InstructorAlerts Component Tests
// Verifies the intervention queue renders the cds_scores-based contract:
// at-risk rows (student, tier, CDS), the 6-tier distribution chips, the
// insight summary, search filtering, and the error state.

import { describe, it, expect, vi, beforeEach, afterEach } from 'vitest';
import { render, screen, fireEvent, waitFor, cleanup, within } from '@testing-library/react';

// Mock the analytics service so the page renders a fixed queue payload.
vi.mock('@/api/analyticsService', () => ({
  default: {
    getInterventionQueue: vi.fn(),
  },
}));

// SectionFilter + useLastSection depend on the api client and auth context.
vi.mock('@/services/api', () => ({
  default: {
    get: vi.fn(),
  },
}));

vi.mock('@/context/AuthContext', () => ({
  useAuth: () => ({ user: { id: 7 } }),
}));

// KPIChartCard (rendered via EvidenceRow) and MasteryBar pull in recharts /
// framer-motion; stub them so the tree renders deterministically in jsdom.
vi.mock('recharts', () => ({
  ResponsiveContainer: ({ children }) => <div>{children}</div>,
  LineChart: ({ children }) => <div>{children}</div>,
  Line: () => null,
}));

vi.mock('framer-motion', () => {
  // Strip framer-motion animation props so stubbing motion.* as a plain DOM
  // element does not trigger "React does not recognize the `whileHover` prop"
  // warnings in the rendered tree.
  const Motion = ({ children, _initial, _animate, _exit, _whileHover, _whileTap, _whileInView, _viewport, _variants, _transition, ...rest }) => (
    <div {...rest}>{children}</div>
  );
  return {
    motion: new Proxy({}, { get: () => Motion }),
    useInView: () => true,
  };
});

import analyticsService from '@/api/analyticsService';
import api from '@/services/api';
import InstructorAlerts from './Alerts';

const QUEUE = {
  sectionId: 1,
  totalStudents: 5,
  atRisk: [
    {
      studentId: 1,
      studentName: 'Alice',
      avgCds: 0.9,
      worstCds: 0.95,
      exerciseId: 10,
      exerciseTitle: 'Loops Lab',
      conceptName: 'Loops',
      computedAt: '2026-08-10T10:00:00.000Z',
      tier: 'critical',
    },
    {
      studentId: 2,
      studentName: 'Bob',
      avgCds: 0.7,
      worstCds: 0.72,
      exerciseId: 11,
      exerciseTitle: 'Arrays Quiz',
      conceptName: 'Arrays',
      computedAt: '2026-08-10T10:00:00.000Z',
      tier: 'needs_support',
    },
  ],
  tierDistribution: {
    excellent: 2,
    strong: 1,
    developing: 0,
    needs_support: 1,
    critical: 1,
    unstarted: 0,
  },
  insight: {
    atRiskCount: 2,
    summary: '2 students are at high risk of failing this section.',
  },
};

describe('InstructorAlerts', () => {
  beforeEach(() => {
    vi.clearAllMocks();
    localStorage.setItem('codeinsight:lastSection', '1');
    api.get.mockResolvedValue({ data: [] });
  });

  afterEach(() => {
    cleanup();
    localStorage.clear();
  });

  it('renders at-risk students, tiers, insight and tier distribution', async () => {
    analyticsService.getInterventionQueue.mockResolvedValue({ data: QUEUE });

    render(<InstructorAlerts />);

    expect(analyticsService.getInterventionQueue).toHaveBeenCalledWith(1);

    // At-risk rows
    expect(await screen.findByText('Alice')).toBeInTheDocument();
    expect(screen.getByText('Bob')).toBeInTheDocument();
    expect(screen.getByText('Loops Lab')).toBeInTheDocument();
    expect(screen.getByText('0.90')).toBeInTheDocument();
    expect(screen.getByText('0.70')).toBeInTheDocument();

    // Insight summary from the backend contract
    expect(
      screen.getByText('2 students are at high risk of failing this section.')
    ).toBeInTheDocument();

    // Enrolled count in the queue header
    expect(screen.getByText(/5 enrolled/)).toBeInTheDocument();

    // 6-tier distribution chips
    const evidence = within(screen.getByRole('group', { name: /supporting evidence/i }));
    for (const label of ['Critical', 'Needs Support', 'Developing', 'Strong', 'Excellent', 'Unstarted']) {
      expect(evidence.getByText(label)).toBeInTheDocument();
    }
  });

  it('filters the queue by search query', async () => {
    analyticsService.getInterventionQueue.mockResolvedValue({ data: QUEUE });

    render(<InstructorAlerts />);

    await screen.findByText('Alice');

    const searchInput = screen.getByPlaceholderText(/search student, concept, or exercise/i);
    fireEvent.change(searchInput, { target: { value: 'Alice' } });

    await waitFor(() => {
      expect(screen.getByText('Alice')).toBeInTheDocument();
      expect(screen.queryByText('Bob')).not.toBeInTheDocument();
    });
  });

  it('shows the empty state when no students are at risk', async () => {
    analyticsService.getInterventionQueue.mockResolvedValue({
      data: {
        ...QUEUE,
        atRisk: [],
        insight: { atRiskCount: 0, summary: 'No students currently at high risk in this section.' },
      },
    });

    render(<InstructorAlerts />);

    // Empty-state paragraph + insight summary both reference the no-risk state.
    const noRisk = await screen.findAllByText(/no students currently at high risk/i);
    expect(noRisk.length).toBeGreaterThanOrEqual(2);
    expect(
      screen.getByText('No students currently at high risk in this section.')
    ).toBeInTheDocument();
  });

  it('shows the error message when the queue fails to load', async () => {
    analyticsService.getInterventionQueue.mockRejectedValue({
      response: { data: { error: 'Section not found' } },
    });

    render(<InstructorAlerts />);

    // Error shows inline in the header and in the retry banner.
    const errors = await screen.findAllByText('Section not found');
    expect(errors.length).toBeGreaterThanOrEqual(1);
  });
});
