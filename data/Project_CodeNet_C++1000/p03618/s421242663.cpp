#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string  A; cin >> A;
  int N = A.size();
  vector<vector<int>> cnt(N, vector<int>(26, 0));

  cnt[0][A[0] - 'a'] = 1;
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < 26; j++) {

      cnt[i][j] = cnt[i - 1][j];

      if (A[i] - 'a' == j) {
        cnt[i][j]++;
      }
    }
  }

  ll ans = 1;
  for (int i = 0; i < N; i++) {
    int j = A[i] - 'a';
    ans += (N - i - 1) - (cnt[N - 1][j] - cnt[i][j]);
  }
  cout << ans << '\n';
  return 0;
}