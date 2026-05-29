import { useState, useEffect } from 'react';
import { useParams, Link, useNavigate } from 'react-router-dom';
import api from '../../services/api';
import Layout from '../../components/Layout';

export default function SectionDetail() {
  const { sectionId } = useParams();
  const [section, setSection] = useState(null);
  const [students, setStudents] = useState([]);
  const [exercises, setExercises] = useState([]);
  const [heatmapData, setHeatmapData] = useState(null);
  const [alerts, setAlerts] = useState([]);
  const [loading, setLoading] = useState(true);
  const [activeTab, setActiveTab] = useState('overview');
  const [searchQuery, setSearchQuery] = useState('');
  const [showDeleteConfirm, setShowDeleteConfirm] = useState(false);
  const [selectedExercise, setSelectedExercise] = useState(null);
  const navigate = useNavigate();

  const CONCEPT_ORDER = ['Datatypes','Variables','Conditionals','Loops','Functions','Arrays','OOP'];

  useEffect(() => {
    fetchSectionData();
  }, [sectionId]);

  const fetchSectionData = async () => {
    try {
      const [secRes, studRes, exRes, heatRes, alertRes] = await Promise.all([
        api.get(`/api/sections/${sectionId}`),
        api.get(`/api/sections/${sectionId}/students-with-scores`),
        api.get(`/api/sections/${sectionId}/exercises`),
        api.get(`/api/analytics/heatmap/${sectionId}`),
        api.get(`/api/analytics/alerts/${sectionId}`)
      ]);
      setSection(secRes.data);
      setStudents(studRes.data || []);
      setExercises(exRes.data || []);
      setHeatmapData(heatRes.data);
      setAlerts(alertRes.data || []);
    } catch (err) {
      console.error('Error fetching section data:', err);
    } finally {
      setLoading(false);
    }
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

  const getTotalAlerts = () => alerts.length;

  const getCompletionPercentage = () => {
    if (!exercises.length) return 0;
    const totalPossible = exercises.reduce((sum, ex) => sum + (ex.submitted_count || 0), 0);
    const totalNeeded = exercises.reduce((sum, ex) => sum + ex.total_students, 0);
    return totalNeeded > 0 ? Math.round((totalPossible / totalNeeded) * 100) : 0;
  };

  const getAvgCDS = () => {
    if (!heatmapData?.scores) return 0;
    const allScores = [];
    for (const student in heatmapData.scores) {
      for (const concept in heatmapData.scores[student]) {
        const score = heatmapData.scores[student][concept];
        if (score?.cds) {
          const cds = typeof score.cds === 'string' ? parseFloat(score.cds) : score.cds;
          if (!isNaN(cds)) allScores.push(cds);
        }
      }
    }
    if (allScores.length === 0) return 0;
    return (allScores.reduce((a, b) => a + b, 0) / allScores.length).toFixed(2);
  };

  const filteredStudents = students.filter(s =>
    s.name.toLowerCase().includes(searchQuery.toLowerCase()) ||
    s.email.toLowerCase().includes(searchQuery.toLowerCase())
  );

  const handleEditExercise = (exercise) => {
    navigate(`/instructor/exercises/${exercise.id}/edit`);
  };

  const handleDeleteExercise = async (exercise) => {
    if (showDeleteConfirm && selectedExercise?.id === exercise.id) {
      try {
        await api.delete(`/api/exercises/${exercise.id}`);
        setExercises(exercises.filter(e => e.id !== exercise.id));
        setShowDeleteConfirm(false);
        setSelectedExercise(null);
      } catch (err) {
        console.error(err);
        alert('Failed to delete exercise');
      }
    } else {
      setShowDeleteConfirm(true);
      setSelectedExercise(exercise);
    }
  };

  const handleToggleExerciseStatus = async (exercise) => {
    try {
      const endpoint = exercise.closed_at ? 'reopen' : 'close';
      const res = await api.post(`/api/exercises/${exercise.id}/${endpoint}`, {});
      setExercises(exercises.map(e =>
        e.id === exercise.id ? { ...e, closed_at: res.data.exercise?.closed_at || null } : e
      ));
    } catch (err) {
      console.error(err);
      alert('Failed to update exercise status');
    }
  };

  if (loading) {
    return (
      <Layout>
        <div style={{ padding: '40px', textAlign: 'center', color: '#8884a0' }}>
          Loading section details...
        </div>
      </Layout>
    );
  }

  if (!section) {
    return (
      <Layout>
        <div style={{ padding: '40px', textAlign: 'center', color: '#8884a0' }}>
          Section not found
        </div>
      </Layout>
    );
  }

  return (
    <Layout>
      <div style={{ display: 'flex', flexDirection: 'column', height: '100vh', overflow: 'hidden' }}>
        {/* Section Banner */}
        <div style={{
          background: 'linear-gradient(135deg, #1e3a5f, #2d5a8e)',
          borderBottom: '1px solid rgba(255,255,255,0.1)',
          padding: '18px 28px',
          flexShrink: 0,
          position: 'relative',
          overflow: 'hidden',
          backgroundImage: 'repeating-linear-gradient(45deg, transparent, transparent 15px, rgba(255,255,255,0.03) 15px, rgba(255,255,255,0.03) 30px)'
        }}>
          <div style={{ fontSize: '11px', color: 'rgba(255,255,255,0.5)', marginBottom: '6px' }}>
            My Sections <span style={{ color: 'rgba(255,255,255,0.7)' }}>› {section.course_code}</span>
          </div>
          <div style={{ fontSize: '20px', fontWeight: 700, color: 'white', marginBottom: '8px' }}>
            {section.course_code} — {section.name}
          </div>
          <div style={{ display: 'flex', gap: '16px', fontSize: '11px', color: 'rgba(255,255,255,0.65)' }}>
            <span>👥 {section.student_count || students.length} students enrolled</span>
            <span>📚 {exercises.length} exercises assigned</span>
            <span>📅 {section.school_year || 'AY 2025–2026'} · Sem 2</span>
          </div>
          <div style={{ position: 'absolute', right: '28px', top: '50%', transform: 'translateY(-50%)', display: 'flex', gap: '10px' }}>
            <button style={{ padding: '7px 14px', borderRadius: '8px', fontSize: '12px', fontWeight: 600, cursor: 'pointer', border: 'none', background: 'rgba(255,255,255,0.15)', color: 'white', fontFamily: 'DM Sans, sans-serif' }}>
              + Enroll Students
            </button>
            <Link to="/instructor/create-exercise" style={{ padding: '7px 14px', borderRadius: '8px', fontSize: '12px', fontWeight: 600, cursor: 'pointer', border: 'none', background: '#85D2D0', color: '#0f1a1a', fontFamily: 'DM Sans, sans-serif', textDecoration: 'none', display: 'inline-block' }}>
              + Assign Exercise
            </Link>
          </div>
        </div>

        {/* Tabs */}
        <div style={{ background: '#1a1a2e', borderBottom: '1px solid #2e2e4a', display: 'flex', padding: '0 28px', flexShrink: 0, overflowX: 'auto' }}>
          {['overview', 'students', 'exercises', 'heatmap'].map(tab => (
            <button
              key={tab}
              onClick={() => setActiveTab(tab)}
              style={{
                padding: '12px 18px',
                fontSize: '12px',
                fontWeight: 600,
                color: activeTab === tab ? '#85D2D0' : '#8884a0',
                cursor: 'pointer',
                border: 'none',
                background: 'transparent',
                borderBottom: activeTab === tab ? '2px solid #85D2D0' : '2px solid transparent',
                transition: 'all 0.15s',
                fontFamily: 'DM Sans, sans-serif'
              }}
            >
              {tab.charAt(0).toUpperCase() + tab.slice(1)}
            </button>
          ))}
        </div>

        {/* Content */}
        <div style={{ padding: '22px 28px', overflowY: 'auto', flex: 1 }}>
          {activeTab === 'overview' && (
            <>
              {/* Stats */}
              <div style={{ display: 'grid', gridTemplateColumns: 'repeat(4, 1fr)', gap: '14px', marginBottom: '22px' }}>
                <div style={{ background: '#1a1a2e', border: '1px solid #2e2e4a', borderRadius: '12px', padding: '14px 16px' }}>
                  <div style={{ fontSize: '10px', fontWeight: 600, letterSpacing: '1.2px', textTransform: 'uppercase', color: '#8884a0', marginBottom: '6px' }}>
                    Enrolled
                  </div>
                  <div style={{ fontFamily: "'Space Mono', monospace", fontSize: '24px', fontWeight: 700, color: '#85D2D0' }}>
                    {section.student_count || students.length}
                  </div>
                  <div style={{ fontSize: '10px', color: '#8884a0', marginTop: '3px' }}>
                    Students in section
                  </div>
                </div>
                <div style={{ background: '#1a1a2e', border: '1px solid #2e2e4a', borderRadius: '12px', padding: '14px 16px' }}>
                  <div style={{ fontSize: '10px', fontWeight: 600, letterSpacing: '1.2px', textTransform: 'uppercase', color: '#8884a0', marginBottom: '6px' }}>
                    Avg CDS
                  </div>
                  <div style={{ fontFamily: "'Space Mono', monospace", fontSize: '24px', fontWeight: 700, color: '#fbbf24' }}>
                    {getAvgCDS()}
                  </div>
                  <div style={{ fontSize: '10px', color: '#8884a0', marginTop: '3px' }}>
                    Moderate difficulty
                  </div>
                </div>
                <div style={{ background: '#1a1a2e', border: '1px solid #2e2e4a', borderRadius: '12px', padding: '14px 16px' }}>
                  <div style={{ fontSize: '10px', fontWeight: 600, letterSpacing: '1.2px', textTransform: 'uppercase', color: '#8884a0', marginBottom: '6px' }}>
                    High Alerts
                  </div>
                  <div style={{ fontFamily: "'Space Mono', monospace", fontSize: '24px', fontWeight: 700, color: '#f87171' }}>
                    {getTotalAlerts()}
                  </div>
                  <div style={{ fontSize: '10px', color: '#8884a0', marginTop: '3px' }}>
                    Need intervention
                  </div>
                </div>
                <div style={{ background: '#1a1a2e', border: '1px solid #2e2e4a', borderRadius: '12px', padding: '14px 16px' }}>
                  <div style={{ fontSize: '10px', fontWeight: 600, letterSpacing: '1.2px', textTransform: 'uppercase', color: '#8884a0', marginBottom: '6px' }}>
                    Completion
                  </div>
                  <div style={{ fontFamily: "'Space Mono', monospace", fontSize: '24px', fontWeight: 700, color: '#4ade80' }}>
                    {getCompletionPercentage()}%
                  </div>
                  <div style={{ fontSize: '10px', color: '#8884a0', marginTop: '3px' }}>
                    Exercises submitted
                  </div>
                </div>
              </div>

              {/* Two Column Layout */}
              <div style={{ display: 'grid', gridTemplateColumns: '1fr 1fr', gap: '16px' }}>
                {/* Students Table */}
                <div style={{ background: '#1a1a2e', border: '1px solid #2e2e4a', borderRadius: '12px', overflow: 'hidden', display: 'flex', flexDirection: 'column' }}>
                  <div style={{ padding: '12px 16px', borderBottom: '1px solid #2e2e4a', display: 'flex', alignItems: 'center', justifyContent: 'space-between', background: '#22223a' }}>
                    <div style={{ fontSize: '12px', fontWeight: 700 }}>Students — Section</div>
                    <input
                      type="text"
                      placeholder="🔍 Search..."
                      value={searchQuery}
                      onChange={(e) => setSearchQuery(e.target.value)}
                      style={{
                        background: '#0f0f1a',
                        border: '1px solid #2e2e4a',
                        borderRadius: '6px',
                        padding: '5px 10px',
                        fontSize: '11px',
                        color: '#e8e6f0',
                        fontFamily: 'DM Sans, sans-serif',
                        outline: 'none',
                        width: '150px'
                      }}
                    />
                  </div>
                  <div style={{ overflowY: 'auto', flex: 1 }}>
                    <table style={{ width: '100%', borderCollapse: 'collapse', fontSize: '12px' }}>
                      <thead>
                        <tr style={{ background: '#22223a' }}>
                          <th style={{ padding: '9px 14px', fontSize: '9px', fontWeight: 700, letterSpacing: '1.2px', textTransform: 'uppercase', color: '#8884a0', textAlign: 'left', borderBottom: '1px solid #2e2e4a' }}>Student</th>
                          <th style={{ padding: '9px 14px', fontSize: '9px', fontWeight: 700, letterSpacing: '1.2px', textTransform: 'uppercase', color: '#8884a0', textAlign: 'center', borderBottom: '1px solid #2e2e4a' }}>Latest CDS</th>
                          <th style={{ padding: '9px 14px', fontSize: '9px', fontWeight: 700, letterSpacing: '1.2px', textTransform: 'uppercase', color: '#8884a0', textAlign: 'center', borderBottom: '1px solid #2e2e4a' }}>Submitted</th>
                        </tr>
                      </thead>
                      <tbody>
                        {filteredStudents.map(student => {
                          const difficulty = getDifficulty(student.latest_cds);
                          const pillarColors = {
                            low: { background: 'rgba(74,222,128,0.1)', color: '#4ade80', border: '1px solid rgba(74,222,128,0.2)' },
                            moderate: { background: 'rgba(251,191,36,0.1)', color: '#fbbf24', border: '1px solid rgba(251,191,36,0.2)' },
                            high: { background: 'rgba(248,113,113,0.12)', color: '#f87171', border: '1px solid rgba(248,113,113,0.25)' }
                          };
                          const pillStyle = difficulty === 'unscored' ? 
                            { background: 'rgba(74,74,106,0.3)', color: '#8884a0', border: '1px solid #2e2e4a' } : 
                            pillarColors[difficulty];

                          return (
                            <tr key={student.id} style={{ borderBottom: '1px solid rgba(46,46,74,0.4)' }}>
                              <td style={{ padding: '9px 14px' }}>
                                <div style={{ fontWeight: 600, color: '#e8e6f0', fontSize: '12px' }}>{student.name}</div>
                                <div style={{ fontSize: '10px', color: '#8884a0' }}>{student.email}</div>
                              </td>
                              <td style={{ padding: '9px 14px', textAlign: 'center' }}>
                                <div style={{
                                  display: 'inline-flex',
                                  alignItems: 'center',
                                  padding: '3px 8px',
                                  borderRadius: '8px',
                                  fontSize: '10px',
                                  fontWeight: 700,
                                  fontFamily: "'Space Mono', monospace",
                                  ...pillStyle
                                }}>
                                  {formatCDS(student.latest_cds)} {difficulty !== 'unscored' && difficulty.charAt(0).toUpperCase() + difficulty.slice(1)}
                                </div>
                              </td>
                              <td style={{ padding: '9px 14px', textAlign: 'center', fontSize: '11px', color: '#8884a0' }}>
                                {student.submitted_count || 0}/{student.total_exercises || 0}
                              </td>
                            </tr>
                          );
                        })}
                      </tbody>
                    </table>
                  </div>
                </div>

                {/* Exercises Panel */}
                <div style={{ display: 'flex', flexDirection: 'column', gap: '10px' }}>
                  <div style={{ fontSize: '13px', fontWeight: 700 }}>Assigned Exercises</div>
                  <div style={{ overflowY: 'auto', flex: 1, display: 'flex', flexDirection: 'column', gap: '10px' }}>
                    {exercises.map(exercise => {
                      const totalScores = (exercise.low_count || 0) + (exercise.moderate_count || 0) + (exercise.high_count || 0);
                      const avgCdsNum = exercise.avg_cds ? parseFloat(exercise.avg_cds) : null;
                      const difficulty = getDifficulty(avgCdsNum);
                      const isHighAvg = avgCdsNum && avgCdsNum > 0.66;

                      return (
                        <div key={exercise.id} style={{
                          background: '#1a1a2e',
                          border: isHighAvg ? '1px solid rgba(248,113,113,0.3)' : '1px solid #2e2e4a',
                          borderRadius: '10px',
                          padding: '14px 16px'
                        }}>
                          <div style={{ display: 'flex', alignItems: 'flex-start', justifyContent: 'space-between', marginBottom: '8px' }}>
                            <div style={{ fontSize: '12px', fontWeight: 700, color: '#e8e6f0' }}>
                              {exercise.title}
                            </div>
                            <div style={{
                              fontSize: '9px',
                              fontWeight: 700,
                              letterSpacing: '0.8px',
                              textTransform: 'uppercase',
                              padding: '3px 8px',
                              borderRadius: '8px',
                              background: 'rgba(133,210,208,0.1)',
                              color: '#85D2D0',
                              border: '1px solid rgba(133,210,208,0.2)'
                            }}>
                              {exercise.concept_name}
                            </div>
                          </div>
                          <div style={{ display: 'flex', gap: '16px', marginBottom: '8px' }}>
                            <div style={{ fontSize: '10px', color: '#8884a0' }}>
                              Submitted: <strong style={{ color: '#e8e6f0' }}>{exercise.submitted_count || 0}/{exercise.total_students}</strong>
                            </div>
                            <div style={{ fontSize: '10px', color: '#8884a0' }}>
                              Avg CDS: <strong style={{ color: isHighAvg ? '#f87171' : difficulty === 'moderate' ? '#fbbf24' : '#4ade80' }}>
                                {formatCDS(avgCdsNum)}
                              </strong>
                            </div>
                          </div>
                          <div style={{ marginTop: '8px' }}>
                            <div style={{ display: 'flex', justifyContent: 'space-between', fontSize: '9px', color: '#8884a0', marginBottom: '4px' }}>
                              <span>Distribution</span>
                              <span style={{ color: isHighAvg ? '#f87171' : difficulty === 'moderate' ? '#fbbf24' : '#4ade80' }}>
                                {isHighAvg ? '⚠ High avg — intervention recommended' : difficulty.charAt(0).toUpperCase() + difficulty.slice(1)}
                              </span>
                            </div>
                            <div style={{ height: '5px', background: '#22223a', borderRadius: '3px', display: 'flex', overflow: 'hidden' }}>
                              {totalScores > 0 && (
                                <>
                                  <div style={{
                                    background: '#4ade80',
                                    width: `${(exercise.low_count || 0) / totalScores * 100}%`,
                                    height: '100%'
                                  }}></div>
                                  <div style={{
                                    background: '#fbbf24',
                                    width: `${(exercise.moderate_count || 0) / totalScores * 100}%`,
                                    height: '100%'
                                  }}></div>
                                  <div style={{
                                    background: '#f87171',
                                    width: `${(exercise.high_count || 0) / totalScores * 100}%`,
                                    height: '100%'
                                  }}></div>
                                </>
                              )}
                            </div>
                          </div>
                        </div>
                      );
                    })}
                  </div>
                </div>
              </div>
            </>
          )}

          {activeTab === 'students' && (
            <div style={{ background: '#1a1a2e', border: '1px solid #2e2e4a', borderRadius: '12px', overflow: 'hidden' }}>
              <div style={{ padding: '12px 16px', borderBottom: '1px solid #2e2e4a', background: '#22223a' }}>
                <div style={{ fontSize: '12px', fontWeight: 700 }}>All Students</div>
              </div>
              <div style={{ overflowX: 'auto' }}>
                <table style={{ width: '100%', borderCollapse: 'collapse' }}>
                  <thead>
                    <tr style={{ background: '#22223a' }}>
                      <th style={{ padding: '9px 14px', fontSize: '9px', fontWeight: 700, letterSpacing: '1.2px', textTransform: 'uppercase', color: '#8884a0', textAlign: 'left', borderBottom: '1px solid #2e2e4a' }}>Name</th>
                      <th style={{ padding: '9px 14px', fontSize: '9px', fontWeight: 700, letterSpacing: '1.2px', textTransform: 'uppercase', color: '#8884a0', textAlign: 'left', borderBottom: '1px solid #2e2e4a' }}>Email</th>
                      <th style={{ padding: '9px 14px', fontSize: '9px', fontWeight: 700, letterSpacing: '1.2px', textTransform: 'uppercase', color: '#8884a0', textAlign: 'center', borderBottom: '1px solid #2e2e4a' }}>Latest CDS</th>
                      <th style={{ padding: '9px 14px', fontSize: '9px', fontWeight: 700, letterSpacing: '1.2px', textTransform: 'uppercase', color: '#8884a0', textAlign: 'center', borderBottom: '1px solid #2e2e4a' }}>Submissions</th>
                    </tr>
                  </thead>
                  <tbody>
                    {students.map(student => {
                      const difficulty = getDifficulty(student.latest_cds);
                      const pillarColors = {
                        low: { background: 'rgba(74,222,128,0.1)', color: '#4ade80', border: '1px solid rgba(74,222,128,0.2)' },
                        moderate: { background: 'rgba(251,191,36,0.1)', color: '#fbbf24', border: '1px solid rgba(251,191,36,0.2)' },
                        high: { background: 'rgba(248,113,113,0.12)', color: '#f87171', border: '1px solid rgba(248,113,113,0.25)' }
                      };
                      const pillStyle = difficulty === 'unscored' ?
                        { background: 'rgba(74,74,106,0.3)', color: '#8884a0', border: '1px solid #2e2e4a' } :
                        pillarColors[difficulty];

                      return (
                        <tr key={student.id} style={{ borderBottom: '1px solid rgba(46,46,74,0.4)' }}>
                          <td style={{ padding: '9px 14px', fontSize: '12px', fontWeight: 600, color: '#e8e6f0' }}>{student.name}</td>
                          <td style={{ padding: '9px 14px', fontSize: '12px', color: '#8884a0' }}>{student.email}</td>
                          <td style={{ padding: '9px 14px', textAlign: 'center' }}>
                            <div style={{
                              display: 'inline-flex',
                              alignItems: 'center',
                              padding: '3px 8px',
                              borderRadius: '8px',
                              fontSize: '10px',
                              fontWeight: 700,
                              fontFamily: "'Space Mono', monospace",
                              ...pillStyle
                            }}>
                              {formatCDS(student.latest_cds)}
                            </div>
                          </td>
                          <td style={{ padding: '9px 14px', textAlign: 'center', fontSize: '11px', color: '#8884a0' }}>
                            {student.submitted_count || 0}/{student.total_exercises || 0}
                          </td>
                        </tr>
                      );
                    })}
                  </tbody>
                </table>
              </div>
            </div>
          )}

          {activeTab === 'exercises' && (
            <div style={{ display: 'flex', flexDirection: 'column', gap: '12px' }}>
              {exercises.map(exercise => {
                const totalScores = (exercise.low_count || 0) + (exercise.moderate_count || 0) + (exercise.high_count || 0);
                const avgCdsNum = exercise.avg_cds ? parseFloat(exercise.avg_cds) : null;
                const difficulty = getDifficulty(avgCdsNum);
                const isHighAvg = avgCdsNum && avgCdsNum > 0.66;

                return (
                  <div key={exercise.id} style={{
                    background: '#1a1a2e',
                    border: isHighAvg ? '1px solid rgba(248,113,113,0.3)' : '1px solid #2e2e4a',
                    borderRadius: '10px',
                    padding: '14px 16px'
                  }}>
                    <div style={{ display: 'flex', alignItems: 'flex-start', justifyContent: 'space-between', marginBottom: '8px' }}>
                      <div>
                        <div style={{ fontSize: '12px', fontWeight: 700, color: '#e8e6f0', marginBottom: '4px' }}>
                          {exercise.title}
                        </div>
                        <div style={{ fontSize: '11px', color: '#8884a0' }}>
                          {exercise.description?.substring(0, 100)}...
                        </div>
                      </div>
                      <div style={{
                        fontSize: '9px',
                        fontWeight: 700,
                        letterSpacing: '0.8px',
                        textTransform: 'uppercase',
                        padding: '3px 8px',
                        borderRadius: '8px',
                        background: 'rgba(133,210,208,0.1)',
                        color: '#85D2D0',
                        border: '1px solid rgba(133,210,208,0.2)',
                        whiteSpace: 'nowrap'
                      }}>
                        {exercise.concept_name}
                      </div>
                    </div>
                    <div style={{ display: 'flex', gap: '24px', marginBottom: '12px', fontSize: '11px', color: '#8884a0' }}>
                      <div>
                        Submitted: <strong style={{ color: '#e8e6f0' }}>{exercise.submitted_count || 0}/{exercise.total_students}</strong>
                      </div>
                      <div>
                        Avg CDS: <strong style={{ color: isHighAvg ? '#f87171' : difficulty === 'moderate' ? '#fbbf24' : '#4ade80' }}>
                          {formatCDS(avgCdsNum)}
                        </strong>
                      </div>
                      <div>
                        Status: <strong style={{ color: exercise.closed_at ? '#85D2D0' : '#8884a0' }}>
                          {exercise.closed_at ? 'Closed' : 'Active'}
                        </strong>
                      </div>
                    </div>
                    <div>
                      <div style={{ display: 'flex', justifyContent: 'space-between', fontSize: '9px', color: '#8884a0', marginBottom: '4px' }}>
                        <span>Difficulty Distribution</span>
                        <span style={{ color: isHighAvg ? '#f87171' : '#8884a0' }}>
                          Low {exercise.low_count || 0} · Mod {exercise.moderate_count || 0} · High {exercise.high_count || 0}
                        </span>
                      </div>
                      <div style={{ height: '5px', background: '#22223a', borderRadius: '3px', display: 'flex', overflow: 'hidden' }}>
                        {totalScores > 0 && (
                          <>
                            <div style={{
                              background: '#4ade80',
                              width: `${(exercise.low_count || 0) / totalScores * 100}%`,
                              height: '100%'
                            }}></div>
                            <div style={{
                              background: '#fbbf24',
                              width: `${(exercise.moderate_count || 0) / totalScores * 100}%`,
                              height: '100%'
                            }}></div>
                            <div style={{
                              background: '#f87171',
                              width: `${(exercise.high_count || 0) / totalScores * 100}%`,
                              height: '100%'
                            }}></div>
                          </>
                        )}
                      </div>
                    </div>
                    <div style={{ display: 'flex', gap: '8px', marginTop: '12px', paddingTop: '12px', borderTop: '1px solid #2e2e4a' }} className="exercise-actions">
                      <button
                        onClick={() => handleEditExercise(exercise)}
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
                        ✎ Edit
                      </button>
                      <button
                        onClick={() => handleToggleExerciseStatus(exercise)}
                        style={{
                          padding: '6px 12px',
                          fontSize: '11px',
                          fontWeight: 600,
                          border: 'none',
                          background: 'transparent',
                          color: exercise.closed_at ? '#4ade80' : '#f87171',
                          cursor: 'pointer',
                          borderRadius: '4px',
                          fontFamily: 'DM Sans, sans-serif',
                          transition: 'all 0.15s'
                        }}
                      >
                        {exercise.closed_at ? '↻ Reopen' : '⊗ Close'}
                      </button>
                      <button
                        onClick={() => handleDeleteExercise(exercise)}
                        style={{
                          padding: '6px 12px',
                          fontSize: '11px',
                          fontWeight: 600,
                          border: 'none',
                          background: showDeleteConfirm && selectedExercise?.id === exercise.id ? '#f87171' : 'transparent',
                          color: showDeleteConfirm && selectedExercise?.id === exercise.id ? '#fff' : '#f87171',
                          cursor: 'pointer',
                          borderRadius: '4px',
                          fontFamily: 'DM Sans, sans-serif',
                          transition: 'all 0.15s'
                        }}
                      >
                        {showDeleteConfirm && selectedExercise?.id === exercise.id ? '⚠ Confirm Delete' : '🗑 Delete'}
                      </button>
                    </div>
                  </div>
                );
              })}
            </div>
          )}

          {showDeleteConfirm && selectedExercise && (
            <div style={{
              position: 'fixed',
              top: 0,
              left: 0,
              right: 0,
              bottom: 0,
              background: 'rgba(0,0,0,0.7)',
              display: 'flex',
              alignItems: 'center',
              justifyContent: 'center',
              zIndex: 1000
            }}>
              <div style={{
                background: '#1a1a2e',
                border: '2px solid #f87171',
                borderRadius: '12px',
                padding: '28px',
                maxWidth: '420px',
                boxShadow: '0 20px 60px rgba(0,0,0,0.5)'
              }}>
                <div style={{ fontSize: '14px', fontWeight: 700, color: '#f87171', marginBottom: '12px' }}>
                  ⚠ Delete Exercise
                </div>
                <p style={{ color: '#8884a0', marginBottom: '16px', lineHeight: '1.5' }}>
                  Are you sure you want to delete <strong style={{ color: '#e8e6f0' }}>"{selectedExercise.title}"</strong>?
                </p>
                <p style={{ color: '#8884a0', fontSize: '11px', marginBottom: '20px', fontStyle: 'italic' }}>
                  This will permanently remove the exercise and all related student submissions. This action cannot be undone.
                </p>
                <div style={{ display: 'flex', gap: '12px' }}>
                  <button
                    onClick={() => { setShowDeleteConfirm(false); setSelectedExercise(null); }}
                    style={{
                      flex: 1,
                      padding: '8px 16px',
                      background: '#2e2e4a',
                      color: '#e8e6f0',
                      border: '1px solid #3e3e5a',
                      borderRadius: '6px',
                      cursor: 'pointer',
                      fontWeight: 600,
                      fontSize: '12px',
                      fontFamily: 'DM Sans, sans-serif',
                      transition: 'all 0.15s'
                    }}
                  >
                    Cancel
                  </button>
                  <button
                    onClick={() => handleDeleteExercise(selectedExercise)}
                    style={{
                      flex: 1,
                      padding: '8px 16px',
                      background: '#f87171',
                      color: '#0f1a1a',
                      border: 'none',
                      borderRadius: '6px',
                      cursor: 'pointer',
                      fontWeight: 700,
                      fontSize: '12px',
                      fontFamily: 'DM Sans, sans-serif',
                      transition: 'all 0.15s'
                    }}
                  >
                    Delete Permanently
                  </button>
                </div>
              </div>
            </div>
          )}
          {activeTab === 'heatmap' && heatmapData && (
            <div>
              <div style={{ marginBottom: '20px' }}>
                <div style={{ display: 'flex', alignItems: 'center', justifyContent: 'space-between', marginBottom: '14px' }}>
                  <div style={{ fontSize: '13px', fontWeight: 700, color: '#e8e6f0', letterSpacing: '0.3px' }}>
                    Concept Difficulty Heatmap
                  </div>
                  <div style={{ display: 'flex', gap: '14px', alignItems: 'center' }}>
                    {[['#4ade80', 'Low'], ['#fbbf24', 'Moderate'], ['#f87171', 'High']].map(([color, label]) => (
                      <div key={label} style={{ display: 'flex', alignItems: 'center', gap: '5px', fontSize: '10px', color: '#8884a0' }}>
                        <div style={{ width: '8px', height: '8px', borderRadius: '2px', background: color }}></div>
                        {label}
                      </div>
                    ))}
                  </div>
                </div>
              </div>
              <div style={{ background: '#1a1a2e', border: '1px solid #2e2e4a', borderRadius: '12px', overflow: 'hidden' }}>
                <table style={{ width: '100%', borderCollapse: 'collapse' }}>
                  <thead>
                    <tr style={{ borderBottom: '1px solid #2e2e4a', background: '#22223a' }}>
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
                      <tr key={student.id} style={{ borderBottom: '1px solid rgba(46,46,74,0.5)' }}>
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
                            unscored: { background: 'rgba(74,74,106,0.3)', color: '#8884a0', border: '1px solid #2e2e4a' }
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
            </div>
          )}
        </div>
      </div>
    </Layout>
  );
}
