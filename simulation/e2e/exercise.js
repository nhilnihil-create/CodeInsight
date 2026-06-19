const EXERCISE = {
  id: null, sectionId: null,
  title: 'Sum 1..N',
  description: 'Write a program that reads an integer N and prints the sum of numbers from 1 to N.',
  starterCode: `#include <iostream>
using namespace std;

int main() {
    // TODO: Implement your solution here

    return 0;
}`,
  referenceSolution: `#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    cout << sum;
    return 0;
}`,
  testCases: [
    { input: '10', expectedOutput: '55', isVisible: true },
    { input: '5', expectedOutput: '15', isVisible: true },
    { input: '100', expectedOutput: '5050', isVisible: false },
    { input: '1', expectedOutput: '1', isVisible: false },
  ],
};
module.exports = { EXERCISE };
