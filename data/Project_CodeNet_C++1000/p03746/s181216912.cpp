#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define rep(i, n) for (int i = 0; i < n; ++i)
#define REP(i, k, n) for (int i = k; i < n; ++i)
#define fore(i,a) for (auto &i : a)
#define repr(i, n) for (int i = n; i >= 0; --i)
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

const static int mod = 1000000000 + 7;
const static int inf = INT_MAX / 2;
const static llong INF = LLONG_MAX / 2;
const static double eps = 1e-10;
const static int dx[] = {1, 0, -1, 0};
const static int dy[] = {0, 1, 0, -1};

vector<vector<int> > G;
vector<bool> visited;

deque<int> path;
void dfs(int v, int mode) {
    if (mode == 1) {
        visited[v] = true;
        for (auto e : G[v]) {
            if (! visited[e]) {
                path.push_front(e);
                dfs(e, 1);
                break;
            }
        }
    } else {
        visited[v] = true;
        for (auto e : G[v]) {
            if (! visited[e]) {
                path.push_back(e);
                dfs(e, 2);
                break;
            }
        }
    }
}

signed main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    G.resize(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    visited.resize(n, false);
    path.push_front(0);
    visited[0] = true;
    path.push_back(G[0].back());
    visited[G[0].back()] = true;

    dfs(0, 1);
    dfs(G[0].back(), 2);

    cout << path.size() << endl;
    stl_rep(itr, path) {
        cout << *itr + 1 << " ";
    }
    cout << endl;

    return 0;
}