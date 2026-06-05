// frontend/src/state/useStateDerivation.js
import { STATE_COPY } from './stateCopy.js';

/**
 * Pure derivation. Spec §8.
 *
 * Triggers:
 *   NoData: 0 submissions OR section < 24h old
 *   LowConfidence: 1-2 submissions/student OR section < 14d old
 *   Healthy: >= 3 submissions/student AND section >= 14d
 *
 * @param {{ submissionsPerStudent: number, sectionAgeDays: number, students: number }} input
 * @returns {{ state: 'NoData'|'LowConfidence'|'Healthy', progressText?: string }}
 */
export function deriveState({ submissionsPerStudent = 0, sectionAgeDays = 0, students = 0 } = {}) {
  let state;
  if (submissionsPerStudent <= 0 || sectionAgeDays < 1) {
    state = 'NoData';
  } else if (submissionsPerStudent < 3 || sectionAgeDays < 14) {
    state = 'LowConfidence';
  } else {
    state = 'Healthy';
  }

  const result = { state };
  if (state === 'LowConfidence') {
    const nextTarget = submissionsPerStudent + 1;
    result.progressText = `${nextTarget} of ${students} submissions to full confidence`;
  }
  return result;
}

/** Look up role-specific copy for a state. */
export function copyFor(role, state) {
  return STATE_COPY[state]?.[role] ?? null;
}
