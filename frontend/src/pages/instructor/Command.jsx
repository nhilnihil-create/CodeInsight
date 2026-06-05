import { useState } from 'react';
import { Link } from 'react-router-dom';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Badge } from '@/components/ui/badge';
import { Button } from '@/components/ui/button';
import InsightCard from '@/components/InsightCard';
import CDSPillDelta from '@/components/CDSPillDelta';
import RiskBadge from '@/components/RiskBadge';
import InterventionCard from '@/components/InterventionCard';
import { MOCK_COMMAND_CENTER } from '@/data/mockData';
import { cn } from '@/lib/utils';

export default function InstructorCommand() {
  const [showIntegrity, setShowIntegrity] = useState(false);
  const data = MOCK_COMMAND_CENTER;

  return (
    <div className="space-y-6">
      <div className="flex items-center gap-2">
        {data.confidence && (
          <span className={cn(
            'text-xs font-medium px-2 py-1 rounded',
            data.confidence.level === 'high'
              ? 'bg-[#22C55E]/10 text-[#22C55E]'
              : data.confidence.level === 'medium'
                ? 'bg-[#FACC15]/10 text-[#FACC15]'
                : 'bg-[#94A3B8]/10 text-[#94A3B8]'
          )}>
            Confidence: {data.confidence.level.charAt(0).toUpperCase() + data.confidence.level.slice(1)}
            (n={data.confidence.n} &middot; {data.confidence.days} days &middot; Wilson 95% CI half-width &le; 0.10)
          </span>
        )}
      </div>

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
                <Link to="#">View question template &rarr;</Link>
              </Button>
            </div>
          </CardContent>
        </Card>
      )}

      <div className="grid gap-4 md:grid-cols-2">
        {data.cards?.map(card => (
          <InsightCard key={card.id} insight={card} />
        ))}
      </div>

      <div className="grid grid-cols-2 md:grid-cols-3 lg:grid-cols-6 gap-3">
        {data.kpis?.map(kpi => (
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
                  classification={kpi.delta > 0 ? 'high' : kpi.delta < 0 ? 'low' : 'na'}
                  trend={kpi.trend}
                />
              )}
            </div>
            {kpi.sparkline && (
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

      <div className="grid gap-6 lg:grid-cols-2">
        <Card>
          <CardHeader>
            <CardTitle className="text-sm">Concept Difficulty</CardTitle>
          </CardHeader>
          <CardContent className="space-y-2">
            {data.conceptBars?.map(bar => (
              <div key={bar.concept} className="flex items-center gap-3">
                <span className="w-8 text-xs font-mono font-medium">{bar.concept}</span>
                <CDSPillDelta
                  value={bar.cds}
                  delta={bar.delta}
                  classification={bar.cds > 0.50 ? 'high' : bar.cds > 0.31 ? 'mod' : 'low'}
                  trend={bar.trend}
                />
                <div className="flex-1 h-3 bg-muted rounded-full overflow-hidden">
                  <div
                    className={cn(
                      'h-full rounded-full',
                      bar.cds > 0.50 ? 'bg-[#EF4444]' : bar.cds > 0.31 ? 'bg-[#FACC15]' : 'bg-[#22C55E]'
                    )}
                    style={{ width: `${(bar.cds / 1) * 100}%` }}
                  />
                </div>
                <span className="text-xs text-muted-foreground">{bar.atRiskCount} at risk</span>
              </div>
            ))}
          </CardContent>
        </Card>

        <Card>
          <CardHeader>
            <CardTitle className="text-sm">At-Risk Roster</CardTitle>
          </CardHeader>
          <CardContent className="space-y-2">
            {data.atRiskRoster?.map(student => (
              <div key={student.id} className="flex items-center justify-between py-1.5 border-b border-border/50 last:border-0">
                <div className="flex items-center gap-2">
                  <span className="text-sm font-medium">{student.name}</span>
                  <RiskBadge tier={student.riskTier} />
                </div>
                <div className="flex items-center gap-1">
                  <Badge variant="secondary" className="text-[10px]">{student.dominantConcept}</Badge>
                  <Button variant="ghost" size="sm" className="h-6 text-[10px]">View</Button>
                </div>
              </div>
            ))}
          </CardContent>
        </Card>
      </div>

      <div className="grid gap-6 lg:grid-cols-2">
        <Card>
          <CardHeader>
            <CardTitle className="text-sm">Learning Signals</CardTitle>
          </CardHeader>
          <CardContent>
            <ul className="space-y-2">
              {data.signals?.map((s, i) => (
                <li key={i} className="text-sm text-muted-foreground flex items-start gap-2">
                  <span className="text-primary mt-1">&bull;</span>
                  {s}
                </li>
              ))}
            </ul>
          </CardContent>
        </Card>

        <div className="space-y-3">
          <h3 className="text-sm font-semibold">Intervention Queue</h3>
          {data.interventions?.map((intervention, i) => (
            <InterventionCard key={i} {...intervention} />
          ))}
        </div>
      </div>

      <Card className="border-dashed border-muted-foreground/30 bg-muted/5">
        <CardContent className="p-4">
          <button
            type="button"
            onClick={() => setShowIntegrity(!showIntegrity)}
            className="w-full flex items-center justify-between text-left"
          >
            <p className="text-sm font-medium text-muted-foreground">
              {data.integrityFlags?.count} integrity flags open across {data.integrityFlags?.sections} sections.
              <Link to="/instructor/integrity" className="ml-2 text-primary underline underline-offset-2">Review queue &rarr;</Link>
            </p>
            <span className="text-xs text-muted-foreground">{showIntegrity ? '▲' : '▼'}</span>
          </button>
        </CardContent>
      </Card>
    </div>
  );
}
