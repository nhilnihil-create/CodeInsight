import { useEffect, useMemo, useState, useCallback } from "react";
import { Link, useNavigate, useParams } from "react-router-dom";
import { ChevronLeft, Plus, Trash2, Layers, Check, AlertCircle, X, ArrowRight, ArrowLeft, Download, Upload, Zap, TrendingUp, ShieldAlert, FileText } from "lucide-react";
import { Button } from "@/components/ui/button";
import { Input } from "@/components/ui/input";
import { Label } from "@/components/ui/label";
import { Badge } from "@/components/ui/badge";
import { Card, CardContent, CardHeader, CardTitle } from "@/components/ui/card";
import { Checkbox } from "@/components/ui/checkbox";
import { Textarea } from "@/components/ui/textarea";
import { Select, SelectContent, SelectItem, SelectTrigger, SelectValue } from "@/components/ui/select";
import { Separator } from "@/components/ui/separator";
import { toast } from "sonner";
import InstructorDashboardShell from "@/components/instructor-dashboard-shell";
import api from "@/services/api";
import { Save } from "lucide-react";

/* ── constants ─────────────────────────────────────────────────────────── */

const STARTER_CODE = `#include <iostream>
using namespace std;

int main() {
  // Write code here
  return 0;
}
`;

const BASKET_KEY = "ci_exercise_basket";

/* ── helpers ───────────────────────────────────────────────────────────── */

function loadBasket() {
  try { return JSON.parse(localStorage.getItem(BASKET_KEY)) || []; }
  catch { return []; }
}
function saveBasket(basket) {
  localStorage.setItem(BASKET_KEY, JSON.stringify(basket));
}

/**
 * Token counter for baseline complexity.
 * Counts C++ identifiers, keywords, operators, and literals.
 * Equivalent to ~1 token per identifier/keyword/literal.
 */
