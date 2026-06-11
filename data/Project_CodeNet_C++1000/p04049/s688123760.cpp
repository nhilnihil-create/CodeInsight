#include <bits/stdc++.h>

using namespace std;
const int inf = 1e9 + 7;
const int N = 1e6 + 1;
vector <int> gr[N];
signed main () {
    int n, k;
    cin >> n >> k;

    vector <pair <int, int> > e;

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        gr[x].push_back(y);
        gr[y].push_back(x);
        e.push_back({x, y});
    }

    int ans = inf;

    for (int i = 0; i < n && k % 2 == 0; i++) {
        vector <int> d(n, inf); queue <int> q; vector <int> used(n, 0);
        d[i] = 0; used[i] = true;q.push(i);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (auto it : gr[cur]) {
                d[it] = min(d[it], d[cur] + 1);
                if (!used[it]) {used[it] = true; q.push(it);}
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) if (d[i] > k / 2) cnt++;
        ans = min(ans, cnt);
    }
    for (int i = 0; i < n - 1 && k % 2; i++) {
        int x = e[i].first, y = e[i].second;
        vector <int> d(n, inf); queue <int> q; vector <char> used(n, 0);
        d[x] = d[y] = 0; used[x] = used[y] = true; q.push(x);q.push(y);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (auto it : gr[cur]) {
                d[it] = min(d[it], d[cur] + 1);
                if (!used[it]) {used[it] = true; q.push(it);}
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) if (d[i] > k / 2) cnt++;
        ans = min(ans, cnt);
    }
    cout << ans << '\n';
}
