/**
 * Analytics Service
 * Axios wrapper for all analytics endpoints
 */

import api from '../services/api';

const analyticsService = {
  /**
   * Get micro-concept alerts for a section
   * @param {number} sectionId
   * @returns {Promise<Array>} Array of alerts with micro-concept feedback
   */
  getAlerts: (sectionId) => {
    return api.get(`/analytics/alerts/${sectionId}`);
  },

  /**
   * Get class-wide misconception report for an exercise
   * @param {number} exerciseId
   * @returns {Promise<Object>} Report with aggregated patterns
   */
  getClassMisconceptionReport: (exerciseId) => {
    return api.get(`/analytics/report/${exerciseId}`);
  },

  /**
   * Get longitudinal progress (mastery trajectory) for a student
   * @param {number} studentId
   * @param {number} conceptId - Optional concept filter
   * @param {number} sectionId - Optional section filter
   * @returns {Promise<Object>} Mastery timeline and progress metrics
   */
  getLongitudinalProgress: (studentId, conceptId, sectionId) => {
    let url = `/analytics/longitudinal/${studentId}`;
    if (conceptId) url += `/${conceptId}`;
    
    const params = {};
    if (sectionId) params.sectionId = sectionId;
    
    return api.get(url, { params });
  },

  /**
   * Get integrity monitoring flags (hardcoding + anomalies)
   * @param {number} exerciseId - Optional exercise filter
   * @returns {Promise<Object>} Flagged submissions with confidence scores
   */
  getIntegrityMonitoring: (exerciseId) => {
    const params = exerciseId ? { exerciseId } : {};
    return api.get('/analytics/integrity', { params });
  },

  /**
   * Get heatmap data for a section
   * @param {number} sectionId
   * @returns {Promise<Object>} Student x concept grid with CDS scores
   */
  getHeatmap: (sectionId) => {
    return api.get(`/analytics/heatmap/${sectionId}`);
  },

  /**
   * Get live CDS rankings for an exercise
   * @param {number} exerciseId
   * @returns {Promise<Object>} Live peer ranking with preliminary badge
   */
  getLiveCDS: (exerciseId) => {
    return api.get(`/analytics/live-cds/${exerciseId}`);
  }
};

export default analyticsService;
