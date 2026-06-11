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
  ll l, t;
  cin >> n >> l >> t;
  ll x[n];
  int w[n];
  REP(i, n) {
    cin >> x[i] >> w[i];
    w[i]--;
  }
  vector<ll> vec;
  REP(i, n) {
    if (w[0] != w[i]) {
      vec.push_back(x[i]);
    }
  }
  ll cnt = 0;
  REP(i, vec.size()) {
    if (w[0] == 0) {
      cnt += (2 * t) / l;
      cnt += ((2 * t) % l >= (vec[i] - x[0]));
    } else {
      cnt -= (2 * t) / l;
      cnt -= ((2 * t) % l >= (l - vec[i] + x[0]));
    }
  }
  cnt = ((cnt % n) + n) % n;
  vector<P> ans;
  REP(i, n) {
    ll val = (x[i] + (w[i] == 0 ? t : -t) % l + l) % l;
    ans.push_back(P(-1, val));
  }
  sort(ALL(ans));
  int pos = (w[0] == 0 ? -1 : n);
  REP(i, n) {
    if (w[0] == 0 && ans[i].second == (x[0] + t) % l) {
      pos = max(pos, i);
    } else if (w[0] == 1 && ans[i].second == (x[0] + (-t % l) + l) % l) {
      pos = min(pos, i);
    }
  }
  for (int i = pos, j = 0; i >= 0; --i, ++j) {
    ans[i].first = (cnt - j + n) % n;
  }
  for (int i = pos, j = 0; i < n; ++i, ++j) {
    ans[i].first = (cnt + j) % n;
  }
  sort(ALL(ans));
  REP(i, n) cout << ans[i].second << endl;
  return 0;
};
