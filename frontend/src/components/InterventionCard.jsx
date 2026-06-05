import { Card, CardContent } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Badge } from '@/components/ui/badge';
import { Avatar } from '@/components/ui/avatar';
import CDSPillDelta from './CDSPillDelta';
import { cn } from '@/lib/utils';

export default function InterventionCard({ student, problem, evidence, suggestedAction, onWhy, className }) {
  return (
    <Card className={cn('border-destructive/20', className)}>
      <CardContent className="p-4 space-y-3">
        <div className="flex items-center gap-3">
          <Avatar className="h-8 w-8">
            <span className="text-xs font-medium">{student.name.split(' ').map(n => n[0]).join('')}</span>
          </Avatar>
          <div>
            <p className="text-sm font-semibold">{student.name}</p>
            <p className="text-xs text-muted-foreground font-mono">{student.id}</p>
          </div>
        </div>

        <div className="space-y-1">
          <div className="flex items-center gap-2">
            <Badge variant="secondary" className="text-xs">{problem.concept}</Badge>
            <CDSPillDelta
              value={problem.cds}
              delta={problem.delta}
              classification={problem.classification}
              trend={problem.trend}
            />
          </div>
          <p className="text-xs text-muted-foreground">{problem.description}</p>
        </div>

        {evidence && evidence.length > 0 && (
          <ul className="space-y-1">
            {evidence.map((e, i) => (
              <li key={i} className="text-xs text-muted-foreground flex items-start gap-2">
                <span className="text-destructive mt-0.5">•</span>
                {e}
              </li>
            ))}
          </ul>
        )}

        <div className="flex items-center justify-between pt-1 border-t border-border/50">
          {suggestedAction ? (
            <Button size="sm" className="gap-1 text-xs" onClick={suggestedAction.onClick}>
              {suggestedAction.label}
            </Button>
          ) : (
            <span className="text-xs text-muted-foreground">No action suggested</span>
          )}
          <button
            type="button"
            onClick={onWhy}
            className="text-[10px] text-muted-foreground underline underline-offset-2 hover:text-foreground"
          >
            Why am I seeing this?
          </button>
        </div>
      </CardContent>
    </Card>
  );
}
