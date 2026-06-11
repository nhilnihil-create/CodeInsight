#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9+7;
const ld error = 2e-6;
const ld PI = acosl(-1); //const ld PI = acosl(-1)

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

#define debug(x) cerr<<#x<<" = "<<(x)<<"\n"
#define hoise cerr<<"hoise - "<<__LINE__<<"\n"
#define tham getchar()
mt19937 rng((unsigned)chrono::system_clock::now().time_since_epoch().count()); //mt199937_64 for ll
//mt19937 rng(199);

inline ll MOD(ll x, ll m = mod){
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 1e5+10;

#define contents(T, c) ostream_iterator<T>(cerr, c)
///===========================================  template  =======================================================

vector<int> adj[nmax];
bool visited[nmax];
bool color[nmax];

bool dfs(int root, int c){
    visited[root] = true;
    color[root] = c;
    bool ret = true;
    for(int u : adj[root]){
        if(visited[u]){
            ret &= (color[u] == (c^1));
        }
        else{
            ret &= dfs(u, c^1);
        }
    }
    return ret;
}

int main(){
    FASTIO;
    int n, m;
    cin>>n>>m;
    for(int i = 1; i<=m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll bipartite = 0;
    ll nonBipartite = 0;
    ll isolated = 0;

    for(int u = 1; u <= n; u++){
        if(!visited[u]){
            bool colorable = dfs(u, 0);

            if(adj[u].size() == 0) isolated++;
            else if(colorable) bipartite++;
            else nonBipartite++;
        }
    }

//    debug(bipartite);
//    debug(nonBipartite);
//    debug(isolated);

    ll ans = ll(n)*ll(n);
    ans -= (n-isolated) * (n-isolated);
    ans += (bipartite+nonBipartite)*(bipartite+nonBipartite);
    ans += bipartite*bipartite;
    cout<<ans;
    return 0;
}
