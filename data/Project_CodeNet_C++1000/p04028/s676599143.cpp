#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int) x.size()
#define all(a) a.begin(), a.end()

const int MAXN = 5050;
const int mod = (int) 1e9 + 7;

long long binpow(long long x, long long p) {
  long long res = 1;
  while (p) {
    if (p & 1) {
      res = (res * x) % mod;
      p--;
    } else {
      x = (x * x) % mod;
      p /= 2;
    }
  }
  return res % mod;
}

long long inv(long long x) {
  return binpow(x, mod - 2) % mod;
}

int n;
string s;
long long dp[MAXN][MAXN];

int main() {

    scanf("%d\n", &n);
    getline(cin, s);

    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++) {
            dp[i + 1][j + 1] = (dp[i + 1][j + 1] + 2ll * dp[i][j]) % mod;
            dp[i + 1][max(j - 1, 0)] = (dp[i + 1][max(j - 1, 0)] + dp[i][j]) % mod;
        }

    long long ans = dp[n][sz(s)] * inv(binpow(2, sz(s))) % mod;
    cout << ans << endl;

    return 0;
}
