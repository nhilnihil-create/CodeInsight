#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].emplace_back(b), g[b].emplace_back(a);
    }

    vector<int> df(n, -1), ds(n, -1);
    {
        queue<int> q;
        q.emplace(0); df[0] = 0;
        while (!q.empty()) {
            int now = q.front(); q.pop();
            for (auto &nxt: g[now]) {
                if (df[nxt] >= 0) continue;
                df[nxt] = df[now] + 1;
                q.emplace(nxt);
            }
        }
    }
    {
        queue<int> q;
        q.emplace(n - 1); ds[n - 1] = 0;
        while (!q.empty()) {
            int now = q.front(); q.pop();
            for (auto &nxt: g[now]) {
                if (ds[nxt] >= 0) continue;
                ds[nxt] = ds[now] + 1;
                q.emplace(nxt);
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (df[i] <= ds[i]) cnt++;
    }
    cout << ((cnt > n - cnt) ? "Fennec" : "Snuke") << endl;
    return 0;
}
