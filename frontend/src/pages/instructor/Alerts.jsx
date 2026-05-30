import { useState, useEffect } from 'react';
import api from '../../services/api';
import { useSidebar } from '../../context/SidebarContext';

export default function InstructorAlerts() {
  const [sections, setSections] = useState([]);
  const [selectedSection, setSelectedSection] = useState(null);
  const [selectedSectionData, setSelectedSectionData] = useState(null);
  const [alerts, setAlerts] = useState([]);
  const { isOpen } = useSidebar();
  const [loading, setLoading] = useState(true);
  const [reviewingId, setReviewingId] = useState(null);

  useEffect(() => {
    fetchSections();
  }, []);

  const fetchSections = async () => {
    try {
      const res = await api.get('/api/sections');
      setSections(res.data || []);
      if (res.data?.length > 0) {
        setSelectedSection(res.data[0].id);
        setSelectedSectionData(res.data[0]);
      }
    } catch (err) {
      console.error('Error fetching sections:', err);
    } finally {
      setLoading(false);
    }
  };

  useEffect(() => {
    if (selectedSection) {
      const data = sections.find(s => s.id === selectedSection);
      setSelectedSectionData(data);
      fetchAlerts(selectedSection);
    }
  }, [selectedSection, sections]);

  const fetchAlerts = async (sectionId) => {
    try {
      const res = await api.get(`/api/analytics/alerts/${sectionId}`);
      setAlerts(res.data || []);
    } catch (err) {
      console.error('Error fetching alerts:', err);
      setAlerts([]);
    }
  };

  const markReviewed = async (alertId) => {
    setReviewingId(alertId);
    try {
      await api.put(`/api/analytics/alerts/${alertId}/review`);
      setAlerts(alerts.filter(a => a.id !== alertId));
    } catch (err) {
      console.error('Error marking alert as reviewed:', err);
    } finally {
      setReviewingId(null);
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

  const getDifficultyLabel = (cds) => {
    if (cds === null || cds === undefined) return 'Unscored';
    if (cds <= 0.33) return 'Low';
    if (cds <= 0.66) return 'Moderate';
    return 'High';
  };

  if (loading) {
    return <div style={{ padding: '40px', color: '#8884a0' }}>Loading...</div>;
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
      <div style={{ marginBottom: '28px' }}>
        <div style={{ fontSize: '17px', fontWeight: 700, color: '#e8e6f0', marginBottom: '2px' }}>
          Early Alerts
        </div>
        <div style={{ fontSize: '11px', color: '#8884a0' }}>
          Monitor high-difficulty submissions from your students
        </div>
      </div>

      {/* Section Selector */}
      <div style={{ marginBottom: '28px' }}>
        <label style={{ fontSize: '11px', fontWeight: 600, letterSpacing: '0.8px', textTransform: 'uppercase', color: '#8884a0', marginBottom: '8px', display: 'block' }}>
          Select Section
        </label>
        <div style={{ position: 'relative', width: '280px' }}>
          <select 
            value={selectedSection || ''}
            onChange={(e) => setSelectedSection(parseInt(e.target.value))}
            style={{
              width: '100%',
              background: '#131d30',
              border: '1px solid #1e304d',
              borderRadius: '8px',
              padding: '10px 13px',
              fontSize: '13px',
              color: '#e8e6f0',
              fontFamily: 'DM Sans, sans-serif',
              outline: 'none',
              appearance: 'none',
              cursor: 'pointer',
              boxSizing: 'border-box'
            }}
          >
            <option value="">Choose a section...</option>
            {sections.map(s => (
              <option key={s.id} value={s.id}>{s.name}</option>
            ))}
          </select>
          <div style={{ position: 'absolute', right: '12px', top: '50%', transform: 'translateY(-50%)', color: '#8884a0', pointerEvents: 'none', fontSize: '12px' }}>
            ▾
          </div>
        </div>
      </div>

      {/* Alerts Stats (if section selected) */}
      {selectedSectionData && (
        <div style={{ marginBottom: '28px', display: 'grid', gridTemplateColumns: 'repeat(3, 1fr)', gap: '14px' }}>
          <div style={{
            background: '#1a1a2e',
            border: '1px solid #2e2e4a',
            borderRadius: '12px',
            padding: '16px'
          }}>
            <div style={{ fontSize: '10px', fontWeight: 600, letterSpacing: '1px', textTransform: 'uppercase', color: '#8884a0', marginBottom: '6px' }}>
              Total Alerts
            </div>
            <div style={{ fontSize: '20px', fontWeight: 700, color: '#e8e6f0' }}>
              {selectedSectionData.alert_count || 0}
            </div>
          </div>
          <div style={{
            background: '#1a1a2e',
            border: '1px solid #2e2e4a',
            borderRadius: '12px',
            padding: '16px'
          }}>
            <div style={{ fontSize: '10px', fontWeight: 600, letterSpacing: '1px', textTransform: 'uppercase', color: '#8884a0', marginBottom: '6px' }}>
              Students
            </div>
            <div style={{ fontSize: '20px', fontWeight: 700, color: '#e8e6f0' }}>
              {selectedSectionData.student_count || 0}
            </div>
          </div>
          <div style={{
            background: '#1a1a2e',
            border: '1px solid #2e2e4a',
            borderRadius: '12px',
            padding: '16px'
          }}>
            <div style={{ fontSize: '10px', fontWeight: 600, letterSpacing: '1px', textTransform: 'uppercase', color: '#8884a0', marginBottom: '6px' }}>
              Pending Review
            </div>
            <div style={{ fontSize: '20px', fontWeight: 700, color: '#f87171' }}>
              {alerts.length}
            </div>
          </div>
        </div>
      )}

      {/* Alerts List */}
      {alerts.length === 0 ? (
        <div style={{
          background: '#1a1a2e',
          border: '1px solid #2e2e4a',
          borderRadius: '12px',
          padding: '40px',
          textAlign: 'center'
        }}>
          <div style={{ color: '#8884a0', fontSize: '14px' }}>
            ✓ No high-difficulty alerts in this section
          </div>
          <div style={{ color: '#8884a0', fontSize: '12px', marginTop: '8px' }}>
            All students are performing well
          </div>
        </div>
      ) : (
        <div style={{ display: 'grid', gap: '14px' }}>
          {alerts.map((alert, idx) => (
            <div key={alert.id} style={{
              background: '#1a1a2e',
              border: '1px solid #2e2e4a',
              borderRadius: '12px',
              padding: '18px',
              display: 'flex',
              alignItems: 'center',
              justifyContent: 'space-between',
              transition: 'all 0.15s',
              hover: {
                borderColor: '#85D2D0'
              }
            }}>
              {/* Left: Alert Info */}
              <div style={{ flex: 1, display: 'grid', gridTemplateColumns: '1fr 1fr 1fr 1fr', gap: '20px', alignItems: 'center' }}>
                {/* Student */}
                <div>
                  <div style={{ fontSize: '10px', fontWeight: 600, letterSpacing: '0.8px', textTransform: 'uppercase', color: '#8884a0', marginBottom: '4px' }}>
                    Student
                  </div>
                  <div style={{ fontSize: '13px', fontWeight: 600, color: '#e8e6f0' }}>
                    {alert.student_name}
                  </div>
                </div>

                {/* Concept */}
                <div>
                  <div style={{ fontSize: '10px', fontWeight: 600, letterSpacing: '0.8px', textTransform: 'uppercase', color: '#8884a0', marginBottom: '4px' }}>
                    Concept
                  </div>
                  <div style={{ fontSize: '13px', fontWeight: 600, color: '#85D2D0' }}>
                    {alert.concept_name}
                  </div>
                </div>

                {/* Exercise */}
                <div>
                  <div style={{ fontSize: '10px', fontWeight: 600, letterSpacing: '0.8px', textTransform: 'uppercase', color: '#8884a0', marginBottom: '4px' }}>
                    Exercise
                  </div>
                  <div style={{ fontSize: '13px', color: '#e8e6f0' }}>
                    {alert.exercise_title?.substring(0, 20)}
                    {alert.exercise_title?.length > 20 ? '...' : ''}
                  </div>
                </div>

                {/* CDS Score */}
                <div>
                  <div style={{ fontSize: '10px', fontWeight: 600, letterSpacing: '0.8px', textTransform: 'uppercase', color: '#8884a0', marginBottom: '4px' }}>
                    CDS Score
                  </div>
                  <div style={{
                    display: 'inline-flex',
                    alignItems: 'center',
                    gap: '6px',
                    background: 'rgba(248,113,113,0.1)',
                    border: `1px solid ${getDifficultyColor(alert.cds_score)}`,
                    borderRadius: '6px',
                    padding: '4px 10px',
                    fontSize: '12px',
                    fontWeight: 700,
                    color: getDifficultyColor(alert.cds_score)
                  }}>
                    <span style={{ width: '6px', height: '6px', borderRadius: '50%', background: getDifficultyColor(alert.cds_score) }}></span>
                    {getDifficultyLabel(alert.cds_score)} ({formatCDS(alert.cds_score)})
                  </div>
                </div>
              </div>

              {/* Right: Action Button */}
              <button 
                onClick={() => markReviewed(alert.id)}
                disabled={reviewingId === alert.id}
                style={{
                  padding: '8px 16px',
                  background: reviewingId === alert.id ? '#2e2e4a' : '#85D2D0',
                  border: 'none',
                  borderRadius: '8px',
                  color: reviewingId === alert.id ? '#8884a0' : '#0a1a1a',
                  fontSize: '12px',
                  fontWeight: 600,
                  cursor: reviewingId === alert.id ? 'not-allowed' : 'pointer',
                  whiteSpace: 'nowrap',
                  fontFamily: 'DM Sans, sans-serif',
                  transition: 'all 0.15s',
                  opacity: reviewingId === alert.id ? 0.6 : 1
                }}
                onMouseEnter={(e) => !reviewingId && (e.target.style.background = '#9ae0de')}
                onMouseLeave={(e) => !reviewingId && (e.target.style.background = '#85D2D0')}
              >
                {reviewingId === alert.id ? 'Marking...' : 'Mark Reviewed'}
              </button>
            </div>
          ))}
        </div>
      )}
    </div>
  );
}
