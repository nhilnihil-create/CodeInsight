import { useState, useMemo, useCallback } from "react";
import { useNavigate, Link } from "react-router-dom";
import { useQuery, useQueryClient } from "@tanstack/react-query";
import { Plus, Search, ArrowRight, Flag, AlertTriangle, RefreshCw, Copy } from "lucide-react";
import { Button } from "@/components/ui/button";
import { Input } from "@/components/ui/input";
import {
  Select,
  SelectContent,
  SelectItem,
  SelectTrigger,
  SelectValue,
} from "@/components/ui/select";
import {
  Dialog,
  DialogContent,
  DialogHeader,
  DialogTitle,
  DialogDescription,
  DialogFooter,
} from "@/components/ui/dialog";
import { Label } from "@/components/ui/label";
import InsightHeader from "@/components/ui/insight-header";
import DecisionList from "@/components/ui/decision-list";
import CDSPillDelta from "@/components/ui/cds-pill-delta";
import { tierForCds, TIER_META } from "@/components/ui/mastery-bar";
import api from "@/services/api";
import { toast } from "sonner";

function buildTerm(row) {
  const sem = row.semester || "Sem 1";
  const year = row.school_year || "";
  return year ? `${sem} · AY ${year}` : sem;
}

async function fetchSections() {
  const { data } = await api.get("/api/sections");
  return data.map((s) => ({
    id: s.id,
    name: s.name,
    course: s.course_code,
    term: buildTerm(s),
    code: s.code,
    students: s.student_count ?? 0,
    atRisk:
      (s.difficulty_distribution?.needs_support ?? 0) +
      (s.difficulty_distribution?.critical ?? 0),
    avgCds: s.avg_cds ?? 0,
    cdsDelta: 0,
    flags: s.integrity_flags_count ?? 0,
    level: tierForCds(s.avg_cds),
  }));
}

