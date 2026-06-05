# Frontend-First Student-Slice Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Port the 3 Frontend-Design student pages (`Dashboard`, `Exercises`, `CodeEditor`) into the live `frontend/` repo as a thin JSX/wouter→react-router-dom migration, re-point the 3 student routes, and produce a buildable, visually-identical student flow that uses the real `AuthContext` for login and Frontend-Design's mock data for page content.

**Architecture:** Three new JSX page files under `frontend/src/pages/student/` with a `.new.jsx` suffix. Two small support modules (`mockData.js`, `auth.js`) ported from the design. `App.jsx` swaps 3 imports. `Layout.jsx` gets a 2-line spacing tweak. No backend integration, no instructor changes, no TypeScript.

**Tech Stack:** JavaScript / JSX, React 18, react-router-dom v6, Vite 5, Tailwind v4, shadcn/ui (Card, Badge, Button, etc. — already present), recharts (already present), lucide-react (already present).

**Reference Spec:** `docs/superpowers/specs/2026-06-04-frontend-first-migration-design.md`

**Reference Source:** `Frontend-Design/Frontend-Design/artifacts/codeinsight/src/` (the TSX files to port)

---

## File Structure

| Path | Status | Responsibility |
|------|--------|----------------|
| `frontend/src/data/mockData.js` | **Create** | Mock data (MOCK_EXERCISES, MOCK_USERS, MOCK_RADAR_DATA, Role constant). JS port of `Frontend-Design/src/data/mockData.ts`. |
| `frontend/src/lib/auth.js` | **Create** | Mock `getCurrentUser` / `login` / `logout` for the new pages. JS port of `Frontend-Design/src/lib/auth.ts`. Real `AuthContext.jsx` is unchanged. |
| `frontend/src/pages/student/Dashboard.new.jsx` | **Create** | Port of `Frontend-Design/src/pages/student/Dashboard.tsx` (TSX→JSX, wouter→none, real `useAuth`). |
| `frontend/src/pages/student/Exercises.new.jsx` | **Create** | Port of `Frontend-Design/src/pages/student/Exercises.tsx` (TSX→JSX, wouter→react-router-dom). |
| `frontend/src/pages/student/CodeEditor.new.jsx` | **Create** | Port of `Frontend-Design/src/pages/student/CodeEditor.tsx` (TSX→JSX, wouter→react-router-dom `useParams`). |
| `frontend/src/App.jsx` | **Modify** | Re-point 3 student route imports to the `.new.jsx` files. |
| `frontend/src/components/Layout.jsx` | **Modify** | Add `max-w-7xl mx-auto` and `p-6 lg:p-8` to the content container. |
| `frontend/src/pages/student/Dashboard.jsx` | **Delete** (after validation) | Old dashboard. Replaced by `.new.jsx`. |
| `frontend/src/pages/student/ExerciseList.jsx` | **Delete** (after validation) | Old exercise list. Replaced by `.new.jsx`. |
| `frontend/src/pages/student/CodeEditor_new.jsx` | **Delete** (after validation) | Old 753-LoC editor. Replaced by `.new.jsx`. |

Total LoC delta: roughly +400 / −2,000 net.

---

## Task 1: Port `mockData.ts` → `mockData.js`

**Files:**
- Create: `frontend/src/data/mockData.js`

- [ ] **Step 1: Create the directory and write the file**

```bash
mkdir -p frontend/src/data
```

Then create `frontend/src/data/mockData.js` with the following content (JS port of the TS source — drop types, drop the unused `EarlyWarningAlert`/`IntegrityFlag`/`StructureViolation` interfaces that the student pages do not need; keep `MOCK_EXERCISES` shape complete because `CodeEditor` reads `starterCode` and `testCases[0]`):

