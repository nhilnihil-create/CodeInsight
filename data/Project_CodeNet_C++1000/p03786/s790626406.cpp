#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define popcnt __builtin_popcount
#define getBit(x, k) ((x >> k) & 1)
#define all(x) (x).begin(),(x).end()
// ---------------------------------

void Main() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  sort(all(a));
  vector<int> d(n), f(n);
  for (int i = 0; i < n; i++) {
    d[i] = a[i];
    if (i) d[i] += d[i - 1];
  }
  int ans = 1;
  f[n - 1] = 1;
  for (int i = n - 2; i >= 0; i--) {
    if (f[i + 1] && d[i] * 2 >= a[i + 1]) {
      f[i] = 1;
      ans++;
    }
  }
  cout << ans << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  cerr << "- ---- -- ----- <3\n";
#endif
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;
  // cin >> T;
  while (T--) Main();
}
