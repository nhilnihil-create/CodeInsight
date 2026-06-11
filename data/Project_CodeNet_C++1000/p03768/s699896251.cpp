#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M; cin >> N >> M;
    vector<vector<int>> graph(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int Q; cin >> Q;
    vector<int> V(Q), D(Q), C(Q);
    for (int i = 0; i < Q; i++) cin >> V[i] >> D[i] >> C[i], V[i]--;
    vector<int> painted(N, -1), result(N);
    function<void(int, int, int)> recur;
    recur = [&](int v, int d, int c) {
        if (d < 0 || painted[v] >= d) return;
        if (painted[v] == -1) result[v] = c;
        painted[v] = d;
        if (d > 0) for (int t : graph[v]) recur(t, d-1, c);
    };
    for (int i = Q-1; i >= 0; i--) {
        recur(V[i], D[i], C[i]);
    }
    for (int r : result) cout << r << '\n';
    return 0;
}
