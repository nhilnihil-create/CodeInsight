#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, K;
  cin >> N >> K;
  vector<int> l(N);
  for (int i = 0; i < N; ++i) {
    cin >> l.at(i);
  }

  sort(l.rbegin(), l.rend());
  int ans = 0;
  for (int i = 0; i < K; ++i) {
    ans += l.at(i);
  }

  cout << ans << endl;
  return 0;
}
