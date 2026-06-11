#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <string>
#define _repargs(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _repargs(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define inf 2000000007
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
template <typename T>
inline void output(T a, int p = 0) {
    if(p) cout << fixed << setprecision(p)  << a << "\n";
    else cout << a << "\n";
}
// end of template
vector<vector<int>> G;
vector<int> vis;
vector<int> vert;
void dfs(int cur, int par = -1, int num = 1){
    if(vis[cur]) return;

    if(G[cur].size() == 0) return;
    vis[cur] = num;
    vert.pb(cur);
    for(int v: G[cur]){
        if(par == v) continue;
        dfs(v, cur, num + 1);
    }
}

template <typename T> inline void voutput(T &v){
    rep(i, v.size()){
        if (i) cout << " " << v[i];
        else cout << v[i];
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    int N, M;
    cin >> N >> M;
    G.resize(N);
    vis.assign(N, 0);
    

    rep(i, M){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].pb(v), G[v].pb(u);
    }
    
    
    ll ans = 0;
    
    ll odd = 0;
    ll even = 0;
    
    rep(i, N){
        vert.clear();
        dfs(i);
        if(vert.size() < 2) continue;
        bool loop = false;
        for(int v: vert){
            for(int w: G[v]){
                if((vis[v] - vis[w]) % 2 == 0){
                    loop = true;
                }
            }
        }
//        cout << "vert:";
//        voutput(vert);
//        cout << i << ":" << loop << endl;
        if(loop) even++;
        else odd++;
    }
//    voutput(vis);
    ll rest = 0;
    rep(i, N) if(vis[i] > 0) rest++;
//    cout << odd << "," << even << "," << rest << endl;
    ans += (odd + even) * (odd + even) + odd * odd;
    ans += (N - rest) * (N - rest) + 2 * (N - rest) * rest;
    
    output(ans);
    
    return 0;
}