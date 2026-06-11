#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

const int INF = 1e9;
const long long LINF = 1e18;

typedef vector<vector<int>> Graph;

void warhsall_floyd(Graph& G) {
    for (int k = 0; k < G.size(); k++) {
        for (int i = 0; i < G.size(); i++) {
            if (G[i][k] == INF) {
                continue;
            }
            for (int j = 0; j < G.size(); j++) {
                if (G[k][j] == INF) {
                    continue;
                }
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
}

int main() {
    int N, M, R;
    cin >> N >> M >> R;

    vector<int> r(R);
    for (int i = 0; i < R; i++) {
        cin >> r[i];
    }

    Graph G(N, vector<int>(N, INF));
    for (int  i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        --A;
        --B;
        G[A][B] = C;
        G[B][A] = C;
    }

    for (int i = 0; i < N; i++) {
        G[i][i] = 0;
    }

    warhsall_floyd(G);

    long long ans = LINF;
    sort(r.begin(), r.end());
    do {
        long long dist = 0;
        for (size_t i = 1; i < r.size(); i++) {
            // cout << r[i - 1] << ", " << r[i] << endl;
            dist += G[r[i - 1] - 1][r[i] - 1];
        }
        ans = min(ans, dist);
    } while (next_permutation(r.begin(), r.end()));

    cout << ans << endl;

    return 0;
}