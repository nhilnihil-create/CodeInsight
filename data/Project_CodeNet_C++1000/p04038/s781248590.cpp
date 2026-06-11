#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <bitset>
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define index(xs, x) (int)(lower_bound(all(xs), x) - xs.begin())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
void add(int &x, int v) { x += v; if (x >= MOD) x -= MOD; }

int N, K;
int dp[4001][2001];
int fact[4010000], inv_fact[4010000];

int modpow(int x, int k) {
  int a = 1;
  while (k) {
    if (k&1) a = (1LL*a*x) % MOD;
    x = (1LL*x*x)%MOD;
    k >>= 1;
  }
  return a;
}
inline int nCr(int n, int k) {
  //if (k < 0 || k > n) return 0;
  return ((1LL*((1LL*fact[n]*inv_fact[k]))%MOD)*inv_fact[n-k]) % MOD;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  fact[0] = 1;
  for (int i=1; i<4010000; i++) fact[i] = (1LL*i*fact[i-1])%MOD;
  rep(i, 4010000) inv_fact[i] = modpow(fact[i], MOD-2);
  cin >> N >> K;
  if (K == 1) {
    cout << 1 << "\n";
    return 0;
  }

  dp[0][0] = 1;
  rep(i, 2*N) {
    // put ○
    rep(j, N+1) if (i-j+1 <= j) add(dp[i+1][j], dp[i][j]);
    // put ●
    rep(j, N) add(dp[i+1][j+1], (1LL*dp[i][j]*nCr(i+(j+1)*(K-2), K-2))%MOD);
  }
  int s = dp[2*N][N];
  for (int i=1; i<=N; i++) s = (1LL*i*s) % MOD;
  cout << s << "\n";
  return 0;
}
