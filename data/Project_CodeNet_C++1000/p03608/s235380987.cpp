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
const int INF = 1001001001;

int dp[10][270];

struct State {
    int v, x, d;
    State(int v, int x, int d): v(v), x(x), d(d) {}
};

int main(){
    int n, m, R;
    cin >> n >> m >> R;
    vector<int> r(R);
    rep(i, R) {
        cin >> r[i];
        r[i]--;
    }
    vector<vector<int>> dist(n, vector<int>(n, INF));
    rep(i, n) dist[i][i] = 0;
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    rep(k, n) rep(i, n) rep(j, n) {
        chmin(dist[i][j], dist[i][k]+dist[k][j]);
    }
    rep(i, 10) rep(j, 270) dp[i][j] = INF;
    rep(i, R) dp[i][1<<i] = 0;
    auto comp = [](State a, State b) {
        return a.d>b.d;
    };
    priority_queue<State, vector<State>, decltype(comp)> q{comp};
    rep(i, R) q.emplace(i, 1<<i, 0);
    while (!q.empty()) {
        State now = q.top();
        q.pop();
        int nv = now.v;
        int nx = now.x;
        int nd = now.d;
        if (nd>dp[nv][nx]) continue;
        rep(i, R) {
            if (i==nv) continue;
            int iv = i;
            int ix = nx | (1<<i);
            int id = nd + dist[r[nv]][r[i]];
            if (id>=dp[iv][ix]) continue;
            dp[iv][ix] = id;
            q.emplace(iv, ix, id);
        }
    }
    int ans = INF;
    rep(i, R) {
        chmin(ans, dp[i][(1<<R)-1]);
    }
    
    cout << ans << endl;
    return 0;
}