```js
// Ported from Frontend-Design/Frontend-Design/artifacts/codeinsight/src/data/mockData.ts
// Used by the new student dashboard, exercises list, and code editor.

export const Role = {
  STUDENT: 'student',
  INSTRUCTOR: 'instructor',
};

export const MOCK_USERS = [
  { id: 'u1', name: 'Dr. Emily Chen', email: 'instructor@psu.edu', role: 'instructor' },
  { id: 'u2', name: 'Alex Santos', email: 'student@psu.edu', role: 'student', studentId: '2023-0014' },
  { id: 'u3', name: 'Maria Garcia', email: 'maria@psu.edu', role: 'student', studentId: '2023-0089' },
  { id: 'u4', name: 'John Doe', email: 'john@psu.edu', role: 'student', studentId: '2023-0102' },
];

export const MOCK_EXERCISES = [
  {
    id: 'e1',
    title: 'Basic Loops',
    description: 'Write a program that prints numbers from 1 to N.',
    conceptTags: ['Loops', 'Variables'],
    difficulty: 'Beginner',
    starterCode: '#include <iostream>\nusing namespace std;\n\nint main() {\n  // Your code here\n  return 0;\n}',
    testCases: [
      { input: '5', expectedOutput: '1 2 3 4 5', isHidden: false },
      { input: '3', expectedOutput: '1 2 3', isHidden: true },
    ],
    dueDate: '2023-11-15T23:59:59Z',
    createdAt: '2023-11-01T10:00:00Z',
  },
  {
    id: 'e2',
    title: 'Function Calculator',
    description: 'Create a function that adds two numbers and returns the result.',
    conceptTags: ['Functions', 'Datatypes'],
    difficulty: 'Intermediate',
    starterCode: '#include <iostream>\nusing namespace std;\n\n// Add your function here\n\nint main() {\n  return 0;\n}',
    testCases: [
      { input: '2 3', expectedOutput: '5', isHidden: false },
      { input: '-1 5', expectedOutput: '4', isHidden: true },
    ],
    dueDate: '2023-11-20T23:59:59Z',
    createdAt: '2023-11-05T10:00:00Z',
  },
  {
    id: 'e3',
    title: 'Array Reversal',
    description: 'Reverse the elements of an array in place.',
    conceptTags: ['Arrays', 'Loops'],
    difficulty: 'Advanced',
    starterCode: '#include <iostream>\nusing namespace std;\n\nint main() {\n  int arr[] = {1, 2, 3, 4, 5};\n  // Your code here\n  return 0;\n}',
    testCases: [
      { input: '', expectedOutput: '5 4 3 2 1', isHidden: false },
    ],
    dueDate: '2023-11-25T23:59:59Z',
    createdAt: '2023-11-10T10:00:00Z',
  },
];

// Mock data for the student dashboard radar chart.
// Each subject is a programming concept; the value (0–100) is the student's CDS.
export const MOCK_RADAR_DATA = [
  { subject: 'Datatypes', A: 20 },
  { subject: 'Variables', A: 35 },
  { subject: 'Conditionals', A: 45 },
  { subject: 'Loops', A: 85 },
  { subject: 'Functions', A: 65 },
  { subject: 'Arrays', A: 90 },
  { subject: 'OOP', A: 50 },
];
```

- [ ] **Step 2: Commit**

```bash
cd /home/nihil/projects/codeinsight
git add frontend/src/data/mockData.js
git commit -m "feat(student-slice): port mockData.ts → mockData.js"
```

---

## Task 2: Port `auth.ts` → `auth.js` (mock for the new pages)

**Files:**
- Create: `frontend/src/lib/auth.js`

The live `frontend/src/context/AuthContext.jsx` is the **real** auth and must NOT be replaced. This new `lib/auth.js` is a separate, mocked helper used **only** by the new student pages (per the "hybrid: real auth, mock content" decision). The real `AuthContext` is what `/login` continues to use.

- [ ] **Step 1: Create the file**

Create `frontend/src/lib/auth.js` with:

```js
// Ported from Frontend-Design/Frontend-Design/artifacts/codeinsight/src/lib/auth.ts
//
// NOTE: This is a MOCK auth helper used only by the new student pages
// (Dashboard.new, Exercises.new, CodeEditor.new). The real auth path
// lives in context/AuthContext.jsx and is what /login uses.

import { MOCK_USERS } from '../data/mockData';

export const login = (email, role) => {
  const user =
    MOCK_USERS.find((u) => u.email === email && u.role === role) ||
    MOCK_USERS.find((u) => u.role === role);
  localStorage.setItem('codeinsight_user', JSON.stringify(user));
  return user;
};

export const logout = () => {
  localStorage.removeItem('codeinsight_user');
};

export const getCurrentUser = () => {
  const data = localStorage.getItem('codeinsight_user');
  return data ? JSON.parse(data) : null;
};
```

