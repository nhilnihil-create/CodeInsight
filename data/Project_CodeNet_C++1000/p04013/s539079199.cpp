#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(vector<ll> &vx, ll offset, ll n, ll sum,
         vector<vector<vector<ll>>> &memo) {
  if (offset == vx.size()) {
    return sum == 0 && n == 0;
  }

  if (n < 0 || sum < 0) {
    return 0;
  }

  if (memo[offset][n][sum] == -1) {
    memo[offset][n][sum] = solve(vx, offset + 1, n, sum, memo) +
                           solve(vx, offset + 1, n - 1, sum - vx[offset], memo);
  }

  return memo[offset][n][sum];
}

int main(int argc, const char *argv[]) {
  int n, a;
  cin >> n >> a;

  vector<ll> vx(n);
  for (int i = 0; i < n; ++i) {
    cin >> vx[i];
  }

  vector<vector<vector<ll>>> memo(
      60, vector<vector<ll>>(60, vector<ll>(60 * 60, -1)));
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += solve(vx, 0, i, a * i, memo);
  }

  cout << ans << '\n';
}