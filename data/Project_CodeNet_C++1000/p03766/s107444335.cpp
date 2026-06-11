#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 6;
const ll MOD = 1e9 + 7;

int n;
ll f[2 * N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cin >> n;
  f[n] = n;
  for (int i = n + 1; i <= 2 * n; ++i) f[i] = 1;
  ll tmp = (1LL * (n - 1) * (n - 1)) % MOD;
  ll sum = n - 1;
  for (int i = n - 1; i; --i) {
    f[i] = (tmp + f[i + 1] + sum) % MOD;
    sum = sum + f[i + 2] - f[i + n + 1];
  }
  cout << f[1];
  return 0;
}