/**
 * Integrity Monitoring Banner Component
 * Displays hardcoding and behavioral anomaly warnings
 */

import React from 'react';
import './IntegrityMonitoringBanner.css';

function IntegrityMonitoringBanner({ flaggedSubmissions }) {
  if (!flaggedSubmissions || flaggedSubmissions.length === 0) {
    return (
      <div className="integrity-banner safe">
        <div className="banner-icon">✓</div>
        <div className="banner-content">
          <h4 className="banner-title">Academic Integrity</h4>
          <p className="banner-message">No suspicious submissions detected this session.</p>
        </div>
      </div>
    );
  }

  const hardcodingFlags = flaggedSubmissions.filter(f => f.issueType === 'hardcoding_detected');
  const anomalyFlags = flaggedSubmissions.filter(f => f.issueType === 'behavioral_anomaly');

  return (
    <div className="integrity-banner warning">
      <div className="banner-icon">⚠️</div>
      <div className="banner-content">
        <h4 className="banner-title">Integrity Alerts</h4>
        <p className="banner-message">
          {flaggedSubmissions.length} submission(s) flagged for manual review
        </p>
        <div className="flagged-items">
          {hardcodingFlags.length > 0 && (
            <div className="flag-group">
              <span className="flag-type hardcoding">🔴 Hardcoding Detected</span>
              <span className="flag-count">{hardcodingFlags.length}</span>
            </div>
          )}
          {anomalyFlags.length > 0 && (
            <div className="flag-group">
              <span className="flag-type anomaly">🟠 Behavioral Anomaly</span>
              <span className="flag-count">{anomalyFlags.length}</span>
            </div>
          )}
        </div>
      </div>
      <div className="banner-action">
        <button className="btn-review-flags">Review Details</button>
      </div>
    </div>
  );
}

export default IntegrityMonitoringBanner;
