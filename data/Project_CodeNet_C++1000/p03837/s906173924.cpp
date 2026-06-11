#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
struct WarshallFloyd {
    const T INF = numeric_limits<T>::max();
    int n;
    vector<vector<T>> d;
    WarshallFloyd(int n) : n(n), d(n, vector<T>(n, INF)) {
        for (int i = 0; i < n; i++) d[i][i] = 0;
    }
    void add_edge(int s, int t, T w, bool directed) {
        d[s][t] = min(d[s][t], w);
        if (directed) d[t][s] = min(d[t][s], w);
        for (int k : {s, t})
            for (int i = 0; i < n; i++) if (d[i][k] != INF)
                for (int j = 0; j < n; j++) if (d[k][j] != INF)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }
    bool has_neg_cycle() {
        for (int i = 0; i < n; i++) if (d[i][i] < 0) return true;
        return false;
    }
    bool in_shortest_path(int s, int t, T w) {
        return d[s][t] >= w;
    }
};

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(m), b(m), c(m);
    for (int i = 0; i < m; i++) cin >> a[i] >> b[i] >> c[i], a[i]--, b[i]--;
    WarshallFloyd<int> wf(n);
    for (int i = 0; i < m; i++) wf.add_edge(a[i], b[i], c[i], true);
    int cnt = 0;
    for (int i = 0; i < m; i++) cnt += !wf.in_shortest_path(a[i], b[i], c[i]);
    cout << cnt << endl;
    return 0;
}
