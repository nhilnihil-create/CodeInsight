#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> P;

const int MN = 300100;
int n, m;
vector<P> mtp[MN];
vector<int> g[MN];
int ans[MN];

struct Fenwick {
    int n;
    vector<int> seg;
    Fenwick(int _n) : n(_n), seg(n + 1) {}
    void add(int k, int v) {
        while (k <= n) {
            seg[k] += v;
            k += k & -k;
        }
    }
    int sum(int k) {
        if (k > n) return 0;
        int r = 0;
        while (k) {
            r += seg[k];
            k -= k & -k;
        }
        return r;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    for (int d = 1; d <= m; d++) {
        for (int i = d; i <= m; i += d) {
            mtp[i].push_back(P(i, d));
        }
    }

    Fenwick fw(m);
    for (int l = 1; l <= m; l++) {
        for (int i = 0; i < int(g[l].size()); i++) {
            int r = g[l][i];
            fw.add(l, 1);
            fw.add(r + 1, -1);
        }
        for (int i = 0; i < int(mtp[l].size()); i++) {
            P &x = mtp[l][i];
            ans[x.second] += fw.sum(x.first) - fw.sum(x.first + x.second);
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}