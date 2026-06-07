import { useState } from "react";
import { Plus, Trash2, Save, UserPlus } from "lucide-react";
import InsightHeader from "@/components/ui/insight-header";
import { Button } from "@/components/ui/button";
import { Input } from "@/components/ui/input";
import { Label } from "@/components/ui/label";
import { cn } from "@/lib/utils";

const INITIAL_STUDENTS = [
  "A. Khan",
  "B. Reyes",
  "C. Park",
  "D. Lopez",
  "E. Chen",
  "F. Adams",
  "G. Park",
  "H. Singh",
];

const INITIAL_EXERCISES = [
  { id: 1, title: "Ex.1 — Arrays",     assigned: 22, due: "Aug 30" },
  { id: 2, title: "Ex.2 — Strings",    assigned: 22, due: "Sep 6"  },
  { id: 3, title: "Ex.3 — Loops",      assigned: 22, due: "Sep 13" },
  { id: 4, title: "Ex.4 — Recursion",  assigned: 22, due: "Sep 20" },
];

export default function SettingsTab() {
  const [name, setName] = useState("Section 04");
  const [course, setCourse] = useState("CS101 — Intro CS");
  const [instructor, setInstructor] = useState("Dr. Mendoza");
  const [students, setStudents] = useState(INITIAL_STUDENTS);
  const [newStudent, setNewStudent] = useState("");

  const addStudent = () => {
    const v = newStudent.trim();
    if (!v) return;
    setStudents((s) => [...s, v]);
    setNewStudent("");
  };

  return (
    <div className="space-y-6">
      <InsightHeader insight="Section metadata and roster configuration." />

      <div className="grid gap-6 md:grid-cols-2">
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
              <Label htmlFor="section-course">Course</Label>
              <Input
                id="section-course"
                value={course}
                onChange={(e) => setCourse(e.target.value)}
                className="h-9 mt-1.5"
              />
            </div>
            <div>
              <Label htmlFor="section-instructor">Instructor</Label>
              <Input
                id="section-instructor"
                value={instructor}
                onChange={(e) => setInstructor(e.target.value)}
                className="h-9 mt-1.5"
              />
            </div>
            <div className="flex justify-end pt-2">
              <Button size="sm" className="font-medium">
                <Save className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                Save changes
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
                value={newStudent}
                onChange={(e) => setNewStudent(e.target.value)}
                onKeyDown={(e) => e.key === "Enter" && addStudent()}
                placeholder="Add student by name or email…"
                className="h-9 flex-1"
                aria-label="Add student"
              />
              <Button
                size="sm"
                variant="outline"
                onClick={addStudent}
                className="font-medium"
              >
                <UserPlus className="h-3.5 w-3.5 mr-1.5" strokeWidth={1.5} />
                Add
              </Button>
            </div>
            <ul className="rounded-md border border-border bg-card divide-y divide-border overflow-hidden">
              {students.map((s, i) => (
                <li
                  key={`${s}-${i}`}
                  className="flex items-center gap-3 px-3 h-10 hover:bg-muted/40 transition-colors"
                >
                  <span className="text-sm text-foreground flex-1 truncate">
                    {s}
                  </span>
                  <button
                    type="button"
                    onClick={() =>
                      setStudents((cur) => cur.filter((_, j) => j !== i))
                    }
                    className="h-7 w-7 inline-flex items-center justify-center rounded-md text-muted-foreground hover:bg-muted hover:text-destructive focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-ring"
                    aria-label={`Remove ${s}`}
                  >
                    <Trash2 className="h-3.5 w-3.5" strokeWidth={1.5} />
                  </button>
                </li>
              ))}
            </ul>
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
          <Button size="sm" variant="outline" className="font-medium">
            <Plus className="h-3.5 w-3.5 mr-1.5" strokeWidth={2} />
            Assign exercise
          </Button>
        </div>
        <ul className="divide-y divide-border">
          {INITIAL_EXERCISES.map((ex) => (
            <li
              key={ex.id}
              className="grid grid-cols-[1fr_5rem_6rem_3rem] items-center gap-3 px-5 h-14 hover:bg-muted/40 transition-colors"
            >
              <span className="text-sm font-medium text-foreground truncate">
                {ex.title}
              </span>
              <span className="text-xs font-mono tabular-nums text-muted-foreground text-right">
                {ex.assigned} assigned
              </span>
              <span className="text-xs font-mono tabular-nums text-muted-foreground text-right">
                Due {ex.due}
              </span>
              <button
                type="button"
                className="h-7 w-7 ml-auto inline-flex items-center justify-center rounded-md text-muted-foreground hover:bg-muted hover:text-destructive focus-visible:outline-none focus-visible:ring-2 focus-visible:ring-ring"
                aria-label={`Unassign ${ex.title}`}
              >
                <Trash2 className="h-3.5 w-3.5" strokeWidth={1.5} />
              </button>
            </li>
          ))}
        </ul>
      </div>
    </div>
  );
}
