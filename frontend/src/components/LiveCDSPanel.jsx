import { useState, useEffect } from 'react';
import api from '../services/api';

const COLORS = {
  bg: '#0c1220',
  surface: '#131d30',
  surface2: '#1a2640',
  border: '#1e304d',
  teal: '#85D2D0',
  text: '#dce8f5',
  muted: '#6a85a8',
  success: '#4ade80',
  warning: '#fbbf24',
  error: '#f87171'
};

export default function LiveCDSPanel({ exerciseId, onClose }) {
  const [data, setData] = useState(null);
  const [loading, setLoading] = useState(true);
  const [autoRefresh, setAutoRefresh] = useState(true);

  useEffect(() => {
    const fetchLiveCDS = async () => {
      try {
        const res = await api.get(`/api/analytics/live-cds/${exerciseId}`);
        setData(res.data);
        setLoading(false);
      } catch (err) {
        console.error('Error fetching live CDS:', err);
        setLoading(false);
      }
    };

    fetchLiveCDS();
    
    if (autoRefresh) {
      const interval = setInterval(fetchLiveCDS, 10000); // Refresh every 10 seconds
      return () => clearInterval(interval);
    }
  }, [exerciseId, autoRefresh]);

  const getCDSColor = (cds) => {
    if (cds <= 0.33) return COLORS.success;
    if (cds <= 0.66) return COLORS.warning;
    return COLORS.error;
  };

  const getCDSLabel = (cds) => {
    if (cds <= 0.33) return 'Low';
    if (cds <= 0.66) return 'Moderate';
    return 'High';
  };

  if (loading) return <div style={{ color: COLORS.muted }}>Loading live CDS...</div>;
  if (!data) return <div style={{ color: COLORS.error }}>Failed to load live CDS</div>;

  return (
    <div style={{
      background: COLORS.surface,
      border: `1px solid ${COLORS.border}`,
      borderRadius: '12px',
      padding: '20px',
      marginTop: '20px',
      maxHeight: '600px',
      overflowY: 'auto'
    }}>
      <div style={{ display: 'flex', justifyContent: 'space-between', alignItems: 'center', marginBottom: '16px' }}>
        <h3 style={{ color: COLORS.teal, margin: 0 }}>
          📊 Live CDS Peer Ranking {data.preliminary && <span style={{ color: COLORS.warning, fontSize: '12px' }}>(Preliminary)</span>}
        </h3>
        <div style={{ display: 'flex', gap: '12px' }}>
          <label style={{ color: COLORS.muted, fontSize: '12px' }}>
            <input type="checkbox" checked={autoRefresh} onChange={(e) => setAutoRefresh(e.target.checked)} />
            {' '}Auto-refresh (10s)
          </label>
          <button onClick={onClose} style={{ background: 'transparent', border: 'none', color: COLORS.muted, cursor: 'pointer' }}>×</button>
        </div>
      </div>

      {/* Summary Stats */}
      <div style={{ display: 'grid', gridTemplateColumns: 'repeat(4, 1fr)', gap: '12px', marginBottom: '20px' }}>
        <div style={{ background: COLORS.surface2, padding: '12px', borderRadius: '8px', textAlign: 'center' }}>
          <div style={{ fontSize: '18px', fontWeight: 700, color: COLORS.teal }}>{data.studentCount}</div>
          <div style={{ fontSize: '10px', color: COLORS.muted }}>Students</div>
        </div>
        <div style={{ background: COLORS.surface2, padding: '12px', borderRadius: '8px', textAlign: 'center' }}>
          <div style={{ fontSize: '18px', fontWeight: 700, color: COLORS.teal }}>{data.submissionCount}</div>
          <div style={{ fontSize: '10px', color: COLORS.muted }}>Submissions</div>
        </div>
        <div style={{ background: COLORS.surface2, padding: '12px', borderRadius: '8px', textAlign: 'center' }}>
          <div style={{ fontSize: '18px', fontWeight: 700, color: data.classAverage?.cds ? getCDSColor(data.classAverage.cds) : COLORS.muted }}>
            {data.classAverage?.cds !== null && data.classAverage?.cds !== undefined ? data.classAverage.cds.toFixed(2) : '—'}
          </div>
          <div style={{ fontSize: '10px', color: COLORS.muted }}>Class Avg CDS</div>
        </div>
        <div style={{ background: COLORS.surface2, padding: '12px', borderRadius: '8px', textAlign: 'center' }}>
          <div style={{ fontSize: '18px', fontWeight: 700, color: COLORS.teal }}>{data.reliability}</div>
          <div style={{ fontSize: '10px', color: COLORS.muted }}>Data Quality</div>
        </div>
      </div>

      {/* Class Average Breakdown */}
      <div style={{ background: COLORS.surface2, padding: '12px', borderRadius: '8px', marginBottom: '20px' }}>
        <div style={{ fontSize: '12px', fontWeight: 700, color: COLORS.muted, marginBottom: '8px' }}>CLASS AVERAGE</div>
        <div style={{ display: 'grid', gridTemplateColumns: 'repeat(3, 1fr)', gap: '8px', fontSize: '12px' }}>
          <div>NER: {data.classAverage?.ner !== null && data.classAverage?.ner !== undefined ? data.classAverage.ner.toFixed(3) : '—'}</div>
          <div>NRS: {data.classAverage?.nrs !== null && data.classAverage?.nrs !== undefined ? data.classAverage.nrs.toFixed(3) : '—'}</div>
          <div>NTS: {data.classAverage?.nts !== null && data.classAverage?.nts !== undefined ? data.classAverage.nts.toFixed(3) : '—'}</div>
        </div>
        <div style={{ marginTop: '8px', fontSize: '12px', color: data.classAverage?.cds ? getCDSColor(data.classAverage.cds) : COLORS.muted }}>
          {data.classAverage?.cds ? getCDSLabel(data.classAverage.cds) : 'Unscored'} (Range: {data.classAverage?.min !== null && data.classAverage?.min !== undefined ? data.classAverage.min.toFixed(2) : '—'} – {data.classAverage?.max !== null && data.classAverage?.max !== undefined ? data.classAverage.max.toFixed(2) : '—'})
        </div>
      </div>

      {/* Student Rankings */}
      <div style={{ fontSize: '12px', fontWeight: 700, color: COLORS.muted, marginBottom: '8px' }}>TOP/BOTTOM PERFORMERS</div>
      <div style={{ maxHeight: '300px', overflowY: 'auto' }}>
        {(data.rankings || []).slice(0, 10).map((rank, i) => (
          <div key={i} style={{
            background: COLORS.surface2,
            padding: '8px',
            marginBottom: '4px',
            borderRadius: '6px',
            display: 'flex',
            justifyContent: 'space-between',
            alignItems: 'center',
            fontSize: '11px'
          }}>
            <div>
              <span style={{ color: COLORS.text, fontWeight: 700 }}>{rank.name}</span>
              <span style={{ color: COLORS.muted, marginLeft: '8px' }}>({rank.totalAttempts} attempts, {rank.failedAttempts} failed)</span>
            </div>
            <div style={{
              background: rank.cds !== null && rank.cds !== undefined ? getCDSColor(rank.cds) : COLORS.muted,
              color: COLORS.bg,
              padding: '4px 8px',
              borderRadius: '4px',
              fontWeight: 700
            }}>
              {rank.cds !== null && rank.cds !== undefined ? rank.cds.toFixed(2) : '—'} {rank.cds !== null && rank.cds !== undefined ? getCDSLabel(rank.cds) : 'Unscored'}
            </div>
          </div>
        ))}
      </div>

      <div style={{ fontSize: '10px', color: COLORS.muted, marginTop: '12px', textAlign: 'center' }}>
        {autoRefresh ? 'Auto-refreshing...' : 'Click refresh to update'}
      </div>
    </div>
  );
}
