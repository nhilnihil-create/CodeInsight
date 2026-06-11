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
  ll Q, H, S, D, N;
  cin >> Q >> H >> S >> D >> N;
  ll ans = 1e17;
  ans = min(ans, N * 4 * Q);
  ans = min(ans, N * 2 * H);
  ans = min(ans, N * S);
  if (2 <= N) {
    ll d = N / 2;
    N %= 2;
    ans = min(ans, d * D + N * 4 * Q);
    ans = min(ans, d * D + N * 2 * H);
    ans = min(ans, d * D + N * S);
  }
  cout << ans << endl;
}