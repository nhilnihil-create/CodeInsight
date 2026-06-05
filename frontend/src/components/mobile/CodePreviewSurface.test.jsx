// frontend/src/components/mobile/CodePreviewSurface.test.jsx
import { describe, it, expect, vi } from 'vitest';
import { render, screen, fireEvent } from '@testing-library/react';
import { CodePreviewSurface } from './CodePreviewSurface.jsx';

describe('<CodePreviewSurface>', () => {
  const data = {
    id: 'ex-3',
    title: 'Nested Loops',
    code: '#include <iostream>\nint main() { return 0; }',
    language: 'cpp',
    difficulty: 0.62,
    concepts: ['LP'],
  };

  it('renders the title and concepts', () => {
    render(<CodePreviewSurface data={data} onRun={() => {}} onSubmit={() => {}} />);
    expect(screen.getByText('Nested Loops')).toBeInTheDocument();
    expect(screen.getByText(/LP/)).toBeInTheDocument();
  });

  it('renders code inside a horizontal-scrollable <pre> (no Monaco)', () => {
    const { container } = render(<CodePreviewSurface data={data} onRun={() => {}} onSubmit={() => {}} />);
    const pre = container.querySelector('pre');
    expect(pre).toBeInTheDocument();
    expect(pre.className).toMatch(/code-preview-surface/);
    expect(pre.style.overflowX).toBe('auto');
  });

  it('fires onRun and onSubmit callbacks', () => {
    const onRun = vi.fn();
    const onSubmit = vi.fn();
    render(<CodePreviewSurface data={data} onRun={onRun} onSubmit={onSubmit} />);
    fireEvent.click(screen.getByText('▶ Run'));
    fireEvent.click(screen.getByText('Submit'));
    expect(onRun).toHaveBeenCalled();
    expect(onSubmit).toHaveBeenCalled();
  });
});
