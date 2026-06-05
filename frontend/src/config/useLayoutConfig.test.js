// frontend/src/config/useLayoutConfig.test.js
import { describe, it, expect, vi } from 'vitest';
import { getConfig, shouldShow } from './useLayoutConfig.js';

describe('getConfig (instructor, mobile)', () => {
  const cfg = getConfig('instructor', 'mobile');

  it('has chrome.appBar with rightSlot="menu"', () => {
    expect(cfg.chrome.appBar.rightSlot).toBe('menu');
  });

  it('has bottomNav with 5 destinations', () => {
    expect(cfg.chrome.bottomNav.items).toHaveLength(5);
  });

  it('/instructor/command has 1 primary widget, 0-2 secondary, multiple tertiary', () => {
    const screen = cfg.screens['/instructor/command'];
    expect(screen.primary).toBeDefined();
    expect(screen.secondary.length).toBeLessThanOrEqual(2);
    expect(screen.tertiary.length).toBeGreaterThanOrEqual(1);
  });

  it('every widget ref across all 3 roles uses a canonical widget name', () => {
    const CANONICAL = new Set([
      // Instructor
      'InstructorPriorityInsight', 'AtRiskQueue', 'AtRiskRoster', 'InterventionQueue',
      'TopStrugglingConcepts', 'ClassProfileRadar', 'WeeklyTeachingInsight',
      'IntegrityFlagCount', 'IntegrityFlagList', 'IntegrityFlagHistory',
      'IntegrityDrillNotice', 'SectionList',
      // Student
      'StudentTodayFocus', 'ActionStack', 'WeakestConceptBar', 'ExerciseCardList',
      'CodePreviewSurface', 'TestResultList', 'OpenFullEditorHint',
      'WeeklyProgress', 'ConceptMasteryBarSet',
      // Admin
      'SnapshotMetrics', 'EvaluationProgress', 'AuditLog',
      'Iso25010Instrument', 'DesktopOnlyNotice',
    ]);
    const roles = ['instructor', 'student', 'admin'];
    for (const role of roles) {
      const cfg = getConfig(role, 'mobile');
      for (const [route, screen] of Object.entries(cfg.screens)) {
        for (const w of [screen.primary, screen.primaryAction, ...screen.secondary, ...screen.tertiary]) {
          if (!w) continue;  // primaryAction may be undefined
          expect(CANONICAL, `${role}${route} -> ${w.widget}`).toContain(w.widget);
        }
      }
    }
  });
});

describe('getConfig (student, mobile)', () => {
  const cfg = getConfig('student', 'mobile');
  it('has bottomNav with 5 destinations', () => {
    expect(cfg.chrome.bottomNav.items).toHaveLength(5);
  });
  it('/student/today has StudentTodayFocus as primary', () => {
    expect(cfg.screens['/student/today'].primary.widget).toBe('StudentTodayFocus');
  });
});

describe('getConfig (admin, mobile)', () => {
  const cfg = getConfig('admin', 'mobile');
  it('has bottomNav with 3 destinations', () => {
    expect(cfg.chrome.bottomNav.items).toHaveLength(3);
  });
  it('/admin/overview has SnapshotMetrics as primary AND EvaluationProgress as primaryAction', () => {
    expect(cfg.screens['/admin/overview'].primary.widget).toBe('SnapshotMetrics');
    expect(cfg.screens['/admin/overview'].primaryAction.widget).toBe('EvaluationProgress');
  });
});

describe('shouldShow', () => {
  const widgetNoShow = { widget: 'X' };
  const widgetLengthGt0 = { widget: 'X', showIf: 'data.length > 0' };
  const widgetLengthGt2 = { widget: 'X', showIf: 'data.length > 2' };
  const widgetAmpLength = { widget: 'X', showIf: 'data && data.length > 0' };
  const widgetCountGe1 = { widget: 'X', showIf: 'data.count >= 1' };
  const widgetUnknown = { widget: 'X', showIf: 'data.weird.path > 0' };

  it('returns true when widget has no showIf', () => {
    expect(shouldShow(widgetNoShow, [1, 2, 3])).toBe(true);
  });
  it('data.length > 0 is true iff data is a non-empty array', () => {
    expect(shouldShow(widgetLengthGt0, [1])).toBe(true);
    expect(shouldShow(widgetLengthGt0, [])).toBe(false);
    expect(shouldShow(widgetLengthGt0, null)).toBe(false);
  });
  it('data.length > 2 requires at least 3 items', () => {
    expect(shouldShow(widgetLengthGt2, [1, 2, 3])).toBe(true);
    expect(shouldShow(widgetLengthGt2, [1, 2])).toBe(false);
  });
  it('data && data.length > 0 is equivalent to data.length > 0 (defensive)', () => {
    expect(shouldShow(widgetAmpLength, [1])).toBe(true);
    expect(shouldShow(widgetAmpLength, [])).toBe(false);
  });
  it('data.count >= 1 evaluates the dotted path with JSON.parse values', () => {
    expect(shouldShow(widgetCountGe1, { count: 1 })).toBe(true);
    expect(shouldShow(widgetCountGe1, { count: 0 })).toBe(false);
    expect(shouldShow(widgetCountGe1, { count: 5 })).toBe(true);
  });
  it('unrecognized expressions fail closed (return false) and warn', () => {
    // Suppress the console.warn for this test
    const spy = vi.spyOn(console, 'warn').mockImplementation(() => {});
    expect(shouldShow(widgetUnknown, { weird: { path: 5 } })).toBe(false);
    expect(spy).toHaveBeenCalled();
    spy.mockRestore();
  });
});
