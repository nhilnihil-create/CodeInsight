/**
 * Longitudinal Progress Chart Component
 * Displays mastery trajectory over time
 */

import React from 'react';
import './LongitudinalProgressChart.css';

function LongitudinalProgressChart({ data, studentName }) {
  if (!data || !data.conceptTimeline || data.conceptTimeline.length === 0) {
    return (
      <div className="longitudinal-container">
        <div className="empty-state">
          <p>No progress data available yet.</p>
        </div>
      </div>
    );
  }

  const getClassificationColor = (classification) => {
    switch (classification) {
      case 'Low':
        return '#10b981';
      case 'Moderate':
        return '#f59e0b';
      case 'High':
        return '#ef4444';
      default:
        return '#6b7280';
    }
  };

  const getClassificationBgColor = (classification) => {
    switch (classification) {
      case 'Low':
        return '#ecfdf5';
      case 'Moderate':
        return '#fffbeb';
      case 'High':
        return '#fee2e2';
      default:
        return '#f3f4f6';
    }
  };

  const getResolutionIcon = (resolved) => {
    return resolved ? '✓' : '◯';
  };

  const { conceptTimeline, overallProgress } = data;

  return (
    <div className="longitudinal-container">
      <div className="chart-header">
        <h3 className="chart-title">📈 Mastery Trajectory</h3>
        {studentName && <p className="student-label">{studentName}</p>}
      </div>

      {overallProgress && (
        <div className="progress-summary">
          <div className="summary-stat">
            <div className="stat-label">Concepts Resolved</div>
            <div className="stat-value">
              {overallProgress.conceptsResolved}/{overallProgress.conceptsAttempted}
            </div>
          </div>
          <div className="summary-stat">
            <div className="stat-label">Resolution Rate</div>
            <div className="stat-value">
              {((overallProgress.resolutionRate || 0) * 100).toFixed(0)}%
            </div>
          </div>
          <div className="summary-stat">
            <div className="stat-label">Trend</div>
            <div className={`stat-trend ${(overallProgress.masteryTrend || 'stable').toLowerCase()}`}>
              {overallProgress.masteryTrend === 'improving' && '📈 Improving'}
              {overallProgress.masteryTrend === 'declining' && '📉 Declining'}
              {overallProgress.masteryTrend === 'stable' && '➡️ Stable'}
            </div>
          </div>
        </div>
      )}

      <div className="timeline">
        {conceptTimeline.map((entry, index) => (
          <div key={index} className="timeline-entry">
            <div className="timeline-marker">
              <div
                className="marker-circle"
                style={{
                  backgroundColor: getClassificationColor(entry.classification),
                  borderColor: getClassificationColor(entry.classification)
                }}
              >
                <span className="marker-icon">{getResolutionIcon(entry.resolved)}</span>
              </div>
              {index < conceptTimeline.length - 1 && (
                <div className="timeline-line"></div>
              )}
            </div>

            <div className="timeline-content">
              <div className="entry-date">{new Date(entry.date).toLocaleDateString()}</div>
              
              <div className="concept-info">
                <div className="concept-header">
                  <h4 className="concept-name">{entry.concept}</h4>
                  <span
                    className="mastery-badge"
                    style={{
                      backgroundColor: getClassificationBgColor(entry.classification),
                      color: getClassificationColor(entry.classification)
                    }}
                  >
                    {entry.classification} ({(entry.masteryScore * 100).toFixed(0)}%)
                  </span>
                </div>

                <p className="exercise-title">{entry.exerciseTitle}</p>

                {entry.microConceptsAttempted && entry.microConceptsAttempted.length > 0 && (
                  <div className="micro-concepts">
                    <div className="micro-concepts-label">Sub-concepts:</div>
                    <div className="concepts-list">
                      {entry.microConceptsAttempted.map((concept, idx) => {
                        const isResolved = entry.microConceptsResolved?.includes(concept);
                        return (
                          <span
                            key={idx}
                            className={`concept-tag ${isResolved ? 'resolved' : 'unresolved'}`}
                          >
                            {isResolved ? '✓' : '○'} {concept}
                          </span>
                        );
                      })}
                    </div>
                  </div>
                )}
              </div>
            </div>
          </div>
        ))}
      </div>

      <div className="chart-legend">
        <div className="legend-item">
          <span className="legend-marker resolved">✓</span>
          <span>Mastered (Low CDS)</span>
        </div>
        <div className="legend-item">
          <span className="legend-marker moderate">◯</span>
          <span>Moderate Difficulty</span>
        </div>
        <div className="legend-item">
          <span className="legend-marker struggling">◯</span>
          <span>Struggling (High CDS)</span>
        </div>
      </div>
    </div>
  );
}

export default LongitudinalProgressChart;
