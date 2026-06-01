import { useState, useEffect, useRef } from 'react';
import { useParams, useNavigate } from 'react-router-dom';
import Editor from '@monaco-editor/react';
import api from '../../services/api';

// Color constants - matching mockup exactly
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

// Session state machine
const SESSION_STATES = {
  INITIAL: 'INITIAL',                      // Exercise loaded, awaiting confirmation
  READY_PENDING: 'READY_PENDING',          // Modal shown, waiting for confirmation
  IN_PROGRESS: 'IN_PROGRESS',              // Timer running, code editable
  PAUSED: 'PAUSED',                        // Tab hidden (Page Visibility API)
  COMPLETED_SUCCESS: 'COMPLETED_SUCCESS',  // Submitted & passed, ready for summary
  COMPLETED_TIMEOUT: 'COMPLETED_TIMEOUT',  // Time expired, show timeout summary
  COMPLETED_LOCKED: 'COMPLETED_LOCKED',    // Exercise already completed, no re-entry
  SUMMARY: 'SUMMARY',                      // Summary card visible, exit available
  CLOSED: 'CLOSED'                         // Exercise closed/exited
};

export default function StudentCodeEditor() {
  const { exerciseId } = useParams();
  const navigate = useNavigate();
  const [exercise, setExercise] = useState(null);
  const [code, setCode] = useState('');
  const [testResults, setTestResults] = useState(null);
  const [attempts, setAttempts] = useState([]);
  const [loading, setLoading] = useState(true);
  const [running, setRunning] = useState(false);
  const [submitting, setSubmitting] = useState(false);
  const [activeTab, setActiveTab] = useState('output');
  const [microConceptFeedback, setMicroConceptFeedback] = useState(null);
  const [timeRemaining, setTimeRemaining] = useState(null);
  const [abortController, setAbortController] = useState(null);
  
  // State machine
  const [sessionState, setSessionState] = useState(SESSION_STATES.INITIAL);
  const [showReadyModal, setShowReadyModal] = useState(false);
  const [showSummaryModal, setShowSummaryModal] = useState(false);
  const [pausedTime, setPausedTime] = useState(0);  // Track paused time for accurate active time
  
  const editorRef = useRef(null);
  const exerciseStartTimeRef = useRef(null);
  const pausedAtRef = useRef(null);  // Track when paused

  useEffect(() => {
    fetchExercise();
  }, [exerciseId]);

  useEffect(() => {
    if (sessionState === SESSION_STATES.IN_PROGRESS && timeRemaining > 0) {
      const timer = setTimeout(() => setTimeRemaining(timeRemaining - 1), 1000);
      return () => clearTimeout(timer);
    } else if (timeRemaining === 0 && sessionState === SESSION_STATES.IN_PROGRESS) {
      // Time expired - show timeout summary
      setSessionState(SESSION_STATES.COMPLETED_TIMEOUT);
      setShowSummaryModal(true);
      // Compute active time (exclude paused intervals)
      const activeTime = exerciseStartTimeRef.current
        ? Math.max(0, Math.floor((Date.now() - exerciseStartTimeRef.current) / 1000) - pausedTime - (pausedAtRef.current ? Math.floor((Date.now() - pausedAtRef.current) / 1000) : 0))
        : 0;
      // Auto-submit current code
      api.post(`/api/student/exercises/${exerciseId}/submit`, { 
        code,
        timeSpentSeconds: activeTime
      }).then(res => {
        setTestResults(res.data);
        setAttempts(prev => [res.data, ...prev]);
      }).catch(err => console.error('Auto-submit error:', err));
    }
  }, [timeRemaining, sessionState, pausedTime]);

  // Sync scroll between editor and output (if needed)
  useEffect(() => {
    function handleVisibilityChange() {
      if (!exercise) return;
      if (document.hidden) {
        // Pausing
        if (sessionState === SESSION_STATES.IN_PROGRESS) {
          pausedAtRef.current = Date.now();
          setSessionState(SESSION_STATES.PAUSED);
        }
      } else {
        // Resuming
        if (sessionState === SESSION_STATES.PAUSED && pausedAtRef.current) {
          const delta = Math.floor((Date.now() - pausedAtRef.current) / 1000);
          setPausedTime(prev => prev + delta);
          pausedAtRef.current = null;
          setSessionState(SESSION_STATES.IN_PROGRESS);
        }
      }
    }

    document.addEventListener('visibilitychange', handleVisibilityChange);
    return () => document.removeEventListener('visibilitychange', handleVisibilityChange);
  }, [exercise, sessionState]);

  const fetchExercise = async () => {
    try {
      const res = await api.get(`/api/student/exercises/${exerciseId}`);
      let exerciseData = res.data;
      if (exerciseData.test_cases && typeof exerciseData.test_cases === 'string') {
        exerciseData.test_cases = JSON.parse(exerciseData.test_cases);
      }
      setExercise(exerciseData);
      
      // BUG FIX #4: Check if student already completed this exercise
      if (exerciseData.isCompleted) {
        // Exercise already completed - show locked summary
        setSessionState(SESSION_STATES.COMPLETED_LOCKED);
        setShowSummaryModal(true);
        setTestResults({
          passed: true,
          completedAt: exerciseData.completedAt,
          lockedMessage: 'This exercise has already been completed.'
        });
        setLoading(false);
        return;
      }
      
      setCode(exerciseData?.starter_code || '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Write code here\n  return 0;\n}');
       
       // TIMER FIX: Always use exercise duration (time_limit_minutes), not deadline
       // Deadline is just when exercise closes, not what student sees in timer
       if (exerciseData.time_limit_minutes) {
         setTimeRemaining(exerciseData.time_limit_minutes * 60);
       }
       
      // Do NOT start timer yet - wait for confirmation modal
      setSessionState(SESSION_STATES.INITIAL);
      setShowReadyModal(true);
       
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

  const handleReadyConfirm = () => {
    // User confirmed, start the timer
    setShowReadyModal(false);
    setSessionState(SESSION_STATES.IN_PROGRESS);
    exerciseStartTimeRef.current = Date.now();
    // reset paused tracking
    pausedAtRef.current = null;
    setPausedTime(0);
  };

  const handleReadyCancel = () => {
    setShowReadyModal(false);
    navigate('/student/exercises');
  };

  // Page Visibility API - pause timer when tab hidden and resume when visible
  useEffect(() => {
    const onVisibility = () => {
      if (document.hidden) {
        // mark paused time start
        if (sessionState === SESSION_STATES.IN_PROGRESS && !pausedAtRef.current) {
          pausedAtRef.current = Date.now();
          setSessionState(SESSION_STATES.PAUSED);
        }
      } else {
        // resume and accumulate paused duration
        if (pausedAtRef.current) {
          const delta = Math.floor((Date.now() - pausedAtRef.current) / 1000);
          setPausedTime(prev => prev + delta);
          pausedAtRef.current = null;
          if (sessionState === SESSION_STATES.PAUSED) setSessionState(SESSION_STATES.IN_PROGRESS);
        }
      }
    };
    document.addEventListener('visibilitychange', onVisibility);
    return () => document.removeEventListener('visibilitychange', onVisibility);
  }, [sessionState]);

  const handleRun = async () => {
    if (sessionState !== SESSION_STATES.IN_PROGRESS) {
      alert('Please confirm you are ready to start the exercise.');
      return;
    }
    
    setRunning(true);
    const controller = new AbortController();
    setAbortController(controller);
    try {
      const res = await api.post(`/api/student/exercises/${exerciseId}/run`, { code }, 
        { signal: controller.signal });
      setTestResults(res.data);
      setActiveTab('output');
    } catch (err) {
      if (err.name !== 'AbortError') {
        setTestResults({
          passed: false,
          testResults: [],
          compilerError: err.response?.data?.message || err.message
        });
        setActiveTab('compiler');
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
      // Calculate active time (excluding paused intervals)
      const totalElapsedSeconds = exerciseStartTimeRef.current
        ? Math.floor((Date.now() - exerciseStartTimeRef.current) / 1000)
        : 0;
      let activeTimeSeconds = totalElapsedSeconds - pausedTime;
      if (pausedAtRef.current) {
        activeTimeSeconds -= Math.floor((Date.now() - pausedAtRef.current) / 1000);
      }
      activeTimeSeconds = Math.max(0, activeTimeSeconds);
      
      const res = await api.post(`/api/student/exercises/${exerciseId}/submit`, { 
        code,
        timeSpentSeconds: activeTimeSeconds
      });
      setTestResults(res.data);
      setMicroConceptFeedback(res.data.microConceptFeedback || null);
      setAttempts(prev => [res.data, ...prev]);
      setActiveTab('output');
      
      // On success, finalize paused tracking and stop timer
      const finalizePaused = () => {
        if (pausedAtRef.current) {
          const delta = Math.floor((Date.now() - pausedAtRef.current) / 1000);
          setPausedTime(prev => prev + delta);
          pausedAtRef.current = null;
        }
      };
      
      // BUG FIX #1: Only show summary on SUCCESS, not on failure
      if (res.data.passed) {
        // finalize and show success summary
        finalizePaused();
        setSessionState(SESSION_STATES.COMPLETED_SUCCESS);
        setShowSummaryModal(true);
      } else {
        // Failure - stay in IN_PROGRESS, show error, allow retry
        setSessionState(SESSION_STATES.IN_PROGRESS);
        setShowSummaryModal(false);
        // Show error notification in output tab
      }
    } catch (err) {
      setTestResults({
        passed: false,
        testResults: [],
        compilerError: err.response?.data?.message || err.message
      });
      setMicroConceptFeedback(null);
      setActiveTab('compiler');
      setSessionState(SESSION_STATES.IN_PROGRESS);
      setShowSummaryModal(false);
    } finally {
      setSubmitting(false);
    }
  };

  const handleExitExercise = () => {
    setShowSummaryModal(false);
    setSessionState(SESSION_STATES.CLOSED);
    // Navigate back or show completion message
    window.history.back();
  };

  const formatTime = (seconds) => {
    if (!seconds) return '0:00';
    const mins = Math.floor(seconds / 60);
    const secs = seconds % 60;
    return `${mins}:${secs.toString().padStart(2, '0')}`;
  };

  // Ready to start modal
  const ReadyModal = () => (
    <div style={{
      position: 'fixed',
      top: 0,
      left: 0,
      right: 0,
      bottom: 0,
      background: 'rgba(0,0,0,0.7)',
      display: 'flex',
      alignItems: 'center',
      justifyContent: 'center',
      zIndex: 1000
    }}>
      <div style={{
        background: COLORS.surface,
        border: `1px solid ${COLORS.border}`,
        borderRadius: '12px',
        padding: '32px',
        maxWidth: '400px',
        boxShadow: '0 20px 60px rgba(0,0,0,0.5)'
      }}>
        <div style={{ fontSize: '18px', fontWeight: 700, color: COLORS.text, marginBottom: '12px' }}>
          Ready to Code?
        </div>
        <div style={{ fontSize: '13px', color: COLORS.muted, marginBottom: '24px', lineHeight: '1.6' }}>
          Timer will start once you confirm. You have <strong style={{ color: COLORS.text }}>{exercise.time_limit_minutes} minutes</strong> to complete this exercise.
        </div>
        <div style={{ display: 'flex', gap: '12px', justifyContent: 'flex-end' }}>
          <button onClick={handleReadyCancel} style={{
            padding: '10px 16px',
            borderRadius: '8px',
            fontSize: '12px',
            fontWeight: 600,
            border: `1px solid ${COLORS.border}`,
            background: 'transparent',
            color: COLORS.muted,
            cursor: 'pointer',
            fontFamily: "'DM Sans', sans-serif",
            transition: 'all 0.15s'
          }}>
            Cancel
          </button>
          <button onClick={handleReadyConfirm} style={{
            padding: '10px 16px',
            borderRadius: '8px',
            fontSize: '12px',
            fontWeight: 600,
            border: 'none',
            background: COLORS.teal,
            color: '#091a1a',
            cursor: 'pointer',
            fontFamily: "'DM Sans', sans-serif",
            transition: 'all 0.15s'
          }}>
            Start Coding
          </button>
        </div>
      </div>
    </div>
  );

  // Summary card modal
  const SummaryModal = () => {
    const totalAttempts = attempts.length;
    const errors = testResults?.testResults?.filter(r => !r.passed).length || 0;
    const activeTime = exerciseStartTimeRef.current
      ? Math.floor((Date.now() - exerciseStartTimeRef.current) / 1000) - pausedTime
      : 0;

    // BUG FIX #1: Show different variants based on state
    const isLocked = sessionState === SESSION_STATES.COMPLETED_LOCKED;
    const isTimeout = sessionState === SESSION_STATES.COMPLETED_TIMEOUT;
    const isSuccess = testResults?.passed && !isTimeout;

    const headerColor = isLocked ? COLORS.muted : isTimeout ? COLORS.error : isSuccess ? COLORS.success : COLORS.error;
    const headerText = isLocked ? '🔒 Exercise Completed' : isTimeout ? '⏱ Time Limit Reached' : isSuccess ? '✓ Correct!' : '✗ Needs Work';
    const borderColor = isLocked ? COLORS.border : isTimeout ? COLORS.error : isSuccess ? COLORS.success : COLORS.error;

    return (
      <div style={{
        position: 'fixed',
        top: 0,
        left: 0,
        right: 0,
        bottom: 0,
        background: 'rgba(0,0,0,0.7)',
        display: 'flex',
        alignItems: 'center',
        justifyContent: 'center',
        zIndex: 1000
      }}>
        <div style={{
          background: COLORS.surface,
          border: `2px solid ${borderColor}`,
          borderRadius: '12px',
          padding: '32px',
          maxWidth: '450px',
          boxShadow: '0 20px 60px rgba(0,0,0,0.5)'
        }}>
          <div style={{ fontSize: '18px', fontWeight: 700, color: headerColor, marginBottom: '20px', display: 'flex', alignItems: 'center', gap: '8px' }}>
            {headerText}
          </div>
          
          {!isLocked && (
            <div style={{ display: 'grid', gridTemplateColumns: '1fr 1fr', gap: '16px', marginBottom: '24px' }}>
              <div style={{ background: COLORS.surface2, padding: '12px', borderRadius: '8px', border: `1px solid ${COLORS.border}` }}>
                <div style={{ fontSize: '11px', color: COLORS.muted, marginBottom: '4px' }}>Attempts</div>
                <div style={{ fontSize: '18px', fontWeight: 700, color: COLORS.text }}>{totalAttempts}</div>
              </div>
              <div style={{ background: COLORS.surface2, padding: '12px', borderRadius: '8px', border: `1px solid ${COLORS.border}` }}>
                <div style={{ fontSize: '11px', color: COLORS.muted, marginBottom: '4px' }}>Failed Tests</div>
                <div style={{ fontSize: '18px', fontWeight: 700, color: errors > 0 ? COLORS.error : COLORS.success }}>{errors}</div>
              </div>
              <div style={{ background: COLORS.surface2, padding: '12px', borderRadius: '8px', border: `1px solid ${COLORS.border}` }}>
                <div style={{ fontSize: '11px', color: COLORS.muted, marginBottom: '4px' }}>Time on Task</div>
                <div style={{ fontSize: '18px', fontWeight: 700, color: COLORS.text }}>{formatTime(activeTime)}</div>
              </div>
              <div style={{ background: COLORS.surface2, padding: '12px', borderRadius: '8px', border: `1px solid ${COLORS.border}` }}>
                <div style={{ fontSize: '11px', color: COLORS.muted, marginBottom: '4px' }}>Status</div>
                <div style={{ fontSize: '18px', fontWeight: 700, color: isSuccess ? COLORS.success : COLORS.warning }}>
                  {isSuccess ? 'Passed' : isTimeout ? 'Time Expired' : 'Submitted'}
                </div>
              </div>
            </div>
          )}
          
          <div style={{ 
            background: isLocked ? 'rgba(106,133,168,0.1)' : isTimeout ? 'rgba(248,113,113,0.1)' : isSuccess ? 'rgba(74,222,128,0.1)' : 'rgba(251,191,36,0.1)',
            border: `1px solid ${isLocked ? 'rgba(106,133,168,0.3)' : isTimeout ? 'rgba(248,113,113,0.3)' : isSuccess ? 'rgba(74,222,128,0.3)' : 'rgba(251,191,36,0.3)'}`,
            borderRadius: '8px', 
            padding: '12px',
            marginBottom: '24px',
            fontSize: '12px',
            color: headerColor
          }}>
            {isLocked
              ? '🔒 You have already completed this exercise and cannot reopen it.'
              : isTimeout
              ? '⏱ Time limit reached. Your latest submission has been recorded.'
              : isSuccess 
              ? '🎉 Congratulations! Your solution passed all test cases. The data has been saved to live CDS.'
              : '⚠️ Your submission has been recorded. Review the feedback and try again!'}
          </div>
          
          <div style={{ display: 'flex', gap: '12px', justifyContent: 'flex-end' }}>
            <button onClick={handleExitExercise} style={{
              padding: '10px 16px',
              borderRadius: '8px',
              fontSize: '12px',
              fontWeight: 600,
              border: 'none',
              background: COLORS.teal,
              color: '#091a1a',
              cursor: 'pointer',
              fontFamily: "'DM Sans', sans-serif",
              transition: 'all 0.15s'
            }}>
              {isLocked ? 'Return to Exercises' : 'Exit Exercise'}
            </button>
          </div>
        </div>
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
      {/* NAVBAR */}
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
          <span>Exercises</span>
          <span>›</span>
          <strong style={{ color: COLORS.text, fontWeight: 600 }}>{exercise.title}</strong>
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

      {/* MAIN WORKSPACE */}
      <div style={{ display: 'flex', flex: 1, overflow: 'hidden' }}>
        {/* LEFT SIDEBAR - PROBLEM PANEL */}
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
              <div style={{ fontSize: '9px', fontWeight: 700, letterSpacing: '1.5px', textTransform: 'uppercase', color: COLORS.muted, marginBottom: '6px' }}>Input Format</div>
              <div style={{ fontFamily: "'Space Mono', monospace", fontSize: '11px', color: COLORS.text, lineHeight: '1.6' }}>{exercise.input_format || 'Standard input'}</div>
            </div>

            <div style={{ background: COLORS.editorBg, border: `1px solid ${COLORS.border}`, borderRadius: '8px', padding: '12px' }}>
              <div style={{ fontSize: '9px', fontWeight: 700, letterSpacing: '1.5px', textTransform: 'uppercase', color: COLORS.muted, marginBottom: '6px' }}>Output Format</div>
              <div style={{ fontFamily: "'Space Mono', monospace", fontSize: '11px', color: COLORS.text, lineHeight: '1.6' }}>{exercise.output_format || 'Standard output'}</div>
            </div>

            {exercise.test_cases && Array.isArray(exercise.test_cases) && exercise.test_cases.length > 0 && (
              <div style={{ marginTop: '18px' }}>
                <div style={{ fontSize: '9px', fontWeight: 700, letterSpacing: '2px', textTransform: 'uppercase', color: COLORS.muted, marginBottom: '8px' }}>Sample Test Cases</div>
                {exercise.test_cases.filter(tc => !tc.hidden).slice(0, 3).map((tc, idx) => {
                  const result = testResults?.testResults?.[idx];
                  const statusColor = result?.passed === true ? COLORS.success : result?.passed === false ? COLORS.error : COLORS.muted;
                  const statusText = result?.passed === true ? '✓ Passed' : result?.passed === false ? '✗ Failed' : '— Not run';
                  return (
                    <div key={idx} style={{ background: COLORS.editorBg, border: `1px solid ${COLORS.border}`, borderRadius: '8px', marginBottom: '8px', overflow: 'hidden' }}>
                      <div style={{ padding: '8px 12px', background: COLORS.surface2, borderBottom: `1px solid ${COLORS.border}`, fontSize: '9px', fontWeight: 700, letterSpacing: '1px', textTransform: 'uppercase', color: COLORS.muted, display: 'flex', justifyContent: 'space-between', alignItems: 'center' }}>
                        <span>Test Case {idx + 1}</span>
                        <span style={{ color: statusColor }}>{statusText}</span>
                      </div>
                      <div style={{ padding: '10px 12px', display: 'grid', gridTemplateColumns: '1fr 1fr', gap: '10px' }}>
                        <div>
                          <div style={{ fontSize: '9px', color: COLORS.muted, marginBottom: '4px' }}>In</div>
                          <div style={{ fontFamily: "'Space Mono', monospace", fontSize: '10px', color: COLORS.text, whiteSpace: 'pre-wrap', wordBreak: 'break-all' }}>{tc.input || tc.stdin || '(empty)'}</div>
                        </div>
                        <div>
                          <div style={{ fontSize: '9px', color: COLORS.muted, marginBottom: '4px' }}>Out</div>
                          <div style={{ fontFamily: "'Space Mono', monospace", fontSize: '10px', color: COLORS.text, whiteSpace: 'pre-wrap', wordBreak: 'break-all' }}>{tc.expected_output || tc.expected || '(empty)'}</div>
                        </div>
                      </div>
                    </div>
                  );
                })}
              </div>
            )}
          </div>
        </div>

        {/* CENTER - CODE EDITOR */}
        <div style={{ flex: 1, display: 'flex', flexDirection: 'column', overflow: 'hidden' }}>
          {/* Editor toolbar */}
          <div style={{ padding: '8px 14px', background: COLORS.surface2, borderBottom: `1px solid ${COLORS.border}`, display: 'flex', alignItems: 'center', justifyContent: 'space-between', flexShrink: 0 }}>
            <div style={{ fontSize: '10px', fontWeight: 700, color: COLORS.teal, background: 'rgba(133,210,208,0.1)', padding: '3px 10px', borderRadius: '6px', fontFamily: "'Space Mono', monospace" }}>C++ (GCC 9.2)</div>
            <div style={{ display: 'flex', gap: '8px' }}>
              {!running ? (
                <button onClick={handleRun} disabled={running || sessionState !== SESSION_STATES.IN_PROGRESS} style={{ padding: '6px 14px', borderRadius: '7px', fontSize: '11px', fontWeight: 700, cursor: running ? 'not-allowed' : 'pointer', border: '1px solid #2a5a4a', background: '#1a4d3a', color: COLORS.success, fontFamily: "'DM Sans', sans-serif", transition: 'all 0.15s', opacity: running ? 0.6 : 1 }}>
                  ▶ Run
                </button>
              ) : (
                <button onClick={handleStop} style={{ padding: '6px 14px', borderRadius: '7px', fontSize: '11px', fontWeight: 700, cursor: 'pointer', border: '1px solid #d97757', background: '#d97757', color: '#fff', fontFamily: "'DM Sans', sans-serif", transition: 'all 0.15s' }}>
                  ⏹ Stop
                </button>
              )}
              <button onClick={handleSubmit} disabled={submitting || sessionState !== SESSION_STATES.IN_PROGRESS} style={{ padding: '6px 14px', borderRadius: '7px', fontSize: '11px', fontWeight: 700, cursor: submitting ? 'not-allowed' : 'pointer', border: 'none', background: COLORS.teal, color: '#091a1a', fontFamily: "'DM Sans', sans-serif", transition: 'all 0.15s', opacity: submitting ? 0.6 : 1 }}>
                {submitting ? '⏳...' : '✓ Submit'}
              </button>
            </div>
          </div>

          {/* Monaco Editor */}
          <div style={{ flex: 1, minHeight: 0, background: COLORS.editorBg }}>
            <Editor
              onMount={(editor) => (editorRef.current = editor)}
              height="100%"
              defaultLanguage="cpp"
              value={code}
              onChange={(val) => setCode(val || '')}
              theme="vs-dark"
              options={{
                minimap: { enabled: false },
                fontSize: 13,
                fontFamily: "'Space Mono', monospace",
                lineNumbers: 'on',
                wordWrap: 'on',
                automaticLayout: true,
                background: COLORS.editorBg,
                scrollBeyondLastLine: false,
                padding: { top: 16, bottom: 16 }
              }}
            />
          </div>

          {/* Output panel */}
          <div style={{ height: '160px', minHeight: '160px', background: COLORS.surface, borderTop: `1px solid ${COLORS.border}`, display: 'flex', flexDirection: 'column', flexShrink: 0 }}>
            <div style={{ display: 'flex', borderBottom: `1px solid ${COLORS.border}`, background: COLORS.surface2 }}>
              {['output', 'feedback', 'compiler'].map(tab => (
                <button key={tab} onClick={() => setActiveTab(tab)} style={{ padding: '8px 16px', fontSize: '11px', fontWeight: 600, color: activeTab === tab ? COLORS.teal : COLORS.muted, cursor: 'pointer', border: 'none', background: 'transparent', borderBottom: activeTab === tab ? `2px solid ${COLORS.teal}` : '2px solid transparent', fontFamily: "'DM Sans', sans-serif", transition: 'all 0.15s' }}>
                  {tab === 'output' ? 'Output' : tab === 'feedback' ? 'Feedback' : 'Compiler'}
                </button>
              ))}
            </div>
            <div style={{ flex: 1, padding: '12px 16px', fontFamily: "'Space Mono', monospace", fontSize: '11px', overflowY: 'auto', color: COLORS.text }}>
              {activeTab === 'output' ? (
                testResults ? (
                  <>
                    {!testResults.passed && testResults.testResults?.length > 0 && (
                      <div style={{ display: 'inline-flex', alignItems: 'center', gap: '6px', padding: '4px 12px', borderRadius: '20px', fontSize: '10px', fontWeight: 700, marginBottom: '8px', background: 'rgba(248,113,113,0.12)', color: COLORS.error, border: '1px solid rgba(248,113,113,0.2)' }}>
                        ✗ Wrong Answer
                      </div>
                    )}
                    {testResults.testResults?.filter(r => !r.hidden).map((result, idx) => (
                      <div key={idx} style={{ marginBottom: '8px', padding: '8px', background: COLORS.surface2, borderRadius: '6px' }}>
                        <span style={{ color: result.passed ? COLORS.success : COLORS.error, fontWeight: 700 }}>Test Case {idx + 1}: {result.passed ? '✓ Pass' : '✗ Fail'}</span>
                        {result.input && <div style={{ fontSize: '10px', marginTop: '4px', color: COLORS.muted }}>Input: {result.input}</div>}
                        {result.expected && <div style={{ fontSize: '10px', color: COLORS.muted }}>Expected: {result.expected}</div>}
                        {result.actual && <div style={{ fontSize: '10px', color: COLORS.muted }}>Got: {result.actual}</div>}
                      </div>
                    ))}
                  </>
                ) : (
                  <div style={{ color: COLORS.muted }}>(No output yet)</div>
                )
              ) : activeTab === 'feedback' ? (
                microConceptFeedback ? (
                  <>
                    {microConceptFeedback.hasFeedback ? (
                      <>
                        <div style={{ marginBottom: '12px', padding: '10px', background: 'rgba(167,139,250,0.1)', border: `1px solid rgba(167,139,250,0.3)`, borderRadius: '6px', color: COLORS.purple, fontSize: '11px', fontWeight: 600 }}>
                          ⚠️ {microConceptFeedback.summary}
                        </div>
                        {microConceptFeedback.issues && microConceptFeedback.issues.map((issue, idx) => (
                          <div key={idx} style={{ marginBottom: '10px', padding: '10px', background: COLORS.surface2, borderRadius: '6px', borderLeft: `3px solid ${COLORS.warning}` }}>
                            <div style={{ fontWeight: 700, color: COLORS.warning, marginBottom: '4px' }}>• {issue.name}</div>
                            <div style={{ fontSize: '10px', color: COLORS.muted, marginBottom: '4px' }}>{issue.description}</div>
                            {microConceptFeedback.evidence?.[idx]?.evidence && (
                              <div style={{ fontSize: '9px', color: COLORS.text, background: COLORS.editorBg, padding: '6px', borderRadius: '4px', fontFamily: "'Space Mono', monospace", whiteSpace: 'pre-wrap', wordBreak: 'break-word' }}>
                                {microConceptFeedback.evidence[idx].evidence}
                              </div>
                            )}
                          </div>
                        ))}
                        {microConceptFeedback.suggestedAction && (
                          <div style={{ marginTop: '12px', padding: '10px', background: 'rgba(74,222,128,0.1)', border: `1px solid rgba(74,222,128,0.3)`, borderRadius: '6px', color: COLORS.success, fontSize: '10px' }}>
                            💡 {microConceptFeedback.suggestedAction}
                          </div>
                        )}
                      </>
                    ) : (
                      <div style={{ color: COLORS.success, fontSize: '11px', fontWeight: 700 }}>
                        ✓ No specific micro-concept issues detected. Great work!
                      </div>
                    )}
                  </>
                ) : (
                  <div style={{ color: COLORS.muted }}>(No feedback yet - submit code to receive feedback)</div>
                )
              ) : activeTab === 'compiler' ? (
                testResults ? (
                  <>
                    {testResults.compilerError ? (
                      <div style={{ color: COLORS.error, whiteSpace: 'pre-wrap', wordBreak: 'break-word', fontFamily: "'Space Mono', monospace", fontSize: '11px' }}>
                        {testResults.compilerError}
                      </div>
                    ) : (
                      <div style={{ color: COLORS.success, fontSize: '12px' }}>✓ Code compiled successfully</div>
                    )}
                  </>
                ) : (
                  <div style={{ color: COLORS.muted }}>(No compiler output yet)</div>
                )
              ) : (
                <div style={{ color: COLORS.muted }}>(Unknown tab)</div>
              )}
            </div>
          </div>
        </div>

        {/* RIGHT SIDEBAR - ATTEMPTS */}
        <div style={{ width: '200px', minWidth: '200px', background: COLORS.surface, borderLeft: `1px solid ${COLORS.border}`, display: 'flex', flexDirection: 'column', overflow: 'hidden' }}>
          <div style={{ padding: '12px 14px', borderBottom: `1px solid ${COLORS.border}`, background: COLORS.surface2, flexShrink: 0 }}>
            <div style={{ fontSize: '11px', fontWeight: 700, color: COLORS.text }}>Attempts ({attempts.length})</div>
          </div>
          <div style={{ padding: '12px', overflowY: 'auto', flex: 1 }}>
            {attempts.length === 0 ? (
              <div style={{ fontSize: '10px', color: COLORS.muted, textAlign: 'center', marginTop: '16px' }}>No attempts</div>
            ) : (
              attempts.map((attempt, idx) => (
                <div key={idx} style={{ background: COLORS.surface2, border: `1px solid ${attempt.passed ? COLORS.success : COLORS.error}`, borderLeft: `3px solid ${attempt.passed ? COLORS.success : COLORS.error}`, borderRadius: '8px', padding: '10px', marginBottom: '8px' }}>
                  <div style={{ fontSize: '9px', fontWeight: 700, letterSpacing: '1px', textTransform: 'uppercase', color: COLORS.muted, marginBottom: '4px' }}>#{idx + 1}</div>
                  <div style={{ fontSize: '10px', fontWeight: 700, color: attempt.passed ? COLORS.success : COLORS.error, marginBottom: '3px' }}>{attempt.passed ? '✓ Pass' : '✗ Fail'}</div>
                  <div style={{ fontSize: '9px', color: COLORS.muted }}>{new Date(attempt.submitted_at || attempt.created_at || Date.now()).toLocaleTimeString([], { hour: '2-digit', minute: '2-digit' })}</div>
                </div>
              ))
            )}
          </div>
        </div>
      </div>

      {/* MODALS */}
      {showReadyModal && <ReadyModal />}
      {showSummaryModal && <SummaryModal />}
    </div>
  );
}
