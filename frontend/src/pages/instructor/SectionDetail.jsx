import { useState, useEffect } from 'react';
import { useParams, Link, useNavigate } from 'react-router-dom';
import {
  UserPlus, Plus, Search, Trash2, AlertTriangle, Copy, RotateCw,
  CheckCircle2, XCircle, Shield, Users, BarChart3, Clock, KeyRound,
  QrCode, ChevronRight, ChevronDown, UserCheck, UserX, Eye,
} from 'lucide-react';
import api from '../../services/api';
import EnrollStudentsModal from '../../components/EnrollStudentsModal';
import StudentAlertCard from '../../components/analytics/StudentAlertCard';
import ExerciseAccordion from '../../components/analytics/ExerciseAccordion';
import ClassWideLongitudinalChart from '../../components/analytics/ClassWideLongitudinalChart';
import ResponsiveLineChart from '../../components/charts/ResponsiveLineChart';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Tabs, TabsList, TabsTrigger, TabsContent } from '@/components/ui/tabs';
import { Button } from '@/components/ui/button';
import { Input } from '@/components/ui/input';
import { Badge } from '@/components/ui/badge';
import { cn } from '@/lib/utils';

function SectionMostDifficultConcepts({ sectionId }) {
  const [concepts, setConcepts] = useState([]);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    let cancelled = false;
    const load = async () => {
      try {
        const res = await api.get(`/api/analytics/heatmap/${sectionId}`);
        const scores = res.data?.scores || {};
        const totals = {};
        const counts = {};
        for (const studentId in scores) {
          for (const concept in scores[studentId]) {
            const cds = scores[studentId][concept]?.cds;
            const num = typeof cds === 'string' ? parseFloat(cds) : cds;
            if (typeof num === 'number' && !isNaN(num)) {
              totals[concept] = (totals[concept] || 0) + num;
              counts[concept] = (counts[concept] || 0) + 1;
            }
          }
        }
        const rows = Object.keys(totals).map((concept) => {
          const avg = totals[concept] / counts[concept];
          return { concept, score: Math.round(avg * 100), difficulty: avg <= 0.33 ? 'low' : avg <= 0.66 ? 'moderate' : 'high' };
        });
        if (!cancelled) {
          rows.sort((a, b) => a.score - b.score);
          setConcepts(rows);
          setLoading(false);
        }
      } catch (err) {
        if (!cancelled) { setConcepts([]); setLoading(false); }
      }
    };
    load();
    return () => { cancelled = true; };
  }, [sectionId]);

  if (loading) return <div className="rounded-md border border-border bg-muted/30 p-6 text-center text-sm text-muted-foreground">Loading concept difficulty…</div>;
  if (concepts.length === 0) return <div className="rounded-md border border-border bg-muted/30 p-6 text-center text-sm text-muted-foreground">No concept-level data yet.</div>;

  return (
    <ul className="divide-y divide-border rounded-md border border-border">
      {concepts.map((row) => {
        const tone = row.difficulty === 'low' ? 'bg-emerald-500' : row.difficulty === 'moderate' ? 'bg-amber-500' : 'bg-red-500';
        return (
          <li key={row.concept} className="flex items-center justify-between px-4 py-3">
            <div className="flex items-center gap-3">
              <span className={cn('inline-block h-2.5 w-2.5 rounded-full', tone)} />
              <span className="text-sm font-semibold text-foreground">{row.concept}</span>
            </div>
            <div className="flex items-center gap-3 text-xs text-muted-foreground">
              <span className="font-mono text-sm font-bold text-foreground">{row.score}</span>
              <span>avg CDS</span>
            </div>
          </li>
        );
      })}
    </ul>
  );
}

function SectionClassTrendChart({ sectionId }) {
  const [data, setData] = useState([]);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    let cancelled = false;
    const load = async () => {
      try {
        const res = await api.get(`/api/analytics/sections/${sectionId}/longitudinal`);
        const students = res.data?.students || [];
        const weekBuckets = {};
        for (const student of students) {
          for (const point of student.progression || []) {
            const ts = point.computed_at;
            const cds = typeof point.cds === 'string' ? parseFloat(point.cds) : point.cds;
            if (!ts || typeof cds !== 'number' || isNaN(cds)) continue;
            const key = isoWeekLabel(ts);
            if (!weekBuckets[key]) weekBuckets[key] = { sum: 0, count: 0, ts: 0 };
            weekBuckets[key].sum += cds;
            weekBuckets[key].count += 1;
            weekBuckets[key].ts = Math.max(weekBuckets[key].ts, new Date(ts).getTime());
          }
        }
        const series = Object.keys(weekBuckets).map((key) => {
          const { sum, count, ts } = weekBuckets[key];
          return { x: key, y: sum / count, _ts: ts };
        }).sort((a, b) => a._ts - b._ts).map(({ x, y }) => ({ x, y }));
        if (!cancelled) { setData(series); setLoading(false); }
      } catch (err) {
        if (!cancelled) { setData([]); setLoading(false); }
      }
    };
    load();
    return () => { cancelled = true; };
  }, [sectionId]);

  if (loading) return <div className="flex h-72 items-center justify-center rounded-md border border-border bg-muted/30 text-sm text-muted-foreground">Loading class trend…</div>;
  return <ResponsiveLineChart data={data} yDomain={[0, 1]} yFmt={(v) => v.toFixed(2)} emptyMessage="No class trend data yet." />;
}

