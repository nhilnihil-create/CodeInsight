// frontend/src/test/setup.js
import '@testing-library/jest-dom';

// jsdom does not implement PointerEvent capture APIs, which Radix UI
// primitives (Select, DropdownMenu, …) rely on. Polyfill them so
// components using Radix can be tested without stubbing the whole tree.
if (!Element.prototype.hasPointerCapture) {
  Element.prototype.hasPointerCapture = () => false;
  Element.prototype.setPointerCapture = () => {};
  Element.prototype.releasePointerCapture = () => {};
}

// jsdom 25 removed its (non-standard) PointerEvent implementation entirely.
// fireEvent.pointerDown then falls back to a bare Event with no `button` /
// `pointerType`, so Radix open-on-pointerdown checks (event.button === 0,
// event.pointerType === "mouse") never fire. Restore a minimal spec-shaped
// PointerEvent backed by MouseEvent.
if (typeof window.PointerEvent === 'undefined') {
  class PointerEvent extends window.MouseEvent {
    constructor(type, params = {}) {
      super(type, params);
      this.pointerId = params.pointerId ?? 0;
      this.pointerType = params.pointerType ?? 'mouse';
      this.isPrimary = params.isPrimary ?? true;
      this.width = params.width ?? 1;
      this.height = params.height ?? 1;
      this.pressure = params.pressure ?? 0.5;
      this.tangentialPressure = params.tangentialPressure ?? 0;
      this.tiltX = params.tiltX ?? 0;
      this.tiltY = params.tiltY ?? 0;
      this.twist = params.twist ?? 0;
    }
  }
  window.PointerEvent = PointerEvent;
  globalThis.PointerEvent = PointerEvent;
}
