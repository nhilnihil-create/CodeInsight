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

// Structure violations — consumed by the unified /instructor/integrity page.
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

// ----------------------------------------------------------------------------
// Redesign mock data (added 2026-06-05) — see redesign spec §8, §9, §10, §11
// ----------------------------------------------------------------------------

export const MOCK_SECTIONS = [
  { id: 'sec1', code: 'K7P-3QX', name: 'BSIT-1A Morning', term: '2026-1', instructorId: 'u1',
    status: 'active', joinPolicy: 'code', maxSize: 60, studentCount: 47, avgCds: 0.42, atRiskCount: 7,
    topInsight: 'Functions is the hardest concept this week  3 flags open' },
  { id: 'sec2', code: 'M9R-2BV', name: 'BSIT-1B Afternoon', term: '2026-1', instructorId: 'u1',
    status: 'active', joinPolicy: 'request', maxSize: 60, studentCount: 52, avgCds: 0.38, atRiskCount: 4,
    topInsight: 'Loops showing improvement  1 flag open' },
  { id: 'sec3', code: 'J5T-1XC', name: 'BSCS-1A Morning', term: '2026-1', instructorId: 'u1',
    status: 'active', joinPolicy: 'code', maxSize: 45, studentCount: 38, avgCds: 0.45, atRiskCount: 9,
    topInsight: 'Arrays is the hardest concept  5 flags open' },
];

export const MOCK_MEMBERSHIPS = [
  { id: 'm1', sectionId: 'sec1', userId: 'u2', role: 'student', status: 'active', joinedAt: '2026-01-15' },
  { id: 'm2', sectionId: 'sec1', userId: 'u3', role: 'student', status: 'active', joinedAt: '2026-01-15' },
  { id: 'm3', sectionId: 'sec1', userId: 'u4', role: 'student', status: 'active', joinedAt: '2026-01-16' },
  { id: 'm4', sectionId: 'sec1', userId: 'u5', role: 'student', status: 'left_requested', joinedAt: '2026-01-14', dropReason: 'schedule conflict' },
  { id: 'm5', sectionId: 'sec2', userId: 'u2', role: 'student', status: 'active', joinedAt: '2026-01-20' },
];

export const MOCK_AUDIT_LOG = [
  { id: 'a1', sectionId: 'sec1', actorId: 'u1', action: 'section_created', meta: { name: 'BSIT-1A Morning' }, createdAt: '2026-01-10T08:00:00Z' },
  { id: 'a2', sectionId: 'sec1', actorId: 'u1', action: 'code_rotated', meta: { code: 'K7P-3QX' }, createdAt: '2026-01-10T08:05:00Z' },
  { id: 'a3', sectionId: 'sec1', actorId: 'u2', action: 'student_joined', meta: { code: 'K7P-3QX' }, createdAt: '2026-01-15T09:00:00Z' },
  { id: 'a4', sectionId: 'sec1', actorId: 'u1', action: 'student_dropped', meta: { studentId: 'u5', reason: 'transferred to BSIT-1B per registrar' }, createdAt: '2026-03-01T10:00:00Z' },
];