- [ ] **Step 2: Commit**

```bash
cd /home/nihil/projects/codeinsight
git add frontend/src/lib/auth.js
git commit -m "feat(student-slice): port mock auth.ts → auth.js (new pages only)"
```

---

## Task 3: Create `Dashboard.new.jsx` (TSX → JSX, real AuthContext)

**Files:**
- Create: `frontend/src/pages/student/Dashboard.new.jsx`

- [ ] **Step 1: Write the file**

```jsx
import { Link } from 'react-router-dom';
import { useAuth } from '../../context/AuthContext';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import {
  Radar,
  RadarChart,
  PolarGrid,
  PolarAngleAxis,
  PolarRadiusAxis,
  ResponsiveContainer,
} from 'recharts';
import { MOCK_RADAR_DATA } from '../../data/mockData';

/**
 * Student Dashboard — Frontend-Design visual, real AuthContext for `user`.
 *
 * Card grid + radar chart show mock data only.
 * "View all" button navigates to /student/exercises.
 */
export default function StudentDashboard() {
  const { user } = useAuth();

  return (
    <div className="space-y-6">
      <div>
        <h1 className="text-3xl font-bold tracking-tight">
          Welcome back{user?.name ? `, ${user.name.split(' ')[0]}` : ''}
        </h1>
        <p className="text-muted-foreground">Here's an overview of your progress.</p>
      </div>

      <div className="grid gap-6 md:grid-cols-2 lg:grid-cols-4">
        <Card>
          <CardHeader className="flex flex-row items-center justify-between space-y-0 pb-2">
            <CardTitle className="text-sm font-medium">Assigned Exercises</CardTitle>
          </CardHeader>
          <CardContent>
            <div className="text-2xl font-bold">3</div>
            <p className="text-xs text-muted-foreground">2 due this week</p>
          </CardContent>
        </Card>
        <Card>
          <CardHeader className="flex flex-row items-center justify-between space-y-0 pb-2">
            <CardTitle className="text-sm font-medium">Completed</CardTitle>
          </CardHeader>
          <CardContent>
            <div className="text-2xl font-bold">0</div>
            <p className="text-xs text-muted-foreground">+0 since last week</p>
          </CardContent>
        </Card>
        <Card>
          <CardHeader className="flex flex-row items-center justify-between space-y-0 pb-2">
            <CardTitle className="text-sm font-medium">Average CDS</CardTitle>
          </CardHeader>
          <CardContent>
            <div className="text-2xl font-bold">45.2</div>
            <p className="text-xs text-muted-foreground text-orange-500">Medium Difficulty</p>
          </CardContent>
        </Card>
        <Card>
          <CardHeader className="flex flex-row items-center justify-between space-y-0 pb-2">
            <CardTitle className="text-sm font-medium">Current Streak</CardTitle>
          </CardHeader>
          <CardContent>
            <div className="text-2xl font-bold">0 days</div>
            <p className="text-xs text-muted-foreground">Start one today</p>
          </CardContent>
        </Card>
      </div>

      <div className="grid gap-6 md:grid-cols-2">
        <Card className="col-span-1">
          <CardHeader>
            <CardTitle>Concept Difficulty Summary (CDS)</CardTitle>
          </CardHeader>
          <CardContent className="h-[300px]">
            <ResponsiveContainer width="100%" height="100%">
              <RadarChart cx="50%" cy="50%" outerRadius="80%" data={MOCK_RADAR_DATA}>
                <PolarGrid />
                <PolarAngleAxis
                  dataKey="subject"
                  tick={{ fill: 'hsl(var(--foreground))', fontSize: 12 }}
                />
                <PolarRadiusAxis angle={30} domain={[0, 100]} />
                <Radar
                  name="CDS"
                  dataKey="A"
                  stroke="hsl(var(--primary))"
                  fill="hsl(var(--primary))"
                  fillOpacity={0.6}
                />
              </RadarChart>
            </ResponsiveContainer>
          </CardContent>
        </Card>

        <Card className="col-span-1">
          <CardHeader>
            <CardTitle>Recent Activity</CardTitle>
          </CardHeader>
          <CardContent>
            <div className="space-y-4">
              <p className="text-sm text-muted-foreground">No recent activity yet.</p>
              <Button asChild variant="outline" className="w-full">
                <Link to="/student/exercises">Browse exercises</Link>
              </Button>
            </div>
          </CardContent>
        </Card>
      </div>
    </div>
  );
}
```

