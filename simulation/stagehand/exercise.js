/**
 * simulation/stagehand/exercise.js
 *
 * Exercise definition for the comprehensive simulation.
 * All 10 personas will work on this same exercise.
 * Includes starter code, test cases, reference solution, and concept tags.
 */

const EXERCISE = {
  id: 99999,  // Will be created dynamically
  title: 'Sum of Natural Numbers',
  description: 'Write a C++ program that calculates the sum of first N natural numbers using a loop.',
  concept: 'Loops',
  secondaryConcepts: ['Variables', 'Arithmetic'],
  tags: ['for-loop', 'accumulation', 'basics'],

  starterCode: `#include <iostream>
using namespace std;
int main() {
    // TODO: Implement your solution here
    
    return 0;
}`,

  referenceSolution: `#include <iostream>
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

  testCases: [
    {
      id: 1,
      input: '',
      expected: '55',
      visible: true,
      description: 'Sum of first 10 natural numbers',
    },
    {
      id: 2,
      input: '',
      expected: '15',
      visible: false,
      description: 'Hidden test: Sum of first 5 natural numbers',
    },
    {
      id: 3,
      input: '',
      expected: '5050',
      visible: false,
      description: 'Hidden test: Sum of first 100 natural numbers',
    },
  ],

  // CDS threshold expectations
  cdsThresholds: {
    low: 0.31,
    moderate: 0.50,
    high: 0.50,
  },

  // Micro-concept definitions for this exercise
  microConcepts: [
    {
      id: 'loop-initialization',
      name: 'Loop Initialization',
      description: 'Correctly initializing loop counter variable',
      weight: 0.3,
    },
    {
      id: 'loop-condition',
      name: 'Loop Condition',
      description: 'Correct loop termination condition',
      weight: 0.3,
    },
    {
      id: 'accumulator-pattern',
      name: 'Accumulator Pattern',
      description: 'Correctly accumulating sum in a variable',
      weight: 0.4,
    },
  ],

  // AST verification rules
  astRules: [
    {
      id: 'has-loop',
      name: 'Must contain a loop',
      type: 'required',
      pattern: 'for_statement|while_statement|do_statement',
    },
    {
      id: 'has-variable',
      name: 'Must declare variables',
      type: 'required',
      pattern: 'declaration',
    },
    {
      id: 'has-output',
      name: 'Must output result',
      type: 'required',
      pattern: 'expression_statement',
    },
  ],
};

module.exports = { EXERCISE };
