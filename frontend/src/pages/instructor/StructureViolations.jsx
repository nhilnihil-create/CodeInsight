import React, { useState, useEffect } from 'react';
import { useParams, useNavigate } from 'react-router-dom';
import { ChevronLeft, AlertTriangle, Loader2 } from 'lucide-react';
import api from '../../services/api';

import { Badge } from '@/components/ui/badge';
import { Button } from '@/components/ui/button';
import { Skeleton } from '@/components/ui/skeleton';
import { ResponsiveTable } from '@/components/ui/responsive-table';

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

      <div className="space-y-4">
        <div>
          <h2 className="text-sm font-semibold flex items-center gap-2">
            <AlertTriangle className="h-4 w-4 text-amber-500" />
            Structure Violations
          </h2>
          <p className="text-xs text-muted-foreground mt-0.5">
            {violations.length} violation{violations.length !== 1 ? 's' : ''} found across all exercises.
          </p>
        </div>

        <ResponsiveTable
          columns={[
            { key: 'student', header: 'Student', mobile: 'primary',
              renderCell: (v) => <span className="font-medium">{v.student_name}</span>,
            },
            { key: 'exercise', header: 'Exercise', mobile: 'label',
              renderCell: (v) => <span>{v.exercise_title}</span>,
            },
            { key: 'concept', header: 'Concept', mobile: 'hidden',
              renderCell: (v) => <span>{v.concept_name}</span>,
            },
            { key: 'violation', header: 'Violation', mobile: 'label',
              renderCell: (v) => <span className="max-w-xs truncate block">{v.reason}</span>,
            },
            { key: 'type', header: 'Type', mobile: 'hidden',
              renderCell: (v) => (
                <Badge variant={severityColor(v.severity || 'warning')}>
                  {v.verification_type || 'ast_verifier'}
                </Badge>
              ),
            },
            { key: 'attempt', header: 'Attempt #', mobile: 'hidden',
              renderCell: (v) => <span>{v.attempt_number || '—'}</span>,
            },
            { key: 'date', header: 'Date', mobile: 'hidden',
              renderCell: (v) => (
                <span className="text-xs text-muted-foreground">
                  {v.submitted_at ? new Date(v.submitted_at).toLocaleDateString() : '—'}
                </span>
              ),
            },
          ]}
          data={violations}
          keyExtractor={(v) => v.id ? String(v.id) : `${v.student_name}-${v.exercise_title}-${v.submitted_at || ''}`}
          emptyMessage="No structure violations detected. All submissions passed AST verification."
        />
      </div>
    </div>
  );
}
