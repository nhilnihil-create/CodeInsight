#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  int ans = max(A*B, C*D);
  cout << ans << endl;
  return 0;
}