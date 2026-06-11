#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  int ans;
  if (B <= C || D <= A) ans = 0;
  else ans = min(B, D) - max(A, C);
  cout << ans << endl;
}
