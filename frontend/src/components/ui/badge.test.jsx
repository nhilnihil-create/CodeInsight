import { describe, it, expect } from 'vitest';
import { render, screen } from '@testing-library/react';
import { Badge } from './badge';

describe('Badge', () => {
  it('renders default badge with text', () => {
    render(<Badge>Active</Badge>);
    expect(screen.getByText('Active')).toBeInTheDocument();
  });

  it('renders with destructive variant', () => {
    const { container } = render(<Badge variant="destructive">Error</Badge>);
    expect(container.firstChild).toHaveClass('bg-destructive');
  });

  it('renders with success variant', () => {
    const { container } = render(<Badge variant="success">Passed</Badge>);
    expect(container.firstChild).toHaveClass('bg-green-500/15');
  });

  it('renders with warning variant', () => {
    const { container } = render(<Badge variant="warning">Warning</Badge>);
    expect(container.firstChild).toHaveClass('bg-amber-500/15');
  });

  it('renders with custom className', () => {
    const { container } = render(<Badge className="custom-class">Styled</Badge>);
    expect(container.firstChild).toHaveClass('custom-class');
  });
});
