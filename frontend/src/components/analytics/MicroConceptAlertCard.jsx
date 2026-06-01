/**
 * Micro-Concept Alert Card Component
 * Displays per-student feedback on structural mistakes
 * Shows microConceptDifficulty, evidence, and instructor recommendations
 */

import React from 'react';
import './MicroConceptAlertCard.css';

function MicroConceptAlertCard({ alert, onDismiss }) {
  const getDifficultyColor = (classification) => {
    switch (classification) {
      case 'High':
        return '#ef4444';
      case 'Moderate':
        return '#f59e0b';
      case 'Low':
        return '#10b981';
      default:
        return '#6b7280';
    }
  };

  const getClassificationBg = (classification) => {
    switch (classification) {
      case 'High':
        return '#fee2e2';
      case 'Moderate':
        return '#fef3c7';
      case 'Low':
        return '#ecfdf5';
      default:
        return '#f3f4f6';
    }
  };

  return (
    <div className="micro-concept-alert-card" style={{ borderLeftColor: getDifficultyColor(alert.classification) }}>
      <div className="card-header">
        <div className="student-info">
          <h4 className="student-name">{alert.student_name}</h4>
          <p className="exercise-title">{alert.exercise_title}</p>
        </div>
        <div className="classification-badge" style={{ backgroundColor: getClassificationBg(alert.classification) }}>
          <span className="badge-text" style={{ color: getDifficultyColor(alert.classification) }}>
            {alert.classification} CDS ({(alert.cds_score * 100).toFixed(1)}%)
          </span>
        </div>
      </div>

      <div className="card-content">
        {alert.microConceptDifficulty && (
          <div className="concept-section">
            <h5 className="section-title">📚 Specific Issue</h5>
            <p className="concept-text">{alert.microConceptDifficulty}</p>
          </div>
        )}

        {alert.evidence && (
          <div className="evidence-section">
            <h5 className="section-title">🔍 Evidence</h5>
            <p className="evidence-text">{alert.evidence}</p>
          </div>
        )}

        {alert.instructorNote && (
          <div className="instructor-section">
            <h5 className="section-title">💡 Teaching Approach</h5>
            <p className="instructor-text">{alert.instructorNote}</p>
          </div>
        )}

        {!alert.microConceptDifficulty && !alert.evidence && (
          <div className="no-detail-section">
            <p className="no-detail-text">
              Student struggled with this exercise. Click "Review" to see submission details.
            </p>
          </div>
        )}
      </div>

      <div className="card-footer">
        <button className="btn-review" onClick={() => {}}>
          Review Submission
        </button>
        {onDismiss && (
          <button className="btn-dismiss" onClick={() => onDismiss(alert.id)}>
            Dismiss
          </button>
        )}
      </div>
    </div>
  );
}

export default MicroConceptAlertCard;
