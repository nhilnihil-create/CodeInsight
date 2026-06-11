#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12);

    int n, m, R;
    cin >> n >> m >> R;

    vector<int> X(R);
    for (int i = 0; i < R; ++i) {
        cin >> X[i];
        --X[i];
    }

    const long long INF = 1LL << 50;
    vector<vector<long long>> dis(n, vector<long long>(n, INF));

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;

        dis[u][v] = min(dis[u][v], (long long) w);
        dis[v][u] = min(dis[v][u], (long long) w);
    }
    for (int i = 0; i < n; ++i) {
        dis[i][i] = 0;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    vector<int> ord(R, 0);
    iota(ord.begin(), ord.end(), 0);

    long long res = INF;
    do {
        long long d = 0;
        for (int i = 1; i < R; ++i) {
            int u = X[ord[i - 1]], v = X[ord[i]];
            d += dis[u][v];
        }
        res = min(res, d);
    } while (next_permutation(ord.begin(), ord.end()));

    cout << res << '\n';

    return 0;
}