import { useState } from 'react';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Input } from '@/components/ui/input';
import { Badge } from '@/components/ui/badge';
import { MOCK_SECTIONS } from '@/data/mockData';

export default function StudentSections() {
  const [joinCode, setJoinCode] = useState('');

  const mySections = MOCK_SECTIONS.slice(0, 2);

  return (
    <div className="space-y-6 max-w-3xl">
      <div>
        <h1 className="text-2xl font-bold">My Sections</h1>
        <p className="text-sm text-muted-foreground">View and manage your enrolled sections.</p>
      </div>

      {mySections.map(section => (
        <Card key={section.id}>
          <CardContent className="p-4 flex items-center justify-between">
            <div>
              <h3 className="font-semibold">{section.name}</h3>
              <p className="text-xs text-muted-foreground font-mono">{section.code} &middot; {section.term}</p>
            </div>
            <Badge variant="outline" className="text-xs">Active</Badge>
          </CardContent>
        </Card>
      ))}

      <Card>
        <CardHeader><CardTitle className="text-sm">Join Another Section</CardTitle></CardHeader>
        <CardContent className="space-y-3">
          <p className="text-xs text-muted-foreground">Enter the 6-character code provided by your instructor.</p>
          <div className="flex gap-2">
            <Input
              placeholder="e.g. K7P-3QX"
              value={joinCode}
              onChange={e => setJoinCode(e.target.value.toUpperCase())}
              maxLength={7}
              className="font-mono w-40"
            />
            <Button size="sm" disabled={joinCode.length < 7}>Join</Button>
          </div>
          <button type="button" className="text-[10px] text-muted-foreground underline underline-offset-2">
            Code not working?
          </button>
        </CardContent>
      </Card>
    </div>
  );
}
