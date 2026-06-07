import { useMemo } from "react";
import {
  Plus,
  X,
  GripVertical,
  TestTube,
  Trash2,
  Search,
} from "lucide-react";
import { Button } from "@/components/ui/button";
import { Input } from "@/components/ui/input";
import { Label } from "@/components/ui/label";
import { Textarea } from "@/components/ui/textarea";
import { Switch } from "@/components/ui/switch";
import { Checkbox } from "@/components/ui/checkbox";
import EmptyState from "@/components/ui/empty-state";
import { cn } from "@/lib/utils";

/**
 * ExerciseFormFields
 * The full 2-column form body shared by ExerciseForm (new + edit).
 * The page wrapper owns the shell, h1, and footer actions.
 *
 *   Left  Title · Description · Concept Tags · Test Cases
 *   Right Timer (min:sec) · Assign to Sections · Deadline  (sticky)
 *
 * The 7 introductory concepts (per spec) are hard-coded in
 * QUICK_CONCEPTS below. Tags can still be added freely via the input.
 *
 * Tokens only.
 */
export default function ExerciseFormFields({
  // ---- state ----
  title,
  description,
  tags,
  tagInput,
  tests,
  sections,
  sectionQuery,
  timerMinutes,
  timerSeconds,
  deadline,
  // ---- validation ----
  titleInvalid = false,
  testsInvalid = false,
  noSectionsSelected = false,
  // ---- handlers ----
  setTitle,
  setDescription,
  setTagInput,
  addTag,
  removeTag,
  onTagKeyDown,
  addTest,
  updateTest,
  removeTest,
  setSectionQuery,
  toggleSection,
  toggleAll,
  setTimerMinutes,
  setTimerSeconds,
  setDeadline,
  // ---- edit-specific flags ----
  showLastEdited = false,
  assignedSectionIds,
  quickConcepts = [],
}) {
  return (
    <div className="grid gap-6 lg:grid-cols-[1fr_320px]">
      {/* ============================================================ */}
      {/* LEFT COLUMN (60–70%)                                         */}
      {/* ============================================================ */}
      <div className="space-y-6 min-w-0">
        <GeneralDetailsCard
          title={title}
          description={description}
          titleInvalid={titleInvalid}
          setTitle={setTitle}
          setDescription={setDescription}
        />

        <ConceptTagsCard
          tags={tags}
          tagInput={tagInput}
          setTagInput={setTagInput}
          addTag={addTag}
          removeTag={removeTag}
          onTagKeyDown={onTagKeyDown}
          quickConcepts={quickConcepts}
        />

        <TestCasesCard
          tests={tests}
          testsInvalid={testsInvalid}
          addTest={addTest}
          updateTest={updateTest}
          removeTest={removeTest}
          showLastEdited={showLastEdited}
        />
      </div>

      {/* ============================================================ */}
      {/* RIGHT COLUMN (sidebar, 30–40%)                               */}
      {/* ============================================================ */}
      <aside className="space-y-4 lg:sticky lg:top-6 lg:self-start min-w-0">
        <TimerCard
          minutes={timerMinutes}
          seconds={timerSeconds}
          setMinutes={setTimerMinutes}
          setSeconds={setTimerSeconds}
        />

        <AssignSectionsCard
          sections={sections}
          sectionQuery={sectionQuery}
          setSectionQuery={setSectionQuery}
          toggleSection={toggleSection}
          toggleAll={toggleAll}
          noSectionsSelected={noSectionsSelected}
          assignedSectionIds={assignedSectionIds}
        />

        <DeadlineCard deadline={deadline} setDeadline={setDeadline} />
      </aside>
    </div>
  );
}

// ============================================================================
// 1. GENERAL DETAILS — Title + rich-text Description
// ============================================================================
function GeneralDetailsCard({
  title,
  description,
  titleInvalid,
  setTitle,
  setDescription,
}) {
  return (
    <Card>
      <SectionHeader title="General Details" />
      <div className="space-y-4">
        <Field label="Exercise Title" htmlFor="ex-title">
          <Input
            id="ex-title"
            value={title}
            onChange={(e) => setTitle(e.target.value)}
            placeholder="e.g. Fibonacci with Recursion"
            className={cn(titleInvalid && "border-destructive ring-1 ring-destructive/40")}
            aria-invalid={titleInvalid}
          />
          {titleInvalid ? (
            <p className="text-xs text-destructive mt-1">Title is required to publish.</p>
          ) : null}
        </Field>

        <Field label="Description" htmlFor="ex-desc">
          <Textarea
            id="ex-desc"
            value={description}
            onChange={(e) => setDescription(e.target.value)}
            placeholder="Describe the problem, the expected behavior, and any constraints…"
            className="min-h-[160px]"
          />
          <p className="text-xs text-muted-foreground mt-1">
            Markdown supported · use `code`, **bold**, and lists.
          </p>
        </Field>
      </div>
    </Card>
  );
}

