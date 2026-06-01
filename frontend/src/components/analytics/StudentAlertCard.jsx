import React, { useState, useEffect } from 'react';
import api from '../../services/api';
import MicroConceptAlertCard from './MicroConceptAlertCard';

function StudentAlertCard({ sectionId }) {
  const [alerts, setAlerts] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [expandedAlertId, setExpandedAlertId] = useState(null);

  useEffect(() => {
    fetchSectionAlerts();
  }, [sectionId]);

  const fetchSectionAlerts = async () => {
    try {
      setLoading(true);
      const res = await api.get(`/api/analytics/sections/${sectionId}/micro-concept-alerts`);
      setAlerts(res.data || []);
    } catch (err) {
      console.error('Error fetching section micro-concept alerts:', err);
      setError('Failed to load alerts');
      setAlerts([]);
    } finally {
      setLoading(false);
    }
  };

  if (loading) {
    return (
      <div style={{
        padding: '20px',
        textAlign: 'center',
        color: '#8884a0',
        background: '#1a1a2e',
        borderRadius: '12px',
        border: '1px solid #2e2e4a'
      }}>
        Loading section alerts...
      </div>
    );
  }

  if (error) {
    return (
      <div style={{
        padding: '20px',
        textAlign: 'center',
        color: '#f87171',
        background: '#1a1a2e',
        borderRadius: '12px',
        border: '1px solid #2e2e4a'
      }}>
        {error}
      </div>
    );
  }

  if (alerts.length === 0) {
    return (
      <div style={{
        padding: '20px',
        textAlign: 'center',
        color: '#8884a0',
        background: '#1a1a2e',
        borderRadius: '12px',
        border: '1px solid #2e2e4a'
      }}>
        <div>✓ No high-difficulty alerts in this section</div>
        <div style={{ marginTop: '8px', fontSize: '12px' }}>
          All students are performing well
        </div>
      </div>
    );
  }

  return (
    <div style={{
      background: '#1a1a2e',
      border: '1px solid #2e2e4a',
      borderRadius: '12px',
      overflow: 'hidden'
    }}>
      <div style={{
        padding: '16px',
        borderBottom: '1px solid #2e2e4a',
        display: 'flex',
        justifyContent: 'space-between',
        alignItems: 'center'
      }}>
        <h3 style={{
          margin: 0,
          fontSize: '18px',
          color: '#e8e6f0',
          fontWeight: 600
        }}>
          Live Monitoring
        </h3>
        <div style={{
          fontSize: '12px',
          color: '#85D2D0'
        }}>
          {alerts.length} active alerts
        </div>
      </div>

      <div style={{
        padding: '16px',
        maxHeight: '600px',
        overflowY: 'auto'
      }}>
        {alerts.map((alert) => (
          <div key={alert.id} style={{
            marginBottom: '16px',
            padding: '16px',
            background: '#22223a',
            borderRadius: '10px',
            border: expandedAlertId === alert.id ? '2px solid #85D2D0' : '1px solid #2e2e4a'
          }}>
            <div style={{
              display: 'flex',
              justifyContent: 'space-between',
              alignItems: 'flex-start',
              marginBottom: '12px'
            }}>
              <div style={{
                display: 'flex',
                alignItems: 'center',
                gap: '12px'
              }}>
                {/* Behavior Anomaly Badges */}
                <div style={{
                  display: 'flex',
                  gap: '8px'
                }}>
                  {/* Paste Detection Badge */}
                  {alert.evidence && alert.evidence.includes('paste') && (
                    <div style={{
                      background: 'rgba(238, 68, 68, 0.1)',
                      border: '1px solid rgba(238, 68, 68, 0.3)',
                      borderRadius: '6px',
                      padding: '4px 8px',
                      fontSize: '11px',
                      fontWeight: 600,
                      color: '#ef4444',
                      display: 'flex',
                      alignItems: 'center',
                      gap: '4px'
                    }}>
                      <span style={{ fontSize: '12px' }}>🚨</span>
                      <span>Paste Detected</span>
                    </div>
                  )}

                  {/* Excessive Velocity Flag */}
                  {alert.evidence && alert.evidence.includes('velocity') && (
                    <div style={{
                      background: 'rgba(255, 159, 67, 0.1)',
                      border: '1px solid rgba(255, 159, 67, 0.3)',
                      borderRadius: '6px',
                      padding: '4px 8px',
                      fontSize: '11px',
                      fontWeight: 600,
                      color: '#ff9f43',
                      display: 'flex',
                      alignItems: 'center',
                      gap: '4px'
                    }}>
                      <span style={{ fontSize: '12px' }}>⚡</span>
                      <span>Excessive Velocity</span>
                    </div>
                  )}

                  {/* Retry Storm Detection */}
                  {alert.evidence && alert.evidence.includes('retry') && (
                    <div style={{
                      background: 'rgba(168, 85, 247, 0.1)',
                      border: '1px solid rgba(168, 85, 247, 0.3)',
                      borderRadius: '6px',
                      padding: '4px 8px',
                      fontSize: '11px',
                      fontWeight: 600,
                      color: '#a855f7',
                      display: 'flex',
                      alignItems: 'center',
                      gap: '4px'
                    }}>
                      <span style={{ fontSize: '12px' }}>🔄</span>
                      <span>Retry Storm</span>
                    </div>
                  )}
                </div>

                {/* Student Info */}
                <div>
                  <div style={{
                    fontSize: '10px',
                    fontWeight: 600,
                    letterSpacing: '0.8px',
                    textTransform: 'uppercase',
                    color: '#8884a0',
                    marginBottom: '4px'
                  }}>
                    Student
                  </div>
                  <div style={{
                    fontSize: '14px',
                    fontWeight: 600,
                    color: '#e8e6f0'
                  }}>
                    {alert.student_name}
                  </div>
                </div>

                {/* CDS Score */}
                <div style={{
                  display: 'inline-flex',
                  alignItems: 'center',
                  gap: '6px',
                  background: `rgba(248,113,113,0.1)`,
                  border: `1px solid ${alert.cds_score > 0.66 ? '#f87171' : alert.cds_score > 0.33 ? '#fbbf24' : '#4ade80'}`,
                  borderRadius: '6px',
                  padding: '4px 10px',
                  fontSize: '12px',
                  fontWeight: 700,
                  color: alert.cds_score > 0.66 ? '#f87171' : alert.cds_score > 0.33 ? '#fbbf24' : '#4ade80'
                }}>
                  <span style={{
                    width: '6px',
                    height: '6px',
                    borderRadius: '50%',
                    background: alert.cds_score > 0.66 ? '#f87171' : alert.cds_score > 0.33 ? '#fbbf24' : '#4ade80'
                  }}></span>
                  {alert.cds_score > 0.66 ? 'High' : alert.cds_score > 0.33 ? 'Moderate' : 'Low'}
                  ({alert.cds_score ? (alert.cds_score * 100).toFixed(1) : '0'}%)
                </div>
              </div>

              {/* Toggle Button */}
              <button
                onClick={() =>
                  expandedAlertId === alert.id
                    ? setExpandedAlertId(null)
                    : setExpandedAlertId(alert.id)
                }
                style={{
                  padding: '6px 12px',
                  fontSize: '11px',
                  fontWeight: 600,
                  border: 'none',
                  background: 'transparent',
                  color: '#85D2D0',
                  cursor: 'pointer',
                  borderRadius: '4px',
                  fontFamily: 'DM Sans, sans-serif',
                  transition: 'all 0.15s'
                }}
              >
                {expandedAlertId === alert.id ? '▲ Hide Details' : '▼ View Misconception Breakdown'}
              </button>
            </div>

            {/* Expanded MCD Content */}
            {expandedAlertId === alert.id && (
              <div style={{
                marginTop: '12px',
                paddingTop: '12px',
                borderTop: '1px solid #2e2e4a'
              }}>
                <MicroConceptAlertCard
                  alert={{
                    ...alert,
                    classification: alert.cds_score > 0.66 ? 'High' : alert.cds_score > 0.33 ? 'Moderate' : 'Low',
                    cds_score: alert.cds_score
                  }}
                  onDismiss={() => {
                    // In a real implementation, this would mark the alert as reviewed
                    // For now, we'll just remove it from the list
                    setAlerts(alerts.filter(a => a.id !== alert.id));
                  }}
                />
              </div>
            )}
          </div>
        ))}
      </div>
    </div>
  );
}

export default StudentAlertCard;