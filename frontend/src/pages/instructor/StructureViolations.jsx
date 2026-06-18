import React, { useState, useEffect } from 'react';
import { useParams, useNavigate } from 'react-router-dom';
import { ChevronLeft, AlertTriangle, Loader2 } from 'lucide-react';
import api from '../../services/api';
import {
  Card, CardContent, CardHeader, CardTitle, CardDescription,
} from '@/components/ui/card';
import { Badge } from '@/components/ui/badge';
import { Button } from '@/components/ui/button';
import { Skeleton } from '@/components/ui/skeleton';
import {
  Table, TableHeader, TableBody, TableHead, TableRow, TableCell,
} from '@/components/ui/table';

export default function StructureViolationsReport() {
  const { sectionId } = useParams();
  const navigate = useNavigate();
  const [violations, setViolations] = useState([]);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    let active = true;
    const load = async () => {
      try {
        const res = await api.get(`/api/analytics/sections/${sectionId}/structure-violations`);
        if (active) setViolations(res.data || []);
      } catch (err) {
        // network errors are expected
      } finally {
        if (active) setLoading(false);
      }
    };
    load();
    return () => { active = false; };
  }, [sectionId]);

  const severityColor = (severity) => {
    switch (severity) {
      case 'error': return 'destructive';
      case 'warning': return 'secondary';
      default: return 'outline';
    }
  };

  if (loading) {
    return (
      <div className="space-y-6">
        <Skeleton className="h-8 w-48" />
        <Skeleton className="h-[400px] w-full" />
      </div>
    );
  }

  return (
    <div className="space-y-6">
      <div className="flex items-center gap-4">
        <Button variant="ghost" size="sm" onClick={() => navigate(-1)}>
          <ChevronLeft className="mr-1 h-4 w-4" /> Back
        </Button>
        <div>
          <h1 className="text-2xl font-bold">Structure Violations Report</h1>
          <p className="text-muted-foreground">
            Submissions where the required programming construct was missing, empty, or used incorrectly.
          </p>
        </div>
      </div>

      <Card>
        <CardHeader>
          <CardTitle className="flex items-center gap-2">
            <AlertTriangle className="h-5 w-5 text-amber-500" />
            Structure Violations
          </CardTitle>
          <CardDescription>
            {violations.length} violation{violations.length !== 1 ? 's' : ''} found across all exercises.
          </CardDescription>
        </CardHeader>
        <CardContent>
          {violations.length === 0 ? (
            <div className="py-12 text-center text-sm text-muted-foreground">
              No structure violations detected. All submissions passed AST verification.
            </div>
          ) : (
            <Table>
              <TableHeader>
                <TableRow>
                  <TableHead>Student</TableHead>
                  <TableHead>Exercise</TableHead>
                  <TableHead>Concept</TableHead>
                  <TableHead>Violation</TableHead>
                  <TableHead>Type</TableHead>
                  <TableHead>Attempt #</TableHead>
                  <TableHead>Date</TableHead>
                </TableRow>
              </TableHeader>
              <TableBody>
                {violations.map((v, i) => (
                  <TableRow key={i}>
                    <TableCell className="font-medium">{v.student_name}</TableCell>
                    <TableCell>{v.exercise_title}</TableCell>
                    <TableCell>{v.concept_name}</TableCell>
                    <TableCell className="max-w-xs truncate">{v.reason}</TableCell>
                    <TableCell>
                      <Badge variant={severityColor(v.severity || 'warning')}>
                        {v.verification_type || 'ast_verifier'}
                      </Badge>
                    </TableCell>
                    <TableCell>{v.attempt_number || '—'}</TableCell>
                    <TableCell className="text-xs text-muted-foreground">
                      {v.submitted_at ? new Date(v.submitted_at).toLocaleDateString() : '—'}
                    </TableCell>
                  </TableRow>
                ))}
              </TableBody>
            </Table>
          )}
        </CardContent>
      </Card>
    </div>
  );
}
