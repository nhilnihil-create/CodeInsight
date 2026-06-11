#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, m, n) for (int i = m; i < n; ++i)
const int MOD = 1000000007;

ll solve() {
  int N; cin >> N;
  vector<int> T(N), A(N);
  rep(i, 0, N) cin >> T[i];
  rep(i, 0, N) cin >> A[i];
  if(N == 1) return T[0] == A[0];
  if(T.back() != A.front()) return 0;
  rep(i, 1, N) if(T[i-1] != T[i] && T[i] > A[i]) return 0;
  rep(i, 0, N-1) if(A[i] != A[i+1] && A[i] > T[i]) return 0;
  ll ans = 1;
  rep(i, 0, N) {
    if(T[i-1] != T[i]) continue;
    if(A[i] != A[i+1]) continue;
    ans *= min(T[i], A[i]);
    ans %= MOD;
  }
  return ans;
}

int main() {
  cout << solve() << endl;
  return 0;
}
