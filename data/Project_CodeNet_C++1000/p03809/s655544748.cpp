#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

vector<vi> adj;
vll A;
vll dp;
bool ng=false;

void dfs(int v, int p){
    if (ng) return;
    if (v!=0 && adj[v].size()==1){
        dp[v] = A[v];
        return;
    }
    ll sum=0,ma=0;
    priority_queue<ll> que;
    for(auto u:adj[v]){
        if (u==p) continue;
        dfs(u,v);
        sum+=dp[u];
        chmax(ma,dp[u]);
    }
    ll xmax=0;
    if (ma*2>sum){
        xmax = sum-ma;
    }else{
        xmax = sum/2;
    }

    ll x = sum-A[v];
    if (x<0 || x>xmax){ng=true; return;}
    ll y = A[v]-x;
    if (y<0){ng=true; return;}
    dp[v] = y;
    if (v==0 && y>0 && adj[v].size()!=1) ng=true;
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin>>n;
    adj.resize(n);
    A.resize(n);
    dp.resize(n);
    rep(i,n) cin>>A[i];
    rep(i,n-1){
        int a,b; cin>>a>>b; a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0,-1);
    // rep(i,n) cout<<dp[i]<<" ";
    if (ng){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
    }
    return 0;
}
