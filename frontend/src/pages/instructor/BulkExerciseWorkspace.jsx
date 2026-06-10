import { useEffect, useMemo, useState, useCallback } from "react";
import { Link, useNavigate } from "react-router-dom";
import { ChevronLeft, Plus, Trash2, Layers, Calendar, Check } from "lucide-react";
import { Button } from "@/components/ui/button";
import { Input } from "@/components/ui/input";
import { Label } from "@/components/ui/label";
import { Select, SelectContent, SelectItem, SelectTrigger, SelectValue } from "@/components/ui/select";
import { Badge } from "@/components/ui/badge";
import InstructorDashboardShell from "@/components/instructor-dashboard-shell";
import api from "@/services/api";

const DIFFICULTIES = ["All", "Easy", "Medium", "Hard"];
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
  const [selectedSection, setSelectedSection] = useState("");
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
  const addToBasket = useCallback((entry) => {
    setBasket(prev => {
      if (prev.find(b => b.id === entry.id)) return prev; // already in basket
      return [...prev, { id: entry.id, title: entry.title, concept: entry.concept, difficulty: entry.difficulty, deadline: "" }];
    });
  }, []);

  const removeFromBasket = useCallback((id) => {
    setBasket(prev => prev.filter(b => b.id !== id));
  }, []);

  const updateBasketDeadline = useCallback((id, dl) => {
    setBasket(prev => prev.map(b => b.id === id ? { ...b, deadline: dl } : b));
  }, []);

  const loadCuratedSequence = useCallback(() => {
    if (concept === "all") return;
    const sequence = bank.filter(e => e.concept === concept);
    if (sequence.length === 0) return;
    setBasket(prev => {
      const next = [...prev];
      for (const entry of sequence) {
        if (!next.find(b => b.id === entry.id)) {
          next.push({ id: entry.id, title: entry.title, concept: entry.concept, difficulty: entry.difficulty, deadline: "" });
        }
      }
      return next;
    });
  }, [concept, bank]);

  // ── publish ──────────────────────────────────────────────────────────
  const handlePublish = async (asDraft) => {
    setError(null);
    setSuccess(null);
    if (basket.length === 0) { setError("Basket is empty."); return; }
    if (!selectedSection) { setError("Select a section to publish to."); return; }

    setBusy(true);
    try {
      const res = await api.post("/api/exercises/bulk-publish", {
        section_id: Number(selectedSection),
        bank_ids: basket.map(b => b.id),
        deadline: deadline || null,
      });
      setSuccess(`${res.data.exercises.length} exercise(s) published.`);
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

      {/* global section selector */}
      <div className="mt-4 flex flex-wrap items-center gap-4">
        <div className="flex-1 min-w-[200px]">
          <Label htmlFor="bulk-section" className="text-xs text-muted-foreground">Publish to Section</Label>
          <Select value={selectedSection} onValueChange={setSelectedSection}>
            <SelectTrigger id="bulk-section"><SelectValue placeholder="Select section…" /></SelectTrigger>
            <SelectContent>
              {sections.map(s => (
                <SelectItem key={s.id} value={String(s.id)}>{s.name}</SelectItem>
              ))}
            </SelectContent>
          </Select>
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
                <SelectTrigger><SelectValue placeholder="All" /></SelectTrigger>
                <SelectContent>
                  {DIFFICULTIES.map(d => <SelectItem key={d} value={d}>{d}</SelectItem>)}
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
              const inBasket = basket.some(b => b.id === entry.id);
              return (
                <div key={entry.id} className="rounded-lg border border-border bg-card p-4 flex gap-3 items-start">
                  <div className="min-w-0 flex-1">
                    <div className="flex items-center gap-2 mb-1">
                      <span className="text-sm font-medium truncate">{entry.title}</span>
                      <Badge variant={difficultyVariant(entry.difficulty)} className="text-[10px] px-1.5 py-0">{entry.difficulty}</Badge>
                    </div>
                    <p className="text-xs text-muted-foreground line-clamp-2">{entry.description}</p>
                  </div>
                  <Button
                    variant={inBasket ? "outline" : "ghost"}
                    size="sm"
                    disabled={inBasket}
                    onClick={() => addToBasket(entry)}
                    className="shrink-0 gap-1 text-xs"
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
                  <li key={item.id} className="rounded-md border border-border bg-muted/40 p-3 space-y-2">
                    <div className="flex items-start justify-between gap-2">
                      <div className="min-w-0 flex-1">
                        <span className="text-sm font-medium block truncate">{item.title}</span>
                        <div className="flex gap-1.5 mt-1">
                          <Badge variant="outline" className="text-[10px] px-1 py-0">{item.concept}</Badge>
                          <Badge variant={difficultyVariant(item.difficulty)} className="text-[10px] px-1 py-0">{item.difficulty}</Badge>
                        </div>
                      </div>
                      <Button
                        variant="ghost"
                        size="sm"
                        onClick={() => removeFromBasket(item.id)}
                        className="shrink-0 text-destructive hover:bg-destructive/10 hover:text-destructive p-0 h-7 w-7"
                      >
                        <Trash2 className="h-3.5 w-3.5" />
                      </Button>
                    </div>
                    <div>
                      <Label htmlFor={`dl-${item.id}`} className="text-xs text-muted-foreground">
                        <Calendar className="h-3 w-3 inline mr-1 -mt-px" />
                        Deadline override
                      </Label>
                      <Input
                        id={`dl-${item.id}`}
                        type="datetime-local"
                        value={item.deadline}
                        onChange={e => updateBasketDeadline(item.id, e.target.value)}
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
                onClick={() => handlePublish(false)}
                disabled={busy || basket.length === 0 || !selectedSection}
                className="w-full font-medium"
              >
                <Layers className="h-4 w-4 mr-1.5" />
                {busy ? "Publishing…" : `Publish ${basket.length} Exercise${basket.length !== 1 ? "s" : ""}`}
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
