import { useState, useEffect, useRef } from 'react';
import Editor from '@monaco-editor/react';
import api from '../../services/api';
import { useAuth } from '../../context/AuthContext';

export default function StudentExercises() {
  const { user } = useAuth();
  const editorRef = useRef(null);
  const timerIntervalRef = useRef(null);
  const exerciseStartTimeRef = useRef(null);
  const activeTimeRef = useRef(0);
  const lastActivityRef = useRef(null);
  const [exercises, setExercises] = useState([]);
  const [selectedExercise, setSelectedExercise] = useState(null);
  const [code, setCode] = useState('#include <iostream>\nusing namespace std;\n\nint main() {\n  // Write your code here\n  return 0;\n}');
  const [result, setResult] = useState(null);
  const [submissions, setSubmissions] = useState([]);
  const [loading, setLoading] = useState(true);
  const [running, setRunning] = useState(false);
  const [submitting, setSubmitting] = useState(false);
  const [abortController, setAbortController] = useState(null);
  const [highlightedLine, setHighlightedLine] = useState(null);
  const [timeRemaining, setTimeRemaining] = useState(0); // in seconds
  const [timeoutAlert, setTimeoutAlert] = useState(false);

  useEffect(() => {
    fetchExercises();
  }, []);

  // Timer countdown effect
  useEffect(() => {
    if (selectedExercise && timeRemaining > 0) {
      timerIntervalRef.current = setInterval(() => {
        setTimeRemaining(prev => {
          if (prev <= 1) {
            clearInterval(timerIntervalRef.current);
            setTimeoutAlert(true);
            return 0;
          }
          return prev - 1;
        });
      }, 1000);
      return () => clearInterval(timerIntervalRef.current);
    }
  }, [selectedExercise, timeRemaining]);

  useEffect(() => {
    if (selectedExercise) {
      fetchSubmissions(selectedExercise.id);
    }
  }, [selectedExercise]);

  const fetchExercises = async () => {
    try {
      const res = await api.get('/api/exercises');
      setExercises(res.data || []);
    } catch (err) {
      console.error('Error fetching exercises:', err);
    } finally {
      setLoading(false);
    }
  };

  const handleSelectExercise = (exercise) => {
    setSelectedExercise(exercise);
    setCode('#include <iostream>\nusing namespace std;\n\nint main() {\n  // Write your code here\n  return 0;\n}');
    setResult(null);
    setTimeRemaining(exercise.time_limit_minutes * 60);
    setTimeoutAlert(false);
    // Start tracking time
    exerciseStartTimeRef.current = Date.now();
    activeTimeRef.current = 0;
    lastActivityRef.current = Date.now();
    fetchSubmissions(exercise.id);
  };

  const handleBackToList = () => {
    setSelectedExercise(null);
    if (timerIntervalRef.current) {
      clearInterval(timerIntervalRef.current);
    }
    // Reset time tracking
    exerciseStartTimeRef.current = null;
    activeTimeRef.current = 0;
    lastActivityRef.current = null;
  };

  const fetchSubmissions = async (exerciseId) => {
    try {
      const res = await api.get(`/api/submissions/${exerciseId}/my`);
      setSubmissions(res.data || []);
    } catch (err) {
      console.error('Error fetching submissions:', err);
    }
  };

  const handleRun = async () => {
    if (!selectedExercise || !code.trim()) return;
    setRunning(true);
    setResult(null);
    const controller = new AbortController();
    setAbortController(controller);
    try {
      const res = await api.post('/api/submissions/run', {
        exerciseId: selectedExercise.id,
        code
      }, { signal: controller.signal });
      setResult(res.data);
    } catch (err) {
      if (err.name !== 'AbortError') {
        setResult({
          status: 'Error',
          error: err.response?.data?.message || err.message
        });
      }
    } finally {
      setRunning(false);
      setAbortController(null);
    }
  };

  const handleStop = () => {
    if (abortController) {
      abortController.abort();
      setAbortController(null);
      setRunning(false);
      setResult({
        status: 'Stopped',
        error: 'Execution stopped by user'
      });
    }
  };

  // Navigate to line in editor and highlight it (IDE-like behavior)
  const goToErrorLine = (lineNumber) => {
    if (editorRef.current && lineNumber) {
      const editor = editorRef.current;
      setHighlightedLine(lineNumber);
      editor.revealLineInCenter(lineNumber);
      editor.setPosition({ lineNumber, column: 1 });
    }
  };

  // Parse and format error blocks with code context
  const parseErrorBlock = (errorText) => {
    const blocks = [];
    const lines = errorText.split('\n');
    let i = 0;
    
    while (i < lines.length) {
      const line = lines[i];
      const headerMatch = line.match(/\[Line (\d+):(\d+)\]\s*(ERROR|WARNING):\s*(.+)/);
      
      if (headerMatch) {
        const lineNum = parseInt(headerMatch[1]);
        const col = parseInt(headerMatch[2]);
        const type = headerMatch[3];
        const msg = headerMatch[4];
        
        // Collect code line and pointer (next 2 lines if they exist)
        let codeLine = '';
        let pointer = '';
        if (i + 1 < lines.length && lines[i + 1].startsWith('    ')) {
          codeLine = lines[i + 1].substring(4); // Remove leading spaces
          i++;
        }
        if (i + 1 < lines.length && lines[i + 1].trim() && lines[i + 1].includes('^')) {
          pointer = lines[i + 1].substring(4); // Remove leading spaces
          i++;
        }
        
        blocks.push({
          type: 'error',
          lineNum,
          col,
          errorType: type,
          message: msg,
          codeLine,
          pointer
        });
      } else if (line.trim()) {
        blocks.push({
          type: 'text',
          content: line
        });
      }
      i++;
    }
    
    return blocks;
  };

  // Render error block with code context (IDE-style)
  const renderErrorBlock = (block, idx) => {
    if (block.type === 'error') {
      return (
        <div
          key={idx}
          onClick={() => goToErrorLine(block.lineNum)}
          style={{
            cursor: 'pointer',
            marginBottom: '8px',
            padding: '8px',
            backgroundColor: highlightedLine === block.lineNum ? 'rgba(248,113,113,0.3)' : 'rgba(248,113,113,0.15)',
            border: `1px solid ${highlightedLine === block.lineNum ? '#ff6b6b' : '#f87171'}`,
            borderRadius: '4px',
            transition: 'all 0.2s'
          }}
        >
          <div style={{ display: 'flex', alignItems: 'center', gap: '6px', marginBottom: '4px', fontWeight: '600' }}>
            <span style={{ color: '#f87171' }}>●</span>
            <span style={{ color: '#f87171' }}>[Line {block.lineNum}:{block.col}] {block.errorType}</span>
          </div>
          <div style={{ marginLeft: '20px', color: '#fbbf24', marginBottom: '4px' }}>
            {block.message}
          </div>
          {block.codeLine && (
            <div style={{ 
              fontFamily: 'DM Mono, monospace',
              fontSize: '10px',
              backgroundColor: 'rgba(0,0,0,0.2)',
              padding: '4px 6px',
              borderRadius: '2px',
              marginBottom: '2px',
              overflow: 'auto'
            }}>
              <div style={{ color: '#e6edf3' }}>{block.codeLine}</div>
              {block.pointer && (
                <div style={{ color: '#ff9999', fontWeight: 'bold' }}>{block.pointer}</div>
              )}
            </div>
          )}
        </div>
      );
    }
    
    return <div key={idx} style={{ marginBottom: '4px' }}>{block.content}</div>;
  };

  const handleSubmit = async () => {
    if (!selectedExercise || !code.trim()) return;
    setSubmitting(true);
    try {
      // Calculate elapsed time in seconds
      const elapsedSeconds = exerciseStartTimeRef.current
        ? Math.floor((Date.now() - exerciseStartTimeRef.current) / 1000)
        : 0;
      
      const res = await api.post('/api/submissions/submit', {
        exerciseId: selectedExercise.id,
        code,
        timeSpentSeconds: elapsedSeconds
      });
      setResult(res.data);
      await fetchSubmissions(selectedExercise.id);
    } catch (err) {
      setResult({
        status: 'Error',
        error: err.response?.data?.message || err.message
      });
    } finally {
      setSubmitting(false);
    }
  };

  if (loading) {
    return (
      <div style={{ padding: '40px', textAlign: 'center', color: '#8b949e' }}>
        Loading exercises...
      </div>
    );
  }

  if (!exercises.length) {
    return (
      <div style={{ padding: '40px', textAlign: 'center', color: '#8b949e' }}>
        No exercises assigned yet.
      </div>
    );
  }

  // Format time display MM:SS
  const formatTime = (seconds) => {
    const mins = Math.floor(seconds / 60);
    const secs = seconds % 60;
    return `${String(mins).padStart(2, '0')}:${String(secs).padStart(2, '0')}`;
  };

  // Grid view - show all exercises as cards
  if (!selectedExercise) {
    return (
      <div style={{ 
        padding: '28px 28px 28px 120px',
        width: '100%',
        boxSizing: 'border-box'
      }}>
        <h1 style={{ fontSize: '20px', fontWeight: 700, color: '#e6edf3', marginBottom: '24px' }}>
          My Exercises
        </h1>

        <div style={{ display: 'grid', gridTemplateColumns: 'repeat(auto-fill, minmax(280px, 1fr))', gap: '16px' }}>
          {exercises.map(exercise => (
            <div
              key={exercise.id}
              onClick={() => handleSelectExercise(exercise)}
              style={{
                background: '#161b22',
                border: '1px solid #30363d',
                borderRadius: '8px',
                padding: '16px',
                cursor: 'pointer',
                transition: 'all 0.2s',
                ':hover': { borderColor: '#85D2D0' }
              }}
              onMouseEnter={(e) => e.currentTarget.style.borderColor = '#85D2D0'}
              onMouseLeave={(e) => e.currentTarget.style.borderColor = '#30363d'}
            >
              <h3 style={{ fontSize: '14px', fontWeight: 700, color: '#e6edf3', marginBottom: '8px' }}>
                {exercise.title}
              </h3>
              <div style={{ fontSize: '12px', color: '#8b949e', marginBottom: '12px' }}>
                <div style={{ marginBottom: '4px' }}>
                  📚 {exercise.concept_name}
                </div>
              </div>
              <div style={{ display: 'flex', gap: '12px', fontSize: '11px', color: '#8b949e' }}>
                <span>⏱️ {exercise.time_limit_minutes}m</span>
              </div>
            </div>
          ))}
        </div>
      </div>
    );
  }

  // Editor view - show code editor for selected exercise
  return (
    <div style={{ display: 'flex', flexDirection: 'column', height: '100%', width: '100%', background: '#0d1117' }}>
      {/* Header with exercise title, timer, and back button */}
      <div style={{
        background: '#161b22',
        borderBottom: '1px solid #30363d',
        padding: '12px 16px',
        display: 'flex',
        justifyContent: 'space-between',
        alignItems: 'center'
      }}>
        <div style={{ display: 'flex', alignItems: 'center', gap: '12px' }}>
          <button
            onClick={handleBackToList}
            style={{
              padding: '6px 12px',
              background: '#30363d',
              border: 'none',
              borderRadius: '4px',
              color: '#8b949e',
              cursor: 'pointer',
              fontSize: '12px'
            }}
          >
            ← Back
          </button>
          <h2 style={{ fontSize: '14px', fontWeight: 700, color: '#e6edf3' }}>
            {selectedExercise.title}
          </h2>
        </div>
        
        <div style={{
          fontSize: '14px',
          fontWeight: 700,
          color: timeRemaining < 300 ? '#f87171' : '#85D2D0',
          display: 'flex',
          alignItems: 'center',
          gap: '8px'
        }}>
          ⏱️ {formatTime(timeRemaining)}
        </div>
      </div>

      {/* Timeout alert */}
      {timeoutAlert && (
        <div style={{
          background: '#f87171',
          color: '#0a1a1a',
          padding: '12px 16px',
          textAlign: 'center',
          fontWeight: 700,
          fontSize: '13px'
        }}>
          ⚠️ Time is up! Your code will be auto-submitted.
        </div>
      )}

      {/* Main content - 3 panel layout */}
      <div style={{ display: 'flex', flex: 1, height: '1px' }}>
        {/* Middle Panel - Exercise Details */}
        <div style={{
          width: '240px',
          minWidth: '240px',
          background: '#0d1117',
          borderRight: '1px solid #30363d',
          overflowY: 'auto',
          padding: '16px',
          fontSize: '12px'
        }}>
          <h3 style={{ fontSize: '13px', fontWeight: 700, color: '#e6edf3', marginBottom: '12px' }}>
            {selectedExercise.title}
          </h3>

          <div style={{ marginBottom: '12px' }}>
            <div style={{ fontSize: '10px', fontWeight: 700, color: '#85D2D0', marginBottom: '4px' }}>
              Concept
            </div>
            <div style={{ color: '#e6edf3' }}>
              {selectedExercise.concept_name}
            </div>
          </div>

          <div style={{ marginBottom: '12px' }}>
            <div style={{ fontSize: '10px', fontWeight: 700, color: '#85D2D0', marginBottom: '4px' }}>
              Description
            </div>
            <div style={{ color: '#8b949e', lineHeight: '1.5', fontSize: '11px' }}>
              {selectedExercise.description}
            </div>
          </div>

          <div style={{ marginBottom: '12px' }}>
            <div style={{ fontSize: '10px', fontWeight: 700, color: '#85D2D0', marginBottom: '4px' }}>
              Time Limit
            </div>
            <div style={{ color: '#e6edf3' }}>
              {selectedExercise.time_limit_minutes} minutes
            </div>
          </div>

          {selectedExercise.test_cases && selectedExercise.test_cases.length > 0 && (
            <div>
              <div style={{ fontSize: '10px', fontWeight: 700, color: '#85D2D0', marginBottom: '8px' }}>
                Sample Test Cases
              </div>
              <div style={{ display: 'flex', flexDirection: 'column', gap: '8px' }}>
                {selectedExercise.test_cases.slice(0, 2).map((tc, i) => (
                  <div key={i} style={{
                    fontSize: '10px',
                    padding: '8px',
                    background: '#21262d',
                    borderRadius: '4px',
                    fontFamily: 'DM Mono, monospace'
                  }}>
                    <div style={{ color: '#85D2D0', marginBottom: '4px' }}>Input:</div>
                    <div style={{ color: '#e6edf3', marginBottom: '6px', whiteSpace: 'pre-wrap', wordBreak: 'break-all' }}>
                      {tc.input || '(none)'}
                    </div>
                    <div style={{ color: '#85D2D0', marginBottom: '4px' }}>Expected:</div>
                    <div style={{ color: '#e6edf3', whiteSpace: 'pre-wrap', wordBreak: 'break-all' }}>
                      {tc.expected_output || '(none)'}
                    </div>
                  </div>
                ))}
              </div>
            </div>
          )}
        </div>

        {/* Right Panel - Code Editor */}
        <div style={{
          flex: 1,
          display: 'flex',
          flexDirection: 'column',
          height: '100%',
          minWidth: 0
        }}>
          <div style={{
            display: 'flex',
            gap: '8px',
            padding: '12px 16px',
            background: '#161b22',
            borderBottom: '1px solid #30363d'
          }}>
            {!running ? (
              <button
                onClick={handleRun}
                disabled={!selectedExercise}
                style={{
                  padding: '8px 14px',
                  background: '#4ade80',
                  border: 'none',
                  borderRadius: '6px',
                  color: '#0a1a1a',
                  fontSize: '12px',
                  fontWeight: 700,
                  cursor: 'pointer'
                }}
              >
                ▶ Run
              </button>
            ) : (
              <button
                onClick={handleStop}
                style={{
                  padding: '8px 14px',
                  background: '#f87171',
                  border: 'none',
                  borderRadius: '6px',
                  color: '#0a1a1a',
                  fontSize: '12px',
                  fontWeight: 700,
                  cursor: 'pointer'
                }}
              >
                ⏹ Stop
              </button>
            )}

            <button
              onClick={handleSubmit}
              disabled={submitting || running || !selectedExercise}
              style={{
                padding: '8px 14px',
                background: '#85D2D0',
                border: 'none',
                borderRadius: '6px',
                color: '#0a1a1a',
                fontSize: '12px',
                fontWeight: 700,
                cursor: submitting || running ? 'not-allowed' : 'pointer',
                opacity: submitting || running ? 0.6 : 1
              }}
            >
              {submitting ? 'Submitting...' : '✓ Submit'}
            </button>
          </div>

          <div style={{ flex: 1, minHeight: 0 }}>
            <Editor
              height="100%"
              defaultLanguage="cpp"
              value={code}
              onChange={(val) => {
                setCode(val || '');
                // Track active coding time
                const now = Date.now();
                const timeSinceLastActivity = (now - (lastActivityRef.current || now)) / 1000;
                // If activity within 30 seconds of previous, count it as continuous
                if (timeSinceLastActivity < 30) {
                  activeTimeRef.current += timeSinceLastActivity;
                }
                lastActivityRef.current = now;
              }}
              onMount={(editor) => {
                editorRef.current = editor;
              }}
              theme="vs-dark"
              options={{
                minimap: { enabled: false },
                fontSize: 13,
                fontFamily: 'DM Mono, monospace',
                lineNumbers: 'on',
                wordWrap: 'on'
              }}
            />
          </div>

          {/* Results Panel */}
          <div style={{
            maxHeight: '180px',
            background: '#161b22',
            borderTop: '1px solid #30363d',
            overflowY: 'auto',
            padding: '12px 16px',
            display: 'flex',
            flexDirection: 'column'
          }}>

            {result && (
              <div style={{
                fontSize: '11px',
                color: result.status === 'Success' || result.allPassed ? '#4ade80' : '#f87171',
                background: result.status === 'Success' || result.allPassed ? 'rgba(74,222,128,0.1)' : 'rgba(248,113,113,0.1)',
                border: `1px solid ${result.status === 'Success' || result.allPassed ? 'rgb(74,222,128)' : 'rgb(248,113,113)'}`,
                borderRadius: '6px',
                padding: '10px',
                fontFamily: 'DM Mono, monospace',
                whiteSpace: 'pre-wrap',
                wordBreak: 'break-word',
                overflow: 'auto'
              }}>
                <div style={{ fontWeight: 700, marginBottom: '6px' }}>
                  {result.status || (result.allPassed ? 'All Tests Passed! ✓' : 'Test Failed')}
                </div>
                {result.results && result.results.map((r, i) => (
                  <div key={i} style={{ marginTop: '6px', paddingTop: '6px', borderTop: '1px solid rgba(255,255,255,0.1)' }}>
                    <div>Test Case {i + 1}: {r.passed ? '✓ PASS' : '✗ FAIL'}</div>
                    {r.input && <div style={{ fontSize: '10px' }}>Input: {r.input}</div>}
                    {r.expected && <div style={{ fontSize: '10px' }}>Expected: {r.expected}</div>}
                    {r.actual && <div style={{ fontSize: '10px' }}>Got: {r.actual}</div>}
                    {r.error && (
                      <div style={{ color: '#f87171', fontSize: '10px', marginTop: '4px' }}>
                        {parseErrorBlock(r.error).map((block, blockIdx) => renderErrorBlock(block, blockIdx))}
                      </div>
                    )}
                  </div>
                ))}
                {result.output && !result.results && (
                  <div>Output: {result.output}</div>
                )}
                {result.error && (
                  <div style={{ color: '#f87171', marginTop: '8px', fontSize: '10px' }}>
                    {parseErrorBlock(result.error).map((block, blockIdx) => renderErrorBlock(block, blockIdx))}
                  </div>
                )}
              </div>
            )}
          </div>
        </div>
      </div>
    </div>
  );
}
