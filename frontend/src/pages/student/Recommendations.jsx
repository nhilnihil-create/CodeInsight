import { useState, useEffect } from 'react';
import { Link } from 'react-router-dom';
import { Card, CardContent } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Badge } from '@/components/ui/badge';
import { cn } from '@/lib/utils';
import StudentDashboardShell from '@/components/student-dashboard-shell';
import JoinSectionGate from '@/components/join-section-gate';
import useHasSections from '@/hooks/useHasSections';
import api from '@/services/api';

const priorityConfig = {
  0: { badge: 'default', label: 'Priority', confidence: 'high' },
  1: { badge: 'default', label: 'Priority', confidence: 'high' },
  2: { badge: 'secondary', label: 'Optional', confidence: 'medium' },
  3: { badge: 'outline', label: 'Stretch', confidence: 'low' },
};

export default function StudentRecommendations() {
  const { hasSections, checking, recheck } = useHasSections();
  const [recs, setRecs] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [fetchKey, setFetchKey] = useState(0);

  useEffect(() => {
    if (hasSections === null || !hasSections) return;
    let cancelled = false;
    const load = async () => {
      try {
        const res = await api.get('/api/student/dashboard');
        if (!cancelled) {
          const recommended = res.data?.recommended || [];
          const mapped = recommended.map((r, idx) => ({
            priority: idx + 1,
            pattern: r.blurb || r.title,
            confidence: r.status === 'pending' ? 'high' : 'medium',
            action: {
              label: (r.isCompleted ?? r.status === 'completed') ? 'Review' : 'Start',
              to: `/student/exercises/${r.id}`,
            },
            whyLink: true,
          }));
          setRecs(mapped);
        }
      } catch (err) {
        if (!cancelled) setError(err.response?.data?.error || 'Failed to load recommendations');
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
          { label: 'Recommended Next Moves' },
        ]}
        subtitle="Personalized suggestions based on your progress."
      >
        <div className="py-12 text-center text-muted-foreground">Loading recommendations…</div>
      </StudentDashboardShell>
    );
  }

  if (!hasSections) {
    return <JoinSectionGate onJoined={handleJoined} />;
  }

  if (error) {
    return (
      <StudentDashboardShell
        breadcrumb={[
          { label: 'Student', href: '/student/dashboard' },
          { label: 'Recommended Next Moves' },
        ]}
        subtitle="Personalized suggestions based on your progress."
      >
        <div className="py-12 text-center text-muted-foreground">Loading recommendations…</div>
      </StudentDashboardShell>
    );
  }

  if (error) {
    return (
      <StudentDashboardShell
        breadcrumb={[
          { label: 'Student', href: '/student/dashboard' },
          { label: 'Recommended Next Moves' },
        ]}
        subtitle="Personalized suggestions based on your progress."
      >
        <div className="py-12 text-center text-destructive">{error}</div>
      </StudentDashboardShell>
    );
  }

  return (
    <StudentDashboardShell
      breadcrumb={[
        { label: 'Student', href: '/student/dashboard' },
        { label: 'Recommended Next Moves' },
      ]}
      subtitle="Personalized suggestions based on your progress."
    >
      {recs.length === 0 ? (
        <Card>
          <CardContent className="p-6 text-center text-muted-foreground">
            No recommendations yet. Complete some exercises to get personalized suggestions!
          </CardContent>
        </Card>
      ) : (
        recs.map(rec => {
          const config = priorityConfig[rec.priority] || priorityConfig[3];
          return (
            <Card
              key={rec.priority}
              className={rec.priority <= 1 ? 'border-l-4 border-l-primary' : ''}
            >
              <CardContent className="p-4 space-y-3">
                <div className="flex items-center justify-between">
                  <Badge variant={config.badge}>
                    {config.label}
                  </Badge>
                  <span
                    className={cn(
                      'text-[10px] font-medium uppercase tracking-wider px-1.5 py-0.5 rounded',
                      config.confidence === 'high'
                        ? 'text-[#22C55E] bg-[#22C55E]/10'
                        : config.confidence === 'medium'
                          ? 'text-[#FACC15] bg-[#FACC15]/10'
                          : 'text-[#94A3B8] bg-[#94A3B8]/10'
                    )}
                  >
                    Confidence:{' '}
                    {config.confidence.charAt(0).toUpperCase() +
                      config.confidence.slice(1)}
                  </span>
                </div>
                <p className="text-sm">{rec.pattern}</p>
                <div className="flex items-center gap-2 pt-1">
                  <Button asChild size="sm">
                    <Link to={rec.action.to}>{rec.action.label}</Link>
                  </Button>
                  {rec.whyLink && (
                    <button
                      type="button"
                      className="text-[10px] text-muted-foreground underline underline-offset-2"
                    >
                      Why am I seeing this?
                    </button>
                  )}
                </div>
              </CardContent>
            </Card>
          );
        })
      )}
    </StudentDashboardShell>
  );
}
