import { useEffect, useMemo, useState } from "react";
import { Link, useNavigate, useParams } from "react-router-dom";
import { Save, Send, ChevronLeft, Trash2 } from "lucide-react";
import { Button } from "@/components/ui/button";
import InstructorDashboardShell from "@/components/instructor-dashboard-shell";
import ExerciseFormFields from "./ExerciseFormFields";
import api from "@/services/api";
import { cn } from "@/lib/utils";

/**
 * Instructor Exercise Form — wired to backend.
 *
 *   URL  /instructor/exercises/new           → POST /api/exercises
 *   URL  /instructor/exercises/:id/edit      → PUT  /api/exercises/:id
 *   URL  /instructor/create-exercise         → POST /api/exercises
 *
 *   Sources real concepts from  GET /api/exercises/concepts
 *   Sources real sections   from  GET /api/sections
 */

const INITIAL_TESTS_NEW = [
  { hidden: false, input: "", expected: "", description: "" },
];

export default function InstructorExerciseForm() {
  const { id } = useParams();
  const navigate = useNavigate();
  const isEdit = Boolean(id) && id !== "new";

  const [concepts, setConcepts] = useState([]);
  const [availableSections, setAvailableSections] = useState([]);
  const [existing, setExisting] = useState(null);
  const [loading, setLoading] = useState(!isEdit);
  const [error, setError] = useState(null);
  const [busy, setBusy] = useState(false);

  useEffect(() => {
    const loadConcepts = api.get("/api/exercises/concepts").then(r => setConcepts(r.data || [])).catch(() => setConcepts([]));
    const loadSections = api.get("/api/sections").then(r => setAvailableSections(r.data || [])).catch(() => setAvailableSections([]));
    const loadExercise = isEdit
      ? api.get(`/api/exercises/${id}`).then(r => setExisting(r.data)).catch(err => setError(err.response?.data?.message || err.message))
      : Promise.resolve();
    Promise.all([loadConcepts, loadSections, loadExercise]).finally(() => setLoading(false));
  }, [id, isEdit]);

  // ---------- Form state ----------
  // Build initial values from loaded exercise data; recompute whenever `existing` changes.
  const formInit = useMemo(() =>
    existing
      ? {
          title: existing.title ?? "",
          description: existing.description ?? "",
          conceptName: existing.concept_name ?? "",
          tests: (existing.test_cases || []).map(tc => ({ hidden: !!tc.hidden, input: tc.input || "", expected: tc.expected || "", description: tc.description || "" })),
          assignedSectionIds: existing.section_id ? [String(existing.section_id)] : [],
          timerMinutes: existing.time_limit_minutes != null
            ? Math.floor(existing.time_limit_minutes / 60)
            : 45,
          timerSeconds: existing.time_limit_minutes != null
            ? existing.time_limit_minutes % 60
            : 0,
          deadline: existing.deadline ? existing.deadline.slice(0, 16) : "",
          starterCode: existing.starter_code ?? "",
          referenceSolution: existing.reference_solution ?? "",
        }
      : {
          title: "",
          description: "",
          conceptName: "",
          tests: INITIAL_TESTS_NEW,
          assignedSectionIds: [],
          timerMinutes: 60,
          timerSeconds: 0,
          deadline: "",
          starterCode: "",
          referenceSolution: "",
        },
    [existing]
  );

  const [title, setTitle] = useState(formInit.title);
  const [description, setDescription] = useState(formInit.description);
  const [conceptName, setConceptName] = useState(formInit.conceptName);
  const [tests, setTests] = useState(formInit.tests);
  const [sections, setSections] = useState(
    availableSections.map((s) => ({
      id: s.id,
      name: s.name,
      students: s.student_count,
      selected: formInit.assignedSectionIds.includes(String(s.id)),
    }))
  );
  const [timerMinutes, setTimerMinutes] = useState(formInit.timerMinutes);
  const [timerSeconds, setTimerSeconds] = useState(formInit.timerSeconds);
  const [deadline, setDeadline] = useState(formInit.deadline);
  const [starterCode, setStarterCode] = useState(formInit.starterCode);
  const [referenceSolution, setReferenceSolution] = useState(formInit.referenceSolution);

  // Sync all form fields when loaded exercise data arrives
  useEffect(() => {
    if (existing) {
      setTitle(existing.title ?? "");
      setDescription(existing.description ?? "");
      setConceptName(existing.concept_name ?? "");
      setTests((existing.test_cases || []).map(tc => ({ hidden: !!tc.hidden, input: tc.input || "", expected: tc.expected || "", description: tc.description || "" })));
      const mins = existing.time_limit_minutes != null ? existing.time_limit_minutes : 45;
      setTimerMinutes(Math.floor(mins / 60));
      setTimerSeconds(mins % 60);
      setDeadline(existing.deadline ? existing.deadline.slice(0, 16) : "");
      setStarterCode(existing.starter_code ?? "");
      setReferenceSolution(existing.reference_solution ?? "");
    }
  }, [existing]);

  // Sync section selection when availableSections or formInit changes
  useEffect(() => {
    setSections(
      availableSections.map((s) => ({
        id: s.id, name: s.name, students: s.student_count,
        selected: formInit.assignedSectionIds.includes(String(s.id)),
      }))
    );
  }, [availableSections, formInit.assignedSectionIds]);

  const [sectionQuery, setSectionQuery] = useState("");

  const [attemptedPublish, setAttemptedPublish] = useState(false);
  const titleInvalid = attemptedPublish && !title.trim();
  const testsInvalid = attemptedPublish && tests.length === 0;
  const noSectionsSelected = sections.every((s) => !s.selected);
  const noConcept = attemptedPublish && !conceptName;

  // ---------- Tag / concept handlers ----------
  const setConcept = (name) => setConceptName(name);

  // ---------- Test-case handlers ----------
  const addTest = () =>
    setTests((prev) => [...prev, { hidden: false, input: "", expected: "", description: "" }]);
  const updateTest = (i, patch) =>
    setTests((prev) => prev.map((t, idx) => (idx === i ? { ...t, ...patch } : t)));
  const removeTest = (i) => setTests((prev) => prev.filter((_, idx) => idx !== i));

  // ---------- Section handlers ----------
  const toggleSection = (id) =>
    setSections((prev) => prev.map((s) => (s.id === id ? { ...s, selected: !s.selected } : s)));
  const toggleAll = () => {
    const allSelected = sections.length > 0 && sections.every((s) => s.selected);
    setSections((prev) => prev.map((s) => ({ ...s, selected: !allSelected })));
  };

  // ---------- Publish / Draft ----------
  const handleSubmit = async (isDraft) => {
    setAttemptedPublish(true);
    if (!isDraft && (!title.trim() || tests.length === 0 || sections.every((s) => !s.selected) || !conceptName)) return;

    const selectedSection = sections.find((s) => s.selected);
    if (!selectedSection) {
      setError("Select at least one section.");
      return;
    }
    const payload = {
      title: title.trim(),
      description,
      concept_name: conceptName,
      section_id: selectedSection.id,
      time_limit_minutes: Math.round(((Number(timerMinutes) || 0) * 60 + (Number(timerSeconds) || 0)) / 60),
      test_cases: tests.map((t) => ({
        input: t.input || "",
        expected: t.expected || "",
        description: t.description || "",
        hidden: !!t.hidden,
      })),
      deadline: deadline || null,
      starter_code: starterCode || null,
      reference_solution: referenceSolution || null,
      is_draft: !!isDraft,
    };
    setBusy(true);
    setError(null);
    try {
      if (isEdit) {
        await api.put(`/api/exercises/${id}`, payload);
      } else {
        await api.post("/api/exercises", payload);
      }
      navigate("/instructor/exercises");
    } catch (err) {
      setError(err.response?.data?.message || err.message);
    } finally {
      setBusy(false);
    }
  };

  const handleDelete = async () => {
    if (!confirm(`Delete "${title}"? This cannot be undone.`)) return;
    setBusy(true);
    setError(null);
    try {
      await api.delete(`/api/exercises/${id}`);
      navigate("/instructor/exercises");
    } catch (err) {
      setError(err.response?.data?.message || err.message);
    } finally {
      setBusy(false);
    }
  };

  const assignedSet = useMemo(
    () => new Set(sections.filter((s) => s.selected).map((s) => s.id)),
    [sections]
  );

  if (loading) {
    return (
      <InstructorDashboardShell>
        <p className="text-muted-foreground">Loading…</p>
      </InstructorDashboardShell>
    );
  }

  return (
    <InstructorDashboardShell>
      <div>
        <Button asChild variant="ghost" size="sm" className="-ml-2">
          <Link to="/instructor/exercises">
            <ChevronLeft className="w-4 h-4 mr-1" /> Back to exercises
          </Link>
        </Button>
      </div>

      <div className="space-y-1">
        <h1 className="text-2xl font-semibold tracking-tight">
          {isEdit ? "Edit Exercise" : "Create New Exercise"}
        </h1>
        <p className="text-sm text-muted-foreground">
          Compose a problem, attach test cases, and assign to a section.
        </p>
      </div>

      {error && <p className="text-sm text-destructive">{error}</p>}

      <ExerciseFormFields
        title={title}
        description={description}
        conceptName={conceptName}
        tests={tests}
        sections={sections}
        sectionQuery={sectionQuery}
        timerMinutes={timerMinutes}
        timerSeconds={timerSeconds}
        deadline={deadline}
        starterCode={starterCode}
        referenceSolution={referenceSolution}
        titleInvalid={titleInvalid}
        testsInvalid={testsInvalid}
        noSectionsSelected={noSectionsSelected}
        noConcept={noConcept}
        setTitle={setTitle}
        setDescription={setDescription}
        setConcept={setConcept}
        addTest={addTest}
        updateTest={updateTest}
        removeTest={removeTest}
        setSectionQuery={setSectionQuery}
        toggleSection={toggleSection}
        toggleAll={toggleAll}
        setTimerMinutes={setTimerMinutes}
        setTimerSeconds={setTimerSeconds}
        setDeadline={setDeadline}
        setStarterCode={setStarterCode}
        setReferenceSolution={setReferenceSolution}
        quickConcepts={concepts.map(c => ({ code: c.name.slice(0, 2).toUpperCase(), name: c.name }))}
        assignedSectionIds={assignedSet}
        showLastEdited={isEdit}
      />

      <div className="flex items-center justify-between pt-6 border-t border-border">
        {isEdit ? (
          <Button type="button" variant="ghost" onClick={handleDelete} disabled={busy} className="font-medium text-destructive hover:bg-destructive/10 hover:text-destructive">
            <Trash2 className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
            Delete
          </Button>
        ) : <div />}
        <div className="flex items-center gap-2">
          <Button type="button" variant="ghost" onClick={() => handleSubmit(true)} disabled={busy} className="font-medium">
            <Save className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
            {busy ? "Saving…" : "Save draft"}
          </Button>
          <Button type="button" onClick={() => handleSubmit(false)} disabled={busy} className={cn("font-medium px-8")}>
            <Send className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
            {busy ? "Publishing…" : (isEdit ? "Update" : "Publish")}
          </Button>
        </div>
      </div>
    </InstructorDashboardShell>
  );
}
