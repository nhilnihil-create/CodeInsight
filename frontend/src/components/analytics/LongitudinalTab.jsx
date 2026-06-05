import React, { useState, useEffect } from 'react';
import { cn } from '@/lib/utils';
import api from '../../services/api';
import LongitudinalProgressChart from './LongitudinalProgressChart';

/**
 * LongitudinalTab — see spec §3 row 5.
 *
 * Ported from hard-coded dark teal hexes to the shadcn semantic token system.
 * The same wrapper now blends into both light and dark themes, matching the
 * `LongitudinalTab` invocation inside `Reports.jsx` (the design-canonical page).
 */
function LongitudinalTab({ sectionId }) {
  const [sectionData, setSectionData] = useState(null);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [selectedStudent, setSelectedStudent] = useState(null);

  useEffect(() => {
    fetchSectionLongitudinal();
  }, [sectionId]);

  const fetchSectionLongitudinal = async () => {
    try {
      setLoading(true);
      const res = await api.get(`/api/analytics/sections/${sectionId}/longitudinal`);
      setSectionData(res.data);
    } catch (err) {
      console.error('Error fetching section longitudinal data:', err);
      setError('Failed to load longitudinal data');
      setSectionData(null);
    } finally {
      setLoading(false);
    }
  };

  if (loading) {
    return (
      <div className="rounded-xl border border-border bg-card p-5 text-center text-sm text-muted-foreground">
        Loading longitudinal data...
      </div>
    );
  }

  if (error) {
    return (
      <div className="rounded-xl border border-destructive/40 bg-destructive/10 p-5 text-center text-sm text-destructive">
        {error}
      </div>
    );
  }

  if (!sectionData || !sectionData.students || sectionData.students.length === 0) {
    return (
      <div className="rounded-xl border border-border bg-card p-5 text-center text-sm text-muted-foreground">
        <div>No student data available for this section</div>
        <div className="mt-2 text-xs">Enroll students and wait for submissions to see progress</div>
      </div>
    );
  }

  const getClassificationTone = (cls) => {
    switch (cls) {
      case 'Low':      return 'bg-emerald-500 text-white';
      case 'Moderate': return 'bg-amber-500 text-white';
      case 'High':     return 'bg-red-500 text-white';
      default:         return 'bg-muted text-muted-foreground';
    }
  };

  const velocityTone = (v) => {
    if (v === 'improving') return 'text-emerald-600 dark:text-emerald-400';
    if (v === 'declining') return 'text-red-600 dark:text-red-400';
    return 'text-muted-foreground';
  };

  return (
    <div className="space-y-4">
      <div className="flex flex-wrap items-center justify-between gap-3 rounded-md border border-border bg-muted/30 px-4 py-3">
        <h3 className="m-0 text-lg font-semibold text-foreground">Longitudinal Reports</h3>
        <div className="flex items-center gap-3">
          <div className="text-xs text-primary">{sectionData.students.length} students</div>
          <select
            value={selectedStudent || ''}
            onChange={(e) => {
              const id = parseInt(e.target.value);
              setSelectedStudent(isNaN(id) ? null : id);
            }}
            className="rounded-md border border-border bg-background px-2.5 py-1 text-xs font-medium text-foreground outline-none focus:border-primary"
          >
            <option value="">All Students (Section Overview)</option>
            {sectionData.students.map(student => (
              <option key={student.studentId} value={student.studentId}>
                {student.studentName}
              </option>
            ))}
          </select>
        </div>
      </div>

      <div className="max-h-[600px] overflow-y-auto p-4">
        {selectedStudent ? (
          <>
            <div className="mb-4 rounded-lg bg-muted px-4 py-3">
              <div className="flex flex-wrap items-center justify-between gap-2">
                <div className="text-sm font-semibold text-foreground">
                  Individual Progress:{' '}
                  {sectionData.students.find(s => s.studentId === selectedStudent)?.studentName ||
                    'Unknown'}
                </div>
                <button
                  type="button"
                  onClick={() => setSelectedStudent(null)}
                  className="rounded px-3 py-1.5 text-xs font-semibold text-primary transition-colors hover:bg-primary/10"
                >
                  Back to Section Overview
                </button>
              </div>
            </div>

            <LongitudinalProgressChart
              data={{
                conceptTimeline: sectionData.students
                  .find(s => s.studentId === selectedStudent)?.progression || [],
                overallProgress: {
                  conceptsResolved: sectionData.students
                    .find(s => s.studentId === selectedStudent)?.progression
                    .filter(p => p.classification === 'Low').length || 0,
                  conceptsAttempted: sectionData.students
                    .find(s => s.studentId === selectedStudent)?.progression.length || 0,
                  resolutionRate: sectionData.students
                    .find(s => s.studentId === selectedStudent)?.progression
                    .filter(p => p.classification === 'Low').length /
                    Math.max(sectionData.students
                      .find(s => s.studentId === selectedStudent)?.progression.length || 1, 1),
                  masteryTrend: sectionData.students
                    .find(s => s.studentId === selectedStudent)?.masteryVelocity || 'stable'
                }
              }}
              studentName={sectionData.students.find(s => s.studentId === selectedStudent)?.studentName}
            />
          </>
        ) : (
          <div className="grid gap-5">
            {/* Section-wide Trends */}
            <div className="overflow-hidden rounded-lg bg-muted">
              <div className="p-4">
                <h4 className="mb-3 text-base font-semibold text-foreground">Section-wide Trends</h4>
                <div className="grid grid-cols-1 gap-4 md:grid-cols-2">
                  {/* Concept Mastery Distribution */}
                  <div>
                    <div className="mb-2 text-xs font-semibold uppercase tracking-wider text-muted-foreground">
                      Concept Mastery Distribution
                    </div>
                    <div className="flex flex-col gap-1.5">
                      {[
                        ['Datatypes',   'bg-emerald-500'],
                        ['Variables',   'bg-emerald-500'],
                        ['Conditionals','bg-amber-500'],
                        ['Loops',       'bg-amber-500'],
                        ['Functions',   'bg-red-500'],
                        ['Arrays',      'bg-red-500'],
                        ['OOP',         'bg-red-600']
                      ].map(([concept, dotClass]) => {
                        const conceptData = sectionData.students.reduce((acc, student) => {
                          const latest = student.progression[student.progression.length - 1];
                          if (latest && latest.concept_name === concept) {
                            return acc + 1;
                          }
                          return acc;
                        }, 0);
                        const totalStudents = sectionData.students.length;
                        const percentage = totalStudents > 0 ? Math.round((conceptData / totalStudents) * 100) : 0;

                        return (
                          <div
                            key={concept}
                            className="flex items-center justify-between rounded-md bg-card px-3 py-2 text-sm"
                          >
                            <span className="text-foreground">{concept}</span>
                            <div className="flex items-center gap-2 text-xs text-muted-foreground">
                              <span className={cn('inline-block h-2.5 w-2.5 rounded-full', dotClass)} />
                              <span>{percentage}% ({conceptData}/{totalStudents})</span>
                            </div>
                          </div>
                        );
                      })}
                    </div>
                  </div>

                  {/* Mastery Velocity Overview */}
                  <div>
                    <div className="mb-2 text-xs font-semibold uppercase tracking-wider text-muted-foreground">
                      Mastery Velocity Distribution
                    </div>
                    <div className="flex flex-col gap-1.5">
                      {[
                        ['Improving', 'bg-emerald-500'],
                        ['Stable',    'bg-muted-foreground'],
                        ['Declining', 'bg-red-500']
                      ].map(([velocity, dotClass]) => {
                        const count = sectionData.students.filter(s => s.masteryVelocity === velocity.toLowerCase()).length;
                        const percentage = sectionData.students.length > 0 ? Math.round((count / sectionData.students.length) * 100) : 0;

                        return (
                          <div
                            key={velocity}
                            className="flex items-center justify-between rounded-md bg-card px-3 py-2 text-sm"
                          >
                            <span className="text-foreground">{velocity}</span>
                            <div className="flex items-center gap-2 text-xs text-muted-foreground">
                              <span className={cn('inline-block h-2.5 w-2.5 rounded-full', dotClass)} />
                              <span>{percentage}% ({count}/{sectionData.students.length})</span>
                            </div>
                          </div>
                        );
                      })}
                    </div>
                  </div>
                </div>
              </div>
            </div>

            {/* Student Roster Timeline */}
            <div className="overflow-hidden rounded-lg bg-muted">
              <div className="border-b border-border p-4">
                <h4 className="m-0 text-base font-semibold text-foreground">Student Progress Timeline</h4>
              </div>
              <div className="max-h-[400px] overflow-y-auto p-4">
                {sectionData.students.map((student) => {
                  const latest = student.progression[student.progression.length - 1];
                  const classification = latest ? latest.classification : 'Unscored';
                  const initials = {
                    Low: 'L', Moderate: 'M', High: 'H', Unscored: '?'
                  }[classification] || '?';

                  return (
                    <div
                      key={student.studentId}
                      className="flex items-center justify-between border-b border-border/60 py-3 last:border-0"
                    >
                      <div className="flex items-center gap-3">
                        <div
                          className={cn(
                            'flex h-9 w-9 items-center justify-center rounded-full text-sm font-semibold',
                            getClassificationTone(classification)
                          )}
                        >
                          {initials}
                        </div>
                        <div>
                          <div className="text-sm font-semibold text-foreground">
                            {student.studentName}
                          </div>
                          <div className="text-xs text-muted-foreground">
                            {student.progression.length} exercises attempted
                          </div>
                        </div>
                      </div>
                      <div className="flex items-center gap-2 text-xs text-muted-foreground">
                        <div>Velocity:</div>
                        <span className={cn('font-semibold', velocityTone(student.masteryVelocity))}>
                          {student.masteryVelocity.charAt(0).toUpperCase() +
                            student.masteryVelocity.slice(1)}
                        </span>
                      </div>
                    </div>
                  );
                })}
              </div>
            </div>
          </div>
        )}
      </div>
    </div>
  );
}

export default LongitudinalTab;
