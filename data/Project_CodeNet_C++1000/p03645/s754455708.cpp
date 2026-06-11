// 2020-06-05 17:53
#include <bits/stdc++.h>
using namespace std;

// 深さ2の全探索すればおk

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 0 -> M-1まで行く
    stack<pair<int, int>> Task;
    Task.emplace(0, 0);
    while (!Task.empty()) {
        auto P = Task.top();
        Task.pop();
        if (P.first == N - 1 && P.second == 2) {
            cout << "POSSIBLE" << endl;
            return 0;
        }
        if (P.second >= 2) continue;
        for (int to : G[P.first]) {
            Task.emplace(to, P.second + 1);
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}