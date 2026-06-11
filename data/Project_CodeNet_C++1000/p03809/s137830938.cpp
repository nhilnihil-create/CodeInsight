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
ll val[nmax];

bool ok = true;
ll dfs(int root, int par){
    if(adj[root].size() == 1){
        ll ret = val[root];
        val[root] = 0;
        return ret;
    }
    ll below = 0;
    ll maxbelow = 0;
    for(int u : adj[root]){
        if(u == par) continue;
        ll open = dfs(u, root);
        below += open;
        maxbelow = max(maxbelow, open);
    }

    ll maxuse = ((maxbelow > below/2)? below - maxbelow : below/2);
    ll used = below - val[root];

//    tham;
//    debug(root);
//    debug(used);
//    debug(maxuse);
//    debug(below);
//    debug(maxbelow);


    if(used < 0 || used > maxuse) ok = false;

    return val[root] - used;
}

int main(){
    FASTIO;

    int n;
    cin>>n;
    for(int i = 1; i<= n; i++) cin>>val[i];
    for(int i = 1; i<n; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(n == 2){
        if(val[1] == val[2]){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
        return 0;
    }

    int root = 0;
    for(int i = 1; i<=n; i++){
        if(adj[i].size() != 1) root = i;
    }

    ll open = dfs(root, -1);
    ok &= (open == 0);

    if(ok){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }

    return 0;
}
/*
5
1 2 1 1 2
2 4
5 2
3 2
1 3
*/
