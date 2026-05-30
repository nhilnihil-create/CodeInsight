import { useState, useEffect } from 'react';
import { Link } from 'react-router-dom';
import api from '../../services/api';

export default function InstructorSections() {
  const [sections, setSections] = useState([]);
  const [activityData, setActivityData] = useState([]);
  const [loading, setLoading] = useState(true);
  const [showForm, setShowForm] = useState(false);
  const [formData, setFormData] = useState({ name: '', course_code: '', school_year: '', semester: 'Sem 1' });

  useEffect(() => {
    fetchSections();
  }, []);

  const fetchSections = async () => {
    try {
      const res = await api.get('/api/sections');
      setSections(res.data || []);

      // Fetch activity for each section
      if (res.data && res.data.length > 0) {
        const activ = [];
        for (const sec of res.data) {
          try {
            const actRes = await api.get(`/api/analytics/activity/${sec.id}`);
            activ.push(...actRes.data);
          } catch (e) {
            console.error('Error fetching activity:', e);
          }
        }
        setActivityData(activ.sort((a, b) => new Date(b.created_at) - new Date(a.created_at)).slice(0, 5));
      }
    } catch (err) {
      console.error('Error fetching sections:', err);
    } finally {
      setLoading(false);
    }
  };

  const handleSubmit = async (e) => {
    e.preventDefault();
    try {
      await api.post('/api/sections', formData);
      setFormData({ name: '', course_code: '', school_year: '', semester: 'Sem 1' });
      setShowForm(false);
      await fetchSections();
    } catch (err) {
      console.error('Error creating section:', err);
    }
  };

  const formatCDS = (value) => {
    if (value === null || value === undefined) return '-';
    const num = typeof value === 'string' ? parseFloat(value) : value;
    return isNaN(num) ? '-' : num.toFixed(2);
  };

  const getDifficultyColor = (cds) => {
    if (cds === null || cds === undefined) return '#8884a0';
    if (cds <= 0.33) return '#4ade80';
    if (cds <= 0.66) return '#fbbf24';
    return '#f87171';
  };

  const getTotalStudents = () => {
    return sections.reduce((sum, s) => sum + (s.student_count || 0), 0);
  };

  const getTotalAlerts = () => {
    return sections.reduce((sum, s) => sum + (s.alert_count || 0), 0);
  };

  const formatTime = (timestamp) => {
    if (!timestamp) return 'just now';
    const date = new Date(timestamp);
    const now = new Date();
    const diffMs = now - date;
    const diffMins = Math.floor(diffMs / 60000);
    const diffHours = Math.floor(diffMs / 3600000);
    const diffDays = Math.floor(diffMs / 86400000);

    if (diffMins < 1) return 'just now';
    if (diffMins < 60) return `${diffMins} min ago`;
    if (diffHours < 24) return `${diffHours} hr${diffHours > 1 ? 's' : ''} ago`;
    return `${diffDays}d ago`;
  };

  if (loading) {
    return <div style={{ padding: '40px', color: '#8884a0' }}>Loading sections...</div>;
  }

  return (
    <div style={{ 
      padding: '28px 28px 28px 16px',
      width: '100%',
      boxSizing: 'border-box',
      background: '#0c1220',
      minHeight: '100%'
    }}>
      {/* Top Bar */}
      <div style={{ display: 'flex', justifyContent: 'space-between', alignItems: 'flex-start', marginBottom: '28px', gap: '16px' }}>
        <div>
          <div style={{ fontSize: '17px', fontWeight: 700, color: '#e8e6f0', marginBottom: '2px' }}>
            My Sections
          </div>
          <div style={{ fontSize: '11px', color: '#8884a0' }}>
            AY 2025–2026 · {sections.length} active sections · {getTotalStudents()} total students
          </div>
        </div>
        <button 
          onClick={() => setShowForm(!showForm)}
          style={{
            padding: '8px 16px',
            background: '#85D2D0',
            border: 'none',
            borderRadius: '8px',
            color: '#0f0f1a',
            fontWeight: 600,
            cursor: 'pointer',
            fontSize: '12px',
            transition: 'all 0.15s'
          }}
          onMouseEnter={(e) => e.target.style.opacity = '0.9'}
          onMouseLeave={(e) => e.target.style.opacity = '1'}
        >
          + New Section
        </button>
      </div>

      {/* Create Form */}
      {showForm && (
        <form onSubmit={handleSubmit} style={{
          background: '#1a1a2e',
          border: '1px solid #2e2e4a',
          borderRadius: '12px',
          padding: '20px',
          marginBottom: '28px'
        }}>
          <div style={{ display: 'grid', gridTemplateColumns: 'repeat(auto-fit, minmax(200px, 1fr))', gap: '16px', marginBottom: '16px' }}>
            <div>
              <label style={{ display: 'block', fontSize: '12px', fontWeight: 600, color: '#8884a0', marginBottom: '6px' }}>
                Section Name
              </label>
              <input 
                type="text"
                required 
                value={formData.name}
                onChange={(e) => setFormData({ ...formData, name: e.target.value })}
                placeholder="e.g., CS101 - Section A"
                style={{
                  width: '100%',
                  padding: '8px 12px',
                  background: '#0f0f1a',
                  border: '1px solid #2e2e4a',
                  borderRadius: '8px',
                  color: '#e8e6f0',
                  fontSize: '12px',
                  boxSizing: 'border-box'
                }}
              />
            </div>
            <div>
              <label style={{ display: 'block', fontSize: '12px', fontWeight: 600, color: '#8884a0', marginBottom: '6px' }}>
                Course Code
              </label>
              <input 
                type="text"
                required 
                value={formData.course_code}
                onChange={(e) => setFormData({ ...formData, course_code: e.target.value })}
                placeholder="e.g., CS101"
                style={{
                  width: '100%',
                  padding: '8px 12px',
                  background: '#0f0f1a',
                  border: '1px solid #2e2e4a',
                  borderRadius: '8px',
                  color: '#e8e6f0',
                  fontSize: '12px',
                  boxSizing: 'border-box'
                }}
              />
            </div>
            <div>
              <label style={{ display: 'block', fontSize: '12px', fontWeight: 600, color: '#8884a0', marginBottom: '6px' }}>
                School Year
              </label>
              <input 
                type="text"
                value={formData.school_year}
                onChange={(e) => setFormData({ ...formData, school_year: e.target.value })}
                placeholder="e.g., AY 2025-2026"
                style={{
                  width: '100%',
                  padding: '8px 12px',
                  background: '#0f0f1a',
                  border: '1px solid #2e2e4a',
                  borderRadius: '8px',
                  color: '#e8e6f0',
                  fontSize: '12px',
                  boxSizing: 'border-box'
                }}
              />
            </div>
            <div>
              <label style={{ display: 'block', fontSize: '12px', fontWeight: 600, color: '#8884a0', marginBottom: '6px' }}>
                Semester
              </label>
              <select 
                value={formData.semester}
                onChange={(e) => setFormData({ ...formData, semester: e.target.value })}
                style={{
                  width: '100%',
                  padding: '8px 12px',
                  background: '#0f0f1a',
                  border: '1px solid #2e2e4a',
                  borderRadius: '8px',
                  color: '#e8e6f0',
                  fontSize: '12px',
                  boxSizing: 'border-box'
                }}
              >
                <option value="Sem 1">Sem 1</option>
                <option value="Sem 2">Sem 2</option>
                <option value="Summer">Summer</option>
              </select>
            </div>
          </div>
          <div style={{ display: 'flex', gap: '8px' }}>
            <button 
              type="submit"
              style={{
                padding: '8px 16px',
                background: '#85D2D0',
                border: 'none',
                borderRadius: '8px',
                color: '#0f0f1a',
                fontWeight: 600,
                cursor: 'pointer',
                fontSize: '12px'
              }}
            >
              Create Section
            </button>
            <button 
              type="button"
              onClick={() => setShowForm(false)}
              style={{
                padding: '8px 16px',
                background: '#2e2e4a',
                border: 'none',
                borderRadius: '8px',
                color: '#8884a0',
                fontWeight: 600,
                cursor: 'pointer',
                fontSize: '12px'
              }}
            >
              Cancel
            </button>
          </div>
        </form>
      )}

      {/* Sections Grid */}
      <div style={{ display: 'grid', gridTemplateColumns: 'repeat(3, 1fr)', gap: '18px', marginBottom: '28px' }}>
        {sections.map(section => {
          const bannerGradients = [
            'linear-gradient(135deg, #1e3a5f, #2d5a8e)',
            'linear-gradient(135deg, #3a1e5f, #6b2d8e)',
            'linear-gradient(135deg, #1e4a3a, #2d8e6b)',
            'linear-gradient(135deg, #4a3a1e, #8e6b2d)'
          ];
          const gradientIndex = (section.id || 0) % bannerGradients.length;
          const avgCDS = section.avg_cds ? parseFloat(section.avg_cds) : null;
          const totalScores = section.difficulty_distribution ? 
            (section.difficulty_distribution.low + section.difficulty_distribution.moderate + section.difficulty_distribution.high) : 1;

          return (
            <Link
              key={section.id}
              to={`/instructor/sections/${section.id}`}
              style={{ textDecoration: 'none' }}
            >
              <div style={{
                background: '#131d30',
                border: '1px solid #1e304d',
                borderRadius: '16px',
                overflow: 'hidden',
                cursor: 'pointer',
                transition: 'all 0.2s',
                display: 'flex',
                flexDirection: 'column',
                height: '100%'
              }}
              onMouseEnter={(e) => {
                e.currentTarget.style.borderColor = '#85D2D0';
                e.currentTarget.style.transform = 'translateY(-2px)';
                e.currentTarget.style.boxShadow = '0 8px 24px rgba(0,0,0,0.3)';
              }}
              onMouseLeave={(e) => {
                e.currentTarget.style.borderColor = '#2e2e4a';
                e.currentTarget.style.transform = 'translateY(0)';
                e.currentTarget.style.boxShadow = 'none';
              }}
              >
                {/* Banner */}
                <div style={{
                  background: bannerGradients[gradientIndex],
                  height: '80px',
                  position: 'relative',
                  display: 'flex',
                  alignItems: 'flex-end',
                  padding: '14px 18px',
                  backgroundImage: 'repeating-linear-gradient(45deg, transparent, transparent 10px, rgba(255,255,255,0.05) 10px, rgba(255,255,255,0.05) 20px)'
                }}>
                  <div>
                    <div style={{ fontFamily: "'Space Mono', monospace", fontSize: '18px', fontWeight: 700, color: 'white', lineHeight: 1.2 }}>
                      {section.course_code}
                    </div>
                    <div style={{ fontSize: '11px', color: 'rgba(255,255,255,0.7)', marginTop: '2px' }}>
                      {section.name}
                    </div>
                  </div>
                </div>

                {/* Card Body */}
                <div style={{ padding: '16px 18px', flex: 1, display: 'flex', flexDirection: 'column' }}>
                  <div style={{ fontSize: '10px', color: '#8884a0', marginBottom: '12px', fontWeight: 500 }}>
                    {section.school_year || 'AY 2025–2026'} · {section.semester || 'Sem 1'}
                  </div>

                  {/* Stats */}
                  <div style={{ display: 'flex', gap: '16px', marginBottom: '14px' }}>
                    <div style={{ textAlign: 'center' }}>
                      <div style={{ fontFamily: "'Space Mono', monospace", fontSize: '17px', fontWeight: 700, color: '#e8e6f0' }}>
                        {section.student_count || 0}
                      </div>
                      <div style={{ fontSize: '9px', textTransform: 'uppercase', letterSpacing: '1px', color: '#8884a0', marginTop: '2px' }}>
                        Students
                      </div>
                    </div>
                    <div style={{ width: '1px', background: '#2e2e4a', alignSelf: 'stretch' }}></div>
                    <div style={{ textAlign: 'center' }}>
                      <div style={{ fontFamily: "'Space Mono', monospace", fontSize: '17px', fontWeight: 700, color: '#e8e6f0' }}>
                        {section.concept_count || 0}
                      </div>
                      <div style={{ fontSize: '9px', textTransform: 'uppercase', letterSpacing: '1px', color: '#8884a0', marginTop: '2px' }}>
                        Concepts
                      </div>
                    </div>
                    <div style={{ width: '1px', background: '#2e2e4a', alignSelf: 'stretch' }}></div>
                    <div style={{ textAlign: 'center' }}>
                      <div style={{ fontFamily: "'Space Mono', monospace", fontSize: '17px', fontWeight: 700, color: section.alert_count > 0 ? '#f87171' : '#e8e6f0' }}>
                        {section.alert_count || 0}
                      </div>
                      <div style={{ fontSize: '9px', textTransform: 'uppercase', letterSpacing: '1px', color: '#8884a0', marginTop: '2px' }}>
                        Alerts
                      </div>
                    </div>
                  </div>

                  {/* Difficulty Bar */}
                  <div style={{ marginBottom: '14px' }}>
                    <div style={{ fontSize: '10px', color: '#8884a0', marginBottom: '5px', display: 'flex', justifyContent: 'space-between' }}>
                      <span>Class Difficulty</span>
                      <span>Avg CDS: {formatCDS(avgCDS)}</span>
                    </div>
                    <div style={{ height: '6px', borderRadius: '4px', background: '#22223a', overflow: 'hidden', display: 'flex' }}>
                      {section.difficulty_distribution && totalScores > 0 ? (
                        <>
                          <div style={{
                            background: '#4ade80',
                            width: `${(section.difficulty_distribution.low / totalScores) * 100}%`,
                            height: '100%'
                          }}></div>
                          <div style={{
                            background: '#fbbf24',
                            width: `${(section.difficulty_distribution.moderate / totalScores) * 100}%`,
                            height: '100%'
                          }}></div>
                          <div style={{
                            background: '#f87171',
                            width: `${(section.difficulty_distribution.high / totalScores) * 100}%`,
                            height: '100%'
                          }}></div>
                        </>
                      ) : (
                        <div style={{ width: '100%', height: '100%', background: '#22223a' }}></div>
                      )}
                    </div>
                  </div>

                  {/* Footer */}
                  <div style={{ display: 'flex', alignItems: 'center', justifyContent: 'space-between', paddingTop: '12px', borderTop: '1px solid #2e2e4a', marginTop: 'auto' }}>
                    <div style={{ fontSize: '11px', color: '#8884a0' }}>
                      {section.exercise_count || 0} exercises assigned
                    </div>
                    <div style={{ fontSize: '11px', fontWeight: 600, color: section.alert_count > 0 ? '#f87171' : '#4ade80' }}>
                      {section.alert_count > 0 ? `⚠ ${section.alert_count} need intervention` : '✓ All on track'}
                    </div>
                  </div>
                </div>
              </div>
            </Link>
          );
        })}

        {/* New Section Card */}
        <button
          onClick={() => setShowForm(!showForm)}
          style={{
            background: 'transparent',
            border: '2px dashed #2e2e4a',
            borderRadius: '16px',
            cursor: 'pointer',
            transition: 'all 0.2s',
            display: 'flex',
            flexDirection: 'column',
            alignItems: 'center',
            justifyContent: 'center',
            minHeight: '220px',
            gap: '10px',
            padding: '20px'
          }}
          onMouseEnter={(e) => {
            e.currentTarget.style.borderColor = '#85D2D0';
            e.currentTarget.style.background = 'rgba(133,210,208,0.03)';
          }}
          onMouseLeave={(e) => {
            e.currentTarget.style.borderColor = '#2e2e4a';
            e.currentTarget.style.background = 'transparent';
          }}
        >
          <div style={{
            width: '40px',
            height: '40px',
            borderRadius: '50%',
            border: '2px dashed #8884a0',
            display: 'flex',
            alignItems: 'center',
            justifyContent: 'center',
            fontSize: '20px',
            color: '#8884a0',
            transition: 'all 0.2s'
          }}>
            +
          </div>
          <div style={{ fontSize: '12px', fontWeight: 600, color: '#8884a0', transition: 'all 0.2s' }}>
            Create New Section
          </div>
        </button>
      </div>

      {/* Recent Activity */}
      <div>
        <div style={{ fontSize: '13px', fontWeight: 700, color: '#e8e6f0', marginBottom: '14px' }}>
          Recent Activity — All Sections
        </div>
        <div style={{ background: '#1a1a2e', border: '1px solid #2e2e4a', borderRadius: '12px', overflow: 'hidden' }}>
          {activityData && activityData.length > 0 ? (
            activityData.map((activity, idx) => (
              <div key={idx} style={{ display: 'flex', alignItems: 'center', gap: '14px', padding: '12px 18px', borderBottom: idx < activityData.length - 1 ? '1px solid rgba(46,46,74,0.5)' : 'none' }}>
                <div style={{
                  width: '8px',
                  height: '8px',
                  borderRadius: '50%',
                  flexShrink: 0,
                  background: activity.difficulty === 'High' ? '#f87171' : activity.difficulty === 'Moderate' ? '#fbbf24' : '#4ade80'
                }}></div>
                <div style={{ fontSize: '12px', color: '#e8e6f0', flex: 1 }}>
                  <span style={{ color: '#85D2D0', fontWeight: 600 }}>{activity.student_name}</span>
                  {' triggered '} 
                  <span style={{ color: getDifficultyColor(parseFloat(activity.cds)) }}>
                    {activity.difficulty} difficulty
                  </span>
                  {' alert on '}
                  <span style={{ color: '#85D2D0', fontWeight: 600 }}>{activity.concept_name}</span>
                </div>
                <div style={{ fontSize: '10px', fontWeight: 600, padding: '2px 8px', borderRadius: '10px', background: '#22223a', color: '#8884a0', border: '1px solid #2e2e4a' }}>
                  {activity.exercise_title?.substring(0, 15)}...
                </div>
                <div style={{ fontSize: '10px', color: '#8884a0', whiteSpace: 'nowrap' }}>
                  {formatTime(activity.created_at)}
                </div>
              </div>
            ))
          ) : (
            <div style={{ padding: '20px', textAlign: 'center', color: '#8884a0', fontSize: '12px' }}>
              No recent activity
            </div>
          )}
        </div>
      </div>
    </div>
  );
}
