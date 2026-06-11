#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<int> cnt(N, 0);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    cnt[a]++, cnt[b]++;
  }
  for (int i = 0; i < N; i++) {
    if (cnt[i] % 2 == 1) {
      cout << "NO" << '\n';
      return 0;
    }
  }
  cout << "YES" << '\n';
  return 0;
}
