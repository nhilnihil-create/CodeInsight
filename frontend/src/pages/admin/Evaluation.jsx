import { useState } from 'react';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Label } from '@/components/ui/label';
import { Textarea } from '@/components/ui/textarea';

const LIKERT_LABELS = ['Strongly Disagree', 'Disagree', 'Agree', 'Strongly Agree'];

const FS_QUESTIONS = [
  'The system accurately detects concept-level difficulty in my programming exercises.',
  'The CDS score reflects my actual understanding of programming concepts.',
  'The early intervention alerts help identify students who need additional support.',
  'The integrity flags are useful for detecting potential academic integrity concerns.',
];

const US_QUESTIONS = [
  'The system interface is intuitive and easy to navigate.',
  'I can find the information I need without assistance.',
  'The dashboard provides clear and understandable insights.',
  'The code editor is easy to use for writing and testing programs.',
  'The system responds quickly to my actions.',
];

const PE_QUESTIONS = [
  'The system loads and processes data within acceptable timeframes.',
  'Chart visualizations render without noticeable delay.',
  'The system remains stable during peak usage periods.',
];

export default function AdminEvaluation() {
  const [responses, setResponses] = useState({});
  const [feedback, setFeedback] = useState('');
  const [submitted, setSubmitted] = useState(false);

  const handleLikert = (key, value) => {
    setResponses(prev => ({ ...prev, [key]: value }));
  };

  const handleSubmit = (e) => {
    e.preventDefault();
    const allAnswered = [...FS_QUESTIONS, ...US_QUESTIONS, ...PE_QUESTIONS]
      .every((_, i) => responses[`q${i}`] != null);
    if (!allAnswered) return;
    console.log('Evaluation responses:', { responses, feedback });
    setSubmitted(true);
  };

  const allAnswered = [...FS_QUESTIONS, ...US_QUESTIONS, ...PE_QUESTIONS]
    .every((_, i) => responses[`q${i}`] != null);

  if (submitted) {
    return (
      <div className="max-w-2xl mx-auto text-center py-12">
        <h2 className="text-xl font-bold mb-2">Thank You</h2>
        <p className="text-muted-foreground">Your evaluation has been recorded. Thank you for your feedback.</p>
      </div>
    );
  }

  return (
    <div className="max-w-3xl mx-auto space-y-6">
      <div>
        <h1 className="text-2xl font-bold">ISO/IEC 25010 Evaluation</h1>
        <p className="text-sm text-muted-foreground">
          Rate each statement on a scale of 1 (Strongly Disagree) to 4 (Strongly Agree).
          Target sample: n=85.
        </p>
      </div>

      <form onSubmit={handleSubmit} className="space-y-6">
        <Card>
          <CardHeader><CardTitle className="text-sm">Functional Suitability</CardTitle></CardHeader>
          <CardContent className="space-y-4">
            {FS_QUESTIONS.map((q, i) => (
              <div key={i}>
                <p className="text-sm mb-2">{q}</p>
                <div className="flex gap-2">
                  {LIKERT_LABELS.map((label, j) => (
                    <button
                      key={j}
                      type="button"
                      onClick={() => handleLikert(`q${i}`, j + 1)}
                      className={`text-xs px-3 py-1.5 rounded border transition-colors ${
                        responses[`q${i}`] === j + 1
                          ? 'bg-primary text-primary-foreground border-primary'
                          : 'bg-card text-muted-foreground border-border hover:border-primary'
                      }`}
                    >
                      {j + 1}: {label}
                    </button>
                  ))}
                </div>
              </div>
            ))}
          </CardContent>
        </Card>

        <Card>
          <CardHeader><CardTitle className="text-sm">Usability</CardTitle></CardHeader>
          <CardContent className="space-y-4">
            {US_QUESTIONS.map((q, i) => (
              <div key={i}>
                <p className="text-sm mb-2">{q}</p>
                <div className="flex gap-2">
                  {LIKERT_LABELS.map((label, j) => (
                    <button
                      key={j}
                      type="button"
                      onClick={() => handleLikert(`q${i + FS_QUESTIONS.length}`, j + 1)}
                      className={`text-xs px-3 py-1.5 rounded border transition-colors ${
                        responses[`q${i + FS_QUESTIONS.length}`] === j + 1
                          ? 'bg-primary text-primary-foreground border-primary'
                          : 'bg-card text-muted-foreground border-border hover:border-primary'
                      }`}
                    >
                      {j + 1}: {label}
                    </button>
                  ))}
                </div>
              </div>
            ))}
          </CardContent>
        </Card>

        <Card>
          <CardHeader><CardTitle className="text-sm">Performance Efficiency</CardTitle></CardHeader>
          <CardContent className="space-y-4">
            {PE_QUESTIONS.map((q, i) => (
              <div key={i}>
                <p className="text-sm mb-2">{q}</p>
                <div className="flex gap-2">
                  {LIKERT_LABELS.map((label, j) => (
                    <button
                      key={j}
                      type="button"
                      onClick={() => handleLikert(`q${i + FS_QUESTIONS.length + US_QUESTIONS.length}`, j + 1)}
                      className={`text-xs px-3 py-1.5 rounded border transition-colors ${
                        responses[`q${i + FS_QUESTIONS.length + US_QUESTIONS.length}`] === j + 1
                          ? 'bg-primary text-primary-foreground border-primary'
                          : 'bg-card text-muted-foreground border-border hover:border-primary'
                      }`}
                    >
                      {j + 1}: {label}
                    </button>
                  ))}
                </div>
              </div>
            ))}
          </CardContent>
        </Card>

        <Card>
          <CardHeader><CardTitle className="text-sm">Additional Feedback</CardTitle></CardHeader>
          <CardContent>
            <Textarea
              placeholder="Optional: any additional comments or suggestions..."
              value={feedback}
              onChange={e => setFeedback(e.target.value)}
              rows={4}
            />
          </CardContent>
        </Card>

        <Button type="submit" disabled={!allAnswered}>
          Submit Evaluation
        </Button>
      </form>
    </div>
  );
}
