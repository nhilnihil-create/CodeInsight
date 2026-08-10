import { useCallback, useEffect, useMemo, useRef, useState } from "react";
import { useNavigate, useParams } from "react-router-dom";
import { motion } from "framer-motion";
import { toast } from "sonner";
import api from "@/services/api";
import { useStudentContext } from "@/context/StudentContext";
import { countTokens } from "@/lib/countTokens";
import EditorHeader from "./editor/EditorHeader";
import ResizableWorkbench from "./editor/ResizableWorkbench";
import MobileEditorTabs from "./editor/MobileEditorTabs";
import EditorActionBar from "./editor/EditorActionBar";

const TAB_DEFAULT = "code";

function transformExercise(ex) {
  return {
    ...ex,
    concepts: ex.concept_name
      ? [{ code: ex.concept_name.slice(0, 2).toUpperCase(), name: ex.concept_name }]
      : [],
    deadlineLabel: ex.deadline
      ? new Date(ex.deadline).toLocaleDateString("en-US", { month: "short", day: "numeric" })
      : null,
  };
}

function transformTestResults(apiResults, compilerError, hiddenSummary) {
  const visible = (apiResults || []).filter((r) => !r.hidden);
  const hidden = (apiResults || []).filter((r) => r.hidden);
  return {
    passing: visible.filter((r) => r.passed).length,
    total: visible.length,
    passed: visible.length > 0 && visible.every((r) => r.passed),
    error: null,
    compilationLog: compilerError || "",
    programOutput: visible.map((r) => r.actual ?? "").join("\n"),
    testResults: visible.map((r, i) => ({
      id: i,
      name: r.name || `Test ${i + 1}`,
      passed: r.passed,
      runtimeMs: r.runtimeMs || 0,
      input: r.input,
      expected: r.expected,
      actual: r.actual,
    })),
    publicTests: visible.map((r, i) => ({
      id: i,
      name: r.name || `Test ${i + 1}`,
      passed: r.passed,
      runtimeMs: r.runtimeMs || 0,
      input: r.input,
      expected: r.expected,
      actual: r.actual,
    })),
    hidden: {
      total: hiddenSummary?.count ?? hidden.length,
      failed: hiddenSummary?.failed ?? hidden.filter((r) => !r.passed).length,
    },
  };
}

function transformAttempts(attempts, totalTests, language) {
  const submissions = (attempts || []).map((a) => ({
    id: a.id,
    attemptNumber: a.attempt_number,
    status: a.passed ? "accepted" : "wrong_answer",
    passed: a.passed_count ?? (a.passed ? totalTests : 0),
    total: (a.total_count ?? totalTests) || 0,
    runtime: "--",
    memory: "--",
    language: language || "C++",
    timestamp: formatTimestamp(a.submitted_at),
    input: "",
    expected: "",
    actual: "",
  }));
  const history = (attempts || []).map((a) => ({
    id: `s-${a.id}`,
    type: "submission",
    label: a.passed
      ? "Submitted \u00b7 Passed"
      : `Submitted \u00b7 Attempt #${a.attempt_number}`,
    timestamp: formatTimestamp(a.submitted_at),
  }));
  return { submissions, history };
}

function formatTimestamp(dateStr) {
  if (!dateStr) return "";
  const d = new Date(dateStr);
  const now = new Date();
  const diffMs = now - d;
  const diffMin = Math.floor(diffMs / 60000);
  if (diffMin < 1) return "just now";
  if (diffMin < 60) return `${diffMin}m ago`;
  const diffHr = Math.floor(diffMin / 60);
  if (diffHr < 24) return `${diffHr}h ago`;
  return `${Math.floor(diffHr / 24)}d ago`;
}

function createSessionId() {
  return crypto?.randomUUID?.() ?? `session-${Date.now()}-${Math.random().toString(36).slice(2)}`;
}

