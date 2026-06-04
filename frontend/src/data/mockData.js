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

// ----------------------------------------------------------------------------
// Instructor-slice mock data (added 2026-06-04) — see spec §5.3.
// ----------------------------------------------------------------------------

// Per-student summary stats for the InstructorStudents table.
export const MOCK_STUDENT_STATS = [
  { studentId: 'u2', avgCds: 72, highestConcept: 'Loops',      lastActiveDays: 1, hasAlert: false },
  { studentId: 'u3', avgCds: 58, highestConcept: 'Arrays',     lastActiveDays: 4, hasAlert: true  },
  { studentId: 'u4', avgCds: 41, highestConcept: 'Conditionals', lastActiveDays: 9, hasAlert: true  },
];

// Class-wide concept heatmap: rows = students, cols = concepts, value 0-100.
export const MOCK_HEATMAP = [
  { studentId: 'u2', name: 'Alex Santos',  scores: { Loops: 90, Arrays: 75, Functions: 60, Pointers: 40, OOP: 55, Variables: 85, Datatypes: 80, Conditionals: 70 } },
  { studentId: 'u3', name: 'Maria Garcia', scores: { Loops: 55, Arrays: 60, Functions: 45, Pointers: 30, OOP: 40, Variables: 70, Datatypes: 65, Conditionals: 50 } },
  { studentId: 'u4', name: 'John Doe',    scores: { Loops: 35, Arrays: 25, Functions: 20, Pointers: 15, OOP: 30, Variables: 55, Datatypes: 50, Conditionals: 40 } },
];

// Integrity flags rendered on the InstructorIntegrity page.
export const MOCK_INTEGRITY_FLAGS = [
  { id: 1, student: 'John Doe',     exercise: 'Basic Loops',         type: 'Hardcoding',           confidence: 95, desc: 'Student output matches expected exactly using hardcoded string outputs rather than logic.', time: '2 hours ago' },
  { id: 2, student: 'Alex Santos',  exercise: 'Function Calculator', type: 'Behavioral Anomaly',   confidence: 88, desc: 'Solution pasted directly. 0 keystrokes tracked prior to correct submission.',                       time: '1 day ago'   },
  { id: 3, student: 'Maria Garcia', exercise: 'Array Reversal',      type: 'Passive Behavior',     confidence: 75, desc: 'Editor open for 45 minutes with less than 10 keystrokes.',                                         time: '2 days ago'  },
  { id: 4, student: 'John Doe',     exercise: 'Array Reversal',      type: 'Code Growth Spike',    confidence: 92, desc: 'Code size increased by 500% in a single second. Possible copy-paste.',                            time: '3 days ago'  },
];

// Structure violations rendered on the InstructorViolations page.
export const MOCK_STRUCTURE_VIOLATIONS = [
  { id: 1, student: 'Alex Santos',  exercise: 'Array Reversal',  concept: 'Arrays', type: 'Output Mismatch', message: 'Expected "5 4 3 2 1" but got "1 2 3 4 5"',     severity: 'high',   time: '5 hours ago' },
  { id: 2, student: 'John Doe',     exercise: 'Function Calculator', concept: 'Functions', type: 'Missing Return',  message: 'Function declares int return type but returns nothing.', severity: 'medium', time: '1 day ago'  },
  { id: 3, student: 'Maria Garcia', exercise: 'Basic Loops',     concept: 'Loops',     type: 'Off-By-One',       message: 'Loop runs n+1 times; expected n iterations.',          severity: 'low',    time: '2 days ago'  },
  { id: 4, student: 'John Doe',     exercise: 'Basic Loops',     concept: 'Loops',     type: 'Infinite Loop',    message: 'Loop condition never becomes false.',                  severity: 'high',   time: '3 days ago'  },
];

// Weekly class-average CDS + high-risk-student counts for the Reports page.
export const MOCK_REPORTS_TIMELINE = [
  { week: 'W1', avgCds: 52, highRiskStudents: 4 },
  { week: 'W2', avgCds: 58, highRiskStudents: 3 },
  { week: 'W3', avgCds: 61, highRiskStudents: 2 },
  { week: 'W4', avgCds: 64, highRiskStudents: 2 },
  { week: 'W5', avgCds: 68, highRiskStudents: 1 },
];

// Concept-level average CDS for the "Most Difficult Concepts" card.
export const MOCK_MOST_DIFFICULT_CONCEPTS = [
  { concept: 'Pointers',     score: 32 },
  { concept: 'OOP',          score: 45 },
  { concept: 'Functions',    score: 55 },
  { concept: 'Conditionals', score: 62 },
];
