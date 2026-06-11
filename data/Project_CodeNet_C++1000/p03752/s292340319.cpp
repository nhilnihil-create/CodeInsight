#define _DEBUG 1
#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#ifdef _DEBUG
#define dump(x) cerr << #x << "=" << x << endl
#define dump2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define dump3(x, y, z)                                                     \
  cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z \
       << endl
#define check(s) cerr << s << endl
#else
#define dump(x)
#define dump2(x, y)
#define dump3(x, y, z)
#define check(s)
#endif

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());

const ll LINF = 2e18;
const int INF = 1e9;

ll N, K;
vector<ll> a;

void solve() {
  ll cost = LINF;

  vector<ll> mx(N);
  mx.at(0) = a.at(0);
  FOR(i, 1, N) { mx.at(i) = max(mx.at(i - 1), a.at(i)); }

  rep(bit, 1 << N) {
    vector<ll> idxs;
    rep(i, N) {
      if (bit & (1 << i)) idxs.push_back(i);
    }
    if (idxs.size() != K) continue;

    ll maxh = 0, sum = 0;
    rep(i, K) {
      ll idx = idxs.at(i);
      maxh = max(maxh, mx[idx]);
      if (a.at(idx) <= maxh) {
        sum += maxh - a.at(idx);
        maxh++;
      } else {
        maxh = a.at(idx);
      }
    }
    cost = min(cost, sum);
  }

  cout << cost << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);

  cin >> N >> K;
  a.resize(N);
  rep(i, N) { cin >> a.at(i); }
  solve();

  return 0;
}
