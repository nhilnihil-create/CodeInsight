#include <bits/stdc++.h>
#define int int64_t
using namespace std;

signed main() {
     int n;
     cin >> n;
     vector<vector<int>> g(n, vector<int>(n));
     for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
               cin >> g[i][j];
          }
     }
     int ans = 0;
     for (int i = 0; i < n; ++i) {
          for (int k = i + 1; k < n; ++k) {
               int mn = 1e18;
               for (int j = 0; j < n; ++j) {
                    if (g[i][j] + g[j][k] < g[i][k]) {
                         cout << -1 << endl;
                         return 0;
                    }
                    if (j != i && j != k) {
                    mn = min(g[i][j] + g[j][k], mn);
                    }
               }
               if (mn > g[i][k]) {
                    ans += g[i][k];
               }
          }
     }
     cout << ans << endl;
     return 0; 
}