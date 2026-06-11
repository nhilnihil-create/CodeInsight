#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  int s = 0;
  int sp = 0;
  int ans = 1;

  for (int i = 0; i < n - 1; i++) {
    if (a[i] < a[i + 1]) s = 1;
    if (a[i] > a[i + 1]) s = -1;

    if (s == 1 && sp == -1 || s == -1 && sp == 1) {
      ans++;
      s = 0;
      sp = 0;
      continue;
    }
    sp = s;
  }

  cout << ans << endl;
}
