import React, { useState, useEffect } from 'react';
import { useNavigate, useParams } from 'react-router-dom';
import {
  ChevronLeft,
  ShieldAlert,
  Filter,
  XCircle,
  Loader2,
} from 'lucide-react';
import api from '../../services/api';
import IntegrityFlagBadge from '../../components/IntegrityFlagBadge';
import {
  Card,
  CardContent,
  CardHeader,
  CardTitle,
  CardDescription,
} from '@/components/ui/card';
import { Badge } from '@/components/ui/badge';
import { Button } from '@/components/ui/button';
import { Skeleton } from '@/components/ui/skeleton';
import { Input } from '@/components/ui/input';
import { ResponsiveTable } from '@/components/ui/responsive-table';
import {
  Dialog,
  DialogContent,
  DialogDescription,
  DialogFooter,
  DialogHeader,
  DialogTitle,
} from '@/components/ui/dialog';
import {
  Select,
  SelectContent,
  SelectItem,
  SelectTrigger,
  SelectValue,
} from '@/components/ui/select';
import { Label } from '@/components/ui/label';

/**
 * Academic Integrity Flags
 *
 * PRESERVED FUNCTIONALITY (do not regress):
 *   - GET /api/analytics/sections/:sectionId/integrity-flags
 *     query: flag_type, student_id, exercise_id, page, limit
 *   - PUT /api/analytics/integrity-flags/:id/review
 *     body: { status, instructor_note }
 *   - Filters: flag_type (HARDCODING | BLANK_TEMPLATE | BEHAVIORAL_ANOMALY |
 *             CODE_GROWTH_ANOMALY | PASSIVE_BEHAVIOR_LOG), student_id, exercise_id
 *   - Pagination: page, limit, total, totalPages
 *   - Status: FLAGGED, REVIEWED, DISMISSED
 *   - Severity: HIGH, MEDIUM, LOW
 *   - Local IntegrityNoteModal with Status select + Instructor Note textarea
 *   - Review → open modal, Dismiss → open modal pre-set to DISMISSED
 *   - Clear Filters resets all 3 filter inputs and returns to page 1
 *   - "Back to Section" navigates to /instructor/sections/:sectionId
 *
 * REPLACED (visual layer only):
 *   - Legacy `btn-secondary` / `btn-outline` / dark-hex inline styles →
 *     shadcn Button, Card, Badge, Skeleton, Input, Dialog, Select, Table
 *   - Raw <select> for filter dropdown → Radix Select
 *   - Local "modal" wrapper → Radix Dialog
 *   - Inline tailwind severity colors → shadcn Badge variants
 *     (HIGH → destructive, MEDIUM → warning, LOW → success)
 *   - Status badge colors → Badge variants
 *     (FLAGGED → warning, REVIEWED → success, DISMISSED → secondary)
 */

const FLAG_TYPES = [
  { value: 'HARDCODING', label: 'Hardcoding Detection' },
  { value: 'BLANK_TEMPLATE', label: 'Blank/Template-only Submission' },
  { value: 'BEHAVIORAL_ANOMALY', label: 'Behavioral Anomaly' },
  { value: 'CODE_GROWTH_ANOMALY', label: 'Code Growth Anomaly' },
  { value: 'PASSIVE_BEHAVIOR_LOG', label: 'Contextual Activity' },
];

const SEVERITY_VARIANT = {
  HIGH: 'destructive',
  MEDIUM: 'warning',
  LOW: 'success',
};

const STATUS_VARIANT = {
  FLAGGED: 'warning',
  REVIEWED: 'success',
  DISMISSED: 'secondary',
};

const STATUS_LABEL = {
  FLAGGED: 'Flagged',
  REVIEWED: 'Reviewed',
  DISMISSED: 'Dismissed',
};

