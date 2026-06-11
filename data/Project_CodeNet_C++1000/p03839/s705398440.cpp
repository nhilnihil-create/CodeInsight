#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "dump.hpp"
#else
#define dump(...)
#define dumpv(...)
#endif

#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int MOD = 1e9 + 7;
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;

void solve() {
  int n, k;
  cin >> n >> k;
  vi a(n);
  rep(i, n) cin >> a[i];
  vector<ll> s1(n + 1), s2(n + 1);
  rep(i, n) s1[i + 1] = s1[i] + a[i];
  rep(i, n) s2[i + 1] = s2[i] + max(0, a[i]);
  dump(a);
  dump(s1);
  dump(s2);

  int left = 0;
  int right = 0;
  ll val = 0; // 区間[left, right)の合計値
  ll ans = -INF;
  for (int i = 0; i < n - k + 1; i++) {
    left = i;
    right = i + k;
    val = max(0ll, s1[right] - s1[left]);
    dump("1", left, right, val);
    val += (s2[i] - s2[0]);
    val += (s2[n] - s2[right]);
    dump("2", left, right, val);
    ans = max(ans, val);
  }
  cout << max(0ll, ans) << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  // freopen("temp.1", "r", stdin);
  solve();
  return 0;
}