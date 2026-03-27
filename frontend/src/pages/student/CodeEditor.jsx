import { useState, useEffect } from 'react';
import { useParams, useNavigate } from 'react-router-dom';
import api from '../../services/api';

const SYNTAX_HIGHLIGHTS = {
  kw: ['#include', 'using', 'namespace', 'int', 'float', 'char', 'bool', 'for', 'while', 'if', 'else', 'return'],
  fn: ['main', 'cin', 'cout'],
  str: ['std', 'endl'],
  comment: ['//'],
};

export default function StudentCodeEditor() {
  const { exerciseId } = useParams();
  const navigate = useNavigate();
  const [exercise, setExercise] = useState(null);
  const [code, setCode] = useState('');
  const [output, setOutput] = useState('');
  const [attempts, setAttempts] = useState([]);
  const [loading, setLoading] = useState(true);
  const [running, setRunning] = useState(false);
  const [submitting, setSubmitting] = useState(false);
  const [activeTab, setActiveTab] = useState('output');
  const [testResults, setTestResults] = useState(null);
  const [timeRemaining, setTimeRemaining] = useState(null);

  useEffect(() => {
    fetchExercise();
  }, [exerciseId]);

  useEffect(() => {
    if (timeRemaining && timeRemaining > 0) {
      const timer = setTimeout(() => setTimeRemaining(timeRemaining - 1), 1000);
      return () => clearTimeout(timer);
    }
  }, [timeRemaining]);

  const fetchExercise = async () => {
    try {
      const res = await api.get(`/api/student/exercises/${exerciseId}`);
      setExercise(res.data);
      setCode(res.data.starter_code || '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Write your code here\n  return 0;\n}');
      
      if (res.data.deadline) {
        const now = new Date();
        const deadline = new Date(res.data.deadline);
        const diffMs = deadline - now;
        if (diffMs > 0) {
          setTimeRemaining(Math.floor(diffMs / 1000));
        }
      }
      
      fetchAttempts(exerciseId);
    } catch (err) {
      console.error('Error fetching exercise:', err);
    } finally {
      setLoading(false);
    }
  };

  const fetchAttempts = async (exId) => {
    try {
      const res = await api.get(`/api/student/exercises/${exId}/attempts`);
      setAttempts(res.data || []);
    } catch (err) {
      console.error('Error fetching attempts:', err);
    }
  };

  const handleRun = async () => {
    setRunning(true);
    try {
      const res = await api.post(`/api/student/exercises/${exerciseId}/run`, { code });
      setTestResults(res.data);
      setOutput(JSON.stringify(res.data, null, 2));
      setActiveTab('output');
    } catch (err) {
      setOutput('Error: ' + (err.response?.data?.message || err.message));
    } finally {
      setRunning(false);
    }
  };

  const handleSubmit = async () => {
    setSubmitting(true);
    try {
      const res = await api.post(`/api/student/exercises/${exerciseId}/submit`, { code });
      setTestResults(res.data);
      setOutput(JSON.stringify(res.data, null, 2));
      setAttempts([res.data, ...attempts]);
      setActiveTab('output');
    } catch (err) {
      setOutput('Error: ' + (err.response?.data?.message || err.message));
    } finally {
      setSubmitting(false);
    }
  };

  const formatTime = (seconds) => {
    if (!seconds) return '0:00';
    const mins = Math.floor(seconds / 60);
    const secs = seconds % 60;
    return `${mins}:${secs.toString().padStart(2, '0')}`;
  };

  if (loading) {
    return <div style={{ padding: '40px', color: '#6a85a8' }}>Loading exercise...</div>;
  }

  if (!exercise) {
    return <div style={{ padding: '40px', color: '#f87171' }}>Exercise not found</div>;
  }

  return (
    <div style={{ 
      display: 'flex',
      flexDirection: 'column',
      height: '100vh',
      background: '#0a1018',
      color: '#dce8f5',
      overflow: 'hidden'
    }}>
      {/* Top Nav */}
      <nav style={{
        height: '48px',
        background: '#131d30',
        borderBottom: '1px solid #1e304d',
        display: 'flex',
        alignItems: 'center',
        padding: '0 20px',
        gap: '16px',
        flexShrink: 0
      }}>
        <div style={{ fontFamily: "'Space Mono', monospace", fontSize: '13px', fontWeight: 700, color: '#85D2D0' }}>
          Code<span style={{ color: '#a99dd4' }}>Insight</span>
        </div>
        <div style={{ fontSize: '11px', color: '#6a85a8', display: 'flex', alignItems: 'center', gap: '6px' }}>
          <span>Exercises</span>
          <span>›</span>
          <strong style={{ color: '#dce8f5', fontWeight: 600 }}>{exercise.title}</strong>
        </div>
        <div style={{ marginLeft: 'auto', display: 'flex', alignItems: 'center', gap: '12px' }}>
          <div style={{
            padding: '4px 12px',
            borderRadius: '12px',
            fontSize: '10px',
            fontWeight: 700,
            letterSpacing: '0.8px',
            textTransform: 'uppercase',
            background: 'rgba(136,123,176,0.15)',
            color: '#a99dd4',
            border: '1px solid rgba(136,123,176,0.3)'
          }}>
            {exercise.concept_name}
          </div>
          {timeRemaining && (
            <div style={{
              fontFamily: "'Space Mono', monospace",
              fontSize: '12px',
              fontWeight: 700,
              color: timeRemaining < 300 ? '#f87171' : '#fbbf24',
              background: 'rgba(251,191,36,0.08)',
              padding: '4px 12px',
              borderRadius: '8px',
              border: '1px solid rgba(251,191,36,0.2)'
            }}>
              ⏱ {formatTime(timeRemaining)}
            </div>
          )}
        </div>
      </nav>

      {/* Main Workspace */}
      <div style={{ display: 'flex', flex: 1, overflow: 'hidden' }}>
        {/* Problem Panel */}
        <div style={{
          width: '340px',
          minWidth: '340px',
          background: '#131d30',
          borderRight: '1px solid #1e304d',
          display: 'flex',
          flexDirection: 'column',
          overflow: 'hidden'
        }}>
          <div style={{
            padding: '14px 18px',
            borderBottom: '1px solid #1e304d',
            background: '#1a2640',
            flexShrink: 0
          }}>
            <div style={{ fontSize: '13px', fontWeight: 700, color: '#dce8f5' }}>
              Problem Statement
            </div>
            <div style={{ fontSize: '10px', color: '#6a85a8', marginTop: '3px', display: 'flex', gap: '12px' }}>
              <span>⏱ {exercise.time_limit_minutes} min limit</span>
              <span>📅 {new Date(exercise.deadline).toLocaleDateString()}</span>
              <span>C++</span>
            </div>
          </div>

          <div style={{ padding: '16px 18px', overflowY: 'auto', flex: 1 }}>
            <div style={{ fontSize: '9px', fontWeight: 700, letterSpacing: '2px', textTransform: 'uppercase', color: '#6a85a8', marginBottom: '8px' }}>
              Description
            </div>
            <div style={{ fontSize: '12px', lineHeight: '1.7', color: '#dce8f5', marginBottom: '18px' }}>
              {exercise.description}
            </div>

            <div style={{ background: '#0a1018', border: '1px solid #1e304d', borderRadius: '8px', padding: '12px', marginBottom: '12px' }}>
              <div style={{ fontSize: '9px', fontWeight: 700, letterSpacing: '1.5px', textTransform: 'uppercase', color: '#6a85a8', marginBottom: '6px' }}>
                Input Format
              </div>
              <div style={{ fontFamily: "'Space Mono', monospace", fontSize: '11px', color: '#dce8f5', lineHeight: '1.6' }}>
                {exercise.input_format || 'Standard input'}
              </div>
            </div>

            <div style={{ background: '#0a1018', border: '1px solid #1e304d', borderRadius: '8px', padding: '12px' }}>
              <div style={{ fontSize: '9px', fontWeight: 700, letterSpacing: '1.5px', textTransform: 'uppercase', color: '#6a85a8', marginBottom: '6px' }}>
                Output Format
              </div>
              <div style={{ fontFamily: "'Space Mono', monospace", fontSize: '11px', color: '#dce8f5', lineHeight: '1.6' }}>
                {exercise.output_format || 'Standard output'}
              </div>
            </div>
          </div>
        </div>

        {/* Editor Panel */}
        <div style={{ flex: 1, display: 'flex', flexDirection: 'column', overflow: 'hidden' }}>
          <div style={{
            padding: '8px 14px',
            background: '#1a2640',
            borderBottom: '1px solid #1e304d',
            display: 'flex',
            alignItems: 'center',
            justifyContent: 'space-between',
            flexShrink: 0
          }}>
            <div style={{
              fontSize: '10px',
              fontWeight: 700,
              color: '#85D2D0',
              background: 'rgba(133,210,208,0.1)',
              padding: '3px 10px',
              borderRadius: '6px',
              fontFamily: "'Space Mono', monospace"
            }}>
              C++ (GCC 9.2)
            </div>
            <div style={{ display: 'flex', gap: '8px' }}>
              <button
                onClick={handleRun}
                disabled={running}
                style={{
                  padding: '6px 14px',
                  borderRadius: '7px',
                  fontSize: '11px',
                  fontWeight: 700,
                  cursor: running ? 'not-allowed' : 'pointer',
                  border: '1px solid #1e304d',
                  background: '#131d30',
                  color: '#6a85a8',
                  fontFamily: "'DM Sans', sans-serif",
                  transition: 'all 0.15s',
                  opacity: running ? 0.6 : 1
                }}
              >
                {running ? 'Running...' : '▶ Run'}
              </button>
              <button
                onClick={handleSubmit}
                disabled={submitting}
                style={{
                  padding: '6px 14px',
                  borderRadius: '7px',
                  fontSize: '11px',
                  fontWeight: 700,
                  cursor: submitting ? 'not-allowed' : 'pointer',
                  border: 'none',
                  background: '#85D2D0',
                  color: '#091a1a',
                  fontFamily: "'DM Sans', sans-serif",
                  transition: 'all 0.15s',
                  opacity: submitting ? 0.6 : 1
                }}
              >
                {submitting ? 'Submitting...' : 'Submit →'}
              </button>
            </div>
          </div>

          <textarea
            value={code}
            onChange={(e) => setCode(e.target.value)}
            style={{
              flex: 1,
              background: '#0a1018',
              color: '#dce8f5',
              border: 'none',
              padding: '16px',
              fontFamily: "'Space Mono', monospace",
              fontSize: '12px',
              lineHeight: '1.8',
              outline: 'none',
              resize: 'none',
              overflowY: 'auto'
            }}
          />

          {/* Output Panel */}
          <div style={{
            height: '160px',
            minHeight: '160px',
            background: '#131d30',
            borderTop: '1px solid #1e304d',
            display: 'flex',
            flexDirection: 'column',
            flexShrink: 0
          }}>
            <div style={{ display: 'flex', borderBottom: '1px solid #1e304d', background: '#1a2640' }}>
              {['output', 'log'].map(tab => (
                <button
                  key={tab}
                  onClick={() => setActiveTab(tab)}
                  style={{
                    padding: '8px 16px',
                    fontSize: '11px',
                    fontWeight: 600,
                    color: activeTab === tab ? '#85D2D0' : '#6a85a8',
                    cursor: 'pointer',
                    border: 'none',
                    background: 'transparent',
                    borderBottom: activeTab === tab ? '2px solid #85D2D0' : '2px solid transparent',
                    fontFamily: "'DM Sans', sans-serif",
                    transition: 'all 0.15s'
                  }}
                >
                  {tab.charAt(0).toUpperCase() + tab.slice(1)}
                </button>
              ))}
            </div>
            <div style={{
              flex: 1,
              padding: '12px 16px',
              fontFamily: "'Space Mono', monospace",
              fontSize: '11px',
              overflowY: 'auto',
              color: '#dce8f5'
            }}>
              {output || '(No output yet)'}
            </div>
          </div>
        </div>

        {/* Attempts Panel */}
        <div style={{
          width: '200px',
          minWidth: '200px',
          background: '#131d30',
          borderLeft: '1px solid #1e304d',
          display: 'flex',
          flexDirection: 'column',
          overflow: 'hidden'
        }}>
          <div style={{
            padding: '12px 14px',
            borderBottom: '1px solid #1e304d',
            background: '#1a2640',
            flexShrink: 0
          }}>
            <div style={{ fontSize: '11px', fontWeight: 700, color: '#dce8f5' }}>
              My Attempts ({attempts.length})
            </div>
          </div>
          <div style={{ padding: '12px', overflowY: 'auto', flex: 1 }}>
            {attempts.map((attempt, idx) => (
              <div key={idx} style={{
                background: '#1a2640',
                border: '1px solid ' + (attempt.passed ? '#4ade80' : '#f87171'),
                borderLeft: '3px solid ' + (attempt.passed ? '#4ade80' : '#f87171'),
                borderRadius: '8px',
                padding: '10px',
                marginBottom: '8px'
              }}>
                <div style={{ fontSize: '9px', fontWeight: 700, letterSpacing: '1px', textTransform: 'uppercase', color: '#6a85a8', marginBottom: '4px' }}>
                  Attempt {idx + 1}
                </div>
                <div style={{
                  fontSize: '10px',
                  fontWeight: 700,
                  color: attempt.passed ? '#4ade80' : '#f87171',
                  marginBottom: '3px'
                }}>
                  {attempt.passed ? '✓ Passed' : '✗ Failed'}
                </div>
                <div style={{ fontSize: '9px', color: '#6a85a8', marginTop: '3px' }}>
                  {new Date(attempt.created_at).toLocaleTimeString([], { hour: '2-digit', minute: '2-digit' })}
                </div>
              </div>
            ))}
            {attempts.length === 0 && (
              <div style={{ fontSize: '10px', color: '#6a85a8', textAlign: 'center', marginTop: '20px' }}>
                No attempts yet
              </div>
            )}
          </div>
        </div>
      </div>
    </div>
  );
}