export const MOCK_COMMAND_CENTER = {
  confidence: { level: 'high', n: 312, days: 18, wilsonHalfWidth: 0.08 },
  weeklyInsight: {
    rule: 'concept-difficulty-rising',
    n: 47,
    message: 'Functions is the hardest concept this week, with 14 of 47 students in High difficulty.',
    action: 'Assign Function-Args-Warmup to BSIT-1A before Wednesdays class. 12 students covered.',
  },
  cards: [
    { id: 'what', title: 'What is happening?', summary: 'Functions is the hardest concept this week. Class CDS 0.62.',
      why: null, confidence: { level: 'high', n: 312 } },
    { id: 'why', title: 'Why is it happening?', summary: '12 of those 14 students fail on the same test case  pass-by-reference is the dominant misconception.',
      why: 'Pattern observation: 85% of incorrect submissions on Ex-4 fail test case 3 (pass-by-reference).',
      confidence: { level: 'high', n: 47 } },
    { id: 'who', title: 'Who needs help?', summary: '7 students on the at-risk roster. 3 moved Low  High in the last 7 days.',
      why: null, confidence: { level: 'medium', n: 14 } },
    { id: 'action', title: 'What action should be taken?', summary: 'Assign Function-Args-Warmup to BSIT-1A before Wednesdays class. 12 students covered.',
      why: 'Recommended intervention: targeted warmup exercise covers the 12 students who failed test case 3.',
      confidence: { level: 'high', n: 12 }, drillTo: '/instructor/exercises/new' },
  ],
  kpis: [
    { label: 'Class Avg CDS', value: 0.42, delta: 0.03, trend: 'down', sparkline: [0.38, 0.40, 0.39, 0.41, 0.40, 0.42] },
    { label: 'Submissions/Week', value: 187, delta: 12, trend: 'up', sparkline: [145, 162, 158, 175, 180, 187] },
    { label: 'At-Risk Count', value: 7, delta: -2, trend: 'up', sparkline: [12, 11, 9, 8, 9, 7] },
    { label: 'Integrity Flags', value: 3, delta: 1, trend: 'down', sparkline: [2, 1, 1, 2, 2, 3] },
    { label: 'Active Sections', value: 3, delta: 0, trend: 'flat', sparkline: [2, 2, 3, 3, 3, 3] },
    { label: 'Mastery Rate', value: 0.72, delta: 0.05, trend: 'up', sparkline: [0.62, 0.64, 0.66, 0.68, 0.70, 0.72] },
  ],
  conceptBars: [
    { concept: 'FN', name: 'Functions', cds: 0.62, delta: 0.08, trend: 'down', atRiskCount: 14 },
    { concept: 'AR', name: 'Arrays', cds: 0.55, delta: 0.03, trend: 'down', atRiskCount: 9 },
    { concept: 'LP', name: 'Loops', cds: 0.48, delta: -0.02, trend: 'up', atRiskCount: 7 },
    { concept: 'OP', name: 'OOP', cds: 0.45, delta: 0.01, trend: 'flat', atRiskCount: 5 },
    { concept: 'CD', name: 'Conditionals', cds: 0.38, delta: -0.04, trend: 'up', atRiskCount: 4 },
    { concept: 'VR', name: 'Variables', cds: 0.25, delta: -0.03, trend: 'up', atRiskCount: 2 },
    { concept: 'DT', name: 'Datatypes', cds: 0.18, delta: -0.01, trend: 'up', atRiskCount: 1 },
  ],
  atRiskRoster: [
    { id: 's1', name: 'John Doe', riskTier: 'critical', dominantConcept: 'FN' },
    { id: 's2', name: 'Maria Garcia', riskTier: 'high', dominantConcept: 'AR' },
    { id: 's3', name: 'Alex Santos', riskTier: 'high', dominantConcept: 'FN' },
  ],
  signals: [
    '3 students repeated the same Ex-3 attempt 4+ times this week.',
    '5 students submitted blank or near-blank templates on Ex-4.',
    'Class avg completion time for Functions exercises: +18% vs last week.',
  ],
  interventions: [
    {
      student: { name: 'John Doe', id: 'u4' },
      problem: { concept: 'FN', cds: 0.71, delta: 0.12, classification: 'high', trend: 'down', description: 'Failed pass-by-reference test case 3 times.' },
      evidence: ['Attempts: 4 on Ex-4', 'Avg time: 28 min vs class avg 14 min', 'Code growth: 0% (no changes between attempts)'],
      suggestedAction: { label: 'Assign Function Args Warmup' },
    },
    {
      student: { name: 'Maria Garcia', id: 'u3' },
      problem: { concept: 'AR', cds: 0.65, delta: 0.06, classification: 'high', trend: 'down', description: 'Array reversal with mixed types.' },
      evidence: ['Attempts: 3 on Ex-3', 'Compiler errors: 6 per attempt avg'],
      suggestedAction: { label: 'Schedule 1:1 Review' },
    },
  ],
  integrityFlags: { count: 3, sections: 2, flags: [] },
};

