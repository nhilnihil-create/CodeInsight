#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

void chmax(int &a, int b) {
  if (a < b) a = b;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  vector<int> d(k + 1);
  d[0] = 1;
  for (auto &i : a) {
    for (int j = k; j >= i; j--) {
      if (d[j - i]) d[j] += d[j - i];
    }
  }
  int ans = 0;
  for (auto &i : a) {
    for (int j = i; j <= k; j++) {
      if (d[j - i]) d[j] -= d[j - i];
    }
    int b = 0;
    for (int j = max(k - i, 0LL); j < k; j++) {
      if (d[j]) {
        b = 1;
        break;
      }
    }
    if (!b) ans++;
    for (int j = k; j >= i; j--) {
      if (d[j - i]) d[j] += d[j - i];
    }
  }
  cout << ans << '\n';
}

signed main() {
#ifdef _DEBUG
  freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) solve();
}