export default function StudentCodeEditor() {
  const navigate = useNavigate();
  const { exerciseId } = useParams();
  const { activeSectionId } = useStudentContext();
  const sectionParams = useMemo(
    () => (activeSectionId ? { sectionId: activeSectionId } : {}),
    [activeSectionId]
  );
  const [exercise, setExercise] = useState(null);
  const [code, setCode] = useState("");
  const [testResults, setTestResults] = useState(null);
  const [submissions, setSubmissions] = useState([]);
  const [history, setHistory] = useState([]);
  const [activeElapsedSeconds, setActiveElapsedSeconds] = useState(0);
  const [isSolved, setIsSolved] = useState(false);
  const [preCheckHints, setPreCheckHints] = useState([]);
  const [activeTab, setActiveTab] = useState(TAB_DEFAULT);
  const [isRunning, setIsRunning] = useState(false);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const editorRef = useRef(null);
  const isSubmittingRef = useRef(false);
  const behavioralCounts = useRef({ tabSwitches: 0, pastes: 0 });
  const pendingEventsRef = useRef([]);
  const editorContainerRef = useRef(null);
  // Code-sampling pipeline refs (growth velocity). Independent of the
  // behavioral logging refs above.
  const sessionIdRef = useRef(createSessionId());
  const activeElapsedSecondsRef = useRef(0);
  const autoCompleteRef = useRef(false);
  const pendingSnapshotsRef = useRef([]);
  const flushSnapshotsRef = useRef(null);
  const codeRef = useRef("");

  const isCompleted = !!exercise?.isCompleted;
  // Review mode: the exercise was already completed or solved this session.
  // In review mode the editor is read-only, Run/Submit are inert, and no
  // behavioral telemetry is collected.
  const isReviewMode = isCompleted || isSolved;

  useEffect(() => {
    const id = exerciseId;
    if (!id) return;
    let cancelled = false;
    setLoading(true);
    setError(null);
    setIsSolved(false);
    api
      .get(`/api/student/exercises/${id}`, { params: sectionParams })
      .then((r) => {
        if (cancelled) return;
        const ex = r.data;
        const transformed = transformExercise(ex);
        setExercise(transformed);
        setCode(ex.starter_code || "");
        setLoading(false);
      })
      .catch((err) => {
        if (cancelled) return;
        setError(
          err.response?.status === 403
            ? "You are not enrolled in this section."
            : err.response?.data?.message || err.message || "Failed to load exercise"
        );
        setLoading(false);
      });
    return () => {
      cancelled = true;
    };
  }, [exerciseId, sectionParams]);

  useEffect(() => {
    if (!exerciseId) return;
    let cancelled = false;
    setSubmissions([]);
    setHistory([]);
    api
      .get(`/api/student/exercises/${exerciseId}/attempts`, { params: sectionParams })
      .then((r) => {
        if (cancelled) return;
        const totalTests = Array.isArray(exercise?.test_cases) ? exercise.test_cases.length : 0;
        const { submissions: subs, history: hist } = transformAttempts(r.data || [], totalTests, 'cpp');
        setSubmissions(subs);
        setHistory(hist);
      })
      .catch((err) => console.warn('Failed to load attempts:', err.message));
    return () => {
      cancelled = true;
    };
  }, [exerciseId, sectionParams]);

  // Mirror of the `code` state for the sampling pipeline: interval
  // callbacks must not close over stale state, and the Monaco instance
  // may be unmounted (mobile tab switch) so the state mirror is the
  // fallback source at sample time.
  useEffect(() => {
    codeRef.current = code;
  }, [code]);

  // One session id per exercise: regenerate whenever the route changes so
  // snapshots are grouped by (student, exercise, session).
  useEffect(() => {
    sessionIdRef.current = createSessionId();
  }, [exerciseId]);

  useEffect(() => {
    if (isCompleted || isSolved) return undefined;
    const id = setInterval(() => {
      setActiveElapsedSeconds((s) => s + 1);
      activeElapsedSecondsRef.current += 1;
    }, 1000);
    return () => {
      clearInterval(id);
    };
  }, [isCompleted, isSolved]);

  // ── Contextual Activity Logging (paper flag #5) ───────────────────────
  // Track tab switches and paste events. Sends cumulative counts with each
  // run (server-owned per-run snapshot) AND asynchronously flushes raw
  // events for the audit trail every 10 seconds.
  useEffect(() => {
    if (!exerciseId || isReviewMode) return;

    // Reset counters when entering a new exercise session
    behavioralCounts.current = { tabSwitches: 0, pastes: 0 };
    pendingEventsRef.current = [];

    // Tab-switch tracking. A single "hidden episode" can fire blur AND
    // visibilitychange together, so the isAway flag dedupes them per episode.
    let isAway = false;
    const markAway = () => {
      if (isAway) return;
      isAway = true;
      behavioralCounts.current.tabSwitches += 1;
      pendingEventsRef.current.push({ type: 'tab_switch', timestamp: new Date().toISOString() });
    };
    const markBack = () => {
      isAway = false;
    };

    const handleVisibilityChange = () => {
      if (document.hidden) markAway();
      else markBack();
    };
    const handleWindowBlur = () => {
      if (!document.hasFocus()) markAway();
    };
    const handleWindowFocus = () => markBack();

    // Paste tracking: capture-phase document paste + a ctrl/cmd+V keydown
    // fallback (some browsers don't fire paste on document) with a 300ms
    // dedupe window, plus drag-drop onto the editor container.
    let lastKeydownPasteAt = 0;
    const handlePaste = () => {
      behavioralCounts.current.pastes += 1;
      pendingEventsRef.current.push({ type: 'paste', timestamp: new Date().toISOString() });
    };
    const handleKeydownPaste = (e) => {
      if (!(e.ctrlKey || e.metaKey) || (e.key !== 'v' && e.key !== 'V')) return;
      const now = Date.now();
      if (now - lastKeydownPasteAt < 300) return;
      lastKeydownPasteAt = now;
      handlePaste();
    };

    // Flush events to backend every 10 seconds (audit trail)
    let flushTimer = null;
    const flushEvents = async () => {
      if (pendingEventsRef.current.length === 0) return;
      const toSend = pendingEventsRef.current.splice(0, pendingEventsRef.current.length);
      try {
        await api.post('/api/student/behavioral-events', {
          exerciseId: parseInt(exerciseId),
          events: toSend,
        });
      } catch (_) {
        // Non-fatal: don't break the editor if telemetry fails
      }
    };

    document.addEventListener('visibilitychange', handleVisibilityChange);
    window.addEventListener('blur', handleWindowBlur);
    window.addEventListener('focus', handleWindowFocus);
    document.addEventListener('paste', handlePaste, true);
    document.addEventListener('keydown', handleKeydownPaste);
    flushTimer = setInterval(flushEvents, 10000);

    return () => {
      document.removeEventListener('visibilitychange', handleVisibilityChange);
      window.removeEventListener('blur', handleWindowBlur);
      window.removeEventListener('focus', handleWindowFocus);
      document.removeEventListener('paste', handlePaste, true);
      document.removeEventListener('keydown', handleKeydownPaste);
      clearInterval(flushTimer);
      flushEvents(); // Final flush on unmount
    };
  }, [exerciseId, isReviewMode]);

  // ── Code Sampling (growth velocity) ─────────────────────────────────────
  // Independent sampling pipeline: every 4s record a sample
  // (tokenCount, activeElapsedSeconds, autocomplete-used) into a local
  // buffer; flush the buffer to the backend every 30s. On visibility loss
  // take a final sample + flush and pause sampling. flushSnapshotsRef is
  // exposed so the submit handler can flush before recording a submission.
  useEffect(() => {
    if (!exerciseId || isReviewMode) return;

    let paused = false;
    const sample = () => {
      if (paused) return;
      // Prefer the live editor text; fall back to the state mirror when
      // the editor isn't mounted (a disposed instance can throw).
      let currentCode = codeRef.current;
      try {
        currentCode = editorRef.current?.getValue() ?? currentCode;
      } catch {
        // Disposed editor — keep the state mirror value.
      }
      pendingSnapshotsRef.current.push({
        tokenCount: countTokens(currentCode),
        activeElapsedSeconds: activeElapsedSecondsRef.current,
        autocomplete: autoCompleteRef.current,
      });
      autoCompleteRef.current = false;
    };
    const flush = async () => {
      if (pendingSnapshotsRef.current.length === 0) return;
      const samples = pendingSnapshotsRef.current.splice(0, pendingSnapshotsRef.current.length);
      try {
        await api.post('/api/student/code-snapshots', {
          exerciseId: parseInt(exerciseId, 10),
          sessionId: sessionIdRef.current,
          samples,
        });
      } catch (_) {
        // Non-fatal: don't break the editor if snapshot telemetry fails
      }
    };
    flushSnapshotsRef.current = flush;

    const interval = setInterval(sample, 4000);
    const flushInterval = setInterval(flush, 30000);
    const onVisibility = () => {
      if (document.hidden) {
        sample();
        flush();
        paused = true;
      } else {
        paused = false;
      }
    };
    document.addEventListener('visibilitychange', onVisibility);

    return () => {
      clearInterval(interval);
      clearInterval(flushInterval);
      document.removeEventListener('visibilitychange', onVisibility);
      sample();
      flush();
    };
  }, [exerciseId, isReviewMode]);

  // Drag-drop paste: the editor container only mounts once the exercise has
  // loaded, so the drop listener is attached separately from the listeners
  // above and re-attached whenever the container (or review mode) changes.
  useEffect(() => {
    const container = editorContainerRef.current;
    if (!container || isReviewMode) return undefined;
    const handleDrop = (e) => {
      if (!e.dataTransfer?.types?.length) return;
      behavioralCounts.current.pastes += 1;
      pendingEventsRef.current.push({ type: 'paste', timestamp: new Date().toISOString() });
    };
    container.addEventListener('drop', handleDrop, true);
    return () => container.removeEventListener('drop', handleDrop, true);
  }, [isReviewMode, exercise]);

  const handleRun = async () => {
    if (!exerciseId || isReviewMode) return;
    setIsRunning(true);
    setTestResults(null);
    try {
      const r = await api.post(`/api/student/exercises/${exerciseId}/run`, {
        code,
        language: 'cpp',
        tabSwitchCount: behavioralCounts.current.tabSwitches,
        pasteCount: behavioralCounts.current.pastes,
        timeSpentSeconds: activeElapsedSeconds,
        lineCount: code.split('\n').filter((line) => line.trim().length > 0).length,
      }, { params: sectionParams });
      const { testResults: rawResults, compilerError, hidden } = r.data;
      setTestResults(transformTestResults(rawResults, compilerError, hidden));
      // The backend persists this run's snapshot (run_attempts), so the
      // counters become server-owned per run — reset for the next run.
      behavioralCounts.current = { tabSwitches: 0, pastes: 0 };
      pendingEventsRef.current = [];
    } catch (err) {
      toast.error(err.response?.data?.message || err.message || "Run failed");
    } finally {
      setIsRunning(false);
    }
  };

  const handleSubmit = async () => {
    if (!exerciseId) {
      toast.error("No exercise in URL — open an exercise to submit.");
      return;
    }
    if (isSubmittingRef.current) return;
    isSubmittingRef.current = true;
    if (isReviewMode) {
      if (isCompleted) toast.info("Exercise already completed. Your CDS is locked.");
      isSubmittingRef.current = false;
      return;
    }
    setIsRunning(true);
    try {
      // Flush pending behavioral events BEFORE submit — awaited so the audit
      // trail is complete before the submission is recorded (the submit
      // endpoint aggregates session totals from per-run run_attempts).
      if (pendingEventsRef.current.length > 0) {
        const pending = pendingEventsRef.current.splice(0, pendingEventsRef.current.length);
        try {
          await api.post('/api/student/behavioral-events', {
            exerciseId: parseInt(exerciseId),
            events: pending,
          });
        } catch (err) {
          console.warn('Failed to flush behavioral events:', err.message);
        }
      }

      // Flush pending code snapshots BEFORE submit so the growth-velocity
      // trail is complete when the submission is recorded. The flush never
      // throws (failures are swallowed inside), so no extra handling.
      if (flushSnapshotsRef.current) {
        await flushSnapshotsRef.current();
      }

      const r = await api.post(`/api/student/exercises/${exerciseId}/submit`, {
        code,
        language: 'cpp',
        timeSpentSeconds: activeElapsedSeconds,
        tabSwitchCount: behavioralCounts.current.tabSwitches,
        pasteCount: behavioralCounts.current.pastes,
        sessionId: sessionIdRef.current,
      }, { params: sectionParams });
      const data = r.data;
      const hidden = data.hiddenTestCount ?? 0;
      const cds = data.liveCDS?.cds ?? data.liveCDS;

      if (data.testResults) {
        setTestResults(transformTestResults(data.testResults, data.compilerError, data.hidden));
      }
      if (data.passed) setIsSolved(true);
      if (data.preCheckHints) {
        setPreCheckHints(data.preCheckHints);
      }

      const hiddenTestText = hidden > 0 ? ` · ${hidden} hidden test${hidden === 1 ? "" : "s"}` : "";
      const hasLiveCds = cds !== null && cds !== undefined;
      if (data.passed) {
        toast.success(
          hasLiveCds
            ? `All tests passed! Exercise completed 🎉 · live CDS ${(cds * 100).toFixed(0)}%${hiddenTestText}`
            : `All tests passed! Exercise completed 🎉${hiddenTestText}`
        );
      } else if (data.verification && data.verification.passed === false &&
                 Array.isArray(data.verification.reasons) && data.verification.reasons.length > 0) {
        const firstReason = data.verification.reasons[0];
        const reasonMessage = firstReason?.message || "Structure verification failed";
        toast.error(reasonMessage);
        setPreCheckHints([{ level: 'hint', message: reasonMessage }]);
      } else {
        toast.success(`Submitted · ${hidden} hidden test${hidden === 1 ? "" : "s"}`);
      }

      // Reflect completion in-session so the "Exercise Completed" banner and
      // review mode appear immediately after the first successful submit.
      setExercise((prev) =>
        prev ? { ...prev, isCompleted: data.isCompleted ?? data.passed } : prev
      );

      try {
        const attRes = await api.get(`/api/student/exercises/${exerciseId}/attempts`, { params: sectionParams });
        const totalTests = Array.isArray(exercise?.test_cases) ? exercise.test_cases.length : 0;
        const { submissions: subs, history: hist } = transformAttempts(attRes.data || [], totalTests, 'cpp');
        setSubmissions(subs);
        setHistory(hist);
      } catch {}
    } catch (err) {
      toast.error(err.response?.data?.message || err.message || "Submission failed");
    } finally {
      isSubmittingRef.current = false;
      setIsRunning(false);
    }
  };

  const handleMount = (editor) => {
    editorRef.current = editor;
  };

  // Fired by Monaco when the user accepts a suggestion; flagged on the
  // next code sample via autoCompleteRef.
  const handleAutocompleteAccept = useCallback(() => {
    autoCompleteRef.current = true;
  }, []);

  const handleBack = useCallback(() => {
    navigate("/student/exercises");
  }, [navigate]);

  const handleCodeChange = (newCode) => {
    setPreCheckHints([]);
    setCode(newCode);
  };

  const handleClearTerminal = useCallback(() => {
    setTestResults((prev) => (prev ? { ...prev, programOutput: "" } : prev));
  }, []);

  if (loading) {
    return (
      <div className="flex h-full min-h-0 flex-col bg-background items-center justify-center">
        <div className="space-y-4 w-64">
          <div className="h-4 bg-muted rounded animate-pulse" />
          <div className="h-4 bg-muted rounded animate-pulse w-3/4" />
          <div className="h-4 bg-muted rounded animate-pulse w-1/2" />
        </div>
      </div>
    );
  }

  if (error) {
    return (
      <div className="flex h-full min-h-0 flex-col bg-background items-center justify-center gap-4">
        <p className="text-destructive text-sm">{error}</p>
        <button
          type="button"
          onClick={handleBack}
          className="inline-flex items-center gap-1.5 h-8 px-3 rounded-md border border-border bg-card text-xs font-medium hover:bg-muted transition-colors"
        >
          Back to exercises
        </button>
      </div>
    );
  }

  if (!exercise) return null;

  return (
    <motion.div
      ref={editorContainerRef}
      initial={{ opacity: 0, scale: 0.99 }}
      animate={{ opacity: 1, scale: 1 }}
      transition={{ duration: 0.3 }}
      className="flex-1 h-full flex flex-col overflow-hidden bg-[#080C15]"
    >
      {isCompleted && (
        <div className="bg-amber-500/10 border-b border-amber-500/20 px-4 py-2 flex items-center justify-between text-sm shrink-0">
          <div className="flex items-center gap-2">
            <span className="font-medium text-amber-400">✓ Exercise Completed</span>
            <span className="text-muted-foreground">— Your CDS is locked. Further submissions won't affect your score.</span>
          </div>
        </div>
      )}

      <EditorHeader
        title={exercise.title}
        concepts={exercise.concepts}
        testResults={testResults}
        timeLimitMinutes={exercise.time_limit_minutes}
        activeElapsedSeconds={activeElapsedSeconds}
        isRunning={isRunning}
        isReviewMode={isReviewMode}
        onRun={handleRun}
        onSubmit={isReviewMode ? undefined : handleSubmit}
        onBack={handleBack}
      />

      <div className="hidden lg:flex flex-1 w-full overflow-hidden h-[calc(100vh-56px)]">
        <ResizableWorkbench
          exercise={exercise}
          code={code}
          onCodeChange={handleCodeChange}
          testResults={testResults}
          onMount={handleMount}
          onAutocompleteAccept={handleAutocompleteAccept}
          language="cpp"
          submissions={submissions}
          history={history}
          programOutput={testResults?.programOutput ?? ""}
          compilationLog={testResults?.compilationLog ?? ""}
          onClearTerminal={handleClearTerminal}
          isReviewMode={isReviewMode}
        />
      </div>

      <div className="flex lg:hidden flex-1 min-h-0 flex-col">
        <MobileEditorTabs
          activeTab={activeTab}
          onTabChange={setActiveTab}
          exercise={exercise}
          code={code}
          onCodeChange={handleCodeChange}
          testResults={testResults}
          onMount={handleMount}
          onAutocompleteAccept={handleAutocompleteAccept}
          submissions={submissions}
          history={history}
          compilationLog={testResults?.compilationLog ?? ""}
          programOutput={testResults?.programOutput ?? ""}
          isReviewMode={isReviewMode}
        />
        <EditorActionBar onRun={handleRun} onSubmit={isReviewMode ? undefined : handleSubmit} isRunning={isRunning} isReviewMode={isReviewMode} />
      </div>

      {preCheckHints.length > 0 && (
        <div className="mt-3 space-y-2 px-4 pb-4">
          {preCheckHints.map((hint, i) => (
            <div
              key={i}
              className={`flex items-start gap-2 text-xs p-2 rounded border ${
                hint.level === 'hint'
                  ? 'bg-amber-500/10 border-amber-500/30 text-amber-600 dark:text-amber-400'
                  : 'bg-blue-500/10 border-blue-500/30 text-blue-600 dark:text-blue-400'
              }`}
            >
              <span className="mt-0.5 shrink-0">
                {hint.level === 'hint' ? '💡' : 'ℹ️'}
              </span>
              <span>{hint.message}</span>
            </div>
          ))}
        </div>
      )}
    </motion.div>
  );
}
