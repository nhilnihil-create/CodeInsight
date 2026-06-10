import { useEffect, useState, useCallback } from "react";
import { Link, useNavigate, useParams } from "react-router-dom";
import { ChevronLeft, Save, Plus, Trash2, TestTube } from "lucide-react";
import { Button } from "@/components/ui/button";
import { Input } from "@/components/ui/input";
import { Label } from "@/components/ui/label";
import { Textarea } from "@/components/ui/textarea";
import { Switch } from "@/components/ui/switch";
import { Badge } from "@/components/ui/badge";
import EmptyState from "@/components/ui/empty-state";
import InstructorDashboardShell from "@/components/instructor-dashboard-shell";
import { cn } from "@/lib/utils";
import api from "@/services/api";

const BASKET_KEY = "ci_bulk_exercise_basket";

function difficultyVariant(d) {
  if (d === "Easy") return "outline";
  if (d === "Hard") return "destructive";
  return "secondary";
}

function loadBasket() {
  try { return JSON.parse(localStorage.getItem(BASKET_KEY)) || []; } catch { return []; }
}
function saveBasket(basket) {
  localStorage.setItem(BASKET_KEY, JSON.stringify(basket));
}

/* ── local card components (same pattern as ExerciseFormFields) ─────────── */

function Card({ children, invalid, className }) {
  return (
    <section className={cn(
      "bg-card border border-border rounded-lg p-5 space-y-4 outline-none transition-shadow",
      invalid && "ring-2 ring-destructive/40 border-destructive/40",
      className
    )}>
      {children}
    </section>
  );
}

function SectionHeader({ title }) {
  return <h2 className="text-sm font-semibold">{title}</h2>;
}

function Field({ label, htmlFor, children }) {
  return (
    <div className="space-y-1.5">
      <Label htmlFor={htmlFor}>{label}</Label>
      {children}
    </div>
  );
}

/* ── page ────────────────────────────────────────────────────────────────── */

const INITIAL_TESTS = [
  { hidden: false, input: "", expected: "", description: "" },
];

