import { useState, useEffect } from 'react';
import { Link } from 'react-router-dom';
import api from '../../services/api';

export default function StudentExerciseList() {
  const [exercises, setExercises] = useState([]);
  const [loading, setLoading] = useState(true);
  const [stats, setStats] = useState({ total: 0, done: 0, pending: 0, locked: 0 });
  const [filterActive, setFilterActive] = useState('all');

  useEffect(() => {
    fetchExercises();
  }, []);

  const fetchExercises = async () => {
    try {
      const res = await api.get('/api/student/exercises');
      setExercises(res.data || []);
      calculateStats(res.data);
    } catch (err) {
      console.error('Error fetching exercises:', err);
    } finally {
      setLoading(false);
    }
  };

  const calculateStats = (exData) => {
    const total = exData.length;
    const done = exData.filter(e => e.status === 'completed').length;
    const pending = exData.filter(e => e.status === 'pending').length;
    const locked = exData.filter(e => e.status === 'locked').length;
    setStats({ total, done, pending, locked });
  };

  const filterExercises = () => {
    let filtered = exercises;
    if (filterActive === 'pending') filtered = exercises.filter(e => e.status === 'pending');
    if (filterActive === 'completed') filtered = exercises.filter(e => e.status === 'completed');
    return filtered;
  };

  const getConceptColor = (concept) => {
    const colors = {
      'Datatypes': 'concept-dt',
      'Variables': 'concept-vars',
      'Conditionals': 'concept-cond',
      'Loops': 'concept-loops',
      'Functions': 'concept-fn',
      'Arrays': 'concept-arrays',
      'OOP': 'concept-oop'
    };
    return colors[concept] || 'concept-dt';
  };

  const getStatusBadge = (status) => {
    if (status === 'completed') return { class: 'status-done', text: '✓ Done' };
    if (status === 'pending') return { class: 'status-pending', text: '⏳ Pending' };
    return { class: 'status-locked', text: '🔒 Locked' };
  };

  const formatCDS = (cds) => {
    if (!cds || cds === null) return { val: '—', label: 'Unscored', class: 'cds-none' };
    const num = typeof cds === 'string' ? parseFloat(cds) : cds;
    if (num <= 0.33) return { val: num.toFixed(2), label: 'Low', class: 'cds-low' };
    if (num <= 0.66) return { val: num.toFixed(2), label: 'Moderate', class: 'cds-mod' };
    return { val: num.toFixed(2), label: 'High', class: 'cds-high' };
  };

  const completionPercent = stats.total ? Math.round((stats.done / stats.total) * 100) : 0;

  if (loading) {
    return <div style={{ padding: '40px', color: '#6a85a8' }}>Loading exercises...</div>;
  }

  return (
    <div style={{
      padding: '22px 26px',
      width: '100%',
      boxSizing: 'border-box',
      overflowY: 'auto',
      height: '100vh',
      background: '#0c1220'
    }}>
      {/* Top Bar */}
      <div style={{ marginBottom: '22px' }}>
        <div style={{ fontSize: '16px', fontWeight: 700, color: '#dce8f5' }}>
          My Exercises
        </div>
        <div style={{ fontSize: '10px', color: '#6a85a8', marginTop: '2px' }}>
          CS101 — Introduction to C++ · AY 2025–2026
        </div>
      </div>

      {/* Progress Summary */}
      <div style={{
        background: '#131d30',
        border: '1px solid #1e304d',
        borderRadius: '12px',
        padding: '18px 22px',
        marginBottom: '20px',
        display: 'flex',
        alignItems: 'center',
        gap: '24px',
        boxSizing: 'border-box'
      }}>
        <div style={{ textAlign: 'center', minWidth: '60px' }}>
          <div style={{ fontFamily: "'Space Mono', monospace", fontSize: '22px', fontWeight: 700, color: '#dce8f5' }}>
            {stats.total}
          </div>
          <div style={{ fontSize: '9px', textTransform: 'uppercase', letterSpacing: '1.2px', color: '#6a85a8', marginTop: '3px' }}>
            Total
          </div>
        </div>
        <div style={{ width: '1px', height: '40px', background: '#1e304d' }}></div>
        <div style={{ textAlign: 'center', minWidth: '60px' }}>
          <div style={{ fontFamily: "'Space Mono', monospace", fontSize: '22px', fontWeight: 700, color: '#4ade80' }}>
            {stats.done}
          </div>
          <div style={{ fontSize: '9px', textTransform: 'uppercase', letterSpacing: '1.2px', color: '#6a85a8', marginTop: '3px' }}>
            Done
          </div>
        </div>
        <div style={{ width: '1px', height: '40px', background: '#1e304d' }}></div>
        <div style={{ textAlign: 'center', minWidth: '60px' }}>
          <div style={{ fontFamily: "'Space Mono', monospace", fontSize: '22px', fontWeight: 700, color: '#fbbf24' }}>
            {stats.pending}
          </div>
          <div style={{ fontSize: '9px', textTransform: 'uppercase', letterSpacing: '1.2px', color: '#6a85a8', marginTop: '3px' }}>
            Pending
          </div>
        </div>
        <div style={{ width: '1px', height: '40px', background: '#1e304d' }}></div>
        <div style={{ textAlign: 'center', minWidth: '60px' }}>
          <div style={{ fontFamily: "'Space Mono', monospace", fontSize: '22px', fontWeight: 700, color: '#6a85a8' }}>
            {stats.locked}
          </div>
          <div style={{ fontSize: '9px', textTransform: 'uppercase', letterSpacing: '1.2px', color: '#6a85a8', marginTop: '3px' }}>
            Locked
          </div>
        </div>
        <div style={{ width: '1px', height: '40px', background: '#1e304d' }}></div>
        <div style={{ flex: 1 }}>
          <div style={{ fontSize: '10px', color: '#6a85a8', marginBottom: '6px', display: 'flex', justifyContent: 'space-between' }}>
            <span>Overall Completion</span>
            <span style={{ color: '#dce8f5', fontWeight: 600 }}>{completionPercent}%</span>
          </div>
          <div style={{ background: '#1a2640', borderRadius: '6px', height: '8px', overflow: 'hidden' }}>
            <div style={{
              height: '100%',
              borderRadius: '6px',
              background: `linear-gradient(90deg, #85D2D0, #a99dd4)`,
              width: `${completionPercent}%`,
              transition: 'width 0.3s'
            }}></div>
          </div>
        </div>
      </div>

      {/* Filter Tabs */}
      <div style={{ display: 'flex', gap: '8px', marginBottom: '16px' }}>
        {['all', 'pending', 'completed'].map(filter => (
          <button
            key={filter}
            onClick={() => setFilterActive(filter)}
            style={{
              padding: '6px 14px',
              borderRadius: '20px',
              fontSize: '11px',
              fontWeight: 600,
              cursor: 'pointer',
              border: '1.5px solid ' + (filterActive === filter ? '#85D2D0' : '#1e304d'),
              color: filterActive === filter ? '#85D2D0' : '#6a85a8',
              background: filterActive === filter ? 'rgba(133,210,208,0.1)' : 'transparent',
              fontFamily: "'DM Sans', sans-serif",
              transition: 'all 0.15s'
            }}
          >
            {filter.charAt(0).toUpperCase() + filter.slice(1)}
          </button>
        ))}
      </div>

      {/* Exercise Cards Grid */}
      <div style={{ display: 'grid', gridTemplateColumns: '1fr 1fr', gap: '12px' }}>
        {filterExercises().map(exercise => {
          const cdsInfo = formatCDS(exercise.latest_cds);
          const statusInfo = getStatusBadge(exercise.status);
          const conceptColor = getConceptColor(exercise.concept_name);

          return (
            <Link
              key={exercise.id}
              to={exercise.status === 'locked' ? '#' : `/student/exercises/${exercise.id}`}
              style={{ textDecoration: 'none' }}
            >
              <div style={{
                background: '#131d30',
                border: '1px solid ' + (exercise.status === 'locked' ? '#1e304d' : (exercise.status === 'completed' ? 'rgba(74,222,128,0.2)' : 'rgba(251,191,36,0.25)')),
                borderRadius: '12px',
                padding: '18px',
                cursor: exercise.status === 'locked' ? 'not-allowed' : 'pointer',
                transition: 'all 0.2s',
                opacity: exercise.status === 'locked' ? 0.5 : 1,
                position: 'relative',
                overflow: 'hidden',
                display: 'flex',
                flexDirection: 'column',
                height: '100%'
              }}
              onMouseEnter={(e) => {
                if (exercise.status !== 'locked') {
                  e.currentTarget.style.borderColor = '#85D2D0';
                  e.currentTarget.style.transform = 'translateY(-1px)';
                }
              }}
              onMouseLeave={(e) => {
                if (exercise.status !== 'locked') {
                  e.currentTarget.style.borderColor = e.currentTarget.style.borderColor;
                  e.currentTarget.style.transform = 'translateY(0)';
                }
              }}
              >
                {exercise.status === 'completed' && (
                  <div style={{ position: 'absolute', top: 0, left: 0, right: 0, height: '2px', background: '#4ade80' }}></div>
                )}

                <div style={{ display: 'flex', alignItems: 'flex-start', justifyContent: 'space-between', marginBottom: '10px' }}>
                  <div style={{
                    display: 'inline-flex',
                    alignItems: 'center',
                    gap: '5px',
                    padding: '4px 10px',
                    borderRadius: '12px',
                    fontSize: '9px',
                    fontWeight: 700,
                    letterSpacing: '0.8px',
                    textTransform: 'uppercase',
                    background: 'rgba(136,123,176,0.15)',
                    color: '#a99dd4',
                    border: '1px solid rgba(136,123,176,0.3)',
                    minWidth: 'fit-content'
                  }}>
                    {exercise.concept_name}
                  </div>
                  <div style={{
                    fontSize: '10px',
                    fontWeight: 600,
                    padding: '3px 8px',
                    borderRadius: '10px',
                    background: statusInfo.class.includes('done') ? 'rgba(74,222,128,0.12)' : (statusInfo.class.includes('pending') ? 'rgba(251,191,36,0.12)' : 'rgba(100,100,140,0.2)'),
                    color: statusInfo.class.includes('done') ? '#4ade80' : (statusInfo.class.includes('pending') ? '#fbbf24' : '#6a85a8')
                  }}>
                    {statusInfo.text}
                  </div>
                </div>

                <div style={{ fontSize: '13px', fontWeight: 700, color: '#dce8f5', marginBottom: '5px', lineHeight: '1.4' }}>
                  {exercise.title}
                </div>

                <div style={{ fontSize: '11px', color: '#6a85a8', lineHeight: '1.5', marginBottom: '12px', flex: 1 }}>
                  {exercise.description?.substring(0, 100)}{exercise.description?.length > 100 ? '...' : ''}
                </div>

                <div style={{ display: 'flex', alignItems: 'center', justifyContent: 'space-between' }}>
                  <div style={{ fontSize: '10px', color: '#6a85a8', display: 'flex', gap: '14px' }}>
                    <div style={{ display: 'flex', alignItems: 'center', gap: '4px' }}>
                      ⏱ {exercise.time_limit_minutes} min
                    </div>
                    <div style={{ display: 'flex', alignItems: 'center', gap: '4px' }}>
                      📅 {new Date(exercise.deadline).toLocaleDateString('en-US', { month: 'short', day: 'numeric' })}
                    </div>
                  </div>
                  <div style={{ display: 'flex', alignItems: 'center', gap: '6px' }}>
                    <span style={{ fontSize: '9px', textTransform: 'uppercase', letterSpacing: '1px', color: '#6a85a8' }}>
                      CDS
                    </span>
                    <span style={{
                      fontFamily: "'Space Mono', monospace",
                      fontSize: '11px',
                      fontWeight: 700,
                      color: cdsInfo.class === 'cds-low' ? '#4ade80' : (cdsInfo.class === 'cds-mod' ? '#fbbf24' : (cdsInfo.class === 'cds-high' ? '#f87171' : '#6a85a8'))
                    }}>
                      {cdsInfo.val} {cdsInfo.label !== 'Unscored' ? '· ' + cdsInfo.label : ''}
                    </span>
                  </div>
                </div>
              </div>
            </Link>
          );
        })}
      </div>
    </div>
  );
}
