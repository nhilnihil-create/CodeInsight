#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=1e9+7;
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;cin>>n>>k;
    vector<ll>a(n);
    rep(i,n){
        cin>>a[i];
    }
    //boolでいける
    vector<vector<bool> >dp(n+1,vector<bool>(k+1));
    vector<vector<bool> >dp2(n+2,vector<bool>(k+1));
    dp[0][0]=1;
    rep(i,n){
        rep(j,k+1){
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
            if(j+a[i]<=k)dp[i+1][j+a[i]]=max(dp[i][j],dp[i+1][j+a[i]]);
            else{
                dp[i+1][k]=max(dp[i+1][k],dp[i][j]);
            }
        }
    }
    ll ans=n;
    dp2[n+1][0]=1;
    for(int i=n+1;i>1;i--){
        rep(j,k+1){
            dp2[i-1][j]=max(dp2[i-1][j],dp2[i][j]);
            if(j+a[i-2]<=k)dp2[i-1][j+a[i-2]]=max(dp2[i][j],dp2[i-1][j+a[i-2]]);
            else{
                dp2[i-1][k]=max(dp2[i-1][k],dp2[i][j]);
            }
        }
    }
    REP(i,1,n+1){
        ll ai=a[i-1];
        ll ma1=0,ma2=0;
        rep(j,k+1){
            if(dp[i-1][j])ma1=j;
        }
        rep(j,k+1){
            if(dp2[i+1][j])ma2=j;
        }
        if(ma1+ma2<k-ai){
            continue;
        }
        //cout<<ma1<<' '<<ma2<<endl;
        vector<ll>rui(k+1);
        rui[k]=dp2[i+1][k];
        for(int j=k-1;j>=0;j--){
            rui[j]=rui[j+1]+dp2[i+1][j];
        }
        bool f=0;
        rep(j,k){
            if(!dp[i-1][j])continue;
            ll l=max(0LL,k-ai-j);
            ll r=k-j;
            if(i==4){
            }
            if(rui[l]-rui[r]>0)f=1;
        }
        if(f)ans--;
        //cout<<i<<' '<<ans<<endl;
    }
    cout<<ans<<endl;
}