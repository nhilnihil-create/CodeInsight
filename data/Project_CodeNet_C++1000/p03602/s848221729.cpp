#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;
vector<vector<ll>> A;

ll solve() {
  ll res = 0;
  for (ll i = 0; i < N; ++i)
    for (ll j = i + 1; j < N; ++j) {
      bool needed = true;
      for (ll k = 0; k < N; ++k) {
        if (k == i || k == j) continue;
        if (A[i][j] > A[i][k] + A[k][j]) return -1;
        if (A[i][j] == A[i][k] + A[k][j]) {
          needed = false;
          break;
        }
      }
      if (needed) res += A[i][j];
    }
  return res;
}
int main() {
  cin >> N;
  A.resize(N);
  for (auto &a : A) a.resize(N);
  for (ll i = 0; i < N; ++i)
    for (ll j = 0; j < N; ++j) cin >> A[i][j];
  cout << solve() << endl;
  return 0;
}
