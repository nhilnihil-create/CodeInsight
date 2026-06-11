#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
ll DP[61][61][2601];
int main() {
  int N,A;
  cin >> N >> A;
  int x[N];
  for (int i = 0; i < N; i++) {
    cin >> x[i];
  }
  for (int i = 0; i <= 60; i++) {
    for (int j = 0; j <= 60; j++) {
      for (int k = 0; k <= 2600; k++) {
        DP[i][j][k] = 0;
      }
    }
  }
  DP[0][0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k <= 2500; k++) {
        DP[i+1][j+1][k+x[i]] += DP[i][j][k];
        DP[i+1][j][k] += DP[i][j][k];
      }
    }
  }
  ll ans = 0;
  for (int i = 1; i <= N; i++) {
    ans += DP[N][i][i*A];
  }
  cout << ans << endl;
  return 0;
}