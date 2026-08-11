import React, { useState, useEffect } from 'react';
import { useParams, useNavigate } from 'react-router-dom';
import { ChevronLeft, TrendingUp, Loader2 } from 'lucide-react';
import api from '../../services/api';
import {
  Card, CardContent, CardHeader, CardTitle, CardDescription,
} from '@/components/ui/card';
import { Badge } from '@/components/ui/badge';
import { Button } from '@/components/ui/button';
import ExportDropdown from '@/components/ui/export-dropdown';
import { Skeleton } from '@/components/ui/skeleton';
import {
  Table, TableHeader, TableBody, TableHead, TableRow, TableCell,
} from '@/components/ui/table';

export default function ClassMicroConceptReport() {
  const { sectionId } = useParams();
  const navigate = useNavigate();
  const [report, setReport] = useState(null);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    let active = true;
    const load = async () => {
      try {
        const res = await api.get(`/api/analytics/sections/${sectionId}/micro-concept-report`);
        if (active) setReport(res.data);
      } catch (err) {
        // network errors are expected
      } finally {
        if (active) setLoading(false);
      }
    };
    load();
    return () => { active = false; };
  }, [sectionId]);

  if (loading) {
    return (
      <div className="space-y-6">
        <Skeleton className="h-8 w-48" />
        <Skeleton className="h-[400px] w-full" />
      </div>
    );
  }

  const concepts = report?.concepts || [];

  return (
    <div className="space-y-6">
      <div className="flex items-center gap-4">
        <Button variant="ghost" size="sm" onClick={() => navigate(-1)}>
          <ChevronLeft className="mr-1 h-4 w-4" /> Back
        </Button>
        <div>
          <h1 className="text-2xl font-bold">Class-Wide Micro-Concept Report</h1>
          <p className="text-muted-foreground">
            Aggregated pattern analysis of specific sub-concepts confusing students.
          </p>
        </div>
        <ExportDropdown sectionId={sectionId} domain="concept_mastery" className="ml-auto" />
      </div>

      {concepts.length === 0 ? (
        <Card>
          <CardContent className="py-12 text-center text-sm text-muted-foreground">
            No micro-concept data available yet. Students need to submit exercises for analysis.
          </CardContent>
        </Card>
      ) : (
        concepts.map((concept) => (
          <Card key={concept.name}>
            <CardHeader>
              <CardTitle className="flex items-center gap-2">
                <TrendingUp className="h-5 w-5 text-primary" />
                {concept.name}
              </CardTitle>
              <CardDescription>
                {concept.studentCount} student{concept.studentCount !== 1 ? 's' : ''} affected · {concept.issueCount} issue{concept.issueCount !== 1 ? 's' : ''} detected
              </CardDescription>
            </CardHeader>
            <CardContent>
              <Table>
                <TableHeader>
                  <TableRow>
                    <TableHead>Micro-Concept Issue</TableHead>
                    <TableHead>Affected Students</TableHead>
                    <TableHead>Severity</TableHead>
                    <TableHead>Recommendation</TableHead>
                  </TableRow>
                </TableHeader>
                <TableBody>
                  {(concept.issues || []).map((issue, idx) => (
                    <TableRow key={idx}>
                      <TableCell className="font-medium">{issue.name}</TableCell>
                      <TableCell>
                        <Badge variant="secondary">{issue.studentCount || 1}</Badge>
                      </TableCell>
                      <TableCell>
                        <Badge variant={issue.severity === 'high' ? 'destructive' : issue.severity === 'medium' ? 'secondary' : 'outline'}>
                          {issue.severity}
                        </Badge>
                      </TableCell>
                      <TableCell className="text-sm text-muted-foreground">{issue.recommendation || issue.description}</TableCell>
                    </TableRow>
                  ))}
                </TableBody>
              </Table>
            </CardContent>
          </Card>
        ))
      )}
    </div>
  );
}
