import { useState, useEffect } from 'react';
import { Link } from 'react-router-dom';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Badge } from '@/components/ui/badge';
import { Button } from '@/components/ui/button';
import InsightCard from '@/components/InsightCard';
import CDSPillDelta from '@/components/CDSPillDelta';
import RiskBadge from '@/components/ui/risk-badge';
import { cn } from '@/lib/utils';
import api from '@/services/api';

export default function InstructorCommand() {
  const [data, setData] = useState(null);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [showIntegrity, setShowIntegrity] = useState(false);

  useEffect(() => {
    let cancelled = false;
    const load = async () => {
      try {
        setLoading(true);
        setError(null);
        const res = await api.get('/api/analytics/command');
        if (!cancelled) setData(res.data);
      } catch (err) {
        if (!cancelled) setError(err.response?.data?.error || 'Failed to load command center');
      } finally {
        if (!cancelled) setLoading(false);
      }
    };
    load();
    return () => { cancelled = true; };
  }, []);

  if (loading) {
    return (
      <div className="space-y-6">
        <div className="py-12 text-center text-muted-foreground">Loading command center…</div>
      </div>
    );
  }

  if (error) {
    return (
      <div className="space-y-6">
        <div className="py-12 text-center text-destructive">{error}</div>
      </div>
    );
  }

  return (
    <div className="space-y-6">
      {data.confidence && (
        <div className="flex items-center gap-2">
          <span className={cn(
            'text-xs font-medium px-2 py-1 rounded',
            data.confidence.level === 'high'
              ? 'bg-[#22C55E]/10 text-[#22C55E]'
              : data.confidence.level === 'medium'
                ? 'bg-[#FACC15]/10 text-[#FACC15]'
                : 'bg-[#94A3B8]/10 text-[#94A3B8]'
          )}>
            Confidence: {data.confidence.level.charAt(0).toUpperCase() + data.confidence.level.slice(1)}
            {data.confidence.n ? ` (n=${data.confidence.n} · ${data.confidence.days} days · Wilson 95% CI half-width ≤ 0.10)` : ''}
          </span>
        </div>
      )}

      {data.weeklyInsight && (
        <Card className="border-l-4 border-l-primary">
          <CardContent className="p-4">
            <div className="flex items-start justify-between gap-4">
              <div className="space-y-1">
                <p className="text-sm font-medium">{data.weeklyInsight.message}</p>
                <p className="text-xs text-muted-foreground font-mono">
                  Rule: {data.weeklyInsight.rule} | n={data.weeklyInsight.n} | Wilson 95% CI half-width = 0.08
                </p>
              </div>
              <Button asChild variant="outline" size="sm">
                <Link to="/instructor/reports">View reports &rarr;</Link>
              </Button>
            </div>
          </CardContent>
        </Card>
      )}

      {data.cards?.length > 0 && (
        <div className="grid gap-4 md:grid-cols-2">
          {data.cards.map(card => (
            <InsightCard key={card.id} insight={card} />
          ))}
        </div>
      )}

      {data.kpis?.length > 0 && (
        <div className="grid grid-cols-2 md:grid-cols-3 lg:grid-cols-4 xl:grid-cols-7 gap-3">
          {data.kpis.map(kpi => (
            <Card key={kpi.label} className="p-3">
              <p className="text-[10px] text-muted-foreground uppercase tracking-wider">{kpi.label}</p>
              <div className="flex items-center gap-2 mt-1">
                <span className="text-lg font-bold font-mono">
                  {typeof kpi.value === 'number' ? (kpi.value > 1 ? kpi.value : kpi.value.toFixed(2)) : kpi.value}
                </span>
                {kpi.delta != null && (
                  <CDSPillDelta
                    value={0}
                    delta={kpi.delta}
                    classification={
                      kpi.inverted
                        ? (kpi.delta < 0 ? 'high' : kpi.delta > 0 ? 'low' : 'na')
                        : (kpi.delta > 0 ? 'high' : kpi.delta < 0 ? 'low' : 'na')
                    }
                    trend={kpi.trend}
                  />
                )}
              </div>
              {kpi.sparkline?.length > 0 && (
                <div className="mt-2 h-6 flex items-end gap-[2px]">
                  {kpi.sparkline.map((v, i) => (
                    <div
                      key={i}
                      className="w-full bg-primary/30 rounded-t"
                      style={{ height: `${(v / Math.max(...kpi.sparkline)) * 100}%` }}
                    />
                  ))}
                </div>
              )}
            </Card>
          ))}
        </div>
      )}

      <div className="grid gap-6 lg:grid-cols-2">
        {data.conceptBars?.length > 0 && (
          <Card>
            <CardHeader>
              <CardTitle className="text-sm">Concept Difficulty</CardTitle>
            </CardHeader>
            <CardContent className="space-y-2">
              {data.conceptBars.map(bar => (
                <div key={bar.concept} className="flex items-center gap-3">
                  <span className="w-8 text-xs font-mono font-medium">{bar.concept}</span>
                  <CDSPillDelta
                    value={bar.cds}
                    delta={bar.delta}
                    classification={bar.cds <= 0.20 ? 'very_low' : bar.cds <= 0.40 ? 'low' : bar.cds <= 0.60 ? 'moderate' : bar.cds <= 0.80 ? 'elevated' : 'high'}
                    trend={bar.trend}
                  />
                  <div className="flex-1 h-3 bg-muted rounded-full overflow-hidden">
                    <div
                      className={cn(
                        'h-full rounded-full',
                        bar.cds <= 0.20 ? 'bg-[#22C55E]' : bar.cds <= 0.40 ? 'bg-[#14B8A6]' : bar.cds <= 0.60 ? 'bg-[#F59E0B]' : bar.cds <= 0.80 ? 'bg-[#F97316]' : 'bg-[#F43F5E]'
                      )}
                      style={{ width: `${(bar.cds / 1) * 100}%` }}
                    />
                  </div>
                  <span className="text-xs text-muted-foreground">{bar.atRiskCount} at risk</span>
                </div>
              ))}
            </CardContent>
          </Card>
        )}

        {data.atRiskRoster?.length > 0 && (
          <Card>
            <CardHeader>
              <CardTitle className="text-sm">At-Risk Roster</CardTitle>
            </CardHeader>
            <CardContent className="space-y-2">
              {data.atRiskRoster.map(student => (
                <div key={student.id} className="flex items-center justify-between py-1.5 border-b border-border/50 last:border-0">
                  <div className="flex items-center gap-2">
                    <span className="text-sm font-medium">{student.name}</span>
                    <RiskBadge level={student.riskTier === 'critical' ? 'critical' : student.riskTier === 'high' ? 'high' : 'medium'} />
                  </div>
                  <div className="flex items-center gap-1">
                    <Badge variant="secondary" className="text-[10px]">{student.dominantConcept}</Badge>
                    <Button asChild variant="ghost" size="sm" className="h-6 text-[10px]">
                      <Link to={`/instructor/students/${student.id}`}>View</Link>
                    </Button>
                  </div>
                </div>
              ))}
            </CardContent>
          </Card>
        )}
      </div>

      {data.signals?.length > 0 && (
        <Card>
          <CardHeader>
            <CardTitle className="text-sm">Learning Signals</CardTitle>
          </CardHeader>
          <CardContent>
            <ul className="space-y-2">
              {data.signals.map((s, i) => (
                <li key={i} className="text-sm text-muted-foreground flex items-start gap-2">
                  <span className="text-primary mt-1">&bull;</span>
                  {s}
                </li>
              ))}
            </ul>
          </CardContent>
        </Card>
      )}

      <Card className="border-dashed border-muted-foreground/30 bg-muted/5">
        <CardContent className="p-4">
          <button
            type="button"
            onClick={() => setShowIntegrity(!showIntegrity)}
            className="w-full flex items-center justify-between text-left"
          >
            <p className="text-sm font-medium text-muted-foreground">
              {data.integrityFlags?.count ?? 0} integrity flag{data.integrityFlags?.count !== 1 ? 's' : ''} open across {data.integrityFlags?.sections ?? 0} section{(data.integrityFlags?.sections ?? 0) !== 1 ? 's' : ''}.
              <Link to="/instructor/integrity" className="ml-2 text-primary underline underline-offset-2">Review queue &rarr;</Link>
            </p>
            <span className="text-xs text-muted-foreground">{showIntegrity ? '▲' : '▼'}</span>
          </button>
        </CardContent>
      </Card>
    </div>
  );
}
