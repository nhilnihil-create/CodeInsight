// frontend/src/components/mobile/PullToRefresh.test.jsx
import { describe, it, expect, vi, beforeAll } from 'vitest';
import { fireEvent, render } from '@testing-library/react';
import { PullToRefresh } from './PullToRefresh.jsx';

// jsdom 25 does not implement PointerEvent; fireEvent.pointerDown falls back to
// a generic Event, which strips clientY/pointerId. Polyfill it for this suite
// so the verbatim test below can read e.clientY.
beforeAll(() => {
  if (typeof window.PointerEvent !== 'undefined') return;
  class PointerEventPolyfill extends MouseEvent {
    constructor(type, init = {}) {
      super(type, init);
      Object.defineProperty(this, 'pointerId', { value: init.pointerId ?? 0, configurable: true });
      Object.defineProperty(this, 'clientX', { value: init.clientX ?? 0, configurable: true });
      Object.defineProperty(this, 'clientY', { value: init.clientY ?? 0, configurable: true });
    }
  }
  window.PointerEvent = PointerEventPolyfill;
});

describe('<PullToRefresh>', () => {
  it('calls onRefresh when pulled past 60px', () => {
    const onRefresh = vi.fn();
    const { container } = render(<PullToRefresh onRefresh={onRefresh}><div /></PullToRefresh>);
    // simulate drag
    const node = container.firstChild;
    fireEvent.pointerDown(node, { clientY: 100, pointerId: 1 });
    fireEvent.pointerMove(node, { clientY: 200, pointerId: 1 });
    fireEvent.pointerUp(node, { clientY: 200, pointerId: 1 });
    expect(onRefresh).toHaveBeenCalled();
  });

  it('does not call onRefresh when pulled < 60px', () => {
    const onRefresh = vi.fn();
    const { container } = render(<PullToRefresh onRefresh={onRefresh}><div /></PullToRefresh>);
    const node = container.firstChild;
    fireEvent.pointerDown(node, { clientY: 100, pointerId: 1 });
    fireEvent.pointerMove(node, { clientY: 120, pointerId: 1 });
    fireEvent.pointerUp(node, { clientY: 120, pointerId: 1 });
    expect(onRefresh).not.toHaveBeenCalled();
  });
});
