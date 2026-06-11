#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

signed main(){
    typedef pair<long long,long long> P;
    constexpr long long INF=LLONG_MAX;
    int N,A,B;cin>>N>>A>>B;
    vector<long long> v(N);
    REP(i, N) cin >> v[i];
    vector<vector<P>> dp(N+1,vector<P>(N+1,P(-INF,0LL)));
    REP(i,N+1) dp[i][0]=P(0,1);
    P ans=P(0LL,1LL);
    REP(i,N) REP(j,N){
        long long u=dp[i][j+1].first,d=dp[i][j].first+v[i];
        if(u>d) dp[i+1][j+1]=P(u,dp[i][j+1].second);
        if(u==d) dp[i+1][j+1]=P(u,dp[i][j+1].second+dp[i][j].second);
        if(u<d) dp[i+1][j+1]=P(d,dp[i][j].second);
        long long tmp=max(u,d);
        if(A<=j+1&&j+1<<B&&ans.first*(j+1)<tmp*ans.second){
            ans=P(tmp,j+1);
        }
    }
    long long choice=0;
    rep(i,A,B+1){ 
        long long sum=dp[N][i].first;
        if(sum*ans.second==ans.first*i){
            choice+=dp[N][i].second;
        }
    }
    printf("%.16f\n",(double)ans.first/(double)ans.second);
    cout<<choice<<endl;
}