const AcademicIntegrityFlags = () => {
  const { sectionId } = useParams();
  const navigate = useNavigate();

  const [flags, setFlags] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [filters, setFilters] = useState({
    flag_type: '',
    student_id: '',
    exercise_id: '',
  });
  const [pagination, setPagination] = useState({
    page: 1,
    limit: 50,
    total: 0,
    totalPages: 0,
  });
  const [selectedFlag, setSelectedFlag] = useState(null);
  const [showNoteModal, setShowNoteModal] = useState(false);

  useEffect(() => {
    const loadFlags = async () => {
      try {
        setLoading(true);
        const params = new URLSearchParams();
        if (filters.flag_type) params.append('flag_type', filters.flag_type);
        if (filters.student_id) params.append('student_id', filters.student_id);
        if (filters.exercise_id) params.append('exercise_id', filters.exercise_id);
        params.append('page', pagination.page);
        params.append('limit', pagination.limit);

        const response = await api.get(
          `/api/analytics/sections/${sectionId}/integrity-flags?${params.toString()}`,
        );
        setFlags(response.data.flags);
        setPagination(response.data.pagination);
        setLoading(false);
      } catch (err) {
        setError(err.response?.data?.message || 'Failed to load integrity flags');
        setLoading(false);
      }
    };

    if (sectionId) {
      loadFlags();
    }
  }, [sectionId, filters, pagination.page, pagination.limit]);

  const handleFilterChange = (e) => {
    const { name, value } = e.target;
    setFilters((prev) => ({ ...prev, [name]: value }));
    setPagination((prev) => ({ ...prev, page: 1 }));
  };

  const handleFilterSelectChange = (value) => {
    setFilters((prev) => ({ ...prev, flag_type: value === '__all__' ? '' : value }));
    setPagination((prev) => ({ ...prev, page: 1 }));
  };

  const handlePageChange = (page) => {
    setPagination((prev) => ({ ...prev, page }));
  };

  const handleReviewFlag = (flag) => {
    setSelectedFlag(flag);
    setShowNoteModal(true);
  };

  const handleNoteModalClose = () => {
    setSelectedFlag(null);
    setShowNoteModal(false);
  };

  const handleNoteModalSubmit = async (updatedFlag) => {
    try {
      await api.put(`/api/analytics/integrity-flags/${updatedFlag.id}/review`, {
        status: updatedFlag.status,
        instructor_note: updatedFlag.instructor_note,
      });
      setFlags((prevFlags) =>
        prevFlags.map((flag) => (flag.id === updatedFlag.id ? updatedFlag : flag)),
      );
      setShowNoteModal(false);
      setSelectedFlag(null);
    } catch (err) {
      console.error('Failed to update integrity flag:', err);
    }
  };

  // Loading state
  if (loading) {
    return (
      <div className="space-y-6 p-6 lg:p-10">
        <div className="flex items-center gap-3">
          <Button
            variant="ghost"
            size="icon"
            onClick={() => navigate(`/instructor/sections/${sectionId}`)}
            aria-label="Back to section"
          >
            <ChevronLeft className="h-4 w-4" />
          </Button>
          <div>
            <h1 className="text-3xl font-bold tracking-tight">Academic Integrity Flags</h1>
            <p className="text-sm text-muted-foreground">
              Monitoring submissions for potential academic integrity concerns
            </p>
          </div>
        </div>
        <Skeleton className="h-24 w-full" />
        <Skeleton className="h-64 w-full" />
      </div>
    );
  }

  // Error state
  if (error) {
    return (
      <div className="space-y-6 p-6 lg:p-10">
        <div className="flex items-center gap-3">
          <Button
            variant="ghost"
            size="icon"
            onClick={() => navigate(`/instructor/sections/${sectionId}`)}
            aria-label="Back to section"
          >
            <ChevronLeft className="h-4 w-4" />
          </Button>
          <h1 className="text-3xl font-bold tracking-tight">Academic Integrity Flags</h1>
        </div>
        <Card className="border-destructive/30 bg-destructive/5">
          <CardContent className="flex items-center gap-3 p-4 text-sm text-destructive">
            <XCircle className="h-5 w-5" />
            {error}
          </CardContent>
        </Card>
      </div>
    );
  }

  const totalShown =
    pagination.total > 0
      ? `${(pagination.page - 1) * pagination.limit + 1}–${Math.min(
          pagination.page * pagination.limit,
          pagination.total,
        )} of ${pagination.total}`
      : '0 of 0';

  return (
    <div className="space-y-6 p-6 lg:p-10">
      {/* Header */}
      <div className="flex flex-wrap items-start justify-between gap-3">
        <div className="flex items-center gap-3">
          <Button
            variant="ghost"
            size="icon"
            onClick={() => navigate(`/instructor/sections/${sectionId}`)}
            aria-label="Back to section"
          >
            <ChevronLeft className="h-4 w-4" />
          </Button>
          <div>
            <h1 className="flex items-center gap-2 text-3xl font-bold tracking-tight">
              <ShieldAlert className="h-6 w-6 text-destructive" />
              Academic Integrity Flags
            </h1>
            <p className="text-sm text-muted-foreground">
              Monitoring submissions for potential academic integrity concerns
            </p>
          </div>
        </div>
        <Button
          variant="outline"
          onClick={() => navigate(`/instructor/sections/${sectionId}`)}
        >
          Back to Section
        </Button>
      </div>

      {/* Filters */}
      <Card>
        <CardHeader className="pb-3">
          <CardTitle className="flex items-center gap-2 text-sm">
            <Filter className="h-4 w-4" /> Filters
          </CardTitle>
        </CardHeader>
        <CardContent>
          <div className="grid gap-4 md:grid-cols-3">
            <div className="space-y-1.5">
              <Label htmlFor="flag_type" className="text-xs font-semibold uppercase tracking-wider">
                Flag Type
              </Label>
              <Select
                value={filters.flag_type || '__all__'}
                onValueChange={handleFilterSelectChange}
              >
                <SelectTrigger id="flag_type">
                  <SelectValue placeholder="All Flag Types" />
                </SelectTrigger>
                <SelectContent>
                  <SelectItem value="__all__">All Flag Types</SelectItem>
                  {FLAG_TYPES.map((t) => (
                    <SelectItem key={t.value} value={t.value}>
                      {t.label}
                    </SelectItem>
                  ))}
                </SelectContent>
              </Select>
            </div>
            <div className="space-y-1.5">
              <Label htmlFor="student_id" className="text-xs font-semibold uppercase tracking-wider">
                Student ID
              </Label>
              <Input
                id="student_id"
                type="number"
                name="student_id"
                value={filters.student_id || ''}
                onChange={handleFilterChange}
                placeholder="Filter by student ID"
              />
            </div>
            <div className="space-y-1.5">
              <Label htmlFor="exercise_id" className="text-xs font-semibold uppercase tracking-wider">
                Exercise ID
              </Label>
              <Input
                id="exercise_id"
                type="number"
                name="exercise_id"
                value={filters.exercise_id || ''}
                onChange={handleFilterChange}
                placeholder="Filter by exercise ID"
              />
            </div>
          </div>

          <div className="mt-4 flex justify-end">
            <Button
              variant="ghost"
              size="sm"
              onClick={() => {
                setFilters({ flag_type: '', student_id: '', exercise_id: '' });
                setPagination((prev) => ({ ...prev, page: 1 }));
              }}
            >
              Clear Filters
            </Button>
          </div>
        </CardContent>
      </Card>

      {/* Flags table */}
      <div className="flex items-center justify-between mb-3">
        <div>
          <h2 className="text-lg font-semibold">Flags</h2>
          <p className="text-sm text-muted-foreground">
            {flags.length} {flags.length === 1 ? 'flag' : 'flags'} on this page
          </p>
        </div>
      </div>

      <ResponsiveTable
        columns={[
          {
            key: 'student_name',
            header: 'Student',
            mobile: 'primary',
            renderCell: (flag) => (
              <span className="font-medium text-foreground">{flag.student_name || 'Unknown Student'}</span>
            ),
          },
          { key: 'exercise_title', header: 'Exercise', mobile: 'hidden',
            renderCell: (flag) => <span className="text-muted-foreground">{flag.exercise_title || 'Unknown Exercise'}</span>,
          },
          {
            key: 'flag_type',
            header: 'Flag Type',
            mobile: 'label',
            renderCell: (flag) => <IntegrityFlagBadge flagType={flag.flag_type} />,
            renderMobileCell: (flag) => {
              const labels = { HARDCODING: 'HC', BLANK_TEMPLATE: 'BT', BEHAVIORAL_ANOMALY: 'BA', CODE_GROWTH_ANOMALY: 'CG', PASSIVE_BEHAVIOR_LOG: 'CA' };
              return <span className="text-xs font-medium">{labels[flag.flag_type] || flag.flag_type}</span>;
            },
          },
          {
            key: 'severity',
            header: 'Severity',
            mobile: 'label',
            renderCell: (flag) => {
              const severityVariant = SEVERITY_VARIANT[flag.severity] || 'outline';
              return <Badge variant={severityVariant}>{flag.severity}</Badge>;
            },
            renderMobileCell: (flag) => {
              const colors = { HIGH: 'text-destructive', MEDIUM: 'text-warning', LOW: 'text-success' };
              return <span className={`font-semibold ${colors[flag.severity] || ''}`}>{flag.severity}</span>;
            },
          },
          {
            key: 'evidence',
            header: 'Evidence',
            mobile: 'hidden',
            renderCell: (flag) => {
              const evidenceText = flag.evidence
                ? JSON.stringify(flag.evidence).substring(0, 50) + '...'
                : 'No evidence';
              return <span className="max-w-xs truncate text-xs text-muted-foreground">{evidenceText}</span>;
            },
          },
          {
            key: 'status',
            header: 'Status',
            mobile: 'label',
            renderCell: (flag) => {
              const statusVariant = STATUS_VARIANT[flag.status] || 'outline';
              return <Badge variant={statusVariant}>{STATUS_LABEL[flag.status] || flag.status}</Badge>;
            },
            renderMobileCell: (flag) => {
              const colors = { FLAGGED: 'text-warning', REVIEWED: 'text-success', DISMISSED: 'text-muted-foreground' };
              return <span className={`font-semibold ${colors[flag.status] || ''}`}>{STATUS_LABEL[flag.status] || flag.status}</span>;
            },
          },
          {
            key: 'actions',
            header: 'Actions',
            mobile: 'actions',
            renderCell: (flag) => (
              <div className="flex justify-end gap-2">
                <Button
                  variant="outline"
                  size="sm"
                  onClick={(e) => { e.stopPropagation(); handleReviewFlag(flag); }}
                  disabled={flag.status === 'REVIEWED' || flag.status === 'DISMISSED'}
                >
                  {flag.status === 'FLAGGED' ? 'Review' : 'View'}
                </Button>
                {flag.status === 'FLAGGED' && (
                  <Button
                    variant="ghost"
                    size="sm"
                    className="text-destructive hover:bg-destructive/10 hover:text-destructive"
                    onClick={(e) => { e.stopPropagation(); handleReviewFlag({ ...flag, status: 'DISMISSED' }); }}
                  >
                    Dismiss
                  </Button>
                )}
              </div>
            ),
            renderMobileCell: (flag) => (
              <div className="flex gap-2 w-full">
                <Button
                  variant="outline"
                  size="sm"
                  className="flex-1 text-xs"
                  onClick={(e) => { e.stopPropagation(); handleReviewFlag(flag); }}
                  disabled={flag.status === 'REVIEWED' || flag.status === 'DISMISSED'}
                >
                  {flag.status === 'FLAGGED' ? 'Review' : 'View'}
                </Button>
                {flag.status === 'FLAGGED' && (
                  <Button
                    variant="ghost"
                    size="sm"
                    className="flex-1 text-xs text-destructive"
                    onClick={(e) => { e.stopPropagation(); handleReviewFlag({ ...flag, status: 'DISMISSED' }); }}
                  >
                    Dismiss
                  </Button>
                )}
              </div>
            ),
          },
        ]}
        data={flags}
        keyExtractor={(flag) => String(flag.id)}
        emptyMessage="No integrity flags found matching the current filters."
      />

      {pagination.total > pagination.limit && (
        <div className="flex items-center justify-between gap-2 mt-4 text-xs text-muted-foreground">
          <span>Showing {totalShown} flags</span>
          <div className="flex gap-2">
            <Button
              variant="outline"
              size="sm"
              onClick={() => handlePageChange(Math.max(1, pagination.page - 1))}
              disabled={pagination.page === 1}
            >
              Previous
            </Button>
            <Button
              variant="outline"
              size="sm"
              onClick={() =>
                handlePageChange(Math.min(pagination.totalPages, pagination.page + 1))
              }
              disabled={pagination.page === pagination.totalPages}
            >
              Next
            </Button>
          </div>
        </div>
      )}
      {showNoteModal && selectedFlag && (
        <IntegrityNoteModal
          flag={selectedFlag}
          onClose={handleNoteModalClose}
          onSubmit={handleNoteModalSubmit}
        />
      )}
    </div>
  );
};

