import { useState, useEffect, useRef } from 'react';
import { useParams, Link } from 'react-router-dom';
import Editor from '@monaco-editor/react';
import { Button } from '@/components/ui/button';
import { Badge } from '@/components/ui/badge';
import { Card, CardContent } from '@/components/ui/card';
import { Play, Send, Square, Clock, AlertCircle, RefreshCw, ChevronLeft } from 'lucide-react';
import { MOCK_EXERCISES } from '@/data/mockData';
import { useTheme, DEFAULT_THEME } from '@/lib/theme';
import { MONACO_THEMES, registerMonacoThemes } from '@/lib/monacoThemes';

/**
 * Code Editor (Monaco port) — see spec §3.1.
 *
 * Ported from commit 62fa4cd (473 lines). Differences from the legacy:
 *  - Reads MOCK_EXERCISES synchronously (no /api/student/exercises/:id fetch).
 *  - Mock run/submit handlers render the same per-test output shape.
 *  - Monaco themes (ci-light / ci-dark-teal / ci-psu) registered on mount,
 *    and the active theme is re-applied whenever useTheme() changes.
 *  - The 2-tab output panel (Output / Compiler Log) is preserved verbatim,
 *    including the clickable error blocks and per-line highlight.
 */

function formatTime(seconds) {
  if (!seconds || seconds < 0) return '0:00';
  const m = Math.floor(seconds / 60);
  const s = seconds % 60;
  return `${m}:${s.toString().padStart(2, '0')}`;
}

function parseErrorBlocks(errorText) {
  if (!errorText) return [];
  const blocks = [];
  const lines = errorText.split('\n');
  let i = 0;
  while (i < lines.length) {
    const line = lines[i];
    const m = line.match(/(?:\[Line\s+(\d+):(\d+)\]|^.*?:(\d+):(?:\d+):)\s*(ERROR|WARNING|error|warning):\s*(.+)/i);
    if (m) {
      const lineNum = parseInt(m[1] || m[3]);
      const col = parseInt(m[2] || 0) || 1;
      const errorType = m[4];
      const message = m[5];
      let codeLine = '';
      let pointer = '';
      if (i + 1 < lines.length && /^\s+/.test(lines[i + 1])) {
        codeLine = lines[i + 1].trim();
        i++;
      }
      if (i + 1 < lines.length && lines[i + 1].includes('^')) {
        pointer = lines[i + 1].trim();
        i++;
      }
      blocks.push({ type: 'error', lineNum, col, errorType, message, codeLine, pointer });
    } else if (line.trim()) {
      blocks.push({ type: 'text', content: line });
    }
    i++;
  }
  return blocks;
}

