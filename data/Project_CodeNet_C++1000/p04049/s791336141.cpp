#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define __ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

const int maxn = 2020;

int n, k;
vector<int> v[maxn];
queue<int> q, p;
bool vis[maxn];
vector<int> vv;

int bfs(int x, int s, bool op) {
    while (!q.empty())q.pop();
    while (!p.empty())p.pop();
    int ct = 0;
    q.push(x);
    ++ct;
    if (op)vv.push_back(x);
    vis[x] = 1;
    for (int i = 0; i <= s; ++i) {
        while (!p.empty()) {
            int x = p.front();
            p.pop();
            for (int j = 0; j < v[x].size(); ++j) {
                if (vis[v[x][j]] == 0) {
                    vis[v[x][j]] = 1;
                    q.push(v[x][j]);
                    if (op) vv.push_back(v[x][j]);
                    ++ct;
                }
            }
        }
        swap(p, q);
    }
    if (s < 0)return 0;
    else return ct;
}

int dp(int x, int s) {
    vis[x] = 1;
    int ct = 0;
    int tot = 0;
    for (int i = 0; i < v[x].size(); ++i) {
        vv.clear();
        int a1 = bfs(v[x][i], s - 1, 1);
        for (auto j:vv) {
            vis[j] = 0;
        }
        int a2 = bfs(v[x][i], s, 0);
        tot = max(tot, a2 - a1);
        ct += a1;
    }
    return ct + tot + 1;
}

int main() {
    __;
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    if (k % 2 == 0) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            memset(vis, 0, sizeof vis);
            ans = max(ans, bfs(i, k / 2, 0));
//            vv.clear();
        }
        cout << n - ans << endl;
    } else {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            memset(vis, 0, sizeof vis);
            ans = max(ans, dp(i, k / 2));
            vv.clear();
        }
        cout << n - ans << endl;
    }
    return 0;
}
/*
 6 1
1 2
3 2
4 2
1 6
5 6
 */