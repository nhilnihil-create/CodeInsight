#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <set>

//#define DEBUG 1

#define int long long
#define for0(i,n) for (int i=0; i<n; i++)
#define iter(c) for(auto it=c.begin(); it!=c.end(); it++)
#define vec(x) vector< x >
#define pb push_back
#define ms(a,z) memset(a,z,sizeof(a));
#define mp make_pair
#define X first
#define Y second
#define sqr(x) 1LL*(x)*(x)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define all(a) a.begin(),a.end()
#define sz(x) (int)(x).size()
#ifdef int
#define read(x) scanf("%lld",&x);
#else
#define read(x) scanf("%d",&x);
#endif

#ifdef DEBUG
#define nl cout<<"\n";
#define pr(x) cout<<(x)<<" ";
#define prl(x) cout<<#x " = "<<x<<endl;
#define prp(x) cout<<"("<<(x).first<<" "<<(x).second<<") ";
#define printv(v) {for(int _=0; _<sz(v); _++) cout<<v[_]<<" "; cout<<"\n";}
#define printa(a,s) {for (int _=0; _<s; _++) cout<<a[_]<<" "; cout<<"\n";}
#define print2D(a,m,n) {for (int _=0; _<m; _++) {for (int __=0; __<n; __++) cout<<a[_][__]<<" "; cout<<"\n";} cout<<"\n";}
#define debug cout<<"ok at line "<<__LINE__<<endl;
#else
#define nl
#define pr(x)
#define prl(x)
#define prp(x)
#define printv(v)
#define printa(a,s)
#define print2D(a,m,n)
#define debug
#endif

#define MAXN 100000

using namespace std;

typedef long long ll;

const int INF = 2147483647;
const long long INFL = 9223372036854775807LL;
const double EPSILON = 0.00000001;
const long long MOD = 1000000007;

vector<int> adj[MAXN+5], children[MAXN+5];
bool visited[MAXN+5];
int grundy[MAXN+5];

vector<int> dfs()
{
    ms(visited,false);
    stack<int> s;
    visited[0] = true;
    s.push(0);
    vector<int> node_order;

    while (!s.empty()) {
        int top = s.top(); s.pop();
        node_order.pb(top);
        iter(adj[top]) {
            if (!visited[*it]) {
                visited[*it] = true;
                children[top].pb(*it);
                s.push(*it);
            }
        }
    }
    return node_order;
}

int32_t main()
{
    #ifdef DEBUG
    freopen("D.txt","r",stdin);
    //freopen("","w",stdout);
    #endif

    int n;
    read(n);
    for0(i,n-1) {
        int u,v;
        read(u); read(v);
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<int> node_order = dfs();
    printv(node_order);

    ms(grundy,0);
    for (int i=sz(node_order)-1; i>=0; i--) {
        int nd = node_order[i];
        iter(children[nd]) {
            grundy[nd] ^= 1+grundy[*it];
        }
    }
    printa(grundy,n)

    if (grundy[0] == 0)
        cout<<"Bob"<<endl;
    else
        cout<<"Alice"<<endl;
    return 0;
}