- [ ] **Step 2: Commit**

```bash
cd /home/nihil/projects/codeinsight
git add frontend/src/pages/student/Dashboard.new.jsx
git commit -m "feat(student-slice): add Dashboard.new.jsx (design visual, real auth)"
```

---

## Task 4: Create `Exercises.new.jsx` (TSX → JSX, wouter → react-router-dom)

**Files:**
- Create: `frontend/src/pages/student/Exercises.new.jsx`

- [ ] **Step 1: Write the file**

```jsx
import { Link } from 'react-router-dom';
import {
  Card,
  CardContent,
  CardHeader,
  CardTitle,
  CardFooter,
} from '@/components/ui/card';
import { Badge } from '@/components/ui/badge';
import { Button } from '@/components/ui/button';
import { MOCK_EXERCISES } from '../../data/mockData';

const difficultyVariant = {
  Beginner: 'secondary',
  Intermediate: 'default',
  Advanced: 'destructive',
};

export default function StudentExercises() {
  return (
    <div className="space-y-6">
      <div>
        <h1 className="text-3xl font-bold tracking-tight">Exercises</h1>
        <p className="text-muted-foreground">Practice and improve your programming skills.</p>
      </div>

      <div className="grid gap-4 md:grid-cols-2 lg:grid-cols-3">
        {MOCK_EXERCISES.map((ex) => (
          <Card key={ex.id} className="flex flex-col h-full">
            <CardHeader>
              <div className="flex justify-between items-start mb-2">
                <Badge variant={difficultyVariant[ex.difficulty] || 'default'}>
                  {ex.difficulty}
                </Badge>
                <span className="text-xs text-muted-foreground">
                  Due: {new Date(ex.dueDate).toLocaleDateString()}
                </span>
              </div>
              <CardTitle className="text-xl">{ex.title}</CardTitle>
            </CardHeader>
            <CardContent className="flex-1">
              <p className="text-sm text-muted-foreground mb-4 line-clamp-2">{ex.description}</p>
              <div className="flex flex-wrap gap-2">
                {ex.conceptTags.map((tag) => (
                  <Badge key={tag} variant="outline">
                    {tag}
                  </Badge>
                ))}
              </div>
            </CardContent>
            <CardFooter className="pt-4 border-t">
              <Button asChild className="w-full">
                <Link to={`/student/exercises/${ex.id}`}>Start Exercise</Link>
              </Button>
            </CardFooter>
          </Card>
        ))}
      </div>
    </div>
  );
}
```

- [ ] **Step 2: Commit**

```bash
cd /home/nihil/projects/codeinsight
git add frontend/src/pages/student/Exercises.new.jsx
git commit -m "feat(student-slice): add Exercises.new.jsx (design visual, mock data)"
```

---

## Task 5: Create `CodeEditor.new.jsx` (TSX → JSX, `useRoute` → `useParams`)

**Files:**
- Create: `frontend/src/pages/student/CodeEditor.new.jsx`

- [ ] **Step 1: Write the file**

