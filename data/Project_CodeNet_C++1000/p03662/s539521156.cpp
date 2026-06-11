#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
#define INF 1007654321
#define PI 3.14159265358979
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repp(i, s, e) for(int i = (s); i <= (e); ++i)
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define FAST_IO() ios::sync_with_stdio(0); cin.tie(0)
template<typename T>
ostream& operator<<(ostream &os, const vector<T> &v) { for (auto x : v) os << x << " "; return os << "\n"; }
template<typename U, typename V>
ostream& operator<<(ostream &os, const pair<U, V> &p) { return os << "(" << p.first << "," << p.second << ")";}

const int MAXN = 1e5 + 50;
vector<int> adj[MAXN];
int dist[MAXN];
int parent[MAXN];
int siz[MAXN];

int dfs(int curr, int prev) {
    parent[curr] = prev;
    siz[curr] = 1;
    for(auto &next : adj[curr]) {
        if(next != prev && parent[next] == -1) {
            dist[next] = dist[curr] + 1;
            siz[curr] += dfs(next, curr);
        }
    }
    return siz[curr];
}

int main() {
    FAST_IO();
    int N; cin >> N;
    rep(i, N - 1) {
        int u, v; cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    } 
    memset(parent, -1, sizeof(parent));
    dist[0] = 0;
    dfs(0, -1);
    int u = N - 1;
    rep(i, (dist[N-1]-1)/2) {
        u = parent[u];
    }
    if(siz[u] < N - siz[u]) cout << "Fennec\n";
    else cout << "Snuke\n";
}