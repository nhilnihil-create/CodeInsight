import { useState } from 'react';
import { useParams, Link } from 'react-router-dom';
import { Button } from '@/components/ui/button';
import { Badge } from '@/components/ui/badge';
import { Play, Send, Clock, AlertCircle, RefreshCw, ChevronLeft } from 'lucide-react';
import { MOCK_EXERCISES } from '../../data/mockData';

/**
 * Code Editor — Frontend-Design visual.
 *
 * Visual-only in this slice. "Run Code" and "Submit" show a fake terminal
 * string so the UI flows end-to-end. Real code execution / submission
 * wiring is the first follow-up slice (it currently lives in the old
 * CodeEditor_new.jsx and is preserved in git history).
 */
export default function StudentCodeEditor() {
  const { exerciseId } = useParams();
  const exercise =
    MOCK_EXERCISES.find((e) => e.id === exerciseId) || MOCK_EXERCISES[0];

  const [code, setCode] = useState(exercise.starterCode);
  const [output, setOutput] = useState(null);

  const handleRun = () => {
    setOutput(`Running...\n\nOutput:\n${exercise.testCases[0].expectedOutput}`);
  };

  const handleSubmit = () => {
    setOutput('Submitting code...\n\nAll test cases passed! Structure validated. CDS updated.');
  };

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
              <Badge key={tag} variant="secondary">
                {tag}
              </Badge>
            ))}
          </div>
        </div>
        <div className="flex gap-4 text-sm text-muted-foreground">
          <div className="flex items-center gap-1">
            <Clock className="w-4 h-4" /> 0m 0s
          </div>
          <div className="flex items-center gap-1">
            <AlertCircle className="w-4 h-4" /> 0 errors
          </div>
          <div className="flex items-center gap-1">
            <RefreshCw className="w-4 h-4" /> 0 submits
          </div>
        </div>
      </div>

      <div className="flex-1 grid grid-cols-1 lg:grid-cols-2 gap-4 min-h-0">
        {/* Left Panel: Description */}
        <div className="flex flex-col gap-4 overflow-hidden">
          <div className="flex-1 bg-card rounded-xl border p-6 overflow-auto">
            <h2 className="font-semibold mb-4">Description</h2>
            <p className="text-sm leading-relaxed mb-6">{exercise.description}</p>

            <h3 className="font-semibold text-sm mb-2 text-muted-foreground uppercase tracking-wider">
              Visible Test Case
            </h3>
            <div className="bg-muted p-4 rounded-md space-y-3 font-mono text-sm">
              <div>
                <div className="text-muted-foreground mb-1">Input:</div>
                <div className="bg-background p-2 rounded border">
                  {exercise.testCases[0].input || '(none)'}
                </div>
              </div>
              <div>
                <div className="text-muted-foreground mb-1">Expected Output:</div>
                <div className="bg-background p-2 rounded border">
                  {exercise.testCases[0].expectedOutput}
                </div>
              </div>
            </div>
          </div>
        </div>

        {/* Right Panel: Editor & Output */}
        <div className="flex flex-col gap-4 overflow-hidden">
          <div className="flex-1 bg-[#1e1e1e] rounded-xl border overflow-hidden flex flex-col relative group">
            <div className="h-10 bg-[#2d2d2d] flex items-center px-4 text-xs font-mono text-gray-400 border-b border-[#3d3d3d]">
              main.cpp
            </div>
            <textarea
              value={code}
              onChange={(e) => setCode(e.target.value)}
              className="flex-1 bg-transparent text-[#d4d4d4] font-mono p-4 resize-none focus:outline-none"
              spellCheck={false}
            />
          </div>

          <div className="h-48 bg-card rounded-xl border p-4 flex flex-col">
            <div className="flex justify-between items-center mb-2">
              <h3 className="font-semibold text-sm">Terminal Output</h3>
              <div className="flex gap-2">
                <Button variant="secondary" size="sm" onClick={handleRun} className="gap-1">
                  <Play className="w-4 h-4" /> Run Code
                </Button>
                <Button size="sm" onClick={handleSubmit} className="gap-1">
                  <Send className="w-4 h-4" /> Submit
                </Button>
              </div>
            </div>
            <div className="flex-1 bg-muted rounded-md p-3 font-mono text-sm overflow-auto whitespace-pre-wrap">
              {output || 'Run your code to see output here.'}
            </div>
          </div>
        </div>
      </div>
    </div>
  );
}
