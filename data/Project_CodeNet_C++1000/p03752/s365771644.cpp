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
  int N, K;
  cin >> N >> K;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  ll mx = -1;
  for (int i = 0; i < 1 << N; i++) {
    ll ibitcount = bitset<32>(i).count();
    if (ibitcount < K) continue;
    ll cost = 0;
    ll now = -1;
    ll now_max = 0;
    vector<ll> tmp(N);
    REP(j, N) {
      
      if ((i & 1 << j) == false) {
        now_max = max(now_max, A[j]);
        continue;
      }
      cost += now_max < A[j] ? 0 : now_max - A[j] + 1;
      tmp[j] = max(A[j],now_max + 1);
      REP(k, j+1) {
        now_max = max(now_max, A[j]);
        now_max = max(now_max, tmp[j]);
      }
    }
    if (mx == -1) {
      mx = cost;
    } else {
      mx = min(cost, mx);
    }
  }
  cout << mx << endl;
}