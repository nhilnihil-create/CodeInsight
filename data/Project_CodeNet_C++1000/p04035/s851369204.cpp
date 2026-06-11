#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())

using namespace std;
using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void dump(vector<T> v) { for (auto& x : v) cerr << x << " "; cerr << endl; }
template<class T> inline void dump(vector<pair<T, T>> v) { for (auto& p : v) cerr << p.first << " " << p.second << endl; }
template<class T> inline void dump(vector<vector<T>> vv) { for (auto& v : vv) {for (auto& x : v) cerr << x << " "; cerr << endl;} }

constexpr int INF = 1e9 + 5;
constexpr long long INFLL = 1LL << 62;
constexpr double eps = (1e-9);

using P = pair<int, int>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, l;
  cin >> n >> l;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  int t = -1;
  for (int i = 1; i < n; i++) {
    if (a[i-1] + a[i] >= l) {
      t = i;
      break;
    }
  }

  if (t == -1) {
    cout << "Impossible" << endl;
    return 0;
  }

  cout << "Possible" << endl;

  // t が最後に切断される
  for (int i = 1; i < t; i++) {
    cout << i << endl;
  }
  for (int i = n-1; i > t; i--) {
    cout << i << endl;
  }

  cout << t << endl;

  return 0;
}
