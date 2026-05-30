import { useState, useEffect } from 'react';
import { Link } from 'react-router-dom';
import api from '../../services/api';
import { useSidebar } from '../../context/SidebarContext';

export default function InstructorDashboard() {
  const { isOpen } = useSidebar();
  const [sections, setSections] = useState([]);
  const [selectedSectionId, setSelectedSectionId] = useState(null);
  const [selectedSection, setSelectedSection] = useState(null);
  const [heatmapData, setHeatmapData] = useState(null);
  const [alerts, setAlerts] = useState([]);
  const [loading, setLoading] = useState(true);
  const [analyticsLoading, setAnalyticsLoading] = useState(false);
  const [error, setError] = useState('');

  const CONCEPT_ORDER = ['Datatypes','Variables','Conditionals','Loops','Functions','Arrays','OOP'];

  useEffect(() => {
    fetchSections();
  }, []);

  useEffect(() => {
    if (selectedSectionId) {
      fetchAnalytics(selectedSectionId);
    }
  }, [selectedSectionId]);

  const fetchSections = async () => {
    try {
      const res = await api.get('/api/sections');
      setSections(res.data || []);
      if (res.data && res.data.length > 0) {
        setSelectedSectionId(res.data[0].id);
        setSelectedSection(res.data[0]);
      }
    } catch (err) {
      setError('Failed to load sections: ' + (err.response?.data?.message || err.message));
      console.error('Sections fetch error:', err);
    } finally {
      setLoading(false);
    }
  };

  const fetchAnalytics = async (sectionId) => {
    setAnalyticsLoading(true);
    try {
      const [heatRes, alertRes] = await Promise.all([
        api.get(`/api/analytics/heatmap/${sectionId}`),
        api.get(`/api/analytics/alerts/${sectionId}`)
      ]);
      setHeatmapData(heatRes.data);
      setAlerts(alertRes.data || []);
    } catch (err) {
      console.error('Error fetching analytics:', err);
    } finally {
      setAnalyticsLoading(false);
    }
  };

  const handleSectionChange = (sectionId) => {
    setSelectedSectionId(sectionId);
    const section = sections.find(s => s.id === sectionId);
    setSelectedSection(section);
  };

  const formatCDS = (value) => {
    if (value === null || value === undefined) return '—';
    const num = typeof value === 'string' ? parseFloat(value) : value;
    return isNaN(num) ? '—' : num.toFixed(2);
  };

  const getDifficulty = (cds) => {
    if (cds === null || cds === undefined) return 'unscored';
    if (cds <= 0.33) return 'low';
    if (cds <= 0.66) return 'moderate';
    return 'high';
  };

  const getModerateRiskCount = () => {
    if (!heatmapData) return 0;
    const seen = new Set();
    let count = 0;
    for (const concept in heatmapData.classAverages) {
      const scores = Object.values(heatmapData.scores).map(s => s[concept]?.cds).filter(s => s !== undefined && s !== null);
      const moderate = scores.filter(s => {
        const num = typeof s === 'string' ? parseFloat(s) : s;
        return num > 0.33 && num <= 0.66;
      }).length;
    }
    // Count students with at least one moderate score
    for (const studentId in heatmapData.scores) {
      const hasModerate = CONCEPT_ORDER.some(concept => {
        const score = heatmapData.scores[studentId][concept];
        if (!score) return false;
        const cds = typeof score.cds === 'string' ? parseFloat(score.cds) : score.cds;
        return cds > 0.33 && cds <= 0.66;
      });
      if (hasModerate && !seen.has(studentId)) {
        seen.add(studentId);
        count++;
      }
    }
    return count;
  };

  const getHighDifficultyCount = () => {
    if (!heatmapData) return 0;
    const seen = new Set();
    for (const studentId in heatmapData.scores) {
      const hasHigh = CONCEPT_ORDER.some(concept => {
        const score = heatmapData.scores[studentId][concept];
        if (!score) return false;
        const cds = typeof score.cds === 'string' ? parseFloat(score.cds) : score.cds;
        return cds > 0.66;
      });
      if (hasHigh) seen.add(studentId);
    }
    return seen.size;
  };

  if (loading) {
    return (
      <div style={{ padding: '40px', textAlign: 'center', color: '#8884a0' }}>
        Loading dashboard...
      </div>
    );
  }

  if (sections.length === 0) {
    return (
      <div style={{ padding: '40px', textAlign: 'center', color: '#8884a0' }}>
        No sections yet. <Link to="/instructor/sections" style={{ color: '#85D2D0' }}>Create one</Link> to get started!
      </div>
    );
  }

  return (
    <div style={{ 
      padding: '28px 28px 28px 16px',
      width: '100%',
      boxSizing: 'border-box',
      background: '#0c1220',
      minHeight: '100%'
    }}>
        {/* Header */}
        <div style={{ display: 'flex', justifyContent: 'space-between', alignItems: 'flex-start', marginBottom: '28px', gap: '16px', flexWrap: 'wrap' }}>
          <div>
            <div style={{ fontSize: '17px', fontWeight: 700, color: '#e8e6f0', marginBottom: '2px' }}>
              Difficulty Analytics Dashboard
            </div>
            {selectedSection && (
              <div style={{ fontSize: '11px', color: '#8884a0' }}>
                {selectedSection.course_code} · {selectedSection.name} · AY 2025–2026 · {selectedSection.student_count} students
              </div>
            )}
          </div>
          <div style={{ display: 'flex', gap: '10px' }}>
            <button style={{
              padding: '8px 16px',
              background: 'transparent',
              border: '1px solid #2e2e4a',
              borderRadius: '8px',
              color: '#8884a0',
              fontWeight: 600,
              cursor: 'pointer',
              fontSize: '12px',
              transition: 'all 0.15s'
            }}>
              Export Report
            </button>
            <Link
              to="/instructor/create-exercise"
              style={{
                padding: '8px 16px',
                background: '#85D2D0',
                border: 'none',
                borderRadius: '8px',
                color: '#0f0f1a',
                fontWeight: 600,
                cursor: 'pointer',
                fontSize: '12px',
                textDecoration: 'none',
                display: 'inline-block'
              }}
            >
              + New Exercise
            </Link>
          </div>
        </div>

        {/* Section Selector */}
        {sections.length > 1 && (
          <div style={{ marginBottom: '20px' }}>
            <label style={{ fontSize: '12px', fontWeight: 600, color: '#8884a0', marginBottom: '8px', display: 'block' }}>
              Select Section
            </label>
            <select
              value={selectedSectionId || ''}
              onChange={(e) => handleSectionChange(parseInt(e.target.value))}
              style={{
                padding: '8px 12px',
                background: '#1a1a2e',
                border: '1px solid #2e2e4a',
                borderRadius: '8px',
                color: '#e8e6f0',
                fontSize: '12px',
                cursor: 'pointer'
              }}
            >
              {sections.map(s => (
                <option key={s.id} value={s.id}>{s.course_code} - {s.name}</option>
              ))}
            </select>
          </div>
        )}

        {analyticsLoading ? (
          <div style={{ color: '#8884a0', textAlign: 'center', padding: '40px' }}>Loading analytics...</div>
        ) : heatmapData && selectedSection ? (
          <>
            {/* Stats Row */}
            <div style={{ display: 'grid', gridTemplateColumns: 'repeat(4, 1fr)', gap: '14px', marginBottom: '28px' }}>
              <div style={{ background: '#131d30', border: '1px solid #1e304d', borderRadius: '12px', padding: '16px 18px', position: 'relative', overflow: 'hidden', borderRight: '3px solid #85D2D0' }}>
                <div style={{ fontSize: '10px', fontWeight: 600, letterSpacing: '1.5px', textTransform: 'uppercase', color: '#8884a0', marginBottom: '8px' }}>
                  Total Students
                </div>
                <div style={{ fontFamily: "'Space Mono', monospace", fontSize: '26px', fontWeight: 700, color: '#e8e6f0' }}>
                  {selectedSection.student_count || 0}
                </div>
                <div style={{ fontSize: '10px', color: '#8884a0', marginTop: '4px' }}>
                  Section active
                </div>
              </div>

              <div style={{ background: '#131d30', border: '1px solid #1e304d', borderRadius: '12px', padding: '16px 18px', position: 'relative', overflow: 'hidden', borderRight: '3px solid #a99dd4' }}>
                <div style={{ fontSize: '10px', fontWeight: 600, letterSpacing: '1.5px', textTransform: 'uppercase', color: '#8884a0', marginBottom: '8px' }}>
                  Concepts Covered
                </div>
                <div style={{ fontFamily: "'Space Mono', monospace", fontSize: '26px', fontWeight: 700, color: '#e8e6f0' }}>
                  {(selectedSection.concept_count || CONCEPT_ORDER.length)}
                </div>
                <div style={{ fontSize: '10px', color: '#8884a0', marginTop: '4px' }}>
                  of {CONCEPT_ORDER.length} planned
                </div>
              </div>

              <div style={{ background: '#131d30', border: '1px solid #1e304d', borderRadius: '12px', padding: '16px 18px', position: 'relative', overflow: 'hidden', borderRight: '3px solid #fbbf24' }}>
                <div style={{ fontSize: '10px', fontWeight: 600, letterSpacing: '1.5px', textTransform: 'uppercase', color: '#8884a0', marginBottom: '8px' }}>
                  Moderate Risk
                </div>
                <div style={{ fontFamily: "'Space Mono', monospace", fontSize: '26px', fontWeight: 700, color: '#e8e6f0' }}>
                  {getModerateRiskCount()}
                </div>
                <div style={{ fontSize: '10px', color: '#8884a0', marginTop: '4px' }}>
                  students flagged
                </div>
              </div>

              <div style={{ background: '#131d30', border: '1px solid #1e304d', borderRadius: '12px', padding: '16px 18px', position: 'relative', overflow: 'hidden', borderRight: '3px solid #f87171' }}>
                <div style={{ fontSize: '10px', fontWeight: 600, letterSpacing: '1.5px', textTransform: 'uppercase', color: '#8884a0', marginBottom: '8px' }}>
                  High Difficulty
                </div>
                <div style={{ fontFamily: "'Space Mono', monospace", fontSize: '26px', fontWeight: 700, color: '#e8e6f0' }}>
                  {getHighDifficultyCount()}
                </div>
                <div style={{ fontSize: '10px', color: '#8884a0', marginTop: '4px' }}>
                  need intervention
                </div>
              </div>
            </div>

            {/* Heatmap Section */}
            <div style={{ marginBottom: '20px' }}>
              <div style={{ display: 'flex', alignItems: 'center', justifyContent: 'space-between', marginBottom: '14px' }}>
                <div style={{ fontSize: '13px', fontWeight: 700, color: '#e8e6f0', letterSpacing: '0.3px' }}>
                  Concept Difficulty Heatmap — Class Overview
                </div>
                <div style={{ display: 'flex', gap: '14px', alignItems: 'center' }}>
                  {[['#4ade80', 'Low'], ['#fbbf24', 'Moderate'], ['#f87171', 'High'], ['#1e304d', 'Unscored']].map(([color, label]) => (
                    <div key={label} style={{ display: 'flex', alignItems: 'center', gap: '5px', fontSize: '10px', color: '#8884a0' }}>
                      <div style={{ width: '8px', height: '8px', borderRadius: '2px', background: color }}></div>
                      {label}
                    </div>
                  ))}
                </div>
              </div>
            </div>

            {/* Heatmap Table */}
            <div style={{ background: '#131d30', border: '1px solid #1e304d', borderRadius: '12px', overflow: 'hidden', marginBottom: '20px' }}>
              <table style={{ width: '100%', borderCollapse: 'collapse' }}>
                <thead>
                  <tr style={{ borderBottom: '1px solid #1e304d', background: '#1a2640' }}>
                    <th style={{ padding: '10px 12px', fontSize: '10px', fontWeight: 600, letterSpacing: '1px', textTransform: 'uppercase', color: '#8884a0', textAlign: 'left', minWidth: '130px' }}>
                      Student
                    </th>
                    {CONCEPT_ORDER.map(concept => (
                      <th key={concept} style={{ padding: '10px 12px', fontSize: '10px', fontWeight: 600, letterSpacing: '1px', textTransform: 'uppercase', color: '#8884a0', textAlign: 'center', whiteSpace: 'nowrap' }}>
                        {concept}
                      </th>
                    ))}
                  </tr>
                </thead>
                <tbody>
                  {heatmapData.students.map(student => (
                    <tr key={student.id} style={{ borderBottom: '1px solid #1e304d' }}>
                      <td style={{ padding: '8px 12px', fontSize: '12px' }}>
                        <div style={{ fontWeight: 600, color: '#e8e6f0', fontSize: '12px' }}>
                          {student.name}
                        </div>
                      </td>
                      {CONCEPT_ORDER.map(concept => {
                        const score = heatmapData.scores[student.id]?.[concept];
                        const cds = score?.cds;
                        const cdsNum = typeof cds === 'string' ? parseFloat(cds) : cds;
                        const difficulty = getDifficulty(cdsNum);
                        
                        const cellStyles = {
                          low: { background: 'rgba(74,222,128,0.12)', color: '#4ade80', border: '1px solid rgba(74,222,128,0.2)' },
                          moderate: { background: 'rgba(251,191,36,0.12)', color: '#fbbf24', border: '1px solid rgba(251,191,36,0.2)' },
                          high: { background: 'rgba(248,113,113,0.14)', color: '#f87171', border: '1px solid rgba(248,113,113,0.25)' },
                          unscored: { background: 'rgba(30,48,77,0.3)', color: '#8884a0', border: '1px solid #1e304d' }
                        };

                        return (
                          <td key={concept} style={{ padding: '8px 12px', textAlign: 'center' }}>
                            <div style={{
                              display: 'inline-flex',
                              alignItems: 'center',
                              justifyContent: 'center',
                              width: '54px',
                              height: '28px',
                              borderRadius: '6px',
                              fontSize: '10px',
                              fontWeight: 700,
                              fontFamily: "'Space Mono', monospace",
                              letterSpacing: '0.5px',
                              ...cellStyles[difficulty]
                            }}>
                              {formatCDS(cdsNum)}
                            </div>
                          </td>
                        );
                      })}
                    </tr>
                  ))}
                </tbody>
              </table>
            </div>

            {/* Bottom Row: Alerts + Class Averages */}
            <div style={{ display: 'grid', gridTemplateColumns: '1.2fr 0.8fr', gap: '14px' }}>
              {/* Alerts Panel */}
              <div style={{ background: '#131d30', border: '1px solid #1e304d', borderRadius: '12px', overflow: 'hidden' }}>
                <div style={{ padding: '12px 16px', borderBottom: '1px solid #1e304d', display: 'flex', alignItems: 'center', justifyContent: 'space-between', background: '#1a2640' }}>
                  <div style={{ fontSize: '12px', fontWeight: 700, color: '#e8e6f0' }}>
                    ⚠ Early Warning Alerts
                  </div>
                  <div style={{ background: 'rgba(248,113,113,0.15)', color: '#f87171', fontSize: '10px', fontWeight: 700, padding: '3px 8px', borderRadius: '20px', border: '1px solid rgba(248,113,113,0.3)' }}>
                    {alerts.length} students
                  </div>
                </div>
                <div>
                  {alerts.slice(0, 5).map((alert, idx) => (
                    <div key={idx} style={{ padding: '12px 16px', borderBottom: idx < Math.min(5, alerts.length - 1) ? '1px solid #1e304d' : 'none', display: 'flex', alignItems: 'center', justifyContent: 'space-between' }}>
                      <div>
                        <div style={{ fontSize: '12px', fontWeight: 600, color: '#e8e6f0' }}>
                          {alert.student_name}
                        </div>
                        <div style={{ fontSize: '10px', color: '#8884a0', marginTop: '2px' }}>
                          High difficulty · {alert.exercise_title}
                        </div>
                      </div>
                      <div style={{ fontFamily: "'Space Mono', monospace", fontSize: '12px', fontWeight: 700, color: '#f87171' }}>
                        {formatCDS(alert.cds_score)}
                      </div>
                    </div>
                  ))}
                  {alerts.length === 0 && (
                    <div style={{ padding: '12px 16px', textAlign: 'center', color: '#8884a0', fontSize: '12px' }}>
                      No alerts — great job!
                    </div>
                  )}
                </div>
              </div>

              {/* Class Average by Concept */}
              <div style={{ background: '#131d30', border: '1px solid #1e304d', borderRadius: '12px', overflow: 'hidden' }}>
                <div style={{ padding: '12px 16px', borderBottom: '1px solid #1e304d', background: '#1a2640' }}>
                  <div style={{ fontSize: '12px', fontWeight: 700, color: '#e8e6f0' }}>
                    Class Average CDS by Concept
                  </div>
                </div>
                <div style={{ padding: '16px' }}>
                  {CONCEPT_ORDER.map(concept => {
                    const avg = heatmapData.classAverages[concept];
                    const avgNum = avg?.avgCDS ? (typeof avg.avgCDS === 'string' ? parseFloat(avg.avgCDS) : avg.avgCDS) : null;
                    const difficulty = getDifficulty(avgNum);
                    const widths = {
                      low: avgNum ? Math.min(avgNum * 100, 100) : 0,
                      moderate: avgNum ? Math.min(avgNum * 100, 100) : 0,
                      high: avgNum ? Math.min(avgNum * 100, 100) : 0,
                      unscored: 0
                    };
                    const barColor = difficulty === 'low' ? '#4ade80' : difficulty === 'moderate' ? '#fbbf24' : difficulty === 'high' ? '#f87171' : '#1e304d';
                    
                    return (
                      <div key={concept} style={{ marginBottom: '12px' }}>
                        <div style={{ display: 'flex', justifyContent: 'space-between', marginBottom: '5px' }}>
                          <span style={{ fontSize: '11px', fontWeight: 600, color: '#e8e6f0' }}>{concept}</span>
                          <span style={{ fontSize: '10px', fontFamily: "'Space Mono', monospace", color: '#8884a0' }}>
                            {formatCDS(avgNum)} · {avg?.classification || 'Unscored'}
                          </span>
                        </div>
                        <div style={{ background: '#0a1018', borderRadius: '4px', height: '7px', overflow: 'hidden', position: 'relative' }}>
                          <div style={{
                            height: '100%',
                            borderRadius: '4px',
                            background: barColor,
                            width: avgNum ? `${Math.min(avgNum * 100, 100)}%` : '0%',
                            transition: 'width 0.6s ease'
                          }}></div>
                        </div>
                      </div>
                    );
                  })}
                </div>
              </div>
            </div>
          </>
        ) : (
          <div style={{ color: '#8884a0', textAlign: 'center', padding: '40px' }}>
            No analytics data available
          </div>
        )}
      </div>
  );
}
