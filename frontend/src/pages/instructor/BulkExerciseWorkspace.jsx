import { useEffect, useMemo, useState, useCallback } from "react";
import { Link, useNavigate } from "react-router-dom";
import { ChevronLeft, Plus, Trash2, Layers, Calendar, Check } from "lucide-react";
import { Button } from "@/components/ui/button";
import { Input } from "@/components/ui/input";
import { Label } from "@/components/ui/label";
import { Select, SelectContent, SelectItem, SelectTrigger, SelectValue } from "@/components/ui/select";
import { Checkbox } from "@/components/ui/checkbox";
import { Badge } from "@/components/ui/badge";
import InstructorDashboardShell from "@/components/instructor-dashboard-shell";
import api from "@/services/api";

const BASKET_KEY = "ci_bulk_exercise_basket";

/* ── helpers ─────────────────────────────────────────────────────────────── */

function difficultyVariant(d) {
  if (d === "Easy") return "outline";
  if (d === "Hard") return "destructive";
  return "secondary";
}

function loadBasket() {
  try {
    return JSON.parse(localStorage.getItem(BASKET_KEY)) || [];
  } catch { return []; }
}

function saveBasket(basket) {
  localStorage.setItem(BASKET_KEY, JSON.stringify(basket));
}

/* ── page ────────────────────────────────────────────────────────────────── */

