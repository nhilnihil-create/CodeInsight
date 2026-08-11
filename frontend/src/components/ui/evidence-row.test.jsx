import { describe, it, expect, vi } from 'vitest';
import { render, screen } from '@testing-library/react';
import EvidenceRow from './evidence-row';

// KPIChartCard pulls in recharts + framer-motion; stub it out so those
// heavy dependencies never load in the unit test environment.
vi.mock('./kpi-chart-card', () => ({
  default: () => <div data-testid="kpi-card" />,
}));

// Minimal chip fixtures (cards are mocked, so no prop validation is needed).
// Labels double as React keys and are unique per rendered row.
const makeChips = (count) =>
  Array.from({ length: count }, (_, i) => ({
    label: `chip-${count}-${i}`,
    value: '1.0',
    series: [],
  }));

describe('EvidenceRow', () => {
  it.each([
    { count: 6, expectedClass: 'lg:grid-cols-3' },
    { count: 3, expectedClass: 'grid-cols-3' },
    { count: 4, expectedClass: 'lg:grid-cols-4' },
    { count: 2, expectedClass: 'sm:grid-cols-2' },
    { count: 0, expectedClass: 'grid-cols-1' },
  ])(
    'renders a $count-chip grid with the $expectedClass branch',
    ({ count, expectedClass }) => {
      render(<EvidenceRow chips={makeChips(count)} />);

      const grid = screen.getByRole('group', { name: /supporting evidence/i });
      expect(grid).toHaveClass(expectedClass);

      if (count === 6) {
        expect(grid).not.toHaveClass('lg:grid-cols-4');
        expect(screen.getAllByTestId('kpi-card')).toHaveLength(6);
      }
    }
  );
});