export default function InstructorSections() {
  const navigate = useNavigate();
  const queryClient = useQueryClient();
  const [query, setQuery] = useState("");
  const [sort, setSort] = useState("at-risk");
  const [course, setCourse] = useState("all");
  const [createOpen, setCreateOpen] = useState(false);
  const [createName, setCreateName] = useState("");
  const [createCourse, setCreateCourse] = useState("");
  const [createYear, setCreateYear] = useState("");
  const [createSemester, setCreateSemester] = useState("Sem 1");
  const [createBusy, setCreateBusy] = useState(false);
  const [createError, setCreateError] = useState(null);

  const { data: sections = [], isLoading, isError, refetch } = useQuery({
    queryKey: ["instructor-sections"],
    queryFn: fetchSections,
  });

  const availableCourses = useMemo(() => {
    const codes = new Set(sections.map((s) => s.course).filter(Boolean));
    return ["all", ...Array.from(codes).sort()];
  }, [sections]);

  const handleCreate = useCallback(async () => {
    if (!createName.trim() || !createCourse.trim()) {
      setCreateError("Name and course code are required.");
      return;
    }
    setCreateBusy(true);
    setCreateError(null);
    try {
      await api.post("/api/sections", {
        name: createName.trim(),
        course_code: createCourse.trim(),
        school_year: createYear.trim(),
        semester: createSemester,
      });
      setCreateOpen(false);
      setCreateName("");
      setCreateCourse("");
      setCreateYear("");
      setCreateSemester("Sem 1");
      queryClient.invalidateQueries({ queryKey: ["instructor-sections"] });
      refetch();
    } catch (err) {
      setCreateError(err.response?.data?.message || "Failed to create section");
    } finally {
      setCreateBusy(false);
    }
  }, [createName, createCourse, createYear, createSemester, queryClient, refetch]);

  const highestAtRisk = useMemo(() => {
    if (!sections.length) return null;
    const top = sections.reduce((max, s) => (s.atRisk > max.atRisk ? s : max), sections[0]);
    if (!top.students || top.atRisk === 0) return null;
    return top;
  }, [sections]);

  const filtered = useMemo(() => {
    const q = query.trim().toLowerCase();
    let rows = sections.filter((s) => {
      const matchesCourse = course === "all" || s.course === course;
      const matchesQuery =
        !q ||
        s.name.toLowerCase().includes(q) ||
        s.course.toLowerCase().includes(q);
      return matchesCourse && matchesQuery;
    });
    rows = [...rows].sort((a, b) => {
      if (sort === "name") return a.name.localeCompare(b.name);
      if (sort === "cds") return b.avgCds - a.avgCds;
      return b.atRisk - a.atRisk;
    });
    return rows;
  }, [query, sort, course, sections]);

  const handleCopyCode = useCallback(async (code, e) => {
    e.stopPropagation();
    try {
      await navigator.clipboard.writeText(code);
      toast.success("Join code copied to clipboard");
    } catch {
      toast.error("Failed to copy join code");
    }
  }, []);

  const items = filtered.map((s) => ({
    id: s.id,
    title: s.name,
    subtitle: `${s.course} · ${s.term}`,
    meta: `${s.students} students`,
    badge: (
      <div className="flex flex-wrap items-center gap-x-2 gap-y-1 justify-end">
        <span
          className={`inline-flex items-center gap-1.5 rounded-full px-2.5 py-0.5 text-[11px] font-semibold uppercase tracking-wide ${TIER_META[s.level].text}`}
          aria-label={`Mastery level: ${TIER_META[s.level].label}`}
        >
          <span className={`h-1.5 w-1.5 rounded-full ${TIER_META[s.level].dot}`} aria-hidden="true" />
          {TIER_META[s.level].label}
        </span>
        <CDSPillDelta
          value={s.avgCds}
          delta={s.cdsDelta}
          showDelta={s.cdsDelta !== 0}
        />
        <span
          className="inline-flex items-center gap-1 text-xs font-mono tabular-nums text-muted-foreground"
          aria-label={`${s.flags} integrity ${s.flags === 1 ? "flag" : "flags"}`}
        >
          <Flag className="h-3 w-3" strokeWidth={1.5} aria-hidden="true" />
          {s.flags}
        </span>
        <button
          type="button"
          onClick={(e) => handleCopyCode(s.code, e)}
          className="inline-flex items-center gap-1 text-xs font-mono text-muted-foreground hover:text-foreground transition-colors px-1.5 py-0.5 rounded hover:bg-accent"
          aria-label={`Copy join code ${s.code}`}
          title={`Copy code: ${s.code}`}
        >
          <Copy className="h-3 w-3" strokeWidth={1.5} />
          {s.code}
        </button>
      </div>
    ),
  }));

  return (
    <div className="space-y-6 sm:space-y-8">
      {/* ---------- PageHeader ---------- */}
      <div className="flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between">
        <div className="min-w-0 space-y-2">
          <div>
            <h1 className="text-2xl font-semibold tracking-tight">Sections</h1>
            <p className="text-sm text-muted-foreground mt-1">
              {isLoading
                ? "Loading sections…"
                : `${sections.length} active section${sections.length === 1 ? "" : "s"}`}
            </p>
          </div>
        </div>
        <div className="flex items-center gap-2">
          <Button variant="outline" size="sm" onClick={() => refetch()} disabled={isLoading}>
            <RefreshCw className={`h-3.5 w-3.5 mr-1.5 ${isLoading ? "animate-spin" : ""}`} strokeWidth={2} />
            Refresh
          </Button>
          <Button size="sm" className="font-medium" onClick={() => setCreateOpen(true)}>
            <Plus className="h-3.5 w-3.5 mr-1.5" strokeWidth={2} />
            New Section
          </Button>
        </div>
      </div>

      {/* ---------- Insight ---------- */}
      {isError ? (
        <div className="flex items-center gap-3 rounded-lg border border-destructive/30 bg-destructive/5 px-4 py-3">
          <AlertTriangle className="h-4 w-4 text-destructive shrink-0" />
          <p className="text-sm text-destructive flex-1">Failed to load sections. Please try again.</p>
          <Button size="sm" variant="outline" className="border-destructive/30 text-destructive hover:bg-destructive/10" onClick={() => refetch()}>
            <RefreshCw className="h-3.5 w-3.5 mr-1.5" strokeWidth={2} />
            Retry
          </Button>
        </div>
      ) : highestAtRisk ? (
        <InsightHeader
          insight={`${highestAtRisk.name} has the highest at-risk density (${highestAtRisk.atRisk} of ${highestAtRisk.students} students).`}
          action={
            <Button asChild size="sm" className="font-medium">
              <Link to={`/instructor/sections/${highestAtRisk.id}`}>
                View {highestAtRisk.name}
                <ArrowRight className="ml-1.5 h-3.5 w-3.5" strokeWidth={2} />
              </Link>
            </Button>
          }
        />
      ) : null}

      {/* ---------- Filter row ---------- */}
      <div className="flex flex-col sm:flex-row sm:items-center gap-2 sm:gap-3">
        <div className="relative flex-1 sm:max-w-sm">
          <Search
            className="pointer-events-none absolute left-3 top-1/2 -translate-y-1/2 h-3.5 w-3.5 text-muted-foreground"
            strokeWidth={1.5}
            aria-hidden="true"
          />
          <Input
            value={query}
            onChange={(e) => setQuery(e.target.value)}
            placeholder="Search sections…"
            className="pl-9 h-9"
            aria-label="Search sections"
          />
        </div>

        <div className="flex items-center gap-2 sm:ml-auto">
          <span className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground hidden sm:inline">
            Sort
          </span>
          <Select value={sort} onValueChange={setSort}>
            <SelectTrigger className="h-9 w-[140px]" aria-label="Sort sections">
              <SelectValue />
            </SelectTrigger>
            <SelectContent>
              <SelectItem value="at-risk">At-risk</SelectItem>
              <SelectItem value="cds">CDS</SelectItem>
              <SelectItem value="name">Name</SelectItem>
            </SelectContent>
          </Select>

          <span className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground hidden sm:inline">
            Course
          </span>
          <Select value={course} onValueChange={setCourse}>
            <SelectTrigger className="h-9 w-[120px]" aria-label="Filter by course">
              <SelectValue />
            </SelectTrigger>
            <SelectContent>
              <SelectItem value="all">All</SelectItem>
              {availableCourses.filter((c) => c !== "all").map((c) => (
                <SelectItem key={c} value={c}>
                  {c}
                </SelectItem>
              ))}
            </SelectContent>
          </Select>
        </div>
      </div>

      {/* ---------- Decision list ---------- */}
      {isLoading ? (
        <div className="rounded-lg border border-border bg-card/50 py-12 px-6 text-center">
          <p className="text-sm font-semibold text-foreground">Loading sections…</p>
          <p className="text-sm text-muted-foreground mt-1">Fetching your sections from the server.</p>
        </div>
      ) : items.length === 0 ? (
        <div className="rounded-lg border border-dashed border-border bg-card/50 py-12 px-6 text-center">
          <p className="text-sm font-semibold text-foreground">No sections match</p>
          <p className="text-sm text-muted-foreground mt-1">
            Try adjusting the search or course filter.
          </p>
        </div>
      ) : (
        <DecisionList
          items={items}
          highlightIndex={0}
          onAction={(item) => navigate(`/instructor/sections/${item.id}`)}
        />
      )}

      <Dialog open={createOpen} onOpenChange={setCreateOpen}>
        <DialogContent>
          <DialogHeader>
            <DialogTitle>Create Section</DialogTitle>
            <DialogDescription>
              Add a new section to organize your students and exercises.
            </DialogDescription>
          </DialogHeader>
          <div className="space-y-4 py-2">
            <div className="space-y-1.5">
              <Label htmlFor="create-name">Section name *</Label>
              <Input
                id="create-name"
                value={createName}
                onChange={(e) => setCreateName(e.target.value)}
                placeholder="e.g. CS101-A"
              />
            </div>
            <div className="space-y-1.5">
              <Label htmlFor="create-course">Course code *</Label>
              <Input
                id="create-course"
                value={createCourse}
                onChange={(e) => setCreateCourse(e.target.value)}
                placeholder="e.g. CS101"
              />
            </div>
            <div className="grid grid-cols-2 gap-3">
              <div className="space-y-1.5">
                <Label htmlFor="create-semester">Semester</Label>
                <Input
                  id="create-semester"
                  value={createSemester}
                  onChange={(e) => setCreateSemester(e.target.value)}
                  placeholder="Sem 1"
                />
              </div>
              <div className="space-y-1.5">
                <Label htmlFor="create-year">School year</Label>
                <Input
                  id="create-year"
                  value={createYear}
                  onChange={(e) => setCreateYear(e.target.value)}
                  placeholder="e.g. 2025-2026"
                />
              </div>
            </div>
            {createError && (
              <p className="text-sm text-destructive">{createError}</p>
            )}
          </div>
          <DialogFooter>
            <Button variant="ghost" onClick={() => setCreateOpen(false)} disabled={createBusy}>
              Cancel
            </Button>
            <Button onClick={handleCreate} disabled={createBusy}>
              {createBusy ? "Creating…" : "Create Section"}
            </Button>
          </DialogFooter>
        </DialogContent>
      </Dialog>
    </div>
  );
}
