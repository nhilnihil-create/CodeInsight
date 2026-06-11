#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

struct Graph {
    struct Vertex { int n; };
    struct Edge { int i, n; };
    Graph(int n, int m) : v(n, { -1 }), e(m), n(n), m(0) {}
    void add_edge(int i, int j) {
        e[m] = { j, v[i].n };
        v[i].n = m;
        m++;
    }
    int dfs(int i, int p) {
        int r = 0;
        for (int j = v[i].n; j >= 0; j = e[j].n) {
            Edge& o = e[j];
            if (o.i == p) continue;
            r ^= dfs(o.i, i) + 1;
        }
        return r;
    }
    vector<Vertex> v;
    vector<Edge> e;
    int n, m;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    Graph g(n, (n - 1) * 2);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g.add_edge(x, y);
        g.add_edge(y, x);
    }

    cout << (g.dfs(0, -1) != 0 ? "Alice" : "Bob") << endl;

    return 0;
}