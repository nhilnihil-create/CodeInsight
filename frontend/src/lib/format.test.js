// frontend/src/lib/format.test.js
import { describe, it, expect } from 'vitest';
import { formatDateAgo, formatDuration } from './format.js';

const NOW = new Date('2026-06-22T12:00:00Z').getTime();
const MIN = 60 * 1000;
const HR = 60 * MIN;
const DAY = 24 * HR;

describe('formatDateAgo', () => {
  it('returns em dash for null/undefined/empty input', () => {
    expect(formatDateAgo(null, NOW)).toBe('—');
    expect(formatDateAgo(undefined, NOW)).toBe('—');
    expect(formatDateAgo('', NOW)).toBe('—');
  });

  it('returns "just now" for the current time', () => {
    expect(formatDateAgo(NOW, NOW)).toBe('just now');
  });

  it('formats 5 minutes ago', () => {
    expect(formatDateAgo(NOW - 5 * MIN, NOW)).toBe('5 minutes ago');
  });

  it('formats 1 minute ago with singular wording', () => {
    expect(formatDateAgo(NOW - 1 * MIN, NOW)).toBe('1 minute ago');
  });

  it('formats 3 hours ago', () => {
    expect(formatDateAgo(NOW - 3 * HR, NOW)).toBe('3 hours ago');
  });

  it('formats 1 day ago with singular wording', () => {
    expect(formatDateAgo(NOW - 1 * DAY, NOW)).toBe('1 day ago');
  });

  it('formats 2 days ago with plural wording', () => {
    expect(formatDateAgo(NOW - 2 * DAY, NOW)).toBe('2 days ago');
  });

  it('returns "just now" for future timestamps', () => {
    expect(formatDateAgo(NOW + MIN, NOW)).toBe('just now');
  });

  it('accepts ISO date strings', () => {
    expect(formatDateAgo(new Date(NOW - 5 * MIN).toISOString(), NOW)).toBe('5 minutes ago');
  });

  it('accepts epoch-seconds number input', () => {
    expect(formatDateAgo((NOW - 5 * MIN) / 1000, NOW)).toBe('5 minutes ago');
  });

  it('accepts epoch-milliseconds number input', () => {
    expect(formatDateAgo(NOW - 5 * MIN, NOW)).toBe('5 minutes ago');
  });

  it('accepts digit-only string input as seconds', () => {
    expect(formatDateAgo(String((NOW - 5 * MIN) / 1000), NOW)).toBe('5 minutes ago');
  });

  it('returns em dash for invalid date strings', () => {
    expect(formatDateAgo('not-a-date', NOW)).toBe('—');
  });
});

describe('formatDuration', () => {
  it('returns em dash for null/undefined', () => {
    expect(formatDuration(null)).toBe('—');
    expect(formatDuration(undefined)).toBe('—');
  });

  it('formats sub-minute durations as seconds', () => {
    expect(formatDuration(45)).toBe('45s');
  });

  it('formats zero as "0s"', () => {
    expect(formatDuration(0)).toBe('0s');
  });

  it('formats 90 seconds as "1m 30s"', () => {
    expect(formatDuration(90)).toBe('1m 30s');
  });

  it('formats 120 seconds as "2m" (omits "00s")', () => {
    expect(formatDuration(120)).toBe('2m');
  });

  it('rounds 61 seconds to "1m 1s"', () => {
    expect(formatDuration(61)).toBe('1m 1s');
  });

  it('formats 754 seconds as "12m 34s"', () => {
    expect(formatDuration(754)).toBe('12m 34s');
  });

  it('formats 3600 seconds as "1h 00m"', () => {
    expect(formatDuration(3600)).toBe('1h 00m');
  });

  it('formats 3900 seconds as "1h 05m"', () => {
    expect(formatDuration(3900)).toBe('1h 05m');
  });

  it('formats 5400 seconds as "1h 30m"', () => {
    expect(formatDuration(5400)).toBe('1h 30m');
  });

  it('formats 7200 seconds as "2h 00m"', () => {
    expect(formatDuration(7200)).toBe('2h 00m');
  });

  it('clamps negative durations to "0s"', () => {
    expect(formatDuration(-30)).toBe('0s');
  });
});
