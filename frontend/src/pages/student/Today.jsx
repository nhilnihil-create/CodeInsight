import { Link } from 'react-router-dom';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import CDSPillDelta from '@/components/CDSPillDelta';
import { MOCK_STUDENT_TODAY } from '@/data/mockData';

export default function StudentToday() {
  const data = MOCK_STUDENT_TODAY;

  return (
    <div className="space-y-6 max-w-3xl">
      <Card>
        <CardContent className="p-6">
          <p className="text-xs text-muted-foreground uppercase tracking-wider mb-1">What</p>
          <h2 className="text-xl font-bold">{data.focus.title}</h2>
          <p className="text-sm text-muted-foreground mt-1">Estimated {data.focus.estimatedMinutes}</p>
        </CardContent>
      </Card>

      <Card>
        <CardContent className="p-6">
          <p className="text-xs text-muted-foreground uppercase tracking-wider mb-1">Why</p>
          <p className="text-sm">{data.why}</p>
        </CardContent>
      </Card>

      <Card>
        <CardContent className="p-6">
          <p className="text-xs text-muted-foreground uppercase tracking-wider mb-1">Who</p>
          <p className="text-sm">
            You, in BSIT-1A. Class avg on this concept:{' '}
            <CDSPillDelta value={data.classAvg} classification={data.classAvg > 0.50 ? 'high' : 'mod'} />
          </p>
        </CardContent>
      </Card>

      <div className="flex gap-3">
        {data.nextMoves?.map((move, i) => (
          <Button key={i} asChild variant={move.primary ? 'default' : 'outline'} size="sm">
            <Link to={move.to}>{move.label}</Link>
          </Button>
        ))}
      </div>

      <Card>
        <CardHeader><CardTitle className="text-sm">Your Concept Mastery</CardTitle></CardHeader>
        <CardContent className="space-y-3">
          {data.concepts?.map(c => (
            <div key={c.concept} className="flex items-center gap-3">
              <span className="w-8 text-xs font-mono font-medium">{c.concept}</span>
              <CDSPillDelta
                value={c.cds}
                delta={c.delta}
                trend={c.trend}
                classification={c.cds > 0.50 ? 'high' : c.cds > 0.31 ? 'mod' : 'low'}
              />
              <div className="flex-1 h-2 bg-muted rounded-full overflow-hidden">
                <div className="h-full rounded-full bg-primary" style={{ width: `${c.cds * 100}%` }} />
              </div>
            </div>
          ))}
        </CardContent>
      </Card>

      <Card className="border-dashed">
        <CardContent className="p-4 space-y-2">
          {data.signals?.map((s, i) => (
            <p key={i} className="text-sm text-muted-foreground">&bull; {s}</p>
          ))}
        </CardContent>
      </Card>
    </div>
  );
}
