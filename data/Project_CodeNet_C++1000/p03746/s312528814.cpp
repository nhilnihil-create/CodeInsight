#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(ll i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

vector<vl> g, ans(2);
ll n, m;
vb seen;

void f(ll i, ll t) {
  for(auto v : g[i]) {
    if(seen[v]) continue;
    seen[v] = true;
    ans[t].push_back(v + 1);
    f(v, t);
    break;
  }
}

int main() {
  cin >> n >> m;
  g.resize(n);
  ll s1, s2;
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
    if(i == 0) {
      s1 = a;
      s2 = b;
    }
  }
  seen.resize(n, false);
  seen[s1] = true;
  seen[s2] = true;
  ans[0].push_back(s1 + 1);
  ans[1].push_back(s2 + 1);
  f(s1, 0);
  f(s2, 1);
  reverse(all(ans[0]));
  cout << ans[0].size() + ans[1].size() << '\n';
  for(auto v : ans[0]) cout << v << ' ';
  for(auto v : ans[1]) cout << v << ' ';
  cout << endl;
}