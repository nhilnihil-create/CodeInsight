import { describe, it, expect } from 'vitest';
import { renderHook } from '@testing-library/react';
import useAnalyticsTheme, { computeCDSTier, computeMasteryTier, CDS_TIERS, MASTERY_TIERS } from './useAnalyticsTheme';

describe('computeCDSTier', () => {
  it('returns No Data for null', () => {
    expect(computeCDSTier(null).label).toBe('No Data');
  });

  it('returns No Data for undefined', () => {
    expect(computeCDSTier(undefined).label).toBe('No Data');
  });

  it('returns No Data for NaN', () => {
    expect(computeCDSTier(NaN).label).toBe('No Data');
  });

  it('classifies 0.00 as tier 1 (Minimal Struggle)', () => {
    const result = computeCDSTier(0);
    expect(result.tier).toBe(1);
    expect(result.label).toContain('Minimal Struggle');
  });

  it('classifies 0.15 as tier 1 (boundary)', () => {
    expect(computeCDSTier(0.15).tier).toBe(1);
  });

  it('classifies 0.16 as tier 2 (Expected Resistance)', () => {
    const result = computeCDSTier(0.16);
    expect(result.tier).toBe(2);
    expect(result.label).toContain('Expected Resistance');
  });

  it('classifies 0.55 as tier 3 (Moderate Friction)', () => {
    const result = computeCDSTier(0.55);
    expect(result.tier).toBe(3);
    expect(result.label).toContain('Moderate Friction');
  });

  it('classifies 0.75 as tier 4 (High Struggle)', () => {
    const result = computeCDSTier(0.75);
    expect(result.tier).toBe(4);
    expect(result.label).toContain('High Struggle');
  });

  it('classifies 0.76 as tier 5 (Critical Blocker)', () => {
    const result = computeCDSTier(0.76);
    expect(result.tier).toBe(5);
    expect(result.label).toContain('Critical Blocker');
  });

  it('classifies 1.0 as tier 5', () => {
    expect(computeCDSTier(1.0).tier).toBe(5);
  });

  it('clamps values below CDS_TIERS[0].min to tier 5', () => {
    const result = computeCDSTier(-1);
    expect(result.tier).toBe(5);
  });

  it('clamps values above CDS_TIERS[4].max to tier 1', () => {
    const result = computeCDSTier(2);
    expect(result.tier).toBe(1);
  });

  it('rounds to 2 decimal places', () => {
    expect(computeCDSTier(0.156).tier).toBe(2);
    expect(computeCDSTier(0.155).tier).toBe(2);
    expect(computeCDSTier(0.154).tier).toBe(1);
  });
});

describe('computeMasteryTier', () => {
  it('returns No Data for null', () => {
    expect(computeMasteryTier(null).label).toBe('No Data');
  });

  it('classifies 95 as tier 1 (Excellent Mastery)', () => {
    const result = computeMasteryTier(95);
    expect(result.tier).toBe(1);
    expect(result.label).toContain('Excellent Mastery');
  });

  it('classifies 85 as tier 1 (boundary)', () => {
    expect(computeMasteryTier(85).tier).toBe(1);
  });

  it('classifies 75 as tier 2 (Nominal Progress)', () => {
    const result = computeMasteryTier(75);
    expect(result.tier).toBe(2);
    expect(result.label).toContain('Nominal Progress');
  });

  it('classifies 50 as tier 3 (Moderate Challenge)', () => {
    const result = computeMasteryTier(50);
    expect(result.tier).toBe(3);
    expect(result.label).toContain('Moderate Challenge');
  });

  it('classifies 30 as tier 4 (Significant Struggle)', () => {
    const result = computeMasteryTier(30);
    expect(result.tier).toBe(4);
    expect(result.label).toContain('Significant Struggle');
  });

  it('classifies 10 as tier 5 (Critical Support Required)', () => {
    const result = computeMasteryTier(10);
    expect(result.tier).toBe(5);
    expect(result.label).toContain('Critical Support Required');
  });

  it('classifies 0 as tier 5', () => {
    expect(computeMasteryTier(0).tier).toBe(5);
  });

  it('clamps values below range to tier 5', () => {
    expect(computeMasteryTier(-10).tier).toBe(5);
  });

  it('clamps values above range to tier 1', () => {
    expect(computeMasteryTier(110).tier).toBe(1);
  });
});

describe('useAnalyticsTheme hook', () => {
  it('returns CDS theme by default', () => {
    const { result } = renderHook(() => useAnalyticsTheme(0.8));
    expect(result.current.tier).toBe(5);
    expect(result.current.color).toBe('rose');
  });

  it('returns Mastery theme when metricType=MASTERY', () => {
    const { result } = renderHook(() => useAnalyticsTheme(92, 'MASTERY'));
    expect(result.current.tier).toBe(1);
    expect(result.current.color).toBe('slate');
  });

  it('returns No Data for invalid value', () => {
    const { result } = renderHook(() => useAnalyticsTheme(null));
    expect(result.current.label).toBe('No Data');
    expect(result.current.tier).toBe(0);
  });

  it('is case-insensitive for metricType', () => {
    const r1 = renderHook(() => useAnalyticsTheme(92, 'mastery'));
    const r2 = renderHook(() => useAnalyticsTheme(92, 'Mastery'));
    expect(r1.result.current.tier).toBe(r2.result.current.tier);
  });

  it('falls back to CDS for unknown metricType', () => {
    const { result } = renderHook(() => useAnalyticsTheme(0.8, 'UNKNOWN'));
    expect(result.current.tier).toBe(5);
  });

  it('memoizes the result (same inputs → same reference)', () => {
    const { result, rerender } = renderHook(
      ({ value, type }) => useAnalyticsTheme(value, type),
      { initialProps: { value: 0.3, type: 'CDS' } }
    );
    const first = result.current;
    rerender({ value: 0.3, type: 'CDS' });
    expect(result.current).toBe(first);
  });

  it('recomputes when value changes', () => {
    const { result, rerender } = renderHook(
      ({ value }) => useAnalyticsTheme(value, 'CDS'),
      { initialProps: { value: 0.3 } }
    );
    expect(result.current.tier).toBe(2);
    rerender({ value: 0.8 });
    expect(result.current.tier).toBe(5);
  });
});
