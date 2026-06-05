import { useState, useEffect } from 'react';
import api from '../services/api';

/**
 * Live CDS Peer Ranking panel.
 *
 * Uses CSS custom properties (defined in src/index.css) so the panel respects
 * the active theme — light = Frontend-Design blue/white, dark = teal palette.
 * No hardcoded hex; every value reads from a token.
 */
const TOKENS = {
  surface: 'var(--card)',
  surface2: 'var(--secondary)',
  border: 'var(--border)',
  primary: 'var(--primary)',
  primaryFg: 'var(--primary-foreground)',
  text: 'var(--card-foreground)',
  muted: 'var(--muted-foreground)',
  success: 'var(--chart-2)',  // green band (concept-success)
  warning: 'var(--chart-4)',  // amber band
  error: 'var(--destructive)',
  fontSans: 'var(--app-font-sans)',
  fontMono: 'var(--app-font-mono)',
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
      const interval = setInterval(fetchLiveCDS, 10000);
      return () => clearInterval(interval);
    }
  }, [exerciseId, autoRefresh]);

  const getCDSColor = (cds) => {
    if (cds <= 0.33) return TOKENS.success;
    if (cds <= 0.66) return TOKENS.warning;
    return TOKENS.error;
  };

  const getCDSLabel = (cds) => {
    if (cds <= 0.33) return 'Low';
    if (cds <= 0.66) return 'Moderate';
    return 'High';
  };

  if (loading) return <div style={{ color: TOKENS.muted, fontFamily: TOKENS.fontSans }}>Loading live CDS...</div>;
  if (!data) return <div style={{ color: TOKENS.error, fontFamily: TOKENS.fontSans }}>Failed to load live CDS</div>;

  const reliabilityColor = data.preliminary ? TOKENS.warning : TOKENS.success;
  const participationLabel =
    data.enrolledCount != null
      ? `${data.submitterCount ?? data.studentCount ?? 0}/${data.enrolledCount} submitted`
      : `${data.studentCount ?? 0} submitters`;

  return (
    <div style={{
      background: TOKENS.surface,
      color: TOKENS.text,
      border: `1px solid ${TOKENS.border}`,
      borderRadius: '12px',
      padding: '20px',
      marginTop: '20px',
      maxHeight: '600px',
      overflowY: 'auto',
      fontFamily: TOKENS.fontSans,
    }}>
      <div style={{ display: 'flex', justifyContent: 'space-between', alignItems: 'center', marginBottom: '16px' }}>
        <h3 style={{ color: TOKENS.primary, margin: 0, fontWeight: 700, fontSize: '16px' }}>
          📊 Live CDS Peer Ranking
          {data.preliminary && (
            <span style={{ color: TOKENS.warning, fontSize: '12px', marginLeft: '8px' }}>
              (Preliminary)
            </span>
          )}
        </h3>
        <div style={{ display: 'flex', gap: '12px', alignItems: 'center' }}>
          <label style={{ color: TOKENS.muted, fontSize: '12px', display: 'inline-flex', alignItems: 'center', gap: '4px' }}>
            <input type="checkbox" checked={autoRefresh} onChange={(e) => setAutoRefresh(e.target.checked)} />
            Auto-refresh (10s)
          </label>
          <button
            onClick={onClose}
            aria-label="Close panel"
            style={{
              background: 'transparent',
              border: 'none',
              color: TOKENS.muted,
              cursor: 'pointer',
              fontSize: '20px',
              lineHeight: 1,
              width: '24px',
              height: '24px',
            }}
          >×</button>
        </div>
      </div>

      {data.preliminary && (
        <div
          className="rounded-lg border p-3"
          style={{
            // Use a soft amber tint derived from the theme's --chart-4 token.
            // We resolve at render time so the alpha is consistent in both
            // light and dark themes.
            backgroundColor: 'hsl(43 74% 66% / 0.10)',
            borderColor: 'hsl(43 74% 66% / 0.30)',
            color: TOKENS.warning,
            fontSize: '11px',
            lineHeight: 1.5,
            marginBottom: '16px',
          }}
        >
          Rankings are preliminary: only {participationLabel}. CDS peer norms need at least 3 submitters
          and full class participation before they are marked accurate.
        </div>
      )}

      <div style={{ display: 'grid', gridTemplateColumns: 'repeat(4, 1fr)', gap: '12px', marginBottom: '20px' }}>
        <div style={{ background: TOKENS.surface2, padding: '12px', borderRadius: '8px', textAlign: 'center', border: `1px solid ${TOKENS.border}` }}>
          <div style={{ fontSize: '18px', fontWeight: 700, color: TOKENS.primary, fontFamily: TOKENS.fontMono }}>
            {data.submitterCount ?? data.studentCount ?? 0}
          </div>
          <div style={{ fontSize: '10px', color: TOKENS.muted }}>Submitters</div>
        </div>
        <div style={{ background: TOKENS.surface2, padding: '12px', borderRadius: '8px', textAlign: 'center', border: `1px solid ${TOKENS.border}` }}>
          <div style={{ fontSize: '18px', fontWeight: 700, color: TOKENS.primary, fontFamily: TOKENS.fontMono }}>{data.submissionCount}</div>
          <div style={{ fontSize: '10px', color: TOKENS.muted }}>Submissions</div>
        </div>
        <div style={{ background: TOKENS.surface2, padding: '12px', borderRadius: '8px', textAlign: 'center', border: `1px solid ${TOKENS.border}` }}>
          <div style={{ fontSize: '18px', fontWeight: 700, color: data.classAverage?.cds != null ? getCDSColor(data.classAverage.cds) : TOKENS.muted, fontFamily: TOKENS.fontMono }}>
            {data.classAverage?.cds != null ? data.classAverage.cds.toFixed(2) : '—'}
          </div>
          <div style={{ fontSize: '10px', color: TOKENS.muted }}>Class Avg CDS</div>
        </div>
        <div style={{ background: TOKENS.surface2, padding: '12px', borderRadius: '8px', textAlign: 'center', border: `1px solid ${TOKENS.border}` }}>
          <div style={{ fontSize: '18px', fontWeight: 700, color: reliabilityColor, fontFamily: TOKENS.fontMono }}>
            {data.reliability}
          </div>
          <div style={{ fontSize: '10px', color: TOKENS.muted }}>Data Quality</div>
        </div>
      </div>

      <div style={{ background: TOKENS.surface2, padding: '12px', borderRadius: '8px', marginBottom: '20px', border: `1px solid ${TOKENS.border}` }}>
        <div style={{ fontSize: '12px', fontWeight: 700, color: TOKENS.muted, marginBottom: '8px', letterSpacing: '0.04em' }}>CLASS AVERAGE (submitters only)</div>
        <div style={{ display: 'grid', gridTemplateColumns: 'repeat(3, 1fr)', gap: '8px', fontSize: '12px', fontFamily: TOKENS.fontMono }}>
          <div>NER: {data.classAverage?.ner != null ? data.classAverage.ner.toFixed(3) : '—'}</div>
          <div>NRS: {data.classAverage?.nrs != null ? data.classAverage.nrs.toFixed(3) : '—'}</div>
          <div>NTS: {data.classAverage?.nts != null ? data.classAverage.nts.toFixed(3) : '—'}</div>
        </div>
        <div style={{ marginTop: '8px', fontSize: '12px', color: data.classAverage?.cds != null ? getCDSColor(data.classAverage.cds) : TOKENS.muted }}>
          {data.classAverage?.cds != null ? getCDSLabel(data.classAverage.cds) : 'Unscored'} (Range:{' '}
          {data.classAverage?.min != null ? data.classAverage.min.toFixed(2) : '—'} –{' '}
          {data.classAverage?.max != null ? data.classAverage.max.toFixed(2) : '—'})
        </div>
      </div>

      <div style={{ fontSize: '12px', fontWeight: 700, color: TOKENS.muted, marginBottom: '8px', letterSpacing: '0.04em' }}>STUDENTS WHO SUBMITTED</div>
      <div style={{ maxHeight: '300px', overflowY: 'auto' }}>
        {(data.rankings || []).length === 0 && (
          <div style={{ fontSize: '11px', color: TOKENS.muted, padding: '8px' }}>
            No submissions yet for this exercise.
          </div>
        )}
        {(data.rankings || []).slice(0, 10).map((rank) => (
          <div
            key={rank.studentId}
            style={{
              background: TOKENS.surface2,
              padding: '8px',
              marginBottom: '4px',
              borderRadius: '6px',
              display: 'flex',
              justifyContent: 'space-between',
              alignItems: 'center',
              fontSize: '11px',
              border: `1px solid ${TOKENS.border}`,
            }}
          >
            <div>
              <span style={{ color: TOKENS.text, fontWeight: 700 }}>{rank.name}</span>
              <span style={{ color: TOKENS.muted, marginLeft: '8px' }}>
                ({rank.totalAttempts} attempts, {rank.failedAttempts} failed)
              </span>
            </div>
            <div style={{
              background: rank.cds != null ? getCDSColor(rank.cds) : TOKENS.muted,
              color: TOKENS.primaryFg,
              padding: '4px 8px',
              borderRadius: '4px',
              fontWeight: 700,
              fontFamily: TOKENS.fontMono,
            }}>
              {rank.cds != null ? rank.cds.toFixed(2) : '—'}{' '}
              {rank.cds != null ? getCDSLabel(rank.cds) : 'Unscored'}
            </div>
          </div>
        ))}
      </div>

      <div style={{ fontSize: '10px', color: TOKENS.muted, marginTop: '12px', textAlign: 'center' }}>
        {autoRefresh ? 'Auto-refreshing...' : 'Click refresh to update'}
      </div>
    </div>
  );
}
