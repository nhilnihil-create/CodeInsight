import React, { useEffect, useState, useCallback } from 'react';
import { Link } from 'react-router-dom';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Badge } from '@/components/ui/badge';
import { Table, TableBody, TableCell, TableHead, TableHeader, TableRow } from '@/components/ui/table';
import { Plus, Lock, Unlock, Trash2, ChevronRight, AlertTriangle } from 'lucide-react';
import ExerciseAccordionRow from '@/components/analytics/ExerciseAccordionRow';
import SectionFilter from '@/components/SectionFilter';
import useLastSection from '@/hooks/useLastSection';
import api from '@/services/api';

/**
 * Exercises list — in-row accordion push-down refactor (2026-06-09).
 *
 * Master table with native <tr> accordion expansion: clicking a row
 * toggles a detail <tr> directly beneath it via colSpan={6}.
 * No fixed overlays, no floating blocks — pure table flow.
 */
export default function InstructorExercises() {
  const [sectionId, setSectionId] = useLastSection();
  const [exercises, setExercises] = useState([]);
  const [customTagMap, setCustomTagMap] = useState({});
  const [expandedId, setExpandedId] = useState(null);
  const [busyId, setBusyId] = useState(null);
  const [error, setError] = useState(null);
  const [loading, setLoading] = useState(true);

  const toggleExpand = useCallback((id) => {
    setExpandedId(prev => prev === id ? null : id);
  }, []);

  const fetchExercises = async (secId) => {
    const url = `/api/sections/${secId}/exercises`;
    const res = await api.get(url);
    const list = Array.isArray(res.data) ? res.data : [];
    return list.map(e => ({
      id: e.id,
      title: e.title,
      conceptTags: e.concept_name ? [e.concept_name] : (e.concept_tags || e.conceptTags || []),
      dueDate: e.deadline || e.due_date || e.dueDate,
      isDraft: e.is_draft,
      closedAt: e.closed_at,
      sectionId: e.section_id,
      avg_cds: e.avg_cds ?? e.avgCds,
      submitted_count: e.submitted_count ?? e.submittedCount,
      total_students: e.total_students ?? e.totalStudents,
    }));
  };

  const fetchCustomTags = async (secId) => {
    try {
      const { data } = await api.get(`/api/custom-tags/exercise-mappings?sectionId=${secId}`);
      return data;
    } catch {
      return {};
    }
  };

  const loadAll = async () => {
    try {
      const [list, tagMap] = await Promise.all([
        fetchExercises(sectionId),
        fetchCustomTags(sectionId),
      ]);
      setExercises(list);
      setCustomTagMap(tagMap);
    } catch {
      setExercises([]);
    }
  };

  useEffect(() => {
    let cancelled = false;
    setLoading(true);
    loadAll().finally(() => { if (!cancelled) setLoading(false); });
    return () => { cancelled = true; };
    // eslint-disable-next-line react-hooks/exhaustive-deps
  }, [sectionId]);

  const handleClose = async (e) => {
    setBusyId(e.id); setError(null);
    try {
      await api.post(`/api/exercises/${e.id}/close`);
      await loadAll();
    } catch (err) {
      setError(err.response?.data?.message || err.message);
    } finally { setBusyId(null); }
  };

  const handleReopen = async (e) => {
    setBusyId(e.id); setError(null);
    try {
      await api.post(`/api/exercises/${e.id}/reopen`);
      await loadAll();
    } catch (err) {
      setError(err.response?.data?.message || err.message);
    } finally { setBusyId(null); }
  };

  const handleDelete = async (e) => {
    if (!confirm(`Delete "${e.title}"? This cannot be undone.`)) return;
    setBusyId(e.id); setError(null);
    try {
      await api.delete(`/api/exercises/${e.id}`);
      await loadAll();
    } catch (err) {
      setError(err.response?.data?.message || err.message);
    } finally { setBusyId(null); }
  };

  const sectionForDetail = sectionId;

  return (
    <div className="space-y-6">
      <div className="flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between">
        <div>
          <h1 className="text-3xl font-bold tracking-tight">Exercises</h1>
          <p className="text-muted-foreground">Manage programming assignments and test cases.</p>
        </div>
        <div className="flex flex-col gap-2 sm:flex-row sm:items-center">
          <SectionFilter value={sectionId} onChange={setSectionId} />
          <Button asChild>
            <Link to="/instructor/exercises/new" className="gap-2">
              <Plus className="w-4 h-4" /> Create Exercise
            </Link>
          </Button>
        </div>
      </div>

      {error && (
        <div className="flex items-center gap-3 rounded-lg border border-destructive/30 bg-destructive/5 px-4 py-3">
          <AlertTriangle className="h-4 w-4 text-destructive shrink-0" />
          <p className="text-sm text-destructive flex-1">{error}</p>
          <Button size="sm" variant="ghost" className="text-destructive" onClick={() => setError(null)}>
            Dismiss
          </Button>
        </div>
      )}

      <Card>
        <CardContent className="p-0">
          <Table>
            <TableHeader>
              <TableRow>
                <TableHead className="w-8" />
                <TableHead>Title</TableHead>
                <TableHead>Concepts</TableHead>
                <TableHead>Due</TableHead>
                <TableHead>Status</TableHead>
                <TableHead />
              </TableRow>
            </TableHeader>
            <TableBody>
              {loading ? (
                <TableRow>
                  <TableCell colSpan={6} className="text-center py-12">
                    <div className="animate-spin h-5 w-5 border-2 border-muted-foreground/30 border-t-muted-foreground rounded-full mx-auto mb-3" />
                    <p className="text-sm text-muted-foreground">Loading exercises…</p>
                  </TableCell>
                </TableRow>
              ) : exercises.length === 0 ? (
                <TableRow>
                  <TableCell colSpan={6} className="text-center text-muted-foreground py-6">
                    No exercises found for this selection.
                  </TableCell>
                </TableRow>
              ) : (
                exercises.map((e) => {
                  const isClosed = !!e.closedAt;
                  const isExpanded = expandedId === e.id;
                  return (
                    <React.Fragment key={e.id}>
                      <TableRow
                        className="cursor-pointer transition-colors hover:bg-muted/40"
                        onClick={() => toggleExpand(e.id)}
                      >
                        <TableCell className="w-8 text-muted-foreground">
                          <ChevronRight
                            className={`w-4 h-4 transition-transform duration-200 ${
                              isExpanded ? 'rotate-90 text-primary' : ''
                            }`}
                          />
                        </TableCell>
                        <TableCell className="font-medium">{e.title}</TableCell>
                        <TableCell>
                          <div className="flex gap-1 flex-wrap">
                            {(e.conceptTags || []).map((t) => (
                              <span
                                key={t}
                                className="bg-info/10 text-info border-info/20 px-2 py-0.5 rounded text-xs"
                              >
                                {t}
                              </span>
                            ))}
                            {customTagMap[e.id]?.map((tag) => (
                              <span
                                key={tag.tagId}
                                className="bg-muted/40 text-muted-foreground border-border/30 px-2 py-0.5 rounded text-[10px] border"
                              >
                                {tag.tagName}
                              </span>
                            ))}
                            {(!e.conceptTags || e.conceptTags.length === 0) && (!customTagMap[e.id] || customTagMap[e.id].length === 0) && (
                              <span className="text-xs text-muted-foreground">—</span>
                            )}
                          </div>
                        </TableCell>
                        <TableCell className="text-muted-foreground">
                          {e.dueDate ? new Date(e.dueDate).toLocaleDateString() : '—'}
                        </TableCell>
                        <TableCell>
                          {e.isDraft ? <Badge variant="outline">Draft</Badge>
                            : isClosed ? <Badge className="bg-muted text-muted-foreground border-border">Closed</Badge>
                            : <Badge className="bg-cds-low/10 text-cds-low border-cds-low/15">Open</Badge>}
                        </TableCell>
                        <TableCell className="text-right">
                          <div className="inline-flex gap-1">
                            <Button asChild variant="ghost" size="sm">
                              <Link to={`/instructor/exercises/${e.id}/edit`}>Edit</Link>
                            </Button>
                            {isClosed ? (
                              <Button variant="ghost" size="sm" onClick={(ev) => { ev.stopPropagation(); handleReopen(e); }} disabled={busyId === e.id} title="Reopen exercise" aria-label="Reopen exercise">
                                <Unlock className="w-3.5 h-3.5" />
                              </Button>
                            ) : (
                              <Button variant="ghost" size="sm" onClick={(ev) => { ev.stopPropagation(); handleClose(e); }} disabled={busyId === e.id} title="Close exercise (compute CDS)" aria-label="Close exercise">
                                <Lock className="w-3.5 h-3.5" />
                              </Button>
                            )}
                            <Button variant="ghost" size="sm" onClick={(ev) => { ev.stopPropagation(); handleDelete(e); }} disabled={busyId === e.id} title="Delete exercise" aria-label="Delete exercise" className="text-destructive hover:bg-destructive/10 hover:text-destructive">
                              <Trash2 className="w-3.5 h-3.5" />
                            </Button>
                          </div>
                        </TableCell>
                      </TableRow>

                      {/* Accordion detail row — pushes siblings down via native table flow */}
                      {isExpanded && (
                        <ExerciseAccordionRow
                          exercise={e}
                          sectionId={sectionForDetail}
                          colSpan={6}
                        />
                      )}
                    </React.Fragment>
                  );
                })
              )}
            </TableBody>
          </Table>
        </CardContent>
      </Card>
    </div>
  );
}