// ============================================================================
// 2. CONCEPT TAGS — 7 introductory concepts (per spec)
// ============================================================================
function ConceptTagsCard({
  tags,
  tagInput,
  setTagInput,
  addTag,
  removeTag,
  onTagKeyDown,
  quickConcepts,
}) {
  return (
    <Card>
      <SectionHeader title="Concept Metadata" />
      <Field label="Concepts" htmlFor="ex-tag-input">
        <div className="flex flex-wrap items-center gap-1.5 rounded-md border border-input bg-background px-2 py-1.5 focus-within:ring-2 focus-within:ring-ring focus-within:ring-offset-1">
          {tags.map((t) => (
            <span
              key={t.name}
              className="inline-flex items-center gap-1 rounded-full bg-primary/10 text-primary border border-primary/20 px-2.5 py-0.5 text-xs font-medium"
            >
              {t.name}
              <button
                type="button"
                onClick={() => removeTag(t.name)}
                className="rounded-full hover:bg-primary/20 p-0.5 -mr-1"
                aria-label={`Remove ${t.name}`}
              >
                <X className="h-3 w-3" strokeWidth={2} />
              </button>
            </span>
          ))}
          <input
            id="ex-tag-input"
            value={tagInput}
            onChange={(e) => setTagInput(e.target.value)}
            onKeyDown={onTagKeyDown}
            onBlur={() => tagInput && addTag(tagInput)}
            placeholder={tags.length === 0 ? "Type a concept, press Enter" : ""}
            className="flex-1 min-w-[8rem] bg-transparent text-sm outline-none placeholder:text-muted-foreground px-1 py-0.5"
          />
        </div>
        {quickConcepts.length > 0 ? (
          <div className="flex flex-wrap items-center gap-1.5 pt-1">
            {quickConcepts.map((c) => {
              const present = tags.some((t) => t.name === c.name);
              return (
                <Button
                  key={c.code}
                  type="button"
                  variant="ghost"
                  size="sm"
                  onClick={() => addTag(c.name)}
                  disabled={present}
                  className="font-medium"
                >
                  {c.name}
                </Button>
              );
            })}
          </div>
        ) : null}
        <p className="text-xs text-muted-foreground">
          Students see these tags. They help target recommendations.
        </p>
      </Field>
    </Card>
  );
}

// ============================================================================
// 3. TEST CASES — dynamic Input/Output pairs with Hidden/Visible toggle
// ============================================================================
function TestCasesCard({
  tests,
  testsInvalid,
  addTest,
  updateTest,
  removeTest,
  showLastEdited,
}) {
  return (
    <Card invalid={testsInvalid}>
      <div className="flex items-center justify-between gap-3">
        <SectionHeader title="Test Cases" />
        <Button
          type="button"
          variant="ghost"
          size="sm"
          onClick={addTest}
          className="font-medium"
        >
          <Plus className="h-3.5 w-3.5 mr-1" strokeWidth={2} />
          Add test case
        </Button>
      </div>

      {tests.length === 0 ? (
        <EmptyState
          icon={<TestTube className="h-4 w-4" strokeWidth={1.5} />}
          title="No test cases yet"
          description="Add at least one test case before publishing."
          action={
            <Button onClick={addTest} size="sm" className="font-medium">
              <Plus className="h-3.5 w-3.5 mr-1.5" strokeWidth={2} />
              Add test case
            </Button>
          }
        />
      ) : (
        <ul className="space-y-3">
          {tests.map((t, i) => (
            <li key={t.id}>
              <TestCaseRow
                index={i + 1}
                test={t}
                onChange={(patch) => updateTest(t.id, patch)}
                onRemove={() => removeTest(t.id)}
                canRemove={tests.length > 1}
                showLastEdited={showLastEdited}
              />
            </li>
          ))}
        </ul>
      )}

      <p className="text-xs text-muted-foreground pt-3 border-t border-border">
        {showLastEdited
          ? "Changes to test cases affect all future submissions. Past submissions are not re-evaluated."
          : "Hidden test cases are used for final grading. Students only see visible ones."}
      </p>
    </Card>
  );
}

