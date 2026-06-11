#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

ll N;
vector<ll> edges[200000];

ll depth(ll x) {
  vector<ll> v;
  for(auto nxt : edges[x]) {
    v.push_back(depth(nxt));
  }
  sort(begin(v), end(v), [](const auto &l, const auto &r) { return l > r;});
  ll res = 0;
  rep(i, v.size()) {
    res = max(res, v[i]+i+1);
  }
  // printf("depth[%d]=%d\n", x , res);
  return res;
}

signed main() {
  cin >> N;
  for (ll i=2; i<=N; i++) {
    ll x;
    cin >> x;
    edges[x].push_back(i);
    //printf("win:%d lose:%d\n", x, i);
  }
  ll ans = depth(1);
  cout << ans << endl;
  return 0;
}
