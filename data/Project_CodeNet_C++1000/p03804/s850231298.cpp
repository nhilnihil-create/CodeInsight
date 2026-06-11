#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void dump(vector<T> v) { for (auto& x : v) cerr << x << " "; cerr << endl; }
template<class T> inline void dump(vector<pair<T, T>> v) { for (auto& p : v) cerr << p.first << " " << p.second << endl; }
template<class T> inline void dump(vector<vector<T>> vv) { for (auto& v : vv) {for (auto& x : v) cerr << x << " "; cerr << endl;} }

constexpr int INF = 1e9+5;
constexpr long long INFLL = 1LL<<60;
constexpr double eps = (1e-9);

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  rep(i, n) cin >> a[i];

  vector<string> b(m);
  rep(i, m) cin >> b[i];

  rep(i, n-m+1) {
    rep(j, n-m+1) {
      bool flag = true;
      rep(x, m) {
        rep(y, m) {
          if (a[i+x][j+y] != b[x][y]) flag = false;
        }
      }
      if (flag) {
        puts("Yes");
        return 0;
      }
    }
  }

  puts("No");

  return 0;
}
