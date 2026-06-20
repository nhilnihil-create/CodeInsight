import { useState, useEffect } from 'react';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Badge } from '@/components/ui/badge';
import StudentDashboardShell from '@/components/student-dashboard-shell';
import JoinSectionGate from '@/components/join-section-gate';
import useHasSections from '@/hooks/useHasSections';
import api from '@/services/api';

const FLAG_DESCRIPTIONS = {
  HARDCODING: {
    title: 'Hardcoding Detected',
    explanation: 'The system detected that your output may contain hardcoded values instead of computed results. For example, printing a literal number instead of calculating it with a loop or variables.',
    whatNext: 'Your instructor will review this. If you computed the answer using proper logic, this may be a false positive.',
  },
  BLANK_TEMPLATE: {
    title: 'Blank/Template Submission',
    explanation: 'Your submission appears to be identical to the starter code. The system expects you to modify the code to solve the exercise.',
    whatNext: 'Make sure you write your own solution in the code editor before submitting.',
  },
  BEHAVIORAL_ANOMALY: {
    title: 'Behavioral Pattern Detected',
    explanation: 'The system detected an unusual pattern in your submission timing. This could be instant success after multiple failures, or completing the exercise significantly faster than classmates.',
    whatNext: 'These are contextual indicators for your instructor to review. They help ensure CDS scores reflect genuine learning.',
  },
  CODE_GROWTH_ANOMALY: {
    title: 'Code Growth Spike',
    explanation: 'A large amount of code appeared in a single submission (>30% growth). This may indicate pasted code rather than incremental coding.',
    whatNext: 'Try to build your solution incrementally, submitting small changes each time.',
  },
  PASSIVE_BEHAVIOR_LOG: {
    title: 'Passive Behavior Logged',
    explanation: 'The system detected patterns like tab switching, pasting code, or extended idle time during your coding session. These help instructors understand your workflow.',
    whatNext: 'No action needed. Your instructor may review this for context. Focus on writing your own code incrementally.',
  },
};

