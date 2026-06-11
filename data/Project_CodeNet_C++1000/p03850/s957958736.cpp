#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;
const ll oo = 1e18;

int n, a[N], opt[N];
ll f[N][3];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  opt[1] = 1; cin >> a[1];
  for (int i = 2; i <= n; ++i) {
    char c;
    cin >> c >> a[i];
    opt[i] = (c == '+') ? 1 : -1;
  }
  f[0][1] = f[0][2] = -oo;
  for (int i = 1; i <= n; ++i) {
    f[i][0] = *max_element(f[i - 1], f[i - 1] + 3) + 1LL * opt[i] * a[i];
    f[i][1] = max(f[i - 1][1], f[i - 1][2]) - 1LL * opt[i] * a[i];
    f[i][2] = f[i - 1][2] + 1LL * opt[i] * a[i];
    if (opt[i] == -1) {
      f[i][2] = max(f[i][2], f[i][1]);
      f[i][1] = max(f[i][1], f[i][0]);
    }
  }
  cout << *max_element(f[n], f[n] + 3);
  return 0;
}