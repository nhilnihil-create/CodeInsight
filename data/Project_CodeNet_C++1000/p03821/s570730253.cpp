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
  int n; cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  int d = 0;
  for (int i = n - 1; i >= 0; i--) {
    a[i] += d;
    if (a[i] == 0) continue;
    int t;
    if (a[i] <= b[i]) t = b[i];
    else t = ((a[i] - 1) / b[i] + 1) * b[i];
    d += t - a[i];
  }
  cout << d << '\n';
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T = 1;
  // cin >> T;
  while (T--) MAIN();
}
