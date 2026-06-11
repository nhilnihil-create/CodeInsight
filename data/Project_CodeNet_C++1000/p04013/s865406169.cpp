#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
typedef long long ll;
ll dp[2][N][N*N];
int n, a;
int x[N];
int tot;
int main() {
  cin>>n>>a;
  tot=0;
  for (int i = 0; i < n; ++i) {
  	cin>>x[i];
    tot += x[i];
  }
  memset(dp, 0LL, sizeof(dp));
  dp[0][0][0] = 1;
  for (int i = 0; i < n; ++i) {
    int now = (i&1) ^ 1;
    memset(dp[now], 0, sizeof(dp[now]));
  	for (int j = 0; j <= i; ++j) {
      for (int k  =0; k < tot; ++k) {
      	dp[now][j+1][k+x[i]] += dp[now^1][j][k];
        dp[now][j][k] += dp[now^1][j][k];
      }
    }
  }
  ll res=0;
  for (int i= 1; i <= n; ++i) {
  	for (int j = 0; j <= tot; ++j) {
      if (j % i == 0 && j / i == a) {
      	res += dp[n&1][i][j];
      }
    }
  }
  cout<<res<<endl;
  return 0;
}