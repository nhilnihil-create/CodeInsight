#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[310][310];
int dp1[310][310];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> dp[i][j];
      dp1[i][j] = dp[i][j];
    }
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
	dp1[i][j] = min(dp1[i][j], dp1[i][k] + dp1[k][j]);
      }
    }
  }

  ll ans = 0;
  for (int i = 0; i < n-1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (dp[i][j] == dp1[i][j]) {
	bool f = 0;
	for (int k = 0; k < n; k++) {
	  if (k == i || k == j) continue;
	  if (dp1[i][j] == dp1[i][k] + dp1[k][j]) {
	    f = 1;
	    break;
	  }
	}
	if (!f) {ans += dp[i][j];}
      }
      if (dp[i][j] > dp1[i][j]) {
	cout << -1 << endl;
	return 0;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
