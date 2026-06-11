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
constexpr long long INFLL = 1LL<<60;
constexpr double eps = (1e-9);

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}

ll calc_cost(const vector<ll>& a, const vector<int>& t) {
  ll ans = 0;
  ll m = 0;
  auto it = t.begin();
  for (int i = 0; i < a.size(); i++) {
    if (i == *it) {
      if (a[i] <= m) {
        ans += (m+1) - a[i];
        m = m + 1;
      } else {
        m = a[i];
      }
      it++;
    } else {
      m = max(m, a[i]);
    }
  }
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll ans = INFLL;

  foreach_comb(n, k, [&](int* indexes) {
    vector<int> t;
    for (int i = 0; i < k; i++) t.push_back(indexes[i]);
    sort(t.begin(), t.end());
    chmin(ans, calc_cost(a, t));
  });

  cout << ans << endl;

  return 0;
}
