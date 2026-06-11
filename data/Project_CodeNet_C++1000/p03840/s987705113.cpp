#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> a(8);
  for (int i = 1; i <= 7; i++) {
    cin >> a[i];
  }
  int ans = (a[1] - a[1] % 2) + a[2] + (a[4] - a[4] % 2) + (a[5] - a[5] % 2);
  if (a[1] > 0 && a[4] > 0 && a[5] > 0) {
    ans = max(ans, (a[1] - 1 - (a[1] - 1) % 2) + a[2] + (a[4] - 1 - (a[4] - 1) % 2) + ((a[5] - 1) - (a[5] - 1) % 2) + 3);
  }
  cout << ans << '\n';
} 