export const MOCK_STUDENT_PROGRESS = {
  cdsOverTime: [
    { week: 'W1', student: 0.35, classAvg: 0.38 },
    { week: 'W2', student: 0.32, classAvg: 0.40 },
    { week: 'W3', student: 0.28, classAvg: 0.39 },
    { week: 'W4', student: 0.25, classAvg: 0.41 },
    { week: 'W5', student: 0.22, classAvg: 0.40 },
    { week: 'W6', student: 0.20, classAvg: 0.42 },
  ],
  perConceptTrend: [
    { concept: 'DT', name: 'Datatypes', cds: 0.15, delta: -0.05, trend: 'up' },
    { concept: 'VR', name: 'Variables', cds: 0.18, delta: -0.03, trend: 'up' },
    { concept: 'CD', name: 'Conditionals', cds: 0.22, delta: -0.02, trend: 'up' },
    { concept: 'LP', name: 'Loops', cds: 0.35, delta: 0.04, trend: 'down' },
    { concept: 'FN', name: 'Functions', cds: 0.62, delta: 0.08, trend: 'down' },
    { concept: 'AR', name: 'Arrays', cds: 0.45, delta: 0.03, trend: 'down' },
    { concept: 'OP', name: 'OOP', cds: 0.50, delta: 0.02, trend: 'flat' },
  ],
  masteredConcepts: ['Datatypes', 'Variables'],
};

export const MOCK_STUDENT_TODAY = {
  focus: { title: 'Ex-4 on Functions', estimatedMinutes: '15-20', concept: 'FN' },
  why: 'Functions is currently your highest-CDS concept at 0.62. Working on it now will have the biggest effect on your week.',
  classAvg: 0.38,
  concepts: [
    { concept: 'DT', name: 'Datatypes', cds: 0.15, delta: -0.05, trend: 'up' },
    { concept: 'VR', name: 'Variables', cds: 0.18, delta: -0.03, trend: 'up' },
    { concept: 'CD', name: 'Conditionals', cds: 0.22, delta: -0.02, trend: 'up' },
    { concept: 'LP', name: 'Loops', cds: 0.35, delta: 0.04, trend: 'down' },
    { concept: 'FN', name: 'Functions', cds: 0.62, delta: 0.08, trend: 'down' },
    { concept: 'AR', name: 'Arrays', cds: 0.45, delta: 0.03, trend: 'down' },
    { concept: 'OP', name: 'OOP', cds: 0.50, delta: 0.02, trend: 'flat' },
  ],
  signals: [
    'Youve improved your completion time on Loops exercises by 25%.',
    'Functions exercises take you longer than average  thats okay, practice helps.',
  ],
  nextMoves: [
    { label: 'Start Ex-4', to: '/student/exercises/e4', primary: true },
    { label: 'Try Functions Warmup', to: '/student/exercises/w1' },
    { label: 'Review Datatypes', to: '/student/exercises/e1' },
  ],
};

export const MOCK_RECOMMENDATIONS = [
  { priority: 1, pattern: 'Your Functions CDS is 0.62  the highest among your concepts.',
    confidence: 'high', whyLink: true, action: { label: 'Start Ex-4', to: '/student/exercises/e4' } },
  { priority: 2, pattern: 'Your completion time on Arrays is 30% above your own average.',
    confidence: 'medium', whyLink: true, action: { label: 'Try Array Warmup', to: '/student/exercises/w2' } },
  { priority: 3, pattern: 'Youve shown consistent mastery on Conditionals this term.',
    confidence: 'high', whyLink: false, action: { label: 'Skip ahead', to: '/student/exercises/e5' } },
];

export const MOCK_STUDENT_INTEGRITY = {
  flags: [
    { id: 'f1', rule: 'behavioral_anomaly  code_growth_spike', description: 'Your code grew faster than 95% of the class in this session.',
      date: '2026-05-28', evidence: 'Exercise: Basic Loops. Your code jumped from 5 lines to 85 lines in under 1 second.' },
  ],
};
