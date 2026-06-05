import React, { useState, useEffect, useMemo } from 'react';
import sectionAnalyticsApi from '../../services/sectionAnalyticsApi';
import IntegrityFlagBadge from '../IntegrityFlagBadge';
import './IntegrityFlagDropdown.css';

const FLAG_TYPE_LABELS = {
  HARDCODING: 'Hardcoding',
  BLANK_TEMPLATE: 'Blank / template only',
  BEHAVIORAL_ANOMALY: 'Behavioral anomaly',
  CODE_GROWTH_ANOMALY: 'Code growth anomaly',
  code_paste_detected: 'Code paste detected',
  code_growth_anomaly: 'Code growth anomaly',
  retry_storm: 'Retry storm',
  hardcoded_output: 'Hardcoded output',
  behavioral_anomaly: 'Behavioral anomaly'
};

function formatEvidence(evidence) {
  if (!evidence) return null;
  if (typeof evidence === 'string') return evidence;
  if (typeof evidence === 'object') return evidence;
  return String(evidence);
}

function IntegrityFlagDropdown({ sectionId, exerciseId, isOpen }) {
  const [flags, setFlags] = useState([]);
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState(null);
  const [expandedStudents, setExpandedStudents] = useState(new Set());

  useEffect(() => {
    if (isOpen && sectionId && exerciseId) {
      fetchIntegrityFlags();
    }
  }, [isOpen, sectionId, exerciseId]);

  const studentsWithFlags = useMemo(() => {
    const byStudent = {};
    for (const flag of flags) {
      const key = flag.student_id;
      if (!byStudent[key]) {
        byStudent[key] = {
          studentId: key,
          studentName: flag.student_name || 'Unknown student',
          flags: []
        };
      }
      byStudent[key].flags.push(flag);
    }
    return Object.values(byStudent).sort((a, b) =>
      a.studentName.localeCompare(b.studentName)
    );
  }, [flags]);

  const fetchIntegrityFlags = async () => {
    try {
      setLoading(true);
      setError(null);
      const res = await sectionAnalyticsApi.getIntegrityFlagsByExercise(sectionId, exerciseId);
      setFlags(Array.isArray(res.data) ? res.data : []);
    } catch (err) {
      console.error('Error fetching integrity flags:', err);
      setError('Failed to load integrity flags');
      setFlags([]);
    } finally {
      setLoading(false);
    }
  };

  const toggleStudent = (studentId) => {
    setExpandedStudents((prev) => {
      const next = new Set(prev);
      if (next.has(studentId)) next.delete(studentId);
      else next.add(studentId);
      return next;
    });
  };

  const markFlagReviewed = async (flagId, e) => {
    e.stopPropagation();
    try {
      await sectionAnalyticsApi.markIntegrityFlagReviewed(flagId);
      setFlags((prev) =>
        prev.map((f) => (f.id === flagId ? { ...f, status: 'reviewed' } : f))
      );
    } catch (err) {
      console.error('Error marking flag reviewed:', err);
    }
  };

  if (!isOpen) return null;

  return (
    <div className="integrity-flag-dropdown">
      <div className="integrity-flag-dropdown__header">
        <span className="integrity-flag-dropdown__title">Academic integrity flags</span>
        <span className="integrity-flag-dropdown__count">
          {studentsWithFlags.length} student{studentsWithFlags.length !== 1 ? 's' : ''} ·{' '}
          {flags.length} flag{flags.length !== 1 ? 's' : ''}
        </span>
      </div>

      {loading && <div className="integrity-flag-dropdown__message">Loading flags...</div>}
      {error && <div className="integrity-flag-dropdown__message is-error">{error}</div>}

      {!loading && !error && studentsWithFlags.length === 0 && (
        <div className="integrity-flag-dropdown__message">
          No integrity flags detected for this exercise.
        </div>
      )}

      {!loading && !error && studentsWithFlags.length > 0 && (
        <div className="integrity-flag-dropdown__list">
          {studentsWithFlags.map((student) => {
            const isExpanded = expandedStudents.has(student.studentId);
            const openFlags = student.flags.filter((f) => f.status !== 'reviewed').length;

            return (
              <div key={student.studentId} className="integrity-flag-dropdown__student">
                <button
                  type="button"
                  className={`integrity-flag-dropdown__student-toggle${isExpanded ? ' is-open' : ''}`}
                  onClick={() => toggleStudent(student.studentId)}
                  aria-expanded={isExpanded}
                >
                  <span className="integrity-flag-dropdown__chevron" aria-hidden="true">
                    ▼
                  </span>
                  <span className="integrity-flag-dropdown__student-name">{student.studentName}</span>
                  <span className="integrity-flag-dropdown__student-meta">
                    {student.flags.length} flag{student.flags.length !== 1 ? 's' : ''}
                    {openFlags > 0 ? ` · ${openFlags} open` : ''}
                  </span>
                  <span className="integrity-flag-dropdown__badges">
                    {[...new Set(student.flags.map((f) => f.flag_type))].map((type) => (
                      <IntegrityFlagBadge key={type} flagType={type} />
                    ))}
                  </span>
                </button>

                {isExpanded && (
                  <div className="integrity-flag-dropdown__student-panel">
                    {student.flags.map((flag) => {
                      const evidence = formatEvidence(flag.evidence);
                      const label =
                        FLAG_TYPE_LABELS[flag.flag_type] || flag.flag_type?.replace(/_/g, ' ');

                      return (
                        <div key={flag.id} className="integrity-flag-dropdown__flag-row">
                          <div className="integrity-flag-dropdown__flag-top">
                            <IntegrityFlagBadge flagType={flag.flag_type} />
                            <span className="integrity-flag-dropdown__flag-label">{label}</span>
                            <span className={`integrity-flag-dropdown__severity severity-${(flag.severity || 'medium').toLowerCase()}`}>
                              {(flag.severity || 'medium').toUpperCase()}
                            </span>
                            {flag.status === 'reviewed' && (
                              <span className="integrity-flag-dropdown__reviewed">Reviewed</span>
                            )}
                            {flag.status !== 'reviewed' && (
                              <button
                                type="button"
                                className="integrity-flag-dropdown__review-btn"
                                onClick={(e) => markFlagReviewed(flag.id, e)}
                              >
                                Mark reviewed
                              </button>
                            )}
                          </div>
                          <p className="integrity-flag-dropdown__evidence">
                            {typeof evidence === 'string'
                              ? evidence
                              : evidence?.message || JSON.stringify(evidence)}
                          </p>
                          {flag.created_at && (
                            <div className="integrity-flag-dropdown__when">
                              Detected {new Date(flag.created_at).toLocaleString()}
                            </div>
                          )}
                        </div>
                      );
                    })}
                  </div>
                )}
              </div>
            );
          })}
        </div>
      )}
    </div>
  );
}

export default IntegrityFlagDropdown;
