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

vector<vl> g;

ll dfs(ll i) {
  ll res = 0;
  priority_queue<ll> q;
  for(auto v : g[i]) q.push(dfs(v));
  for(ll j = 0; !q.empty(); j++) {
    ll now = q.top() + j;
    res = max(res, now);
    q.pop();
  }
  return res + 1;
}

int main() {
  ll n;
  cin >> n;
  g.resize(n);
  rep(i, n - 1) {
    ll a;
    cin >> a;
    a--;
    g[a].push_back(i + 1);
  }
  cout << dfs(0) - 1 << endl;
}