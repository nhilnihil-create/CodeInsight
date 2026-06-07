import { useCallback, useEffect, useRef, useState } from "react";
import { useNavigate, useParams } from "react-router-dom";
import { toast } from "sonner";
import api from "@/services/api";
import { useBehavioralTracking } from "@/hooks/useBehavioralTracking";
import EditorHeader from "./editor/EditorHeader";
import ResizableWorkbench from "./editor/ResizableWorkbench";
import MobileEditorTabs from "./editor/MobileEditorTabs";
import EditorActionBar from "./editor/EditorActionBar";
import {
  EXERCISE,
  INITIAL_CODE,
  INITIAL_TEST_RESULTS,
  SUBMISSIONS,
  HISTORY,
  LANGUAGE_OPTIONS,
} from "./editor/mockData";

/**
 * CodeEditor — orchestrator. All panel rendering lives in
 *   ./editor/{EditorHeader,ResizableWorkbench,ProblemPanel,
 *             CodeEditorSurface,SubmissionsPanel,OutputPanel,
 *             InstructionsPanel,TestOutputPanel,MobileEditorTabs,
 *             EditorActionBar}.jsx
 *
 * Layout (matches the redesign spec)
 *
 *   ┌─────────────────────────────────────────────────────────────┐
 *   │ EditorHeader (sticky)  Back · Title · N/M · Timer · Run/Submit · Lang · Theme
 *   ├──────────┬──────────────────────────────┬──────────────────┤
 *   │  INSTR.  │            Editor             │  Submissions    │
 *   │  + Tests │  ┌──────────────────────┐     │   History       │
 *   │          │  │  Monaco              │     │                  │
 *   │          │  ├──────────────────────┤     │                  │
 *   │          │  │  Terminal (3 tabs)   │     │                  │
 *   │          │  └──────────────────────┘     │                  │
 *   └──────────┴──────────────────────────────┴──────────────────┘
 *
 *   Mobile (< lg)  3-tab switcher (Code · Output · Problem) + action bar
 *
 * State  code, language, testResults, activeTab (mobile), timerSeconds,
 *        isRunning. The bottom terminal is always visible — no toggle.
 */

const TAB_DEFAULT = "code";

export default function StudentCodeEditor() {
  const navigate = useNavigate();
  const { id: exerciseId } = useParams();
  const [code, setCode] = useState(INITIAL_CODE);
  const [language, setLanguage] = useState(EXERCISE.language);
  const [testResults, setTestResults] = useState(INITIAL_TEST_RESULTS);
  const [activeTab, setActiveTab] = useState(TAB_DEFAULT);
  const [timerSeconds, setTimerSeconds] = useState(35 * 60);
  const [isRunning, setIsRunning] = useState(false);
  const editorRef = useRef(null);
  const { eventsRef } = useBehavioralTracking({ idleMs: 30_000 });

  useEffect(() => {
    if (timerSeconds <= 0) return undefined;
    const id = setTimeout(() => setTimerSeconds((s) => Math.max(0, s - 1)), 1000);
    return () => clearTimeout(id);
  }, [timerSeconds]);

  const handleRun = () => {
    setIsRunning(true);
    setTimeout(() => setIsRunning(false), 600);
  };

  const handleSubmit = async () => {
    if (!exerciseId) {
      toast.error("No exercise in URL — open an exercise to submit.");
      return;
    }
    setIsRunning(true);
    try {
      const r = await api.post(`/api/student/exercises/${exerciseId}/submit`, {
        code,
        timeSpentSeconds: Math.max(0, 35 * 60 - timerSeconds),
        behavioralEvents: eventsRef.current,
      });
      const hidden = r.data?.hiddenTestCount ?? 0;
      const cds = r.data?.liveCDS?.cds ?? r.data?.liveCDS;
      toast.success(
        cds != null
          ? `Submitted · ${hidden} hidden test${hidden === 1 ? "" : "s"} · live CDS ${(cds * 100).toFixed(0)}%`
          : `Submitted · ${hidden} hidden test${hidden === 1 ? "" : "s"}`
      );
    } catch (err) {
      toast.error(err.response?.data?.message || err.message || "Submission failed");
    } finally {
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

  return (
    <div className="flex h-full min-h-0 flex-col bg-background">
      <EditorHeader
        title={EXERCISE.title}
        concepts={EXERCISE.concepts}
        testResults={testResults}
        timerSeconds={timerSeconds}
        isRunning={isRunning}
        onRun={handleRun}
        onSubmit={handleSubmit}
        onBack={handleBack}
        language={language}
        languageOptions={LANGUAGE_OPTIONS}
        onLanguageChange={setLanguage}
      />

      <div className="hidden lg:flex flex-1 min-h-0">
        <ResizableWorkbench
          exercise={EXERCISE}
          code={code}
          onCodeChange={setCode}
          testResults={testResults}
          onMount={handleMount}
          language={language}
          languageOptions={LANGUAGE_OPTIONS}
          onLanguageChange={setLanguage}
          submissions={SUBMISSIONS}
          history={HISTORY}
          programOutput={testResults?.programOutput ?? ""}
          compilationLog={testResults?.compilationLog ?? ""}
          onClearTerminal={handleClearTerminal}
        />
      </div>

      <div className="flex lg:hidden flex-1 min-h-0 flex-col">
        <MobileEditorTabs
          activeTab={activeTab}
          onTabChange={setActiveTab}
          exercise={EXERCISE}
          code={code}
          onCodeChange={setCode}
          testResults={testResults}
          onMount={handleMount}
          submissions={SUBMISSIONS}
          history={HISTORY}
        />
        <EditorActionBar onRun={handleRun} onSubmit={handleSubmit} isRunning={isRunning} />
      </div>
    </div>
  );
}