export default function StudentCodeEditor() {
  const { exerciseId } = useParams();
  const exercise = MOCK_EXERCISES.find((e) => e.id === exerciseId) || MOCK_EXERCISES[0];
  const { theme } = useTheme();

  const [code, setCode] = useState(exercise.starterCode);
  const [testResults, setTestResults] = useState(null);
  const [attempts, setAttempts] = useState([]);
  const [running, setRunning] = useState(false);
  const [submitting, setSubmitting] = useState(false);
  const [activeTab, setActiveTab] = useState('output');
  const [timeRemaining, setTimeRemaining] = useState(null);
  const [abortController, setAbortController] = useState(null);
  const [highlightedLine, setHighlightedLine] = useState(null);

  const exerciseStartTimeRef = useRef(Date.now());
  const editorRef = useRef(null);

  // Initialize deadline countdown from MOCK_EXERCISES[i].dueDate
  useEffect(() => {
    if (exercise.dueDate) {
      const diff = new Date(exercise.dueDate) - new Date();
      if (diff > 0) setTimeRemaining(Math.floor(diff / 1000));
    }
  }, [exercise.dueDate]);

  // Tick the countdown
  useEffect(() => {
    if (timeRemaining == null || timeRemaining <= 0) return;
    const t = setTimeout(() => setTimeRemaining((s) => (s > 0 ? s - 1 : 0)), 1000);
    return () => clearTimeout(t);
  }, [timeRemaining]);

  // Swap Monaco theme live when useTheme() changes
  useEffect(() => {
    if (editorRef.current) {
      const monacoTheme = MONACO_THEMES[theme] || MONACO_THEMES[DEFAULT_THEME];
      editorRef.current._monaco?.editor.setTheme(monacoTheme);
    }
  }, [theme]);

  const handleEditorMount = (editor, monaco) => {
    registerMonacoThemes(monaco);
    monaco.editor.setTheme(MONACO_THEMES[theme] || MONACO_THEMES[DEFAULT_THEME]);
    editorRef.current = { ...editor, _monaco: monaco };
  };

  const goToErrorLine = (lineNumber) => {
    if (!editorRef.current || !lineNumber) return;
    setHighlightedLine(lineNumber);
    editorRef.current.revealLineInCenter(lineNumber);
    editorRef.current.setPosition({ lineNumber, column: 1 });
    editorRef.current.focus();
  };

  const handleRun = async () => {
    setRunning(true);
    setActiveTab('output');
    const controller = new AbortController();
    setAbortController(controller);
    // Mock: render the first test's expected output, and synthesize a
    // compiler-log error if the code is empty.
    await new Promise((r) => setTimeout(r, 200));
    controller.signal.throwIfAborted?.();
    const empty = code.trim().length === 0;
    const result = {
      passed: !empty,
      testResults: empty
        ? []
        : exercise.testCases.map((tc, i) => ({
            name: `Test ${i + 1}`,
            input: tc.input || '',
            expected: tc.expectedOutput,
            actual: empty ? '' : tc.expectedOutput,
            passed: true,
          })),
      compilation_log: empty
        ? '[Line 5:1] ERROR: expected unqualified-id\n    int main() {\n    ^'
        : '',
    };
    setTestResults(result);
    if (result.compilation_log) setActiveTab('compiler-log');
    setRunning(false);
    setAbortController(null);
  };

  const handleStop = () => {
    if (abortController) {
      abortController.abort();
      setAbortController(null);
    }
    setRunning(false);
  };

  const handleSubmit = async () => {
    const submitStart = Date.now();
    setSubmitting(true);
    await new Promise((r) => setTimeout(r, 200));
    const elapsed = Math.floor((Date.now() - submitStart) / 1000);
    const result = {
      passed: true,
      testResults: exercise.testCases.map((tc, i) => ({
        name: `Test ${i + 1}`,
        input: tc.input || '',
        expected: tc.expectedOutput,
        actual: tc.expectedOutput,
        passed: true,
      })),
      timeSpentSeconds: elapsed,
    };
    setTestResults(result);
    setAttempts((prev) => [{ id: Date.now(), passed: true, time: elapsed }, ...prev]);
    setActiveTab('output');
    setSubmitting(false);
  };

  const errorBlocks = testResults?.compilation_log ? parseErrorBlocks(testResults.compilation_log) : [];

  return (
    <div className="h-[calc(100vh-100px)] flex flex-col space-y-4">
      <div className="flex items-center justify-between">
        <div>
          <Link
            to="/student/exercises"
            className="inline-flex items-center text-sm text-muted-foreground hover:text-foreground mb-2"
          >
            <ChevronLeft className="w-4 h-4 mr-1" /> Back to exercises
          </Link>
          <h1 className="text-2xl font-bold tracking-tight">{exercise.title}</h1>
          <div className="flex items-center gap-2 mt-1">
            <Badge variant="outline">{exercise.difficulty}</Badge>
            {exercise.conceptTags.map((tag) => (
              <Badge key={tag} variant="secondary">{tag}</Badge>
            ))}
          </div>
        </div>
        <div className="flex gap-4 text-sm text-muted-foreground">
          {timeRemaining != null && timeRemaining > 0 && (
            <div className="flex items-center gap-1">
              <Clock className="w-4 h-4" /> {formatTime(timeRemaining)}
            </div>
          )}
          <div className="flex items-center gap-1">
            <AlertCircle className="w-4 h-4" /> {errorBlocks.length} errors
          </div>
          <div className="flex items-center gap-1">
            <RefreshCw className="w-4 h-4" /> {attempts.length} submits
          </div>
        </div>
      </div>

      <div className="flex-1 grid grid-cols-1 lg:grid-cols-2 gap-4 min-h-0">
        <div className="flex flex-col gap-4 overflow-hidden">
          <Card className="flex-1 overflow-auto">
            <CardContent className="p-6">
              <h2 className="font-semibold mb-4">Description</h2>
              <p className="text-sm leading-relaxed mb-6">{exercise.description}</p>
              <h3 className="font-semibold text-sm mb-2 text-muted-foreground uppercase tracking-wider">
                Visible Test Case
              </h3>
              <div className="bg-muted p-4 rounded-md space-y-3 font-mono text-sm">
                <div>
                  <div className="text-muted-foreground mb-1">Input:</div>
                  <div className="bg-background p-2 rounded border">
                    {exercise.testCases[0]?.input || '(none)'}
                  </div>
                </div>
                <div>
                  <div className="text-muted-foreground mb-1">Expected Output:</div>
                  <div className="bg-background p-2 rounded border">
                    {exercise.testCases[0]?.expectedOutput}
                  </div>
                </div>
              </div>
            </CardContent>
          </Card>
        </div>

        <div className="flex flex-col gap-4 overflow-hidden">
          <div className="flex-1 rounded-xl border overflow-hidden flex flex-col">
            <div className="h-9 bg-muted flex items-center px-4 text-xs font-mono text-muted-foreground border-b border-border">
              main.cpp
            </div>
            <Editor
              height="100%"
              defaultLanguage="cpp"
              language="cpp"
              value={code}
              onChange={(v) => setCode(v ?? '')}
              theme={MONACO_THEMES[theme] || MONACO_THEMES[DEFAULT_THEME]}
              onMount={handleEditorMount}
              options={{
                fontFamily: "'JetBrains Mono', monospace",
                fontSize: 13,
                minimap: { enabled: false },
                scrollBeyondLastLine: false,
                automaticLayout: true,
              }}
            />
          </div>

          <div className="h-56 bg-card rounded-xl border p-3 flex flex-col">
            <div className="flex justify-between items-center mb-2">
              <div className="flex gap-1">
                <button
                  type="button"
                  onClick={() => setActiveTab('output')}
                  className={
                    'px-3 py-1 text-xs font-medium rounded ' +
                    (activeTab === 'output'
                      ? 'bg-primary text-primary-foreground'
                      : 'text-muted-foreground hover:bg-muted')
                  }
                >
                  Output
                </button>
                <button
                  type="button"
                  onClick={() => setActiveTab('compiler-log')}
                  className={
                    'px-3 py-1 text-xs font-medium rounded ' +
                    (activeTab === 'compiler-log'
                      ? 'bg-primary text-primary-foreground'
                      : 'text-muted-foreground hover:bg-muted')
                  }
                >
                  Compiler Log
                </button>
              </div>
              <div className="flex gap-2">
                {running ? (
                  <Button variant="destructive" size="sm" onClick={handleStop} className="gap-1">
                    <Square className="w-4 h-4" /> Stop
                  </Button>
                ) : (
                  <Button variant="secondary" size="sm" onClick={handleRun} className="gap-1" disabled={submitting}>
                    <Play className="w-4 h-4" /> Run
                  </Button>
                )}
                <Button size="sm" onClick={handleSubmit} className="gap-1" disabled={running || submitting}>
                  <Send className="w-4 h-4" /> Submit
                </Button>
              </div>
            </div>
            <div
              className="flex-1 bg-muted rounded-md p-3 text-sm overflow-auto whitespace-pre-wrap"
              style={{ fontFamily: "'JetBrains Mono', monospace" }}
            >
              {activeTab === 'output' ? (
                testResults ? (
                  testResults.testResults.length === 0 ? (
                    <span className="text-muted-foreground">No test results.</span>
                  ) : (
                    testResults.testResults.map((r, i) => (
                      <div key={i} className="mb-2">
                        <span className={r.passed ? 'text-green-600' : 'text-destructive'}>
                          {r.passed ? '✓' : '✗'} {r.name}
                        </span>
                        <div className="text-muted-foreground ml-4 text-xs">
                          in: {r.input || '(none)'} | expected: {r.expected} | actual: {r.actual}
                        </div>
                      </div>
                    ))
                  )
                ) : (
                  <span className="text-muted-foreground">Run your code to see output here.</span>
                )
              ) : errorBlocks.length === 0 ? (
                <span className="text-muted-foreground">No compiler errors.</span>
              ) : (
                errorBlocks.map((b, i) =>
                  b.type === 'error' ? (
                    <div
                      key={i}
                      onClick={() => goToErrorLine(b.lineNum)}
                      onKeyDown={(e) => {
                        if (e.key === 'Enter' || e.key === ' ') {
                          e.preventDefault();
                          goToErrorLine(b.lineNum);
                        }
                      }}
                      role="button"
                      tabIndex={0}
                      className="mb-2 p-2 rounded border border-destructive/30 bg-destructive/10 cursor-pointer"
                    >
                      <div className="text-destructive font-semibold text-xs">
                        ● [Line {b.lineNum}:{b.col}] {b.errorType}
                      </div>
                      <div className="ml-4 text-xs text-amber-600">{b.message}</div>
                      {b.codeLine && (
                        <div className="ml-4 mt-1 bg-background/50 px-2 py-1 rounded text-xs font-mono">
                          {b.codeLine}
                          {b.pointer && <div className="text-destructive font-bold">{b.pointer}</div>}
                        </div>
                      )}
                      {highlightedLine === b.lineNum && (
                        <div className="ml-4 text-[10px] text-primary mt-1">↑ editor scrolled to line {b.lineNum}</div>
                      )}
                    </div>
                  ) : (
                    <div key={i} className="text-muted-foreground text-xs">{b.content}</div>
                  )
                )
              )}
            </div>
          </div>

          {attempts.length > 0 && (
            <div className="rounded-xl border bg-card p-3 max-h-32 overflow-auto">
              <h3 className="text-xs font-semibold text-muted-foreground uppercase tracking-wider mb-2">
                Attempt History
              </h3>
              {attempts.map((a) => (
                <div key={a.id} className="text-xs flex justify-between py-1 border-b border-border/50 last:border-0">
                  <span className="text-green-600">✓ Submitted</span>
                  <span className="text-muted-foreground">{formatTime(a.time)}</span>
                </div>
              ))}
            </div>
          )}
        </div>
      </div>
    </div>
  );
}
