/**
 * Class-Wide Misconception Report Component
 * Displays aggregated misconception patterns post-exercise
 */

import React from 'react';
import './ClassMisconceptionReport.css';

function ClassMisconceptionReport({ report, onClose, embedded = false }) {
  if (!report) {
    return null;
  }

  const emptyState = !report.mostCommonIssue || report.totalStudents === 0;

  const content = (
      <div className={embedded ? 'class-misconception-embedded' : 'class-misconception-modal'}>
        <div className="modal-header">
          <div>
            <h2 className="modal-title">Class-Wide Misconception Report</h2>
            <p className="modal-subtitle">{report.exerciseTitle || 'Exercise Analysis'}</p>
          </div>
          {!embedded && onClose && (
            <button className="btn-close" onClick={onClose}>&times;</button>
          )}
        </div>

        <div className="modal-content">
          {emptyState ? (
            <div className="empty-state">
              <p className="empty-message">
                {report.totalStudents === 0
                  ? '⏳ No submissions yet. Check back after students complete the exercise.'
                  : 'No misconception patterns detected.'}
              </p>
            </div>
          ) : (
            <>
              <div className="metrics-grid">
                <div className="metric-card">
                  <div className="metric-value">{report.totalStudents}</div>
                  <div className="metric-label">Total Students</div>
                </div>
                <div className="metric-card">
                  <div className="metric-value">{report.completedStudents || 0}</div>
                  <div className="metric-label">Completed</div>
                </div>
                <div className="metric-card">
                  <div className="metric-value">
                    {report.completedStudents && report.totalStudents
                      ? ((report.completedStudents / report.totalStudents) * 100).toFixed(1)
                      : '0'}%
                  </div>
                  <div className="metric-label">Completion Rate</div>
                </div>
              </div>

              <div className="issues-section">
                <h3 className="section-heading">Top Issues Identified</h3>

                {report.mostCommonIssue && (
                  <div className="issue-card primary">
                    <div className="issue-rank">1</div>
                    <div className="issue-content">
                      <h4 className="issue-name">{report.mostCommonIssue}</h4>
                      <div className="issue-stats">
                        <span className="stat">
                          <strong>{report.affectedCount}</strong> students ({report.affectedPercent.toFixed(1)}%)
                        </span>
                      </div>
                    </div>
                  </div>
                )}

                {report.secondIssue && (
                  <div className="issue-card secondary">
                    <div className="issue-rank">2</div>
                    <div className="issue-content">
                      <h4 className="issue-name">{report.secondIssue}</h4>
                      <div className="issue-stats">
                        <span className="stat">
                          <strong>{report.secondCount}</strong> students ({report.secondPercent?.toFixed(1) || '0'}%)
                        </span>
                      </div>
                    </div>
                  </div>
                )}
              </div>

              <div className="insights-section">
                <div className="insight-card">
                  <h4 className="insight-title">📊 Class Summary</h4>
                  <p className="insight-text">{report.classSummary}</p>
                </div>

                <div className="insight-card">
                  <h4 className="insight-title">🔎 Root Cause</h4>
                  <p className="insight-text">{report.rootCause}</p>
                </div>

                <div className="insight-card recommendation">
                  <h4 className="insight-title">💡 Recommended Action</h4>
                  <p className="insight-text">{report.recommendedAction}</p>
                </div>

                <div className="insight-card">
                  <h4 className="insight-title">✅ Before Advancing</h4>
                  <p className="insight-text">{report.beforeAdvancing}</p>
                </div>
              </div>
            </>
          )}
        </div>

        {!embedded && onClose && (
          <div className="modal-footer">
            <button className="btn-close-action" onClick={onClose}>
              Close Report
            </button>
          </div>
        )}
      </div>
  );

  if (embedded) {
    return content;
  }

  return (
    <div className="class-misconception-modal-overlay">
      {content}
    </div>
  );
}

export default ClassMisconceptionReport;
