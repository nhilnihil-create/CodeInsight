#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll Q, H, S, D;
  long double N;
  cin >> Q >> H >> S >> D >> N;
  double cp_q, cp_h, cp_s, cp_d;
  cp_q = Q / 0.25;
  cp_h = H / 0.5;
  cp_s = S;
  cp_d = D / 2.0;
  map<double, pair<ll, double>> values;
  values.insert(make_pair(cp_q, make_pair(Q, 0.25)));
  values.insert(make_pair(cp_h, make_pair(H, 0.5)));
  values.insert(make_pair(cp_s, make_pair(S, 1.0)));
  values.insert(make_pair(cp_d, make_pair(D, 2.0)));

  ll ans = 0ll;
  for (auto const &v : values) {
    if (N < v.second.second) {
      continue;
    }
    ll buy_count = floor(N / v.second.second);
    ans += buy_count * v.second.first;
    N -= buy_count * v.second.second;
    if (N <= 0) {
      break;
    }
  }

  cout << ans << endl;

  return 0;
}
