// frontend/src/state/StateAwareShell.test.jsx
import { describe, it, expect } from 'vitest';
import { render, screen } from '@testing-library/react';
import { StateAwareShell } from './StateAwareShell.jsx';

describe('<StateAwareShell>', () => {
  it('renders NoData copy when state is NoData and there is no data', () => {
    render(
      <StateAwareShell role="instructor" data={null} state="NoData" />
    );
    expect(screen.getByText(/No exercise activity yet/)).toBeInTheDocument();
    expect(screen.getByText(/Open exercises/)).toBeInTheDocument();
  });

  it('renders children when state is Healthy and data is present', () => {
    render(
      <StateAwareShell role="instructor" data={{ insight: 'hi' }} state="Healthy">
        <div data-testid="child">child content</div>
      </StateAwareShell>
    );
    expect(screen.getByTestId('child')).toBeInTheDocument();
  });

  it('shows Limited badge when state is LowConfidence', () => {
    render(
      <StateAwareShell role="instructor" data={{}} state="LowConfidence" progressText="5 of 150 submissions to full confidence">
        <div>real content</div>
      </StateAwareShell>
    );
    expect(screen.getByText('Limited')).toBeInTheDocument();
    expect(screen.getByText(/5 of 150/)).toBeInTheDocument();
  });
});
