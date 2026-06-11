#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(25);

  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> ans(n, 0);
  ll res = 0;
  vector<ll> idx, v;
  rep(i, n) {
    if (a[i] > res) {
      idx.push_back(i);
      v.push_back(res);
      res = a[i];
    }
  }
  reverse(idx.begin(), idx.end());
  reverse(v.begin(), v.end());
  ll m = idx.size();
  priority_queue<ll> pq;
  rep(i, n) pq.push(a[i]);
  ll cnt = 0;
  rep(i, m) {
    if (i) ans[idx[i]] += cnt * (v[i - 1] - v[i]);
    while (!pq.empty() && pq.top() != v[i]) {
      ll maxa = pq.top();
      pq.pop();
      ans[idx[i]] += maxa - v[i];
      cnt++;
    }
  }
  rep(i, n) cout << ans[i] << '\n';




  
  return 0;
}