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

    int n;
    int m;
    cin >> n >> m;

    vector<int> A(m);
    vector<int> B(m);
    vector<long long> W(m);

    vector<vector<pair<int, long long>>> graph(n);
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        --a, --b;
        A[i] = a, B[i] = b, W[i] = w;
        graph[a].emplace_back(b, w);
    }

    const long long INF = 1LL << 50;
    vector<long long> dis(n, -INF);
    dis[0] = 0;

    const int LIMIT = 2 * n + 10;
    int rnd = -1;
    for (int i = 0; i < LIMIT; ++i) {
        for (int u = 0; u < n; ++u) {
            for (auto& e : graph[u]) {
                int v = e.first;
                long long w = e.second;
                if (v == n - 1 && dis[v] < dis[u] + w) {
                    rnd = i;
                }
                dis[v] = max(dis[v], dis[u] + w);
            }
        }
    }

    if (rnd > n) {
        cout << "inf\n";
    } else {
        cout << dis[n - 1] << '\n';
    }
    return 0;
}