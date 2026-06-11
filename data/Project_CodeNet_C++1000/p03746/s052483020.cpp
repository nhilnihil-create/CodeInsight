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

    deque<int> path;
    vector<bool> visited(n, false);
    path.push_front(0);
    visited[0] = true;
    path.push_back(G[0].back());
    visited[G[0].back()] = true;

    bool updated;
    int end_point;
    while (true) {
        updated = false;
        end_point = path.front();
        rep(i, G[end_point].size()) {
            if (! visited[G[end_point][i]]) {
                visited[G[end_point][i]] = true;
                path.push_front(G[end_point][i]);
                updated = true;
                break;
            }
        }
        if (! updated) break;
    }

    while (true) {
        updated = false;
        end_point = path.back();
        rep(i, G[end_point].size()) {
            if (! visited[G[end_point][i]]) {
                visited[G[end_point][i]] = true;
                path.push_back(G[end_point][i]);
                updated = true;
                break;
            }
        }
        if (! updated ) break;
    }

    cout << path.size() << endl;
    stl_rep(itr, path) {
        cout << *itr + 1 << " ";
    }
    cout << endl;

    return 0;
}