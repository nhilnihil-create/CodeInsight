import React, { useState, useEffect } from 'react';
import sectionAnalyticsApi from '../../services/sectionAnalyticsApi';

function IntegrityFlagDropdown({ sectionId, exerciseId, isOpen, onToggle }) {
  const [flags, setFlags] = useState([]);
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState(null);
  const [expandedFlags, setExpandedFlags] = useState(new Set());

  useEffect(() => {
    if (isOpen && sectionId && exerciseId) {
      fetchIntegrityFlags();
    }
  }, [isOpen, sectionId, exerciseId]);

  const fetchIntegrityFlags = async () => {
    try {
      setLoading(true);
      setError(null);
      const res = await sectionAnalyticsApi.getIntegrityFlagsByExercise(sectionId, exerciseId);
      setFlags(res.data || []);
    } catch (err) {
      console.error('Error fetching integrity flags:', err);
      setError('Failed to load integrity flags');
      setFlags([]);
    } finally {
      setLoading(false);
    }
  };

  const toggleFlagDetails = (flagId) => {
    setExpandedFlags(prev => {
      const newSet = new Set(prev);
      if (newSet.has(flagId)) {
        newSet.delete(flagId);
      } else {
        newSet.add(flagId);
      }
      return newSet;
    });
  };

  const markFlagReviewed = async (flagId, e) => {
    e.stopPropagation();
    try {
      await sectionAnalyticsApi.markIntegrityFlagReviewed(flagId);
      setFlags(prev => prev.map(f => f.id === flagId ? { ...f, status: 'reviewed' } : f));
    } catch (err) {
      console.error('Error marking flag reviewed:', err);
    }
  };

  const getSeverityColor = (severity) => {
    switch (severity?.toLowerCase()) {
      case 'high':
        return { bg: 'rgba(248,113,113,0.1)', color: '#f87171', border: '1px solid rgba(248,113,113,0.3)' };
      case 'medium':
        return { bg: 'rgba(251,191,36,0.1)', color: '#fbbf24', border: '1px solid rgba(251,191,36,0.3)' };
      case 'low':
      default:
        return { bg: 'rgba(74,222,128,0.1)', color: '#4ade80', border: '1px solid rgba(74,222,128,0.3)' };
    }
  };

  const getFlagTypeLabel = (flagType) => {
    const labels = {
      'code_paste': '📋 Code Paste Detected',
      'code_growth_anomaly': '📈 Code Growth Anomaly',
      'retry_storm': '🔄 Retry Storm',
      'time_anomaly': '⏱️ Time Anomaly',
      'hardcoded_output': '💾 Hardcoded Output',
      'behavioral_anomaly': '👁️ Behavioral Anomaly'
    };
    return labels[flagType] || flagType;
  };

  if (!isOpen) {
    return null;
  }

  return (
    <div style={{
      background: '#131d30',
      borderTop: '1px solid #2e2e4a',
      padding: '16px',
      margin: 0
    }}>
      <div style={{
        display: 'flex',
        justifyContent: 'space-between',
        alignItems: 'center',
        marginBottom: '12px'
      }}>
        <div style={{
          fontSize: '12px',
          fontWeight: 700,
          color: '#e8e6f0',
          textTransform: 'uppercase',
          letterSpacing: '0.8px'
        }}>
          Academic Integrity Flags
        </div>
        <div style={{
          fontSize: '10px',
          color: '#8884a0',
          background: 'rgba(74,74,106,0.3)',
          padding: '2px 8px',
          borderRadius: '4px'
        }}>
          {flags.length} flag{flags.length !== 1 ? 's' : ''}
        </div>
      </div>

      {loading && (
        <div style={{
          fontSize: '11px',
          color: '#8884a0',
          textAlign: 'center',
          padding: '12px'
        }}>
          Loading flags...
        </div>
      )}

      {error && (
        <div style={{
          fontSize: '11px',
          color: '#f87171',
          textAlign: 'center',
          padding: '12px'
        }}>
          {error}
        </div>
      )}

      {!loading && !error && flags.length === 0 && (
        <div style={{
          fontSize: '11px',
          color: '#8884a0',
          textAlign: 'center',
          padding: '12px'
        }}>
          ✓ No integrity flags detected for this exercise
        </div>
      )}

      {!loading && !error && flags.length > 0 && (
        <div style={{
          display: 'flex',
          flexDirection: 'column',
          gap: '8px'
        }}>
          {flags.map(flag => {
            const isExpanded = expandedFlags.has(flag.id);
            const severityStyle = getSeverityColor(flag.severity);
            const isReviewed = flag.status === 'reviewed';

            return (
              <div
                key={flag.id}
                style={{
                  background: '#1a1a2e',
                  border: severityStyle.border,
                  borderRadius: '6px',
                  padding: '10px 12px',
                  cursor: 'pointer',
                  transition: 'background-color 0.2s'
                }}
                onClick={() => toggleFlagDetails(flag.id)}
              >
                <div style={{
                  display: 'flex',
                  justifyContent: 'space-between',
                  alignItems: 'flex-start',
                  gap: '8px'
                }}>
                  <div style={{ flex: 1 }}>
                    <div style={{
                      display: 'flex',
                      alignItems: 'center',
                      gap: '8px',
                      marginBottom: '4px'
                    }}>
                      <span style={{
                        fontSize: '11px',
                        fontWeight: 700,
                        color: severityStyle.color,
                        background: severityStyle.bg,
                        padding: '2px 6px',
                        borderRadius: '4px'
                      }}>
                        {flag.severity?.toUpperCase() || 'MEDIUM'}
                      </span>
                      <span style={{
                        fontSize: '11px',
                        fontWeight: 600,
                        color: '#e8e6f0'
                      }}>
                        {getFlagTypeLabel(flag.flag_type)}
                      </span>
                      {isReviewed && (
                        <span style={{
                          fontSize: '9px',
                          color: '#85D2D0',
                          fontWeight: 600
                        }}>
                          ✓ Reviewed
                        </span>
                      )}
                    </div>
                    <div style={{
                      fontSize: '10px',
                      color: '#8884a0'
                    }}>
                      Student: <strong style={{ color: '#e8e6f0' }}>{flag.student_name || 'Unknown'}</strong>
                    </div>
                  </div>

                  <div style={{
                    display: 'flex',
                    gap: '6px',
                    alignItems: 'center'
                  }}>
                    {!isReviewed && (
                      <button
                        onClick={(e) => markFlagReviewed(flag.id, e)}
                        style={{
                          padding: '4px 8px',
                          fontSize: '9px',
                          fontWeight: 600,
                          border: '1px solid rgba(133,210,208,0.3)',
                          background: 'rgba(133,210,208,0.1)',
                          color: '#85D2D0',
                          borderRadius: '4px',
                          cursor: 'pointer',
                          transition: 'all 0.2s'
                        }}
                        onMouseEnter={(e) => {
                          e.target.style.background = 'rgba(133,210,208,0.2)';
                        }}
                        onMouseLeave={(e) => {
                          e.target.style.background = 'rgba(133,210,208,0.1)';
                        }}
                      >
                        Mark Reviewed
                      </button>
                    )}
                    <span style={{
                      fontSize: '10px',
                      color: '#8884a0',
                      transform: isExpanded ? 'rotate(180deg)' : 'rotate(0deg)',
                      transition: 'transform 0.2s'
                    }}>
                      ▼
                    </span>
                  </div>
                </div>

                {/* Expanded Details */}
                {isExpanded && (
                  <div style={{
                    marginTop: '10px',
                    paddingTop: '10px',
                    borderTop: '1px solid #2e2e4a',
                    fontSize: '10px',
                    color: '#8884a0',
                    lineHeight: '1.5'
                  }}>
                    {flag.evidence && Object.keys(flag.evidence).length > 0 && (
                      <div style={{ marginBottom: '8px' }}>
                        <div style={{ fontWeight: 600, color: '#e8e6f0', marginBottom: '4px' }}>Evidence:</div>
                        <div style={{ paddingLeft: '8px', borderLeft: '2px solid rgba(133,210,208,0.2)' }}>
                          {Object.entries(flag.evidence).map(([key, value]) => (
                            <div key={key} style={{ marginBottom: '2px' }}>
                              <strong>{key}:</strong> {String(value)}
                            </div>
                          ))}
                        </div>
                      </div>
                    )}

                    {flag.context_behaviors && flag.context_behaviors.length > 0 && (
                      <div>
                        <div style={{ fontWeight: 600, color: '#e8e6f0', marginBottom: '4px' }}>Behaviors:</div>
                        <div style={{ paddingLeft: '8px' }}>
                          {flag.context_behaviors.map((behavior, idx) => (
                            <div key={idx} style={{ marginBottom: '2px' }}>
                              • {behavior}
                            </div>
                          ))}
                        </div>
                      </div>
                    )}

                    {flag.created_at && (
                      <div style={{ marginTop: '8px', fontSize: '9px', color: '#8884a0' }}>
                        Detected: {new Date(flag.created_at).toLocaleDateString()} {new Date(flag.created_at).toLocaleTimeString()}
                      </div>
                    )}
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
