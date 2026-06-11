#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  int count = 0;
  cin >> A >> B >> C;

  while(A % 2 == 0 && B % 2 == 0 && C % 2 == 0) {
    int newA = B / 2 + C / 2;
    int newB = A / 2 + C / 2;
    int newC = A / 2 + B / 2;
    if (newA == A && newB == B && newC == C) {
      count = -1;
      break;
    }
    A = newA;
    B = newB;
    C = newC;
    count++;
  }

  cout << count << endl;
}