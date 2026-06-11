#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, C, K;
  cin >> N >> C >> K;
  vector<int> T(N);
  for (int i = 0; i < N; i++) cin >> T.at(i);
  sort(T.begin(), T.end());
  int D = -1, P = 0, ans = 0;
  for (int i = 0; i < N; i++) {
    P++;
    if (T.at(i) > D || P > C) {
      ans++;
      D = T.at(i) + K;
      P = 1;
    }
  }
  cout << ans << endl;
}