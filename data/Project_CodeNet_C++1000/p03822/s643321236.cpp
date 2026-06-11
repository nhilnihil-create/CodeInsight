
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=(ll)1E12;//10^12
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
const double EPS=1E-8;
////////////////////////////////////////
#define N 100005
int n;
vector<int>c[N];
int dp[N];

int dfs(int s){
    if(dp[s]!=-1)return dp[s];
    if(c[s].size()==0) return dp[s]=0;
    vector<int>v;
    for(int x:c[s]){
        v.pb(dfs(x));
    }
    sort(v.begin(),v.end());
    int m=v.size();
    int res=0;
    rep(i,0,m-1){
        res=max(res,v[i]+m-i);
    }
    return dp[s]=res;
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    
    cin>>n;
    rep(i,1,n-1){
        int p;cin>>p;p--;
        c[p].pb(i);
    }
    fill(dp,dp+N,-1);
    cout<<dfs(0)<<endl;
    
    return 0;
}