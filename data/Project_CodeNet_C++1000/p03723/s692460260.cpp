#include <iostream>
using namespace std;

int main(void) {
  int A, B, C;
  cin >> A >> B >> C;
  int answer = 0;
  while (true) {
    if (A % 2 || B % 2 || C % 2) break;
    int newA = B / 2 + C / 2;
    int newB = A / 2 + C / 2;
    int newC = A / 2 + B / 2;
    if (A == newA && B == newB && C == newC) {
      answer = -1;
      break;
    }
    A = newA;
    B = newB;
    C = newC;
    ++answer;
  }
  cout << answer << endl;
  return 0;
}