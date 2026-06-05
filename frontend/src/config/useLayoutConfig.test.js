// frontend/src/config/useLayoutConfig.test.js
import { describe, it, expect } from 'vitest';
import { getConfig } from './useLayoutConfig.js';

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

  it('every widget ref has the canonical widget name (no synonyms)', () => {
    const all = [cfg.screens['/instructor/command']];
    for (const s of all) {
      for (const w of [s.primary, ...s.secondary, ...s.tertiary]) {
        // canonical names from spec §9
        expect(['InstructorPriorityInsight', 'AtRiskQueue', 'AtRiskRoster',
          'InterventionQueue', 'TopStrugglingConcepts', 'ClassProfileRadar',
          'WeeklyTeachingInsight', 'IntegrityFlagCount', 'IntegrityFlagList',
          'IntegrityFlagHistory', 'IntegrityDrillNotice', 'SectionList'])
          .toContain(w.widget);
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
