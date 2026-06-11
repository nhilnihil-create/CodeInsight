#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define ld long double
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

#define INF LONG_LONG_MAX

vector<vi> adj;
vector<bool> reach;

void dfs(int v)
{
    reach[v] = true;
    for(auto u:adj[v]){
        if (reach[u]) continue;
        dfs(u);
    }
}

//-------------------------------------------------

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    adj.resize(n);
    using edge = tuple<int,int,ll>;
    vector<edge> es;
    rep(i,m){
        ll a,b,c; cin>>a>>b>>c; a--; b--;
        adj[b].pb(a);
        es.emplace_back(a,b,c);
    }
    reach.resize(n,false);
    dfs(n-1);
    vll dist(n,-INF);
    dist[0] = 0;
    rep(i,n){
        rep(j,m){
            int from,to; ll c;
            tie(from,to,c) = es[j];
            if (dist[from]==-INF) continue;
            if (dist[to] < dist[from]+c){
                dist[to] = dist[from]+c;
                if (i==n-1 && reach[to]){
                    cout<<"inf\n";
                    return 0;
                }
            }
        }
    }
    cout<<dist[n-1]<<endl;
    return 0;
}
