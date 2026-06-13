import { useCallback, useEffect, useRef, useState } from "react";
import { useNavigate, useParams } from "react-router-dom";
import { toast } from "sonner";
import api from "@/services/api";
import { useBehavioralTracking } from "@/hooks/useBehavioralTracking";
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
  // Persistence key: per-exercise, versioned so stale values are ignored.
  const STORAGE_KEY = `codeinsight:elapsed:${exerciseId}:v1`;

  // On mount: restore persisted elapsed time for this exercise, or start at 0.
  // If the student already solved this exercise (backend flag), the
  // effect below resets to 0 after the exercise data arrives.
  const [activeElapsedSeconds, setActiveElapsedSeconds] = useState(() => {
    if (typeof window === "undefined") return 0;
    try {
      const key = `codeinsight:elapsed:${exerciseId}:v1`;
      const stored = window.localStorage?.getItem(key);
      if (stored) { const n = parseInt(stored, 10); if (Number.isFinite(n) && n >= 0) return n; }
    } catch { /* ignore */ }
    return 0;
  });
  const [isSolved, setIsSolved] = useState(false);
  const [activeTab, setActiveTab] = useState(TAB_DEFAULT);
  const [isRunning, setIsRunning] = useState(false);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const editorRef = useRef(null);
  const isSubmittingRef = useRef(false);
  const { eventsRef } = useBehavioralTracking({ idleMs: 30_000 });

  // Practice mode: student already has a correct submission for this exercise.
  // Practice mode allows experimentation without affecting CDS analytics.
  const isCompleted = !!exercise?.isCompleted;
  const [isPracticeMode, setIsPracticeMode] = useState(false);
  const [practiceResult, setPracticeResult] = useState(null);

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

  // --- Stopwatch: runs in both modes, persists across exits -----------------
  // Stops when the student solves the exercise (isSolved) or when in
  // Review Mode (isCompleted). On unmount, persists elapsed to localStorage.
  useEffect(() => {
    if (isCompleted || isSolved) return undefined;

    const id = setInterval(() => {
      setActiveElapsedSeconds((s) => s + 1);
    }, 1000);

    return () => {
      clearInterval(id);
      try {
        window.localStorage?.setItem(STORAGE_KEY, String(activeElapsedSeconds));
      } catch { /* ignore */ }
    };
  }, [isCompleted, isSolved, exerciseId, activeElapsedSeconds]);

  // --- Auto-submit when time runs out (Assessment Mode only) -----------------
  useEffect(() => {
    if (isCompleted || isSolved) return undefined;
    const limit = exercise?.time_limit_minutes * 60;
    if (exercise?.mode === 'assessment' && limit && activeElapsedSeconds >= limit) {
      if (isSubmittingRef.current) return;
      handleSubmit();
    }
  }, [activeElapsedSeconds, exercise, isCompleted, isSolved]);

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
    if (isCompleted && isPracticeMode) {
      // Practice mode submit — no CDS impact
      setIsRunning(true);
      try {
        const r = await api.post(`/api/student/exercises/${exerciseId}/practice`, {
          code,
          language: 'cpp',
          timeSpentSeconds: activeElapsedSeconds,
        });
        const data = r.data;
        if (data.testResults) {
          setPracticeResult(transformTestResults(data.testResults, data.compilerError));
          setTestResults(practiceResult ? practiceResult : transformTestResults(data.testResults, data.compilerError));
        }
        if (data.allPassed) setIsSolved(true);
        toast.success(
          data.passed
            ? `Practice: All tests passed! (does not affect CDS)`
            : `Practice: Some tests failed (does not affect CDS)`
        );
      } catch (err) {
        toast.error(err.response?.data?.message || err.message || "Practice submission failed");
      } finally {
        isSubmittingRef.current = false;
        setIsRunning(false);
      }
      return;
    }
    if (isCompleted) {
      toast.info("You already completed this exercise. Switch to Practice Mode to continue editing.");
      isSubmittingRef.current = false;
      return;
    }
    setIsRunning(true);
    try {
      const r = await api.post(`/api/student/exercises/${exerciseId}/submit`, {
        code,
        language: 'cpp',
        timeSpentSeconds: activeElapsedSeconds,
        behavioralEvents: eventsRef.current,
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
    <div className="flex h-full min-h-0 flex-col bg-background">
      {/* Practice Mode Banner */}
      {isCompleted && (
        <div className="bg-amber-500/10 border-b border-amber-500/20 px-4 py-2 flex items-center justify-between text-sm">
          <div className="flex items-center gap-2">
            <span className="font-medium text-amber-600">✓ Exercise Completed</span>
            <span className="text-muted-foreground">— Your CDS is locked. Further submissions won't affect your score.</span>
          </div>
          <button
            type="button"
            onClick={() => setIsPracticeMode(!isPracticeMode)}
            className={`px-3 py-1 rounded-md text-xs font-medium transition-colors ${
              isPracticeMode
                ? "bg-amber-500/20 text-amber-700 border border-amber-500/30"
                : "bg-muted text-muted-foreground hover:bg-muted/80"
            }`}
          >
            {isPracticeMode ? "Practice Mode Active" : "Enable Practice Mode"}
          </button>
        </div>
      )}

      <EditorHeader
        title={exercise.title}
        concepts={exercise.concepts}
        testResults={testResults}
        mode={exercise.mode}
        timeLimitMinutes={exercise.time_limit_minutes}
        activeElapsedSeconds={activeElapsedSeconds}
        isRunning={isRunning}
        isReviewMode={isCompleted}
        onRun={handleRun}
        onSubmit={isCompleted ? (isPracticeMode ? handleSubmit : undefined) : handleSubmit}
        onBack={handleBack}
      />

      {/* Rubric Scorecard (Assessment Mode only) */}
      {rubricScore && exercise?.mode === 'assessment' && (
        <div className="px-4 py-2 border-b border-border bg-muted/20">
          <div className="max-w-3xl mx-auto">
            <RubricScorecard rubricScore={rubricScore} />
          </div>
        </div>
      )}

      <div className="hidden lg:flex flex-1 min-h-0">
        <ResizableWorkbench
          exercise={exercise}
          code={code}
          onCodeChange={setCode}
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
          onCodeChange={setCode}
          testResults={testResults}
          onMount={handleMount}
          submissions={submissions}
          history={history}
          compilationLog={testResults?.compilationLog ?? ""}
          programOutput={testResults?.programOutput ?? ""}
          isReviewMode={isCompleted}
        />
        <EditorActionBar onRun={handleRun} onSubmit={isCompleted ? (isPracticeMode ? handleSubmit : undefined) : handleSubmit} isRunning={isRunning} />
      </div>
    </div>
  );
}
