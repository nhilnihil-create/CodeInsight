#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e6 + 5, mod = 1e9 + 7;
int n, f[N];

main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  f[0] = 0, f[1] = n, f[2] = n * n % mod;
  int tot = 0;
  for(int i = 3; i <= n; ++i) {
    f[i] = (f[i - 1] + (n - 1) * (n - 1) % mod) % mod;
    f[i] = (f[i] + tot + n - i + 2) % mod;
    tot = (tot + f[i - 2]) % mod;

  }
  cout << f[n] << '\n';
}
