import { useCallback, useEffect, useRef, useState } from "react";
import { useNavigate, useParams } from "react-router-dom";
import { motion } from "framer-motion";
import { toast } from "sonner";
import api from "@/services/api";
import EditorHeader from "./editor/EditorHeader";
import ResizableWorkbench from "./editor/ResizableWorkbench";
import MobileEditorTabs from "./editor/MobileEditorTabs";
import EditorActionBar from "./editor/EditorActionBar";
import RubricScorecard from "./components/RubricScorecard";

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

function transformTestResults(apiResults, compilerError) {
  const visible = (apiResults || []).filter((r) => !r.hidden);
  const hidden = (apiResults || []).filter((r) => r.hidden);
  return {
    passing: visible.filter((r) => r.passed).length,
    total: visible.length,
    passed: visible.length > 0 && visible.every((r) => r.passed),
    error: null,
    compilationLog: compilerError || "",
    programOutput: "",
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
      total: hidden.length,
      failed: hidden.filter((r) => !r.passed).length,
    },
  };
}

function transformAttempts(attempts, totalTests, language) {
  const submissions = (attempts || []).map((a) => ({
    id: a.id,
    status: a.passed ? "accepted" : "wrong_answer",
    passed: a.passed ? totalTests : 0,
    total: totalTests || 0,
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

export default function StudentCodeEditor() {
  const navigate = useNavigate();
  const { exerciseId } = useParams();
  const [exercise, setExercise] = useState(null);
  const [code, setCode] = useState("");
  const [testResults, setTestResults] = useState(null);
  const [rubricScore, setRubricScore] = useState(null);
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
  const behavioralCounts = useRef({ tabSwitches: 0, pastes: 0, idleSeconds: 0 });
  const pendingEventsRef = useRef([]);
  const lastActivityRef = useRef(Date.now());
  const idleTimerRef = useRef(null);
  const editorContainerRef = useRef(null);

  const isCompleted = !!exercise?.isCompleted;

  useEffect(() => {
    const id = exerciseId;
    if (!id) return;
    let cancelled = false;
    setLoading(true);
    setError(null);
    setIsSolved(false);
    api
      .get(`/api/student/exercises/${id}`)
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
        setError(err.response?.data?.message || err.message || "Failed to load exercise");
        setLoading(false);
      });
    return () => {
      cancelled = true;
    };
  }, [exerciseId]);

  useEffect(() => {
    if (!exerciseId) return;
    let cancelled = false;
    setSubmissions([]);
    setHistory([]);
    api
      .get(`/api/student/exercises/${exerciseId}/attempts`)
      .then((r) => {
        if (cancelled) return;
        const totalTests = Array.isArray(exercise?.test_cases) ? exercise.test_cases.length : 0;
        const { submissions: subs, history: hist } = transformAttempts(r.data || [], totalTests, 'cpp');
        setSubmissions(subs);
        setHistory(hist);
      })
      .catch(() => {});
    return () => {
      cancelled = true;
    };
  }, [exerciseId]);

  useEffect(() => {
    if (isCompleted || isSolved) return undefined;
    const id = setInterval(() => {
      setActiveElapsedSeconds((s) => s + 1);
    }, 1000);
    return () => {
      clearInterval(id);
    };
  }, [isCompleted, isSolved]);

  // ── Passive Behavioral Logging (paper flag #5) ────────────────────────
  // Track tab switches, paste events, and idle time. Sends cumulative
  // counts with each submission AND asynchronously flushes raw events
  // for audit trail every 10 seconds.
  useEffect(() => {
    if (!exerciseId || isCompleted || isSolved) return;

    // Reset counters when entering a new exercise session
    behavioralCounts.current = { tabSwitches: 0, pastes: 0, idleSeconds: 0 };
    pendingEventsRef.current = [];
    lastActivityRef.current = Date.now();

    const handleVisibilityChange = () => {
      if (document.hidden) {
        behavioralCounts.current.tabSwitches += 1;
        pendingEventsRef.current.push({ type: 'tab_switch', timestamp: new Date().toISOString() });
      } else {
        // Tab refocused — reset idle timer
        lastActivityRef.current = Date.now();
      }
    };

    const handlePaste = () => {
      behavioralCounts.current.pastes += 1;
      pendingEventsRef.current.push({ type: 'paste', timestamp: new Date().toISOString() });
      lastActivityRef.current = Date.now();
    };

    const handleActivity = () => {
      lastActivityRef.current = Date.now();
    };

    // Check idle every second — accumulate idle seconds when no activity
    const handleIdleCheck = () => {
      const elapsed = Date.now() - lastActivityRef.current;
      if (elapsed >= 1000) {
        behavioralCounts.current.idleSeconds += 1;
      }
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
    document.addEventListener('paste', handlePaste);
    document.addEventListener('keydown', handleActivity);
    document.addEventListener('mousedown', handleActivity);
    flushTimer = setInterval(flushEvents, 10000);
    idleTimerRef.current = setInterval(handleIdleCheck, 1000);

    return () => {
      document.removeEventListener('visibilitychange', handleVisibilityChange);
      document.removeEventListener('paste', handlePaste);
      document.removeEventListener('keydown', handleActivity);
      document.removeEventListener('mousedown', handleActivity);
      clearInterval(flushTimer);
      clearInterval(idleTimerRef.current);
      flushEvents(); // Final flush on unmount
    };
  }, [exerciseId, isCompleted, isSolved]);

  const handleRun = async () => {
    if (!exerciseId) return;
    setIsRunning(true);
    setTestResults(null);
    try {
      const r = await api.post(`/api/student/exercises/${exerciseId}/run`, { code, language: 'cpp' });
      const { testResults: rawResults, compilerError } = r.data;
      setTestResults(transformTestResults(rawResults, compilerError));
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
    if (isCompleted) {
      toast.info("Exercise already completed. Your CDS is locked.");
      isSubmittingRef.current = false;
      return;
    }
    setIsRunning(true);
    try {
      // Flush pending behavioral events BEFORE submit to prevent double-counting
      if (pendingEventsRef.current.length > 0) {
        const pending = pendingEventsRef.current.splice(0, pendingEventsRef.current.length);
        api.post('/api/student/behavioral-events', {
          exerciseId: parseInt(exerciseId),
          events: pending,
        }).catch(() => {});
      }

      const r = await api.post(`/api/student/exercises/${exerciseId}/submit`, {
        code,
        language: 'cpp',
        timeSpentSeconds: activeElapsedSeconds,
        tabSwitchCount: behavioralCounts.current.tabSwitches,
        pasteCount: behavioralCounts.current.pastes,
        idleTimeSeconds: behavioralCounts.current.idleSeconds,
      });
      const data = r.data;
      const hidden = data.hiddenTestCount ?? 0;
      const cds = data.liveCDS?.cds ?? data.liveCDS;

      if (data.testResults) {
        setTestResults(transformTestResults(data.testResults, data.compilerError));
      }
      if (data.allPassed) setIsSolved(true);
      if (data.rubricScore) {
        setRubricScore(data.rubricScore);
      }
      if (data.preCheckHints) {
        setPreCheckHints(data.preCheckHints);
      }

      toast.success(
        cds != null
          ? `Submitted · ${hidden} hidden test${hidden === 1 ? "" : "s"} · live CDS ${(cds * 100).toFixed(0)}%`
          : `Submitted · ${hidden} hidden test${hidden === 1 ? "" : "s"}`
      );

      try {
        const attRes = await api.get(`/api/student/exercises/${exerciseId}/attempts`);
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
        isReviewMode={isCompleted}
        onRun={handleRun}
        onSubmit={isCompleted ? undefined : handleSubmit}
        onBack={handleBack}
      />

      {rubricScore && (
        <div className="px-4 py-2 border-b border-white/[0.05] bg-[#131B2E]/40 backdrop-blur-md shrink-0">
          <div className="max-w-3xl mx-auto">
            <RubricScorecard rubricScore={rubricScore} />
          </div>
        </div>
      )}

      <div className="hidden lg:flex flex-1 w-full overflow-hidden h-[calc(100vh-56px)]">
        <ResizableWorkbench
          exercise={exercise}
          code={code}
          onCodeChange={handleCodeChange}
          testResults={testResults}
          onMount={handleMount}
          language="cpp"
          submissions={submissions}
          history={history}
          programOutput={testResults?.programOutput ?? ""}
          compilationLog={testResults?.compilationLog ?? ""}
          onClearTerminal={handleClearTerminal}
          isReviewMode={isCompleted}
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
          submissions={submissions}
          history={history}
          compilationLog={testResults?.compilationLog ?? ""}
          programOutput={testResults?.programOutput ?? ""}
          isReviewMode={isCompleted}
        />
        <EditorActionBar onRun={handleRun} onSubmit={isCompleted ? undefined : handleSubmit} isRunning={isRunning} />
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
