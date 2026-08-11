/**
 * Analytics Service
 * Axios wrapper for all analytics endpoints
 */

import api from '../services/api';

const analyticsService = {
  /**
   * Get micro-concept alerts for a section
   * @param {number} sectionId
   * @param {Object} filters - Optional filters (classification, concept)
   * @returns {Promise<Object>} Array of alerts
   */
  getAlerts: (sectionId, filters = {}) => {
    const params = new URLSearchParams(filters);
    return api.get(`/api/analytics/sections/${sectionId}/micro-concept-alerts?${params.toString()}`);
  },

  /**
   * Get class-wide misconception report for an exercise in a section
   * @param {number} sectionId
   * @param {number} exerciseId
   * @returns {Promise<Object>} Report with aggregated patterns
   */
  /**
   * Automated CDS check + class misconception report for one exercise.
   * @param {boolean} refreshCds - When true (default), recomputes batch CDS before the report.
   */
  getClassMisconceptionReport: (sectionId, exerciseId, { refreshCds = true } = {}) => {
    return api.get(`/api/analytics/sections/${sectionId}/class-insights/${exerciseId}`, {
      params: { refresh: refreshCds ? 'true' : 'false' }
    });
  },

  /**
   * Get longitudinal progress (mastery trajectory) for a student
   * @param {number} studentId
   * @param {number} conceptId - Optional concept filter
   * @param {number} sectionId - Optional section filter
   * @returns {Promise<Object>} Mastery timeline and progress metrics
   */
  getLongitudinalProgress: (studentId, conceptId, sectionId) => {
    let url = `/api/analytics/longitudinal/${studentId}`;
    if (conceptId) {
      url += `/${conceptId}`;
    }
    
    if (sectionId) {
      url += `?sectionId=${sectionId}`;
    }

    return api.get(url);
  },

  /**
   * Get class-wide longitudinal progress (every student's CDS timeline)
   * for a section. The frontend aggregates this into a class-average line
   * per concept.
   * @param {number} sectionId
   * @returns {Promise<{sectionId:number, students:Array<{studentId, studentName, progression:Array<{cds, classification, computed_at, exercise_title, exercise_id, concept_id, concept_name}>, masteryVelocity}>}>}
   */
  getSectionLongitudinal: (sectionId) => {
    return api.get(`/api/analytics/sections/${sectionId}/longitudinal`);
  },

  /**
   * Get integrity flags for a section or exercise
   * @param {number} sectionId - Optional section ID
   * @param {number} exerciseId - Optional exercise ID
   * @returns {Promise<Object>} Object containing flags array and pagination
   */
  getIntegrityMonitoring: (sectionId, exerciseId) => {
    let url = '/api/analytics/integrity-flags';
    if (sectionId && exerciseId) {
      url = `/api/analytics/sections/${sectionId}/integrity-flags/${exerciseId}`;
    } else if (sectionId) {
      url = `/api/analytics/sections/${sectionId}/integrity-flags`;
    } else if (exerciseId) {
      url = `/api/analytics/integrity-flags/exercise/${exerciseId}`;
    }
    return api.get(url);
  },

  /**
   * Get heatmap data for a section
   * @param {number} sectionId
   * @returns {Promise<Object>} Student x concept grid with CDS scores
   */
  getHeatmap: (sectionId) => {
    return api.get(`/api/analytics/heatmap/${sectionId}`);
  },

  /**
   * Get live CDS rankings for an exercise (Instructor View)
   * @param {number} exerciseId
   * @returns {Promise<Object>} Detailed live ranking with class metrics
   */
  getLiveCDS: (exerciseId) => {
    return api.get(`/api/analytics/live-cds/${exerciseId}`);
  },

  /**
   * Get live peer rankings for an exercise (Instructor View)
   * @param {number} exerciseId
   * @returns {Promise<Object>} Peer ranking with student names
   */
  getLivePeerRanking: (exerciseId) => {
    return api.get(`/api/analytics/live/${exerciseId}`);
  },
  
  /**
   * Mark an integrity flag as reviewed
   * @param {number} flagId
   * @param {Object} data - { status, instructorNote }
   */
  reviewIntegrityFlag: (flagId, data) => {
    return api.put(`/api/analytics/integrity-flags/${flagId}/review`, data);
  },

  /**
   * Get the live intervention queue for a section (per-student average CDS,
   * High risk only — avg CDS > 0.60, the same signal as the dashboard banner).
   * Supports sectionId="all" for the instructor's combined sections.
   * @param {number|string} sectionId
   * @returns {Promise<Object>} { sectionId, totalStudents, atRisk, tierDistribution, insight }
   */
  getInterventionQueue: (sectionId) => {
    return api.get(`/api/analytics/alerts/${sectionId}`);
  },
};

export default analyticsService;