export default function StudentIntegrityView() {
  const { hasSections, checking, recheck } = useHasSections();
  const [flags, setFlags] = useState([]);
  const [stats, setStats] = useState(null);
  const [cdsSummary, setCdsSummary] = useState(null);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [fetchKey, setFetchKey] = useState(0);
  const [responseForm, setResponseForm] = useState({ flagId: null, text: '' });

  useEffect(() => {
    if (hasSections === null || !hasSections) return;
    let cancelled = false;
    const load = async () => {
      try {
        const res = await api.get('/api/student/integrity-flags');
        if (!cancelled) {
          const data = res.data || {};
          setFlags(data.flags || []);
          setStats(data.stats || null);
          setCdsSummary(data.cdsSummary || null);
        }
      } catch (err) {
        if (!cancelled) setError(err.response?.data?.error || 'Failed to load integrity data');
      } finally {
        if (!cancelled) setLoading(false);
      }
    };
    load();
    return () => { cancelled = true; };
  }, [hasSections, fetchKey]);

  const handleJoined = () => {
    recheck();
    setFetchKey((k) => k + 1);
  };

  if (checking) {
    return (
      <StudentDashboardShell
        breadcrumb={[
          { label: 'Student', href: '/student/dashboard' },
          { label: 'My Learning Dashboard' },
        ]}
        subtitle="Patterns detected in your work — always hypotheses, never verdicts."
      >
        <div className="py-12 text-center text-muted-foreground">Loading integrity data…</div>
      </StudentDashboardShell>
    );
  }

  if (!hasSections) {
    return <JoinSectionGate onJoined={handleJoined} />;
  }

  if (loading) {
    return (
      <StudentDashboardShell
        breadcrumb={[
          { label: 'Student', href: '/student/dashboard' },
          { label: 'My Learning Dashboard' },
        ]}
        subtitle="Patterns detected in your work — always hypotheses, never verdicts."
      >
        <div className="py-12 text-center text-muted-foreground">Loading integrity data…</div>
      </StudentDashboardShell>
    );
  }

  if (error) {
    return (
      <StudentDashboardShell
        breadcrumb={[
          { label: 'Student', href: '/student/dashboard' },
          { label: 'My Learning Dashboard' },
        ]}
        subtitle="Patterns detected in your work — always hypotheses, never verdicts."
      >
        <div className="py-12 text-center text-destructive">{error}</div>
      </StudentDashboardShell>
    );
  }

  return (
    <StudentDashboardShell
      breadcrumb={[
        { label: 'Student', href: '/student/dashboard' },
        { label: 'My Learning Dashboard' },
      ]}
      subtitle="Patterns detected in your work — always hypotheses, never verdicts."
    >
      {stats && (
        <div className="grid grid-cols-2 md:grid-cols-4 gap-3">
          <Card>
            <CardContent className="p-3 text-center">
              <p className="text-2xl font-bold">{stats.totalFlags}</p>
              <p className="text-xs text-muted-foreground">Total Flags</p>
            </CardContent>
          </Card>
          <Card>
            <CardContent className="p-3 text-center">
              <p className="text-2xl font-bold text-amber-500">{stats.flaggedCount}</p>
              <p className="text-xs text-muted-foreground">Under Review</p>
            </CardContent>
          </Card>
          <Card>
            <CardContent className="p-3 text-center">
              <p className="text-2xl font-bold text-emerald-500">{stats.reviewedCount}</p>
              <p className="text-xs text-muted-foreground">Reviewed</p>
            </CardContent>
          </Card>
          {cdsSummary?.averageCds != null && (
            <Card>
              <CardContent className="p-3 text-center">
                <p className="text-2xl font-bold">{cdsSummary.averageCds}</p>
                <p className="text-xs text-muted-foreground">Avg CDS Score</p>
              </CardContent>
            </Card>
          )}
        </div>
      )}

      {/* Info banner */}
      <Card className="border-dashed border-muted-foreground/30 bg-muted/20">
        <CardContent className="p-4 text-sm text-muted-foreground">
          <strong>What are integrity flags?</strong> These are patterns detected by the system to help your instructor
          understand your learning process. They are <em>hypotheses for review</em>, not verdicts. Your instructor
          will look at the context and decide if any action is needed.
        </CardContent>
      </Card>

      {flags.length === 0 ? (
        <Card>
          <CardContent className="p-6 text-center text-muted-foreground">
            No patterns detected. Keep coding!
          </CardContent>
        </Card>
      ) : (
        flags.map(flag => {
          const info = FLAG_DESCRIPTIONS[flag.rule] || {
            title: flag.rule?.replace(/_/g, ' ') || 'Integrity Flag',
            explanation: flag.description || 'A pattern was detected in your submission.',
            whatNext: 'Your instructor will review this.',
          };

          return (
            <Card
              key={flag.id}
              className="border-dashed border-muted-foreground/30"
            >
              <CardContent className="p-4 space-y-3">
                <div className="flex items-start justify-between">
                  <div>
                    <Badge variant="outline" className="text-xs font-mono">
                      {flag.rule}
                    </Badge>
                    <p className="text-sm font-medium mt-2">{info.title}</p>
                  </div>
                </div>

                <p className="text-sm text-muted-foreground">{info.explanation}</p>

                {flag.evidence && (
                  <div className="text-xs text-muted-foreground bg-muted/50 p-2 rounded">
                    <strong>Evidence:</strong> {typeof flag.evidence === 'string' ? flag.evidence : JSON.stringify(flag.evidence)}
                  </div>
                )}

                <div className="text-xs text-muted-foreground bg-muted/30 p-2 rounded border-l-2 border-primary/30">
                  <strong>What happens next:</strong> {info.whatNext}
                </div>

                {flag.status === 'flagged' && !flag.student_response && responseForm.flagId !== flag.id && (
                  <div className="pt-2">
                    <button
                      onClick={() => setResponseForm({ flagId: flag.id, text: '' })}
                      className="text-xs text-primary hover:underline cursor-pointer"
                    >
                      Add context for your instructor
                    </button>
                  </div>
                )}
                {responseForm.flagId === flag.id && (
                  <div className="pt-2 space-y-2">
                    <textarea
                      className="w-full text-xs p-2 rounded border border-input bg-background resize-none"
                      rows={3}
                      maxLength={2000}
                      placeholder="Share any context about your submission process, sources you used, or challenges you faced..."
                      value={responseForm.text}
                      onChange={(e) => setResponseForm(prev => ({ ...prev, text: e.target.value }))}
                    />
                    <div className="flex gap-2">
                      <button
                        onClick={async () => {
                          try {
                            await api.post(`/api/student/integrity-flags/${flag.id}/respond`, {
                              response: responseForm.text
                            });
                            const updated = flags.map(f =>
                              f.id === flag.id ? { ...f, student_response: responseForm.text } : f
                            );
                            setFlags(updated);
                            setResponseForm({ flagId: null, text: '' });
                          } catch (err) {
                            console.error('Failed to submit response:', err);
                          }
                        }}
                        className="text-xs bg-primary text-primary-foreground px-3 py-1 rounded hover:bg-primary/90 cursor-pointer disabled:opacity-50"
                        disabled={!responseForm.text?.trim()}
                      >
                        Submit
                      </button>
                      <button
                        onClick={() => setResponseForm({ flagId: null, text: '' })}
                        className="text-xs text-muted-foreground hover:text-foreground cursor-pointer"
                      >
                        Cancel
                      </button>
                    </div>
                  </div>
                )}
                {flag.student_response && (
                  <div className="text-xs bg-primary/5 p-2 rounded border-l-2 border-primary">
                    <strong>Your context:</strong> {flag.student_response}
                  </div>
                )}

                {flag.exercise && (
                  <p className="text-xs text-muted-foreground">
                    Exercise: {flag.exercise} · {flag.date ? new Date(flag.date).toLocaleDateString() : ''}
                  </p>
                )}
              </CardContent>
            </Card>
          );
        })
      )}
    </StudentDashboardShell>
  );
}
