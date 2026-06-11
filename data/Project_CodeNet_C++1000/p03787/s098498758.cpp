#include <bits/stdc++.h>
using namespace std;
#define ll long long
#ifdef BALBIT
#define IOS()
#define bug(...) fprintf(stderr,"#%d (%s) = ",__LINE__,#__VA_ARGS__),_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
#endif
int solo = 0;
int bip=0,tri = 0;
const int maxn = 1e5+5;
vector<int> g[maxn];
int col[maxn];
bool seen[maxn];

int sz = 0;

bool bd(int v, bool x = 0) {
    col[v] = x;
    for (int u : g[v]){
        if (-1==col[u]) {
            if (!bd(u, x^1))return 0;
        }else{
            if (col[u] == x) {
                return 0;
            }
        }
    }
    return 1;
}

void fill(int v) {
    seen[v] = 1;
    sz ++;
    for( int u : g[v]) {
        if (!seen[u]) fill(u);
    }
}

int main(){
    ios::sync_with_stdio(cin.tie(0));
    memset(col,-1,sizeof col);
    int n,m; cin>>n>>m;
    for (int i = 0; i<m; ++i) {
        int a,b; cin>>a>>b;
        #define pb push_back
        g[a].pb(b); g[b].pb(a);
    }
    for (int i = 1; i<=n; ++i) {
        if (!seen[i]) {
            sz = 0;
            fill(i);
            if (sz == 1) {
                solo ++;
            }else{
                if (bd(i,0)) {
                    bip ++;
                }else{
                    tri++;
                }
            }
        }
    }
    bug(solo, bip, tri);
    cout<<solo * (ll) (n) + (n-solo) * (ll) solo + 2*bip * (ll) bip + bip * (ll) tri + tri * (ll) tri + tri * (ll) bip;
}