function countTokens(code) {
  if (!code) return 0;
  // Remove comments and strings for cleaner counting
  const cleaned = code
    .replace(/\/\/.*$/gm, '')      // single-line comments
    .replace(/\/\*[\s\S]*?\*\//g, '') // multi-line comments
    .replace(/"[^"]*"/g, '""')     // string literals → placeholder
    .replace(/'[^']*'/g, "''");    // char literals → placeholder

  // Match: keywords, identifiers, numbers, operators
  const tokens = cleaned.match(/[a-zA-Z_]\w*|\d+|[+\-*/=<>!&|^~%]+/g) || [];
  return tokens.length;
}

/**
 * Static growth fallback: compares new code tokens against baseline.
 * Returns { flagged, baselineTokens, newTokens, growthPercent, threshold }
 * Primary detection is time-based rate-burst analysis (adaptive to the
 * student's own typing speed); this static rule runs only when no typing
 * telemetry exists.
 */
function checkGrowthVelocity(starterCode, newCode, threshold = 200) {
  const baseline = countTokens(starterCode);
  const current = countTokens(newCode);
  if (baseline === 0) return { flagged: false, baselineTokens: 0, newTokens: current, growthPercent: 0, threshold };
  const growthPercent = ((current - baseline) / baseline) * 100;
  return {
    flagged: growthPercent > threshold,
    baselineTokens: baseline,
    newTokens: current,
    growthPercent: Math.round(growthPercent),
    threshold,
  };
}

function blankExercise() {
  return {
    id: crypto.randomUUID(),
    bankId: null,
    title: "",
    description: "",
    concept_name: "",
    concept_tags: [], // NEW: multi-tag support [{concept_id, concept_name, weight, is_primary}]
    starter_code: STARTER_CODE,
    test_cases: [{ input: "", expected: "", description: "", hidden: false }],
    time_limit_minutes: 45,
    deadline: "",
  };
}

/* ── Step Wizard ───────────────────────────────────────────────────────── */

const STEPS = [
  { key: "details",     label: "Title & Description" },     // 0
  { key: "concept",     label: "Concept Tag" },             // 1
  { key: "code",        label: "Starter Code" },            // 2
  { key: "tests",       label: "Test Cases" },              // 3
  { key: "sections",    label: "Section Assignment" },      // 4
  { key: "constraints", label: "Timer" },                   // 5
];

function StepIndicator({ currentStep, canAdvance, onStepClick }) {
  return (
    <div className="flex flex-wrap items-center gap-1.5">
      {STEPS.map((s, i) => {
        const done = i < currentStep;
        const active = i === currentStep;
        const reachable = i <= canAdvance;
        return (
          <button
            key={s.key}
            type="button"
            onClick={() => { if (reachable) onStepClick(i); }}
            className={`flex items-center gap-1.5 px-2.5 py-1.5 rounded-full text-xs font-medium whitespace-nowrap transition-colors ${
              active
                ? "bg-primary text-primary-foreground shadow-[0_0_16px_rgba(45,212,191,0.25)]"
                : done
                  ? "bg-muted text-muted-foreground hover:bg-muted/80 cursor-pointer"
                  : reachable
                    ? "bg-muted/60 text-muted-foreground/70 hover:bg-muted/80 cursor-pointer"
                    : "bg-muted/30 text-muted-foreground/40"
            }`}
          >
            {done ? <Check className="w-3 h-3" /> : <span className="w-4 h-4 flex items-center justify-center rounded-full border text-[10px]">{i + 1}</span>}
            {s.label}
          </button>
        );
      })}
    </div>
  );
}

/* ── TestCaseEditor — Multi-line I/O support ───────────────────────────── */

function TestCaseEditor({ tests, onChange }) {
  const update = (i, field, value) => onChange(tests.map((t, j) => j === i ? { ...t, [field]: value } : t));
  const add = () => onChange([...tests, { input: "", expected: "", description: "", hidden: false }]);
  const remove = (i) => onChange(tests.filter((_, j) => j !== i));

  return (
    <div className="space-y-3">
      <div className="flex items-center justify-between">
        <span className="text-xs font-medium text-muted-foreground">{tests.length} test case{tests.length !== 1 ? 's' : ''}</span>
        <Button variant="outline" size="sm" onClick={add}>
          <Plus className="w-3.5 h-3.5 mr-1" /> Add Test Case
        </Button>
      </div>
      {tests.map((t, i) => (
        <Card key={i} variant="dense">
          <CardContent className="pt-4 space-y-3">
            <div className="flex items-center justify-between gap-2">
              <div className="flex items-center gap-2 min-w-0">
                <span className="text-xs font-semibold">Test {i + 1}</span>
                <span className="text-[10px] font-mono text-muted-foreground/50 truncate">
                  {t.description || "No description"}
                </span>
              </div>
              <div className="flex items-center gap-2 shrink-0">
                <button
                  type="button"
                  onClick={() => update(i, "hidden", !t.hidden)}
                  className={`text-[10px] px-2 py-0.5 rounded-full border transition-colors ${
                    t.hidden
                      ? 'bg-amber-500/10 border-amber-500/30 text-amber-500'
                      : 'bg-muted/40 border-border/40 text-muted-foreground hover:bg-muted/60'
                  }`}
                >
                  {t.hidden ? '🔒 Hidden' : '👁 Visible'}
                </button>
                <Button variant="ghost" size="sm" onClick={() => remove(i)} disabled={tests.length <= 1} className="h-6 w-6 p-0">
                  <Trash2 className="w-3.5 h-3.5 text-destructive" />
                </Button>
              </div>
            </div>

            {/* Description input — always available (was dead behind a button) */}
            <Input
              value={t.description}
              onChange={(e) => update(i, "description", e.target.value)}
              className="text-xs"
              placeholder="Test description (e.g. Normal input, Edge case: n=0)"
            />

            {/* I/O fields — stack on mobile, side-by-side on sm+ */}
            <div className="grid grid-cols-1 sm:grid-cols-2 gap-3">
              <div className="min-w-0">
                <Label className="text-[10px] uppercase tracking-wider text-muted-foreground">Stdin Input</Label>
                <Textarea
                  value={t.input}
                  onChange={(e) => update(i, "input", e.target.value)}
                  className="text-xs font-mono min-h-[60px] resize-y mt-1"
                  placeholder={"5\n1 2 3 4 5"}
                  rows={3}
                />
              </div>
              <div className="min-w-0">
                <Label className="text-[10px] uppercase tracking-wider text-muted-foreground">Expected Stdout</Label>
                <Textarea
                  value={t.expected}
                  onChange={(e) => update(i, "expected", e.target.value)}
                  className="text-xs font-mono min-h-[60px] resize-y mt-1"
                  placeholder={"15"}
                  rows={3}
                />
              </div>
            </div>
          </CardContent>
        </Card>
      ))}
    </div>
  );
}

/* ── Exercise Form Step ────────────────────────────────────────────────── */

function ExerciseForm({ exercise, onChange, concepts, step }) {
  const set = (key, value) => onChange({ ...exercise, [key]: value });

  // Compute baseline complexity
  const baselineTokens = useMemo(() => countTokens(exercise.starter_code), [exercise.starter_code]);
  const complexityLabel = baselineTokens < 20 ? "Minimal" : baselineTokens < 50 ? "Basic" : baselineTokens < 100 ? "Moderate" : "Advanced";

  return (
    <div className="space-y-6">
      {/* Step 0: Title & Description */}
      {step === 0 && (
        <>
          <div>
            <Label className="text-sm font-medium">Title <span className="text-destructive">*</span></Label>
            <Input value={exercise.title} onChange={e => set("title", e.target.value)} placeholder="e.g. Print Fibonacci Series up to N" />
          </div>
          <div>
            <Label className="text-sm font-medium">Description</Label>
            <Textarea value={exercise.description} onChange={e => set("description", e.target.value)} rows={4} placeholder="Write clear instructions for students..." className="text-sm" />
          </div>
        </>
      )}

      {/* Step 1: Concept Tags (Multi-select) */}
      {step === 1 && (
        <div className="space-y-4">
          <div>
            <Label className="text-sm font-medium">Primary Concept <span className="text-destructive">*</span></Label>
            <Select value={exercise.concept_name} onValueChange={v => {
              const selected = concepts.find(c => c.name === v);
              let nextTags = exercise.concept_tags;
              if (selected) {
                const existing = nextTags.find(t => t.concept_id === selected.id);
                if (!existing) {
                  nextTags = [...nextTags, { concept_id: selected.id, concept_name: v, weight: 1.0, is_primary: true }];
                } else {
                  nextTags = nextTags.map(t =>
                    t.concept_id === selected.id ? { ...t, is_primary: true } : t
                  );
                }
              }
              onChange({ ...exercise, concept_name: v, concept_tags: nextTags });
            }}>
              <SelectTrigger data-testid="concept-trigger"><SelectValue placeholder="Select primary concept" /></SelectTrigger>
              <SelectContent>
                {concepts.map(c => <SelectItem key={c.id} value={c.name}>{c.name}</SelectItem>)}
              </SelectContent>
            </Select>
            <p className="text-xs text-muted-foreground mt-1">Primary concept for CDS analytics and heatmap display.</p>
          </div>

          <Separator />

          {/* Multi-tag section */}
          <div>
            <Label className="text-sm font-medium">Secondary Concepts (optional)</Label>
            <p className="text-xs text-muted-foreground mb-2">Select additional concepts this exercise covers.</p>

            <div className="flex flex-wrap gap-1.5 max-h-40 overflow-y-auto p-2 border rounded-md bg-muted/20">
              {concepts.filter(c => c.name !== exercise.concept_name).map(c => {
                const isSelected = exercise.concept_tags.some(t => t.concept_id === c.id);
                return (
                  <button
                    key={c.id}
                    type="button"
                    onClick={() => {
                      if (isSelected) {
                        set("concept_tags", exercise.concept_tags.filter(t => t.concept_id !== c.id));
                      } else {
                        set("concept_tags", [...exercise.concept_tags, { concept_id: c.id, concept_name: c.name, weight: 0.5, is_primary: false }]);
                      }
                    }}
                    className={`px-2 py-1 rounded-full text-xs border transition-colors ${
                      isSelected
                        ? 'bg-primary/10 border-primary/30 text-primary font-medium'
                        : 'bg-background border-border text-muted-foreground hover:bg-muted/50'
                    }`}
                  >
                    {c.name}
                    {isSelected && <span className="ml-1 text-[10px]">✓</span>}
                  </button>
                );
              })}
            </div>
          </div>

          {/* Show selected tags */}
          {exercise.concept_tags.length > 0 && (
            <div className="flex flex-wrap gap-1.5">
              {exercise.concept_tags
                .sort((a, b) => (b.is_primary ? 1 : 0) - (a.is_primary ? 1 : 0))
                .map(t => (
                  <Badge key={t.concept_id} variant={t.is_primary ? 'default' : 'outline'} className="text-xs">
                    {t.is_primary ? '★ ' : ''}{t.concept_name} ({Math.round(t.weight * 100)}%)
                  </Badge>
                ))}
            </div>
          )}


        </div>
      )}

      {/* Step 2: Starter Code + Baseline Complexity */}
      {step === 2 && (
        <>
          <div>
            <Label className="text-sm font-medium">Starter Code</Label>
            <Textarea value={exercise.starter_code} onChange={e => set("starter_code", e.target.value)} rows={8} className="font-mono text-xs" />
          </div>

          {/* Baseline Complexity Card */}
          <Card className="border-amber-500/20 bg-amber-500/5">
            <CardHeader className="pb-2">
              <CardTitle className="text-sm font-medium flex items-center gap-2">
                <Zap className="w-4 h-4 text-amber-500" /> Baseline Complexity
                <Badge variant="outline" className="text-xs">{complexityLabel}</Badge>
              </CardTitle>
            </CardHeader>
            <CardContent className="text-xs space-y-2">
              <div className="flex items-center justify-between">
                <span className="text-muted-foreground">Token Count</span>
                <span className="font-mono font-semibold">{baselineTokens}</span>
              </div>
              <Separator />
              <div className="flex items-center justify-between">
                <span className="text-muted-foreground">Growth Flagging</span>
                <span className="font-mono font-semibold">Rate-burst</span>
              </div>
              <p className="text-muted-foreground text-[10px] mt-1">
                Flags submissions where code grows in a <strong>sudden burst</strong> far above the student's own typing speed — the threshold is adaptive to each student.
                Bursts coinciding with paste events are correlated. A static line-growth rule applies only when no typing telemetry exists. Flags are for review only.
              </p>
              {baselineTokens < 5 && (
                <div className="flex items-center gap-1.5 text-amber-600 text-[10px]">
                  <ShieldAlert className="w-3 h-3" />
                  Low baseline complexity — consider adding more starter code for accurate growth detection.
                </div>
              )}
            </CardContent>
          </Card>
        </>
      )}

      {/* Step 3: Test Cases */}
      {step === 3 && (
        <TestCaseEditor tests={exercise.test_cases} onChange={v => set("test_cases", v)} />
      )}

      {/* Step 4: Section Assignment (handled in basket panel) */}
      {step === 4 && (
        <div className="space-y-4">
          <p className="text-sm text-muted-foreground">Sections are selected in the basket panel on the right. Each exercise in your basket can be published to multiple sections.</p>
          <Card>
            <CardContent className="pt-4">
              <div className="flex items-center gap-2 text-sm">
                <Check className="w-4 h-4 text-green-500" />
                <span>Exercises in your basket will be published to all checked sections.</span>
              </div>
            </CardContent>
          </Card>
        </div>
      )}

      {/* Step 5: Timer */}
      {step === 5 && (
        <div className="space-y-4">
          <div>
            <Label className="text-sm font-medium">Time Limit <span className="text-muted-foreground font-normal">(minutes)</span></Label>
            <Input type="number" value={exercise.time_limit_minutes} onChange={e => set("time_limit_minutes", Number(e.target.value))} min={1} max={600} className="max-w-xs" />
            <p className="text-xs text-muted-foreground mt-1">Due date is set in the basket panel on the right when you publish.</p>
          </div>

          {/* Rate-Burst Detection Info */}
          <Card>
            <CardHeader className="pb-2">
              <CardTitle className="text-sm font-medium flex items-center gap-2">
                <TrendingUp className="w-4 h-4 text-primary" /> Rate-Burst Detection
              </CardTitle>
            </CardHeader>
            <CardContent className="text-xs space-y-2">
              <p className="text-muted-foreground">
                The student's typing speed is sampled every few seconds (token count over active editing time). An adaptive threshold is derived
                from their session median and classmates' medians; a burst of growth far above their own speed gets flagged for review, and bursts
                coinciding with paste events are correlated. A static line-growth rule applies only when no typing telemetry exists.
                Flags are low severity, for review only — not automatic penalties.
              </p>
              <div className="grid grid-cols-3 gap-2">
                <div className="text-center p-2 rounded bg-muted/40">
                  <div className="text-lg font-mono font-semibold">Live</div>
                  <div className="text-[10px] text-muted-foreground">Speed sampled every few seconds</div>
                </div>
                <div className="text-center p-2 rounded bg-muted/40">
                  <div className="text-lg font-mono font-semibold">Adaptive</div>
                  <div className="text-[10px] text-muted-foreground">Threshold per student</div>
                </div>
                <div className="text-center p-2 rounded bg-destructive/10">
                  <div className="text-lg font-mono font-semibold text-destructive">Rate-burst</div>
                  <div className="text-[10px] text-destructive">⚠ Flag for review</div>
                </div>
              </div>
            </CardContent>
          </Card>
        </div>
      )}
    </div>
  );
}

/* ── Basket Panel ───────────────────────────────────────────────────────── */

function BasketPanel({ basket, setBasket, sections, onPublish, onClear }) {
  const [selectedSections, setSelectedSections] = useState([]);
  const [deadline, setDeadline] = useState("");

  const toggleSection = (id) => {
    setSelectedSections(prev => prev.includes(id) ? prev.filter(s => s !== id) : [...prev, id]);
  };

  const removeItem = (id) => setBasket(prev => prev.filter(b => b.id !== id));

  return (
    <div className="space-y-4">
      <div className="flex items-center justify-between">
        <h3 className="text-sm font-semibold flex items-center gap-1.5">
          <Layers className="w-4 h-4" /> Basket
          <Badge variant="secondary" className="text-xs">{basket.length}</Badge>
        </h3>
        {basket.length > 0 && (
          <Button variant="ghost" size="sm" onClick={onClear} className="text-xs text-destructive h-6">
            <Trash2 className="w-3 h-3 mr-1" /> Clear
          </Button>
        )}
      </div>

      {basket.length === 0 ? (
        <div className="rounded-lg border border-dashed border-border/40 p-6 text-center">
          <p className="text-xs text-muted-foreground">Add exercises using the form or databank below.</p>
        </div>
      ) : (
        <div className="space-y-1.5">
          {basket.map(b => {
            const tokens = countTokens(b.starter_code);
            return (
              <Card key={b.id} className="border-border/60">
                <CardContent className="pt-3 pb-3 flex items-start gap-2">
                  <div className="flex-1 min-w-0">
                    <p className="text-sm font-medium truncate">{b.title || "Untitled"}</p>
                    <div className="flex items-center gap-1.5 mt-0.5">
                      <Badge variant="outline" className="text-[10px] px-1 py-0 h-4">{b.concept_name || "—"}</Badge>
                      <span className="text-[10px] text-muted-foreground">{tokens} tokens</span>
                    </div>
                  </div>
                  <Button variant="ghost" size="sm" onClick={() => removeItem(b.id)} className="h-6 w-6 p-0 shrink-0">
                    <X className="w-3 h-3 text-muted-foreground" />
                  </Button>
                </CardContent>
              </Card>
            );
          })}
        </div>
      )}

      {basket.length > 0 && (
        <>
          <Separator />
          <div className="space-y-3">
            <h4 className="text-xs font-semibold text-muted-foreground uppercase tracking-wider">Publish To</h4>

            <div className="space-y-1">
              {sections.map(s => (
                <label key={s.id} className="flex items-center gap-2 py-1 cursor-pointer">
                  <Checkbox checked={selectedSections.includes(String(s.id))} onCheckedChange={() => toggleSection(String(s.id))} />
                  <span className="text-sm">{s.name} <span className="text-muted-foreground">({s.course_code})</span></span>
                </label>
              ))}
            </div>

            <div>
              <Label className="text-xs text-muted-foreground">Due Date (optional)</Label>
              <Input type="date" value={deadline} onChange={e => setDeadline(e.target.value)} className="text-sm [color-scheme:dark]" />
            </div>

            <div className="flex gap-2">
              <Button
                variant="outline"
                size="sm"
                onClick={() => onPublish(basket, selectedSections, deadline, true)}
                disabled={basket.length === 0}
                className="flex-1"
              >
                <Download className="w-3.5 h-3.5 mr-1" /> Draft
              </Button>
              <Button
                size="sm"
                onClick={() => {
                  if (selectedSections.length === 0) { toast.error("Select at least one section."); return; }
                  onPublish(basket, selectedSections, deadline, false);
                }}
                disabled={basket.length === 0}
                className="flex-1"
              >
                <Upload className="w-3.5 h-3.5 mr-1" /> Publish
              </Button>
            </div>
          </div>
        </>
      )}
    </div>
  );
}

/* ── Databank Browser — Bank templates + seeded ITP1 exercises ─────────── */

function DatabankBrowser({ onAddToBasket }) {
  const [bank, setBank] = useState([]);
  const [loading, setLoading] = useState(true);
  const [query, setQuery] = useState("");
  const [concept, setConcept] = useState("all");
  const [source, setSource] = useState("all");

  useEffect(() => {
    // Fetch from combined databank endpoint (bank templates + ITP1 exercises)
    const promises = [
      api.get("/api/exercises/databank").then(r => r.data || []).catch(() => []),
    ];
    Promise.all(promises).then(([items]) => {
      setBank(items);
      setLoading(false);
    }).catch(() => {
      setBank([]);
      setLoading(false);
    });
  }, []);

  const concepts = useMemo(() => [...new Set(bank.map(e => e.concept))].sort(), [bank]);

  const filtered = useMemo(() => {
    return bank.filter(e =>
      (concept === "all" || e.concept === concept) &&
      (source === "all" || e.source === source) &&
      (!query || e.title.toLowerCase().includes(query.toLowerCase()) || e.description.toLowerCase().includes(query.toLowerCase()))
    );
  }, [bank, concept, source, query]);

  if (loading) return <p className="text-sm text-muted-foreground text-center py-4">Loading databank…</p>;
  if (filtered.length === 0) return <p className="text-sm text-muted-foreground text-center py-4">No exercises in databank.</p>;

  return (
    <Card>
      <CardHeader className="pb-3">
        <CardTitle className="text-sm font-medium flex items-center gap-2">
          <Layers className="w-4 h-4" /> Databank
          <span className="text-xs font-normal text-muted-foreground">— {filtered.length} of {bank.length} exercises</span>
        </CardTitle>
        <div className="flex flex-col sm:flex-row gap-2 mt-2">
          <Input placeholder="Search..." value={query} onChange={e => setQuery(e.target.value)} className="text-sm h-8 flex-1 min-w-0" />
          <div className="flex gap-2 shrink-0">
            <Select value={source} onValueChange={setSource}>
              <SelectTrigger className="h-8 text-sm flex-1 sm:w-28"><SelectValue placeholder="Source" /></SelectTrigger>
              <SelectContent>
                <SelectItem value="all">All ({bank.length})</SelectItem>
                <SelectItem value="bank">Templates ({bank.filter(e=>e.source==='bank').length})</SelectItem>
                <SelectItem value="seeded">ITP1 ({bank.filter(e=>e.source==='seeded').length})</SelectItem>
              </SelectContent>
            </Select>
            <Select value={concept} onValueChange={setConcept}>
              <SelectTrigger className="h-8 text-sm flex-1 sm:w-36"><SelectValue placeholder="Concept" /></SelectTrigger>
              <SelectContent>
                <SelectItem value="all">All Concepts</SelectItem>
                {concepts.map(c => <SelectItem key={c} value={c}>{c}</SelectItem>)}
              </SelectContent>
            </Select>
          </div>
        </div>
      </CardHeader>
      <CardContent className="p-0 max-h-64 overflow-y-auto">
        {filtered.map(e => (
          <button
            key={`${e.source}-${e.id}`}
            type="button"
            onClick={() => onAddToBasket(e)}
            className="w-full text-left px-4 py-2.5 flex items-center gap-3 hover:bg-muted/50 transition-colors border-b border-border/30 last:border-b-0"
          >
            <div className="flex-1 min-w-0">
              <div className="flex items-center gap-2">
                <span className="text-sm font-medium truncate">{e.title}</span>
                <Badge variant="outline" className="text-[10px] px-1 py-0 h-4 shrink-0">{e.concept}</Badge>
                <Badge variant={e.source === 'bank' ? 'secondary' : 'outline'} className="text-[10px] px-1 py-0 h-4 shrink-0">
                  {e.source === 'bank' ? 'Template' : 'ITP1'}
                </Badge>
              </div>
              <p className="text-[11px] text-muted-foreground truncate">{e.description}</p>
            </div>
            <ArrowRight className="w-3.5 h-3.5 text-muted-foreground shrink-0" />
          </button>
        ))}
      </CardContent>
    </Card>
  );
}

/* ── Main Workspace ────────────────────────────────────────────────────── */

export default function ExerciseWorkspace() {
  const navigate = useNavigate();
  const { id } = useParams();
  const isEdit = Boolean(id) && id !== "new" && id !== "workspace";

  const [concepts, setConcepts] = useState([]);
  const [sections, setSections] = useState([]);
  const [loading, setLoading] = useState(true);
  const [basket, setBasket] = useState(loadBasket);
  const [currentExercise, setCurrentExercise] = useState(blankExercise());
  const [currentStep, setCurrentStep] = useState(0);
  const [canAdvance, setCanAdvance] = useState(0);
  const [busy, setBusy] = useState(false);
  const [drafts, setDrafts] = useState([]);
  const [draftsOpen, setDraftsOpen] = useState(false);
  const [draftsLoading, setDraftsLoading] = useState(false);

  useEffect(() => {
    Promise.all([
      api.get("/api/exercises/concepts").then(r => setConcepts(r.data || [])).catch(() => setConcepts([])),
      api.get("/api/sections").then(r => setSections(r.data || [])).catch(() => setSections([])),
      isEdit ? api.get(`/api/exercises/${id}`).then(r => {
        const ex = r.data;
        setCurrentExercise({
          ...blankExercise(),
          title: ex.title || "",
          description: ex.description || "",
          concept_name: ex.concept_name || ex.concept_tags?.find(t => t.is_primary)?.concept_name || ex.concept_names?.[0] || "",
          concept_tags: ex.concept_tags || [],
          starter_code: ex.starter_code || STARTER_CODE,
          test_cases: (ex.test_cases || []).map(tc => ({ input: tc.input || "", expected: tc.expected || "", description: tc.description || "", hidden: !!tc.hidden })),
          time_limit_minutes: ex.time_limit_minutes || 45,
          deadline: ex.deadline ? ex.deadline.slice(0, 10) : "",
          _editId: ex.id,
        });
      }).catch((err) => console.warn('Failed to load exercise:', err.message)) : Promise.resolve(),
    ]).finally(() => setLoading(false));
  }, [id, isEdit]);

  // E2E test hook: expose programmatic concept selection
  useEffect(() => {
    const handler = (e) => {
      if (e.detail?.concept_name) {
        setCurrentExercise(prev => ({ ...prev, concept_name: e.detail.concept_name }));
      }
    };
    document.addEventListener('e2e:setConcept', handler);
    return () => document.removeEventListener('e2e:setConcept', handler);
  }, []);

  useEffect(() => { saveBasket(basket); }, [basket]);

  /* ── Basket actions ─────────────────────────────────────────────── */

  const addToBasket = () => {
    if (!currentExercise.title.trim()) { toast.error("Enter a title before adding to basket."); return; }
    if (!currentExercise.concept_name) { toast.error("Select a concept before adding to basket."); return; }

    setBasket(prev => {
      if (currentExercise.bankId) {
        const idx = prev.findIndex(b => b.bankId === currentExercise.bankId);
        if (idx >= 0) {
          const next = [...prev];
          next[idx] = { ...currentExercise };
          return next;
        }
      }
      if (currentExercise._editId) {
        const idx = prev.findIndex(b => b._editId === currentExercise._editId);
        if (idx >= 0) {
          const next = [...prev];
          next[idx] = { ...currentExercise };
          return next;
        }
      }
      if (currentExercise._draftId) {
        const idx = prev.findIndex(b => b._draftId === currentExercise._draftId);
        if (idx >= 0) {
          const next = [...prev];
          next[idx] = { ...currentExercise };
          return next;
        }
      }
      return [...prev, { ...currentExercise }];
    });
    toast.success(`"${currentExercise.title}" added to basket`);
    setCurrentExercise(blankExercise());
    setCurrentStep(0);
    setCanAdvance(0);
  };

  const clearBasket = () => { setBasket([]); toast.info("Basket cleared"); };

  /* ── Drafts ─────────────────────────────────────────────────────── */

  const fetchDrafts = async () => {
    setDraftsLoading(true);
    try {
      const res = await api.get("/api/exercises/drafts");
      setDrafts(res.data || []);
    } catch {
      setDrafts([]);
    } finally {
      setDraftsLoading(false);
    }
  };

  const toggleDrafts = () => {
    if (!draftsOpen) fetchDrafts();
    setDraftsOpen(prev => !prev);
  };

  const handleUseDraft = (draft) => {
    setCurrentExercise({
      ...blankExercise(),
      _draftId: draft.id,
      title: draft.title || "",
      description: draft.description || "",
      concept_name: draft.concept_name || "",
      concept_tags: (draft.concept_tags || []).map(t => ({
        concept_id: t.concept_id,
        concept_name: t.concept_name,
        weight: t.weight,
        is_primary: t.is_primary,
      })),
      starter_code: draft.starter_code || STARTER_CODE,
      test_cases: (draft.test_cases || []).map(tc => ({
        input: tc.input || "",
        expected: tc.expected || "",
        description: tc.description || "",
        hidden: !!tc.hidden,
      })),
      time_limit_minutes: draft.time_limit_minutes || 45,
      deadline: draft.deadline ? draft.deadline.slice(0, 10) : "",
    });
    setCurrentStep(0);
    setCanAdvance(STEPS.length - 1);
    setDraftsOpen(false);
    toast.info(`"${draft.title}" loaded from drafts — edit and add to basket`);
    document.getElementById("exercise-form")?.scrollIntoView({ behavior: "smooth" });
  };

  const handleDeleteDraft = async (draft) => {
    if (!confirm(`Delete draft "${draft.title}"?`)) return;
    try {
      await api.delete(`/api/exercises/${draft.id}`);
      setDrafts(prev => prev.filter(d => d.id !== draft.id));
      toast.success("Draft deleted");
    } catch (err) {
      toast.error(err.response?.data?.message || "Failed to delete draft");
    }
  };

  /* ── Publish / Draft ────────────────────────────────────────────── */

  const handlePublish = async (items, selectedSections, deadline, asDraft) => {
    if (items.length === 0) return;
    setBusy(true);
    try {
      let totalPublished = 0;
      const errors = [];
      const consumedDraftIds = new Set();
      // Track network-error items on draft saves — the server may have
      // processed the request even though the response didn't arrive
      // (Render cold-start / proxy timeout).
      const networkMisses = [];

      for (const item of items) {
        if (item.bankId) {
          const timeLimitOverrides = {};
          if (item.time_limit_minutes) timeLimitOverrides[item.bankId] = item.time_limit_minutes;

          for (const sectionId of selectedSections) {
            try {
              const r = await api.post("/api/exercises/bulk-publish", {
                section_id: Number(sectionId),
                bank_ids: [item.bankId],
                deadline: deadline || null,
                time_limit_overrides: timeLimitOverrides,
              });
              totalPublished += r.data.exercises?.length || 1;
            } catch (err) {
              errors.push(`${item.title}: ${err.response?.data?.message || err.message}`);
            }
          }
        } else {
          // Create contract still requires concept_name (primary); tags ride along.
          const tagsPayload = [...(item.concept_tags || [])].sort(
            (a, b) => (b.is_primary ? 1 : 0) - (a.is_primary ? 1 : 0)
          );
          const payload = {
            title: item.title,
            description: item.description,
            concept_name: item.concept_name,
            time_limit_minutes: item.time_limit_minutes,
            test_cases: (item.test_cases || []).map(tc => ({
              input: tc.input || "", expected: tc.expected || "",
              description: tc.description || "", hidden: !!tc.hidden,
            })),
            starter_code: item.starter_code || null,
            deadline: deadline || item.deadline || null,
            is_draft: asDraft,
            concept_tags: tagsPayload,
          };

          const targetSections = (asDraft && selectedSections.length === 0) ? [null] : selectedSections;
          for (const sectionId of targetSections) {
            try {
              const { data: created } = await api.post("/api/exercises", {
                ...payload,
                section_id: sectionId != null ? Number(sectionId) : null,
              });
              totalPublished++;
              if (item._draftId) consumedDraftIds.add(item._draftId);
            } catch (err) {
              errors.push(`${item.title}: ${err.response?.data?.message || err.message}`);
              // No HTTP response = network / timeout — server may still have saved it
              if (asDraft && !err.response) {
                networkMisses.push({ item, errIdx: errors.length - 1 });
              }
            }
          }
        }
      }

      // ── Draft recovery: verify network-error saves server-side ─────────
      if (networkMisses.length > 0) {
        try {
          const res = await api.get("/api/exercises/drafts");
          const savedDrafts = res.data || [];
          const recoveredIdx = new Set();
          for (const { item, errIdx } of networkMisses) {
            if (savedDrafts.some(d => d.title === item.title)) {
              totalPublished++;
              recoveredIdx.add(errIdx);
            }
          }
          // Remove recovered errors (splice backwards to preserve indices)
          for (const idx of [...recoveredIdx].sort((a, b) => b - a)) {
            errors.splice(idx, 1);
          }
        } catch {
          // Recovery fetch failed — leave original errors as-is
        }
      }

      if (errors.length > 0) {
        toast.error(`${errors.length} failed: ${errors.slice(0, 2).join(", ")}${errors.length > 2 ? "…" : ""}`);
      }

      // Delete consumed drafts (only when publish succeeded, not asDraft)
      if (!asDraft) {
        for (const item of items) {
          if (item._draftId && consumedDraftIds.has(item._draftId)) {
            try {
              await api.delete(`/api/exercises/${item._draftId}`);
            } catch {
              // Best-effort: draft deletion failure is non-critical
            }
          }
        }
      }

      setBasket([]);
      if (totalPublished > 0) {
        toast.success(asDraft ? `${totalPublished} saved as draft` : `${totalPublished} published`);
      }
      setTimeout(() => navigate("/instructor/exercises"), 1000);
    } catch (err) {
      toast.error(err.response?.data?.message || err.message);
    } finally {
      setBusy(false);
    }
  };

  /* ── Update existing exercise ─────────────────────────────────────── */

  const handleUpdateExercise = async () => {
    if (!currentExercise.title.trim()) { toast.error("Enter a title before updating."); return; }
    const hasPrimary = (currentExercise.concept_tags || []).some(t => t.is_primary) || !!currentExercise.concept_name;
    if (!hasPrimary) { toast.error("Select a concept before updating."); return; }
    if (!id || id === "new" || id === "workspace") return;

    setBusy(true);
    try {
      // Primary tag first, as shown in the editor (breaking change: no concept_name).
      const tagsPayload = [...(currentExercise.concept_tags || [])].sort(
        (a, b) => (b.is_primary ? 1 : 0) - (a.is_primary ? 1 : 0)
      );
      const payload = {
        title: currentExercise.title,
        description: currentExercise.description,
        time_limit_minutes: currentExercise.time_limit_minutes,
        test_cases: (currentExercise.test_cases || []).map(tc => ({
          input: tc.input || "", expected: tc.expected || "",
          description: tc.description || "", hidden: !!tc.hidden,
        })),
        starter_code: currentExercise.starter_code || null,
        deadline: currentExercise.deadline || null,
        is_draft: false,
        concept_tags: tagsPayload,
      };
      const { data: updated } = await api.put(`/api/exercises/${id}`, payload);
      toast.success("Exercise updated");
      setTimeout(() => navigate("/instructor/exercises"), 800);
    } catch (err) {
      toast.error(err.response?.data?.message || err.message);
    } finally {
      setBusy(false);
    }
  };

  /* ── Databank click → load into editor ──────────────────────────── */

  const handleDatabankClick = (entry) => {
    setCurrentExercise({
      ...blankExercise(),
      bankId: entry.source === 'bank' ? entry.id : null,
      title: entry.title || "",
      description: entry.description || "",
      concept_name: entry.concept || "",
      starter_code: entry.starter_code || STARTER_CODE,
      test_cases: (entry.test_cases || []).map(tc => ({
        input: tc.input || "", expected: tc.expected || "",
        description: tc.description || "", hidden: !!tc.hidden,
      })),
      time_limit_minutes: entry.sequence_order === 1 ? 30 : entry.sequence_order === 2 ? 45 : 60,
      deadline: "",
    });
    setCurrentStep(0);
    setCanAdvance(STEPS.length - 1);
    toast.info(`"${entry.title}" loaded — edit and add to basket`);
    document.getElementById("exercise-form")?.scrollIntoView({ behavior: "smooth" });
  };

  if (loading) {
    return <InstructorDashboardShell><p className="text-muted-foreground">Loading…</p></InstructorDashboardShell>;
  }

  return (
    <InstructorDashboardShell>
      <div className="space-y-6">
        {/* Header */}
        <div className="flex items-center gap-4">
          <Button asChild variant="ghost" size="sm">
            <Link to="/instructor/exercises"><ChevronLeft className="w-4 h-4 mr-1" /> Back</Link>
          </Button>
          <div className="min-w-0">
            <h1 className="text-2xl font-semibold tracking-tight">
              {isEdit ? "Edit Exercise" : "Exercise Workspace"}
            </h1>
            <p className="text-sm text-muted-foreground">
              {isEdit ? "Modify an existing exercise." : "Build exercises step by step, add to basket, then publish."}
            </p>
          </div>
          {!isEdit && (
            <Button variant="ghost" size="sm" onClick={toggleDrafts} className="ml-auto">
              <FileText className="w-4 h-4 mr-1.5" />
              View Drafts
              {drafts.length > 0 && (
                <Badge variant="secondary" className="text-xs ml-1.5">{drafts.length}</Badge>
              )}
            </Button>
          )}
        </div>

        {/* Step Indicator */}
        <StepIndicator currentStep={currentStep} canAdvance={canAdvance} onStepClick={setCurrentStep} />

        {/* Drafts Panel */}
        {draftsOpen && (
          <Card className="border-white/[0.08] bg-white/[0.02] backdrop-blur-xl">
            <CardHeader className="pb-3">
              <div className="flex items-center justify-between">
                <CardTitle className="text-sm font-medium flex items-center gap-2">
                  <FileText className="w-4 h-4" /> Your Drafts
                  <Badge variant="secondary" className="text-xs">{drafts.length}</Badge>
                </CardTitle>
                <Button variant="ghost" size="sm" onClick={() => setDraftsOpen(false)} className="h-6 w-6 p-0">
                  <X className="w-3.5 h-3.5" />
                </Button>
              </div>
            </CardHeader>
            <CardContent className="pt-0">
              {draftsLoading ? (
                <p className="text-sm text-muted-foreground text-center py-4">Loading drafts…</p>
              ) : drafts.length === 0 ? (
                <p className="text-sm text-muted-foreground text-center py-4">No draft exercises yet.</p>
              ) : (
                <div className="space-y-1.5 max-h-64 overflow-y-auto">
                  {drafts.map(d => (
                    <div key={d.id} className="flex items-center gap-3 px-3 py-2.5 rounded-lg border border-border/30 hover:bg-muted/30 transition-colors">
                      <div className="flex-1 min-w-0">
                        <p className="text-sm font-medium truncate">{d.title || "Untitled"}</p>
                        <div className="flex items-center gap-1.5 mt-0.5">
                          <Badge variant="outline" className="text-[10px] px-1 py-0 h-4">{d.concept_name || "—"}</Badge>
                          <span className="text-[10px] text-muted-foreground">
                            {new Date(d.created_at).toLocaleDateString()}
                          </span>
                        </div>
                      </div>
                      <div className="flex items-center gap-1 shrink-0">
                        <Button variant="ghost" size="sm" onClick={() => handleUseDraft(d)} className="h-7 text-xs">
                          <ArrowRight className="w-3 h-3 mr-1" /> Use Draft
                        </Button>
                        <Button variant="ghost" size="sm" onClick={() => handleDeleteDraft(d)} className="h-7 w-7 p-0">
                          <Trash2 className="w-3 h-3 text-destructive" />
                        </Button>
                      </div>
                    </div>
                  ))}
                </div>
              )}
            </CardContent>
          </Card>
        )}

        <div className="grid grid-cols-1 lg:grid-cols-3 xl:grid-cols-5 gap-6">
          {/* Main form */}
          <div className="lg:col-span-2 xl:col-span-3 min-w-0" id="exercise-form">
            <Card>
              <CardHeader className="pb-3">
                <div className="flex items-center justify-between gap-3">
                  <div className="min-w-0">
                    <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
                      Step {currentStep + 1} of {STEPS.length}
                    </p>
                    <CardTitle className="text-sm mt-0.5">{STEPS[currentStep]?.label}</CardTitle>
                  </div>
                  {currentExercise.title && (
                    <Badge variant="outline" className="text-xs truncate max-w-[40%]">{currentExercise.title}</Badge>
                  )}
                </div>
              </CardHeader>
              <CardContent className="pt-6">
                <ExerciseForm
                  exercise={currentExercise}
                  onChange={setCurrentExercise}
                  concepts={concepts}
                  step={currentStep}
                />

                {/* Navigation */}
                <div className="flex flex-wrap items-center justify-between gap-3 mt-6 pt-4 border-t border-white/[0.06]">
                  <Button variant="ghost" disabled={currentStep === 0} onClick={() => setCurrentStep(s => s - 1)}>
                    <ArrowLeft className="w-4 h-4 mr-1" /> Previous
                  </Button>

                  {currentStep < STEPS.length - 1 ? (
                    <Button onClick={() => {
                      setCanAdvance(Math.max(canAdvance, currentStep + 1));
                      setCurrentStep(s => s + 1);
                    }}>
                      Next <ArrowRight className="w-4 h-4 ml-1" />
                    </Button>
                  ) : isEdit ? (
                    <Button onClick={handleUpdateExercise} disabled={busy}>
                      <Save className="w-4 h-4 mr-1" /> {busy ? "Saving..." : "Update Exercise"}
                    </Button>
                  ) : (
                    <div className="flex flex-wrap gap-2">
                      <Button variant="outline" onClick={addToBasket}>
                        <Plus className="w-4 h-4 mr-1" /> Add to Basket
                      </Button>
                      <Button onClick={addToBasket}>
                        <Layers className="w-4 h-4 mr-1" /> Add &amp; New
                      </Button>
                    </div>
                  )}
                </div>
              </CardContent>
            </Card>

            {/* Databank */}
            <div className="mt-6">
              <DatabankBrowser onAddToBasket={handleDatabankClick} />
            </div>
          </div>

          {/* Basket sidebar */}
          <div className="lg:col-span-1 xl:col-span-2 min-w-0">
            <div className="sticky top-6">
              <BasketPanel
                basket={basket}
                setBasket={setBasket}
                sections={sections}
                onPublish={handlePublish}
                onClear={clearBasket}
              />
            </div>
          </div>
        </div>
      </div>
    </InstructorDashboardShell>
  );
}
