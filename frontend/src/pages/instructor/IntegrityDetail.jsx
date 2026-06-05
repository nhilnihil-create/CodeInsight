import { useParams, Link } from 'react-router-dom';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Badge } from '@/components/ui/badge';
import { Button } from '@/components/ui/button';
import { ChevronLeft } from 'lucide-react';
import { MOCK_INTEGRITY_FLAGS } from '@/data/mockData';

export default function InstructorIntegrityDetail() {
  const { id } = useParams();
  const flag = MOCK_INTEGRITY_FLAGS.find(f => f.id === parseInt(id));

  if (!flag) {
    return (
      <div className="space-y-4">
        <Button asChild variant="ghost" size="sm">
          <Link to="/instructor/integrity"><ChevronLeft className="w-4 h-4 mr-1" /> Back to integrity</Link>
        </Button>
        <Card><CardContent className="p-6">
          <p className="text-muted-foreground">Flag not found.</p>
        </CardContent></Card>
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
          <h1 className="text-2xl font-bold">{flag.type}</h1>
          <p className="text-muted-foreground text-sm">{flag.student} &middot; {flag.exercise} &middot; {flag.time}</p>
        </div>
        <Badge variant="destructive" className="text-xs">{flag.confidence}% confidence</Badge>
      </div>

      <div className="grid gap-6 md:grid-cols-2">
        <Card>
          <CardHeader>
            <CardTitle className="text-sm">Evidence</CardTitle>
          </CardHeader>
          <CardContent className="space-y-3">
            <p className="text-sm">{flag.desc}</p>
            <div className="bg-muted p-3 rounded text-xs font-mono text-muted-foreground">
              z-score: +2.1&sigma;<br />
              confidence interval: {flag.confidence}% Wilson CI<br />
              n=47 submissions
            </div>
          </CardContent>
        </Card>
        <Card>
          <CardHeader>
            <CardTitle className="text-sm">Suggested Next Action</CardTitle>
          </CardHeader>
          <CardContent className="space-y-3">
            <Button className="w-full" variant="outline">Mark Reviewed</Button>
            <Button className="w-full" variant="outline">Request 1:1</Button>
            <Button className="w-full" variant="outline">Refer to Registrar</Button>
            <Button className="w-full" variant="ghost" className="text-destructive">Dismiss (with reason)</Button>
          </CardContent>
        </Card>
      </div>
    </div>
  );
}
