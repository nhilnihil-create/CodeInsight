import { useState, useEffect } from 'react';
import api from '../../services/api';
import { useSidebar } from '../../context/SidebarContext';

export default function InstructorDeveloper() {
  const { isOpen } = useSidebar();
  const [sections, setSections] = useState([]);
  const [selectedSection, setSelectedSection] = useState(null);
  const [exercises, setExercises] = useState([]);
  const [selectedExercise, setSelectedExercise] = useState(null);
  const [students, setStudents] = useState([]);
  const [selectedStudent, setSelectedStudent] = useState(null);
  
  // Class maximums (user inputs)
  const [maxFailed, setMaxFailed] = useState(5);
  const [maxTotal, setMaxTotal] = useState(10);
  const [maxTime, setMaxTime] = useState(3600);
  
  // Student data
  const [studentData, setStudentData] = useState(null);
  const [cdsResult, setCdsResult] = useState(null);

  useEffect(() => {
    fetchSections();
  }, []);

  useEffect(() => {
    if (selectedSection) {
      fetchExercises(selectedSection);
      fetchStudents(selectedSection);
    }
  }, [selectedSection]);

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

  const fetchExercises = async (sectionId) => {
    try {
      const res = await api.get(`/api/exercises`);
      // Filter exercises by section
      const filtered = (res.data || []).filter(ex => ex.section_id === sectionId);
      setExercises(filtered);
      if (filtered.length > 0) {
        setSelectedExercise(filtered[0].id);
      }
    } catch (err) {
      console.error('Error fetching exercises:', err);
    }
  };

  const fetchStudents = async (sectionId) => {
    try {
      const res = await api.get(`/api/sections/${sectionId}/students`);
      setStudents(res.data || []);
      if (res.data?.length > 0) {
        setSelectedStudent(res.data[0].id);
      }
    } catch (err) {
      console.error('Error fetching students:', err);
    }
  };

  const calculateCDS = async () => {
    if (!selectedStudent || !selectedExercise) {
      alert('Please select a student and exercise');
      return;
    }

    try {
      const res = await api.get(
        `/api/submissions/${selectedStudent}/${selectedExercise}`
      );
      const submissions = res.data || [];

      if (!submissions.length) {
        alert('No submissions found for this student and exercise');
        return;
      }

      const failedCount = submissions.filter(s => !s.is_correct).length;
      const totalCount = submissions.length;
      const maxTimeUsed = Math.max(...submissions.map(s => s.time_spent_seconds || 0));

      // Prevent division by zero
      const mf = maxFailed || 1;
      const mt = maxTotal || 1;

      // Calculate NER, NRS, NTS
      const ner = Math.min(1, failedCount / mf);
      const nrs = Math.min(1, totalCount / mt);
      const nts = Math.min(1, maxTimeUsed / maxTime);

      // Calculate CDS: 40% NER + 35% NRS + 25% NTS
      const cds = (0.4 * ner) + (0.35 * nrs) + (0.25 * nts);
      const classification = 
        cds <= 0.33 ? 'Low' : 
        cds <= 0.66 ? 'Moderate' : 
        'High';

      setStudentData({
        failedCount,
        totalCount,
        maxTimeUsed,
      });

      setCdsResult({
        ner: ner.toFixed(4),
        nrs: nrs.toFixed(4),
        nts: nts.toFixed(4),
        cds: cds.toFixed(4),
        classification
      });
    } catch (err) {
      console.error('Error calculating CDS:', err);
      alert('Error calculating CDS');
    }
  };

  const formatTime = (seconds) => {
    const h = Math.floor(seconds / 3600);
    const m = Math.floor((seconds % 3600) / 60);
    const s = seconds % 60;
    return `${h}:${m.toString().padStart(2, '0')}:${s.toString().padStart(2, '0')}`;
  };

  return (
    <div style={{
      padding: '28px 28px 28px 16px',
      width: '100%',
      boxSizing: 'border-box'
    }}>
      <h1 style={{ fontSize: '20px', fontWeight: 700, color: '#e6edf3', marginBottom: '24px' }}>
        Developer Settings - CDS Calculator
      </h1>

      <div style={{ display: 'grid', gridTemplateColumns: 'repeat(auto-fit, minmax(300px, 1fr))', gap: '24px' }}>
        {/* Left Panel: Inputs */}
        <div>
          <h2 style={{ fontSize: '14px', fontWeight: 700, color: '#e6edf3', marginBottom: '16px' }}>
            Configuration
          </h2>

          <div style={{ marginBottom: '16px' }}>
            <label style={{ display: 'block', fontSize: '12px', color: '#8b949e', marginBottom: '6px', fontWeight: 600 }}>
              Section
            </label>
            <select
              value={selectedSection || ''}
              onChange={(e) => setSelectedSection(parseInt(e.target.value))}
              style={{
                width: '100%',
                padding: '8px 10px',
                background: '#0d1117',
                border: '1px solid #30363d',
                borderRadius: '6px',
                color: '#e6edf3',
                fontSize: '12px',
                boxSizing: 'border-box'
              }}
            >
              <option value="">Select section...</option>
              {sections.map(s => (
                <option key={s.id} value={s.id}>{s.name}</option>
              ))}
            </select>
          </div>

          <div style={{ marginBottom: '16px' }}>
            <label style={{ display: 'block', fontSize: '12px', color: '#8b949e', marginBottom: '6px', fontWeight: 600 }}>
              Exercise
            </label>
            <select
              value={selectedExercise || ''}
              onChange={(e) => setSelectedExercise(parseInt(e.target.value))}
              style={{
                width: '100%',
                padding: '8px 10px',
                background: '#0d1117',
                border: '1px solid #30363d',
                borderRadius: '6px',
                color: '#e6edf3',
                fontSize: '12px',
                boxSizing: 'border-box'
              }}
            >
              <option value="">Select exercise...</option>
              {exercises.map(e => (
                <option key={e.id} value={e.id}>{e.title}</option>
              ))}
            </select>
          </div>

          <div style={{ marginBottom: '16px' }}>
            <label style={{ display: 'block', fontSize: '12px', color: '#8b949e', marginBottom: '6px', fontWeight: 600 }}>
              Student
            </label>
            <select
              value={selectedStudent || ''}
              onChange={(e) => setSelectedStudent(parseInt(e.target.value))}
              style={{
                width: '100%',
                padding: '8px 10px',
                background: '#0d1117',
                border: '1px solid #30363d',
                borderRadius: '6px',
                color: '#e6edf3',
                fontSize: '12px',
                boxSizing: 'border-box'
              }}
            >
              <option value="">Select student...</option>
              {students.map(s => (
                <option key={s.id} value={s.id}>{s.name}</option>
              ))}
            </select>
          </div>

          <div style={{ marginBottom: '16px', padding: '16px', background: '#161b22', borderRadius: '6px', border: '1px solid #30363d' }}>
            <label style={{ display: 'block', fontSize: '12px', color: '#8b949e', marginBottom: '6px', fontWeight: 600 }}>
              Class Max Failed Attempts: <span style={{ color: '#85D2D0', fontWeight: 700 }}>{maxFailed}</span>
            </label>
            <input
              type="number"
              value={maxFailed}
              onChange={(e) => setMaxFailed(parseInt(e.target.value) || 1)}
              min="1"
              style={{
                width: '100%',
                padding: '8px 10px',
                background: '#0d1117',
                border: '1px solid #30363d',
                borderRadius: '4px',
                color: '#e6edf3',
                fontSize: '12px',
                boxSizing: 'border-box'
              }}
            />
          </div>

          <div style={{ marginBottom: '16px', padding: '16px', background: '#161b22', borderRadius: '6px', border: '1px solid #30363d' }}>
            <label style={{ display: 'block', fontSize: '12px', color: '#8b949e', marginBottom: '6px', fontWeight: 600 }}>
              Class Max Total Attempts: <span style={{ color: '#85D2D0', fontWeight: 700 }}>{maxTotal}</span>
            </label>
            <input
              type="number"
              value={maxTotal}
              onChange={(e) => setMaxTotal(parseInt(e.target.value) || 1)}
              min="1"
              style={{
                width: '100%',
                padding: '8px 10px',
                background: '#0d1117',
                border: '1px solid #30363d',
                borderRadius: '4px',
                color: '#e6edf3',
                fontSize: '12px',
                boxSizing: 'border-box'
              }}
            />
          </div>

          <div style={{ marginBottom: '16px', padding: '16px', background: '#161b22', borderRadius: '6px', border: '1px solid #30363d' }}>
            <label style={{ display: 'block', fontSize: '12px', color: '#8b949e', marginBottom: '6px', fontWeight: 600 }}>
              Class Max Time (seconds): <span style={{ color: '#85D2D0', fontWeight: 700 }}>{formatTime(maxTime)}</span>
            </label>
            <input
              type="number"
              value={maxTime}
              onChange={(e) => setMaxTime(parseInt(e.target.value) || 1)}
              min="1"
              style={{
                width: '100%',
                padding: '8px 10px',
                background: '#0d1117',
                border: '1px solid #30363d',
                borderRadius: '4px',
                color: '#e6edf3',
                fontSize: '12px',
                boxSizing: 'border-box'
              }}
            />
          </div>

          <button
            onClick={calculateCDS}
            style={{
              width: '100%',
              padding: '10px 14px',
              background: '#85D2D0',
              border: 'none',
              borderRadius: '6px',
              color: '#0a1a1a',
              fontWeight: 700,
              fontSize: '12px',
              cursor: 'pointer',
              transition: 'all 0.2s'
            }}
          >
            Calculate CDS
          </button>
        </div>

        {/* Right Panel: Results */}
        <div>
          <h2 style={{ fontSize: '14px', fontWeight: 700, color: '#e6edf3', marginBottom: '16px' }}>
            Results
          </h2>

          {studentData && (
            <div style={{
              padding: '16px',
              background: '#161b22',
              borderRadius: '6px',
              border: '1px solid #30363d',
              marginBottom: '16px'
            }}>
              <h3 style={{ fontSize: '12px', fontWeight: 700, color: '#8b949e', marginBottom: '12px' }}>
                Student Submission Data
              </h3>
              <div style={{ display: 'grid', gap: '8px', fontSize: '12px' }}>
                <div style={{ display: 'flex', justifyContent: 'space-between' }}>
                  <span style={{ color: '#8b949e' }}>Failed Attempts:</span>
                  <span style={{ color: '#e6edf3', fontWeight: 700 }}>{studentData.failedCount}</span>
                </div>
                <div style={{ display: 'flex', justifyContent: 'space-between' }}>
                  <span style={{ color: '#8b949e' }}>Total Attempts:</span>
                  <span style={{ color: '#e6edf3', fontWeight: 700 }}>{studentData.totalCount}</span>
                </div>
                <div style={{ display: 'flex', justifyContent: 'space-between' }}>
                  <span style={{ color: '#8b949e' }}>Max Time Spent:</span>
                  <span style={{ color: '#e6edf3', fontWeight: 700 }}>{formatTime(studentData.maxTimeUsed)}</span>
                </div>
              </div>
            </div>
          )}

          {cdsResult && (
            <div>
              <div style={{
                padding: '16px',
                background: '#161b22',
                borderRadius: '6px',
                border: '1px solid #30363d',
                marginBottom: '16px'
              }}>
                <h3 style={{ fontSize: '12px', fontWeight: 700, color: '#8b949e', marginBottom: '12px' }}>
                  Metric Calculations
                </h3>
                <div style={{ display: 'grid', gap: '10px' }}>
                  <div style={{
                    padding: '10px',
                    background: '#0d1117',
                    borderRadius: '4px',
                    border: '1px solid #30363d'
                  }}>
                    <div style={{ fontSize: '11px', color: '#8b949e', marginBottom: '2px' }}>
                      NER (Normalized Error Rate) = 40%
                    </div>
                    <div style={{ fontSize: '11px', color: '#8b949e', marginBottom: '4px' }}>
                      Failed / Class Max Failed = {studentData.failedCount} / {maxFailed}
                    </div>
                    <div style={{ fontSize: '14px', fontWeight: 700, color: '#fbbf24' }}>
                      {cdsResult.ner}
                    </div>
                  </div>

                  <div style={{
                    padding: '10px',
                    background: '#0d1117',
                    borderRadius: '4px',
                    border: '1px solid #30363d'
                  }}>
                    <div style={{ fontSize: '11px', color: '#8b949e', marginBottom: '2px' }}>
                      NRS (Normalized Request Score) = 35%
                    </div>
                    <div style={{ fontSize: '11px', color: '#8b949e', marginBottom: '4px' }}>
                      Total / Class Max Total = {studentData.totalCount} / {maxTotal}
                    </div>
                    <div style={{ fontSize: '14px', fontWeight: 700, color: '#fbbf24' }}>
                      {cdsResult.nrs}
                    </div>
                  </div>

                  <div style={{
                    padding: '10px',
                    background: '#0d1117',
                    borderRadius: '4px',
                    border: '1px solid #30363d'
                  }}>
                    <div style={{ fontSize: '11px', color: '#8b949e', marginBottom: '2px' }}>
                      NTS (Normalized Time Score) = 25%
                    </div>
                    <div style={{ fontSize: '11px', color: '#8b949e', marginBottom: '4px' }}>
                      Time Used / Class Max Time = {formatTime(studentData.maxTimeUsed)} / {formatTime(maxTime)}
                    </div>
                    <div style={{ fontSize: '14px', fontWeight: 700, color: '#fbbf24' }}>
                      {cdsResult.nts}
                    </div>
                  </div>
                </div>
              </div>

              <div style={{
                padding: '16px',
                background: '#161b22',
                borderRadius: '6px',
                border: `2px solid ${
                  cdsResult.classification === 'Low' ? '#4ade80' :
                  cdsResult.classification === 'Moderate' ? '#fbbf24' :
                  '#f87171'
                }`
              }}>
                <div style={{ fontSize: '11px', color: '#8b949e', marginBottom: '8px', fontWeight: 600 }}>
                  FINAL CDS SCORE
                </div>
                <div style={{
                  fontSize: '18px',
                  fontWeight: 700,
                  color: cdsResult.classification === 'Low' ? '#4ade80' :
                          cdsResult.classification === 'Moderate' ? '#fbbf24' :
                          '#f87171',
                  marginBottom: '8px'
                }}>
                  {cdsResult.cds}
                </div>
                <div style={{
                  fontSize: '12px',
                  fontWeight: 700,
                  color: '#e6edf3'
                }}>
                  Classification: <span style={{
                    color: cdsResult.classification === 'Low' ? '#4ade80' :
                            cdsResult.classification === 'Moderate' ? '#fbbf24' :
                            '#f87171'
                  }}>
                    {cdsResult.classification}
                  </span>
                </div>
                <div style={{ fontSize: '10px', color: '#8b949e', marginTop: '8px', marginBottom: 0 }}>
                  CDS = (0.40 × NER) + (0.35 × NRS) + (0.25 × NTS)
                </div>
                <div style={{ fontSize: '10px', color: '#8b949e', marginBottom: 0 }}>
                  CDS = (0.40 × {cdsResult.ner}) + (0.35 × {cdsResult.nrs}) + (0.25 × {cdsResult.nts})
                </div>
              </div>
            </div>
          )}

          {!cdsResult && (
            <div style={{
              padding: '40px 20px',
              textAlign: 'center',
              color: '#8b949e',
              fontSize: '12px'
            }}>
              Select a section, exercise, student and click "Calculate CDS" to see results
            </div>
          )}
        </div>
      </div>
    </div>
  );
}