```jsx
import { useState } from 'react';
import { useParams, Link } from 'react-router-dom';
import { Button } from '@/components/ui/button';
import { Badge } from '@/components/ui/badge';
import { Play, Send, Clock, AlertCircle, RefreshCw, ChevronLeft } from 'lucide-react';
import { MOCK_EXERCISES } from '../../data/mockData';

/**
 * Code Editor — Frontend-Design visual.
 *
 * Visual-only in this slice. "Run Code" and "Submit" show a fake terminal
 * string so the UI flows end-to-end. Real code execution / submission
 * wiring is the first follow-up slice (it currently lives in the old
 * CodeEditor_new.jsx and is preserved in git history).
 */
export default function StudentCodeEditor() {
  const { exerciseId } = useParams();
  const exercise =
    MOCK_EXERCISES.find((e) => e.id === exerciseId) || MOCK_EXERCISES[0];

  const [code, setCode] = useState(exercise.starterCode);
  const [output, setOutput] = useState(null);

  const handleRun = () => {
    setOutput(`Running...\n\nOutput:\n${exercise.testCases[0].expectedOutput}`);
  };

  const handleSubmit = () => {
    setOutput('Submitting code...\n\nAll test cases passed! Structure validated. CDS updated.');
  };

  return (
    <div className="h-[calc(100vh-100px)] flex flex-col space-y-4">
      <div className="flex items-center justify-between">
        <div>
          <Link
            to="/student/exercises"
            className="inline-flex items-center text-sm text-muted-foreground hover:text-foreground mb-2"
          >
            <ChevronLeft className="w-4 h-4 mr-1" /> Back to exercises
          </Link>
          <h1 className="text-2xl font-bold tracking-tight">{exercise.title}</h1>
          <div className="flex items-center gap-2 mt-1">
            <Badge variant="outline">{exercise.difficulty}</Badge>
            {exercise.conceptTags.map((tag) => (
              <Badge key={tag} variant="secondary">
                {tag}
              </Badge>
            ))}
          </div>
        </div>
        <div className="flex gap-4 text-sm text-muted-foreground">
          <div className="flex items-center gap-1">
            <Clock className="w-4 h-4" /> 0m 0s
          </div>
          <div className="flex items-center gap-1">
            <AlertCircle className="w-4 h-4" /> 0 errors
          </div>
          <div className="flex items-center gap-1">
            <RefreshCw className="w-4 h-4" /> 0 submits
          </div>
        </div>
      </div>

      <div className="flex-1 grid grid-cols-1 lg:grid-cols-2 gap-4 min-h-0">
        {/* Left Panel: Description */}
        <div className="flex flex-col gap-4 overflow-hidden">
          <div className="flex-1 bg-card rounded-xl border p-6 overflow-auto">
            <h2 className="font-semibold mb-4">Description</h2>
            <p className="text-sm leading-relaxed mb-6">{exercise.description}</p>

            <h3 className="font-semibold text-sm mb-2 text-muted-foreground uppercase tracking-wider">
              Visible Test Case
            </h3>
            <div className="bg-muted p-4 rounded-md space-y-3 font-mono text-sm">
              <div>
                <div className="text-muted-foreground mb-1">Input:</div>
                <div className="bg-background p-2 rounded border">
                  {exercise.testCases[0].input || '(none)'}
                </div>
              </div>
              <div>
                <div className="text-muted-foreground mb-1">Expected Output:</div>
                <div className="bg-background p-2 rounded border">
                  {exercise.testCases[0].expectedOutput}
                </div>
              </div>
            </div>
          </div>
        </div>

        {/* Right Panel: Editor & Output */}
        <div className="flex flex-col gap-4 overflow-hidden">
          <div className="flex-1 bg-[#1e1e1e] rounded-xl border overflow-hidden flex flex-col relative group">
            <div className="h-10 bg-[#2d2d2d] flex items-center px-4 text-xs font-mono text-gray-400 border-b border-[#3d3d3d]">
              main.cpp
            </div>
            <textarea
              value={code}
              onChange={(e) => setCode(e.target.value)}
              className="flex-1 bg-transparent text-[#d4d4d4] font-mono p-4 resize-none focus:outline-none"
              spellCheck={false}
            />
          </div>

          <div className="h-48 bg-card rounded-xl border p-4 flex flex-col">
            <div className="flex justify-between items-center mb-2">
              <h3 className="font-semibold text-sm">Terminal Output</h3>
              <div className="flex gap-2">
                <Button variant="secondary" size="sm" onClick={handleRun} className="gap-1">
                  <Play className="w-4 h-4" /> Run Code
                </Button>
                <Button size="sm" onClick={handleSubmit} className="gap-1">
                  <Send className="w-4 h-4" /> Submit
                </Button>
              </div>
            </div>
            <div className="flex-1 bg-muted rounded-md p-3 font-mono text-sm overflow-auto whitespace-pre-wrap">
              {output || 'Run your code to see output here.'}
            </div>
          </div>
        </div>
      </div>
    </div>
  );
}
```

