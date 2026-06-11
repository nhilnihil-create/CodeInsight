#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll mod = 1e9 + 7;

const int N = 100 + 1;
const int SN = 100 * 100 + 1;

int a[N];
int dp[SN];

int main() {
  int n;
  cin >> n;
  int nmax = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    nmax += a[i];
  }
  memset(dp, -1, sizeof(dp));
  int ans = 0;
  for (int i = 1; i <= nmax; i++) {
    for (int j = 0; j < n; j++) {
      if (i - a[j] == 0 || ((i - a[j] >= 1) && (dp[i - a[j]] != -1) && (dp[i - a[j]] < j))) {
        dp[i] = j;
        if (i % 10) ans = i;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
