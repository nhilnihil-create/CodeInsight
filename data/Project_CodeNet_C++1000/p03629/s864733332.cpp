#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
#define vec vector<ll>
#define mat vector<vector<ll> >
#define fi first
#define se second
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=998244353;
signed main(){
    string s;cin>>s;
    ll n=s.size();
    vector<vector<ll> >dp(n+1,vector<ll>(26));
    rep(i,26){
        dp[n][i]=1;
    }
    for(int i=n-1;i>=0;i--){
        rep(j,26){
            dp[i][j]=dp[i+1][j];
        }
        ll a=n;
        rep(j,26){
            if(dp[i][j]<a){
                a=dp[i][j];
            }
        }
        dp[i][s[i]-'a']=a+1;
    }
    string ans="";
    ll now=n;
    ll idx=26;
    rep(i,26){
        if(now>dp[0][i]){
            now=dp[0][i];
            idx=i;
        }
    }
    ans+=(char)('a'+idx);
    rep(i,n){
        if(s[i]-'a'!=idx)continue;
        rep(j,26){
            if(now>dp[i+1][j]){
                now--;
                idx=j;
            }
        }
        ans+=(char)('a'+idx);
    }
    cout<<ans<<endl;
}