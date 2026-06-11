#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
#define REP(i,n) for(int i=0; i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

int main(){
    int N;ll A;cin>>N>>A;
    vector<ll> x(N);
    REP(i,N)cin>>x[i];
    ll dp[51][2501][51];
    // dp[i][j][k] i番目までの数字をk個つかって和をjとできるものの場合の数
    REP(i,51)REP(j,2501)REP(k,51)dp[i][j][k]=0;
    dp[0][0][0]=1;
    FOR(i,1,N+1)REP(j,2501)REP(k,N+1){
        if(x[i-1]>j||k==0)dp[i][j][k]=dp[i-1][j][k];
        else{
            dp[i][j][k]=dp[i-1][j-x[i-1]][k-1]+dp[i-1][j][k];
        }
    }
    ll res=0;
    FOR(i,1,N+1)res+=dp[N][A*i][i];
    cout<<res<<endl;
    return 0;
}