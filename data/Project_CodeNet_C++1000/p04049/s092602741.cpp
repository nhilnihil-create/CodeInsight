#include <bits/stdc++.h>
using namespace std;

#define Gene template< class
#define Rics printer& operator,
Gene c> struct rge{c b, e;};
Gene c> rge<c> range(c i, c j){ return {i, j};}
struct printer{
    ~printer(){cerr<<endl;}
    Gene c >Rics(c x){ cerr<<boolalpha<<x; return *this;}
    Rics(string x){cerr<<x;return *this;}
    Gene c, class d >Rics(pair<c, d> x){ return *this,"(",x.first,", ",x.second,")";}
    Gene ... d, Gene ...> class c >Rics(c<d...> x){ return *this, range(begin(x), end(x));}
    Gene c >Rics(rge<c> x){
        *this,"["; for(auto it = x.b; it != x.e; ++it)
            *this,(it==x.b?"":", "),*it; return *this,"]";}
};
#define debug() cerr<<"LINE "<<__LINE__<<" >> ", printer()
#define dbg(x) "[",#x,": ",(x),"] "
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r) {
    return uniform_int_distribution<int>(l, r) (rng);
}

const int N = 2005;
vector<int> g[N];
int n, K;
int ans = 1e9;
int cur;

void dfs(int u, int p, int d, int ex) {
    if(2*d + ex > K) cur++;
    for(int v : g[u]) {
        if(v == p) continue;
        dfs(v, u, d+1, ex);
    }
}

int main() {
//    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> K;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        for(int v : g[i]) {
            cur = 0;
            dfs(i, v, 0, 1);
            dfs(v, i, 0, 1);
            debug(), dbg(i), dbg(v), dbg(cur);
            ans = min(ans, cur);
        }
    }
    for(int i = 1; i <= n; i++) {
        cur = 0;
        dfs(i, -1, 0, 0);
        debug(), dbg(i), dbg(cur);
        ans = min(ans, cur);
    }
    cout << ans << endl;
}



