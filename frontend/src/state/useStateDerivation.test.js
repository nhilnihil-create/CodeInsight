// frontend/src/state/useStateDerivation.test.js
import { describe, it, expect } from 'vitest';
import { deriveState } from './useStateDerivation.js';

describe('deriveState (priority insight taxonomy)', () => {
  it('returns "NoData" when there are 0 submissions', () => {
    expect(deriveState({ submissionsPerStudent: 0, sectionAgeDays: 30, students: 50 })
      .state).toBe('NoData');
  });

  it('returns "NoData" when section is < 24h old regardless of submissions', () => {
    expect(deriveState({ submissionsPerStudent: 5, sectionAgeDays: 0, students: 10 })
      .state).toBe('NoData');
  });

  it('returns "LowConfidence" when 1-2 submissions per student', () => {
    expect(deriveState({ submissionsPerStudent: 1, sectionAgeDays: 30, students: 50 })
      .state).toBe('LowConfidence');
  });

  it('returns "LowConfidence" when section is < 14d old even with 3+ submissions', () => {
    expect(deriveState({ submissionsPerStudent: 3, sectionAgeDays: 5, students: 50 })
      .state).toBe('LowConfidence');
  });

  it('returns "Healthy" when >= 3 submissions per student AND section >= 14d', () => {
    expect(deriveState({ submissionsPerStudent: 3, sectionAgeDays: 14, students: 50 })
      .state).toBe('Healthy');
  });

  it('includes a numeric progress counter when LowConfidence', () => {
    const r = deriveState({ submissionsPerStudent: 1, sectionAgeDays: 30, students: 50 });
    expect(r.progressText).toMatch(/2 of 50/);
  });

  it('Healthy returns no progressText', () => {
    const r = deriveState({ submissionsPerStudent: 3, sectionAgeDays: 30, students: 50 });
    expect(r.progressText).toBeUndefined();
  });
});
