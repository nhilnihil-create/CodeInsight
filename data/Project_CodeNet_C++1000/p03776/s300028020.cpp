#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

map<int, map<int, int>> mem;

int C(int n, int k) {
  if (k == 1) return n;
  if (k == n) return 1;
  if (mem[n][k]) return mem[n][k];
  return mem[n][k] = C(n - 1, k - 1) + C(n - 1, k);
}

void solve() {
  int n, l, r;
  cin >> n >> l >> r;
  vector<double> a(n);
  for (auto &i : a) cin >> i;
  sort(all(a), greater<int>());
  double sum = 0;
  for (int i = 0; i < l; i++) {
    sum += a[i];
  }
  cout << fixed << setprecision(10);
  cout << sum / l << '\n';
  int al = 0, il = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == a[l - 1]) {
      al++;
      if (i < l) il++;
    }
  }
  int ans = 0;
  if (il == l) {
    for (int i = l; i <= min(al, r); i++) {
      ans += C(al, i);
    }
  } else {
    ans = C(al, il);
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
