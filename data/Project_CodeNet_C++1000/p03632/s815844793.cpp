#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  int Start = max(A, C);
  int End = min(B, D);
  if (Start >= End) cout << "0" << endl;
  else cout << End-Start << endl;
  return 0;
  
}


