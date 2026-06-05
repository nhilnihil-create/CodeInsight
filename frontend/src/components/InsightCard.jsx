import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Link } from 'react-router-dom';
import { ChevronRight } from 'lucide-react';
import { cn } from '@/lib/utils';

export default function InsightCard({ insight, chart, drillTo, className }) {
  if (!insight) return null;

  return (
    <Card className={cn('', className)}>
      <CardHeader className="pb-2">
        <div className="flex items-start justify-between gap-4">
          <div className="space-y-1">
            <CardTitle className="text-base">{insight.title}</CardTitle>
            {insight.confidence && (
              <span className={cn(
                'inline-block text-[10px] font-medium uppercase tracking-wider px-1.5 py-0.5 rounded',
                insight.confidence.level === 'high'
                  ? 'text-[#22C55E] bg-[#22C55E]/10'
                  : insight.confidence.level === 'medium'
                    ? 'text-[#FACC15] bg-[#FACC15]/10'
                    : 'text-[#94A3B8] bg-[#94A3B8]/10'
              )}>
                Confidence: {insight.confidence.level.charAt(0).toUpperCase() + insight.confidence.level.slice(1)}
                {insight.confidence.n && ` (n=${insight.confidence.n})`}
              </span>
            )}
          </div>
        </div>
      </CardHeader>
      <CardContent className="space-y-3">
        <p className="text-sm text-foreground font-medium">{insight.summary}</p>
        {insight.why && (
          <p className="text-sm text-muted-foreground">{insight.why}</p>
        )}
        {chart && <div className="pt-2">{chart}</div>}
        <div className="flex items-center justify-between pt-1">
          {insight.action && (
            <p className="text-xs text-primary font-medium">{insight.action}</p>
          )}
          {drillTo && (
            <Button asChild variant="ghost" size="sm" className="gap-1 text-xs">
              <Link to={drillTo}>
                Drill down <ChevronRight className="w-3 h-3" />
              </Link>
            </Button>
          )}
        </div>
      </CardContent>
    </Card>
  );
}
