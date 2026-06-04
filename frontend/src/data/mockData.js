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