export default function BankExerciseEdit() {
  const { id } = useParams();
  const navigate = useNavigate();

  const [bankEntry, setBankEntry] = useState(null);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [inBasket, setInBasket] = useState(false);

  // Form state
  const [title, setTitle] = useState("");
  const [description, setDescription] = useState("");
  const [conceptName, setConceptName] = useState("");
  const [starterCode, setStarterCode] = useState("");
  const [referenceSolution, setReferenceSolution] = useState("");
  const [tests, setTests] = useState(INITIAL_TESTS);
  const [timerMinutes, setTimerMinutes] = useState(45);
  const [timerSeconds, setTimerSeconds] = useState(0);

  // ── load bank entry ──────────────────────────────────────────────────
  useEffect(() => {
    api.get(`/api/exercises/bank/${id}`).then(r => r.data).then(entry => {
      if (!entry) {
        setError("Bank entry not found.");
        setLoading(false);
        return;
      }
      setBankEntry(entry);
      setTitle(entry.title || "");
      setDescription(entry.description || "");
      setConceptName(entry.concept || "");
      setStarterCode(entry.starter_code || "");
      setReferenceSolution(entry.sample_solution || "");
      setTests(
        (entry.test_cases || []).length > 0
          ? entry.test_cases.map(tc => ({
              hidden: !!tc.is_hidden,
              input: tc.input || "",
              expected: tc.expected_output || "",
              description: "",
            }))
          : INITIAL_TESTS
      );
      // Check if already in basket
      const basket = loadBasket();
      setInBasket(basket.some(b => b.bankId === entry.id));
      setLoading(false);
    }).catch(() => { setError("Bank entry not found."); setLoading(false); });
  }, [id]);

  // ── test case handlers ───────────────────────────────────────────────
  const addTest = () => setTests(prev => [...prev, { hidden: false, input: "", expected: "", description: "" }]);
  const updateTest = (i, patch) => setTests(prev => prev.map((t, idx) => idx === i ? { ...t, ...patch } : t));
  const removeTest = (i) => setTests(prev => prev.filter((_, idx) => idx !== i));

  // ── build basket payload from current form state ─────────────────────
  const getBasketPayload = useCallback(() => {
    const testCases = tests.map(t => ({
      input: t.input,
      expected_output: t.expected,
      is_hidden: !!t.hidden,
    }));
    return {
      title,
      concept: conceptName,
      difficulty: bankEntry?.difficulty || "Easy",
      description,
      starter_code: starterCode,
      sample_solution: referenceSolution,
      test_cases: testCases,
      time_limit_minutes: (Number(timerMinutes) || 0) * 60 + (Number(timerSeconds) || 0),
    };
  }, [title, conceptName, bankEntry, description, starterCode, referenceSolution, tests, timerMinutes, timerSeconds]);

  // ── add / update basket ──────────────────────────────────────────────
  const handleAddToBasket = () => {
    const payload = getBasketPayload();
    const basket = loadBasket();
    const idx = basket.findIndex(b => b.bankId === bankEntry.id);
    if (idx >= 0) {
      basket[idx] = { ...basket[idx], ...payload };
    } else {
      basket.push({ bankId: bankEntry.id, bankName: bankEntry.title, deadline: "", ...payload });
    }
    saveBasket(basket);
    setInBasket(true);
    setTimeout(() => navigate("/instructor/exercises/bulk-create"), 600);
  };

  // ── render ───────────────────────────────────────────────────────────
  if (loading) {
    return (
      <InstructorDashboardShell>
        <p className="text-muted-foreground">Loading…</p>
      </InstructorDashboardShell>
    );
  }

  if (error) {
    return (
      <InstructorDashboardShell>
        <p className="text-destructive">{error}</p>
        <Button asChild variant="ghost" className="mt-2">
          <Link to="/instructor/exercises/bulk-create">← Back to bulk create</Link>
        </Button>
      </InstructorDashboardShell>
    );
  }

  return (
    <InstructorDashboardShell>
      {/* header */}
      <div className="space-y-1">
        <Button asChild variant="ghost" size="sm" className="-ml-2">
          <Link to="/instructor/exercises/bulk-create">
            <ChevronLeft className="w-4 h-4 mr-1" /> Back to bulk create
          </Link>
        </Button>
        <div className="flex items-center gap-3">
          <h1 className="text-2xl font-semibold tracking-tight">Edit Bank Exercise</h1>
          <Badge variant={difficultyVariant(bankEntry?.difficulty)} className="text-xs px-2 py-0.5">
            {bankEntry?.difficulty}
          </Badge>
          <span className="text-xs text-muted-foreground">· {conceptName} · Sequence #{bankEntry?.sequence_order}</span>
        </div>
        <p className="text-sm text-muted-foreground">
          Customize this exercise before adding it to your publication basket. All changes are saved to the basket.
        </p>
      </div>

      {/* ── form ─────────────────────────────────────────────────────── */}
      <div className="mt-4 grid gap-6 lg:grid-cols-[1fr_320px]">
        {/* LEFT COLUMN */}
        <div className="space-y-6 min-w-0">
          {/* Title + Description */}
          <Card>
            <SectionHeader title="General Details" />
            <div className="space-y-4">
              <Field label="Exercise Title" htmlFor="ex-title">
                <Input id="ex-title" value={title} onChange={e => setTitle(e.target.value)} placeholder="Exercise title…" />
              </Field>
              <Field label="Description" htmlFor="ex-desc">
                <Textarea id="ex-desc" value={description} onChange={e => setDescription(e.target.value)} placeholder="Describe the problem…" className="min-h-[160px]" />
              </Field>
            </div>
          </Card>

          {/* Code */}
          <Card>
            <SectionHeader title="Code" />
            <Field label="Starter Code" htmlFor="ex-starter">
              <Textarea id="ex-starter" value={starterCode} onChange={e => setStarterCode(e.target.value)} placeholder="# Student starter code…" className="min-h-[120px] font-mono text-xs" />
            </Field>
            <Field label="Sample Solution" htmlFor="ex-ref">
              <Textarea id="ex-ref" value={referenceSolution} onChange={e => setReferenceSolution(e.target.value)} placeholder="# Your reference solution…" className="min-h-[120px] font-mono text-xs" />
            </Field>
          </Card>

          {/* Test Cases */}
          <Card>
            <div className="flex items-center justify-between gap-3">
              <SectionHeader title="Test Cases" />
              <Button type="button" variant="ghost" size="sm" onClick={addTest} className="font-medium">
                <Plus className="h-3.5 w-3.5 mr-1" strokeWidth={2} />
                Add test case
              </Button>
            </div>
            {tests.length === 0 ? (
              <EmptyState
                icon={<TestTube className="h-4 w-4" strokeWidth={1.5} />}
                title="No test cases yet"
                description="Add at least one test case."
                action={<Button onClick={addTest} size="sm" className="font-medium"><Plus className="h-3.5 w-3.5 mr-1.5" strokeWidth={2} />Add test case</Button>}
              />
            ) : (
              <ul className="space-y-3">
                {tests.map((t, i) => (
                  <li key={i}>
                    <div className="rounded-md border border-border bg-muted/40 p-3 space-y-3">
                      <div className="flex items-center gap-2">
                        <div className="flex flex-col min-w-0 flex-1">
                          <span className="text-sm font-medium">Test case {i + 1}</span>
                        </div>
                        <span className={cn(
                          "inline-flex items-center rounded-full border px-2 py-0.5 text-[11px] font-semibold uppercase tracking-wide",
                          t.hidden ? "bg-warning/10 text-warning border-warning/20" : "bg-success/10 text-success border-success/20"
                        )}>
                          {t.hidden ? "Hidden" : "Visible"}
                        </span>
                        <div className="flex items-center gap-2 pl-2 border-l border-border/60">
                          <Label htmlFor={`hidden-${i}`} className="text-xs text-muted-foreground cursor-pointer">Hidden</Label>
                          <Switch id={`hidden-${i}`} checked={t.hidden} onCheckedChange={v => updateTest(i, { hidden: v })} />
                        </div>
                      </div>
                      <div className="grid gap-3 sm:grid-cols-2">
                        <Field label="Input" htmlFor={`in-${i}`}>
                          <Textarea id={`in-${i}`} rows={2} value={t.input} onChange={e => updateTest(i, { input: e.target.value })} placeholder="stdin" className="font-mono text-xs" />
                        </Field>
                        <Field label="Expected Output" htmlFor={`out-${i}`}>
                          <Textarea id={`out-${i}`} rows={2} value={t.expected} onChange={e => updateTest(i, { expected: e.target.value })} placeholder="expected stdout" className="font-mono text-xs" />
                        </Field>
                      </div>
                      <div className="flex justify-end">
                        <Button type="button" variant="ghost" size="sm" onClick={() => removeTest(i)} disabled={tests.length <= 1} className="font-medium text-destructive hover:bg-destructive/10 hover:text-destructive">
                          <Trash2 className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />Remove
                        </Button>
                      </div>
                    </div>
                  </li>
                ))}
              </ul>
            )}
          </Card>
        </div>

        {/* RIGHT COLUMN (sidebar) */}
        <aside className="space-y-4 lg:sticky lg:top-6 lg:self-start min-w-0">
          {/* Timer */}
          <Card>
            <SectionHeader title="Timer" />
            <p className="text-xs text-muted-foreground -mt-2">Default time limit for this exercise.</p>
            <div className="grid grid-cols-2 gap-3">
              <Field label="Minutes" htmlFor="ex-timer-min">
                <Input id="ex-timer-min" type="number" min={0} max={240} value={timerMinutes} onChange={e => setTimerMinutes(Math.max(0, Number(e.target.value) || 0))} className="font-mono tabular-nums" />
              </Field>
              <Field label="Seconds" htmlFor="ex-timer-sec">
                <Input id="ex-timer-sec" type="number" min={0} max={59} value={timerSeconds} onChange={e => setTimerSeconds(Math.min(59, Math.max(0, Number(e.target.value) || 0)))} className="font-mono tabular-nums" />
              </Field>
            </div>
          </Card>

          {/* Add to Basket */}
          <Card className="border-primary/30">
            <div className="space-y-3">
              <h2 className="text-sm font-semibold text-primary">Publication Basket</h2>
              {inBasket && (
                <p className="text-xs text-muted-foreground">
                  This exercise is already in your basket. Saving again will update the existing entry.
                </p>
              )}
              <Button onClick={handleAddToBasket} className="w-full font-medium" size="lg">
                <Save className="h-4 w-4 mr-1.5" />
                {inBasket ? "Update in Basket" : "Add to Basket"}
              </Button>
              <Button asChild variant="ghost" size="sm" className="w-full">
                <Link to="/instructor/exercises/bulk-create">Back to workspace</Link>
              </Button>
            </div>
          </Card>
        </aside>
      </div>
    </InstructorDashboardShell>
  );
}
