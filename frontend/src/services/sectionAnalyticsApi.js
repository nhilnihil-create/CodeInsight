import api from './api';

/**
 * Section-scoped analytics API client
 * All endpoints return section-filtered data
 */

export const sectionAnalyticsApi = {
  // Micro-Concept Alerts
  getMicroConceptAlerts: async (sectionId, options = {}) => {
    const { limit = 50, offset = 0 } = options;
    return api.get(`/api/analytics/sections/${sectionId}/micro-concept-alerts`, {
      params: { limit, offset }
    });
  },

  markMicroConceptAlertReviewed: async (alertId) => {
    return api.put(`/api/analytics/micro-concept-alerts/${alertId}/mark-reviewed`);
  },

  // Class-Wide Misconception Reports
  getClassInsights: async (sectionId) => {
    return api.get(`/api/analytics/sections/${sectionId}/class-insights`);
  },

  getClassInsightsByExercise: async (sectionId, exerciseId) => {
    return api.get(`/api/analytics/sections/${sectionId}/class-insights/${exerciseId}`);
  },

  // Longitudinal Progress Tracking
  getSectionLongitudinal: async (sectionId) => {
    return api.get(`/api/analytics/sections/${sectionId}/longitudinal`);
  },

  // Behavioral Academic Integrity Flags
  getIntegrityFlags: async (sectionId, options = {}) => {
    const { limit = 50, offset = 0 } = options;
    return api.get(`/api/analytics/sections/${sectionId}/integrity-flags`, {
      params: { limit, offset }
    });
  },

  getIntegrityFlagsByExercise: async (sectionId, exerciseId) => {
    return api.get(`/api/analytics/sections/${sectionId}/integrity-flags/${exerciseId}`);
  },

  markIntegrityFlagReviewed: async (flagId, instructorNote = '') => {
    return api.put(`/api/analytics/integrity-flags/${flagId}/mark-reviewed`, {
      instructor_note: instructorNote
    });
  }
};

export default sectionAnalyticsApi;
