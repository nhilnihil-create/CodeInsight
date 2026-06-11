#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, C, K;
  cin >> N >> C >> K;
  vector<int> T(N);
  for (int i = 0; i < N; i++) cin >> T.at(i);

  sort(T.begin(), T.end());

  int lim = T.at(0) + K, c = 0, ans = 1;
  for (int i = 0; i < N; i++) {
    if (T.at(i) <= lim && c < C) c++;
    else lim = T.at(i) + K, c = 1, ans++;
  }
  cout << ans << "\n";
}