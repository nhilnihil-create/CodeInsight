import { useState, useEffect, useRef } from 'react';
import { useParams } from 'react-router-dom';
import Editor from '@monaco-editor/react';
import api from '../../services/api';

const COLORS = {
  bg: '#0c1220',
  surface: '#131d30',
  surface2: '#1a2640',
  border: '#1e304d',
  editorBg: '#0a1018',
  teal: '#85D2D0',
  purple: '#a99dd4',
  text: '#dce8f5',
  muted: '#6a85a8',
  success: '#4ade80',
  warning: '#fbbf24',
  error: '#f87171'
};

export default function StudentCodeEditor() {
  const { exerciseId } = useParams();
  const [exercise, setExercise] = useState(null);
  const [code, setCode] = useState('');
  const [testResults, setTestResults] = useState(null);
  const [attempts, setAttempts] = useState([]);
  const [loading, setLoading] = useState(true);
  const [running, setRunning] = useState(false);
  const [submitting, setSubmitting] = useState(false);
  const [activeTab, setActiveTab] = useState('output');
  const [timeRemaining, setTimeRemaining] = useState(null);
  const [abortController, setAbortController] = useState(null);
  const [highlightedLine, setHighlightedLine] = useState(null);
  const exerciseStartTimeRef = useRef(null);
  const pausedAccumRef = useRef(0); // total milliseconds paused
  const lastHiddenAtRef = useRef(null);
  const editorRef = useRef(null);

  useEffect(() => {
    fetchExercise();
  }, [exerciseId]);

  useEffect(() => {
    // Page Visibility API: track paused time when tab is hidden
    const handleVisibility = () => {
      if (document.hidden) {
        lastHiddenAtRef.current = Date.now();
      } else {
        if (lastHiddenAtRef.current) {
          pausedAccumRef.current += Date.now() - lastHiddenAtRef.current;
          lastHiddenAtRef.current = null;
        }
      }
    };
    document.addEventListener('visibilitychange', handleVisibility);
    return () => { document.removeEventListener('visibilitychange', handleVisibility); };
  }, []);

  useEffect(() => {
    if (timeRemaining && timeRemaining > 0) {
      const timer = setTimeout(() => setTimeRemaining(timeRemaining - 1), 1000);
      return () => clearTimeout(timer);
    }
  }, [timeRemaining]);

  const fetchExercise = async () => {
    try {
      const res = await api.get(`/api/student/exercises/${exerciseId}`);
      let exerciseData = res.data;
      if (exerciseData.test_cases && typeof exerciseData.test_cases === 'string') {
        exerciseData.test_cases = JSON.parse(exerciseData.test_cases);
      }
      setExercise(exerciseData);
      setCode(exerciseData.starter_code || '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Write code here\n  return 0;\n}');
      
      if (exerciseData.deadline) {
        const now = new Date();
        const deadline = new Date(exerciseData.deadline);
        const diffMs = deadline - now;
        if (diffMs > 0) setTimeRemaining(Math.floor(diffMs / 1000));
      }
      
      exerciseStartTimeRef.current = Date.now();
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
      setAttempts([]);
    }
  };

  const handleRun = async () => {
    setRunning(true);
    const controller = new AbortController();
    setAbortController(controller);
    try {
      const res = await api.post(`/api/student/exercises/${exerciseId}/run`, { code }, 
        { signal: controller.signal });
      setTestResults(res.data);
      
      // Auto-switch to Compiler Log tab if there's a compiler error
      const hasCompilerError = res.data.testResults?.[0]?.error || res.data.error || res.data.compilation_log;
      setActiveTab(hasCompilerError ? 'compiler-log' : 'output');
    } catch (err) {
      if (err.name !== 'AbortError') {
        setTestResults({
          passed: false,
          testResults: [],
          error: err.response?.data?.message || err.message
        });
        setActiveTab('compiler-log');
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
    }
  };

  const handleSubmit = async () => {
    setSubmitting(true);
    try {
      const elapsedMs = exerciseStartTimeRef.current ? (Date.now() - exerciseStartTimeRef.current) : 0;
      const activeMs = Math.max(0, elapsedMs - (pausedAccumRef.current || 0));
      const activeSeconds = Math.floor(activeMs / 1000);
      
      const res = await api.post(`/api/student/exercises/${exerciseId}/submit`, { 
        code,
        timeSpentSeconds: activeSeconds
      });
      // Normalize response: visible results are in `results`, hidden summary in `hidden`
      const data = res.data || {};
      const visible = Array.isArray(data.results) ? data.results : (data.testResults || []);
      const normalized = {
        passed: data.allPassed ?? data.passed ?? false,
        testResults: visible,
        hiddenSummary: data.hidden || null,
        cds: data.cds,
        classification: data.classification
      };
      setTestResults(normalized);
      // Add a lightweight attempt entry for attempt list
      const attemptEntry = {
        passed: normalized.passed,
        submitted_at: new Date().toISOString(),
        attemptNumber: data.attemptNumber
      };
      setAttempts(prev => [attemptEntry, ...prev]);
      setActiveTab('output');
    } catch (err) {
      setTestResults({
        passed: false,
        testResults: [],
        error: err.response?.data?.message || err.message
      });
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

  // Parse error blocks from compiler output
  const parseErrorBlock = (errorText) => {
    if (!errorText) return [];
    const blocks = [];
    const lines = errorText.split('\n');
    let i = 0;
    
    while (i < lines.length) {
      const line = lines[i];
      // Match patterns like: [Line 5:10] ERROR: message or Line 5: error: message
      const headerMatch = line.match(/(?:\[Line\s+(\d+):(\d+)\]|^.*?:(\d+):(?:\d+):)\s*(ERROR|WARNING|error|warning):\s*(.+)/i);
      
      if (headerMatch) {
        const lineNum = parseInt(headerMatch[1] || headerMatch[3]);
        const col = parseInt(headerMatch[2] || 0) || 1;
        const type = headerMatch[4];
        const msg = headerMatch[5];
        
        // Collect code line and pointer
        let codeLine = '';
        let pointer = '';
        if (i + 1 < lines.length && (lines[i + 1].startsWith('    ') || /^\s+/.test(lines[i + 1]))) {
          codeLine = lines[i + 1].trim();
          i++;
        }
        if (i + 1 < lines.length && lines[i + 1].includes('^')) {
          pointer = lines[i + 1].trim();
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

  // Go to error line in editor
  const goToErrorLine = (lineNumber) => {
    if (editorRef.current && lineNumber) {
      const editor = editorRef.current;
      setHighlightedLine(lineNumber);
      editor.revealLineInCenter(lineNumber);
      editor.setPosition({ lineNumber, column: 1 });
    }
  };

  // Render error block with code context (IDE-style terminal)
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
            border: `1px solid ${highlightedLine === block.lineNum ? '#ff6b6b' : COLORS.error}`,
            borderRadius: '4px',
            transition: 'all 0.2s'
          }}
        >
          <div style={{ display: 'flex', alignItems: 'center', gap: '6px', marginBottom: '4px', fontWeight: '600' }}>
            <span style={{ color: COLORS.error }}>●</span>
            <span style={{ color: COLORS.error }}>[Line {block.lineNum}:{block.col}] {block.errorType}</span>
          </div>
          <div style={{ marginLeft: '20px', color: COLORS.warning, marginBottom: '4px', fontSize: '11px' }}>
            {block.message}
          </div>
          {block.codeLine && (
            <div style={{ 
              fontFamily: "'Space Mono', monospace",
              fontSize: '10px',
              backgroundColor: 'rgba(0,0,0,0.3)',
              padding: '6px 8px',
              borderRadius: '4px',
              marginBottom: '2px',
              overflow: 'auto',
              border: `1px solid ${COLORS.border}`
            }}>
              <div style={{ color: COLORS.text, whiteSpace: 'pre-wrap', wordBreak: 'break-all' }}>{block.codeLine}</div>
              {block.pointer && (
                <div style={{ color: '#ff9999', fontWeight: 'bold', marginTop: '2px' }}>{block.pointer}</div>
              )}
            </div>
          )}
        </div>
      );
    }
    
    return (
      <div key={idx} style={{ marginBottom: '4px', color: COLORS.text, fontSize: '11px', fontFamily: "'Space Mono', monospace" }}>
        {block.content}
      </div>
    );
  };

  if (loading) {
    return <div style={{ padding: '40px', color: COLORS.muted, background: COLORS.bg, height: '100vh' }}>Loading...</div>;
  }

  if (!exercise) {
    return <div style={{ padding: '40px', color: COLORS.error, background: COLORS.bg, height: '100vh' }}>Exercise not found</div>;
  }

  return (
    <div style={{
      display: 'flex',
      flexDirection: 'column',
      height: '100vh',
      background: COLORS.bg,
      color: COLORS.text,
      fontFamily: "'DM Sans', sans-serif",
      overflow: 'hidden'
    }}>
      <nav style={{
        height: '48px',
        background: COLORS.surface,
        borderBottom: `1px solid ${COLORS.border}`,
        display: 'flex',
        alignItems: 'center',
        padding: '0 20px',
        gap: '16px',
        flexShrink: 0
      }}>
        <div style={{ fontFamily: "'Space Mono', monospace", fontSize: '13px', fontWeight: 700, color: COLORS.teal }}>
          Code<span style={{ color: COLORS.purple }}>Insight</span>
        </div>
        <div style={{ fontSize: '11px', color: COLORS.muted, display: 'flex', alignItems: 'center', gap: '6px' }}>
          <span>Exercises › <strong style={{ color: COLORS.text, fontWeight: 600 }}>{exercise.title}</strong></span>
        </div>
        <div style={{ marginLeft: 'auto', display: 'flex', alignItems: 'center', gap: '12px' }}>
          <span style={{ fontSize: '10px', fontWeight: 700, textTransform: 'uppercase', letterSpacing: '0.8px', padding: '4px 12px', borderRadius: '12px', background: 'rgba(136,123,176,0.15)', color: COLORS.purple, border: '1px solid rgba(136,123,176,0.3)' }}>
            {exercise.concept_name}
          </span>
          {timeRemaining && (
            <div style={{ fontFamily: "'Space Mono', monospace", fontSize: '12px', fontWeight: 700, color: timeRemaining < 300 ? COLORS.error : COLORS.warning, background: 'rgba(251,191,36,0.08)', padding: '4px 12px', borderRadius: '8px', border: '1px solid rgba(251,191,36,0.2)' }}>
              ⏱ {formatTime(timeRemaining)}
            </div>
          )}
        </div>
      </nav>

      <div style={{ display: 'flex', flex: 1, overflow: 'hidden' }}>
        <div style={{
          width: '340px',
          minWidth: '340px',
          background: COLORS.surface,
          borderRight: `1px solid ${COLORS.border}`,
          display: 'flex',
          flexDirection: 'column',
          overflow: 'hidden'
        }}>
          <div style={{ padding: '14px 18px', borderBottom: `1px solid ${COLORS.border}`, background: COLORS.surface2, flexShrink: 0 }}>
            <div style={{ fontSize: '13px', fontWeight: 700, color: COLORS.text }}>Problem Statement</div>
            <div style={{ fontSize: '10px', color: COLORS.muted, marginTop: '4px', display: 'flex', gap: '12px' }}>
              <span>⏱ {exercise.time_limit_minutes}m</span>
              <span>📅 {exercise.deadline ? new Date(exercise.deadline).toLocaleDateString('en-US', { month: 'short', day: 'numeric' }) : 'No deadline'}</span>
              <span>C++</span>
            </div>
          </div>
          <div style={{ padding: '16px 18px', overflowY: 'auto', flex: 1 }}>
            <div style={{ fontSize: '9px', fontWeight: 700, letterSpacing: '2px', textTransform: 'uppercase', color: COLORS.muted, marginBottom: '8px' }}>Description</div>
            <div style={{ fontSize: '12px', lineHeight: '1.7', color: COLORS.text, marginBottom: '18px' }}>{exercise.description}</div>

            <div style={{ background: COLORS.editorBg, border: `1px solid ${COLORS.border}`, borderRadius: '8px', padding: '12px', marginBottom: '12px' }}>
              <div style={{ fontSize: '9px', fontWeight: 700, letterSpacing: '1.5px', textTransform: 'uppercase', color: COLORS.muted, marginBottom: '6px' }}>Input</div>
              <div style={{ fontFamily: "'Space Mono', monospace", fontSize: '11px', color: COLORS.text, lineHeight: '1.6' }}>{exercise.input_format || 'Standard input'}</div>
            </div>

            <div style={{ background: COLORS.editorBg, border: `1px solid ${COLORS.border}`, borderRadius: '8px', padding: '12px' }}>
              <div style={{ fontSize: '9px', fontWeight: 700, letterSpacing: '1.5px', textTransform: 'uppercase', color: COLORS.muted, marginBottom: '6px' }}>Output</div>
              <div style={{ fontFamily: "'Space Mono', monospace", fontSize: '11px', color: COLORS.text, lineHeight: '1.6' }}>{exercise.output_format || 'Standard output'}</div>
            </div>

            {exercise.test_cases && Array.isArray(exercise.test_cases) && exercise.test_cases.length > 0 && (
              <div style={{ marginTop: '18px' }}>
                <div style={{ fontSize: '9px', fontWeight: 700, letterSpacing: '2px', textTransform: 'uppercase', color: COLORS.muted, marginBottom: '8px' }}>Sample Cases</div>
                {exercise.test_cases.slice(0, 2).map((tc, idx) => {
                  const result = testResults?.testResults?.[idx];
                  const statusColor = result?.passed === true ? COLORS.success : result?.passed === false ? COLORS.error : COLORS.muted;
                  const statusText = result?.passed === true ? '✓' : result?.passed === false ? '✗' : '—';
                  return (
                    <div key={idx} style={{ background: COLORS.editorBg, border: `1px solid ${COLORS.border}`, borderRadius: '8px', marginBottom: '8px', overflow: 'hidden' }}>
                      <div style={{ padding: '8px 12px', background: COLORS.surface2, borderBottom: `1px solid ${COLORS.border}`, fontSize: '9px', fontWeight: 700, letterSpacing: '1px', textTransform: 'uppercase', color: COLORS.muted, display: 'flex', justifyContent: 'space-between' }}>
                        <span>Test {idx + 1}</span>
                        <span style={{ color: statusColor }}>{statusText}</span>
                      </div>
                      <div style={{ padding: '10px 12px', display: 'grid', gridTemplateColumns: '1fr 1fr', gap: '10px' }}>
                        <div><div style={{ fontSize: '9px', color: COLORS.muted, marginBottom: '4px' }}>In</div><div style={{ fontFamily: "'Space Mono', monospace", fontSize: '9px', color: COLORS.text, whiteSpace: 'pre-wrap', wordBreak: 'break-all' }}>{(tc.input || tc.stdin || '').slice(0, 30)}</div></div>
                        <div><div style={{ fontSize: '9px', color: COLORS.muted, marginBottom: '4px' }}>Out</div><div style={{ fontFamily: "'Space Mono', monospace", fontSize: '9px', color: COLORS.text, whiteSpace: 'pre-wrap', wordBreak: 'break-all' }}>{(tc.expected_output || tc.expected || '').slice(0, 30)}</div></div>
                      </div>
                    </div>
                  );
                })}
              </div>
            )}
          </div>
        </div>

        <div style={{ flex: 1, display: 'flex', flexDirection: 'column', overflow: 'hidden' }}>
          <div style={{ padding: '8px 14px', background: COLORS.surface2, borderBottom: `1px solid ${COLORS.border}`, display: 'flex', alignItems: 'center', justifyContent: 'space-between', flexShrink: 0 }}>
            <div style={{ fontSize: '10px', fontWeight: 700, color: COLORS.teal, background: 'rgba(133,210,208,0.1)', padding: '3px 10px', borderRadius: '6px', fontFamily: "'Space Mono', monospace" }}>C++ • GCC 9.2</div>
            <div style={{ display: 'flex', gap: '8px' }}>
              {!running ? (
                <button onClick={handleRun} disabled={running} style={{ padding: '6px 14px', borderRadius: '7px', fontSize: '11px', fontWeight: 700, cursor: 'pointer', border: '1px solid #2a5a4a', background: '#1a4d3a', color: COLORS.success, fontFamily: "'DM Sans', sans-serif" }}>
                  ▶ Run
                </button>
              ) : (
                <button onClick={handleStop} style={{ padding: '6px 14px', borderRadius: '7px', fontSize: '11px', fontWeight: 700, cursor: 'pointer', border: '1px solid #d97757', background: '#d97757', color: '#fff', fontFamily: "'DM Sans', sans-serif" }}>
                  ⏹ Stop
                </button>
              )}
              <button onClick={handleSubmit} disabled={submitting} style={{ padding: '6px 14px', borderRadius: '7px', fontSize: '11px', fontWeight: 700, cursor: 'pointer', border: 'none', background: COLORS.teal, color: '#091a1a', fontFamily: "'DM Sans', sans-serif", opacity: submitting ? 0.6 : 1 }}>
                {submitting ? '⏳' : '✓ Submit'}
              </button>
            </div>
          </div>

          <div style={{ flex: 1, minHeight: 0, background: COLORS.editorBg }}>
            <Editor
              height="100%"
              defaultLanguage="cpp"
              value={code}
              onChange={(val) => setCode(val || '')}
              onMount={(editor) => { editorRef.current = editor; }}
              theme="vs-dark"
              options={{
                minimap: { enabled: false },
                fontSize: 13,
                fontFamily: "'Space Mono', monospace",
                lineNumbers: 'on',
                wordWrap: 'on',
                automaticLayout: true,
                padding: { top: 16, bottom: 16 },
                scrollBeyondLastLine: false
              }}
            />
          </div>

          <div style={{ height: '160px', background: COLORS.surface, borderTop: `1px solid ${COLORS.border}`, display: 'flex', flexDirection: 'column' }}>
            <div style={{ display: 'flex', borderBottom: `1px solid ${COLORS.border}`, background: COLORS.surface2 }}>
              {['output', 'log'].map(tab => (
                <button key={tab} onClick={() => setActiveTab(tab)} style={{ padding: '8px 16px', fontSize: '11px', fontWeight: 600, color: activeTab === tab ? COLORS.teal : COLORS.muted, cursor: 'pointer', border: 'none', background: 'transparent', borderBottom: activeTab === tab ? `2px solid ${COLORS.teal}` : '2px solid transparent', fontFamily: "'DM Sans', sans-serif" }}>
                  {tab === 'output' ? 'Output' : 'Compiler Log'}
                </button>
              ))}
            </div>
            <div style={{ flex: 1, padding: '12px 16px', fontFamily: "'Space Mono', monospace", fontSize: '11px', overflowY: 'auto', color: COLORS.text }}>
              {activeTab === 'output' ? (
                testResults ? (
                  <>
                    {!testResults.passed && testResults.testResults?.length > 0 && <div style={{ color: COLORS.error, marginBottom: '8px', fontWeight: 700 }}>✗ Wrong Answer</div>}
                    {testResults.testResults?.map((result, idx) => (
                      <div key={idx} style={{ marginBottom: '6px', padding: '6px', background: COLORS.surface2, borderRadius: '4px' }}>
                        <span style={{ color: result.passed ? COLORS.success : COLORS.error, fontWeight: 700 }}>Test {idx + 1}: {result.passed ? '✓' : '✗'}</span>
                        {(result.input || result.expected || result.actual) && <div style={{ fontSize: '10px', marginTop: '2px', color: COLORS.muted }}>I: {result.input} | E: {result.expected} | G: {result.actual}</div>}
                      </div>
                    ))}
                    <div style={{ marginTop: '12px', padding: '8px', background: COLORS.surface2, borderRadius: '4px', borderLeft: `3px solid ${testResults.cds <= 0.33 ? COLORS.success : testResults.cds <= 0.66 ? COLORS.warning : COLORS.error}` }}>
                      <div style={{ fontSize: '10px', color: COLORS.muted, marginBottom: '3px' }}>CDS Score:</div>
                      <div style={{ fontWeight: 700, fontSize: '12px', color: testResults.cds <= 0.33 ? COLORS.success : testResults.cds <= 0.66 ? COLORS.warning : COLORS.error }}>
                        {testResults.cds?.toFixed(2) || '—'} ({testResults.classification || 'Unscored'})
                      </div>
                    </div>
                    {testResults.hiddenSummary && (
                      <div style={{ marginTop: '8px', padding: '8px', background: COLORS.surface2, borderRadius: '4px', fontSize: '11px', color: COLORS.muted }}>
                        Hidden tests: {testResults.hiddenSummary.count} — {testResults.hiddenSummary.passed ? 'All passed' : 'Some failed'}
                      </div>
                    )}

                    {/* Micro-concept feedback panel */}
                    {testResults.microConceptFeedback && testResults.microConceptFeedback.hasFeedback && (
                      <div style={{ marginTop: '16px', padding: '12px', background: COLORS.surface2, borderRadius: '4px', borderLeft: `4px solid ${COLORS.teal}` }}>
                        <div style={{ fontSize: '10px', fontWeight: 700, letterSpacing: '1px', textTransform: 'uppercase', color: COLORS.muted, marginBottom: '8px' }}>
                          Specific Feedback
                        </div>
                        <div style={{ fontSize: '11px', lineHeight: '1.5', color: COLORS.text }}>
                          {testResults.microConceptFeedback.studentMessages?.map((msg, idx) => (
                            <div key={idx} style={{ marginBottom: '6px' }}>
                              <span style={{ color: COLORS.warning, fontWeight: 600 }}>💡</span> {msg}
                            </div>
                          )) || [
                            <div key="no-msg" style={{ marginBottom: '6px' }}>
                              <span style={{ color: COLORS.warning, fontWeight: 600 }}>💡</span> {testResults.microConceptFeedback.message}
                            </div>
                          ]}
                          {testResults.microConceptFeedback.evidence && testResults.microConceptFeedback.evidence.length > 0 && (
                            <div style={{ marginTop: '8px', fontSize: '10px', color: COLORS.muted }}>
                              <div style={{ fontWeight: 600, marginBottom: '4px' }}>Evidence:</div>
                              {testResults.microConceptFeedback.evidence.map((ev, idx) => (
                                <div key={idx} style={{ marginBottom: '4px', paddingLeft: '12px' }}>
                                  • {ev.evidence}
                                </div>
                              ))}
                            </div>
                          )}
                        </div>
                      </div>
                    )}
                  </>
                ) : <div style={{ color: COLORS.muted }}>(No output)</div>
              ) : (
                testResults ? (
                  <>
                    {testResults.testResults?.length > 0 && testResults.testResults[0]?.error && (
                      <>
                        {parseErrorBlock(testResults.testResults[0].error).map((block, idx) => renderErrorBlock(block, idx))}
                      </>
                    )}
                    {testResults.error && parseErrorBlock(testResults.error).map((block, idx) => renderErrorBlock(block, idx))}
                    {testResults.compilation_log && parseErrorBlock(testResults.compilation_log).map((block, idx) => renderErrorBlock(block, idx))}
                    {!testResults.testResults?.[0]?.error && !testResults.error && !testResults.compilation_log && <div style={{ color: COLORS.muted }}>(No compiler output)</div>}
                  </>
                ) : <div style={{ color: COLORS.muted }}>(No log)</div>
              )}
            </div>
          </div>
        </div>

        <div style={{ width: '200px', background: COLORS.surface, borderLeft: `1px solid ${COLORS.border}`, display: 'flex', flexDirection: 'column' }}>
          <div style={{ padding: '12px 14px', borderBottom: `1px solid ${COLORS.border}`, background: COLORS.surface2 }}>
            <div style={{ fontSize: '11px', fontWeight: 700, color: COLORS.text }}>Attempts ({attempts.length})</div>
          </div>
          <div style={{ padding: '12px', overflowY: 'auto', flex: 1 }}>
            {attempts.length === 0 ? (
              <div style={{ fontSize: '10px', color: COLORS.muted, textAlign: 'center', marginTop: '16px' }}>No attempts</div>
            ) : (
              attempts.map((attempt, idx) => (
                <div key={idx} style={{ background: COLORS.surface2, border: `1px solid ${attempt.passed ? COLORS.success : COLORS.error}`, borderLeft: `3px solid ${attempt.passed ? COLORS.success : COLORS.error}`, borderRadius: '6px', padding: '8px', marginBottom: '6px' }}>
                  <div style={{ fontSize: '9px', fontWeight: 700, color: COLORS.muted, marginBottom: '2px' }}>#{idx + 1}</div>
                  <div style={{ fontSize: '10px', fontWeight: 700, color: attempt.passed ? COLORS.success : COLORS.error }}>{attempt.passed ? '✓' : '✗'}</div>
                  <div style={{ fontSize: '8px', color: COLORS.muted }}>{new Date(attempt.submitted_at).toLocaleTimeString([], { hour: '2-digit', minute: '2-digit' })}</div>
                </div>
              ))
            )}
          </div>
        </div>
      </div>
    </div>
  );
}
