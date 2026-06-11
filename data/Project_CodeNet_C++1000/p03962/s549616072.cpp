#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  
  if (A == B && B == C) {
    cout << 1 << endl;
  } else if (A == B && B != C || A == C && A != B || B == C && A != B) {
    cout << 2 << endl;
  } else {
    cout << 3 << endl;
  }
}