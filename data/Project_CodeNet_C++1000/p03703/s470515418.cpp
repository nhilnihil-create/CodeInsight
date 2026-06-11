#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

class BIT {
  vector<int> dat;
public:
  BIT (int n) {
    dat.resize(n+1, 0);
  }
  void add(int i, int n) {
    while (i < dat.size()) {
      dat[i] += n;
      i += i & -i;
    }
  }
  int sum(int i) {
    int res = 0;
    while (i > 0) {
      res += dat[i];
      i -= i & -i;
    }
    return res;
  }
  void clear() {
    for (int i = 1; i < dat.size(); i++)
      dat[i] = 0;
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  rep(i, n) a[i] -= k;
  vector<ll> sum(n+1);
  rep(i, n) sum[i+1] = sum[i]+a[i];
  map<ll, int> mp;
  rep(i, n+1) mp[sum[i]];
  int idx = 1;
  for (auto& e : mp) {
    e.second = idx;
    idx++;
  }
  rep(i, n+1) sum[i] = mp[sum[i]];
  BIT bit(n+1);
  ll ans = 0;
  rep(i, n+1) {
    ans += bit.sum(sum[i]);
    bit.add(sum[i], 1);
  }
  cout << ans << endl;
  return 0;
}