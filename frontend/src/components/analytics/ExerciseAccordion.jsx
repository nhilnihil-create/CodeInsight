import React, { useState, useEffect } from 'react';
import api from '../../services/api';
import ClassMisconceptionReport from './ClassMisconceptionReport';

function ExerciseAccordion({ sectionId }) {
  const [exercises, setExercises] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [reports, setReports] = useState({});
  const [loadingReports, setLoadingReports] = useState({});

  useEffect(() => {
    fetchSectionExercises();
  }, [sectionId]);

  const fetchSectionExercises = async () => {
    if (!sectionId) {
      setExercises([]);
      setLoading(false);
      return;
    }
    try {
      setLoading(true);
      const res = await api.get(`/api/sections/${sectionId}/exercises`);
      setExercises(res.data || []);
    } catch (err) {
      console.error('Error fetching section exercises:', err);
      setError('Failed to load exercises');
      setExercises([]);
    } finally {
      setLoading(false);
    }
  };

  const fetchExerciseReport = async (exerciseId) => {
    if (!sectionId) return;
    try {
      setLoadingReports(prev => ({
        ...prev,
        [exerciseId]: true
      }));
      const res = await api.get(`/api/analytics/sections/${sectionId}/class-insights/${exerciseId}`);
      setReports(prev => ({
        ...prev,
        [exerciseId]: res.data
      }));
    } catch (err) {
      console.error(`Error fetching report for exercise ${exerciseId}:`, err);
      // Don't set error state here to avoid breaking the UI for one exercise
    } finally {
      setLoadingReports(prev => ({
        ...prev,
        [exerciseId]: false
      }));
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
        Loading exercises...
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

  if (exercises.length === 0) {
    return (
      <div style={{
        padding: '20px',
        textAlign: 'center',
        color: '#8884a0',
        background: '#1a1a2e',
        borderRadius: '12px',
        border: '1px solid #2e2e4a'
      }}>
        <div>No exercises found in this section</div>
        <div style={{ marginTop: '8px', fontSize: '12px' }}>
          Assign exercises to see analytics
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
          Exercise Analytics
        </h3>
        <div style={{
          fontSize: '12px',
          color: '#85D2D0'
        }}>
          {exercises.length} exercises
        </div>
      </div>

      <div style={{
        padding: '16px',
        maxHeight: '600px',
        overflowY: 'auto'
      }}>
        {exercises.map((exercise) => {
          const isReportLoading = loadingReports[exercise.id];
          const report = reports[exercise.id];

          return (
            <div key={exercise.id} style={{
              marginBottom: '16px',
              background: '#22223a',
              borderRadius: '10px',
              overflow: 'hidden'
            }}>
              {/* Accordion Header */}
              <div style={{
                padding: '16px',
                cursor: 'pointer',
                borderBottom: '1px solid #2e2e4a',
                display: 'flex',
                justifyContent: 'space-between',
                alignItems: 'center',
                transition: 'background-color 0.2s'
              }}
              onMouseEnter={() => {
                // Hover effect would be handled by CSS in a real implementation
              }}
              onMouseLeave={() => {
                // Hover effect would be handled by CSS in a real implementation
              }}
              >
                <div style={{
                  display: 'flex',
                  alignItems: 'center',
                  gap: '12px',
                  flex: 1
                }}>
                  <div style={{
                    fontSize: '14px',
                    fontWeight: 600,
                    color: '#e8e6f0'
                  }}>
                    {exercise.title}
                  </div>
                  <div style={{
                    fontSize: '11px',
                    color: '#85D2D0',
                    background: 'rgba(133,210,208,0.1)',
                    border: '1px solid rgba(133,210,208,0.2)',
                    borderRadius: '6px',
                    padding: '2px 6px',
                    fontWeight: 600
                  }}>
                    {exercise.concept_name}
                  </div>
                </div>

                <div style={{
                  display: 'flex',
                  gap: '16px',
                  alignItems: 'center',
                  fontSize: '11px',
                  color: '#8884a0'
                }}>
                  <div>
                    Submitted: <strong style={{ color: '#e8e6f0' }}>
                      {exercise.submitted_count || 0}/{exercise.total_students || 0}
                    </strong>
                  </div>
                  <div>
                    Avg CDS: <strong style={{ color: exercise.avg_cds && parseFloat(exercise.avg_cds) > 0.66 ? '#f87171' : exercise.avg_cds && parseFloat(exercise.avg_cds) > 0.33 ? '#fbbf24' : '#4ade80' }}>
                      {exercise.avg_cds ? parseFloat(exercise.avg_cds).toFixed(2) : '--'}
                    </strong>
                  </div>
                </div>

                <div style={{
                  display: 'flex',
                  alignItems: 'center',
                  gap: '8px',
                  padding: '4px',
                  borderRadius: '4px',
                  background: isReportLoading || report ? '#131d30' : 'transparent'
                }}>
                  {isReportLoading ? (
                    <div style={{
                      fontSize: '10px',
                      color: '#85D2D0'
                    }}>
                      Loading...
                    </div>
                  ) : (
                    <span style={{
                      fontSize: '12px'
                    }}>
                      ▼
                    </span>
                  )}
                </div>
              </div>

              {/* Accordion Content */}
              <div style={{
                overflow: 'hidden',
                maxHeight: report ? 500 : 0,
                transition: 'max-height 0.3s ease-out',
                background: isReportLoading ? '#1a1a2e' : report ? '#1a1a2e' : 'transparent'
              }}
              >
                {isReportLoading && (
                  <div style={{
                    padding: '20px',
                    textAlign: 'center',
                    color: '#8884a0'
                  }}>
                    Loading report...
                  </div>
                )}

                {report && !isReportLoading && (
                  <>
                    <div style={{
                      padding: '16px',
                      borderBottom: '1px solid #2e2e4a'
                    }}>
                      <ClassMisconceptionReport report={report} onClose={() => {}} />
                    </div>

                    {/* Analytical Anomaly Footer Drawer */}
                    <div style={{
                      padding: '12px 16px',
                      borderTop: '1px solid #2e2e4a',
                      background: '#131d30',
                      fontSize: '11px',
                      color: '#8884a0'
                    }}>
                      <div style={{
                        display: 'flex',
                        flexDirection: 'column',
                        gap: '12px',
                        alignItems: 'flex-start'
                      }}>
                        <div style={{
                          display: 'flex',
                          justifyContent: 'space-between',
                          alignItems: 'center',
                          width: '100%'
                        }}>
                          <span>Historical Deviations</span>
                          <button
                            onClick={() => {
                              // In a real implementation, this would toggle the drawer
                              // For now, we'll keep it simple
                            }}
                            style={{
                              padding: '6px 12px',
                              fontSize: '11px',
                              fontWeight: 600,
                              border: '1px solid #85D2D0',
                              background: 'transparent',
                              color: '#85D2D0',
                              cursor: 'pointer',
                              borderRadius: '4px',
                              transition: 'all 0.2s ease'
                            }}
                            onMouseEnter={(e) => {
                              e.currentTarget.style.background = 'rgba(133,210,208,0.1)';
                            }}
                            onMouseLeave={(e) => {
                              e.currentTarget.style.background = 'transparent';
                            }}
                          >
                            ▼ View Details
                          </button>
                        </div>

                        {/* Analytical Anomaly Content (collapsed by default) */}
                        <div style={{
                          marginTop: '8px',
                          paddingTop: '8px',
                          borderTop: '1px solid #2e2e4a',
                          display: 'none' /* Would be toggled in real implementation */
                        }}>
                          <div style={{
                            fontSize: '10px',
                            color: '#8884a0',
                            lineHeight: '1.4'
                          }}>
                            <p>• Submission velocity patterns: Monitoring for anomalous submission bursts</p>
                            <p>• Code similarity analysis: Detecting potential collaboration patterns</p>
                            <p>• Time-on-task outliers: Identifying unusual time distribution</p>
                            <p>• Correctness consistency: Checking for inconsistent problem-solving approaches</p>
                          </div>
                        </div>
                      </div>
                    </div>
                    </>
                  )}
              </div>
            </div>
          );
        })}
      </div>
    </div>
  );
}

export default ExerciseAccordion;