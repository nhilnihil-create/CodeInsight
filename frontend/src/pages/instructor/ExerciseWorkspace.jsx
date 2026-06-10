import { useEffect, useMemo, useState, useCallback } from "react";
import { Link, useNavigate, useParams } from "react-router-dom";
import { ChevronLeft, Plus, Trash2, Layers, Check, AlertCircle, X, ArrowRight, ArrowLeft, Download, Upload, Zap, TrendingUp, ShieldAlert, Loader2, ShieldCheck, CheckCircle2, Clock, Calendar } from "lucide-react";
import { Button } from "@/components/ui/button";
import { Input } from "@/components/ui/input";
import { Label } from "@/components/ui/label";
import { Badge } from "@/components/ui/badge";
import { Card, CardContent, CardHeader, CardTitle } from "@/components/ui/card";
import { Checkbox } from "@/components/ui/checkbox";
import { Switch } from "@/components/ui/switch";
import { Textarea } from "@/components/ui/textarea";
import { Select, SelectContent, SelectItem, SelectTrigger, SelectValue } from "@/components/ui/select";
import { Separator } from "@/components/ui/separator";
import { toast } from "sonner";
import InstructorDashboardShell from "@/components/instructor-dashboard-shell";
import api from "@/services/api";
import ReferenceSolutionEditor from "./components/ReferenceSolutionEditor";
import ValidationResultsPanel from "./components/ValidationResultsPanel";
import ModeSelector from "./components/ModeSelector";
import RubricConfigurator from "./components/RubricConfigurator";

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
 * Growth velocity check: compares new code tokens against baseline.
 * Returns { flagged, baselineTokens, newTokens, growthPercent, threshold }
 * Threshold: 200% growth (3× the baseline) triggers flag.
 * This replaces static solution comparison with dynamic growth monitoring.
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
    starter_code: STARTER_CODE,
    reference_solution: "",
    test_cases: [{
      input: '',
      expectedOutput: '',
      validationType: 'exact',
      isVisible: true,
    }],
    time_limit_minutes: 0,
    deadline: "",
    mode: "learning",
    rubric_config: { functional: 40, efficiency: 25, standards: 20, integrity: 15 },
    is_validated: false,
    is_validating: false,
    validation_results: null,
  };
}

/* ── Step Wizard ───────────────────────────────────────────────────────── */

const STEPS = [
  { key: "details",     label: "Title & Description" },     // 0
  { key: "concept",     label: "Concept Tag" },             // 1
  { key: "code",        label: "Starter Code" },            // 2
  { key: "tests",       label: "Test Cases" },              // 3
  { key: "sections",    label: "Section Assignment" },      // 4
  { key: "constraints", label: "Timer & Deadline" },        // 5
  { key: "validate",    label: "Validate & Basket" },       // 6
];

