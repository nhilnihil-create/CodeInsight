import React, { useState } from 'react';
import api from '../../services/api';
import './MicroConceptAlertCard.css';

function MicroConceptAlertCard({ alert, onDismiss }) {
  const [showSubmissionModal, setShowSubmissionModal] = useState(false);
  const [submissionCode, setSubmissionCode] = useState('');
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState('');

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

  const fetchSubmission = async () => {
    setLoading(true);
    setError('');
    try {
      // Log the alert object for debugging
      console.log('Alert object received:', alert);

      // Check if alert has the required IDs
      if (!alert.student_id || !alert.exercise_id) {
        console.error('Missing required IDs in alert:', {
          student_id: alert.student_id,
          exercise_id: alert.exercise_id,
          alert
        });
        setError('Missing student or exercise ID in alert data');
        return;
      }

      console.log(`Fetching submission for student ${alert.student_id}, exercise ${alert.exercise_id}`);
      const response = await api.get(`/api/submissions/${alert.student_id}/${alert.exercise_id}`);
      console.log('Submissions API response:', response.data);

      // Handle response: could be array of submissions, single submission object, or undefined
      let submissions = [];

      // Safely check if response.data exists and is not null
      if (response.data !== undefined && response.data !== null) {
        if (Array.isArray(response.data)) {
          submissions = response.data;
        } else if (typeof response.data === 'object') {
          // If it's a single submission object
          submissions = [response.data];
        }
      }

      // Filter out any null, undefined, or non-object submissions
      submissions = submissions.filter(sub =>
        sub !== null &&
        sub !== undefined &&
        typeof sub === 'object'
      );

      console.log('Processed submissions array:', submissions);

      // If we have submissions, sort and get the latest
      if (submissions.length > 0) {
        try {
          submissions.sort((a, b) => {
            // Safely handle created_at dates
            const dateA = a ? new Date(a.created_at) : new Date(0);
            const dateB = b ? new Date(b.created_at) : new Date(0);
            return dateB - dateA;
          });
          const latestSubmission = submissions[0];
          console.log('Latest submission object:', latestSubmission);

          // Safely access the code property
          if (latestSubmission && typeof latestSubmission === 'object') {
            const code = latestSubmission.code;
            console.log('Submission code:', code);
            setSubmissionCode(code !== undefined && code !== null ? code : 'No code available');
          } else {
            console.error('Latest submission is not a valid object:', latestSubmission);
            setSubmissionCode('Invalid submission data format');
          }
        } catch (sortError) {
          console.error('Error sorting submissions:', sortError);
          // Fallback: just take the first submission if sorting fails
          const latestSubmission = submissions[0];
          if (latestSubmission && typeof latestSubmission === 'object') {
            const code = latestSubmission.code;
            console.log('Submission code (fallback):', code);
            setSubmissionCode(code !== undefined && code !== null ? code : 'No code available');
          } else {
            setSubmissionCode('Invalid submission data');
          }
        }
      } else {
        setSubmissionCode('No submissions found for this student and exercise');
      }
    } catch (err) {
      console.error('Error fetching submission:', err);
      setError('Failed to load submission code: ' + (err.message || 'Unknown error'));
    } finally {
      setLoading(false);
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
        <button
          className="btn-review"
          onClick={() => {
            setShowSubmissionModal(true);
            fetchSubmission();
          }}
          disabled={loading}
        >
          {loading ? 'Loading...' : 'Review Submission'}
        </button>
        {onDismiss && (
          <button className="btn-dismiss" onClick={() => onDismiss(alert.id)}>
            Dismiss
          </button>
        )}
      </div>

      {/* Submission Modal */}
      {showSubmissionModal && (
        <div className="modal-backdrop" onClick={() => setShowSubmissionModal(false)}>
          <div className="modal-content">
            <div className="modal-header">
              <h3>Submission Review: {alert.student_name}</h3>
              <p style={{ margin: '4px 0 0', color: '#8884a0', fontSize: '14px' }}>
                {alert.exercise_title}
              </p>
              <button className="modal-close" onClick={() => setShowSubmissionModal(false)}>
                ×
              </button>
            </div>
            <div className="modal-body">
              {loading ? (
                <p>Loading submission...</p>
              ) : error ? (
                <p className="error">{error}</p>
              ) : (
                <div className="code-container">
                  <pre><code>{submissionCode}</code></pre>
                </div>
              )}
            </div>
          </div>
        </div>
      )}
    </div>
  );
}

export default MicroConceptAlertCard;