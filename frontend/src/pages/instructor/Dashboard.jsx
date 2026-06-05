import { useEffect, useState } from "react";
import { Card, CardContent, CardHeader, CardTitle } from "@/components/ui/card";
import { Users, Code2, AlertTriangle, Activity } from "lucide-react";
import { Link } from "react-router-dom";
import ClassMisconceptionReport from "@/components/analytics/ClassMisconceptionReport";
import IntegrityMonitoringBanner from "@/components/analytics/IntegrityMonitoringBanner";
import SectionFilter from "@/components/SectionFilter";
import api from "@/services/api";

/**
 * Instructor Dashboard
 * Now respects the section filter (All / per-section) per user directive
 * 2026-06-04. Top stat cards refetch on filter change. Subcomponent cards
 * (ClassMisconceptionReport, IntegrityMonitoringBanner) continue to render
 * with their own data sources; the filter is a client-side control on this
 * page so the headline numbers react to the selected section.
 */
export default function InstructorDashboard() {
  const [sectionId, setSectionId] = useState("all");
  const [stats, setStats] = useState({
    totalStudents: 0,
    activeExercises: 0,
    criticalAlerts: 0,
    avgCds: 0,
  });
  const [conceptAverages, setConceptAverages] = useState([]);
  const [recentActivity, setRecentActivity] = useState([]);

  useEffect(() => {
    let cancelled = false;
    const load = async () => {
      try {
        if (sectionId === "all") {
          // Aggregate from the list endpoint when "All Sections" is chosen.
          const res = await api.get("/api/sections");
          const sections = Array.isArray(res.data) ? res.data : [];
          if (cancelled) return;
          const totalStudents = sections.reduce(
            (a, s) => a + (parseInt(s.student_count || 0, 10) || 0),
            0
          );
          setStats((prev) => ({ ...prev, totalStudents }));
          setConceptAverages([]);
          setRecentActivity([]);
          return;
        }
        const [secRes, exRes, alertRes, heatRes, actRes] = await Promise.all([
          api.get(`/api/sections/${sectionId}`),
          api.get(`/api/sections/${sectionId}/exercises`),
          api.get(`/api/analytics/alerts/${sectionId}`),
          api.get(`/api/analytics/heatmap/${sectionId}`),
          api.get(`/api/analytics/activity/${sectionId}`),
        ]);
        if (cancelled) return;
        const exercises = Array.isArray(exRes.data) ? exRes.data : [];
        const activeExercises = exercises.filter(
          (e) => !e.closed_at
        ).length;
        const alerts = Array.isArray(alertRes.data) ? alertRes.data : [];
        const criticalAlerts = alerts.length;
        const scores = heatRes.data?.scores || {};
        const cdsValues = [];
        const perConcept = {};
        for (const studentId in scores) {
          for (const concept in scores[studentId]) {
            const cds = scores[studentId][concept]?.cds;
            const num = typeof cds === "string" ? parseFloat(cds) : cds;
            if (typeof num === "number" && !isNaN(num)) {
              cdsValues.push(num);
              perConcept[concept] = perConcept[concept] || { sum: 0, n: 0 };
              perConcept[concept].sum += num;
              perConcept[concept].n += 1;
            }
          }
        }
        const avgCds =
          cdsValues.length > 0
            ? cdsValues.reduce((a, b) => a + b, 0) / cdsValues.length
            : 0;
        const conceptRows = Object.keys(perConcept).map((name) => ({
          name,
          cds: Math.round((perConcept[name].sum / perConcept[name].n) * 100),
        }));
        setStats({
          totalStudents: parseInt(secRes.data?.student_count || 0, 10) || 0,
          activeExercises,
          criticalAlerts,
          avgCds,
        });
        setConceptAverages(conceptRows);
        setRecentActivity(Array.isArray(actRes.data) ? actRes.data : []);
      } catch (err) {
        if (!cancelled) {
          setStats({ totalStudents: 0, activeExercises: 0, criticalAlerts: 0, avgCds: 0 });
          setConceptAverages([]);
          setRecentActivity([]);
        }
      }
    };
    load();
    return () => {
      cancelled = true;
    };
  }, [sectionId]);

  const avgCdsPct = Math.round(stats.avgCds * 100);
  const avgTone =
    avgCdsPct <= 33
      ? "text-green-500"
      : avgCdsPct <= 66
      ? "text-blue-500"
      : "text-destructive";

  return (
    <div className="space-y-6">
      <div className="flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between">
        <div>
          <h1 className="text-3xl font-bold tracking-tight">Instructor Dashboard</h1>
          <p className="text-muted-foreground">Class overview and active alerts.</p>
        </div>
        <SectionFilter value={sectionId} onChange={setSectionId} />
      </div>

      <div className="grid gap-6 md:grid-cols-2 lg:grid-cols-4">
        <Card>
          <CardHeader className="flex flex-row items-center justify-between space-y-0 pb-2">
            <CardTitle className="text-sm font-medium">Total Students</CardTitle>
            <Users className="w-4 h-4 text-muted-foreground" />
          </CardHeader>
          <CardContent>
            <div className="text-2xl font-bold">{stats.totalStudents}</div>
          </CardContent>
        </Card>
        <Card>
          <CardHeader className="flex flex-row items-center justify-between space-y-0 pb-2">
            <CardTitle className="text-sm font-medium">Active Exercises</CardTitle>
            <Code2 className="w-4 h-4 text-muted-foreground" />
          </CardHeader>
          <CardContent>
            <div className="text-2xl font-bold">{stats.activeExercises}</div>
          </CardContent>
        </Card>
        <Card className="bg-destructive/5 border-destructive/20">
          <CardHeader className="flex flex-row items-center justify-between space-y-0 pb-2">
            <CardTitle className="text-sm font-medium text-destructive">Critical Alerts</CardTitle>
            <AlertTriangle className="w-4 h-4 text-destructive" />
          </CardHeader>
          <CardContent>
            <div className="text-2xl font-bold text-destructive">{stats.criticalAlerts}</div>
            <Link to="/instructor/warnings" className="text-xs text-destructive hover:underline mt-1 inline-block">View all warnings</Link>
          </CardContent>
        </Card>
        <Card>
          <CardHeader className="flex flex-row items-center justify-between space-y-0 pb-2">
            <CardTitle className="text-sm font-medium">Avg Class CDS</CardTitle>
            <Activity className="w-4 h-4 text-muted-foreground" />
          </CardHeader>
          <CardContent>
            <div className={`text-2xl font-bold ${avgTone}`}>{avgCdsPct}</div>
            <p className="text-xs text-muted-foreground">
              {avgCdsPct <= 33 ? "Low Difficulty" : avgCdsPct <= 66 ? "Medium Difficulty" : "High Difficulty"}
            </p>
          </CardContent>
        </Card>
      </div>

      <div className="grid gap-6 md:grid-cols-2 lg:grid-cols-3">
        <Card className="md:col-span-2">
          <CardHeader>
            <CardTitle>Class Concept Averages</CardTitle>
          </CardHeader>
          <CardContent>
            <div className="space-y-4">
              {conceptAverages.length === 0 ? (
                <div className="text-sm text-muted-foreground">No concept data yet for this selection.</div>
              ) : (
                conceptAverages.map((concept) => (
                  <div key={concept.name} className="flex items-center">
                    <div className="w-24 text-sm font-medium">{concept.name}</div>
                    <div className="flex-1 flex items-center gap-2">
                      <div className="w-full bg-muted rounded-full h-2">
                        <div
                          className={`h-2 rounded-full ${concept.cds > 75 ? 'bg-destructive' : concept.cds > 50 ? 'bg-orange-500' : concept.cds > 25 ? 'bg-blue-500' : 'bg-green-500'}`}
                          style={{ width: `${concept.cds}%` }}
                        />
                      </div>
                      <div className="w-8 text-right text-xs text-muted-foreground font-mono">{concept.cds}</div>
                    </div>
                  </div>
                ))
              )}
            </div>
          </CardContent>
        </Card>

        <Card>
          <CardHeader>
            <CardTitle>Recent Activity</CardTitle>
          </CardHeader>
          <CardContent>
            <div className="space-y-4">
              {recentActivity.length === 0 ? (
                <div className="text-sm text-muted-foreground">No recent activity.</div>
              ) : (
                recentActivity.slice(0, 6).map((item, i) => (
                  <div key={item.id || i} className="flex flex-col gap-1 pb-3 border-b last:border-0 last:pb-0">
                    <div className="text-sm font-medium">{item.user_name || item.user || "System"}</div>
                    <div className="text-xs text-muted-foreground">{item.action || item.message || ""}</div>
                    <div className="text-[10px] text-muted-foreground/70">
                      {item.time_ago || (item.created_at ? new Date(item.created_at).toLocaleString() : "")}
                    </div>
                  </div>
                ))
              )}
            </div>
          </CardContent>
        </Card>
      </div>

      <Card>
        <CardHeader>
          <CardTitle>Class Misconceptions</CardTitle>
        </CardHeader>
        <CardContent>
          <ClassMisconceptionReport embedded />
        </CardContent>
      </Card>

      <IntegrityMonitoringBanner />
    </div>
  );
}
