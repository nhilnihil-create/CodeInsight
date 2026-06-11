#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Paint {
    int i, d;
    Paint(int i, int d) : i(i), d(d) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N+1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int Q;
    cin >> Q;
    vector<int> num(N+1, -1);
    vector<int> color(Q);
    vector<vector<Paint>> paint(N+1);
    vector<vector<Paint>> npaint(N+1);
    vector<unordered_set<int>> used(N+1);

    for (int i = 0; i < Q; i++) {
        int v, d, c;
        cin >> v >> d >> c;
        color[i] = c;
        paint[v].emplace_back(i, d);
    }

    for (int j = 0; j <= 10; j++) {
        for (int v = 1; v <= N; v++) npaint[v].clear();

        for (int v = 1; v <= N; v++) {
            if (paint[v].size() == 0) continue;

            sort(paint[v].begin(), paint[v].end(), [&](auto& p1, auto& p2) {
                return p1.i > p2.i;
            });

            vector<Paint> pv;
            for (auto& p : paint[v]) {
                if (used[v].count(p.i) > 0) continue;
                if (pv.size() == 0 || pv.back().d < p.d) {
                    pv.push_back(p);
                    used[v].insert(p.i);
                }
            }

            if (pv.size() == 0) continue;

            num[v] = max(num[v], pv[0].i);

            for (int u : G[v]) {
                for (auto& p : pv) {
                    if (p.d > 0) {
                        npaint[u].emplace_back(p.i, p.d - 1);
                    }
                }
            }
        }
        paint = npaint;
    }
    for (int v = 1; v <= N; v++) {
        if (num[v] == -1) cout << 0 << '\n';
        else cout << color[num[v]] << '\n';
    }
}