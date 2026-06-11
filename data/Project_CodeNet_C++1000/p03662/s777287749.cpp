/* Author : Aaryan Srivastava ^__^ */ 
#include <bits/stdc++.h>
#include <random>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second   
#define rep(i,n) for(int i = 0 ; i < (n) ; i++)
#define repA(i,x,y) for(int i = (x) ; i <= (y) ; i++)
#define repD(i,x,y) for(int i = (x) ; i >= (y) ; i--)
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define setval(a,val) memset(a,val,sizeof(a))
#define Randomize mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define trav(x , a) for(auto &x : a)
#define sz(a) ((int)a.size())
typedef long long ll ; 
#define int ll
using namespace std;

const int N = 3e5 + 5 ;
const int mod = 1e9 + 7 ;
const ll inf = 1e18 ;
const int SZ = 101 ;
const long double eps = 1e-9 ;

using namespace __gnu_pbds;
using ordered_set =  tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ;

typedef pair<int, int> pii; 
typedef pair<int , pii> ipii ;
typedef pair<pii , int> piii ; 
typedef unsigned long long ull ;
typedef long double ld;

ll po(ll x,ll y,ll p = mod) {ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}

const int LG = 18;
int d[N] , up[LG][N] , sub[N] , n; 
vector<int> g[N];

void dfs(int u , int p = 0){
    if(p != 0) d[u] = d[p] + 1; 
    up[0][u] = p; 
    sub[u]++ ;
    rep(i , LG - 1) up[i + 1][u] = up[i][up[i][u]];
    trav(v , g[u]) if(v != p){
        dfs(v , u);
        sub[u] += sub[v];
    }
} 

int lca(int u , int v){
    if(d[u] > d[v]) swap(u , v);
    int k = d[v] - d[u] , U = u , V = v;
    repD(i , LG - 1, 0) if(k >> i & 1){
        v = up[i][v] ;
    }
    if(u == v) return u ;
    repD(i , LG - 1 , 0){
        if(up[i][u] != up[i][v]){
            u = up[i][u];
            v = up[i][v];
        }
    }
    return up[0][u];
}

int go_up(int u, int h){
    repD(i , LG - 1 , 0) if(h >> i & 1) u = up[i][u];
    return u ;
}

pii get(int u , int v){
    int l = lca(u , v);
    int t = d[l] * 2LL - d[u] - d[v];  
    t *= -1;
    t = (t - 1)/2 ;
    // cout << t << '\n';
    if(d[u] <= d[v]){
        // first will get
        v = go_up(v , t);
        // cout << u << ' ' << v << '\n';
        return mp(n - sub[v] , sub[v]);
    }else{
        u = go_up(u , t);
        // cout << u << ' ' << v << '\n';
        return mp(sub[u] , n - sub[u]);
    }
}

void solve()
{
    cin >> n ;
    rep(i , n - 1){
        int x , y;
        cin >> x >> y ;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1);
    auto p = get(1 , n);
    // cout << p.ff << ' ' << p.ss << '\n';
    cout << (p.ff > p.ss ? "Fennec" : "Snuke");
}
     
int32_t main(int32_t argc, char *argv[])
{
    ios::sync_with_stdio(0);    
    cin.tie(0); cout.tie(0);
    int TC = 1, t = 0;
    //cin >> TC ;
    while(t++ < TC)
    {
        //cout << "Case #" << t << ": " ;
        solve();
        cout << "\n" ;
    }
    return 0;
}
