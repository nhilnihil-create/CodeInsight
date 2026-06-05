// frontend/src/hooks/use-mode.test.js
import { describe, it, expect, vi, afterEach } from 'vitest';
import { renderHook } from '@testing-library/react';
import { useMode, breakpointFromWidth } from './use-mobile.js';

describe('breakpointFromWidth', () => {
  it('returns "mobile" below 640', () => {
    expect(breakpointFromWidth(320)).toBe('mobile');
    expect(breakpointFromWidth(639)).toBe('mobile');
  });
  it('returns "tablet" at 640-1023', () => {
    expect(breakpointFromWidth(640)).toBe('tablet');
    expect(breakpointFromWidth(1023)).toBe('tablet');
  });
  it('returns "desktop" at 1024+', () => {
    expect(breakpointFromWidth(1024)).toBe('desktop');
    expect(breakpointFromWidth(1920)).toBe('desktop');
  });
});

describe('useMode', () => {
  afterEach(() => {
    window.innerWidth = 1024;
  });

  it('returns "desktop" by default at 1024px', () => {
    window.innerWidth = 1024;
    const { result } = renderHook(() => useMode());
    expect(result.current).toBe('desktop');
  });

  it('returns "mobile" at 375px', () => {
    window.innerWidth = 375;
    const { result } = renderHook(() => useMode());
    expect(result.current).toBe('mobile');
  });
});
