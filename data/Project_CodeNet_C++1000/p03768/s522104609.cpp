#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)
#define RREP(i,n) for (int i=(n)-1;i>=0;--i)

using namespace std;

template <class T>
using vec2 = vector<vector<T>>;

template <class T>
vec2<T> vec2_init(int n0, int n1, T x = 0) {
    return vec2<T>(n0, vector<T>(n1, x));
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    constexpr int D_MAX = 10;

    int N, M;
    cin >> N >> M;
    vector<vector<int>> g(N);
    REP(_, M) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int Q;
    cin >> Q;
    vector<int> v(Q), d(Q), c(Q);
    REP(i, Q) {
        cin >> v[i] >> d[i] >> c[i];
        --v[i];
    }

    auto used = vec2_init<bool>(N, D_MAX + 1);
    vector<int> color(N);

    function<void(int, int, int)> f = [&](int u, int d, int c) {
        if (color[u] == 0) {
            color[u] = c;
        }
        if (d > 0) {
            if (!used[u][d - 1]) {
                used[u][d - 1] = true;
                f(u, d - 1, c);
            }
            for (int v : g[u]) {
                if (!used[v][d - 1]) {
                    used[v][d - 1] = true;
                    f(v, d - 1, c);
                }
            }
        }
    };

    RREP(i, Q) {
        f(v[i], d[i], c[i]);
    }

    REP(i, N) {
        cout << color[i] << '\n';
    }
    cout << flush;

    return 0;
}