- [ ] **Step 2: Commit**

```bash
cd /home/nihil/projects/codeinsight
git add frontend/src/pages/student/CodeEditor.new.jsx
git commit -m "feat(student-slice): add CodeEditor.new.jsx (design visual, mock run/submit)"
```

---

## Task 6: Re-point 3 student routes in `App.jsx`

**Files:**
- Modify: `frontend/src/App.jsx`

- [ ] **Step 1: Read the current imports**

The current `App.jsx` imports the 3 student pages like this (lines 15–17):

```jsx
import StudentExerciseList from './pages/student/ExerciseList';
import StudentCodeEditor from './pages/student/CodeEditor_new';
import StudentProgress from './pages/student/Progress';
```

(`StudentExerciseList` is also used as the alias for the dashboard route in several places.)

- [ ] **Step 2: Update the imports**

Change the 3 student page imports to point at the new files. Keep `StudentProgress` and `StudentProfile` untouched. Add an import for the new dashboard:

```jsx
import StudentDashboard from './pages/student/Dashboard.new';
import StudentExerciseList from './pages/student/Exercises.new';
import StudentCodeEditor from './pages/student/CodeEditor.new';
import StudentProgress from './pages/student/Progress';
import StudentProfile from './pages/student/Profile';
```

- [ ] **Step 3: Add the `pageTitle` prop on the student routes**

Each `<ProtectedRoute requiredRole="student">` that renders a student page needs to pass a `pageTitle` so the new `Layout` header shows the right title. The current `<Layout>` already supports a `pageTitle` prop. Update the 3 student routes to pass titles. Locate the three `<Route>` blocks in `App.jsx` that render student pages and update them. For example:

```jsx
<Route path="/student" element={
  <ProtectedRoute requiredRole="student">
    <StudentDashboard />
  </ProtectedRoute>
} />
```

becomes:

```jsx
<Route path="/student" element={
  <ProtectedRoute requiredRole="student" pageTitle="Dashboard">
    <StudentDashboard />
  </ProtectedRoute>
} />
```

Apply the same change to:
- `/student/dashboard` → `pageTitle="Dashboard"`
- `/student/exercises` → `pageTitle="Exercises"`
- `/student/exercises/:exerciseId` → `pageTitle="Code Editor"`

(And the two design-aligned alias routes for `/student/exercises` and `/student/exercises/:exerciseId` near the bottom of `App.jsx` — give them the same titles.)

Note: `ProtectedRoute` wraps children in `<Layout>`, and `<Layout>` reads `pageTitle` from a prop that needs to be threaded through. Look at the current `App.jsx` `ProtectedRoute` definition (lines 23–32): it currently passes only `children`. Extend it to accept and forward `pageTitle`:

```jsx
function ProtectedRoute({ children, requiredRole, pageTitle }) {
  const { isLoggedIn, user } = useAuth();

  if (!isLoggedIn) return <Navigate to="/login" replace />;
  if (requiredRole && user?.role !== requiredRole) {
    const home = user?.role === 'instructor' ? '/instructor/dashboard' : '/student/dashboard';
    return <Navigate to={home} replace />;
  }
  return <Layout pageTitle={pageTitle}>{children}</Layout>;
}
```

- [ ] **Step 4: Commit**

```bash
cd /home/nihil/projects/codeinsight
git add frontend/src/App.jsx
git commit -m "feat(student-slice): re-point 3 student routes to .new pages"
```

---

## Task 7: Lighten `Layout.jsx` spacing to match design rhythm

**Files:**
- Modify: `frontend/src/components/Layout.jsx`

- [ ] **Step 1: Read the current file**

