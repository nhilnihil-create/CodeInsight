// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
// IN THE NAME OF GOD
#include <bits/stdc++.h>

#define ff first
#define endl '\n'
#define in insert
#define ss second
#define ll long long
#define pb push_back
#define ld long double
#define pii pair <int, int>
#define pll pair <long long, long long>

using namespace std;

const int mod = 1e9 + 7, N = 2222, MAXN = 4e6 + 46;
ll n, k, dp[N][N], fact[MAXN], inv[MAXN], f[MAXN];

inline int C(int x, int y){
  return fact[x] * inv[y] % mod * inv[x - y] % mod;
}

int main(){
  //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  if(k == 1) return cout << 1, 0;

  fact[0] = inv[0] = inv[1] = f[0] = f[1] = dp[0][0] = 1;

  for(int i = 1; i < MAXN; i++){
    fact[i] = fact[i - 1] * i;
    fact[i] %= mod;
  }
  for(int i = 2; i < MAXN; i++){
    f[i] = (mod - mod / i) * f[mod % i];
    f[i] %= mod;
    inv[i] = f[i] * inv[i - 1];
    inv[i] %= mod;
  }
  for(int i = 1; i <= n; i++){
    for(int j = i; j >= 1; j--){
      dp[i][j] = dp[i][j + 1];
      dp[i][j] += dp[i - 1][j - 1] * (i * k - j - 1 < k - 2 ? 0 : C(i * k - j - 1, k - 2));
      dp[i][j] %= mod;
    }
    dp[i][0] = dp[i][1];
  }
  cout << (dp[n][0] * fact[n]) % mod;
}
// programmer: a_h_k_81
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
