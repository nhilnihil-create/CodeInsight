#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
#define all(obj) (obj).begin(), (obj).end()
static const int dx[4] = {0, 1, 0, -1};
static const int dy[4] = {1, 0, -1, 0};
static const char dir[4] = {'u', 'r', 'd', 'l'};
static const ll INF = 1ll << 60;
static const ll MOD = 1e9 + 7;

signed main() {
  int N;
  cin >> N;
  vector<ll> T(N), A(N);
  rep(i, N) { cin >> T[i]; }
  rep(i, N) { cin >> A[i]; }

  if (A[0] != T[N - 1]) {
    cout << 0 << endl;
    return 0;
  }

  ll ans = 1ll;
  for (int i = 1; i < N - 1; i++) {
    if (T[i] == T[i - 1] && A[i + 1] == A[i]) {
      ans *= min(T[i], A[i]);
      ans %= MOD;
    } else if (T[i] > T[i - 1] && A[i + 1] == A[i] && A[i] < T[i]) {
      ans = 0;
    } else if (T[i] == T[i - 1] && A[i + 1] > A[i] && A[i] > T[i]) {
      ans = 0;
    } else if (T[i] > T[i - 1] && A[i + 1] > A[i] && A[i] != T[i]) {
      ans = 0;
    }
  }
  cout << ans << endl;
  return 0;
}