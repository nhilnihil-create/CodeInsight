// frontend/src/hooks/useAdaptiveN.test.js
import { describe, it, expect } from 'vitest';
import { computeN } from './useAdaptiveN.js';

describe('computeN', () => {
  it('returns 5 when viewport fits 5 rows comfortably', () => {
    // viewportHeight=812 (iPhone 14), chrome=104, primary=200, rowHeight=88
    expect(computeN(812, 104, 200, 88)).toBe(5);
  });

  it('returns 3 on a shorter foldable inner display', () => {
    // viewportHeight=600, chrome=104, primary=200, rowHeight=88
    expect(computeN(600, 104, 200, 88)).toBe(3);
  });

  it('never returns 0 even when viewport is very short', () => {
    expect(computeN(200, 104, 200, 88)).toBe(1);
  });

  it('never returns more than 5 (spec cap)', () => {
    expect(computeN(4000, 0, 0, 88)).toBe(5);
  });

  it('uses the formula min(5, floor((vh - chrome - primary) / rowHeight))', () => {
    // (812 - 104 - 200) / 88 = 508/88 = 5.77 → floor=5 → min(5,5)=5
    expect(computeN(812, 104, 200, 88)).toBe(5);
    // (640 - 104 - 200) / 88 = 336/88 = 3.81 → floor=3 → min(5,3)=3
    expect(computeN(640, 104, 200, 88)).toBe(3);
  });
});
