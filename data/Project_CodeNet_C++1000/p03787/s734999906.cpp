#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int n, m;
vector<char> v; // dfsで訪問済みか 二部グラフ判定用の色も兼ねる
vector<int> f; // 最初の辺
vector<pair<int, int>> e; // もう片方の端点と次の辺
int c, b;

void add_edge(int u, int v) {
    e[c] = { v, f[u] }; // お尻に足していく
    f[u] = c;
    c++;
}

void dfs(int i, int d) {
    v[i] = d;
    c++;
    d ^= 3;
    for (int k = f[i]; k >= 0; k = e[k].second) {
        int j = e[k].first;
        if (v[j]) b |= v[j] ^ d; else dfs(j, d);
    }
}

int main() {
    cin >> n >> m;
    v = vector<char>(n);
    f = vector<int>(n, -1);
    e = vector<pair<int, int>>(m * 2);
    c = 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        add_edge(u, v);
        add_edge(v, u);
    }

    int64_t k[3] = {};
    for (int i = 0; i < n; i++) {
        if (v[i]) continue;
        c = b = 0;
        dfs(i, 1);
        k[(c > 1) + (b != 0)]++;
    }

    k[2] += k[1];
    int64_t r = k[0] * (n * 2 - k[0]) + k[2] * k[2] + k[1] * k[1];

    cout << r << endl;

    return 0;
}