The current `Layout.jsx` is 41 lines, wraps `{children}` in a `<main>` that uses the `SidebarContext` margin and a `pageTitle` sticky header.

- [ ] **Step 2: Constrain the content width and add the design's spacing**

Find the inner `<div className="w-full">{children}</div>` and replace it with:

```jsx
<div className="w-full max-w-7xl mx-auto p-6 lg:p-8">
  {children}
</div>
```

This matches the Frontend-Design `AppLayout.tsx` content area (`flex-1 overflow-auto p-6 lg:p-8 bg-muted/10`) but keeps our existing `Layout` structure (sidebar + sticky header).

- [ ] **Step 3: Commit**

```bash
cd /home/nihil/projects/codeinsight
git add frontend/src/components/Layout.jsx
git commit -m "feat(student-slice): align Layout spacing with Frontend-Design rhythm"
```

---

## Task 8: Build, run, and validate

**Files:** None (verification only)

- [ ] **Step 1: Build the frontend**

```bash
cd /home/nihil/projects/codeinsight/frontend
npm run build
```

Expected: build completes with no errors. Warnings about unused imports are OK only if they exist in the OLD untouched files (e.g., `CodeEditor_new.jsx.bak`); the new files must be warning-free.

- [ ] **Step 2: Boot the dev server in the background**

```bash
cd /home/nihil/projects/codeinsight/frontend
npm run dev
```

Run this in the background (`run_in_background: true`) so subsequent steps can hit the server. Note the URL it prints (typically `http://localhost:5173`).

- [ ] **Step 3: Smoke-test the student flow**

Hit each route and confirm:
- `/login` renders the existing real-backend login form (unchanged).
- After logging in as a student, `/student/dashboard` shows 4 stat cards + radar chart + recent activity.
- `/student/exercises` shows 3 exercise cards in a responsive grid.
- Clicking "Start Exercise" navigates to `/student/exercises/e1` (or whichever id) and shows the editor shell with description left, dark editor right, terminal output bottom.
- "Run Code" and "Submit" produce the mock output strings.
- `/student/progress` and `/student/profile` still render their existing (untouched) code.
- All `/instructor/*` routes still work.

If the dev server log shows React errors or missing-import warnings, fix them before proceeding.

- [ ] **Step 4: Stop the dev server**

Use `KillShell` on the background task from Step 2.

- [ ] **Step 5: Delete the old student files**

```bash
cd /home/nihil/projects/codeinsight
rm frontend/src/pages/student/Dashboard.jsx
rm frontend/src/pages/student/ExerciseList.jsx
rm frontend/src/pages/student/CodeEditor_new.jsx
```

Update `App.jsx` if any of those filenames are still referenced (the new imports in Task 6 should already have replaced them — verify with `grep -n "ExerciseList\|Dashboard.jsx\|CodeEditor_new.jsx" frontend/src/App.jsx` and clean up any stragglers).

- [ ] **Step 6: Rename `.new.jsx` to canonical filenames**

```bash
cd /home/nihil/projects/codeinsight
mv frontend/src/pages/student/Dashboard.new.jsx     frontend/src/pages/student/Dashboard.jsx
mv frontend/src/pages/student/Exercises.new.jsx     frontend/src/pages/student/Exercises.jsx
mv frontend/src/pages/student/CodeEditor.new.jsx    frontend/src/pages/student/CodeEditor.jsx
```

Update the imports in `App.jsx` to match the canonical filenames:

```jsx
import StudentDashboard from './pages/student/Dashboard';
import StudentExerciseList from './pages/student/Exercises';
import StudentCodeEditor from './pages/student/CodeEditor';
```

- [ ] **Step 7: Final build**

```bash
cd /home/nihil/projects/codeinsight/frontend
npm run build
```

Expected: clean build, no errors, no new warnings introduced by the rename.

- [ ] **Step 8: Commit the cutover**

```bash
cd /home/nihil/projects/codeinsight
git add -A frontend/src/pages/student/ frontend/src/App.jsx
git commit -m "feat(student-slice): cut over to new student pages, remove old files"
```

---

## Task 9: Final report