function TestCaseRow({ index, test, onChange, onRemove, canRemove, showLastEdited }) {
  return (
    <div className="rounded-md border border-border bg-muted/40 p-3 space-y-3">
      <div className="flex items-center gap-2">
        <GripVertical
          className="h-4 w-4 text-muted-foreground shrink-0 cursor-grab"
          strokeWidth={1.5}
          aria-label="Drag to reorder"
        />
        <div className="flex flex-col min-w-0 flex-1">
          <span className="text-sm font-medium">Test case {index}</span>
          {showLastEdited && test.lastEdited ? (
            <span className="text-xs text-muted-foreground">
              Last edited {test.lastEdited}
            </span>
          ) : null}
        </div>
        <span
          className={cn(
            "inline-flex items-center rounded-full border px-2 py-0.5 text-[11px] font-semibold uppercase tracking-wide",
            test.hidden
              ? "bg-warning/10 text-warning border-warning/20"
              : "bg-success/10 text-success border-success/20"
          )}
        >
          {test.hidden ? "Hidden from students" : "Visible to students"}
        </span>
        <div className="flex items-center gap-2 pl-2 border-l border-border/60">
          <Label
            htmlFor={`hidden-${test.id}`}
            className="text-xs text-muted-foreground cursor-pointer"
          >
            Hidden
          </Label>
          <Switch
            id={`hidden-${test.id}`}
            checked={test.hidden}
            onCheckedChange={(v) => onChange({ hidden: v })}
          />
        </div>
      </div>

      <div className="grid gap-3 sm:grid-cols-2">
        <Field label="Input" htmlFor={`in-${test.id}`}>
          <Textarea
            id={`in-${test.id}`}
            rows={2}
            value={test.input}
            onChange={(e) => onChange({ input: e.target.value })}
            placeholder="stdin"
            className="font-mono text-xs"
          />
        </Field>
        <Field label="Expected Output" htmlFor={`out-${test.id}`}>
          <Textarea
            id={`out-${test.id}`}
            rows={2}
            value={test.expected}
            onChange={(e) => onChange({ expected: e.target.value })}
            placeholder="expected stdout"
            className="font-mono text-xs"
          />
        </Field>
      </div>

      <Field label="Description (optional)" htmlFor={`desc-${test.id}`}>
        <Input
          id={`desc-${test.id}`}
          value={test.description}
          onChange={(e) => onChange({ description: e.target.value })}
          placeholder="What this test checks"
        />
      </Field>

      <div className="flex items-center justify-end">
        <Button
          type="button"
          variant="ghost"
          size="sm"
          onClick={onRemove}
          disabled={!canRemove}
          className="font-medium text-destructive hover:bg-destructive/10 hover:text-destructive"
        >
          <Trash2 className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
          Remove
        </Button>
      </div>
    </div>
  );
}

// ============================================================================
// 4. TIMER — minutes + seconds
// ============================================================================
function TimerCard({ minutes, seconds, setMinutes, setSeconds }) {
  return (
    <Card>
      <SectionHeader title="Timer" />
      <p className="text-xs text-muted-foreground -mt-2">
        Maximum time students have to solve this exercise.
      </p>
      <div className="grid grid-cols-2 gap-3">
        <Field label="Minutes" htmlFor="ex-timer-min">
          <Input
            id="ex-timer-min"
            type="number"
            min={0}
            max={240}
            value={minutes}
            onChange={(e) => setMinutes(Math.max(0, Number(e.target.value) || 0))}
            className="font-mono tabular-nums"
          />
        </Field>
        <Field label="Seconds" htmlFor="ex-timer-sec">
          <Input
            id="ex-timer-sec"
            type="number"
            min={0}
            max={59}
            value={seconds}
            onChange={(e) =>
              setSeconds(Math.min(59, Math.max(0, Number(e.target.value) || 0)))
            }
            className="font-mono tabular-nums"
          />
        </Field>
      </div>
    </Card>
  );
}

