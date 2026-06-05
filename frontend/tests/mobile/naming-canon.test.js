// frontend/tests/mobile/naming-canon.test.js
// Spec §9, acceptance §13.16. Every component filename in src/components/mobile/
// must match a canonical name from the spec.

import { describe, it, expect } from 'vitest';
import { readdirSync } from 'fs';
import { join } from 'path';

const CANON = new Set([
  'AppBar', 'BottomNav',
  'InstructorPriorityInsight', 'AtRiskQueue', 'AtRiskRoster', 'InterventionQueue',
  'TopStrugglingConcepts', 'ClassProfileRadar', 'WeeklyTeachingInsight',
  'IntegrityFlagCount', 'IntegrityFlagList', 'IntegrityFlagHistory', 'IntegrityDrillNotice',
  'StudentTodayFocus', 'WeakestConceptBar', 'ConceptMasteryBarSet', 'ActionStack', 'WeeklyProgress',
  'ExerciseCardList', 'CodePreviewSurface', 'TestResultList', 'OpenFullEditorHint',
  'SnapshotMetrics', 'EvaluationProgress', 'Iso25010Instrument', 'AuditLog',
  'DesktopOnlyNotice', 'SectionList',
  'RiskBadge', 'CDSPillDelta',
  'primitives',  // dir
  '.', '..',
]);

describe('mobile component naming canon (spec §9, acceptance §13.16)', () => {
  const dir = 'src/components/mobile';
  const files = readdirSync(dir);
  it('every .jsx file under src/components/mobile/ is a canonical name', () => {
    const offenders = files
      .filter((f) => f.endsWith('.jsx') && !f.endsWith('.test.jsx'))
      .map((f) => f.replace('.jsx', ''))
      .filter((n) => !CANON.has(n));
    expect(offenders).toEqual([]);
  });
});
