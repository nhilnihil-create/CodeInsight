import { useState } from 'react';
import api from '../../services/api';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
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

const SECTION_KEYS = { fs: 'fs', us: 'us', pe: 'pe' };

export default function AdminEvaluation() {
  const [responses, setResponses] = useState({});
  const [feedback, setFeedback] = useState('');
  const [submitted, setSubmitted] = useState(false);
  const [busy, setBusy] = useState(false);
  const [error, setError] = useState(null);

  const handleLikert = (section, index, value) => {
    setResponses((prev) => ({ ...prev, [`${section}_${index + 1}`]: value }));
  };

  const handleSubmit = async (e) => {
    e.preventDefault();
    setBusy(true);
    setError(null);
    try {
      const payload = { ...responses, feedback_text: feedback || undefined };
      await api.post('/api/evaluation/responses', payload);
      setSubmitted(true);
    } catch (err) {
      setError(err.response?.data?.message || err.message);
    } finally {
      setBusy(false);
    }
  };

  const allAnswered =
    FS_QUESTIONS.every((_, i) => responses[`fs_${i + 1}`] != null) &&
    US_QUESTIONS.every((_, i) => responses[`us_${i + 1}`] != null) &&
    PE_QUESTIONS.every((_, i) => responses[`pe_${i + 1}`] != null);

  if (submitted) {
    return (
      <div className="max-w-2xl mx-auto text-center py-12">
        <h2 className="text-xl font-bold mb-2">Thank You</h2>
        <p className="text-muted-foreground">Your evaluation has been recorded. Thank you for your feedback.</p>
      </div>
    );
  }

  const renderSection = (title, section, questions) => (
    <Card>
      <CardHeader><CardTitle className="text-sm">{title}</CardTitle></CardHeader>
      <CardContent className="space-y-4">
        {questions.map((q, i) => {
          const key = `${section}_${i + 1}`;
          return (
            <div key={i}>
              <p className="text-sm mb-2">{q}</p>
              <div className="flex gap-2 flex-wrap">
                {LIKERT_LABELS.map((label, j) => (
                  <button
                    key={j}
                    type="button"
                    onClick={() => handleLikert(section, i, j + 1)}
                    className={`text-xs px-3 py-1.5 rounded border transition-colors ${
                      responses[key] === j + 1
                        ? 'bg-primary text-primary-foreground border-primary'
                        : 'bg-card text-muted-foreground border-border hover:border-primary'
                    }`}
                  >
                    {j + 1}: {label}
                  </button>
                ))}
              </div>
            </div>
          );
        })}
      </CardContent>
    </Card>
  );

  return (
    <div className="max-w-3xl mx-auto space-y-6">
      <div>
        <h1 className="text-2xl font-bold">ISO/IEC 25010 Evaluation</h1>
        <p className="text-sm text-muted-foreground">
          Rate each statement on a scale of 1 (Strongly Disagree) to 4 (Strongly Agree).
        </p>
      </div>

      <form onSubmit={handleSubmit} className="space-y-6">
        {renderSection('Functional Suitability', SECTION_KEYS.fs, FS_QUESTIONS)}
        {renderSection('Usability', SECTION_KEYS.us, US_QUESTIONS)}
        {renderSection('Performance Efficiency', SECTION_KEYS.pe, PE_QUESTIONS)}

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

        {error && <p className="text-xs text-destructive">{error}</p>}

        <Button type="submit" disabled={!allAnswered || busy}>
          {busy ? 'Submitting…' : 'Submit Evaluation'}
        </Button>
      </form>
    </div>
  );
}
