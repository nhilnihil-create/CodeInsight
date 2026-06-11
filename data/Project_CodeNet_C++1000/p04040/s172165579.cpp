#include <bits/stdc++.h>
using namespace std;

namespace Combinatorics {

using lint = long long;

lint MOD;
vector<lint> factorial, inv;

lint power(lint n, lint x) {
  if (x == 0) {
    return 1;
  }
  lint res = power(n, x / 2);
  res *= res;
  res %= MOD;
  if (x & 1) {
    res *= n;
    res %= MOD;
  }
  return res;
}

void init(int n, int MOD_) {
  MOD = MOD_;
  factorial.resize(n);
  factorial[0] = 1;
  for (int i = 1; i < n; i++) {
    factorial[i] = factorial[i - 1] * i % MOD;
  }
  inv.resize(n);
  inv[n - 1] = power(factorial[n - 1], MOD - 2);
  for (int i = n - 2; i >= 0; i--) {
    inv[i] = inv[i + 1] * (i + 1) % MOD;
  }
}

lint Choose(int n, int k) {
  return factorial[n] * inv[k] % MOD * inv[n - k] % MOD;
}

}

int main() {
  int N, M, A, B, MOD = 1e9 + 7;
  cin >> N >> M >> A >> B;

  Combinatorics::init(2 * (N + M), 1e9 + 7);
  long long ans = 0;
  for (int i = 1; i <= N - A; i++) {
    pair<int, int> part1(i - 1, B - 1);
    pair<int, int> part2(N - i, M - B - 1);
    ans += 1ll * Combinatorics::Choose(part1.first + part1.second, part1.first) * Combinatorics::Choose(part2.first + part2.second, part2.first) % MOD;
    ans %= MOD;
  }

  cout << ans << "\n";
  return 0;
}