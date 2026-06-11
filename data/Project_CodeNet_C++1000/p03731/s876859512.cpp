#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, M;
  cin >> N >> M;
  vector<long> T(N);
  for (int i = 0; i < N; i++) cin >> T.at(i);
  long ans = 0;
  for (int i = 0; i + 1 < N; i++) {
    long tmp = T.at(i + 1) - T.at(i);
    ans += min(tmp, M);
  }
  cout << ans + M << "\n";
}