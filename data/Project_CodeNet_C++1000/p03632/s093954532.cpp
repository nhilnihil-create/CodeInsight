#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  int from = max(A, C);
  int to = min(B, D);

  string ans = std::to_string(max(to - from, 0));
  cout << ans << endl;
}