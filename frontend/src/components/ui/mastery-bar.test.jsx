import { describe, it, expect, vi } from 'vitest';
import { render } from '@testing-library/react';

vi.mock('framer-motion', () => {
  const MockMotion = ({ children, initial, animate, transition, ...rest }) => {
    void initial;
    void animate;
    void transition;
    return <div {...rest}>{children}</div>;
  };
  return { motion: new Proxy({}, { get: () => MockMotion }), useInView: () => true };
});

import MasteryBar, { TIER_BAR } from './mastery-bar';

describe('MasteryBar', () => {
  it.each(Object.entries(TIER_BAR))('renders academic bar class %s -> %s', (tier, cls) => {
    const { container } = render(<MasteryBar percent={66} tier={tier} />);
    const bar = container.querySelector('.' + cls);
    expect(bar).toBeInTheDocument();
    expect(bar).toHaveClass('h-full', 'rounded-full');
    expect(bar.className).not.toContain('mastery-bar');
  });

  it('falls back to tier-excellent-bar for unknown tiers', () => {
    const { container } = render(<MasteryBar percent={66} tier="unknown" />);
    expect(container.querySelector('.tier-excellent-bar')).toBeInTheDocument();
  });

  it('defaults to the strong tier when tier is omitted', () => {
    const { container } = render(<MasteryBar percent={66} />);
    expect(container.querySelector('.tier-strong-bar')).toBeInTheDocument();
  });
});
