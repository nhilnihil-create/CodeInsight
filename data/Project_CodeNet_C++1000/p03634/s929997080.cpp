#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n;
  cin >> n;
  vector <vector <pair <ll, ll>>> v(n, vector <pair <ll, ll>> ());
  rep(i, n-1) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    v.at(a).push_back(make_pair(b, c)); v.at(b).push_back(make_pair(a, c));
  }
  ll q, k;
  cin >> q >> k;
  k--;
  vector <ll> d(n, INF);
  queue <ll> s;
  d.at(k) = 0; s.push(k);
  while (s.size()) {
    ll p = s.front(); s.pop();
    rep(i, v.at(p).size()) {
      ll tmp = v.at(p).at(i).first, cost = v.at(p).at(i).second;
      if (d.at(tmp) == INF) {
        d.at(tmp) = d.at(p) + cost;
        s.push(tmp);
      }
    }
  }
  rep(i, q) {
    ll x, y;
    cin >> x >> y;
    x--; y--;
    cout << d.at(x) + d.at(y) << endl;
  }
}