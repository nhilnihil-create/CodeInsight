#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

#define MAXN 100000
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n;
vector<pair<ll, int>> adj[MAXN];
ll d[MAXN];

void dijkstra(int a) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> PQ;
    int color[n];
    rep(i, n) {
        color[i] = WHITE;
        d[i] = LINF;
    }

    d[a] = 0;
    PQ.push(make_pair(d[a], a));
    color[a] = GRAY;

    while(!PQ.empty()) {
        pair<ll, int> f = PQ.top();
        PQ.pop();
        ll cst = f.first;
        int u = f.second;
        color[u] = BLACK;
        if (d[u] < cst) continue;

        for (int i = 0; i < (int)adj[u].size(); ++i) {
            int v = adj[u][i].second;
            if (color[v] == BLACK) continue;
            if (d[v] > d[u] + adj[u][i].first) {
                d[v] = d[u] + adj[u][i].first;
                PQ.push(make_pair(d[v], v));
                color[v] = GRAY;
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    rep(i, n - 1) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].push_back(make_pair(c, b));
        adj[b].push_back(make_pair(c, a));
    }

    int q, k;
    cin >> q >> k;
    --k;
    dijkstra(k);

    rep(i, q) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        cout << d[x] + d[y] << endl;

    }
    


    return 0;
}