// ============================================================================
// 5. ASSIGN TO SECTIONS — multi-select with search
// ============================================================================
function AssignSectionsCard({
  sections,
  sectionQuery,
  setSectionQuery,
  toggleSection,
  toggleAll,
  noSectionsSelected,
  assignedSectionIds,
}) {
  const filteredSections = useMemo(() => {
    const q = sectionQuery.trim().toLowerCase();
    if (!q) return sections;
    return sections.filter((s) => s.name.toLowerCase().includes(q));
  }, [sections, sectionQuery]);

  const selectedCount = sections.filter((s) => s.selected).length;
  const allSelected = sections.length > 0 && selectedCount === sections.length;
  const someSelected = selectedCount > 0 && !allSelected;
  const allChecked = allSelected ? true : someSelected ? "indeterminate" : false;

  return (
    <Card>
      <SectionHeader title="Assign to Sections" />

      <div className="relative">
        <Search
          className="absolute left-3 top-1/2 -translate-y-1/2 h-3.5 w-3.5 text-muted-foreground pointer-events-none"
          strokeWidth={1.5}
          aria-hidden="true"
        />
        <Input
          value={sectionQuery}
          onChange={(e) => setSectionQuery(e.target.value)}
          placeholder="Search sections…"
          className="pl-9 h-9"
        />
      </div>

      <div className="flex items-center gap-2 px-1">
        <Checkbox
          id="select-all-sections"
          checked={allChecked}
          onCheckedChange={toggleAll}
        />
        <Label
          htmlFor="select-all-sections"
          className="text-xs text-muted-foreground cursor-pointer"
        >
          Select all
        </Label>
      </div>

      <ul className="space-y-1 max-h-64 overflow-y-auto -mx-1 px-1">
        {filteredSections.length === 0 ? (
          <li className="text-xs text-muted-foreground px-2 py-3">
            No sections match “{sectionQuery}”.
          </li>
        ) : (
          filteredSections.map((s) => {
            const wasAssigned =
              assignedSectionIds instanceof Set && assignedSectionIds.has(s.id);
            const showUnassignWarning = wasAssigned && !s.selected;
            return (
              <li key={s.id}>
                <label
                  className={cn(
                    "flex items-center gap-2.5 rounded-md px-2 py-1.5 cursor-pointer transition-colors",
                    s.selected ? "bg-primary/5" : "hover:bg-muted/40"
                  )}
                >
                  <Checkbox
                    checked={s.selected}
                    onCheckedChange={() => toggleSection(s.id)}
                    aria-label={`Assign to ${s.name}`}
                  />
                  <span className="text-sm truncate flex-1 inline-flex items-center gap-1.5">
                    {s.name}
                    {wasAssigned ? (
                      <span className="inline-flex items-center bg-success/10 text-success text-[10px] font-semibold uppercase tracking-wide rounded-full px-1.5 py-0.5">
                        Assigned
                      </span>
                    ) : null}
                  </span>
                  <span className="text-xs text-muted-foreground font-mono tabular-nums shrink-0">
                    {s.students}
                  </span>
                </label>
                {showUnassignWarning ? (
                  <p className="text-xs text-warning-foreground pl-9 pr-2 pb-1.5">
                    Removing this section will hide the exercise from its students.
                  </p>
                ) : null}
              </li>
            );
          })
        )}
      </ul>

      {selectedCount > 0 ? (
        <span className="inline-flex items-center bg-primary/10 text-primary text-xs font-medium px-2 py-0.5 rounded-full">
          {selectedCount} section{selectedCount === 1 ? "" : "s"} selected
        </span>
      ) : null}

      <p className="text-xs text-muted-foreground border-t border-border pt-3">
        {noSectionsSelected
          ? "Exercise will be unpublished until assigned."
          : "Students in selected sections will see this exercise when published."}
      </p>
    </Card>
  );
}

// ============================================================================
// 6. DEADLINE — Date/Time Picker
// ============================================================================
function DeadlineCard({ deadline, setDeadline }) {
  return (
    <Card>
      <SectionHeader title="Deadline" />
      <Field label="Due Date & Time" htmlFor="ex-deadline">
        <Input
          id="ex-deadline"
          type="datetime-local"
          value={deadline}
          onChange={(e) => setDeadline(e.target.value)}
        />
        <p className="text-xs text-muted-foreground mt-1">
          Students must submit before this time.
        </p>
      </Field>
    </Card>
  );
}

// ============================================================================
// Local helpers
// ============================================================================
function Card({ children, invalid, className }) {
  return (
    <section
      className={cn(
        "bg-card border border-border rounded-lg p-5 space-y-4 outline-none transition-shadow",
        invalid && "ring-2 ring-destructive/40 border-destructive/40",
        className
      )}
    >
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
