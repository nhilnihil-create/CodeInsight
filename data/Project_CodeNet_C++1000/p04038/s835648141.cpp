#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) ((x).size()))
typedef long long ll;
typedef long double ld;

const ll mod = 1000000000 + 7;

int n, k;
ll p[5000000], pinv[5000000], inv[5000000], dp[3000];

ll binom(int n, int k) {
  return (((p[n] * pinv[n - k]) % mod) * pinv[k]) % mod;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> n >> k;
	p[0] = p[1] = pinv[0] = pinv[1] = inv[1] = 1;
	for (int i = 2; i <= n * k; i++)
		inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod, p[i] = (p[i - 1] * i) % mod, pinv[i] = (pinv[i - 1] * inv[i]) % mod;
  if (k == 1) {
    cout << "1\n";
    return 0;
  }
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = i; j >= 0; j--)
      dp[j + 1] = (dp[j + 2] + dp[j] * binom(i * k - j + k - 2, k - 2)) % mod;
    dp[0] = dp[1];
    // for (int j = 0; j <= i + 1; j++)
    //   cerr << dp[j] << (j < i + 1 ? " " : "\n");
  }
  cout << (dp[0] * p[n]) % mod << "\n";
}
