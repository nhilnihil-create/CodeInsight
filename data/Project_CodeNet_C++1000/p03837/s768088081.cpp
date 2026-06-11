#include "bits/stdc++.h"

using namespace std;

const int INF = 1000000000;

void Main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N, vector<int>(N, INF));
    vector<pair<pair<int, int>, int>> edges;
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        graph[a][b] = c;
        graph[b][a] = c;
        edges.push_back(make_pair(make_pair(a, b), c));
    }
    for (int i = 0; i < N; ++i) {
        graph[i][i] = 0;
    }

    vector<vector<int>> minPath = graph;
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                minPath[i][j] = min(minPath[i][j], minPath[i][k] + minPath[k][j]);
            }
        }
    }

    int ans = 0;
    for (auto e : edges) {
        int a = e.first.first;
        int b = e.first.second;
        int c = e.second;
        bool found = false;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (minPath[i][j] == minPath[i][a] + c + minPath[b][j]) {
                    found = true;
                }
            }
        }
        if (!found) {
            ++ans;
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
