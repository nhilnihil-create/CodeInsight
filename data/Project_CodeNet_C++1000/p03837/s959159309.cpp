//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

struct edge {
    int from;
    int to;
    int64_t cost;
    edge(int f = 0, int x=0, int64_t y=0):to(x), cost(y), from(f) {}
};

vector<vector<edge> > G; // resizeの必要あり


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vvi dist(n, vi(n, INF));
    edge G[m];
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        dist[a][b] = c;
        dist[b][a] = c;
        G[i] = edge(a, b, c);
    }

    rep(k, n) {
        rep(i, n) {
            rep(j, n) {
                if(i == j) dist[i][j] = 0;
                else {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    vector<bool> check(m, false);
    rep(i, m) {
        edge &e = G[i];
        if(dist[e.from][e.to] < e.cost) check[i] = true;
    }

    int ans = 0;
    rep(i, m) {
        ans += check[i];
    }

    cout << ans << endl;
}