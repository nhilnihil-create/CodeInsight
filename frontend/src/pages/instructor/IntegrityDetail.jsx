import { useState, useEffect } from 'react';
import { useParams, Link } from 'react-router-dom';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Badge } from '@/components/ui/badge';
import { Button } from '@/components/ui/button';
import { ChevronLeft } from 'lucide-react';
import RiskBadge from '@/components/RiskBadge';
import api from '@/services/api';

function formatTimeAgo(dateStr) {
  if (!dateStr) return '';
  const now = Date.now();
  const then = new Date(dateStr).getTime();
  const diffSec = Math.round((now - then) / 1000);
  if (diffSec < 60) return 'just now';
  const diffMin = Math.round(diffSec / 60);
  if (diffMin < 60) return `${diffMin} min ago`;
  const diffHour = Math.round(diffMin / 60);
  if (diffHour < 24) return `${diffHour}h ago`;
  const diffDay = Math.round(diffHour / 24);
  if (diffDay < 30) return `${diffDay}d ago`;
  return new Date(dateStr).toLocaleDateString();
}

export default function InstructorIntegrityDetail() {
  const { id } = useParams();
  const [flag, setFlag] = useState(null);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);

  useEffect(() => {
    let cancelled = false;
    const load = async () => {
      try {
        setLoading(true);
        setError(null);
        const res = await api.get(`/api/analytics/integrity-flags/${id}`);
        if (!cancelled) setFlag(res.data);
      } catch (err) {
        if (!cancelled) setError(err.response?.data?.error || 'Failed to load flag details');
      } finally {
        if (!cancelled) setLoading(false);
      }
    };
    load();
    return () => { cancelled = true; };
  }, [id]);

  const handleAction = async (status) => {
    try {
      await api.put(`/api/analytics/integrity-flags/${id}/mark-reviewed`, { status });
      const res = await api.get(`/api/analytics/integrity-flags/${id}`);
      setFlag(res.data);
    } catch (err) {
      console.error('Failed to update flag:', err);
    }
  };

  if (loading) {
    return (
      <div className="space-y-4">
        <Button asChild variant="ghost" size="sm">
          <Link to="/instructor/integrity"><ChevronLeft className="w-4 h-4 mr-1" /> Back to integrity</Link>
        </Button>
        <Card><CardContent className="p-6 text-center text-muted-foreground">Loading flag details…</CardContent></Card>
      </div>
    );
  }

  if (error || !flag) {
    return (
      <div className="space-y-4">
        <Button asChild variant="ghost" size="sm">
          <Link to="/instructor/integrity"><ChevronLeft className="w-4 h-4 mr-1" /> Back to integrity</Link>
        </Button>
        <Card><CardContent className="p-6 text-center text-destructive">{error || 'Flag not found.'}</CardContent></Card>
      </div>
    );
  }

  return (
    <div className="space-y-6">
      <Button asChild variant="ghost" size="sm">
        <Link to="/instructor/integrity"><ChevronLeft className="w-4 h-4 mr-1" /> Back to integrity</Link>
      </Button>

      <div className="flex items-center justify-between">
        <div>
          <h1 className="text-2xl font-bold">{flag.flagType}</h1>
          <p className="text-muted-foreground text-sm">
            {flag.studentName} · {flag.exerciseTitle} · {formatTimeAgo(flag.createdAt)}
          </p>
        </div>
        <div className="flex items-center gap-2">
          <Badge variant={flag.status === 'flagged' ? 'destructive' : flag.status === 'dismissed' ? 'secondary' : 'default'}>
            {flag.status}
          </Badge>
          <RiskBadge level={flag.severity} />
        </div>
      </div>

      <div className="grid gap-6 md:grid-cols-2">
        <Card>
          <CardHeader>
            <CardTitle className="text-sm">Evidence</CardTitle>
          </CardHeader>
          <CardContent className="space-y-3">
            {flag.evidence?.length > 0 ? (
              <ul className="space-y-2">
                {flag.evidence.map((item, i) => (
                  <li key={i} className="text-sm text-muted-foreground">&bull; {item}</li>
                ))}
              </ul>
            ) : (
              <p className="text-sm text-muted-foreground">No evidence recorded.</p>
            )}
            <div className="bg-muted p-3 rounded text-xs font-mono text-muted-foreground">
              Severity: {flag.severity}<br />
              Confidence: {flag.confidence}%<br />
              Section: {flag.sectionName}
            </div>
          </CardContent>
        </Card>

        <Card>
          <CardHeader>
            <CardTitle className="text-sm">Suggested Next Action</CardTitle>
          </CardHeader>
          <CardContent className="space-y-3">
            <Button className="w-full" variant="outline" onClick={() => handleAction('reviewed')}>
              Mark Reviewed
            </Button>
            <Button className="w-full" variant="outline">
              Request 1:1
            </Button>
            <Button className="w-full" variant="outline">
              Refer to Registrar
            </Button>
            <Button className="w-full text-destructive" variant="ghost" onClick={() => handleAction('dismissed')}>
              Dismiss (with reason)
            </Button>
          </CardContent>
        </Card>
      </div>
    </div>
  );
}
