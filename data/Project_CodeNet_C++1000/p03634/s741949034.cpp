#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
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

int main() {
  ll n;
  cin >> n;
  vector<vector<P>> g(n);
  rep(i, n - 1) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }
  ll m, k;
  cin >> m >> k;
  k--;
  vl d(n, -1);
  d[k] = 0;
  queue<int> q;
  q.push(k);
  while(!q.empty()) {
    int i = q.front();
    q.pop();
    for(auto v : g[i]) {
      ll ni = v.first;
      if(d[ni] != -1) continue;
      ll c = v.second;
      d[ni] = d[i] + c;
      q.push(ni);
    }
  }
  rep(_, m) {
    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    cout << d[x] + d[y] << endl;
  }
}