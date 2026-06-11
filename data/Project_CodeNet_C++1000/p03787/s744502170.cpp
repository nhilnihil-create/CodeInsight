#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int n, m;
vector<vector<int>> e;
vector<char> v;
int c, b;

void dfs(int i, int d) {
    v[i] = d;
    c++;
    d ^= 3;
    for (int j : e[i]) {
        if (v[j]) b |= v[j] ^ d; else dfs(j, d);
    }
}

int main() {
    cin >> n >> m;
    v = vector<char>(n);
    e = vector<vector<int>>(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
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
