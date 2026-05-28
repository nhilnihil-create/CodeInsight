import { useState, useEffect } from 'react';
import { useNavigate } from 'react-router-dom';
import api from '../../services/api';
import { useSidebar } from '../../context/SidebarContext';

const CONCEPTS = ['Datatypes', 'Variables', 'Conditionals', 'Loops', 'Functions', 'Arrays', 'OOP'];

export default function InstructorCreateExercise() {
  const { isOpen } = useSidebar();
  const navigate = useNavigate();
  const [sections, setSections] = useState([]);
  const [selectedConcept, setSelectedConcept] = useState(null);
  const [formData, setFormData] = useState({
    title: '',
    description: '',
    section_id: '',
    concept_name: '',
    time_limit_minutes: 45,
    deadline: '',
    track_ner: true,
    track_nrs: true,
    track_nts: true,
    auto_alert: true,
    test_cases: [{ input: '', expected_output: '', hidden: false }]
  });
  const [loading, setLoading] = useState(true);
  const [submitting, setSubmitting] = useState(false);

  useEffect(() => {
    fetchSections();
  }, []);

  const fetchSections = async () => {
    try {
      const res = await api.get('/api/sections');
      setSections(res.data || []);
    } catch (err) {
      console.error('Error fetching sections:', err);
    } finally {
      setLoading(false);
    }
  };

  const handleConceptSelect = (concept) => {
    setSelectedConcept(concept);
    setFormData({ ...formData, concept_name: concept });
  };

  const handleTestCaseChange = (index, field, value) => {
    const newCases = [...formData.test_cases];
    newCases[index][field] = value;
    setFormData({ ...formData, test_cases: newCases });
  };

  const addTestCase = () => {
    setFormData({
      ...formData,
      test_cases: [...formData.test_cases, { input: '', expected_output: '', hidden: false }]
    });
  };

  const removeTestCase = (index) => {
    setFormData({
      ...formData,
      test_cases: formData.test_cases.filter((_, i) => i !== index)
    });
  };

  const handleSubmit = async (e, isDraft = false) => {
    e.preventDefault();
    if (!formData.title || !formData.description || !formData.section_id || !formData.concept_name) {
      alert('Please fill all required fields');
      return;
    }
    if (formData.test_cases.length < 2 || formData.test_cases.some(tc => !tc.input || !tc.expected_output)) {
      alert('Please add at least 2 complete test cases');
      return;
    }
    setSubmitting(true);
    try {
      await api.post('/api/exercises', {
        ...formData,
        is_draft: isDraft
      });
      alert(isDraft ? 'Exercise saved as draft!' : 'Exercise published successfully!');
      navigate('/instructor/sections');
    } catch (err) {
      alert('Error: ' + (err.response?.data?.message || err.message));
    } finally {
      setSubmitting(false);
    }
  };

  if (loading) {
    return <div style={{ padding: '40px', color: '#8884a0' }}>Loading...</div>;
  }

  return (
    <div style={{ 
      padding: '28px',
      width: '100%',
      boxSizing: 'border-box',
      overflowY: 'auto',
      height: '100vh'
    }}>
      {/* Top Bar */}
      <div style={{ marginBottom: '28px' }}>
        <div style={{ fontSize: '17px', fontWeight: 700, color: '#e8e6f0', marginBottom: '2px' }}>
          Create New Exercise
        </div>
        <div style={{ fontSize: '11px', color: '#8884a0' }}>
          Tag a concept · Set test cases · Assign to class
        </div>
      </div>

      <form onSubmit={(e) => handleSubmit(e, false)} style={{ display: 'grid', gridTemplateColumns: '1.4fr 0.6fr', gap: '20px', alignItems: 'start' }}>
        {/* Left: Main Form */}
        <div>
          {/* Exercise Details Card */}
          <div style={{
            background: '#1a1a2e',
            border: '1px solid #2e2e4a',
            borderRadius: '14px',
            padding: '24px',
            marginBottom: '16px'
          }}>
            <div style={{ fontSize: '13px', fontWeight: 700, color: '#e8e6f0', marginBottom: '20px', paddingBottom: '12px', borderBottom: '1px solid #2e2e4a' }}>
              Exercise Details
            </div>

            {/* Title */}
            <div style={{ marginBottom: '18px' }}>
              <label style={{ fontSize: '11px', fontWeight: 600, letterSpacing: '0.8px', textTransform: 'uppercase', color: '#8884a0', marginBottom: '7px', display: 'block' }}>
                Exercise Title
              </label>
              <input 
                type="text"
                required
                value={formData.title}
                onChange={(e) => setFormData({ ...formData, title: e.target.value })}
                placeholder="e.g., Basic For Loop — Sum of Array Elements"
                style={{
                  width: '100%',
                  background: '#22223a',
                  border: '1px solid #2e2e4a',
                  borderRadius: '8px',
                  padding: '10px 13px',
                  fontSize: '13px',
                  color: '#e8e6f0',
                  fontFamily: 'DM Sans, sans-serif',
                  outline: 'none',
                  transition: 'border-color 0.15s',
                  boxSizing: 'border-box'
                }}
                onFocus={(e) => e.target.style.borderColor = '#85D2D0'}
                onBlur={(e) => e.target.style.borderColor = '#2e2e4a'}
              />
            </div>

            {/* Description */}
            <div style={{ marginBottom: '18px' }}>
              <label style={{ fontSize: '11px', fontWeight: 600, letterSpacing: '0.8px', textTransform: 'uppercase', color: '#8884a0', marginBottom: '7px', display: 'block' }}>
                Problem Description
              </label>
              <textarea 
                required
                value={formData.description}
                onChange={(e) => setFormData({ ...formData, description: e.target.value })}
                placeholder="Describe the problem..."
                style={{
                  width: '100%',
                  background: '#22223a',
                  border: '1px solid #2e2e4a',
                  borderRadius: '8px',
                  padding: '10px 13px',
                  fontSize: '13px',
                  color: '#e8e6f0',
                  fontFamily: 'DM Sans, sans-serif',
                  outline: 'none',
                  resize: 'vertical',
                  minHeight: '90px',
                  transition: 'border-color 0.15s',
                  boxSizing: 'border-box'
                }}
                onFocus={(e) => e.target.style.borderColor = '#85D2D0'}
                onBlur={(e) => e.target.style.borderColor = '#2e2e4a'}
              />
            </div>

            {/* Concept Pills */}
            <div style={{ marginBottom: '18px' }}>
              <label style={{ fontSize: '11px', fontWeight: 600, letterSpacing: '0.8px', textTransform: 'uppercase', color: '#8884a0', marginBottom: '7px', display: 'block' }}>
                Concept Tag <span style={{ color: '#f87171', fontSize: '10px' }}>*required</span>
              </label>
              <div style={{ display: 'flex', flexWrap: 'wrap', gap: '8px', marginTop: '4px' }}>
                {CONCEPTS.map(concept => (
                  <button
                    key={concept}
                    type="button"
                    onClick={() => handleConceptSelect(concept)}
                    style={{
                      padding: '6px 14px',
                      borderRadius: '20px',
                      fontSize: '11px',
                      fontWeight: 600,
                      cursor: 'pointer',
                      border: '1.5px solid ' + (selectedConcept === concept ? '#887BB0' : '#2e2e4a'),
                      color: selectedConcept === concept ? '#a99dd4' : '#8884a0',
                      background: selectedConcept === concept ? 'rgba(136,123,176,0.15)' : 'transparent',
                      fontFamily: 'DM Sans, sans-serif',
                      transition: 'all 0.15s'
                    }}
                  >
                    {concept}
                  </button>
                ))}
              </div>
              {selectedConcept && (
                <div style={{ display: 'inline-flex', alignItems: 'center', gap: '6px', background: 'rgba(136,123,176,0.15)', border: '1px solid #887BB0', borderRadius: '20px', padding: '5px 12px', fontSize: '11px', fontWeight: 600, color: '#a99dd4', marginTop: '10px' }}>
                  <div style={{ width: '6px', height: '6px', borderRadius: '50%', background: '#887BB0' }}></div>
                  Tagged: {selectedConcept}
                </div>
              )}
            </div>
          </div>

          {/* Test Cases Card */}
          <div style={{
            background: '#1a1a2e',
            border: '1px solid #2e2e4a',
            borderRadius: '14px',
            padding: '24px'
          }}>
            <div style={{ fontSize: '13px', fontWeight: 700, color: '#e8e6f0', marginBottom: '20px', paddingBottom: '12px', borderBottom: '1px solid #2e2e4a' }}>
              Test Cases
            </div>
            <div style={{ fontSize: '11px', color: '#8884a0', marginBottom: '16px' }}>
              Use hidden test cases to prevent students from seeing inputs/outputs while still affecting their score
            </div>

            {formData.test_cases.map((tc, idx) => (
              <div key={idx} style={{
                background: '#22223a',
                border: '1px solid #2e2e4a',
                borderRadius: '8px',
                padding: '12px',
                marginBottom: '10px',
                display: 'grid',
                gridTemplateColumns: '1fr 1fr',
                gap: '10px',
                position: 'relative'
              }}>
                <div style={{
                  position: 'absolute',
                  top: '-8px',
                  left: '12px',
                  background: '#1a1a2e',
                  border: '1px solid #2e2e4a',
                  borderRadius: '10px',
                  padding: '1px 8px',
                  fontSize: '9px',
                  fontWeight: 700,
                  color: '#8884a0',
                  letterSpacing: '1px'
                }}>
                  TEST CASE {idx + 1}
                </div>
                <div style={{ marginTop: '12px' }}>
                  <div style={{ fontSize: '10px', fontWeight: 600, letterSpacing: '1px', textTransform: 'uppercase', color: '#8884a0', marginBottom: '5px' }}>
                    Input
                  </div>
                  <textarea
                    value={tc.input}
                    onChange={(e) => handleTestCaseChange(idx, 'input', e.target.value)}
                    placeholder="e.g., 3&#10;1 2 3"
                    style={{
                      background: '#0f0f1a',
                      border: '1px solid #2e2e4a',
                      borderRadius: '6px',
                      padding: '8px',
                      fontSize: '11px',
                      fontFamily: 'Space Mono, monospace',
                      color: '#e8e6f0',
                      width: '100%',
                      outline: 'none',
                      resize: 'none',
                      minHeight: '50px',
                      boxSizing: 'border-box'
                    }}
                  />
                </div>
                <div style={{ marginTop: '12px' }}>
                  <div style={{ fontSize: '10px', fontWeight: 600, letterSpacing: '1px', textTransform: 'uppercase', color: '#8884a0', marginBottom: '5px' }}>
                    Expected Output
                  </div>
                  <textarea
                    value={tc.expected_output}
                    onChange={(e) => handleTestCaseChange(idx, 'expected_output', e.target.value)}
                    placeholder="e.g., 6"
                    style={{
                      background: '#0f0f1a',
                      border: '1px solid #2e2e4a',
                      borderRadius: '6px',
                      padding: '8px',
                      fontSize: '11px',
                      fontFamily: 'Space Mono, monospace',
                      color: '#e8e6f0',
                      width: '100%',
                      outline: 'none',
                      resize: 'none',
                      minHeight: '50px',
                      boxSizing: 'border-box'
                    }}
                  />
                </div>
                <div style={{ marginTop: '12px', display: 'flex', alignItems: 'center', gap: '8px' }}>
                  <input
                    type="checkbox"
                    checked={tc.hidden}
                    onChange={(e) => handleTestCaseChange(idx, 'hidden', e.target.checked)}
                    style={{ width: '16px', height: '16px', cursor: 'pointer' }}
                  />
                  <label style={{ fontSize: '11px', color: '#8884a0', fontWeight: 500, cursor: 'pointer' }}>
                    Hidden from students
                  </label>
                </div>
                {formData.test_cases.length > 2 && (
                  <button
                    type="button"
                    onClick={() => removeTestCase(idx)}
                    style={{
                      position: 'absolute',
                      top: '8px',
                      right: '8px',
                      background: 'transparent',
                      border: 'none',
                      color: '#f87171',
                      cursor: 'pointer',
                      fontSize: '12px',
                      fontWeight: 600
                    }}
                  >
                    ✕
                  </button>
                )}
              </div>
            ))}

            <button 
              type="button"
              onClick={addTestCase}
              style={{
                width: '100%',
                padding: '8px',
                border: '1.5px dashed #2e2e4a',
                borderRadius: '8px',
                background: 'transparent',
                color: '#8884a0',
                fontSize: '12px',
                cursor: 'pointer',
                fontFamily: 'DM Sans, sans-serif',
                transition: 'all 0.15s'
              }}
              onMouseEnter={(e) => {
                e.target.style.borderColor = '#85D2D0';
                e.target.style.color = '#85D2D0';
              }}
              onMouseLeave={(e) => {
                e.target.style.borderColor = '#2e2e4a';
                e.target.style.color = '#8884a0';
              }}
            >
              + Add Test Case
            </button>
          </div>
        </div>

        {/* Right Panel */}
        <div style={{ display: 'flex', flexDirection: 'column', gap: '14px' }}>
          {/* Assignment Settings */}
          <div style={{
            background: '#1a1a2e',
            border: '1px solid #2e2e4a',
            borderRadius: '14px',
            padding: '18px'
          }}>
            <div style={{ fontSize: '12px', fontWeight: 700, color: '#e8e6f0', marginBottom: '14px', paddingBottom: '10px', borderBottom: '1px solid #2e2e4a' }}>
              Assignment Settings
            </div>

            {/* Section */}
            <div style={{ marginBottom: '18px' }}>
              <label style={{ fontSize: '11px', fontWeight: 600, letterSpacing: '0.8px', textTransform: 'uppercase', color: '#8884a0', marginBottom: '7px', display: 'block' }}>
                Assign to Class
              </label>
              <div style={{ position: 'relative' }}>
                <select 
                  required
                  value={formData.section_id}
                  onChange={(e) => setFormData({ ...formData, section_id: e.target.value })}
                  style={{
                    width: '100%',
                    background: '#22223a',
                    border: '1px solid #2e2e4a',
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
                    <option key={s.id} value={s.id}>
                      {s.name} ({s.student_count || 0} students)
                    </option>
                  ))}
                </select>
                <div style={{ position: 'absolute', right: '12px', top: '50%', transform: 'translateY(-50%)', color: '#8884a0', pointerEvents: 'none', fontSize: '12px' }}>
                  ▾
                </div>
              </div>
            </div>

            {/* Time Limit */}
            <div style={{ marginBottom: '18px' }}>
              <label style={{ fontSize: '11px', fontWeight: 600, letterSpacing: '0.8px', textTransform: 'uppercase', color: '#8884a0', marginBottom: '7px', display: 'block' }}>
                Time Limit
              </label>
              <div style={{ position: 'relative' }}>
                <select 
                  value={formData.time_limit_minutes}
                  onChange={(e) => setFormData({ ...formData, time_limit_minutes: parseInt(e.target.value) })}
                  style={{
                    width: '100%',
                    background: '#22223a',
                    border: '1px solid #2e2e4a',
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
                  <option value={30}>30 minutes</option>
                  <option value={45}>45 minutes</option>
                  <option value={60}>60 minutes</option>
                  <option value={90}>90 minutes</option>
                </select>
                <div style={{ position: 'absolute', right: '12px', top: '50%', transform: 'translateY(-50%)', color: '#8884a0', pointerEvents: 'none', fontSize: '12px' }}>
                  ▾
                </div>
              </div>
            </div>

            {/* Deadline */}
            <div style={{ marginBottom: '0' }}>
              <label style={{ fontSize: '11px', fontWeight: 600, letterSpacing: '0.8px', textTransform: 'uppercase', color: '#8884a0', marginBottom: '7px', display: 'block' }}>
                Deadline
              </label>
              <input 
                type="datetime-local"
                value={formData.deadline}
                onChange={(e) => setFormData({ ...formData, deadline: e.target.value })}
                style={{
                  width: '100%',
                  background: '#22223a',
                  border: '1px solid #2e2e4a',
                  borderRadius: '8px',
                  padding: '10px 13px',
                  fontSize: '13px',
                  color: '#e8e6f0',
                  fontFamily: 'DM Sans, sans-serif',
                  outline: 'none',
                  boxSizing: 'border-box'
                }}
              />
            </div>
          </div>

          {/* Difficulty Tracking */}
          <div style={{
            background: '#1a1a2e',
            border: '1px solid #2e2e4a',
            borderRadius: '14px',
            padding: '18px'
          }}>
            <div style={{ fontSize: '12px', fontWeight: 700, color: '#e8e6f0', marginBottom: '14px', paddingBottom: '10px', borderBottom: '1px solid #2e2e4a' }}>
              Difficulty Tracking
            </div>

            {[
              { key: 'track_ner', label: 'Track error rate (NER)' },
              { key: 'track_nrs', label: 'Track retry count (NRS)' },
              { key: 'track_nts', label: 'Track time-on-task (NTS)' },
              { key: 'auto_alert', label: 'Auto-alert on High CDS' }
            ].map((item, idx) => (
              <div key={item.key} style={{ display: 'flex', justifyContent: 'space-between', alignItems: 'center', marginBottom: idx < 3 ? '12px' : '0' }}>
                <span style={{ fontSize: '11px', color: '#8884a0', fontWeight: 500 }}>
                  {item.label}
                </span>
                <button
                  type="button"
                  onClick={() => setFormData({ ...formData, [item.key]: !formData[item.key] })}
                  style={{
                    width: '36px',
                    height: '20px',
                    background: formData[item.key] ? '#85D2D0' : '#2e2e4a',
                    border: 'none',
                    borderRadius: '10px',
                    position: 'relative',
                    cursor: 'pointer',
                    transition: 'background 0.2s'
                  }}
                >
                  <div style={{
                    content: '""',
                    width: '16px',
                    height: '16px',
                    background: 'white',
                    borderRadius: '50%',
                    position: 'absolute',
                    top: '2px',
                    right: formData[item.key] ? '2px' : '18px',
                    transition: 'right 0.2s'
                  }}></div>
                </button>
              </div>
            ))}
          </div>

          {/* Publish Buttons */}
          <div>
            <button 
              type="submit"
              disabled={submitting}
              style={{
                width: '100%',
                padding: '13px',
                background: '#85D2D0',
                color: '#0a1a1a',
                fontSize: '13px',
                fontWeight: 700,
                border: 'none',
                borderRadius: '10px',
                cursor: submitting ? 'not-allowed' : 'pointer',
                fontFamily: 'DM Sans, sans-serif',
                letterSpacing: '0.3px',
                opacity: submitting ? 0.6 : 1,
                transition: 'all 0.15s'
              }}
              onMouseEnter={(e) => !submitting && (e.target.style.background = '#9ae0de')}
              onMouseLeave={(e) => !submitting && (e.target.style.background = '#85D2D0')}
            >
              {submitting ? 'Publishing...' : 'Publish Exercise'}
            </button>
            <button 
              type="button"
              onClick={(e) => handleSubmit(e, true)}
              disabled={submitting}
              style={{
                width: '100%',
                padding: '10px',
                background: 'transparent',
                color: '#8884a0',
                fontSize: '12px',
                fontWeight: 600,
                border: '1px solid #2e2e4a',
                borderRadius: '10px',
                cursor: submitting ? 'not-allowed' : 'pointer',
                fontFamily: 'DM Sans, sans-serif',
                marginTop: '8px',
                opacity: submitting ? 0.6 : 1,
                transition: 'all 0.15s'
              }}
            >
              Save as Draft
            </button>
          </div>
        </div>
      </form>
    </div>
  );
}
