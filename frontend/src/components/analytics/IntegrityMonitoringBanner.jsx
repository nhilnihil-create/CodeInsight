/**
 * Integrity Monitoring Banner — sits at the top of the instructor
 * Dashboard and the Integrity page. Two states:
 *   - safe    (no flags):  "All clear" message, shield-check icon
 *   - warning (with flags):  flag chips + a "Review details" CTA
 *
 * Theme-aware: all colors come from shadcn semantic tokens defined in
 * src/index.css (see IntegrityMonitoringBanner.css).
 */

import { Link } from 'react-router-dom';
import { ShieldCheck, ShieldAlert, ArrowRight } from 'lucide-react';
import './IntegrityMonitoringBanner.css';

function IntegrityMonitoringBanner({ flaggedSubmissions }) {
  if (!flaggedSubmissions || flaggedSubmissions.length === 0) {
    return (
      <div className="integrity-banner safe">
        <div className="banner-icon">
          <ShieldCheck size={18} strokeWidth={2.25} />
        </div>
        <div className="banner-content">
          <h4 className="banner-title">Academic integrity</h4>
          <p className="banner-message">
            No suspicious submissions detected in this window.
          </p>
        </div>
        <div className="banner-action">
          <Link
            to="/instructor/integrity"
            className="btn-review-flags"
            aria-label="Open the full integrity review page"
          >
            Open review
            <ArrowRight size={14} strokeWidth={2.5} />
          </Link>
        </div>
      </div>
    );
  }

  const hardcodingFlags = flaggedSubmissions.filter(
    (f) => f.issueType === 'hardcoding_detected'
  );
  const anomalyFlags = flaggedSubmissions.filter(
    (f) => f.issueType === 'behavioral_anomaly'
  );

  return (
    <div className="integrity-banner warning">
      <div className="banner-icon">
        <ShieldAlert size={18} strokeWidth={2.25} />
      </div>
      <div className="banner-content">
        <h4 className="banner-title">Integrity alerts</h4>
        <p className="banner-message">
          {flaggedSubmissions.length} submission
          {flaggedSubmissions.length === 1 ? '' : 's'} flagged for manual review.
        </p>
        {(hardcodingFlags.length > 0 || anomalyFlags.length > 0) && (
          <div className="flagged-items">
            {hardcodingFlags.length > 0 && (
              <span className="flag-group">
                <span className="flag-type hardcoding">
                  <span className="flag-dot" aria-hidden="true" />
                  Hardcoding
                </span>
                <span className="flag-count">{hardcodingFlags.length}</span>
              </span>
            )}
            {anomalyFlags.length > 0 && (
              <span className="flag-group">
                <span className="flag-type anomaly">
                  <span className="flag-dot" aria-hidden="true" />
                  Behavioral anomaly
                </span>
                <span className="flag-count">{anomalyFlags.length}</span>
              </span>
            )}
          </div>
        )}
      </div>
      <div className="banner-action">
        <Link
          to="/instructor/integrity"
          className="btn-review-flags"
          aria-label="Open the full integrity review page"
        >
          Review details
          <ArrowRight size={14} strokeWidth={2.5} />
        </Link>
      </div>
    </div>
  );
}

export default IntegrityMonitoringBanner;
