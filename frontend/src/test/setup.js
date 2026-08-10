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
