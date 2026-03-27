import { useState, useEffect } from 'react';
import { useParams } from 'react-router-dom';
import api from '../../services/api';
import { useSidebar } from '../../context/SidebarContext';

export default function InstructorAnalytics() {
  const { isOpen } = useSidebar();
  const [sections, setSections] = useState([]);
  const [selectedSection, setSelectedSection] = useState(null);
  const [heatmapData, setHeatmapData] = useState(null);
  const [loading, setLoading] = useState(false);

  useEffect(() => {
    fetchSections();
  }, []);

  const fetchSections = async () => {
    try {
      const res = await api.get('/api/sections');
      setSections(res.data || []);
      if (res.data?.length > 0) {
        setSelectedSection(res.data[0].id);
      }
    } catch (err) {
      console.error('Error fetching sections:', err);
    }
  };

  useEffect(() => {
    if (selectedSection) {
      fetchHeatmap(selectedSection);
    }
  }, [selectedSection]);

  const fetchHeatmap = async (sectionId) => {
    setLoading(true);
    try {
      const res = await api.get(`/api/analytics/heatmap/${sectionId}`);
      setHeatmapData(res.data);
    } catch (err) {
      console.error('Error fetching heatmap:', err);
    } finally {
      setLoading(false);
    }
  };

  const formatNumber = (value, decimals = 2) => {
    if (value === null || value === undefined) return '-';
    const num = typeof value === 'string' ? parseFloat(value) : value;
    return isNaN(num) ? '-' : num.toFixed(decimals);
  };

  return (
    <div style={{ 
      padding: '28px 28px 28px 16px',
      width: '100%',
      boxSizing: 'border-box'
    }}>
      <h1 style={{ fontSize: '20px', fontWeight: 700, color: '#e6edf3', marginBottom: '24px' }}>
        Analytics Dashboard
      </h1>

      <div style={{ marginBottom: '24px' }}>
        <label style={{ fontSize: '12px', color: '#8b949e', marginBottom: '8px', display: 'block' }}>
          Select Section
        </label>
        <select 
          value={selectedSection || ''}
          onChange={(e) => setSelectedSection(parseInt(e.target.value))}
          style={{ width: '200px' }}
        >
          <option value="">Choose a section...</option>
          {sections.map(s => (
            <option key={s.id} value={s.id}>{s.name}</option>
          ))}
        </select>
      </div>

      {loading ? (
        <div style={{ color: '#8b949e' }}>Loading...</div>
      ) : heatmapData ? (
        <div>
          <div style={{ marginBottom: '24px' }}>
            <h2 style={{ fontSize: '14px', fontWeight: 700, color: '#e6edf3', marginBottom: '12px' }}>
              Class Concept Averages
            </h2>
            <div style={{ display: 'grid', gridTemplateColumns: 'repeat(auto-fill, minmax(180px, 1fr))', gap: '12px' }}>
              {heatmapData.concepts.map(concept => {
                const avg = heatmapData.classAverages[concept];
                let color = '#f87171'; // red
                if (avg?.avgCDS !== null) {
                  if (avg.avgCDS <= 0.33) color = '#4ade80'; // green
                  else if (avg.avgCDS <= 0.66) color = '#fbbf24'; // amber
                }
                return (
                  <div key={concept} style={{
                    background: '#161b22',
                    border: `2px solid ${color}`,
                    borderRadius: '6px',
                    padding: '12px'
                  }}>
                    <div style={{ fontSize: '12px', fontWeight: 700, color: '#e6edf3', marginBottom: '4px' }}>
                      {concept}
                    </div>
                    <div style={{ fontSize: '14px', fontWeight: 700, color }}>
                      {avg?.avgCDS !== null ? avg.avgCDS.toFixed(3) : 'N/A'}
                    </div>
                    <div style={{ fontSize: '10px', color: '#8b949e' }}>
                      {avg?.classification || 'Unscored'}
                    </div>
                  </div>
                );
              })}
            </div>
          </div>

          <div>
            <h2 style={{ fontSize: '14px', fontWeight: 700, color: '#e6edf3', marginBottom: '12px' }}>
              Student Performance Heatmap
            </h2>
            <div style={{
              overflowX: 'auto',
              background: '#161b22',
              borderRadius: '6px',
              border: '1px solid #30363d',
              padding: '12px'
            }}>
              <table style={{ width: '100%', borderCollapse: 'collapse', fontSize: '11px' }}>
                <thead>
                  <tr>
                    <th style={{ 
                      textAlign: 'left', 
                      padding: '8px', 
                      borderBottom: '1px solid #30363d',
                      fontWeight: 700,
                      color: '#8b949e'
                    }}>Student</th>
                    {heatmapData.concepts.map(c => (
                      <th key={c} style={{ 
                        textAlign: 'center', 
                        padding: '8px',
                        borderBottom: '1px solid #30363d',
                        fontWeight: 700,
                        color: '#8b949e'
                      }}>{c}</th>
                    ))}
                  </tr>
                </thead>
                <tbody>
                  {heatmapData.students.map(student => (
                    <tr key={student.id}>
                      <td style={{ padding: '8px', borderBottom: '1px solid #21262d', color: '#e6edf3' }}>
                        {student.name}
                      </td>
                      {heatmapData.concepts.map(concept => {
                        const score = heatmapData.scores[student.id]?.[concept];
                        const cds = score?.cds;
                        const cdsNum = typeof cds === 'string' ? parseFloat(cds) : cds;
                        let cellColor = 'transparent';
                        if (cdsNum !== undefined && cdsNum !== null && !isNaN(cdsNum)) {
                          if (cdsNum <= 0.33) cellColor = 'rgba(74,222,128,0.15)';
                          else if (cdsNum <= 0.66) cellColor = 'rgba(251,191,36,0.15)';
                          else cellColor = 'rgba(248,113,113,0.15)';
                        }
                        return (
                          <td key={concept} style={{
                            padding: '8px',
                            textAlign: 'center',
                            borderBottom: '1px solid #21262d',
                            background: cellColor,
                            color: '#e6edf3'
                          }}>
                            {formatNumber(cds)}
                          </td>
                        );
                      })}
                    </tr>
                  ))}
                </tbody>
              </table>
            </div>
          </div>
        </div>
      ) : (
        <div style={{ color: '#8b949e' }}>No data available</div>
      )}
    </div>
  );
}
