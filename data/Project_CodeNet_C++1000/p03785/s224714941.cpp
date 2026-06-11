#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define vc vector<char>
#define ii pair<int,int>
#define fi first
#define sc second
#define all(x) (x).begin(),(x).end()
#define get_bit(x, k) ((x >> k) & 1)
// ---------------------------------

void MAIN() {
  int n, c, k;
  cin >> n >> c >> k;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  sort(all(a));
  int i = 0, ans = 0;
  while (i < n) {
    i = upper_bound(a.begin() + i, a.begin() + min(i + c, n), a[i] + k) - a.begin();
    ans++;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
