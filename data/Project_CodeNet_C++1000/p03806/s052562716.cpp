#include <algorithm>
#include <iostream>

using namespace std;

const int INF = 10000;
int n, ma, mb, ans;
int dp[500][500];

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  for (int i = 0; i < 500; i++) {
    for (int j = 0; j < 500; j++) {
      dp[i][j] = INF;
    }
  }
  dp[0][0] = 0;
  
  cin >> n >> ma >> mb;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 400; i >= 0; i--) {
      for (int j = 400; j >= 0; j--) {
        dp[i+a][j+b] = min(dp[i+a][j+b], dp[i][j] + c);
      }
    }
  }
  
  ans = INF;
  for (int i = 1; i <= 400; i++) {
    for (int j = 1; j <= 400; j++) {
      if (i * mb == j * ma) {
          ans = min(ans, dp[i][j]);
      }
    }
  }
  if (ans == INF) ans = -1;
  
  cout << ans << endl;
  return 0;
}
