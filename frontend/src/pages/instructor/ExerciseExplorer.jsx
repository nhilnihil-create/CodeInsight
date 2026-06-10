import { useEffect, useState, useCallback } from "react";
import { Link } from "react-router-dom";
import { Card, CardContent, CardHeader, CardTitle } from "@/components/ui/card";
import { Button } from "@/components/ui/button";
import { Badge } from "@/components/ui/badge";
import { Input } from "@/components/ui/input";
import { Table, TableBody, TableCell, TableHead, TableHeader, TableRow } from "@/components/ui/table";
import { Search, Layers, Plus, Eye, ChevronRight, AlertTriangle, RefreshCw } from "lucide-react";
import api from "@/services/api";

/**
 * Exercise Explorer — instructor-facing search/discovery page.
 *
 * Full-text search across exercise titles/descriptions.
 * Filter by concept (primary or secondary tags).
 * Shows exercise bank + section-published exercises.
 */

export default function ExerciseExplorer() {
  const [query, setQuery] = useState("");
  const [concept, setConcept] = useState("");
  const [sectionId, setSectionId] = useState("all");
  const [exercises, setExercises] = useState([]);
  const [concepts, setConcepts] = useState([]);
  const [sections, setSections] = useState([]);
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState(null);
  const [searching, setSearching] = useState(false);

  // Load concepts and sections on mount
  useEffect(() => {
    const loadConcepts = api.get("/api/exercises/concepts")
      .then(r => setConcepts(r.data || [])).catch(() => setConcepts([]));
    const loadSections = api.get("/api/sections")
      .then(r => setSections(r.data || [])).catch(() => setSections([]));
    Promise.all([loadConcepts, loadSections]);
  }, []);

  // Search exercises
  const doSearch = useCallback(async () => {
    setLoading(true);
    setError(null);
    try {
      const params = new URLSearchParams();
      if (query.trim()) params.set("q", query.trim());
      if (concept) params.set("concept", concept);
      if (sectionId !== "all") params.set("section_id", sectionId);

      const { data } = await api.get(`/api/search/exercises?${params}`);
      setExercises(data || []);
    } catch (err) {
      setError(err.response?.data?.message || err.message);
      setExercises([]);
    } finally {
      setLoading(false);
    }
  }, [query, concept, sectionId]);

  // Debounced search
  useEffect(() => {
    setSearching(true);
    const timer = setTimeout(() => { doSearch(); setSearching(false); }, 400);
    return () => clearTimeout(timer);
  }, [doSearch]);

  return (
    <div className="space-y-6">
      <div className="flex flex-col gap-4 sm:flex-row sm:items-end sm:justify-between">
        <div>
          <h1 className="text-3xl font-bold tracking-tight">Exercise Explorer</h1>
          <p className="text-muted-foreground">Search and filter exercises by concept, section, or keywords.</p>
        </div>
        <div className="flex items-center gap-2">
          <Button asChild variant="outline">
            <Link to="/instructor/exercises/bulk-create" className="gap-2">
              <Layers className="w-4 h-4" /> Bulk Create
            </Link>
          </Button>
          <Button asChild>
            <Link to="/instructor/exercises/new" className="gap-2">
              <Plus className="w-4 h-4" /> Create Exercise
            </Link>
          </Button>
        </div>
      </div>

      {/* Search Bar */}
      <Card>
        <CardHeader className="pb-3">
          <CardTitle className="text-sm font-medium flex items-center gap-2">
            <Search className="h-4 w-4" /> Search &amp; Filter
          </CardTitle>
        </CardHeader>
        <CardContent className="space-y-4">
          <div className="flex flex-col sm:flex-row gap-3">
            <Input
              placeholder="Search exercises by title or description..."
              value={query}
              onChange={(e) => setQuery(e.target.value)}
              className="flex-1"
              autoFocus
            />
            <select
              value={concept}
              onChange={(e) => setConcept(e.target.value)}
              className="rounded-md border border-input bg-background px-3 py-2 text-sm"
            >
              <option value="">All Concepts</option>
              {concepts.map(c => (
                <option key={c.id} value={c.name}>{c.name}</option>
              ))}
            </select>
            <select
              value={sectionId}
              onChange={(e) => setSectionId(e.target.value)}
              className="rounded-md border border-input bg-background px-3 py-2 text-sm"
            >
              <option value="all">All Sections</option>
              {sections.map(s => (
                <option key={s.id} value={s.id}>{s.name} ({s.course_code})</option>
              ))}
            </select>
          </div>
        </CardContent>
      </Card>

      {/* Error */}
      {error && (
        <div className="flex items-center gap-3 rounded-lg border border-destructive/30 bg-destructive/5 px-4 py-3">
          <AlertTriangle className="h-4 w-4 text-destructive shrink-0" />
          <p className="text-sm text-destructive flex-1">{error}</p>
          <Button size="sm" variant="ghost" className="text-destructive" onClick={() => setError(null)}>Dismiss</Button>
        </div>
      )}

      {/* Results */}
      <Card>
        <CardContent className="p-0">
          {loading ? (
            <div className="text-center py-12">
              <RefreshCw className={`h-5 w-5 border-2 border-muted-foreground/30 border-t-muted-foreground rounded-full mx-auto mb-3 ${searching ? "animate-spin" : ""}`} />
              <p className="text-sm text-muted-foreground">Searching…</p>
            </div>
          ) : exercises.length === 0 ? (
            <div className="text-center py-12 text-muted-foreground">
              {query || concept ? "No exercises match your search." : "Create your first exercise to get started."}
            </div>
          ) : (
            <Table>
              <TableHeader>
                <TableRow>
                  <TableHead className="w-8" />
                  <TableHead>Title</TableHead>
                  <TableHead>Concept</TableHead>
                  <TableHead>Section</TableHead>
                  <TableHead>Completions</TableHead>
                  <TableHead>Status</TableHead>
                  <TableHead />
                </TableRow>
              </TableHeader>
              <TableBody>
                {exercises.map((e) => {
                  const isClosed = !!e.closed_at;
                  const isDraft = e.is_draft;
                  return (
                    <React.Fragment key={e.id}>
                      <TableRow className="cursor-pointer transition-colors hover:bg-muted/40">
                        <TableCell className="w-8 text-muted-foreground">
                          <ChevronRight className="w-4 h-4" />
                        </TableCell>
                        <TableCell className="font-medium">{e.title}</TableCell>
                        <TableCell>
                          <div className="flex gap-1 flex-wrap">
                            <Badge variant="outline">{e.concept_name}</Badge>
                            {e.secondary_concepts?.map(c => (
                              <Badge key={c} variant="secondary" className="text-xs">{c}</Badge>
                            ))}
                          </div>
                        </TableCell>
                        <TableCell className="text-muted-foreground text-sm">
                          {e.section_id ? `#${e.section_id}` : "—"}
                        </TableCell>
                        <TableCell className="text-sm font-mono tabular-nums">
                          {e.completion_count || 0}
                        </TableCell>
                        <TableCell>
                          {isDraft ? <Badge variant="outline">Draft</Badge>
                            : isClosed ? <Badge className="bg-muted text-muted-foreground border-border">Closed</Badge>
                            : <Badge className="bg-cds-low/10 text-cds-low border-cds-low/15">Open</Badge>}
                        </TableCell>
                        <TableCell className="text-right">
                          <Button asChild variant="ghost" size="sm">
                            <Link to={`/instructor/exercises/${e.id}/edit`}>
                              <Eye className="w-3.5 h-3.5 mr-1" /> Edit
                            </Link>
                          </Button>
                        </TableCell>
                      </TableRow>
                    </React.Fragment>
                  );
                })}
              </TableBody>
            </Table>
          )}
        </CardContent>
      </Card>
    </div>
  );
}
