import { describe, it, expect } from 'vitest';
import { render, screen } from '@testing-library/react';
import EmptyState from './empty-state';
import { Button } from './button';

describe('EmptyState', () => {
  it('renders title and description', () => {
    render(<EmptyState title="No results" description="Try adjusting your search" />);
    expect(screen.getByText('No results')).toBeInTheDocument();
    expect(screen.getByText('Try adjusting your search')).toBeInTheDocument();
  });

  it('renders with icon', () => {
    const { container } = render(
      <EmptyState title="Empty" description="Nothing here" icon={<span data-testid="test-icon">🔍</span>} />
    );
    expect(container.querySelector('svg, span')).toBeInTheDocument();
  });

  it('renders with action button', () => {
    render(
      <EmptyState
        title="No items"
        description="Add your first item"
        action={<Button>Create</Button>}
      />
    );
    expect(screen.getByRole('button', { name: /create/i })).toBeInTheDocument();
  });

  it('renders footnote', () => {
    render(
      <EmptyState title="Empty" description="No data" footnote="Last updated 5m ago" />
    );
    expect(screen.getByText('Last updated 5m ago')).toBeInTheDocument();
  });

  it('has role="status" for accessibility', () => {
    render(<EmptyState title="Empty" description="Nothing" />);
    expect(screen.getByRole('status')).toBeInTheDocument();
  });
});
