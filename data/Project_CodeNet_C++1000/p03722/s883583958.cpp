#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

const ll INF = 1e18;
vvi to, ot;
vb seen_1, seen_n, seen;

void dfs(int v) {
    if (seen_1[v]) return;
    seen_1[v] = true;
    for (int u : to[v]) dfs(u);
}

void rdfs(int v) {
    if (seen_n[v]) return;
    seen_n[v] = true;
    for (int u : ot[v]) rdfs(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    to.resize(n);
    ot.resize(n);
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        edges.eb(a, b, -c);
        to[a].pb(b);
        ot[b].pb(a);
    }
    seen_1 = seen_n = seen = vb(n, false);
    dfs(0);
    rdfs(n-1);
    rep(i, n) seen[i] = (seen_1[i] && seen_n[i]);
    
    vll d(n, INF);
    d[0] = 0;
    for (int t = 0; ; ++t) {
        bool upd = false;
        rep(i, m) {
            int a, b, w;
            tie(a, b, w) = edges[i];
            if (!seen[a] || !seen[b]) continue;
            if (chmin(d[b], d[a] + w)) upd = true;
        }
        if (!upd) break;
        if (t == n-1) {
            cout << "inf" << endl;
            return 0;
        }
    }
    cout << -d[n-1] << endl;

}