#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int A, B, C, D;
  cin >> A >> B >> C >> D;

  cout << max(0, min(B, D) - max(A, C)) << endl;
  return 0;
}
