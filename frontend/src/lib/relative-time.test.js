// frontend/src/lib/relative-time.test.js
import { describe, it, expect } from 'vitest';
import { formatDurationFromNow, formatDeadlineFromNow, formatMinutesUntilDue } from './relative-time.js';

const NOW = new Date('2026-06-22T12:00:00Z').getTime();
const MIN = 60 * 1000;

describe('formatDurationFromNow', () => {
  it('returns null for invalid input', () => {
    expect(formatDurationFromNow(null)).toBe(null);
    expect(formatDurationFromNow(undefined)).toBe(null);
    expect(formatDurationFromNow(NaN)).toBe(null);
  });

  it('returns "now" for sub-minute values', () => {
    expect(formatDurationFromNow(0)).toBe('now');
    expect(formatDurationFromNow(0.5)).toBe('now');
    expect(formatDurationFromNow(-0.5)).toBe('now');
  });

  it('formats minutes', () => {
    expect(formatDurationFromNow(45)).toBe('45m');
    expect(formatDurationFromNow(-45)).toBe('45m');
    expect(formatDurationFromNow(59.6)).toBe('59m');
    expect(formatDurationFromNow(-59.6)).toBe('59m');
  });

  it('formats hours compactly (minutes dropped)', () => {
    expect(formatDurationFromNow(60)).toBe('1h');
    expect(formatDurationFromNow(-60)).toBe('1h');
    expect(formatDurationFromNow(90)).toBe('1h');
    expect(formatDurationFromNow(-90)).toBe('1h');
    expect(formatDurationFromNow(119)).toBe('1h');
    expect(formatDurationFromNow(-119)).toBe('1h');
  });

  it('formats days and day+hour combos', () => {
    expect(formatDurationFromNow(1440)).toBe('1d');
    expect(formatDurationFromNow(-1440)).toBe('1d');
    expect(formatDurationFromNow(1500)).toBe('1d 1h');
    expect(formatDurationFromNow(-1500)).toBe('1d 1h');
    expect(formatDurationFromNow(5128)).toBe('3d 13h');
    expect(formatDurationFromNow(-5128)).toBe('3d 13h');
  });
});

describe('formatDeadlineFromNow', () => {
  it('returns "No deadline" for missing or invalid deadlines', () => {
    expect(formatDeadlineFromNow(null, NOW)).toBe('No deadline');
    expect(formatDeadlineFromNow(undefined, NOW)).toBe('No deadline');
    expect(formatDeadlineFromNow('not-a-date', NOW)).toBe('No deadline');
  });

  it('returns "Due now" for the current time and near-misses', () => {
    expect(formatDeadlineFromNow(NOW, NOW)).toBe('Due now');
    expect(formatDeadlineFromNow(NOW + 0.5 * MIN, NOW)).toBe('Due now');
    expect(formatDeadlineFromNow(NOW - 0.5 * MIN, NOW)).toBe('Due now');
  });

  it('formats overdue minutes and hours', () => {
    expect(formatDeadlineFromNow(NOW - 45 * MIN, NOW)).toBe('Overdue 45m');
    expect(formatDeadlineFromNow(NOW - 60 * MIN, NOW)).toBe('Overdue 1h');
    expect(formatDeadlineFromNow(NOW - 90 * MIN, NOW)).toBe('Overdue 1h');
  });

  it('formats overdue days (past branch drops hours)', () => {
    expect(formatDeadlineFromNow(NOW - 1440 * MIN, NOW)).toBe('Overdue 1d');
    expect(formatDeadlineFromNow(NOW - 1500 * MIN, NOW)).toBe('Overdue 1d');
    expect(formatDeadlineFromNow(NOW - 5128 * MIN, NOW)).toBe('Overdue 3d');
  });

  it('formats future due times', () => {
    expect(formatDeadlineFromNow(NOW + 45 * MIN, NOW)).toBe('Due in 45m');
    expect(formatDeadlineFromNow(NOW + 60 * MIN, NOW)).toBe('Due in 1h');
    expect(formatDeadlineFromNow(NOW + 90 * MIN, NOW)).toBe('Due in 1h');
    expect(formatDeadlineFromNow(NOW + 1440 * MIN, NOW)).toBe('Due in 1d');
    expect(formatDeadlineFromNow(NOW + 1500 * MIN, NOW)).toBe('Due in 1d 1h');
    expect(formatDeadlineFromNow(NOW + 2880 * MIN, NOW)).toBe('Due in 2d');
    expect(formatDeadlineFromNow(NOW + 10080 * MIN, NOW)).toBe('Due in 7d');
  });

  it('accepts ISO date strings', () => {
    expect(formatDeadlineFromNow(new Date(NOW - 45 * MIN).toISOString(), NOW)).toBe('Overdue 45m');
  });
});

describe('formatMinutesUntilDue', () => {
  it('returns "No deadline" for invalid input', () => {
    expect(formatMinutesUntilDue(null)).toBe('No deadline');
    expect(formatMinutesUntilDue(undefined)).toBe('No deadline');
    expect(formatMinutesUntilDue(NaN)).toBe('No deadline');
  });

  it('returns "Due now" for sub-minute values before the sign check', () => {
    expect(formatMinutesUntilDue(0)).toBe('Due now');
    expect(formatMinutesUntilDue(0.5)).toBe('Due now');
    expect(formatMinutesUntilDue(-0.5)).toBe('Due now');
  });

  it('formats overdue durations', () => {
    expect(formatMinutesUntilDue(-45)).toBe('Overdue 45m');
    expect(formatMinutesUntilDue(-60)).toBe('Overdue 1h');
    expect(formatMinutesUntilDue(-90)).toBe('Overdue 1h');
    expect(formatMinutesUntilDue(-1500)).toBe('Overdue 1d 1h');
    expect(formatMinutesUntilDue(-5128)).toBe('Overdue 3d 13h');
  });

  it('formats due-in durations', () => {
    expect(formatMinutesUntilDue(45)).toBe('Due in 45m');
    expect(formatMinutesUntilDue(90)).toBe('Due in 1h');
    expect(formatMinutesUntilDue(1500)).toBe('Due in 1d 1h');
    expect(formatMinutesUntilDue(5128)).toBe('Due in 3d 13h');
  });
});