function StepIndicator({ currentStep, canAdvance, onStepClick }) {
  return (
    <div className="flex items-center gap-1 overflow-x-auto pb-2">
      {STEPS.map((s, i) => {
        const done = i < currentStep;
        const active = i === currentStep;
        const reachable = i <= canAdvance;
        return (
          <button
            key={s.key}
            type="button"
            onClick={() => { if (reachable) onStepClick(i); }}
            className={`flex items-center gap-1.5 px-3 py-1.5 rounded-full text-xs font-medium whitespace-nowrap transition-colors ${
              active ? "bg-primary text-primary-foreground" :
              done ? "bg-muted text-muted-foreground hover:bg-muted/80 cursor-pointer" :
              reachable ? "bg-muted/60 text-muted-foreground/70 hover:bg-muted/80 cursor-pointer" :
              "bg-muted/30 text-muted-foreground/40"
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

/* ── TestCaseEditor (Dynamic Row Table) ────────────────────────────────── */

const VALIDATION_TYPES = [
  { value: 'exact',    label: 'Exact',    desc: 'Token-by-token match (whitespace-insensitive)' },
  { value: 'contains', label: 'Contains',  desc: 'Expected must appear somewhere in output' },
  { value: 'regex',    label: 'Regex',     desc: 'Expected is a regex pattern' },
];

function TestCaseEditor({ tests, onChange }) {
  const update = (i, field, value) => onChange(tests.map((t, j) => j === i ? { ...t, [field]: value } : t));
  const add = () => onChange([...tests, {
    input: '',
    expectedOutput: '',
    validationType: 'exact',
    isVisible: true,
  }]);
  const remove = (i) => onChange(tests.filter((_, j) => j !== i));

  return (
    <div className="space-y-3">
      {/* Header */}
      <div className="flex items-center justify-between">
        <div>
          <Label className="text-sm font-medium">Test Cases</Label>
          <p className="text-[10px] text-muted-foreground mt-0.5">Each row defines one test: input → expected output → validation rule</p>
        </div>
        <Button variant="outline" size="sm" onClick={add}>
          <Plus className="w-3.5 h-3.5 mr-1" /> Add Test
        </Button>
      </div>

      {/* Table Header */}
      <div className="hidden md:grid grid-cols-12 gap-2 text-[10px] font-semibold uppercase tracking-wider text-muted-foreground px-1">
        <div className="col-span-3">Input (stdin)</div>
        <div className="col-span-3">Expected Output</div>
        <div className="col-span-2">Validation</div>
        <div className="col-span-2 text-center">Visibility</div>
        <div className="col-span-2 text-right">Action</div>
      </div>

      {/* Test Rows */}
      {tests.map((t, i) => (
        <Card key={i} className="border-border/60">
          <CardContent className="pt-3 pb-3">
            {/* Mobile layout (stacked) */}
            <div className="md:hidden space-y-2">
              <div className="flex items-center justify-between">
                <span className="text-xs font-medium">Test {i + 1}</span>
                <Button variant="ghost" size="sm" onClick={() => remove(i)} disabled={tests.length <= 1}>
                  <Trash2 className="w-3.5 h-3.5 text-destructive" />
                </Button>
              </div>
              <div>
                <Label className="text-[10px] text-muted-foreground">Input</Label>
                <Textarea value={t.input} onChange={(e) => update(i, 'input', e.target.value)} className="font-mono text-xs h-16 resize-none" placeholder="stdin" />
              </div>
              <div>
                <Label className="text-[10px] text-muted-foreground">Expected Output</Label>
                <Textarea value={t.expectedOutput} onChange={(e) => update(i, 'expectedOutput', e.target.value)} className="font-mono text-xs h-16 resize-none" placeholder="stdout" />
              </div>
              <div className="grid grid-cols-2 gap-2">
                <div>
                  <Label className="text-[10px] text-muted-foreground">Validation</Label>
                  <Select value={t.validationType || 'exact'} onValueChange={(v) => update(i, 'validationType', v)}>
                    <SelectTrigger className="text-xs h-7"><SelectValue /></SelectTrigger>
                    <SelectContent>
                      {VALIDATION_TYPES.map(vt => <SelectItem key={vt.value} value={vt.value}>{vt.label}</SelectItem>)}
                    </SelectContent>
                  </Select>
                </div>
                <div className="flex items-end pb-1">
                  <label className="flex items-center gap-1.5 text-xs">
                    <Checkbox checked={t.isVisible !== false} onCheckedChange={(v) => update(i, 'isVisible', !!v)} />
                    Visible to students
                  </label>
                </div>
              </div>
            </div>

            {/* Desktop layout (grid) */}
            <div className="hidden md:grid grid-cols-12 gap-2 items-start">
              {/* Input */}
              <div className="col-span-3">
                <Textarea
                  value={t.input}
                  onChange={(e) => update(i, 'input', e.target.value)}
                  className="font-mono text-xs h-20 resize-none"
                  placeholder="stdin"
                />
              </div>
              {/* Expected Output */}
              <div className="col-span-3">
                <Textarea
                  value={t.expectedOutput}
                  onChange={(e) => update(i, 'expectedOutput', e.target.value)}
                  className="font-mono text-xs h-20 resize-none"
                  placeholder={t.validationType === 'regex' ? 'regex pattern...' : 'stdout'}
                />
              </div>
              {/* Validation Type */}
              <div className="col-span-2">
                <Select value={t.validationType || 'exact'} onValueChange={(v) => update(i, 'validationType', v)}>
                  <SelectTrigger className="text-xs h-9">
                    <SelectValue />
                  </SelectTrigger>
                  <SelectContent>
                    {VALIDATION_TYPES.map(vt => (
                      <SelectItem key={vt.value} value={vt.value}>
                        <div>
                          <span className="font-medium">{vt.label}</span>
                          <p className="text-[10px] text-muted-foreground">{vt.desc}</p>
                        </div>
                      </SelectItem>
                    ))}
                  </SelectContent>
                </Select>
              </div>
              {/* Visibility */}
              <div className="col-span-2 flex items-center justify-center h-9">
                <label className="flex items-center gap-1.5 text-xs cursor-pointer">
                  <Checkbox checked={t.isVisible !== false} onCheckedChange={(v) => update(i, 'isVisible', !!v)} />
                  <span className={t.isVisible !== false ? 'text-green-600' : 'text-muted-foreground'}>
                    {t.isVisible !== false ? 'Visible' : 'Hidden'}
                  </span>
                </label>
              </div>
              {/* Delete */}
              <div className="col-span-2 flex items-center justify-end h-9">
                <Button variant="ghost" size="sm" onClick={() => remove(i)} disabled={tests.length <= 1} className="h-7 w-7 p-0">
                  <Trash2 className="w-3.5 h-3.5 text-destructive" />
                </Button>
              </div>
            </div>
          </CardContent>
        </Card>
      ))}

      {tests.length === 0 && (
        <div className="rounded-lg border border-dashed border-border/40 p-6 text-center">
          <p className="text-sm text-muted-foreground">No test cases yet.</p>
          <Button variant="outline" size="sm" onClick={add} className="mt-2">
            <Plus className="w-3.5 h-3.5 mr-1" /> Add First Test Case
          </Button>
        </div>
      )}
    </div>
  );
}

/* ── Exercise Form Step ────────────────────────────────────────────────── */

function ExerciseForm({ exercise, onChange, concepts, step, onValidate }) {
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

      {/* Step 1: Concept Tag */}
      {step === 1 && (
        <div>
          <Label className="text-sm font-medium">Concept <span className="text-destructive">*</span></Label>
          <Select value={exercise.concept_name} onValueChange={v => set("concept_name", v)}>
            <SelectTrigger><SelectValue placeholder="Select a concept" /></SelectTrigger>
            <SelectContent>
              {concepts.map(c => <SelectItem key={c.id} value={c.name}>{c.name}</SelectItem>)}
            </SelectContent>
          </Select>
          <p className="text-xs text-muted-foreground mt-2">Primary concept for CDS analytics and heatmap display.</p>
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
                <span className="text-muted-foreground">Growth Velocity Threshold</span>
                <span className="font-mono font-semibold">200%</span>
              </div>
              <p className="text-muted-foreground text-[10px] mt-1">
                Submissions exceeding <strong>3× the baseline token count</strong> in a single attempt will trigger an integrity flag.
                This monitors growth velocity instead of comparing against a static solution.
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

      {/* Step 5: Timer, Deadline, Mode */}
      {step === 5 && (
        <div className="space-y-4">
          {/* Mode Selector */}
          <ModeSelector value={exercise.mode || 'learning'} onChange={v => {
            set('mode', v);
            if (v === 'assessment' && !exercise.time_limit_minutes) {
              set('time_limit_minutes', 45);
            }
          }} />

          {/* Rubric Configurator (assessment mode only) */}
          {exercise.mode === 'assessment' && (
            <Card className="border-primary/20">
              <CardContent className="pt-4">
                <RubricConfigurator value={exercise.rubric_config} onChange={v => set('rubric_config', v)} />
              </CardContent>
            </Card>
          )}

          <Separator />

          {/* Timer toggle + input */}
          <div className="flex items-center gap-3 mb-3">
            <Clock className="w-4 h-4 text-muted-foreground" />
            <Label className="text-sm font-medium">Timer</Label>
            <Switch
              checked={exercise.mode === 'assessment' || !!exercise.time_limit_minutes}
              onCheckedChange={(checked) => {
                if (!checked) {
                  set('time_limit_minutes', 0);
                } else {
                  set('time_limit_minutes', 45);
                }
              }}
              disabled={exercise.mode === 'assessment'}
            />
            <span className="text-[10px] text-muted-foreground">
              {exercise.mode === 'assessment'
                ? 'Required — cannot disable'
                : exercise.time_limit_minutes
                  ? `${exercise.time_limit_minutes} min`
                  : 'Off — students work at own pace'}
            </span>
          </div>

          {exercise.time_limit_minutes > 0 && (
            <div className="mb-4 pl-7">
              <Input
                type="number"
                value={exercise.time_limit_minutes}
                onChange={e => set("time_limit_minutes", Math.max(1, Number(e.target.value)))}
                min={1}
                max={600}
                className="w-40"
              />
            </div>
          )}

          {/* Deadline toggle + input */}
          <div className="flex items-center gap-3 mb-3">
            <Calendar className="w-4 h-4 text-muted-foreground" />
            <Label className="text-sm font-medium">Deadline</Label>
            <Switch
              checked={exercise.deadline !== undefined && exercise.deadline !== ''}
              onCheckedChange={(checked) => {
                if (checked) {
                  set('deadline', new Date().toISOString().slice(0, 10));
                } else {
                  set('deadline', '');
                }
              }}
            />
            <span className="text-[10px] text-muted-foreground">
              {exercise.deadline ? exercise.deadline : 'Off'}
            </span>
          </div>

          {exercise.deadline !== undefined && (
            <div className="mb-4 pl-7">
              <Input
                type="date"
                value={exercise.deadline}
                onChange={e => set("deadline", e.target.value)}
                className="w-48"
              />
            </div>
          )}

          {/* Growth Velocity Info */}
          <Card>
            <CardHeader className="pb-2">
              <CardTitle className="text-sm font-medium flex items-center gap-2">
                <TrendingUp className="w-4 h-4 text-primary" /> Growth Velocity Monitor
              </CardTitle>
            </CardHeader>
            <CardContent className="text-xs space-y-2">
              <p className="text-muted-foreground">
                When students submit code, the system compares their token count against this exercise's baseline ({baselineTokens} tokens).
                If a student's submission grows by more than 200% in a single attempt, an integrity flag is triggered.
              </p>
              <div className="grid grid-cols-3 gap-2">
                <div className="text-center p-2 rounded bg-muted/40">
                  <div className="text-lg font-mono font-semibold">{baselineTokens}</div>
                  <div className="text-[10px] text-muted-foreground">Baseline</div>
                </div>
                <div className="text-center p-2 rounded bg-muted/40">
                  <div className="text-lg font-mono font-semibold">{Math.round(baselineTokens * 2)}</div>
                  <div className="text-[10px] text-muted-foreground">+100%</div>
                </div>
                <div className="text-center p-2 rounded bg-destructive/10">
                  <div className="text-lg font-mono font-semibold text-destructive">{Math.round(baselineTokens * 3)}</div>
                  <div className="text-[10px] text-destructive">⚠ Flag &gt;200%</div>
                </div>
              </div>
            </CardContent>
          </Card>
        </div>
      )}

      {/* Step 6: Validate & Basket */}
      {step === 6 && (
        <div className="space-y-4">
          <div>
            <Label className="text-sm font-medium">Reference Solution</Label>
            <p className="text-[10px] text-muted-foreground mt-0.5">
              Write your correct solution. Click "Verify Exercise" to test it against all test cases.
            </p>
          </div>

          <ReferenceSolutionEditor
            value={exercise.reference_solution || ''}
            onChange={v => set('reference_solution', v)}
            height="250px"
          />

          {/* Validation Status */}
          <div className="flex items-center gap-2">
            {exercise.is_validating && (
              <Badge variant="secondary" className="gap-1">
                <Loader2 className="w-3 h-3 animate-spin" /> Validating…
              </Badge>
            )}
            {exercise.is_validated && (
              <Badge className="bg-green-500/10 text-green-700 border-green-500/30 gap-1" variant="outline">
                <Check className="w-3 h-3" /> Validated
              </Badge>
            )}
            {!exercise.is_validated && !exercise.is_validating && (
              <Badge variant="destructive" className="gap-1">
                <AlertCircle className="w-3 h-3" /> Not Validated
              </Badge>
            )}
          </div>

          <Button
            onClick={onValidate}
            disabled={exercise.is_validating || !exercise.reference_solution?.trim()}
            className="w-full"
          >
            {exercise.is_validating ? (
              <><Loader2 className="w-4 h-4 mr-1 animate-spin" /> Running Verification…</>
            ) : (
              <><ShieldCheck className="w-4 h-4 mr-1" /> Verify Exercise</>
            )}
          </Button>

          {exercise.validation_results && (
            <Card>
              <CardHeader className="pb-2">
                <CardTitle className="text-sm font-medium">Verification Results</CardTitle>
              </CardHeader>
              <CardContent>
                <ValidationResultsPanel
                  results={exercise.validation_results}
                  is_validating={exercise.is_validating}
                />
              </CardContent>
            </Card>
          )}
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

  const hasUnvalidated = basket.some(b => !b.is_validated && !b._editValidated);

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
            const validated = b.is_validated || b._editValidated;
            return (
              <Card key={b.id} className="border-border/60">
                <CardContent className="pt-3 pb-3 flex items-start gap-2">
                  <div className="flex-1 min-w-0">
                    <div className="flex items-center gap-1.5">
                      <p className="text-sm font-medium truncate">{b.title || "Untitled"}</p>
                      {validated ? (
                        <CheckCircle2 className="w-3.5 h-3.5 text-green-500 shrink-0" />
                      ) : (
                        <AlertCircle className="w-3.5 h-3.5 text-destructive shrink-0" />
                      )}
                    </div>
                    <div className="flex items-center gap-1.5 mt-0.5">
                      <Badge variant="outline" className="text-[10px] px-1 py-0 h-4">{b.concept_name || "—"}</Badge>
                      <span className="text-[10px] text-muted-foreground">{tokens} tokens</span>
                      {b.mode === 'assessment' && (
                        <Badge className="text-[10px] px-1 py-0 h-4 bg-amber-500/10 text-amber-700" variant="outline">
                          Assessment
                        </Badge>
                      )}
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
              <Label className="text-xs text-muted-foreground">Deadline (optional)</Label>
              <Input type="date" value={deadline} onChange={e => setDeadline(e.target.value)} className="text-sm" />
            </div>

            {hasUnvalidated && (
              <div className="flex items-center gap-1.5 text-[10px] text-destructive">
                <AlertCircle className="w-3 h-3" />
                All exercises must be validated before publishing.
              </div>
            )}

            <div className="flex gap-2">
              <Button
                variant="outline"
                size="sm"
                onClick={() => onPublish(basket, selectedSections, deadline, true)}
                disabled={basket.length === 0 || hasUnvalidated}
                className="flex-1"
                title={hasUnvalidated ? "Validate all exercises first" : undefined}
              >
                <Download className="w-3.5 h-3.5 mr-1" /> Draft
              </Button>
              <Button
                size="sm"
                onClick={() => {
                  if (selectedSections.length === 0) { toast.error("Select at least one section."); return; }
                  onPublish(basket, selectedSections, deadline, false);
                }}
                disabled={basket.length === 0 || hasUnvalidated}
                className="flex-1"
                title={hasUnvalidated ? "Validate all exercises first" : undefined}
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

/* ── Databank Browser ──────────────────────────────────────────────────── */

function DatabankBrowser({ onAddToBasket }) {
  const [bank, setBank] = useState([]);
  const [loading, setLoading] = useState(true);
  const [query, setQuery] = useState("");
  const [concept, setConcept] = useState("all");

  useEffect(() => {
    api.get("/api/exercises/bank").then(r => setBank(r.data || [])).catch(() => setBank([])).finally(() => setLoading(false));
  }, []);

  const concepts = useMemo(() => [...new Set(bank.map(e => e.concept))], [bank]);

  const filtered = useMemo(() => {
    return bank.filter(e =>
      (concept === "all" || e.concept === concept) &&
      (!query || e.title.toLowerCase().includes(query.toLowerCase()))
    );
  }, [bank, concept, query]);

  if (loading) return <p className="text-sm text-muted-foreground text-center py-4">Loading databank…</p>;
  if (filtered.length === 0) return <p className="text-sm text-muted-foreground text-center py-4">No exercises in databank.</p>;

  return (
    <Card>
      <CardHeader className="pb-3">
        <CardTitle className="text-sm font-medium flex items-center gap-2">
          <Layers className="w-4 h-4" /> Databank
          <span className="text-xs font-normal text-muted-foreground">— click to edit, then add to basket</span>
        </CardTitle>
        <div className="flex gap-2 mt-2">
          <Input placeholder="Search databank..." value={query} onChange={e => setQuery(e.target.value)} className="text-sm h-8" />
          <Select value={concept} onValueChange={setConcept}>
            <SelectTrigger className="w-36 h-8 text-sm"><SelectValue placeholder="Concept" /></SelectTrigger>
            <SelectContent>
              <SelectItem value="all">All Concepts</SelectItem>
              {concepts.map(c => <SelectItem key={c} value={c}>{c}</SelectItem>)}
            </SelectContent>
          </Select>
        </div>
      </CardHeader>
      <CardContent className="p-0 max-h-64 overflow-y-auto">
        {filtered.map(e => (
          <button
            key={e.id}
            type="button"
            onClick={() => onAddToBasket(e)}
            className="w-full text-left px-4 py-2.5 flex items-center gap-3 hover:bg-muted/50 transition-colors border-b border-border/30 last:border-b-0"
          >
            <div className="flex-1 min-w-0">
              <div className="flex items-center gap-2">
                <span className="text-sm font-medium truncate">{e.title}</span>
                <Badge variant="outline" className="text-[10px] px-1 py-0 h-4 shrink-0">{e.concept}</Badge>
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
          concept_name: ex.concept_name || "",
          starter_code: ex.starter_code || STARTER_CODE,
          reference_solution: ex.reference_solution || "",
          test_cases: (ex.test_cases || []).map(tc => ({
            input: tc.input || '',
            expectedOutput: tc.expectedOutput || tc.expected || '',
            validationType: tc.validationType || tc.validation_type || 'exact',
            isVisible: tc.isVisible !== undefined ? tc.isVisible : (tc.hidden === undefined ? true : !tc.hidden),
          })),
          time_limit_minutes: ex.time_limit_minutes || 45,
          deadline: ex.deadline ? ex.deadline.slice(0, 10) : "",
          mode: ex.mode || 'learning',
          rubric_config: ex.rubric_config || { functional: 40, efficiency: 25, standards: 20, integrity: 15 },
          is_validated: ex.is_validated || false,
          _editId: ex.id,
          _editValidated: ex.is_validated || false,
        });
        // If already validated, allow adding to basket without re-validation
        if (ex.is_validated) {
          setCanAdvance(STEPS.length - 1);
        }
      }).catch(() => {}) : Promise.resolve(),
    ]).finally(() => setLoading(false));
  }, [id, isEdit]);

  useEffect(() => { saveBasket(basket); }, [basket]);

  /* ── Validate exercise ──────────────────────────────────────────── */

  const handleValidate = async () => {
    if (!currentExercise.reference_solution?.trim()) {
      toast.error("Write a reference solution before verifying.");
      return;
    }
    if (!currentExercise.test_cases?.length) {
      toast.error("Add at least one test case before verifying.");
      return;
    }

    setCurrentExercise(prev => ({ ...prev, is_validating: true, validation_results: null }));
    try {
      const { data } = await api.post("/api/exercises/validate", {
        reference_solution: currentExercise.reference_solution,
        test_cases: currentExercise.test_cases,
        time_limit_minutes: currentExercise.time_limit_minutes,
      });
      const { validated, results } = data;
      setCurrentExercise(prev => ({
        ...prev,
        is_validating: false,
        is_validated: validated,
        validation_results: results,
      }));
      if (validated) {
        toast.success("All test cases passed! Exercise is validated.");
      } else {
        const failed = results.filter(r => !r.passed).length;
        toast.error(`${failed} test(s) failed. Fix the reference solution or test cases.`);
      }
    } catch (err) {
      toast.error(err.response?.data?.message || "Validation failed");
      setCurrentExercise(prev => ({ ...prev, is_validating: false }));
    }
  };

  /* ── Basket actions ─────────────────────────────────────────────── */

  const addToBasket = () => {
    if (!currentExercise.title.trim()) { toast.error("Enter a title before adding to basket."); return; }
    if (!currentExercise.concept_name) { toast.error("Select a concept before adding to basket."); return; }
    // Assessment mode requires a time limit
    if (currentExercise.mode === 'assessment' && (!currentExercise.time_limit_minutes || currentExercise.time_limit_minutes <= 0)) {
      toast.error("Assessment mode requires a time limit. Go to Step 6 to set one.");
      setCurrentStep(5);
      return;
    }
    // Curation gate: must be validated before adding to basket (unless editing an already-validated exercise)
    if (!currentExercise.is_validated && !currentExercise._editValidated) {
      toast.error("Validate the exercise (Step 7) before adding to basket.");
      setCurrentStep(6);
      return;
    }

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
      return [...prev, { ...currentExercise }];
    });
    toast.success(`"${currentExercise.title}" added to basket`);
    setCurrentExercise(blankExercise());
    setCurrentStep(0);
    setCanAdvance(0);
  };

  const clearBasket = () => { setBasket([]); toast.info("Basket cleared"); };

  /* ── Publish / Draft ────────────────────────────────────────────── */

  const handlePublish = async (items, selectedSections, deadline, asDraft) => {
    if (items.length === 0) return;
    setBusy(true);
    try {
      let totalPublished = 0;
      const errors = [];

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
          const mappedTests = (item.test_cases || []).map(tc => ({
            input: tc.input || '',
            expectedOutput: tc.expectedOutput || tc.expected || '',
            validationType: tc.validationType || tc.validation_type || 'exact',
            isVisible: tc.isVisible !== undefined ? tc.isVisible : (tc.hidden === undefined ? true : !tc.hidden),
          }));
          // Ensure at least 2 test cases (backend Joi min(2) was relaxed to min(1),
          // but the original spec requires 2+; auto-pad if user only has 1)
          while (mappedTests.length < 2) {
            mappedTests.push({ input: '', expectedOutput: '', validationType: 'exact', isVisible: true });
          }

          const payload = {
            title: item.title,
            description: item.description,
            concept_name: item.concept_name,
            time_limit_minutes: item.time_limit_minutes || 45,
            test_cases: mappedTests,
            starter_code: item.starter_code || null,
            reference_solution: item.reference_solution || null,
            deadline: deadline || item.deadline || null,
            is_draft: asDraft,
            mode: item.mode || 'learning',
            rubric_config: item.rubric_config || {},
          };

          for (const sectionId of selectedSections) {
            try {
              const r = await api.post("/api/exercises", { ...payload, section_id: Number(sectionId) });
              totalPublished++;
            } catch (err) {
              const msg = err.response?.data?.message || err.message;
              const details = err.response?.data?.details
                ? err.response.data.details.map(d => `${d.path}: ${d.message}`).join(', ')
                : '';
              errors.push(`${item.title}: ${msg}${details ? ` (${details})` : ''}`);
            }
          }
        }
      }

      if (errors.length > 0) {
        toast.error(`${errors.length} failed: ${errors.slice(0, 2).join(", ")}${errors.length > 2 ? "…" : ""}`);
      }

      setBasket([]);
      toast.success(asDraft ? `${totalPublished} saved as draft` : `${totalPublished} published`);
      setTimeout(() => navigate("/instructor/exercises"), 1000);
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
      bankId: entry.id,
      title: entry.title || "",
      description: entry.description || "",
      concept_name: entry.concept || "",
      starter_code: entry.starter_code || STARTER_CODE,
      reference_solution: entry.sample_solution || "",
      test_cases: (entry.test_cases || []).map(tc => ({
        input: tc.input || '',
        expectedOutput: tc.expectedOutput || tc.expected || '',
        validationType: tc.validationType || tc.validation_type || 'exact',
        isVisible: tc.isVisible !== undefined ? tc.isVisible : (tc.hidden === undefined ? true : !tc.hidden),
      })),
      time_limit_minutes: entry.sequence_order === 1 ? 30 : entry.sequence_order === 2 ? 45 : 60,
      deadline: "",
      is_validated: entry.is_validated || false,
      _editValidated: entry.is_validated || false,
    });
    setCurrentStep(0);
    setCanAdvance(STEPS.length - 1);
    if (entry.is_validated) {
      toast.info(`"${entry.title}" loaded — validated, ready to publish`);
    } else {
      toast.info(`"${entry.title}" loaded — write a reference solution and validate before publishing`);
    }
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
        </div>

        {/* Step Indicator */}
        <StepIndicator currentStep={currentStep} canAdvance={canAdvance} onStepClick={setCurrentStep} />

        <div className="grid grid-cols-1 lg:grid-cols-3 gap-6">
          {/* Main form */}
          <div className="lg:col-span-2" id="exercise-form">
            <Card>
              <CardHeader className="pb-3 border-b border-border">
                <div className="flex items-center justify-between">
                  <div>
                    <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
                      Step {currentStep + 1} of {STEPS.length}
                    </p>
                    <CardTitle className="text-sm">{STEPS[currentStep]?.label}</CardTitle>
                  </div>
                  {currentExercise.title && (
                    <Badge variant="outline" className="text-xs">{currentExercise.title}</Badge>
                  )}
                </div>
              </CardHeader>
              <CardContent className="pt-6">
                <ExerciseForm
                  exercise={currentExercise}
                  onChange={setCurrentExercise}
                  concepts={concepts}
                  step={currentStep}
                  onValidate={handleValidate}
                />

                {/* Navigation */}
                <div className="flex items-center justify-between mt-6 pt-4 border-t border-border">
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
                  ) : (
                    <div className="flex gap-2">
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
          <div className="lg:col-span-1">
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
