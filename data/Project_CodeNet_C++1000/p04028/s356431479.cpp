#include <cassert>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits.h>
#include <map>
#include <queue>
#include <set>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll mod_pow(ll x, ll n, ll mod = MOD) {
  ll res = 1;

  while (n > 0) {
    if (n & 1) {
      res = res * x % mod;
    }

    x = x * x % mod;
    n >>= 1;
  }

  return res;
}

ll mod_inverse(ll x, ll mod = MOD) {
  return mod_pow(x, mod - 2, mod);
}

const int MAX_N = 5001;
int dp[MAX_N][MAX_N];

int main() {
  int N;
  string S;

  cin >> N;
  cin >> S;

  int L = S.size();
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;

  for (int i = 0; i < N; ++i){
    for (int j = 0; j < N; ++j) {
      if (j > 0) {
        dp[i + 1][j - 1] += dp[i][j];
        dp[i + 1][j - 1] %= MOD;
      } else {
        dp[i + 1][j] += dp[i][j];
        dp[i + 1][j] %= MOD;
      }

      dp[i + 1][j + 1] += 2 * dp[i][j];
      dp[i + 1][j + 1] %= MOD;
    }
  }

  ll m = mod_pow(2, L);
  cout << (dp[N][L] * mod_inverse(m)) % MOD << endl;

  return 0;
}
