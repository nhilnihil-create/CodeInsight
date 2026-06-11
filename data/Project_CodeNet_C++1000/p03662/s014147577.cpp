#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)

const static int MOD = 1000000000 + 7;
const static llong INF = 1LL << 60;
const static int dy[] = {0, 1, 0, -1};
const static int dx[] = {1, 0, -1, 0};

vector<bool> visited;
vector<vector<int> > g;
vector<int> distance_from_zero, distance_from_N;

void dfs1(int s, int d) {
    if (visited[s] == true) return;

    visited[s] = true;
    distance_from_zero[s] = d;
    rep(i, g[s].size()) {
        dfs1(g[s][i], d + 1);
    }

    return;
}

void dfs2(int s, int d) {
    if (visited[s] == true) return;

    visited[s] = true;
    distance_from_N[s] = d;
    rep(i, g[s].size()) {
        dfs2(g[s][i], d + 1);
    }

    return;
}

signed main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    g.resize(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    visited.resize(n, false);
    distance_from_zero.resize(n, 0);
    dfs1(0, 0);

    visited.clear();
    visited.resize(n, false);
    distance_from_N.resize(n, 0);
    dfs2(n - 1, 0);

    int f_cnt = 0, s_cnt = 0; 
    rep(i, n) {
        if (distance_from_zero[i] <= distance_from_N[i]) ++f_cnt;
        else ++s_cnt;
    }

    if (f_cnt > s_cnt) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;

    return 0;
}