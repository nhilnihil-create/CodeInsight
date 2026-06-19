const BASE_URL = 'http://localhost:5173';
const BACKEND_URL = 'http://localhost:5000';
const DB_CONFIG = { host: 'localhost', port: 5432, database: 'codeinsight', user: 'codeuser', password: 'codepassword123' };
const INSTRUCTOR = { email: 'instructor@psu.edu', password: 'password123' };
const SECTION_NAME = 'Workflow Test Section';
const SECTION_CODE = 'WFT-001';
const SCREENSHOT_DIR = __dirname + '/screenshots';
const EXERCISES = [
  {
    id: null, title: 'Sum 1 to N',
    description: 'Write a C++ program that reads an integer N and prints the sum of numbers from 1 to N.\n\nInput: A single integer N\nOutput: A single integer (the sum)',
    conceptName: 'Loops', timeLimitMinutes: 5,
    starterCode: '#include <iostream>\nusing namespace std;\n\nint main() {\n    // TODO: Implement your solution here\n    \n    return 0;\n}',
    referenceSolution: '#include <iostream>\nusing namespace std;\n\nint main() {\n    int n;\n    cin >> n;\n    int sum = 0;\n    for (int i = 1; i <= n; i++) sum += i;\n    cout << sum;\n    return 0;\n}',
    testCases: [
      { input: '10', expectedOutput: '55', isVisible: true, description: 'Sum of 1 to 10' },
      { input: '5', expectedOutput: '15', isVisible: true, description: 'Sum of 1 to 5' },
      { input: '100', expectedOutput: '5050', isVisible: false, description: 'Sum of 1 to 100' },
      { input: '1', expectedOutput: '1', isVisible: false, description: 'Edge case N=1' },
    ],
  },
  {
    id: null, title: 'Even or Odd',
    description: 'Write a C++ program that reads N integers and prints even or odd for each.\n\nInput: First line is N, followed by N integers\nOutput: N lines each even or odd',
    conceptName: 'Conditionals', timeLimitMinutes: 5,
    starterCode: '#include <iostream>\nusing namespace std;\n\nint main() {\n    // TODO\n    return 0;\n}',
    referenceSolution: '#include <iostream>\nusing namespace std;\n\nint main() {\n    int n, x;\n    cin >> n;\n    for (int i = 0; i < n; i++) {\n        cin >> x;\n        if (x % 2 == 0) cout << "even" << endl;\n        else cout << "odd" << endl;\n    }\n    return 0;\n}',
    testCases: [
      { input: '3\n1\n2\n3', expectedOutput: 'odd\neven\nodd', isVisible: true, description: 'Three numbers' },
      { input: '2\n4\n7', expectedOutput: 'even\nodd', isVisible: true, description: 'Two numbers' },
      { input: '1\n0', expectedOutput: 'even', isVisible: false, description: 'Zero is even' },
    ],
  },
  {
    id: null, title: 'Find Maximum',
    description: 'Write a C++ program that reads N integers and prints the maximum.\n\nInput: First line is N, followed by N integers\nOutput: A single integer (the maximum)',
    conceptName: 'Arrays', timeLimitMinutes: 5,
    starterCode: '#include <iostream>\nusing namespace std;\n\nint main() {\n    // TODO\n    return 0;\n}',
    referenceSolution: '#include <iostream>\n#include <algorithm>\nusing namespace std;\n\nint main() {\n    int n, arr[1000];\n    cin >> n;\n    for (int i = 0; i < n; i++) cin >> arr[i];\n    int mx = arr[0];\n    for (int i = 1; i < n; i++) mx = max(mx, arr[i]);\n    cout << mx;\n    return 0;\n}',
    testCases: [
      { input: '5\n3\n1\n4\n1\n5', expectedOutput: '5', isVisible: true, description: 'Five numbers' },
      { input: '3\n-1\n-5\n-3', expectedOutput: '-1', isVisible: true, description: 'All negative' },
      { input: '1\n42', expectedOutput: '42', isVisible: false, description: 'Single element' },
    ],
  },
];
module.exports = { BASE_URL, BACKEND_URL, DB_CONFIG, INSTRUCTOR, SECTION_NAME, SECTION_CODE, EXERCISES, SCREENSHOT_DIR };