export default function BulkExerciseWorkspace() {
  const navigate = useNavigate();

  // Data sources
  const [bank, setBank] = useState([]);
  const [sections, setSections] = useState([]);
  const [loading, setLoading] = useState(true);

  // Filters
  const [concept, setConcept] = useState("all");
  const [difficulty, setDifficulty] = useState("all");

  // Basket
  const [basket, setBasket] = useState(loadBasket);
  const [selectedSections, setSelectedSections] = useState([]);
  const [deadline, setDeadline] = useState("");

  // Status
  const [busy, setBusy] = useState(false);
  const [error, setError] = useState(null);
  const [success, setSuccess] = useState(null);

  // ── fetch bank + sections on mount ────────────────────────────────────
  useEffect(() => {
    const loadBank = api.get("/api/exercises/bank").then(r => setBank(r.data || [])).catch(() => setBank([]));
    const loadSections = api.get("/api/sections").then(r => setSections(r.data || [])).catch(() => setSections([]));
    Promise.all([loadBank, loadSections]).finally(() => setLoading(false));
  }, []);

  // ── persist basket on every change ────────────────────────────────────
  useEffect(() => { saveBasket(basket); }, [basket]);

  // ── filtered bank list ───────────────────────────────────────────────
  const filtered = useMemo(() => {
    return bank.filter(e =>
      (concept === "all" || e.concept === concept) &&
      (difficulty === "all" || e.difficulty === difficulty)
    );
  }, [bank, concept, difficulty]);

  // ── unique concept list for dropdown ─────────────────────────────────
  const concepts = useMemo(() => {
    const seen = new Set();
    return bank.reduce((acc, e) => {
      if (!seen.has(e.concept)) { seen.add(e.concept); acc.push(e.concept); }
      return acc;
    }, []);
  }, [bank]);

  // ── basket actions ───────────────────────────────────────────────────
  // Basket items store: { bankId, bankName, title, concept, difficulty,
  //                      description, starter_code, sample_solution, test_cases,
  //                      time_limit_minutes, deadline }
  const addToBasket = useCallback((entry) => {
    setBasket(prev => {
      if (prev.find(b => b.bankId === entry.id)) return prev;
      return [...prev, {
        bankId: entry.id,
        bankName: entry.title,
        title: entry.title,
        concept: entry.concept,
        difficulty: entry.difficulty,
        description: entry.description || "",
        starter_code: entry.starter_code || "",
        sample_solution: entry.sample_solution || "",
        test_cases: entry.test_cases || [],
        time_limit_minutes: entry.sequence_order === 1 ? 1800 : entry.sequence_order === 2 ? 2700 : 3600,
        deadline: "",
      }];
    });
  }, []);

  // Upsert from BankExerciseEdit — replaces the full payload for a bankId
  const updateBasketItem = useCallback((bankId, payload) => {
    setBasket(prev => {
      const idx = prev.findIndex(b => b.bankId === bankId);
      if (idx >= 0) {
        const next = [...prev];
        next[idx] = { ...next[idx], ...payload };
        return next;
      }
      return [...prev, { bankId, ...payload }];
    });
  }, []);

  const removeFromBasket = useCallback((bankId) => {
    setBasket(prev => prev.filter(b => b.bankId !== bankId));
  }, []);

  const updateBasketDeadline = useCallback((bankId, dl) => {
    setBasket(prev => prev.map(b => b.bankId === bankId ? { ...b, deadline: dl } : b));
  }, []);

  const toggleSection = useCallback((id) => {
    setSelectedSections(prev =>
      prev.includes(id) ? prev.filter(s => s !== id) : [...prev, id]
    );
  }, []);

  const loadCuratedSequence = useCallback(() => {
    if (concept === "all") return;
    const sequence = bank.filter(e => e.concept === concept);
    if (sequence.length === 0) return;
    setBasket(prev => {
      const next = [...prev];
      for (const entry of sequence) {
        if (!next.find(b => b.bankId === entry.id)) {
          next.push({
            bankId: entry.id,
            bankName: entry.title,
            title: entry.title,
            concept: entry.concept,
            difficulty: entry.difficulty,
            description: entry.description || "",
            starter_code: entry.starter_code || "",
            sample_solution: entry.sample_solution || "",
            test_cases: entry.test_cases || [],
            time_limit_minutes: entry.sequence_order === 1 ? 1800 : entry.sequence_order === 2 ? 2700 : 3600,
            deadline: "",
          });
        }
      }
      return next;
    });
  }, [concept, bank]);

  // ── publish ──────────────────────────────────────────────────────────
  const handlePublish = async () => {
    setError(null);
    setSuccess(null);
    if (basket.length === 0) { setError("Basket is empty."); return; }
    if (selectedSections.length === 0) { setError("Select at least one section to publish to."); return; }

    setBusy(true);
    try {
      // Publish to each selected section in parallel
      // Build time_limit_overrides from basket items that have a custom value
      const timeLimitOverrides = {};
      basket.forEach(b => {
        if (b.time_limit_minutes != null) {
          timeLimitOverrides[b.bankId] = b.time_limit_minutes;
        }
      });

      const results = await Promise.all(
        selectedSections.map(sectionId =>
          api.post("/api/exercises/bulk-publish", {
            section_id: Number(sectionId),
            bank_ids: basket.map(b => b.bankId),
            deadline: deadline || null,
            time_limit_overrides: timeLimitOverrides,
          })
        )
      );
      const total = results.reduce((sum, r) => sum + r.data.exercises.length, 0);
      setSuccess(`${total} exercise(s) published across ${selectedSections.length} section(s).`);
      setBasket([]);
      setTimeout(() => navigate("/instructor/exercises"), 1200);
    } catch (err) {
      setError(err.response?.data?.message || err.message);
    } finally {
      setBusy(false);
    }
  };

  // ── render ───────────────────────────────────────────────────────────
  if (loading) {
    return (
      <InstructorDashboardShell>
        <p className="text-muted-foreground">Loading curriculum bank…</p>
      </InstructorDashboardShell>
    );
  }

  return (
    <InstructorDashboardShell>
      {/* header */}
      <div className="space-y-1">
        <Button asChild variant="ghost" size="sm" className="-ml-2">
          <Link to="/instructor/exercises">
            <ChevronLeft className="w-4 h-4 mr-1" /> Back to exercises
          </Link>
        </Button>
        <h1 className="text-2xl font-semibold tracking-tight">Bulk Exercise Workspace</h1>
        <p className="text-sm text-muted-foreground">
          Browse the curriculum bank, stage exercises, and publish them as a weekly set.
        </p>
      </div>

      {/* global section selector + deadline */}
      <div className="mt-4 flex flex-wrap items-start gap-4">
        <div className="min-w-[240px]">
          <Label className="text-xs text-muted-foreground">Publish to Sections</Label>
          <div className="mt-1 rounded-lg border border-border bg-card p-2 max-h-40 overflow-y-auto space-y-0.5">
            {sections.length === 0 ? (
              <p className="text-xs text-muted-foreground px-2 py-3">No sections available.</p>
            ) : (
              <>
                {/* Select all */}
                <label className="flex items-center gap-2 rounded-md px-2 py-1.5 cursor-pointer hover:bg-muted/40">
                  <Checkbox
                    checked={selectedSections.length === sections.length && sections.length > 0}
                    onCheckedChange={() => {
                      setSelectedSections(prev =>
                        prev.length === sections.length ? [] : sections.map(s => String(s.id))
                      );
                    }}
                  />
                  <span className="text-sm truncate flex-1">All sections</span>
                </label>
                {sections.map(s => (
                  <label key={s.id} className="flex items-center gap-2 rounded-md px-2 py-1.5 cursor-pointer hover:bg-muted/40">
                    <Checkbox
                      checked={selectedSections.includes(String(s.id))}
                      onCheckedChange={() => toggleSection(String(s.id))}
                    />
                    <span className="text-sm truncate flex-1">{s.name}</span>
                    <span className="text-xs text-muted-foreground font-mono">{s.student_count ?? s.students ?? 0}</span>
                  </label>
                ))}
              </>
            )}
          </div>
          {selectedSections.length > 0 && (
            <span className="inline-flex items-center bg-primary/10 text-primary text-xs font-medium px-2 py-0.5 rounded-full mt-1">
              {selectedSections.length} section{selectedSections.length !== 1 ? "s" : ""} selected
            </span>
          )}
        </div>
        <div className="min-w-[180px]">
          <Label htmlFor="bulk-deadline" className="text-xs text-muted-foreground">Default Deadline (optional)</Label>
          <Input id="bulk-deadline" type="datetime-local" value={deadline} onChange={e => setDeadline(e.target.value)} />
        </div>
      </div>

      {/* feedback */}
      {error && <p className="mt-3 text-sm text-destructive">{error}</p>}
      {success && (
        <div className="mt-3 flex items-center gap-2 rounded-lg border border-emerald-300 bg-emerald-50 px-4 py-2">
          <Check className="h-4 w-4 text-emerald-600" />
          <p className="text-sm text-emerald-700">{success}</p>
        </div>
      )}

      {/* split layout */}
      <div className="mt-4 grid gap-6 lg:grid-cols-[1fr_380px]">
        {/* ═══════════════ LEFT: Exercise Browser ═══════════════ */}
        <div className="space-y-4">
          {/* filters */}
          <div className="flex flex-wrap items-center gap-3">
            <div className="min-w-[180px]">
              <Label className="text-xs text-muted-foreground">Concept</Label>
              <Select value={concept} onValueChange={setConcept}>
                <SelectTrigger><SelectValue placeholder="All concepts" /></SelectTrigger>
                <SelectContent>
                  <SelectItem value="all">All concepts</SelectItem>
                  {concepts.map(c => <SelectItem key={c} value={c}>{c}</SelectItem>)}
                </SelectContent>
              </Select>
            </div>
            <div className="min-w-[140px]">
              <Label className="text-xs text-muted-foreground">Difficulty</Label>
              <Select value={difficulty} onValueChange={setDifficulty}>
                <SelectTrigger><SelectValue placeholder="All difficulties" /></SelectTrigger>
                <SelectContent>
                  <SelectItem value="all">All difficulties</SelectItem>
                  {["Easy", "Medium", "Hard"].map(d => <SelectItem key={d} value={d}>{d}</SelectItem>)}
                </SelectContent>
              </Select>
            </div>
            <Button
              variant="default"
              size="sm"
              onClick={loadCuratedSequence}
              disabled={concept === "all"}
              className="gap-1.5 self-end"
            >
              <Layers className="h-4 w-4" />
              Load Curated 1-Week Sequence
            </Button>
          </div>

          {/* card list */}
          <div className="space-y-2 max-h-[calc(100vh-340px)] overflow-y-auto pr-1">
            {filtered.length === 0 && (
              <p className="text-sm text-muted-foreground py-8 text-center">No exercises match these filters.</p>
            )}
            {filtered.map(entry => {
              const inBasket = basket.some(b => b.bankId === entry.id);
              return (
                <div key={entry.id} className="rounded-lg border border-border bg-card flex items-start group hover:bg-muted/30 transition-colors">
                  <div
                    className="min-w-0 flex-1 p-4 cursor-pointer"
                    onClick={() => navigate(`/instructor/exercises/bank/${entry.id}/edit`)}
                    role="button"
                    tabIndex={0}
                    onKeyDown={e => { if (e.key === "Enter") navigate(`/instructor/exercises/bank/${entry.id}/edit`); }}
                  >
                    <div className="flex items-center gap-2 mb-1">
                      <span className="text-sm font-medium truncate">{entry.title}</span>
                      <Badge variant={difficultyVariant(entry.difficulty)} className="text-[10px] px-1.5 py-0">{entry.difficulty}</Badge>
                    </div>
                    <p className="text-xs text-muted-foreground line-clamp-2">{entry.description}</p>
                    <p className="text-xs text-primary mt-1 opacity-0 group-hover:opacity-100 transition-opacity">Open in editor →</p>
                  </div>
                  <Button
                    variant={inBasket ? "outline" : "ghost"}
                    size="sm"
                    disabled={inBasket}
                    onClick={(e) => { e.stopPropagation(); addToBasket(entry); }}
                    className="shrink-0 gap-1 text-xs self-center mr-2"
                  >
                    {inBasket ? <Check className="h-3.5 w-3.5" /> : <Plus className="h-3.5 w-3.5" />}
                    {inBasket ? "Added" : "Add"}
                  </Button>
                </div>
              );
            })}
          </div>
        </div>

        {/* ═══════════════ RIGHT: Publication Basket ═══════════════ */}
        <aside className="space-y-4 lg:sticky lg:top-6 lg:self-start">
          <div className="rounded-lg border border-border bg-card p-5 space-y-4">
            <div className="flex items-center justify-between">
              <h2 className="text-sm font-semibold">Publication Basket</h2>
              <Badge variant="outline">{basket.length} item{basket.length !== 1 ? "s" : ""}</Badge>
            </div>

            {basket.length === 0 ? (
              <p className="text-xs text-muted-foreground text-center py-6">No exercises staged.</p>
            ) : (
              <ul className="space-y-2 max-h-[400px] overflow-y-auto pr-1">
                {basket.map(item => (
                  <li key={item.bankId} className="rounded-md border border-border bg-muted/40 p-3 space-y-2">
                    <div className="flex items-start justify-between gap-2">
                      <div className="min-w-0 flex-1">
                        <div className="flex items-center gap-2">
                          <span className="text-sm font-medium block truncate">{item.title}</span>
                          <Link to={`/instructor/exercises/bank/${item.bankId}/edit`} className="text-xs text-primary hover:underline shrink-0">Edit</Link>
                        </div>
                        <div className="flex gap-1.5 mt-1 flex-wrap">
                          <Badge variant="outline" className="text-[10px] px-1 py-0">{item.concept}</Badge>
                          <Badge variant={difficultyVariant(item.difficulty)} className="text-[10px] px-1 py-0">{item.difficulty}</Badge>
                          {item.time_limit_minutes && (
                            <Badge variant="outline" className="text-[10px] px-1 py-0">⏱ {Math.floor(item.time_limit_minutes / 60)}m {item.time_limit_minutes % 60}s</Badge>
                          )}
                        </div>
                      </div>
                      <Button
                        variant="ghost"
                        size="sm"
                        onClick={() => removeFromBasket(item.bankId)}
                        className="shrink-0 text-destructive hover:bg-destructive/10 hover:text-destructive p-0 h-7 w-7"
                      >
                        <Trash2 className="h-3.5 w-3.5" />
                      </Button>
                    </div>
                    <div>
                      <Label htmlFor={`dl-${item.bankId}`} className="text-xs text-muted-foreground">
                        <Calendar className="h-3 w-3 inline mr-1 -mt-px" />
                        Deadline override
                      </Label>
                      <Input
                        id={`dl-${item.bankId}`}
                        type="datetime-local"
                        value={item.deadline}
                        onChange={e => updateBasketDeadline(item.bankId, e.target.value)}
                        className="h-8 text-xs"
                      />
                    </div>
                  </li>
                ))}
              </ul>
            )}

            {/* actions */}
            <div className="flex flex-col gap-2 pt-2 border-t border-border">
              <Button
                onClick={handlePublish}
                disabled={busy || basket.length === 0 || selectedSections.length === 0}
                className="w-full font-medium"
              >
                <Layers className="h-4 w-4 mr-1.5" />
                {busy ? "Publishing…" : `Publish ${basket.length} Exercise${basket.length !== 1 ? "s" : ""} to ${selectedSections.length || "?"} section${selectedSections.length !== 1 ? "s" : ""}`}
              </Button>
              <Button
                onClick={() => { setBasket([]); setError(null); setSuccess(null); }}
                variant="ghost"
                size="sm"
                disabled={basket.length === 0}
                className="w-full text-destructive hover:bg-destructive/10 hover:text-destructive"
              >
                Clear basket
              </Button>
            </div>
          </div>
        </aside>
      </div>
    </InstructorDashboardShell>
  );
}
