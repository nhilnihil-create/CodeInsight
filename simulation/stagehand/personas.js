/**
 * simulation/stagehand/personas.js
 *
 * 10 diverse student personas representing different learning profiles
 * and academic integrity risk categories. Each persona has:
 *   - Login credentials
 *   - Behavioral characteristics (typing speed, tab switches, paste frequency)
 *   - Submission strategy (how they approach the exercise)
 *   - Expected integrity flags (what the system should detect)
 *   - Expected CDS profile (expected difficulty classification)
 */

const PERSONAS = [
  // ── 1. High Performer ───────────────────────────────────────────────────
  {
    id: 1,
    name: 'Maria',
    email: 'maria@student.psu.edu',
    password: 'password123',
    tier: 'high',
    description: 'Strong student who solves correctly on first attempt',
    behavior: {
      typingSpeed: 80,        // ms per keystroke (fast)
      tabSwitches: 0,         // no tab switching
      pasteEvents: 0,         // no pasting
      idleTime: 0,            // no idle time
      doubleClicks: 0,
    },
    submissions: [
      {
        attempt: 1,
        code: `#include <iostream>
using namespace std;
int main() {
    int n = 10;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    cout << sum;
    return 0;
}`,
        isCorrect: true,
        timeSpent: 120,
      },
    ],
    expectedFlags: [],
    expectedCDS: 'Low',
    expectedClassification: 'Low',
  },

  // ── 2. Average Student ──────────────────────────────────────────────────
  {
    id: 2,
    name: 'Alex',
    email: 'alex@student.psu.edu',
    password: 'password123',
    tier: 'medium',
    description: 'Takes a few attempts, shows learning progression',
    behavior: {
      typingSpeed: 120,
      tabSwitches: 2,
      pasteEvents: 0,
      idleTime: 5,
      doubleClicks: 1,
    },
    submissions: [
      {
        attempt: 1,
        code: `#include <iostream>
using namespace std;
int main() {
    int n = 10;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum = sum + 1;
    }
    cout << sum;
    return 0;
}`,
        isCorrect: false,
        timeSpent: 180,
      },
      {
        attempt: 2,
        code: `#include <iostream>
using namespace std;
int main() {
    int n = 10;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    cout << sum;
    return 0;
}`,
        isCorrect: true,
        timeSpent: 150,
      },
    ],
    expectedFlags: [],
    expectedCDS: 'Low',
    expectedClassification: 'Low',
  },

  // ── 3. Struggling Student ───────────────────────────────────────────────
  {
    id: 3,
    name: 'Jordan',
    email: 'jordan@student.psu.edu',
    password: 'password123',
    tier: 'struggling',
    description: 'Multiple failures, shows retry storm pattern',
    behavior: {
      typingSpeed: 150,
      tabSwitches: 5,
      pasteEvents: 1,
      idleTime: 30,
      doubleClicks: 3,
    },
    submissions: [
      {
        attempt: 1,
        code: `#include <iostream>
using namespace std;
int main() {
    cout << 55;
    return 0;
}`,
        isCorrect: false,
        timeSpent: 60,
      },
      {
        attempt: 2,
        code: `#include <iostream>
using namespace std;
int main() {
    int n = 10;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum + i;
    }
    cout << sum;
    return 0;
}`,
        isCorrect: false,
        timeSpent: 90,
      },
      {
        attempt: 3,
        code: `#include <iostream>
using namespace std;
int main() {
    int n = 10;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    cout << sum;
    return 0;
}`,
        isCorrect: true,
        timeSpent: 200,
      },
    ],
    expectedFlags: [],
    expectedCDS: 'Low',
    expectedClassification: 'Low',
  },

  // ── 4. Hardcoder (copies solution) ──────────────────────────────────────
  {
    id: 4,
    name: 'Chloe',
    email: 'chloe@student.psu.edu',
    password: 'password123',
    tier: 'high',
    description: 'Immediately submits hardcoded answer - should trigger HARDCODED_SOLUTION flag',
    behavior: {
      typingSpeed: 5,
      tabSwitches: 10,
      pasteEvents: 5,
      idleTime: 0,
      doubleClicks: 0,
    },
    submissions: [
      {
        attempt: 1,
        code: `#include <iostream>
using namespace std;
int main() {
    cout << 55;
    return 0;
}`,
        isCorrect: true,
        timeSpent: 15,
      },
    ],
    expectedFlags: ['HARDCODED_SOLUTION'],
    expectedCDS: 'Low',
    expectedClassification: 'Low',
  },

  // ── 5. Blank Template Submitter ─────────────────────────────────────────
  {
    id: 5,
    name: 'Derek',
    email: 'derek@student.psu.edu',
    password: 'password123',
    tier: 'struggling',
    description: 'Submits starter code unchanged - should trigger BLANK_TEMPLATE flag',
    behavior: {
      typingSpeed: 100,
      tabSwitches: 3,
      pasteEvents: 0,
      idleTime: 45,
      doubleClicks: 0,
    },
    submissions: [
      {
        attempt: 1,
        code: `#include <iostream>
using namespace std;
int main() {
    // TODO: Implement your solution here
    
    return 0;
}`,
        isCorrect: false,
        timeSpent: 30,
      },
    ],
    expectedFlags: ['BLANK_TEMPLATE'],
    expectedCDS: 'Low',
    expectedClassification: 'Low',
  },

  // ── 6. Retry Storm Student ──────────────────────────────────────────────
  {
    id: 6,
    name: 'Emma',
    email: 'emma@student.psu.edu',
    password: 'password123',
    tier: 'struggling',
    description: '12 rapid failures triggering RETRY_STORM detection',
    behavior: {
      typingSpeed: 200,
      tabSwitches: 15,
      pasteEvents: 3,
      idleTime: 2,
      doubleClicks: 8,
    },
    submissions: Array.from({ length: 12 }, (_, i) => ({
      attempt: i + 1,
      code: `#include <iostream>
using namespace std;
int main() {
    int sum = ${i};
    cout << sum;
    return 0;
}`,
      isCorrect: false,
      timeSpent: 30 + Math.floor(Math.random() * 20),
    })),
    expectedFlags: ['RETRY_STORM'],
    expectedCDS: 'High',
    expectedClassification: 'High',
  },

  // ── 7. Behavioral Anomaly (tab switcher + paster) ───────────────────────
  {
    id: 7,
    name: 'Fiona',
    email: 'fiona@student.psu.edu',
    password: 'password123',
    tier: 'medium',
    description: 'Excessive tab switching and paste events - behavioral anomaly',
    behavior: {
      typingSpeed: 100,
      tabSwitches: 25,
      pasteEvents: 10,
      idleTime: 5,
      doubleClicks: 2,
    },
    submissions: [
      {
        attempt: 1,
        code: `#include <iostream>
using namespace std;
int main() {
    int n = 10;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    cout << sum;
    return 0;
}`,
        isCorrect: true,
        timeSpent: 180,
      },
    ],
    expectedFlags: ['PASSIVE_BEHAVIOR_LOG'],
    expectedCDS: 'Low',
    expectedClassification: 'Low',
  },

  // ── 8. Code Growth Anomaly ──────────────────────────────────────────────
  {
    id: 8,
    name: 'George',
    email: 'george@student.psu.edu',
    password: 'password123',
    tier: 'medium',
    description: 'Massive code growth between submissions (>30%) - CODE_GROWTH_ANOMALY',
    behavior: {
      typingSpeed: 130,
      tabSwitches: 4,
      pasteEvents: 2,
      idleTime: 10,
      doubleClicks: 1,
    },
    submissions: [
      {
        attempt: 1,
        code: `#include <iostream>
using namespace std;
int main() {
    cout << 10;
    return 0;
}`,
        isCorrect: false,
        timeSpent: 60,
      },
      {
        attempt: 2,
        code: `#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// This function calculates the sum of first n natural numbers
// using an optimized mathematical formula
long long calculateSum(long long n) {
    // Using the formula n*(n+1)/2 for O(1) computation
    // This avoids the O(n) loop approach
    return n * (n + 1) / 2;
}

// Alternative iterative approach for verification
long long calculateSumIterative(long long n) {
    long long sum = 0;
    for (long long i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

// Matrix-based approach for educational purposes
void printSumTable(int maxN) {
    cout << "N\\tSum" << endl;
    for (int i = 1; i <= maxN; i++) {
        cout << i << "\\t" << calculateSum(i) << endl;
    }
}

int main() {
    int n = 10;
    
    // Calculate using formula
    long long result1 = calculateSum(n);
    
    // Verify with iterative approach
    long long result2 = calculateSumIterative(n);
    
    // Cross-check
    if (result1 != result2) {
        cerr << "Error: Results don't match!" << endl;
        return 1;
    }
    
    // Output the result
    cout << result1;
    
    // Optional: print table for debugging
    // printSumTable(n);
    
    return 0;
}`,
        isCorrect: true,
        timeSpent: 120,
      },
    ],
    expectedFlags: ['CODE_GROWTH_ANOMALY'],
    expectedCDS: 'Low',
    expectedClassification: 'Low',
  },

  // ── 9. Learning Plateau (declining performance) ─────────────────────────
  {
    id: 9,
    name: 'Hannah',
    email: 'hannah@student.psu.edu',
    password: 'password123',
    tier: 'medium',
    description: 'Shows declining performance across exercises - LEARNING_PLATEAU',
    behavior: {
      typingSpeed: 140,
      tabSwitches: 8,
      pasteEvents: 2,
      idleTime: 20,
      doubleClicks: 2,
    },
    submissions: [
      {
        attempt: 1,
        code: `#include <iostream>
using namespace std;
int main() {
    int n = 10;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    cout << sum;
    return 0;
}`,
        isCorrect: false,
        timeSpent: 250,
      },
      {
        attempt: 2,
        code: `#include <iostream>
using namespace std;
int main() {
    int n = 10;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    cout << sum;
    return 0;
}`,
        isCorrect: true,
        timeSpent: 200,
      },
    ],
    expectedFlags: [],
    expectedCDS: 'Low',
    expectedClassification: 'Low',
  },

  // ── 10. Idle Student (long idle times) ──────────────────────────────────
  {
    id: 10,
    name: 'Ian',
    email: 'ian@student.psu.edu',
    password: 'password123',
    tier: 'struggling',
    description: 'Long idle periods, minimal code changes - passive behavior',
    behavior: {
      typingSpeed: 200,
      tabSwitches: 12,
      pasteEvents: 0,
      idleTime: 120,
      doubleClicks: 5,
    },
    submissions: [
      {
        attempt: 1,
        code: `#include <iostream>
using namespace std;
int main() {
    int n = 10;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    cout << sum;
    return 0;
}`,
        isCorrect: true,
        timeSpent: 600,
      },
    ],
    expectedFlags: ['PASSIVE_BEHAVIOR_LOG'],
    expectedCDS: 'Low',
    expectedClassification: 'Low',
  },
];

module.exports = { PERSONAS };
