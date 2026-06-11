#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,K;
  cin >> N >> K;
  int a[N], b = 0;
  vector<vector<bool>> dp1(N+1,vector<bool>(K+1)),dp2(N+1,vector<bool>(K+1));
  dp1[0][0] = true;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    a[i] = min(a[i],K);
    for (int j = 0; j <= K; j++) {
      if (!dp1[i][j]) continue;
      dp1[i+1][j] = true;
      if (j+a[i] <= K) dp1[i+1][j+a[i]] = true;
    }
  }
  dp2[N][0] = true;
  for (int i = N-1; i+1; i--) {
    for (int j = 0; j < K; j++) {
      if (!dp2[i+1][j]) continue;
      dp2[i][j] = true;
      if (j+a[i] <= K) dp2[i][j+a[i]] = true;
    }
  }
  for (int i = 0; i < N; i++) {
    bool ok = false;
    for (int j = 0; j < K; j++) {
      if ((dp1[i][j] || dp2[i+1][j]) && j+a[i] >= K) {
        ok = true;
        break;
      }
    }
    for (int j = 0; j <= K-a[i]; j++) {
      if (dp1[i][j] && dp2[i+1][K-j-a[i]]) {
        ok = true;
        break;
      }
    }
    b += !ok;
  }
  cout << b;
}