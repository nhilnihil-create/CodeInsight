#include<bits/stdc++.h>
#define all(v) v.begin(), v.end() 
using namespace std;
typedef long long ll;

const int N = 55, MX = 2600;

int n, A, a[N];
ll dp[N][N][MX];

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> A;
   for(int i=1; i<=n; ++i) cin >> a[i];
   dp[0][0][0] = 1ll;
   // dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k-a[i]]
   // among first i cards selecting j cards you can make sum - k
   for(int i=1; i<=n; ++i) {
       for(int j=1; j<=n; ++j) {
           for(int k=0; k<MX-a[i]; ++k) {
               dp[i][j-1][k] += dp[i-1][j-1][k];
               dp[i][j][k+a[i]] += dp[i-1][j-1][k];
           }
       }
   }
   ll res = 0;
   for(int j=1; j<=n; ++j) {
       res += dp[n][j][j*A];
   }
   cout << res << endl;
   return 0;
} 
