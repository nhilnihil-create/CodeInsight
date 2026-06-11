#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 40;
const int MAXAB = 400;
const int INF = 1e9;

int a[N + 1], b[N + 1], c[N + 1];
int dp[N + 1][MAXAB + 1][MAXAB + 1];

int main() {
  int n, A, B;
  cin >> n >> A >> B;
  
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  
  
  for (int k = 0; k <= n; k++)
    for (int i = 0; i <= MAXAB; i++)
      for (int j = 0; j <= MAXAB; j++)
        dp[k][i][j] = INF;
  
  dp[0][0][0] = 0;
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= MAXAB; j++) {
      for (int k = 0; k <= MAXAB; k++) {
        if (dp[i][j][k] == INF) continue;
        dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
        if (a[i] +  j <= MAXAB && b[i] + k <= MAXAB) {
          dp[i + 1][j + a[i]][k + b[i]] = min(dp[i + 1][j + a[i]][k + b[i]], dp[i][j][k] + c[i]);
        }
      }
    }
  }
  
  int ans = INF;
  
  for (int i = 1; i <= MAXAB; i++) {
    for (int j = 1; j <= MAXAB; j++) {
      if (A * j == B * i) {
        ans = min(ans, dp[n][i][j]);
      }
    }
  }
  
  cout << (ans == INF ? -1 : ans) << endl;
  return 0;
}
