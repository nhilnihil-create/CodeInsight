#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int dpL[5001][5001], dpR[5001][5001];

int main()
{
  int n, k;
  int a[5001];
  
  scanf("%d %d", &n, &k);
  
  dpL[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    a[i] = min(a[i], k);
    
    for (int j = 0; j <= k; j++) {
      dpL[i][j] = dpL[i - 1][j];
      if (j >= a[i]) dpL[i][j] |= dpL[i - 1][j - a[i]];
    }
  }
  
  for (int i = 0; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      dpL[i][j] += dpL[i][j - 1];
    }
  }
  
  dpR[n][0] = dpR[n][a[n]] = true;
  for (int i = n - 1; i >= 1; i--) {
    for (int j = 0; j <= k; j++) {
      dpR[i][j] = dpR[i + 1][j];
      if (j >= a[i]) dpR[i][j] |= dpR[i + 1][j - a[i]];
    }
  }
  
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] >= k) continue;
    
    bool need = false;
    if (i == n && dpL[i - 1][k - 1] - dpL[i - 1][k - a[i] - 1] > 0) {
      need = true;
    }
    else {
      for (int j = 0; j <= k - 1; j++) {
        if (dpR[i + 1][j] && dpL[i - 1][k - 1 - j] - (k - a[i] - j <= 0 ? 0 : dpL[i - 1][k - a[i] - j - 1]) > 0) {
          need = true;
        }
      }
    }
    cnt += !need;
  }
  
  printf("%d\n", cnt);
  
  return 0;
}