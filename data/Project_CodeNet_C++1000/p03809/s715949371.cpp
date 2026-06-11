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

const int N = 1e5+100;

vector<int> g[N];
int a[N];
long long dp[N];

void dfs(int u, int p) {
//    debug(), dbg(u), dbg(p);
    if(g[u].size() == 1) {
        dp[u] = a[u];
        return;
    }
    long long sum = 0;
    vector<long long> all;
    for(int v : g[u]) {
        if(v == p) continue;
        dfs(v, u);
        sum += dp[v];
        all.push_back(dp[v]);
    }
    sort(all.begin(), all.end());
    long long pairs = 0;
    if(all.size() >= 2) {
        long long mx = all.back();
        long long other = sum-mx;
        if(other >= mx) pairs = sum/2;
        else pairs = other;
    }
    long long req_pair = sum-a[u];
//    debug(), dbg(u), dbg(req_pair), dbg(pairs), dbg(sum);
    if(req_pair >= 0 && req_pair <= pairs) {
        dp[u] = sum - 2*req_pair;
    }
    else {
        cout << "NO" << endl;
        exit(0);
    }
}

int main() {
//    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(n == 2) {
        if(a[1] == a[2]) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
        return 0;
    }
    int root = -1;
    for(int i = 1; i <= n; i++) {
        if(g[i].size() > 1) {
            root = i;
            break;
        }
    }
    dfs(root, -1);
//    for(int i = 1; i <= n; i++) {
//        debug(), dbg(i), dbg(dp[i]);
//    }
    if(dp[root] == 0) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}



