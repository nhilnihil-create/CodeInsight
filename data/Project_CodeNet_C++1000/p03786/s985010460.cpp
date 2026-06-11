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
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  sort(A.begin(), A.end(), greater<ll>());
  vector<ll> wa(N);
  wa[N - 1] = A[N - 1];
  for (int i = N - 2; i >= 0; i--) {
    wa[i] = wa[i + 1] + A[i];
  }
  int ans = 0;
  REP(i, N - 1) {
    ans = i + 1;
    if (A[i] > 2 * wa[i + 1]) break;
    if (i == N - 2) ans++;
  }

  cout << ans << endl;
}