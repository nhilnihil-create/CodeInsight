#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int main() {
  ll N, C, K;
  cin >> N >> C >> K;
  vector<ll> T(N);
  REP(i, N) cin >> T[i];
  ll ans = 0;
  ll num = 0;
  sort(T.begin(), T.end());
  ll intcnt = 0;
  ll time = T[0];
  REP(i, N) {
    if (K < T[i] - time) {
      ans++;
      num = 0;
      time = T[i];
      intcnt = i;
    }
    if (C <= num) {
      ans++;
      num = 0;
      intcnt = i;
      time = T[i];
    }
    num++;
  }
  if (0 < num) ans++;
  cout << ans << endl;
}