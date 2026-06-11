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

template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n = 0): n(n), d(n + 1, 0) {}
  void add(int i, T x = 1) {
    for (; i <= n; i += i & -i) {
      d[i] += x;
    }
  }
  T sum(int i) {
    T x = 0;
    for (; i; i -= i & -i) {
      x += d[i];
    }
    return x;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(25);

  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<pair<ll, ll>> p(n + 1, {0, 0});
  rep(i, n) p[i + 1].first = p[i].first + a[i] - k;
  rep(i, n + 1) p[i].second = i + 1;
  sort(p.begin(), p.end());
  BIT<ll> bit(n + 10);
  ll ans = 0;
  rep(i, n + 1) {
    ans += bit.sum(p[i].second);
    bit.add(p[i].second);
  }
  cout << ans << '\n';

  

  




  
  return 0;
}