#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const ll MOD = 1000000007;
const ll INF = 1000000000;
const ll LINF = 1ll<<50;
template<typename T>
void printv(const vector<T>& s) {
  for(ll i=0;i<(ll)(s.size());++i) {
    cout << s[i];
    if(i == (ll)(s.size())-1) cout << endl;
    else cout << " ";
  }
}
signed main() {
  cin.tie(0);
  cout << fixed << setprecision(10);
  ll n, m; cin >> n >> m;
  vector<vector<ll>> g(n);
  for(ll i=0;i<m;++i) {
    ll a, b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  ll q; cin >> q;
  vector<ll> v(q), d(q), c(q);
  for(ll i=0;i<q;++i) {
    cin >> v[i] >> d[i] >> c[i];
    v[i]--;
  }
  reverse(v.begin(), v.end());
  reverse(d.begin(), d.end());
  reverse(c.begin(), c.end());
  vector<vector<ll>> dp(n, vector<ll>(11, INF));
  for(ll i=0;i<q;++i) {
    queue<P> que;
    vector<bool> sel(n);
    que.push({v[i], d[i]});
    sel[v[i]] = true;
    for(ll j=0;j<=d[i];++j) {
      dp[v[i]][j] = min(dp[v[i]][j], i);
    }
    while(!que.empty()) {
      ll nowv = que.front().first, nowd = que.front().second; que.pop();
      for(ll j=0;j<(ll)(g[nowv].size());++j) {
        ll nextv = g[nowv][j];
        if(!sel[nextv]) {
          sel[nextv] = true;
          if(nowd == 1) {
            dp[nextv][0] = min(dp[nextv][0], i);
            continue;
          }
          if(dp[nextv][nowd-1] < i) continue;
          for(ll k=0;k<=nowd-1;++k) {
            dp[nextv][k] = min(dp[nextv][k], i);
          }
          que.push({nextv, nowd-1});
        }
      }
    }
  }
  for(ll i=0;i<n;++i) {
    if(dp[i][0] == INF) {
      cout << 0 << endl;
    } else {
      cout << c[dp[i][0]] << endl;
    }
  }
}
