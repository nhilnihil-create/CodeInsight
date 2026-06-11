#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int (i)=0; i<(int)(n); i++)

int dp[50][410][410],a[50],b[50],c[50];

int main(void){
    int N,M,K,ans=1000000;
    cin >> N >> M >> K;
    REP(i,N) cin >> a[i] >> b[i] >> c[i];
    REP(i,N+1)
    	REP(j,10*N+1)
    		REP(k,10*N+1)
                dp[i][j][k] = 1000000;
    dp[0][0][0]=0;
	REP(i,N+1)
    	REP(j,10*N+1)
    		REP(k,10*N+1){
              	if(dp[i][j][k] == 1000000) continue;
                dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
                dp[i+1][j+a[i]][k+b[i]] = min(dp[i+1][j+a[i]][k+b[i]], dp[i][j][k]+c[i]);
            }
    for(int i=1;i<=10*N;i++){
        if(i*K/M>10*N) break;
      	if(i%M!=0) continue;
        ans=min(ans, dp[N][i][i*K/M]);
    }
    if(ans == 1000000) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
