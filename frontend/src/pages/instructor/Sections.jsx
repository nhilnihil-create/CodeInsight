import { useState, useMemo } from "react";
import { useNavigate, Link } from "react-router-dom";
import { Plus, Search, ArrowRight, Flag } from "lucide-react";
import { Button } from "@/components/ui/button";
import { Input } from "@/components/ui/input";
import {
  Select,
  SelectContent,
  SelectItem,
  SelectTrigger,
  SelectValue,
} from "@/components/ui/select";
import InsightHeader from "@/components/ui/insight-header";
import DecisionList from "@/components/ui/decision-list";
import PageBreadcrumb from "@/components/ui/page-breadcrumb";
import RiskBadge from "@/components/ui/risk-badge";
import CDSPillDelta from "@/components/ui/cds-pill-delta";

const SECTIONS = [
  {
    id: 4,
    name: "Section 04",
    course: "CS101",
    term: "Sem 1 · AY 2025–2026",
    students: 22,
    atRisk: 6,
    avgCds: 0.71,
    cdsDelta: 0.04,
    flags: 2,
    level: "high",
  },
  {
    id: 3,
    name: "Section 03",
    course: "CS101",
    term: "Sem 1 · AY 2025–2026",
    students: 19,
    atRisk: 1,
    avgCds: 0.38,
    cdsDelta: -0.02,
    flags: 0,
    level: "moderate",
  },
  {
    id: 2,
    name: "Section 02",
    course: "CS201",
    term: "Sem 1 · AY 2025–2026",
    students: 24,
    atRisk: 3,
    avgCds: 0.55,
    cdsDelta: 0.01,
    flags: 1,
    level: "moderate",
  },
  {
    id: 1,
    name: "Section 01",
    course: "CS201",
    term: "Sem 1 · AY 2025–2026",
    students: 18,
    atRisk: 0,
    avgCds: 0.22,
    cdsDelta: -0.05,
    flags: 0,
    level: "low",
  },
  {
    id: 5,
    name: "Section 05",
    course: "CS301",
    term: "Sem 2 · AY 2025–2026",
    students: 15,
    atRisk: 2,
    avgCds: 0.48,
    cdsDelta: 0.0,
    flags: 1,
    level: "moderate",
  },
];

const COURSES = ["all", "CS101", "CS201", "CS301"];

export default function InstructorSections() {
  const navigate = useNavigate();
  const [query, setQuery] = useState("");
  const [sort, setSort] = useState("at-risk");
  const [course, setCourse] = useState("all");

  const filtered = useMemo(() => {
    const q = query.trim().toLowerCase();
    let rows = SECTIONS.filter((s) => {
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
  }, [query, sort, course]);

  const items = filtered.map((s) => ({
    id: s.id,
    title: s.name,
    subtitle: `${s.course} · ${s.term}`,
    meta: `${s.students} students`,
    badge: (
      <div className="flex items-center gap-2">
        <RiskBadge level={s.level} />
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
      </div>
    ),
  }));

  return (
    <div className="space-y-6 sm:space-y-8">
      {/* ---------- PageHeader ---------- */}
      <div className="flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between">
        <div className="min-w-0 space-y-2">
          <PageBreadcrumb crumbs={[{ label: "Sections" }]} />
          <div>
            <h1 className="text-2xl font-semibold tracking-tight">Sections</h1>
            <p className="text-sm text-muted-foreground mt-1">
              {SECTIONS.length} active sections · AY 2025–2026
            </p>
          </div>
        </div>
        <Button asChild size="sm" className="font-medium">
          <Link to="/instructor/sections/new">
            <Plus className="h-3.5 w-3.5 mr-1.5" strokeWidth={2} />
            New Section
          </Link>
        </Button>
      </div>

      {/* ---------- Insight ---------- */}
      <InsightHeader
        insight="Section 04 has the highest at-risk density (6 of 22 students)."
        action={
          <Button asChild size="sm" className="font-medium">
            <Link to="/instructor/sections/4">
              View Section 04
              <ArrowRight className="ml-1.5 h-3.5 w-3.5" strokeWidth={2} />
            </Link>
          </Button>
        }
      />

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
              {COURSES.filter((c) => c !== "all").map((c) => (
                <SelectItem key={c} value={c}>
                  {c}
                </SelectItem>
              ))}
            </SelectContent>
          </Select>
        </div>
      </div>

      {/* ---------- Decision list ---------- */}
      {items.length === 0 ? (
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
    </div>
  );
}
