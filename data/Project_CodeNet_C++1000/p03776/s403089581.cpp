#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  vector<ll> v(N);
  for (int i = 0; i < N; i++) cin >> v[i];
  sort(v.begin(), v.end(), greater<ll>());
  double ans = 0;
  for (int i = 0; i < A; i++) ans += v[i];
  cout << setprecision(30) << (double)ans / A << endl;

  ll comb[51][51] = {};
  for (int i = 1; i <= 50; i++) {
    comb[i][0] = comb[i][i] = 1;
    for (int j = 1; j <= i - 1; j++) {
      comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
    }
  }

  int cnt = 0, x = -1;
  for (int i = 0; i < N; i++) {
    if (v[i] == v[A - 1]) {
      cnt++;
      if (x == -1) x = i;
    }
  }
  ll ans2 = comb[cnt][A - x];
  if (v[0] == v[A - 1]) {
    for (int i = A; i < B; i++) {
      if (v[i] != v[A - 1]) continue;
      ans2 += comb[cnt][i - x + 1];
    }
  }
  cout << ans2 << endl;
}