#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define MOD 1000000007
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REP1(i, N) for (int i = 1; i <= N; ++i)
#define RREP(i, N) for (int i = N - 1; i >= 0; --i)
#define ALL(a) a.begin(), a.end()

int main() {
  int n;
  ll W;
  cin >> n >> W;
  ll w[n], v[n];
  REP(i, n) cin >> w[i] >> v[i];
  vector<ll> vc[4];
  REP(i, n) vc[w[i] - w[0]].push_back(v[i]);
  REP(i, 4) {
    sort(ALL(vc[i]));
    reverse(ALL(vc[i]));
  }
  vector<ll> sum[4];
  REP(i, 4) {
    sum[i].push_back(0);
    ll tmp = 0;
    REP(j, vc[i].size()) {
      sum[i].push_back(tmp + vc[i][j]);
      tmp += vc[i][j];
    }
  }
  ll ans = 0;
  REP(i, sum[0].size()) {
    REP(j, sum[1].size()) {
      REP(k, sum[2].size()) {
        REP(l, sum[3].size()) {
          ll tmp = w[0] * i + (w[0] + 1) * j + (w[0] + 2) * k + (w[0] + 3) * l;
          if (tmp <= W) {
            ans = max(ans, sum[0][i] + sum[1][j] + sum[2][k] + sum[3][l]);
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}