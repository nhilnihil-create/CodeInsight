#include <cmath>
#include <cstdio>
#include <limits>
#include <tuple>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <string>
#include <array>
#include <iomanip>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rrep(i, n) for (int i = n-1; i >= 0; --i)
#define REP(i, s, n) for (int i = s; i< (int)(n); ++i)
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;
ll inf = ll(1e9);
using ll1d = vector<ll>;
using ll2d = vector<ll1d>;
using ll3d = vector<ll2d>;

bool judge(vector<ll> h, const ll &k, const ll &a, const ll &b) {
  ll cnt = 0;
  rep(i, h.size()) {
    h[i] -= k * b;
    if (h[i] > 0)
      cnt += (h[i] +a - b -1)/ (a - b);
  }
  return k >= cnt;
}

void solve(istream &ccin = cin, ostream &ccout = cout) {
  ll n, a, b;
  ccin >> n >> a >> b;

  vector<ll> h(n);
  rep(i, n) ccin >> h[i];

  ll lower = -1;
  ll higher = inf;
  while (higher - lower > 1) {
    ll mid = (higher + lower) / 2;
    if (judge(h, mid, a, b)) {
      higher = mid;
    } else {
      lower = mid;
    }
  }

  ccout << higher << endl;
}

int main() {
  ios::sync_with_stdio(false);
  solve();
  return 0;
}