function isoWeekLabel(iso) {
  const d = new Date(iso);
  if (isNaN(d.getTime())) return 'Wk ?';
  const start = new Date(d.getFullYear(), 0, 1);
  const diff = (d - start) / (1000 * 60 * 60 * 24);
  const wk = Math.floor(diff / 7) + 1;
  return `Wk ${wk}`;
}

const POLICY_COLORS = {
  code: 'text-[#22C55E] bg-[#22C55E]/10 border-[#22C55E]/30',
  request: 'text-[#FACC15] bg-[#FACC15]/10 border-[#FACC15]/30',
  closed: 'text-[#EF4444] bg-[#EF4444]/10 border-[#EF4444]/30',
};

export default function SectionDetail() {
  const { sectionId } = useParams();
  const [section, setSection] = useState(null);
  const [students, setStudents] = useState([]);
  const [exercises, setExercises] = useState([]);
  const [heatmapData, setHeatmapData] = useState(null);
  const [alerts, setAlerts] = useState([]);
  const [loading, setLoading] = useState(true);
  const [activeTab, setActiveTab] = useState('hub');
  const [searchQuery, setSearchQuery] = useState('');
  const [showDeleteConfirm, setShowDeleteConfirm] = useState(false);
  const [selectedExercise, setSelectedExercise] = useState(null);
  const [showEnrollModal, setShowEnrollModal] = useState(false);
  const [liveCDSExerciseId, setLiveCDSExerciseId] = useState(null);
  const [rotating, setRotating] = useState(false);
  const [copied, setCopied] = useState(false);
  const navigate = useNavigate();

  const CONCEPT_ORDER = ['Datatypes','Variables','Conditionals','Loops','Functions','Arrays','OOP'];

  useEffect(() => { fetchSectionData(); }, [sectionId]);

  const fetchSectionData = async () => {
    try {
      const [secRes, studRes, exRes, heatRes, alertRes] = await Promise.all([
        api.get(`/api/sections/${sectionId}`),
        api.get(`/api/sections/${sectionId}/students-with-scores`),
        api.get(`/api/sections/${sectionId}/exercises`),
        api.get(`/api/analytics/heatmap/${sectionId}`),
        api.get(`/api/analytics/sections/${sectionId}/integrity-flags`)
      ]);
      setSection(secRes.data);
      setStudents(studRes.data || []);
      setExercises(exRes.data || []);
      setHeatmapData(heatRes.data);
      setAlerts(alertRes.data || []);
    } catch (err) {
      console.error('Error fetching section data:', err);
    } finally {
      setLoading(false);
    }
  };

  const formatCDS = (value) => {
    if (value === null || value === undefined) return '—';
    const num = typeof value === 'string' ? parseFloat(value) : value;
    return isNaN(num) ? '—' : num.toFixed(2);
  };

  const getDifficulty = (cds) => {
    if (cds === null || cds === undefined) return 'unscored';
    if (cds <= 0.33) return 'low';
    if (cds <= 0.66) return 'moderate';
    return 'high';
  };

  const DIFFICULTY_TONE = {
    low:       'text-emerald-700 bg-emerald-100 border-emerald-200 dark:text-emerald-300 dark:bg-emerald-950/40 dark:border-emerald-900',
    moderate:  'text-amber-700 bg-amber-100 border-amber-200 dark:text-amber-300 dark:bg-amber-950/40 dark:border-amber-900',
    high:      'text-red-700 bg-red-100 border-red-200 dark:text-red-300 dark:bg-red-950/40 dark:border-red-900',
    unscored:  'text-muted-foreground bg-muted border-border',
  };

  const DIFFICULTY_DOT = { low: 'bg-emerald-500', moderate: 'bg-amber-500', high: 'bg-red-500' };

  const getTotalAlerts = () => alerts.length;
  const getCompletionPercentage = () => {
    if (section && typeof section.exercise_count !== 'undefined' && typeof section.completed_exercises !== 'undefined') {
      const total = parseInt(section.exercise_count || 0, 10) || 0;
      const done = parseInt(section.completed_exercises || 0, 10) || 0;
      return total > 0 ? Math.round((done / total) * 100) : 0;
    }
    if (!exercises.length) return 0;
    const totalPossible = exercises.reduce((sum, ex) => sum + (parseInt(ex.submitted_count || 0, 10) || 0), 0);
    const totalNeeded = exercises.reduce((sum, ex) => sum + (parseInt(ex.total_students || 0, 10) || 0), 0);
    return totalNeeded > 0 ? Math.round((totalPossible / totalNeeded) * 100) : 0;
  };

  const getAvgCDS = () => {
    if (!heatmapData?.scores) return 0;
    const allScores = [];
    for (const student in heatmapData.scores) {
      for (const concept in heatmapData.scores[student]) {
        const score = heatmapData.scores[student][concept];
        if (score?.cds) {
          const cds = typeof score.cds === 'string' ? parseFloat(score.cds) : score.cds;
          if (!isNaN(cds)) allScores.push(cds);
        }
      }
    }
    if (allScores.length === 0) return 0;
    return (allScores.reduce((a, b) => a + b, 0) / allScores.length).toFixed(2);
  };

  const filteredStudents = students.filter(s =>
    s.name.toLowerCase().includes(searchQuery.toLowerCase()) ||
    s.email.toLowerCase().includes(searchQuery.toLowerCase())
  );

  const handleEditExercise = (exercise) => { navigate(`/instructor/exercises/${exercise.id}/edit`); };

  const handleDeleteExercise = async (exercise) => {
    if (showDeleteConfirm && selectedExercise?.id === exercise.id) {
      try {
        await api.delete(`/api/exercises/${exercise.id}`);
        setExercises(exercises.filter(e => e.id !== exercise.id));
        setShowDeleteConfirm(false);
        setSelectedExercise(null);
      } catch (err) {
        console.error(err);
        alert('Failed to delete exercise');
      }
    } else {
      setShowDeleteConfirm(true);
      setSelectedExercise(exercise);
    }
  };

  const handleToggleExerciseStatus = async (exercise) => {
    try {
      const endpoint = exercise.closed_at ? 'reopen' : 'close';
      await api.post(`/api/exercises/${exercise.id}/${endpoint}`, {});
      await fetchSectionData();
    } catch (err) {
      console.error(err);
      alert('Failed to update exercise status');
    }
  };

  const handleCopyCode = () => {
    if (section?.code) {
      navigator.clipboard.writeText(section.code);
      setCopied(true);
      setTimeout(() => setCopied(false), 2000);
    }
  };

  const handleRotateCode = async () => {
    setRotating(true);
    try {
      const res = await api.post(`/api/sections/${sectionId}/rotate-code`);
      setSection(prev => ({ ...prev, code: res.data.code }));
    } catch (err) {
      console.error('Failed to rotate code:', err);
    } finally {
      setTimeout(() => setRotating(false), 600);
    }
  };

  if (loading) return <div className="p-10 text-center text-muted-foreground">Loading section details...</div>;
  if (!section) return <div className="p-10 text-center text-muted-foreground">Section not found</div>;

  const avgCDSDiff = getDifficulty(parseFloat(getAvgCDS()));
  const studentCount = section.student_count || students.length;
  const alertCount = getTotalAlerts();
  const completionPct = getCompletionPercentage();

  const tabs = [
    { id: 'hub', label: 'Hub', count: null },
    { id: 'roster', label: 'Roster', count: studentCount },
    { id: 'join-requests', label: 'Join requests', count: 3 },
    { id: 'codes', label: 'Codes & policy', count: null },
    { id: 'tas', label: 'TAs', count: 1 },
    { id: 'audit', label: 'Audit log', count: null },
  ];

  return (
    <div className="space-y-5">
      {/* Purple chip header — spec §11.9B */}
      <div className="flex flex-col gap-4 rounded-xl border border-[#A855F7]/30 bg-gradient-to-r from-[#A855F7]/10 to-[#7C3AED]/10 p-5 sm:flex-row sm:items-start sm:justify-between">
        <div className="flex-1">
          <Badge variant="secondary" className="mb-2 inline-flex items-center gap-1 border-[#A855F7]/30 bg-[#A855F7]/10 text-[10px] text-[#A855F7]">
            <Shield className="h-3 w-3" /> Instructor · {section.school_year || 'AY 2025–2026'}
          </Badge>
          <h2 className="text-xl font-bold text-foreground">{section.name}</h2>
          <div className="mt-1 flex flex-wrap items-center gap-3 text-xs text-muted-foreground">
            <span className="flex items-center gap-1"><Users className="h-3 w-3" /> {studentCount} students</span>
            <span className="flex items-center gap-1"><BarChart3 className="h-3 w-3" /> {exercises.length} exercises</span>
            <span className="flex items-center gap-1"><Clock className="h-3 w-3" /> {section.semester || 'Sem 1'}</span>
            <Badge variant="outline" className={cn('text-[9px] px-1.5 py-0', POLICY_COLORS[section.join_policy] || '')}>
              {section.join_policy || 'code'}
            </Badge>
          </div>
        </div>
        <div className="flex shrink-0 gap-2">
          <Button variant="outline" size="sm" onClick={() => setShowEnrollModal(true)}>
            <UserPlus className="mr-1 h-3.5 w-3.5" /> Enroll Students
          </Button>
          <Button asChild size="sm">
            <Link to="/instructor/create-exercise"><Plus className="mr-1 h-3.5 w-3.5" /> Assign Exercise</Link>
          </Button>
        </div>
      </div>

      {/* Join Code Card — spec §11.9B */}
      <Card className="border-[#A855F7]/20">
        <CardContent className="flex flex-col items-start gap-3 p-4 sm:flex-row sm:items-center sm:justify-between">
          <div className="flex items-center gap-3">
            <div className="flex h-9 w-9 items-center justify-center rounded-lg bg-[#A855F7]/10">
              <KeyRound className="h-4 w-4 text-[#A855F7]" />
            </div>
            <div>
              <div className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">Join Code</div>
              <div className="font-mono text-lg font-bold tracking-[0.15em] text-foreground">{section.code || '—'}</div>
            </div>
          </div>
          <div className="flex flex-wrap gap-2">
            <Button variant="outline" size="sm" className="h-7 text-[10px]" onClick={handleCopyCode}>
              {copied ? <><CheckCircle2 className="mr-1 h-3 w-3 text-emerald-500" /> Copied</> : <><Copy className="mr-1 h-3 w-3" /> Copy</>}
            </Button>
            <Button variant="outline" size="sm" className="h-7 text-[10px]" onClick={handleRotateCode} disabled={rotating}>
              <RotateCw className={cn('mr-1 h-3 w-3', rotating && 'animate-spin')} /> Rotate
            </Button>
            <Button variant="outline" size="sm" className="h-7 text-[10px]">
              <QrCode className="mr-1 h-3 w-3" /> QR
            </Button>
          </div>
        </CardContent>
      </Card>

      {/* Tabs — spec §11.9B */}
      <div className="overflow-x-auto">
        <div className="flex gap-1 border-b border-border">
          {tabs.map(tab => (
            <button
              key={tab.id}
              onClick={() => setActiveTab(tab.id)}
              className={cn(
                'relative flex items-center gap-1.5 whitespace-nowrap px-4 py-2.5 text-xs font-semibold transition-colors',
                activeTab === tab.id ? 'text-foreground' : 'text-muted-foreground hover:text-foreground'
              )}
            >
              {tab.label}
              {tab.count != null && (
                <span className={cn(
                  'inline-flex h-4 min-w-[1.25rem] items-center justify-center rounded-full px-1 text-[9px] font-bold',
                  activeTab === tab.id ? 'bg-primary text-primary-foreground' : 'bg-muted-foreground/15 text-muted-foreground'
                )}>
                  {tab.count}
                </span>
              )}
              {activeTab === tab.id && (
                <span className="absolute inset-x-3 -bottom-px h-0.5 rounded-full bg-primary" />
              )}
            </button>
          ))}
        </div>
      </div>

      {/* ========== HUB TAB ========== */}
      {activeTab === 'hub' && (
        <div className="space-y-6">
          {/* KPI strip */}
          <div className="grid grid-cols-2 gap-3 sm:grid-cols-4">
            <Card>
              <CardContent className="pt-4">
                <div className="text-[9px] font-semibold uppercase tracking-wider text-muted-foreground">Enrolled</div>
                <div className="mt-1 font-mono text-2xl font-bold text-foreground">{studentCount}</div>
                <div className="text-[9px] text-muted-foreground">Students</div>
              </CardContent>
            </Card>
            <Card>
              <CardContent className="pt-4">
                <div className="text-[9px] font-semibold uppercase tracking-wider text-muted-foreground">Avg CDS</div>
                <div className={cn('mt-1 font-mono text-2xl font-bold', DIFFICULTY_TONE[avgCDSDiff].split(' ').filter(c => c.startsWith('text-')).join(' '))}>
                  {getAvgCDS()}
                </div>
                <div className="text-[9px] text-muted-foreground">{avgCDSDiff === 'unscored' ? 'No data' : `${avgCDSDiff.charAt(0).toUpperCase()}${avgCDSDiff.slice(1)} difficulty`}</div>
              </CardContent>
            </Card>
            <Card>
              <CardContent className="pt-4">
                <div className="text-[9px] font-semibold uppercase tracking-wider text-muted-foreground">Alerts</div>
                <div className={cn('mt-1 font-mono text-2xl font-bold', alertCount > 0 ? 'text-red-600 dark:text-red-400' : 'text-foreground')}>{alertCount}</div>
                <div className="text-[9px] text-muted-foreground">Need intervention</div>
              </CardContent>
            </Card>
            <Card>
              <CardContent className="pt-4">
                <div className="text-[9px] font-semibold uppercase tracking-wider text-muted-foreground">Completion</div>
                <div className="mt-1 font-mono text-2xl font-bold text-emerald-600 dark:text-emerald-400">{completionPct}%</div>
                <div className="text-[9px] text-muted-foreground">Exercises submitted</div>
              </CardContent>
            </Card>
          </div>

          {/* Two-column: Students table + Exercises */}
          <div className="grid grid-cols-1 gap-4 lg:grid-cols-2">
            <Card className="flex flex-col overflow-hidden">
              <CardHeader className="flex flex-row items-center justify-between space-y-0 border-b border-border bg-muted/30 px-4 py-2.5">
                <CardTitle className="text-xs font-bold">Students</CardTitle>
                <div className="relative w-[130px]">
                  <Search className="pointer-events-none absolute left-2 top-1/2 h-3 w-3 -translate-y-1/2 text-muted-foreground" />
                  <Input type="text" placeholder="Search..." value={searchQuery} onChange={(e) => setSearchQuery(e.target.value)} className="h-7 pl-7 text-[10px]" />
                </div>
              </CardHeader>
              <div className="max-h-[400px] overflow-y-auto">
                <table className="w-full border-collapse text-xs">
                  <thead className="sticky top-0 bg-muted/30">
                    <tr>
                      <th className="border-b border-border px-3 py-2 text-left text-[8px] font-bold uppercase tracking-wider text-muted-foreground">Student</th>
                      <th className="border-b border-border px-3 py-2 text-center text-[8px] font-bold uppercase tracking-wider text-muted-foreground">Latest CDS</th>
                      <th className="border-b border-border px-3 py-2 text-center text-[8px] font-bold uppercase tracking-wider text-muted-foreground">Submitted</th>
                    </tr>
                  </thead>
                  <tbody>
                    {filteredStudents.map(student => {
                      const difficulty = getDifficulty(student.latest_cds);
                      return (
                        <tr key={student.id} className="border-b border-border/60 last:border-0">
                          <td className="px-3 py-2">
                            <div className="font-semibold text-foreground">{student.name}</div>
                            <div className="text-[9px] text-muted-foreground">{student.email}</div>
                          </td>
                          <td className="px-3 py-2 text-center">
                            <span className={cn('inline-flex items-center rounded-md border px-2 py-0.5 font-mono text-[9px] font-bold', DIFFICULTY_TONE[difficulty])}>
                              {formatCDS(student.latest_cds)}{' '}{difficulty !== 'unscored' && difficulty.charAt(0).toUpperCase() + difficulty.slice(1)}
                            </span>
                          </td>
                          <td className="px-3 py-2 text-center text-[10px] text-muted-foreground">
                            {student.submitted_count || 0}/{student.total_exercises || 0}
                          </td>
                        </tr>
                      );
                    })}
                  </tbody>
                </table>
              </div>
            </Card>

            <div className="flex min-h-0 flex-1 flex-col gap-3">
              <h3 className="text-xs font-bold text-foreground">Exercises</h3>
              <ExerciseAccordion
                sectionId={sectionId}
                exercises={exercises}
                loading={loading}
                formatCDS={formatCDS}
                getDifficulty={getDifficulty}
                liveCDSExerciseId={liveCDSExerciseId}
                onLiveCDSToggle={(id) => setLiveCDSExerciseId((prev) => (prev === id ? null : id))}
              />
            </div>
          </div>

          {/* Concept difficulty panel */}
          <Card>
            <CardHeader><CardTitle className="text-xs font-bold">Most Difficult Concepts</CardTitle></CardHeader>
            <CardContent><SectionMostDifficultConcepts sectionId={sectionId} /></CardContent>
          </Card>
        </div>
      )}

      {/* ========== ROSTER TAB ========== */}
      {activeTab === 'roster' && (
        <div className="space-y-4">
          <div className="flex items-center justify-between">
            <div className="relative w-[200px]">
              <Search className="pointer-events-none absolute left-2.5 top-1/2 h-3.5 w-3.5 -translate-y-1/2 text-muted-foreground" />
              <Input type="text" placeholder="Search students..." value={searchQuery} onChange={(e) => setSearchQuery(e.target.value)} className="h-8 pl-7 text-xs" />
            </div>
            <div className="flex gap-2">
              <select className="flex h-8 rounded-md border border-input bg-background px-2 py-1 text-[10px]">
                <option>All CDS</option>
                <option>Low</option>
                <option>Moderate</option>
                <option>High</option>
              </select>
              <select className="flex h-8 rounded-md border border-input bg-background px-2 py-1 text-[10px]">
                <option>All alerts</option>
                <option>Has alerts</option>
                <option>No alerts</option>
              </select>
            </div>
          </div>
          <Card>
            <div className="max-h-[600px] overflow-y-auto">
              <table className="w-full border-collapse text-xs">
                <thead className="sticky top-0 bg-muted/30">
                  <tr>
                    <th className="border-b border-border px-3 py-2.5 text-left text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Student</th>
                    <th className="border-b border-border px-3 py-2.5 text-center text-[9px] font-bold uppercase tracking-wider text-muted-foreground">CDS</th>
                    <th className="border-b border-border px-3 py-2.5 text-center text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Trend</th>
                    <th className="border-b border-border px-3 py-2.5 text-center text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Alerts</th>
                    <th className="border-b border-border px-3 py-2.5 text-center text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Submitted</th>
                    <th className="border-b border-border px-3 py-2.5 text-center text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Actions</th>
                  </tr>
                </thead>
                <tbody>
                  {filteredStudents.map(student => {
                    const difficulty = getDifficulty(student.latest_cds);
                    return (
                      <tr key={student.id} className="border-b border-border/60 last:border-0 hover:bg-muted/20">
                        <td className="px-3 py-2.5">
                          <Link to={`/instructor/students/${student.id}`} className="font-semibold text-foreground hover:text-primary">{student.name}</Link>
                          <div className="text-[9px] text-muted-foreground">{student.email}</div>
                        </td>
                        <td className="px-3 py-2.5 text-center">
                          <span className={cn('inline-flex items-center rounded-md border px-2 py-0.5 font-mono text-[9px] font-bold', DIFFICULTY_TONE[difficulty])}>
                            {formatCDS(student.latest_cds)}
                          </span>
                        </td>
                        <td className="px-3 py-2.5 text-center">
                          <span className={cn('text-[10px]', student.trend === 'up' ? 'text-emerald-500' : student.trend === 'down' ? 'text-red-500' : 'text-muted-foreground')}>
                            {student.trend === 'up' ? '↑' : student.trend === 'down' ? '↓' : '—'}
                          </span>
                        </td>
                        <td className="px-3 py-2.5 text-center">
                          <span className={cn('font-mono text-[10px]', (student.alert_count || 0) > 0 ? 'text-red-500 font-bold' : 'text-muted-foreground')}>
                            {student.alert_count || 0}
                          </span>
                        </td>
                        <td className="px-3 py-2.5 text-center text-[10px] text-muted-foreground">
                          {student.submitted_count || 0}/{student.total_exercises || 0}
                        </td>
                        <td className="px-3 py-2.5 text-center">
                          <Button asChild variant="ghost" size="sm" className="h-6 text-[9px]">
                            <Link to={`/instructor/students/${student.id}`}><Eye className="mr-1 h-3 w-3" /> View</Link>
                          </Button>
                        </td>
                      </tr>
                    );
                  })}
                </tbody>
              </table>
            </div>
          </Card>
        </div>
      )}

      {/* ========== JOIN REQUESTS TAB ========== */}
      {activeTab === 'join-requests' && (
        <Card>
          <CardHeader><CardTitle className="text-xs font-bold">Pending Join Requests (3)</CardTitle></CardHeader>
          <CardContent>
            <div className="divide-y divide-border">
              {[
                { name: 'Maria Santos', email: 'msantos@example.com', requested: '3h ago', status: 'pending' },
                { name: 'James Kim', email: 'jkim@example.com', requested: '1d ago', status: 'pending' },
                { name: 'Aisha Patel', email: 'apatel@example.com', requested: '2d ago', status: 'pending' },
              ].map((req, i) => (
                <div key={i} className="flex items-center justify-between py-3 first:pt-0 last:pb-0">
                  <div>
                    <div className="text-sm font-semibold text-foreground">{req.name}</div>
                    <div className="text-xs text-muted-foreground">{req.email} · requested {req.requested}</div>
                  </div>
                  <div className="flex gap-2">
                    <Button size="sm" variant="outline" className="h-7 text-[10px] text-emerald-500"><UserCheck className="mr-1 h-3 w-3" /> Approve</Button>
                    <Button size="sm" variant="outline" className="h-7 text-[10px] text-red-500"><UserX className="mr-1 h-3 w-3" /> Deny</Button>
                  </div>
                </div>
              ))}
            </div>
          </CardContent>
        </Card>
      )}

      {/* ========== CODES & POLICY TAB ========== */}
      {activeTab === 'codes' && (
        <div className="space-y-4">
          <Card>
            <CardContent className="pt-6">
              <div className="mb-4">
                <label className="block text-xs font-semibold text-muted-foreground mb-1.5">Join Policy</label>
                <select className="flex h-9 w-full max-w-xs rounded-md border border-input bg-background px-3 py-1 text-xs">
                  <option value="code" selected={section.join_policy === 'code'}>Code-based (students join with code)</option>
                  <option value="request" selected={section.join_policy === 'request'}>Request-based (instructor approval)</option>
                  <option value="closed" selected={section.join_policy === 'closed'}>Closed (no new join requests)</option>
                </select>
              </div>
              <div>
                <div className="text-xs font-semibold text-muted-foreground mb-1.5">Current Code</div>
                <div className="flex items-center gap-3">
                  <span className="font-mono text-xl font-bold tracking-[0.2em] text-foreground">{section.code || '—'}</span>
                  <Button variant="outline" size="sm" className="h-7 text-[10px]" onClick={handleCopyCode}>
                    {copied ? <><CheckCircle2 className="mr-1 h-3 w-3 text-emerald-500" /> Copied</> : <><Copy className="mr-1 h-3 w-3" /> Copy</>}
                  </Button>
                  <Button variant="outline" size="sm" className="h-7 text-[10px]" onClick={handleRotateCode} disabled={rotating}>
                    <RotateCw className={cn('mr-1 h-3 w-3', rotating && 'animate-spin')} /> Rotate Code
                  </Button>
                </div>
                <p className="mt-2 text-[10px] text-muted-foreground">Rotating the code will invalidate the old code. Students will need the new code to join.</p>
              </div>
            </CardContent>
          </Card>
        </div>
      )}

      {/* ========== TAS TAB ========== */}
      {activeTab === 'tas' && (
        <Card>
          <CardHeader className="flex flex-row items-center justify-between space-y-0">
            <CardTitle className="text-xs font-bold">Teaching Assistants (1)</CardTitle>
            <Button variant="outline" size="sm" className="h-7 text-[10px]"><UserPlus className="mr-1 h-3 w-3" /> Add TA</Button>
          </CardHeader>
          <CardContent>
            <div className="divide-y divide-border">
              <div className="flex items-center justify-between py-3 first:pt-0">
                <div className="flex items-center gap-3">
                  <div className="flex h-8 w-8 items-center justify-center rounded-full bg-primary/10 text-xs font-bold text-primary">JD</div>
                  <div>
                    <div className="text-sm font-semibold text-foreground">Jane Doe</div>
                    <div className="text-xs text-muted-foreground">jane.doe@example.com</div>
                  </div>
                </div>
                <div className="flex gap-2">
                  <Badge variant="secondary" className="text-[9px]">Full Access</Badge>
                  <Button variant="ghost" size="sm" className="h-7 text-[10px] text-red-500">Remove</Button>
                </div>
              </div>
            </div>
          </CardContent>
        </Card>
      )}

      {/* ========== AUDIT LOG TAB ========== */}
      {activeTab === 'audit' && (
        <Card>
          <CardHeader><CardTitle className="text-xs font-bold">Audit Log</CardTitle></CardHeader>
          <CardContent>
            <div className="divide-y divide-border">
              {[
                { action: 'Section created', user: 'Dr. Reyes', ts: '2025-09-01 08:00', detail: 'CS101-A' },
                { action: 'Join policy changed', user: 'Dr. Reyes', ts: '2025-09-02 10:30', detail: 'code → request' },
                { action: 'Code rotated', user: 'Dr. Reyes', ts: '2025-09-15 14:00', detail: 'New code generated' },
                { action: 'Student enrolled (manual)', user: 'Dr. Reyes', ts: '2025-09-16 09:15', detail: 'Maria Santos' },
                { action: 'TA added', user: 'Dr. Reyes', ts: '2025-10-01 11:00', detail: 'Jane Doe' },
              ].map((entry, i) => (
                <div key={i} className="flex items-start gap-3 py-2.5 first:pt-0 last:pb-0">
                  <div className="flex h-5 w-5 items-center justify-center rounded-full bg-muted mt-0.5">
                    <div className="h-1.5 w-1.5 rounded-full bg-primary/50" />
                  </div>
                  <div className="flex-1">
                    <div className="text-xs font-semibold text-foreground">{entry.action}</div>
                    <div className="text-[10px] text-muted-foreground">{entry.detail}</div>
                  </div>
                  <div className="text-right text-[9px] text-muted-foreground whitespace-nowrap">
                    <div>{entry.ts}</div>
                    <div>{entry.user}</div>
                  </div>
                </div>
              ))}
            </div>
          </CardContent>
        </Card>
      )}

      {/* ========== EXERCISE MANAGEMENT (from old tab) ========== */}
      {/* Preserve exercise analytics content under hub for backward compat */}
      {activeTab === 'exercise-analytics' && (
        <div className="space-y-4">
          <h3 className="text-sm font-bold text-foreground">Exercise management</h3>
          <ExerciseAccordion
            sectionId={sectionId}
            exercises={exercises}
            loading={loading}
            showManagement
            formatCDS={formatCDS}
            getDifficulty={getDifficulty}
            onEditExercise={handleEditExercise}
            onToggleExerciseStatus={handleToggleExerciseStatus}
            onDeleteExercise={handleDeleteExercise}
            liveCDSExerciseId={liveCDSExerciseId}
            onLiveCDSToggle={(id) => setLiveCDSExerciseId((prev) => (prev === id ? null : id))}
            showDeleteConfirm={showDeleteConfirm}
            selectedExerciseId={selectedExercise?.id}
            onExerciseStatsUpdate={(exerciseId, stats) => {
              setExercises((prev) =>
                prev.map((ex) =>
                  ex.id === exerciseId
                    ? { ...ex, avg_cds: stats.avg_cds ?? ex.avg_cds, low_count: stats.low_count ?? ex.low_count, moderate_count: stats.moderate_count ?? ex.moderate_count, high_count: stats.high_count ?? ex.high_count, submitted_count: stats.submitted_count ?? ex.submitted_count }
                    : ex
                )
              );
            }}
          />
        </div>
      )}

      {/* ========== LONGITUDINAL (preserved from old tab) ========== */}
      {activeTab === 'longitudinal' && (
        <div className="space-y-6">
          <div>
            <h1 className="text-2xl font-bold tracking-tight">Longitudinal Reports</h1>
            <p className="text-xs text-muted-foreground">Section-wide trends and concept-level difficulty.</p>
          </div>
          <Tabs defaultValue="trend">
            <TabsList>
              <TabsTrigger value="trend">Class Trend</TabsTrigger>
              <TabsTrigger value="longitudinal">Longitudinal</TabsTrigger>
              <TabsTrigger value="concepts">Most Difficult Concepts</TabsTrigger>
            </TabsList>
            <TabsContent value="trend">
              <Card>
                <CardHeader><CardTitle>Weekly Class Average CDS</CardTitle></CardHeader>
                <CardContent className="h-72"><SectionClassTrendChart sectionId={sectionId} /></CardContent>
              </Card>
            </TabsContent>
            <TabsContent value="longitudinal">
              <Card>
                <CardHeader><CardTitle>Class-Wide Longitudinal Trend</CardTitle></CardHeader>
                <CardContent><ClassWideLongitudinalChart sectionId={sectionId} /></CardContent>
              </Card>
            </TabsContent>
            <TabsContent value="concepts">
              <Card>
                <CardHeader><CardTitle>Most Difficult Concepts</CardTitle></CardHeader>
                <CardContent><SectionMostDifficultConcepts sectionId={sectionId} /></CardContent>
              </Card>
            </TabsContent>
          </Tabs>
        </div>
      )}

      {/* ========== HEATMAP (preserved) ========== */}
      {activeTab === 'heatmap' && heatmapData && (
        <div>
          <div className="mb-4 flex items-center justify-between">
            <h3 className="text-sm font-bold tracking-tight">Concept Difficulty Heatmap</h3>
            <div className="flex items-center gap-3.5 text-[10px] text-muted-foreground">
              {['low','moderate','high'].map(tone => (
                <div key={tone} className="flex items-center gap-1.5">
                  <span className={cn('h-2 w-2 rounded-sm', DIFFICULTY_DOT[tone])} />
                  {tone.charAt(0).toUpperCase() + tone.slice(1)}
                </div>
              ))}
            </div>
          </div>
          <Card className="overflow-hidden">
            <div className="overflow-x-auto">
              <table className="w-full border-collapse">
                <thead>
                  <tr className="border-b border-border bg-muted/40">
                    <th className="px-3 py-2.5 text-left text-[10px] font-semibold uppercase tracking-wider text-muted-foreground min-w-[130px]">Student</th>
                    {CONCEPT_ORDER.map(concept => (
                      <th key={concept} className="whitespace-nowrap px-3 py-2.5 text-center text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">{concept}</th>
                    ))}
                  </tr>
                </thead>
                <tbody>
                  {heatmapData.students.map(student => (
                    <tr key={student.id} className="border-b border-border/60 last:border-0">
                      <td className="px-3 py-2 text-xs"><div className="font-semibold text-foreground">{student.name}</div></td>
                      {CONCEPT_ORDER.map(concept => {
                        const score = heatmapData.scores[student.id]?.[concept];
                        const cds = score?.cds;
                        const cdsNum = typeof cds === 'string' ? parseFloat(cds) : cds;
                        const difficulty = getDifficulty(cdsNum);
                        return (
                          <td key={concept} className="px-3 py-2 text-center">
                            <span className={cn('inline-flex h-7 w-[54px] items-center justify-center rounded-md border font-mono text-[10px] font-bold tracking-wide', DIFFICULTY_TONE[difficulty])}>
                              {formatCDS(cdsNum)}
                            </span>
                          </td>
                        );
                      })}
                    </tr>
                  ))}
                </tbody>
              </table>
            </div>
          </Card>
        </div>
      )}

      {/* Delete confirmation modal */}
      {showDeleteConfirm && selectedExercise && (
        <div role="dialog" aria-modal="true" className="fixed inset-0 z-50 flex items-center justify-center bg-black/60 backdrop-blur-sm">
          <Card className="w-full max-w-md border-destructive">
            <CardContent className="pt-6">
              <div className="mb-3 flex items-center gap-2 text-sm font-bold text-destructive"><AlertTriangle className="h-4 w-4" /> Delete Exercise</div>
              <p className="mb-4 text-sm leading-relaxed text-muted-foreground">
                Are you sure you want to delete <strong className="text-foreground">"{selectedExercise.title}"</strong>?
              </p>
              <p className="mb-5 text-[11px] italic text-muted-foreground">This will permanently remove the exercise and all related student submissions. This action cannot be undone.</p>
              <div className="flex gap-2">
                <Button variant="outline" className="flex-1" onClick={() => { setShowDeleteConfirm(false); setSelectedExercise(null); }}>Cancel</Button>
                <Button variant="destructive" className="flex-1" onClick={() => handleDeleteExercise(selectedExercise)}><Trash2 className="mr-1 h-3.5 w-3.5" /> Delete Permanently</Button>
              </div>
            </CardContent>
          </Card>
        </div>
      )}

      {/* Enroll Students Modal */}
      {showEnrollModal && (
        <EnrollStudentsModal sectionId={sectionId} onClose={() => setShowEnrollModal(false)} onSuccess={fetchSectionData} />
      )}
    </div>
  );
}
