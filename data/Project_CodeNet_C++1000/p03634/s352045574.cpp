#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

vector<P> to[100005];
ll dist[100005];

void dfs(int v, int p=-1) {
    ll d = dist[v];
    for (auto e: to[v]) {
        if (e.first==p) continue;
        dist[e.first] = d + e.second;
        dfs(e.first, v);
    }
}

int main(){
    int n;
    cin >> n;
    rep(i, n-1) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        to[a].emplace_back(b, c);
        to[b].emplace_back(a, c);
    }
    int q, k;
    cin >> q >> k;
    k--;
    dfs(k);
    rep(qi, q) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        ll ans = dist[x] + dist[y];
        cout << ans << endl;
    }
    return 0;
}