// Modal for instructor notes — uses Radix Dialog (shadcn-styled) but
// preserves the local-React-component contract that the rest of the file
// relies on (controlled by showNoteModal/selectedFlag in the parent).
const IntegrityNoteModal = ({ flag, onClose, onSubmit }) => {
  const [note, setNote] = useState(flag.instructor_note || '');
  const [status, setStatus] = useState(flag.status || 'FLAGGED');
  const [submitting, setSubmitting] = useState(false);

  const handleSubmit = async (e) => {
    e.preventDefault();
    setSubmitting(true);
    try {
      await onSubmit({ ...flag, instructor_note: note, status });
    } finally {
      setSubmitting(false);
    }
  };

  return (
    <Dialog open onOpenChange={(open) => !open && onClose()}>
      <DialogContent>
        <DialogHeader>
          <DialogTitle>
            {flag.status === 'FLAGGED' ? 'Review Integrity Flag' : 'View Integrity Flag'}
          </DialogTitle>
          <DialogDescription>
            Add a note and update the review status. Notes are visible to other instructors.
          </DialogDescription>
        </DialogHeader>
        <form onSubmit={handleSubmit} className="space-y-4">
          <div className="space-y-1.5">
            <Label htmlFor="status" className="text-xs font-semibold uppercase tracking-wider">
              Status
            </Label>
            <Select value={status} onValueChange={setStatus}>
              <SelectTrigger id="status">
                <SelectValue />
              </SelectTrigger>
              <SelectContent>
                <SelectItem value="FLAGGED">Flagged</SelectItem>
                <SelectItem value="REVIEWED">Reviewed</SelectItem>
                <SelectItem value="DISMISSED">Dismissed</SelectItem>
              </SelectContent>
            </Select>
          </div>

          <div className="space-y-1.5">
            <Label htmlFor="note" className="text-xs font-semibold uppercase tracking-wider">
              Instructor Note
            </Label>
            <textarea
              id="note"
              value={note}
              onChange={(e) => setNote(e.target.value)}
              rows={5}
              className="flex w-full rounded-md border border-input bg-background px-3 py-2 text-sm ring-offset-background placeholder:text-muted-foreground focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-ring focus-visible:ring-offset-2"
              placeholder="Add notes about your review or actions taken..."
            />
          </div>

          <DialogFooter>
            <Button type="button" variant="outline" onClick={onClose} disabled={submitting}>
              Cancel
            </Button>
            <Button type="submit" disabled={submitting}>
              {submitting ? (
                <>
                  <Loader2 className="mr-2 h-4 w-4 animate-spin" /> Saving…
                </>
              ) : flag.status === 'FLAGGED' ? (
                'Save Review'
              ) : (
                'Update'
              )}
            </Button>
          </DialogFooter>
        </form>
      </DialogContent>
    </Dialog>
  );
};

export default AcademicIntegrityFlags;
