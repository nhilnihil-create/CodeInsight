#include <bits/stdc++.h>
using namespace std;

const int INF = (1 << 30) - 1;

int main() {
    // Debug::set_INF(INF);
    int N, M;  cin >> N >> M;
    vector<vector<int>> dist(N, vector<int>(N, INF));
    for (int i = 0; i < M; ++i) {
        int a, b, c;  cin >> a >> b >> c;
        dist[a - 1][b - 1] = c;
        dist[b - 1][a - 1] = c;
    }
    for (int i = 0; i < N; ++i) dist[i][i] = 0;
    // DUMP(dist);

    map<pair<int, int>, int> cnt;
    auto dist_cp = dist;
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    if (i != j && dist_cp[i][j] != INF) ++cnt[pair<int, int>(i, j)];
                }
            }
        }
    }
    // DUMP(dist, cnt);

    cout << cnt.size() / 2 << endl;
}
