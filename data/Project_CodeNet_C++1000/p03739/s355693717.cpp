#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define FORV(i, v) for (auto i = v.begin(); i != v.end(); i++)
using namespace std;

using ll = long long;
using P = pair<int, int>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFLL = LLONG_MAX / 3;
const double eps = (1e-9);

ll calc(vector<ll>& a, int n, int flag) {
  ll ans = 0;
  ll sum = 0;
  rep(i, n) {
    if (i % 2 == flag) {
      if (sum + a[i] < 1) {
        // 足した結果を +1 以上にしたい
        ans += 1 - (sum + a[i]);
        sum = 1;
      } else {
        sum += a[i];
      }
    } else {
      // 足した結果を -1 以下にしたい
      if (sum + a[i] > -1) {
        ans += (sum + a[i]) + 1;
        sum = -1;
      } else {
        sum += a[i];
      }
    }
  }
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll ans = calc(a, n, 0);
  chmin(ans, calc(a, n, 1));

  cout << ans << endl;

  return 0;
}
