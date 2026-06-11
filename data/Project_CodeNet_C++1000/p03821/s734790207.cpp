#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
int main() {
  int N;
  cin >> N;
  vector<ll> A(N), B(N);
  REP(i, N) cin >> A[i] >> B[i];
  ll ans = 0;
  for (ll i = N - 1; i >= 0; i--) {
    if (0 == (A[i] + ans) % B[i]) continue;
    ans += B[i] - (A[i] + ans) % B[i];
  }
  cout << ans << endl;
}