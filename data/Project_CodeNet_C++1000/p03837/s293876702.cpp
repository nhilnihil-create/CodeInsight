#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
#define rep(i, n) for (int i = 0; i < n; i++)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, m;
vector<vector<pint>> g (105);
set<pint> s;

void dijkstra (int now) {
    int l[n], p[n];
    bool seen[n] = {};
    priority_queue<pint, vector<pint>, greater<pint>> pq;
    rep (i, n) {
        l[i] = inf;
        p[i] = -1;
    }
    l[now] = 0;
    pq.push ({0, now});

    while (!pq.empty()) {
        pint f = pq.top();
        pq.pop();
        int u = f.second;
        rep (i, g[u].size()) {
            int next = g[u][i].second;
            if (!seen[next] && l[next] > l[u] + g[u][i].first) {
                l[next] = l[u] + g[u][i].first;
                p[next] = u;
                pq.push ({l[next], next});
            }
        }
    }

    rep (i, n) {
        if (p[i] == -1) continue;
        int a = max (i, p[i]), b = min (i, p[i]);
        s.insert ({a, b});
        // cout << now << " " << a << " " << b << " " << l[i] << "\n";
    }
}

int main() {
    cin >> n >> m;
    int a[m], b[m], c[m];
    rep (i, m) {
        cin >> a[i] >> b[i] >> c[i];
        g[--a[i]].push_back ({c[i], --b[i]});
        g[b[i]].push_back ({c[i], a[i]});
    }
    rep (i, n) dijkstra (i);
    int ans = m - s.size();
    cout << ans << "\n";
}