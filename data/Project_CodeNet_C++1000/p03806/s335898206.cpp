#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int ma,mb;
    cin >> n >> ma >> mb;
    int a[n],b[n],c[n];
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    int dp[n+1][401][401];
    for(int i=0; i<401; i++){
        for(int j=0; j<401; j++){
            for(int k=0; k<n+1; k++){
                dp[k][i][j] = 10000;
            }
        }
    }
    dp[0][0][0] = 0;
    for(int i=1; i<n+1; i++){
        for(int ca=0; ca < 401; ca++){
            for(int cb=0; cb < 401; cb++){
                if(dp[i-1][ca][cb] == 10000) continue;
                dp[i][ca][cb] = min(dp[i-1][ca][cb],dp[i][ca][cb]);
                dp[i][ca+a[i-1]][cb+b[i-1]] = min(dp[i-1][ca][cb]+c[i-1],dp[i][ca+a[i-1]][cb+b[i-1]]);
            }
        }
    }
    int ans = 10000;
    for(int ca=1; ca<401; ca++){
        for(int cb=1; cb<401; cb++){
            if(ca*mb==cb*ma){
                ans = min(ans,dp[n][ca][cb]);
            }
        }
    }
    if(ans == 10000) ans = -1;
    cout << ans << endl;

    return 0;
}
