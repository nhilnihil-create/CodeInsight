import { useState, useEffect } from 'react';
import api from '../../services/api';
import { useSidebar } from '../../context/SidebarContext';

export default function StudentProgress() {
  const { isOpen } = useSidebar();
  const [scores, setScores] = useState([]);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    fetchScores();
  }, []);

  const fetchScores = async () => {
    try {
      const res = await api.get('/api/analytics/my-scores');
      setScores(res.data || []);
    } catch (err) {
      console.error('Error fetching scores:', err);
    } finally {
      setLoading(false);
    }
  };

  const getClassificationColor = (classification) => {
    if (classification === 'Low') return '#4ade80';
    if (classification === 'Moderate') return '#fbbf24';
    return '#f87171';
  };

  // Safe number formatter - converts string/number to fixed decimal
  const formatNumber = (value, decimals = 3) => {
    if (value === null || value === undefined) return '—';
    const num = typeof value === 'string' ? parseFloat(value) : value;
    return isNaN(num) ? '—' : num.toFixed(decimals);
  };

  if (loading) {
    return <div style={{ padding: '40px', color: '#8b949e' }}>Loading...</div>;
  }

  return (
    <div style={{ 
      padding: isOpen ? '28px 28px 28px 28px' : '28px 28px 28px 0',
      width: '100%',
      boxSizing: 'border-box',
      background: '#0c1220',
      minHeight: '100vh'
    }}>
      <h1 style={{ fontSize: '20px', fontWeight: 700, color: '#dce8f5', marginBottom: '24px' }}>
        My Progress
      </h1>

      {scores.length === 0 ? (
        <div style={{ color: '#6a85a8' }}>
          No scores yet. Submit exercises to track your progress.
        </div>
      ) : (
        <div>
          {/* Summary Cards */}
          <div style={{ display: 'grid', gridTemplateColumns: 'repeat(auto-fit, minmax(160px, 1fr))', gap: '12px', marginBottom: '24px' }}>
            <div style={{
              background: '#131d30',
              border: '1px solid #1e304d',
              borderRadius: '8px',
              padding: '16px',
              textAlign: 'center'
            }}>
              <div style={{ fontSize: '11px', fontWeight: 700, letterSpacing: '1px', textTransform: 'uppercase', color: '#6a85a8', marginBottom: '8px' }}>Total Exercises</div>
              <div style={{ fontSize: '24px', fontWeight: 700, color: '#dce8f5' }}>
                {new Set(scores.map(s => s.exercise_title)).size}
              </div>
            </div>
            <div style={{
              background: '#131d30',
              border: '1px solid #1e304d',
              borderRadius: '8px',
              padding: '16px',
              textAlign: 'center'
            }}>
              <div style={{ fontSize: '11px', fontWeight: 700, letterSpacing: '1px', textTransform: 'uppercase', color: '#6a85a8', marginBottom: '8px' }}>Avg CDS</div>
              <div style={{ fontSize: '24px', fontWeight: 700, color: '#85D2D0' }}>
                {formatNumber(scores.reduce((a, s) => a + (typeof s.cds === 'string' ? parseFloat(s.cds) || 0 : s.cds || 0), 0) / scores.length, 3)}
              </div>
            </div>
            <div style={{
              background: '#131d30',
              border: '1px solid #1e304d',
              borderRadius: '8px',
              padding: '16px',
              textAlign: 'center'
            }}>
              <div style={{ fontSize: '11px', fontWeight: 700, letterSpacing: '1px', textTransform: 'uppercase', color: '#6a85a8', marginBottom: '8px' }}>Low Difficulty</div>
              <div style={{ fontSize: '24px', fontWeight: 700, color: '#4ade80' }}>
                {scores.filter(s => s.classification === 'Low').length}
              </div>
            </div>
          </div>

          {/* Scores Table */}
          <div style={{
            background: '#131d30',
            border: '1px solid #1e304d',
            borderRadius: '8px',
            overflow: 'hidden'
          }}>
            <table style={{ width: '100%', borderCollapse: 'collapse', fontSize: '12px' }}>
              <thead>
                <tr style={{ borderBottom: '1px solid #1e304d', background: '#1a2640' }}>
                  <th style={{ textAlign: 'left', padding: '12px', color: '#6a85a8', fontWeight: 700, fontSize: '10px', letterSpacing: '0.5px', textTransform: 'uppercase' }}>Concept</th>
                  <th style={{ textAlign: 'left', padding: '12px', color: '#6a85a8', fontWeight: 700, fontSize: '10px', letterSpacing: '0.5px', textTransform: 'uppercase' }}>Exercise</th>
                  <th style={{ textAlign: 'center', padding: '12px', color: '#6a85a8', fontWeight: 700, fontSize: '10px', letterSpacing: '0.5px', textTransform: 'uppercase' }}>CDS Score</th>
                  <th style={{ textAlign: 'center', padding: '12px', color: '#6a85a8', fontWeight: 700, fontSize: '10px', letterSpacing: '0.5px', textTransform: 'uppercase' }}>Classification</th>
                  <th style={{ textAlign: 'center', padding: '12px', color: '#6a85a8', fontWeight: 700, fontSize: '10px', letterSpacing: '0.5px', textTransform: 'uppercase' }}>NER</th>
                  <th style={{ textAlign: 'center', padding: '12px', color: '#6a85a8', fontWeight: 700, fontSize: '10px', letterSpacing: '0.5px', textTransform: 'uppercase' }}>NRS</th>
                  <th style={{ textAlign: 'center', padding: '12px', color: '#6a85a8', fontWeight: 700, fontSize: '10px', letterSpacing: '0.5px', textTransform: 'uppercase' }}>NTS</th>
                </tr>
              </thead>
              <tbody>
                {scores.map((score, i) => (
                  <tr key={i} style={{ borderBottom: i < scores.length - 1 ? '1px solid #1e304d' : 'none' }}>
                    <td style={{ padding: '12px', color: '#dce8f5' }}>{score.concept_name}</td>
                    <td style={{ padding: '12px', color: '#dce8f5' }}>{score.exercise_title}</td>
                    <td style={{ 
                      textAlign: 'center', 
                      padding: '12px', 
                      color: getClassificationColor(score.classification),
                      fontWeight: 700
                    }}>
                      {formatNumber(score.cds, 3)}
                    </td>
                    <td style={{ 
                      textAlign: 'center', 
                      padding: '12px',
                      color: getClassificationColor(score.classification),
                      fontWeight: 700
                    }}>
                      {score.classification}
                    </td>
                    <td style={{ textAlign: 'center', padding: '12px', color: '#6a85a8' }}>
                      {formatNumber(score.ner, 3)}
                    </td>
                    <td style={{ textAlign: 'center', padding: '12px', color: '#6a85a8' }}>
                      {formatNumber(score.nrs, 3)}
                    </td>
                    <td style={{ textAlign: 'center', padding: '12px', color: '#6a85a8' }}>
                      {formatNumber(score.nts, 3)}
                    </td>
                  </tr>
                ))}
              </tbody>
            </table>
          </div>
        </div>
      )}
    </div>
  );
}
