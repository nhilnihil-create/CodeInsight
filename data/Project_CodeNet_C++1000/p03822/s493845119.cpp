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
#define ins insert

#define debug(a) cerr<<(a)<<endl
#define dbrep(a,n) rep(_i,n) cerr<<(a[_i])<<" "; cerr<<endl
#define dbrep2(a,n,m) rep(_i,n){rep(_j,m) cerr<<(a[_i][_j])<<" "; cerr<<endl;}

using namespace std;

template<class A, class B>
ostream &operator<<(ostream &os, const pair<A,B> &p){return os<<"("<<p.fi<<","<<p.se<<")";}
template<class A, class B>
istream &operator>>(istream &is, pair<A,B> &p){return is>>p.fi>>p.se;}

const int N_MAX = 1e5;
vi G[N_MAX];
int dp[N_MAX];

void dfs(int v, int p)
{
    vi vec;
    for(auto u:G[v]){
        if (u==p) continue;
        dfs(u,v);
        vec.pb(dp[u]);
    }
    sort(rall(vec));
    int V = vec.size();
    rep(i,V) vec[i]+=i+1;
    if (V>0) dp[v] = *max_element(all(vec));
}

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin>>N;

    FOR(i,1,N-1){
        int a; cin>>a; a--;
        G[i].pb(a);
        G[a].pb(i);
    }
    dfs(0,-1);
    cout<<dp[0]<<endl;
    return 0;
}
