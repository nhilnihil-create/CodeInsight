#include<bits/stdc++.h>
using namespace std;
struct _IO{_IO(){ios::sync_with_stdio(0);cin.tie(0);}}_io;
typedef long long ll; typedef long double db;
const int N = 5e3 + 5, M = 1e9 + 7;

ll dp[N][N];

ll qpow(ll x, ll n) {
  ll res = 1;
  for (; n; n >>= 1, x = x * x % M) if (n & 1) res = res * x % M;
  return res;
}

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int m = s.size();
  dp[0][0] = 1;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j] * 2) % M;
      dp[i+1][max(j-1, 0)] = (dp[i+1][max(j-1, 0)] + dp[i][j]) % M;
    }
  }
  cout << qpow(qpow(2, M -2), m) * dp[n][m] % M;
}
