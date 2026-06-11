#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
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

constexpr int INF = 1e9+5;
constexpr long long INFLL = 1LL<<62;
constexpr double eps = (1e-9);

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  auto b = a;
  sort(ALL(b));

  map<int, int> even, odd;
  rep(i, n) {
    if (i % 2 == 0) even[b[i]]++;
    else odd[b[i]]++;
  }

  int num = 0;

  rep(i, n) {
    if (i % 2 == 0 && even[a[i]] >> 0) {
      even[a[i]]--;
    } else if (i % 2 ==1 && odd[a[i]] > 0) {
      odd[a[i]]--;
    } else {
      num++;
    }
  }

  int ans = num / 2;

  cout << ans << endl;

  return 0;
}
