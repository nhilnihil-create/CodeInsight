import React, { useState, useEffect } from 'react';
import api from '../../services/api';
import LongitudinalProgressChart from './LongitudinalProgressChart';

function LongitudinalTab({ sectionId }) {
  const [sectionData, setSectionData] = useState(null);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [selectedStudent, setSelectedStudent] = useState(null);

  useEffect(() => {
    fetchSectionLongitudinal();
  }, [sectionId]);

  const fetchSectionLongitudinal = async () => {
    try {
      setLoading(true);
      const res = await api.get(`/api/analytics/sections/${sectionId}/longitudinal`);
      setSectionData(res.data);
    } catch (err) {
      console.error('Error fetching section longitudinal data:', err);
      setError('Failed to load longitudinal data');
      setSectionData(null);
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
        Loading longitudinal data...
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

  if (!sectionData || !sectionData.students || sectionData.students.length === 0) {
    return (
      <div style={{
        padding: '20px',
        textAlign: 'center',
        color: '#8884a0',
        background: '#1a1a2e',
        borderRadius: '12px',
        border: '1px solid #2e2e4a'
      }}>
        <div>No student data available for this section</div>
        <div style={{ marginTop: '8px', fontSize: '12px' }}>
          Enroll students and wait for submissions to see progress
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
          Longitudinal Reports
        </h3>
        <div style={{
          display: 'flex',
          alignItems: 'center',
          gap: '12px'
        }}>
          <div style={{
            fontSize: '12px',
            color: '#85D2D0'
          }}>
            {sectionData.students.length} students
          </div>
          <select
            value={selectedStudent || ''}
            onChange={(e) => {
              const id = parseInt(e.target.value);
              setSelectedStudent(isNaN(id) ? null : id);
            }}
            style={{
              background: '#131d30',
              border: '1px solid #1e304d',
              borderRadius: '6px',
              padding: '6px 10px',
              fontSize: '11px',
              color: '#e8e6f0',
              fontFamily: 'DM Sans, sans-serif',
              outline: 'none',
              cursor: 'pointer'
            }}
          >
            <option value="">All Students (Section Overview)</option>
            {sectionData.students.map(student => (
              <option key={student.studentId} value={student.studentId}>
                {student.studentName}
              </option>
            ))}
          </select>
        </div>
      </div>

      <div style={{
        padding: '16px',
        maxHeight: '600px',
        overflowY: 'auto'
      }}>
        {selectedStudent ? (
          // Individual student view
          <>
            <div style={{
              marginBottom: '16px',
              padding: '12px 16px',
              background: '#22223a',
              borderRadius: '8px'
            }}>
              <div style={{
                display: 'flex',
                justifyContent: 'space-between',
                alignItems: 'center'
              }}>
                <div style={{
                  fontSize: '14px',
                  fontWeight: 600,
                  color: '#e8e6f0'
                }}>
                  Individual Progress: {sectionData.students.find(s => s.studentId === selectedStudent)?.studentName || 'Unknown'}
                </div>
                <button
                  onClick={() => setSelectedStudent(null)}
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
                  Back to Section Overview
                </button>
              </div>
            </div>

            <LongitudinalProgressChart
              data={{
                conceptTimeline: sectionData.students
                  .find(s => s.studentId === selectedStudent)?.progression || [],
                overallProgress: {
                  conceptsResolved: sectionData.students
                    .find(s => s.studentId === selectedStudent)?.progression
                    .filter(p => p.classification === 'Low').length || 0,
                  conceptsAttempted: sectionData.students
                    .find(s => s.studentId === selectedStudent)?.progression.length || 0,
                  resolutionRate: sectionData.students
                    .find(s => s.studentId === selectedStudent)?.progression
                    .filter(p => p.classification === 'Low').length /
                    Math.max(sectionData.students
                      .find(s => s.studentId === selectedStudent)?.progression.length || 1, 1),
                  masteryTrend: sectionData.students
                    .find(s => s.studentId === selectedStudent)?.masteryVelocity || 'stable'
                }
              }}
              studentName={sectionData.students.find(s => s.studentId === selectedStudent)?.studentName}
            />
          </>
        ) : (
          // Section overview view
          <div style={{
            display: 'grid',
            gap: '20px'
          }}>
            {/* Section-wide Trends */}
            <div style={{
              background: '#22223a',
              borderRadius: '10px',
              overflow: 'hidden'
            }}>
              <div style={{
                padding: '16px',
                borderBottom: '1px solid #2e2e4a'
              }}>
                <h4 style={{
                  margin: '0 0 12px 0',
                  fontSize: '16px',
                  color: '#e8e6f0',
                  fontWeight: 600
                }}>
                  Section-wide Trends
                </h4>
                <div style={{
                  display: 'grid',
                  gridTemplateColumns: 'repeat(auto-fit, minmax(200px, 1fr))',
                  gap: '16px'
                }}>
                  {/* Concept Mastery Distribution */}
                  <div>
                    <div style={{
                      fontSize: '12px',
                      fontWeight: 600,
                      color: '#8884a0',
                      marginBottom: '8px'
                    }}>
                      Concept Mastery Distribution
                    </div>
                    <div style={{
                      display: 'flex',
                      flexDirection: 'column',
                      gap: '6px'
                    }}>
                      {[['Datatypes', '#4ade80'], ['Variables', '#4ade80'], ['Conditionals', '#fbbf24'], ['Loops', '#fbbf24'], ['Functions', '#f87171'], ['Arrays', '#f87171'], ['OOP', '#ef4444']].map(([concept, color]) => {
                        const conceptData = sectionData.students.reduce((acc, student) => {
                          const latest = student.progression[student.progression.length - 1];
                          if (latest && latest.concept_name === concept) {
                            return acc + 1;
                          }
                          return acc;
                        }, 0);
                        const totalStudents = sectionData.students.length;
                        const percentage = totalStudents > 0 ? Math.round((conceptData / totalStudents) * 100) : 0;

                        return (
                          <div key={concept} style={{
                            display: 'flex',
                            justifyContent: 'space-between',
                            alignItems: 'center',
                            padding: '8px 12px',
                            background: '#131d30',
                            borderRadius: '6px'
                          }}>
                            <span>{concept}</span>
                            <div style={{
                              display: 'flex',
                              alignItems: 'center',
                              gap: '6px'
                            }}>
                              <div style={{
                                width: '10px',
                                height: '10px',
                                borderRadius: '50%',
                                background: color
                              }}></div>
                              <span>{percentage}% ({conceptData}/{totalStudents})</span>
                            </div>
                          </div>
                        );
                      })}
                    </div>
                  </div>

                  {/* Mastery Velocity Overview */}
                  <div>
                    <div style={{
                      fontSize: '12px',
                      fontWeight: 600,
                      color: '#8884a0',
                      marginBottom: '8px'
                    }}>
                      Mastery Velocity Distribution
                    </div>
                    <div style={{
                      display: 'flex',
                      flexDirection: 'column',
                      gap: '6px'
                    }}>
                      {[['Improving', '#10b981'], ['Stable', '#6b7280'], ['Declining', '#ef4444']].map(([velocity, color]) => {
                        const count = sectionData.students.filter(s => s.masteryVelocity === velocity.toLowerCase()).length;
                        const percentage = sectionData.students.length > 0 ? Math.round((count / sectionData.students.length) * 100) : 0;

                        return (
                          <div key={velocity} style={{
                            display: 'flex',
                            justifyContent: 'space-between',
                            alignItems: 'center',
                            padding: '8px 12px',
                            background: '#131d30',
                            borderRadius: '6px'
                          }}>
                            <span>{velocity}</span>
                            <div style={{
                              display: 'flex',
                              alignItems: 'center',
                              gap: '6px'
                            }}>
                              <div style={{
                                width: '10px',
                                height: '10px',
                                borderRadius: '50%',
                                background: color
                              }}></div>
                              <span>{percentage}% ({count}/{sectionData.students.length})</span>
                            </div>
                          </div>
                        );
                      })}
                    </div>
                  </div>
                </div>
              </div>
            </div>

            {/* Student Roster Timeline */}
            <div style={{
              background: '#22223a',
              borderRadius: '10px',
              overflow: 'hidden'
            }}>
              <div style={{
                padding: '16px',
                borderBottom: '1px solid #2e2e4a'
              }}>
                <h4 style={{
                  margin: '0 0 12px 0',
                  fontSize: '16px',
                  color: '#e8e6f0',
                  fontWeight: 600
                }}>
                  Student Progress Timeline
                </h4>
              </div>
              <div style={{
                padding: '16px',
                maxHeight: '400px',
                overflowY: 'auto'
              }}>
                {sectionData.students.map((student) => {
                  const latest = student.progression[student.progression.length - 1];
                  const classification = latest ? latest.classification : 'Unscored';
                  const getClassificationColor = (classification) => {
                    switch (classification) {
                      case 'Low': return '#10b981';
                      case 'Moderate': return '#f59e0b';
                      case 'High': return '#ef4444';
                      default: return '#6b7280';
                    }
                  };

                  return (
                    <div key={student.studentId} style={{
                      display: 'flex',
                      justifyContent: 'space-between',
                      alignItems: 'center',
                      padding: '12px 16px',
                      borderBottom: '1px solid #2e2e4a'
                    }}>
                      <div style={{
                        display: 'flex',
                        alignItems: 'center',
                        gap: '12px'
                      }}>
                        <div style={{
                          width: '36px',
                          height: '36px',
                          borderRadius: '50%',
                          background: getClassificationColor(classification),
                          display: 'flex',
                          alignItems: 'center',
                          justifyContent: 'center',
                          color: 'white',
                          fontSize: '14px',
                          fontWeight: 600
                        }}>
                          {classification === 'Low' && 'L'}
                          {classification === 'Moderate' && 'M'}
                          {classification === 'High' && 'H'}
                          {classification === 'Unscored' && '?'}
                        </div>
                        <div>
                          <div style={{
                            fontSize: '13px',
                            fontWeight: 600,
                            color: '#e8e6f0'
                          }}>
                            {student.studentName}
                          </div>
                          <div style={{
                            fontSize: '11px',
                            color: '#8884a0'
                          }}>
                            {student.progression.length} exercises attempted
                          </div>
                        </div>
                      </div>
                      <div style={{
                        display: 'flex',
                        alignItems: 'center',
                        gap: '8px',
                        fontSize: '11px',
                        color: '#8884a0'
                      }}>
                        <div>Velocity: </div>
                        <span style={{
                          fontWeight: 600,
                          color: student.masteryVelocity === 'improving' ? '#10b981' :
                                student.masteryVelocity === 'declining' ? '#ef4444' : '#6b7280'
                        }}>
                          {student.masteryVelocity.charAt(0).toUpperCase() + student.masteryVelocity.slice(1)}
                        </span>
                      </div>
                    </div>
                  );
                })}
              </div>
            </div>
          </div>
        )}
      </div>
    </div>
  );
}

export default LongitudinalTab;