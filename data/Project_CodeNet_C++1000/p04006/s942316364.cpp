#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;ll x;cin>>n>>x;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    vector<vector<ll>> dp(2020,vector<ll>(2020,1e+18));
    rep(i,n)rep(j,n+1)dp[i][j]=a[i];
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>> > que;
    rep(i,n){
        dp[i][0]=a[i];
        que.push({a[i],0});
    }
    rep(i,n){
        rep(j,n){
            dp[(i+j+1)%n][j+1]=min(dp[(i+j+1)%n][j+1],min(dp[(i+j+1)%n][j],a[i]));
        }
    }
    rep(i,n){
        ll tmp=1e+18;
        rep(j,n+1){
            chmin(dp[i][j],tmp);
            chmin(tmp,dp[i][j]);
        }
    }
    ll res=1e+18;
    rep(i,n+1){
        ll tmp=0;
        rep(j,n)tmp+=dp[j][i];
        tmp+=x*i;
        chmin(res,tmp);
    }
    cout<<res<<endl;
}
