#include<iostream>
#include<algorithm>

int const MAXN = 40;
int const INF = 5000;
int const MAXG = 401;

int N, Ma, Mb;
int a[MAXN], b[MAXN], c[MAXN];

int dp[MAXN+1][MAXG][MAXG];

int main() {
  std::cin >> N >> Ma >> Mb;
  int ma = 0, mb = 0, mc = 0;
  for(int i = 0; i < N; ++i) {
    std::cin >> a[i] >> b[i] >> c[i];
    ma += a[i]; mb += b[i]; mc += c[i];
  }
  for(int i = 0; i <= N; ++i) for(int j = 0; j <= ma; ++j) {
    std::fill(dp[i][j], dp[i][j]+mb+1, INF);
  }
  dp[0][0][0] = 0;
  for(int i = 1; i <= N; ++i) for(int j = 0; j <= ma; ++j) {
    for(int k = 0; k <= mb; ++k) {
      int aa = a[i-1], bb = b[i-1], cc = c[i-1];
      int nv = (j >= aa && k >= bb)? dp[i-1][j-aa][k-bb] + cc: INF;
      dp[i][j][k] = std::min(dp[i-1][j][k], nv);
    }
  }
  int ans = INF;
  for(int k = 1; k*Ma <= ma && k*Mb <= mb; ++k) ans = std::min(ans, dp[N][k*Ma][k*Mb]);
  if(ans >= INF) ans = -1;
  std::cout << ans << std::endl;
  return 0;
}
