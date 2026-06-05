// frontend/src/components/mobile/primitives/RiskBadge.test.jsx
import { describe, it, expect } from 'vitest';
import { render, screen } from '@testing-library/react';
import { RiskBadge } from './RiskBadge.jsx';

describe('<RiskBadge mode="mobile">', () => {
  it('always shows the label AND the color (spec §6.1, §13.10)', () => {
    render(<RiskBadge level="critical" mode="mobile" />);
    const el = screen.getByText('Critical');
    expect(el).toBeInTheDocument();
    expect(el.parentElement.dataset.level).toBe('critical');
  });

  it('renders all 4 levels', () => {
    ['low', 'medium', 'high', 'critical'].forEach((l) => {
      const { unmount } = render(<RiskBadge level={l} mode="mobile" />);
      expect(screen.getByText(new RegExp(l, 'i'))).toBeInTheDocument();
      unmount();
    });
  });

  it('renders the symbol as decorative (aria-hidden)', () => {
    render(<RiskBadge level="high" mode="mobile" />);
    const sym = screen.getByText('●⚠');
    expect(sym.getAttribute('aria-hidden')).toBe('true');
  });
});
