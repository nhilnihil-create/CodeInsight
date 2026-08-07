import { useState, useEffect } from "react";
import { useQuery, useMutation, useQueryClient } from "@tanstack/react-query";
import { Plus, Trash2, Save, UserPlus, AlertTriangle, RefreshCw } from "lucide-react";
import { toast } from "sonner";
import InsightHeader from "@/components/ui/insight-header";
import { Button } from "@/components/ui/button";
import { Input } from "@/components/ui/input";
import { Label } from "@/components/ui/label";
import api from "@/services/api";

export default function SettingsTab({ sectionId, sectionName, courseCode, onUpdated, onDeleted }) {
  const queryClient = useQueryClient();
  const [name, setName] = useState(sectionName || "");
  const [course, setCourse] = useState(courseCode || "");
  const [newEmail, setNewEmail] = useState("");

  useEffect(() => {
    setName(sectionName || "");
    setCourse(courseCode || "");
  }, [sectionName, courseCode]);

  const { data: students = [], isLoading, refetch } = useQuery({
    queryKey: ["section-students", sectionId],
    queryFn: async () => {
      const { data } = await api.get(`/api/sections/${sectionId}/students-with-scores`);
      return data.map((s) => ({
        id: s.id,
        name: s.name,
        email: s.email,
      }));
    },
    enabled: !!sectionId,
  });

  const { data: exercises = [] } = useQuery({
    queryKey: ["section-exercises", sectionId],
    queryFn: async () => {
      const { data } = await api.get(`/api/sections/${sectionId}/exercises`);
      return data.map((ex) => ({
        id: ex.id,
        title: ex.title,
        concept: ex.concept_name,
        submitted: ex.submitted_count ?? 0,
        total: ex.total_students ?? 0,
      }));
    },
    enabled: !!sectionId,
  });

  const updateMetaMutation = useMutation({
    mutationFn: async () => {
      await api.put(`/api/sections/${sectionId}`, { name, course_code: course });
    },
    onSuccess: () => {
      toast.success("Section updated");
      queryClient.invalidateQueries({ queryKey: ["section", sectionId] });
      queryClient.invalidateQueries({ queryKey: ["instructor-sections"] });
      if (onUpdated) onUpdated();
    },
    onError: () => toast.error("Failed to update section"),
  });

  const enrollMutation = useMutation({
    mutationFn: async (email) => {
      await api.post(`/api/sections/${sectionId}/enroll`, { emails: [email] });
    },
    onSuccess: () => {
      toast.success("Student enrolled");
      setNewEmail("");
      refetch();
      queryClient.invalidateQueries({ queryKey: ["section-students", sectionId] });
      queryClient.invalidateQueries({ queryKey: ["section", sectionId] });
      if (onUpdated) onUpdated();
    },
    onError: () => toast.error("Failed to enroll student"),
  });

  const unenrollMutation = useMutation({
    mutationFn: async (studentId) => {
      await api.delete(`/api/sections/${sectionId}/enroll/${studentId}`);
    },
    onSuccess: () => {
      toast.success("Student removed");
      refetch();
      queryClient.invalidateQueries({ queryKey: ["section-students", sectionId] });
      queryClient.invalidateQueries({ queryKey: ["section", sectionId] });
      if (onUpdated) onUpdated();
    },
    onError: () => toast.error("Failed to remove student"),
  });

  const deleteSectionMutation = useMutation({
    mutationFn: async () => {
      await api.delete(`/api/sections/${sectionId}`);
    },
    onSuccess: () => {
      toast.success("Section deleted");
      queryClient.invalidateQueries({ queryKey: ["instructor-sections"] });
      if (onDeleted) onDeleted();
    },
    onError: () => toast.error("Failed to delete section"),
  });

  const handleAddStudent = () => {
    const v = newEmail.trim();
    if (!v) return;
    enrollMutation.mutate(v);
  };

  const handleDelete = () => {
    if (!confirm("Delete this section? All enrollments, exercises, submissions, and analytics will be permanently removed. This cannot be undone.")) return;
    deleteSectionMutation.mutate();
  };

  return (
    <div className="space-y-6">
      <InsightHeader insight="Section metadata and roster configuration." />

      <div className="flex flex-col gap-6">
        {/* Section metadata */}
        <div className="rounded-lg border border-border bg-card shadow-sm">
          <div className="px-5 py-3 border-b border-border">
            <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
              Settings
            </p>
            <h3 className="text-sm font-semibold mt-0.5">Section metadata</h3>
          </div>
          <div className="p-5 space-y-4">
            <div>
              <Label htmlFor="section-name">Section name</Label>
              <Input
                id="section-name"
                value={name}
                onChange={(e) => setName(e.target.value)}
                className="h-9 mt-1.5"
              />
            </div>
            <div>
              <Label htmlFor="section-course">Course code</Label>
              <Input
                id="section-course"
                value={course}
                onChange={(e) => setCourse(e.target.value)}
                className="h-9 mt-1.5"
              />
            </div>
            <div className="flex justify-end pt-2">
              <Button
                size="sm"
                className="font-medium"
                onClick={() => updateMetaMutation.mutate()}
                disabled={updateMetaMutation.isPending}
              >
                <Save className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                {updateMetaMutation.isPending ? "Saving…" : "Save changes"}
              </Button>
            </div>
          </div>
        </div>

        {/* Roster */}
        <div className="rounded-lg border border-border bg-card shadow-sm">
          <div className="px-5 py-3 border-b border-border flex items-center justify-between">
            <div>
              <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
                Settings
              </p>
              <h3 className="text-sm font-semibold mt-0.5">
                Roster ({students.length})
              </h3>
            </div>
          </div>
          <div className="p-5 space-y-3">
            <div className="flex gap-2">
              <Input
                value={newEmail}
                onChange={(e) => setNewEmail(e.target.value)}
                onKeyDown={(e) => e.key === "Enter" && handleAddStudent()}
                placeholder="Add student by email…"
                className="h-9 flex-1"
                aria-label="Add student"
              />
              <Button
                size="sm"
                variant="outline"
                onClick={handleAddStudent}
                disabled={enrollMutation.isPending}
                className="font-medium"
              >
                <UserPlus className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                {enrollMutation.isPending ? "Adding…" : "Add"}
              </Button>
            </div>
            {isLoading ? (
              <p className="text-sm text-muted-foreground text-center py-4">Loading roster…</p>
            ) : (
              <ul className="rounded-md border border-border bg-card divide-y divide-border overflow-hidden">
                {students.length === 0 ? (
                  <li className="px-3 h-10 flex items-center text-sm text-muted-foreground">
                    No students enrolled yet
                  </li>
                ) : (
                  students.map((s) => (
                    <li
                      key={s.id}
                      className="flex items-center gap-3 px-3 h-10 hover:bg-muted/40 transition-colors"
                    >
                      <span className="text-sm font-medium text-foreground flex-1 truncate">
                        {s.name}
                      </span>
                      <span className="text-xs text-muted-foreground shrink-0">({s.email})</span>
                      <button
                        type="button"
                        onClick={() => unenrollMutation.mutate(s.id)}
                        disabled={unenrollMutation.isPending}
                        className="h-7 w-7 inline-flex items-center justify-center rounded-md text-muted-foreground hover:bg-muted hover:text-destructive focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-ring"
                        aria-label={`Remove ${s.name}`}
                      >
                        <Trash2 className="h-3.5 w-3.5" strokeWidth={1.5} />
                      </button>
                    </li>
                  ))
                )}
              </ul>
            )}
          </div>
        </div>
      </div>

      {/* Exercise assignment */}
      <div className="rounded-lg border border-border bg-card shadow-sm">
        <div className="px-5 py-3 border-b border-border flex items-center justify-between">
          <div>
            <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
              Settings
            </p>
            <h3 className="text-sm font-semibold mt-0.5">Assigned exercises</h3>
          </div>
          <Button
            size="sm"
            variant="outline"
            className="font-medium"
            onClick={() => window.open(`/instructor/exercises/new?section=${sectionId}`, "_self")}
          >
            <Plus className="h-3.5 w-3.5 mr-1.5" strokeWidth={2} />
            Assign exercise
          </Button>
        </div>
        {exercises.length === 0 ? (
          <div className="px-5 py-8 text-center">
            <p className="text-sm text-muted-foreground">No exercises assigned yet</p>
          </div>
        ) : (
          <ul className="divide-y divide-border">
            {exercises.map((ex) => (
              <li
                key={ex.id}
                className="grid grid-cols-[1fr_5rem_6rem_3rem] items-center gap-3 px-5 h-14 hover:bg-muted/40 transition-colors"
              >
                <span className="text-sm font-medium text-foreground truncate">
                  {ex.title}
                </span>
                <span className="text-xs font-mono tabular-nums text-muted-foreground text-right">
                  {ex.submitted}/{ex.total} submitted
                </span>
                <span className="text-xs font-mono tabular-nums text-muted-foreground text-right">
                  {ex.concept}
                </span>
                <button
                  type="button"
                  className="h-7 w-7 ml-auto inline-flex items-center justify-center rounded-md text-muted-foreground hover:bg-muted hover:text-destructive focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-ring"
                  aria-label={`Unassign ${ex.title}`}
                  onClick={() => toast.info("Exercise removal coming soon")}
                >
                  <Trash2 className="h-3.5 w-3.5" strokeWidth={1.5} />
                </button>
              </li>
            ))}
          </ul>
        )}
      </div>

      {/* Delete section */}
      <div className="rounded-lg border border-destructive/20 bg-destructive/5 shadow-sm">
        <div className="px-5 py-3 border-b border-destructive/20">
          <p className="text-[10px] font-semibold uppercase tracking-wider text-destructive">
            Danger zone
          </p>
          <h3 className="text-sm font-semibold mt-0.5">Delete section</h3>
        </div>
        <div className="p-5 flex items-center justify-between">
          <p className="text-sm text-muted-foreground max-w-md">
            Permanently delete this section and all associated data
            (enrollments, exercises, submissions, and analytics).
            This cannot be undone.
          </p>
          <Button
            size="sm"
            variant="destructive"
            className="font-medium shrink-0"
            onClick={handleDelete}
            disabled={deleteSectionMutation.isPending}
          >
            {deleteSectionMutation.isPending ? "Deleting…" : "Delete section"}
          </Button>
        </div>
      </div>
    </div>
  );
}
