
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

LL dp[5001][5002];

int main(){

    int N;cin>>N;
    string s;cin>>s;
    LL inf = 1e9 + 7;
    fill(dp[0],dp[N+1],0);
    dp[0][0]=1;
    for (int i=1;i<=N;i++)for (int j=0;j<=N;j++)dp[i][j] =(dp[i-1][j+1] + (j==0 ? dp[i-1][0] : 2*dp[i-1][j-1]))%inf;
    LL inv=500000004;

    LL ans =dp[N][s.size()];
    REP(i,s.size())ans=(ans*inv)%inf;
    cout<<ans<<endl;



    return 0;
}