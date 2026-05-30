import { useState, useEffect } from 'react';
import { Link } from 'react-router-dom';
import api from '../../services/api';

// Color constants - matching mockup exactly
const COLORS = {
  bg: '#0c1220',
  surface: '#131d30',
  surface2: '#1a2640',
  border: '#1e304d',
  teal: '#85D2D0',
  purple: '#a99dd4',
  text: '#dce8f5',
  muted: '#6a85a8',
  success: '#4ade80',
  warning: '#fbbf24',
  error: '#f87171'
};

export default function StudentExerciseList() {
  const [exercises, setExercises] = useState([]);
  const [stats, setStats] = useState(null);
  const [filter, setFilter] = useState('all');
  const [loading, setLoading] = useState(true);
  const [hoveredCard, setHoveredCard] = useState(null);

  useEffect(() => {
    fetchData();
  }, []);

  const fetchData = async () => {
    try {
      const [exRes, statsRes] = await Promise.all([
        api.get('/api/student/exercises'),
        api.get('/api/student/stats')
      ]);
      
      let exData = exRes.data || [];
      exData = exData.map(ex => {
        if (ex.test_cases && typeof ex.test_cases === 'string') {
          ex.test_cases = JSON.parse(ex.test_cases);
        }
        return ex;
      });
      
      setExercises(exData);
      setStats(statsRes.data || {});
    } catch (err) {
      console.error('Error fetching data:', err);
    } finally {
      setLoading(false);
    }
  };

  const getFilteredExercises = () => {
    if (filter === 'all') return exercises;
    if (filter === 'completed') return exercises.filter(ex => ex.status === 'completed');
    if (filter === 'pending') return exercises.filter(ex => ex.status === 'pending' || ex.status === 'locked');
    return exercises;
  };

  const getStatusColor = (status) => {
    if (status === 'completed') return COLORS.success;
    if (status === 'pending') return COLORS.warning;
    return COLORS.muted;
  };

  const getCDSColor = (cds) => {
    const numCds = typeof cds === 'string' ? parseFloat(cds) : cds;
    if (!numCds && numCds !== 0) return COLORS.muted;
    if (numCds <= 0.33) return COLORS.error;
    if (numCds <= 0.66) return COLORS.warning;
    return COLORS.success;
  };

  const getCDSLabel = (cds) => {
    const numCds = typeof cds === 'string' ? parseFloat(cds) : cds;
    if (!numCds && numCds !== 0) return 'Unscored';
    if (numCds <= 0.33) return 'Low';
    if (numCds <= 0.66) return 'Moderate';
    return 'High';
  };

  if (loading) {
    return <div style={{ padding: '40px', color: COLORS.muted, background: COLORS.bg, height: '100vh' }}>Loading...</div>;
  }

  const filteredExercises = getFilteredExercises();

  return (
    <div style={{ background: COLORS.bg, color: COLORS.text, fontFamily: "'DM Sans', sans-serif", minHeight: '100vh', padding: '24px 40px' }}>
      {/* HEADER */}
      <div style={{ marginBottom: '32px' }}>
        <div style={{ fontSize: '32px', fontWeight: 700, marginBottom: '8px' }}>Exercises</div>
        <div style={{ fontSize: '14px', color: COLORS.muted }}>Solve coding challenges and improve your programming skills</div>
      </div>

      {/* STATS CARDS */}
      {stats && (
        <div style={{ display: 'grid', gridTemplateColumns: 'repeat(3, 1fr)', gap: '16px', marginBottom: '32px' }}>
          <div style={{ background: COLORS.surface, border: `1px solid ${COLORS.border}`, borderRadius: '12px', padding: '20px', textAlign: 'center' }}>
            <div style={{ fontSize: '28px', fontWeight: 700, color: COLORS.teal, marginBottom: '4px' }}>{stats.total_exercises || 0}</div>
            <div style={{ fontSize: '12px', color: COLORS.muted, fontWeight: 600 }}>Total Exercises</div>
            <div style={{ height: '4px', background: COLORS.surface2, borderRadius: '2px', marginTop: '12px', overflow: 'hidden' }}>
              <div style={{ height: '100%', background: COLORS.teal, width: `${stats.total_exercises > 0 ? 100 : 0}%` }} />
            </div>
          </div>

          <div style={{ background: COLORS.surface, border: `1px solid ${COLORS.border}`, borderRadius: '12px', padding: '20px', textAlign: 'center' }}>
            <div style={{ fontSize: '28px', fontWeight: 700, color: COLORS.success, marginBottom: '4px' }}>{stats.completed_exercises || 0}</div>
            <div style={{ fontSize: '12px', color: COLORS.muted, fontWeight: 600 }}>Completed</div>
            <div style={{ height: '4px', background: COLORS.surface2, borderRadius: '2px', marginTop: '12px', overflow: 'hidden' }}>
              <div style={{ height: '100%', background: COLORS.success, width: `${stats.total_exercises > 0 ? (stats.completed_exercises / stats.total_exercises * 100) : 0}%` }} />
            </div>
          </div>

          <div style={{ background: COLORS.surface, border: `1px solid ${COLORS.border}`, borderRadius: '12px', padding: '20px', textAlign: 'center' }}>
            <div style={{ fontSize: '28px', fontWeight: 700, color: COLORS.warning, marginBottom: '4px' }}>{stats.pending_exercises || 0}</div>
            <div style={{ fontSize: '12px', color: COLORS.muted, fontWeight: 600 }}>Pending</div>
            <div style={{ height: '4px', background: COLORS.surface2, borderRadius: '2px', marginTop: '12px', overflow: 'hidden' }}>
              <div style={{ height: '100%', background: COLORS.warning, width: `${stats.total_exercises > 0 ? (stats.pending_exercises / stats.total_exercises * 100) : 0}%` }} />
            </div>
          </div>

        </div>
      )}

      {/* FILTER TABS */}
      <div style={{ display: 'flex', gap: '12px', marginBottom: '28px', borderBottom: `1px solid ${COLORS.border}`, paddingBottom: '16px' }}>
        {['all', 'pending', 'completed'].map(f => (
          <button
            key={f}
            onClick={() => setFilter(f)}
            style={{
              padding: '8px 16px',
              borderRadius: '8px',
              fontSize: '12px',
              fontWeight: 600,
              cursor: 'pointer',
              border: 'none',
              background: filter === f ? COLORS.teal : 'transparent',
              color: filter === f ? '#091a1a' : COLORS.muted,
              fontFamily: "'DM Sans', sans-serif",
              transition: 'all 0.2s',
              textTransform: 'capitalize'
            }}
          >
            {f === 'all' ? 'All' : f === 'completed' ? 'Completed' : 'Pending'}
          </button>
        ))}
      </div>

      {/* EXERCISE GRID */}
      <div style={{ display: 'grid', gridTemplateColumns: 'repeat(2, 1fr)', gap: '20px' }}>
        {filteredExercises.length === 0 ? (
          <div style={{ gridColumn: '1 / -1', textAlign: 'center', padding: '60px 20px', color: COLORS.muted }}>
            <div style={{ fontSize: '14px' }}>No exercises found</div>
          </div>
        ) : (
          filteredExercises.map(exercise => (
            <Link key={exercise.id} to={`/student/exercises/${exercise.id}`} style={{ textDecoration: 'none' }}>
              <div 
                onMouseEnter={() => setHoveredCard(exercise.id)}
                onMouseLeave={() => setHoveredCard(null)}
                style={{ 
                  background: COLORS.surface, 
                  border: `1px solid ${hoveredCard === exercise.id ? COLORS.teal : COLORS.border}`, 
                  borderRadius: '12px', 
                  padding: '20px', 
                  cursor: 'pointer', 
                  transition: 'all 0.2s',
                  boxShadow: hoveredCard === exercise.id ? `0 0 16px rgba(133, 210, 208, 0.15)` : 'none'
                }}>
                {/* Concept chip */}
                <div style={{ display: 'flex', justifyContent: 'space-between', alignItems: 'start', marginBottom: '12px' }}>
                  <span style={{ fontSize: '10px', fontWeight: 700, textTransform: 'uppercase', letterSpacing: '0.8px', padding: '4px 10px', borderRadius: '10px', background: 'rgba(136,123,176,0.15)', color: COLORS.purple, border: '1px solid rgba(136,123,176,0.3)' }}>
                    {exercise.concept_name}
                  </span>
                  <span style={{ fontSize: '10px', fontWeight: 700, textTransform: 'uppercase', letterSpacing: '0.8px', padding: '4px 12px', borderRadius: '6px', background: `rgba(${exercise.status === 'completed' ? '74, 222, 128' : exercise.status === 'pending' ? '251, 191, 36' : '106, 133, 168'}, 0.12)`, color: getStatusColor(exercise.status) }}>
                    {exercise.status === 'completed' ? 'Completed' : exercise.status === 'pending' ? 'Pending' : 'Locked'}
                  </span>
                </div>

                {/* Title */}
                <div style={{ fontSize: '16px', fontWeight: 700, color: COLORS.text, marginBottom: '8px' }}>
                  {exercise.title}
                </div>

                {/* Description preview */}
                <div style={{ fontSize: '12px', color: COLORS.muted, marginBottom: '16px', lineHeight: '1.5', maxHeight: '40px', overflow: 'hidden', textOverflow: 'ellipsis' }}>
                  {exercise.description}
                </div>

                {/* Metadata */}
                <div style={{ display: 'flex', gap: '16px', fontSize: '10px', color: COLORS.muted, marginBottom: '16px', paddingBottom: '16px', borderBottom: `1px solid ${COLORS.border}` }}>
                  <span>⏱ {exercise.time_limit_minutes}m</span>
                  <span>📅 {exercise.deadline ? new Date(exercise.deadline).toLocaleDateString('en-US', { month: 'short', day: 'numeric' }) : 'No deadline'}</span>
                  <span style={{ marginLeft: 'auto' }}>{Array.isArray(exercise.test_cases) ? exercise.test_cases.length : 0} tests</span>
                </div>

                {/* CDS Score and Stats */}
                {exercise.status === 'completed' && exercise.cds !== null && exercise.cds !== undefined && (
                  <div>
                    <div style={{ fontSize: '10px', fontWeight: 700, color: COLORS.muted, marginBottom: '6px' }}>DIFFICULTY</div>
                    <div style={{ display: 'flex', alignItems: 'center', gap: '8px' }}>
                      <div style={{ fontSize: '20px', fontWeight: 700, color: getCDSColor(exercise.cds) }}>{parseFloat(exercise.cds).toFixed(2)}</div>
                      <div style={{ display: 'inline-block', fontSize: '11px', fontWeight: 700, padding: '3px 10px', borderRadius: '12px', background: `rgba(${getCDSColor(exercise.cds) === COLORS.success ? '74, 222, 128' : getCDSColor(exercise.cds) === COLORS.warning ? '251, 191, 36' : '248, 113, 113'}, 0.12)`, color: getCDSColor(exercise.cds) }}>
                        {getCDSLabel(exercise.cds)}
                      </div>
                    </div>
                  </div>
                )}

                {exercise.status !== 'completed' && (
                  <div style={{ fontSize: '10px', color: COLORS.muted, textAlign: 'center', padding: '12px', borderRadius: '8px', background: COLORS.surface2 }}>
                    {exercise.status === 'locked' ? 'Complete prerequisites to unlock' : 'Start solving'}
                  </div>
                )}
              </div>
            </Link>
          ))
        )}
      </div>
    </div>
  );
}
