#include <bits/stdc++.h>
#define pii pair<int, pair<int, int>>
#define ss second
#define ff first
#define all(x) ((x).begin(), (x).end())

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
const ll oo = 10000000;
const int maxn = 40, maxab = 10;
int n, ma, mb, dp[maxn+1][maxn*maxab + 1][maxn*maxab + 1], a[maxn+1], b[maxn+1], c[maxn+1];

int main(){
    ios_base::sync_with_stdio(false);

    cin >> n >> ma >> mb;
    
    for (int i=0; i<n; ++i) cin >> a[i] >> b[i] >> c[i];

    for (int i=0; i<=n; ++i){
        for (int j=0; j <= maxn*maxab; ++j){
            for (int k=0; k <= maxn*maxab; ++k){
                dp[i][j][k] = oo;
            }
        }
    }

    dp[0][0][0] = 0;

    for (int k=0; k < n; ++k){
        for (int i=0; i<=maxn*maxab; ++i){
            for (int j=0; j<=maxn*maxab; ++j){
                if (dp[k][i][j] == oo) continue;
                dp[k+1][i][j] = min(dp[k][i][j], dp[k+1][i][j]);
                dp[k+1][i+a[k]][j+b[k]] = min(dp[k+1][i+a[k]][j+b[k]], dp[k][i][j] + c[k]);
            }
        }
    }

    int ans = oo;

    for (int i=1; i<=maxn*maxab; i++){
        for (int j=1; j<=maxn*maxab; j++){
            if (i*mb == j*ma) ans = min(ans, dp[n][i][j]);
        }
    }
    if (ans == oo) ans = -1;
    cout << ans << endl;
    return 0;
}