#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e5 * 2 + 100, INF = 1e9, MOD = 1e9 + 7;

bool gt[SIZE], used[SIZE];
ll dsu[SIZE][2], sz[SIZE][2];
vector<vector<ll>> graph;
vector<pair<ll, ll>> cur;


ll find(int v, int ind) {
    if (dsu[v][ind] == v) return v;
    else return dsu[v][ind] = find(dsu[v][ind], ind);
}
void dfs(int v) {
    used[v] = 1;

    cur.push_back({ find(v, 0), v });
    for (auto to : graph[v]) {
        if (!used[to]) {

            dfs(to);
        }
    }
}
void uni(int v, int u, int ind) {
    u = find(u, ind);
    v = find(v, ind);

    if (u != v) {
        dsu[u][ind] = v;
        sz[v][ind] += sz[u][ind];
    }
}
int main()
{
    fastInp;

    string s;

    ll n, k, l;
    cin >> n >> k >> l;

    for (int i = 0; i < n; i++) {
        sz[i][0] = 1;
        sz[i][1] = 1;
        dsu[i][0] = i;
        dsu[i][1] = i;
    }

    for (int i = 0; i < k; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        uni(u, v, 0);
    }

    graph.resize(n);
    for (int i = 0; i < l; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            cur.clear();
            dfs(i);
            sort(cur.begin(), cur.end());
            for (int j = 1; j < cur.size(); j++) {
                if (cur[j].first == cur[j - 1].first) uni(cur[j].second, cur[j - 1].second, 1);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        ll u = find(i, 1);
        cout << sz[u][1] << " ";
    }
    return 0;
}