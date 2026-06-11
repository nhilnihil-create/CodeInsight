#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 2007;

int n, k, ans = maxn, qu[maxn], fr, rr, dist[maxn];
vector<int> G[maxn];

void proc(int u, int v)
{
	fr = rr = 0;
	for (int i = 1; i <= n; ++i) dist[i] = maxn;
	if (u) dist[qu[++rr] = u] = 0;
	if (v) dist[qu[++rr] = v] = 0;
	int cur = n;
    while (fr < rr) {
        u = qu[++fr];
        if (dist[u] <= k) --cur;
        else break;

        for (int v : G[u]) if (dist[u] + 1 < dist[v]) {
            dist[qu[++rr] = v] = dist[u] + 1;
        }
    }
    ans = min(ans, cur);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n-1; ++i) {
    	int u, v; cin >> u >> v;
    	G[u].push_back(v);
    	G[v].push_back(u);
    }

    if (k & 1) {
        k >>= 1;
        for (int u = 1; u <= n; ++u) for (int v : G[u]) if (u < v) {
            proc(u, v);
        }
    } else {
    	k >>= 1;
        for (int u = 1; u <= n; ++u) proc(u, 0);
    }

    cout << ans;
}