**Files:**
- Create: `docs/superpowers/plans/2026-06-04-student-slice-report.md`

- [ ] **Step 1: Write a short final report**

```markdown
# Student-Flow Vertical Slice — Final Report

**Date:** 2026-06-04
**Status:** [Completed / Blocked — see notes]
**Branch:** feature/cds-auto-trigger

## Routes Migrated
- `/student/dashboard` → `frontend/src/pages/student/Dashboard.jsx` (new)
- `/student/exercises` → `frontend/src/pages/student/Exercises.jsx` (new)
- `/student/exercises/:exerciseId` → `frontend/src/pages/student/CodeEditor.jsx` (new)

## Features Migrated
- Card-grid dashboard with 4 KPI cards + radar chart of CDS by concept
- Responsive 3-up exercise card grid with difficulty badges and "Start Exercise" CTAs
- Split-pane code editor: description (left), dark editor + terminal output (right)

## Features Designed In Mock Mode (real wiring in follow-up)
- "Run Code" and "Submit" buttons — show fake terminal output, not real execution
- "Average CDS" / "Completed" / "Streak" / "Recent Activity" — static mock numbers
- Exercise list — sourced from `MOCK_EXERCISES`, not the backend

## Design Tokens Applied
- `bg-card`, `text-card-foreground`, `text-muted-foreground`, `bg-muted`, `text-primary`, `bg-primary/10` (shadcn semantic tokens already present in `index.css`)
- `rounded-xl`, `border` (matches Frontend-Design `AppLayout` content)
- VS-Code-style dark editor chrome (`#1e1e1e` / `#2d2d2d` / `#d4d4d4`) preserved verbatim from the design
- `max-w-7xl mx-auto p-6 lg:p-8` content container (matches `AppLayout.tsx`)

## Out of Scope / Follow-up Slices
- Instructor vertical slice (10 pages)
- Real-API integration for student pages (replace `MOCK_EXERCISES` with `api.js` calls)
- Real code execution / submission in the editor (logic exists in old `CodeEditor_new.jsx.bak`, port forward)
- `LiveCDSPanel`, `IntegrityFlagBadge`, `CodeComparisonModal`, `EnrollStudentsModal`, `analytics/*` widgets
- Design tokens doc at `docs/superpowers/specs/2026-06-04-design-tokens.md`
- Mobile responsive pass + a11y audit

## Build Status
- `npm run build` — pass / fail (record)
- Dev server smoke test — pass / fail (record)
```

Fill in the bracketed status, the `pass / fail` lines, and any observations.

- [ ] **Step 2: Commit the report**

```bash
cd /home/nihil/projects/codeinsight
git add docs/superpowers/plans/2026-06-04-student-slice-report.md
git commit -m "docs(student-slice): add final report"
```

---

## Self-Review (run before handoff)

- **Spec coverage:** §3.1 (mockData, auth, 3 new pages) → Tasks 1–5. §3.2 (App.jsx + Layout.jsx) → Tasks 6–7. §6 (validation) → Task 8. §8 (final report) → Task 9. ✓
- **Placeholder scan:** No "TBD"/"TODO"/"implement later" steps. All code blocks are full. ✓
- **Type consistency:** `useParams()` returns `{ exerciseId }` and is read that way in Task 5. The `difficultyVariant` map keys (`Beginner`/`Intermediate`/`Advanced`) match the values in `MOCK_EXERCISES`. `Role` is exported as a `const` object (not a TS enum) and is unused by the new pages (they only need the real `AuthContext`). ✓
- **Risk check:** Old student files are kept around through Task 6 (re-point) and only deleted in Task 8 Step 5 — this is the safe order, no orphaned references. `ProtectedRoute` change in Task 6 Step 3 adds a new prop without breaking existing call sites (any `<ProtectedRoute>` that omits `pageTitle` still works because `<Layout>` checks the prop truthy). ✓

---

**Plan complete. Two execution options:**

1. **Subagent-Driven (recommended)** — I dispatch a fresh subagent per task, review between tasks, fast iteration with two-stage review.
2. **Inline Execution** — I execute tasks in this session using `executing-plans`, batch execution with checkpoints for your review.

Which approach?
