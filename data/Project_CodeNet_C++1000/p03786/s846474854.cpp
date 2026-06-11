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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(ALL(a));
  vector<ll> cs(n, 0);   // i番目以下の生き物すべてが合体したときの大きさ
  cs[0] = a[0];
  for (int i = 1; i < n; i++) {
    cs[i] = cs[i-1] + a[i];
  }
  int ans = 1;  // 最大の生き物はOK

  for (int i = n-2; i >= 0; i--) {
    if (cs[i] * 2 >= a[i+1]) ans++;  // 自分以下の生き物を全部吸収したら次の生き物を吸収できる？
    else break;
  }

  cout << ans << endl;

  return 0;
}
