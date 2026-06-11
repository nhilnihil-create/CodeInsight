#include <bits/stdc++.h>
#define rep2(i, n, m) for (int i = m; i < (int)(n); i++)
#define rep(i, n) rep2(i, n, 0)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
using ll = long long;  //
template <typename T>
T sq(T x) {
  return x * x;
}
signed main() {
  int N;
  cin >> N;
  vector<ll> T(N);
  vector<ll> A(N);
  rep(i, N) { cin >> T.at(i) >> A.at(i); }
  ll taka = T.at(0);
  ll aoi = A.at(0);
  rep(i, N) {
    ll tmp_taka = taka / T.at(i);
    ll tmp_aoi = aoi / A.at(i);
    if (taka % T.at(i) != 0) {
      tmp_taka++;
    }
    if (aoi % A.at(i) != 0) {
      tmp_aoi++;
    }
    ll tmp = max(tmp_taka, tmp_aoi);
    taka = tmp * T.at(i);
    aoi = tmp * A.at(i);
  }
  cout << taka + aoi << endl;
  return 0;
}

