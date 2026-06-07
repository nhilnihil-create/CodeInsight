/**
 * Mock data for the CodeEditor workbench. Real /api wiring is a follow-up;
 * the previous /api/student/exercises/:id + /run + /submit endpoints are
 * parked for the next sprint.
 */

export const EXERCISE = {
  id: "e7",
  title: "Recursion I",
  language: "cpp",
  languageLabel: "C++",
  timeLimit: 35,
  deadlineLabel: "Jun 6",
  description: `# Recursion I

Write a function that returns the **nth Fibonacci number** using recursion.

Your function must:

- Take a single non-negative integer *n*
- Return the nth value in the Fibonacci sequence (0-indexed)
- Handle the base cases: \`fib(0) == 0\` and \`fib(1) == 1\`

Use recursion (not iteration or memoization) to demonstrate the technique.
`,
  functionSignature: "long long fib(int n);",
  inputFormat: "A single integer n on a line.",
  outputFormat: "The nth Fibonacci number, on its own line.",
  examples: [
    { input: "0",  output: "0"  },
    { input: "1",  output: "1"  },
    { input: "5",  output: "5"  },
    { input: "10", output: "55" },
  ],
  constraints: [
    "0 ≤ n ≤ 40",
    "Use recursion (no loops, no memoization).",
    "Runtime target: < 100 ms.",
  ],
  concepts: [
    { code: "RC", name: "Recursion" },
    { code: "BC", name: "Base case" },
  ],
  peerBenchmark: "78% of your classmates passed this on the first attempt.",
};

export const LANGUAGE_OPTIONS = [
  { value: "cpp",       label: "C++"        },
  { value: "python",    label: "Python"     },
  { value: "javascript",label: "JavaScript" },
  { value: "java",      label: "Java"       },
  { value: "go",        label: "Go"         },
];

export const INITIAL_CODE = `#include <iostream>
using namespace std;

// Return the nth Fibonacci number (0-indexed).
long long fib(int n) {
  // TODO: implement
  return 0;
}

int main() {
  int n;
  cin >> n;
  cout << fib(n);
  return 0;
}
`;

/**
 * testResults shape consumed by OutputPanel:
 *   { passing, total, passed, error, compilationLog, programOutput,
 *     testResults: [ { passed, runtimeMs, input, expected, actual } ],
 *     hidden: { total, failed } }
 */
export const INITIAL_TEST_RESULTS = {
  passing: 3,
  total: 8,
  passed: false,
  error: null,
  compilationLog:
    "[g++ -std=c++17 -O2] main.cpp compiled in 1.42 s · 0 warnings",
  programOutput:
    "Running...\n" +
    "Test case 5 failed\n" +
    "Input: 10\n" +
    "Expected: 55\n" +
    "Got: 0\n" +
    "Time: 0 ms   Memory: 2.1 MB",
  testResults: [
    { passed: true,  runtimeMs:  8, input: "0",  expected: "0",     actual: "0"     },
    { passed: true,  runtimeMs:  9, input: "1",  expected: "1",     actual: "1"     },
    { passed: true,  runtimeMs: 12, input: "5",  expected: "5",     actual: "5"     },
    { passed: false, runtimeMs: 14, input: "10", expected: "55",    actual: "0"     },
    { passed: false, runtimeMs: 16, input: "20", expected: "6765",  actual: "0"     },
    { passed: false, runtimeMs: 22, input: "30", expected: "832040",actual: "0"     },
    { passed: false, runtimeMs: 28, input: "35", expected: "9227465", actual: "0"  },
    { passed: false, runtimeMs: 31, input: "40", expected: "102334155", actual: "0" },
  ],
  hidden: { total: 1, failed: 1 },
  console: `[g++ -std=c++17 -O2] compiled in 1.42s
Running 8 tests…
  test 1: passed (8ms)
  test 2: passed (9ms)
  test 3: passed (12ms)
  test 4: FAILED — expected 55, got 0
  test 5: FAILED — expected 6765, got 0
  test 6: FAILED — expected 832040, got 0
  test 7: FAILED — expected 9227465, got 0
  test 8: FAILED — expected 102334155, got 0
Summary: 3 / 8 passing`,
  cds: 0.46,
  classification: "Moderate",
};

export const SUBMISSIONS = [
  { id: 1842, status: "wrong_answer", passed: 5, total: 8, runtime: "14 ms", memory: "8.2 MB", language: "C++", timestamp: "2m ago",  input: "10", expected: "55",  actual: "0"   },
  { id: 1841, status: "wrong_answer", passed: 4, total: 8, runtime: "12 ms", memory: "8.1 MB", language: "C++", timestamp: "12m ago", input: "10", expected: "55",  actual: "0"   },
  { id: 1840, status: "wrong_answer", passed: 3, total: 8, runtime: "11 ms", memory: "8.0 MB", language: "C++", timestamp: "22m ago", input: "5",  expected: "5",   actual: "0"   },
  { id: 1839, status: "wrong_answer", passed: 3, total: 8, runtime: "10 ms", memory: "8.0 MB", language: "C++", timestamp: "1h ago",  input: "5",  expected: "5",   actual: "0"   },
  { id: 1838, status: "wrong_answer", passed: 2, total: 8, runtime: " 9 ms", memory: "7.9 MB", language: "C++", timestamp: "1h ago",  input: "1",  expected: "1",   actual: "0"   },
];

export const HISTORY = [
  { id: "h1", type: "submission", label: "Submitted · 5/8",                          timestamp: "2m ago"  },
  { id: "h2", type: "run",        label: "Run · 3/8 passing",                         timestamp: "5m ago"  },
  { id: "h3", type: "edit",       label: "Edited fib() — added base case",            timestamp: "8m ago"  },
  { id: "h4", type: "submission", label: "Submitted · 4/8",                          timestamp: "12m ago" },
  { id: "h5", type: "run",        label: "Run · 4/8 passing",                         timestamp: "15m ago" },
  { id: "h6", type: "edit",       label: "Edited fib() — implemented recursion",      timestamp: "20m ago" },
  { id: "h7", type: "submission", label: "Submitted · 3/8",                          timestamp: "22m ago" },
  { id: "h8", type: "run",        label: "Run · 2/8 passing",                         timestamp: "25m ago" },
  { id: "h9", type: "edit",       label: "Started exercise",                          timestamp: "30m ago" },
];
